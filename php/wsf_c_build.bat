@echo off
@call vcvars32.bat /nologo

@call build\init.bat
rem Build Apache Axis2/C

@cd axis2c\build
@if exist axis2c-bin-%AXIS2C_VERSION%-win32 rmdir /s /q axis2c-bin-%AXIS2C_VERSION%-win32
@cd win32
@nmake /nologo dist_as_lib AUTOCONF=..\..\..\configure.in
@if not %ERRORLEVEL% EQU 0 goto end

rem Build Apache Rampart/C
@cd ..\..\..\rampartc\build\win32
@nmake /nologo dist_no_samples AUTOCONF=..\..\..\configure.in AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32

@if not %ERRORLEVEL% EQU 0 goto rampart_error

@cd ..
@xcopy /E /Q /I /Y rampartc-%RAMPARTC_VERSION%\modules\rampart .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\modules\rampart
@copy /Y rampartc-%RAMPARTC_VERSION%\include\*.h .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\include\
@copy /Y rampartc-%RAMPARTC_VERSION%\lib\rampart.lib .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\lib\
@copy /Y rampartc-%RAMPARTC_VERSION%\lib\rampart.dll .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\lib\
@xcopy /E /Q /I /Y rampartc-%RAMPARTC_VERSION%\modules\rahas .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\modules\rahas

@goto build_sandesha2

:rampart_error
@cd ..

rem Build Apache Sandesha2/C
:build_sandesha2
@cd ..\..\sandesha2c\build\win32
@nmake /nologo dist_no_samples AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32 AUTOCONF=..\..\..\configure.in

@if not %ERRORLEVEL% EQU 0 goto sandesha2_error

@cd ..
@xcopy /E /Q /I /Y sandesha2\modules\sandesha2 .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\modules\sandesha2
@xcopy /E /Q /I /Y sandesha2\lib\sandesha2_client.lib  .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\lib\
@xcopy /E /Q /I /Y sandesha2\lib\sandesha2_client.dll  .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\lib\
@xcopy /E /Q /I /Y sandesha2\modules\sandesha2\sandesha2.lib  .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\lib\
@xcopy /E /Q /I /Y sandesha2\modules\sandesha2\sandesha2.dll  .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\lib\
@copy /Y sandesha2\include\*.h  .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\include\
@copy /Y sandesha2\include\*.h  .\..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\include\
@goto build_neethi_util

:sandesha2_error
@cd ..

rem Build Neethi util
:build_neethi_util
@cd ..\..\
@cd axis2c\neethi\src\util
@nmake /nologo -f neethi_util.mk AXIS2_BIN_DIR=..\..\..\build\axis2c-bin-%AXIS2C_VERSION%-win32 AUTOCONF=..\..\..\..\configure.in
@copy neethi_options.h ..\..\..\build\axis2c-bin-%AXIS2C_VERSION%-win32\include
@cd ..\..\..\..\

:pack_wsfc
rem @cd ..\..
@if not exist wso2-wsf-c-bin-%WSFC_VERSION% mkdir wso2-wsf-c-bin-%WSFC_VERSION%
@xcopy /E /Q /I /Y axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32 wso2-wsf-c-bin-%WSFC_VERSION%
@copy /Y config\axis2.xml wso2-wsf-c-bin-%WSFC_VERSION%\axis2.xml
@copy /Y INSTALL wso2-wsf-c-bin-%WSFC_VERSION%
@copy /Y README wso2-wsf-c-bin-%WSFC_VERSION%
@copy /Y NEWS wso2-wsf-c-bin-%WSFC_VERSION%
@copy /Y COPYING wso2-wsf-c-bin-%WSFC_VERSION%
@copy /Y AUTHORS wso2-wsf-c-bin-%WSFC_VERSION%
@xcopy /E /I /Q /Y docs  wso2-wsf-c-bin-%WSFC_VERSION%\docs

:end
