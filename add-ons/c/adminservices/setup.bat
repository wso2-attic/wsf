@rem banner
@echo.
@echo /****************************************************/
@echo /*     WSO2 WSF/{C,CPP} Admin Console Installer     */
@echo /****************************************************/

@set product=
@set home=
@set carbon_home=

@rem select product
@echo.
@echo Step 1
@echo ------
@echo 	1. WSO2 WSF/C
@echo 	2. WSO2 WSF/C++
@echo.
@set /p product= "Select target product : "

@if "%product%"=="1" goto prod_c
@if "%product%"=="2" goto prod_cpp

@goto end_prod_error

:prod_c
@echo.
@echo Step 2
@echo ------ 
@set /p home= "Specify your WSO2 WSF/C home : " 
@echo.

@if not exist %home% goto end_home_error

@goto carbon

:prod_cpp
@echo.
@echo Step 2
@echo ------ 
@set /p home= "Specify your WSO2 WSF/C++ home : " 
@echo.

@if not exist %home% goto end_home_error

@goto carbon

:carbon
@echo.
@echo Step 3
@echo ------ 
@set /p carbon_home= "Specify where you want to install WSO2 Carbon Console : " 
@echo.

@if not exist %carbon_home% goto end_carbon_error

@goto deploy_services

:deploy_services
@echo.
@echo Step 4
@echo ------ 
@xcopy /E /Q /I /Y .\services %home%\services 
@if not errorlevel 0 goto deploy_services_error 
@echo Installing services ... [OK]
@goto deploy_modules

:deploy_modules
@echo.
@xcopy /E /Q /I /Y .\modules %home%\modules 
@if not errorlevel 0 goto deploy_modules_error
@echo Installing modules ... [OK]
@goto deploy_carbon 

:deploy_carbon
@echo.
@xcopy /E /Q /I /Y .\carbon\wso2carbon-2.0.2 %carbon_home%\wso2carbon-2.0.2 
@if not errorlevel 0 goto deploy_carbon_error
@echo Installing Carbon console ... [OK]
@goto customize_services

:customize_services
@echo.
@deploy.js %home%\services\SecurityAdminService\policies\scenario1-policy.xml %home%
@echo Customizing services ... [OK]
@goto customize_carbon

:customize_carbon
@echo.
@if "%product%"=="1" copy .\carbon\conf\carbon.c.xml %carbon_home%\wso2carbon-2.0.2\conf\carbon.xml
@if not errorlevel 0 goto customize_carbon_error
@if "%product%"=="2" copy .\carbon\conf\carbon.cpp.xml %carbon_home%\wso2carbon-2.0.2\conf\carbon.xml
@if not errorlevel 0 goto customize_carbon_error
@if "%product%"=="1" copy .\carbon\styles\org.wso2.wsas.styles-3.1.2.c.jar %carbon_home%\wso2carbon-2.0.2\repository\components\plugins\org.wso2.wsas.styles-3.1.2.jar
@if not errorlevel 0 goto customize_carbon_error
@if "%product%"=="2" copy .\carbon\styles\org.wso2.wsas.styles-3.1.2.cpp.jar %carbon_home%\wso2carbon-2.0.2\repository\components\plugins\org.wso2.wsas.styles-3.1.2.jar
@if not errorlevel 0 goto customize_carbon_error
@echo Customizing Carbon ... [OK]
@echo.
@echo Admin installed successfully ...
@goto end 

:end_prod_error
@echo.
@echo [ERROR] Target product has to be either "1" or "2"
@goto end

:end_home_error
@echo.
@echo [ERROR] The path does not exist
@goto end

:end_carbon_error
@echo.
@echo [ERROR] The path does not exist
@goto end

:deploy_services_error
@echo.
@echo Installing services ... [ERROR]
@goto end

:deploy_modules_error
@echo.
@echo Installing modules ... [ERROR]
@goto end

:deploy_carbon_error
@echo.
@echo Installing Carbon console ... [ERROR]
@goto end

:customize_services_error
@echo.
@echo Customizing services ... [ERROR]
@goto end

:customize_carbon_error
@echo.
@echo Customizing Carbon ... [ERROR]
@goto end

:end
