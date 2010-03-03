prglibdir=$(prefix)/services/ResourceAdminService
prglib_LTLIBRARIES = libResourceAdminService.la
prglib_DATA= resources/services.xml
noinst_HEADERS = 

libResourceAdminService_la_SOURCES = axis2_skel_ResourceAdminService.c \
							   codegen/adb_addCollection.c \
							   codegen/adb_getVersionsBeanResponse.c \
							   codegen/adb_getCollectionContentResponse.c \
							   codegen/adb_addCollectionResponse.c \
							   codegen/adb_importResource.c \
							   codegen/adb_getCollectionMediatypeDefinitionsResponse.c \
							   codegen/adb_addRemoteLink.c \
							   codegen/adb_MetadataBean.c \
							   codegen/adb_getContentBean.c \
							   codegen/adb_addResource.c \
							   codegen/adb_moveResource.c \
							   codegen/adb_getContentBeanResponse.c \
							   codegen/adb_addRolePermission.c \
							   codegen/adb_PermissionBean.c \
							   codegen/adb_getContentDownloadBean.c \
							   codegen/adb_addRolePermissionResponse.c \
							   codegen/adb_PermissionEntry.c \
							   codegen/adb_getContentDownloadBeanResponse.c \
							   codegen/adb_addSymbolicLink.c \
							   codegen/adb_renameResource.c \
							   codegen/adb_getCustomUIMediatypeDefinitionsResponse.c \
							   codegen/adb_addTextResource.c \
							   codegen/adb_ResourceData.c \
							   codegen/adb_getMediatypeDefinitionsResponse.c \
							   codegen/adb_addUserPermission.c \
							   codegen/adb_ResourceServiceException.c \
							   codegen/adb_getMetadata.c \
							   codegen/adb_ResourceServiceExceptionE0.c \
							   codegen/adb_addUserPermissionResponse.c \
							   codegen/adb_getMetadataResponse.c \
							   codegen/adb_changeRolePermissions.c \
							   codegen/adb_ResourceTreeEntryBean.c \
							   codegen/adb_getPermissions.c \
							   codegen/adb_changeRolePermissionsResponse.c \
							   codegen/adb_restoreVersion.c \
							   codegen/adb_getPermissionsResponse.c \
							   codegen/adb_changeUserPermissions.c \
							   codegen/adb_setDescription.c \
							   codegen/adb_getProperty.c \
							   codegen/adb_changeUserPermissionsResponse.c \
							   codegen/adb_setSessionResourcePath.c \
							   codegen/adb_getPropertyResponse.c \
							   codegen/adb_CollectionContentBean.c \
							   codegen/adb_TagCount.c \
							   codegen/adb_getResourceData.c \
							   codegen/adb_ContentBean.c \
							   codegen/adb_updateTextContent.c \
							   codegen/adb_getResourceDataResponse.c \
							   codegen/adb_ContentDownloadBean.c \
							   codegen/adb_VersionPath.c \
							   codegen/adb_getResourceTreeEntry.c \
							   codegen/adb_copyResource.c \
							   codegen/adb_VersionsBean.c \
							   codegen/adb_getResourceTreeEntryResponse.c \
							   codegen/adb_createVersion.c \
							   codegen/adb_WebResourcePath.c \
							   codegen/adb_getSessionResourcePathResponse.c \
							   codegen/adb__delete.c \
							   codegen/axis2_extension_mapper.c \
							   codegen/adb_getTextContent.c \
							   codegen/adb_Exception.c \
							   codegen/adb_ExceptionE1.c \
							   codegen/adb_getTextContentResponse.c \
							   codegen/axis2_svc_skel_ResourceAdminService.c \
							   codegen/adb_getVersionsBean.c \
							   codegen/adb_getCollectionContent.c 
libResourceAdminService_la_LIBADD =../util/libservice_admin_util.la

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST= resources/services.xml codegen/adb_addCollection.h codegen/adb_copyResource.h codegen/adb_getPermissionsResponse.h codegen/adb_renameResource.h codegen/adb_addCollectionResponse.h codegen/adb_createVersion.h codegen/adb_getProperty.h codegen/adb_ResourceData.h codegen/adb_addRemoteLink.h codegen/adb__delete.h codegen/adb_getPropertyResponse.h codegen/adb_ResourceServiceExceptionE0.h codegen/adb_addResource.h codegen/adb_ExceptionE1.h codegen/adb_getResourceData.h codegen/adb_ResourceServiceException.h codegen/adb_addRolePermission.h codegen/adb_Exception.h codegen/adb_getResourceDataResponse.h codegen/adb_ResourceTreeEntryBean.h codegen/adb_addRolePermissionResponse.h codegen/adb_getCollectionContent.h codegen/adb_getResourceTreeEntry.h codegen/adb_restoreVersion.h codegen/adb_addSymbolicLink.h codegen/adb_getCollectionContentResponse.h codegen/adb_getResourceTreeEntryResponse.h codegen/adb_setDescription.h codegen/adb_addTextResource.h codegen/adb_getCollectionMediatypeDefinitionsResponse.h codegen/adb_getSessionResourcePathResponse.h codegen/adb_setSessionResourcePath.h codegen/adb_addUserPermission.h codegen/adb_getContentBean.h codegen/adb_getTextContent.h codegen/adb_TagCount.h codegen/adb_addUserPermissionResponse.h codegen/adb_getContentBeanResponse.h codegen/adb_getTextContentResponse.h codegen/adb_updateTextContent.h codegen/adb_changeRolePermissions.h codegen/adb_getContentDownloadBean.h codegen/adb_getVersionsBean.h codegen/adb_VersionPath.h codegen/adb_changeRolePermissionsResponse.h codegen/adb_getContentDownloadBeanResponse.h codegen/adb_getVersionsBeanResponse.h codegen/adb_VersionsBean.h codegen/adb_changeUserPermissions.h codegen/adb_getCustomUIMediatypeDefinitionsResponse.h codegen/adb_importResource.h codegen/adb_WebResourcePath.h codegen/adb_changeUserPermissionsResponse.h codegen/adb_getMediatypeDefinitionsResponse.h codegen/adb_MetadataBean.h codegen/axis2_extension_mapper.h codegen/adb_CollectionContentBean.h codegen/adb_getMetadata.h codegen/adb_moveResource.h codegen/axis2_skel_ResourceAdminService.h codegen/adb_ContentBean.h codegen/adb_getMetadataResponse.h codegen/adb_PermissionBean.h codegen/adb_ContentDownloadBean.h codegen/adb_getPermissions.h codegen/adb_PermissionEntry.h
