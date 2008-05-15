#!/usr/bin/env perl

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
