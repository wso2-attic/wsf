#!/usr/bin/env perl

use WSO2::WSF;

# This sample demonstrate calling a REST service.  Assumes WSF/C is installed and listening on
# port 8585

$payload =<<E;
<ns1:echoString xmlns:ns1="http://perl.axis2.org/samples">
  <text>Listing Rubbish</text>
</ns1:echoString>
E

my $client = new WSO2::WSF::WSClient(
	{ 'wsfc_home'  => '/opt/wso2/wsf_c/',
	  'to'         => 'http://localhost:8585/axis2/services/echo/echoString',
  	  'HTTPMethod' => 'GET',
  	  'useSOAP'    => 'FALSE'
	} );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
