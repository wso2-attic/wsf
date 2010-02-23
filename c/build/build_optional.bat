cd ..

rem Build Apache Rampart/C
if %1 == "no" goto build_sandesha2
echo %1
cd rampartc\build\win32
nmake dist AUTOCONF=..\..\..\configure.in AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32

if not %ERRORLEVEL% EQU 0 goto rampart_error

cd ..
xcopy /E /Q /I /Y rampartc-%RAMPARTC_VERSION%\modules .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\modules
copy /Y rampartc-%RAMPARTC_VERSION%\include\*.h .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\include\
copy /Y rampartc-%RAMPARTC_VERSION%\lib\* .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\lib\
copy /Y rampartc-%RAMPARTC_VERSION%\samples\src\rampartc\data\server_axis2.xml .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\axis2.xml
xcopy /E /I /Q /Y rampartc-%RAMPARTC_VERSION%\samples .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples
xcopy /E /I /Q /Y rampartc-%RAMPARTC_VERSION%\services .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\services
cd ..\..
goto build_sandesha2

:rampart_error
cd ..\..\..

rem Build Apache Sandesha2/C
:build_sandesha2
if %2 == "no" goto build_savan
cd sandesha2c\build\win32
nmake dist AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32 AUTOCONF=..\..\..\configure.in

if not %ERRORLEVEL% EQU 0 goto sandesha2_error

cd ..
xcopy /E /Q /I /Y sandesha2\modules\sandesha2 .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\modules\sandesha2
xcopy /E /Q /I /Y sandesha2\modules\sandesha2\sandesha2.lib  .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\lib\
xcopy /E /Q /I /Y sandesha2\modules\sandesha2\sandesha2.dll  .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\lib\
xcopy /E /Q /I /Y sandesha2\lib\*  .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\lib\
xcopy /E /I /Q /Y sandesha2\samples .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples
xcopy /E /Q /I /Y sandesha2\services .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\services
copy /Y sandesha2\include\*.h  .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\include\
copy /Y ..\config\*.bat .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples\bin\sandesha2
copy /Y ..\config\*.sh .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples\bin\sandesha2
cd ..\..
goto build_savan

:sandesha2_error
cd ..\..\..

rem Build Apache Savan/C
:build_savan
if %3 == "no" goto build_udp_transport
cd savanc\build\win32
nmake dist AUTOCONF=..\..\..\configure.in AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32

if not %ERRORLEVEL% EQU 0 goto savan_error

cd ..
xcopy /E /Q /I /Y savanc\modules\savan .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\modules\savan
xcopy /E /Q /I /Y savanc\services .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\services
xcopy /E /Q /I /Y savanc\samples .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples
copy /Y savanc\lib\* .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\lib\
copy /Y savanc\include\*.h .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\include\ 
cd ..\..\
goto build_udp_transport

:savan_error
cd ..\..\..

rem Buil UDP transport
:build_udp_transport
if %4 == "no" goto end
cd axis2c\src\core\transport\udp
nmake all -f udp_transport.mk AXIS2_BIN_DIR=..\..\..\..\build\axis2c-bin-%AXIS2C_VERSION%-win32 AUTOCONF=..\..\..\..\..\configure.in
cd ..\..\..\..\..\
goto end

:end
