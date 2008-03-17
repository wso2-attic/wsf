package WSO2::WSF::WSFault;

use 5.008008;
# use strict;
use warnings;
use Error qw(:try);
use base 'Error';

use overload ('""' => 'stringify');

sub new {
    my $class = shift;
    my $this = ref( $class ) || $class;
    my ($code, $reason, $role, $detail, $xml) = (@_);

    $self->{code} = $code;
    $self->{reason} = $reason;
    $self->{role} = $role;
    $self->{detail} = $detail;
    $self->{xml} = $xml;

    if( defined( $self ) ) {
	foreach my $k (keys (%{$self})) {
	    $this->{$k} = $self->{$k};
	}
    }

    bless $self, $this;
    return $self;
}

sub stringify {
    my ($self) = @_;
    my $class = ref($self) || $self;

    return "WSFault: " . $self->{detail} . "\n";

}

1;
