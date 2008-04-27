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
use WSO2::WSF::WSFC;

sub new 
{
    my $this = shift;
    my $properties = {};

    # Create environment
    my $env = WSO2::WSF::WSFC::wsf_env_create ($WSO2::WSF::WSConfig::LOG_PATH,
                                               $WSO2::WSF::WSConfig::LOG_LEVEL);
    $properties->{"env"} = $env;

    # Create message receiver
    my $msg_recv = WSO2::WSF::WSFC::wsf_xml_msg_recv_create ($env);
    $properties->{"msg_recv"} = $msg_recv;

    # Initialize XML reader
    WSO2::WSF::WSFC::axiom_xml_reader_init ();

    # Create worker
    my $worker = WSO2::WSF::WSFC::wsf_worker_create ($env,
                                                     $WSO2::WSF::WSConfig::WSFC_HOME);

    # Initialize object with the given set of properties
    my %options = @_;
    while (($key, $value) = each (%options))
    {
        $properties->{$key} = $value;
    }

    bless $properties, $this;

    return $properties;
}


sub test
{
    my $this = shift;

    while (($key, $value) = each (%$this))
    {
        print $key . " -> " . $value . "\n";
    }

}

1;
