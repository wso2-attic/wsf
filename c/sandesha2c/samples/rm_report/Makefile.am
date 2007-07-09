prgbindir=$(prefix)/bin/samples/sandesha2
prgbin_PROGRAMS = rm_report
samplesdir=$(prefix)/samples/client/rm_report
samples_DATA=report.c Makefile.am Makefile.in
rm_report_SOURCES = report.c report_util.c

rm_report_LDADD   =  \
			../../src/core/libsandesha2.la \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    -lsandesha2_client \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = @AXIS2INC@ \
			-I../../include 

EXTRA_DIST=report_util.h
