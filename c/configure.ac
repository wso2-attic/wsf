dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(wso2-wsf-c-src, 1.0alpha2)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([tar-ustar])
AC_PREFIX_DEFAULT(/usr/local/wsf_c)

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
AC_CHECK_LIB(z, inflate)

if test -d $srcdir/axis2c; then
    AC_CONFIG_SUBDIRS(axis2c)
fi

if test -d $srcdir/sandesha2c; then
    AC_CONFIG_SUBDIRS(sandesha2c)
fi

if test -d $srcdir/rampartc; then
    AC_CONFIG_SUBDIRS(rampartc)
fi

if test -d $srcdir/savanc; then
    AC_CONFIG_SUBDIRS(savanc)
fi

if test -d $srcdir/wsclient; then
    AC_CONFIG_SUBDIRS(wsclient)
fi

#CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE -Wno-implicit-function-declaration"
CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
#    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration "
    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration -Wall"
fi
LDFLAGS="-lpthread"

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])
AC_CHECK_HEADERS([linux/if.h],[],[],
[
#include <sys/socket.h>
])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
#AC_CHECK_FUNCS([memmove])


AC_CONFIG_FILES([Makefile 
    ])
    
AC_OUTPUT
