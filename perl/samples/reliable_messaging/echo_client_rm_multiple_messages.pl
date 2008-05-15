#!/usr/bin/env perl

use WSO2::WSF;

# This sample sending multiple messages with WS-RM using a single client instance.
# Assumes WSF/C is installed and axis2_http_server is listening on port 8585

my $payload =<<E;
<ns1:echoString xmlns:ns1="http://tempuri.org/">
  <ns1:Text>Gah.</ns1:Text>
</ns1:echoString>
E

my $message = new WSO2::WSF::WSMessage(
    { 'to'      => 'http://localhost:8585/axis2/services/RMSampleService',
      'action'  => 'http://php.axis2.org/samples/echoString',
      'payload' => $payload
    } );

my $client = new WSO2::WSF::WSClient(
    { 'reliable'               => 'TRUE',
      'useWSA'                 => 'TRUE',
      'will_continue_sequence' => 'TRUE',
      'log_level'              => 4
    } );

$client->request( $message );

my $message1 = new WSO2::WSF::WSMessage(
    { 'to'      => 'http://localhost:8585/axis2/services/RMSampleService',
      'action'  => 'http://php.axis2.org/samples/echoString',
      'payload' => $payload
    } );

$client->request( $message1 );

my $message2 = new WSO2::WSF::WSMessage(
    { 'to'           => 'http://localhost:8585/axis2/services/RMSampleService',
      'action'       => 'http://php.axis2.org/samples/echoString',
      'last_message' => 'TRUE',
      'payload'      => $payload
    } );

$client->request( $message2 );

sleep(10);
