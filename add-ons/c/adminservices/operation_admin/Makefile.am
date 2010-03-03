prglibdir=$(prefix)/services/OperationAdmin
prglib_LTLIBRARIES = libOperationAdmin.la
prglib_DATA= resources/services.xml
noinst_HEADERS = 

libOperationAdmin_la_SOURCES = axis2_skel_OperationAdmin.c \
								codegen/adb_configureMTOM.c \
								codegen/adb_getPolicyResponse.c \
								codegen/adb_listPublishedOperationsResponse.c \
								codegen/adb_getDeclaredOperationParameters.c \
								codegen/adb_listAllOperations.c \
								codegen/adb_OperationMetaData.c \
								codegen/adb_getDeclaredOperationParametersResponse.c \
								codegen/adb_listAllOperationsResponse.c \
								codegen/adb_OperationMetaDataWrapper.c \
								codegen/adb_getOperationMetaData.c \
								codegen/adb_listControlOperations.c \
								codegen/adb_removeOperationParameter.c \
								codegen/adb_getOperationMetaDataResponse.c \
								codegen/adb_listControlOperationsResponse.c \
								codegen/adb_setOperationParameters.c \
								codegen/adb_getOperationParameters.c \
								codegen/adb_listOperationPhaseHandlers.c \
								codegen/adb_setPolicy.c \
								codegen/adb_getOperationParametersResponse.c \
								codegen/adb_listOperationPhaseHandlersResponse.c \
								codegen/axis2_extension_mapper.c \
								codegen/adb_getOperationStatistics.c \
								codegen/adb_listOperationPhases.c \
								codegen/axis2_svc_skel_OperationAdmin.c \
								codegen/adb_getOperationStatisticsResponse.c \
								codegen/adb_listOperationPhasesResponse.c \
								codegen/adb_getPolicy.c \
								codegen/adb_listPublishedOperations.c 
libOperationAdmin_la_LIBADD = ../util/libservice_admin_util.la

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST= resources/OperationAdmin.wsdl resources/services.xml codegen/adb_configureMTOM.h codegen/adb_getPolicyResponse.h codegen/adb_listPublishedOperationsResponse.h codegen/adb_getDeclaredOperationParameters.h codegen/adb_listAllOperations.h codegen/adb_OperationMetaData.h codegen/adb_getDeclaredOperationParametersResponse.h  codegen/adb_listAllOperationsResponse.h codegen/adb_OperationMetaDataWrapper.h codegen/adb_getOperationMetaData.h codegen/adb_listControlOperations.h codegen/adb_removeOperationParameter.h codegen/adb_getOperationMetaDataResponse.h codegen/adb_listControlOperationsResponse.h codegen/adb_setOperationParameters.h codegen/adb_getOperationParameters.h codegen/adb_listOperationPhaseHandlers.h codegen/adb_setPolicy.h codegen/adb_getOperationParametersResponse.h codegen/adb_listOperationPhaseHandlersResponse.h codegen/axis2_extension_mapper.h codegen/adb_getOperationStatistics.h codegen/adb_listOperationPhases.h codegen/axis2_skel_OperationAdmin.h codegen/adb_getOperationStatisticsResponse.h codegen/adb_listOperationPhasesResponse.h codegen/adb_getPolicy.h codegen/adb_listPublishedOperations.h
