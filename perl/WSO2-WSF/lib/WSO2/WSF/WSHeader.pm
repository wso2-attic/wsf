package WSO2::WSF::WSHeader;

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

    # add options as "instance variables"
    if( defined( $self ) ) {
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

WSO2::WSF::WSHeader - Create a WSHeader object.

=head1 SYNOPSYS

  my $header = new WSO2::WSF::WSHeader( { WSHEADER_OPTIONS } );

  my $header = new WSO2::WSF::WSHeader( { 'name' => 'person',
                                          'data' => 'Frodo',
                                          ...
                                        } );

  my $client = new WSO2::WSF::WSClient( { ...
                                          'inputHeaders' => [ $header ],
                                          ...
                                        } );

=head1 DESCRIPTION

A WSMessage object can be used to store all the info in order to successfully
consume a Web service.  This could be passed to the request method after you
create a WSClient object.

A WSHeader object can be used to hold a custom header element which could
then be passed as an array to 'inputHeaders' option when creating a WSClient
object.

=head1 WSHEADER_OPTIONS

=over 4

=item ns

Specify SOAP header's namespace URI.

=item nsprefix

Soap header's namespace prefix.

=item name

Soap header element's localname

=item data

If it's a single value give it as a string, if nested elements are need to
be generated give an array of WSHeader objects.

# a single header element

  my $h1 = new WSO2::WSF::WSHeader( { 'name' => 'person',
                                      'data' => 'Frodo'
                                    } );

# header with child elements

  my $name = new WSO2::WSF::WSHeader( { 'name' => 'fullname',
                                        'data' => 'Frodo Baggins'
                                      } );

  my $age = new WSO2::WSF::WSHeader( { 'name' => 'age',
                                       'data' => 'Eleventy-one'
                                     } );

  my $h3 = new WSO2::WSF::WSHeader( { 'name' => 'person',
                                      'data' => [ $name, $age ]
                                    } );

=item mustUnderstand

Can contain either 'TRUE' or 'FALSE' values.  Specifys whether to add
mustUnderstand attribute to the Soap Header or not.

=item role

Can either be 1, 2 or 3.
  1 - This will set the role to none, meaning if there are intermediary
      SOAP nodes they will not process the header.
  2 - This will set the role to next, meaning the next SOAP node to
      receive the header must process it.
  3 - This will set the role to ultimate receiver, meaning the last
      SOAP node to receive the SOAP header will process it.

=head1 SEE ALSO

Look at WSO2::WSF::WSClient to see how to pass a WSHeader and create a custom
header element.

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

