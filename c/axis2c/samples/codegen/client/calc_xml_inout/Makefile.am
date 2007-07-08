prgbindir=$(prefix)/bin/samples
prgbin_PROGRAMS = Calculator
samplesdir=$(prefix)/samples/client/Calculator

Calculator_SOURCES = \
      test_Calcultor.c \
      axis2_Calculator_stub.c


Calculator_LDADD   = $(LDFLAGS) \
                    -L$(AXIS2C_HOME)/lib \
                    -laxutil \
                    -laxis2_axiom \
                    -laxis2_wsdl \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = -I$(AXIS2C_HOME)/include \
			@UTILINC@ \
			@AXIOMINC@
