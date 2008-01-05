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
@set WSFCPP_SOURCE=%CD%
@if not exist "%WSFCPP_HOME%" set WSFCPP_HOME=%CD%\wso2-wsf-cpp-bin-1.0.0-win32
@if exist "%WSFCPP_HOME%" rmdir /s /q "%WSFCPP_HOME%"
@mkdir "%WSFCPP_HOME%"
@cd "%WSFCPP_HOME%"
@xcopy /E /Q /I /Y "%WSFCPP_SOURCE%\wsf_c\wso2-wsf-c-bin-1.2.0-win32" .
@copy /Y "%WSFCPP_SOURCE%\INSTALL" .
@copy /Y "%WSFCPP_SOURCE%\README.INSTALL.WINDOWS" .
@copy /Y "%WSFCPP_SOURCE%\README.SAMPLES" .
@copy /Y "%WSFCPP_SOURCE%\README" .
@copy /Y "%WSFCPP_SOURCE%\NEWS" .
@copy /Y "%WSFCPP_SOURCE%\COPYING" .
@copy /Y "%WSFCPP_SOURCE%\AUTHORS" .
@copy /Y "%WSFCPP_SOURCE%\NOTICE" .
@xcopy /E /I /Q /Y "%WSFCPP_SOURCE%\docs"  docs
@cd "%WSFCPP_SOURCE%"

rem Remove WSF/C Client Samples
:strip_c_client_samples
@set WSFCPP_SOURCE=%CD%
@cd "%WSFCPP_HOME%\bin\samples"
@if exist rampart xcopy /E /Q /I /Y rampart ..\rampart
@cd ..\
@rmdir /s /q samples
@mkdir samples
@if exist rampart xcopy /E /Q /I /Y rampart samples\rampart
@if exist rampart rmdir /s /q rampart
@cd "%WSFCPP_SOURCE%"

rem Clean bin Folder
:clean_bin_dir
@set WSFCPP_SOURCE=%CD%
@cd "%WSFCPP_HOME%\bin"
@del *.exp
@del *.lib
@cd "%WSFCPP_SOURCE%"

rem Build Source
:build_source
@cd src
@nmake dist -f wsf.mk AUTOCONF=..\configure.in
@if not %ERRORLEVEL% EQU 0 goto end
@cd ..\include
@copy /Y *.h "%WSFCPP_HOME%\include"
@cd ..

rem Build Client Samples
:build_client_samples
@set WSFCPP_SOURCE=%CD%
@cd "%WSFCPP_HOME%\bin\samples"
@if exist cpp rmdir /s /q cpp
@mkdir cpp
@cd "%WSFCPP_SOURCE%"
@cd samples
@nmake dist -f samples.mk AUTOCONF=..\configure.in
@if not %ERRORLEVEL% EQU 0 goto end
@xcopy /E /I /Q /Y secpolicy "%WSFCPP_HOME%\bin\samples\cpp\secpolicy"
@cd "%WSFCPP_HOME%\bin\samples\cpp"
@for /F "tokens=*" %%G in ('dir /B /AD /S *.svn*') do rmdir /S /Q %%G
@for /F "tokens=*" %%G in ('dir /B /S *.sh*') do del %%G
@for /F "tokens=*" %%G in ('dir /B /S *.am*') do del %%G
@cd "%WSFCPP_SOURCE%"

rem Deploy Sample Source
:dep_sample_source
@if exist "%WSFCPP_HOME%\samples" rmdir /s /q "%WSFCPP_HOME%\samples"
@xcopy /E /I /Q /Y samples "%WSFCPP_HOME%\samples"
@copy /Y configure.in "%WSFCPP_HOME%"
@set WSFCPP_SOURCE=%CD%
@cd "%WSFCPP_HOME%\samples"
@for /F "tokens=*" %%G in ('dir /B /AD /S *.svn*') do rmdir /S /Q %%G
@for /F "tokens=*" %%G in ('dir /B /AD /S int.msvc') do rmdir /S /Q %%G
@for /F "tokens=*" %%G in ('dir /B /S *.sh*') do del %%G
@for /F "tokens=*" %%G in ('dir /B /S *.am*') do del %%G
@cd "%WSFCPP_SOURCE%"

:end
