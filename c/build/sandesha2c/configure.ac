dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)
AC_INIT(sandesha2c-src, 0.90)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AC_PREFIX_DEFAULT(/usr/local/sandesha2c)

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

CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Wall -Werror -Wno-implicit-function-declaration -g"
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
        AXIS2INC="-I$withval"
    dnl else find the axis2inc include dir in $(AXIS2C_HOME)/include
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

AC_MSG_CHECKING(path to use sqlite storage .)
AC_ARG_WITH(sqlite,
[  --with-sqlite[=PATH]      use sqlite storage.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    WRAPPER_DIR=""
    ;;
  *)
    AC_MSG_RESULT($withval)
    WRAPPER_DIR="sqlite"
    dnl Find sqlite include dir in the path
    if test -d $withval; then
        sqliteinc="-I$withval"
    dnl else find the sqliteinc include dir in /usr/include
    elif test -d '/usr/include'; then
        sqliteinc="-I/usr/include"
    else
        AC_MSG_ERROR(could not find sqliteinc. stop)
    fi
    WRAPPER_DIR="sqlite"
    LDFLAGS="$LDFLAGS -lsqlite3"
    ;;
  esac ],
  AC_MSG_RESULT(yes)
  WRAPPER_DIR="sqlite"
  sqliteinc="-I/usr/include"
  LDFLAGS="$LDFLAGS -lsqlite3"
)

AC_MSG_CHECKING(path to use mysql storage .)
AC_ARG_WITH(mysql,
[  --with-mysql[=PATH]      use mysql storage.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    WRAPPER_DIR=""
    ;;
  *)
    AC_MSG_RESULT($withval)
    WRAPPER_DIR="mysql"
    dnl Find mysql include dir in the path
    if test -d $withval; then
        mysqlinc="-I$withval"
    dnl else find the mysqlinc include dir in /usr/include/mysql
    elif test -d '/usr/include/mysql'; then
        mysqlinc="-I/usr/include/mysql"
    else
        AC_MSG_ERROR(could not find mysqlinc. stop)
    fi
    WRAPPER_DIR="mysql"
    LDFLAGS="$LDFLAGS -lmysqlclient -lnsl -lm -lz"
    ;;
  esac ],
  AC_MSG_RESULT(no)
)


AXIOMINC="-I$abs_top_builddir/../axis2c/axiom/include"
UTILINC="-I$abs_top_builddir/../axis2c/util/include"
NEETHIINC="-I$abs_top_builddir/../axis2c/neethi/include"
AC_SUBST(AXIS2INC)
AC_SUBST(AXIOMINC)
AC_SUBST(UTILINC)
AC_SUBST(NEETHIINC)
MYSQLINC=$mysqlinc
SQLITEINC=$sqliteinc

AC_SUBST(MYSQLINC)
AC_SUBST(SQLITEINC)
AC_SUBST(WRAPPER_DIR)

AC_CONFIG_FILES([Makefile \
    src/Makefile \
    src/util/Makefile \
    src/wsrm/Makefile\
    src/transport/Makefile\
    src/workers/Makefile\
    src/handlers/Makefile\
    src/msgprocessors/Makefile\
    src/storage/Makefile\
    src/storage/beans/Makefile\
    src/storage/common/Makefile \
    src/storage/inmemory/Makefile\
    src/storage/sqlite/Makefile\
    src/storage/mysql/Makefile\
    src/client/Makefile \
    src/core/Makefile \
    src/polling/Makefile 
    ])
    
AC_OUTPUT
