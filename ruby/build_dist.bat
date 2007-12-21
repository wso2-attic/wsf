@echo off

rem @call clean.bat

@copy configure.in wsf_c\configure.in
@copy wsf_c_build.bat wsf_c\build.bat

@cd wsf_c

@call build.bat

@cd ..

@mkdir wso2-wsf-ruby-bin-1.0.0-win32

@xcopy /E /Q /Y /I wsf_c\wso2-wsf-c-bin-1.2.0 wso2-wsf-ruby-bin-1.0.0-win32\wsf_c

@if exist wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\services rmdir /S /Q wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\services

@if exist wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\modules\savan rmdir /S /Q wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\modules\savan

@if exist wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\samples rmdir /S /Q wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\samples

@if exist wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\ides rmdir /S /Q wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\ides

@if exist wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\bin\samples rmdir /S /Q wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\bin\samples

@if exist wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\bin\tools rmdir /S /Q wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\bin\tools

@if exist wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\bin\docs rmdir /S /Q wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\bin\docs

@if exist wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\modules\logging rmdir /S /Q wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\modules\logging

rem @if exist xcopy /Y /I /Q /E scripts wso2-wsf-ruby-bin-1.0.0-win32\scripts

@if exist lib xcopy /Y /I /Q /E lib wso2-wsf-ruby-bin-1.0.0-win32\lib

@if exist samples xcopy /Y /I /Q /E samples wso2-wsf-ruby-bin-1.0.0-win32\samples

@if exist docs xcopy /Y /I /Q /E docs wso2-wsf-ruby-bin-1.0.0-win32\docs

@if exist NOTICE copy /Y NOTICE wso2-wsf-ruby-bin-1.0.0-win32

@if exist INSTALL copy /Y INSTALL wso2-wsf-ruby-bin-1.0.0-win32

@if exist README.SAMPLES copy /Y README.SAMPLES wso2-wsf-ruby-bin-1.0.0-win32

@if exist README copy /Y README wso2-wsf-ruby-bin-1.0.0-win32

@if exist LICENSE copy /Y LICENSE wso2-wsf-ruby-bin-1.0.0-win32

@if exist find_config_h.rb copy /Y find_config_h.rb wso2-wsf-ruby-bin-1.0.0-win32

@if exist NEWS copy /Y NEWS wso2-wsf-ruby-bin-1.0.0-win32

@if exist README.INSTALL_WIN32 copy /Y README.INSTALL_WIN32  wso2-wsf-ruby-bin-1.0.0-win3

@if exist install.rb copy /Y install.rb wso2-wsf-ruby-bin-1.0.0-win32

@if exist find_rbconfig.rb copy /Y find_rbconfig.rb wso2-wsf-ruby-bin-1.0.0-win32

rem @cd src

rem @nmake /nologo -f build.mk dist

@call build.bat

@if exist WSFC.so copy /Y WSFC.so wso2-wsf-ruby-bin-1.0.0-win32\lib

cd wsservice

@if exist wsservice.so copy /Y wsservice.so ..\wso2-wsf-ruby-bin-1.0.0-win32\lib

cd ..

@if exist sqlite-3_3_81 cd sqlite-3_3_81

@if exist sqlite3.dll copy /Y sqlite3.dll ..\wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\lib

@if exist sqlite3.exe copy /Y sqlite3.exe ..\wso2-wsf-ruby-bin-1.0.0-win32\wsf_c\lib

@if exist sqlite3.exe cd ..

