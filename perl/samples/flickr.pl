#!/usr/bin/env perl

use WSO2::WSF;

# This will call the Flickr web service.  You need to provide your Flickr API key to get this
# sample working

$payload =<<E;
<x:FlickrRequest xmlns:x="urn:flickr">
  <method>flickr.test.echo</method>
  <api_key>your_api_key</api_key>
  <name>vacation</name>
</x:FlickrRequest>
E

my $client = new WSO2::WSF::WSClient( { 'wsfc_home' => '/opt/wso2/wsf_c',
	   	             		'to'        => 'http://api.flickr.com/services/soap/' } );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
