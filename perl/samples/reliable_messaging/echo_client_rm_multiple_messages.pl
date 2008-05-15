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

# This sample sending multiple messages with WS-RM using a single client instance.
# Assumes WSF/C is installed and axis2_http_server is listening on port 8585

my $payload =<<E;
<ns1:echoString xmlns:ns1="http://tempuri.org/">
  <ns1:Text>Gah.</ns1:Text>
</ns1:echoString>
E

my $message = new WSO2::WSF::WSMessage(
    { 'to'      => 'http://localhost:8585/axis2/services/RMSampleService',
      'action'  => 'http://php.axis2.org/samples/echoString',
      'payload' => $payload
    } );

my $client = new WSO2::WSF::WSClient(
    { 'reliable'               => 'TRUE',
      'useWSA'                 => 'TRUE',
      'will_continue_sequence' => 'TRUE',
      'log_level'              => 4
    } );

$client->request( $message );

my $message1 = new WSO2::WSF::WSMessage(
    { 'to'      => 'http://localhost:8585/axis2/services/RMSampleService',
      'action'  => 'http://php.axis2.org/samples/echoString',
      'payload' => $payload
    } );

$client->request( $message1 );

my $message2 = new WSO2::WSF::WSMessage(
    { 'to'           => 'http://localhost:8585/axis2/services/RMSampleService',
      'action'       => 'http://php.axis2.org/samples/echoString',
      'last_message' => 'TRUE',
      'payload'      => $payload
    } );

$client->request( $message2 );

sleep(10);
