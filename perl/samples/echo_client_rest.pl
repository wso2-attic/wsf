#!/usr/bin/perl

use WSO2::WSF;

$payload =<<E;
<ns1:echoString xmlns:ns1="http://perl.axis2.org/samples">
        <text>Listing Rubbish</text>
</ns1:echoString>
E

my $client = new WSO2::WSF::WSClient( 
	{ 'axis2c_home' => '/where/is/axis2/',
	  'to'		=> 'http://localhost:8585/axis2/services/echo',
  	  'HTTPMethod'	=> 'GET',
  	  'useSOAP'	=> 'FALSE' } );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
