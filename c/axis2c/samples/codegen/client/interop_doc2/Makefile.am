prgbindir = $(prefix)/bin/samples
prgbin_PROGRAMS = test_echo_string test_echo_struct test_echo_string_array
samplesdir = $(prefix)/samples/client/WSDLInteropTestDocLitService

test_echo_string_SOURCES = \
  axis2_ArrayOfstring_literal.c axis2_echoStringArray.c axis2_echoStringArrayResponse.c \
  axis2_echoString.c axis2_echoStringResponse.c axis2_echoStruct.c axis2_echoStructResponse.c \
  axis2_echoVoid.c axis2_echoVoidResponse.c axis2_SOAPStruct.c axis2_WSDLInteropTestDocLitService_stub.c \
  test_echo_string.c
test_echo_string_LDADD = \
           $(LDFLAGS) -L$(AXIS2C_HOME)/lib -laxutil -laxis2_axiom \
            -laxis2_wsdl -laxis2_engine -laxis2_parser -lpthread -laxis2_http_sender \
            -laxis2_http_receiver \
           $(GUTHTHILA_LIBS) $(LIBXML2_LIBS)

test_echo_struct_SOURCES = \
  axis2_ArrayOfstring_literal.c axis2_echoStringArray.c \
  axis2_echoStringArrayResponse.c axis2_echoString.c \
  axis2_echoStringResponse.c axis2_echoStruct.c axis2_echoStructResponse.c \
  axis2_echoVoid.c axis2_echoVoidResponse.c axis2_SOAPStruct.c \
  axis2_WSDLInteropTestDocLitService_stub.c test_echo_struct.c 
test_echo_struct_LDADD = \
           $(LDFLAGS) -L$(AXIS2C_HOME)/lib -laxutil -laxis2_axiom \
            -laxis2_wsdl -laxis2_engine -laxis2_parser -lpthread -laxis2_http_sender \
            -laxis2_http_receiver \
           $(GUTHTHILA_LIBS) $(LIBXML2_LIBS)

test_echo_string_array_SOURCES = \
  axis2_ArrayOfstring_literal.c axis2_echoStringArray.c \
  axis2_echoStringArrayResponse.c axis2_echoString.c \
  axis2_echoStringResponse.c axis2_echoStruct.c axis2_echoStructResponse.c \
  axis2_echoVoid.c axis2_echoVoidResponse.c axis2_SOAPStruct.c \
  axis2_WSDLInteropTestDocLitService_stub.c test_echo_string_array.c 
test_echo_string_array_LDADD = \
           $(LDFLAGS) -L$(AXIS2C_HOME)/lib -laxutil -laxis2_axiom \
            -laxis2_wsdl -laxis2_engine -laxis2_parser -lpthread -laxis2_http_sender \
            -laxis2_http_receiver \
           $(GUTHTHILA_LIBS) $(LIBXML2_LIBS)

INCLUDES = -I$(AXIS2C_HOME)/include \
               @UTILINC@ \
               @AXIOMINC@
