AUTOCONF = .\..\configure.in
!include $(AUTOCONF)

WSFCPP_HOME_DIR=.\..\wso2-wsf-cpp-bin-$(WSFCPP_VERSION)-win32

CFLAGS = /nologo /w /D "WIN32" /D "_WINDOWS" /D "USE_SANDESHA2" /D "_MBCS" /D "AXIS2_DECLARE_EXPORT" /GR /EHsc
CC=@cl.exe

LDFLAGS = /nologo /LIBPATH:$(WSFCPP_HOME_DIR)\lib /LIBPATH:$(LIBXML2_BIN_DIR)\lib /INCREMENTAL:NO
LD=@link.exe

RC=@rc.exe

!if "$(ENABLE_LIBXML2)" == "1"
LIBS = axutil.lib axis2_engine.lib axis2_parser.lib \
       axiom.lib libxml2.lib wsock32.lib axis2_http_sender.lib \
       neethi_util.lib neethi.lib 
!else
LIBS = axutil.lib axis2_engine.lib axis2_parser.lib \
       axiom.lib guththila.lib wsock32.lib axis2_http_sender.lib \
       neethi_util.lib neethi.lib 
!endif

INCLUDE_PATH = /I.\..\include /I$(WSFCPP_HOME_DIR)\include /I$(WSFCPP_HOME_DIR)\include\platforms /I$(LIBXML2_BIN_DIR)\include /I$(ICONV_BIN_DIR)\include /I$(OPENSSL_BIN_DIR)\include

!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7 $(CRUNTIME)d
LDFLAGS = $(LDFLAGS) /DEBUG
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" /O2 $(CRUNTIME)
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


wso2_wsf_dll :
	@if not exist int.msvc mkdir int.msvc
	$(CC) $(CFLAGS) $(INCLUDE_PATH) main\*.cpp /Foint.msvc\ /c
	$(RC) /r /fo "int.msvc\wsf.res" main\wsf.rc
	$(LD) $(LDFLAGS) int.msvc\*.obj int.msvc\wsf.res $(LIBS) /DLL  /OUT:$(WSFCPP_HOME_DIR)\lib\wso2_wsf.dll /IMPLIB:$(WSFCPP_HOME_DIR)\lib\wso2_wsf.lib
	if exist $(WSFCPP_HOME_DIR)\lib\wso2_wsf.dll.manifest mt.exe -manifest $(WSFCPP_HOME_DIR)\lib\wso2_wsf.dll.manifest -outputresource:$(WSFCPP_HOME_DIR)\lib\wso2_wsf.dll;2

wsf_cpp_msg_recv_dll:
	@if not exist int.msvc\msg_recv mkdir int.msvc\msg_recv
	$(CC) $(CFLAGS) $(INCLUDE_PATH) msg_recv\wsf_cpp_msg_recv.cpp /Foint.msvc\msg_recv\ /c
	$(LD) $(LDFLAGS) int.msvc\msg_recv\wsf_cpp_msg_recv.obj $(LIBS) wso2_wsf.lib /DLL /OUT:$(WSFCPP_HOME_DIR)\lib\wsf_cpp_msg_recv.dll
	if exist $(WSFCPP_HOME_DIR)\lib\wsf_cpp_msg_recv.dll.manifest mt.exe -manifest $(WSFCPP_HOME_DIR)\lib\wsf_cpp_msg_recv.dll.manifest -outputresource:$(WSFCPP_HOME_DIR)\lib\wsf_cpp_msg_recv.dll;2

wso2_wsf_security_dll:
	@if not exist int.msvc\security mkdir int.msvc\security
	$(CC) $(CFLAGS) $(INCLUDE_PATH) security\*.cpp /Foint.msvc\security\ /c
	$(LD) $(LDFLAGS) int.msvc\security\*.obj $(LIBS) wso2_wsf.lib rampart.lib /DLL  /OUT:$(WSFCPP_HOME_DIR)\lib\wso2_wsf_security.dll /IMPLIB:$(WSFCPP_HOME_DIR)\lib\wso2_wsf_security.lib
	if exist $(WSFCPP_HOME_DIR)\lib\wso2_wsf_security.dll.manifest mt.exe -manifest $(WSFCPP_HOME_DIR)\lib\wso2_wsf_security.dll.manifest -outputresource:$(WSFCPP_HOME_DIR)\lib\wso2_wsf_security.dll;2

!if "$(ENABLE_RAMPARTC)" == "0"
wsfcpp: wso2_wsf_dll wsf_cpp_msg_recv_dll
!else
wsfcpp: wso2_wsf_dll wsf_cpp_msg_recv_dll wso2_wsf_security_dll
!endif
	
cleanint:
	@if exist $(WSFCPP_HOME_DIR)\lib\wso2_wsf.ilk del $(WSFCPP_HOME_DIR)\lib\wso2_wsf.ilk

clean: 
	@if exist int.msvc rmdir /s /q int.msvc
		
dist: clean wsfcpp cleanint
