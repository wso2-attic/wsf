prglibdir=$(prefix)/services/LoggingAdmin
prglib_LTLIBRARIES = libLoggingAdmin.la
prglib_DATA= resources/services.xml
noinst_HEADERS = 

libLoggingAdmin_la_SOURCES = axis2_skel_LoggingAdmin.c \
							  codegen/adb_AppenderData.c \
							  codegen/adb_getAllLoggerDataResponse.c \
							  codegen/adb_getLoggerDataResponse.c \
							  codegen/adb_updateAllAppenderData.c \
							  codegen/axis2_svc_skel_LoggingAdmin.c \
							  codegen/adb_Exception.c \
							  codegen/adb_getAppenderData.c \
							  codegen/adb_getSystemLogResponse.c \
							  codegen/adb_updateLoggerData.c \
							  codegen/adb_ExceptionE0.c \
							  codegen/adb_getAppenderDataResponse.c \
							  codegen/adb_LogData.c \
							  codegen/adb_updateSystemLog.c \
							  codegen/adb_getAllLoggerData.c \
							  codegen/adb_getLoggerData.c \
							  codegen/adb_LoggerData.c \
							  codegen/axis2_extension_mapper.c 
libLoggingAdmin_la_LIBADD = 

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST= resources/services.xml resources/LoggingAdmin.wsdl codegen/adb_AppenderData.h codegen/adb_getAppenderData.h codegen/adb_LogData.h codegen/axis2_extension_mapper.h codegen/adb_ExceptionE0.h codegen/adb_getAppenderDataResponse.h codegen/adb_LoggerData.h codegen/axis2_skel_LoggingAdmin.h codegen/adb_Exception.h codegen/adb_getLoggerData.h codegen/adb_updateAllAppenderData.h codegen/adb_getAllLoggerData.h codegen/adb_getLoggerDataResponse.h codegen/adb_updateLoggerData.h codegen/adb_getAllLoggerDataResponse.h codegen/adb_getSystemLogResponse.h codegen/adb_updateSystemLog.h
