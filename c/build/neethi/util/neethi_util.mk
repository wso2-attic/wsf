!include "..\..\..\..\build\versions.in"
!include "..\..\..\build\win32\configure.in"

AXIS2_BIN_DIR= ..\..\..\build\axis2c-bin-$(AXIS2C_VERSION)-win32

CFLAGS = /nologo /D "WIN32" /D "AXIS2_DECLARE_EXPORT" /D "_WINDOWS" /D "_MBCS"
LDFLAGS = /nologo


!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7 $(CRUNTIME)d
LDFLAGS = $(LDFLAGS) /DEBUG /INCREMENTAL
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" /O2 $(CRUNTIME)
LDFLAGS = $(LDFLAGS)
!endif


neethi_util: copy_include
	cl.exe $(CFLAGS)  *.c /I$(AXIS2_BIN_DIR)\include /c
	link.exe $(LDFLAGS) *.obj /LIBPATH:$(AXIS2_BIN_DIR)\lib axiom.lib axutil.lib \
	axis2_engine.lib axis2_parser.lib /DLL /OUT:$(AXIS2_BIN_DIR)\lib\neethi_util.dll \
	/IMPLIB:$(AXIS2_BIN_DIR)\lib\neethi_util.lib
	if exist $(AXIS2_BIN_DIR)\lib\neethi_util.dll.manifest mt.exe -manifest $(AXIS2_BIN_DIR)\lib\neethi_util.dll.manifest -outputresource:$(AXIS2_BIN_DIR)\lib\neethi_util.dll;2

copy_include :
	copy /Y neethi_options.h .\..\..\..\include\

