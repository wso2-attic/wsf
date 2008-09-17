@echo off

REM ---------------------------------------------------------------------------
REM  Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
REM
REM  Licensed under the Apache License, Version 2.0 (the "License");
REM  you may not use this file except in compliance with the License.
REM  You may obtain a copy of the License at
REM
REM      http://www.apache.org/licenses/LICENSE-2.0
REM
REM  Unless required by applicable law or agreed to in writing, software
REM  distributed under the License is distributed on an "AS IS" BASIS,
REM  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
REM  See the License for the specific language governing permissions and
REM  limitations under the License.

rem ---------------------------------------------------------------------------
rem Main Script for the WSO2 WSF/Jython
rem
rem Environment Variable Prequisites
rem
rem   WSFJYTHON_HOME    Home of WSF/Jython installation. If not set I will  try
rem                     to figure it out.
rem
rem   JAVA_HOME       Must point at your Java Development Kit installation.
rem
rem   JAVA_OPTS       (Optional) Java runtime options used when the commands
rem                   is executed.
rem ---------------------------------------------------------------------------

rem ----- if JAVA_HOME is not set we're not happy ------------------------------
:checkJava

if "%JAVA_HOME%" == "" goto noJavaHome
if not exist "%JAVA_HOME%\bin\java.exe" goto noJavaHome
goto checkServer

:noJavaHome
echo "You must set the JAVA_HOME variable before running WSO2 Mashup Server."
goto end

rem ----- Only set WSFJYTHON_HOME if not already set ----------------------------
:checkServer
rem %~sdp0 is expanded pathname of the current script under NT with spaces in the path removed
if "%WSFJYTHON_HOME%"=="" set WSFJYTHON_HOME=%~sdp0..

rem find WSFJYTHON_HOME if it does not exist due to either an invalid value passed
rem by the user or the %0 problem on Windows 9x

goto updateClasspath

:noServerHome
echo WSFJYTHON_HOME is set incorrectly or WSO2 WSF/Jython could not be located. Please set WSFJYTHON_HOME.
goto end

rem ----- update classpath -----------------------------------------------------
:updateClasspath

setlocal EnableDelayedExpansion
cd %WSFJYTHON_HOME%
FOR %%C in (%WSFJYTHON_HOME%\lib\jars\*.jar) DO set WSFJYTHON_CLASSPATH=!WSFJYTHON_CLASSPATH!;./lib/jars/%%~nC%%~xC

FOR %%C in (%WSFJYTHON_HOME%\lib\mars\*.mar) DO set WSFJYTHON_CLASSPATH=!WSFJYTHON_CLASSPATH!;./lib/mars/%%~nC%%~xC

set WSFJYTHON_CLASSPATH="%JAVA_HOME%\lib\tools.jar";"%WSFJYTHON_HOME%\lib\jars";%WSFJYTHON_CLASSPATH%;%CLASSPATH%

rem ----- Process the input command -------------------------------------------

rem Slurp the command line arguments. This loop allows for an unlimited number
rem of arguments (up to the command line limit, anyway).

shift
rem goto setupArgs


rem ----- doneStart ------------------------------------------------------------
rem This label provides a place for the argument list loop to break out
rem and for NT handling to skip to.

:doneStart
if "%OS%"=="Windows_NT" @setlocal
if "%OS%"=="WINNT" @setlocal

rem ---------- Handle the SSL Issue with proper JDK version --------------------
rem find the version of the jdk
:findJdk

"%JAVA_HOME%\bin\java" -version 2>&1 | findstr "1.4" >NUL
IF ERRORLEVEL 1 goto checkJdk15
goto jdk14

:checkJdk15
"%JAVA_HOME%\bin\java" -version 2>&1 | findstr "1.5" >NUL
IF ERRORLEVEL 1 goto checkJdk16
goto jdk15

:checkJdk16
"%JAVA_HOME%\bin\java" -version 2>&1 | findstr "1.6" >NUL
IF ERRORLEVEL 1 goto unknownJdk
goto jdk16

:unknownJdk
echo [ERROR] WSO2 WSF/Jython is supported only on JDK 1.5 and higher
goto runServer

:jdk14
  echo [ERROR] WSO2 WSF/Jython is supported only on JDK 1.5 and higher
  goto end

:jdk15
  set WSFJYTHON_CLASSPATH="%WSFJYTHON_HOME%\lib\jars\bcprov-jdk15-132.jar";%WSFJYTHON_CLASSPATH%
	goto runServer
:jdk16
  set WSFJYTHON_CLASSPATH="%WSFJYTHON_HOME%\lib\jars\bcprov-jdk15-132.jar";%WSFJYTHON_CLASSPATH%
	goto runServer


rem ----------------- Execute The Requested Command ----------------------------

:runServer
cd %WSFJYTHON_HOME%

set JAVA_ENDORSED="%JAVA_HOME%\jre\lib\endorsed";"%JAVA_HOME%\lib\endorsed"

"%JAVA_HOME%\bin\java" -classpath %WSFJYTHON_CLASSPATH% %JAVA_OPTS% -Djava.endorsed.dirs=%JAVA_ENDORSED% org.python.util.jython %0

:end
goto endlocal

:endlocal
