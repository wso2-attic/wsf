SUBDIRS=ssl libcurl
lib_LTLIBRARIES = libaxis2_http_sender.la



if AXIS2_LIBCURL_ENABLED
LIBCURL_SOURCES=libcurl/axis2_libcurl.c\
                libcurl/libcurl_stream.c 
LIBCURL_LIBS=-lssl -lcrypto -lcurl -ldl -lz
else
LIBCURL_SOURCES=
LIBCURL_LIBS=
endif


if AXIS2_SSL_ENABLED
SSL_SOURCES = ssl/ssl_stream.c\
               ssl/ssl_utils.c
SSL_LIBS = -lssl -lcrypto
else
SSL_SOURCES=
SSL_LIBS=
endif

libaxis2_http_sender_la_SOURCES = http_transport_sender.c \
                                  http_sender.c \
                                  http_client.c \
								  $(SSL_SOURCES) \
								  $(LIBCURL_SOURCES)

libaxis2_http_sender_la_LIBADD = $(top_builddir)/src/core/transport/http/common/libaxis2_http_common.la\
                                 $(top_builddir)/src/core/transport/http/util/libaxis2_http_util.la\
				 				 $(top_builddir)/axiom/src/om/libaxis2_axiom.la\
				 				 $(top_builddir)/util/src/libaxutil.la\
								 $(LIBCURL_LIBS)\
								 $(SSL_LIBS)


libaxis2_http_sender_la_LDFLAGS = -version-info $(VERSION_NO)

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
