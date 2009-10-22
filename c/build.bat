@echo off
call vcvars32.bat /nologo

rem setup version variables
call build\init.bat

rem Build Apache Axis2/C
cd axis2c\build
if exist axis2c-bin-%AXIS2C_VERSION%-win32 rmdir /s /q axis2c-bin-%AXIS2C_VERSION%-win32
cd win32
nmake dist AUTOCONF=..\..\..\configure.in
cd ..\axis2c-bin-1.6.0-win32\samples\
ren src axis2c
mkdir src
move axis2c src\
if not %ERRORLEVEL% EQU 0 goto end

rem Build Flickr sample
cd ..\..\..\..\examples\flickr
nmake -f flickr.mk
mkdir ..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples\bin\wsf_c
copy /Y flickr.exe  ..\..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples\bin\wsf_c

rem Build Trader sample
cd ..\trader
nmake -f trader.mk trader
cd ..\..

mkdir axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples\src\wsf_c
xcopy /E /Q /I /Y examples axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples\src\wsf_c
del /s /q axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples\src\wsf_c\*.exe
del /s /q axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples\src\wsf_c\*.dll
del /s /q axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples\src\wsf_c\*.exp
del /s /q axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples\src\wsf_c\*.lib
del /s /q axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32\samples\src\wsf_c\*.obj

rem Build Optional Modules
cd build
nmake -f optional.mk
cd ..

rem Build Neethi util
:build_neethi_util
cd axis2c\neethi\src\util
nmake -f neethi_util.mk AXIS2_BIN_DIR=..\..\..\build\axis2c-bin-%AXIS2C_VERSION%-win32 AUTOCONF=..\..\..\..\configure.in
cd ..\..\..\..\

rem Build wsclient
cd wsclient
nmake -f wsclient.mk AXIS2_BIN_DIR=..\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32 AUTOCONF=..\configure.in
cd ..

rem Build Unit Test Framework
cd test\framework
nmake install -f wsfc_unit.mk AUTOCONF=..\..\configure.in
cd ..\..

rem Build Tests

:pack_wsfc
if not exist wso2-wsf-c-bin-%WSFC_VERSION%-win32 mkdir wso2-wsf-c-bin-%WSFC_VERSION%-win32
xcopy /E /Q /I /Y axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32 wso2-wsf-c-bin-%WSFC_VERSION%-win32
copy /Y config\axis2.xml wso2-wsf-c-bin-%WSFC_VERSION%-win32\axis2.xml
copy /Y INSTALL wso2-wsf-c-bin-%WSFC_VERSION%-win32
copy /Y README wso2-wsf-c-bin-%WSFC_VERSION%-win32
copy /Y NEWS wso2-wsf-c-bin-%WSFC_VERSION%-win32
copy /Y COPYING wso2-wsf-c-bin-%WSFC_VERSION%-win32
copy /Y AUTHORS wso2-wsf-c-bin-%WSFC_VERSION%-win32
copy /Y NOTICE wso2-wsf-c-bin-%WSFC_VERSION%-win32
xcopy /E /I /Q /Y docs  wso2-wsf-c-bin-%WSFC_VERSION%-win32\docs

:end
