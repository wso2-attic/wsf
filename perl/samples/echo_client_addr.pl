#!/usr/bin/env perl

use WSO2::WSF;

# This sample demonstrate how to create a message with WS-Addressing headers.
# Assumes WSF/PHP is installed and all the samples can be accessed from http://localhost/samples

$payload =<<E;
<ns1:echoString xmlns:ns1="http://perl.axis2.org/samples">
  <text>Listing Rubbish</text>
</ns1:echoString>
E

my $message = new WSO2::WSF::WSMessage(
	{ 'payload'	=> $payload,
	  'wsfc_home'   => '/opt/wso2/wsf_c/',
	  'to'		=> 'http://localhost/samples/echo_service_addr.php',
	  'action'	=> 'http://php.axis2.org/samples/echoString',
	  'log_level'   => 4
	} );

my $client = new WSO2::WSF::WSClient( { 'useWSA' => 'TRUE' } );

my $response = $client->request( $message );

print $response->{str};
