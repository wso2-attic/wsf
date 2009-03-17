@echo off
@set WSFCPP_SOURCE=%CD%
call init.bat
@cd wsf_c
@call clean.bat
@cd %WSFCPP_SOURCE%
@if exist wso2-wsf-cpp-bin-%WSFCPP_VERSION%-win32 rmdir /S /Q wso2-wsf-cpp-bin-%WSFCPP_VERSION%-win32
@if not exist int.msvc mkdir int.msvc
@for /F "tokens=*" %%G in ('dir /B /AD /S *int.msvc*') do rmdir /S /Q "%%G"
