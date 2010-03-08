prglibdir=$(prefix)/services/AuthenticationAdminService
prglib_LTLIBRARIES = libAuthenticationAdminService.la
prglib_DATA= resources/services.xml
noinst_HEADERS = 

libAuthenticationAdminService_la_SOURCES =  axis2_skel_AuthenticationAdminService.c \
								codegen/adb_AccessControlAdmin.c \
								codegen/adb_ExceptionE0.c \
								codegen/adb_loginResponse.c \
								codegen/adb_UserStoreAdmin.c \
								codegen/adb_AuthenticationException.c \
								codegen/adb_loginWithDelegation.c \
								codegen/adb_AuthenticationExceptionE1.c \
								codegen/adb_getSystemPermissionOfUser.c \
								codegen/adb_UserStoreReader.c \
								codegen/adb_loginWithDelegationResponse.c \
								codegen/adb_getSystemPermissionOfUserResponse.c \
								codegen/adb_Authenticator.c \
								codegen/adb_ProfileConfiguration.c \
								codegen/axis2_extension_mapper.c \
								codegen/adb_getUserPermissions.c \
								codegen/adb_Authorizer.c \
								codegen/adb_UserClaimsAdmin.c \
								codegen/adb_getUserPermissionsResponse.c \
								codegen/axis2_svc_skel_AuthenticationAdminService.c \
								codegen/adb_Claim.c \
								codegen/adb_UserProfileAdmin.c \
								codegen/adb_login.c \
								codegen/adb_Exception.c \
								codegen/adb_UserRealm.c
libAuthenticationAdminService_la_LIBADD = 

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST= resources/services.xml resources/AuthenticationAdminService.wsdl codegen/adb_AccessControlAdmin.h codegen/adb_Claim.h codegen/adb_getUserPermissions.h codegen/adb_loginWithDelegationResponse.h codegen/adb_UserStoreAdmin.h codegen/adb_AuthenticationExceptionE1.h codegen/adb_ExceptionE0.h codegen/adb_getUserPermissionsResponse.h codegen/adb_ProfileConfiguration.h codegen/adb_UserStoreReader.h codegen/adb_AuthenticationException.h codegen/adb_Exception.h codegen/adb_login.h codegen/adb_UserClaimsAdmin.h codegen/axis2_extension_mapper.h codegen/adb_Authenticator.h codegen/adb_getSystemPermissionOfUser.h codegen/adb_loginResponse.h codegen/adb_UserProfileAdmin.h codegen/axis2_skel_AuthenticationAdminService.h codegen/adb_Authorizer.h codegen/adb_getSystemPermissionOfUserResponse.h codegen/adb_loginWithDelegation.h codegen/adb_UserRealm.h
