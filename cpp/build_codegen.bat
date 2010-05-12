echo off

cd build\codegen

mvn clean install -Drelease

cd ..\..\..\
 
exit
