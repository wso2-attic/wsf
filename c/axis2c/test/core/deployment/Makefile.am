TESTS = test_deployment
noinst_PROGRAMS = test_deployment
SUBDIRS =
AM_CFLAGS = $(CFLAGS) -g -pthread
test_deployment_SOURCES = test_deployment.c

test_deployment_LDADD   =  \
                    ../../../util/src/libaxutil.la \
                    ../../../axiom/src/om/libaxis2_axiom.la \
                    ../../../axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
		                                 $(top_builddir)/neethi/src/libneethi.la \
			$(top_builddir)/src/core/engine/libaxis2_engine.la \
			$(top_builddir)/src/core/transport/http/common/libaxis2_http_common.la \
                    -L$(top_builddir)$(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)
                    
INCLUDES = -I$(top_builddir)/include \
            -I$(top_builddir)/src/core/description \
            -I$(top_builddir)/src/core/context \
            -I$(top_builddir)/src/core/phaseresolver \
            -I$(top_builddir)/src/core/deployment \
            -I$(top_builddir)/src/core/engine \
            -I$(top_builddir)/src/core/clientapi \
            -I$(top_builddir)/src/core/util \
            -I ../../../util/include \
            -I ../../../axiom/include \
            -I ../../../neethi/include
			
