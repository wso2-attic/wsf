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

# This assumes you have installed WSF/PHP and all the samples can be accessed from
# http://localhost/samples

my $payload =<<E;
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
E

open MYC, "< ../keys/alice_cert.cert";
undef $/;
my $mycert = <MYC>;

open MYK, "< ../keys/alice_key.pem";
undef $/;
my $mykey = <MYK>;

open REC, "< ../keys/bob_cert.cert";
undef $/;
my $reccert = <REC>;

my $msg = new WSO2::WSF::WSMessage(
    { 'to' => 'http://localhost/samples/security/complete/service.php',
      'action' => 'http://php.axis2.org/samples/echoString',
      'payload' => $payload } );

open XML, "< policy.xml";
undef $/;
my $policy_xml = <XML>;

my $policy = new WSO2::WSF::WSPolicy($policy_xml);

my $sec_token = new WSO2::WSF::WSSecurityToken( { 'privateKey'          => $mykey,
						  'certificate'         => $mycert,
						  'receiverCertificate' => $reccert } );

my $client = new WSO2::WSF::WSClient( { 'useWSA'        => 'TRUE',
				        'useSOAP'       => '1.1',
				        'policy'        => $policy,
				        'securityToken' => $sec_token } );

my $res_msg = $client->request( $msg );

print $res_msg->{str};
