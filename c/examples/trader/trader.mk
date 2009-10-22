!include ..\..\build\versions.in
!include ..\..\configure.in

TRADER_HOME = .
TRADER_UTIL = util
TRADER_CLIENT = $(TRADER_HOME)\client
TRADER_EXCHANGE = $(TRADER_HOME)\exchange
TRADER_EXCHANGE_UTIL = $(TRADER_EXCHANGE)\util
TRADER_EXCHANGE_CLIENT = $(TRADER_EXCHANGE)\exchange-client
TRADER_EXCHANGE_TRADER = $(TRADER_EXCHANGE)\exchange-trader
TRADER_TRADER_UTIL = $(TRADER_HOME)\trader\util
TRADER_TRADER_CLIENT = $(TRADER_HOME)\trader\trader-client
TRADER_TRADER_EXCHANGE =$(TRADER_HOME)\trader\trader-exchange

LDFLAGS=/LIBPATH:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib
CFLAGS= /I..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\include 

!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS) /D "_DEBUG"  
LDFLAGS = $(LDFLAGS) /DEBUG
!else
CFLAGS = $(CFLAGS) /D "NDEBUG" 
LDFLAGS = $(LDFLAGS)
!endif

CC=cl.exe
LD=link.exe
MT=mt.exe

TRADER_DECLARES =  $(CFLAGS) /D "_CRT_SECURE_NO_DEPRECATE" /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS"

create_dirs:
	if not exist ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangeclient mkdir ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangeclient
	if not exist ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangetrader mkdir ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangetrader
	if not exist ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderclient mkdir  ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderclient
	if not exist ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderexchange mkdir ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderexchange
		
trader_util:
	$(CC) /nologo $(TRADER_DECLARES) $(TRADER_UTIL)\*.c  /Iinclude /Fo$(TRADER_UTIL)\ /c
	
trader_client:	
	$(CC) /nologo $(TRADER_DECLARES) $(TRADER_CLIENT)\*.c /Iinclude /Fo$(TRADER_CLIENT)\ /c
	$(LD) /nologo  $(TRADER_CLIENT)\*.obj $(TRADER_UTIL)\*.obj $(LDFLAGS) /OUT:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\samples\bin\wsf_c\trader.exe
	if exist ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\samples\bin\wsf_c\trader.exe.manifest $(MT) -nologo -manifest ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\samples\bin\wsf_c\trader.exe.manifest -outputresource:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\samples\bin\wsf_c\trader.exe;1
trader_exchange_util:	
	$(CC) /nologo $(TRADER_DECLARES) $(TRADER_EXCHANGE_UTIL)\*.c  /I..\..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\include /Iinclude /Fo$(TRADER_EXCHANGE_UTIL)\ /c

trader_exchange_client:
	$(CC) /nologo $(TRADER_DECLARES) $(TRADER_EXCHANGE_CLIENT)\*.c  /Iinclude /Fo$(TRADER_EXCHANGE_CLIENT)\ /c
	$(LD) /nologo $(TRADER_EXCHANGE_CLIENT)\*.obj $(TRADER_UTIL)\*.obj $(LDFLAGS) /DLL /OUT:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangeclient\exchangeclient.dll
	if exist ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangeclient\exchangeclient.dll.manifest $(MT) -nologo -manifest ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangeclient\exchangeclient.dll.manifest -outputresource:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangeclient\exchangeclient.dll;2
	copy /Y $(TRADER_EXCHANGE_CLIENT)\services.xml ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangeclient

trader_exchange_trader:
	$(CC) /nologo $(TRADER_DECLARES) $(TRADER_EXCHANGE_TRADER)\*.c  /Iinclude /Fo$(TRADER_EXCHANGE_TRADER)\ /c
	$(LD) /nologo  $(TRADER_EXCHANGE_TRADER)\*.obj $(TRADER_EXCHANGE_UTIL)\*.obj  $(TRADER_UTIL)\*.obj $(LDFLAGS) /DLL /OUT:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangetrader\exchangetrader.dll
	if exist ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangetrader\exchangetrader.dll.manifest $(MT) -nologo -manifest ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangetrader\exchangetrader.dll.manifest -outputresource:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangetrader\exchangetrader.dll;2
	copy /Y $(TRADER_EXCHANGE_TRADER)\services.xml ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\exchangetrader

trader_trader_util:
	cl.exe /nologo $(TRADER_DECLARES) $(TRADER_TRADER_UTIL)\*.c  /Iinclude /Fo$(TRADER_TRADER_UTIL)\ /c
	
trader_trader_client:
	$(CC) /nologo $(TRADER_DECLARES) $(TRADER_TRADER_CLIENT)\*.c  /Iinclude /Fo$(TRADER_TRADER_CLIENT)\ /c
	$(LD) /nologo $(LDFLAGS) $(TRADER_TRADER_CLIENT)\*.obj $(TRADER_TRADER_UTIL)\*.obj $(TRADER_UTIL)\*.obj /DLL /OUT:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderclient\traderclient.dll
	if exist ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderclient\traderclient.dll.manifest $(MT) -nologo -manifest ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderclient\traderclient.dll.manifest -outputresource:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderclient\traderclient.dll;2
	copy /Y $(TRADER_TRADER_CLIENT)\services.xml ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderclient

trader_trader_exchange:
	$(CC) /nologo $(TRADER_DECLARES) $(TRADER_TRADER_EXCHANGE)\*.c /Iinclude /Fo$(TRADER_TRADER_EXCHANGE)\ /c
	$(LD) /nologo $(LDFLAGS)  $(TRADER_TRADER_EXCHANGE)\*.obj $(TRADER_TRADER_UTIL)\*.obj $(TRADER_UTIL)\*.obj /DLL /OUT:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderexchange\traderexchange.dll
	if exist ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderexchange\traderexchange.dll.manifest $(MT) -nologo -manifest ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderexchange\traderexchange.dll.manifest -outputresource:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderexchange\traderexchange.dll;2
	copy /Y  $(TRADER_TRADER_EXCHANGE)\services.xml ..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\services\traderexchange

clean:
	del /q $(TRADER_UTIL)\*.obj
	del /q $(TRADER_CLIENT)\*.obj
	del /q $(TRADER_EXCHANGE_UTIL)\*.obj
	del /q $(TRADER_EXCHANGE_CLIENT)\*.obj
	del /q $(TRADER_TRADER_UTIL)\*.obj
	del /q $(TRADER_TRADER_CLIENT)\*.obj
	del /q $(TRADER_TRADER_EXCHANGE)\*.obj
	
trader: create_dirs trader_util trader_client trader_exchange_util trader_exchange_client trader_exchange_trader trader_trader_util trader_trader_client trader_trader_exchange

