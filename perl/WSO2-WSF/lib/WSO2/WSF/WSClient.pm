package WSO2::WSF::WSClient;

use 5.008008;
# use strict;
use warnings;
# use base qw(WSO2::WSF);

use WSO2::WSF::C;
use WSO2::WSF::WSMessage;
use WSO2::WSF::WSFault;
use WSO2::WSF::WSPolicy;
use Error qw(:try);

# WSClient constructor
sub new {
    my $class = shift;
    my $this = ref( $class ) || $class;
    my $self = shift;

    $self = {} unless defined $self;

    # adding passed options as "instance variables"
    if ( defined $self ) {
	foreach my $k ( keys( %{$self} ) ) {
	    $this->{$k} = $self->{$k};
	}
    }

    bless $self, $this;
    return $self;
}

# construct the SOAP message according to options (without RM)
# RM options will be set later
sub build_request_message {
    my $class = shift;
    my $this = shift;
    my $self = shift;
    my $oneway = shift;

    $self = {} unless defined $self;

    my $is_wsmessage = 0;

    # adding passed options as "instance variables"
    foreach my $k ( keys %{$self} ) {
	$this->{$k} = $self->{$k};
    }

    # a WSMessage object was passed
    $is_wsmessage = 1  if $self =~ /WSMessage/;

    # default log file
    if ( not defined $this->{log_file} ) {
	$this->{log_file} = "/tmp/wsf_perl_client.log";
    }

    # default log level if user dosen't specify one
    my $loglevel = $WSO2::WSF::C::AXIS2_LOG_LEVEL_INFO;

    if ( defined $this->{log_level} ) {
	if ( $this->{log_level} == 0 ) {
	    $loglevel = $WSO2::WSF::C::AXIS2_LOG_LEVEL_CRITICAL;
	} elsif ( $this->{log_level} == 1 ) {
	    $loglevel = $WSO2::WSF::C::AXIS2_LOG_LEVEL_ERROR;
	} elsif ( $this->{log_level} == 2 ) {
	    $loglevel = $WSO2::WSF::C::AXIS2_LOG_LEVEL_WARNING;
	} elsif ( $this->{log_level} == 4 ) {
	    $loglevel = $WSO2::WSF::C::AXIS2_LOG_LEVEL_DEBUG;
	} elsif ( $this->{log_level} == 5 ) {
            $loglevel = $WSO2::WSF::C::AXIS2_LOG_LEVEL_USER;
        } elsif ( $this->{log_level} == 6 ) {
	    $loglevel = $WSO2::WSF::C::AXIS2_LOG_LEVEL_TRACE;
	}
    }

    # making the env, accessible as an "instance variable"
    $this->{env} = WSO2::WSF::C::axutil_env_create_all(
	$this->{log_file},
	$loglevel );

    unless( defined $this->{env} ) {
	die "ERROR:  Failed to create WSF/C environment";
    }

    # no longer use axis2c_home, this extension use WSF/C now
    if ( defined $this->{axis2c_home} ) {
	die "axis2c_home is now deprecated, please use wsfc_home instead.";
    }

    unless ( defined $this->{wsfc_home} ) {
	if ( defined $ENV{WSFC_HOME} ) {
	    # get it from the environment variable
	    $this->{wsfc_home} = $ENV{WSFC_HOME};
	} else {
	    # can't continue without knowing where WSF/C is installed.
	    WSO2::WSF::C::axis2_log_error($this->{env},
					  "[wsf-perl] Location where WSF/C installed is not specified" );
	    die "ERROR:  WSF/C home is not given.  Either specify wsfc_home option or set WSFC_HOME environment variable to where you installed WSF/C";
	}
    }

    # create the service client
    $this->{svc_client} = wsf_svc_client_create( $this );

    # record whether addressing is engaged or not
    local $addr_action_present;

    # wsf_reader_create will fill this
    local $reader = '';

    WSO2::WSF::C::wsf_client_set_module_param_option($this->{env},
                                                     $this->{svc_client},
                                                     "sandesha2",
                                                     "sandesha2_db",
                                                     "/tmp/sandesha2_db");

    wsf_reader_create($is_wsmessage, $this->{env}, $this->{payload});

    $request_payload = wsf_get_payload_as_axiom( $this );

    WSO2::WSF::C::axiom_xml_reader_free( $reader, $this->{env} );

    local $client_options = wsf_get_client_options( $this );

    wsf_set_proxy_settings( $this );

    wsf_add_ssl_properties( $this );

    # handle custom headers, accepts a WSHeader object via inputHeaders
    wsf_client_set_headers( $this );

    local $wsf_soap_version = $WSO2::WSF::C::AXIOM_SOAP12;
    local $wsf_soap_uri = $WSO2::WSF::C::AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;

    local $is_addressing_engaged = $WSO2::WSF::C::AXIS2_FALSE;


    if ( $this->{responseXOP} ) {
	if ( ($this->{responseXOP} =~ /true/i) or ($this->{responseXOP} == 1) ) {
	    $response_xop = 1;
	}
    }

    wsf_set_client_options( $this );

    # WS-Security related stuff
    wsf_handle_security( $this );

    wsf_set_default_header_type( $this );

    # end point reference
    wsf_set_epr( $this );

    wsf_set_soap_action( $this );

    # WS-Addressing related stuff
    wsf_set_addressing_options( $this );

    # outgoing attachments
    wsf_handle_outgoing_attachments( $this, $client_options, $request_payload );

    wsf_handle_reliable_messaging( $this, $oneway );
}


sub request {
    my $class = shift;
    my $this = ref( $class ) || $class;
    my $self = shift;

    local $request_payload;
    local $response_xop = 0;
    local $is_rm_engaged = $WSO2::WSF::C::AXIS2_FALSE;
    local $will_continue_sequence = 0;
    local $rm_spec_version;

    # last parameter is for oneway
    build_request_message( $class, $this, $self, 0 );

    # last parameter is for oneway
    return wsf_process_response( $this, 0 );

}

sub send_message {
    my $class = shift;
    my $this = ref( $class ) || $class;
    my $self = shift;

    local $request_payload;
    local $response_xop = 0;
    local $is_rm_engaged = $WSO2::WSF::C::AXIS2_FALSE;
    local $will_continue_sequence = 0;
    local $rm_spec_version;

    # last parameter is for oneway
    build_request_message( $class, $this, $self, 1 );

    # last parameter is for oneway
    return wsf_process_response( $this, 1 );
}

sub wsf_client_set_headers {
    # adding user defined headers to the SOAP message.
    # users can create a WSHeader object and pass it to inputHeaders

    my ($this) = (@_);

    # $this->{cp_ih} - stands for copied inputHeaders. Save the header
    # stuff that comes since we're recursing and passing $this

    if ( defined $this->{inputHeaders} ) {

	foreach my $cpih (@{$this->{inputHeaders}}) {
	    if ( $cpih !~ /WSHeader/) {
		# you can't put an elephant into the washing machine, sorry
		die "Invalid header data, please give custom header info via a WSHeader object";
	    }

	    if ( not defined $cpih->{name} ) {
		# dude, can't make a header without a name
		die "Name of the header not given";
	    }

	    # wsf_util_construct_header_node(env, parent, $cpih)
	    my $header = wsf_util_construct_header_node( $this->{env}, undef, $cpih );
	    if ( defined $header ) {
		WSO2::WSF::C::axis2_svc_client_add_header($this->{svc_client}, $this->{env}, WSO2::WSF::C::axiom_node_t_pp_value($header));
	    }
	}
    }
}

sub wsf_util_construct_header_node {
    my $env = shift @_;
    my $parent = shift @_;
    my ($ihs) = (@_); # input headers
    my $header_ns;
    my $header_ele;
    my $header_node = WSO2::WSF::C::new_axiom_node_t_pp();
    local $curr_ns_index = 0;
    my $soap_ns;

    if ( defined($ihs->{ns}) and defined($ihs->{nsprefix}) ) {
	$header_ns = WSO2::WSF::C::axiom_namespace_create($env,
							  $ihs->{ns},
							  $ihs->{nsprefix});
    } elsif ( defined $ihs->{ns} ) {
	 my $prefix = "ns$curr_ns_index";
	 $curr_ns_index++;
	 $header_ns = WSO2::WSF::C::axiom_namespace_create($env,
							   $ihs->{ns},
							   $prefix);
    }

    $header_ele = WSO2::WSF::C::axiom_element_create($env,
						     $parent,
						     $ihs->{name},
						     $header_ns,
						     $header_node);

    if ( defined $ihs->{mustUnderstand} ) {
	$soap_ns = WSO2::WSF::C::axiom_namespace_create($env, $wsf_soap_uri, "soapenv" );
	my $mu_attr = WSO2::WSF::C::axiom_attribute_create($env,
							   "mustUnderstand",
							   $ihs->{mustUnderstand},
							   $soap_ns);
	WSO2::WSF::C::axiom_element_add_attribute($header_ele, $env, $mu_attr, WSO2::WSF::C::axiom_node_t_pp_value($header_node));
    }

    if ( defined $ihs->{role} ) {
	my $role_attr;
	my $role_val;

	if ( $ihs->{role} eq $WSO2::WSF::C::WS_SOAP_ROLE_NEXT ) {
	    $role_val = $WSO2::WSF::C::WS_SOAP_ROLE_NEXT_URI;
	} elsif ( $ihs->{role} eq $WSO2::WSF::C::WS_SOAP_ROLE_NONE ) {
	    $role_val = $WSO2::WSF::C::WS_SOAP_ROLE_NONE_URI;
	} elsif ( $ihs->{role} eq $WSO2::WSF::C::WS_SOAP_ROLE_ULTIMATE_RECEIVER ) {
	    $role_val = $WSO2::WSF::C::WS_SOAP_ROLE_ULTIMATE_RECEIVER_URI;
	} else {
	     $role_val = $ihs->{role};
	}

	if ( not defined $soap_ns ) {
	    $soap_ns = WSO2::WSF::C::axiom_namespace_create($env, $wsf_soap_uri, "soapenv");
	}

	if ( ($wsf_soap_version eq $WSO2::WSF::C::AXIOM_SOAP12) and (defined $role_val)  ) {
	    $role_attr = WSO2::WSF::C::axiom_attribute_create($env,
							      $WSO2::WSF::C::WS_HEADER_ROLE,
							      $role_val,
							      $soap_ns);
	} elsif ( ($wsf_soap_version eq $WSO2::WSF::C::AXIOM_SOAP11) and (defined $role_val) ) {
	    $role_attr = WSO2::WSF::C::axiom_attribute_create($env,
							      $WSO2::WSF::C::WS_HEADER_ACTOR,
							      $role_val,
							      $soap_ns);

	}
	WSO2::WSF::C::axiom_element_add_attribute($header_ele, 
						  $env, 
						  $role_attr, 
						  WSO2::WSF::C::axiom_node_t_pp_value($header_node));
    }

    if ( (defined $ihs->{data}) and ($ihs->{data} =~ /WSHeader/) ) {
	wsf_util_construct_header_node( $env, $header_node, $ihs->{data} );
    } elsif ( (defined $ihs->{data}) and ($ihs->{data} =~ /ARRAY/) ) {
	foreach my $h (@{$ihs->{data}}) {
	    wsf_util_construct_header_node( $env, WSO2::WSF::C::axiom_node_t_pp_value($header_node), $h );
	}
    } else {
	my $node;
	if ( $ihs =~ /</ ) {
	    # wheeee, XML
	    $node = WSO2::WSF::C::wsf_util_deserialize_buffer($env, $ihs);
	    WSO2::WSF::C::axiom_node_add_child($header_node, $env, $node) if defined $node;
	} elsif ( not $node ) {
	    WSO2::WSF::C::axiom_element_set_text($header_ele, $env, $ihs->{data}, WSO2::WSF::C::axiom_node_t_pp_value($header_node));
	}
    }
    return $header_node;
}

sub wsf_client_set_addressing_options_to_options {
    my $this = shift;
    my $cops = shift; # client options

    if ( defined $this->{action} ) {
	WSO2::WSF::C::axis2_options_set_action( $cops, $this->{env}, $this->{action} );
	WSO2::WSF::C::axis2_log_debug( $this->{env}, "[wsf-perl] addressing action present - $this->{action}" );
    }

    if ( defined $this->{replyTo} ) {
	my $rep_epr = WSO2::WSF::C::axis2_endpoint_ref_create( $this->{env}, $this->{replyTo} );
	WSO2::WSF::C::axis2_options_set_reply_to( $cops, $this->{env}, $rep_epr );
	WSO2::WSF::C::axis2_log_debug( $this->{env}, "[wsf-perl] replyTo present - $this->{replyTo}" );
    }

    if ( defined $this->{faultTo} ) {
	my $f_epr = WSO2::WSF::C::axis2_endpoint_ref_create( $this->{env}, $this->{faultTo} );
	WSO2::WSF::C::axis2_options_set_fault_to( $cops, $this->{env}, $f_epr );
	WSO2::WSF::C::axis2_log_debug( $this->{env}, "[wsf-perl] faultTo present - $this->{faultTo}" );
    }

    if ( defined $this->{from} ) {
	my $from_erp = WSO2::WSF::C::axis2_endpoint_ref_create( $this->{env}, $this->{from} );
	WSO2::WSF::C::axis2_options_set_from( $cops, $this->{env}, $from_epr );
	WSO2::WSF::C::axis2_log_debug( $this->{env}, "[wsf-perl] from present - $this->{from}" );
    }
}

sub wsf_handle_reliable_messaging {
    my $this = shift;
    my $oneway = shift;

    my $reliable = $this->{reliable};
    if ( (defined $reliable) and 
	 ( ($reliable =~ /true/i) or ($reliable == "1.0") or ($reliable == "1.1") ) ) {

	# set version
# 	my $rm_version_str = ( $reliable eq "1.1" ) ?
# 	  $WSO2::WSF::C::WSF_RM_VERSION_1_1_STR :
# 	  $WSO2::WSF::C::WSF_RM_VERSION_1_0_STR;

        my $rm_version = ( $reliable eq "1.1" ) ?
          $WSO2::WSF::C::WSF_RM_VERSION_1_1 :
          $WSO2::WSF::C::WSF_RM_VERSION_1_0;

        my $rm_version_str;

        my $rm_spec_version_str;
        my $engage_rm = $WSO2::WSF::C::AXIS2_FALSE;

        if ( $rm_version > 0 ) {
            if ( $rm_version eq $WSO2::WSF::C::WSF_RM_VERSION_1_0 ) {
                $rm_spec_version = $WSO2::WSF::C::WSF_RM_VERSION_1_0;
                $rm_spec_version_str = $WSO2::WSF::C::WSF_RM_VERSION_1_0_STR;
                WSO2::WSF::C::axis2_log_debug( $this->{env},
                                               "[wsf-perl] rm spec version 1.0" );
            } elsif ( $rm_version eq $WSO2::WSF::C::WSF_RM_VERSION_1_1 ) {
                $rm_spec_version = $WSO2::WSF::C::WSF_RM_VERSION_1_1;
                $rm_spec_version_str = $WSO2::WSF::C::WSF_RM_VERSION_1_1_STR;
                WSO2::WSF::C::axis2_log_debug( $this->{env},
                                               "[wsf-perl] rm spec version 1.1" );
            }


            my $rm_prop = WSO2::WSF::C::wsf_axutil_property_create_with_args(
                $this->{env},
                $WSO2::WSF::C::AXIS2_SCOPE_REQUEST,
                $WSO2::WSF::C::AXIS2_FALSE,
                WSO2::WSF::C::wsf_axutil_strdup( $this->{env}, $rm_spec_version_str ) );

            WSO2::WSF::C::wsf_axis2_options_set_property( $client_options,
                                                          $this->{env},
                                                          $WSO2::WSF::C::WSF_SANDESHA2_CLIENT_RM_SPEC_VERSION,
                                                          $rm_prop );
            $engage_rm = $WSO2::WSF::C::AXIS2_TRUE;
        }

# 	my $rm_property = WSO2::WSF::C::wsf_axutil_property_create_with_args(
# 	     $this->{env},
# 	     $WSO2::WSF::C::AXIS2_SCOPE_REQUEST,
# 	     $WSO2::WSF::C::AXIS2_FALSE,
# 	     WSO2::WSF::C::wsf_axutil_strdup( $this->{env}, $rm_version_str ) );

# 	WSO2::WSF::C::wsf_axis2_options_set_property( $client_options,
# 						      $this->{env},
# 						      $WSO2::WSF::C::WSF_SANDESHA2_CLIENT_RM_SPEC_VERSION,
# 						      $rm_property );

	my $need_to_engage_addressing = ( (not defined $addr_action_present) and 
					  (defined $this->{action}) ) ? 1 : undef;

        if ( ($is_addressing_engaged || ((not $is_addressing_engaged) and defined $this->{action}))
             and ($engage_rm) ) {
            if ( not $is_addressing_engaged ) {
		wsf_client_set_addressing_options_to_options( $this, $client_options );
		WSO2::WSF::C::axis2_svc_client_engage_module( $this->{svc_client}, $this->{env}, "addressing" );
		WSO2::WSF::C::axis2_log_debug( $this->{env}, "[wsf-perl] useWSA not specified, addressing engaged since rm is engaed" );
	    }

	    # engage sandesha2
	    WSO2::WSF::C::axis2_svc_client_engage_module( $this->{svc_client},
							  $this->{env},
							  $WSO2::WSF::C::AXIS2_MODULE_SANDESHA2 );
	    $is_rm_engaged = $WSO2::WSF::C::AXIS2_TRUE;

	    # set sequence expiry time
	    if ( defined $this->{sequenceExpiryTime} ) {
		WSO2::WSF::C::wsf_set_module_param_value( $this->{env},
							  $this->{svc_client},
							  $WSO2::WSF::C::AXIS2_MODULE_SANDESHA2,
							  $WSO2::WSF::C::WSF_SANDESHA2_CLIENT_INACT_TIMEOUT,
							  $this->{sequenceExpiryTime} ) if defined $this->{sequenceExpiryTime};
	    }

	    # set sequence key
	    if ( defined $this->{sequenceKey} ) {
		my $sequence_key_property = WSO2::WSF::C::wsf_axutil_property_create_with_args(
                    $this->{env},
                    $WSO2::WSF::C::AXIS2_SCOPE_REQUEST,
                    $WSO2::WSF::C::AXIS2_TRUE,
                    WSO2::WSF::C::wsf_axutil_strdup( $this->{env}, $sequence_key ) );

		WSO2::WSF::C::wsf_axis2_options_set_property( $client_options,
							      $this->{env},
							      $WSO2::WSF::C::WSF_SANDESHA2_CLIENT_SEQ_KEY,
							      $sequence_key_property );
	    }

	    if ( defined $this->{willContinueSequence} ) {
		$will_continue_sequence = 1;
		WSO2::WSF::C::axis2_log_debug( $this->{env}, "[wsf-perl] willContinueSequence is true" );
	    }
        }

	if ( $is_rm_engaged == $WSO2::WSF::C::AXIS2_TRUE ) {

	    if ( $will_continue_sequence ) {
		if ( (defined $this->{lastMessage}) and ($this->{lastMessage} == 1) ) {
		    $will_continue_sequence = 0;
		    if ( $rm_spec_version == $WSO2::WSF::C::WSF_RM_VERSION_1_0 ) {
			my $last_msg_prop = WSO2::WSF::C::wsf_axutil_property_create_with_args(
			    $this->{env},
                            $WSO2::WSF::C::AXIS2_SCOPE_APPLICATION,
			    $WSO2::WSF::C::AXIS2_FALSE,
			    $WSO2::WSF::C::AXIS2_VALUE_TRUE);
			WSO2::WSF::C::axis2_options_set_property( $client_options,
								  $this->{env},
								  "Sandesha2LastMessage",
								  $last_msg_prop );
		    }
		} elsif ( not $will_continue_sequence ) {
		    WSO2::WSF::C::axis2_log_debug( $this->{env},
						   "[wsf-perl] setting TreminateSequence property" );
		    if ( $rm_spec_version == $WSO2::WSF::C::WSF_RM_VERSION_1_0 ) {
			                    # axutil_property_t *last_msg_prop =
#                         axutil_property_create_with_args (env,
#                         0, 0, 0, AXIS2_VALUE_TRUE);
#                     axis2_options_set_property (client_options, env,
#                         "Sandesha2LastMessage", last_msg_prop);
#                     AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
#                         "[wsf_client] setting Sandesha2LastMessage");
			my $last_msg_prop = WSO2::WSF::C::wsf_axutil_property_create_with_args(
			    $this->{env},
			     $WSO2::WSF::C::AXIS2_SCOPE_REQUEST,
			    $WSO2::WSF::C::AXIS2_FALSE,
			    $WSO2::WSF::C::AXIS2_VALUE_TRUE);
			WSO2::WSF::C::axis2_options_set_property( $client_options,
								  $this->{env},
								  "Sandesha2LastMessage",
								  $last_msg_prop );
			WSO2::WSF::C::axis2_log_debug( $this->{env}, "[wsf-perl] setting Sandesha2LastMessage" );
		    }
		}

		# two way single channel
		if ( not $oneway ) {
		    my $timeout = undef;
		    my $timeout_property = undef;
		    my $offered_seq_id = undef;
		    my $sequence_property = undef;

		    $offered_seq_id = WSO2::WSF::C::axutil_uuid_gen( $this->{env} );

		    $sequence_property = WSO2::WSF::C::axutil_property_create( $this->{env} );

		    WSO2::WSF::C::axutil_property_set_value( $sequence_property,
							     $this->{env},
							     WSO2::WSF::C::axutil_strdup( $this->{env}, $offered_seq_id ));

		    WSO2::WSF::C::axis2_options_set_property( $client_options,
							      $this->{env},
							      "Sandesha2OfferedSequenceId", 
							      $sequence_property);

		    WSO2::WSF::C::axis2_log_debug( $this->{env},
						   "[wsf-log] Sandesha2OfferedSequenceId is set as property");

		    $timeout = (defined $this->{responseTimeout}) ? 
		        $this->{responseTimeout} : $WSO2::WSF::C::WSF_RM_DEFAULT_RESPONSE_TIMEOUT;

		    $timeout_property = WSO2::WSF::C::axutil_property_create_with_args(
		        $client_options,
			$this->{env},
			$WSO2::WSF::C::AXIS2_TIMEOUT_IN_SECONDS,
			$timeout_property );
		}

	    }
	}
    }

}

sub wsf_handle_outgoing_attachments {
    my ($this, $cliopt, $reqpayload) = (@_);

    if ( defined $this->{attachments} ) {

	my $enable_mtom = ( defined( $this->{useMTOM} ) && $this->{useMTOM} =~ /true/i ) ?
	  $WSO2::WSF::C::AXIS2_TRUE : $WSO2::WSF::C::AXIS2_FALSE;

	my $default_content_type_ref = defined( $this->{$WSO2::WSF::C::WSF_MP_DEF_ATT_CON_TYPE} ) ?
	  $WSO2::WSF::C::WSF_MP_DEF_ATT_CON_TYPE : undef;

	my $default_content_type = defined( $default_content_type_ref ) ?
	  $default_content_type_ref : $WSO2::WSF::C::WSF_DEFAULT_CONTENT_TYPE;

	WSO2::WSF::C::axis2_options_set_enable_mtom( $cliopt, $this->{env}, $enable_mtom);
	pack_attachments( $this, $reqpayload, $this->{attachments}, $enable_mtom, $default_content_type );
    }
}

sub pack_attachments {
    my $this = shift;
    my ($node, $atts, $mtom, $ct) = (@_);

    return if not defined $node;

    if ( WSO2::WSF::C::axiom_node_get_node_type( $node, $this->{env} ) == $WSO2::WSF::C::AXIOM_ELEMENT ) {
	my $node_element = WSO2::WSF::C::wsf_axiom_node_get_data_element( $node, $this->{env} );

	if ( defined $node_element ) {
	    my $child_element_ite = WSO2::WSF::C::axiom_element_get_child_elements( $node_element, $this->{env}, $node );

	    if ( defined( $child_element_ite ) ) {
		my $child_node = WSO2::WSF::C::axiom_child_element_iterator_next( $child_element_ite, $this->{env} );
		my $attachment_done = 0;

		while ( ( defined $child_node ) and ( $attachment_done == 0 ) ) {
		    my $child_element = WSO2::WSF::C::wsf_axiom_node_get_data_element( $child_node, $this->{env} );
		    my $element_localname = WSO2::WSF::C::axiom_element_get_localname( $child_element, $this->{env} );

		    if ( ( defined $element_localname ) and
			 ( WSO2::WSF::C::wsf_axutil_strcmp( $element_localname, $WSO2::WSF::C::AXIS2_ELEMENT_LN_INCLUDE ) == $WSO2::WSF::C::AXIS2_TRUE ) ) {

			my $element_namespace = WSO2::WSF::C::axiom_element_get_namespace($child_element, $this->{env}, $child_node);

			if ( defined $element_namespace ) {
			    my $namespace_uri = WSO2::WSF::C::axiom_namespace_get_uri( $element_namespace, $this->{env} );

			    if ( ( defined $namespace_uri ) and
			         ( WSO2::WSF::C::wsf_axutil_strcmp( $namespace_uri, $WSO2::WSF::C::AXIS2_NAMESPACE_URI_INCLUDE ) == $WSO2::WSF::C::AXIS2_TRUE ) ) {
				my $cnt_type = WSO2::WSF::C::axiom_element_get_attribute_value_by_name( $node_element,
												        $this->{env},
													$WSO2::WSF::C::AXIS2_ELEMENT_ATTR_NAME_CONTENT_TYPE );
				my $content_type = ( defined $cnt_type ) ? $cnt_type : $ct;
				my $href = WSO2::WSF::C::axiom_element_get_attribute_value_by_name( $child_element,
												    $this->{env},
												    $WSO2::WSF::C::AXIS2_ELEMENT_ATTR_NAME_HREF );
				$href =~ s/^\s+|\s+$//g;

				if ( length( $href ) > 4 ) {
				    my $cid = substr( $href, 4, length( $href ) );
				    my $content = $atts->{$cid};

				    if ( defined $content ) {
					WSO2::WSF::C::wsf_axiom_attach_content( $this->{env},
										$child_node,
										$node,
										$mtom,
										$content_type,
										$content,
										length( $content ) );
					$attachment_done = 1;
				    }
				}
			    }
			}
		    }
		    $child_node = WSO2::WSF::C::axiom_child_element_iterator_next($child_element_ite, $this->{env});
		}
	    }
	}
    }

    # process child nodes
    my $child_node = WSO2::WSF::C::axiom_node_get_first_child($node, $this->{env});
    while ( defined $child_node ) {
	pack_attachments( $this, $child_node, $atts, $mtom, $ct );

	$child_node = WSO2::WSF::C::axiom_node_get_next_sibling($child_node, $this->{env});
    }

}

sub wsf_client_send_terminate_sequence {
    my $this = shift;

    if ( $is_rm_engaged and (not $will_continue_sequence) and 
         $rm_spec_version == $WSO2::WSF::C::WSF_RM_VERSION_1_1 ) {
	WSO2::WSF::C::sandesha2_client_terminate_seq_with_svc_client_and_seq_key(
	   $this->{env},
	   $this->{svc_client},
           $sequence_key );
    }
}

sub wsf_process_response {
    my $this = shift;
    my $oneway = shift;

    if ( $oneway ) {
	my $retval = 0;
	$retval = WSO2::WSF::C::axis2_svc_client_send_robust( $this->{svc_client},
							      $this->{env},
							      $request_payload );
	wsf_client_send_terminate_sequence( $this );
	return $retval;
    } else {

	my $response_payload = WSO2::WSF::C::axis2_svc_client_send_receive(
									   $this->{svc_client},
									   $this->{env},
									   $request_payload );

	wsf_client_send_terminate_sequence( $this );


	if ( WSO2::WSF::C::axis2_svc_client_get_last_response_has_fault( $this->{svc_client}, $this->{env} ) == $WSO2::WSF::C::AXIS2_TRUE ) {
	    # soap fault occured
	    my $last_soap_fault = last_soap_fault_exception( $this );
	} elsif ( defined $response_payload ) {
	    # handle attachments

	    my $buffer = WSO2::WSF::C::wsf_axiom_node_to_str( $this->{env}, $response_payload );

	    my $res_msg = new WSO2::WSF::WSMessage( { 'payload' => $this->{payload},
						      'str'     => $buffer } );

	    wsf_handle_incoming_attachments($res_msg, $response_payload, $this);

	    return $res_msg;
	} else {
	    WSO2::WSF::C::axis2_log_debug( $this->{env}, "[wsf-perl] Error, no response received" );
	}
    }
}

sub wsf_handle_incoming_attachments {
    my $msg = shift;
    my $r_payload = shift;
    my $this = shift;

    if ( $response_xop == 1 ) {
	unpack_attachments($msg, $r_payload, $this);
    } else {
	WSO2::WSF::C::wsf_util_find_xop_content_and_convert_to_base64($this->{env}, $r_payload);
    }
}

sub unpack_attachments {
    my $msg = shift;
    my $r_payload = shift;
    my $this = shift;

    if ( defined $r_payload ) {
	if ( WSO2::WSF::C::axiom_node_get_node_type($r_payload, $this->{env}) == $WSO2::WSF::C::AXIOM_TEXT ) {
	    my $text_element = WSO2::WSF::C::wsf_axiom_node_get_text_element($r_payload, $this->{env});

	    if ( defined $text_element ) {
		my $data_handler = WSO2::WSF::C::axiom_text_get_data_handler($text_element, $this->{env});

		if ( defined $data_handler ) {
		    my $content = WSO2::WSF::C::wsf_axiom_data_handler_get_content($data_handler, $this->{env});
		    my $content_type = WSO2::WSF::C::axiom_data_handler_get_content_type($data_handler, $this->{env});
		    my $cid = WSO2::WSF::C::axiom_text_get_content_id($text_element, $this->{env});

		    $msg->{attachments} = { "$cid" => $content };
		    $msg->{content_types} = { "$cid" => "$content_type" };
		}
	    }
	}
    }

    # processing child nodes
    my $child_node = WSO2::WSF::C::axiom_node_get_first_child($r_payload, $this->{env});
    while ( $child_node ) {
	unpack_attachments($msg, $child_node, $this);
	$child_node = WSO2::WSF::C::axiom_node_get_next_sibling($child_node, $this->{env});
    }
}

sub last_soap_fault_exception {
    my $this = shift;

    my $e = new WSO2::WSF::C::fault_data_t;
    $e = WSO2::WSF::C::wsf_last_soap_fault_exception( $this->{svc_client}, $this->{env} );

    my $fault = new WSO2::WSF::WSFault( $e->{code},
					$e->{reason},
					$e->{role},
					$e->{detail},
					$e->{xml} );
    throw $fault;
}

sub wsf_set_addressing_options {
    my $this = shift;

    # addressing
    $addr_action_present = undef;

    # setting addressing options
    if( defined( $this->{useWSA} ) && ( ( $this->{useWSA} eq "1.0" ) ||
					( $this->{useWSA} eq "submission" ) ||
					( $this->{useWSA} eq "TRUE" ) ) ) {

	WSO2::WSF::C::axis2_log_debug(
	    $this->{env},
	    "[wsf-perl] useWSA is specified, value = $this->{useWSA}" );

	if( defined $this->{replyTo} ) {
	    my $replyto_epr = WSO2::WSF::C::axis2_endpoint_ref_create(
		$this->{env},
		$this->{replyTo} );
	    WSO2::WSF::C::axis2_options_set_reply_to(
		$client_options,
		$this->{env},
		$replyto_epr );
	}

	if( defined $this->{faultTo} ) {
	    my $faultto_epr = WSO2::WSF::C::axis2_endpoint_ref_create(
		$this->{env},
		$this->{faultTo} );
	    WSO2::WSF::C::axis2_options_set_fault_to(
		$client_options,
		$this->{env},
		$faultto_epr );
	}

	if( defined $this->{from} ) {
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
            $is_addressing_engaged = $WSO2::WSF::C::AXIS2_TRUE;
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

}

sub wsf_set_soap_action {
    my $this = shift;

    # setting the SOAP action
    if( defined $this->{action} ) {
	WSO2::WSF::C::axis2_options_set_action(
	    $client_options, 
	    $this->{env}, 
	    $this->{action} );
    }
}

sub wsf_set_epr {
    my $this = shift;

    # setting end point reference
    my $to_epr = WSO2::WSF::C::axis2_endpoint_ref_create( $this->{env}, $this->{to} );
    WSO2::WSF::C::axis2_options_set_to( $client_options, $this->{env}, $to_epr );
}

sub wsf_set_default_header_type {
    my $this = shift;

    # default header type is post, only setting the HTTP_METHOD if GET
    if( defined( $this->{HTTPMethod}) and ( $this->{HTTPMethod} =~ /^GET$/i ) ) {
	WSO2::WSF::C::axis2_options_set_http_method(
	    $client_options,
            $this->{env},
	    $WSO2::WSF::C::AXIS2_HTTP_GET)
    }
}

sub wsf_set_client_options {
    my $this = shift;

    my $soap_version = $WSO2::WSF::C::AXIOM_SOAP12;
    my $use_soap = $WSO2::WSF::C::AXIS2_TRUE;

    if( defined $this->{useSOAP} ) {
	for( $this->{useSOAP} ) {
	    if	  ( /^1\.2$/ )   { $soap_version = $WSO2::WSF::C::AXIOM_SOAP12; }
	    elsif ( /^1\.1$/ )   { $soap_version = $WSO2::WSF::C::AXIOM_SOAP11;
				   $wsf_soap_version = $WSO2::WSF::C::AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI; }
	    elsif ( /^true$/i )  { $soap_version = $WSO2::WSF::C::AXIOM_SOAP12; }
	    elsif ( /^false$/i ) { $use_soap = $WSO2::WSF::C::AXIS2_FALSE; }
	    else       	         { $soap_version = $WSO2::WSF::C::AXIOM_SOAP12; }
	}
    }

    if( $use_soap == $WSO2::WSF::C::AXIS2_TRUE ) {
	WSO2::WSF::C::axis2_options_set_soap_version(
	    $client_options,
	    $this->{env},
	    $soap_version );
    } else {
	WSO2::WSF::C::axis2_options_set_enable_rest(
	    $client_options,
	    $this->{env},
            $WSO2::WSF::C::AXIS2_TRUE);
    }

}

sub wsf_add_ssl_properties {
    my $this = shift;

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
	    WSO2::WSF::C::axutil_strdup($this->{env}, $this->{passphrase}) );

	WSO2::WSF::C::axis2_options_set_property(
	    $client_options,
	    $this->{env},
	    $WSO2::WSF::C::WSF_PROP_NAME_SERVER_CERT,
	    $ssl_server_key_prop );

	WSO2::WSF::C::axis2_options_set_property(
	    $client_options,
	    $this->{env},
	    $WSO2::WSF::C::WSF_PROP_NAME_KEY_FILE,
	    $ssl_client_key_prop );

	WSO2::WSF::C::axis2_options_set_property(
	    $client_options,
	    $this->{env},
	    $WSO2::WSF::C::WSF_PROP_NAME_SSL_PASSPHRASE,
	    $passphrase_prop );
    }

}

sub wsf_handle_security {
    my $this = shift;

    my $policy = defined( $this->{policy} ) ?
      $this->{policy} : undef;

    my $sec_token = defined( $this->{securityToken} ) ?
      $this->{securityToken} : undef;

    if ( defined($policy) && defined($sec_token) ) {
	# policy is given, let's do the rest

	WSO2::WSF::C::handle_client_security($this->{env},
					     $this->{svc_client},
					     $policy->get_policy_as_axiom_node($this->{env}),
					     ($sec_token->{privateKey} ? $sec_token->{privateKey} : ""),
					     ($sec_token->{certificate} ? $sec_token->{certificate} : ""),
					     ($sec_token->{receiverCertificate} ? $sec_token->{receiverCertificate} : ""),
					     ($sec_token->{user} ? $sec_token->{user} : ""),
					     ($sec_token->{password} ? $sec_token->{password} : ""),
					     ($sec_token->{passwordType} ? $sec_token->{passwordType} : ""),
					     ($sec_token->{ttl} ? $sec_token->{ttl} : "")
					    );
    }

}

sub wsf_get_client_options {
    my $this = shift;

    my $ops = WSO2::WSF::C::axis2_svc_client_get_options( $this->{svc_client}, $this->{env} );

    WSO2::WSF::C::axis2_options_set_xml_parser_reset( $ops,
						      $this->{env},
						      $WSO2::WSF::C::AXIS2_TRUE );
    return $ops;
}

sub wsf_get_payload_as_axiom {
    my $this = shift;

    # request payload
    my $req_pl = WSO2::WSF::C::wsf_str_to_axiom_node( $this->{env},
						      $this->{payload},
						      length( $this->{payload} ) );

    unless( defined $req_pl ) {
	WSO2::WSF::C::axis2_log_debug(
	    $this->{env},
	    "[wsf-perl] Failed to convert payload to an axiom node" );
    }

    die "ERROR:  Request payload should not be null" unless defined $req_pl;
    return $req_pl;
}

sub wsf_reader_create {
    my($isws, $env, $payload) = (@_);

    # same thing is done 
#     if( $isws ) {
# 	$reader = WSO2::WSF::C::axiom_xml_reader_create_for_memory_new(
# 	    $env,
# 	    $payload,
# 	    length( $payload ),
# 	    "utf-8",
# 	    $WSO2::WSF::C::AXIS2_XML_PARSER_TYPE_BUFFER );
#     } else {
# 	$reader = WSO2::WSF::C::axiom_xml_reader_create_for_memory_new(
# 	    $env,
# 	    $payload,
# 	    length( $payload ),
# 	    "utf-8",
# 	    $WSO2::WSF::C::AXIS2_XML_PARSER_TYPE_BUFFER );
#     }
    $reader = WSO2::WSF::C::axiom_xml_reader_create_for_memory_new(
	    $env,
	    $payload,
	    length( $payload ),
	    "utf-8",
	    $WSO2::WSF::C::AXIS2_XML_PARSER_TYPE_BUFFER );

    unless( defined( $reader ) ) {
	WSO2::WSF::C::axis2_log_debug(
	    $env,
	    "[wsf-perl] Failed to create xml_reader_for_memory" );
    }

}

sub wsf_svc_client_create {
    my $this = shift;
    my $svc = WSO2::WSF::C::axis2_svc_client_create(
 	$this->{env},
 	$this->{wsfc_home} );

    unless( defined $svc ) {
 	WSO2::WSF::C::axis2_log_debug(
 	    $this->{env},
 	    "[wsf-perl] Service client creation failed" );
 	die "ERROR:  Failed to create service client";
     }
    return $svc;
}

sub wsf_set_proxy_settings {
    my $this = shift;

    if ( defined( $this->{proxy_host} ) && defined( $this->{proxy_port} ) ) {
	WSO2::WSF::C::axis2_svc_client_set_proxy(
	    $this->{svc_client},
	    $this->{env},
	    $this->{proxy_host},
	    $this->{proxy_port} );
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

1;
__END__

=head1 NAME

WSO2::WSF::WSClient - Perl interface to consume Web services using WSF/C.

=head1 SYNOPSIS

  use WSO2::WSF::WSClient;

  my $client = new WSO2::WSF::WSClient();

  my $client = new WSO2::WSF::WSClient( { WSCLIENT_OPTIONS } );

  my $response = $client->request( { 'payload' => 'your payload in XML' } );

  my $message = new WSO2::WSF::WSMessage( { WSMESSAGE_OPTIONS } );
  my $response = $client->request( $message );

=head1 DESCRIPTION

This module provide a simple interface in Perl to WSO2 WSF/C.  It's based on 
Apache Axis2/C project and bundle several other related projects (Sandesha2/C,
Rampart/C, Savan ...) in to a single distribution.

You could give options to WSClient contructor when creating a new client
or you could construct a WSMessage object and pass it to the request method
after creating the client.

=head1 WSCLIENT_OPTIONS

=over 4

=item wsfc_home

This should hold the absolute path name where you have installed WSF/C.
If you don't provide this, WSF/Perl look for an environment variable called
WSFC_HOME.  If it cannot find the location where WSF/C is installed it'll exit
giving an error message.

=item useSOAP

Valid options, 'TRUE', 'FALSE', '1.1', '1.2'.  Default value is 'TRUE'.
If this is set SOAP bindings will be used.  Otherwise REST style invocation
will be used along with the method given by HTTPMethod option.  By default
SOAP 1.2 message style will be used.

=item HTTPMethod

Specifies which HTTP method to use. Valid values are 'GET', 'get', 'POST' and
'post'.  Defaults to 'POST'.

=item useWSA

Tell whether to use WS-Addressing.  Valid values are 'TRUE', 'FALSE', '1.0'
and 'submission'.  If 'submission' is specified 'action' must be present.

=head1 METHODS

=over 4

=item request( { 'payload' => 'payload in XML' } );

=item request( $message );

This is an instance method.  You could either give the payload as an XML
string or you could construct a WSMessage object and give that.

=head1 SEE ALSO

Look at WSO2::WSF::WSMessage for how to construct a WSMessage object with
various message related options.

Mailing list, bug tracker, svn info can be found on the project web site at
http://wso2.org/projects/wsf/perl

=head1 AUTHOR

Chintana Wilamuna, E<lt>chintana@wso2.comE<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2007 by WSO2

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

=cut
