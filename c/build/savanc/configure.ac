dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(rampartc-src, 0.93)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([tar-ustar])
AC_PREFIX_DEFAULT(/usr/local/rampartc)

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AM_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

dnl Checks for libraries.
AC_CHECK_LIB(dl, dlopen)

CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Werror -Wall -Wno-implicit-function-declaration"
    #CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration"
fi
LDFLAGS="-lpthread"

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])

dnl Checks for typedefs, structures, and compiler characteristics.
dnl AC_C_CONST

dnl Checks for library functions.
dnl AC_FUNC_MALLOC
dnl AC_FUNC_REALLOC
#AC_CHECK_FUNCS([memmove])

AC_MSG_CHECKING(To Use Axis2 C AXIOM. This is a compulsory module to build Axis2 C)
AC_ARG_WITH(axiom,
[  --with-axiom[=PATH]      use axiom.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find axiom include dir in the path
    if test -d $withval; then
        axiominc="-I$withval"
    dnl else find the axiom include dir in $(AXIS2C_HOME)/include
    elif test -d '$(AXIS2C_HOME)/include'; then
        axiominc="-I$(AXIS2C_HOME)/include"
    else
        AC_MSG_ERROR(could not find axiom. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(To Use Axis2 C Util. This is a compulsory module to build Axis2 C)
AC_ARG_WITH(axis2_util,
[  --with-axis2_util[=PATH]      use axis2_util.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find axis2_util include dir in the path
    if test -d $withval; then
        axis2_utilinc="-I$withval"
    dnl else find the axis2_util include dir in $(AXIS2C_HOME)/include
    elif test -d './axis2c/include'; then
        axis2_utilinc="-I./axis2c/include"
    else
        AC_MSG_ERROR(could not find axis2_util. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(To Use Xml Schema. This is a compulsory module to build Woden C)

AXIOMINC=$axiominc
UTILINC=$axis2_utilinc

AC_SUBST(AXIOMINC)
AC_SUBST(UTILINC)
AC_SUBST(XMLSCHEMAINC)

AC_CONFIG_FILES([Makefile \
    src/Makefile \
    src/client/Makefile\
    src/core/Makefile\
    src/handlers/Makefile \
    src/msgreceivers/Makefile\
    src/subscribers/Makefile\
    src/data/Makefile\
    src/util/Makefile\
    samples/Makefile\
    samples/client/Makefile\
    samples/client/subscriber/Makefile\
    samples/server/Makefile\
    samples/server/publisher/Makefile\
    samples/server/listener/Makefile\
    ])
    
AC_OUTPUT
