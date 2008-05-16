package WSO2::WSF::WSSecurityToken;

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
use base 'Exporter';

sub new {
    my $class = shift;
    my $this = ref( $class ) || $class;
    my $self = shift;		# options

    # $self = {} unless( defined( $self ) );

    if ( (defined $self->{policy}) and ( scalar( $self->{policy} ) =~ /HASH/ ) ) {
	die "ERROR:  Policy should be a hash";
    }

    if ( defined( $self ) ) {
	foreach my $k (keys (%{$self})) {
	    # removing certificate delimiters, until this is handled in
	    # Rampart/C itself
	    if ( $k eq "privateKey" ) {
		$self->{$k} =~ s/-----BEGIN RSA PRIVATE KEY-----//sim if defined $self->{$k};
		$self->{$k} =~ s/-----END RSA PRIVATE KEY-----//sim if defined $self->{$k};
	    } elsif ( ($k eq "receiverCertificate") or ($k eq "certificate") ) {
		$self->{$k} =~ s/-----BEGIN CERTIFICATE-----//sim if defined $self->{$k};
		$self->{$k} =~ s/-----END CERTIFICATE-----//sim if defined $self->{$k};
	    }
	    $this->{$k} = $self->{$k};
	}
    }


    bless $self, $this;
    return $self;
}
1;
__END__

=head1 NAME

WSO2::WSF::WSSecurityToken - Create a WSSecurityToken object

=head1 SYNOPSYS

  my $sec_token = new WSO2::WSF::WSSecurityToken( { SEC_TOKEN_OPTIONS } );

=head1 DESCRIPTION

This object is used to store security properties and is passed to 'securityToken'
option when creating the client object.

my $sec_token = new WSO2::WSF::WSSecurityToken( { ... } );

my $client = new WSO2::WSF::WSClient( { ...
                                        'securityToken' => $sec_token,
                                        ...
                                      } );

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
