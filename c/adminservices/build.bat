@if "%1"=="" goto usage

@if "%VV32CALLED%"=="" goto call_vv32

:call_nmake
call ..\build\init.bat
nmake -f adminservices.mk %1
@goto end

:call_vv32
@call vcvars32.bat > vc.tmp
@del vc.tmp
@set VV32CALLED="YES"
@goto call_nmake

:usage
@echo Usage : build.bat {all, mkdist}

:end
