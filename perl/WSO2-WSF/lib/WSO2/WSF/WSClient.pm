package WSO2::WSF::WSClient;

use 5.008008;
# use strict;
use warnings;
use base 'Exporter';

# require WSO2::WSF::C;
use WSO2::WSF::C;

# WSClient constructor
sub new {
       	my $this = shift;
	my $args = shift;

        unless (defined $args->{axis2c_home}) {
                die("ERROR:  Axis2/C home is not given");
        }

        $this->{env} = WSO2::WSF::C::axutil_env_create_all("/tmp/wsf-perl.log", $WSO2::WSF::C::AXIS2_LOG_LEVEL_TRACE);
	
        unless (defined $this->{env}) {
                die("ERROR:  Failed to create WSF/C environment");
        }
	$this->{svc_client} = WSO2::WSF::C::axis2_svc_client_create($this->{env}, $args->{axis2c_home});

	unless (defined $this->{svc_client}) {
	       die("ERROR:  Failed to create service client");
	}

	bless($args, $this);
	return $args;
}

sub request {
	my $this = "WSO2::WSF::WSClient";
	shift;
	my $args = shift;

	print $this->{action}, "\n";

	# skipping sandesha for the moment
	# wsf_client_set_module_param_options('env'		  => $this->{env}, 
	#				    'svc_client'	  => $this->{svc_client}, 
	#				    'module_name'	  => "sandesha2", 
	#				    'module_option'	  => "sandesha2_db", 
	#				    'module_option_value' => "/home/gandalf/svn/wsf-c/deploy");

	# let's do the string stuff first, later on WSMessage
	my $reader = WSO2::WSF::C::axiom_xml_reader_create_for_memory_new($this->{env}, 
								      	  $args->{payload},
								          length($args->{payload}),
								          "utf-8",
								          $WSO2::WSF::C::AXIS2_XML_PARSER_TYPE_BUFFER);

	# convert $reader to an axiom node
	my $builder = WSO2::WSF::C::axiom_stax_builder_create($this->{env}, $reader);

	# convert payload to an axiom node
	my $request_payload = wsf_util_read_payload( { 'reader'	=> $reader, 
						       'env'	=> $this->{env} } );

	WSO2::WSF::C::axiom_xml_reader_free($reader, $this->{env});

	my $client_options = WSO2::WSF::C::axis2_svc_client_get_options($this->{svc_client}, $this->{env});

	# adding proxy settings
	if ( defined( $args->{proxy_host} ) && defined( $args->{proxy_port} ) ) {
		WSO2::WSF::C::axis2_svc_client_set_proxy( $this->{svc_client},
							  $this->{env},
							  $args->{proxy_host},
							  $args->{proxy_port} );
	}

	# adding ssl properties
	if ( defined( $args->{ssl_server_key_filename} ) &&
	     defined( $args->{ssl_client_key_filename} ) &&
	     defined( $args->{passphrase} ) ) {

		my $ssl_server_key_prop = WSO2::WSF::C::axutil_property_create_with_args( $this->{env},
											  0,
											  &WSO2::WSF::C::AXIS2_TRUE,
											  0,
											  WSO2::WSF::C::axutil_strdup($this->{env}, $args->{ssl_server_key_filename}) );
		my $ssl_client_key_prop = WSO2::WSF::C::axutil_property_create_with_args( $this->{env},
											  0,
											  &WSO2::WSF::C::AXIS2_TRUE,
											  0,
											  WSO2::WSF::C::axutil_strdup($this->{env}, $args->{ssl_client_key_filename}) );
		my $passphrase_prop = WSO2::WSF::C::axutil_property_create_with_args( $this->{env},
										      0,
										      &WSO2::WSF::C::AXIS2_TRUE,
										      0,
										      WSO2::WSF::C::axutil_strdup($this->{evn}, $args->{passphrase}) );


        }

	# assuming payload is a string

	my $soap_version = "1.2";
	$soap_version = $args->{"useSOAP"} if (defined($args->{"useSOAP"}));

	if ( ($soap_version ne "1.2") or ($soap_version ne "1.1") ) {
		$soap_version = 0;
	}

	if ($soap_version) {
		WSO2::WSF::C::axis2_options_set_soap_version($client_options,
							     $this->{env},
							     int($soap_version));
	} else {
		my $rest_property = WSO2::WSF::C::axutil_property_create($this->{env});

		WSO2::WSF::C::axutil_property_set_value_new($rest_property,
							$this->{env},
							WSO2::WSF::C::axutil_strdup_new($this->{env},
										    "$WSO2::WSF::C::AXIS2_TRUE"));

		WSO2::WSF::C::axis2_options_set_property_new($client_options,
							 $this->{env},
							 $WSO2::WSF::C::AXIS2_ENABLE_REST,
							 "$rest_property");


	}

	# default header type is post, only setting the HTTP_METHOD if GET
	if (defined($args->{HTTPMethod}) and ($args->{HTTPMethod} eq "GET")) {
		my $get_property = WSO2::WSF::C::axutil_property_create($this->{env});

		WSO2::WSF::C::axutil_property_set_value_new($get_property,
							    $this->{env},
							    WSO2::WSF::C::axutil_strdup_new($this->{env},
								    			    $WSO2::WSF::C::AXIS2_HTTP_GET));

		WSO2::WSF::C::axis2_options_set_property_new($client_options,
							     $this->{env},
							     $WSO2::WSF::C::AXIS2_HTTP_METHOD,
							     $get_property);
	}

	# setting end point
	my $to_epr = WSO2::WSF::C::axis2_endpoint_ref_create($this->{env}, $args->{to});
	WSO2::WSF::C::axis2_options_set_to($client_options, $this->{env}, $to_epr);

	# setting the SOAP action
	print $args->{to}, "\n";
	if (defined($args->{action})) {
		my $action_string = WSO2::WSF::C::axutil_string_create($this->{env}, $args->{action});
		WSO2::WSF::C::axis2_options_set_soap_action($client_options, $this->{env}, $args->{action});
		print "\n***\n";
	}
}

sub wsf_util_read_payload {
	my $args = shift;

	my $builder = WSO2::WSF::C::axiom_stax_builder_create($args->{env}, $args->{reader});

	return undef unless $builder;

	my $document = WSO2::WSF::C::axiom_stax_builder_get_document($builder, $args->{env});

	return undef unless $document;

	$payload = WSO2::WSF::C::axiom_document_get_root_element($document, $args->{env});

	return undef unless $payload;
	WSO2::WSF::C::axiom_document_build_all($document, $args->{env});
	return $payload;

}

sub ws_util_serilize_om {
	my $args = shift;

	my $builder = WSO2::WSF::C::axiom_stax_builder_create($args->{env}, $args->{reader});
}

# helper method to set options, sholdn't be calling this directly though
# need to make it a private method
# env - instance variable
# svc_client - instance variable
# module_name => ""
# module_option => ""
# module_option_value => ""
sub wsf_client_set_module_param_options {
	my $args = shift;

	my $module_qname = WSO2::WSF::C::axis2_qname_create($args->{env}, $args->{module_name}, "", "");
	my $svc_ctx = WSO2::WSF::C::axis2_svc_client_get_svc_ctx($args->{svc_client}, $args->{env});
	my $conf_ctx = WSO2::WSF::C::axis2_svc_ctx_get_conf_ctx($svc_ctx, $args->{env});
	my $conf = WSO2::WSF::C::axis2_conf_ctx_get_conf($conf_ctx, $args->{env});
	my $module_desc = WSO2::WSF::C::axis2_conf_get_module($conf, $args->{env}, $module_qname);
	# print $module_qname . "\n";

	# function not complete yet
}
1;
