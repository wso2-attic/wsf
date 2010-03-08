dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(wsfc-samples-src, 2.0.0)
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
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET


#CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE -Wno-implicit-function-declaration"
CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Wall  -Wno-implicit-function-declaration -g"
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
    dnl Find wsfc include dir in the path
    if test -d $withval; then
        wsfcinc="-I$withval"
    dnl else find the wsfc include dir in $(WSFC_HOME)/include
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
AXIS2INC="$wsfcinc"
SANDESHA2INC="$wsfcinc"
RAMPARTINC="$wsfcinc"

AC_SUBST(WSFCINC)
AC_SUBST(AXIS2INC)
AC_SUBST(SANDESHA2INC)
AC_SUBST(RAMPARTINC)


export prefix 

AC_CONFIG_FILES([Makefile \
    flickr/Makefile \
    trader/Makefile \
    trader/util/Makefile \
    trader/trader/Makefile \
    trader/exchange/Makefile \
    trader/trader/util/Makefile \
    trader/trader/trader-client/Makefile \
    trader/trader/trader-exchange/Makefile \
    trader/exchange/util/Makefile \
    trader/exchange/exchange-client/Makefile \
    trader/exchange/exchange-trader/Makefile \
    trader/client/Makefile
    ])
    
AC_OUTPUT
