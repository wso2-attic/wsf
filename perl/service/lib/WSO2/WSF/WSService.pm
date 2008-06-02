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
use WSO2::WSF::C;
use WSO2::WSF::WSRequest;
use WSO2::WSF::Server;
use Data::Dumper;
use CGI;

sub new {
    my $class = shift;
    my $self = {
        -rh => shift,
        -request => new WSO2::WSF::WSRequest (),
        -svc_info => WSO2::WSF::Server::wsf_svc_info_t->new (),
        -env => WSO2::WSF::Server::wsf_get_env(),
        -worker => WSO2::WSF::Server::wsf_get_worker(),
        -msg_recv => WSO2::WSF::Server::wsf_get_msg_recv()
    };
    my $env = $self->{-env};
    my $request = $self->{-request};
    my $operation = $self->{-rh};
    my $svc_info = $self->{-svc_info};
    my $msg_recv = $self->{-msg_recv};
    my $worker = $self->{-worker};
    #$request populate method is used to populate $request object with
    #information in CGI.
    $request->populate;

    my $h_ops_to_function = WSO2::WSF::C::axutil_hash_make($env);
    my $h_ops_to_action = WSO2::WSF::C::axutil_hash_make($env);


    my $rh_op = $operation->{'operations'};
    foreach (keys %$rh_op){
        WSO2::WSF::C::axutil_hash_set($h_ops_to_function, $_, -1, $rh_op->{$_});
    }
    #populating svc_info
    WSO2::WSF::Serverc::wsf_svc_info_t_ops_to_functions_set($svc_info, $h_ops_to_function);
    WSO2::WSF::Serverc::wsf_svc_info_t_ops_to_actions_set($svc_info, $h_ops_to_function);

    #generating svc_name replacing / with |
    #for example /axis2/services/echo_services.pl becomes
    #|axis2|services|echo_services.pl
    my $svc_name = $request->{-url_abs};
    $svc_name =~ s#/#|#g;
    WSO2::WSF::Serverc::wsf_svc_info_t_svc_name_set($svc_info, $svc_name);
    WSO2::WSF::Serverc::wsf_svc_info_t_msg_recv_set($svc_info, $msg_recv);

    my $script_filename = $request->{-script_filename};
    WSO2::WSF::Serverc::wsf_svc_info_t_script_filename_set($svc_info, $script_filename);

    #setting perl worker for svc_info structure because that is essential
    #for creating svc from svc_info.
    WSO2::WSF::Serverc::wsf_svc_info_t_perl_worker_set($svc_info, $worker);

    WSO2::WSF::Serverc::wsf_util_create_svc_from_svc_info($svc_info, $env);
    WSO2::WSF::Serverc::wsf_util_process_ws_service_operations_and_actions ($svc_info, $env);
    WSO2::WSF::Serverc::wsf_util_conf_add_svc($svc_info, $env);

    bless $self, $class;
    return $self;
}

# test method is for debugging purposes
sub test {
    my ($self) = @_;
    my ($value, $key);
    my $operation = $self->{-rh};
    my $rh_op = $operation->{'operations'};
    while (($key, $value) = each (%$rh_op)){
        print "key value is $key and value is $value \n";
    }
    print "action ".$operation->{'action'}."\n";
}

sub reply {
    my ($self) = @_;

    #get global env and worker
    my $env = $self->{-env};
    my $worker = $self->{-worker};
    my $request = $self->{-request};
    my $svc_info = $self->{-svc_info};


    #request infor structure
    my $req_info = WSO2::WSF::Server::wsf_req_info_t->new ();

    #populating wsf_request_info structure
    WSO2::WSF::Serverc::wsf_req_info_t_content_encoding_set($req_info, $request->{-content_type});
    WSO2::WSF::Serverc::wsf_req_info_t_content_type_set($req_info, $request->{-content_type});
    WSO2::WSF::Serverc::wsf_req_info_t_content_length_set($req_info, $request->{-content_length});
    WSO2::WSF::Serverc::wsf_req_info_t_svr_name_set($req_info, $request->{-server_name});
    WSO2::WSF::Serverc::wsf_req_info_t_svr_port_set($req_info, $request->{-server_port});
    WSO2::WSF::Serverc::wsf_req_info_t_http_protocol_set($req_info, $request->{-server_protocol});
    WSO2::WSF::Serverc::wsf_req_info_t_soap_action_set($req_info, $request->{-soap_action});
    WSO2::WSF::Serverc::wsf_req_info_t_request_method_set($req_info, $request->{-request_method});
    WSO2::WSF::Serverc::wsf_req_info_t_request_uri_set($req_info, $request->{-url_abs});
    WSO2::WSF::Serverc::wsf_req_info_t_query_string_set($req_info, $request->{-query_string});
    WSO2::WSF::Serverc::wsf_req_info_t_req_data_set($req_info, $request->{-postdata});
    WSO2::WSF::Serverc::wsf_req_info_t_req_data_length_set($req_info,
                                                           $request->{-content_length});
    #populating svc_info struct
    print "worker ".$worker." env ".$env."\n";

    #invoking worker
    WSO2::WSF::Serverc::wsf_worker_process_request($worker, $env, $req_info, $svc_info);
}


1;
