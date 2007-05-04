echo: 
	@cl.exe /nologo /D "WIN32" /D "_WINDOWS" /D "AXIS2_DECLARE_EXPORT" /D "_MBCS" echo_blocking_soap11.C echo_util.c /I.\..\..\..\include /c
	@link.exe /nologo echo_blocking_soap11.obj echo_util.obj /LIBPATH:.\..\..\..\lib axiom.lib axutil.lib axis2_engine.lib axis2_parser.lib /OUT:echo_blocking_soap11.exe

	



