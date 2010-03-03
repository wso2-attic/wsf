prglibdir=$(prefix)/services/ModuleAdminService
prglib_LTLIBRARIES = libModuleAdminService.la
prglib_DATA= resources/services.xml
noinst_HEADERS = 

libModuleAdminService_la_SOURCES = axis2_skel_ModuleAdminService.c \
							 codegen/adb_disengageModuleForOperation.c \
							 codegen/adb_getModuleInfo.c \
							 codegen/adb_listModulesResponse.c \
							 codegen/adb_disengageModuleForOperationResponse.c \
							 codegen/adb_getModuleInfoResponse.c \
							 codegen/adb_ModuleMetaData.c \
							 codegen/adb_disengageModuleForService.c \
							 codegen/adb_getModuleParameters.c \
							 codegen/adb_ModuleMgtException.c \
							 codegen/adb_disengageModuleForServiceGroup.c \
							 codegen/adb_ModuleMgtExceptionE0.c \
							 codegen/adb_getModuleParametersResponse.c \
							 codegen/adb_disengageModuleForServiceGroupResponse.c \
							 codegen/adb_globallyDisengageModule.c \
							 codegen/adb_removeModule.c \
							 codegen/adb_disengageModuleForServiceResponse.c \
							 codegen/adb_globallyDisengageModuleResponse.c \
							 codegen/adb_removeModuleParameter.c \
							 codegen/adb_disengageModuleFromSystem.c \
							 codegen/adb_globallyEngageModule.c \
							 codegen/adb_removeModuleParameterResponse.c \
							 codegen/adb_disengageModuleFromSystemResponse.c \
							 codegen/adb_globallyEngageModuleResponse.c \
							 codegen/adb_removeModuleResponse.c \
							 codegen/adb_engageModuleForOperation.c \
							 codegen/adb_listGloballyEngagedModulesResponse.c \
							 codegen/adb_setModuleParameters.c \
							 codegen/adb_engageModuleForOperationResponse.c \
							 codegen/adb_listModulesForOperation.c \
							 codegen/adb_uploadModule.c \
							 codegen/adb_engageModuleForService.c \
							 codegen/adb_listModulesForOperationResponse.c \
							 codegen/adb_uploadModuleResponse.c \
							 codegen/adb_engageModuleForServiceGroup.c \
							 codegen/adb_listModulesForService.c \
							 codegen/axis2_extension_mapper.c \
							 codegen/adb_engageModuleForServiceGroupResponse.c \
							 codegen/adb_listModulesForServiceGroup.c \
							 codegen/adb_listModulesForServiceGroupResponse.c \
							 codegen/axis2_svc_skel_ModuleAdminService.c \
							 codegen/adb_engageModuleForServiceResponse.c \
							 codegen/adb_Exception.c \
							 codegen/adb_listModulesForServiceResponse.c

libModuleAdminService_la_LIBADD = ../util/libservice_admin_util.la


INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST= resources/ModuleAdminService.wsdl resources/services.xml codegen/adb_disengageModuleForOperation.h codegen/adb_engageModuleForServiceGroupResponse.h codegen/adb_globallyEngageModuleResponse.h codegen/adb_ModuleMgtException.h codegen/adb_disengageModuleForOperationResponse.h codegen/adb_engageModuleForService.h codegen/adb_listGloballyEngagedModulesResponse.h codegen/adb_removeModule.h codegen/adb_disengageModuleForServiceGroup.h codegen/adb_engageModuleForServiceResponse.h codegen/adb_listModulesForOperation.h codegen/adb_removeModuleParameter.h codegen/adb_disengageModuleForServiceGroupResponse.h codegen/adb_Exception.h codegen/adb_listModulesForOperationResponse.h codegen/adb_removeModuleParameterResponse.h codegen/adb_disengageModuleForService.h codegen/adb_getModuleInfo.h codegen/adb_listModulesForServiceGroup.h codegen/adb_removeModuleResponse.h codegen/adb_disengageModuleForServiceResponse.h codegen/adb_getModuleInfoResponse.h codegen/adb_listModulesForServiceGroupResponse.h codegen/adb_setModuleParameters.h codegen/adb_disengageModuleFromSystem.h codegen/adb_getModuleParameters.h codegen/adb_listModulesForService.h codegen/adb_uploadModule.h codegen/adb_disengageModuleFromSystemResponse.h codegen/adb_getModuleParametersResponse.h codegen/adb_listModulesForServiceResponse.h codegen/adb_uploadModuleResponse.h codegen/adb_engageModuleForOperation.h codegen/adb_globallyDisengageModule.h codegen/adb_listModulesResponse.h codegen/axis2_extension_mapper.h codegen/adb_engageModuleForOperationResponse.h codegen/adb_globallyDisengageModuleResponse.h codegen/adb_ModuleMetaData.h codegen/axis2_skel_ModuleAdminService.h codegen/adb_engageModuleForServiceGroup.h codegen/adb_globallyEngageModule.h codegen/adb_ModuleMgtExceptionE0.h
