noinst_LTLIBRARIES = libaxis2_clientapi.la
libaxis2_clientapi_la_SOURCES = async_result.c \
                                callback.c \
                                listener_manager.c \
                                callback_recv.c \
                                stub.c \
				options.c \
				op_client.c \
				svc_client.c

INCLUDES = -I$(top_builddir)/include \
            -I$(top_builddir)/src/core/engine \
            -I$(top_builddir)/src/core/deployment \
            -I$(top_builddir)/util/include \
           -I$(top_builddir)/util/include/platforms \
            -I$(top_builddir)/axiom/include \
			-I$(top_builddir)/neethi/include
