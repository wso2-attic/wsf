@echo off
echo.
echo Building WSF Client...
echo.
ruby extconf-win32.rb
nmake 
nmake install
echo. 
echo Building WSF Service...
echo.
cd wsservice
ruby extconf-win32.rb
nmake
nmake install
cd ..
