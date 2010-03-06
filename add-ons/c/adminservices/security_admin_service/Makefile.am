prglibdir=$(prefix)/services/SecurityAdminService
prglib_LTLIBRARIES = libSecurityAdminService.la
prglib_DATA= resources/services.xml resources/scenario-config.xml
noinst_HEADERS = 

libSecurityAdminService_la_SOURCES = axis2_skel_SecurityAdminService.c \
									   codegen/adb_activateUsernameTokenAuthentication.c \
									   codegen/adb_getSecurityScenarioResponse.c \
									   codegen/adb_getScenariosResponse.c \
									   codegen/adb_SecurityScenarioDataWrapper.c \
									   codegen/adb_applySecurity.c \
									   codegen/adb_SecurityConfigData.c \
									   codegen/adb_getSecurityConfigData.c \
									   codegen/axis2_extension_mapper.c \
									   codegen/adb_disableSecurityOnService.c \
									   codegen/adb_SecurityConfigException.c \
									   codegen/adb_getSecurityConfigDataResponse.c \
									   codegen/adb_SecurityConfigExceptionE0.c \
									   codegen/adb_Exception.c \
									   codegen/axis2_svc_skel_SecurityAdminService.c \
									   codegen/adb_getSecurityScenario.c \
									   codegen/adb_getScenarios.c \
									   codegen/adb_SecurityScenarioData.c
libSecurityAdminService_la_LIBADD =../util/libservice_admin_util.la 

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST= resources/services.xml resources/scenario10-policy.xml resources/scenario11-policy.xml resources/scenario12-policy.xml resources/scenario13-policy.xml resources/scenario14-policy.xml resources/scenario15-policy.xml resources/scenario16-policy.xml resources/scenario17-policy.xml resources/scenario1-policy.xml resources/scenario2-policy.xml resources/scenario3-policy.xml resources/scenario4-policy.xml resources/scenario5-policy.xml resources/scenario6-policy.xml resources/scenario7-policy.xml resources/scenario8-policy.xml resources/scenario9-policy.xml resources/scenario-config.xml codegen/adb_activateUsernameTokenAuthentication.h codegen/adb_getScenarios.h codegen/adb_getSecurityScenario.h codegen/adb_SecurityConfigException.h codegen/axis2_skel_SecurityAdminService.h codegen/adb_applySecurity.h codegen/adb_getScenariosResponse.h codegen/adb_getSecurityScenarioResponse.h codegen/adb_SecurityScenarioData.h codegen/adb_disableSecurityOnService.h codegen/adb_getSecurityConfigData.h codegen/adb_SecurityConfigData.h codegen/adb_SecurityScenarioDataWrapper.h codegen/adb_Exception.h codegen/adb_getSecurityConfigDataResponse.h codegen/adb_SecurityConfigExceptionE0.h codegen/axis2_extension_mapper.h

install-data-hook:
	mkdir -p $(prefix)/services/SecurityAdminService/policies
	cp -f resources/scenario*-policy.xml $(prefix)/services/SecurityAdminService/policies


