#################################################
# Makefile for axiom [ msvc]
# you can do 
# nmake all       = bulid the library and tests
# nmake clean  - remove all compiler output files
# nmake install  - install the library and header files
# nmake tests   - build tests
#################################################

!include configure.in
#define folders 

AXIOMSRC = ..\..
AXIOM_DIST_DIR= ..\axiom
AXIOM = axiom
AXIS2_PARSER = axis2_parser

#versioning information
#AXIOM_DIST_VERSION = $(AXIOM_MAJOR_VERSION).$(AXIOM_MINOR_VERSION).$(AXIOM_MICRO_VERSION)

#compiler options
CC = cl.exe
CFLAGS = /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "AXIS2_DECLARE_EXPORT" /D "AXIS2_SVR_MULTI_THREADED" /w /nologo
CFLAGS = $(CFLAGS) /I$(LIBXML2_INSTALL_DIR)\include /I$(ICONV_INSTALL_DIR)\include /I$(AXIS2_UTIL_INSTALL_DIR)\include /I$(AXIS2_UTIL_INSTALL_DIR)\include\platforms /I$(AXIOMSRC)\include /I$(AXIOMSRC)\src\om /I$(AXIOMSRC)\src\soap /I$(AXIOMSRC)\src\attachments

#linker options 
LD = link.exe
LDFLAGS = /nologo /LIBPATH:$(LIBXML2_INSTALL_DIR)\lib /LIBPATH:$(ICONV_INSTALL_DIR)\lib /LIBPATH:$(AXIS2_UTIL_INSTALL_DIR)\lib
LIBS = axis2_util.lib libxml2.lib iconv.lib


#debug symbols
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7
LDFLAGS = $(LDFLAGS) /DEBUG /NODEFAULTLIB:LIBCMTD.lib
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" /O2 
LDFLAGS = $(LDFLAGS)
!endif

#create the director structure

distdir:
	if not exist $(AXIOM_DIST_DIR) mkdir $(AXIOM_DIST_DIR)
	if not exist $(AXIOM_DIST_DIR)\bin mkdir $(AXIOM_DIST_DIR)\bin
	if not exist $(AXIOM_DIST_DIR)\lib mkdir $(AXIOM_DIST_DIR)\lib
	if not exist $(AXIOM_DIST_DIR)\include mkdir $(AXIOM_DIST_DIR)\include

clean :
	if exist $(AXIOM_DIST_DIR) rmdir /S /Q $(AXIOM_DIST_DIR)

copy_include:
	xcopy /E $(AXIOMSRC)\include $(AXIOM_DIST_DIR)\include

build_axis2_parser:
	$(CC) $(CFLAGS) $(AXIOMSRC)\src\parser\libxml2\*.c /c
	$(LD) $(LDFLAGS) $(LIBS) *.obj /DLL /OUT:$(AXIS2_PARSER).dll /IMPLIB:$(AXIS2_PARSER).lib
	copy $(AXIS2_PARSER).dll $(AXIOM_DIST_DIR)\bin
	copy $(AXIS2_PARSER).lib $(AXIOM_DIST_DIR)\lib
	del *.obj
	del *.dll
	del *.exp
	del *.lib


build_axiom:
	$(CC) $(CFLAGS) $(AXIOMSRC)\src\om\*.c $(AXIOMSRC)\src\soap\*.c $(AXIOMSRC)\src\attachments\*.c $(AXIOMSRC)\src\util\*.c /c
	$(LD) $(LDFLAGS) $(LIBS) *.obj $(AXIOM_DIST_DIR)\lib\axis2_parser.lib /DLL /OUT:$(AXIOM).dll /IMPLIB:$(AXIOM).lib
	copy $(AXIOM).dll $(AXIOM_DIST_DIR)\bin
	copy $(AXIOM).lib $(AXIOM_DIST_DIR)\lib
	del *.obj
	del *.dll
	del *.exp
	del *.lib

install: clean distdir build_axis2_parser build_axiom copy_include
	 


	






	



