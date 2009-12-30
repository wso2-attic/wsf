lib_LTLIBRARIES=libwso2_wsf.la

libwso2_wsf_la_SOURCES= WSFault.cpp \
			WSFException.cpp \
			OMAttribute.cpp \
			OMElement.cpp \
			OMNode.cpp \
			Options.cpp \
			ServiceClient.cpp \
			OMDataHandler.cpp \
			OMNamespace.cpp \
			OMText.cpp \
			Property.cpp \
			Parameter.cpp \
			Environment.cpp \
			NeethiPolicy.cpp \
			MessageContext.cpp \
			ServiceSkeleton.cpp \
			MessageReceiver.cpp \
			Stub.cpp 


libwso2_wsf_la_LIBADD = ../../wsf_c/axis2c/util/src/libaxutil.la \
                        ../../wsf_c/axis2c/neethi/src/libneethi.la \
                        ../../wsf_c/axis2c/axiom/src/om/libaxis2_axiom.la \
			-lpthread




INCLUDES = -I ../../include \
		-I ../../wsf_c/axis2c/include \
		-I ../../wsf_c/axis2c/util/include/platforms \
		-I ../../wsf_c/axis2c/neethi/include \
		-I ../../wsf_c/axis2c/axiom/include \
		-I ../../wsf_c/axis2c/util/include \
		-I ../../wsf_c/rampartc/include \
		-I ../../wsf_c/sandesha2c/include \
		-I ../../wsf_c/savanc/include 


EXTRA_DIST=wsf.rc
