#!/usr/bin/env perl

use WSO2::WSF::WSClient;

my @payload_strings;

for ( my $i = 0; $i < 10; $i++ ) {
    $payload_strings[$i] = <<EOF;
<ns1:echoString xmlns:ns1="http://ws.apache.org/axis2/c/samples">
   <text>Parallel universe - $i</text>
</ns1:echoString>
EOF
}

my $service_client = new WSO2::WSF::WSClient( { 'axis2c_home' => '/where/is/wsf/c',
					        'to'          => 'http://localhost:8585/axis2/services/echo'
					      } );

for ( my $i = 0; $i < 10; $i++ ) {
    my $msg = new WSO2::WSF::WSMessage( { 'payload' => $payload_strings[$i],
					  'to'      => 'http://localhost:8585/axis2/services/echo' } );

    my $response = $service_client->request( $msg );

    print $response->{str} . "\n";
}
