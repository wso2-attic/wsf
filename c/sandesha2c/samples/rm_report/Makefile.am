prgbindir=$(prefix)/bin/samples
prgbin_PROGRAMS = rm_report
samplesdir=$(prefix)/samples/client/rm_report
samples_DATA=report.c Makefile.am Makefile.in
rm_report_SOURCES = report.c report_util.c

rm_report_LDADD   =  \
                    -L$(AXIS2C_HOME)/lib \
                    -L$(AXIS2C_HOME)/modules/sandesha2 \
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

INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.0 \
			-I../../include \
			@UTILINC@ \
			@AXIOMINC@
