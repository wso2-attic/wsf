!include "..\..\..\..\..\build\versions.in"

AUTOCONF = E:\wsfc\configure.in
!include $(AUTOCONF)

AXIS2_BIN_DIR=..\..\..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32

CFLAGS = /nologo /D "WIN32" /w /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" \
	/I$(AXIS2_BIN_DIR)\include /I.

!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7 $(CRUNTIME)d
LDFLAGS = $(LDFLAGS) /DEBUG
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" /O2 $(CRUNTIME)
LDFLAGS = $(LDFLAGS)
!endif

!if "$(ENABLE_RAMPARTC)" == "1"
OPFLAGS = rampart.lib
!else
OPFLAGS =
!endif

axis2_udp_sender:
	echo off

	if not exist int.msvc mkdir int.msvc
	cl.exe $(CFLAGS) sender\*.c /Foint.msvc\ /c

	link.exe $(LDFLAGS) /LIBPATH:$(AXIS2_BIN_DIR)\lib int.msvc\*.obj axutil.lib  axis2_engine.lib \
	axis2_parser.lib axiom.lib $(OPFLAGS) \
	/DLL /OUT:$(AXIS2_BIN_DIR)\lib\axis2_udp_sender.dll /IMPLIB:$(AXIS2_BIN_DIR)\lib\axis2_udp_sender.lib
	-@$(_VC_MANIFEST_EMBED_DLL)
	
	if exist int.msvc rmdir /s /q int.msvc
	
axis2_udp_receiver:
	echo off

	if not exist int.msvc mkdir int.msvc
	cl.exe $(CFLAGS) receiver\*.c /Foint.msvc\ /c

	link.exe $(LDFLAGS) /LIBPATH:$(AXIS2_BIN_DIR)\lib int.msvc\*.obj axutil.lib  axis2_engine.lib \
	axis2_parser.lib axiom.lib $(OPFLAGS) \
	/DLL /OUT:$(AXIS2_BIN_DIR)\lib\axis2_udp_receiver.dll /IMPLIB:$(AXIS2_BIN_DIR)\lib\axis2_udp_receiver.lib
	-@$(_VC_MANIFEST_EMBED_DLL)

	if exist int.msvc rmdir /s /q int.msvc
	
axis2_udp_server:
	echo off

	if not exist int.msvc mkdir int.msvc
	cl.exe $(CFLAGS) server\*.c /Foint.msvc\ /c

	link.exe $(LDFLAGS) /LIBPATH:$(AXIS2_BIN_DIR)\lib int.msvc\*.obj axutil.lib  axis2_engine.lib \
	axis2_parser.lib axiom.lib axis2_udp_sender.lib axis2_udp_receiver.lib $(OPFLAGS) \
	/OUT:$(AXIS2_BIN_DIR)\bin\axis2_udp_server.exe 
	-@$(_VC_MANIFEST_EMBED_DLL)

	if exist int.msvc rmdir /s /q int.msvc	
	
all: axis2_udp_sender axis2_udp_receiver axis2_udp_server
	
	
