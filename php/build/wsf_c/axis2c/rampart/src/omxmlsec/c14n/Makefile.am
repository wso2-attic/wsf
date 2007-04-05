lib_LTLIBRARIES = liboxsc14n.la
noinst_HEADERS = c14n_sorted_list.h

liboxsc14n_la_SOURCES = c14n.c\
			sorted_list.c

liboxsc14n_la_LIBADD  = -lssl\
    		-lcrypto

INCLUDES = -I$(top_builddir)/include \
			-I ../../../../util/include \
			-I ../../../../include \
			-I ../../../../axiom/include \
			-I ../../../../include

