/*
    SSSD

    Helper routines for file descriptor events

    Authors:
        Sumit Bose <sbose@redhat.com>

    Copyright (C) 2010 Red Hat

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "util/util.h"
#include "providers/ldap/sdap_async_private.h"

struct sdap_fd_events {
#ifdef HAVE_LDAP_CONNCB
    struct ldap_conncb *conncb;
#else
    struct tevent_fd *fde;
#endif
};

int get_fd_from_ldap(LDAP *ldap, int *fd)
{
    int ret;

    ret = ldap_get_option(ldap, LDAP_OPT_DESC, fd);
    if (ret != LDAP_OPT_SUCCESS || *fd < 0) {
        DEBUG(SSSDBG_CRIT_FAILURE, "Failed to get fd from ldap!!\n");
        *fd = -1;
        return EIO;
    }

    return EOK;
}

int remove_ldap_connection_callbacks(struct sdap_handle *sh)
{
    /* sdap_fd_events might be NULL here if the back end was marked offline
     * before a connection was established.
     */
    if (sh->sdap_fd_events) {
#ifdef HAVE_LDAP_CONNCB
        talloc_zfree(sh->sdap_fd_events->conncb);
#else
        talloc_zfree(sh->sdap_fd_events->fde);
#endif
    }
    return EOK;
}

#ifdef HAVE_LDAP_CONNCB

static int remove_connection_callback(TALLOC_CTX *mem_ctx)
{
    int lret;
    //从talloc指针中获取类型化的指针，由ptr给定的正确转换的指针，错误时为NULL。
    struct ldap_conncb *conncb = talloc_get_type(mem_ctx, struct ldap_conncb);

    struct ldap_cb_data *cb_data = talloc_get_type(conncb->lc_arg,
                                                   struct ldap_cb_data);

    lret = ldap_get_option(cb_data->sh->ldap, LDAP_OPT_CONNECT_CB, conncb);
    if (lret != LDAP_OPT_SUCCESS) {
        DEBUG(SSSDBG_CRIT_FAILURE, "Failed to remove connection callback.\n");
    } else {
        DEBUG(SSSDBG_TRACE_ALL, "Successfully removed connection callback.\n");
    }
    return EOK;
}

static int sdap_ldap_connect_callback_add(LDAP *ld, Sockbuf *sb,
                                          LDAPURLDesc *srv,
                                          struct sockaddr *addr,
                                          struct ldap_conncb *ctx)
{
    int ret;
    ber_socket_t ber_fd;
    struct fd_event_item *fd_event_item;
    struct ldap_cb_data *cb_data = talloc_get_type(ctx->lc_arg,
                                                   struct ldap_cb_data);

    if (cb_data == NULL) {
        DEBUG(SSSDBG_CRIT_FAILURE,
              "sdap_ldap_connect_callback_add called without "
                  "callback data.\n");
        return EINVAL;
    }
//检索与Sockbuf相关的文件描述符； arg必须是ber_socket_t *。
 // 如果存在有效的描述符，则返回值为1，否则为-1。
    ret = ber_sockbuf_ctrl(sb, LBER_SB_OPT_GET_FD, &ber_fd);
    if (ret == -1) {
        DEBUG(SSSDBG_CRIT_FAILURE, "ber_sockbuf_ctrl failed.\n");
        return EINVAL;
    }

    if (DEBUG_IS_SET(SSSDBG_TRACE_LIBS)) {
        char *uri = ldap_url_desc2str(srv);
        DEBUG(SSSDBG_TRACE_LIBS, "New LDAP connection to [%s] with fd [%d].\n",
                  uri, ber_fd);
        free(uri);
    }

    fd_event_item = talloc_zero(cb_data, struct fd_event_item);
    if (fd_event_item == NULL) {
        DEBUG(SSSDBG_CRIT_FAILURE, "talloc failed.\n");
        return ENOMEM;
    }

    fd_event_item->fde = tevent_add_fd(cb_data->ev, fd_event_item, ber_fd,
                                       TEVENT_FD_READ, sdap_ldap_result,
                                       cb_data->sh);
    if (fd_event_item->fde == NULL) {
        DEBUG(SSSDBG_CRIT_FAILURE, "tevent_add_fd failed.\n");
        talloc_free(fd_event_item);
        return ENOMEM;
    }
    fd_event_item->fd = ber_fd;

    DLIST_ADD(cb_data->fd_list, fd_event_item);

    return LDAP_SUCCESS;
}

static void sdap_ldap_connect_callback_del(LDAP *ld, Sockbuf *sb,
                                           struct ldap_conncb *ctx)
{
    int ret;
    ber_socket_t ber_fd;
    struct fd_event_item *fd_event_item;
    struct ldap_cb_data *cb_data = talloc_get_type(ctx->lc_arg,
                                                   struct ldap_cb_data);

    if (sb == NULL || cb_data == NULL) {
        return;
    }

    ret = ber_sockbuf_ctrl(sb, LBER_SB_OPT_GET_FD, &ber_fd);
    if (ret == -1) {
        DEBUG(SSSDBG_CRIT_FAILURE, "ber_sockbuf_ctrl failed.\n");
        return;
    }
    DEBUG(SSSDBG_TRACE_ALL, "Closing LDAP connection with fd [%d].\n", ber_fd);

    DLIST_FOR_EACH(fd_event_item, cb_data->fd_list) {
        if (fd_event_item->fd == ber_fd) {
            break;
        }
    }
    if (fd_event_item == NULL) {
        DEBUG(SSSDBG_CRIT_FAILURE, "No event for fd [%d] found.\n", ber_fd);
        return;
    }

    DLIST_REMOVE(cb_data->fd_list, fd_event_item);
    talloc_zfree(fd_event_item);

    return;
}

#else

static int sdap_install_ldap_callbacks(struct sdap_handle *sh,
                                       struct tevent_context *ev)
{
    int fd;
    int ret;

    if (sh->sdap_fd_events) {
        DEBUG(SSSDBG_CRIT_FAILURE,
              "sdap_install_ldap_callbacks is called with already "
                  "initialized sdap_fd_events.\n");
        return EINVAL;
    }

    sh->sdap_fd_events = talloc_zero(sh, struct sdap_fd_events);
    if (!sh->sdap_fd_events) {
        DEBUG(SSSDBG_CRIT_FAILURE, "talloc_zero failed.\n");
        return ENOMEM;
    }

    ret = get_fd_from_ldap(sh->ldap, &fd);
    if (ret) return ret;

    sh->sdap_fd_events->fde = tevent_add_fd(ev, sh->sdap_fd_events, fd,
                                            TEVENT_FD_READ, sdap_ldap_result,
                                            sh);
    if (!sh->sdap_fd_events->fde) {
        talloc_zfree(sh->sdap_fd_events);
        return ENOMEM;
    }

    DEBUG(SSSDBG_TRACE_INTERNAL,
          "Trace: sh[%p], connected[%d], ops[%p], fde[%p], ldap[%p]\n",
              sh, (int)sh->connected, sh->ops, sh->sdap_fd_events->fde,
              sh->ldap);

    return EOK;
}

#endif


errno_t setup_ldap_connection_callbacks(struct sdap_handle *sh,
                                        struct tevent_context *ev)
{
#ifdef HAVE_LDAP_CONNCB
    int ret;
    struct ldap_cb_data *cb_data;

    sh->sdap_fd_events = talloc_zero(sh, struct sdap_fd_events);
    if (sh->sdap_fd_events == NULL) {
        DEBUG(SSSDBG_CRIT_FAILURE, "talloc_zero failed.\n");
        ret = ENOMEM;
        goto fail;
    }

    sh->sdap_fd_events->conncb = talloc_zero(sh->sdap_fd_events,
                                             struct ldap_conncb);
    if (sh->sdap_fd_events->conncb == NULL) {
        DEBUG(SSSDBG_CRIT_FAILURE, "talloc_zero failed.\n");
        ret = ENOMEM;
        goto fail;
    }

    cb_data = talloc_zero(sh->sdap_fd_events->conncb, struct ldap_cb_data);
    if (cb_data == NULL) {
        DEBUG(SSSDBG_CRIT_FAILURE, "talloc_zero failed.\n");
        ret = ENOMEM;
        goto fail;
    }
    cb_data->sh = sh;
    cb_data->ev = ev;

    sh->sdap_fd_events->conncb->lc_add = sdap_ldap_connect_callback_add; //建立连接后调用
    sh->sdap_fd_events->conncb->lc_del = sdap_ldap_connect_callback_del; //在连接关闭之前调用
    sh->sdap_fd_events->conncb->lc_arg = cb_data;

    ret = ldap_set_option(sh->ldap, LDAP_OPT_CONNECT_CB,
                          sh->sdap_fd_events->conncb);  //设置连接回调，此选项特定于OpenLDAP
    if (ret != LDAP_OPT_SUCCESS) {
        DEBUG(SSSDBG_CRIT_FAILURE, "Failed to set connection callback\n");
        ret = EFAULT;
        goto fail;
    }

    talloc_set_destructor((TALLOC_CTX *) sh->sdap_fd_events->conncb,
                          remove_connection_callback);

    return EOK;

fail:
    talloc_zfree(sh->sdap_fd_events);
    return ret;
#else
    DEBUG(SSSDBG_TRACE_ALL, "LDAP connection callbacks are not supported.\n");
    return EOK;
#endif
}

errno_t sdap_set_connected(struct sdap_handle *sh, struct tevent_context *ev)
{
    int ret = EOK;

    sh->connected = true;

#ifndef HAVE_LDAP_CONNCB
    ret = sdap_install_ldap_callbacks(sh, ev);
#endif

    return ret;
}

errno_t sdap_call_conn_cb(const char *uri,int fd, struct sdap_handle *sh)
{
#ifdef HAVE_LDAP_CONNCB
    int ret;
    Sockbuf *sb;
    LDAPURLDesc *lud;

/*
*这些例程用于管理底层I / O操作
*        由轻型BER库执行。 它们被隐式调用
*       由其他库调用，通常不需要直接调用
*        从应用程序。 I / O框架是模块化的并且是新的
*       可以通过适当定义
*       Sockbuf_IO结构并将其安装到现有的Sockbuf上。
*       Sockbuf结构由ber_sockbuf_alloc（）分配和释放
*       ber_sockbuf_free（）。 ber_sockbuf_ctrl（）函数是
*       用于获取和设置与Sockbuf或特定I / O相关的选项
*        Sockbuf的一层。 ber_sockbuf_add_io（）和
*        ber_sockbuf_remove_io（）函数用于添加和删除特定的
*       Sockbuf上的I / O层。
*
*/

    sb = ber_sockbuf_alloc();
    if (sb == NULL) {
        DEBUG(SSSDBG_CRIT_FAILURE, "ber_sockbuf_alloc failed.\n");
        return ENOMEM;
    }
//将Sockbuf的文件描述符设置为arg指向的描述符； arg必须是ber_socket_t *。
//返回值将始终为1。
    ret = ber_sockbuf_ctrl(sb, LBER_SB_OPT_SET_FD, &fd);
    if (ret != 1) {
        DEBUG(SSSDBG_CRIT_FAILURE, "ber_sockbuf_ctrl failed.\n");
        return EFAULT;
    }
//返回LDAP URL描述的地址。 应用程序应调用ldap_free_urldesc（）例程以在不再需要时释放URL描述。
//由LDAP_LIBASCII编译器变量确定，将在本地EBCDIC代码页或UTF-8中返回文本数据。
    ret = ldap_url_parse(uri, &lud);
    if (ret != 0) {
        ber_sockbuf_free(sb);
        DEBUG(SSSDBG_CRIT_FAILURE,
              "ldap_url_parse failed to validate [%s] on fd [%d].\n",
               uri, fd);
        return EFAULT;
    }

    ret = sdap_ldap_connect_callback_add(NULL, sb, lud, NULL,
                                         sh->sdap_fd_events->conncb);

    ldap_free_urldesc(lud);
    ber_sockbuf_free(sb);
    return ret;   //成功返回0
#else
    DEBUG(SSSDBG_TRACE_ALL, "LDAP connection callbacks are not supported.\n");
    return EOK;
#endif
}
