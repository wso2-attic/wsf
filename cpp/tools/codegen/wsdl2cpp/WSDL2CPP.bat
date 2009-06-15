echo off
setlocal EnableDelayedExpansion
set CODEGEN_HOME=%CD%\..
set CODEGEN_CLASSPATH=%CODEGEN_HOME%
FOR %%c in ("%CODEGEN_HOME%\lib\*.jar") DO set CODEGEN_CLASSPATH=!CODEGEN_CLASSPATH!;%%c;

java -classpath %CODEGEN_CLASSPATH% org.apache.axis2.wsdl.WSDL2CPP %*


