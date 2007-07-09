TESTS = test_context
check_PROGRAMS = test_context
noinst_PROGRAMS = test_context
SUBDIRS =
AM_CFLAGS = -g -pthread
test_context_SOURCES = test_context.c


test_context_LDADD   =	../../../util/src/libaxutil.la \
						../../../axiom/src/om/libaxis2_axiom.la \
						../../../axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
						$(top_builddir)/src/core/engine/libaxis2_engine.la \
						$(top_builddir)/src/core/transport/http/common/libaxis2_http_common.la \
						                             $(top_builddir)/neethi/src/libneethi.la \
			        	-L$(top_builddir)$(GUTHTHILA_LIBS) \
			        	$(LIBXML2_LIBS)

INCLUDES = -I${CUTEST_HOME}/include \
            -I$(top_builddir)/src/xml/guththila/src \
            -I$(top_builddir)/include \
            -I$(top_builddir)/src/core/description \
			-I ../../../util/include \
			-I ../../../axiom/include 
