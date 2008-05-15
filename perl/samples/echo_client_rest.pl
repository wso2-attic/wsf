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

# This sample demonstrate calling a REST service.  Assumes WSF/C is installed and listening on
# port 8585

$payload =<<E;
<ns1:echoString xmlns:ns1="http://perl.axis2.org/samples">
  <text>Listing Rubbish</text>
</ns1:echoString>
E

my $client = new WSO2::WSF::WSClient(
	{ 'wsfc_home'  => '/opt/wso2/wsf_c/',
	  'to'         => 'http://localhost:8585/axis2/services/echo/echoString',
  	  'HTTPMethod' => 'GET',
  	  'useSOAP'    => 'FALSE'
	} );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
