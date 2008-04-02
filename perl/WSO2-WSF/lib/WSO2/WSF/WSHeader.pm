package WSO2::WSF::WSHeader;

use 5.008008;
# use strict;
use warnings;
use base 'Exporter';

sub new {
    my $class = shift;
    my $this = ref( $class ) || $class;
    my $self = shift;		# options

    if( defined( $self ) ) {
	foreach my $k (keys (%{$self})) {
	    $this->{$k} = $self->{$k};
	}
    }

    bless $self, $this;
    return $self;
}
1;
