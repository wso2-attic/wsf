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
	PHP_ADD_INCLUDE(../wsf_c/axis2c/include/)
	PHP_ADD_INCLUDE(../wsf_c/axis2c/util/include/)
	PHP_ADD_INCLUDE(../wsf_c/axis2c/axiom/include/)
	PHP_ADD_INCLUDE(../wsf_c/axis2c/neethi/include/)
	PHP_ADD_INCLUDE(../wsf_c/rampartc/include/)
    PHP_ADD_INCLUDE(../wsf_c/axis2c/neethi/src/util/)
	PHP_ADD_INCLUDE(/usr/include/libxml2)
  	dnl # check for lib and symbol presence

  	PHP_ADD_LIBRARY_WITH_PATH(axis2_parser, ../wsf_c/axis2c/axiom/src/parser/libxml2/.libs, WSF_SHARED_LIBADD)
  	PHP_ADD_LIBRARY_WITH_PATH(axis2_axiom, ../wsf_c/axis2c/axiom/src/om/.libs, WSF_SHARED_LIBADD)
  	PHP_ADD_LIBRARY_WITH_PATH(axis2_minizip, ../wsf_c/axis2c/util/src/minizip/.libs, WSF_SHARED_LIBADD)
	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_engine, ../wsf_c/axis2c/src/core/engine/.libs, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axutil, ../wsf_c/axis2c/util/src/.libs, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_http_sender, ../wsf_c/axis2c/src/core/transport/http/sender/.libs, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(axis2_http_receiver, ../wsf_c/axis2c/src/core/transport/http/receiver/.libs, WSF_SHARED_LIBADD)	
	PHP_ADD_LIBRARY_WITH_PATH(mod_rampart, ../wsf_c/rampartc/src/core/.libs, WSF_SHARED_LIBADD)	
    PHP_ADD_LIBRARY_WITH_PATH(neethi, ../wsf_c/axis2c/neethi/src/.libs, WSF_SHARED_LIBADD)	
    PHP_ADD_LIBRARY_WITH_PATH(neethi_util, ../wsf_c/axis2c/neethi/src/util/.libs, WSF_SHARED_LIBADD)

  	PHP_SUBST(WSF_SHARED_LIBADD)

	PHP_NEW_EXTENSION(wsf, wsf.c xml_msg_recv.c util.c stream.c worker.c out_transport_info.c client.c  php_encoding.c php_http.c php_sdl.c php_schema.c php_xml.c wsf_soap.c policy.c , $ext_shared)
	
	PHP_ADD_EXTENSION_DEP(wsf, libxml)

	PHP_ADD_EXTENSION_DEP(wsf, dom)

	dnl PHP_ADD_EXTENSION_DEP(axis2, simplexml)

fi
