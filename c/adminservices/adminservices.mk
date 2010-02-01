
AUTOCONF = configure.in
!include $(AUTOCONF)

ADMIN_SVC_SRCDIR = .\ 
ADMIN_SVC_INTDIR = .\intmsvc
ADMIN_SVC_DISTDIR = .\services

INCLUDE_PATH = /I $(WSFC_HOME)\include /I $(WSFC_HOME)/../include /I$(ADMIN_SVC_SRCDIR)\include 
LIBS_PATH = /LIBPATH:$(WSFC_HOME)\lib 

## Packaged Service Names

AUTH_SERVICE=AuthenticationAdminService
SERVER_ADMIN_SERVICE=ServerAdmin
OP_ADMIN_SERVICE=OperationAdmin
SERVICE_ADMIN_SERVICE=ServiceAdmin
SERVICE_GRP_ADMIN_SERVICE=ServiceGroupAdmin

## Service Code SRC
AUTH_SVC_SRC=$(ADMIN_SVC_SRCDIR)\authentication
SERVER_ADMIN_SRC=$(ADMIN_SVC_SRCDIR)\server_admin
SERVICE_ADMIN_SRC=$(ADMIN_SVC_SRCDIR)\service_admin
SERVICE_ADMIN_UTIL_SRC=$(ADMIN_SVC_SRCDIR)\util

##################### compiler options

CC = cl.exe 
CFLAGS = /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "AXIS2_DECLARE_EXPORT"   \
	 /D "AXIS2_SVR_MULTI_THREADED" /w /nologo $(INCLUDE_PATH) 

################### linker options

LD = link.exe
LDFLAGS = /nologo $(LIBS_PATH)

LIBS = axutil.lib axiom.lib axis2_engine.lib


SSL_LIB_FLAG = "MD"
!if "$(CRUNTIME)" == "/MT"
SSL_LIB_FLAG = "MT"
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

#################### hack!
#CFLAGS = $(CFLAGS) /D "_WINSOCKAPI_"

distdir:
	if not exist $(ADMIN_SVC_DISTDIR)	mkdir $(ADMIN_SVC_DISTDIR)
	if not exist $(ADMIN_SVC_DISTDIR)\$(AUTH_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(AUTH_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(SERVER_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(SERVER_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(SERVICE_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(SERVICE_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(SERVICE_GRP_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(SERVICE_GRP_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_DISTDIR)\$(OP_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(OP_ADMIN_SERVICE)


clean: 
	if exist $(ADMIN_SVC_DISTDIR) rmdir /S /Q $(ADMIN_SVC_DISTDIR)
	if exist $(ADMIN_SVC_INTDIR)  rmdir /S /Q $(ADMIN_SVC_INTDIR)

intdirs:
	if not exist $(ADMIN_SVC_INTDIR) mkdir $(ADMIN_SVC_INTDIR)
	if not exist $(ADMIN_SVC_INTDIR)\$(AUTH_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(AUTH_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(SERVER_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(SERVER_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(SERVICE_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(SERVICE_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(SERVICE_GRP_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(SERVICE_GRP_ADMIN_SERVICE)
	if not exist $(ADMIN_SVC_INTDIR)\$(OP_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(OP_ADMIN_SERVICE)


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
	$(SERVER_ADMIN_SRC)\*.c /Fo$(ADMIN_SVC_INTDIR)\$(SERVER_ADMIN_SERVICE)\ /c
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
	
#==================================================================================
#Keystore Admin Service 
#==================================================================================
KEYSTORE_ADMIN_SERVICE = KeyStoreAdminService
KEYSTORE_ADMIN_DISTDIR = $(ADMIN_SVC_DISTDIR)\$(KEYSTORE_ADMIN_SERVICE)
KEYSTORE_ADMIN_INTDIR = $(ADMIN_SVC_INTDIR)\$(KEYSTORE_ADMIN_SERVICE)
KEYSTORE_ADMIN_SRC = 	$(ADMIN_SVC_SRCDIR)\keystore_admin\codegen\*.c \
					$(ADMIN_SVC_SRCDIR)\keystore_admin\*.c

keystore_admin: $(KEYSTORE_ADMIN_SRC)
	if not exist $(KEYSTORE_ADMIN_DISTDIR) mkdir $(KEYSTORE_ADMIN_DISTDIR)
	if not exist $(KEYSTORE_ADMIN_INTDIR) mkdir $(KEYSTORE_ADMIN_INTDIR)
	$(CC) $(CFLAGS) $(KEYSTORE_ADMIN_SRC) /Fo$(KEYSTORE_ADMIN_INTDIR)\ /c
	$(LD) $(LDFLAGS) $(KEYSTORE_ADMIN_INTDIR)\*.obj $(LIBS) esb.lib /DLL \
		/OUT:$(KEYSTORE_ADMIN_DISTDIR)\$(KEYSTORE_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(ADMIN_SVC_SRCDIR)\keystore_admin\resources\services.xml $(KEYSTORE_ADMIN_DISTDIR)
	
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
STAT_ADMIN_SRC=$(ADMIN_SVC_SRCDIR)\statistics_admin

$(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)\$(STAT_ADMIN_SERVICE).dll : 
    if not exist $(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_SERVICE) mkdir $(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_SERVICE)
    if not exist $(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE) mkdir $(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)
	$(CC) $(CFLAGS) /I$(STAT_ADMIN_SRC) $(STAT_ADMIN_SRC)\codegen\*.c $(STAT_ADMIN_SRC)\*.c $(SERVICE_ADMIN_UTIL_SRC)\*.c /Fo$(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_SERVICE)\ /c
	$(LD) $(LDFLAGS) $(ADMIN_SVC_INTDIR)\$(STAT_ADMIN_SERVICE)\*.obj $(LIBS) /DLL \
		/OUT:$(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)\$(STAT_ADMIN_SERVICE).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	copy $(OP_ADMIN_SRC)\resources\services.xml $(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)\

	copy $(STAT_ADMIN_SRC)\resources\$(STAT_ADMIN_SERVICE).wsdl $(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)\

stat_admin_service: $(ADMIN_SVC_DISTDIR)\$(STAT_ADMIN_SERVICE)\$(STAT_ADMIN_SERVICE).dll


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
	
#==================================================================================
#Registry Client 
#==================================================================================
REGISTRY_CLIENT = registry_client
REGISTRY_CLIENT_DISTDIR = $(ADMIN_SVC_DISTDIR)\$(REGISTRY_CLIENT)
REGISTRY_CLIENT_INTDIR = $(ADMIN_SVC_INTDIR)\$(REGISTRY_CLIENT)
REGISTRY_CLIENT_SRC = 	$(ADMIN_SVC_SRCDIR)\registry_client\*.c 

registry_client: $(REGISTRY_CLIENT_SRC)
	if not exist $(REGISTRY_CLIENT_DISTDIR) mkdir $(REGISTRY_CLIENT_DISTDIR)
	if not exist $(REGISTRY_CLIENT_INTDIR) mkdir $(REGISTRY_CLIENT_INTDIR)
	$(CC) $(CFLAGS) $(REGISTRY_CLIENT_SRC) /Fo$(REGISTRY_CLIENT_INTDIR)\ /c
	$(LD) $(LDFLAGS) $(REGISTRY_CLIENT_INTDIR)\*.obj $(LIBS) esb.lib /DLL \
		/OUT:$(REGISTRY_CLIENT_DISTDIR)\$(REGISTRY_CLIENT).dll
	-@$(_VC_MANIFEST_EMBED_DLL)
	
#==============================================================================================

admin_svc_all: authentication_service server_admin_service service_admin_service service_grp_admin_service op_admin_service stat_admin_service
#admin_svc_all: authentication_service server_admin_service proxy_admin op_admin_service service_admin_service keystore_admin

install: distdir intdirs admin_svc_all

dist: install 

