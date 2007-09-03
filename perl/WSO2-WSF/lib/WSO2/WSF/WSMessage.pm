package WSO2::WSF::WSMessage;

use 5.008008;
# use strict;
use warnings;
use base 'Exporter';

sub new {
	my $this = shift;
	my $payload = shift;
	my $self = shift;

	$self = {} unless( defined( $self ) );

	unless( defined( $payload ) ) {
		die "ERROR:  Payload cannot be null";
	}

	if( defined( $self ) ) {
		foreach my $k (keys (%{$self})) {
			$this->{$k} = $self->{$k};
		}
	}

	bless $self, $this;
	return $self;
}
1;
