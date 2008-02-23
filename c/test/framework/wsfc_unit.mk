AUTOCONF = .\..\..\configure.in
!include $(AUTOCONF)

WSFC_HOME_DIR="%WSFC_HOME%"

CFLAGS = /nologo /w /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "AXIS2_DECLARE_EXPORT"

LDFLAGS = /nologo /LIBPATH:$(WSFC_HOME_DIR)\lib

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
	@if not exist int.msvc mkdir int.msvc
	@cl.exe $(CFLAGS) $(INCLUDE_PATH) src\*.c /Foint.msvc\ /c
    @if not exist $(WSFC_HOME_DIR) mkdir $(WSFC_HOME_DIR)
    @if not exist $(WSFC_HOME_DIR)\lib mkdir $(WSFC_HOME_DIR)\lib
	@link.exe $(LDFLAGS) int.msvc\*.obj /DLL  /OUT:$(WSFC_HOME_DIR)\lib\wso2_wsfc_unit.dll /IMPLIB:$(WSFC_HOME_DIR)\lib\wso2_wsfc_unit.lib
	-@$(_VC_MANIFEST_EMBED_DLL)

wso2_wsfc_unit_samples:
    @cd samples
	@if not exist int.msvc mkdir int.msvc
	@cl.exe $(CFLAGS) *.c /I.\..\include /I.\ /Foint.msvc\ /c
    @if not exist $(WSFC_HOME_DIR)\bin mkdir $(WSFC_HOME_DIR)\bin
	@if not exist $(WSFC_HOME_DIR)\bin\test mkdir $(WSFC_HOME_DIR)\bin\test
	@if not exist $(WSFC_HOME_DIR)\bin\test\framework mkdir $(WSFC_HOME_DIR)\bin\test\framework
	@if not exist $(WSFC_HOME_DIR)\bin\test\framework\samples mkdir $(WSFC_HOME_DIR)\bin\test\framework\samples
	@link.exe $(LDFLAGS) /LIBPATH:$(WSFC_HOME_DIR)\lib int.msvc\*.obj wso2_wsfc_unit.lib \
        /OUT:$(WSFC_HOME_DIR)\bin\test\framework\samples\sample.exe
    -@$(_VC_MANIFEST_EMBED_EXE)
    @cd ..

wsfc_unit: wso2_wsfc_unit_dll

cleanint:
	@if exist $(WSFC_HOME_DIR)\lib\wso2_wsfc_unit.ilk del $(WSFC_HOME_DIR)\lib\wso2_wsfc_unit.ilk

clean: 
	@if exist int.msvc rmdir /s /q int.msvc
	@if exist samples\int.msvc rmdir /s /q samples\int.msvc

install: wsfc_unit wso2_wsfc_unit_samples

dist: clean install cleanint

