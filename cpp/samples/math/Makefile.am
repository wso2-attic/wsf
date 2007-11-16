prgbindir=$(prefix)/bin/samples
prgbin_PROGRAMS = math 
math_SOURCES = math.cpp

math_LDADD   = $(LDFLAGS) \
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

INCLUDES =	-I$(top_builddir)/include \
		@AXIS2INC@

