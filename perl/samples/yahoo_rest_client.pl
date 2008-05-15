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

# This will call the Yahoo! web service and return the search results.

$payload =<<E;
<webSearch><appid>WSF/Perl</appid><query>ethanol</query><form/></webSearch>
E

my $client = new WSO2::WSF::WSClient( 
	{ 'to'		=> 'http://search.yahooapis.com/WebSearchService/V1/webSearch',
  	  'HTTPMethod'	=> 'GET',
  	  'useSOAP'	=> 'FALSE' } );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
