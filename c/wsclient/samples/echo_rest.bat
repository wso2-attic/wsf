@echo off

"%WSFC_HOME%\bin\wsclient" http://localhost:9090/axis2/services/echo/echoString < "%WSFC_HOME%\samples\bin\wsclient\data\echo.xml"

