dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(wsclient-src, 0.93)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([tar-ustar])
AC_PREFIX_DEFAULT(/usr/local/wsclient)

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
AC_CHECK_LIB(z, inflate)

#CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE -Wno-implicit-function-declaration"
CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration "
#    CFLAGS="$CFLAGS -ansi -Wall -Werror -Wno-implicit-function-declaration "
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

AC_MSG_CHECKING(whether to enable trace)
AC_ARG_ENABLE(trace, [  --enable-trace    enable trace. default=no],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    CFLAGS="$CFLAGS"
    ;;
  *)
    AC_MSG_RESULT(yes)
    CFLAGS="$CFLAGS -DAXIS2_TRACE"
    ;;
  esac ],
  AC_MSG_RESULT(no)
  CFLAGS="$CFLAGS"
)

AC_MSG_CHECKING(whether to build rampart)
AC_ARG_ENABLE(rampart, [  --enable-rampart	build rampart. default=yes],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    RAMPART_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    CFLAGS="$CFLAGS -DWSF_RAMPART_ENABLED"
    RAMPART_LIBS="../../rampartc/src/core/libmod_rampart.la"
    OMXMLSEC_LIBS="../../rampartc/src/omxmlsec/libomxmlsec.la"
    SECCONV_LIBS="../../rampartc/src/secconv/libsecconv.la"
    ;;
  esac ],
  AC_MSG_RESULT(yes)
  CFLAGS="$CFLAGS -DWSF_RAMPART_ENABLED"
  RAMPART_LIBS="../../rampartc/src/core/libmod_rampart.la"
  OMXMLSEC_LIBS="../../rampartc/src/omxmlsec/libomxmlsec.la"
  SECCONV_LIBS="../../rampartc/src/secconv/libsecconv.la"
)

AC_MSG_CHECKING(whether to use openssl)
AC_ARG_ENABLE(openssl, [  --enable-openssl  enable ssl. default=no],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    CFLAGS="$CFLAGS"
    ssl_enabled=false
    ;;
  *)
    AC_MSG_RESULT(yes)
    CFLAGS="$CFLAGS -DAXIS2_SSL_ENABLED"
    ssl_enabled=true
    ;;
  esac ],
  AC_MSG_RESULT(no)
  CFLAGS="$CFLAGS"
)

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
        axis2inc="-I$(AXIS2C_HOME)/include/axis2-1.1"
    else
        AC_MSG_ERROR(could not find axis2inc. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_DEFINE_UNQUOTED(WSFC_PREFIX, "$prefix",[WSF/C Install Path])

AXIS2INC=$axis2inc
AXIOMINC=$axis2inc/../axiom/include
UTILINC=$axis2inc/../util/include
NEETHIINC=$axis2inc/../neethi/include

AC_SUBST(AXIS2INC)
AC_SUBST(AXIOMINC)
AC_SUBST(UTILINC)
AC_SUBST(NEETHIINC)

AC_SUBST(OMXMLSEC_LIBS)
AC_SUBST(RAMPART_LIBS)
AC_SUBST(SECCONV_LIBS)

AC_SUBST(TESTDIR)
AC_SUBST(SAMPLES)
AM_CONDITIONAL(AXIS2_SSL_ENABLED, test x$ssl_enabled = xtrue)

AC_CONFIG_FILES([Makefile \
    src/Makefile \
    samples/Makefile \
    samples/data/Makefile
    ])
    
AC_OUTPUT
