TESTS = test_soap
noinst_PROGRAMS = test_soap
check_PROGRAMS = test_soap
SUBDIRS =
AM_CFLAGS = -g -O2 -pthread
test_soap_SOURCES = test_soap.c

test_soap_LDADD   =	../../../util/src/libaxutil.la \
					$(top_builddir)/src/om/libaxis2_axiom.la \
					$(top_builddir)/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
                    $(LIBXML2_LIBS) \
                    $(GUTHTHILA_LIBS)
                    
INCLUDES = -I$(top_builddir)/include \
            -I$(top_builddir)/src/parser \
			-I ../../../util/include
