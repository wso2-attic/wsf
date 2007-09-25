#!/usr/bin/perl 

use WSO2::WSF;

$payload =<<E;
<ns1:echoString xmlns:ns1="http://perl.axis2.org/samples">
	<text>Listing Rubbish</text>
</ns1:echoString>
E

my $message = new WSO2::WSF::WSMessage(
	{ 'payload'	=> $payload,
	  'axis2c_home' => '/where/is/axis2/',
	  'to'		=> 'http://localhost:8585/axis2/services/echo',
	  'action'	=> 'http://perl.axis2.org/samples/echoString' } );

my $client = new WSO2::WSF::WSClient( { 'useWSA' => 'TRUE' } );

my $response = $client->request( $message );

print $response->{str};
