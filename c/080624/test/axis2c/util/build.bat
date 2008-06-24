@echo off
@if not exist int.msvc mkdir int.msvc
@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" /I .\ /I ..\..\framework\include /I %WSFC_HOME%\include /Foint.msvc\ /c *.c
@link.exe /nologo /LIBPATH:%WSFC_HOME%\lib axutil.lib wso2_wsfc_unit.lib /OUT:test_util.exe int.msvc\*.obj
@if exist int.msvc rmdir /s /q int.msvc
@echo on