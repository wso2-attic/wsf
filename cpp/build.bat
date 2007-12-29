@echo off
@call vcvars32.bat /nologo

rem Build WSO2 WSF/C
@copy configure.in wsf_c\configure.in
@cd wsf_c
@if exist wso2-wsf-c-bin-1.2.0-win32 rmdir /s /q wso2-wsf-c-bin-1.2.0-win32
@call build.bat

rem Un-comment line below for Fail-safe Install
rem @if not %ERRORLEVEL% EQU 0 goto end

@if not exist wso2-wsf-c-bin-1.2.0-win32 goto end

rem Pack WSO2 WSF/C++
:pack_wsfcpp
@cd ..
@if not exist "%WSFCPP_HOME%" set WSFCPP_HOME=%CD%\wso2-wsf-cpp-bin-1.0.0-win32
@if exist "%WSFCPP_HOME%" rmdir /s /q "%WSFCPP_HOME%"
@mkdir "%WSFCPP_HOME%"
@cd "%WSFCPP_HOME%"
@xcopy /E /Q /I /Y ..\wsf_c\wso2-wsf-c-bin-1.2.0-win32 .
@copy /Y ..\INSTALL .
@copy /Y ..\README.INSTALL.WINDOWS .
@copy /Y ..\README .
@copy /Y ..\NEWS .
@copy /Y ..\COPYING .
@copy /Y ..\AUTHORS .
@copy /Y ..\NOTICE .
@xcopy /E /I /Q /Y ..\docs  docs
@cd ..

rem Remove WSF/C Client Samples
:strip_c_client_samples
@cd "%WSFCPP_HOME%\bin\samples"
@if exist rampart xcopy /E /Q /I /Y rampart ..\rampart
@cd ..\
@rmdir /s /q samples
@mkdir samples
@if exist rampart xcopy /E /Q /I /Y rampart samples\rampart
@if exist rampart rmdir /s /q rampart
@cd ..\..

rem Clean bin Folder
:clean_bin_dir
@cd "%WSFCPP_HOME%\bin"
@del *.exp
@del *.lib
@cd ..\..

rem Build Source
:build_source
@cd src
@nmake dist -f wsf.mk AUTOCONF=..\configure.in
@if not %ERRORLEVEL% EQU 0 goto end
@cd ..\include
@copy /Y *.h "%WSFCPP_HOME%\include"
@cd ..

:end
