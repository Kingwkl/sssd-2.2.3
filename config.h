/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Absolute path to the build directory */
#define ABS_BUILD_DIR "/home/wkl/下载/sssd_2.2.3.orig/sssd-2.2.3"

/* Absolute path to the source directory */
#define ABS_SRC_DIR "/home/wkl/下载/sssd_2.2.3.orig/sssd-2.2.3"

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* whether to build unconditionally enable files domain */
/* #undef ADD_FILES_DOMAIN */

/* "The default enforcing level for AD GPO access-control" */
#define AD_GPO_ACCESS_MODE_DEFAULT "enforcing"

/* Path to the 3rd party modules */
#define APP_MODULES_PATH ""LIBDIR"/sssd/modules"

/* whether to build with AUTOFS support */
#define BUILD_AUTOFS 1

/* whether to build with InfoPipe support */
#define BUILD_IFP 1

/* whether to build with KCM server support */
#define BUILD_KCM 1

/* whether to build SSSD implementation of libwbclient */
#define BUILD_LIBWBCLIENT 1

/* whether to build unconditionally enable local provider */
/* #undef BUILD_LOCAL_PROVIDER */

/* whether to build with NFSv4 IDMAP support */
#define BUILD_NFS_IDMAP 1

/* whether to build with samba support */
#define BUILD_SAMBA 1

/* whether to build with SECRETS support */
/* #undef BUILD_SECRETS */

/* whether to build with SSH support */
#define BUILD_SSH 1

/* whether to build with SUDO support */
#define BUILD_SUDO 1

/* libsecret will be built */
#define BUILD_WITH_LIBSECRET 1

/* Path to the SSSD data provider plugins */
#define DATA_PROVIDER_PLUGINS_PATH ""LIBDIR"/sssd"

/* Path to the SSSD databases */
#define DB_PATH ""SSS_STATEDIR"/db"

/* The default value of krb5_ccachedir */
#define DEFAULT_CCACHE_DIR "/tmp"

/* The default value of krb5_ccname_template */
#define DEFAULT_CCNAME_TEMPLATE "FILE:%d/krb5cc_%U_XXXXXX"

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
#define ENABLE_NLS 1

/* Where to store GPO policy files */
#define GPO_CACHE_PATH ""SSS_STATEDIR"/gpo_cache"

/* Define to 1 if you have the <ares.h> header file. */
/* #undef HAVE_ARES_H */

/* whether platform is big endian */
/* #undef HAVE_BIG_ENDIAN */

/* Define to 1 if you have the <byteswap.h> header file. */
#define HAVE_BYTESWAP_H 1

/* Define to 1 if you have the MacOS X function CFLocaleCopyCurrent in the
   CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYCURRENT */

/* Define to 1 if you have the MacOS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */

/* Define to 1 if you have the <check.h> header file. */
/* #undef HAVE_CHECK_H */

/* Build with cifs idmap plugin */
#define HAVE_CIFS_IDMAP_PLUGIN 1

/* Define to 1 if the system has the type `DBusBasicValue'. */
#define HAVE_DBUSBASICVALUE 1

/* Define if dbus_watch_get_unix_fd exists */
#define HAVE_DBUS_WATCH_GET_UNIX_FD 1

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
#define HAVE_DCGETTEXT 1

/* Build with debian config */
/* #undef HAVE_DEBIAN */

/* Define to 1 if you have the declaration of `cygwin_conv_path', and to 0 if
   you don't. */
/* #undef HAVE_DECL_CYGWIN_CONV_PATH */

/* Define if you have the GNU dld library. */
/* #undef HAVE_DLD */

/* Define to 1 if you have the `dlerror' function. */
#define HAVE_DLERROR 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define if you have the _dyld_func_lookup function. */
/* #undef HAVE_DYLD */

/* Define to 1 if you have the <endian.h> header file. */
#define HAVE_ENDIAN_H 1

/* Define to 1 if the system has the type `errno_t'. */
/* #undef HAVE_ERRNO_T */

/* Define to 1 if you have the `explicit_bzero' function. */
#define HAVE_EXPLICIT_BZERO 1

/* Using faketime for some tests */
/* #undef HAVE_FAKETIME */

/* Build with fedora config */
#define HAVE_FEDORA 1

/* whether compiler supports __attribute__((destructor)) */
#define HAVE_FUNCTION_ATTRIBUTE_DESTRUCTOR 1

/* whether compiler supports __attribute__((format)) */
#define HAVE_FUNCTION_ATTRIBUTE_FORMAT 1

/* whether compiler supports __attribute__((warn_unused_result)) */
#define HAVE_FUNCTION_ATTRIBUTE_WARN_UNUSED_RESULT 1

/* Define to 1 if you have the `futimens' function. */
#define HAVE_FUTIMENS 1

/* Build with gdm-pam-extensions support */
#define HAVE_GDM_PAM_EXTENSIONS 1

/* Build with gentoo config */
/* #undef HAVE_GENTOO */

/* Define to 1 if you have the `getpgrp' function. */
#define HAVE_GETPGRP 1

/* Define if the GNU gettext() function is already present or preinstalled. */
#define HAVE_GETTEXT 1

/* Using glib2 for unicode */
#define HAVE_GLIB2 1

/* Define if g_utf8_validate exists */
#define HAVE_G_UTF8_VALIDATE 1

/* Define to 1 if you have the <http_parser.h> header file. */
/* #undef HAVE_HTTP_PARSER_H */

/* Define if you have the iconv() function. */
/* #undef HAVE_ICONV */

/* Inotify works */
#define HAVE_INOTIFY 1

/* Define to 1 if the system has the type `intptr_t'. */
#define HAVE_INTPTR_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <jansson.h> header file. */
/* #undef HAVE_JANSSON_H */

/* Define to 1 if you have the <keyutils.h> header file. */
#define HAVE_KEYUTILS_H 1

/* Define to 1 if you have the `krb5_cc_cache_match' function. */
#define HAVE_KRB5_CC_CACHE_MATCH 1

/* Define to 1 if you have the `krb5_cc_get_full_name' function. */
#define HAVE_KRB5_CC_GET_FULL_NAME 1

/* Define to 1 if you have the `krb5_find_authdata' function. */
#define HAVE_KRB5_FIND_AUTHDATA 1

/* Define to 1 if you have the `krb5_free_keytab_entry_contents' function. */
#define HAVE_KRB5_FREE_KEYTAB_ENTRY_CONTENTS 1

/* Define to 1 if you have the `krb5_free_unparsed_name' function. */
#define HAVE_KRB5_FREE_UNPARSED_NAME 1

/* Define to 1 if you have the `krb5_get_error_message' function. */
#define HAVE_KRB5_GET_ERROR_MESSAGE 1

/* Define to 1 if you have the `krb5_get_init_creds_opt_alloc' function. */
#define HAVE_KRB5_GET_INIT_CREDS_OPT_ALLOC 1

/* Define to 1 if you have the `krb5_get_init_creds_opt_set_canonicalize'
   function. */
#define HAVE_KRB5_GET_INIT_CREDS_OPT_SET_CANONICALIZE 1

/* Define to 1 if you have the
   `krb5_get_init_creds_opt_set_change_password_prompt' function. */
#define HAVE_KRB5_GET_INIT_CREDS_OPT_SET_CHANGE_PASSWORD_PROMPT 1

/* Define to 1 if you have the `krb5_get_init_creds_opt_set_expire_callback'
   function. */
#define HAVE_KRB5_GET_INIT_CREDS_OPT_SET_EXPIRE_CALLBACK 1

/* Define to 1 if you have the `krb5_get_init_creds_opt_set_fast_ccache_name'
   function. */
#define HAVE_KRB5_GET_INIT_CREDS_OPT_SET_FAST_CCACHE_NAME 1

/* Define to 1 if you have the `krb5_get_init_creds_opt_set_fast_flags'
   function. */
#define HAVE_KRB5_GET_INIT_CREDS_OPT_SET_FAST_FLAGS 1

/* Define to 1 if you have the `krb5_get_init_creds_opt_set_responder'
   function. */
#define HAVE_KRB5_GET_INIT_CREDS_OPT_SET_RESPONDER 1

/* Define to 1 if you have the `krb5_get_time_offsets' function. */
#define HAVE_KRB5_GET_TIME_OFFSETS 1

/* Define to 1 if you have the <krb5.h> header file. */
#define HAVE_KRB5_H 1

/* Define to 1 if you have the <krb5/krb5.h> header file. */
#define HAVE_KRB5_KRB5_H 1

/* Define to 1 if you have the `krb5_kt_free_entry' function. */
#define HAVE_KRB5_KT_FREE_ENTRY 1

/* Define to 1 if you have the `krb5_kt_have_content' function. */
#define HAVE_KRB5_KT_HAVE_CONTENT 1

/* Build with krb5 localauth plugin */
#define HAVE_KRB5_LOCALAUTH_PLUGIN 1

/* Build with krb5 locator plugin */
#define HAVE_KRB5_LOCATOR_PLUGIN 1

/* Define to 1 if you have the `krb5_parse_name_flags' function. */
#define HAVE_KRB5_PARSE_NAME_FLAGS 1

/* Define to 1 if you have the `krb5_principal_get_realm' function. */
/* #undef HAVE_KRB5_PRINCIPAL_GET_REALM */

/* Define to 1 if you have the `krb5_princ_realm' function. */
/* #undef HAVE_KRB5_PRINC_REALM */

/* Define to 1 if you have the `krb5_set_trace_callback' function. */
#define HAVE_KRB5_SET_TRACE_CALLBACK 1

/* Define to 1 if the system has the type `krb5_ticket_times'. */
#define HAVE_KRB5_TICKET_TIMES 1

/* Define to 1 if the system has the type `krb5_times'. */
/* #undef HAVE_KRB5_TIMES */

/* Define to 1 if you have the `krb5_timestamp_to_sfstring' function. */
#define HAVE_KRB5_TIMESTAMP_TO_SFSTRING 1

/* Define to 1 if the system has the type `krb5_trace_info'. */
#define HAVE_KRB5_TRACE_INFO 1

/* Define to 1 if you have the `krb5_unparse_name_flags' function. */
#define HAVE_KRB5_UNPARSE_NAME_FLAGS 1

/* Define if LDAP connection callbacks are available */
#define HAVE_LDAP_CONNCB 1

/* Define to 1 if you have the `ldap_control_create' function. */
#define HAVE_LDAP_CONTROL_CREATE 1

/* Define to 1 if you have the `ldap_create_deref_control_value' function. */
#define HAVE_LDAP_CREATE_DEREF_CONTROL_VALUE 1

/* Define to 1 if you have the `ldap_derefresponse_free' function. */
#define HAVE_LDAP_DEREFRESPONSE_FREE 1

/* Define to 1 if you have the `ldap_init_fd' function. */
#define HAVE_LDAP_INIT_FD 1

/* Define to 1 if you have the `ldap_parse_derefresponse_control' function. */
#define HAVE_LDAP_PARSE_DEREFRESPONSE_CONTROL 1

/* Define to 1 if you have the <ldb.h> header file. */
#define HAVE_LDB_H 1

/* Define to 1 if you have the <ldb_module.h> header file. */
#define HAVE_LDB_MODULE_H 1

/* Build with libcrypt crypto back end */
/* #undef HAVE_LIBCRYPTO */

/* Build with libcurl support */
/* #undef HAVE_LIBCURL */

/* Define if you have the libdl library or equivalent. */
#define HAVE_LIBDL 1

/* Define if libdlloader will be built on this platform */
#define HAVE_LIBDLLOADER 1

/* libini_config version 0.6.1 or greater */
#define HAVE_LIBINI_CONFIG_V0 1

/* libini_config version 1.0.0 or greater */
#define HAVE_LIBINI_CONFIG_V1 1

/* libini_config version 1.1.0 or greater */
#define HAVE_LIBINI_CONFIG_V1_1 1

/* libini_config version 1.3.0 or greater */
#define HAVE_LIBINI_CONFIG_V1_3 1

/* Build with libnetlink support */
/* #undef HAVE_LIBNL */

/* Libnetlink version = 1 */
/* #undef HAVE_LIBNL1 */

/* Libnetlink version = 3 */
/* #undef HAVE_LIBNL3 */

/* Define if libpcre2 is present */
/* #undef HAVE_LIBPCRE2 */

/* Define if libpcre version is less than 7 */
/* #undef HAVE_LIBPCRE_LESSER_THAN_7 */

/* Define if you have the librt library or equivalent. */
#define HAVE_LIBRT 1

/* Using libunistring for unicode */
/* #undef HAVE_LIBUNISTRING */

/* whether platform is little endian */
#define HAVE_LITTLE_ENDIAN 1

/* Define to 1 if the system has the type `long long'. */
#define HAVE_LONG_LONG 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <netlink.h> header file. */
/* #undef HAVE_NETLINK_H */

/* Define to 1 if you have the <nfsidmap_plugin.h> header file. */
#define HAVE_NFSIDMAP_PLUGIN_H 1

/* Does libnl have nl_set_passcred? */
/* #undef HAVE_NL_SET_PASSCRED */

/* Does libnl have nl_socket_add_membership? */
/* #undef HAVE_NL_SOCKET_ADD_MEMBERSHIP */

/* Does libnl have nl_socket_modify_cb? */
/* #undef HAVE_NL_SOCKET_MODIFY_CB */

/* Does libnl have nl_socket_set_passcred? */
/* #undef HAVE_NL_SOCKET_SET_PASSCRED */

/* flush nscd cache after local domain operations */
#define HAVE_NSCD /usr/sbin/nscd

/* Build with NSS crypto back end */
#define HAVE_NSS 1

/* Build with the PAC responder */
#define HAVE_PAC_RESPONDER 1

/* Define to 1 if you have the `pam_modutil_getlogin' function. */
#define HAVE_PAM_MODUTIL_GETLOGIN 1

/* Define to 1 if you have the `pam_vsyslog' function. */
#define HAVE_PAM_VSYSLOG 1

/* Define to 1 if you have the <pcre.h> header file. */
/* #undef HAVE_PCRE_H */

/* Define to 1 if you have the <popt.h> header file. */
/* #undef HAVE_POPT_H */

/* Define to 1 if you have the `prctl' function. */
#define HAVE_PRCTL 1

/* Pthread mutexes available. */
#define HAVE_PTHREAD 1

/* Build with python2 bindings */
/* #undef HAVE_PYTHON2_BINDINGS */

/* Build with python3 bindings */
/* #undef HAVE_PYTHON3_BINDINGS */

/* Build with redhat config */
/* #undef HAVE_REDHAT */

/* Does libnl have rtnl_route_get_oif? */
/* #undef HAVE_RTNL_ROUTE_GET_OIF */

/* Define to 1 if you have the <sasl/sasl.h> header file. */
/* #undef HAVE_SASL_SASL_H */

/* Define to 1 if you have the <security/openpam.h> header file. */
/* #undef HAVE_SECURITY_OPENPAM_H */

/* Define to 1 if you have the <security/pam_appl.h> header file. */
#define HAVE_SECURITY_PAM_APPL_H 1

/* Define to 1 if you have the <security/pam_ext.h> header file. */
#define HAVE_SECURITY_PAM_EXT_H 1

/* Define to 1 if you have the <security/pam_misc.h> header file. */
#define HAVE_SECURITY_PAM_MISC_H 1

/* Define to 1 if you have the <security/pam_modules.h> header file. */
#define HAVE_SECURITY_PAM_MODULES_H 1

/* Define to 1 if you have the <security/pam_modutil.h> header file. */
#define HAVE_SECURITY_PAM_MODUTIL_H 1

/* Define to 1 if you have the <security/_pam_macros.h> header file. */
#define HAVE_SECURITY__PAM_MACROS_H 1

/* Build with SELinux support */
#define HAVE_SELINUX 1

/* Define to 1 if you have the <selinux/selinux.h> header file. */
#define HAVE_SELINUX_SELINUX_H 1

/* Build with SELinux support */
#define HAVE_SEMANAGE 1

/* Define to 1 if you have the <semanage/semanage.h> header file. */
#define HAVE_SEMANAGE_SEMANAGE_H 1

/* Whether the service command is available */
#define HAVE_SERVICE 1

/* Define to 1 if you have the <setjmp.h> header file. */
/* #undef HAVE_SETJMP_H */

/* Define if you have the shl_load function. */
/* #undef HAVE_SHL_LOAD */

/* Define to 1 if you have the `sigaction' function. */
#define HAVE_SIGACTION 1

/* Define to 1 if you have the `sigblock' function. */
#define HAVE_SIGBLOCK 1

/* Define to 1 if you have the `sigprocmask' function. */
#define HAVE_SIGPROCMASK 1

/* Define to 1 if you have the <stdarg.h> header file. */
/* #undef HAVE_STDARG_H */

/* Define to 1 if you have the <stddef.h> header file. */
/* #undef HAVE_STDDEF_H */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if `lc_arg' is a member of `struct ldap_conncb'. */
#define HAVE_STRUCT_LDAP_CONNCB_LC_ARG 1

/* Define to 1 if `resource_groups' is a member of `struct PAC_LOGON_INFO'. */
#define HAVE_STRUCT_PAC_LOGON_INFO_RESOURCE_GROUPS 1

/* Define to 1 if `gid' is a member of `struct ucred'. */
#define HAVE_STRUCT_UCRED_GID 1

/* Define to 1 if `pid' is a member of `struct ucred'. */
#define HAVE_STRUCT_UCRED_PID 1

/* Define to 1 if `uid' is a member of `struct ucred'. */
#define HAVE_STRUCT_UCRED_UID 1

/* Build with suse config */
/* #undef HAVE_SUSE */

/* Build with systemd support */
/* #undef HAVE_SYSTEMD */

/* Build with $daemon_lib_name support */
/* #undef HAVE_SYSTEMD_DAEMON */

/* Build with $login_lib_name support */
/* #undef HAVE_SYSTEMD_LOGIN */

/* Define to 1 if systemtap is enabled */
/* #undef HAVE_SYSTEMTAP */

/* Define to 1 if you have the <sys/endian.h> header file. */
/* #undef HAVE_SYS_ENDIAN_H */

/* Define to 1 if you have the <sys/inotify.h> header file. */
#define HAVE_SYS_INOTIFY_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <tdb.h> header file. */
/* #undef HAVE_TDB_H */

/* Build with certificates from test CA */
#define HAVE_TEST_CA 1

/* Define if struct ucred is available */
#define HAVE_UCRED 1

/* Define to 1 if you have the <unicase.h> header file. */
/* #undef HAVE_UNICASE_H */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the <unistr.h> header file. */
/* #undef HAVE_UNISTR_H */

/* Define to 1 if you have the `utimensat' function. */
#define HAVE_UTIMENSAT 1

/* Define to 1 if you have the <uuid/uuid.h> header file. */
/* #undef HAVE_UUID_UUID_H */

/* The path to the ipa-getkeytab utility */
#define IPA_GETKEYTAB_PATH "/usr/sbin/ipa-getkeytab"

/* KRB5 configuration file */
#define KRB5_CONF_PATH ""SYSCONFDIR"/krb5.conf"

/* Directory used for storing Kerberos replay caches */
#define KRB5_RCACHE_DIR "__LIBKRB5_DEFAULTS__"

/* Where to store log files for the SSSD */
#define LOG_PATH ""VARDIR"/log/sssd"

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Where to store mmap cache files for the SSSD interconnects */
#define MCACHE_PATH ""SSS_STATEDIR"/mc"

/* The shell used to deny access to users */
#define NOLOGIN_SHELL "/sbin/nologin"

/* whether to build sssd nss plugin with nonstandard glibc behaviour */
/* #undef NONSTANDARD_SSS_NSS_BEHAVIOUR */

/* NSCD configuration file */
#define NSCD_CONF_PATH "/etc/nscd.conf"

/* The path to nscd, if available */
#define NSCD_PATH "/usr/sbin/nscd"

/* The path to nsupdate */
#define NSUPDATE_PATH "/usr/bin/nsupdate"

/* Name of package */
#define PACKAGE "sssd"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "sssd-devel@lists.fedorahosted.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "sssd"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "sssd 2.2.3"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "sssd"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "2.2.3"

/* Define libpcre2 unit size */
/* #undef PCRE2_CODE_UNIT_WIDTH */

/* Where to store pid files for the SSSD */
#define PID_PATH ""VARDIR"/run"

/* Where to store pipe files for the SSSD interconnects */
#define PIPE_PATH ""SSS_STATEDIR"/pipes"

/* Prerelease version number of package */
#define PRERELEASE_VERSION ""

/* Where to store pubconf files for the SSSD */
#define PUBCONF_PATH ""SSS_STATEDIR"/pubconf"

/* The path of libpython for dlopen-tests */
/* #undef PYTHON_DLOPEN_LIB */

/* Path to the SSSD Secrets databases */
#define SECRETS_DB_PATH ""SSS_STATEDIR"/secrets"

/* The path to service */
#define SERVICE_PATH "/sbin/service"

/* The shell used to record user sessions */
#define SESSION_RECORDING_SHELL "/usr/bin/tlog-rec-session"

/* The size of `char', as computed by sizeof. */
#define SIZEOF_CHAR 1

/* The size of `gid_t', as computed by sizeof. */
#define SIZEOF_GID_T 4

/* The size of `id_t', as computed by sizeof. */
#define SIZEOF_ID_T 4

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 8

/* The size of `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8

/* The size of `off_t', as computed by sizeof. */
#define SIZEOF_OFF_T 8

/* The size of `short', as computed by sizeof. */
#define SIZEOF_SHORT 2

/* The size of `size_t', as computed by sizeof. */
#define SIZEOF_SIZE_T 8

/* The size of `ssize_t', as computed by sizeof. */
#define SIZEOF_SSIZE_T 8

/* The size of `uid_t', as computed by sizeof. */
#define SIZEOF_UID_T 4

/* Samba's struct idmap_domain has dom_sid member */
#define SMB_IDMAP_DOMAIN_HAS_DOM_SID 1

/* Detected version of Samba's idmap plugin interface */
#define SMB_IDMAP_INTERFACE_VERSION 6

/* Path to softhsm2 PKCS#11 module */
/* #undef SOFTHSM2_PATH */

/* "The default user to run SSSD as" */
#define SSSD_USER "root"

/* __attribute__((fallthrough)) if supported */
#define SSS_ATTRIBUTE_FALLTHROUGH __attribute__ ((fallthrough))

/* Define to 1 if you want ldb version check. */
/* #undef SSS_LDB_VERSION_CHECK */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Directory used for 'make check' temporary files */
#define TEST_DIR "."

/* Define if the keyring should be used */
#define USE_KEYRING 1

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif


/* Version number of package */
#define VERSION "2.2.3"

/* journald is available */
/* #undef WITH_JOURNALD */

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */

/* Define to `short' if <sys/types.h> does not define. */
/* #undef int16_t */

/* Define to `long' if <sys/types.h> does not define. */
/* #undef int32_t */

/* Define to `long long' if <sys/types.h> does not define. */
/* #undef int64_t */

/* Define to `char' if <sys/types.h> does not define. */
/* #undef int8_t */

/* Define to `long long' if <stdint.h> does not define. */
/* #undef intptr_t */

/* Define to `unsigned long long' if <sys/types.h> does not define. */
/* #undef ptrdiff_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef ssize_t */

/* Define to `unsigned short' if <sys/types.h> does not define. */
/* #undef uint16_t */

/* Define to `unsigned long' if <sys/types.h> does not define. */
/* #undef uint32_t */

/* Define to `unsigned long long' if <sys/types.h> does not define. */
/* #undef uint64_t */

/* Define to `unsigned char' if <sys/types.h> does not define. */
/* #undef uint8_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
#define uint_t unsigned int

/* Define to `unsigned long long' if <sys/types.h> does not define. */
/* #undef uintptr_t */
