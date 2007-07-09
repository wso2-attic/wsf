noinst_PROGRAMS = round2 
round2_SOURCES = round2_client.c

round2_LDADD   =    $(LDFLAGS) \
                    ../../../../util/src/libaxutil.la \
                    ../../../../axiom/src/om/libaxis2_axiom.la \
                    ../../../../axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
					$(top_builddir)/modules/core/engine/libaxis2_engine.la \
					$(top_builddir)/modules/core/transport/http/sender/libaxis2_http_sender.la \
					$(top_builddir)/modules/core/transport/http/receiver/libaxis2_http_receiver.la \
                    -L$(top_builddir)/$(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = -I$(top_builddir)/include \
           -I ../../../../util/include \
            -I ../../../../axiom/include

