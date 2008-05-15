#!/usr/bin/env perl

use WSO2::WSF;

# This client demonstrate how to specify which SOAP binding to use.  By default SOAP 1.2 will
# be used.  Specify the version using 'useSOAP' => '1.1' to use SOAP 1.1.  Assumes WSF/C is
# installed and axis2_http_server is listening on port 8585

$payload =<<E;
<ns1:echoString xmlns:ns1="http://perl.axis2.org/samples">
  <text>Listing Rubbish</text>
</ns1:echoString>
E

my $message = new WSO2::WSF::WSMessage(
	{ 'payload'	=> $payload,
	  'axis2c_home' => '/opt/wso2/wsf_c/',
	  'to'		=> 'http://localhost:8585/axis2/services/echo',
	  'action'	=> 'http://perl.axis2.org/samples/echoString'
	} );

my $client = new WSO2::WSF::WSClient( { 'useSOAP' => '1.1' } );

my $response = $client->request( $message );

print $response->{str};
