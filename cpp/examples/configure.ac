dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(wsfcpp-samples-src, 2.1.0)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
dnl AM_INIT_AUTOMAKE([tar-ustar])
AM_INIT_AUTOMAKE
AC_PREFIX_DEFAULT(/usr/local/wsf_cpp)
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


AC_CONFIG_FILES([Makefile \
    clients/Makefile \
    clients/echo/Makefile \
    clients/flickr/Makefile \
    clients/math/Makefile \
    clients/mtom/Makefile \
    clients/mtom/resources/Makefile \
    clients/notify/Makefile \
    clients/yahoo/Makefile \
    clients/google/Makefile \
    services/Makefile \
    services/echo/Makefile \
    services/math/Makefile \
    services/mtom/Makefile \
    services/notify/Makefile \
    services/version/Makefile \
    callbacks/Makefile \
    callbacks/authentication_provider/Makefile \
    callbacks/password_callback/Makefile \
    callbacks/replay_detector/Makefile \
    callbacks/sct_provider/Makefile \
    trader/Makefile \
    trader/util/Makefile \
    trader/client/Makefile \
    trader/exchange/Makefile \
    trader/trader/Makefile \
    trader/trader/trader-util/Makefile \
    trader/trader/trader-client/Makefile  
    ])
    
AC_OUTPUT
