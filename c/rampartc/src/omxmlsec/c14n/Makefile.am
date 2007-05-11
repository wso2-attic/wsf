lib_LTLIBRARIES = liboxsc14n.la

noinst_HEADERS = c14n_sorted_list.h

liboxsc14n_la_SOURCES = c14n.c \
					  sorted_list.c

liboxsc14n_la_LIBADD = ${AXIS2C_HOME}/lib

INCLUDES =	-I ../../../../axis2c/include \
		-I ../../../../axis2c/axiom/include \
		-I ../../../../axis2c/util/include \
		-I ../../../include \
	    @AXIS2INC@
