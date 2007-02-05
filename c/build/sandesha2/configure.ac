dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(sandesha2c-src, M1_pre)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AC_PREFIX_DEFAULT(/usr/local/sandesha2c)

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
    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration"
fi
LDFLAGS="-lpthread"

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
#AC_CHECK_FUNCS([memmove])

AC_MSG_CHECKING(path to use Axis2C . This is a compulsory to build Sandesha2C)
AC_ARG_WITH(axis2,
[  --with-axis2[=PATH]      use axis2c.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT($withval)
    dnl Find axis2 include dir in the path
    if test -d $withval; then
        axis2inc="-I$withval"
    dnl else find the axis2inc include dir in $(AXIS2C_HOME)/include
    elif test -d '$(AXIS2C_HOME)/include'; then
        axis2inc="-I$(AXIS2C_HOME)/include"
    else
        AC_MSG_ERROR(could not find axis2inc. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AXIS2INC=$axis2inc

AC_SUBST(AXIS2INC)
AC_SUBST(AXIOMINC)
AC_SUBST(UTILINC)

AC_CONFIG_FILES([Makefile \
    src/Makefile \
    src/util/Makefile \
    src/wsrm/Makefile\
    src/transport/Makefile\
    src/workers/Makefile\
    src/handlers/Makefile\
    src/msgprocessors/Makefile\
    src/storage/Makefile\
    src/storage/beans/Makefile\
    src/storage/inmemory/Makefile\
    src/client/Makefile \
    src/core/Makefile \
    src/polling/Makefile 
    ])
    
AC_OUTPUT
