use ExtUtils::MakeMaker;

# Run SWIG interface wrapper
print "Generating SWIG interface files ...\n";
system ("swig -perl -I./swig -outdir ../ wsf.i");

my $wsfc_home = $ENV{WSFC_HOME} || '/home/dinesh/wsf_c/deploy';

WriteMakefile ("NAME" => "WSO2::WSF::Server",
               "INC" => "-I. -I$wsfc_home/include/axis2-1.6.0",
               "LIBS" => ["-L$wsfc_home/lib -L .
			   -laxutil
			   -laxis2_parser
			   -laxiom
                           -laxis2_engine
			   -laxis2_http_sender "],
               "OBJECT" => "wsf.o
			    wsf_wrap.o
			    wsf_xml_msg_recv.o
			    wsf_worker.o
			    wsf_util.o
			    wsf_out_transport_info.o
			    wsf_stream.o");
