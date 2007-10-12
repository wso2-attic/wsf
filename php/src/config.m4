PHP_ARG_ENABLE(wsf, Whether to enable WSF/PHP Support,
[ --with-wsf Enable WSO2 WSF/PHP Support])

if test "$PHP_WSF" = "yes"; then
	AC_DEFINE(HAVE_WSF, 1, [Whether you have WSO2 WSF/PHP])

	if test "$PHP_LIBXML" = "no"; then
		AC_MSG_ERROR([WSF/PHP extension requires LIBXML extension, add --enable-libxml])
	fi
	
    dnl # add include path
	PHP_ADD_INCLUDE(/opt/wso2/wsfc/include/axis2-1.1)
	PHP_ADD_INCLUDE(/opt/wso2/wsfc/sandesha2/include/sandesha2-0.91)
	PHP_ADD_INCLUDE(/opt/wso2/wsfc/rampart/include/rampart-1.0)
	PHP_ADD_INCLUDE(/usr/include/libxml2)
  	dnl # check for lib and symbol presence

  	PHP_ADD_LIBRARY_WITH_PATH(axis2_parser, /opt/wso2/wsfc/lib/, WSF_SHARED_LIBADD)
  	PHP_ADD_LIBRARY_WITH_PATH(axis2_axiom, /opt/wso2/wsfc/lib/, WSF_SHARED_LIBADD)
  	PHP_ADD_LIBRARY_WITH_PATH(axis2_minizip, /opt/wso2/wsfc/lib/, WSF_SHARED_LIBADD)
	PHP_ADD_LIBRARY_WITH_PATH(axis2_engine, /opt/wso2/wsfc/lib/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axutil, /opt/wso2/wsfc/lib/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_http_sender, /opt/wso2/wsfc/lib/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_http_receiver, /opt/wso2/wsfc/lib/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(mod_rampart, /opt/wso2/wsfc/modules/rampart/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(neethi, /opt/wso2/wsfc/lib/, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(neethi_util, /opt/wso2/wsfc/lib/, WSF_SHARED_LIBADD)
  	PHP_SUBST(WSF_SHARED_LIBADD)

	PHP_NEW_EXTENSION(wsf, wsf.c wsf_xml_msg_recv.c wsf_util.c wsf_stream.c wsf_worker.c wsf_out_transport_info.c wsf_client.c  php_encoding.c php_sdl.c php_http.c php_schema.c php_xml.c wsf_soap.c wsf_policy.c wsf_wsdl.c, $ext_shared)
	
	PHP_ADD_EXTENSION_DEP(wsf, libxml)
	PHP_ADD_EXTENSION_DEP(wsf, dom)
fi
