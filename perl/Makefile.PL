use ExtUtils::MakeMaker;
WriteMakefile(
    'NAME'    => 'WSO2::WSF::C',
    'INC'    => '-I/opt/wso2/wsf_c/include/axis2-1.2 -I/opt/wso2/wsf_c/include/rampart-1.0',
    'LIBS'    => ['-L/opt/wso2/wsf_c/lib -laxutil -laxis2_minizip -lperl -laxis2_parser -laxis2_libxml2 -laxis2_axiom -laxis2_engine -laxis2_http_common -laxis2_http_sender -laxis2_http_receiver -lneethi_util -lneethi -laxis2_parser -laxis2_xmpp_receiver -laxis2_xmpp_sender -lhtpwcb -lomopenssl -lomxmlsec -lsaml -lsandesha2_client -lsavan_client'],
    'OBJECT'  => 'WSFC_wrap.o',
);
