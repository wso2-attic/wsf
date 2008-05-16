package WSO2::WSF::WSPolicy;

# Copyright 2005,2006 WSO2, Inc. http://wso2.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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
__END__

=head1 NAME

WSO2::WSF::WSPolicy - Create a WSPolicy object

=head1 SYNOPSYS

  my $policy = new WSO2::WSF::WSPolicy( { WSPOLICY_OPTIONS } );

=head1 DESCRIPTION



=head1 SEC_TOKEN_OPTIONS

=over 4

=item user

Holds the username.

=item certificate

User's certificate to be used for signing.  Load the entire certificate
into a string and give that as a value.  You can use the usual slurp
mode to do this.

my CERT, "< my_certificate.cert";
undef $/;
my $cert = <CERT>;

=item password

User's password used for UsernameToken

=item passwordType

Password type used in UsernameToken.  Valid vaules are 'PlainText' and
'Digest'.

=item privateKey

User's private key, loaded from the privake key file, same as loading
the certificate.

=item receiverCertificate

Receiver's certificate to be used for encryption, same as loading the
certificate.

=item ttl

The time period within which the message would be valid in seconds.

=head1 SEE ALSO

Look at WSO2::WSF::WSClient to see how to pass a WSMessage and consume an
existing Web service.

Mailing list, bug tracker, svn info can be found on the project web site at
http://wso2.org/projects/wsf/perl

=head1 AUTHOR

WSO2 WSF/Perl Team

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
