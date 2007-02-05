PHP_ARG_ENABLE(wsf, whether to eable AXIS2 support,
[ --with-wsf Enable WSO2 WSF for PHP support])

if test "$PHP_WSF" = "yes"; then
	AC_DEFINE(HAVE_WSF, 1, [Whether you have WSO2 WSF for PHP])

	if test -z "AXIS2C_HOME"; then
		AC_MSG_RESULT([not found])
		AC_MSG_ERROR(Cannot find Axis2C home. Please set AXIS2C_HOME env variable)
	fi	

	if test "$PHP_LIBXML" = "no"; then
		AC_MSG_ERROR([SimpleXML extension requires LIBXML extension, add --enable-libxml])
	fi
	
	 dnl # add include path
	PHP_ADD_INCLUDE(../wsf_c/axis2/include/)
	PHP_ADD_INCLUDE(../wsf_c/axis2/util/include/)
	PHP_ADD_INCLUDE(../wsf_c/axis2/axiom/include/)
	PHP_ADD_INCLUDE(../wsf_c/axis2/xml_schema/include/)
	PHP_ADD_INCLUDE(../wsf_c/axis2/woden/include/)
	PHP_ADD_INCLUDE(../wsf_c/axis2/rampart/include/)
	PHP_ADD_INCLUDE(/usr/include/libxml2)
  	dnl # check for lib and symbol presence

  	PHP_ADD_LIBRARY_WITH_PATH(axis2_parser, ../wsf_c/axis2/axiom/src/parser/libxml2/.libs, WSF_SHARED_LIBADD)
  	PHP_ADD_LIBRARY_WITH_PATH(axis2_axiom, ../wsf_c/axis2/axiom/src/om/.libs, WSF_SHARED_LIBADD)
  	PHP_ADD_LIBRARY_WITH_PATH(axis2_minizip, ../wsf_c/axis2/util/src/minizip/.libs, WSF_SHARED_LIBADD)
	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_engine, ../wsf_c/axis2/modules/core/engine/.libs, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_wsdl, ../wsf_c/axis2/modules/wsdl/.libs, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_util, ../wsf_c/axis2/util/src/.libs, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_http_sender, ../wsf_c/axis2/modules/core/transport/http/sender/.libs, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_http_receiver, ../wsf_c/axis2/modules/core/transport/http/receiver/.libs, WSF_SHARED_LIBADD)	

  	PHP_SUBST(WSF_SHARED_LIBADD)

	PHP_NEW_EXTENSION(wsf, wsf.c php_xml.c php_encoding.c php_schema.c php_http.c php_sdl.c xml_msg_recv.c util.c stream.c worker.c out_transport_info.c , $ext_shared)
	
	PHP_ADD_EXTENSION_DEP(wsf, libxml)

	PHP_ADD_EXTENSION_DEP(wsf, dom)

	dnl PHP_ADD_EXTENSION_DEP(axis2, simplexml)

fi
