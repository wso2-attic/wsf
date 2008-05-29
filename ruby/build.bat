@echo off

@call vcvars32.bat /nologo

@echo.

@echo Building WSF Client...

@echo.

ruby extconf.rb

nmake 

mt.exe -manifest WSFC.so.manifest -outputresource:WSFC.so;2

nmake install

echo. 

echo Building WSF Service...

echo.

@cd wsservice

ruby extconf.rb

nmake

mt.exe -manifest wsservice.so.manifest -outputresource:wsservice.so;2

nmake install

cd .. 


