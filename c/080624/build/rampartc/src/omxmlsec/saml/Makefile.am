lib_LTLIBRARIES =libsaml.la

libsaml_la_SOURCES = assertion.c \
			  attr_stmt.c \
			  auth_des_stmt.c \
			  auth_smt.c \
			  condition.c \
			  id_type.c \
			  query.c \
			  request.c \
			  response.c \
			  stmt.c \
			  subject.c \
			  sutil.c

INCLUDES = -I$(top_builddir)/include \
            -I ../../../../util/include \
            -I ../../../../include \
            -I ../../../../axiom/include \
	    @OPENSSLINC@ \
	    @UTILINC@ \
	    @AXIOMINC@ \
		@NEETHIINC@ \
	    @AXIS2INC@
