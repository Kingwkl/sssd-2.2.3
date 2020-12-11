/*
    Generated by sbus code generator

    Copyright (C) 2017 Red Hat

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

#include <errno.h>
#include <stdint.h>
#include <talloc.h>
#include <stdbool.h>
#include <dbus/dbus.h>

#include "sbus/interface/sbus_iterator_readers.h"
#include "sbus/interface/sbus_iterator_writers.h"
#include "sbus/interface_dbus/sbus_dbus_arguments.h"

errno_t _sbus_dbus_invoker_read_as
   (TALLOC_CTX *mem_ctx,
    DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_as *args)
{
    errno_t ret;

    ret = sbus_iterator_read_as(mem_ctx, iter, &args->arg0);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_write_as
   (DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_as *args)
{
    errno_t ret;

    ret = sbus_iterator_write_as(iter, args->arg0);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_read_b
   (TALLOC_CTX *mem_ctx,
    DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_b *args)
{
    errno_t ret;

    ret = sbus_iterator_read_b(iter, &args->arg0);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_write_b
   (DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_b *args)
{
    errno_t ret;

    ret = sbus_iterator_write_b(iter, args->arg0);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_read_s
   (TALLOC_CTX *mem_ctx,
    DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_s *args)
{
    errno_t ret;

    ret = sbus_iterator_read_s(mem_ctx, iter, &args->arg0);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_write_s
   (DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_s *args)
{
    errno_t ret;

    ret = sbus_iterator_write_s(iter, args->arg0);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_read_ss
   (TALLOC_CTX *mem_ctx,
    DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_ss *args)
{
    errno_t ret;

    ret = sbus_iterator_read_s(mem_ctx, iter, &args->arg0);
    if (ret != EOK) {
        return ret;
    }

    ret = sbus_iterator_read_s(mem_ctx, iter, &args->arg1);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_write_ss
   (DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_ss *args)
{
    errno_t ret;

    ret = sbus_iterator_write_s(iter, args->arg0);
    if (ret != EOK) {
        return ret;
    }

    ret = sbus_iterator_write_s(iter, args->arg1);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_read_sss
   (TALLOC_CTX *mem_ctx,
    DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_sss *args)
{
    errno_t ret;

    ret = sbus_iterator_read_s(mem_ctx, iter, &args->arg0);
    if (ret != EOK) {
        return ret;
    }

    ret = sbus_iterator_read_s(mem_ctx, iter, &args->arg1);
    if (ret != EOK) {
        return ret;
    }

    ret = sbus_iterator_read_s(mem_ctx, iter, &args->arg2);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_write_sss
   (DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_sss *args)
{
    errno_t ret;

    ret = sbus_iterator_write_s(iter, args->arg0);
    if (ret != EOK) {
        return ret;
    }

    ret = sbus_iterator_write_s(iter, args->arg1);
    if (ret != EOK) {
        return ret;
    }

    ret = sbus_iterator_write_s(iter, args->arg2);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_read_su
   (TALLOC_CTX *mem_ctx,
    DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_su *args)
{
    errno_t ret;

    ret = sbus_iterator_read_s(mem_ctx, iter, &args->arg0);
    if (ret != EOK) {
        return ret;
    }

    ret = sbus_iterator_read_u(iter, &args->arg1);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_write_su
   (DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_su *args)
{
    errno_t ret;

    ret = sbus_iterator_write_s(iter, args->arg0);
    if (ret != EOK) {
        return ret;
    }

    ret = sbus_iterator_write_u(iter, args->arg1);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_read_u
   (TALLOC_CTX *mem_ctx,
    DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_u *args)
{
    errno_t ret;

    ret = sbus_iterator_read_u(iter, &args->arg0);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

errno_t _sbus_dbus_invoker_write_u
   (DBusMessageIter *iter,
    struct _sbus_dbus_invoker_args_u *args)
{
    errno_t ret;

    ret = sbus_iterator_write_u(iter, args->arg0);
    if (ret != EOK) {
        return ret;
    }

    return EOK;
}

