prgbindir=$(prefix)/bin/
prgbin_PROGRAMS = axis2_http_server
SUBDIRS =
AM_CFLAGS = -g -pthread
axis2_http_server_SOURCES = http_server_main.c

axis2_http_server_LDADD   =  $(LDFLAGS) \
                            -L$(top_builddir)/modules/wsdl \
                            -L$(top_builddir)/modules/core/engine \
                            -L$(top_builddir)/modules/core/transport/http/sender \
                            -L$(top_builddir)/modules/core/transport/http/receiver \
							-L../../../../../../axiom/src/om \
							../../../../../../util/src/libaxutil.la \
							../../../../../../axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
                            -laxis2_engine \
                            -lpthread \
                            -laxis2_http_sender \
                            -laxis2_http_receiver \
							-L$(top_builddir)$(GUTHTHILA_LIBS) \
                            $(LIBXML2_LIBS)
                    
INCLUDES =  -I$(top_builddir)/include \
            -I$(top_builddir)/modules/wsdl\
            -I$(top_builddir)/modules/core/description\
            -I$(top_builddir)/modules/core/context \
            -I$(top_builddir)/modules/core/deployment\
            -I$(top_builddir)/modules/core/phaseresolver \
            -I$(top_builddir)/modules/core/engine \
            -I$(top_builddir)/xml_schema/include \
            -I$(top_builddir)/util/include \
            -I$(top_builddir)/axiom/include
