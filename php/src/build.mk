AUTOCONF = .\..\configure.in
!include $(AUTOCONF)

WSFPHP_BIN_DIR=wso2-wsf-php-bin-$(WSFPHP_VERSION)-win32

CFLAGS = /nologo /w /D "WIN32" /D "_WINDOWS" /D "PHP_WIN32" /D "COMPILE_DL_WSF" \
	 /D "_USE_32BIT_TIME_T=1" /D "ZEND_WIN32" /D "ZEND_DEBUG=0" \
	 /D "_MBCS" 

LDFLAGS = /nologo /LIBPATH:.\..\$(WSFPHP_BIN_DIR)\wsf_c\lib /LIBPATH:$(PHP_BIN_DIR)\dev \
	  /LIBPATH:$(LIBXML2_BIN_DIR)\lib

LIBS = axutil.lib axis2_engine.lib axis2_parser.lib axiom.lib rampart.lib axis2_http_sender.lib \
       neethi_util.lib neethi.lib sandesha2.lib sandesha2_client.lib wsock32.lib

!if "$(ENABLE_LIBXML2)" =="1"
LIBS=$(LIBS) libxml2.lib
!endif

INCLUDE_PATH = /I$(PHP_SRC_DIR) /I$(PHP_SRC_DIR)\main /I$(PHP_SRC_DIR)\regex \
	       /I$(PHP_SRC_DIR)\ext /I$(PHP_SRC_DIR)\sapi /I$(PHP_SRC_DIR)\Zend \
	       /I$(PHP_SRC_DIR)\TSRM /I.\..\$(WSFPHP_BIN_DIR)\wsf_c\include \
	       /I$(LIBXML2_BIN_DIR)\include /I$(ICONV_BIN_DIR)\include \
	       /I$(OPENSSL_BIN_DIR)\include


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
	@link.exe $(LDFLAGS) intdir\*.obj intdir\wsf.res $(LIBS) /DLL  /OUT:.\..\$(WSFPHP_BIN_DIR)\wsf.dll
	if exist .\..\$(WSFPHP_BIN_DIR)\wsf.dll.manifest mt.exe -manifest .\..\$(WSFPHP_BIN_DIR)\wsf.dll.manifest -outputresource:.\..\$(WSFPHP_BIN_DIR)\wsf.dll;2
	if exist .\..\$(WSFPHP_BIN_DIR)\wsf.lib del .\..\$(WSFPHP_BIN_DIR)\wsf.lib
	if exist .\..\$(WSFPHP_BIN_DIR)\wsf.exp del .\..\$(WSFPHP_BIN_DIR)\wsf.exp

wsfphp: wsf.dll

cleanint:
	@if exist .\..\$(WSFPHP_BIN_DIR)\wsf.lib del .\..\$(WSFPHP_BIN_DIR)\wsf.lib
	@if exist .\..\$(WSFPHP_BIN_DIR)\wsf.ilk del .\..\$(WSFPHP_BIN_DIR)\wsf.ilk
	@if exist .\..\$(WSFPHP_BIN_DIR)\wsf.exp del .\..\$(WSFPHP_BIN_DIR)\wsf.exp


clean: 
	@if exist intdir rmdir /s /q intdir
		
dist: clean wsfphp cleanint



