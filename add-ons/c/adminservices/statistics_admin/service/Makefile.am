prglibdir=$(prefix)/services/StatisticsAdmin
prglib_LTLIBRARIES = libStatisticsAdmin.la
prglib_DATA= resources/services.xml
noinst_HEADERS = 
libStatisticsAdmin_la_SOURCES = axis2_skel_StatisticsAdmin.c \
								 codegen/adb_getAvgOperationResponseTime.c \
								 codegen/adb_getMinSystemResponseTimeResponse.c \
								 codegen/adb_getServiceResponseCountResponse.c \
								 codegen/adb_getAvgOperationResponseTimeResponse.c \
								 codegen/adb_getOperationFaultCount.c \
								 codegen/adb_getServiceStatistics.c \
								 codegen/adb_getAvgServiceResponseTime.c \
								 codegen/adb_getOperationFaultCountResponse.c \
								 codegen/adb_getServiceStatisticsResponse.c \
								 codegen/adb_getAvgServiceResponseTimeResponse.c \
								 codegen/adb_getOperationRequestCount.c \
								 codegen/adb_getSystemFaultCountResponse.c \
								 codegen/adb_getAvgSystemResponseTimeResponse.c \
								 codegen/adb_getOperationRequestCountResponse.c \
								 codegen/adb_getSystemRequestCountResponse.c \
								 codegen/adb_getMaxOperationResponseTime.c \
								 codegen/adb_getOperationResponseCount.c \
								 codegen/adb_getSystemResponseCountResponse.c \
								 codegen/adb_getMaxOperationResponseTimeResponse.c \
								 codegen/adb_getOperationResponseCountResponse.c \
								 codegen/adb_getSystemStatisticsResponse.c \
								 codegen/adb_getMaxServiceResponseTime.c \
								 codegen/adb_getOperationStatistics.c \
								 codegen/adb_Metric.c \
								 codegen/adb_getMaxServiceResponseTimeResponse.c \
								 codegen/adb_getOperationStatisticsResponse.c \
								 codegen/adb_OperationStatistics.c \
								 codegen/adb_getMaxSystemResponseTimeResponse.c \
								 codegen/adb_getServiceFaultCount.c \
								 codegen/adb_ServiceStatistics.c \
								 codegen/adb_getMinOperationResponseTime.c \
								 codegen/adb_getServiceFaultCountResponse.c \
								 codegen/adb_SystemStatistics.c \
								 codegen/adb_getMinOperationResponseTimeResponse.c \
								 codegen/adb_getServiceRequestCount.c \
								 codegen/axis2_extension_mapper.c \
								 codegen/adb_getMinServiceResponseTime.c \
								 codegen/adb_getServiceRequestCountResponse.c \
								 codegen/axis2_svc_skel_StatisticsAdmin.c \
								 codegen/adb_getMinServiceResponseTimeResponse.c \
								 codegen/adb_getServiceResponseCount.c
libStatisticsAdmin_la_LIBADD = ../../util/libservice_admin_util.la

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST=resources/services.xml resources/StatisticsAdmin.wsdl axis2_statistics_admin_constants.h codegen/adb_getAvgOperationResponseTime.h codegen/adb_getMinSystemResponseTimeResponse.h codegen/adb_getServiceResponseCountResponse.h codegen/adb_getAvgOperationResponseTimeResponse.h codegen/adb_getOperationFaultCount.h codegen/adb_getServiceStatistics.h codegen/adb_getAvgServiceResponseTime.h codegen/adb_getOperationFaultCountResponse.h codegen/adb_getServiceStatisticsResponse.h codegen/adb_getAvgServiceResponseTimeResponse.h codegen/adb_getOperationRequestCount.h codegen/adb_getSystemFaultCountResponse.h codegen/adb_getAvgSystemResponseTimeResponse.h codegen/adb_getOperationRequestCountResponse.h codegen/adb_getSystemRequestCountResponse.h codegen/adb_getMaxOperationResponseTime.h codegen/adb_getOperationResponseCount.h codegen/adb_getSystemResponseCountResponse.h codegen/adb_getMaxOperationResponseTimeResponse.h codegen/adb_getOperationResponseCountResponse.h codegen/adb_getSystemStatisticsResponse.h codegen/adb_getMaxServiceResponseTime.h codegen/adb_getOperationStatistics.h codegen/adb_Metric.h codegen/adb_getMaxServiceResponseTimeResponse.h codegen/adb_getOperationStatisticsResponse.h codegen/adb_OperationStatistics.h codegen/adb_getMaxSystemResponseTimeResponse.h codegen/adb_getServiceFaultCount.h codegen/adb_ServiceStatistics.h codegen/adb_getMinOperationResponseTime.h codegen/adb_getServiceFaultCountResponse.h codegen/adb_SystemStatistics.h codegen/adb_getMinOperationResponseTimeResponse.h codegen/adb_getServiceRequestCount.h codegen/axis2_extension_mapper.h codegen/adb_getMinServiceResponseTime.h codegen/adb_getServiceRequestCountResponse.h codegen/axis2_skel_StatisticsAdmin.h codegen/adb_getMinServiceResponseTimeResponse.h codegen/adb_getServiceResponseCount.h
