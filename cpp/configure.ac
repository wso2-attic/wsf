dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(wso2-wsf-cpp, 0.1)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([tar-ustar])
AC_PREFIX_DEFAULT(/opt/wso2/wsf_cpp)

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

if test -d $srcdir/wsf_c; then
    AC_CONFIG_SUBDIRS(wsf_c)
fi


CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Wall -Werror -Wno-implicit-function-declaration -g"
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
AC_CHECK_HEADERS([net/if_types.h])
AC_CHECK_HEADERS([net/if_dl.h])

dnl This is a check to see if we are running MacOS X
dnl It may be better to do a Darwin check
AC_CHECK_HEADERS([sys/appleapiopts.h]) 
dnl Checks for typedefs, structures, and compiler characteristics.

dnl Checks for library functions.
dnl AC_FUNC_MALLOC
dnl AC_FUNC_REALLOC
#AC_CHECK_FUNCS([memmove])

AC_MSG_CHECKING(Axis2)
AC_ARG_WITH(axis2,
[  --with-axis2[=PATH]   axis2.
    ],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    XMPP_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find iksemel XMPP include dir 
    if test -d $withval; then
        axis2inc="-I$withval"
        AXIS2_DIR="axis2"
    dnl else find the iksemel include dir in /usr/include
    elif test -d '$(AXIS2C_HOME)/include/axis2-1.1'; then
        axis2inc="-I$(AXIS2C_HOME)/include/axis2-1.1"
        AXIS2_DIR="axis2"
    else
        AC_MSG_ERROR(Could not find axis2. stop)
    fi
        AXIS2_DIR="axis2"
    ;;
  esac ],
  AC_MSG_RESULT(no)
)


AXIS2INC=$axis2inc
AC_SUBST(AXIS2INC)

export prefix 

AC_CONFIG_FILES([Makefile \
	src/Makefile \
	samples/Makefile \
	samples/echo/Makefile \
	samples/google/Makefile \
	samples/math/Makefile \
	samples/mtom/Makefile \
	samples/mtom/resources/Makefile \
	samples/notify/Makefile \
	samples/yahoo/Makefile \
	samples/secpolicy/Makefile  \
	samples/secpolicy/scenario1/Makefile  \
	samples/secpolicy/scenario2/Makefile  \
	samples/secpolicy/scenario3/Makefile  \
	samples/secpolicy/scenario4/Makefile  \
	samples/secpolicy/scenario5/Makefile  \
	samples/secpolicy/scenario6/Makefile  \
	samples/secpolicy/scenario7/Makefile  \
	samples/flickr/Makefile 
    ])
    
AC_OUTPUT
