AUTOCONF = .\..\..\configure.in
!include $(AUTOCONF)

WSFCPP_HOME_DIR="%WSFCPP_HOME%"
SAMPLES_HOME_DIR=.\

CFLAGS = /nologo /w /D "WIN32" /D "_WINDOWS" /D "_MBCS" /EHsc

LDFLAGS = /nologo /LIBPATH:$(WSFCPP_HOME_DIR)\lib

LIBS = axutil.lib axis2_engine.lib axis2_parser.lib axiom.lib wso2_wsf.lib

INCLUDE_PATH = /I$(WSFCPP_HOME_DIR)\include

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
_VC_MANIFEST_EMBED_DLL= if exist $@.manifest $(MT) -nologo -manifest $@.manifest -outputresource:$@;2
!endif

int_dir:
	@if not exist int.msvc mkdir int.msvc

sec_echo_dir:
	@if not exist int.msvc\echo mkdir int.msvc\sec_echo
	@if not exist $(WSFCPP_HOME_DIR)\bin\samples\cpp\security\client\sec_echo mkdir $(WSFCPP_HOME_DIR)\bin\samples\cpp\security\client\sec_echo
             
sec_echo_exe:
	@if not exist int.msvc\sec_echo\sec_echo mkdir int.msvc\sec_echo\sec_echo
	@cl.exe $(CFLAGS) $(INCLUDE_PATH) $(SAMPLES_HOME_DIR)\sec_echo\echo.cpp /Foint.msvc\sec_echo\sec_echo\ /c
	@link.exe $(LDFLAGS) int.msvc\sec_echo\sec_echo\*.obj $(LIBS) /OUT:$(WSFCPP_HOME_DIR)\bin\samples\cpp\security\client\sec_echo\echo.exe
	-@$(_VC_MANIFEST_EMBED_EXE)
	@copy /Y $(SAMPLES_HOME_DIR)\sec_echo\deploy_client_repo.bat $(WSFCPP_HOME_DIR)\bin\samples\cpp\security\client\sec_echo
	@copy /Y $(SAMPLES_HOME_DIR)\sec_echo\update_n_run.bat $(WSFCPP_HOME_DIR)\bin\samples\cpp\security\client\sec_echo
	@xcopy /S/I/Q/Y $(SAMPLES_HOME_DIR)\sec_echo\data $(WSFCPP_HOME_DIR)\bin\samples\cpp\security\client\sec_echo\data
	
sec_samples: int_dir sec_echo_dir sec_echo_exe

clean: 
	@if exist int.msvc rmdir /s /q int.msvc
		
dist: clean sec_samples