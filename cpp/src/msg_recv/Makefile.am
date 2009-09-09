lib_LTLIBRARIES=libwsf_cpp_msg_recv.la

libwsf_cpp_msg_recv_la_SOURCES= wsf_cpp_msg_recv.cpp

libwsf_cpp_msg_recv_la_LIBADD=../main/libwso2_wsf.la \
        	             ../../wsf_c/axis2c/util/src/libaxutil.la \
                             ../../wsf_c/axis2c/axiom/src/om/libaxis2_axiom.la \
                	     ../../wsf_c/axis2c/neethi/src/libneethi.la \
	                     -lpthread


INCLUDES = -I ../../include \
		-I ../../wsf_c/axis2c/include \
		-I ../../wsf_c/axis2c/neethi/include \
		-I ../../wsf_c/axis2c/axiom/include \
		-I ../../wsf_c/axis2c/util/include \
		-I ../../wsf_c/axis2c/util/include/platforms 

