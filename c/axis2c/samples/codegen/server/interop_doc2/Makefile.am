prglibdir=$(prefix)/services/interop_doc2
samplesdir=$(prefix)/samples/server/interop_doc2
prglib_LTLIBRARIES = libWSDLInteropTestDocLitService.la
prglib_DATA= services.xml
EXTRA_DIST = services.xml
SUBDIRS =
libWSDLInteropTestDocLitService_la_SOURCES =  \
axis2_ArrayOfstring_literal.c    axis2_echoStringResponse.c  axis2_echoVoidResponse.c \
axis2_echoStringArray.c          axis2_echoStruct.c          axis2_SOAPStruct.c \
axis2_echoStringArrayResponse.c  axis2_echoStructResponse.c  axis2_WSDLInteropTestDocLitService.c \
axis2_echoString.c               axis2_echoVoid.c            axis2_WSDLInteropTestDocLitService_svc_skeleton.c

libWSDLInteropTestDocLitService_la_LIBADD  =
INCLUDES = -I$(AXIS2C_HOME)/include \
			@UTILINC@ \
			@AXIOMINC@
