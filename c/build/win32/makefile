# THIS IS THE MAKE FILE FOR AXIS2/C
# this file should reside in the win32 directory of the source directory
# when executed 
# nmake [all] build dlls , server , samples [ client, server ] 
# nmake clean clean everything
# nmake samples build samples
# nmake install to install axis2 with server all modules and services
# nmake dist    to create the distribution, builds all distributable components

#It is possible to run individual targets to build those targets only, 
# eg nmake axis2_apache_module , will build apache module


# install directory will be (default)deploy or a user specified  directory
# then the directory structure is following
#      AXIS2_INSTALL_DIR
#	|
#	|- bin        - server and other executables
#       |   |- samples - samples
#       |- logs	
#	|- lib	      - library modules
#	|- services   - deployed services will be hear
#	|- modules    - deployed modules will be hear
#       |- include    - all include files of axis2 will go here
#       |- tests
#            |- system_tests
#            |- unit tests           

AUTOCONF = configure.in
!include $(AUTOCONF)

# directory structure of install directory

AXIS2_INSTALL_DIR = ..\deploy
AXIS2_SERVICES = $(AXIS2_INSTALL_DIR)\services
AXIS2_MODULES = $(AXIS2_INSTALL_DIR)\modules
AXIS2_LIBS = $(AXIS2_INSTALL_DIR)\lib
AXIS2_BINS = $(AXIS2_INSTALL_DIR)\bin
AXIS2_INCLUDE = $(AXIS2_INSTALL_DIR)\include
AXIS2_SAMPLES = $(AXIS2_BINS)\samples
AXIS2_LOG     = $(AXIS2_INSTALL_DIR)\logs
AXIS2_TESTS = $(AXIS2_INSTALL_DIR)\tests
AXIS2_TESTS_SYS = $(AXIS2_TESTS)\system_tests
AXIS2_TESTS_UNIT = $(AXIS2_TESTS)\unit_tests
AXIS2_SOURCE_DIR = ..\..\axis2
RAMPART_INCLUDE = $(AXIS2_SOURCE_DIR)\rampart\include 
WSCLIENT_SOURCE_DIR= ..\..\wsclient

#  versioning information

AXIS2_MAJOR_VERSION = M
AXIS2_MINOR_VERSION = 0
AXIS2_MICRO_VERSION = 9

#binary distribution dll names

AXIS2_UTIL   = axis2_util
AXIS2_PARSER = axis2_parser
AXIOM = axiom
AXIS2_WSDL   = axis2_wsdl
AXIS2_TRANSPORT_SENDER = axis2_http_sender
AXIS2_TRANSPORT_RECEIVER = axis2_http_receiver
AXIS2_ENGINE = axis2_engine
AXIS2_SERVER = axis2_http_server
AXIS2_APACHE_MODULE = mod_axis2

#other modules 

AXIS2_RAMPART = mod_rampart
AXIS2_MOD_ADDR = axis2_mod_addr
AXIS2_MOD_LOG = axis2_mod_log

# include path
APACHE_INCLUE_PATH = /I$(APACHE_BIN_DIR)\include
AXIS2_INCLUDE_PATH = 	/I$(AXIS2_SOURCE_DIR)\util\include \
		/I$(AXIS2_SOURCE_DIR)\util\src\  \
		/I$(AXIS2_SOURCE_DIR)\woden\include \
		/I$(AXIS2_SOURCE_DIR)\woden\src\util \
		/I$(AXIS2_SOURCE_DIR)\util\src\minizip\  \
		/I$(AXIS2_SOURCE_DIR)\axiom\include  \
		/I$(AXIS2_SOURCE_DIR)\axiom\src\om  \
		/I$(AXIS2_SOURCE_DIR)\axiom\src\soap \
		/I$(AXIS2_SOURCE_DIR)\util\include\platforms \
		/I$(AXIS2_SOURCE_DIR)\modules\wsdl \
		/I$(AXIS2_SOURCE_DIR)\modules\core\clientapi \
		/I$(AXIS2_SOURCE_DIR)\modules\core\deployment \
		/I$(AXIS2_SOURCE_DIR)\modules\core\description \
		/I$(AXIS2_SOURCE_DIR)\modules\core\transport \
		/I$(AXIS2_SOURCE_DIR)\include \
		/I$(AXIS2_SOURCE_DIR)\modules\core\engine \
		/I$(AXIS2_SOURCE_DIR)\modules\core\context \
		/I$(AXIS2_SOURCE_DIR)\modules\core\util \
		/I$(AXIS2_SOURCE_DIR)\modules\core\transport\http\server\apache2 \
		/I$(AXIS2_SOURCE_DIR)\axiom\src\attachments \
		/I$(AXIS2_SOURCE_DIR)\xml_schema\include \
		/I$(LIBXML2_BIN_DIR)\include \
		/I$(ICONV_BIN_DIR)\include \
		/I$(ZLIB_BIN_DIR)\include \
		/I$(WSCLIENT_SOURCE_DIR)\src

!if "$(ENABLE_SSL)" == "1"
AXIS2_INCLUDE_PATH = $(AXIS2_INCLUDE_PATH) /I$(OPENSSL_BIN_DIR )\include
!endif

#source paths for core modules

AXIS2_UTIL_SRC = $(AXIS2_SOURCE_DIR)\util\src\platforms\windows\*.c \
		$(AXIS2_SOURCE_DIR)\util\src\minizip\*.c \
		$(AXIS2_SOURCE_DIR)\util\src\*.c 

AXIS2_PARSER_SRC = $(AXIS2_SOURCE_DIR)\axiom\src\parser\libxml2\*.c

AXIOM_SRC = $(AXIS2_SOURCE_DIR)\axiom\src\om\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\soap\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\attachments\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\util\*.c
						
AXIS2_ENGINE_SRC =  $(AXIS2_SOURCE_DIR)\modules\core\addr\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\clientapi\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\context\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\deployment\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\description\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\engine\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\phaseresolver\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\receivers\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\util\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\transport\http\*.c 

AXIS2_WSDL_SRC = $(AXIS2_SOURCE_DIR)\modules\wsdl\*.c

AXIS2_HTTP_SENDER_SRC = $(AXIS2_SOURCE_DIR)\modules\core\transport\http\sender\*.c
!if "$(ENABLE_SSL)" == "1"
AXIS2_HTTP_SENDER_SRC = $(AXIS2_HTTP_SENDER_SRC) \
		$(AXIS2_SOURCE_DIR)\modules\core\transport\http\sender\ssl\*.c
!endif

AXIS2_HTTP_RECEIVER_SRC = $(AXIS2_SOURCE_DIR)\modules\core\transport\http\receiver\*.c 


#addr module

AXIS2_MOD_ADDR_SRC = $(AXIS2_SOURCE_DIR)\modules\mod_addr\*.c



#compiler options
CC = cl.exe 
CFLAGS = /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "AXIS2_DECLARE_EXPORT"  \
	  /D "AXIS2_SVR_MULTI_THREADED" /w /nologo $(AXIS2_INCLUDE_PATH) \
	 $(APACHE_INCLUDE_PATH)

# linker options
LD = link.exe
LDFLAGS = /nologo /LIBPATH:$(AXIS2_LIBS) /LIBPATH:$(LIBXSLT_BIN_DIR)\lib /LIBPATH:$(LIBXML2_BIN_DIR)\lib  \
		/LIBPATH:$(APACHE_BIN_DIR)\lib /LIBPATH:$(ZLIB_BIN_DIR)\lib
LIBS =  Rpcrt4.lib Ws2_32.lib
!if "$(ENABLE_SSL)" == "1"
LDFLAGS = $(LDFLAGS) /LIBPATH:$(OPENSSL_BIN_DIR )\lib
LIBS = $(LIBS) libeay32MT.lib ssleay32MT.lib
!endif

!if "$(APACHE_VERSION_IS_2_0_59)" == "1"
APACHE_LIBS = apr.lib xml.lib libhttpd.lib aprutil.lib libapr.lib
!else
APACHE_LIBS = apr-1.lib xml.lib libhttpd.lib aprutil-1.lib libapr-1.lib
!endif


#debug symbols
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7
LDFLAGS = $(LDFLAGS) /DEBUG /NODEFAULTLIB:LIBCMTD.lib 
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" /O2 /MT
LDFLAGS = $(LDFLAGS)
!endif


################################################################

# create the directory structure
deploy:
	if not exist $(AXIS2_INSTALL_DIR) mkdir $(AXIS2_INSTALL_DIR) 
	if not exist $(AXIS2_BINS) mkdir $(AXIS2_BINS)
	if not exist $(AXIS2_SERVICES) mkdir $(AXIS2_SERVICES)
	if not exist $(AXIS2_MODULES) mkdir $(AXIS2_MODULES)
	if not exist $(AXIS2_LIBS) mkdir $(AXIS2_LIBS)
	if not exist $(AXIS2_INCLUDE) mkdir $(AXIS2_INCLUDE)
	if not exist $(AXIS2_LOG) mkdir $(AXIS2_LOG)

#clean 
clean:
	if exist $(AXIS2_INSTALL_DIR) rmdir /S /Q $(AXIS2_INSTALL_DIR)

clean_make_dir:
	del *.obj del *.exe del *.exp

copy_include: deploy
	xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\include $(AXIS2_INSTALL_DIR)\include\

	if exist $(AXIS2_INSTALL_DIR)\include\Makefile.am del $(AXIS2_INSTALL_DIR)\include\Makefile.am

	xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\axiom\include $(AXIS2_INSTALL_DIR)\include\

	if exist $(AXIS2_INSTALL_DIR)\include\Makefile.am del $(AXIS2_INSTALL_DIR)\include\Makefile.am

	xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\util\include $(AXIS2_INSTALL_DIR)\include\

axis2_util: 
	$(CC) $(CFLAGS) $(AXIS2_UTIL_SRC)  /c
	$(LD) $(LDFLAGS) *.obj $(LIBS) $(ZLIB_BIN_DIR)\lib\zdll.lib \
		/DLL  /OUT:$(AXIS2_UTIL).dll /IMPLIB:$(AXIS2_UTIL).lib
	del *.obj
	del *.exp
	copy $(AXIS2_UTIL).* $(AXIS2_LIBS)\
	
	del axis2*.*

axis2_parser: 
	$(CC) $(CFLAGS) $(AXIS2_PARSER_SRC) /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(LIBS) \
	$(LIBXML2_BIN_DIR)\lib\libxml2.lib  /DLL \
	/OUT:$(AXIS2_PARSER).dll /IMPLIB:$(AXIS2_PARSER).lib
	del *.obj
	del *.exp
	copy $(AXIS2_PARSER).* $(AXIS2_LIBS)\

	del axis2*.*

axiom: 
	$(CC) $(CFLAGS) $(AXIOM_SRC) /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib \
	$(AXIS2_PARSER).lib $(LIBS)  /DLL /OUT:$(AXIOM).dll /IMPLIB:$(AXIOM).lib
	del *.obj
	del *.exp
	copy $(AXIOM).* $(AXIS2_LIBS)\

	del $(AXIOM).*

axis2_wsdl: 
	$(CC) $(CFLAGS) $(AXIS2_WSDL_SRC) /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(LIBS) \
	/DLL /OUT:$(AXIS2_WSDL).dll /IMPLIB:$(AXIS2_WSDL).lib
	del *.obj
	del *.exp
	copy $(AXIS2_WSDL).* $(AXIS2_LIBS)\
	
	del axis2*.*

axis2_engine: 
	$(CC) $(CFLAGS) $(AXIS2_ENGINE_SRC) /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(AXIS2_WSDL).lib woden.lib $(LIBS)  \
	/DLL /OUT:$(AXIS2_ENGINE).dll /IMPLIB:$(AXIS2_ENGINE).lib
	del *.obj
	del *.exp
	copy $(AXIS2_ENGINE).* $(AXIS2_LIBS)\

	del axis2*.*

axis2_http_sender: 
	$(CC) $(CFLAGS) $(AXIS2_HTTP_SENDER_SRC) /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	/DLL /OUT:$(AXIS2_TRANSPORT_SENDER).dll /IMPLIB:$(AXIS2_TRANSPORT_SENDER).lib

	del *.obj
	del *.exp
	copy $(AXIS2_TRANSPORT_SENDER).* $(AXIS2_LIBS)\
	
	del axis2*.*
	
		
axis2_http_receiver: 
	$(CC) $(CFLAGS) $(AXIS2_HTTP_RECEIVER_SRC) /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib  \
	/DLL /OUT:$(AXIS2_TRANSPORT_RECEIVER).dll /IMPLIB:$(AXIS2_TRANSPORT_RECEIVER).lib
	del *.obj
	del *.exp
	copy $(AXIS2_TRANSPORT_RECEIVER).* $(AXIS2_LIBS)\
	
	del axis2*.*	

# modules 

axis2_mod_addr:
	$(CC) $(CFLAGS) $(AXIS2_MOD_ADDR_SRC) /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib /DLL /OUT:axis2_mod_addr.dll  /IMPLIB:axis2_mod_addr.lib
	del *.obj
	
	if not exist $(AXIS2_MODULES)\addressing mkdir $(AXIS2_MODULES)\addressing

	copy axis2_mod_addr.dll $(AXIS2_MODULES)\addressing\

	del *.dll
	del *.lib
	copy $(AXIS2_SOURCE_DIR)\modules\mod_addr\module.xml $(AXIS2_MODULES)\addressing

axis2_mod_log:
	$(CC) $(CFLAGS)  $(AXIS2_SOURCE_DIR)\modules\mod_log\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib /DLL /OUT:axis2_mod_log.dll  /IMPLIB:axis2_mod_log.lib
	del *.obj
	
	if not exist $(AXIS2_MODULES)\logging mkdir $(AXIS2_MODULES)\logging

	copy axis2_mod_log.dll $(AXIS2_MODULES)\logging\

	del *.dll
	del *.lib
	copy $(AXIS2_SOURCE_DIR)\modules\mod_log\module.xml $(AXIS2_MODULES)\logging





############# end modules  ###################

################ services ####################


axis2_services_echo:
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\echo \
	$(AXIS2_SOURCE_DIR)\samples\server\echo\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib $(AXIS2_TRANSPORT_RECEIVER).lib \
	$(AXIS2_TRANSPORT_SENDER).lib /DLL /OUT:echo.dll  
	del *.obj
	
	if not exist $(AXIS2_SERVICES)\echo mkdir $(AXIS2_SERVICES)\echo

	copy echo.dll $(AXIS2_SERVICES)\echo

	del *.dll
	del *.exp
	del *.lib
	
	copy $(AXIS2_SOURCE_DIR)\samples\server\echo\services.xml $(AXIS2_SERVICES)\echo

axis2_services_notify:
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\echo \
	$(AXIS2_SOURCE_DIR)\samples\server\notify\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib $(AXIS2_TRANSPORT_RECEIVER).lib \
	$(AXIS2_TRANSPORT_SENDER).lib /DLL /OUT:notify.dll  
	del *.obj
	
	if not exist $(AXIS2_SERVICES)\notify mkdir $(AXIS2_SERVICES)\notify

	copy notify.dll $(AXIS2_SERVICES)\notify

	del *.dll

	del *.lib
	
	copy $(AXIS2_SOURCE_DIR)\samples\server\notify\services.xml $(AXIS2_SERVICES)\notify


axis2_services_math:
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\math \
	$(AXIS2_SOURCE_DIR)\samples\server\math\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib $(AXIS2_TRANSPORT_RECEIVER).lib \
	$(AXIS2_TRANSPORT_SENDER).lib /DLL /OUT:math.dll  
	del *.obj
	
	if not exist $(AXIS2_SERVICES)\math mkdir $(AXIS2_SERVICES)\math

	copy math.dll $(AXIS2_SERVICES)\math

	del *.dll

	del *.lib
	
	copy $(AXIS2_SOURCE_DIR)\samples\server\math\services.xml $(AXIS2_SERVICES)\math

axis2_services_mtom:
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\mtom \
	$(AXIS2_SOURCE_DIR)\samples\server\mtom\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib $(AXIS2_TRANSPORT_RECEIVER).lib \
	$(AXIS2_TRANSPORT_SENDER).lib /DLL /OUT:mtom.dll  
	del *.obj
	
	if not exist $(AXIS2_SERVICES)\mtom mkdir $(AXIS2_SERVICES)\mtom

	copy mtom.dll $(AXIS2_SERVICES)\mtom

	del *.dll
	del *.exp
	del *.lib
	
	copy $(AXIS2_SOURCE_DIR)\samples\server\mtom\services.xml $(AXIS2_SERVICES)\mtom

axis2_services_calculator:
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\Calculator \
	$(AXIS2_SOURCE_DIR)\samples\server\Calculator\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib $(AXIS2_TRANSPORT_RECEIVER).lib \
	$(AXIS2_TRANSPORT_SENDER).lib /DLL /OUT:Calculator.dll  
	del *.obj
	
	if not exist $(AXIS2_SERVICES)\Calculator mkdir $(AXIS2_SERVICES)\Calculator

	copy Calculator.dll $(AXIS2_SERVICES)\Calculator

	del *.dll
	del *.exp
	del *.lib
	
	copy $(AXIS2_SOURCE_DIR)\samples\server\Calculator\services.xml $(AXIS2_SERVICES)\Calculator
	

axis2_services_sg_math:
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\sg_math  \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\add.c \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\add_skeleton.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	$(AXIS2_TRANSPORT_RECEIVER).lib $(AXIS2_TRANSPORT_SENDER).lib /DLL /OUT:add.dll  
	del *.obj

	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\sg_math \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\div.c \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\div_skeleton.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib $(AXIS2_TRANSPORT_RECEIVER).lib \
	$(AXIS2_TRANSPORT_SENDER).lib /DLL /OUT:div.dll  
	del *.obj
	
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\sg_math  \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\sub.c $(AXIS2_SOURCE_DIR)\samples\server\sg_math\sub_skeleton.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib $(AXIS2_TRANSPORT_RECEIVER).lib $(AXIS2_TRANSPORT_SENDER).lib /DLL /OUT:sub.dll  
	del *.obj
	
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\sg_math  \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\mul.c $(AXIS2_SOURCE_DIR)\samples\server\sg_math\mul_skeleton.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib $(AXIS2_TRANSPORT_RECEIVER).lib \
	$(AXIS2_TRANSPORT_SENDER).lib /DLL /OUT:mul.dll  
	del *.obj
	
	if not exist $(AXIS2_SERVICES)\sg_math mkdir $(AXIS2_SERVICES)\sg_math

	copy *.dll $(AXIS2_SERVICES)\sg_math\

	del *.dll
	del *.exp
	del *.lib
	
	copy $(AXIS2_SOURCE_DIR)\samples\server\sg_math\services.xml $(AXIS2_SERVICES)\sg_math

################## server ##################################

axis2_server: 
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\modules\core\transport\http\server\simple_axis2_server\http_server_main.c /c
	$(LD) $(LDFLAGS) http_server_main.obj $(AXIS2_UTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	$(AXIS2_TRANSPORT_RECEIVER).lib  /OUT:$(AXIS2_SERVER).exe 
	del *.obj
	copy $(AXIS2_SERVER).exe $(AXIS2_BINS)\
	
	del axis2*.*

	copy $(AXIS2_SOURCE_DIR)\samples\server\axis2.xml $(AXIS2_INSTALL_DIR)\


################# apache module ###########################

axis2_apache_module:
	$(CC) $(CFLAGS) $(APACHE_INCLUE_PATH) $(AXIS2_SOURCE_DIR)\modules\core\transport\http\server\apache2\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib $(APACHE_LIBS) /DLL /OUT:mod_axis2.dll  /IMPLIB:mod_axis2.lib 
	del *.obj
	copy mod_axis2.dll $(AXIS2_LIBS)\

	copy mod_axis2.lib $(AXIS2_LIBS)\

	del *.dll
	del *.exp
	del *.lib
	
###################### clients #################################

axis2_client_math:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\samples\client\math\*.c /w /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib  /OUT:math.exe 
	del *.obj
	
	if not exist $(AXIS2_BINS)\samples mkdir $(AXIS2_BINS)\samples

	copy math.exe $(AXIS2_BINS)\samples
	del math.exe
	del math.exp

axis2_client_echo:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\samples\client\echo\echo.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib  /OUT:echo.exe 
	del *.obj
	
	if not exist $(AXIS2_BINS)\samples mkdir $(AXIS2_BINS)\samples

	copy echo.exe $(AXIS2_BINS)\samples
	del echo.exe
	del echo.exp


axis2_client_dynamic_client:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\samples\client\dynamic_client\dynamic_client.c /c
	$(LD) $(LDFLAGS) dynamic_client.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib  /OUT:dynamic_client.exe 
	del *.obj
	
	if not exist $(AXIS2_BINS)\samples mkdir $(AXIS2_BINS)\samples
	if not exist $(AXIS2_BINS)\samples\resources mkdir $(AXIS2_BINS)\samples\resources
	copy $(AXIS2_SOURCE_DIR)\samples\client\dynamic_client\*.wsdl $(AXIS2_BINS)\samples\resources

	copy dynamic_client.exe $(AXIS2_BINS)\samples
	del dynamic_client.exe
	del dynamic_client.exp
	
axis2_client_google_spell:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\samples\client\google\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:google.exe 
	del *.obj
	
	if not exist $(AXIS2_BINS)\samples mkdir $(AXIS2_BINS)\samples

	copy google.exe $(AXIS2_BINS)\samples
	del google.exe

axis2_client_yahoo:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\samples\client\yahoo\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:yahoo.exe 
	del *.obj
	
	if not exist $(AXIS2_BINS)\samples mkdir $(AXIS2_BINS)\samples

	copy yahoo.exe $(AXIS2_BINS)\samples
	del yahoo.exe

axis2_client_notify:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\samples\client\notify\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:notify.exe 
	del *.obj
	
	if not exist $(AXIS2_BINS)\samples mkdir $(AXIS2_BINS)\samples

	copy notify.exe $(AXIS2_BINS)\samples
	del notify.exe
	del notify.exp

axis2_client_mtom:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\client\mtom\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:mtom.exe 
	del *.obj
	
	if not exist $(AXIS2_BINS)\samples mkdir $(AXIS2_BINS)\samples
	mkdir $(AXIS2_BINS)\samples\resources 
	xcopy $(AXIS2_SOURCE_DIR)\samples\client\mtom\resources $(AXIS2_BINS)\samples\resources 

	copy mtom.exe $(AXIS2_BINS)\samples
	del mtom.exe
	del mtom.exp


axis2_client_userguide:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_blocking.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:echo_blocking.exe 
	del *.obj
	
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_non_blocking.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:echo_non_blocking.exe 
	del *.obj

	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_blocking_addr.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:echo_blocking_addr.exe 
	del *.obj

	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_rest.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:echo_rest.exe 
	del *.obj

	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_blocking_dual.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib  /OUT:echo_blocking_dual.exe 
	del *.obj

	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_non_blocking_dual.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:echo_non_blocking_dual.exe 
	del *.obj

	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_blocking_soap11.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:echo_blocking_soap11.exe 
	del *.obj
	
	
	if not exist $(AXIS2_BINS)\samples mkdir $(AXIS2_BINS)\samples

	copy *.exe $(AXIS2_BINS)\samples
	del *.exe
	
	
copy_extra:
	copy $(AXIS2_SOURCE_DIR)\INSTALL $(AXIS2_INSTALL_DIR)
	copy $(AXIS2_SOURCE_DIR)\LICENSE $(AXIS2_INSTALL_DIR)
	copy $(AXIS2_SOURCE_DIR)\CREDITS $(AXIS2_INSTALL_DIR)
	copy $(AXIS2_SOURCE_DIR)\README $(AXIS2_INSTALL_DIR)
	if exist $(AXIS2_SOURCE_DIR)\docs xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\docs $(AXIS2_INSTALL_DIR)\docs

copy_samples:
	if not exist $(AXIS2_INSTALL_DIR)\samples mkdir $(AXIS2_INSTALL_DIR)\samples

	if not exist $(AXIS2_INSTALL_DIR)\samples\client mkdir $(AXIS2_INSTALL_DIR)\samples\client
	if not exist $(AXIS2_INSTALL_DIR)\samples\user_guide mkdir $(AXIS2_INSTALL_DIR)\samples\user_guide

	if not exist $(AXIS2_INSTALL_DIR)\samples\client\echo mkdir $(AXIS2_INSTALL_DIR)\samples\client\echo
	copy $(AXIS2_SOURCE_DIR)\samples\client\echo\echo.c $(AXIS2_INSTALL_DIR)\samples\client\echo
	copy $(AXIS2_SOURCE_DIR)\samples\client\echo\README.txt $(AXIS2_INSTALL_DIR)\samples\client\echo
	

	if not exist $(AXIS2_INSTALL_DIR)\samples\client\math mkdir $(AXIS2_INSTALL_DIR)\samples\client\math
	copy $(AXIS2_SOURCE_DIR)\samples\client\math\*.c $(AXIS2_INSTALL_DIR)\samples\client\math
	copy $(AXIS2_SOURCE_DIR)\samples\client\math\*.h $(AXIS2_INSTALL_DIR)\samples\client\math

	if not exist $(AXIS2_INSTALL_DIR)\samples\client\google mkdir $(AXIS2_INSTALL_DIR)\samples\client\google
	copy $(AXIS2_SOURCE_DIR)\samples\client\google\*.c $(AXIS2_INSTALL_DIR)\samples\client\google
	copy $(AXIS2_SOURCE_DIR)\samples\client\google\README.txt $(AXIS2_INSTALL_DIR)\samples\client\google

	if not exist $(AXIS2_INSTALL_DIR)\samples\client\dynamic_client mkdir $(AXIS2_INSTALL_DIR)\samples\client\dynamic_client
	copy $(AXIS2_SOURCE_DIR)\samples\client\dynamic_client\dynamic_client.c $(AXIS2_INSTALL_DIR)\samples\client\dynamic_client
	copy $(AXIS2_SOURCE_DIR)\samples\client\dynamic_client\README $(AXIS2_INSTALL_DIR)\samples\client\dynamic_client

	
	if not exist $(AXIS2_INSTALL_DIR)\samples\client\notify mkdir $(AXIS2_INSTALL_DIR)\samples\client\notify
	copy $(AXIS2_SOURCE_DIR)\samples\client\notify\*.c $(AXIS2_INSTALL_DIR)\samples\client\notify

	if not exist $(AXIS2_INSTALL_DIR)\samples\client\mtom\resources mkdir $(AXIS2_INSTALL_DIR)\samples\client\mtom\resources
	copy $(AXIS2_SOURCE_DIR)\samples\client\mtom\*.c $(AXIS2_INSTALL_DIR)\samples\client\mtom
	copy $(AXIS2_SOURCE_DIR)\samples\client\mtom\resources\*.jpg $(AXIS2_INSTALL_DIR)\samples\client\mtom\resources

	xcopy /E /I $(AXIS2_SOURCE_DIR)\samples\user_guide $(AXIS2_INSTALL_DIR)\samples\user_guide

	if not exist $(AXIS2_INSTALL_DIR)\samples\server mkdir $(AXIS2_INSTALL_DIR)\samples\server

	if not exist $(AXIS2_INSTALL_DIR)\samples\server\echo mkdir $(AXIS2_INSTALL_DIR)\samples\server\echo
	copy $(AXIS2_SOURCE_DIR)\samples\server\echo\*.c $(AXIS2_INSTALL_DIR)\samples\server\echo
	copy $(AXIS2_SOURCE_DIR)\samples\server\echo\*.h $(AXIS2_INSTALL_DIR)\samples\server\echo
	copy $(AXIS2_SOURCE_DIR)\samples\server\echo\*.xml $(AXIS2_INSTALL_DIR)\samples\server\echo

	if not exist $(AXIS2_INSTALL_DIR)\samples\server\math mkdir $(AXIS2_INSTALL_DIR)\samples\server\math
	copy $(AXIS2_SOURCE_DIR)\samples\server\math\*.c $(AXIS2_INSTALL_DIR)\samples\server\math
	copy $(AXIS2_SOURCE_DIR)\samples\server\math\*.h $(AXIS2_INSTALL_DIR)\samples\server\math
	copy $(AXIS2_SOURCE_DIR)\samples\server\math\*.xml $(AXIS2_INSTALL_DIR)\samples\server\math

	if not exist $(AXIS2_INSTALL_DIR)\samples\server\notify mkdir $(AXIS2_INSTALL_DIR)\samples\server\notify
	copy $(AXIS2_SOURCE_DIR)\samples\server\notify\*.c $(AXIS2_INSTALL_DIR)\samples\server\notify
	copy $(AXIS2_SOURCE_DIR)\samples\server\notify\*.h $(AXIS2_INSTALL_DIR)\samples\server\notify
	copy $(AXIS2_SOURCE_DIR)\samples\server\notify\*.xml $(AXIS2_INSTALL_DIR)\samples\server\notify

	if not exist $(AXIS2_INSTALL_DIR)\samples\server\sg_math mkdir $(AXIS2_INSTALL_DIR)\samples\server\sg_math
	copy $(AXIS2_SOURCE_DIR)\samples\server\sg_math\*.c $(AXIS2_INSTALL_DIR)\samples\server\sg_math
	copy $(AXIS2_SOURCE_DIR)\samples\server\sg_math\*.h $(AXIS2_INSTALL_DIR)\samples\server\sg_math
	copy $(AXIS2_SOURCE_DIR)\samples\server\sg_math\*.xml $(AXIS2_INSTALL_DIR)\samples\server\sg_math

	if not exist $(AXIS2_INSTALL_DIR)\samples\server\mtom mkdir $(AXIS2_INSTALL_DIR)\samples\server\mtom
	copy $(AXIS2_SOURCE_DIR)\samples\server\mtom\*.c $(AXIS2_INSTALL_DIR)\samples\server\mtom
	copy $(AXIS2_SOURCE_DIR)\samples\server\mtom\*.h $(AXIS2_INSTALL_DIR)\samples\server\mtom
	copy $(AXIS2_SOURCE_DIR)\samples\server\mtom\*.xml $(AXIS2_INSTALL_DIR)\samples\server\mtom

mv_dist:
	if exist ..\axis2c-bin-$(RELEASE_VER)-win32 rmdir /S /Q ..\axis2c-bin-$(RELEASE_VER)-win32
	xcopy /E /I $(AXIS2_INSTALL_DIR) ..\axis2c-bin-$(RELEASE_VER)-win32
	rmdir /S /Q $(AXIS2_INSTALL_DIR)


all_services: axis2_services_echo axis2_services_math axis2_services_notify axis2_services_sg_math axis2_services_mtom axis2_services_calculator 

all_clients: axis2_client_echo axis2_client_math  axis2_client_google_spell axis2_client_yahoo axis2_client_notify axis2_client_mtom axis2_client_userguide axis2_client_dynamic_client 

basic_modules: axis2_util axis2_parser axiom

################################# tools ##################################################

# tcpmon

tcpmon: 
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_CRT_SECURE_NO_DEPRECATE" $(AXIS2_INCLUDE_PATH) \
	/I $(AXIS2_SOURCE_DIR)\tools\tcpmon\include \
	$(AXIS2_SOURCE_DIR)\tools\tcpmon\src\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib /OUT:tcpmon.exe 
	del *.obj
	copy tcpmon.* $(AXIS2_BINS)\

	del *.exe

# codegen tool

W2C_INCLUDE_PATH = /I$(AXIS2_SOURCE_DIR)\tools\codegen\include \
		   /I$(LIBXSLT_BIN_DIR)\include


W2C_CODEGEN_SOURCE_PATH  = $(AXIS2_SOURCE_DIR)\tools\codegen\src\util\*.c \
		   $(AXIS2_SOURCE_DIR)\tools\codegen\src\wsdl\*.c \
		   $(AXIS2_SOURCE_DIR)\tools\codegen\src\schema\compiler\*.c \

W2C_WRITER_PATH = $(AXIS2_SOURCE_DIR)\tools\codegen\src\wsdl\writer

		   
w2c_codegen:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH) $(W2C_CODEGEN_SOURCE_PATH) /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	xml_schema.lib woden.lib libxslt.lib libxml2.lib /DLL /OUT:w2c_codegen.dll /IMPLIB:w2c_codegen.lib
 
	del *.obj
	
	if not exist $(AXIS2_INSTALL_DIR)\lib\codegen mkdir $(AXIS2_INSTALL_DIR)\lib\codegen

	copy w2c_codegen.* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_codegen*



w2c_databinding_adb_ext:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH) $(AXIS2_SOURCE_DIR)\tools\codegen\src\schema\databinding_adb_ext.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_databinding_adb_ext.dll /IMPLIB:w2c_databinding_adb_ext.lib
 
	del *.obj
	
	if not exist $(AXIS2_INSTALL_DIR)\lib\codegen mkdir $(AXIS2_INSTALL_DIR)\lib\codegen

	copy w2c_databinding_adb_ext* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_databinding_adb_ext*

w2c_c_emitter:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH) $(AXIS2_SOURCE_DIR)\tools\codegen\src\wsdl\emitter\*.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_c_emitter.dll /IMPLIB:w2c_c_emitter.lib
 
	del *.obj
	
	if not exist $(AXIS2_INSTALL_DIR)\lib\codegen mkdir $(AXIS2_INSTALL_DIR)\lib\codegen

	copy w2c_c_emitter* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_c_emitter*
	
w2c_schema_c_writer:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH) $(AXIS2_SOURCE_DIR)\tools\codegen\src\schema\writer\*.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_schema_c_writer.dll /IMPLIB:w2c_schema_c_writer.lib
 
	del *.obj
	
	copy w2c_schema_c_writer* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_schema_c_writer*
	

w2c_cservice_xml_writer:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH) $(W2C_WRITER_PATH)\cservice_xml_writer.c $(W2C_WRITER_PATH)\writer.c  /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_cservice_xml_writer.dll /IMPLIB:w2c_cservice_xml_writer.lib
 
	del *.obj
	
	copy w2c_cservice_xml_writer* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_cservice_xml_writer*

w2c_cskel_header_writer:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH)  $(W2C_WRITER_PATH)\cskel_header_writer.c  $(W2C_WRITER_PATH)\writer.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_cskel_header_writer.dll /IMPLIB:w2c_cskel_header_writer.lib
 
	del *.obj
	
	copy w2c_cskel_header_writer* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_cskel_header_writer*

w2c_cskel_source_writer:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH)  $(W2C_WRITER_PATH)\cskel_source_writer.c  $(W2C_WRITER_PATH)\writer.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_cskel_source_writer.dll /IMPLIB:w2c_cskel_source_writer.lib
 
	del *.obj
	
	copy w2c_cskel_source_writer* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_cskel_source_writer*

w2c_cstub_source_writer:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH)  $(W2C_WRITER_PATH)\cstub_source_writer.c  $(W2C_WRITER_PATH)\writer.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_cstub_source_writer.dll /IMPLIB:w2c_cstub_source_writer.lib
 
	del *.obj
	
	copy w2c_cstub_source_writer* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_cstub_source_writer*

w2c_cstub_header_writer:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH)  $(W2C_WRITER_PATH)\cstub_header_writer.c  $(W2C_WRITER_PATH)\writer.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_cstub_header_writer.dll /IMPLIB:w2c_cstub_header_writer.lib
 
	del *.obj
	
	copy w2c_cstub_header_writer* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_cstub_header_writer*

w2c_csvc_skeleton_writer:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH)  $(W2C_WRITER_PATH)\csvc_skeleton_writer.c  $(W2C_WRITER_PATH)\writer.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_csvc_skeleton_writer.dll /IMPLIB:w2c_csvc_skeleton_writer.lib
 
	del *.obj
	
	copy w2c_csvc_skeleton_writer* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_csvc_skeleton_writer*

w2c_c_code_indenter_ext:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH)  $(AXIS2_SOURCE_DIR)\tools\codegen\src\wsdl\extensions\c_code_indenter_ext.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_c_code_indenter_ext.dll /IMPLIB:w2c_c_code_indenter_ext.lib
 
	del *.obj
	
	copy w2c_c_code_indenter_ext* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_c_code_indenter_ext*

w2c_c_qname2name_ext:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH)  $(AXIS2_SOURCE_DIR)\tools\codegen\src\wsdl\extensions\c_qname2name_ext.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_c_qname2name_ext.dll /IMPLIB:w2c_c_qname2name_ext.lib
 
	del *.obj
	
	copy w2c_c_qname2name_ext* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_c_qname2name_ext*

w2c_c_namemaker_ext:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH)  $(AXIS2_SOURCE_DIR)\tools\codegen\src\wsdl\extensions\c_namemaker_ext.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_c_namemaker_ext.dll /IMPLIB:w2c_c_namemaker_ext.lib
 
	del *.obj
	
	copy w2c_c_namemaker_ext* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_c_namemaker_ext*

w2c_default_qname2name_ext:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH)  $(AXIS2_SOURCE_DIR)\tools\codegen\src\wsdl\extensions\default_qname2name_ext.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_default_qname2name_ext.dll /IMPLIB:w2c_default_qname2name_ext.lib
 
	del *.obj
	
	copy w2c_default_qname2name_ext* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_default_qname2name_ext*

w2c_databinding_default_ext:
	$(CC) $(CFLAGS) $(W2C_INCLUDE_PATH)  $(AXIS2_SOURCE_DIR)\tools\codegen\src\wsdl\extensions\databinding_default_ext.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib $(LIBS) \
	xml_schema.lib woden.lib w2c_codegen.lib /LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen \
	/DLL /OUT:w2c_databinding_default_ext.dll /IMPLIB:w2c_databinding_default_ext.lib
 
	del *.obj
	
	copy w2c_databinding_default_ext* $(AXIS2_INSTALL_DIR)\lib\codegen

	del w2c_databinding_default_ext*
	
wsdl2code:
	$(CC) /nologo $(CFLAGS) $(W2C_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\tools\codegen\src\wsdl2code.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib \
	xml_schema.lib woden.lib w2c_codegen.lib $(LIBS) \
	/LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen /OUT:wsdl2code.exe 

	del *.obj
	
	copy wsdl2code* $(AXIS2_INSTALL_DIR)\bin

	del wsdl2code*


schema2code:
	$(CC) /nologo $(CFLAGS) $(W2C_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\tools\codegen\src\schema\xsd2code.c /c
	$(LD) $(LDFLAGS) *.obj axis2_util.lib axiom.lib axis2_parser.lib \
	xml_schema.lib woden.lib w2c_codegen.lib $(LIBS) \
	/LIBPATH:$(AXIS2_INSTALL_DIR)\lib\codegen /OUT:schema2code.exe 

	del *.obj
	
	copy schema2code* $(AXIS2_INSTALL_DIR)\bin
	
	del schema2code*

copy_config:
	xcopy /I /E /Y $(AXIS2_SOURCE_DIR)\tools\codegen\src\typemappers $(AXIS2_INSTALL_DIR)\conf\typemappers

	xcopy /I /E /Y $(AXIS2_SOURCE_DIR)\tools\codegen\src\templates $(AXIS2_INSTALL_DIR)\conf\templates

	copy $(AXIS2_SOURCE_DIR)\tools\codegen\src\util\codegen-config.properties $(AXIS2_INSTALL_DIR)\conf
	
	copy $(AXIS2_SOURCE_DIR)\tools\codegen\src\schema\compiler\schema-config.properties $(AXIS2_INSTALL_DIR)\conf

	copy $(AXIS2_SOURCE_DIR)\tools\codegen\src\util\resource.properties $(AXIS2_INSTALL_DIR)\conf

copy_resources:
	xcopy /I /E /Y $(AXIS2_SOURCE_DIR)\tools\codegen\test\resources\wsdl $(AXIS2_INSTALL_DIR)\bin\codegen_resources\wsdl

	xcopy /I /E /Y $(AXIS2_SOURCE_DIR)\tools\codegen\test\resources\xml $(AXIS2_INSTALL_DIR)\bin\codegen_resources\xml



codegen_writers: w2c_c_emitter w2c_schema_c_writer w2c_cservice_xml_writer w2c_cskel_header_writer w2c_cskel_source_writer w2c_cstub_source_writer w2c_cstub_header_writer w2c_csvc_skeleton_writer
codegen_ext: w2c_databinding_adb_ext w2c_c_code_indenter_ext w2c_c_namemaker_ext w2c_default_qname2name_ext w2c_c_qname2name_ext w2c_databinding_default_ext
codegen_tool: w2c_codegen wsdl2code schema2code codegen_writers codegen_ext copy_config copy_resources


################################ other porjects #########################################

#rampart module

OMXMLSEC_SRC = $(AXIS2_SOURCE_DIR)\rampart\src\omxmlsec\*.c \
    	       $(AXIS2_SOURCE_DIR)\rampart\src\omxmlsec\tokens\*.c \
    	       $(AXIS2_SOURCE_DIR)\rampart\src\omxmlsec\openssl\*.c 

MOD_RAMPART_SRC = $(AXIS2_SOURCE_DIR)\rampart\src\core\*.c \
		$(AXIS2_SOURCE_DIR)\rampart\src\handlers\*.c \
		$(AXIS2_SOURCE_DIR)\rampart\src\util\*.c

MOD_RAMPART_INCLUDE_PATH = /I$(AXIS2_SOURCE_DIR)\rampart\include

!if "$(ENABLE_SSL)" == "0"
MOD_RAMPART_INCLUDE_PATH = $(MOD_RAMPART_INCLUDE_PATH) /I$(OPENSSL_BIN_DIR)\include
LDFLAGS = $(LDFLAGS) /LIBPATH:$(OPENSSL_BIN_DIR)\lib
!endif


#debug symbols
!if "$(DEBUG)" == "1"
LIBS = $(LIBS) libeay32MTd.lib ssleay32MTd.lib
!else
LIBS = $(LIBS) libeay32MT.lib ssleay32MT.lib
!endif

APPLINK_FILE = $(OPENSSL_BIN_DIR)\include\openssl\applink.c

rampart_do_nothing:

RAMPART_BIN_DIR = $(AXIS2_INSTALL_DIR)\bin
RAMPART_SAMPLES_CLIENT_DIR = $(RAMPART_BIN_DIR)\samples\rampart\client
RAMPART_SAMPLES_SERVER_DIR = $(RAMPART_BIN_DIR)\samples\rampart\server
RAMPART_SAMPLES_KEYS_DIR = $(RAMPART_BIN_DIR)\samples\rampart\keys
RAMPART_SAMPLES_SERVICE_DIR = $(AXIS2_INSTALL_DIR)\services
RAMPART_MODULES_DIR = $(AXIS2_INSTALL_DIR)\modules\

mod_rampart:
	$(CC) $(CFLAGS) $(MOD_RAMPART_INCLUDE_PATH) $(MOD_RAMPART_SRC) $(OMXMLSEC_SRC) $(APPLINK_FILE) /c
	$(LD) $(LDFLAGS) /LIBPATH:$(AXIS2_INSTALL_DIR)\rampart\rampart *.obj $(AXIS2_UTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib  $(LIBS) \
	$(AXIS2_ENGINE).lib /DLL /OUT:mod_rampart.dll  /IMPLIB:mod_rampart.lib
	del *.obj
	
	if not exist $(RAMPART_MODULES_DIR)\rampart mkdir $(RAMPART_MODULES_DIR)\rampart

	copy mod_rampart.dll $(RAMPART_MODULES_DIR)\rampart
	
	del *.dll
	del *.lib
	del *.exp
	copy $(AXIS2_SOURCE_DIR)\rampart\src\data\module.xml $(RAMPART_MODULES_DIR)\rampart
	
mod_rampart_pwcb: 
	$(CC) $(CFLAGS) $(MOD_RAMPART_INCLUDE_PATH) $(AXIS2_SOURCE_DIR)\rampart\samples\callback\pwcb.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib /DLL /OUT:pwcb.dll /IMPLIB:pwcb.lib

	if not exist $(RAMPART_SAMPLES_CLIENT_DIR)\callback mkdir $(RAMPART_SAMPLES_CLIENT_DIR)\callback
	
	copy pwcb.dll $(RAMPART_SAMPLES_CLIENT_DIR)\callback\pwcb.dll
	copy $(AXIS2_SOURCE_DIR)\rampart\samples\callback\pwcb.c $(RAMPART_SAMPLES_CLIENT_DIR)\callback
	del pwcb.*

mod_rampart_htpwcb: 
	$(CC) $(CFLAGS) $(MOD_RAMPART_INCLUDE_PATH) $(AXIS2_SOURCE_DIR)\rampart\samples\callback\htpasswd_callback\htpwcb.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib /DLL /OUT:htpwcb.dll /IMPLIB:htpwcb.lib

	if not exist $(RAMPART_SAMPLES_CLIENT_DIR)\callback\htpasswd mkdir $(RAMPART_SAMPLES_CLIENT_DIR)\callback\htpasswd
	
	copy htpwcb.dll $(RAMPART_SAMPLES_CLIENT_DIR)\callback\htpasswd\htpwcb.dll
	del htpwcb.*

mod_rampart_services_sec_echo:
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\rampart\samples\server\sec_echo \
	$(AXIS2_SOURCE_DIR)\rampart\samples\server\sec_echo\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib $(AXIS2_TRANSPORT_RECEIVER).lib \
	$(AXIS2_TRANSPORT_SENDER).lib /DLL /OUT:sec_echo.dll  
	del *.obj
	
	if not exist $(RAMPART_SAMPLES_SERVICE_DIR)\sec_echo mkdir $(RAMPART_SAMPLES_SERVICE_DIR)\sec_echo

	copy sec_echo.dll $(RAMPART_SAMPLES_SERVICE_DIR)\sec_echo

	del *.dll
	del *.exp
	del *.lib
	
	copy $(AXIS2_SOURCE_DIR)\rampart\samples\server\sec_echo\*.c $(RAMPART_SAMPLES_SERVICE_DIR)\sec_echo
	copy $(AXIS2_SOURCE_DIR)\rampart\samples\server\sec_echo\*.h $(RAMPART_SAMPLES_SERVICE_DIR)\sec_echo
	copy $(AXIS2_SOURCE_DIR)\rampart\samples\server\sec_echo\services.xml $(RAMPART_SAMPLES_SERVICE_DIR)\sec_echo
	
mod_rampart_samples_enc_echo:
	if not exist $(RAMPART_SAMPLES_CLIENT_DIR)\enc_echo mkdir $(RAMPART_SAMPLES_CLIENT_DIR)\enc_echo
	
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) $(MOD_RAMPART_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\rampart\samples\client\enc_echo\echo.c /c
	$(LD) $(LDFLAGS) echo.obj $(AXIS2_UTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(AXIS2_ENGINE).lib /OUT:enc_echo.exe

	del *.obj
	copy enc_echo.exe $(RAMPART_SAMPLES_CLIENT_DIR)\enc_echo
	copy $(AXIS2_SOURCE_DIR)\rampart\samples\client\enc_echo\echo.c $(RAMPART_SAMPLES_CLIENT_DIR)\enc_echo
	
	xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\rampart\samples\client\enc_echo\data $(RAMPART_SAMPLES_CLIENT_DIR)\enc_echo\data
	del enc_echo.exe

mod_rampart_samples: mod_rampart_samples_enc_echo mod_rampart_services_sec_echo

mod_rampart_copy_include:
	xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\rampart\include $(AXIS2_INSTALL_DIR)\rampart\include
	copy $(AXIS2_SOURCE_DIR)\rampart\README $(AXIS2_INSTALL_DIR)\rampart

mod_rampart_copy_keys:
	if not exist $(RAMPART_SAMPLES_KEYS_DIR) mkdir $(RAMPART_SAMPLES_KEYS_DIR)
	xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\rampart\samples\keys\* $(RAMPART_SAMPLES_KEYS_DIR)

mod_rampart_all: mod_rampart mod_rampart_pwcb mod_rampart_htpwcb mod_rampart_samples mod_rampart_copy_include



####################################
#xml schema project ################

XML_SCHEMA_INCLUDE_PATH = /I$(AXIS2_SOURCE_DIR)\xml_schema\include

xml_schema:
	$(CC) $(CFLAGS) $(XML_SCHEMA_INCLUDE_PATH) $(AXIS2_SOURCE_DIR)\xml_schema\src\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib /DLL /OUT:xml_schema.dll /IMPLIB:xml_schema.lib

	copy xml_schema.dll $(AXIS2_INSTALL_DIR)\lib\xml_schema.dll
	copy xml_schema.lib $(AXIS2_INSTALL_DIR)\lib\xml_schema.lib
	del *.obj
	del xml_schema.*

xml_schema_copy_include:
	xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\xml_schema\include $(AXIS2_INSTALL_DIR)\include

xml_schema_copy_resources:
	xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\xml_schema\test-resources $(AXIS2_INSTALL_DIR)\xml_schema\test-resources
	if not exist $(AXIS2_INSTALL_DIR)\xml_schema\samples mkdir $(AXIS2_INSTALL_DIR)\xml_schema\samples
	copy $(AXIS2_SOURCE_DIR)\xml_schema\samples\test_schema.c $(AXIS2_INSTALL_DIR)\xml_schema\samples\
	
xml_schema_sample:
	$(CC) $(CFLAGS) $(XML_SCHEMA_INCLUDE_PATH) $(AXIS2_SOURCE_DIR)\xml_schema\samples\test_schema.c /c
	$(LD) $(LDFLAGS) test_schema.obj $(AXIS2_UTIL).lib $(AXIS2_PARSER).lib $(AXIOM).lib \
	$(AXIS2_INSTALL_DIR)\lib\xml_schema.lib \
	/OUT:test_schema.exe
	if not exist $(AXIS2_INSTALL_DIR)\bin\samples\xml_schema mkdir $(AXIS2_INSTALL_DIR)\bin\samples\xml_schema

	copy test_schema.exe $(AXIS2_INSTALL_DIR)\bin\samples\xml_schema
	del test*.*

xml_schema_all: xml_schema xml_schema_sample xml_schema_copy_include

################################################

########################################
############## woden ###################

WODEN_INCLUDE_PATH = /I$(AXIS2_SOURCE_DIR)\woden\include \
		     /I$(AXIS2_SOURCE_DIR)\xml_schema\include \
		     /I$(AXIS2_SOURCE_DIR)\woden\src\util 

WODEN_SRC_DIR = $(AXIS2_SOURCE_DIR)\woden\src\builder\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\builder\wsdl10\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\schema\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\types\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\util\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl10\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl10\xml\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl10\extensions\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl10\extensions\soap\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl20\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl20\extensions\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl20\extensions\soap\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl20\xml\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\xml\*.c 
woden : 
	$(CC) $(CFLAGS) /Fo $(WODEN_INCLUDE_PATH) $(WODEN_SRC_DIR) /c
	$(LD) $(LDFLAGS) *.obj xml_schema.lib $(AXIS2_UTIL).lib $(AXIS2_PARSER).lib \
	$(AXIOM).lib /DLL /OUT:woden.dll /IMPLIB:woden.lib 
	
	copy woden.lib $(AXIS2_INSTALL_DIR)\lib
	copy woden.dll $(AXIS2_INSTALL_DIR)\lib
	del *.obj
	del woden.dll
	del woden.lib
	del woden.exp

woden_copy_include:
	xcopy /Y /I /E $(AXIS2_SOURCE_DIR)\woden\include $(AXIS2_INSTALL_DIR)\include 

woden_sample:
	$(CC) $(CFLAGS) $(WODEN_INCLUDE_PATH) $(AXIS2_SOURCE_DIR)\woden\samples\test_wsdl2.c /c
	$(LD) $(LDFLAGS) test_wsdl2.obj $(AXIS2_UTIL).lib $(AXIS2_PARSER).lib $(AXIOM).lib \
	$(AXIS2_INSTALL_DIR)\lib\woden.lib $(AXIS2_INSTALL_DIR)\lib\woden.lib\
	/OUT:test_woden.exe
	if not exist $(AXIS2_INSTALL_DIR)\bin\samples\woden mkdir $(AXIS2_INSTALL_DIR)\bin\samples\woden

	copy test_woden.exe $(AXIS2_INSTALL_DIR)\bin\samples\woden
	del test*.*
	
woden_all: woden woden_sample woden_copy_include
 
##############################################################################################
#axis2.dll

SRC_DIR =       $(AXIS2_SOURCE_DIR)\util\src\platforms\windows\*.c \
		$(AXIS2_SOURCE_DIR)\util\src\minizip\*.c \
		$(AXIS2_SOURCE_DIR)\util\src\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\parser\libxml2\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\om\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\soap\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\attachments\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\util\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\builder\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\builder\wsdl10\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\schema\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\types\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\util\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl10\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl10\xml\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl10\extensions\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl10\extensions\soap\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl20\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl20\extensions\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl20\extensions\soap\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\wsdl20\xml\*.c \
		$(AXIS2_SOURCE_DIR)\woden\src\xml\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\addr\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\clientapi\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\context\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\deployment\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\description\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\engine\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\phaseresolver\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\receivers\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\util\*.c \
		$(AXIS2_SOURCE_DIR)\modules\core\transport\http\*.c \
		$(AXIS2_SOURCE_DIR)\modules\wsdl\*.c \
		$(AXIS2_SOURCE_DIR)\xml_schema\src\*.c

axis2:
	$(CC) $(CFLAGS) /Fo $(AXIS2_INCLUDE_PATH) $(SRC_DIR) /D "_WINDLL" /Gm /Zi /c
	$(LD) $(LDFLAGS) *.obj Rpcrt4.lib Ws2_32.lib zdll.lib libxml2.lib \
	/DLL /OUT:axis2.dll /IMPLIB:axis2.lib 
	
	copy axis2.lib $(AXIS2_INSTALL_DIR)\lib
	copy axis2.dll $(AXIS2_INSTALL_DIR)\lib
	del *.obj
	del *.dll
	del *.lib
	del *.exp

##############################################################################################

wsclient: 
	$(CC) /nologo /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) /I$(RAMPART_INCLUDE) \
	$(WSCLIENT_SOURCE_DIR)\src\*.c /c
	$(LD) $(LDFLAGS) *.obj $(AXIS2_UTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	$(AXIS2_TRANSPORT_RECEIVER).lib $(AXIS2_TRANSPORT_SENDER).lib /OUT:wsclient.exe 
	del *.obj
	copy wsclient.exe $(AXIS2_BINS)\
	
	del wsclient*.*
##############################################################################################


all: clean_make_dir clean deploy basic_modules xml_schema_all woden_all axis2_wsdl axis2_engine axis2_http_sender axis2_http_receiver axis2_mod_addr axis2_mod_log all_services all_clients wsclient axis2_server   copy_include clean_make_dir 
 
install: all

dist: all mod_rampart_all axis2_apache_module tcpmon codegen_tool copy_extra copy_samples mv_dist 


