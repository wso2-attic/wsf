
AUTOCONF = configure.in_win32
!include $(AUTOCONF)

ADMIN_SVC_SRCDIR = .\ 
ADMIN_SVC_BUILDDIR = .\build
ADMIN_SVC_INTDIR = $(ADMIN_SVC_BUILDDIR)\intmsvc
ADMIN_SVC_DISTDIR = $(ADMIN_SVC_BUILDDIR)\services
ADMIN_MOD_DISTDIR = $(ADMIN_SVC_BUILDDIR)\modules
ADMIN_DISTDIR = $(ADMIN_SVC_BUILDDIR)\wso2-wsf-admin-bin-m1-win32

INCLUDE_PATH = /I$(OPENSSL_BIN_DIR)\include /I$(WSFC_HOME_DIR)\include /I$(WSFC_HOME_DIR)/../include /I$(ADMIN_SVC_SRCDIR)\include \
	       /I$(BAM_PUBLISHER_SRC)\module\codegen /I$(BAM_PUBLISHER_SRC)\module 

LIBS_PATH = /LIBPATH:$(WSFC_HOME_DIR)\lib /LIBPATH:$(OPENSSL_BIN_DIR)\lib\VC


## Packaged Service Names

AUTH_SERVICE=AuthenticationAdminService
SERVER_ADMIN_SERVICE=ServerAdmin
OP_ADMIN_SERVICE=OperationAdmin
SERVICE_ADMIN_SERVICE=ServiceAdmin
SERVICE_GRP_ADMIN_SERVICE=ServiceGroupAdmin
SECURITY_ADMIN_SERVICE=SecurityAdminService
USER_MANAGER_SERVICE=UserManagementService
KEYSTORE_ADMIN_SERVICE = KeyStoreAdminService
TRANSPORT_ADMIN_SERVICE=TransportAdmin

## Service Code SRC
AUTH_SVC_SRC=$(ADMIN_SVC_SRCDIR)\authentication
SERVER_ADMIN_SRC=$(ADMIN_SVC_SRCDIR)\server_admin
SERVICE_ADMIN_SRC=$(ADMIN_SVC_SRCDIR)\service_admin
SERVICE_ADMIN_UTIL_SRC=$(ADMIN_SVC_SRCDIR)\util
SECURITY_ADMIN_SVC_SRC=$(ADMIN_SVC_SRCDIR)\security_admin_service
USER_MANAGER_SVC_SRC=$(ADMIN_SVC_SRCDIR)\usermanager
KEYSTORE_ADMIN_SVC_SRC=$(ADMIN_SVC_SRCDIR)\keystore_admin
TRANSPORT_ADMIN_SVC_SRC=$(ADMIN_SVC_SRCDIR)\transport_admin

##################### compiler options

CC = cl.exe 
CFLAGS = /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "AXIS2_DECLARE_EXPORT"   \
	 /D "AXIS2_SVR_MULTI_THREADED" /w /nologo $(INCLUDE_PATH) 

################### linker options

LD = link.exe
LDFLAGS = /nologo $(LIBS_PATH)

LIBS = axutil.lib axiom.lib axis2_engine.lib axis2_parser.lib neethi.lib neethi_util.lib rampart.lib


SSL_LIB_FLAG = MD
!if "$(CRUNTIME)" == "/MT"
SSL_LIB_FLAG = MT
!endif

####################
MT=mt.exe
MT="$(MT)"

!if "$(EMBED_MANIFEST)" == "0"
_VC_MANIFEST_EMBED_EXE=
_VC_MANIFEST_EMBED_DLL=
!else
_VC_MANIFEST_EMBED_EXE= if exist $@.manifest $(MT) -nologo -manifest $@.manifest -outputresource:$@;1
_VC_MANIFEST_EMBED_DLL= if exist $@.manifest $(MT) -nologo -manifest $@.manifest -outputresource:$@;2
!endif


#################### debug symbol

!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG" /Od /Z7 $(CRUNTIME)d
LDFLAGS = $(LDFLAGS) /DEBUG
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" /O2 $(CRUNTIME)
LDFLAGS = $(LDFLAGS)
!endif

#debug symbols
!if "$(DEBUG)" == "1"
LIBS = $(LIBS) libeay32$(SSL_LIB_FLAG)d.lib ssleay32$(SSL_LIB_FLAG)d.lib
!else
LIBS = $(LIBS) libeay32$(SSL_LIB_FLAG).lib ssleay32$(SSL_LIB_FLAG).lib
!endif

#################### hack!
#CFLAGS = $(CFLAGS) /D "_WINSOCKAPI_"

distdir:
	if not exist $(ADMIN_SVC_BUILDDIR) mkdir $(ADMIN_SVC_BUILDDIR)
	if not exist $(ADMIN_SVC_DISTDIR) mkdir $(ADMIN_SVC_DISTDIR)
	if not exist $(ADMIN_MOD_DISTDIR) mkdir $(ADMIN_MOD_DISTDIR)
	if not exist $(ADMIN_SVC_DISTDIR)\$(AUTH_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(AUTH_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(SERVER_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(SERVER_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(SERVICE_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(SERVICE_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(SERVICE_GRP_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(SERVICE_GRP_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(OP_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(OP_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(SECURITY_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(SECURITY_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(USER_MANAGER_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(USER_MANAGER_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(KEYSTORE_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(KEYSTORE_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(TRANSPORT_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(TRANSPORT_ADMIN_SERVICE)
	

clean: 
	if exist $(ADMIN_SVC_BUILDDIR) rmdir /S /Q $(ADMIN_SVC_BUILDDIR)
	
intdirs:
	if not exist $(ADMIN_SVC_BUILDDIR) mkdir $(ADMIN_SVC_BUILDDIR) 
	if not exist $(ADMIN_SVC_INTDIR) mkdir $(ADMIN_SVC_INTDIR)
	if not exist $(ADMIN_SVC_INTDIR)\$(AUTH_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(AUTH_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(SERVER_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(SERVER_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(SERVICE_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(SERVICE_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(SERVICE_GRP_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(SERVICE_GRP_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(OP_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(OP_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(SECURITY_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(SECURITY_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(USER_MANAGER_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(USER_MANAGER_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(KEYSTORE_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(KEYSTORE_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(TRANSPORT_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(TRANSPORT_ADMIN_SERVICE)


$(ADMIN_SVC_DISTDIR)\$(AUTH_SERVICE)\$(AUTH_SERVICE).dll: $(AUTH_SVC_SRC)\codegen\*.c $(AUTH_SVC_SRC)\*.c
	$(CC) $(CFLAGS) /I $(AUTH_SVC_SRC) $(AUTH_SVC_SRC)\codegen\*.c \
		$(AUTH_SVC_SRC)\*.c /Fo$(ADMIN_SVC_INTDIR)\$(AUTH_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(AUTH_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(AUTH_SERVICE)\$(AUTH_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(AUTH_SVC_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(AUTH_SERVICE)\ 
	copy $(AUTH_SVC_SRC)\resources\$(AUTH_SERVICE).wsdl $(ADMIN_SVC_DISTDIR)\$(AUTH_SERVICE)\

authentication_service : $(ADMIN_SVC_DISTDIR)\$(AUTH_SERVICE)\$(AUTH_SERVICE).dll

$(ADMIN_SVC_DISTDIR)\$(SERVER_ADMIN_SERVICE)\$(SERVER_ADMIN_SERVICE).dll: $(SERVER_ADMIN_SRC)\codegen\*.c $(SERVER_ADMIN_SRC)\*.c
	$(CC) $(CFLAGS) $(SERVER_ADMIN_SRC)\codegen\*.c \
	$(SERVER_ADMIN_SRC)\*.c $(SERVICE_ADMIN_UTIL_SRC)\*.c /Fo$(ADMIN_SVC_INTDIR)\$(SERVER_ADMIN_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(SERVER_ADMIN_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(SERVER_ADMIN_SERVICE)\$(SERVER_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	
	copy $(SERVER_ADMIN_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(SERVER_ADMIN_SERVICE)\

	copy $(SERVER_ADMIN_SRC)\resources\$(SERVER_ADMIN_SERVICE).wsdl $(ADMIN_SVC_DISTDIR)\$(SERVER_ADMIN_SERVICE)\

server_admin_service : $(ADMIN_SVC_DISTDIR)\$(SERVER_ADMIN_SERVICE)\$(SERVER_ADMIN_SERVICE).dll


#==================================================================================
#Proxy Admin Service 
#==================================================================================
PROXY_ADMIN_SERVICE = ProxyServiceAdmin
PROXY_ADMIN_DISTDIR = $(ADMIN_SVC_DISTDIR)\$(PROXY_ADMIN_SERVICE)
PROXY_ADMIN_INTDIR = $(ADMIN_SVC_INTDIR)\$(PROXY_ADMIN_SERVICE)
PROXY_ADMIN_SRC = 	$(ADMIN_SVC_SRCDIR)\proxy_admin\codegen\*.c \
					$(ADMIN_SVC_SRCDIR)\proxy_admin\*.c

proxy_admin: $(PROXY_ADMIN_SRC)
	if not exist $(PROXY_ADMIN_DISTDIR) mkdir $(PROXY_ADMIN_DISTDIR)
	if not exist $(PROXY_ADMIN_INTDIR) mkdir $(PROXY_ADMIN_INTDIR)
	$(CC) $(CFLAGS) $(PROXY_ADMIN_SRC) /Fo$(PROXY_ADMIN_INTDIR)\ /c
	$(LD) $(LDFLAGS) $(PROXY_ADMIN_INTDIR)\*.obj $(LIBS) esb.lib /DLL \
		/OUT:$(PROXY_ADMIN_DISTDIR)\$(PROXY_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(ADMIN_SVC_SRCDIR)\proxy_admin\resources\services.xml $(PROXY_ADMIN_DISTDIR)
	
#==============================================================================================
OP_ADMIN_SRC=$(ADMIN_SVC_SRCDIR)\operation_admin

$(ADMIN_SVC_DISTDIR)\$(OP_ADMIN_SERVICE)\$(OP_ADMIN_SERVICE).dll : 
	$(CC) $(CFLAGS) $(OP_ADMIN_SRC)\codegen\*.c $(OP_ADMIN_SRC)\*.c $(SERVICE_ADMIN_UTIL_SRC)\*.c /Fo$(ADMIN_SVC_INTDIR)\$(OP_ADMIN_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(OP_ADMIN_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(OP_ADMIN_SERVICE)\$(OP_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(OP_ADMIN_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(OP_ADMIN_SERVICE)\

	copy $(OP_ADMIN_SRC)\resources\$(OP_ADMIN_SERVICE).wsdl $(ADMIN_SVC_DISTDIR)\$(OP_ADMIN_SERVICE)\

op_admin_service: $(ADMIN_SVC_DISTDIR)\$(OP_ADMIN_SERVICE)\$(OP_ADMIN_SERVICE).dll

#=====================================================================================================
STAT_ADMIN_SERVICE=StatisticsAdmin
STAT_ADMIN_SRC=$(ADMIN_SVC_SRCDIR)\statistics_admin\service

$(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)\$(STAT_ADMIN_SERVICE).dll : 
    if not exist $(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_SERVICE)
    if not exist $(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)
	$(CC) $(CFLAGS) $(STAT_ADMIN_SRC)\codegen\*.c $(STAT_ADMIN_SRC)\*.c $(SERVICE_ADMIN_UTIL_SRC)\*.c /Fo$(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)\$(STAT_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(STAT_ADMIN_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)\

	copy $(STAT_ADMIN_SRC)\resources\$(STAT_ADMIN_SERVICE).wsdl $(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)\

stat_admin_service: $(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)\$(STAT_ADMIN_SERVICE).dll

#=======================================================================================================
#module admin service
MODULE_ADMIN_SERVICE=ModuleAdminService
MODULE_ADMIN_SRC=$(ADMIN_SVC_SRCDIR)\module_admin

$(ADMIN_SVC_DISTDIR)\$(MODULE_ADMIN_SERVICE)\$(MODULE_ADMIN_SERVICE).dll : 
    if not exist $(ADMIN_SVC_INTDIR)\$(MODULE_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(MODULE_ADMIN_SERVICE)
    if not exist $(ADMIN_SVC_DISTDIR)\$(MODULE_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(MODULE_ADMIN_SERVICE)
	$(CC) $(CFLAGS) $(MODULE_ADMIN_SRC)\codegen\*.c $(MODULE_ADMIN_SRC)\*.c $(SERVICE_ADMIN_UTIL_SRC)\*.c /Fo$(ADMIN_SVC_INTDIR)\$(MODULE_ADMIN_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(MODULE_ADMIN_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(MODULE_ADMIN_SERVICE)\$(MODULE_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(MODULE_ADMIN_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(MODULE_ADMIN_SERVICE)\

	copy $(MODULE_ADMIN_SRC)\resources\$(MODULE_ADMIN_SERVICE).wsdl $(ADMIN_SVC_DISTDIR)\$(MODULE_ADMIN_SERVICE)\

module_admin_service: $(ADMIN_SVC_DISTDIR)\$(MODULE_ADMIN_SERVICE)\$(MODULE_ADMIN_SERVICE).dll

#=======================================================================================================
#statistics module

STAT_ADMIN_MODULE=statistics
STAT_ADMIN_MODULE_SRC=$(ADMIN_SVC_SRCDIR)\statistics_admin\module

$(ADMIN_MOD_DISTDIR)\$(STAT_ADMIN_MODULE)\$(STAT_ADMIN_MODULE).dll :
	if not exist $(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_MODULE) mkdir $(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_MODULE)
	if not exist $(ADMIN_MOD_DISTDIR)\$(STAT_ADMIN_MODULE) mkdir $(ADMIN_MOD_DISTDIR)\$(STAT_ADMIN_MODULE)
	$(CC) $(CFLAGS) $(STAT_ADMIN_MODULE_SRC)\*.c $(SERVICE_ADMIN_UTIL_SRC)\*.c /Fo$(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_MODULE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_MODULE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_MOD_DISTDIR)\$(STAT_ADMIN_MODULE)\$(STAT_ADMIN_MODULE).dll
		-@$(_VC_MANIFEST_EMBED_DLL)
		copy $(STAT_ADMIN_MODULE_SRC)\module.xml $(ADMIN_MOD_DISTDIR)\$(STAT_ADMIN_MODULE)\
		
stat_admin_module : $(ADMIN_MOD_DISTDIR)\$(STAT_ADMIN_MODULE)\$(STAT_ADMIN_MODULE).dll

#=====================================================================================================
$(ADMIN_SVC_DISTDIR)\$(SERVICE_ADMIN_SERVICE)\$(SERVICE_ADMIN_SERVICE).dll: 	
	$(CC) $(CFLAGS) $(SERVICE_ADMIN_SRC)\codegen\*.c \
		$(SERVICE_ADMIN_SRC)\*.c $(SERVICE_ADMIN_UTIL_SRC)\*.c /Fo$(ADMIN_SVC_INTDIR)\$(SERVICE_ADMIN_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(SERVICE_ADMIN_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(SERVICE_ADMIN_SERVICE)\$(SERVICE_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(SERVICE_ADMIN_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(SERVICE_ADMIN_SERVICE)\

service_admin_service : $(ADMIN_SVC_DISTDIR)\$(SERVICE_ADMIN_SERVICE)\$(SERVICE_ADMIN_SERVICE).dll

#=====================================================================================================
SERVICE_GRP_ADMIN_SRC=$(ADMIN_SVC_SRCDIR)\service_group_admin

$(ADMIN_SVC_DISTDIR)\$(SERVICE_GRP_ADMIN_SERVICE)\$(SERVICE_GRP_ADMIN_SERVICE).dll: 	
	$(CC) $(CFLAGS) $(SERVICE_GRP_ADMIN_SRC)\codegen\*.c $(SERVICE_ADMIN_UTIL_SRC)\*.c $(SERVICE_GRP_ADMIN_SRC)\*.c \
		/Fo$(ADMIN_SVC_INTDIR)\$(SERVICE_GRP_ADMIN_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(SERVICE_GRP_ADMIN_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(SERVICE_GRP_ADMIN_SERVICE)\$(SERVICE_GRP_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(SERVICE_GRP_ADMIN_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(SERVICE_GRP_ADMIN_SERVICE)\

service_grp_admin_service: $(ADMIN_SVC_DISTDIR)\$(SERVICE_GRP_ADMIN_SERVICE)\$(SERVICE_GRP_ADMIN_SERVICE).dll
#=====================================================================================================
$(ADMIN_SVC_DISTDIR)\$(SECURITY_ADMIN_SERVICE)\$(SECURITY_ADMIN_SERVICE).dll: $(SECURITY_ADMIN_SVC_SRC)\codegen\*.c $(SECURITY_ADMIN_SVC_SRC)\*.c
	$(CC) $(CFLAGS) $(SECURITY_ADMIN_SVC_SRC)\codegen\*.c $(SECURITY_ADMIN_SVC_SRC)\*.c \
		$(SERVICE_ADMIN_UTIL_SRC)\security_admin_util.c \
		/Fo$(ADMIN_SVC_INTDIR)\$(SECURITY_ADMIN_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(SECURITY_ADMIN_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(SECURITY_ADMIN_SERVICE)\$(SECURITY_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	if not exist $(ADMIN_SVC_DISTDIR)\$(SECURITY_ADMIN_SERVICE)\policies mkdir $(ADMIN_SVC_DISTDIR)\$(SECURITY_ADMIN_SERVICE)\policies
	copy $(SECURITY_ADMIN_SVC_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(SECURITY_ADMIN_SERVICE)
	copy $(SECURITY_ADMIN_SVC_SRC)\resources\scenario-config.xml $(ADMIN_SVC_DISTDIR)\$(SECURITY_ADMIN_SERVICE)
	copy $(SECURITY_ADMIN_SVC_SRC)\resources\scenario*-policy.xml $(ADMIN_SVC_DISTDIR)\$(SECURITY_ADMIN_SERVICE)\policies\

security_admin_service: $(ADMIN_SVC_DISTDIR)\$(SECURITY_ADMIN_SERVICE)\$(SECURITY_ADMIN_SERVICE).dll
#=====================================================================================================
$(ADMIN_SVC_DISTDIR)\$(USER_MANAGER_SERVICE)\$(USER_MANAGER_SERVICE).dll: $(USER_MANAGER_SVC_SRC)\codegen\*.c $(USER_MANAGER_SVC_SRC)\*.c
	$(CC) $(CFLAGS) $(USER_MANAGER_SVC_SRC)\codegen\*.c $(USER_MANAGER_SVC_SRC)\*.c \
		/Fo$(ADMIN_SVC_INTDIR)\$(USER_MANAGER_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(USER_MANAGER_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(USER_MANAGER_SERVICE)\$(USER_MANAGER_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(USER_MANAGER_SVC_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(USER_MANAGER_SERVICE)

user_manager_service: $(ADMIN_SVC_DISTDIR)\$(USER_MANAGER_SERVICE)\$(USER_MANAGER_SERVICE).dll
#=====================================================================================================
$(ADMIN_SVC_DISTDIR)\$(KEYSTORE_ADMIN_SERVICE)\$(KEYSTORE_ADMIN_SERVICE).dll: $(KEYSTORE_ADMIN_SVC_SRC)\codegen\*.c $(KEYSTORE_ADMIN_SVC_SRC)\*.c
	$(CC) $(CFLAGS) $(KEYSTORE_ADMIN_SVC_SRC)\codegen\*.c $(KEYSTORE_ADMIN_SVC_SRC)\*.c \
		$(SERVICE_ADMIN_UTIL_SRC)\keystore_admin_util.c \
		/Fo$(ADMIN_SVC_INTDIR)\$(KEYSTORE_ADMIN_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(KEYSTORE_ADMIN_SERVICE)\*.obj $(LIBS) rampart.lib /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(KEYSTORE_ADMIN_SERVICE)\$(KEYSTORE_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	if not exist $(ADMIN_SVC_DISTDIR)\$(KEYSTORE_ADMIN_SERVICE)\keystores mkdir $(ADMIN_SVC_DISTDIR)\$(KEYSTORE_ADMIN_SERVICE)\keystores
	copy $(KEYSTORE_ADMIN_SVC_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(KEYSTORE_ADMIN_SERVICE)
	copy $(KEYSTORE_ADMIN_SVC_SRC)\resources\wso2wsfc.* $(ADMIN_SVC_DISTDIR)\$(KEYSTORE_ADMIN_SERVICE)\keystores

keystore_admin_service: $(ADMIN_SVC_DISTDIR)\$(KEYSTORE_ADMIN_SERVICE)\$(KEYSTORE_ADMIN_SERVICE).dll
#=====================================================================================================
$(ADMIN_SVC_DISTDIR)\$(TRANSPORT_ADMIN_SERVICE)\$(TRANSPORT_ADMIN_SERVICE).dll: $(TRANSPORT_ADMIN_SVC_SRC)\codegen\*.c $(TRANSPORT_ADMIN_SVC_SRC)\*.c
	$(CC) $(CFLAGS) $(TRANSPORT_ADMIN_SVC_SRC)\codegen\*.c $(TRANSPORT_ADMIN_SVC_SRC)\*.c \
		/Fo$(ADMIN_SVC_INTDIR)\$(TRANSPORT_ADMIN_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(TRANSPORT_ADMIN_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(TRANSPORT_ADMIN_SERVICE)\$(TRANSPORT_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(TRANSPORT_ADMIN_SVC_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(TRANSPORT_ADMIN_SERVICE)

transport_admin_service: $(ADMIN_SVC_DISTDIR)\$(TRANSPORT_ADMIN_SERVICE)\$(TRANSPORT_ADMIN_SERVICE).dll
#==================================================================================
# bam publisher service
BAM_PUBLISHER_SERVICE=ServiceStatPublisherAdmin
BAM_PUBLISHER_SRC=$(ADMIN_SVC_SRCDIR)\bam_publisher

$(ADMIN_SVC_DISTDIR)\$(BAM_PUBLISHER_SERVICE)\$(BAM_PUBLISHER_SERVICE).dll : 
    if not exist $(ADMIN_SVC_INTDIR)\$(BAM_PUBLISHER_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(BAM_PUBLISHER_SERVICE)
    if not exist $(ADMIN_SVC_DISTDIR)\$(BAM_PUBLISHER_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(BAM_PUBLISHER_SERVICE)
	$(CC) $(CFLAGS) $(BAM_PUBLISHER_SRC)\services\*.c /Fo$(ADMIN_SVC_INTDIR)\$(BAM_PUBLISHER_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(BAM_PUBLISHER_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(BAM_PUBLISHER_SERVICE)\$(BAM_PUBLISHER_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(BAM_PUBLISHER_SRC)\services\services.xml $(ADMIN_SVC_DISTDIR)\$(BAM_PUBLISHER_SERVICE)\

bam_publisher_service: $(ADMIN_SVC_DISTDIR)\$(BAM_PUBLISHER_SERVICE)\$(BAM_PUBLISHER_SERVICE).dll

#=======================================================================================================
# bam publisher module

BAM_PUBLISHER_MODULE=bam_publisher
BAM_PUBLISHER_MODULE_SRC=$(BAM_PUBLISHER_SRC)\module\op_stat_handler.c \
			 $(BAM_PUBLISHER_SRC)\module\mod_bam_publisher.c \
			 $(BAM_PUBLISHER_SRC)\module\statistics.c \
			 $(BAM_PUBLISHER_SRC)\module\util.c \
			 $(BAM_PUBLISHER_SRC)\module\svc_stat_handler.c

$(ADMIN_MOD_DISTDIR)\$(BAM_PUBLISHER_MODULE)\$(BAM_PUBLISHER_MODULE).dll :
	if not exist $(ADMIN_SVC_INTDIR)\$(BAM_PUBLISHER_MODULE) mkdir $(ADMIN_SVC_INTDIR)\$(BAM_PUBLISHER_MODULE)
	if not exist $(ADMIN_MOD_DISTDIR)\$(BAM_PUBLISHER_MODULE) mkdir $(ADMIN_MOD_DISTDIR)\$(BAM_PUBLISHER_MODULE)
	$(CC) $(CFLAGS)  $(BAM_PUBLISHER_MODULE_SRC) $(SERVICE_ADMIN_UTIL_SRC)\*.c \
		/Fo$(ADMIN_SVC_INTDIR)\$(BAM_PUBLISHER_MODULE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(BAM_PUBLISHER_MODULE)\*.obj \
		$(LIBS) savan_msgreceivers.lib savan.lib savan_client.lib /DLL \
		/OUT:$(ADMIN_MOD_DISTDIR)\$(BAM_PUBLISHER_MODULE)\$(BAM_PUBLISHER_MODULE).dll
		-@$(_VC_MANIFEST_EMBED_DLL)
		copy $(BAM_PUBLISHER_SRC)\module\module.xml $(ADMIN_MOD_DISTDIR)\$(BAM_PUBLISHER_MODULE)\
		
bam_publisher_module : $(ADMIN_MOD_DISTDIR)\$(BAM_PUBLISHER_MODULE)\$(BAM_PUBLISHER_MODULE).dll	
#=============================================================================================


#=============================================================================================
#admin_svc_all: bam_publisher_module bam_publisher_service 
admin_svc_all: authentication_service server_admin_service service_admin_service service_grp_admin_service op_admin_service security_admin_service user_manager_service stat_admin_module stat_admin_service module_admin_service keystore_admin_service transport_admin_service
 
all: distdir intdirs admin_svc_all

dist: $(ADMIN_SVC_BUILDDIR)
	if exist $(ADMIN_DISTDIR) rmdir /S /Q $(ADMIN_DISTDIR)
	mkdir $(ADMIN_DISTDIR)
	xcopy /E /Q /I /Y $(ADMIN_SVC_DISTDIR) $(ADMIN_DISTDIR)\services
	xcopy /E /Q /I /Y $(ADMIN_MOD_DISTDIR) $(ADMIN_DISTDIR)\modules
	xcopy /E /Q /I /Y $(ADMIN_SVC_SRCDIR)\carbon $(ADMIN_DISTDIR)\carbon
	copy setup.bat $(ADMIN_DISTDIR)
	copy deploy.js $(ADMIN_DISTDIR)
	copy LICENSE $(ADMIN_DISTDIR)
	copy INSTALL $(ADMIN_DISTDIR)
	copy NEWS    $(ADMIN_DISTDIR)
	copy CREDITS $(ADMIN_DISTDIR)
	copy README  $(ADMIN_DISTDIR)

mkdist: all dist
