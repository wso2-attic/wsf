@echo off
if "%1" == "" goto end
if "%2" == "" goto end

set _SMPL_DIR=%cd%
set _SLEEP=3

echo -------------------------------------------------------------------------
echo Deploying %1
echo -------------------------------------------------------------------------

call deploy.bat %1
@echo off

echo Killing server
taskkill /F /IM axis2_http_server.exe

echo Go to %WSFCPP_HOME%
cd %WSFCPP_HOME%/bin

echo Start server @ %2
start /min axis2_http_server.exe -p%2

rem echo Sleeping for %_SLEEP% seconds
echo waiting.......
pause %_SLEEP%

echo Go to client directory
if not "%1" == "scenario14"  goto else
	cd %_SMPL_DIR%/../client/saml_echo
	goto endif
:else
	cd %_SMPL_DIR%/../client/sec_echo
:endif

echo Run the sample
call update_n_run.bat
@echo off

echo Killing server
taskkill /F /IM axis2_http_server.exe

echo Jump back to samples dir :%_SMPL_DIR%
cd %_SMPL_DIR%

goto superend

:end
echo usage %0 scenarioxx server_port

:superend
if "%3" == "" @echo on
