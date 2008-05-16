package WSO2::WSF;

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
use strict;
use warnings;

require Exporter;

our @ISA = qw(Exporter);

# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.

# This allows declaration	use WSO2::WSF ':all';
# If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
# will save memory.
our %EXPORT_TAGS = ( 'all' => [ qw(
	
) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(
	
);

our $VERSION = '0.01';


# Preloaded methods go here.

use WSO2::WSF::C;
use WSO2::WSF::WSClient;
use WSO2::WSF::WSMessage;
use WSO2::WSF::WSSecurityToken;
use WSO2::WSF::WSFault;
use WSO2::WSF::WSHeader;
use WSO2::WSF::WSPolicy;

1;
__END__

=head1 NAME

WSO2::WSF - Perl extension for WSO2 WSF/C.

=head1 DESCRIPTION

This Perl module allows anyone to consume Web services while using the Apache
Axis2/C engine underneath.

=head1 SEE ALSO

See the documentation for WSO2::WSF::WSClient and WSO2::WSF::WSMessage for using
those classes to write Web service clients.

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
