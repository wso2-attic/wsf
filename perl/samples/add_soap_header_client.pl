#!/usr/bin/env perl

use WSO2::WSF;

# This sample shows how to add custom SOAP headers

$payload =<<E;
<ns1:echoString xmlns:ns1="http://ws.apache.org/axis2/c/samples">
<text>Hello World!</text>
</ns1:echoString>
E

my $name = new WSO2::WSF::WSHeader( {'name' => 'name',
				     'data' => 'ServiceRequester1' } );

my $version = new WSO2::WSF::WSHeader( {'name' => 'version',
					'data' => '1.0' } );

my $timereq = new WSO2::WSF::WSHeader( {'name' => 'timeRequestMade',
					'data' => '13:20:00' } );

my $capp = new WSO2::WSF::WSHeader( {'name' => 'CallingApplication',
				     'ns' => 'http://SOAPHeaderDemonstration',
				     'nsprefix' => 'MyPrefix',
				     'data' => [$name, $version, $timereq] } );

my $client = new WSO2::WSF::WSClient( { 'wsfc_home'  => '/opt/wso2/wsf_c',
	   	             		'to'           => 'http://localhost/axis2/services/echo',
					'payload'     => $payload,
					'inputHeaders' => [$capp]
				      } );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
