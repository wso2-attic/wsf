@echo off

rem @call clean.bat

@copy configure.in wsf_c\configure.in
@copy wsf_c_build.bat wsf_c\build.bat

@cd wsf_c

@call build.bat

@cd ..

@mkdir wso2-wsf-php-bin-1.1.0-win32

@xcopy /E /Q /Y /I wsf_c\wso2-wsf-c-bin-1.1.0 wso2-wsf-php-bin-1.1.0-win32\wsf_c

@if exist wso2-wsf-php-bin-1.1.0-win32\wsf_c\services rmdir /S /Q wso2-wsf-php-bin-1.1.0-win32\wsf_c\services

@if exist wso2-wsf-php-bin-1.1.0-win32\wsf_c\modules\savan rmdir /S /Q wso2-wsf-php-bin-1.1.0-win32\wsf_c\modules\savan

@if exist wso2-wsf-php-bin-1.1.0-win32\wsf_c\samples rmdir /S /Q wso2-wsf-php-bin-1.1.0-win32\wsf_c\samples

@if exist wso2-wsf-php-bin-1.1.0-win32\wsf_c\ides rmdir /S /Q wso2-wsf-php-bin-1.1.0-win32\wsf_c\ides

@if exist wso2-wsf-php-bin-1.1.0-win32\wsf_c\bin\samples rmdir /S /Q wso2-wsf-php-bin-1.1.0-win32\wsf_c\bin\samples

@if exist wso2-wsf-php-bin-1.1.0-win32\wsf_c\bin\tools rmdir /S /Q wso2-wsf-php-bin-1.1.0-win32\wsf_c\bin\tools

@if exist wso2-wsf-php-bin-1.1.0-win32\wsf_c\bin\docs rmdir /S /Q wso2-wsf-php-bin-1.1.0-win32\wsf_c\bin\docs

@if exist wso2-wsf-php-bin-1.1.0-win32\wsf_c\modules\logging rmdir /S /Q wso2-wsf-php-bin-1.1.0-win32\wsf_c\modules\logging

@if exist scripts xcopy /Y /I /Q /E scripts wso2-wsf-php-bin-1.1.0-win32\scripts

@if exist samples xcopy /Y /I /Q /E samples wso2-wsf-php-bin-1.1.0-win32\samples

@if exist docs xcopy /Y /I /Q /E docs wso2-wsf-php-bin-1.1.0-win32\docs

@if exist NOTICE copy /Y NOTICE wso2-wsf-php-bin-1.1.0-win32

@if exist README.INSTALL_WIN32 copy /Y README.INSTALL_WIN32 wso2-wsf-php-bin-1.1.0-win32

@if exist README.INSTALL copy /Y README.INSTALL wso2-wsf-php-bin-1.1.0-win32

@if exist LICENSE copy /Y LICENSE wso2-wsf-php-bin-1.1.0-win32

@if exist NEWS copy /Y NEWS wso2-wsf-php-bin-1.1.0-win32


@cd src

@nmake /nologo -f build.mk dist

@cd ..

