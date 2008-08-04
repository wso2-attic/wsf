echo off
echo -------------------------------------------------------------------------
echo deploying client repository .... 
echo -------------------------------------------------------------------------

rem if your client repository is different, change the value.
set CLIENT_REPO=%AXIS2C_HOME%\client_repo

echo Start creating a client repository at %CLIENT_REPO%

if exist  "%CLIENT_REPO%" (
    echo %CLIENT_REPO% exists.
) else (
    echo Creating a new directory for client repo
    mkdir "%CLIENT_REPO%"
)


@echo Copying axis2.xml to client_repo
copy /Y ".\data\client.axis2.xml" "%CLIENT_REPO%\axis2.xml"
	  
copy /Y ".\..\..\secpolicy\scenario5\client-policy.xml" "%CLIENT_REPO%\policy.xml"

@echo Copying libraries to client_repo
xcopy /S/I/Q/Y "%AXIS2C_HOME%\lib" "%CLIENT_REPO%\lib"

@echo Copying latest modules to client_repo
xcopy /S/I/Q/Y "%AXIS2C_HOME%\modules" "%CLIENT_REPO%\modules"

echo -------------------------------------------------------------------------
echo Client repository deployed to %CLIENT_REPO%
echo -------------------------------------------------------------------------
echo on
