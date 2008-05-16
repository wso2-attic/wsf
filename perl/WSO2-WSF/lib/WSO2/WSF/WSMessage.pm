package WSO2::WSF::WSMessage;

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

    $self = {} unless defined $self;

    unless( defined $self->{payload} ) {
	die "ERROR:  Payload cannot be null";
    }

    if( ( scalar( $self->{payload} ) =~ /HASH/ ) or
	( scalar( $self->{payload} ) =~ /ARRAY/ ) ) {
	die "ERROR:  Payload should be a string";
    }

    if( defined $self ) {
	foreach my $k (keys (%{$self})) {
	    $this->{$k} = $self->{$k};
	}
    }

    bless $self, $this;
    return $self;
}
1;
__END__

=head1 NAME

WSO2::WSF::WSMessage - Create a WSMessage object

=head1 SYNOPSYS

  use WSO2::WSF::WSMessage;

  my $message = new WSO2::WSF::WSMessage( { WSMESSAGE_OPTIONS } );

  my $message = new WSO2::WSF::WSMessage( { 'payload' => 'payload in XML' } );

=head1 DESCRIPTION

A WSMessage object can be used to store all the info in order to successfully
consume a Web service.  This could be passed to the request method after you
create a WSClient object.

=head1 WSMESSAGE_OPTIONS

=over 4

=item wsfc_home

This is a mandatory options that contain the absolute folder of your
WSF/C installation.

=item payload

Must give the payload as an XML string.

=item to

Should contain the end point URI of the service that you're going to
consume. This is a mandatory options on the client side.  If WS-Addressing is
used this'll be used as the WSA to header.

=item action

This is used when creating WS-A header.  This URI will help to uniquely identify
the operation to be invoked.  This is also used as the SOAP action regardless
of useWSA is specified or not.

=item from

A URI indicating where the response came from.  WS-A From.

=item replyTo

URI specifying where the response should be sent to.  WS-A ReplyTo.

=item faultTo

URI specifying where the SOAP fault should be sent to in case of an error.
WS-A FaultTo.

=item inputHeaders

This accept an array of WSHeader objects.  Even if it's one header element
you have to give it in an array.

my $header1 = new WSO2::WSF::WSHeader( { ... } );

my $client = new WSO2::WSF::WSMessage( { ...
                                         'inputHeaders' => [ $header1 ],
                                         ...
                                       } );

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
