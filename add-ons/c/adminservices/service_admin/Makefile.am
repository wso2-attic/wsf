prglibdir=$(prefix)/services/ServiceAdmin
prglib_LTLIBRARIES = libServiceAdmin.la
prglib_DATA= resources/services.xml
noinst_HEADERS = 

libServiceAdmin_la_SOURCES =   adb_Policy.c \
                                axis2_skel_ServiceAdmin.c \
								codegen/adb_AbstractPolicyOperator.c \
								codegen/adb_PolicyComponent.c \
								codegen/adb_getModulePolicyResponse.c \
								codegen/adb_addPoliciesToService.c \
								codegen/adb_getNumberOfActiveServicesResponse.c \
								codegen/adb_PolicyMetaData.c \
								codegen/adb_addTransportBinding.c \
								codegen/adb_getNumberOfFaultyServicesResponse.c \
								codegen/adb_removeBindingPolicy.c \
								codegen/adb_addTransportBindingResponse.c \
								codegen/adb_getNumberOfInactiveServicesResponse.c \
								codegen/adb_removeServiceParameter.c \
								codegen/adb_All.c \
								codegen/adb_getOperationMessagePolicy.c \
								codegen/adb_removeServicePoliciesByNamespace.c \
								codegen/adb_changeServiceState.c \
								codegen/adb_getOperationMessagePolicyResponse.c \
								codegen/adb_removeTransportBinding.c \
								codegen/adb_configureMTOM.c \
								codegen/adb_getOperationPolicy.c \
								codegen/adb_removeTransportBindingResponse.c \
								codegen/adb_deleteFaultyServiceGroup.c \
								codegen/adb_getOperationPolicyResponse.c \
								codegen/adb_ServerException.c \
								codegen/adb_deleteFaultyServiceGroupResponse.c \
								codegen/adb_ServerExceptionE1.c \
								codegen/adb_getPolicies.c \
								codegen/adb_deleteFaultyServiceGroups.c \
								codegen/adb_getPoliciesResponse.c \
								codegen/adb_ServiceGroupMetaData.c \
								codegen/adb_deleteServiceGroups.c \
								codegen/adb_getPolicy.c \
								codegen/adb_ServiceGroupMetaDataWrapper.c \
								codegen/adb_engageModuleToService.c \
								codegen/adb_getPolicyResponse.c \
								codegen/adb_ServiceMetaData.c \
								codegen/adb_Exception.c \
								codegen/adb_ExceptionE0.c \
								codegen/adb_getServiceBindings.c \
								codegen/adb_setBindingOperationMessagePolicy.c \
								codegen/adb_getServiceBindingsResponse.c \
								codegen/adb_setBindingOperationPolicy.c \
								codegen/adb_FaultyService.c \
								codegen/adb_getServiceData.c \
								codegen/adb_setBindingPolicy.c \
								codegen/adb_FaultyServicesWrapper.c \
								codegen/adb_getServiceDataResponse.c \
								codegen/adb_setModulePolicy.c \
								codegen/adb_getBindingOperationMessagePolicy.c \
								codegen/adb_getServiceParameters.c \
								codegen/adb_setPolicy.c \
								codegen/adb_getBindingOperationMessagePolicyResponse.c \
								codegen/adb_getServiceParametersResponse.c \
								codegen/adb_setServiceOperationMessagePolicy.c \
								codegen/adb_getBindingOperationPolicy.c \
								codegen/adb_getWSDL.c \
								codegen/adb_setServiceOperationPolicy.c \
								codegen/adb_getBindingOperationPolicyResponse.c \
								codegen/adb_getWSDLResponse.c \
								codegen/adb_setServiceParameters.c \
								codegen/adb_getBindingPolicy.c \
								codegen/adb_Iterator.c \
								codegen/adb_setServicePolicy.c \
								codegen/adb_getBindingPolicyResponse.c \
								codegen/adb_listServiceGroup.c \
								codegen/adb_startService.c \
								codegen/adb_getExposedTransports.c \
								codegen/adb_listServiceGroupResponse.c \
								codegen/adb_stopService.c \
								codegen/adb_getExposedTransportsResponse.c \
								codegen/adb_listServiceGroups.c \
								codegen/axis2_extension_mapper.c \
								codegen/adb_getFaultyServiceArchives.c \
								codegen/adb_listServiceGroupsResponse.c \
								codegen/adb_getFaultyServiceArchivesResponse.c \
								codegen/axis2_svc_skel_ServiceAdmin.c \
								codegen/adb_Map.c \
								codegen/adb_getModulePolicy.c
libServiceAdmin_la_LIBADD = ../util/libservice_admin_util.la

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST= resources/services.xml resources/ServiceAdmin.wsdl codegen/adb_AbstractPolicyOperator.h codegen/adb_getModulePolicyResponse.h codegen/adb_Policy.h codegen/adb_addPoliciesToService.h codegen/adb_getNumberOfActiveServicesResponse.h codegen/adb_PolicyMetaData.h codegen/adb_addTransportBinding.h codegen/adb_getNumberOfFaultyServicesResponse.h codegen/adb_removeBindingPolicy.h codegen/adb_addTransportBindingResponse.h codegen/adb_getNumberOfInactiveServicesResponse.h codegen/adb_removeServiceParameter.h codegen/adb_All.h codegen/adb_getOperationMessagePolicy.h codegen/adb_removeServicePoliciesByNamespace.h codegen/adb_changeServiceState.h codegen/adb_getOperationMessagePolicyResponse.h codegen/adb_removeTransportBinding.h codegen/adb_configureMTOM.h codegen/adb_getOperationPolicy.h codegen/adb_removeTransportBindingResponse.h codegen/adb_deleteFaultyServiceGroup.h codegen/adb_getOperationPolicyResponse.h codegen/adb_ServerExceptionE1.h codegen/adb_deleteFaultyServiceGroupResponse.h codegen/adb_getPolicies.h codegen/adb_ServerException.h codegen/adb_deleteFaultyServiceGroups.h codegen/adb_getPoliciesResponse.h codegen/adb_ServiceGroupMetaData.h codegen/adb_deleteServiceGroups.h codegen/adb_getPolicy.h codegen/adb_ServiceGroupMetaDataWrapper.h codegen/adb_engageModuleToService.h codegen/adb_getPolicyResponse.h codegen/adb_ServiceMetaData.h codegen/adb_ExceptionE0.h codegen/adb_getServiceBindings.h codegen/adb_setBindingOperationMessagePolicy.h codegen/adb_Exception.h codegen/adb_getServiceBindingsResponse.h codegen/adb_setBindingOperationPolicy.h codegen/adb_FaultyService.h codegen/adb_getServiceData.h codegen/adb_setBindingPolicy.h codegen/adb_FaultyServicesWrapper.h codegen/adb_getServiceDataResponse.h codegen/adb_setModulePolicy.h codegen/adb_getBindingOperationMessagePolicy.h codegen/adb_getServiceParameters.h codegen/adb_setPolicy.h codegen/adb_getBindingOperationMessagePolicyResponse.h codegen/adb_getServiceParametersResponse.h codegen/adb_setServiceOperationMessagePolicy.h codegen/adb_getBindingOperationPolicy.h codegen/adb_getWSDL.h codegen/adb_setServiceOperationPolicy.h codegen/adb_getBindingOperationPolicyResponse.h codegen/adb_getWSDLResponse.h codegen/adb_setServiceParameters.h codegen/adb_getBindingPolicy.h codegen/adb_Iterator.h codegen/adb_setServicePolicy.h codegen/adb_getBindingPolicyResponse.h codegen/adb_listServiceGroup.h codegen/adb_startService.h codegen/adb_getExposedTransports.h codegen/adb_listServiceGroupResponse.h codegen/adb_stopService.h codegen/adb_getExposedTransportsResponse.h codegen/adb_listServiceGroups.h codegen/axis2_extension_mapper.h codegen/adb_getFaultyServiceArchives.h codegen/adb_listServiceGroupsResponse.h codegen/axis2_skel_ServiceAdmin.h codegen/adb_getFaultyServiceArchivesResponse.h codegen/adb_Map.h codegen/adb_getModulePolicy.h codegen/adb_PolicyComponent.h
