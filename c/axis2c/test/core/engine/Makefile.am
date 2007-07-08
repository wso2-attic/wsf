TESTS = test_engine
check_PROGRAMS = test_engine
noinst_PROGRAMS = test_engine
SUBDIRS =
AM_CFLAGS = -g -pthread
test_engine_SOURCES = test_engine.c


test_engine_LDADD   =   \
                    ../../../util/src/libaxutil.la \
                    ../../../axiom/src/om/libaxis2_axiom.la \
                    ../../../axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
		$(top_builddir)/src/core/engine/libaxis2_engine.la \
		$(top_builddir)/src/core/transport/http/common/libaxis2_http_common.la \
		                             $(top_builddir)/neethi/src/libneethi.la \
	                -L$(top_builddir)$(GUTHTHILA_LIBS) \
	                $(LIBXML2_LIBS)

INCLUDES =	-I$(top_builddir)/src/xml/guththila \
            -I$(top_builddir)/include \
            -I$(top_builddir)/src/core/description \
            -I$(top_builddir)/src/core/deployment \
            -I$(top_builddir)/src/core/engine \
            -I ../../../util/include \
            -I ../../../axiom/include \
            -I ../../../neethi/include 

