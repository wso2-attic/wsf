#!/usr/bin/env perl

use WSO2::WSF;

# This client demonstrate how to encrypt a message before sending.  Assumes WSF/PHP is
# installed and all the samples can be accessed from http://localhost/samples

my $payload =<<E;
<ns1:echo xmlns:ns1="http://php.axis2.org/samples">
  <text>Hello World!</text>
</ns1:echo>
E

open RCK, "< ../keys/bob_cert.cert";
undef $/;
my $rec_cert = <RCK>;

open PVK, "< ../keys/alice_key.pem";
undef $/;
my $pvt_key = <PVK>;

my $req_message = new WSO2::WSF::WSMessage(
    { 'payload'   => $payload,
      'to'        => 'http://localhost:8787/samples/security/encryption/service.php',
      'action'    => 'http://php.axis2.org/samples/echoString',
      'log_level' => 4
    } );

my $sec_arr = { 'encrypt'                => 'TRUE',
	        'algorithmSuite'         => 'Basic256Rsa15',
	        'securityTokenReference' => 'IssuerSerial' };

my $policy = new WSO2::WSF::WSPolicy( { 'security' => $sec_arr } );

my $sec_token = new WSO2::WSF::WSSecurityToken( { 'privateKey'          => $pvt_key,
						  'receiverCertificate' => $rec_cert } );

my $client = new WSO2::WSF::WSClient( { 'useWSA'        => 'TRUE',
				        'policy'        => $policy,
				        'securityToken' => $sec_token } );

my $response = $client->request( $req_message );

print $response->{str};



