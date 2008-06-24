!include "..\..\build\versions.in"

echo:
	cl.exe /nologo /D "_CRT_SECURE_NO_DEPRECATE" /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" *.C  /I..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\include /c
	link.exe /nologo *.obj /LIBPATH:..\..\axis2c\build\axis2c-bin-$(AXIS2C_VERSION)-win32\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib   /OUT:flickr.exe

	



