prglibdir=$(prefix)/services/KeyStoreAdminService
prglib_LTLIBRARIES = libKeyStoreAdminService.la
prglib_DATA= resources/services.xml
noinst_HEADERS = 

libKeyStoreAdminService_la_SOURCES = axis2_skel_KeyStoreAdminService.c \
							   codegen/adb_addKeyStore.c \
							   codegen/adb_getStoreEntries.c \
							   codegen/adb_getKeystoreInfo.c \
							   codegen/adb_SecurityConfigException.c \
							   codegen/axis2_svc_skel_KeyStoreAdminService.c \
							   codegen/adb_CertData.c \
							   codegen/adb_getStoreEntriesResponse.c \
							   codegen/adb_SecurityConfigExceptionE0.c \
							   codegen/adb_getKeystoreInfoResponse.c \
							   codegen/adb_deleteStore.c \
							   codegen/adb_importCertToStore.c \
							   codegen/adb_getKeyStoresResponse.c \
							   codegen/axis2_extension_mapper.c \
							   codegen/adb_Exception.c \
							   codegen/adb_KeyStoreData.c

libKeyStoreAdminService_la_LIBADD = ../util/libservice_admin_util.la \
				$(prefix)/lib/librampart.la
	

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@RAMPARTINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST= resources/services.xml resources/KeyStoreAdminService.wsdl resources/wso2wsfc.dat resources/wso2wsfc.p12 codegen/adb_addKeyStore.h codegen/adb_Exception.h codegen/adb_getKeyStoresResponse.h codegen/adb_importCertToStore.h codegen/adb_SecurityConfigException.h codegen/adb_CertData.h codegen/adb_getKeystoreInfo.h codegen/adb_getStoreEntries.h codegen/adb_KeyStoreData.h codegen/axis2_extension_mapper.h codegen/adb_deleteStore.h codegen/adb_getKeystoreInfoResponse.h codegen/adb_getStoreEntriesResponse.h codegen/adb_SecurityConfigExceptionE0.h codegen/axis2_skel_KeyStoreAdminService.h

install-data-hook:
	mkdir -p $(prefix)/services/KeyStoreAdminService/keystores
	cp -f resources/wso2wsfc.* $(prefix)/services/KeyStoreAdminService/keystores

