package WSO2::WSF::WSMessage;

use 5.008008;
# use strict;
use warnings;
use base 'Exporter';

sub new {
	my $class = shift;
	my $this = ref( $class ) || $class;
	my $self = shift; # options

	# $self = {} unless( defined( $self ) );

	unless( defined( $self->{payload} ) ) {
		die "ERROR:  Payload cannot be null";
	}

	if( ( scalar( $self->{payload} ) =~ /HASH/ ) or
	    ( scalar( $self->{payload} ) =~ /ARRAY/ ) ) {
		die "ERROR:  Payload should be a string";
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
