package WSO2::WSF::WSMessage;

use 5.008008;
# use strict;
use warnings;
use base 'Exporter';

sub new {
	my $this = shift;
	my $payload = shift;
	my $self = shift; # options

	$self = {} unless( defined( $self ) );

	unless( defined( $payload ) ) {
		die "ERROR:  Payload cannot be null";
	}

	if( ( scalar( $payload ) =~ /HASH/ ) or
	    ( scalar( $payload ) =~ /ARRAY/ ) ) {
		die "ERROR:  Payload should be a string";
	}

	$this->{"payload"} = $payload;

	if( defined( $self ) ) {
		foreach my $k (keys (%{$self})) {
			$this->{$k} = $self->{$k};
		}
	}

	bless $self, $this;
	return $self;
}
1;
