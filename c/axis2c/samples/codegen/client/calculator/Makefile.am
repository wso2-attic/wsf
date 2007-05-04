prgbindir=$(prefix)/bin/samples
prgbin_PROGRAMS = Calculator
samplesdir=$(prefix)/samples/client/Calculator

Calculator_SOURCES = \
axis2_add.c            axis2_Calculator_stub.c  axis2_divResponse.c    axis2_mulResponse.c    axis2_subResponse.c \
axis2_addRequest.c     axis2_div.c              axis2_mul.c            axis2_sub.c            test_Calcultor.c \
axis2_addResponse20.c  axis2_divRequest.c       axis2_mulRequest.c     axis2_subRequest.c \
axis2_addResponse.c    axis2_divResponse16.c    axis2_mulResponse14.c  axis2_subResponse12.c


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
