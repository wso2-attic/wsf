@echo off

@call clean.bat

@copy configure.in wsf_c\configure.in

@cd wsf_c

@call build.bat

@cd ..


@mkdir wso2-wsf-php-bin-1.0

@xcopy /E /Q /I wsf_c\wso2-wsf-c-bin-1.0 wso2-wsf-php-bin-1.0\wsf_c

@if exist wso2-wsf-php-bin-1.0\wsf_c\services rmdir /S /Q wso2-wsf-php-bin-1.0\wsf_c\services

@if exist wso2-wsf-php-bin-1.0\wsf_c\modules\savan rmdir /S /Q wso2-wsf-php-bin-1.0\wsf_c\modules\savan

@if exist wso2-wsf-php-bin-1.0\wsf_c\modules\logging rmdir /S /Q wso2-wsf-php-bin-1.0\wsf_c\modules\logging

