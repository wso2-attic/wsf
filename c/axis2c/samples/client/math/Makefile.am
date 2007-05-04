prgbindir=$(prefix)/bin/samples
samplesdir=$(prefix)/samples/client/math
prgbin_PROGRAMS = math
noinst_HEADERS = axis2_math_stub.h
samples_DATA=axis2_math_stub.c math_client.c axis2_math_stub.h Makefile.am Makefile.in
math_SOURCES = axis2_math_stub.c \
                math_client.c

math_LDADD   =  \
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

INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.0 \
			@UTILINC@ \
			@AXIOMINC@

EXTRA_DIST=math.mk
