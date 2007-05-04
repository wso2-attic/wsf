prgbindir=$(prefix)/bin/samples
prgbin_PROGRAMS = echo_blocking echo_non_blocking echo_blocking_addr echo_rest echo_blocking_dual echo_non_blocking_dual echo_blocking_soap11
samplesdir=$(prefix)/samples/user_guide/clients
samples_DATA=echo_util.h echo_util.c echo_blocking.c echo_non_blocking.c echo_blocking_addr.c echo_rest.c \
    Makefile.am Makefile.in echo_blocking_dual.c echo_non_blocking_dual.c echo_blocking_soap11.c

echo_blocking_SOURCES = echo_blocking.c echo_util.c
echo_non_blocking_SOURCES = echo_non_blocking.c echo_util.c
echo_blocking_addr_SOURCES = echo_blocking_addr.c echo_util.c
echo_rest_SOURCES = echo_util.c echo_rest.c
echo_blocking_dual_SOURCES = echo_blocking_dual.c echo_util.c
echo_non_blocking_dual_SOURCES = echo_non_blocking_dual.c echo_util.c
echo_blocking_soap11_SOURCES = echo_blocking_soap11.c echo_util.c

LINK_FLAGS = $(LDFLAGS) \
             -L$(AXIS2C_HOME)/lib \
			 -laxutil \
             -laxis2_axiom \
             -laxis2_engine \
             -laxis2_parser \
             -lpthread \
             -laxis2_http_sender \
             -laxis2_http_receiver \
             $(GUTHTHILA_LIBS) \
             $(LIBXML2_LIBS)

echo_blocking_LDADD = $(LINK_FLAGS)
echo_non_blocking_LDADD = $(LINK_FLAGS)
echo_blocking_addr_LDADD = $(LINK_FLAGS)
echo_rest_LDADD = $(LINK_FLAGS)
echo_blocking_dual_LDADD = $(LINK_FLAGS)
echo_non_blocking_dual_LDADD = $(LINK_FLAGS)
echo_blocking_soap11_LDADD = $(LINK_FLAGS)

INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.0 \
			@UTILINC@ \
			@AXIOMINC@

EXTRA_DIST=echo_util.h echo_blocking_addr.mk echo_blocking.mk echo_non_blocking_dual.mk  echo_rest.mk echo_blocking_dual.mk echo_blocking_soap11.mk echo_non_blocking.mk

