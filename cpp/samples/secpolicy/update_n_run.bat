@echo off
rem If your client repository is different, change the value.
set CLIENT_REPO="%AXIS2C_HOME%\client_repo"

rem INSTALL MODULE to make sure that both server and client have the same module.
@echo Copying latest module to client_repo
@xcopy /E /I /Q /Y %AXIS2C_HOME%\modules\rampart %CLIENT_REPO%\modules

rem RUN
@../echo/echo_security %AXIS2C_HOME%\client_repo\
@echo on
