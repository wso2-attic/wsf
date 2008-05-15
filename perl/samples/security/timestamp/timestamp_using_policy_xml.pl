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

# This assumes WSF/PHP is installed and all the samples are accessible from
# http://localhost/samples

my $payload =<<E;
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
E

my $msg = new WSO2::WSF::WSMessage(
    { 'to'      => 'http://localhost/samples/security/timestamp/policy_file_based/service.php',
      'action'  => 'http://php.axis2.org/samples/echoString',
      'payload' => $payload
    } );

open FILE, "< policy.xml";
undef $/;
my $policy_xml = <FILE>;

my $policy = new WSO2::WSF::WSPolicy( $policy_xml );

my $sec_token = new WSO2::WSF::WSSecurityToken( { 'ttl' => 60 } );

my $client = new WSO2::WSF::WSClient( { 'useWSA'        => 'TRUE',
				        'policy'        => $policy,
				        'securityToken' => $sec_token
				      } );

my $response = $client->request( $msg );

print $response->{str};
