# Copyright 2005 - 2008 WSO2, Inc. http://wso2.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

package WSO2::WSF::WSService;

use WSO2::WSF::WSConfig;
use WSO2::WSFC;
use Data::Dumper;

sub new {
    my $class = shift;
    my $self = {
        _rh => shift,
    };
    bless $self, $class;
    return $self;
}

# test method is for debugging purposes
sub test {
    my ($self) = @_;
    my ($value, $key);
    my $operation = $self->{_rh};
    my $rh_op = $operation->{'operations'};
    while (($key, $value) = each (%$rh_op)){
        print "key value is $key and value is $value \n";
    }
    print "action ".$operation->{'action'}."\n";
}

sub reply {
    my ($self) = @_;
    print "invoking reply method"."\n";
}



1;
