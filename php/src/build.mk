AUTOCONF = .\..\configure.in
!include $(AUTOCONF)

CFLAGS = /nologo /w /D "WIN32" /D "_WINDOWS" /D "PHP_WIN32" /D "COMPILE_DL_WSF" \
	 /D "_USE_32BIT_TIME_T=1" /D "USE_SANDESHA2" /D "ZEND_WIN32" /D "ZEND_DEBUG=0" \
	 /D "_MBCS" 

LDFLAGS = /nologo /LIBPATH:.\..\wso2-wsf-php-bin-1.2.0-win32\wsf_c\lib /LIBPATH:$(PHP_BIN_DIR)\dev \
	  /LIBPATH:$(LIBXML2_BIN_DIR)\lib

LIBS = axutil.lib axis2_engine.lib axis2_parser.lib \
       axiom.lib libxml2.lib mod_rampart.lib axis2_http_sender.lib \
       neethi_util.lib neethi.lib sandesha2.lib libxml2.lib wsock32.lib

INCLUDE_PATH = /I$(PHP_SRC_DIR) /I$(PHP_SRC_DIR)\main /I$(PHP_SRC_DIR)\regex \
	       /I$(PHP_SRC_DIR)\ext /I$(PHP_SRC_DIR)\sapi /I$(PHP_SRC_DIR)\Zend \
	       /I$(PHP_SRC_DIR)\TSRM /I.\..\wso2-wsf-php-bin-1.2.0-win32\wsf_c\include \
	       /I$(LIBXML2_BIN_DIR)\include /I$(WIN32BUILD_DIR)\include \
	       /I$(ICONV_BIN_DIR)\include 

!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7 $(CRUNTIME)d
LDFLAGS = $(LDFLAGS) /DEBUG
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" /O2 $(CRUNTIME)
LDFLAGS = $(LDFLAGS)
!endif


!if "$(ZTS)" == "1"
CFLAGS = $(CFLAGS) /D "ZTS"
LIBS = $(LIBS) php5ts.lib
!else
LIBS = $(LIBS) php5.lib
!endif

WSFPHP_SRC= wsf.c \
	    wsf_util.c \
	    wsf_client.c \
	    wsf_worker.c \
	    wsf_wsdl.c \
	    wsf_xml_msg_recv.c \
	    wsf_out_transport_info.c \
	    wsf_policy.c \
	    wsf_stream.c


wsf.dll :
	@if not exist intdir mkdir intdir
	@cl.exe $(CFLAGS) $(INCLUDE_PATH) $(WSFPHP_SRC) /Fointdir\ /c
	@rc.exe /r /fo "intdir/wsf.res" wsf.rc
	@link.exe $(LDFLAGS) intdir\*.obj intdir\wsf.res $(LIBS) /DLL  /OUT:.\..\wso2-wsf-php-bin-1.2.0-win32\wsf.dll

wsfphp: wsf.dll

cleanint:
	@if exist .\..\wso2-wsf-php-bin-1.2.0-win32\wsf.lib del .\..\wso2-wsf-php-bin-1.2.0-win32\wsf.lib
	@if exist .\..\wso2-wsf-php-bin-1.2.0-win32\wsf.ilk del .\..\wso2-wsf-php-bin-1.2.0-win32\wsf.ilk
	@if exist .\..\wso2-wsf-php-bin-1.2.0-win32\wsf.exp del .\..\wso2-wsf-php-bin-1.2.0-win32\wsf.exp


clean: 
	@if exist intdir rmdir /s /q intdir
		
copy_sqlite:
	@if exist $(SQLITE_BIN_DIR)\sqlite3.dll copy /Y  $(SQLITE_BIN_DIR)\sqlite3.dll .\..\wso2-wsf-php-bin-1.2.0-win32\wsf_c\lib
	@if exist $(SQLITE_BIN_DIR)\sqlite3.exe copy /Y  $(SQLITE_BIN_DIR)\sqlite3.exe .\..\wso2-wsf-php-bin-1.2.0-win32\wsf_c\lib

dist: clean copy_sqlite wsfphp cleanint



