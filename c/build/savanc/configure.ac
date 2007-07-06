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
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

dnl Checks for libraries.
AC_CHECK_LIB(dl, dlopen)

CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Wall -Werror -Wno-implicit-function-declaration"
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
abs_top_builddir=`pwd`
AC_SUBST(abs_top_builddir)

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
        AXIS2INC="-I$withval"
    dnl else find the axis2inc include dir in $(AXIS2C_HOME)/include
    elif [ -d "$abs_top_builddir" ]; then
            AXIS2INC="-I$abs_top_builddir/../axis2c/include"
    else
        AC_MSG_ERROR(could not find axis2inc. stop)
    fi
    ;;
  esac ],
  AXIS2INC="-I$abs_top_builddir/../axis2c/include"
  AC_MSG_RESULT(no)
)



AC_MSG_CHECKING(To Use Xml Schema. This is a compulsory module to build Woden C)
AXIOMINC="-I$abs_top_builddir/../axis2c/axiom/include"
UTILINC="-I$abs_top_builddir/../axis2c/util/include"
NEETHIINC="-I$abs_top_builddir/../axis2c/neethi/include"
AC_SUBST(AXIS2INC)
AC_SUBST(AXIOMINC)
AC_SUBST(UTILINC)
AC_SUBST(NEETHIINC)
AC_SUBST(XMLSCHEMAINC)

AC_CONFIG_FILES([Makefile \
    src/Makefile \
    src/client/Makefile\
    src/core/Makefile\
    src/handlers/Makefile \
    src/msgreceivers/Makefile\
    src/subscribers/Makefile\
    src/subs_mgr/Makefile\
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
