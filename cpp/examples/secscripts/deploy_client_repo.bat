echo off
echo -------------------------------------------------------------------------
echo deploying client repository .... 
echo -------------------------------------------------------------------------

rem if your client repository is different, change the value.
set CLIENT_REPO=%WSFCPP_HOME%\client_repo

echo Start creating a client repository at %CLIENT_REPO%

if exist  "%CLIENT_REPO%" (
    echo %CLIENT_REPO% exists.
) else (
    echo Creating a new directory for client repo
    mkdir "%CLIENT_REPO%"
)


@echo Copying axis2.xml to client_repo
copy /Y "%WSFCPP_HOME%\samples\src\c\rampartc\data\client_axis2.xml" "%CLIENT_REPO%\axis2.xml"
	  
call deploy.bat
echo off

@echo Copying libraries to client_repo
xcopy /S/I/Q/Y "%WSFCPP_HOME%\lib" "%CLIENT_REPO%\lib"

@echo Copying latest modules to client_repo
xcopy /S/I/Q/Y "%WSFCPP_HOME%\modules" "%CLIENT_REPO%\modules"

echo -------------------------------------------------------------------------
echo Client repository deployed to %CLIENT_REPO%
echo -------------------------------------------------------------------------
echo on
