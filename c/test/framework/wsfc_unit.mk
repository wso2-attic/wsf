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
_VC_MANIFEST_EMBED_DLL=
!else
_VC_MANIFEST_EMBED_DLL= if exist $@.manifest mt.exe -nologo -manifest $@.manifest -outputresource:$@;2
!endif

wso2_wsfc_unit_dll:
	@if not exist int.msvc mkdir int.msvc
	@cl.exe $(CFLAGS) $(INCLUDE_PATH) src\*.c /Foint.msvc\ /c
	@link.exe $(LDFLAGS) int.msvc\*.obj /DLL  /OUT:$(WSFC_HOME_DIR)\lib\wso2_wsfc_unit.dll /IMPLIB:$(WSFC_HOME_DIR)\lib\wso2_wsfc_unit.lib
	-@$(_VC_MANIFEST_EMBED_DLL)

wso2_wsfc_unit_samples:
	@if not exist int.msvc mkdir int.msvc
	@cl.exe /nologo /D "WIN32" /w /D "_WINDOWS" /D "_MBCS" samples\*.c \
        /I.\include /I.\samples /Foint.msvc\ /c
	@if not exist $(WSFC_HOME_DIR)\bin\test mkdir $(WSFC_HOME_DIR)\bin\test
	@if not exist $(WSFC_HOME_DIR)\bin\test\framework mkdir $(WSFC_HOME_DIR)\bin\test\framework
	@if not exist $(WSFC_HOME_DIR)\bin\test\framework\samples mkdir $(WSFC_HOME_DIR)\bin\test\framework\samples
	@link.exe /LIBPATH:$(WSFC_HOME_DIR)\lib int.msvc\*.obj axutil.lib  \wso2_wsfc_unit.lib \
        $(OPFLAGS) /OUT:$(WSFC_HOME_DIR)\bin\test\framework\samples

wsfc_unit: wso2_wsfc_unit_dll

cleanint:
	@if exist $(WSFC_HOME_DIR)\lib\wso2_wsfc_unit.ilk del $(WSFC_HOME_DIR)\lib\wso2_wsfc_unit.ilk

clean: 
	@if exist int.msvc rmdir /s /q int.msvc

install: wsfc_unit wso2_wsfc_unit_samples

dist: clean install cleanint

