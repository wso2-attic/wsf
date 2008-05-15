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

my $payload =<<E;
<ns1:echoString xmlns:ns1="http://tempuri.org/">
  <ns1:Text>echo1</ns1:Text>
</ns1:echoString>
E

my $msg = new WSO2::WSF::WSMessage( { 'action' => 'http://php.axis2.org/samples/echoString',
                                      'payload' => $payload
                                    } );

my $client = new WSO2::WSF::WSClient(
    { 'to' => 'http://localhost:8585/axis2/services/RMSampleService',
      'reliable' => 'TRUE',
      'log_level' => 6
    } );

my $res_msg = $client->request( $msg );

print $res_msg->{str} if defined $res_msg;

sleep(10);
