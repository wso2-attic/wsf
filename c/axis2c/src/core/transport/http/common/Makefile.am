lib_LTLIBRARIES = libaxis2_http_common.la

libaxis2_http_common_la_LIBADD=$(top_builddir)/util/src/libaxutil.la\
                                 $(top_builddir)/src/core/transport/http/util/libaxis2_http_util.la

libaxis2_http_common_la_SOURCES = http_header.c\
                                  http_out_transport_info.c\
                                  http_request_line.c\
                                  http_simple_request.c\
                                  http_simple_response.c\
                                  http_status_line.c\
                                  http_response_writer.c\
                                  simple_http_svr_conn.c\
                                  http_worker.c


INCLUDES = -I$(top_builddir)/include \
	       -I$(top_builddir)/src/core/transport\
	       -I$(top_builddir)/src/core/transport/http \
           -I$(top_builddir)/src/core/description \
           -I$(top_builddir)/src/core/context \
           -I$(top_builddir)/src/core/phaseresolver \
           -I$(top_builddir)/src/core/engine \
           -I$(top_builddir)/src/core/deployment \
           -I$(top_builddir)/util/include \
           -I$(top_builddir)/axiom/include
