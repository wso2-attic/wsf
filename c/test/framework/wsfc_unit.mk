!include .\..\..\build\versions.in

AUTOCONF = .\..\..\configure.in
!include $(AUTOCONF)

WSFC_HOME_DIR_DLL=.\..\..\wso2-wsf-c-bin-$(WSFC_VERSION)-win32\samples
WSFC_HOME_DIR_SAMPLE=.\..\..\..\wso2-wsf-c-bin-$(WSFC_VERSION)-win32\samples

CFLAGS = /nologo /w /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "AXIS2_DECLARE_EXPORT"

LDFLAGS = /nologo

INCLUDE_PATH = /I.\include

!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7 $(CRUNTIME)d
LDFLAGS = $(LDFLAGS) /DEBUG
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" /O2 $(CRUNTIME)
LDFLAGS = $(LDFLAGS)
!endif

!if "$(EMBED_MANIFEST)" == "0"
_VC_MANIFEST_EMBED_EXE=
_VC_MANIFEST_EMBED_DLL=
!else
_VC_MANIFEST_EMBED_EXE= if exist $@.manifest $(MT) -nologo -manifest $@.manifest -outputresource:$@;1
_VC_MANIFEST_EMBED_DLL= if exist $@.manifest mt.exe -nologo -manifest $@.manifest -outputresource:$@;2
!endif

wso2_wsfc_unit_dll:
	if not exist int.msvc mkdir int.msvc
	cl.exe $(CFLAGS) $(INCLUDE_PATH) src\*.c /Foint.msvc\ /c
	if not exist $(WSFC_HOME_DIR_DLL) mkdir $(WSFC_HOME_DIR_DLL)
	if not exist $(WSFC_HOME_DIR_DLL)\lib mkdir $(WSFC_HOME_DIR_DLL)\lib
	link.exe $(LDFLAGS) /LIBPATH:$(WSFC_HOME_DIR_DLL)\lib int.msvc\*.obj /DLL \
	/OUT:$(WSFC_HOME_DIR_DLL)\lib\wso2_wsfc_unit.dll /IMPLIB:$(WSFC_HOME_DIR_DLL)\lib\wso2_wsfc_unit.lib
	-@$(_VC_MANIFEST_EMBED_DLL)

wso2_wsfc_unit_samples:
	cd samples
	cd
	if not exist int.msvc mkdir int.msvc
	cl.exe $(CFLAGS) *.c /I.\..\include /I.\ /Foint.msvc\ /c
	if not exist $(WSFC_HOME_DIR_SAMPLE)\bin mkdir $(WSFC_HOME_DIR_SAMPLE)\bin
	if not exist $(WSFC_HOME_DIR_SAMPLE)\bin\test mkdir $(WSFC_HOME_DIR_SAMPLE)\bin\test
	if not exist $(WSFC_HOME_DIR_SAMPLE)\bin\test\framework mkdir $(WSFC_HOME_DIR_SAMPLE)\bin\test\framework
	if not exist $(WSFC_HOME_DIR_SAMPLE)\bin\test\framework\samples mkdir $(WSFC_HOME_DIR_SAMPLE)\bin\test\framework\samples
	link.exe $(LDFLAGS) /LIBPATH:$(WSFC_HOME_DIR_SAMPLE)\lib int.msvc\*.obj wso2_wsfc_unit.lib \
        /OUT:$(WSFC_HOME_DIR_SAMPLE)\bin\test\framework\samples\sample.exe
	-@$(_VC_MANIFEST_EMBED_EXE)
	cd ..

wsfc_unit: wso2_wsfc_unit_dll

cleanint:
	if exist $(WSFC_HOME_DIR_DLL)\lib\wso2_wsfc_unit.ilk del $(WSFC_HOME_DIR_DLL)\lib\wso2_wsfc_unit.ilk

clean: 
	if exist int.msvc rmdir /s /q int.msvc
	if exist samples\int.msvc rmdir /s /q samples\int.msvc

install: wsfc_unit wso2_wsfc_unit_samples

dist: clean install cleanint

