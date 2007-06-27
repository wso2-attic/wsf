@echo off

%WSFC_HOME%\bin\wsclient http://localhost:9090/axis2/services/echo < %WSFC_HOME%\bin\samples\wsclient\data\echo.xml

