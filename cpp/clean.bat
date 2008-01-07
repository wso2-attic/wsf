@echo off
@if exist wsf_c\axis2c\build\axis2c-bin-1.2.0-win32 rmdir /S /Q wsf_c\axis2c\build\axis2c-bin-1.2.0-win32
@if exist wsf_c\sandesha2c\build\sandesha2 rmdir /S /Q wsf_c\sandesha2c\build\sandesha2
@if exist wsf_c\rampartc\build\rampartc-1.0 rmdir /S /Q wsf_c\rampartc\build\rampartc-1.0
@if exist wsf_c\savanc\build\savanc rmdir /S /Q wsf_c\savanc\build\savanc
@if exist wsf_c\wso2-wsf-c-bin-1.2.0-win32 rmdir /S /Q wsf_c\wso2-wsf-c-bin-1.2.0-win32
@if exist wso2-wsf-cpp-bin-1.0.0-win32 rmdir /S /Q wso2-wsf-cpp-bin-1.0.0-win32
@if not exist int.msvc mkdir int.msvc
@for /F "tokens=*" %%G in ('dir /B /AD /S *int.msvc*') do rmdir /S /Q "%%G"
@if exist wsf_c\axis2c\build\deploy rmdir /S /Q wsf_c\axis2c\build\deploy
