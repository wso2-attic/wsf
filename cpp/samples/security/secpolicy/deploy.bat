@echo off
::Here we have scenario 5 as the default 
SET scn=scenario5
IF NOT "%1" == "" SET scn=%1

echo Deploying %scn%
echo Copying %scn%\client policy file
deploy.js %scn%\client-policy.xml %WSFCPP_HOME%\client_repo\policy.xml
echo Copying %scn%\services.xml
deploy.js %scn%\services.xml %WSFCPP_HOME%\services\sec_echo\services.xml
@echo on
