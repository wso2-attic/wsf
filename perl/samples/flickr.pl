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

# This will call the Flickr web service.  You need to provide your Flickr API key to get this
# sample working

$payload =<<E;
<x:FlickrRequest xmlns:x="urn:flickr">
  <method>flickr.test.echo</method>
  <api_key>your_api_key</api_key>
  <name>vacation</name>
</x:FlickrRequest>
E

my $client = new WSO2::WSF::WSClient( { 'wsfc_home' => '/opt/wso2/wsf_c',
	   	             		'to'        => 'http://api.flickr.com/services/soap/' } );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
