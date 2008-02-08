@echo off
@call vcvars32.bat /nologo

rem Build Apache Axis2/C

@cd axis2c\build
@if exist axis2c-bin-1.3.0-win32 rmdir /s /q axis2c-bin-1.3.0-win32
@cd win32
@nmake /nologo dist_as_lib AUTOCONF=..\..\..\configure.in
@if not %ERRORLEVEL% EQU 0 goto end

rem Build Apache Rampart/C
@cd ..\..\..\rampartc\build\win32
@nmake /nologo dist_no_samples AUTOCONF=..\..\..\configure.in AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32

@if not %ERRORLEVEL% EQU 0 goto rampart_error

@cd ..
@xcopy /E /Q /I /Y rampartc-1.1.0\modules\rampart .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\modules\rampart
@copy /Y rampartc-1.1.0\include\*.h .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include\
@copy /Y rampartc-1.1.0\modules\rampart\mod_rampart.lib .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@copy /Y rampartc-1.1.0\modules\rampart\mod_rampart.dll .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@goto build_sandesha2

:rampart_error
@cd ..

rem Build Apache Sandesha2/C
:build_sandesha2
@cd ..\..\sandesha2c\build\win32
@nmake /nologo dist_no_samples AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-1.3.0-win32 AUTOCONF=..\..\..\configure.in

@if not %ERRORLEVEL% EQU 0 goto sandesha2_error

@cd ..
@xcopy /E /Q /I /Y sandesha2\modules\sandesha2 .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\modules\sandesha2
@xcopy /E /Q /I /Y sandesha2\lib\sandesha2_client.lib  .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@xcopy /E /Q /I /Y sandesha2\lib\sandesha2_client.dll  .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@xcopy /E /Q /I /Y sandesha2\modules\sandesha2\sandesha2.lib  .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@xcopy /E /Q /I /Y sandesha2\modules\sandesha2\sandesha2.dll  .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib\
@copy /Y sandesha2\include\*.h  .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include\
@copy /Y sandesha2\include\*.h  .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\include\
@mkdir .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\sandesha2
@copy /Y ..\config\*.txt .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\sandesha2
@copy /Y ..\config\*.bat .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\sandesha2
@copy /Y ..\config\*.sh .\..\..\axis2c\build\axis2c-bin-1.3.0-win32\bin\sandesha2
@goto build_neethi_util

:sandesha2_error
@cd ..

rem Build Neethi util
:build_neethi_util
@cd ..\..\
@cd axis2c\neethi\src\util
@nmake /nologo -f neethi_util.mk AXIS2_BIN_DIR=..\..\..\build\axis2c-bin-1.3.0-win32 AUTOCONF=..\..\..\..\configure.in
@copy neethi_options.h ..\..\..\build\axis2c-bin-1.3.0-win32\include
@cd ..\..\..\..\

:pack_wsfc
rem @cd ..\..
@if not exist wso2-wsf-c-bin-1.2.0 mkdir wso2-wsf-c-bin-1.2.0
@xcopy /E /Q /I /Y axis2c\build\axis2c-bin-1.3.0-win32 wso2-wsf-c-bin-1.2.0
@copy /Y config\axis2.xml wso2-wsf-c-bin-1.2.0\axis2.xml
@copy /Y INSTALL wso2-wsf-c-bin-1.2.0
@copy /Y README wso2-wsf-c-bin-1.2.0
@copy /Y NEWS wso2-wsf-c-bin-1.2.0
@copy /Y COPYING wso2-wsf-c-bin-1.2.0
@copy /Y AUTHORS wso2-wsf-c-bin-1.2.0
@xcopy /E /I /Q /Y docs  wso2-wsf-c-bin-1.2.0\docs

:end
