#!/usr/bin/perl

use WSO2::WSF;

$payload =<<E;
<webSearch><appid>WSF/Perl</appid><query>ethanol</query><form/></webSearch>
E

my $client = new WSO2::WSF::WSClient( 
	{ 'axis2c_home' => '/where/is/axis2/',
	  'to'		=> 'http://search.yahooapis.com/WebSearchService/V1/webSearch',
  	  'HTTPMethod'	=> 'GET',
  	  'useSOAP'	=> 'FALSE' } );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
