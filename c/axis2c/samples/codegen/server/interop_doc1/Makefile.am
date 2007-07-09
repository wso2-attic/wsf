prglibdir=$(prefix)/services/interop_doc1
samplesdir=$(prefix)/samples/server/interop_doc1
prglib_LTLIBRARIES = libInteropTestPortTypeDocService.la
prglib_DATA= services.xml
EXTRA_DIST = services.xml
SUBDIRS =
libInteropTestPortTypeDocService_la_SOURCES =  \
axis2_echoBase64.c              axis2_echoFloatResponse.c         axis2_echoStructArray.c \
axis2_echoBase64Response.c      axis2_echoHexBinary.c             axis2_echoStructArrayResponse.c \
axis2_echoBoolean.c             axis2_echoHexBinaryResponse.c     axis2_echoStruct.c \
axis2_echoBooleanResponse.c     axis2_echoIntegerArray.c          axis2_echoStructResponse.c \
axis2_echoDate.c                axis2_echoIntegerArrayResponse.c  axis2_echoVoid.c \
axis2_echoDateResponse.c        axis2_echoInteger.c               axis2_echoVoidResponse.c \
axis2_echoDecimal.c             axis2_echoIntegerResponse.c       axis2_InteropTestPortTypeDocService.c \
axis2_echoDecimalResponse.c     axis2_echoStringArray.c           axis2_InteropTestPortTypeDocService_svc_skeleton.c \
axis2_echoFloatArray.c          axis2_echoStringArrayResponse.c   axis2_SOAPStruct.c \
axis2_echoFloatArrayResponse.c  axis2_echoString.c \
axis2_echoFloat.c               axis2_echoStringResponse.c

libInteropTestPortTypeDocService_la_LIBADD  =
INCLUDES = -I$(AXIS2C_HOME)/include \
			@UTILINC@ \
			@AXIOMINC@
