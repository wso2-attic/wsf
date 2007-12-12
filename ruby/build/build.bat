@echo off
echo.
echo Building WSF Client...
echo.
ruby extconf-win32.rb
nmake 
mt.exe -manifest WSFC.so.manifest -outputresource:WSFC.so;2
nmake install
echo. 
echo Building WSF Service...
echo.
cd wsservice
ruby extconf-win32.rb
nmake
mt.exe -manifest wsservice.so.manifest -outputresource:wsservice.so;2
nmake install
cd ..
