#!/usr/bin/env perl

use WSO2::WSF;

# This assumes WSF/C is installed and axis2_http_server is listening on port 8585

my $payload =<<E;
<ns1:ping xmlns:ns1="http://tempuri.org/">
  <ns1:Text>ping1</ns1:Text>
</ns1:ping>
E

my $msg = new WSO2::WSF::WSMessage(
    { 'to'      => 'http://127.0.0.1:8585/axis2/services/RMSampleService',
      'action'  => 'http://php.axis2.org/samples/pingString',
      'payload' => $payload
    } );

my $client = new WSO2::WSF::WSClient(
    { 'reliable' => 'TRUE',
      'useWSA'   => 'TRUE'
    } );

$client->send_message( $msg );

sleep(10);
