@echo off
rem if your client repository is different, change the value.
set CLIENT_REPO=%WSFCPP_HOME%\client_repo

rem INSTALL MODULE to make sure that both server and client have the same module.
echo "Copying latest module to client_repo"
xcopy /E /Y /I "%WSFCPP_HOME%\modules\rampart" "%CLIENT_REPO%\modules\rampart"

%WSFCPP_HOME%\samples\bin\sec_echo.exe http://localhost:9090/axis2/services/sec_echo %CLIENT_REPO%

@echo on
