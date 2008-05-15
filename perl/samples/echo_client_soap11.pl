#!/usr/bin/env perl

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

use WSO2::WSF;

# This client demonstrate how to specify which SOAP binding to use.  By default SOAP 1.2 will
# be used.  Specify the version using 'useSOAP' => '1.1' to use SOAP 1.1.  Assumes WSF/C is
# installed and axis2_http_server is listening on port 8585

$payload =<<E;
<ns1:echoString xmlns:ns1="http://perl.axis2.org/samples">
  <text>Listing Rubbish</text>
</ns1:echoString>
E

my $message = new WSO2::WSF::WSMessage(
	{ 'payload'	=> $payload,
	  'axis2c_home' => '/opt/wso2/wsf_c/',
	  'to'		=> 'http://localhost:8585/axis2/services/echo',
	  'action'	=> 'http://perl.axis2.org/samples/echoString'
	} );

my $client = new WSO2::WSF::WSClient( { 'useSOAP' => '1.1' } );

my $response = $client->request( $message );

print $response->{str};
