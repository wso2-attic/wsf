@echo off
@cd ..

rem Build Apache Rampart/C
@if %1 == "no" goto build_sandesha2
@echo %1
@cd rampartc\build\win32
@nmake dist AUTOCONF=..\..\..\configure.in AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32

@if not %ERRORLEVEL% EQU 0 goto rampart_error

@cd ..
@xcopy /E /Q /I /Y rampartc-1.1.0\modules\rampart .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\modules\rampart
@copy /Y rampartc-1.1.0\include\*.h .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include\
@copy /Y rampartc-1.1.0\modules\rampart\mod_rampart.lib .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@copy /Y rampartc-1.1.0\modules\rampart\mod_rampart.dll .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@copy /Y rampartc-1.1.0\bin\samples\services\sec_echo\server_axis2.xml .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\axis2.xml
@xcopy /E /I /Q /Y rampartc-1.1.0\bin\samples .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\samples\rampart
@xcopy /E /I /Q /Y .\..\samples .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\samples\rampart
@xcopy /E /I /Q /Y rampartc-1.1.0\bin\samples\services\sec_echo .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\sec_echo
@cd ..\..
@goto build_sandesha2

:rampart_error
@cd ..\..\..

rem Build Apache Sandesha2/C
:build_sandesha2
@if %2 == "no" goto build_savan
@cd sandesha2c\build\win32
@nmake dist AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32 AUTOCONF=..\..\..\configure.in

@if not %ERRORLEVEL% EQU 0 goto sandesha2_error

@cd ..
@xcopy /E /Q /I /Y sandesha2\modules\sandesha2 .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\modules\sandesha2
@xcopy /E /Q /I /Y sandesha2\modules\sandesha2\sandesha2.lib  .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@xcopy /E /Q /I /Y sandesha2\modules\sandesha2\sandesha2.dll  .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@mkdir .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\samples\sandesha2
@copy /Y sandesha2\bin\samples\sandesha2\*.exe .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\samples\sandesha2
@xcopy /E /Q /I /Y sandesha2\services\RMSampleService .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\RMSampleService
@xcopy /E /Q /I /Y sandesha2\samples .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\samples\sandesha2
@copy /Y sandesha2\include\*.h  .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include\
@xcopy /E /Q /I /Y  sandesha2\bin\samples\sandesha2 .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\samples\sandesha2
@mkdir .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\sandesha2
@copy /Y ..\config\*.txt .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\sandesha2
@copy /Y ..\config\*.bat .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\sandesha2
@copy /Y ..\config\*.sh .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\sandesha2
@cd ..\..
@goto build_savan

:sandesha2_error
@cd ..\..\..

rem Build Apache Savan/C
:build_savan
@if %3 == "no" goto end
@cd savanc\build\win32
@nmake dist AUTOCONF=..\..\..\configure.in AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32

@if not %ERRORLEVEL% EQU 0 goto savan_error

@cd ..
@xcopy /E /Q /I /Y savanc\modules\savan .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\modules\savan
@xcopy /E /Q /I /Y savanc\services\publisher .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\publisher
@xcopy /E /Q /I /Y savanc\services\listener .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\listener
@xcopy /E /Q /I /Y savanc\services\subscription .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\services\subscription
@xcopy /E /Q /I /Y savanc\samples .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\samples\savan
@copy /Y savanc\modules\savan\mod_savan.dll .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@copy /Y savanc\modules\savan\mod_savan.lib .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@copy /Y savanc\lib\savan_client.dll .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@copy /Y savanc\lib\savan_client.lib .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\

@mkdir .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\samples\savan
@copy /Y savanc\bin\samples\savan\*.exe .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\samples\savan
@cd ..\..
@goto end

:savan_error
@cd ..\..\..

:end
