AUTOCONF = .\..\configure.in
!include $(AUTOCONF)

# WSFCPP_HOME_DIR="%WSFCPP_HOME%"

WSFCPP_HOME_DIR=.\..\wso2-wsf-cpp-bin-$(WSFCPP_VERSION)-win32

CLIENT_SAMPLES_HOME_DIR=.\clients
SERVICES_SAMPLES_HOME_DIR=.\services
CALLBACK_SAMPLES_HOME_DIR=.\callbacks

WSFCPP_SAMPLES_DIR=$(WSFCPP_HOME_DIR)\samples\bin
WSFCPP_SAMPLES_LIB_DIR=$(WSFCPP_HOME_DIR)\samples\lib

CFLAGS = /nologo /w /D "WIN32" /D "_WINDOWS" /D "_MBCS" /EHsc
CFLAGS = /nologo /w /D "WIN32" /D "_WINDOWS" /D "_MBCS" /EHsc

CC=@cl.exe
LD=@link.exe

LDFLAGS = /nologo /LIBPATH:$(WSFCPP_HOME_DIR)\lib

!if "$(ENABLE_RAMPARTC)" == "0"
LIBS = axutil.lib axis2_engine.lib axis2_parser.lib axiom.lib wso2_wsf.lib
!else
LIBS = axutil.lib axis2_engine.lib axis2_parser.lib axiom.lib wso2_wsf.lib wso2_wsf_security.lib rampart.lib
!endif


INCLUDE_PATH = /I$(WSFCPP_HOME_DIR)\include /I.\..\include /I$(WSFCPP_HOME_DIR)\include\platforms /I$(OPENSSL_BIN_DIR)\include

!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7 $(CRUNTIME)d /D "AXIS2_DECLARE_EXPORT"
LDFLAGS = $(LDFLAGS) /DEBUG
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" $(CRUNTIME) /D "AXIS2_DECLARE_EXPORT"
LDFLAGS = $(LDFLAGS)
!endif


# Manifest Options
####################
MT=mt.exe
MT="$(MT)"

!if "$(EMBED_MANIFEST)" == "0"
_VC_MANIFEST_EMBED_EXE=
_VC_MANIFEST_EMBED_DLL=
!else
_VC_MANIFEST_EMBED_EXE= if exist $@.manifest $(MT) -nologo -manifest $@.manifest -outputresource:$@;1
_VC_MANIFEST_EMBED_DLL= if exist $@.manifest $(MT) -nologo -manifest $@.manifest -outputresource:$@;2
!endif


distdir:
	if not exist $(WSFCPP_SAMPLES_DIR)	mkdir $(WSFCPP_SAMPLES_DIR)
	if not exist $(WSFCPP_SAMPLES_LIB_DIR) mkdir $(WSFCPP_SAMPLES_LIB_DIR)

int_dir:
	@if not exist int.msvc mkdir int.msvc

echo_dir:
	@if not exist int.msvc\echo mkdir int.msvc\echo
             
echo_exe:
	@if not exist int.msvc\echo\echo mkdir int.msvc\echo\echo
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\echo\echo.cpp /Foint.msvc\echo\echo\ /c
	$(LD) $(LDFLAGS) int.msvc\echo\echo\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\echo.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

echo_blocking_exe:
	@if not exist int.msvc\echo\echo_blocking mkdir int.msvc\echo\echo_blocking
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\echo\echo_blocking.cpp /Foint.msvc\echo\echo_blocking\ /c
	$(LD) $(LDFLAGS) int.msvc\echo\echo_blocking\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\echo_blocking.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

echo_blocking_addr_exe:
	@if not exist int.msvc\echo\echo_blocking_addr mkdir int.msvc\echo\echo_blocking_addr
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\echo\echo_blocking_addr.cpp /Foint.msvc\echo\echo_blocking_addr\ /c
	$(LD) $(LDFLAGS) int.msvc\echo\echo_blocking_addr\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\echo_blocking_addr.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

echo_blocking_dual_exe:
	@if not exist int.msvc\echo\echo_blocking_dual mkdir int.msvc\echo\echo_blocking_dual
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\echo\echo_blocking_dual.cpp /Foint.msvc\echo\echo_blocking_dual\ /c
	$(LD) $(LDFLAGS) int.msvc\echo\echo_blocking_dual\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\echo_blocking_dual.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

echo_blocking_soap11_exe:
	@if not exist int.msvc\echo\echo_blocking_soap11 mkdir int.msvc\echo\echo_blocking_soap11
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\echo\echo_blocking_soap11.cpp /Foint.msvc\echo\echo_blocking_soap11\ /c
	$(LD) $(LDFLAGS) int.msvc\echo\echo_blocking_soap11\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\echo_blocking_soap11.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

echo_non_blocking_exe:
	@if not exist int.msvc\echo\echo_non_blocking mkdir int.msvc\echo\echo_non_blocking
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\echo\echo_non_blocking.cpp /Foint.msvc\echo\echo_non_blocking\ /c
	$(LD) $(LDFLAGS) int.msvc\echo\echo_non_blocking\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\echo_non_blocking.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

echo_non_blocking_dual_exe:
	@if not exist int.msvc\echo\echo_non_blocking_dual mkdir int.msvc\echo\echo_non_blocking_dual
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\echo\echo_non_blocking_dual.cpp /Foint.msvc\echo\echo_non_blocking_dual\ /c
	$(LD) $(LDFLAGS) int.msvc\echo\echo_non_blocking_dual\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\echo_non_blocking_dual.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

echo_rest_exe:
	@if not exist int.msvc\echo\echo_rest mkdir int.msvc\echo\echo_rest
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\echo\echo_rest.cpp /Foint.msvc\echo\echo_rest\ /c
	$(LD) $(LDFLAGS) int.msvc\echo\echo_rest\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\echo_rest.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

echo_security_exe:
	@if not exist int.msvc\echo\echo_security mkdir int.msvc\echo\echo_security
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\echo\echo_security.cpp /Foint.msvc\echo\echo_security\ /c
	$(LD) $(LDFLAGS) int.msvc\echo\echo_security\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\sec_echo.exe
	-@$(_VC_MANIFEST_EMBED_EXE)
	

echo_samples: echo_dir echo_exe echo_blocking_exe echo_blocking_addr_exe echo_blocking_dual_exe echo_blocking_soap11_exe echo_non_blocking_exe echo_non_blocking_dual_exe echo_rest_exe echo_security_exe


flickr_exe:
	if not exist int.msvc\flickr mkdir int.msvc\flickr
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\flickr\flickr.cpp /Foint.msvc\flickr\ /c
	$(LD) $(LDFLAGS) int.msvc\flickr\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\flickr.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

google_exe:
	@if not exist int.msvc\google mkdir int.msvc\google
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\google\google.cpp /Foint.msvc\google\ /c
	$(LD) $(LDFLAGS) int.msvc\google\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\google.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

math_exe:
	@if not exist int.msvc\math mkdir int.msvc\math
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\math\math.cpp /Foint.msvc\math\ /c
	$(LD) $(LDFLAGS) int.msvc\math\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\math.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

notify_exe:
	@if not exist int.msvc\notify mkdir int.msvc\notify
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\notify\notify.cpp /Foint.msvc\notify\ /c
	$(LD) $(LDFLAGS) int.msvc\notify\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\notify.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

yahoo_exe:
	@if not exist int.msvc\yahoo mkdir int.msvc\yahoo
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\yahoo\yahoo.cpp /Foint.msvc\yahoo\ /c
	$(LD) $(LDFLAGS) int.msvc\yahoo\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\yahoo.exe
	-@$(_VC_MANIFEST_EMBED_EXE)

mtom_exe:
	@if not exist int.msvc\mtom mkdir int.msvc\mtom
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CLIENT_SAMPLES_HOME_DIR)\mtom\mtom.cpp /Foint.msvc\mtom\ /c
	$(LD) $(LDFLAGS) int.msvc\mtom\*.obj $(LIBS) /OUT:$(WSFCPP_SAMPLES_DIR)\mtom.exe
	-@$(_VC_MANIFEST_EMBED_EXE)
	@xcopy /E /I /Q /Y $(CLIENT_SAMPLES_HOME_DIR)\mtom\resources $(WSFCPP_SAMPLES_DIR)\resources
	@if exist $(WSFCPP_SAMPLES_DIR)\mtom\resources\*.am del $(WSFCPP_SAMPLES_DIR)\resources\*.am

echo_service:
	@if not exist int.msvc\services\echo mkdir int.msvc\services\echo
	@if not exist $(WSFCPP_HOME_DIR)\services\echo mkdir $(WSFCPP_HOME_DIR)\services\echo
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(SERVICES_SAMPLES_HOME_DIR)\echo\Echo.cpp /Foint.msvc\services\echo\ /c
	$(LD) $(LDFLAGS) int.msvc\services\echo\*.obj $(LIBS) /DLL /OUT:$(WSFCPP_HOME_DIR)\services\echo\echo.dll
	-@$(_VC_MANIFEST_EMBED_EXE)
	@copy  /Y $(SERVICES_SAMPLES_HOME_DIR)\echo\services.xml $(WSFCPP_HOME_DIR)\services\echo\services.xml

mtom_service:
	@if not exist int.msvc\services\mtom mkdir int.msvc\services\mtom
	@if not exist $(WSFCPP_HOME_DIR)\services\mtom mkdir $(WSFCPP_HOME_DIR)\services\mtom
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(SERVICES_SAMPLES_HOME_DIR)\mtom\*.cpp /Foint.msvc\services\mtom\ /c
	$(LD) $(LDFLAGS) int.msvc\services\mtom\*.obj $(LIBS) /DLL /OUT:$(WSFCPP_HOME_DIR)\services\mtom\mtom.dll
	-@$(_VC_MANIFEST_EMBED_EXE)
	@copy  /Y $(SERVICES_SAMPLES_HOME_DIR)\mtom\services.xml $(WSFCPP_HOME_DIR)\services\mtom\services.xml


version_service:
	@if not exist int.msvc\services\version mkdir int.msvc\services\version
	@if not exist $(WSFCPP_HOME_DIR)\services\version mkdir $(WSFCPP_HOME_DIR)\services\version
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(SERVICES_SAMPLES_HOME_DIR)\version\*.cpp /Foint.msvc\services\version\ /c
	$(LD) $(LDFLAGS) int.msvc\services\version\*.obj $(LIBS) /DLL /OUT:$(WSFCPP_HOME_DIR)\services\version\version.dll
	-@$(_VC_MANIFEST_EMBED_EXE)
	@copy  /Y $(SERVICES_SAMPLES_HOME_DIR)\version\services.xml $(WSFCPP_HOME_DIR)\services\version\services.xml


notify_service:
	@if not exist int.msvc\services\notify mkdir int.msvc\services\notify
	@if not exist $(WSFCPP_HOME_DIR)\services\notify mkdir $(WSFCPP_HOME_DIR)\services\notify
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(SERVICES_SAMPLES_HOME_DIR)\notify\*.cpp /Foint.msvc\services\notify\ /c
	$(LD) $(LDFLAGS) int.msvc\services\notify\*.obj $(LIBS) /DLL /OUT:$(WSFCPP_HOME_DIR)\services\notify\notify.dll
	-@$(_VC_MANIFEST_EMBED_EXE)
	@copy  /Y $(SERVICES_SAMPLES_HOME_DIR)\notify\services.xml $(WSFCPP_HOME_DIR)\services\notify\services.xml


math_service:
	@if not exist int.msvc\services\math mkdir int.msvc\services\math
	@if not exist $(WSFCPP_HOME_DIR)\services\math mkdir $(WSFCPP_HOME_DIR)\services\math
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(SERVICES_SAMPLES_HOME_DIR)\math\*.cpp /Foint.msvc\services\math\ /c
	$(LD) $(LDFLAGS) int.msvc\services\math\*.obj $(LIBS) /DLL /OUT:$(WSFCPP_HOME_DIR)\services\math\math.dll
	-@$(_VC_MANIFEST_EMBED_EXE)
	@copy  /Y $(SERVICES_SAMPLES_HOME_DIR)\math\services.xml $(WSFCPP_HOME_DIR)\services\math\services.xml


wsfcpp_samples: int_dir distdir echo_samples flickr_exe google_exe math_exe notify_exe yahoo_exe mtom_exe echo_service mtom_service version_service notify_service math_service


password_callback:
	@if not exist int.msvc\callbacks\password_callback mkdir int.msvc\callbacks\password_callback
	@if not exist $(WSFCPP_SAMPLES_LIB_DIR) mkdir $(WSFCPP_SAMPLES_LIB_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CALLBACK_SAMPLES_HOME_DIR)\password_callback\*.cpp /Foint.msvc\callbacks\password_callback\ /c
	$(LD) $(LDFLAGS) int.msvc\callbacks\password_callback\*.obj $(LIBS) /DLL /OUT:$(WSFCPP_SAMPLES_LIB_DIR)\pwcb.dll
	-@$(_VC_MANIFEST_EMBED_EXE)

authentication_provider:
	@if not exist int.msvc\callbacks\authentication_provider mkdir int.msvc\callbacks\authentication_provider
	@if not exist $(WSFCPP_SAMPLES_LIB_DIR) mkdir $(WSFCPP_SAMPLES_LIB_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CALLBACK_SAMPLES_HOME_DIR)\authentication_provider\*.cpp /Foint.msvc\callbacks\authentication_provider\ /c
	$(LD) $(LDFLAGS) int.msvc\callbacks\authentication_provider\*.obj $(LIBS)  /DLL /OUT:$(WSFCPP_SAMPLES_LIB_DIR)\authn_provider.dll
	-@$(_VC_MANIFEST_EMBED_EXE)

replay_detector:
	@if not exist int.msvc\callbacks\replay_detector mkdir int.msvc\callbacks\replay_detector
	@if not exist $(WSFCPP_SAMPLES_LIB_DIR) mkdir $(WSFCPP_SAMPLES_LIB_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CALLBACK_SAMPLES_HOME_DIR)\replay_detector\*.cpp /Foint.msvc\callbacks\replay_detector\ /c
	$(LD) $(LDFLAGS) int.msvc\callbacks\replay_detector\*.obj $(LIBS)  /DLL /OUT:$(WSFCPP_SAMPLES_LIB_DIR)\rdflatfile.dll
	-@$(_VC_MANIFEST_EMBED_EXE)

sct_provider:
	@if not exist int.msvc\callbacks\sct_provider mkdir int.msvc\callbacks\sct_provider
	@if not exist $(WSFCPP_SAMPLES_LIB_DIR) mkdir $(WSFCPP_SAMPLES_LIB_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(CALLBACK_SAMPLES_HOME_DIR)\sct_provider\*.cpp /Foint.msvc\callbacks\sct_provider\ /c
	$(LD) $(LDFLAGS) int.msvc\callbacks\sct_provider\sct_provider_hashdb.obj $(LIBS) /DLL /OUT:$(WSFCPP_SAMPLES_LIB_DIR)\sctprovider_hashdb.dll
	-@$(_VC_MANIFEST_EMBED_EXE)
	$(LD) $(LDFLAGS) int.msvc\callbacks\sct_provider\sct_provider.obj $(LIBS) /DLL /OUT:$(WSFCPP_SAMPLES_LIB_DIR)\sctprovider.dll
	-@$(_VC_MANIFEST_EMBED_EXE)

copy_scripts:
	@xcopy /I /Y /E secscripts $(WSFCPP_SAMPLES_DIR)\security
	@move $(WSFCPP_SAMPLES_DIR)\security\update_n_run.bat $(WSFCPP_SAMPLES_DIR)\

wsfcpp_callback: password_callback authentication_provider replay_detector sct_provider

clean: 
	@if exist int.msvc rmdir /s /q int.msvc
		
!if "$(ENABLE_RAMPARTC)" == "0"
dist: clean wsfcpp_samples
!else
dist: clean wsfcpp_samples wsfcpp_callback copy_scripts
!endif
