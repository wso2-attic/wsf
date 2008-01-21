@echo off
@call vcvars32.bat /nologo

rem Build Apache Axis2/C

@cd axis2c\build
@if exist axis2c-bin-1.2.0-win32 rmdir /s /q axis2c-bin-1.2.0-win32
@cd win32
@nmake dist AUTOCONF=..\..\..\configure.in
@if not %ERRORLEVEL% EQU 0 goto end

rem Build Flickr sample
@cd ..\..\..\examples\flickr
@nmake -f flickr.mk
@copy /Y flickr.exe  ..\..\axis2c\build\axis2c-bin-1.2.0-win32\bin\samples

rem Build Trader sample
@cd ..\trader
@nmake -f trader.mk
@cd ..\..

rem Build Optional Modules
@cd build
@nmake -f optional.mk
@cd ..

rem Build Neethi util
:build_neethi_util
@cd axis2c\neethi\src\util
@nmake -f neethi_util.mk AXIS2_BIN_DIR=..\..\..\build\axis2c-bin-1.2.0-win32 AUTOCONF=..\..\..\..\configure.in
@cd ..\..\..\..\

rem Build wsclient
@cd wsclient
@nmake -f wsclient.mk AXIS2_BIN_DIR=..\axis2c\build\axis2c-bin-1.2.0-win32 AUTOCONF=..\configure.in
@cd ..

:pack_wsfc
@if not exist wso2-wsf-c-bin-1.2.0-win32 mkdir wso2-wsf-c-bin-1.2.0-win32
@xcopy /E /Q /I /Y axis2c\build\axis2c-bin-1.2.0-win32 wso2-wsf-c-bin-1.2.0-win32
@copy /Y config\axis2.xml wso2-wsf-c-bin-1.2.0-win32\axis2.xml
@copy /Y INSTALL wso2-wsf-c-bin-1.2.0-win32
@copy /Y README wso2-wsf-c-bin-1.2.0-win32
@copy /Y NEWS wso2-wsf-c-bin-1.2.0-win32
@copy /Y COPYING wso2-wsf-c-bin-1.2.0-win32
@copy /Y AUTHORS wso2-wsf-c-bin-1.2.0-win32
@copy /Y NOTICE wso2-wsf-c-bin-1.2.0-win32
@xcopy /E /I /Q /Y docs  wso2-wsf-c-bin-1.2.0-win32\docs

:end
