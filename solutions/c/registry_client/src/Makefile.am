lib_LTLIBRARIES = libregistry_client.la
CFLAGS = -g -O0
libregistry_client_la_SOURCES = rest_client.c conf.c resource.c comment.c remote_registry.c util.c
libregistry_client_la_LIBADD = $(LDFLAGS) \
							-L$(AXIS2C_HOME)/lib \
							-lcurl -laxutil

INCLUDES = -I$(top_builddir)/include  \
          @AXIS2INC@ \
          @LIBCURLINC@
