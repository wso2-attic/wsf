package WSO2::WSF::WSPolicy;

use 5.008008;
# use strict;
use warnings;
use base qw(WSO2::WSF);

use WSO2::WSF::C;
use WSO2::WSF::WSMessage;

sub new {
    my $class = shift;
    my $this = ref( $class ) || $class;
    my $self = shift;		# options

    # $self = {} unless( defined( $self ) );

    if( defined( $self ) ) {
	foreach my $k (keys (%{$self})) {
	    $this->{$k} = $self->{$k};
	}
    }

    bless $self, $this;
    return $self;
}

sub get_policy_axiom_node {
    my $this = shift;
    my $env = shift;

    if ( defined $this->{policy} ) {

	if ( $this->{policy} =~ /HASH/ ) {
	    return create_policy_from_hash( $this, $env );
	} else {
	    return create_policy_from_string( $this, $env );
	}

    } else {
	return undef;
    }

}

sub create_policy_from_hash {
    my $this = shift;
    my $env = shift;

    if ( (not defined $this->{policy}) or ($this->{policy} =~ /HASH/) ) {
	return undef;
    }

    my $options = $this->{policy};

    return undef if not defined $options;

    my $neethi_options = WSO2::WSF::C::neethi_options_create($env);
    if ( defined $neethi_options ) {
	my $op = (defined $options->{include_time_stamp}) ?
	  $options->{include_time_stamp} : undef;

	if ( (defined $op) and ($op eq 'TRUE') ) {
	    WSO2::WSF::C::neethi_options_set_include_timestamp($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	}

	$op = (defined $options->{use_username_token}) ?
	  $options->{use_username_token} : undef;

	if ( (defined $op) and ($op eq 'TRUE') ) {
	    WSO2::WSF::C::neethi_options_set_is_username_token($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	}

	$op = (defined $options->{encrypt}) ?
	  $options->{encrypt} : undef;

	if ( (defined $op) ) {
	    if ( $op == $WSO2::WSF::C::AXIS2_TRUE ) {
		WSO2::WSF::C::neethi_options_set_encrypt_body($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	    } else {
		WSO2::WSF::C::neethi_options_set_encrypt_body($neethi_options, $env, $op);
	    }
	}

	$op = (defined $options->{algorithm_suite}) ?
	  $options->{algorithm_suite} : undef;

	if ( defined $op ) {
	    WSO2::WSF::C::neethi_options_set_algorithmsuite($neethi_options, $env, $op);
	}

	$op = (defined $options->{sign}) ?
	  $options->{sign} : undef;

	if ( defined $op ) {
	    if ( $op == $WSO2::WSF::C::AXIS2_TRUE ) {
		WSO2::WSF::C::neethi_options_set_sign_body($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	    } else {
		WSO2::WSF::C::neethi_options_set_sign_body($neethi_options, $env, $op);
	    }
	}

	$op = (defined $options->{security_token_reference}) ?
	  $options->{security_token_reference} : undef;

	if ( defined $op ) {
	    my $token_ref = get_rampart_token_value($op);
	    WSO2::WSF::C::neethi_options_set_keyidentifier($neethi_options, $env, $token_ref) if defined $token_ref;
	}

	$op = (defined $options->{encrypt_signature}) ?
	  $options->{encrypt_signature} : undef;

	if ( (defined $op) and ($op eq 'TRUE') ) {
	    WSO2::WSF::C::neethi_options_set_signature_protection($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	}

	$op = (defined $options->{protection_order}) ?
	  $options->{protection_order} : undef;

	if ( defined $op ) {
	    if ( $op eq "EncryptBeforeSigning" ) {
		WSO2::WSF::C::neethi_options_set_encrypt_before_sign($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	    } elsif ( $op eq  "SignBeforeEncrypt" ) {
		WSO2::WSF::C::neethi_options_set_encrypt_before_sign($neethi_options, $env, $WSO2::WSF::C::AXIS2_FALSE);
	    }
	}

	return WSO2::WSF::C::neethi_options_get_root_node($neethi_options, $env);
    }
    return undef;
}

sub get_rampart_token_value {
    my $op = shift;

    if ( $op eq "IssuerSerial" ) {
	return $WSO2::WSF::C::RP_REQUIRE_ISSUER_SERIAL_REFERENCE;
    } elsif ( $op eq "KeyIdentifier" ) {
	return $WSO2::WSF::C::RP_REQUIRE_KEY_IDENTIFIRE_REFERENCE;
    } elsif ( $op eq "EmbeddedToken" ) {
	return $WSO2::WSF::C::RP_REQUIRE_EMBEDDED_TOKEN_REFERENCE;
    } elsif ( $op eq "Thumbprint" ) {
	return $WSO2::WSF::C::RP_REQUIRE_THUMBPRINT_REFERENCE;
    } else {
	return undef;
    }
}

sub create_policy_from_string {
    my $this = shift;
    my $env = shift;

    return undef if not defined $this->{policy};

    return WSO2::WSF::C::wsf_str_to_axiom_node($env, $this->{policy}, length($this->{policy}));
}


1;
