echo:
	@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "_MBCS" *.C /I.\..\..\..\include /c
	@link.exe /nologo *.obj /LIBPATH:.\..\..\..\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib /DLL /OUT:echo.dll

	



