
TRADER_HOME = ..
TRADER_UTIL = util
TRADER_CLIENT = $(TRADER_HOME)\client
TRADER_EXCHANGE = $(TRADER_HOME)\exchange
TRADER_EXCHANGE_UTIL = $(TRADER_EXCHANGE)\util
TRADER_EXCHANGE_CLIENT = ..\exchange-client
TRADER_EXCHANGE_TRADER = ..\exchange-trader
TRADER_TRADER_UTIL = ..\..\trader\util
TRADER_TRADER_CLIENT = ..\trader-client
TRADER_TRADER_EXCHANGE = ..\trader_exchange

echo:
	@cd $(TRADER_UTIL)
	@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" *.C  /I..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include /I../include /c
	@link.exe /nologo *.obj /LIBPATH:..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib  /DLL /OUT:wsf_util.dll

	@cd $(TRADER_CLIENT)
	@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" trader_client.c axis2_stub_TraderClient.c axis2_stub_ExchangeClient.c /I..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include /I../include /c
	@link.exe /nologo *.obj ..\util\*.obj /LIBPATH:..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib axis2_http_sender.lib axis2_http_receiver.lib  /OUT:trader.exe
	@copy /Y trader.exe ..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\samples
	
	@cd $(TRADER_EXCHANGE_UTIL)
	@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" *.C  /I..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include /I..\..\include /c
	@link.exe /nologo *.obj ..\..\util\*.obj /LIBPATH:..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib  /DLL /OUT:wsf_exchange_util.dll


	@cd $(TRADER_EXCHANGE_CLIENT)
	@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" *.C  /I..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include /I..\..\include /c
	@link.exe /nologo *.obj ..\..\util\*.obj /LIBPATH:..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib  /DLL /OUT:exchangeclient.dll
	@if not exist ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\exchangeclient mkdir ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\exchangeclient
	@copy /Y exchangeclient.dll ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\exchangeclient
	@copy /Y services.xml ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\exchangeclient

	@cd $(TRADER_EXCHANGE_TRADER)
	@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" *.C  /I..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include /I..\..\include /c
	@link.exe /nologo *.obj ..\..\util\*.obj ..\util\*.obj /LIBPATH:..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib  /DLL /OUT:exchangetrader.dll
	@if not exist ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\exchangetrader mkdir ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\exchangetrader
	@copy /Y exchangetrader.dll ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\exchangetrader
	@copy /Y services.xml ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\exchangetrader

	@cd $(TRADER_TRADER_UTIL)
	@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" *.C  /I..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include /I..\..\include /c
	@link.exe /nologo *.obj ..\..\util\*.obj /LIBPATH:..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib  /DLL /OUT:wsf_trader_util.dll

	@cd $(TRADER_TRADER_CLIENT)
	@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" *.C  /I..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include /I..\..\include /c
	@link.exe /nologo *.obj ..\..\util\*.obj ..\util\*.obj /LIBPATH:..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib  /DLL /OUT:traderclient.dll
	@if not exist ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\traderclient mkdir ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\traderclient
	@copy /Y traderclient.dll ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\traderclient
	@copy /Y services.xml ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\traderclient


	@cd $(TRADER_TRADER_exchange)
	@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" *.C  /I..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include /I..\..\include /c
	@link.exe /nologo *.obj ..\..\util\*.obj ..\util\*.obj /LIBPATH:..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib  /DLL /OUT:traderexchange.dll
	@if not exist ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\traderexchange mkdir ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\traderexchange
	@copy /Y traderexchange.dll ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\traderexchange
	@copy /Y services.xml ..\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\traderexchange
