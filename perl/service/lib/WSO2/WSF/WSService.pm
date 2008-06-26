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
use WSO2::WSF::Server;
# use Apache2::RequestUtil ();

sub new {
    my $class = shift;
    my $options = shift;
    my $repo_path = '/opt/wso2/wsf_c';
    my $self = {
        -rh => $options->{'operations'},
        -svc_info => WSO2::WSF::Server::wsf_svc_info_t->new(),
        -env => WSO2::WSF::Server::wsf_env_create("/tmp", 4),
    };

    my $msg_recv = WSO2::WSF::Server::wsf_xml_msg_recv_create( $self->{-env} );
    WSO2::WSF::C::axis2_log_debug( $self->{-env}, "[wsf-perl] xml message receiver creation failed" )
        unless defined $msg_recv;

    WSO2::WSF::Server::axiom_xml_reader_init();

    my $worker = WSO2::WSF::Server::wsf_worker_create( $self->{-env}, $repo_path );
    WSO2::WSF::C::axis2_log_debug( $self->{-env}, "[wsf-perl] worker create faild for repo path $repo_path " )
        unless defined $worker;

#    $self->{-request} = Apache2::RequestUtil->request();

    $self->{-msg_recv} = $msg_recv;
    $self->{-worker} = $worker;

    bless $self, $class;
    return $self;
}

sub fill_svc_info {
    my $self = shift;
    my $svc_info = shift;
    my $request = shift;
    my $env = shift;
    my $worker = shift;

    my $h_ops_to_function = WSO2::WSF::C::axutil_hash_make($env);
    my $h_ops_to_action = WSO2::WSF::C::axutil_hash_make($env);

    foreach (keys %{$self->{-rh}}){
        WSO2::WSF::C::axutil_hash_set($h_ops_to_function, $_, -1, $self->{-rh}->{$_});
    }

    #populating svc_info
    WSO2::WSF::Serverc::wsf_svc_info_t_ops_to_functions_set($svc_info, $h_ops_to_function);
    WSO2::WSF::Serverc::wsf_svc_info_t_ops_to_actions_set($svc_info, $h_ops_to_action);

    #generating svc_name replacing / with |
    #for example /axis2/services/echo_services.pl becomes
    #|axis2|services|echo_services.pl
    my $svc_name = $request->uri();
    $svc_name =~ s#/#|#g;
    WSO2::WSF::Serverc::wsf_svc_info_t_svc_name_set($svc_info, $svc_name);
    WSO2::WSF::Serverc::wsf_svc_info_t_msg_recv_set($svc_info, $self->{-msg_recv});

    WSO2::WSF::Serverc::wsf_svc_info_t_script_filename_set($svc_info, $request->filename());

    #setting perl worker for svc_info structure because that is essential
    #for creating svc from svc_info.
    WSO2::WSF::Serverc::wsf_svc_info_t_perl_worker_set($svc_info, $worker);

    WSO2::WSF::Serverc::wsf_util_create_svc_from_svc_info($svc_info, $env);
    WSO2::WSF::Serverc::wsf_util_process_ws_service_operations_and_actions ($svc_info, $env);
    WSO2::WSF::Serverc::wsf_util_conf_add_svc($svc_info, $env);

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
    my $self = shift;
    my $request = shift;

    #get global env and worker
    my $env = $self->{-env};
    my $worker = $self->{-worker};
    my $svc_info = $self->{-svc_info};

    #request infor structure
    my $req_info = WSO2::WSF::Server::wsf_req_info_t->new();

    fill_svc_info($self, $svc_info, $request, $env, $worker);

    #populating wsf_request_info structure

    # getting a type error from swig saying the 2nd argument should be a char *
    # so concaternating with an empty string
    my $content_type = "" . $request->headers_in->{'content-type'};

    WSO2::WSF::Serverc::wsf_req_info_t_content_encoding_set($req_info, $request->content_encoding());
    WSO2::WSF::Serverc::wsf_req_info_t_content_type_set($req_info, $content_type);
    WSO2::WSF::Serverc::wsf_req_info_t_content_length_set($req_info, $request->headers_in->{'content-length'});
    WSO2::WSF::Serverc::wsf_req_info_t_svr_name_set($req_info, $request->hostname());

    my @svrinfo = split(/:/, $request->headers_in->{'host'}); # This will have servername and the port number
    WSO2::WSF::Serverc::wsf_req_info_t_svr_port_set($req_info, $svrinfo[1]); # getting the port number

    WSO2::WSF::Serverc::wsf_req_info_t_http_protocol_set($req_info, $request->protocol());

    if (defined $request->headers_in->{'soapaction'}) {
        WSO2::WSF::Serverc::wsf_req_info_t_soap_action_set($req_info, $request->headers_in->{'soapaction'});
    }

    WSO2::WSF::Serverc::wsf_req_info_t_request_method_set($req_info, $request->method());
    WSO2::WSF::Serverc::wsf_req_info_t_request_uri_set($req_info, $request->uri());
    WSO2::WSF::Serverc::wsf_req_info_t_query_string_set($req_info, $request->args());

    my $postdata;
    $request->read($postdata, $request->headers_in->{'content-length'});
    WSO2::WSF::Serverc::wsf_req_info_t_req_data_set($req_info, $postdata);

    WSO2::WSF::Serverc::wsf_req_info_t_req_data_length_set($req_info, $request->headers_in->{'content-length'});

    #invoking worker
    my $status = WSO2::WSF::Serverc::wsf_worker_process_request($worker, $env, $req_info, $svc_info);

    # WSO2::WSF::C::axis2_log_debug( $env, "****** $status" );
    # $request->status($status);
    my $respayload = WSO2::WSF::Serverc::wsf_req_info_t_result_payload_get($req_info);

    $request->content_type( 'application/soap+xml;charset=UTF-8' );
    print $respayload;
}

1;
