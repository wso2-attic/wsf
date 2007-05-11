dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(rampart-samples-src, 0.90)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([tar-ustar])
AC_PREFIX_DEFAULT(/usr/local/rampart/samples)

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AM_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

dnl check for flavours of varargs macros (test from GLib)
AC_MSG_CHECKING(for ISO C99 varargs macros in C)
AC_TRY_COMPILE([],[
int a(int p1, int p2, int p3);
#define call_a(...) a(1,__VA_ARGS__)
call_a(2,3);
],axis2c_have_iso_c_varargs=yes,axis2c_have_iso_c_varargs=no)
AC_MSG_RESULT($axis2c_have_iso_c_varargs)

AC_MSG_CHECKING(for GNUC varargs macros)
AC_TRY_COMPILE([],[
int a(int p1, int p2, int p3);
#define call_a(params...) a(1,params)
call_a(2,3);
],axis2c_have_gnuc_varargs=yes,axis2c_have_gnuc_varargs=no)
AC_MSG_RESULT($axis2c_have_gnuc_varargs)

dnl Output varargs tests
if test x$axis2c_have_iso_c_varargs = xyes; then
    AC_DEFINE(HAVE_ISO_VARARGS,1,[Have ISO C99 varargs macros])
fi
if test x$axis2c_have_gnuc_varargs = xyes; then
    AC_DEFINE(HAVE_GNUC_VARARGS,1,[Have GNU-style varargs macros])
fi

dnl Checks for libraries.
AC_CHECK_LIB(dl, dlopen)

CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Wall -Werror -Wno-implicit-function-declaration"
fi

LDFLAGS="$LDFLAGS -lpthread"

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
#AC_CHECK_FUNCS([memmove])


AXIOMINC=$axiominc
UTILINC=$axis2_utilinc
XMLSCHEMAINC=$axis2_xml_schemainc

AC_SUBST(AXIOMINC)
AC_SUBST(UTILINC)
AC_SUBST(XMLSCHEMAINC)
AC_SUBST(TESTDIR)
AC_SUBST(PARSER_DIR)

AC_CONFIG_FILES([Makefile \
        data/Makefile \
        callback/Makefile \
        callback/htpasswd_callback/Makefile \
        authn_provider/Makefile \
        credential_provider/Makefile \
        server/Makefile \
        server/sec_echo/Makefile \
        client/Makefile
        client/sec_echo/Makefile \
        client/sec_echo/data/Makefile \
        omxmlsec/Makefile \
        omxmlsec/xmlsig/Makefile \
        omxmlsec/xmlenc/Makefile \
        keys/Makefile \
        keys/ahome/Makefile \
        keys/bhome/Makefile \
        keys/xhome/Makefile \
        keys/yhome/Makefile \
	secpolicy/Makefile \
	secpolicy/scenario1/Makefile \
	secpolicy/scenario2/Makefile \
	secpolicy/scenario3/Makefile \
	secpolicy/scenario4/Makefile \
	secpolicy/scenario5/Makefile \
	secpolicy/scenario6/Makefile \
	secpolicy/scenario7/Makefile \
	secpolicy/scenario8/Makefile \
	secpolicy/scenario9/Makefile
    ])
    
AC_OUTPUT
