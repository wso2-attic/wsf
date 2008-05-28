#!/usr/bin/perl
use strict;
use WSO2::WSF;
use WSO2::WSF::WSService;
my ($payload, $service);
my %operations;
$payload =<<E;
<ns1:echoString xmlns:ns1="http://perl.axis2.org/samples">
        <text>Listing Rubbish</text>
</ns1:echoString>
E

sub echoFunction {
    my $message; 
    my $arg = $_[0];
    print "invoking echoFunction\n";	
    $message = new WSO2::WSF::WSMessage ({'payload' => $arg});
    return $message;
}

sub print_this {
    print "test 123 dinesh ###\n";
}

%operations = ( 'echoString' => 'echoFunction',
                'echoAdd' => 'addTwoIntegers',
                'echoSub' => 'subTwoIntegers');

$service = new WSO2::WSF::WSService({'operations' => \%operations,
                                     'action' => 'testAction'});
$service->reply ();
