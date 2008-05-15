#!/usr/bin/env perl

use WSO2::WSF;

# This assumes WSF/PHP is installed and all the samples can be accessed from
# http://localhost/samples

my $payload =<<E;
<ns1:echo xmlns:ns1="http://php.axis2.org/samples">
  <text>Hello World!</text>
</ns1:echo>
E

my $msg = new WSO2::WSF::WSMessage(
    { 'wsfc_home' => '/opt/wso2/wsf_c',
      'to'        => 'http://localhost/samples/security/username_token/service.php',
      'action'    => 'http://php.axis2.org/samples/echoString',
      'payload'   => $payload
    } );

my $security_options = { 'useUsernameToken' => 'TRUE' };

my $policy = new WSO2::WSF::WSPolicy( { 'security' => $security_options } );

my $security_token = new WSO2::WSF::WSSecurityToken( { 'user'         => 'Raigama',
						       'password'     => 'RaigamaPW',
						       'passwordType' => 'Digest' } );

my $client = new WSO2::WSF::WSClient( { 'useWSA'        => 'TRUE',
				        'policy'        => $policy,
				        'securityToken' => $security_token } );

my $res = $client->request( $msg );

print $res->{str};
