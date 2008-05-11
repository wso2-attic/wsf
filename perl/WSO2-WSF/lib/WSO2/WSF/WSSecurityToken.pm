package WSO2::WSF::WSSecurityToken;

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
