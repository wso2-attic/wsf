dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(reg_client, 0.01)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
dnl AM_INIT_AUTOMAKE([tar-ustar])
AM_INIT_AUTOMAKE
AC_PREFIX_DEFAULT(/usr/local/reg_client/samples)
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

CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE -g -Werror"
LDFLAGS="-L$AXIS2C_HOME/lib -lpthread"

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC

AC_MSG_CHECKING(To Use Axis2 C Axis2. This is a compulsory module to build Registry Client C)
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
        axis2inc="-I$(AXIS2C_HOME)/include/axis2-1.5"
    else
        AC_MSG_ERROR(could not find Axis2. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(To Use Savan C . This is a compulsory module to build Registry Client C)
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

AC_CONFIG_FILES([Makefile \
                 src/Makefile \
                 samples/Makefile \
                 samples/server/Makefile \
                 samples/server/wso2/Makefile \
                 samples/server/wsfc/Makefile \
                 samples/client/Makefile \
                 samples/client/subscriber/Makefile \
                 test/Makefile])
    
AC_OUTPUT
