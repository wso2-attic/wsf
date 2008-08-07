lib_LTLIBRARIES = libaxis2_udp_sender.la

libaxis2_udp_sender_la_SOURCES = udp_sender.c

libaxis2_udp_sender_la_LIBADD = $(top_builddir)/src/core/transport/http/common/libaxis2_http_common.la\
                                 $(top_builddir)/src/core/transport/http/util/libaxis2_http_util.la\
				 			 $(top_builddir)/axiom/src/om/libaxis2_axiom.la\
				 				 $(top_builddir)/util/src/libaxutil.la


libaxis2_udp_sender_la_LDFLAGS = -version-info $(VERSION_NO)

INCLUDES = -I$(top_builddir)/include \
	   -I$(top_builddir)/src/core/transport\
           -I$(top_builddir)/src/core/transport/udp \
           -I$(top_builddir)/src/core/description \
           -I$(top_builddir)/src/core/context \
           -I$(top_builddir)/src/core/phaseresolver \
           -I$(top_builddir)/src/core/engine \
           -I$(top_builddir)/src/core/deployment \
           -I$(top_builddir)/util/include \
	   -I.. \
           -I$(top_builddir)/axiom/include
