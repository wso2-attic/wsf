echo off

cd wsf_c\build\codegen

mvn clean install -Drelease

cd ..\..\..\
 
exit
