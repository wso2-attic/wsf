prglibdir=$(prefix)/samples/lib
prglib_LTLIBRARIES=libsctprovider.la libsctprovider_hashdb.la

libsctprovider_la_SOURCES= sct_provider.cpp
libsctprovider_la_LIBADD=../../../wsf_c/axis2c/src/core/description/libaxis2_description.la \
	             ../../../wsf_c/axis2c/src/core/deployment/libaxis2_deployment.la \
		     ../../../wsf_c/axis2c/src/core/context/libaxis2_context.la \
		     ../../../wsf_c/axis2c/util/src/libaxutil.la \
		     ../../../wsf_c/axis2c/neethi/src/libneethi.la \
		     ../../../wsf_c/axis2c/axiom/src/om/libaxis2_axiom.la \
   		     ../../../src/security/libwso2_wsf_security.la

libsctprovider_hashdb_la_SOURCES= sct_provider_hashdb.cpp
libsctprovider_hashdb_la_LIBADD=../../../wsf_c/axis2c/src/core/description/libaxis2_description.la \
	             ../../../wsf_c/axis2c/src/core/deployment/libaxis2_deployment.la \
		     ../../../wsf_c/axis2c/src/core/context/libaxis2_context.la \
		     ../../../wsf_c/axis2c/util/src/libaxutil.la \
		     ../../../wsf_c/axis2c/neethi/src/libneethi.la \
		     ../../../wsf_c/axis2c/axiom/src/om/libaxis2_axiom.la \
		     ../../../src/security/libwso2_wsf_security.la 

INCLUDES =  -I ../../../wsf_c/axis2c/include \
            -I ../../../wsf_c/axis2c/util/include \
            -I ../../../wsf_c/axis2c/util/include/platforms \
            -I ../../../wsf_c/axis2c/axiom/include \
            -I ../../../wsf_c/axis2c/neethi/include \
            -I ../../../wsf_c/rampartc/include \
            -I ../../../include


