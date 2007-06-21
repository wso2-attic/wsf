dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(wsfc-samples-src, 1.1.0)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
dnl AM_INIT_AUTOMAKE([tar-ustar])
AM_INIT_AUTOMAKE
AC_PREFIX_DEFAULT(/usr/local/wsf_c)
m4_ifdef([_A][M_PROG_TAR],[_A][M_SET_OPTION([tar-ustar])])

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AM_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET


#CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE -Wno-implicit-function-declaration"
CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Wall -Werror -Wno-implicit-function-declaration -g"
fi
LDFLAGS="$LDFLAGS -lpthread"

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])
AC_CHECK_HEADERS([sys/socket.h])

abs_top_builddir=`pwd`
AC_SUBST(abs_top_builddir)

AC_MSG_CHECKING(To Use WSF/C . This is a compulsory module to build WSF/C samples)
AC_ARG_WITH(wsfc,
[  --with-wsfc[=PATH]      use wsfc.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find axis2_util include dir in the path
    if test -d $withval; then
        wsfcinc="-I$withval"
    dnl else find the axis2_util include dir in $(AXIS2C_HOME)/include
    elif test -d '$(WSFC_HOME)/include'; then
        wsfcinc="-I$(WSFC_HOME)/include/"
    else
        AC_MSG_ERROR(could not find WSF/C. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

WSFCINC=$wsfcinc
AXIS2INC="$wsfcinc/axis2-1.1"

AC_SUBST(WSFCINC)
AC_SUBST(AXIS2INC)


export prefix 

AC_CONFIG_FILES([Makefile  \
    flicker/Makefile
    ])
    
AC_OUTPUT
