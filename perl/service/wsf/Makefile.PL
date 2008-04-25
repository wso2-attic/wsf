use ExtUtils::MakeMaker;
use WSO2::WSF::WSConfig;

# Run SWIG interface wrapper
print "Generating SWIG interface files ...\n";
system ("swig -perl -I./swig -outdir ../ wsf.i");

WriteMakefile ("NAME" => "WSO2::WSF::WSFC",
			   "INC" => "-I$WSO2::WSF::WSConfig::WSFC_HOME\\include",
			   "LIBS" => ["-L$WSO2::WSF::WSConfig::WSFC_HOME\\lib 
			   			   -laxutil 
						   -laxis2_parser 
						   -laxiom 
						   -laxis2_engine 
						   -laxis2_http_sender "],
			   "OBJECT" => "wsf.o 
			   				wsf_wrap.o 
							wsf_xml_msg_recv.o 
							wsf_worker.o 
							wsf_out_transport_info.o 
							wsf_stream.o");
