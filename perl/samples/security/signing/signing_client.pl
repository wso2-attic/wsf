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

# This samples demonstrate how to sign a message before sending.
# Assumes WSF/PHP is installed and all the samples can be accessed from
# http://localhost/samples

my $payload =<<E;
<ns1:echo xmlns:ns1="http://php.axis2.org/samples">
  <text>Hello World!</text>
</ns1:echo>
E

open MYC, "../keys/alice_cert.cert";
undef $/;
my $mycert = <MYC>;

open MYK, "../keys/alice_key.pem";
undef $/;
my $mykey = <MYK>;

open REC, "../keys/bob_cert.cert";
undef $/;
my $reccert = <REC>;

my $req_msg = new WSO2::WSF::WSMessage(
    { 'payload' => $payload,
      'to'      => 'http://localhost/samples/security/signing/service.php',
      'action'  => 'http://php.axis2.org/samples/echoString'
    } );

my $sec_arr = { 'sign'                   => 'TRUE',
	        'algorithmSuite'         => 'Basic256Rsa15',
	        'securityTokenReference' => 'IssuerSerial' };

my $policy = new WSO2::WSF::WSPolicy( { 'security' => $sec_arr } );

my $sec_token = new WSO2::WSF::WSSecurityToken( { 'privateKey'          => $mykey,
						  'certificate'         => $mycert,
						  'receiverCertificate' => $reccert } );

my $client = new WSO2::WSF::WSClient( { 'useWSA'        => 'TRUE',
				        'policy'        => $policy,
				        'securityToken' => $sec_token } );

my $res = $client->request( $req_msg );

print $res->{str};
