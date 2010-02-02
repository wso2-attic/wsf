prglibdir=$(prefix)/modules/bam_publisher
prglib_LTLIBRARIES = libbam_publisher.la
prglib_DATA= module.xml

libbam_publisher_la_SOURCES = svc_stat_handler.c \
								 op_stat_handler.c \
								 mod_bam_publisher.c \
								 util.c \
								 statistics.c \
								 codegen/adb_getAvgOperationResponseTime.c \
								 codegen/adb_getMinServiceResponseTimeResponse.c \
								 codegen/adb_getServiceRequestCountResponse.c \
								 codegen/adb_getAvgOperationResponseTimeResponse.c \
								 codegen/adb_getMinSystemResponseTimeResponse.c \
								 codegen/adb_getServiceResponseCount.c \
								 codegen/adb_getAvgServiceResponseTime.c \
								 codegen/adb_getOperationFaultCount.c \
								 codegen/adb_getServiceResponseCountResponse.c \
								 codegen/adb_getAvgServiceResponseTimeResponse.c \
								 codegen/adb_getOperationFaultCountResponse.c \
								 codegen/adb_getServiceStatistics.c \
								 codegen/adb_getAvgSystemResponseTimeResponse.c \
								 codegen/adb_getOperationRequestCount.c \
								 codegen/adb_getServiceStatisticsResponse.c \
								 codegen/adb_getMaxOperationResponseTime.c \
								 codegen/adb_getOperationRequestCountResponse.c \
								 codegen/adb_getSystemFaultCountResponse.c \
								 codegen/adb_getMaxOperationResponseTimeResponse.c \
								 codegen/adb_getOperationResponseCount.c \
								 codegen/adb_getSystemRequestCountResponse.c \
								 codegen/adb_getMaxServiceResponseTime.c \
								 codegen/adb_getOperationResponseCountResponse.c \
								 codegen/adb_getSystemResponseCountResponse.c \
								 codegen/adb_getMaxServiceResponseTimeResponse.c \
								 codegen/adb_getOperationStatistics.c \
								 codegen/adb_getSystemStatisticsResponse.c \
								 codegen/adb_getMaxSystemResponseTimeResponse.c \
								 codegen/adb_getOperationStatisticsResponse.c \
								 codegen/adb_Metric.c codegen/adb_getMinOperationResponseTime.c \
								 codegen/adb_getServiceFaultCount.c \
								 codegen/adb_OperationStatistics.c \
								 codegen/adb_getMinOperationResponseTimeResponse.c \
								 codegen/adb_getServiceFaultCountResponse.c \
								 codegen/adb_ServiceStatistics.c \
								 codegen/adb_getMinServiceResponseTime.c \
								 codegen/adb_getServiceRequestCount.c \
								 codegen/adb_SystemStatistics.c
libbam_publisher_la_LIBADD = ../../util/libservice_admin_util.la

INCLUDES = -I$(top_builddir)/include \
			-I. \
			-I./codegen \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST=module.xml
