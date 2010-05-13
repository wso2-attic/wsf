dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(axis2_util-src, 1.6.0)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE
AC_PREFIX_DEFAULT(/usr/local/axis2_util)

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
AC_CHECK_LIB(z, inflate)

#CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE -Wno-implicit-function-declaration"
CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration -D_GNU_SOURCE"
fi
LDFLAGS="$LDFLAGS -lpthread"

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])
AC_CHECK_HEADERS([sys/socket.h])
AC_CHECK_HEADERS([net/if.h], [], [],
[#include <stdio.h>
#if STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# if HAVE_STDLIB_H
# include <stdlib.h>
# endif
#endif
#if HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
])
AC_CHECK_HEADERS([linux/if.h],[],[],
[
#if HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
])
AC_CHECK_HEADERS([net/if_types.h net/if_dl.h])

dnl This is a check to see if we are running MacOS X
dnl It may be better to do a Darwin check
AC_CHECK_HEADER([sys/appleapiopts.h],
               [AC_DEFINE([IS_MACOSX],[1],[Define to 1 if compiling on MacOS X])],
               [])

dnl Checks for typedefs, structures, and compiler characteristics.
dnl AC_C_CONST
AC_CHECK_TYPES([struct lifreq])
AC_CHECK_TYPES([struct sockaddr_dl], [], [],
[
#if HAVE_NET_IF_DL_H
# include <net/if_dl.h>
#endif
])

dnl Checks for library functions.
dnl AC_FUNC_MALLOC
dnl AC_FUNC_REALLOC
#AC_CHECK_FUNCS([memmove])

# System-dependent adjustments.
cygwin=no
darwin=no
solaris=no
no_undefined=no

case "${host_cpu}" in
alpha*)
  if test x"$GCC" = xyes
  then
    CFLAGS="$CFLAGS -mfp-rounding-mode=d -mieee"
    CXXFLAGS="$CXXFLAGS -mfp-rounding-mode=d -mieee"
  else
    CFLAGS="$CFLAGS -fprm d -ieee -underflow_to_zero"
    CXXFLAGS="$CXXFLAGS -fprm d -ieee -underflow_to_zero"
  fi
  ;;
*)
  ;;
esac

case "${host_os}" in
cygwin)
  cygwin=yes
  no_undefined=yes
  ;;
darwin*)
  darwin=yes
  if test x"$GCC" = xyes
  then
    CFLAGS="$CFLAGS -Wno-long-double"
    CXXFLAGS="$CXXFLAGS -Wno-long-double"
  fi
  ;;
solaris*)
  solaris=yes
  AC_DEFINE(AXIS2_SOLARIS,1,[Am I on Solaris?])
  
  ;;
*)
  ;;
esac

AM_CONDITIONAL(HOST_OS_CYGWIN, test x$cygwin = xyes)
AM_CONDITIONAL(HOST_OS_DARWIN, test x$darwin = xyes)
AM_CONDITIONAL(HOST_OS_SOLARIS, test x$solaris = xyes)
AM_CONDITIONAL(NO_UNDEFINED, test x$no_undefined = xyes)


AC_MSG_CHECKING(whether to build guththila xml parser library)
AC_ARG_ENABLE(guththila, [  --enable-guththila    build guththila xml parser library wrapper. default=no],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    GUTHTHILA_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    GUTHTHILA_DIR="guththila"

    ;;
  esac ],
  AC_MSG_RESULT(no)
  GUTHTHILA_DIR=""
)

AC_MSG_CHECKING(whether to build tests)
AC_ARG_ENABLE(tests, [  --enable-tests    build tests. default=no],
[ case "${enableval}" in
  yes)
    AC_MSG_RESULT(yes)
    TESTDIR="test"
    ;;
  *)
    AC_MSG_RESULT(no)
    TESTDIR=""

    ;;
  esac ],
  AC_MSG_RESULT(no)
  TESTDIR=""
)

AC_MSG_CHECKING(whether to use archive)
AC_ARG_WITH(archive,
[  --with-archive[=PATH]      Find the zlib header files in 'PATH'.
    If you omit the '=PATH' part completely, the configure script will search
    '/usr/include/' for zlib headers.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ZLIBBUILD=""
    zliblibs=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    zliblibs="minizip/libaxis2_minizip.la"
    CFLAGS="$CFLAGS -DAXIS2_ARCHIVE_ENABLED"
    if test -d $withval; then
        zlibinc="-I$withval"
    elif test -d '/usr/include'; then
        zlibinc="-I/usr/include"
    else
        AC_MSG_ERROR(could not find zlib stop)
    fi
    ZLIBBUILD="minizip"
    ;;
  esac ],
  AC_MSG_RESULT(no)
)



CFLAGS="$CFLAGS $GUTHTHILA_CFLAGS"

UTILINC=$axis2_utilinc
ZLIBINC=$zlibinc
ZLIBLIBS=$zliblibs
VERSION_NO="4:0:4"

AC_SUBST(VERSION_NO)
AC_SUBST(UTILINC)
AC_SUBST(ZLIBINC)
AC_SUBST(ZLIBLIBS)
AC_SUBST(ZLIBBUILD)
AC_SUBST(GUTHTHILA_DIR)
AC_SUBST(GUTHTHILA_LIBS)
AC_SUBST(TESTDIR)

AC_CONFIG_FILES([Makefile \
    src/Makefile \
    src/platforms/unix/Makefile \
    src/minizip/Makefile \
    src/stomp/Makefile \
    include/Makefile \
    test/Makefile \
    test/util/Makefile \
    test/allocator/Makefile \
    test/date_time/Makefile \
    test/duration/Makefile \
    test/link_list/Makefile \
    test/properties/Makefile \
    test/rand/Makefile \
    test/stack/Makefile \
    test/string_util/Makefile \
    test/uri/Makefile \
    test/url/Makefile \
    test/utils/Makefile \
    ])
    
AC_OUTPUT
