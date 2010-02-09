noinst_LTLIBRARIES = libkeystore_admin.la

libkeystore_admin_la_SOURCES = axis2_skel_KeyStoreAdminService.c \
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
libkeystore_admin_la_LIBADD = 

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@RAMPARTINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST=
