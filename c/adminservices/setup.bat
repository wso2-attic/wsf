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

@goto install

:install
@echo.
@echo Step 4
@echo ------ 
@echo Installing services ... [OK]
@xcopy /E /Q /I /Y .\services %home%\services 
@echo Installing modules ... [OK]
@xcopy /E /Q /I /Y .\modules %home%\modules 
@echo Installing Carbon console ... [OK]
@xcopy /E /Q /I /Y .\carbon\wso2carbon-2.0.2 %carbon_home% 
@echo Customizing ... [OK]
@if "%product%"=="1" copy .\carbon\conf\carbon.c.xml %carbon_home%\conf\carbon.xml
@if "%product%"=="2" copy .\carbon\conf\carbon.cpp.xml %carbon_home%\conf\carbon.xml
@if "%product%"=="1" copy .\carbon\styles\org.wso2.wsas.styles-3.1.2.c.jar %carbon_home%\repository\components\plugins\org.wso2.wsas.styles-3.1.2.jar
@if "%product%"=="2" copy .\carbon\styles\org.wso2.wsas.styles-3.1.2.cpp.jar %carbon_home%\repository\components\plugins\org.wso2.wsas.styles-3.1.2.jar
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

:end
