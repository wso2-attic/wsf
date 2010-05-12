echo off

call init.bat

set WRD=%CD%
set DIL=%CD%\wso2-wsf-cpp-bin-%WSFCPP_VERSION%-win32

cd build\codegen\modules\distribution\target\ 

unzip wsf-cpp-1.0-bin.zip

cd wsf-cpp-1.0

if not exist %DIL%\bin\tools\codegen mkdir  %DIL%\bin\tools\codegen

xcopy /I /E /Q lib %DIL%\bin\tools\codegen\lib

cd %WRD%
xcopy /I /E /Q tools\codegen\wsdl2cpp %DIL%\bin\tools\codegen\wsdl2cpp
cd %WRD%
