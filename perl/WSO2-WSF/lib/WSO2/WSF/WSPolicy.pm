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

    $self = {} unless defined $self;

    # add options as "instance variables"
    if( defined( $self ) ) {
	if ( scalar($self) =~ /HASH/ ) {
	    foreach my $k (keys (%{$self})) {
		$this->{$k} = $self->{$k};
	    }
	} else {
	    # should be a string
	    $this->{security} = $self;
	    # making it a reference since Perl only blesses hard references (rascist bastard)
	    $self = {};
	    $self->{security} = $this->{security};
	}

    }

    bless $self, $this;
    return $self;
}

sub get_policy_as_axiom_node {
    my $this = shift;
    my $env = shift;

    if ( defined $this->{security} ) {

	if ( $this->{security} =~ /HASH/ ) {
	    return create_policy_from_hash( $this, $env );
	} else {
	    # it's a string
	    return create_policy_from_string( $this, $env );
	}

    } else {
	return undef;
    }

}

sub create_policy_from_hash {
    my $this = shift;
    my $env = shift;

    if ( (not defined $this->{security}) or ($this->{security} !~ /HASH/) ) {
	return undef;
    }

    my $options = $this->{security};

    return undef if not defined $options;

    my $neethi_options = WSO2::WSF::C::neethi_options_create($env);
    if ( defined $neethi_options ) {
	my $its = (defined $options->{includeTimeStamp}) ?
	  $options->{includeTimeStamp} : undef;

	if ( (defined $its) and ($its eq 'TRUE') ) {
	    WSO2::WSF::C::neethi_options_set_include_timestamp($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	}

	my $unt = (defined $options->{useUsernameToken}) ?
	  $options->{useUsernameToken} : undef;

	if ( (defined $unt) and ($unt =~ /true/i) ) {
	    WSO2::WSF::C::neethi_options_set_is_username_token($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	}

	my $enc = (defined $options->{encrypt}) ?
	  $options->{encrypt} : undef;

	if ( defined $enc ) {
	    if ( $enc =~ /true/i ) {
		WSO2::WSF::C::neethi_options_set_encrypt_body($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	    } else {
		WSO2::WSF::C::neethi_options_set_encrypt_body($neethi_options, $env, $enc);
	    }
	}

	my $algos = (defined $options->{algorithmSuite}) ?
	  $options->{algorithmSuite} : undef;

	if ( defined $algos ) {
	    WSO2::WSF::C::neethi_options_set_algorithmsuite($neethi_options, $env, $algos);
	}

	my $sign = (defined $options->{sign}) ?
	  $options->{sign} : undef;

	if ( defined $sign ) {
	    if ( $sign =~ /true/i ) {
		WSO2::WSF::C::neethi_options_set_sign_body($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	    } else {
		WSO2::WSF::C::neethi_options_set_sign_body($neethi_options, $env, $sign);
	    }
	}

	my $str = (defined $options->{securityTokenReference}) ?
	  $options->{securityTokenReference} : undef;

	if ( defined $str ) {
	    my $token_ref = get_rampart_token_value($str);
	    WSO2::WSF::C::neethi_options_set_keyidentifier($neethi_options, $env, $token_ref) if defined $token_ref;
	}

	$op = (defined $options->{encryptSignature}) ?
	  $options->{encryptSignature} : undef;

	if ( (defined $op) and ($op eq 'TRUE') ) {
	    WSO2::WSF::C::neethi_options_set_signature_protection($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	}

	my $po = (defined $options->{protectionOrder}) ?
	  $options->{protectionOrder} : undef;

	if ( defined $po ) {
	    if ( $po eq "EncryptBeforeSigning" ) {
		WSO2::WSF::C::neethi_options_set_encrypt_before_sign($neethi_options, $env, $WSO2::WSF::C::AXIS2_TRUE);
	    } elsif ( $po eq  "SignBeforeEncrypt" ) {
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

    return undef if not defined $this->{security};

    return WSO2::WSF::C::wsf_str_to_axiom_node($env, $this->{security}, length($this->{security}));
}


1;
