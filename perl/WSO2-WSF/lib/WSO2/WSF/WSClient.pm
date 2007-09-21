package WSO2::WSF::WSClient;

use 5.008008;
# use strict;
use warnings;
use base qw(WSO2::WSF);

use WSO2::WSF::C;
use WSO2::WSF::WSMessage;

our @EXPORT = qw( new );

# WSClient constructor
sub new {
       	my $class = shift;
	my $this = ref( $class ) || $class;
	my $args = shift;

	$args = {} unless( defined( $args ) );

	if( defined( $args ) ) {
		foreach my $k ( keys( %{$args} ) ) {
			$this->{$k} = $args->{$k};
		}
	}

	bless( $args, $this );
	return $args;
}

sub request {
	my $class = shift;
	my $this = ref( $class ) || $class;
	my $args = shift;
	
	$args = {} unless( defined( $args ) );

	my $is_wsmessage = 0;

	foreach my $k ( keys %{$args} ) {
		$this->{$k} = $args->{$k};
	}

	$is_wsmessage = 1  if( $args =~ /WSMessage/ );


        $this->{env} = WSO2::WSF::C::axutil_env_create_all(
			"/tmp/wsf-perl.log", 
			$WSO2::WSF::C::AXIS2_LOG_LEVEL_TRACE );
	
	unless( defined( $this->{env} ) ) {
		die( "ERROR:  Failed to create WSF/C environment" );
	}

        unless( defined( $this->{axis2c_home} ) ) {
		WSO2::WSF::C::axis2_log_debug(
			$this->{env},
			"[wsf-perl] Location where WSF/C installed is not specified" );
                die( "ERROR:  Axis2/C home is not given" );
        }

	$this->{svc_client} = WSO2::WSF::C::axis2_svc_client_create(
			$this->{env}, 
			$this->{axis2c_home} );

	unless( defined( $this->{svc_client} ) ) {
		WSO2::WSF::C::axis2_log_debug(
			$this->{env},
			"[wsf-perl] Service client creation failed" );
		die( "ERROR:  Failed to create service client" );
	}

	# skipping sandesha for the moment
	# wsf_client_set_module_param_options('env'		  => $this->{env}, 
	#				    'svc_client'	  => $this->{svc_client}, 
	#				    'module_name'	  => "sandesha2", 
	#				    'module_option'	  => "sandesha2_db", 
	#				    'module_option_value' => "/home/gandalf/svn/wsf-c/deploy");

	my $reader = '';

	if( $is_wsmessage ) {
		$reader = WSO2::WSF::C::axiom_xml_reader_create_for_memory_new(
			$this->{env}, 
			$this->{payload},
			length( $this->{payload} ),
			"utf-8",
			$WSO2::WSF::C::AXIS2_XML_PARSER_TYPE_BUFFER );
	} else {
		$reader = WSO2::WSF::C::axiom_xml_reader_create_for_memory_new(
			$this->{env}, 
			$this->{payload},
			length( $this->{payload} ),
			"utf-8",
			$WSO2::WSF::C::AXIS2_XML_PARSER_TYPE_BUFFER );
	}

	unless( defined( $reader ) ) {
		WSO2::WSF::C::axis2_log_debug(
			$this->{env},
			"[wsf-perl] Failed to create xml_reader_for_memory" );
	}

	# convert $reader to an axiom node
	my $builder = WSO2::WSF::C::axiom_stax_builder_create( $this->{env}, $reader );

	unless( defined( $builder ) ) {
		WSO2::WSF::C::axis2_log_debug(
			$this->{env},
			"[wsf-perl] Axiom node conversion failed" );
	}

	# convert payload to an axiom node
	my $request_payload = wsf_util_read_payload( { 'reader'	=> $reader, 
						       'env'	=> $this->{env} } );

	unless( defined( $request_payload ) ) {
		WSO2::WSF::C::axis2_log_debug(
			$this->{env},
			"[wsf-perl] Failed to convert payload to an axiom node" );
	}

	die( "ERROR:  Request payload should not be null" ) unless( defined( $request_payload ) );

	WSO2::WSF::C::axiom_xml_reader_free( $reader, $this->{env} );

	my $client_options = WSO2::WSF::C::axis2_svc_client_get_options(
			$this->{svc_client}, 
			$this->{env} );
	WSO2::WSF::C::axis2_options_set_xml_parser_reset(
			$client_options,
			$this->{env},
			$WSO2::WSF::C::AXIS2_TRUE );
	

	# adding proxy settings
	if ( defined( $this->{proxy_host} ) && defined( $this->{proxy_port} ) ) {
		WSO2::WSF::C::axis2_svc_client_set_proxy( 
			$this->{svc_client},
			$this->{env},
			$this->{proxy_host},
			$this->{proxy_port} );
	}

	# adding ssl properties
	if ( defined( $this->{ssl_server_key_filename} ) &&
	     defined( $this->{ssl_client_key_filename} ) &&
	     defined( $this->{passphrase} ) ) {

		my $ssl_server_key_prop = WSO2::WSF::C::axutil_property_create_with_args( 
			$this->{env},
			0,
			$WSO2::WSF::C::AXIS2_TRUE,
			0,
			WSO2::WSF::C::axutil_strdup($this->{env}, $this->{ssl_server_key_filename}) );
		my $ssl_client_key_prop = WSO2::WSF::C::axutil_property_create_with_args( 
			$this->{env},
			0,
			$WSO2::WSF::C::AXIS2_TRUE,
			0,
			WSO2::WSF::C::axutil_strdup($this->{env}, $this->{ssl_client_key_filename}) );
		my $passphrase_prop = WSO2::WSF::C::axutil_property_create_with_args( 
			$this->{env},
			0,
			$WSO2::WSF::C::AXIS2_TRUE,
			0,
			WSO2::WSF::C::axutil_strdup($this->{evn}, $this->{passphrase}) );
        }

	# assuming payload is a string, setting client options

	my $soap_version = $WSO2::WSF::C::AXIOM_SOAP12;
	my $use_soap = $WSO2::WSF::C::AXIS2_TRUE;

	if( defined( $this->{useSOAP} ) ) {
		for( $this->{useSOAP} ) {
			if	( /^1\.2$/ )  { $soap_version = $WSO2::WSF::C::AXIOM_SOAP12; }
			elsif 	( /^1\.1$/ )  { $soap_version = $WSO2::WSF::C::AXIOM_SOAP11; }
			elsif	( /^TRUE$/ )  { $soap_version = $WSO2::WSF::C::AXIOM_SOAP12; }
			elsif	( /^FALSE$/ ) { $use_soap = $WSO2::WSF::C::AXIS2_FALSE; }
			else		      { $soap_version = $WSO2::WSF::C::AXIOM_SOAP12; }
		}
	}

	if( $use_soap == $WSO2::WSF::C::AXIS2_TRUE ) {
		WSO2::WSF::C::axis2_options_set_soap_version(
			$client_options,
			$this->{env},
			$soap_version );
	} else {
		my $rest_property = WSO2::WSF::C::axutil_property_create( $this->{env} );

		WSO2::WSF::C::axutil_property_set_value_new(
			$rest_property,
			$this->{env},
			$WSO2::WSF::C::AXIS2_VALUE_TRUE );

		WSO2::WSF::C::axis2_options_set_property_new(
			$client_options,
			$this->{env},
			$WSO2::WSF::C::AXIS2_ENABLE_REST,
			$rest_property );
	}

	# default header type is post, only setting the HTTP_METHOD if GET
	if( defined( $this->{HTTPMethod}) and ( $this->{HTTPMethod} eq "GET" ) ) {
		my $get_property = WSO2::WSF::C::axutil_property_create( $this->{env} );

		WSO2::WSF::C::axutil_property_set_value_new(
			$get_property,
			$this->{env},
			$WSO2::WSF::C::AXIS2_HTTP_GET );

		WSO2::WSF::C::axis2_options_set_property_new(
			$client_options,
			$this->{env},
			$WSO2::WSF::C::AXIS2_HTTP_METHOD,
			$get_property );

	}

	# setting end point
	my $to_epr = WSO2::WSF::C::axis2_endpoint_ref_create( $this->{env}, $this->{to} );
	WSO2::WSF::C::axis2_options_set_to( $client_options, $this->{env}, $to_epr );

	# setting the SOAP action
	if( defined( $this->{action} ) ) {
		my $action_string = WSO2::WSF::C::axutil_string_create( 
			$this->{env}, 
			$this->{action} );
		WSO2::WSF::C::axis2_options_set_soap_action(
			$client_options, 
			$this->{env}, 
			$action_string );
	}

	# addressing
	my $addr_action_present = 0;

	# setting addressing options
	if( defined( $this->{useWSA} ) && ( ( $this->{useWSA} eq "1.0" ) ||
					    ( $this->{useWSA} eq "submission" ) ||
					    ( $this->{useWSA} eq "TRUE" ) ) ) {

		WSO2::WSF::C::axis2_log_debug(
			$this->{env},
			"[wsf-perl] useWSA is specified, value = $this->{useWSA}" );

		if( defined( $this->{to} ) ) {
			WSO2::WSF::C::axis2_options_set_action(
				$client_options,
				$this->{env},
				$this->{to} );
			
			# need to engage addressing
			$addr_action_present = 1;
		}

		if( defined( $this->{replyTo} ) ) {
			my $replyto_epr = WSO2::WSF::C::axis2_endpoint_ref_create(
				$this->{env},
				$this->{replyTo} );
			WSO2::WSF::C::axis2_options_set_reply_to(
				$client_options,
				$this->{env},
				$replyto_epr );
		}

		if( defined( $this->{faultTo} ) ) {
			my $faultto_epr = WSO2::WSF::C::axis2_endpoint_ref_create(
				$this->{env},
				$this->{faultTo} );
			WSO2::WSF::C::axis2_options_set_fault_to(
				$client_options,
				$this->{env},
				$faultto_epr );
		}

		if( defined( $this->{from} ) ) {
			my $from_epr = WSO2::WSF::C::axis2_endpoint_ref_create(
				$this->{env},
				$this->{from} );
			WSO2::WSF::C::axis2_options_set_reply_to(
				$client_options,
				$this->{env},
				$from_epr );
		}

		if( $addr_action_present == 1 ) {
			WSO2::WSF::C::axis2_svc_client_engage_module(
				$this->{svc_client},
				$this->{env},
				"addressing" );
		}

		if( $this->{useWSA} eq "submission" ) {
			my $prop = WSO2::WSF::C::axutil_property_create_with_args(
				$this->{env},
				0,
				$WSO2::WSF::C::AXIS2_TRUE,
				0,
				WSO2::WSF::C::axutil_strdup( 
					$this->{env},
					$WSO2::WSF::C::AXIS2_WSA_NAMESPACE_SUBMISSION ) );
			WSO2::WSF::C::axis2_options_set_property(
				$client_options,
				$this->{env},
				$WSO2::WSF::C::AXIS2_WSA_VERSION,
				$prop );
		}

	} else {
		# either a wrong value or FALSE
	}

	# setting headers
	
	# outgoing attachments

	my $response_payload = WSO2::WSF::C::axis2_svc_client_send_receive(
		$this->{svc_client},
		$this->{env},
		$request_payload );

	if( WSO2::WSF::C::axis2_svc_client_get_last_response_has_fault( 
			$this->{svc_client}, 
			$this->{env} ) ) {
		my $soap_envelop = WSO2::WSF::C::axis2_svc_client_get_last_response_soap_envelope(
                                        $this->{svc_client}, 
					$this->{env} );
                
                my $soap_body;
		my $soap_fault;

                if( $soap_envelop ) {
                        $soap_body = WSO2::WSF::C::axiom_soap_envelope_get_body( 
					$soap_envelop, 
					$this->{env} );
		}
		
		if( $soap_body ) {
			$soap_fault = WSO2::WSF::C::axiom_soap_body_get_fault( 
					$soap_body, 
					$this->{env} );
		}

		if( $soap_fault ) {
			my $soap_version = 0;
			$soap_version = WSO2::WSF::C::axis2_options_get_soap_version(
					$client_options,
					$this->{env} );

			my $fault_node = WSO2::WSF::C::axiom_soap_fault_get_base_node(
					$soap_fault,
					$this->{env} );

			if( $fault_node ) {
				# contruct a WSFault object and throw an exception
			}
		}
	} elsif( $response_payload ) {
		# handle attachments
		
		my $writer = WSO2::WSF::C::axiom_xml_writer_create_for_memory(
			$this->{env},
			undef,
			$WSO2::WSF::C::AXIS2_TRUE,
			0,
			$WSO2::WSF::C::AXIS2_XML_PARSER_TYPE_BUFFER );

		my $om_output = WSO2::WSF::C::axiom_output_create(
			$this->{env},
			$writer );

		WSO2::WSF::C::axiom_node_serialize(
			$response_payload,
			$this->{env},
			$om_output );

		my $buffer = WSO2::WSF::C::axiom_xml_writer_get_xml_new(
			$writer,
			$this->{env} );

		$res_msg = new WSO2::WSF::WSMessage( { 'payload' => $this->{payload},
						       'str' 	 => $buffer } );
		return $res_msg;
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
