@echo off
@call vcvars32.bat /nologo

@cd axis2c\build

@if exist axis2c-bin-1.1.0-win32 rmdir /s /q axis2c-bin-1.1.0-win32

@cd win32

@nmake dist 

@cd ..\..\..\rampartc\build\win32

@nmake dist AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-1.1.0-win32

@cd ..

@xcopy /E /Q /I rampartc-0.90\modules\rampart .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\modules\rampart

@copy /Y rampartc-0.90\include\*.h .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\include\

@mkdir .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\docs\ramaprt

@copy rampartc-0.90\INSTALL .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\docs\ramaprt

@copy rampartc-0.90\README .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\docs\ramaprt

@copy  rampartc-0.90\modules\rampart\mod_rampart.lib .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\lib\
@copy  rampartc-0.90\modules\rampart\mod_rampart.dll .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\lib\

@xcopy /E /I /Q rampartc-0.90\bin\samples .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\bin\samples\rampart

@xcopy /E /I /Q rampartc-0.90\bin\samples\services\sec_echo .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\services\sec_echo


@cd ..\..\sandesha2c\build\win32

@nmake dist AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-1.1.0-win32


@cd ..

@xcopy /E /Q /I sandesha2\modules\sandesha2 .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\modules\sandesha2

@xcopy /E /Q /I sandesha2\modules\sandesha2\sandesha2.lib  .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\lib\

@xcopy /E /Q /I sandesha2\modules\sandesha2\sandesha2.dll  .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\lib\

@copy sandesha2\samples\*.exe .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\bin\samples\

@xcopy /E /Q /I sandesha2\services\RMSampleService .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\services\RMSampleService


@copy /Y sandesha2\axis2.xml .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\axis2.xml

@copy /Y sandesha2\include\*.h  .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\include\

@copy /Y sandesha2\sqlite_schema.bat  .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\sqlite_schema.bat

@copy /Y  sandesha2\bin\samples .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\bin\samples

@mkdir .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\docs\sandesha2

@copy sandesha2\README .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\docs\sandesha2

@copy sandesha2\INSTALL .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\docs\sandesha2


@cd ..\..\

@cd axis2c\neethi\src\util

@nmake -f neethi_util.mk AXIS2_BIN_DIR=..\..\..\build\axis2c-bin-1.1.0-win32

@cd ..\..\..\..\

@cd wsclient

@nmake -f wsclient.mk AXIS2_BIN_DIR=..\axis2c\build\axis2c-bin-1.1.0-win32

@cd ..

@cd savanc\build\win32

@nmake dist AXIS2_BIN_DIR=.\..\..\..\axis2c\build\axis2c-bin-1.1.0-win32


@cd ..

@xcopy /E /Q /I savanc\modules\savan .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\modules\savan

@xcopy /E /Q /I savanc\services\publisher .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\services\publisher

@xcopy /E /Q /I savanc\services\listener .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\services\listener

@copy savanc\modules\savan\mod_savan.dll .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\lib\

@copy savanc\modules\savan\mod_savan.lib .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\lib\

@copy savanc\bin\samples\savan\*.exe .\..\..\axis2c\build\axis2c-bin-1.1.0-win32\bin\samples\

@cd ..\..


@if not exist wso2-wsf-c-bin-1.0alhpa2 mkdir wso2-wsf-c-bin-1.0alhpa2

@xcopy /E /Q /I axis2c\build\axis2c-bin-1.1.0-win32 wso2-wsf-c-bin-1.0alhpa2

@copy /Y config\axis2.xml wso2-wsf-c-bin-1.0alhpa2\axis2.xml

@copy /Y INSTALL wso2-wsf-c-bin-1.0alhpa2
@copy /Y README wso2-wsf-c-bin-1.0alhpa2
@copy /Y NEWS wso2-wsf-c-bin-1.0alhpa2
@copy /Y COPYING wso2-wsf-c-bin-1.0alhpa2
@copy /Y AUTHORS wso2-wsf-c-bin-1.0alhpa2





