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
#      AXIS2_BINDIR
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


AXIS2_RELEASE_DIR=axis2c-bin-$(RELEASE_VER)-win32
 
AXIS2_BINDIR   = ..\deploy
AXIS2_SERVICES = $(AXIS2_BINDIR)\services
AXIS2_MODULES  = $(AXIS2_BINDIR)\modules
AXIS2_LIBS     = $(AXIS2_BINDIR)\lib
AXIS2_BINS     = $(AXIS2_BINDIR)\bin
AXIS2_INCLUDE  = $(AXIS2_BINDIR)\include
AXIS2_SAMPLES  = $(AXIS2_BINS)\samples
AXIS2_TOOLS    = $(AXIS2_BINS)\tools
AXIS2_LOG      = $(AXIS2_BINDIR)\logs
AXIS2_TESTS    = $(AXIS2_BINDIR)\tests
AXIS2_TESTS_SYS = $(AXIS2_TESTS)\system_tests
AXIS2_TESTS_UNIT = $(AXIS2_TESTS)\unit_tests
AXIS2_SOURCE_DIR = ..\..

#directories for intermediate files

AXIS2_INTDIR= .\int.msvc
AXIS2_INTDIR_AXIOM = $(AXIS2_INTDIR)\axiom
AXIS2_INTDIR_UTIL  = $(AXIS2_INTDIR)\util
AXIS2_INTDIR_CORE  = $(AXIS2_INTDIR)\core
AXIS2_INTDIR_TNS = $(AXIS2_INTDIR)\http_sender
AXIS2_INTDIR_TNR = $(AXIS2_INTDIR)\http_receiver
AXIS2_INTDIR_PARSER = $(AXIS2_INTDIR)\axis2_parser
AXIS2_INTDIR_ADDRESSING = $(AXIS2_INTDIR)\src\addressing
AXIS2_INTDIR_SAMPLES = $(AXIS2_INTDIR)\samples
AXIS2_INTDIR_GUTHTHILA = $(AXIS2_INTDIR)\guththila

#  versioning information

AXIS2_MAJOR_VERSION = M
AXIS2_MINOR_VERSION = 0
AXIS2_MICRO_VERSION = 9

#binary distribution dll names
#core modules

AXUTIL   = axutil
AXIS2_PARSER = axis2_parser
AXIOM        = axiom
AXIS2_TRANSPORT_SENDER = axis2_http_sender
AXIS2_TRANSPORT_RECEIVER = axis2_http_receiver
AXIS2_ENGINE = axis2_engine
AXIS2_APACHE_MODULE = mod_axis2
AXIS2_IIS_MODULE = axis2_mod_IIS
AXIS2_MOD_ADDR = axis2_mod_addr
AXIS2_SERVER = axis2_http_server
GUTHTHILA = guththila

PARSER = build

!if "$(ENABLE_GUTHTHILA)" == "1"
PARSER = $(PARSER)_with_guththila
!endif

#other modules 

AXIS2_RAMPART = mod_rampart
AXIS2_MOD_LOG = axis2_mod_log

# include path
APACHE_INCLUE_PATH = /I$(APACHE_BIN_DIR)\include
AXIS2_INCLUDE_PATH = 	/I$(AXIS2_SOURCE_DIR)\util\include \
		/I$(AXIS2_SOURCE_DIR)\util\src\  \
		/I$(AXIS2_SOURCE_DIR)\util\src\minizip\  \
		/I$(AXIS2_SOURCE_DIR)\axiom\include  \
		/I$(AXIS2_SOURCE_DIR)\axiom\src\om  \
		/I$(AXIS2_SOURCE_DIR)\axiom\src\soap \
		/I$(AXIS2_SOURCE_DIR)\util\include\platforms \
		/I$(AXIS2_SOURCE_DIR)\src\core\clientapi \
		/I$(AXIS2_SOURCE_DIR)\src\core\deployment \
		/I$(AXIS2_SOURCE_DIR)\src\core\description \
		/I$(AXIS2_SOURCE_DIR)\src\core\transport \
		/I$(AXIS2_SOURCE_DIR)\include \
		/I$(AXIS2_SOURCE_DIR)\src\core\engine \
		/I$(AXIS2_SOURCE_DIR)\src\core\context \
		/I$(AXIS2_SOURCE_DIR)\src\core\util \
		/I$(AXIS2_SOURCE_DIR)\src\core\transport\http\server\apache2 \
		/I$(AXIS2_SOURCE_DIR)\axiom\src\attachments \
		/I$(LIBXML2_BIN_DIR)\include \
		/I$(ICONV_BIN_DIR)\include \
		/I$(ZLIB_BIN_DIR)\include
		
GUTHTHILA_INCLUDE_PATH = /I$(AXIS2_SOURCE_DIR)\guththila\include
 
!if "$(ENABLE_SSL)" == "1"
AXIS2_INCLUDE_PATH = $(AXIS2_INCLUDE_PATH) /I$(OPENSSL_BIN_DIR)\include
!endif
!if "$(ENABLE_LIBCURL)" == "1"
AXIS2_INCLUDE_PATH = $(AXIS2_INCLUDE_PATH) /I$(LIBCURL_BIN_DIR)\include
!endif


#source paths for core modules

AXIS2_UTIL_SRC = $(AXIS2_SOURCE_DIR)\util\src\platforms\windows\*.c \
		$(AXIS2_SOURCE_DIR)\util\src\minizip\*.c \
		$(AXIS2_SOURCE_DIR)\util\src\*.c 

AXIS2_PARSER_SRC = $(AXIS2_SOURCE_DIR)\axiom\src\parser\*.c \
		   $(AXIS2_SOURCE_DIR)\axiom\src\parser\libxml2\*.c

AXIS2_GUTHTHILA_PARSER_SRC = $(AXIS2_SOURCE_DIR)\axiom\src\parser\*.c \
                             $(AXIS2_SOURCE_DIR)\axiom\src\parser\guththila\*.c


AXIOM_SRC = $(AXIS2_SOURCE_DIR)\axiom\src\om\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\soap\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\attachments\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\util\*.c

AXIS2_ENGINE_SRC =  $(AXIS2_SOURCE_DIR)\src\core\addr\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\clientapi\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\context\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\deployment\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\description\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\engine\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\phaseresolver\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\receivers\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\util\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\transport\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\transport\http\common\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\transport\http\util\*.c
		
		
AXIS2_HTTP_SENDER_SRC = $(AXIS2_SOURCE_DIR)\src\core\transport\http\sender\*.c


!if "$(ENABLE_SSL)" == "1"
AXIS2_HTTP_SENDER_SRC = $(AXIS2_HTTP_SENDER_SRC) \
		$(AXIS2_SOURCE_DIR)\src\core\transport\http\sender\ssl\*.c
!endif
!if "$(ENABLE_LIBCURL)" == "1"
AXIS2_HTTP_SENDER_SRC = $(AXIS2_HTTP_SENDER_SRC) \
		$(AXIS2_SOURCE_DIR)\src\core\transport\http\sender\libcurl\*.c
!endif


AXIS2_HTTP_RECEIVER_SRC = $(AXIS2_SOURCE_DIR)\src\core\transport\http\receiver\*.c 

AXIS2_MOD_ADDR_SRC = $(AXIS2_SOURCE_DIR)\src\modules\mod_addr\*.c

GUTHTHILA_SRC = $(AXIS2_SOURCE_DIR)\guththila\src\*.c


##################### compiler options

CC = @cl.exe 
CFLAGS = /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "AXIS2_DECLARE_EXPORT"  \
	/D "_CRT_SECURE_NO_DEPRECATE" /D "_CRT_SECURE_NO_WARNINGS" \
	  /D "AXIS2_SVR_MULTI_THREADED" /w /nologo $(AXIS2_INCLUDE_PATH) \
	 $(APACHE_INCLUDE_PATH)

!if "$(ENABLE_SSL)" == "1"
CFLAGS = $(CFLAGS) /D "AXIS2_SSL_ENABLED"
!endif

!if "$(ENABLE_LIBCURL)" == "1"
CFLAGS = $(CFLAGS) /D "AXIS2_LIBCURL_ENABLED"
!endif

################### linker options

LD = @link.exe
LDFLAGS = /nologo /LIBPATH:$(AXIS2_LIBS) /LIBPATH:$(LIBXSLT_BIN_DIR)\lib \
	     /LIBPATH:$(LIBXML2_BIN_DIR)\lib  /LIBPATH:$(APACHE_BIN_DIR)\lib \
		 /LIBPATH:$(ZLIB_BIN_DIR)\lib
		 
LIBS =  Rpcrt4.lib Ws2_32.lib

!if "$(ENABLE_SSL)" == "1"
LDFLAGS = $(LDFLAGS) /LIBPATH:$(OPENSSL_BIN_DIR)\lib\VC
LIBS = $(LIBS) libeay32MT.lib ssleay32MT.lib
!endif

!if "$(ENABLE_LIBCURL)" == "1"
LDFLAGS = $(LDFLAGS) /LIBPATH:$(LIBCURL_BIN_DIR)
LIBS = $(LIBS) libcurl_imp.lib
!endif

!if "$(APACHE_VERSION_IS_2_0_59)" == "1"
APACHE_LIBS = apr.lib xml.lib libhttpd.lib aprutil.lib libapr.lib
!else
APACHE_LIBS = apr-1.lib xml.lib libhttpd.lib aprutil-1.lib libapr-1.lib
!endif



#################### debug symbols
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
	if not exist $(AXIS2_BINDIR) mkdir $(AXIS2_BINDIR) 
	if not exist $(AXIS2_BINS) mkdir $(AXIS2_BINS)
	if not exist $(AXIS2_SERVICES) mkdir $(AXIS2_SERVICES)
	if not exist $(AXIS2_MODULES) mkdir $(AXIS2_MODULES)
	if not exist $(AXIS2_LIBS) mkdir $(AXIS2_LIBS)
	if not exist $(AXIS2_INCLUDE) mkdir $(AXIS2_INCLUDE)
	if not exist $(AXIS2_LOG) mkdir $(AXIS2_LOG)
	if not exist $(AXIS2_MODULES)\addressing mkdir $(AXIS2_MODULES)\addressing
			
#intermediate directories
	
	if not exist $(AXIS2_INTDIR) mkdir $(AXIS2_INTDIR)
	if not exist $(AXIS2_INTDIR_AXIOM) mkdir $(AXIS2_INTDIR_AXIOM)
	if not exist $(AXIS2_INTDIR_UTIL) mkdir $(AXIS2_INTDIR_UTIL)
	if not exist $(AXIS2_INTDIR_CORE) mkdir $(AXIS2_INTDIR_CORE)
	if not exist $(AXIS2_INTDIR_TNS) mkdir $(AXIS2_INTDIR_TNS)
	if not exist $(AXIS2_INTDIR_TNR) mkdir $(AXIS2_INTDIR_TNR)
	if not exist $(AXIS2_INTDIR_PARSER) mkdir $(AXIS2_INTDIR_PARSER)
	if not exist $(AXIS2_INTDIR_ADDRESSING) mkdir $(AXIS2_INTDIR_ADDRESSING)
	if not exist $(AXIS2_INTDIR_SAMPLES) mkdir $(AXIS2_INTDIR_SAMPLES)
    if not exist $(AXIS2_INTDIR_GUTHTHILA) mkdir $(AXIS2_INTDIR_GUTHTHILA)	
	
#clean 
clean:
	if exist $(AXIS2_BINDIR) rmdir /S /Q $(AXIS2_BINDIR)
	if exist $(AXIS2_INTDIR) rmdir /S /Q $(AXIS2_INTDIR)
	
clean_make_dir:
	del *.obj del *.exe del *.exp

axis2_util: 
	$(CC) $(CFLAGS) $(AXIS2_UTIL_SRC) /Fo$(AXIS2_INTDIR_UTIL)\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_UTIL)\*.obj $(LIBS) $(ZLIB_BIN_DIR)\lib\zdll.lib \
	/DLL  /OUT:$(AXIS2_LIBS)\$(AXUTIL).dll  /IMPLIB:$(AXIS2_LIBS)\$(AXUTIL).lib 

guththila:
	$(CC) $(CFLAGS) $(GUTHTHILA_INCLUDE_PATH) $(GUTHTHILA_SRC) /Fo$(AXIS2_INTDIR_GUTHTHILA)\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_GUTHTHILA)\*.obj $(AXUTIL).lib \
	$(LIBS) \
	/DLL /OUT:$(AXIS2_LIBS)\$(GUTHTHILA).dll /IMPLIB:$(AXIS2_LIBS)\$(GUTHTHILA).lib

axis2_parser:
		
	$(CC) $(CFLAGS) $(AXIS2_PARSER_SRC) /Fo$(AXIS2_INTDIR_PARSER)\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_PARSER)\*.obj $(AXUTIL).lib $(LIBS) \
	$(LIBXML2_BIN_DIR)\lib\libxml2.lib  /DLL \
	/OUT:$(AXIS2_LIBS)\$(AXIS2_PARSER).dll /IMPLIB:$(AXIS2_LIBS)\$(AXIS2_PARSER).lib
	
axis2_parser_with_guththila:
        $(CC) $(CFLAGS) $(GUTHTHILA_INCLUDE_PATH) $(AXIS2_GUTHTHILA_PARSER_SRC) /Fo$(AXIS2_INTDIR_PARSER)\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_PARSER)\*.obj $(AXUTIL).lib $(LIBS) \
	$(AXIS2_LIBS)\$(GUTHTHILA).lib  /DLL \
	/OUT:$(AXIS2_LIBS)\$(AXIS2_PARSER).dll /IMPLIB:$(AXIS2_LIBS)\$(AXIS2_PARSER).lib
	
axiom: 
	$(CC) $(CFLAGS) $(AXIOM_SRC) /Fo$(AXIS2_INTDIR_AXIOM)\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_AXIOM)\*.obj $(AXUTIL).lib \
	$(AXIS2_PARSER).lib $(LIBS)  /DLL /OUT:$(AXIS2_LIBS)\$(AXIOM).dll \
	/IMPLIB:$(AXIS2_LIBS)\$(AXIOM).lib
	
axis2_engine: 
	$(CC) $(CFLAGS) $(AXIS2_ENGINE_SRC) /Fo$(AXIS2_INTDIR_CORE)\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_CORE)\*.obj $(AXUTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS)  \
	/DLL /OUT:$(AXIS2_LIBS)\$(AXIS2_ENGINE).dll /IMPLIB:$(AXIS2_LIBS)\$(AXIS2_ENGINE).lib

axis2_http_sender: 
	$(CC) $(CFLAGS) $(AXIS2_HTTP_SENDER_SRC) /Fo$(AXIS2_INTDIR_TNS)\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_TNS)\*.obj $(AXUTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	/DLL /OUT:$(AXIS2_LIBS)\$(AXIS2_TRANSPORT_SENDER).dll /IMPLIB:$(AXIS2_LIBS)\$(AXIS2_TRANSPORT_SENDER).lib

axis2_http_receiver: 
	$(CC) $(CFLAGS) $(AXIS2_HTTP_RECEIVER_SRC) /Fo$(AXIS2_INTDIR_TNR)\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_TNR)\*.obj $(AXUTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib  \
	/DLL /OUT:$(AXIS2_LIBS)\$(AXIS2_TRANSPORT_RECEIVER).dll /IMPLIB:$(AXIS2_LIBS)\$(AXIS2_TRANSPORT_RECEIVER).lib

axis2_mod_addr:
	
	$(CC) $(CFLAGS) $(AXIS2_MOD_ADDR_SRC) /Fo$(AXIS2_INTDIR_ADDRESSING)\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_ADDRESSING)\*.obj $(AXUTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib /DLL /OUT:$(AXIS2_MODULES)\addressing\$(AXIS2_MOD_ADDR).dll
	copy $(AXIS2_SOURCE_DIR)\src\modules\mod_addr\module.xml $(AXIS2_MODULES)\addressing



		
##### simple_axis_server
SIMPLE_AXIS2_SVR_SRC=$(AXIS2_SOURCE_DIR)\src\core\transport\http\server\simple_axis2_server\http_server_main.c
axis2_server: 
	if not exist $(AXIS2_INTDIR)\simple_http_server mkdir $(AXIS2_INTDIR)\simple_http_server
	
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(SIMPLE_AXIS2_SVR_SRC) /Fo$(AXIS2_INTDIR)\simple_http_server\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR)\simple_http_server\http_server_main.obj $(AXUTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	$(AXIS2_TRANSPORT_RECEIVER).lib  /OUT:$(AXIS2_BINS)\$(AXIS2_SERVER).exe 
	
	copy $(AXIS2_SOURCE_DIR)\samples\server\axis2.xml $(AXIS2_BINDIR)\

axis2_core: axis2_util axis2_parser axiom axis2_engine axis2_http_sender axis2_http_receiver axis2_mod_addr axis2_server

axis2_core_guththila: axis2_util guththila axis2_parser_with_guththila axiom axis2_engine axis2_http_sender axis2_http_receiver axis2_mod_addr axis2_server
	
#################################
#server modules

#apache module 

AXIS2_APACHE_MODULE_SRC=$(AXIS2_SOURCE_DIR)\src\core\transport\http\server\apache2\*.c

axis2_apache_module:
    if not exist $(AXIS2_INTDIR)\apache_module mkdir $(AXIS2_INTDIR)\apache_module
    $(CC) $(CFLAGS) $(APACHE_INCLUE_PATH)  $(AXIS2_APACHE_MODULE_SRC) /Fo$(AXIS2_INTDIR)\apache_module\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR)\apache_module\*.obj $(AXUTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib $(APACHE_LIBS) /DLL /OUT:$(AXIS2_LIBS)\mod_axis2.dll
	
#mod IIS

MOD_IIS_SRC = $(AXIS2_SOURCE_DIR)\src\core\transport\http\server\iis\*.c \
	      $(AXIS2_SOURCE_DIR)\src\core\transport\http\server\IIS\iis_iaspi_plugin_51\*.c 
DEF_FILE = $(AXIS2_SOURCE_DIR)\src\core\transport\http\server\IIS\mod_axis2.def

	
axis2_IIS_module:
	if not exist $(AXIS2_INTDIR)\mod_IIS mkdir $(AXIS2_INTDIR)\mod_IIS
	$(CC) $(CFLAGS) $(MOD_IIS_SRC) /Fo$(AXIS2_INTDIR)\mod_IIS\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR)\mod_IIS\*.obj $(AXUTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) Advapi32.lib $(AXIS2_ENGINE).lib /DEF:$(DEF_FILE) /DLL /OUT:$(AXIS2_LIBS)\mod_axis2_IIS.dll

############# end modules  ###################


################ samples ####################
axis2_mod_log:
	if not exist $(AXIS2_INTDIR_SAMPLES)\mod_log mkdir $(AXIS2_INTDIR_SAMPLES)\mod_log
	if not exist $(AXIS2_SAMPLES)\logging mkdir $(AXIS2_SAMPLES)\logging

	$(CC) $(CFLAGS)  $(AXIS2_SOURCE_DIR)\src\modules\mod_log\*.c /Fo$(AXIS2_INTDIR_SAMPLES)\mod_log\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_SAMPLES)\mod_log\*.obj $(AXUTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib /DLL /OUT:$(AXIS2_SAMPLES)\logging\axis2_mod_log.dll 
	
	copy $(AXIS2_SOURCE_DIR)\src\modules\mod_log\module.xml $(AXIS2_SAMPLES)\logging

#sample services

axis2_services_echo:
	if not exist $(AXIS2_SERVICES)\echo mkdir $(AXIS2_SERVICES)\echo
	if not exist $(AXIS2_INTDIR_SAMPLES)\services\echo mkdir $(AXIS2_INTDIR_SAMPLES)\services\echo
	
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\echo \
	$(AXIS2_SOURCE_DIR)\samples\server\echo\*.c /Fo$(AXIS2_INTDIR_SAMPLES)\services\echo\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_SAMPLES)\services\echo\*.obj $(AXUTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	/DLL /OUT:$(AXIS2_SERVICES)\echo\echo.dll  
	
	copy $(AXIS2_SOURCE_DIR)\samples\server\echo\services.xml $(AXIS2_SERVICES)\echo

axis2_services_notify:
	if not exist $(AXIS2_SERVICES)\notify mkdir $(AXIS2_SERVICES)\notify
	if not exist $(AXIS2_INTDIR_SAMPLES)\services\notify mkdir $(AXIS2_INTDIR_SAMPLES)\services\notify

	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\echo \
	$(AXIS2_SOURCE_DIR)\samples\server\notify\*.c /Fo$(AXIS2_INTDIR_SAMPLES)\services\notify\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_SAMPLES)\services\notify\*.obj $(AXUTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	 /DLL /OUT:$(AXIS2_SERVICES)\notify\notify.dll  
	
	copy $(AXIS2_SOURCE_DIR)\samples\server\notify\services.xml $(AXIS2_SERVICES)\notify


axis2_services_math:
	if not exist $(AXIS2_SERVICES)\math mkdir $(AXIS2_SERVICES)\math
	if not exist $(AXIS2_INTDIR_SAMPLES)\services\math mkdir $(AXIS2_INTDIR_SAMPLES)\services\math

	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\math \
	$(AXIS2_SOURCE_DIR)\samples\server\math\*.c /Fo$(AXIS2_INTDIR_SAMPLES)\services\math\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_SAMPLES)\services\math\*.obj $(AXUTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib /DLL /OUT:$(AXIS2_SERVICES)\math\math.dll  
	
	copy $(AXIS2_SOURCE_DIR)\samples\server\math\services.xml $(AXIS2_SERVICES)\math

axis2_services_mtom:
	if not exist $(AXIS2_SERVICES)\mtom mkdir $(AXIS2_SERVICES)\mtom
	if not exist $(AXIS2_INTDIR_SAMPLES)\services\mtom mkdir $(AXIS2_INTDIR_SAMPLES)\services\mtom
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\mtom \
	$(AXIS2_SOURCE_DIR)\samples\server\mtom\*.c /Fo$(AXIS2_INTDIR_SAMPLES)\services\mtom\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_SAMPLES)\services\mtom\*.obj $(AXUTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib /DLL /OUT:$(AXIS2_SERVICES)\mtom\mtom.dll  

	copy $(AXIS2_SOURCE_DIR)\samples\server\mtom\services.xml $(AXIS2_SERVICES)\mtom

axis2_services_calculator:
	if not exist $(AXIS2_SERVICES)\Calculator mkdir $(AXIS2_SERVICES)\Calculator
	if not exist $(AXIS2_INTDIR_SAMPLES)\services\Calculator mkdir $(AXIS2_INTDIR_SAMPLES)\services\Calculator

	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\Calculator \
	$(AXIS2_SOURCE_DIR)\samples\server\Calculator\*.c /Fo$(AXIS2_INTDIR_SAMPLES)\services\Calculator\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_SAMPLES)\services\Calculator\*.obj $(AXUTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	/DLL /OUT:$(AXIS2_SERVICES)\Calculator\Calculator.dll  

	copy $(AXIS2_SOURCE_DIR)\samples\server\Calculator\services.xml $(AXIS2_SERVICES)\Calculator


AXIS2_INTDIR_SGM=$(AXIS2_INTDIR_SAMPLES)\services\sgmath

axis2_services_sg_math:
	if not exist $(AXIS2_SERVICES)\sg_math mkdir $(AXIS2_SERVICES)\sg_math
	if not exist $(AXIS2_INTDIR_SGM)\add mkdir $(AXIS2_INTDIR_SGM)\add
	if not exist $(AXIS2_INTDIR_SGM)\sub mkdir $(AXIS2_INTDIR_SGM)\sub
	if not exist $(AXIS2_INTDIR_SGM)\mul mkdir $(AXIS2_INTDIR_SGM)\mul
	if not exist $(AXIS2_INTDIR_SGM)\div mkdir $(AXIS2_INTDIR_SGM)\div

	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\sg_math  \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\add.c \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\add_skeleton.c /Fo$(AXIS2_INTDIR_SGM)\add\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_SGM)\add\*.obj $(AXUTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	/DLL /OUT:$(AXIS2_SERVICES)\sg_math\add.dll  

	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\sg_math \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\div.c \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\div_skeleton.c /Fo$(AXIS2_INTDIR_SGM)\div\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_SGM)\div\*.obj $(AXUTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib /DLL /OUT:$(AXIS2_SERVICES)\sg_math\div.dll  
	
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\sg_math  \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\sub.c \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\sub_skeleton.c /Fo$(AXIS2_INTDIR_SGM)\sub\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_SGM)\sub\*.obj $(AXUTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib  /DLL /OUT:$(AXIS2_SERVICES)\sg_math\sub.dll  
	
	$(CC) $(CFLAGS) /I$(AXIS2_SOURCE_DIR)\samples\server\sg_math  \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\mul.c \
	$(AXIS2_SOURCE_DIR)\samples\server\sg_math\mul_skeleton.c /Fo$(AXIS2_INTDIR_SGM)\mul\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_SGM)\mul\*.obj $(AXUTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib \
	$(LIBS) $(AXIS2_ENGINE).lib $(AXIS2_TRANSPORT_RECEIVER).lib \
	$(AXIS2_TRANSPORT_SENDER).lib /DLL /OUT:$(AXIS2_SERVICES)\sg_math\mul.dll  
	
	copy $(AXIS2_SOURCE_DIR)\samples\server\sg_math\services.xml $(AXIS2_SERVICES)\sg_math

###################### clients #################################
AXIS2_INTDIR_CLI = $(AXIS2_INTDIR)\samples\clients
axis2_clients_intdir:
	if not exist $(AXIS2_BINS)\samples mkdir $(AXIS2_BINS)\samples
	if not exist $(AXIS2_INTDIR_CLI)\math mkdir $(AXIS2_INTDIR_CLI)\math
	if not exist $(AXIS2_INTDIR_CLI)\echo mkdir $(AXIS2_INTDIR_CLI)\echo
	if not exist $(AXIS2_INTDIR_CLI)\dyn_cli mkdir $(AXIS2_INTDIR_CLI)\dyn_cli
	if not exist $(AXIS2_INTDIR_CLI)\gslc mkdir $(AXIS2_INTDIR_CLI)\gslc
	if not exist $(AXIS2_INTDIR_CLI)\yahoo mkdir $(AXIS2_INTDIR_CLI)\yahoo
	if not exist $(AXIS2_INTDIR_CLI)\notify mkdir $(AXIS2_INTDIR_CLI)\notify
	if not exist $(AXIS2_INTDIR_CLI)\mtom mkdir $(AXIS2_INTDIR_CLI)\mtom

axis2_client_math:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\samples\client\math\*.c /Fo$(AXIS2_INTDIR_CLI)\math\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_CLI)\math\*.obj $(AXUTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib  /OUT:$(AXIS2_BINS)\samples\math.exe 

axis2_client_echo:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\samples\client\echo\echo.c /Fo$(AXIS2_INTDIR_CLI)\echo\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_CLI)\echo\*.obj $(AXUTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib  /OUT:$(AXIS2_BINS)\samples\echo.exe 

axis2_client_google_spell:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\samples\client\google\*.c /Fo$(AXIS2_INTDIR_CLI)\gslc\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_CLI)\gslc\*.obj $(AXUTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib  /OUT:$(AXIS2_BINS)\samples\google.exe 

axis2_client_yahoo:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\samples\client\yahoo\*.c /Fo$(AXIS2_INTDIR_CLI)\yahoo\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_CLI)\yahoo\*.obj $(AXUTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:$(AXIS2_BINS)\samples\yahoo.exe 

axis2_client_notify:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH) \
	$(AXIS2_SOURCE_DIR)\samples\client\notify\*.c /Fo$(AXIS2_INTDIR_CLI)\notify\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_CLI)\notify\*.obj $(AXUTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:$(AXIS2_BINS)\samples\notify.exe 

axis2_client_mtom:
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\client\mtom\*.c /Fo$(AXIS2_INTDIR_CLI)\mtom\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR_CLI)\mtom\*.obj $(AXUTIL).lib $(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:$(AXIS2_BINS)\samples\mtom.exe 

	mkdir $(AXIS2_BINS)\samples\resources 
	xcopy $(AXIS2_SOURCE_DIR)\samples\client\mtom\resources $(AXIS2_BINS)\samples\resources 

axis2_client_userguide:
	if not exist $(AXIS2_INTDIR)\userguide\echo_blocking mkdir $(AXIS2_INTDIR)\userguide\echo_blocking
	if not exist $(AXIS2_INTDIR)\userguide\echo_non_blocking mkdir $(AXIS2_INTDIR)\userguide\echo_non_blocking
	if not exist $(AXIS2_INTDIR)\userguide\echo_blocking_addr mkdir $(AXIS2_INTDIR)\userguide\echo_blocking_addr
	if not exist $(AXIS2_INTDIR)\userguide\echo_rest mkdir $(AXIS2_INTDIR)\userguide\echo_rest
	if not exist $(AXIS2_INTDIR)\userguide\echo_blocking_dual mkdir $(AXIS2_INTDIR)\userguide\echo_blocking_dual
	if not exist $(AXIS2_INTDIR)\userguide\echo_non_blocking_dual mkdir $(AXIS2_INTDIR)\userguide\echo_non_blocking_dual
	if not exist $(AXIS2_INTDIR)\userguide\echo_blocking_soap11 mkdir $(AXIS2_INTDIR)\userguide\echo_blocking_soap11


	$(CC) $(CFLAGS) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_blocking.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /Fo$(AXIS2_INTDIR)\userguide\echo_blocking\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR)\userguide\echo_blocking\*.obj $(AXUTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib  /OUT:$(AXIS2_BINS)\samples\echo_blocking.exe

	
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_non_blocking.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /Fo$(AXIS2_INTDIR)\userguide\echo_non_blocking\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR)\userguide\echo_non_blocking\*.obj $(AXUTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	/OUT:$(AXIS2_BINS)\samples\echo_non_blocking.exe



	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_blocking_addr.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /Fo$(AXIS2_INTDIR)\userguide\echo_blocking_addr\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR)\userguide\echo_blocking_addr\*.obj $(AXUTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	/OUT:$(AXIS2_BINS)\samples\echo_blocking_addr.exe 


	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_rest.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /Fo$(AXIS2_INTDIR)\userguide\echo_rest\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR)\userguide\echo_rest\*.obj $(AXUTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	/OUT:$(AXIS2_BINS)\samples\echo_rest.exe 

	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_blocking_dual.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /Fo$(AXIS2_INTDIR)\userguide\echo_blocking_dual\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR)\userguide\echo_blocking_dual\*.obj $(AXUTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib  /OUT:$(AXIS2_BINS)\samples\echo_blocking_dual.exe

	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_non_blocking_dual.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /Fo$(AXIS2_INTDIR)\userguide\echo_non_blocking_dual\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR)\userguide\echo_non_blocking_dual\*.obj $(AXUTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) $(AXIS2_ENGINE).lib \
	/OUT:$(AXIS2_BINS)\samples\echo_non_blocking_dual.exe 
	
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" $(AXIS2_INCLUDE_PATH)  \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_blocking_soap11.c \
	$(AXIS2_SOURCE_DIR)\samples\user_guide\clients\echo_util.c /Fo$(AXIS2_INTDIR)\userguide\echo_blocking_soap11\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR)\userguide\echo_blocking_soap11\*.obj $(AXUTIL).lib \
	$(AXIOM).lib $(AXIS2_PARSER).lib $(LIBS) \
	$(AXIS2_ENGINE).lib  /OUT:$(AXIS2_BINS)\samples\echo_blocking_soap11.exe 

	
	
copy_extra:
	copy $(AXIS2_SOURCE_DIR)\INSTALL $(AXIS2_BINDIR)
	copy $(AXIS2_SOURCE_DIR)\LICENSE $(AXIS2_BINDIR)
	copy $(AXIS2_SOURCE_DIR)\CREDITS $(AXIS2_BINDIR)
	copy $(AXIS2_SOURCE_DIR)\README $(AXIS2_BINDIR)
	copy $(AXIS2_SOURCE_DIR)\AUTHORS $(AXIS2_BINDIR)
	copy $(AXIS2_SOURCE_DIR)\NEWS $(AXIS2_BINDIR)
	copy $(AXIS2_SOURCE_DIR)\NOTICE $(AXIS2_BINDIR)
	if exist $(AXIS2_SOURCE_DIR)\docs xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\docs $(AXIS2_BINDIR)\docs

copy_samples:
	if not exist $(AXIS2_BINDIR)\samples mkdir $(AXIS2_BINDIR)\samples

	if not exist $(AXIS2_BINDIR)\samples\client mkdir $(AXIS2_BINDIR)\samples\client
	if not exist $(AXIS2_BINDIR)\samples\user_guide mkdir $(AXIS2_BINDIR)\samples\user_guide

	if not exist $(AXIS2_BINDIR)\samples\client\echo mkdir $(AXIS2_BINDIR)\samples\client\echo
	copy $(AXIS2_SOURCE_DIR)\samples\client\echo\echo.c $(AXIS2_BINDIR)\samples\client\echo
	copy $(AXIS2_SOURCE_DIR)\samples\client\echo\README.txt $(AXIS2_BINDIR)\samples\client\echo
	copy $(AXIS2_SOURCE_DIR)\samples\client\echo\echo.mk $(AXIS2_BINDIR)\samples\client\echo

	if not exist $(AXIS2_BINDIR)\samples\client\math mkdir $(AXIS2_BINDIR)\samples\client\math
	copy $(AXIS2_SOURCE_DIR)\samples\client\math\*.c $(AXIS2_BINDIR)\samples\client\math
	copy $(AXIS2_SOURCE_DIR)\samples\client\math\*.h $(AXIS2_BINDIR)\samples\client\math
      copy $(AXIS2_SOURCE_DIR)\samples\client\math\math.mk $(AXIS2_BINDIR)\samples\client\math


	if not exist $(AXIS2_BINDIR)\samples\client\google mkdir $(AXIS2_BINDIR)\samples\client\google
	copy $(AXIS2_SOURCE_DIR)\samples\client\google\*.c $(AXIS2_BINDIR)\samples\client\google
	copy $(AXIS2_SOURCE_DIR)\samples\client\google\README.txt $(AXIS2_BINDIR)\samples\client\google
      copy $(AXIS2_SOURCE_DIR)\samples\client\google\google.mk $(AXIS2_BINDIR)\samples\client\google

	if not exist $(AXIS2_BINDIR)\samples\client\notify mkdir $(AXIS2_BINDIR)\samples\client\notify
	copy $(AXIS2_SOURCE_DIR)\samples\client\notify\*.c $(AXIS2_BINDIR)\samples\client\notify
	copy $(AXIS2_SOURCE_DIR)\samples\client\notify\notify.mk $(AXIS2_BINDIR)\samples\client\notify

	if not exist $(AXIS2_BINDIR)\samples\client\mtom\resources mkdir $(AXIS2_BINDIR)\samples\client\mtom\resources
	copy $(AXIS2_SOURCE_DIR)\samples\client\mtom\*.c $(AXIS2_BINDIR)\samples\client\mtom
	copy $(AXIS2_SOURCE_DIR)\samples\client\mtom\resources\*.jpg $(AXIS2_BINDIR)\samples\client\mtom\resources
	copy $(AXIS2_SOURCE_DIR)\samples\client\mtom\mtom.mk $(AXIS2_BINDIR)\samples\client\mtom

	if not exist $(AXIS2_BINDIR)\samples\client\yahoo mkdir $(AXIS2_BINDIR)\samples\client\yahoo
	copy $(AXIS2_SOURCE_DIR)\samples\client\yahoo\*.c $(AXIS2_BINDIR)\samples\client\yahoo
	copy $(AXIS2_SOURCE_DIR)\samples\client\yahoo\yahoo.mk $(AXIS2_BINDIR)\samples\client\yahoo




	xcopy /E /I $(AXIS2_SOURCE_DIR)\samples\user_guide $(AXIS2_BINDIR)\samples\user_guide

	if not exist $(AXIS2_BINDIR)\samples\server mkdir $(AXIS2_BINDIR)\samples\server

	if not exist $(AXIS2_BINDIR)\samples\server\Calculator mkdir $(AXIS2_BINDIR)\samples\server\Calculator
	copy $(AXIS2_SOURCE_DIR)\samples\server\Calculator\*.c $(AXIS2_BINDIR)\samples\server\Calculator 
	copy $(AXIS2_SOURCE_DIR)\samples\server\Calculator\*.h $(AXIS2_BINDIR)\samples\server\Calculator 
	copy $(AXIS2_SOURCE_DIR)\samples\server\Calculator\*.xml $(AXIS2_BINDIR)\samples\server\Calculator 
	copy $(AXIS2_SOURCE_DIR)\samples\server\Calculator\Calculator.mk $(AXIS2_BINDIR)\samples\server\Calculator 

	if not exist $(AXIS2_BINDIR)\samples\server\echo mkdir $(AXIS2_BINDIR)\samples\server\echo
	copy $(AXIS2_SOURCE_DIR)\samples\server\echo\*.c $(AXIS2_BINDIR)\samples\server\echo
	copy $(AXIS2_SOURCE_DIR)\samples\server\echo\*.h $(AXIS2_BINDIR)\samples\server\echo
	copy $(AXIS2_SOURCE_DIR)\samples\server\echo\*.xml $(AXIS2_BINDIR)\samples\server\echo
	copy $(AXIS2_SOURCE_DIR)\samples\server\echo\echo.mk $(AXIS2_BINDIR)\samples\server\echo

	if not exist $(AXIS2_BINDIR)\samples\server\math mkdir $(AXIS2_BINDIR)\samples\server\math
	copy $(AXIS2_SOURCE_DIR)\samples\server\math\*.c $(AXIS2_BINDIR)\samples\server\math
	copy $(AXIS2_SOURCE_DIR)\samples\server\math\*.h $(AXIS2_BINDIR)\samples\server\math
	copy $(AXIS2_SOURCE_DIR)\samples\server\math\*.xml $(AXIS2_BINDIR)\samples\server\math
	copy $(AXIS2_SOURCE_DIR)\samples\server\math\math.mk $(AXIS2_BINDIR)\samples\server\math

	if not exist $(AXIS2_BINDIR)\samples\server\notify mkdir $(AXIS2_BINDIR)\samples\server\notify
	copy $(AXIS2_SOURCE_DIR)\samples\server\notify\*.c $(AXIS2_BINDIR)\samples\server\notify
	copy $(AXIS2_SOURCE_DIR)\samples\server\notify\*.h $(AXIS2_BINDIR)\samples\server\notify
	copy $(AXIS2_SOURCE_DIR)\samples\server\notify\*.xml $(AXIS2_BINDIR)\samples\server\notify
      copy $(AXIS2_SOURCE_DIR)\samples\server\notify\notify.mk $(AXIS2_BINDIR)\samples\server\notify

	if not exist $(AXIS2_BINDIR)\samples\server\sg_math mkdir $(AXIS2_BINDIR)\samples\server\sg_math
	copy $(AXIS2_SOURCE_DIR)\samples\server\sg_math\*.c $(AXIS2_BINDIR)\samples\server\sg_math
	copy $(AXIS2_SOURCE_DIR)\samples\server\sg_math\*.h $(AXIS2_BINDIR)\samples\server\sg_math
	copy $(AXIS2_SOURCE_DIR)\samples\server\sg_math\*.xml $(AXIS2_BINDIR)\samples\server\sg_math
	copy $(AXIS2_SOURCE_DIR)\samples\server\sg_math\sg_math.mk $(AXIS2_BINDIR)\samples\server\sg_math

	if not exist $(AXIS2_BINDIR)\samples\server\mtom mkdir $(AXIS2_BINDIR)\samples\server\mtom
	copy $(AXIS2_SOURCE_DIR)\samples\server\mtom\*.c $(AXIS2_BINDIR)\samples\server\mtom
	copy $(AXIS2_SOURCE_DIR)\samples\server\mtom\*.h $(AXIS2_BINDIR)\samples\server\mtom
	copy $(AXIS2_SOURCE_DIR)\samples\server\mtom\*.xml $(AXIS2_BINDIR)\samples\server\mtom
      copy $(AXIS2_SOURCE_DIR)\samples\server\mtom\mtom.mk $(AXIS2_BINDIR)\samples\server\mtom

copy_include: 
	xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\include $(AXIS2_BINDIR)\include\

	if exist $(AXIS2_BINDIR)\include\Makefile.am del $(AXIS2_BINDIR)\include\Makefile.am

	xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\axiom\include $(AXIS2_BINDIR)\include\

	if exist $(AXIS2_BINDIR)\include\Makefile.am del $(AXIS2_BINDIR)\include\Makefile.am

	xcopy /E /I /Y $(AXIS2_SOURCE_DIR)\util\include $(AXIS2_BINDIR)\include\

copy_vc_projects:
      if not exist $(AXIS2_BINDIR)\ides mkdir $(AXIS2_BINDIR)\ides
      if not exist $(AXIS2_BINDIR)\ides\vc mkdir $(AXIS2_BINDIR)\ides\vc
      if not exist $(AXIS2_BINDIR)\ides\vc\samples mkdir $(AXIS2_BINDIR)\ides\vc\samples

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients
	
	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\echo mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\echo
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\echo\echo.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\echo

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\math mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\math
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\math\math.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\math

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\google mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\google
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\google\google.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\google

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\mtom mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\mtom
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\mtom\mtom.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\mtom

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\notify mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\notify
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\notify\notify.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\notify

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\yahoo mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\yahoo
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\yahoo\yahoo.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\yahoo

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_blocking mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_blocking
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\echo_blocking\echo_blocking.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_blocking

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_blocking_addr mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_blocking_addr
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\echo_blocking_addr\echo_blocking_addr.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_blocking_addr

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_blocking_dual mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_blocking_dual
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\echo_blocking_dual\echo_blocking_dual.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_blocking_dual

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_non_blocking mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_non_blocking
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\echo_non_blocking\echo_non_blocking.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_non_blocking

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_non_blocking_dual mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_non_blocking_dual
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\echo_non_blocking_dual\echo_non_blocking_dual.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_non_blocking_dual

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_rest mkdir $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_rest
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\echo_rest\echo_rest.vcproj $(AXIS2_BINDIR)\ides\vc\samples\clients\echo_rest

	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\clients\clients.sln $(AXIS2_BINDIR)\ides\vc\samples\clients


 	if not exist $(AXIS2_BINDIR)\ides\vc\samples\services mkdir $(AXIS2_BINDIR)\ides\vc\samples\services

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\services\echo mkdir $(AXIS2_BINDIR)\ides\vc\samples\services\echo
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\services\echo\echo.vcproj $(AXIS2_BINDIR)\ides\vc\samples\services\echo

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\services\math mkdir $(AXIS2_BINDIR)\ides\vc\samples\services\math
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\services\math\math.vcproj $(AXIS2_BINDIR)\ides\vc\samples\services\math

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\services\mtom mkdir $(AXIS2_BINDIR)\ides\vc\samples\services\mtom
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\services\mtom\mtom.vcproj $(AXIS2_BINDIR)\ides\vc\samples\services\mtom

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\services\notify mkdir $(AXIS2_BINDIR)\ides\vc\samples\services\notify
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\services\notify\notify.vcproj $(AXIS2_BINDIR)\ides\vc\samples\services\notify

	if not exist $(AXIS2_BINDIR)\ides\vc\samples\services\Calculator mkdir $(AXIS2_BINDIR)\ides\vc\samples\services\Calculator
	copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\services\Calculator\Calculator.vcproj $(AXIS2_BINDIR)\ides\vc\samples\services\Calculator

      copy $(AXIS2_SOURCE_DIR)\ides\vc\samples\services\services.sln $(AXIS2_BINDIR)\ides\vc\samples\services


mv_dist:
	cd $(AXIS2_BINDIR)
	cd ..
	if exist $(AXIS2_RELEASE_DIR) rmdir /S /Q $(AXIS2_RELEASE_DIR)
	rename  deploy $(AXIS2_RELEASE_DIR)


all_services: axis2_services_echo axis2_services_math axis2_services_notify axis2_services_sg_math axis2_services_mtom axis2_services_calculator 

all_clients: axis2_clients_intdir axis2_client_echo axis2_client_math  axis2_client_google_spell axis2_client_yahoo axis2_client_notify axis2_client_mtom axis2_client_userguide 

axis2_samples: axis2_mod_log all_services all_clients

axis2_server_modules: axis2_apache_module axis2_IIS_module

################################# tools ##################################################

# tcpmon

tcpmon: 
	if not exist $(AXIS2_INTDIR)\tools\tcpmon mkdir $(AXIS2_INTDIR)\tools\tcpmon
	if not exist $(AXIS2_TOOLS) mkdir $(AXIS2_TOOLS)
	$(CC) /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_CRT_SECURE_NO_DEPRECATE" $(AXIS2_INCLUDE_PATH) \
	/I $(AXIS2_SOURCE_DIR)\tools\tcpmon\include \
	$(AXIS2_SOURCE_DIR)\tools\tcpmon\src\*.c /Fo$(AXIS2_INTDIR)\tools\tcpmon\ /c
	$(LD) $(LDFLAGS) $(AXIS2_INTDIR)\tools\tcpmon\*.obj $(AXUTIL).lib $(AXIOM).lib \
	$(AXIS2_PARSER).lib /OUT:$(AXIS2_TOOLS)\tcpmon.exe

##############################################################################################
#axis2.dll

SRC_DIR = $(AXIS2_SOURCE_DIR)\util\src\platforms\windows\*.c \
		$(AXIS2_SOURCE_DIR)\util\src\minizip\*.c \
		$(AXIS2_SOURCE_DIR)\util\src\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\parser\libxml2\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\om\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\soap\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\attachments\*.c \
		$(AXIS2_SOURCE_DIR)\axiom\src\util\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\addr\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\clientapi\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\context\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\deployment\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\description\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\engine\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\phaseresolver\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\receivers\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\util\*.c \
		$(AXIS2_SOURCE_DIR)\src\core\transport\http\*.c \
		$(AXIS2_SOURCE_DIR)\src\wsdl\*.c \

axis2:
	$(CC) $(CFLAGS) /Fo $(AXIS2_INCLUDE_PATH) $(SRC_DIR) /D "_WINDLL" /Gm /Zi /c
	$(LD) $(LDFLAGS) *.obj Rpcrt4.lib Ws2_32.lib zdll.lib libxml2.lib \
	/DLL /OUT:axis2.dll /IMPLIB:axis2.lib 
	
##############################################################################################

build: clean_make_dir clean deploy axis2_core axis2_samples copy_include clean_make_dir 

build_with_guththila : clean_make_dir clean deploy axis2_core_guththila axis2_samples copy_include clean_make_dir

##############################################################################################

all: $(PARSER)

install: all

dist: all axis2_apache_module tcpmon copy_extra copy_samples copy_vc_projects mv_dist

