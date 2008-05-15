#!/usr/bin/env perl

use WSO2::WSF;

# This will call the Yahoo! web service and return the search results.

$payload =<<E;
<webSearch><appid>WSF/Perl</appid><query>ethanol</query><form/></webSearch>
E

my $client = new WSO2::WSF::WSClient( 
	{ 'to'		=> 'http://search.yahooapis.com/WebSearchService/V1/webSearch',
  	  'HTTPMethod'	=> 'GET',
  	  'useSOAP'	=> 'FALSE' } );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
