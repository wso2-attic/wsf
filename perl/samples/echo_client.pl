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

# This samples demonstrate sending a simple message to a service and getting a reply back.
# Assumes WSF/PHP is installed and all the samples can be accessed from http://localhost/samples/

my $payload =<<E;
<ns1:echoString xmlns:ns1="http://ws.apache.org/axis2/c/samples">
  <text>Hello World!</text>
</ns1:echoString>
E

my $client = new WSO2::WSF::WSClient(
    { 'to'          => 'http://localhost/samples/echo_service.php',
      'log_file' => '/tmp/thislogfile',
      'log_level' => 4
    } );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
