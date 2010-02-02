@if "%VV32CALLED%"=="" goto call_vv32

:call_nmake
nmake -f adminservices.mk dist
@goto end

:call_vv32
@call vcvars32.bat > vc.tmp
@del vc.tmp
@set VV32CALLED="YES"
@goto call_nmake

:end
