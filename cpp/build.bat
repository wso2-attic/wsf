@echo off
@call vcvars32.bat /nologo

@call clean.bat

rem Build WSO2 WSF/C
@copy configure.in wsf_c\configure.in
@copy wsf_c_build.bat wsf_c\build.bat
@cd wsf_c
@call build.bat

rem Un-comment line below for Fail-safe Install
rem @if not %ERRORLEVEL% EQU 0 goto end

rem Pack WSO2 WSF/C++
:pack_wsfcpp
@cd ..
@set WSFCPP_SOURCE=%CD%
@if not exist "%WSFCPP_HOME%" set WSFCPP_HOME=%CD%\wso2-wsf-cpp-bin-%WSFCPP_VERSION%-win32
@if exist "%WSFCPP_HOME%" rmdir /s /q "%WSFCPP_HOME%"
@mkdir "%WSFCPP_HOME%"
@cd "%WSFCPP_HOME%"
@xcopy /E /Q /I /Y "%WSFCPP_SOURCE%\wsf_c\wso2-wsf-c-bin-%WSFC_VERSION%" .
@copy /Y "%WSFCPP_SOURCE%\INSTALL" .
@copy /Y "%WSFCPP_SOURCE%\README.INSTALL.WINDOWS" .
@copy /Y "%WSFCPP_SOURCE%\README.SAMPLES" .
@copy /Y "%WSFCPP_SOURCE%\README" .
@copy /Y "%WSFCPP_SOURCE%\NEWS" .
@copy /Y "%WSFCPP_SOURCE%\COPYING" .
@copy /Y "%WSFCPP_SOURCE%\AUTHORS" .
@copy /Y "%WSFCPP_SOURCE%\NOTICE" .
@cd "%WSFCPP_SOURCE%"

rem Add HTML Documentation
:add_html_docs
@set WSFCPP_SOURCE=%CD%
@cd "%WSFCPP_HOME%"
@mkdir docs_temp
@xcopy /E /I /Q /Y docs  docs_temp
@rmdir /S /Q docs
@mkdir docs
@mkdir docs\wsf_c
@xcopy /E /I /Q /Y "%WSFCPP_SOURCE%\docs"  docs\cpp
@xcopy /E /I /Q /Y docs_temp  docs\wsf_c\docs
@rmdir /S /Q docs_temp
@if exist wsclient\docs\index.html mkdir docs\wsf_c\wsclient
@if exist docs\wsf_c\wsclient mkdir docs\wsf_c\wsclient\docs
@if exist docs\wsf_c\wsclient\docs copy /Y wsclient\docs\index.html docs\wsf_c\wsclient\docs\
@if exist docs\wsf_c\docs\wsclient mkdir docs\wsf_c\wsclient
@if exist docs\wsf_c\docs\wsclient xcopy /E /I /Q /Y docs\wsf_c\docs\wsclient docs\wsf_c\wsclient
@if exist docs\wsf_c\docs\wsclient rmdir /S /Q docs\wsf_c\docs\wsclient
@if exist docs\wsf_c\wsclient\index.html mkdir docs\wsf_c\wsclient\docs
@if exist docs\wsf_c\wsclient\index.html copy /Y docs\wsf_c\wsclient\index.html docs\wsf_c\wsclient\docs\
@if exist docs\wsf_c\wsclient\index.html del docs\wsf_c\wsclient\index.html
@if exist docs\wsf_c\docs\axis2c rmdir /S /Q docs\wsf_c\docs\axis2c
@if exist docs\wsf_c\docs\rampartc rmdir /S /Q docs\wsf_c\docs\rampartc
@if exist docs\wsf_c\docs\sandesha2c rmdir /S /Q docs\wsf_c\docs\sandesha2c
@cd "%WSFCPP_SOURCE%"

rem Remove WSF/C Client Samples
:strip_c_client_samples
@set WSFCPP_SOURCE=%CD%
@cd "%WSFCPP_HOME%\bin\samples"
@if exist security xcopy /E /Q /I /Y security ..\security
@cd ..\
@rmdir /s /q samples
@mkdir samples
@if exist security xcopy /E /Q /I /Y security samples\security
@if exist security rmdir /s /q security
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
@cd examples
@nmake dist -f samples.mk AUTOCONF=..\configure.in
@if not %ERRORLEVEL% EQU 0 goto end
@cd "%WSFCPP_HOME%\bin\samples\cpp"
@if not exist .svn mkdir .svn
@for /F "tokens=*" %%G in ('dir /B /AD /S *.svn*') do rmdir /S /Q "%%G"
@if not exist *.sh echo > #.sh
@for /F "tokens=*" %%G in ('dir /B /S *.sh*') do del "%%G"
@if not exist *.am echo > #.am
@for /F "tokens=*" %%G in ('dir /B /S *.am*') do del "%%G"
@cd "%WSFCPP_SOURCE%"

rem Build security Samples
@set WSFCPP_SOURCE=%CD%
@cd "%WSFCPP_HOME%\bin\samples"
@if exist security xcopy /E /Q /I /Y security cpp\security
@if exist security rmdir /S /Q security 
@cd cpp\security
@mkdir client
@cd "%WSFCPP_SOURCE%"
@cd samples
@cd security
@xcopy /E /Q /I /Y secpolicy %WSFCPP_HOME%\bin\samples\cpp\security\secpolisy
@nmake dist -f sec_samples.mk AUTOCONF=..\..\configure.in
@if not %ERRORLEVEL% EQU 0 goto end
@cd "%WSFCPP_HOME%\bin\samples\cpp\security"
@if not exist .svn mkdir .svn
@for /F "tokens=*" %%G in ('dir /B /AD /S *.svn*') do rmdir /S /Q "%%G"
@if not exist *.sh echo > #.sh
@for /F "tokens=*" %%G in ('dir /B /S *.sh*') do del "%%G"
@if not exist *.am echo > #.am
@for /F "tokens=*" %%G in ('dir /B /S *.am*') do del "%%G"
@cd "%WSFCPP_SOURCE%"
 
rem Deploy Sample Source
:dep_sample_source
@if exist "%WSFCPP_HOME%\samples" rmdir /s /q "%WSFCPP_HOME%\samples"
@xcopy /E /I /Q /Y samples "%WSFCPP_HOME%\samples"
@copy /Y configure.in "%WSFCPP_HOME%"
@set WSFCPP_SOURCE=%CD%
@cd "%WSFCPP_HOME%\samples"
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
