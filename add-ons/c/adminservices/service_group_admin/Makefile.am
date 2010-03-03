prglibdir=$(prefix)/services/ServiceGroupAdmin
prglib_LTLIBRARIES = libServiceGroupAdmin.la
prglib_DATA= resources/services.xml
noinst_HEADERS = 

libServiceGroupAdmin_la_SOURCES = axis2_skel_ServiceGroupAdmin.c \
									codegen/adb_configureServiceGroupMTOM.c \
									codegen/adb_removeServiceGroupParameter.c \
									codegen/adb_getServiceGroupParameterResponse.c \
									codegen/adb_updateServiceGroupParameter.c \
									codegen/adb_configureServiceGroupMTOMResponse.c \
									codegen/adb_ServerException.c \
									codegen/adb_getServiceGroupParameters.c \
									codegen/adb_ServerExceptionE1.c \
									codegen/adb_updateServiceGroupParamters.c \
									codegen/adb_dumpAAR.c \
									codegen/adb_getServiceGroupParametersResponse.c \
									codegen/axis2_extension_mapper.c \
									codegen/adb_dumpAARResponse.c \
									codegen/adb_ServiceGroupMetaData.c \
									codegen/adb_listServiceGroup.c \
									codegen/adb_Exception.c \
									codegen/adb_ServiceMetaData.c \
									codegen/axis2_svc_skel_ServiceGroupAdmin.c \
									codegen/adb_ExceptionE0.c \
									codegen/adb_listServiceGroupResponse.c \
									codegen/adb_setServiceGroupParameter.c \
									codegen/adb_ParameterMetaData.c \
									codegen/adb_getServiceGroupParameter.c \
									codegen/adb_setServiceGroupParameters.c 
libServiceGroupAdmin_la_LIBADD = ../util/libservice_admin_util.la

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST= resources/services.xml resources/ServiceGroupAdmin.wsdl codegen/adb_configureServiceGroupMTOM.h codegen/adb_getServiceGroupParameters.h codegen/adb_ServiceGroupMetaData.h codegen/adb_configureServiceGroupMTOMResponse.h codegen/adb_getServiceGroupParametersResponse.h codegen/adb_ServiceMetaData.h codegen/adb_dumpAAR.h codegen/adb_listServiceGroup.h codegen/adb_setServiceGroupParameter.h codegen/adb_dumpAARResponse.h codegen/adb_listServiceGroupResponse.h codegen/adb_setServiceGroupParameters.h codegen/adb_ExceptionE0.h codegen/adb_ParameterMetaData.h codegen/adb_updateServiceGroupParameter.h codegen/adb_Exception.h codegen/adb_removeServiceGroupParameter.h codegen/adb_updateServiceGroupParamters.h codegen/adb_getServiceGroupParameter.h codegen/adb_ServerExceptionE1.h codegen/axis2_extension_mapper.h codegen/adb_getServiceGroupParameterResponse.h codegen/adb_ServerException.h codegen/axis2_skel_ServiceGroupAdmin.h
