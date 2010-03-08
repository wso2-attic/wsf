dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(wso2-wsf-admin-src, m1)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([tar-ustar])
AC_PREFIX_DEFAULT(/usr/local/adminservices)

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

AC_MSG_CHECKING(path to use WSFC . This is a compulsory to build Admin Services)
AC_ARG_WITH(wsfc,
[  --with-wsfc[=PATH]      use wsfc.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT($withval)
    dnl Find wsfc include dir in the path
    if test -d $withval; then
        wsfcinc="-I$withval"
        wsfclib="-L$withval/../../lib"
    dnl else find the wsfcinc include dir in $(AXIS2C_HOME)/include
    elif test -d '$(WSFC_HOME)/include'; then
        wsfcinc="-I$(WSFC_HOME)/include/wsfc-2.0.0"
        wsfclib="-L$(WSFC_HOME)/lib"
    else
        AC_MSG_ERROR(could not find wsfcinc. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_DEFINE_UNQUOTED(WSFC_PREFIX, "$prefix",[WSF/C Install Path])

WSFCINC=$wsfcinc
AXIS2INC=$wsfcinc
AXIOMINC=$wsfcinc
UTILINC=$wsfcinc
NEETHIINC=$wsfcinc
SAVANINC=$wsfcinc
RAMPARTINC=$wsfcinc
SAVANLIB=$wsfclib

AC_SUBST(SAVANINC)
AC_SUBST(RAMPARTINC)
AC_SUBST(AXIS2INC)
AC_SUBST(AXIOMINC)
AC_SUBST(UTILINC)
AC_SUBST(NEETHIINC)

AC_SUBST(OMXMLSEC_LIBS)
AC_SUBST(RAMPART_LIBS)
AC_SUBST(SECCONV_LIBS)
AC_SUBST(SAVANLIB)

AC_SUBST(TESTDIR)
AC_SUBST(SAMPLES)
AM_CONDITIONAL(AXIS2_SSL_ENABLED, test x$ssl_enabled = xtrue)

AC_CONFIG_FILES([Makefile \
    util/Makefile \
    authentication/Makefile \
    keystore_admin/Makefile \
    logging_admin/Makefile \
    module_admin/Makefile \
    server_admin/Makefile \
    service_admin/Makefile \
    service_group_admin/Makefile \
    statistics_admin/Makefile \
    statistics_admin/module/Makefile \
    statistics_admin/service/Makefile \
    transport_admin/Makefile \
    usermanager/Makefile \
    operation_admin/Makefile \
    security_admin_service/Makefile
    ])
    
AC_OUTPUT
