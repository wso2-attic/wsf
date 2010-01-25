dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(savanc-sample-src, 1.1.0)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
dnl AM_INIT_AUTOMAKE([tar-ustar])
AM_INIT_AUTOMAKE
m4_ifdef([_A][M_PROG_TAR],[_A][M_SET_OPTION([tar-ustar])])
AC_PREFIX_DEFAULT(/usr/local/savanc)

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

dnl check for flavours of varargs macros (test from GLib)
AC_MSG_CHECKING(for ISO C99 varargs macros in C)
AC_TRY_COMPILE([],[
int a(int p1, int p2, int p3);
#define call_a(...) a(1,__VA_ARGS__)
call_a(2,3);
],savanc_have_iso_c_varargs=yes,savanc_have_iso_c_varargs=no)
AC_MSG_RESULT($savanc_have_iso_c_varargs)

AC_MSG_CHECKING(for GNUC varargs macros)
AC_TRY_COMPILE([],[
int a(int p1, int p2, int p3);
#define call_a(params...) a(1,params)
call_a(2,3);
],savanc_have_gnuc_varargs=yes,savanc_have_gnuc_varargs=no)
AC_MSG_RESULT($savanc_have_gnuc_varargs)

dnl Output varargs tests
if test x$savanc_have_iso_c_varargs = xyes; then
    AC_DEFINE(HAVE_ISO_VARARGS,1,[Have ISO C99 varargs macros])
fi
if test x$savanc_have_gnuc_varargs = xyes; then
    AC_DEFINE(HAVE_GNUC_VARARGS,1,[Have GNU-style varargs macros])
fi

dnl Checks for libraries.
AC_CHECK_LIB(dl, dlopen)

CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE -Werror"
LDFLAGS="$LDFLAGS -lpthread"

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
dnl AC_FUNC_MALLOC
dnl AC_FUNC_REALLOC

CFLAGS="$CFLAGS $LIBXML2_CFLAGS $GUTHTHILA_CFLAGS"

AC_MSG_CHECKING(To Use Axis2 C . This is a compulsory module to build Axis2 C samples)
AC_ARG_WITH(axis2,
[  --with-axis2[=PATH]     Find the AXIS2 header files in 'PATH'.
    'PATH' should point to AXIS2 include files location.
    If you omit the '=PATH' part completely, the configure script will search
    '$(AXIS2C_HOME)/include/axis2-1.4.0' for AXIS2 headers.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find axiom include dir in the path
    if test -d $withval; then
        axis2inc="-I$withval"
    dnl else find the axiom include dir in $(AXIS2C_HOME)/include
    elif test -d '$(AXIS2C_HOME)/include'; then
        axiominc="-I$(AXIS2C_HOME)/include/axis2-1.4.0"
    else
        AC_MSG_ERROR(could not find axis2. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(To Use Savan C . This is a compulsory module to build Savan C samples)
AC_ARG_WITH(savan,
[  --with-savan[=PATH]     Find the SAVAN header files in 'PATH'.
    'PATH' should point to SAVAN include files location.
    If you omit the '=PATH' part completely, the configure script will search
    '$(AXIS2C_HOME)/include/savan-0.90' for SAVAN headers.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find savan include dir in the path
    if test -d $withval; then
        savaninc="-I$withval"
    dnl else find the savan include dir in $(AXIS2C_HOME)/include
    elif test -d '$(AXIS2C_HOME)/include'; then
        savaninc="-I$(AXIS2C_HOME)/include/savan-0.90"
    else
        AC_MSG_ERROR(could not find savan. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

SAVANINC=$savaninc
AXIS2INC=$axis2inc

AC_SUBST(SAVANINC)
AC_SUBST(AXIS2INC)
AC_SUBST(LIBXML2_CFLAGS)
AC_SUBST(LIBXML2_LIBS)
AC_SUBST(LIBXML2_DIR)
AC_SUBST(GUTHTHILA_DIR)
AC_SUBST(GUTHTHILA_LIBS)

AC_CONFIG_FILES([Makefile \
    server/Makefile \
    server/wso2/Makefile \
    server/wsfc/Makefile \
    client/Makefile \
    client/subscriber/Makefile
    ])
    
AC_OUTPUT
