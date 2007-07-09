####################################################
# Makefile for savan c							   #
# you can do 					                   #
# nmake dist     - distribution  (dist / samples ) #
# nmake clean  	 - clean			               #
# nmake samples  - samples 			               #
####################################################

AUTOCONF = configure.in
!include $(AUTOCONF)

#define folders 

SAVANSRC = ..\..
SAVANDISTDIR = ..\savanc
SAVANINTDIR = .\int.msvc
SAVANDLL = mod_savan

SAVAN_CODE = $(SAVANSRC)\src\core\*.c \
		 $(SAVANSRC)\src\client\*.c \
		 $(SAVANSRC)\src\handlers\*.c \
		 $(SAVANSRC)\src\util\*.c \
		 $(SAVANSRC)\src\subscribers\*.c \
		 $(SAVANSRC)\src\msgreceivers\*.c 
		
		 
	     
#compiler options
CC = @cl.exe
CFLAGS = /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "AXIS2_DECLARE_EXPORT" /w /nologo \
	/I$(AXIS2_BIN_DIR)\include  /I$(SAVANSRC)\include 

#linker options 
LD = @link.exe
LDFLAGS = /nologo /LIBPATH:$(AXIS2_BIN_DIR)\lib /LIBPATH:$(SAVANDISTDIR)\modules\savan
LIBS = axutil.lib axiom.lib axis2_parser.lib axis2_engine.lib axis2_http_receiver.lib axis2_http_sender.lib

#debug symbols
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7
LDFLAGS = $(LDFLAGS) /DEBUG /NODEFAULTLIB:LIBCMTD.lib
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" /O2 
LDFLAGS = $(LDFLAGS)
!endif

#create the directory structure

distdir:
	if not exist $(SAVANDISTDIR) mkdir $(SAVANDISTDIR)
	if not exist $(SAVANDISTDIR)\modules\savan mkdir $(SAVANDISTDIR)\modules\savan
	if not exist $(SAVANDISTDIR)\include mkdir $(SAVANDISTDIR)\include
	if not exist $(SAVANDISTDIR)\samples mkdir $(SAVANDISTDIR)\samples
	if not exist $(SAVANDISTDIR)\bin\samples mkdir $(SAVANDISTDIR)\bin\samples
	if not exist $(SAVANDISTDIR)\bin\samples\savan mkdir $(SAVANDISTDIR)\bin\samples\savan
	if not exist $(SAVANDISTDIR)\services\listener mkdir $(SAVANDISTDIR)\services\listener
	if not exist $(SAVANDISTDIR)\services\publisher mkdir $(SAVANDISTDIR)\services\publisher

intdir:
	if not exist $(SAVANINTDIR) mkdir $(SAVANINTDIR)
	if not exist $(SAVANINTDIR)\samples mkdir $(SAVANINTDIR)\samples
	if not exist $(SAVANINTDIR)\samples\subscriber mkdir $(SAVANINTDIR)\samples\subscriber
	if not exist $(SAVANINTDIR)\samples\listener mkdir $(SAVANINTDIR)\samples\listener
	if not exist $(SAVANINTDIR)\samples\publisher mkdir $(SAVANINTDIR)\samples\publisher

clean :
	@if exist $(SAVANDISTDIR) rmdir /S /Q $(SAVANDISTDIR)
	@if exist int.msvc rmdir /S /Q int.msvc

copy_extra:
	@copy $(SAVANSRC)\README $(SAVANDISTDIR)
	@copy $(SAVANSRC)\NEWS $(SAVANDISTDIR)
	
copy_samples:
	@xcopy /E $(SAVANSRC)\samples $(SAVANDISTDIR)\samples
	@del /s /q $(SAVANDISTDIR)\samples\*.am
	@del /q $(SAVANDISTDIR)\samples\*.*

copy_include:
	@xcopy /E $(SAVANSRC)\include $(SAVANDISTDIR)\include

savan:
	$(CC) $(CFLAGS) $(SAVAN_CODE) /Fo$(SAVANINTDIR)\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SAVANINTDIR)\*.obj /DLL \
	/OUT:$(SAVANDISTDIR)\modules\savan\$(SAVANDLL).dll /IMPLIB:$(SAVANDISTDIR)\modules\savan\$(SAVANDLL).lib
	@copy $(SAVANSRC)\src\data\module.xml $(SAVANDISTDIR)\modules\savan\module.xml
	

###samples

publisher:
	$(CC) $(CFLAGS) $(SAVANSRC)\samples\server\publisher\*.c /Fo$(SAVANINTDIR)\samples\publisher\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SAVANINTDIR)\samples\publisher\*.obj $(SAVANDLL).lib /DLL \
	/OUT:$(SAVANDISTDIR)\services\publisher\publisher.dll
	@copy $(SAVANSRC)\samples\server\publisher\services.xml $(SAVANDISTDIR)\services\publisher\

listener:
	$(CC) $(CFLAGS) $(SAVANSRC)\samples\server\listener\*.c /Fo$(SAVANINTDIR)\samples\listener\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SAVANINTDIR)\samples\listener\*.obj $(SAVANDLL).lib /DLL \
	/OUT:$(SAVANDISTDIR)\services\listener\listener.dll
	@copy $(SAVANSRC)\samples\server\listener\services.xml $(SAVANDISTDIR)\services\listener\

subscriber:
	$(CC) $(CFLAGS) $(SAVANSRC)\samples\client\subscriber\*.c /Fo$(SAVANINTDIR)\samples\subscriber\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SAVANINTDIR)\samples\subscriber\*.obj $(SAVANDLL).lib \
	/OUT:$(SAVANDISTDIR)\bin\samples\savan\subscriber.exe
	
dist: clean distdir intdir savan publisher listener subscriber copy_include copy_samples copy_extra


	 


	






	



