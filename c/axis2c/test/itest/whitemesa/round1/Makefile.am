noinst_PROGRAMS = round1 
round1_SOURCES = round1_client.c

round1_LDADD   =    $(LDFLAGS) \
                    ../../../../util/src/libaxutil.la \
                    ../../../../axiom/src/om/libaxis2_axiom.la \
                    ../../../../axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
					$(top_builddir)/src/core/engine/libaxis2_engine.la \
					$(top_builddir)//src/core/transport/http/sender/libaxis2_http_sender.la \
					$(top_builddir)/src/core/transport/http/receiver/libaxis2_http_receiver.la \
					$(top_builddir)/src/core/transport/http/common/libaxis2_http_common.la \
                    -L$(top_builddir)/$(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = -I$(top_builddir)/include \
            -I ../../../../util/include \
            -I ../../../../axiom/include

