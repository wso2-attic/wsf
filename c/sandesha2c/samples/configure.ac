dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(sandesha2-sample-src, 0.93)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
dnl AM_INIT_AUTOMAKE([tar-ustar])
AM_INIT_AUTOMAKE
AC_PREFIX_DEFAULT(/usr/local/sandesha2/samples)
m4_ifdef([_A][M_PROG_TAR],[_A][M_SET_OPTION([tar-ustar])])

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

dnl Checks for libraries.
AC_CHECK_LIB(dl, dlopen)

CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE"
LDFLAGS="-L$AXIS2C_HOME/lib -lpthread"

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC

PKG_CHECK_MODULES(LIBXML2, libxml-2.0)
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS $LIBXML2_CFLAGS $GUTHTHILA_CFLAGS -g"
fi

AC_MSG_CHECKING(To Use Axis2 C Axis2. This is a compulsory module to build Sandesha2 C)
AC_ARG_WITH(axis2,
[  --with-axis2[=PATH]      use axis2.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find axis2_util include dir in the path
    if test -d $withval; then
        axis2inc="-I$withval"
    dnl else find the axis2_util include dir in $(AXIS2C_HOME)/include
    elif test -d '$(AXIS2C_HOME)/include'; then
        axis2inc="-I$(AXIS2C_HOME)/include/axis2-1.1"
    else
        AC_MSG_ERROR(could not find Axis2. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)


APACHE2INC=$apache2inc
AXIS2INC=$axis2inc
APRINC=$aprinc

AC_SUBST(APACHE2INC)
AC_SUBST(APRINC)
AC_SUBST(AXIS2INC)
AC_SUBST(LIBXML2_CFLAGS)
AC_SUBST(LIBXML2_LIBS)
AC_SUBST(LIBXML2_DIR)
AC_SUBST(GUTHTHILA_DIR)
AC_SUBST(GUTHTHILA_LIBS)
AC_SUBST(DICLIENT_DIR)

AC_CONFIG_FILES([Makefile \
    RMSampleService/Makefile \
    rm_echo_1_0/Makefile \
    rm_echo_1_1/Makefile \
    rm_echo_single_1_0/Makefile \
    rm_echo_single_1_1/Makefile \
    rm_ping_1_0/Makefile \
    rm_ping_1_1/Makefile \
    rm_mtom_1_0/Makefile \
    rm_report/Makefile \
    resources/Makefile
    ])
    
AC_OUTPUT
