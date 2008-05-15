#!/usr/bin/env perl

use WSO2::WSF;

# This samples demonstrate sending a simple message to a service and getting a reply back.
# Assumes WSF/PHP is installed and all the samples can be accessed from http://localhost/samples/

my $payload =<<E;
<ns1:echoString xmlns:ns1="http://ws.apache.org/axis2/c/samples">
  <text>Hello World!</text>
</ns1:echoString>
E

my $client = new WSO2::WSF::WSClient(
    { 'to'          => 'http://localhost/samples/echo_service.php',
      'log_file' => '/tmp/thislogfile',
      'log_level' => 4
    } );

my $response = $client->request( { 'payload' => $payload } );

print $response->{str};
