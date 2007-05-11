
AUTOCONF = configure.in
!include $(AUTOCONF)

RAMPART = rampart
RAMPART_SOURCE_DIR = ..\..\

RAMPART_INTDIR = .\int.msvc
RAMPART_DIST_NAME = .\..\rampartc-$(MAJOR_VER).$(MINOR_VER)
#RAMPART_DISTDIR = .\..\rampartc
RAMPART_DISTDIR = $(RAMPART_DIST_NAME)

#rampart module

OMXMLSEC_SRC = $(RAMPART_SOURCE_DIR)\src\omxmlsec\*.c \
    	       $(RAMPART_SOURCE_DIR)\src\omxmlsec\tokens\*.c \
    	       $(RAMPART_SOURCE_DIR)\src\omxmlsec\c14n\*.c \
    	       $(RAMPART_SOURCE_DIR)\src\omxmlsec\openssl\*.c

SECPOLICY_SRC = $(RAMPART_SOURCE_DIR)\src\secpolicy\builder\*.c \
    	       $(RAMPART_SOURCE_DIR)\src\secpolicy\model\*.c 

MOD_RAMPART_SRC = $(RAMPART_SOURCE_DIR)\src\core\*.c \
		$(RAMPART_SOURCE_DIR)\src\handlers\*.c \
		$(RAMPART_SOURCE_DIR)\src\util\*.c

MOD_RAMPART_INCLUDE_PATH = /I$(RAMPART_SOURCE_DIR)\include \
		           /I$(OPENSSL_BIN_DIR)\include \
			   /I$(AXIS2_BIN_DIR)\include

APPLINK_FILE = $(OPENSSL_BIN_DIR)\include\openssl\applink.c

AXIS2_LIBS = $(AXIS2_BIN_DIR)\lib
AXIS2_MODS = $(AXIS2_BIN_DIR)\modules

##################### compiler options

CC = @cl.exe 
CFLAGS = /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "AXIS2_DECLARE_EXPORT"  \
	 /D "AXIS2_SVR_MULTI_THREADED" /w /nologo $(AXIS2_INCLUDE_PATH) 

################### linker options

LD = @link.exe
LDFLAGS = /nologo /LIBPATH:$(AXIS2_LIBS) /LIBPATH:$(OPENSSL_BIN_DIR)\lib\VC \
	  /LIBPATH:$(AXIS2_BIN_DIR)\lib


#debug symbols
!if "$(DEBUG)" == "1"
LIBS = $(LIBS) libeay32MTd.lib ssleay32MTd.lib
!else
LIBS = $(LIBS) libeay32MT.lib ssleay32MT.lib
!endif

#################### debug symbol

!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7
LDFLAGS = $(LDFLAGS) /DEBUG /NODEFAULTLIB:LIBCMTD.lib 
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" /O2 /MT
LDFLAGS = $(LDFLAGS)
!endif

#################### hack!
CFLAGS = $(CFLAGS) /D "_WINSOCKAPI_"

distdir:
	if not exist $(RAMPART_DISTDIR) mkdir $(RAMPART_DISTDIR)
	mkdir $(RAMPART_DISTDIR)\bin\samples\callback
	mkdir $(RAMPART_DISTDIR)\bin\samples\authn_provider
	mkdir $(RAMPART_DISTDIR)\bin\samples\services\sec_echo
	mkdir $(RAMPART_DISTDIR)\bin\samples\client\sec_echo
	mkdir $(RAMPART_DISTDIR)\bin\samples\client\sec_echo\data
	mkdir $(RAMPART_DISTDIR)\bin\samples\credential_provider
	mkdir $(RAMPART_DISTDIR)\modules\rampart
	mkdir $(RAMPART_DISTDIR)\include

clean: 
	if exist $(RAMPART_DISTDIR) rmdir /S /Q $(RAMPART_DISTDIR)
	if exist $(RAMPART_INTDIR)  rmdir /S /Q $(RAMPART_INTDIR)

intdirs:
	if not exist $(RAMPART_INTDIR) mkdir $(RAMPART_INTDIR)

	if not exist $(RAMPART_INTDIR)\samples\callback\pwcb mkdir $(RAMPART_INTDIR)\samples\callback\pwcb
	if not exist $(RAMPART_INTDIR)\samples\authn_provider mkdir $(RAMPART_INTDIR)\samples\authn_provider
	if not exist $(RAMPART_INTDIR)\samples\services\sec_echo\ mkdir $(RAMPART_INTDIR)\samples\services\sec_echo
	if not exist $(RAMPART_INTDIR)\samples\client\sec_echo\ mkdir $(RAMPART_INTDIR)\samples\client\sec_echo
	if not exist $(RAMPART_INTDIR)\samples\credential_provider\ mkdir $(RAMPART_INTDIR)\samples\credential_provider

mod_rampart:
	$(CC) $(CFLAGS) $(MOD_RAMPART_INCLUDE_PATH) $(MOD_RAMPART_SRC) $(OMXMLSEC_SRC) $(SECPOLICY_SRC) $(APPLINK_FILE) /Fo$(RAMPART_INTDIR)\ /c
	$(LD) $(LDFLAGS) $(RAMPART_INTDIR)\*.obj \
	      $(LIBS) axutil.lib axiom.lib axis2_parser.lib axis2_engine.lib \
              /DLL /OUT:$(RAMPART_DISTDIR)\modules\rampart\mod_rampart.dll /IMPLIB:$(RAMPART_DISTDIR)\modules\rampart\mod_rampart.lib
	
	copy $(RAMPART_SOURCE_DIR)\src\data\module.xml $(RAMPART_DISTDIR)\modules\rampart


mod_rampart_pwcb:
	$(CC) $(CFLAGS) $(MOD_RAMPART_INCLUDE_PATH) $(RAMPART_SOURCE_DIR)\samples\callback\pwcb.c /Fo$(RAMPART_INTDIR)\samples\callback\ /c
	$(LD) $(LDFLAGS) $(LIBS) axutil.lib $(RAMPART_INTDIR)\samples\callback\*.obj /DLL /OUT:$(RAMPART_DISTDIR)\bin\samples\callback\pwcb.dll \
	      /IMPLIB:$(RAMPART_DISTDIR)\bin\samples\callback\pwcb.lib


mod_rampart_authn: 
	$(CC) $(CFLAGS) $(MOD_RAMPART_INCLUDE_PATH) $(RAMPART_SOURCE_DIR)\samples\authn_provider\authn_provider.c \
	      /Fo$(RAMPART_INTDIR)\samples\authn_provider\ /c
	$(LD) $(LDFLAGS) $(RAMPART_INTDIR)\samples\authn_provider\*.obj mod_rampart.lib axutil.lib /LIBPATH:$(RAMPART_DISTDIR)\modules\rampart /DLL \
	      /OUT:$(RAMPART_DISTDIR)\bin\samples\authn_provider\authn.dll

mod_rampart_services_sec_echo:
	$(CC) $(CFLAGS) $(MOD_RAMPART_INCLUDE_PATH) /I$(RAMPART_SOURCE_DIR)\samples\server\sec_echo \
	      $(RAMPART_SOURCE_DIR)\samples\server\sec_echo\*.c \
	      /Fo$(RAMPART_INTDIR)\samples\services\sec_echo\ /c
	$(LD) $(LDFLAGS) $(RAMPART_INTDIR)\samples\services\sec_echo\*.obj \
	      axutil.lib axiom.lib axis2_parser.lib $(LIBS) axis2_engine.lib \
	      axis2_http_receiver.lib axis2_http_sender.lib \
              /DLL /OUT:$(RAMPART_DISTDIR)\bin\samples\services\sec_echo\sec_echo.dll
	
	copy $(RAMPART_SOURCE_DIR)\samples\server\sec_echo\services.xml $(RAMPART_DISTDIR)\bin\samples\services\sec_echo\

mod_rampart_samples_sec_echo:
	$(CC) $(CFLAGS) $(MOD_RAMPART_INCLUDE_PATH) \
	      $(RAMPART_SOURCE_DIR)\samples\client\sec_echo\echo.c \
	      /Fo$(RAMPART_INTDIR)\samples\client\sec_echo\ /c
	$(LD) $(LDFLAGS) $(RAMPART_INTDIR)\samples\client\sec_echo\echo.obj axutil.lib axiom.lib \
	      axis2_parser.lib axis2_engine.lib /OUT:$(RAMPART_DISTDIR)\bin\samples\client\sec_echo\echo.exe
	
	copy $(RAMPART_SOURCE_DIR)\samples\client\sec_echo\deploy_client_repo.bat $(RAMPART_DISTDIR)\bin\samples\client\sec_echo\
	
	copy $(RAMPART_SOURCE_DIR)\samples\client\sec_echo\data\client.axis2.xml $(RAMPART_DISTDIR)\bin\samples\client\sec_echo\data\
	
mod_rampart_samples_credential_provider:
	$(CC) $(CFLAGS) $(MOD_RAMPART_INCLUDE_PATH) \
	      $(RAMPART_SOURCE_DIR)\samples\credential_provider\*.c \
	      /Fo$(RAMPART_INTDIR)\samples\credential_provider\ /c
	$(LD) $(LDFLAGS) $(RAMPART_INTDIR)\samples\credential_provider\cred_provider.obj \
	      axutil.lib axiom.lib axis2_parser.lib $(LIBS) axis2_engine.lib \
	      axis2_http_receiver.lib axis2_http_sender.lib \
              /DLL /OUT:$(RAMPART_DISTDIR)\bin\samples\credential_provider\cred_provider.dll

mod_rampart_samples: mod_rampart_samples_sec_echo mod_rampart_services_sec_echo

mod_rampart_copy_include:
	xcopy /E /I /Y $(RAMPART_SOURCE_DIR)\include $(RAMPART_DISTDIR)\include

mod_rampart_copy_keys:
	if not exist $(RAMPART_DISTDIR)\bin\samples\keys mkdir $(RAMPART_DISTDIR)\bin\samples\keys
	xcopy /E /I /Y $(RAMPART_SOURCE_DIR)\samples\keys\* $(RAMPART_DISTDIR)\bin\samples\keys

mod_rampart_copy_deploy:
	copy deploy_rampart.bat $(RAMPART_DISTDIR)

copy_sec_policy:
	xcopy /E /I /Y $(RAMPART_SOURCE_DIR)\samples\secpolicy $(RAMPART_DISTDIR)\bin\samples\secpolicy

copy_dist_files:
	copy $(RAMPART_SOURCE_DIR)\README $(RAMPART_DISTDIR)
	copy $(RAMPART_SOURCE_DIR)\INSTALL $(RAMPART_DISTDIR)
	copy $(RAMPART_SOURCE_DIR)\AUTHORS $(RAMPART_DISTDIR)
	copy $(RAMPART_SOURCE_DIR)\COPYING $(RAMPART_DISTDIR)
	copy $(RAMPART_SOURCE_DIR)\LICENSE $(RAMPART_DISTDIR)
	copy $(RAMPART_SOURCE_DIR)\NEWS $(RAMPART_DISTDIR)
	copy $(RAMPART_SOURCE_DIR)\NOTICE $(RAMPART_DISTDIR)


#copy make_bin_dist.bat $(RAMPART_DISTDIR)

mod_rampart_all: mod_rampart mod_rampart_authn mod_rampart_pwcb mod_rampart_htpwcb mod_rampart_samples mod_rampart_copy_include copy_dist_files

mv_dist:
	move $(RAMPART_DISTDIR) $(RAMPART_DIST_NAME)

del_am:
	chdir $(RAMPART_DISTDIR)
	del /s *.am
	chdir .\..\win32

dist: clean distdir intdirs mod_rampart mod_rampart_pwcb mod_rampart_authn mod_rampart_services_sec_echo mod_rampart_samples_sec_echo mod_rampart_samples_credential_provider mod_rampart_copy_deploy copy_sec_policy mod_rampart_copy_include copy_dist_files mod_rampart_copy_keys del_am

deploy:
	chdir $(RAMPART_DISTDIR)
	deploy_rampart.bat
	chdir .\..\win32

install: dist deploy




