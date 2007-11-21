prgbindir=$(prefix)/bin/samples/google
prgbin_PROGRAMS = google
google_SOURCES = google.cpp

google_LDADD   = $(LDFLAGS) \
                -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
			../../src/libwso2_wsf.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = -I ../../include \
                -I ../../wsf_c/axis2c/include \
                -I ../../wsf_c/axis2c/neethi/include \
                -I ../../wsf_c/axis2c/axiom/include \
                -I ../../wsf_c/axis2c/util/include \
                -I ../../wsf_c/rampartc/include \
                -I ../../wsf_c/sandesha2c/include \
                -I ../../wsf_c/savanc/include


