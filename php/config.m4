PHP_ARG_ENABLE(wsf, Whether to enable WSF/PHP Support,
[ --with-wsf Enable WSO2 WSF/PHP Support])

if test "$PHP_WSF" = "yes"; then
	AC_DEFINE(HAVE_WSF, 1, [Whether you have WSO2 WSF/PHP])

	if test "$PHP_LIBXML" = "no"; then
		AC_MSG_ERROR([WSF/PHP extension requires LIBXML extension, add --enable-libxml])
	fi
	
    dnl # add include path

	PHP_ADD_INCLUDE(/opt/wso2/wsf_c/include/axis2-1.6.0)
	PHP_ADD_INCLUDE(/opt/wso2/wsf_c/include/sandesha2-0.91)
	PHP_ADD_INCLUDE(/opt/wso2/wsf_c/include/rampart-1.3.0)
	PHP_ADD_INCLUDE(/usr/include/libxml2)
  	dnl # check for lib and symbol presence

  	PHP_ADD_LIBRARY_WITH_PATH(axis2_parser, /opt/wso2/wsf_c/lib/, WSF_SHARED_LIBADD)
  	PHP_ADD_LIBRARY_WITH_PATH(axis2_axiom, /opt/wso2/wsf_c/lib/, WSF_SHARED_LIBADD)
	PHP_ADD_LIBRARY_WITH_PATH(axis2_engine, /opt/wso2/wsf_c/lib/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axutil, /opt/wso2/wsf_c/lib/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_http_sender, /opt/wso2/wsf_c/lib/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_http_receiver, /opt/wso2/wsf_c/lib/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(mod_rampart, /opt/wso2/wsf_c/modules/rampart/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(neethi, /opt/wso2/wsf_c/lib/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(neethi_util, /opt/wso2/wsf_c/lib/, WSF_SHARED_LIBADD)
	PHP_ADD_LIBRARY_WITH_PATH(sandesha2_client, /opt/wso2/wsf_c/lib/, WSF_SHARED_LIBADD)
  	PHP_SUBST(WSF_SHARED_LIBADD)

wsf_srcs="src/wsf.c \
src/wsf_xml_msg_recv.c \
src/wsf_util.c \
src/wsf_stream.c \
src/wsf_worker.c \
src/wsf_out_transport_info.c \
src/wsf_client.c \
src/wsf_policy.c \
src/wsf_wsdl.c"


	PHP_NEW_EXTENSION(wsf, $wsf_srcs , $ext_shared)
	PHP_ADD_BUILD_DIR($ext_builddir/src)
	PHP_ADD_EXTENSION_DEP(wsf, libxml)
fi
