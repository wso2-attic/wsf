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

# This sample demonstrate sending multiple messages to a service using a single client instance.
# Assumes WSF/C is installed and axis2_http_server is listening at port 8585

my @payload_strings;

for ( my $i = 0; $i < 10; $i++ ) {
    $payload_strings[$i] = <<EOF;
<ns1:echoString xmlns:ns1="http://ws.apache.org/axis2/c/samples">
   <text>Parallel universe - $i</text>
</ns1:echoString>
EOF
}

my $service_client = new WSO2::WSF::WSClient(
    { 'to' => 'http://localhost:8585/axis2/services/echo' } );

for ( my $i = 0; $i < 10; $i++ ) {
    my $msg = new WSO2::WSF::WSMessage(
        { 'payload' => $payload_strings[$i],
	  'to'      => 'http://localhost:8585/axis2/services/echo'
        } );

    my $response = $service_client->request( $msg );

    print $response->{str} . "\n";
}
