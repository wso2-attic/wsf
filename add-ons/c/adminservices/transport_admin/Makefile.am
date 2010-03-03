prglibdir=$(prefix)/services/TransportAdmin
prglib_LTLIBRARIES = libTransportAdmin.la
prglib_DATA= resources/services.xml
noinst_HEADERS = 

libTransportAdmin_la_SOURCES = axis2_skel_TransportAdmin.c \
								codegen/adb_addExposedTransports.c \
								codegen/adb_getServiceSpecificInParameters.c \
								codegen/adb_TransportData.c \
								codegen/adb_dependenciesAvailable.c \
								codegen/adb_getServiceSpecificInParametersResponse.c \
								codegen/adb_TransportDetails.c \
								codegen/adb_dependenciesAvailableResponse.c \
								codegen/adb_getServiceSpecificOutParameters.c \
								codegen/adb_TransportParameter.c \
								codegen/adb_disableListener.c \
								codegen/adb_getServiceSpecificOutParametersResponse.c \
								codegen/adb_TransportSummary.c \
								codegen/adb_disableSender.c \
								codegen/adb_getTransportDetails.c \
								codegen/adb_updateGloballyDefinedInParameters.c \
								codegen/adb_Exception.c \
								codegen/adb_getTransportDetailsResponse.c \
								codegen/adb_updateGloballyDefinedOutParameters.c \
								codegen/adb_ExceptionE0.c \
								codegen/adb_listExposedTransports.c \
								codegen/adb_updateServiceSpecificInParameters.c \
								codegen/adb_getAllTransportDataResponse.c \
								codegen/adb_listExposedTransportsResponse.c \
								codegen/adb_updateServiceSpecificOutParameters.c \
								codegen/adb_getGloballyDefinedInParameters.c \
								codegen/adb_listTransportsForService.c \
								codegen/axis2_extension_mapper.c \
								codegen/adb_getGloballyDefinedInParametersResponse.c \
								codegen/adb_listTransportsForServiceResponse.c \
								codegen/axis2_svc_skel_TransportAdmin.c \
								codegen/adb_getGloballyDefinedOutParameters.c \
								codegen/adb_listTransportsResponse.c \
								codegen/adb_getGloballyDefinedOutParametersResponse.c \
                                codegen/adb_removeExposedTransports.c
libTransportAdmin_la_LIBADD = 

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST= resources/services.xml resources/TransportAdmin.wsdl codegen/adb_addExposedTransports.h codegen/adb_getGloballyDefinedInParametersResponse.h codegen/adb_listExposedTransports.h codegen/adb_TransportSummary.h codegen/adb_dependenciesAvailable.h codegen/adb_getGloballyDefinedOutParameters.h codegen/adb_listExposedTransportsResponse.h codegen/adb_updateGloballyDefinedInParameters.h codegen/adb_dependenciesAvailableResponse.h codegen/adb_getGloballyDefinedOutParametersResponse.h codegen/adb_listTransportsForService.h codegen/adb_updateGloballyDefinedOutParameters.h codegen/adb_disableListener.h codegen/adb_getServiceSpecificInParameters.h codegen/adb_listTransportsForServiceResponse.h codegen/adb_updateServiceSpecificInParameters.h codegen/adb_disableSender.h codegen/adb_getServiceSpecificInParametersResponse.h codegen/adb_listTransportsResponse.h codegen/adb_updateServiceSpecificOutParameters.h codegen/adb_ExceptionE0.h codegen/adb_getServiceSpecificOutParameters.h codegen/adb_removeExposedTransports.h codegen/axis2_extension_mapper.h codegen/adb_Exception.h codegen/adb_getServiceSpecificOutParametersResponse.h codegen/adb_TransportData.h codegen/axis2_skel_TransportAdmin.h codegen/adb_getAllTransportDataResponse.h codegen/adb_getTransportDetails.h codegen/adb_TransportDetails.h codegen/adb_getGloballyDefinedInParameters.h codegen/adb_getTransportDetailsResponse.h codegen/adb_TransportParameter.h
