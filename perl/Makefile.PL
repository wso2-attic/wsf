use ExtUtils::MakeMaker;
WriteMakefile(
        'NAME'    => 'WSO2::WSF::C',
        'LIBS'    => ['-laxutil -laxis2_minizip -lperl -laxis2_parser -laxis2_libxml2 -laxis2_axiom -laxis2_engine -laxis2_http_common -laxis2_http_sender -laxis2_http_receiver'],
	'OBJECT'  => 'WSFC_wrap.o',
);
