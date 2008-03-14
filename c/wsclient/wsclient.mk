AUTOCONF = ..\configure.in
!include $(AUTOCONF)

AXIS2_BIN_DIR=.\..\axis2c\build\axis2c-bin-1.3.0-win32

!if "$(ENABLE_RAMPARTC)" == "1"
OPFLAGS = mod_rampart.lib
!else
OPFLAGS =
!endif

wsclient:
	@echo off

	@if not exist int.msvc mkdir int.msvc
	@cl.exe /nologo /D "WIN32" /w /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" src\*.c \
	/I$(AXIS2_BIN_DIR)\include /I.\..\axis2c\neethi\include /I.\..\axis2c\neethi\src\util /Foint.msvc\ /c

	@link.exe /LIBPATH:$(AXIS2_BIN_DIR)\lib int.msvc\*.obj axutil.lib  axis2_engine.lib \
	axis2_parser.lib axiom.lib neethi_util.lib axis2_http_sender.lib $(OPFLAGS) /OUT:$(AXIS2_BIN_DIR)\bin\wsclient.exe
	@if exist int.msvc rmdir /s /q int.msvc
	@mkdir $(AXIS2_BIN_DIR)\bin\samples\wsclient
	@xcopy /S /Y samples\* $(AXIS2_BIN_DIR)\bin\samples\wsclient
	
