@echo off
echo. 
echo Building WSF Service...
echo.
cd wsservice
ruby extconf-win32.rb
nmake
mt.exe -manifest wsservice.so.manifest -outputresource:wsservice.so;2
nmake install
cd ..
