
echo:
	@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" *.C  /I..\..\axis2c\build\axis2c-bin-1.3.0-win32\include /c
	@link.exe /nologo *.obj /LIBPATH:..\..\axis2c\build\axis2c-bin-1.3.0-win32\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib   /OUT:flickr.exe

	



