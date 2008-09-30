@echo off
call build\init.bat

if exist axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32 rmdir /S /Q axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32
if exist axis2c\build\deploy rmdir /S /Q axis2c\build\deploy
if exist axis2c\build\win32\int.msvc rmdir /S /Q axis2c\build\win32\int.msvc

if exist sandesha2c\build\sandesha2 rmdir /S /Q sandesha2c\build\sandesha2
if exist sandesha2c\build\win32\int.msvc rmdir /S /Q sandesha2c\build\win32\int.msvc

if exist rampartc\build\rampartc-%RAMPARTC_VERSION% rmdir /S /Q rampartc\build\rampartc-%RAMPARTC_VERSION%
if exist rampartc\build\win32\int.msvc rmdir /S /Q rampartc\build\win32\int.msvc

if exist savanc\build\savanc rmdir /S /Q savanc\build\savanc
if exist savanc\build\win32\int.msvc rmdir /S /Q savanc\build\win32\int.msvc

if exist wso2-wsf-c-bin-%WSFC_VERSION%-win32 rmdir /S /Q wso2-wsf-c-bin-%WSFC_VERSION%-win32


