@echo off
::Here we have scenario 5 as the default 
SET scn=scenario5
IF NOT "%1" == "" SET scn=%1

echo Deploying %scn%
echo Copying %scn%\client policy file
copy  %scn%\client-policy.xml %AXIS2C_HOME%\client_repo\policy.xml
echo Copying %scn%\services.xml
copy  %scn%\services.xml %AXIS2C_HOME%\services\sec_echo\services.xml
echo Please change path name settings in following files before running the client
echo   1. %AXIS2C_HOME%\client_repo\policy.xml
echo   2. %AXIS2C_HOME%\services\sec_echo\services.xml
pause
@echo on