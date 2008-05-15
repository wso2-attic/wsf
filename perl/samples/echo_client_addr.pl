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

# This sample demonstrate how to create a message with WS-Addressing headers.
# Assumes WSF/PHP is installed and all the samples can be accessed from http://localhost/samples

$payload =<<E;
<ns1:echoString xmlns:ns1="http://perl.axis2.org/samples">
  <text>Listing Rubbish</text>
</ns1:echoString>
E

my $message = new WSO2::WSF::WSMessage(
	{ 'payload'	=> $payload,
	  'wsfc_home'   => '/opt/wso2/wsf_c/',
	  'to'		=> 'http://localhost/samples/echo_service_addr.php',
	  'action'	=> 'http://php.axis2.org/samples/echoString',
	  'log_level'   => 4
	} );

my $client = new WSO2::WSF::WSClient( { 'useWSA' => 'TRUE' } );

my $response = $client->request( $message );

print $response->{str};
