AC_PREREQ(2.59)

AC_INIT(wso2_registry_client_c, 0.1.0)
AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE
AM_CONFIG_HEADER(config.h)
AC_PREFIX_DEFAULT(/usr/local/regstry_client)

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

AC_CHECK_LIB(curl, curl_easy_send)

AC_MSG_CHECKING(path to use Axis2C . This is a compulsory to build rest_client)
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
    elif test -d '$(AXIS2C_HOME)/include/axis2-1.6.0'; then
        axis2inc="-I$(AXIS2C_HOME)/include/axis2-1.6.0"
    else
        AC_MSG_ERROR(could not find axis2inc. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(path to use libcurl . This is a compulsory to build rest_client)
AC_ARG_WITH(libcurl,
[  --with-libcurl[=PATH]      use libcurl.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT($withval)
    dnl Find libcurl include dir in the path
    if test -d $withval; then
        libcurlinc="-I$withval"
    dnl else find the libcurlinc include dir in 
    elif test -d '/usr/include/curl'; then
        libcurlinc="/usr/include"
    elif test -d '/usr/local/include/curl'; then
        libcurlinc="/usr/local/include"
    else
        AC_MSG_ERROR(could not find libcurl. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)


AC_MSG_CHECKING(whether to build tests)
AC_ARG_ENABLE(tests, [  --enable-tests
                          build tests (default=no)],
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
CFLAGS="$CFLAGS -Wall -Werror"

AXIS2INC=$axis2inc
AXIS2LIB='-L$(AXIS2C_HOME)/lib'
AXIOMINC=$axiominc
LIBCURLINC=$libcurlinc

AC_SUBST(AXIS2INC)
AC_SUBST(AXIS2LIB)
AC_SUBST(AXIOMINC)
AC_SUBST(LIBCURLINC)
AC_SUBST(TESTDIR)


AC_CONFIG_FILES([Makefile \
    src/Makefile
    test/Makefile
    ])

AC_OUTPUT
