prgbindir=$(prefix)/bin/samples
samplesdir=$(prefix)/samples/client/InteropTestPortTypeDocService
prgbin_PROGRAMS = test_echo_date test_echo_struct_array
test_echo_date_SOURCES = \
axis2_echoBase64.c              axis2_echoFloat.c                 axis2_echoString.c \
axis2_echoBase64Response.c      axis2_echoFloatResponse.c         axis2_echoStringResponse.c \
axis2_echoBoolean.c             axis2_echoHexBinary.c             axis2_echoStructArray.c \
axis2_echoBooleanResponse.c     axis2_echoHexBinaryResponse.c     axis2_echoStructArrayResponse.c \
axis2_echoDate.c                axis2_echoIntegerArray.c          axis2_echoStruct.c \
axis2_echoDateResponse.c        axis2_echoIntegerArrayResponse.c  axis2_echoStructResponse.c \
axis2_echoDecimal.c             axis2_echoInteger.c               axis2_echoVoid.c \
axis2_echoDecimalResponse.c     axis2_echoIntegerResponse.c       axis2_echoVoidResponse.c \
axis2_echoFloatArray.c          axis2_echoStringArray.c           axis2_InteropTestPortTypeDocService_stub.c \
axis2_echoFloatArrayResponse.c  axis2_echoStringArrayResponse.c   axis2_SOAPStruct.c \
test_echo_date.c

test_echo_date_LDADD   =  \
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

test_echo_struct_array_SOURCES = \
axis2_echoBase64.c              axis2_echoFloat.c                 axis2_echoString.c \
axis2_echoBase64Response.c      axis2_echoFloatResponse.c         axis2_echoStringResponse.c \
axis2_echoBoolean.c             axis2_echoHexBinary.c             axis2_echoStructArray.c \
axis2_echoBooleanResponse.c     axis2_echoHexBinaryResponse.c     axis2_echoStructArrayResponse.c \
axis2_echoDate.c                axis2_echoIntegerArray.c          axis2_echoStruct.c \
axis2_echoDateResponse.c        axis2_echoIntegerArrayResponse.c  axis2_echoStructResponse.c \
axis2_echoDecimal.c             axis2_echoInteger.c               axis2_echoVoid.c \
axis2_echoDecimalResponse.c     axis2_echoIntegerResponse.c       axis2_echoVoidResponse.c \
axis2_echoFloatArray.c          axis2_echoStringArray.c           axis2_InteropTestPortTypeDocService_stub.c \
axis2_echoFloatArrayResponse.c  axis2_echoStringArrayResponse.c   axis2_SOAPStruct.c \
test_echo_struct_array.c

test_echo_struct_array_LDADD   =  \
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
