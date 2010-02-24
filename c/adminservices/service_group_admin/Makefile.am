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
libServiceGroupAdmin_la_LIBADD = 

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST=
