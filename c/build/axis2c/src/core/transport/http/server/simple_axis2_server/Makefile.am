prgbindir=$(prefix)/bin/
prgbin_PROGRAMS = axis2_http_server
SUBDIRS =
AM_CFLAGS = -g -pthread
axis2_http_server_SOURCES = http_server_main.c

axis2_http_server_LDADD   =  $(LDFLAGS) \
                            -L$(top_builddir)/src/wsdl \
                            -L$(top_builddir)/src/core/engine \
                            -L$(top_builddir)/src/core/transport/http/sender \
                            -L$(top_builddir)/src/core/transport/http/receiver \
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
            -I$(top_builddir)/src/wsdl\
            -I$(top_builddir)/src/core/description\
            -I$(top_builddir)/src/core/context \
            -I$(top_builddir)/src/core/deployment\
            -I$(top_builddir)/src/core/phaseresolver \
            -I$(top_builddir)/src/core/engine \
            -I$(top_builddir)/xml_schema/include \
            -I$(top_builddir)/util/include \
            -I$(top_builddir)/axiom/include
