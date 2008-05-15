#!/usr/bin/env perl

use WSO2::WSF;

my $payload =<<E;
<ns1:echo xmlns:ns1="http://php.axis2.org/samples">
  <text>Hello World!</text>
</ns1:echo>
E

my $msg = new WSO2::WSF::WSMessage(
    { 'to'      => 'http://localhost:8787/samples/security/timestamp/service.php',
      'action'  => 'http://php.axis2.org/samples/echoString',
      'payload' => $payload
    } );

my $sec_arr = { 'includeTimeStamp' => 'TRUE' };

my $policy = new WSO2::WSF::WSPolicy( { 'security' => $sec_arr } );

my $sec_token = new WSO2::WSF::WSSecurityToken( { 'ttl' => 60 } );

my $client = new WSO2::WSF::WSClient( { 'useWSA'        => 'TRUE',
				        'policy'        => $policy,
				        'securityToken' => $sec_token
				      } );

my $response = $client->request( $msg );

print $response->{str};

