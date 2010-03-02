dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(savanc-src, 1.0)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([tar-ustar])
AC_PREFIX_DEFAULT(/usr/local/savanc)

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

if test -d $srcdir/samples; then
    AC_CONFIG_SUBDIRS(samples)
fi

CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration"
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

AC_MSG_CHECKING(path to use Axis2C . This is a compulsory to build Savan/C)
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
    dnl else find the axis2inc include dir in $(WSFC_HOME)/include
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

AC_MSG_CHECKING(whether to build sqlite based subscription manager)
AC_ARG_ENABLE(sqlite, [  --enable-sqlite
                          build Sqlite based subscription manager (default=yes)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    SAVAN_SUBS_MGR_SQLITE="sqlite"
    SAVAN_SUBS_MGR="sqlite"

    ;;
  esac ],
  AC_MSG_RESULT(yes)
  SAVAN_SUBS_MGR_SQLITE="sqlite"
  SAVAN_SUBS_MGR="sqlite"
)


AC_MSG_CHECKING(whether to build service based subscription manager)
AC_ARG_ENABLE(service, [  --enable-service    
                          build service based subscription manager (default=no)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    SAVAN_SUBS_MGR_SERVICE=""
    SAVAN_SUBS_MGR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    SAVAN_SUBS_MGR_SERVICE="service"
    SAVAN_SUBS_MGR="service"
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(To Use Registry based subscription manager. This is an optional module to build Savan C)
AC_ARG_WITH(registry,
[  --with-registry[=PATH]     Find the REGISTRY header files in 'PATH'.
    'PATH' should point to REGISTRY include files location.
    If you omit the '=PATH' part completely, the configure script will search
    '$(WSFC_HOME)/include/registry-0.1.0' for REGISTRY headers.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    SAVAN_SUBS_MGR_REGISTRY=""
    SAVAN_SUBS_MGR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    SAVAN_SUBS_MGR_REGISTRY="registry"
    SAVAN_SUBS_MGR="registry"
    dnl Find registry include dir in the path
    if test -d $withval; then
        registryinc="-I$withval"
    dnl else find the registry include dir in $(WSFC_HOME)/include
    elif test -d '$(WSFC_HOME)/include'; then
        registryinc="-I$(WSFC_HOME)/include/registry-0.1.0"
    else
        AC_MSG_ERROR(could not find registry. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(To Use XPath based filter . This is an optional module to build Savan C)
AC_ARG_ENABLE(xpath, [  --enable-xpath
                      Enable XPath filtering support (default=yes)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    SAVAN_FILTER=""
    SAVAN_FILTER_LIB=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    SAVAN_FILTER="xpath"
    SAVAN_FILTER_LIB=xpath/libsavan_filter_mod.la
    dnl Find libxml2 include dir in the path
    dnl Find the libxml2/libxslt include dir in /usr/include
    if test -d '/usr/include'; then
        xpathinc="-I/usr/include"
    else
        AC_MSG_ERROR(could not find libxml2/libxslt. Assume set in CFLAGS)
    fi
    PKG_CHECK_MODULES(XSLT, libxslt)
    CFLAGS="$CFLAGS -DSAVAN_FILTERING $XSLT_CFLAGS"
    LDFLAGS="$LDFLAGS -lxslt"
    ;; 
  esac ],
  AC_MSG_RESULT(no)
)

#Default for savan publisher
SAVAN_PUBLISHER_XPATH="default"
SAVAN_PUBLISHER_LIB="default/libsavan_publisher.la"

AC_MSG_CHECKING(To Use Xml Schema.)
AXIOMINC="-I$abs_top_builddir/../axis2c/axiom/include"
UTILINC="-I$abs_top_builddir/../axis2c/util/include"
NEETHIINC="-I$abs_top_builddir/../axis2c/neethi/include"
CFLAGS="$CFLAGS $LIBXML2_CFLAGS"

REGISTRYINC=$registryinc
XPATHINC=$xpathinc

AC_SUBST(REGISTRYINC)
AC_SUBST(XPATHINC)
AC_SUBST(AXIS2INC)
AC_SUBST(AXIOMINC)
AC_SUBST(UTILINC)
AC_SUBST(NEETHIINC)
AC_SUBST(XMLSCHEMAINC)
AC_SUBST(SAVAN_SUBS_MGR_REGISTRY)
AC_SUBST(SAVAN_SUBS_MGR_SERVICE)
AC_SUBST(SAVAN_SUBS_MGR_SQLITE)
AC_SUBST(SAVAN_SUBS_MGR)
AC_SUBST(SAVAN_FILTER)
AC_SUBST(SAVAN_FILTER_LIB)
AC_SUBST(SAVAN_PUBLISHER_ESB)
AC_SUBST(SAVAN_PUBLISHER_XPATH)
AC_SUBST(SAVAN_PUBLISHER_LIB)

export SAVAN_SUBS_MGR_REGISTRY
export SAVAN_SUBS_MGR_SERVICE
export SAVAN_SUBS_MGR_SQLITE
export SAVAN_SUBS_MGR
export SAVAN_FILTER
export SAVAN_FILTER_LIB
export SAVAN_PUBLISHER_ESB
export SAVAN_PUBLISHER_XPATH
export SAVAN_PUBLISHER_LIB

AC_CONFIG_FILES([Makefile \
    src/Makefile \
    src/client/Makefile\
    src/core/Makefile\
    src/handlers/Makefile \
    src/msgreceivers/Makefile\
    src/subscribers/Makefile\
    src/subs_mgrs/Makefile\
    src/subs_mgrs/common/Makefile\
    src/subs_mgrs/sqlite/Makefile\
    src/subs_mgrs/service/Makefile\
    src/subs_mgrs/service/subs_mgr_svc/Makefile\
    src/filters/Makefile\
    src/filters/common/Makefile\
    src/filters/xpath/Makefile\
    src/publishers/Makefile\
    src/publishers/common/Makefile\
    src/publishers/default/Makefile\
    src/data/Makefile\
    src/util/Makefile
    ])
    
AC_OUTPUT
