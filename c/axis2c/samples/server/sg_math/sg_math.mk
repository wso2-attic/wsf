echo:
	@cl.exe /nologo /D "WIN32" /D "AXIS2_DECLARE_EXPORT" /D "_WINDOWS" /D "_MBCS" add.c add_skeleton.c /I.\..\..\..\include /c
	@link.exe /nologo add.obj /LIBPATH:.\..\..\..\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib /DLL /OUT:add.dll

	
	@cl.exe /nologo /D "WIN32" /D "AXIS2_DECLARE_EXPORT" /D "_WINDOWS" /D "_MBCS" div.c div_skeleton.c /I.\..\..\..\include /c
	@link.exe /nologo div.obj /LIBPATH:.\..\..\..\lib axiom.lib axis2_util.lib axis2_engine.lib axis2_parser.lib /DLL /OUT:div.dll


	@cl.exe /nologo /D "WIN32" /D "AXIS2_DECLARE_EXPORT" /D "_WINDOWS" /D "_MBCS" sub.c sub_skeleton.c /I.\..\..\..\include /c
	@link.exe /nologo sub.obj /LIBPATH:.\..\..\..\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib /DLL /OUT:sub.dll


	@cl.exe /nologo /D "WIN32" /D "AXIS2_DECLARE_EXPORT" /D "_WINDOWS" /D "_MBCS" mul.c mul_skeleton.c /I.\..\..\..\include /c
	@link.exe /nologo mul.obj /LIBPATH:.\..\..\..\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib /DLL /OUT:mul.dll
