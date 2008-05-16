package WSO2::WSF::WSFault;

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
__END__

=head1 NAME

WSO2::WSF::WSFault - Create a WSFault object

=head1 SYNOPSYS

  my $fault = new WSO2::WSF::WSFault( { FAULT_OPTIONS } );

=head1 DESCRIPTION

A WSFault object stores all information related to a SOAP fault.  Values of
all arguments are strings.  Usually this is used to represent the faults
returned by which ever the calling service.

=head1 FAULT_OPTIONS

=over 4

=item code

SOAP fault code. SOAP fault codes are intended to provide a means by which
faults are classified.  Please see SOAP 1.2 spec for more information.  This
is a mandatory option.

=item reason

SOAP fault reason. Provides a human readable explanation of the fault.  This
is a mandatory option.

=item role

SOAP fault role. Identifies the role in which the SOAP processing node was
operating at the time the fault occurred.

=item detail

SOAP Fault detail. Contains application specific error information.

=item xml

This will contain the request payload which resulted in the fault.

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
