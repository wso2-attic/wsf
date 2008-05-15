#!/usr/bin/env perl

use WSO2::WSF;

# This sample tries to download an image from a service hosted with WSF/PHP
# and assumes that you've installed and configured WSF/PHP and all the samples
# can be accessed from http://localhost/samples.

my $payload =<<E;
<download />
E

my $client = new WSO2::WSF::WSClient(
    { 'to'        => 'http://localhost/samples/mtom/mtom_download_service.php',
      'wsfc_home' => '/opt/wso2/wsf_c',
      'useMTOM' => 'TRUE',
      'responseXOP' => 'TRUE'
    } );

my $msg = new WSO2::WSF::WSMessage( { 'payload' => $payload } );

my $res = $client->request( $msg );


my $atts = $res->{attachments};
my $ct = $res->{content_types};

my $image_name = '';

if ( defined($atts) && defined($ct) ) {
    foreach my $attachment (keys %{$atts}) {
	my $f = $atts->{$attachment};
	my $content_type = $ct->{$attachment};
	if ( $content_type eq "image/jpeg" ) {
	    $image_name = "$attachment.jpg";
	    open IMG, "> $image_name";
	    binmode IMG;
	    syswrite IMG, $f;
	    close IMG;
	}
    }
}
