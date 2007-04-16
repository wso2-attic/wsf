SUBDIRS=ssl libcurl
lib_LTLIBRARIES = libaxis2_http_sender.la
libaxis2_http_sender_la_SOURCES = http_transport_sender.c\
                                  http_sender.c\
                                  http_client.c

libaxis2_http_sender_la_LIBADD = $(top_builddir)/src/core/transport/http/common/libaxis2_http_common.la\
                                 $(top_builddir)/src/core/transport/http/util/libaxis2_http_util.la\
				 $(top_builddir)/axiom/src/om/libaxis2_axiom.la\
				 $(top_builddir)/util/src/libaxutil.la


if AXIS2_LIBCURL_ENABLED
libaxis2_http_sender_la_SOURCES +=libcurl/axis2_libcurl.c\
                                  libcurl/libcurl_stream.c

libaxis2_http_sender_la_LIBADD +=-lssl\
                                  -lcrypto\
                                  -lcurl\
	                          -ldl\
	                          -lz
endif


if AXIS2_SSL_ENABLED
libaxis2_http_sender_la_SOURCES += ssl/ssl_stream.c\
                                   ssl/ssl_utils.c
libaxis2_http_sender_la_LIBADD += -lssl\
                                 -lcrypto
endif


INCLUDES = -I$(top_builddir)/include \
	       -I$(top_builddir)/src/core/transport\
           -I$(top_builddir)/src/core/transport/http \
           -I$(top_builddir)/src/core/transport/http/sender/libcurl \
           -I$(top_builddir)/src/core/description \
           -I$(top_builddir)/src/core/context \
           -I$(top_builddir)/src/core/phaseresolver \
           -I$(top_builddir)/src/core/engine \
           -I$(top_builddir)/src/core/deployment \
           -I$(top_builddir)/util/include \
           -I$(top_builddir)/axiom/include
