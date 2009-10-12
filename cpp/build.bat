@echo off
@call vcvars32.bat /nologo

rem @call clean.bat

rem Build WSO2 WSF/C
@copy configure.in wsf_c\configure.in
@call init.bat
@cd wsf_c
@call build.bat

rem Uncomment line below for Fail-safe Install
@if not %ERRORLEVEL% EQU 0 goto end

rem Pack WSO2 WSF/C++
:pack_wsfcpp
@cd ..
@set WSFCPP_SOURCE=%CD%
@set WSFCPP_BUILD_HOME=%WSFCPP_SOURCE%\wso2-wsf-cpp-bin-%WSFCPP_VERSION%-win32
rem @if exist "%WSFCPP_BUILD_HOME%" rmdir /s /q "%WSFCPP_BUILD_HOME%"
@mkdir "%WSFCPP_BUILD_HOME%"
@cd "%WSFCPP_BUILD_HOME%"
@xcopy /E /Q /I /Y "%WSFCPP_SOURCE%\wsf_c\wso2-wsf-c-bin-%WSFC_VERSION%-win32" .
@copy /Y "%WSFCPP_SOURCE%\INSTALL" .
@copy /Y "%WSFCPP_SOURCE%\README.INSTALL.WINDOWS" .
@copy /Y "%WSFCPP_SOURCE%\README.SAMPLES" .
@copy /Y "%WSFCPP_SOURCE%\README" .
@copy /Y "%WSFCPP_SOURCE%\NEWS" .
@copy /Y "%WSFCPP_SOURCE%\COPYING" .
@copy /Y "%WSFCPP_SOURCE%\AUTHORS" .
@copy /Y "%WSFCPP_SOURCE%\NOTICE" .
@copy /Y "%WSFCPP_SOURCE%\ChangeLog" .
@cd "%WSFCPP_SOURCE%"

rem Add HTML Documentation
:add_html_docs
@cd "%WSFCPP_BUILD_HOME%"
move docs wsf_c
mkdir docs
@xcopy /E /I /Q /Y "%WSFCPP_SOURCE%\docs"  docs\cpp
move wsf_c docs\wsf_c

:remove_wsf_c_services
@cd %WSFCPP_BUILD_HOME%
move services services_c
@mkdir services
xcopy /E /I /Q /Y services_c\sec_echo services\sec_echo\
xcopy /E /I /Q /Y services_c\secconv_echo services\secconv_echo\
@rmdir /s /q services_c
@if exist bin\tools\wsdl2c rmdir /s /q bin\tools\wsdl2c
@cd %WSFCPP_SOURCE%

rem Clean bin Folder
:clean_bin_dir
@cd "%WSFCPP_BUILD_HOME%\bin"
@del *.exp
@del *.lib
@cd "%WSFCPP_BUILD_HOME%\lib"
@del *.exp
@cd "%WSFCPP_SOURCE%"

rem Build Source
:build_source
@cd src
@nmake dist -f wsf.mk AUTOCONF=..\configure.in
@if not %ERRORLEVEL% EQU 0 goto end
@cd ..\include
@copy /Y *.h "%WSFCPP_BUILD_HOME%\include"
@cd ..

rem Build Client Samples
:build_client_samples
copy "%WSFCPP_BUILD_HOME%\samples\bin\*.bat" "%WSFCPP_BUILD_HOME%\samples\"
@if exist "%WSFCPP_BUILD_HOME%\samples\bin" rmdir /s /q "%WSFCPP_BUILD_HOME%\samples\bin"
@if exist "%WSFCPP_BUILD_HOME%\samples\lib" rmdir /s /q "%WSFCPP_BUILD_HOME%\samples\lib"
@cd "%WSFCPP_SOURCE%"
@cd examples
@nmake dist -f samples.mk AUTOCONF=..\configure.in
@if not %ERRORLEVEL% EQU 0 goto end
move "%WSFCPP_BUILD_HOME%\samples\*.bat" "%WSFCPP_BUILD_HOME%\samples\bin\"

rem Deploy Sample Source
:dep_sample_source
@move "%WSFCPP_BUILD_HOME%\samples\src" "%WSFCPP_BUILD_HOME%\samples\src_c"
@mkdir "%WSFCPP_BUILD_HOME%\samples\src\c"
@xcopy /E /I /Q /Y "%WSFCPP_BUILD_HOME%\samples\src_c" "%WSFCPP_BUILD_HOME%\samples\src\c"
@rmdir /s /q "%WSFCPP_BUILD_HOME%\samples\src_c"
@cd %WSFCPP_SOURCE%
@xcopy /E /I /Q /Y examples "%WSFCPP_BUILD_HOME%\samples\src\cpp"
@copy /Y configure.in "%WSFCPP_BUILD_HOME%\samples\src"
@cd "%WSFCPP_BUILD_HOME%\samples\src\cpp"
@if not exist .svn mkdir .svn
@for /F "tokens=*" %%G in ('dir /B /AD /S *.svn*') do rmdir /S /Q "%%G"
@if not exist int.msvc mkdir int.msvc
@for /F "tokens=*" %%G in ('dir /B /AD /S *int.msvc*') do rmdir /S /Q "%%G"
@if not exist *.sh echo > #.sh
@for /F "tokens=*" %%G in ('dir /B /S *.sh*') do del "%%G"
@if not exist *.am echo > #.am
@for /F "tokens=*" %%G in ('dir /B /S *.am*') do del "%%G"
@cd "%WSFCPP_SOURCE%"

:end
@echo on
