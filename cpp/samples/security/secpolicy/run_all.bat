@echo off
set _SCEN=scenario
set _PORT=9090

IF NOT "%1" == "" SET _PORT=%1
echo Using port %_PORT% to start the server



for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 21 22 23 25 26) do call test_scen.bat %_SCEN%%%i %_PORT% off
    
taskkill /F /IM axis2_http_server.exe
echo DONE

pause
@echo on
