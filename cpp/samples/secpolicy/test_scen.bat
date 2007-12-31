@echo off
@set SAMPLE_DIR=%CD%

@IF "%2" == "" goto print_msg

rem Deploy and run scenario
@echo -------------------------------------------------------------------------
@echo >Deploying %1
@deploy.bat %1
@echo >Killing server
@taskkill /F /IM axis2_http_server.exe
@echo >Go to %AXIS2C_HOME%
@cd %AXIS2C_HOME%/bin
@echo >Start server @ %1

rem Start Server in Bgnd
@axis2_http_server.exe -p%2

@echo >Go to client directory
@cd %SAMPLE_DIR%
@echo >Run the sample
@update_n_run.bat
@taskkill /F /IM axis2_http_server.exe
@cd %SAMPLE_DIR%
@echo >Jump back to samples dir :%CD%


rem Print Message
:print_msg
@echo Usage : %0 scenarioX server-port

rem End
:end
@echo on