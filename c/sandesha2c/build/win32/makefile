####################################################
# Makefile for Sandesha2						   #
# you can do 					                   #
# nmake dist     - distribution  (dist / samples ) #
# nmake clean  	 - clean			               #
# nmake samples  - samples 			               #
####################################################

!include configure.in
#define folders 

SANDESHASRC = ..\..
SANDESHADISTDIR = ..\sandesha2
SANDESHA2_INTDIR = .\int.msvc
SANDESHA_DLL = sandesha2

SANDESHA2_CODE = $(SANDESHASRC)\src\core\*.c \
		 $(SANDESHASRC)\src\client\*.c \
		 $(SANDESHASRC)\src\storage\beans\*.c \
		 $(SANDESHASRC)\src\storage\inmemory\*.c \
		 $(SANDESHASRC)\src\storage\*.c \
		 $(SANDESHASRC)\src\transport\*.c \
		 $(SANDESHASRC)\src\polling\*.c \
		 $(SANDESHASRC)\src\msgprocessors\*.c \
		 $(SANDESHASRC)\src\handlers\*.c \
		 $(SANDESHASRC)\src\transport\*.c \
         $(SANDESHASRC)\src\util\*.c \
 		 $(SANDESHASRC)\src\workers\*.c \
	     $(SANDESHASRC)\src\wsrm\*.c 
	     
#compiler options
CC = @cl.exe
CFLAGS = /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "AXIS2_DECLARE_EXPORT" /w /nologo \
	/I$(AXIS2_BIN_DIR)\include  /I$(SANDESHASRC)\include 

#linker options 
LD = @link.exe
LDFLAGS = /nologo /LIBPATH:$(AXIS2_BIN_DIR)\lib /LIBPATH:$(SANDESHADISTDIR)\modules\sandesha2
LIBS = axutil.lib axiom.lib axis2_parser.lib axis2_engine.lib axis2_http_receiver.lib axis2_http_sender.lib


!if "$(WITH_SQLITE)" == "1"
SANDESHA2_CODE = $(SANDESHA2_CODE) \
				$(SANDESHASRC)\src\storage\sqlite\*.c
CFLAGS = $(CFLAGS) /I$(SQLITE_SRC_DIR)
LDFLAGS = $(LDFLAGS) /LIBPATH:$(SQLITE_SRC_DIR)
LIBS = $(LIBS) sqlite3.lib
!endif

!if "$(WITH_MYSQL)" == "1"
SANDESHA2_CODE = $(SANDESHA2_CODE) \
				 $(SANDESHASRC)\src\storage\mysql\*.c
CFLAGS = $(CFLAGS) /I$(MYSQL_BIN_DIR)\include
LDFLAGS = $(LDFLAGS) /LIBPATH:$(MYSQL_BIN_DIR)\lib\opt
LIBS =$(LIBS) libmysql.lib
!endif

#debug symbols
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7
LDFLAGS = $(LDFLAGS) /DEBUG /NODEFAULTLIB:LIBCMTD.lib
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" /O2 
LDFLAGS = $(LDFLAGS) /LIBPATH:$(MYSQL_BIN_DIR)\lib\opt
!endif

#create the directory structure

distdir:
	if not exist $(SANDESHADISTDIR) mkdir $(SANDESHADISTDIR)
	if not exist $(SANDESHADISTDIR)\modules\sandesha2 mkdir $(SANDESHADISTDIR)\modules\sandesha2
	if not exist $(SANDESHADISTDIR)\include mkdir $(SANDESHADISTDIR)\include
	if not exist $(SANDESHADISTDIR)\samples mkdir $(SANDESHADISTDIR)\samples
	if not exist $(SANDESHADISTDIR)\bin\samples mkdir $(SANDESHADISTDIR)\bin\samples
	if not exist $(SANDESHADISTDIR)\services\RMSampleService mkdir $(SANDESHADISTDIR)\services\RMSampleService
	if not exist $(SANDESHADISTDIR)\config mkdir $(SANDESHADISTDIR)\config

intdir:
	if not exist $(SANDESHA2_INTDIR) mkdir $(SANDESHA2_INTDIR)
	if not exist $(SANDESHA2_INTDIR)\samples mkdir $(SANDESHA2_INTDIR)\samples
	if not exist $(SANDESHA2_INTDIR)\samples\rm_echo_1_0 mkdir $(SANDESHA2_INTDIR)\samples\rm_echo_1_0
	if not exist $(SANDESHA2_INTDIR)\samples\rm_echo_1_1 mkdir $(SANDESHA2_INTDIR)\samples\rm_echo_1_1
	if not exist $(SANDESHA2_INTDIR)\samples\rm_echo_single_1_0 mkdir $(SANDESHA2_INTDIR)\samples\rm_echo_single_1_0
	if not exist $(SANDESHA2_INTDIR)\samples\rm_echo_single_1_1 mkdir $(SANDESHA2_INTDIR)\samples\rm_echo_single_1_1
	if not exist $(SANDESHA2_INTDIR)\samples\rm_mtom_1_0 mkdir $(SANDESHA2_INTDIR)\samples\rm_mtom_1_0
	if not exist $(SANDESHA2_INTDIR)\samples\rm_ping_1_0 mkdir $(SANDESHA2_INTDIR)\samples\rm_ping_1_0 
	if not exist $(SANDESHA2_INTDIR)\samples\rm_ping_1_1 mkdir $(SANDESHA2_INTDIR)\samples\rm_Ping_1_1
	if not exist $(SANDESHA2_INTDIR)\samples\rm_report mkdir $(SANDESHA2_INTDIR)\samples\rm_report
	if not exist $(SANDESHA2_INTDIR)\samples\RMSampleService mkdir $(SANDESHA2_INTDIR)\samples\RMSampleService

clean :
	@if exist $(SANDESHADISTDIR) rmdir /S /Q $(SANDESHADISTDIR)

copy_extra:
	@copy $(SANDESHASRC)\config\sqlite_schema.bat $(SANDESHADISTDIR)
	@copy $(SANDESHASRC)\config\mysql_schema.txt $(SANDESHADISTDIR)
	@copy $(SANDESHASRC)\config\init_mysql.bat $(SANDESHADISTDIR)
	@copy $(SANDESHASRC)\LICENSE $(SANDESHADISTDIR)
	@copy $(SANDESHASRC)\README $(SANDESHADISTDIR)
	@copy $(SANDESHASRC)\INSTALL $(SANDESHADISTDIR)
	@copy $(SANDESHASRC)\NEWS $(SANDESHADISTDIR)
	
copy_samples:
	@xcopy /E $(SANDESHASRC)\samples $(SANDESHADISTDIR)\samples
	@del /s /q $(SANDESHADISTDIR)\samples\*.am
	@del /q $(SANDESHADISTDIR)\samples\*.*

copy_include:
	@xcopy /E $(SANDESHASRC)\include $(SANDESHADISTDIR)\include

sandesha2:
	$(CC) $(CFLAGS) $(SANDESHA2_CODE) /Fo$(SANDESHA2_INTDIR)\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SANDESHA2_INTDIR)\*.obj /DLL \
	/OUT:$(SANDESHADISTDIR)\modules\sandesha2\$(SANDESHA_DLL).dll /IMPLIB:$(SANDESHADISTDIR)\modules\sandesha2\$(SANDESHA_DLL).lib

copy_xml:
	@copy $(SANDESHASRC)\config\axis2.xml  $(SANDESHADISTDIR)\axis2.xml
	@copy $(SANDESHASRC)\config\module.xml $(SANDESHADISTDIR)\modules\sandesha2\module.xml
	@copy $(SANDESHASRC)\config\sqlite_schema.bat $(SANDESHADISTDIR)\config\
	

### sample clients

rm_ping_1_0:
	$(CC) $(CFLAGS) $(SANDESHASRC)\samples\rm_ping_1_0\*.c /Fo$(SANDESHA2_INTDIR)\samples\rm_ping_1_0\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SANDESHA2_INTDIR)\samples\rm_ping_1_0\*.obj $(SANDESHA_DLL).lib \
	/OUT:$(SANDESHADISTDIR)\bin\samples\rm_ping_1_0.exe

rm_ping_1_1:
	$(CC) $(CFLAGS) $(SANDESHASRC)\samples\rm_ping_1_1\*.c /Fo$(SANDESHA2_INTDIR)\samples\rm_ping_1_1\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SANDESHA2_INTDIR)\samples\rm_ping_1_0\*.obj $(SANDESHA_DLL).lib \
	/OUT:$(SANDESHADISTDIR)\bin\samples\rm_ping_1_1.exe 

rm_echo_1_0:
	$(CC) $(CFLAGS) $(SANDESHASRC)\samples\rm_echo_1_0\*.c /Fo$(SANDESHA2_INTDIR)\samples\rm_echo_1_0\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SANDESHA2_INTDIR)\samples\rm_echo_1_0\*.obj $(SANDESHA_DLL).lib \
	/OUT:$(SANDESHADISTDIR)\bin\samples\rm_echo_1_0.exe
	
rm_echo_1_1:
	$(CC) $(CFLAGS) $(SANDESHASRC)\samples\rm_echo_1_1\*.c /Fo$(SANDESHA2_INTDIR)\samples\rm_echo_1_1\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SANDESHA2_INTDIR)\samples\rm_echo_1_1\*.obj \
	$(SANDESHA_DLL).lib /OUT:$(SANDESHADISTDIR)\bin\samples\rm_echo_1_1.exe 

rm_mtom_1_0:
	$(CC) $(CFLAGS) $(SANDESHASRC)\samples\rm_mtom_1_0\*.c /Fo$(SANDESHA2_INTDIR)\samples\rm_mtom_1_0\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SANDESHA2_INTDIR)\samples\rm_mtom_1_0\*.obj $(SANDESHA_DLL).lib \
	/OUT:$(SANDESHADISTDIR)\bin\samples\rm_mtom_1_0.exe
	
rm_echo_single_1_0:
	$(CC) $(CFLAGS) $(SANDESHASRC)\samples\rm_echo_single_1_0\*.c /Fo$(SANDESHA2_INTDIR)\samples\rm_echo_single_1_0\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SANDESHA2_INTDIR)\samples\rm_echo_single_1_0\*.obj $(SANDESHA_DLL).lib \
	/OUT:$(SANDESHADISTDIR)\bin\samples\rm_echo_single_1_0.exe 

rm_echo_single_1_1:
	$(CC) $(CFLAGS) $(SANDESHASRC)\samples\rm_echo_single_1_1\*.c /Fo$(SANDESHA2_INTDIR)\samples\rm_echo_single_1_1\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SANDESHA2_INTDIR)\samples\rm_echo_single_1_1\*.obj \
	$(SANDESHA_DLL).lib /OUT:$(SANDESHADISTDIR)\bin\samples\rm_echo_single_1_1.exe
	
rm_report:
	$(CC) $(CFLAGS) $(SANDESHASRC)\samples\rm_report\*.c /Fo$(SANDESHA2_INTDIR)\samples\rm_report\ /c
	$(LD) $(LDFLAGS) $(LIBS) $(SANDESHA2_INTDIR)\samples\rm_report\*.obj \
	$(SANDESHA_DLL).lib /OUT:$(SANDESHADISTDIR)\bin\samples\rm_report.exe
	

all_clients: rm_ping_1_0 rm_ping_1_1 rm_echo_1_1 rm_echo_1_0 rm_mtom_1_0 rm_echo_single_1_0 rm_echo_single_1_1 rm_report


#### services
RMSampleService:
	$(CC) $(CFLAGS) $(SANDESHASRC)\samples\RMSampleService\*.c /Fo$(SANDESHA2_INTDIR)\samples\RMSampleService\ /c
	$(LD) $(LDFLAGS) $(SANDESHA2_INTDIR)\samples\RMSampleService\*.obj $(LIBS) /DLL \
	/OUT:$(SANDESHADISTDIR)\services\RMSampleService\RMSampleService.dll
	
	@copy $(SANDESHASRC)\samples\RMSampleService\services.xml $(SANDESHADISTDIR)\services\RMSampleService

all_services: RMSampleService

samples: all_clients all_services

dist: clean distdir intdir sandesha2 copy_samples samples copy_xml copy_include copy_extra


	 


	






	



