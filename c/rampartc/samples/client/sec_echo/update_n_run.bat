@echo off
rem if your client repository is different, change the value.
set CLIENT_REPO=%AXIS2C_HOME%\clientrepo

rem INSTALL MODULE to make sure that both server and client have the same module.
echo "Copying latest module to client_repo"
xcopy /E /Y /I "%AXIS2C_HOME%\modules\rampart" "%CLIENT_REPO%\modules"

echo RUN echo.exe http://localhost:9090/axis2/services/echo %CLIENT_REPO%
"%AXIS2C_HOME%\bin\samples\rampart\client\enc_echo\enc_echo.exe" http://localhost:9090/axis2/services/echo "%CLIENT_REPO%"

@echo on
