echo off

call init.bat

set DIL=%CD%\wso2-wsf-cpp-bin-%WSFCPP_VERSION%-win32

cd wsf_c\build\codegen

mvn clean install -Drelease

cd modules\distribution\target\ 

unzip wsf-cpp-1.0-bin.zip

cd wsf-cpp-1.0

if not exist %DIL%\bin\tools\codegen mkdir  %DIL%\bin\tools\codegen

xcopy lib %DIL%\bin\tools\codegen

cd %DIL%

