@echo off
@call vcvars32.bat /nologo

@call clean.bat

@cd .\wsf_c\axis2c\build

@if exist axis2c-bin-1.0.0-win32 rmdir /s /q axis2c-bin-1.0.0-win32

@cd win32

@nmake dist

@if exist ..\axis2c-bin-1.0.0-win32\bin\samples\logging rmdir ..\axis2c-bin-1.0.0-win32\bin\samples\logging

@cd .\..\..\..\rampartc\build\win32

@nmake dist

@cd .\..

@xcopy /E /Q /I rampartc-0.90\modules\rampart .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\modules\rampart

@copy /Y rampartc-0.90\modules\rampart\mod_rampart.lib .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\lib\
@copy /Y rampartc-0.90\modules\rampart\mod_rampart.dll .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\lib\


@cd ..\..\sandesha2c\build\win32

@nmake dist

@cd ..

@xcopy /E /Q /I sandesha2\modules\sandesha2 .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\modules\sandesha2

@copy sandesha2\bin\samples\*.exe .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\bin\samples\

@if exist .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\services rmdir /s /q .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\services

rem @xcopy /E /Q /I sandesha2\services\RMSampleService .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\services\RMSampleService


@copy /Y sandesha2\axis2.xml .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\axis2.xml

@copy /Y sandesha2\sqlite_schema.bat  .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\sqlite_schema.bat

@copy /Y %SQLITE_HOME%\sqlite3.dll .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\lib\

@copy /Y %SQLITE_HOME%\sqlite3.exe .\..\..\axis2c\build\axis2c-bin-1.0.0-win32\lib\


@cd ..\..\..\

@mkdir wso2-wsf-php-bin-1.0alpha2

@xcopy /E /Q /I wsf_c\axis2c\build\axis2c-bin-1.0.0-win32 wso2-wsf-php-bin-1.0alpha2\wsf_c

@xcopy /E /Q /I src\scripts wso2-wsf-php-bin-1.0alpha2\scripts

@mkdir wso2-wsf-php-bin-1.0alpha2\docs

@xcopy /E /Q /I src\xdocs wso2-wsf-php-bin-1.0alpha2\docs\


@XCOPY /E /Q /I src\samples wso2-wsf-php-bin-1.0alpha2\samples

@copy /Y src\README* wso2-wsf-php-bin-1.0alpha2\docs\

@copy /Y src\LICENSE wso2-wsf-php-bin-1.0alpha2\
























