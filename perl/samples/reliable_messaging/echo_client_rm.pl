#!/usr/bin/env perl

use WSO2::WSF;

my $payload =<<E;
<ns1:echoString xmlns:ns1="http://tempuri.org/">
  <ns1:Text>echo1</ns1:Text>
</ns1:echoString>
E

my $msg = new WSO2::WSF::WSMessage( { 'action' => 'http://php.axis2.org/samples/echoString',
                                      'payload' => $payload
                                    } );

my $client = new WSO2::WSF::WSClient(
    { 'to' => 'http://localhost:8585/axis2/services/RMSampleService',
      'reliable' => 'TRUE',
      'log_level' => 6
    } );

my $res_msg = $client->request( $msg );

print $res_msg->{str} if defined $res_msg;

sleep(10);
