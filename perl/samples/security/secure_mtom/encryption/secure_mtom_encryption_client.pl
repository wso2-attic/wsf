#!/usr/bin/env perl

use WSO2::WSF;

my $payload =<<E;
<ns1:upload xmlns:ns1="http://php.axis2.org/samples/mtom">
  <ns1:fileName>test.jpg</ns1:fileName>
  <ns1:image xmlmime:contentType="image/jpeg" xmlns:xmlmime="http://www.w3.org/2004/06/xmlmime">
    <xop:Include xmlns:xop="http://www.w3.org/2004/08/xop/include" href="cid:myid1"></xop:Include>
  </ns1:image>
</ns1:upload>
E

open FILE, "< ../../../mtom/axis2.jpg";
undef $/;
my $image = <FILE>;

open REC, "< ../../keys/bob_cert.cert";
undef $/;
my $reccert = <REC>;

open PVK, "< ../../keys/alice_key.pem";
undef $/;
my $pvtkey = <PVK>;

my $msg = new WSO2::WSF::WSMessage(
    { 'to'          => 'http://localhost:8787/samples/security/secure_mtom/encryption/service.php',
      'action'      => 'http://wso2.org/upload',
      'attachments' => { 'myid' => $image },
      'payload'     => $payload
    } );

my $sec_arr = { 'encrypt'                => 'TRUE',
	        'algorithmSuite'         => 'Basic256Rsa15',
	        'securityTokenReference' => 'IssuerSerial'
	      };

my $policy = new WSO2::WSF::WSPolicy( { 'security' => $sec_arr } );

my $sec_token = new WSO2::WSF::WSSecurityToken( { 'privateKey'          => $pvtkey,
						  'receiverCertificate' => $reccert
						} );

my $client = new WSO2::WSF::WSClient( { 'useWSA'        => 'TRUE',
				        'useMTOM'       => 'TRUE',
				        'policy'        => $policy,
				        'securityToken' => $sec_token
				      } );

my $res_msg = $client->request( $msg );

print $res_msg->{str};
