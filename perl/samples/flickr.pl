#!/usr/bin/perl

use WSO2::WSF;
use WSO2::WSF::WSClient;

$payload =<<E;
<x:FlickrRequest xmlns:x="urn:flickr">
<method>flickr.test.echo</method>
<api_key>your_api_key</api_key>
<name>vacation</name>
</x:FlickrRequest>
E

my $client = new WSO2::WSF::WSClient( { 'axis2c_home' => '/where/is/axis2/',
	   	             		'to'          => 'http://api.flickr.com/services/soap/' } );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
