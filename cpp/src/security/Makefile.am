lib_LTLIBRARIES=libwso2_wsf_security.la

libwso2_wsf_security_la_SOURCES= AuthenticationProvider.cpp \
			PasswordCallback.cpp \
			ReplayDetector.cpp \
			SCTProvider.cpp

libwso2_wsf_security_la_LIBADD =../../wsf_c/axis2c/src/core/engine/libaxis2_engine.la \
                        ../../wsf_c/axis2c/util/src/libaxutil.la \
                        ../../wsf_c/axis2c/neethi/src/libneethi.la \
                        ../../wsf_c/axis2c/axiom/src/om/libaxis2_axiom.la \
			../../wsf_c/rampartc/src/util/librampart.la \
			../main/libwso2_wsf.la \
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


