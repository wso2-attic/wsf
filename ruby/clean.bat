@echo off

@call init.bat
@call .\wsf_c\build\init.bat

@cd wsf_c

@call clean.bat

@cd ..

@if exist wsf_c\wso2-wsf-c-bin-%WSFC_VERSION% rmdir /S /Q wsf_c\wso2-wsf-c-bin-%WSFC_VERSION%

@if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32 rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist wsf_c\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32 rmdir /s /q wsf_c\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32

@if exist wsf_c\axis2c\build\deploy rmdir /s /q wsf_c\axis2c\build\deploy

@if exist wsf_c\axis2c\build\win32\int.msvc rmdir /s /q wsf_c\axis2c\build\win32\int.msvc

@if exist wsf_c\rampartc\build\rampartc-%RAMPARTC_VERSION% rmdir /s /q wsf_c\rampartc\build\rampartc-%RAMPARTC_VERSION%

@if exist wsf_c\rampartc\build\win32\int.msvc rmdir /s /q wsf_c\rampartc\build\win32\int.msvc

@if exist wsf_c\sandesha2c\build\sandesha2 rmdir /s /q wsf_c\sandesha2c\build\sandesha2

@if exist wsf_c\sandesha2c\build\win32\int.msvc rmdir /s /q wsf_c\sandesha2c\build\win32\int.msvc

@if exist src\intdir rmdir /s /q src\intdir

@del /Q *.obj

@del /Q /F *.pdb
 
@del /Q /F *.lib

@del /Q /F mkmf.log

@del /Q /F *.manifest

@del /Q /F makefile

@del /Q /F *.dll

@del /Q /F *.so

@del /Q /F *.exp

