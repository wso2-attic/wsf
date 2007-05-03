package WSO2::WSF::WSClient;

use 5.008008;
# use strict;
use warnings;
use base 'Exporter';

# WSClient constructor
sub new {
	my $axis2c_home;
       	my $this = shift;
	my $self = { @_ };
	my $a2ch = "AXIS2C_HOME"; 

        unless (defined $ENV{$a2ch}) {
                die("Environment variable $a2ch is not set, exitting.");
        }
        $axis2c_home = $ENV{$a2ch};

        $self->{env} = WSO2::WSF::C::axutil_env_create_all("/tmp/wsf-perl.log", $WSO2::WSF::C::AXIS2_LOG_LEVEL_TRACE);
        unless (defined $self->{env}) {
                die("ERROR:  Failed to create WSF/C environment");
        }
	$self->{svc_client} = WSO2::WSF::C::axis2_svc_client_create($self->{env}, $axis2c_home);

	unless (defined $self->{svc_client}) {
	        die("ERROR:  Failed to create service client");
	}

        return bless($self, $this);
}

sub request {
	my $this = shift;
	my $self = { @_ };

	# skipping sandesha for the moment
	# wsf_client_set_module_param_options('env'		  => $this->{env}, 
	#				    'svc_client'	  => $this->{svc_client}, 
	#				    'module_name'	  => "sandesha2", 
	#				    'module_option'	  => "sandesha2_db", 
	#				    'module_option_value' => "/home/gandalf/svn/wsf-c/deploy");

	# let's do the string stuff first, later on WSMessage
	my $reader = WSO2::WSF::C::axiom_xml_reader_create_for_memory_new($this->{env}, 
								      	  $self->{payload},
								          length($self->{payload}),
								          "utf-8",
								          $WSO2::WSF::C::AXIS2_XML_PARSER_TYPE_BUFFER);

	# convert $reader to an axiom node
	my $builder = WSO2::WSF::C::axiom_stax_builder_create($this->{env}, $reader);

	# convert payload to an axiom node
	my $request_payload = ws_util_read_payload('reader'	=> $reader, 
						   'env'	=> $this->{env});
	print $request_payload . "\n";
}

sub ws_util_read_payload {
	my $self = { @_ };

	my $builder = WSO2::WSF::C::axiom_stax_builder_create($self->{env}, $self->{reader});

	return undef unless $builder;

	my $document = WSO2::WSF::C::axiom_stax_builder_get_document($builder, $self->{env});

	return undef unless $document;

	$payload = WSO2::WSF::C::axiom_document_get_root_element($document, $self->{env});

	return undef unless $payload;
	WSO2::WSF::C::axiom_document_build_all($document, $env);
	# return $payload;

	if ($payload) {
		
	}
}

sub ws_util_serilize_om {
	my $self = { @_ };

	my $builder = WSO2::WSF::C::axiom_stax_builder_create($self->{env}, $self->{reader});


}

# helper method to set options, sholdn't be calling this directly though
# need to make it a private method
# env - instance variable
# svc_client - instance variable
# module_name => ""
# module_option => ""
# module_option_value => ""
sub wsf_client_set_module_param_options {
	my $self = { @_ };

	my $module_qname = WSO2::WSF::C::axis2_qname_create($self->{env}, $self->{module_name}, "", "");
	my $svc_ctx = WSO2::WSF::C::axis2_svc_client_get_svc_ctx($self->{svc_client}, $self->{env});
	my $conf_ctx = WSO2::WSF::C::axis2_svc_ctx_get_conf_ctx($svc_ctx, $self->{env});
	my $conf = WSO2::WSF::C::axis2_conf_ctx_get_conf($conf_ctx, $self->{env});
	my $module_desc = WSO2::WSF::C::axis2_conf_get_module($conf, $self->{env}, $module_qname);
	# print $module_qname . "\n";

	# function not complete yet
}
1;
