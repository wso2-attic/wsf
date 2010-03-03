prglibdir=$(prefix)/services/ServerAdmin
prglib_LTLIBRARIES = libServerAdmin.la
prglib_DATA= resources/services.xml
noinst_HEADERS = 

libServerAdmin_la_SOURCES =    axis2_skel_ServerAdmin.c \
								codegen/adb_Exception.c \
								codegen/adb_getServerStatusResponse.c \
								codegen/adb_restartResponse.c \
								codegen/axis2_extension_mapper.c \
								codegen/adb_ExceptionE0.c \
								codegen/adb_getServerVersionResponse.c \
								codegen/adb_ServerData.c \
								codegen/axis2_svc_skel_ServerAdmin.c \
								codegen/adb_getServerDataAsStringResponse.c \
								codegen/adb_isAliveResponse.c \
								codegen/adb_shutdownGracefullyResponse.c \
								codegen/adb_getServerDataResponse.c \
								codegen/adb_restartGracefullyResponse.c \
								codegen/adb_shutdownResponse.c
libServerAdmin_la_LIBADD = ../util/libservice_admin_util.la 

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST= resources/services.xml resources/ServerAdmin.wsdl codegen/adb_ExceptionE0.h codegen/adb_getServerVersionResponse.h codegen/adb_shutdownGracefullyResponse.h codegen/adb_Exception.h codegen/adb_isAliveResponse.h codegen/adb_shutdownResponse.h codegen/adb_getServerDataAsStringResponse.h codegen/adb_restartGracefullyResponse.h codegen/axis2_extension_mapper.h codegen/adb_getServerDataResponse.h codegen/adb_restartResponse.h codegen/axis2_skel_ServerAdmin.h codegen/adb_getServerStatusResponse.h codegen/adb_ServerData.h
