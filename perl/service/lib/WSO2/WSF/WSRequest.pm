package WSO2::WSF::WSRequest;
use CGI;

sub new {
    my $class = shift;
    my $self = {
        -cgi => new CGI
    };
    bless $self, $class;
    return $self;
}


sub postdata {
    my ($self) = @_;
    my $cgi = $self->{-cgi};
    return $cgi->param('POSTDATA');
}


sub content_type {
    my ($self) = @_;
    my $cgi = $self->{-cgi};
    die "cgi object is not created" unless $cgi;
    return $cgi->content_type();
}


sub url {
    my ($self) = @_;
    my $cgi = $self->{-cgi};
    $self->{-url} = $cgi->url(-path-info=>1 , -query => 1);
    return $self->{-url};
}


sub http_header {
    my ($self, $header) = @_;
    my $cgi = $self->{-cgi};
    return $cgi->http($header);
}


sub request_method {
    my ($self, $header) = @_;
    my $cgi = $self->{-cgi};
    return $cgi->request_method;
}

sub status {
    my ($self, $status) = @_;
    my $cgi = $self->{-cgi};
    print $cgi->header(-status=>$status);
}

sub cgi {
    my ($self) = @_;
    $self->{-cgi};
}

sub populate {
    my ($self) = @_;
    my $cgi = $self->{-cgi};
    $self->{-content_type} = $cgi->content_type;
    $self->{-content_length} = $ENV{'CONTENT_LENGTH'};
    $self->{-request_method} = $cgi->request_method;
    $self->{-server_name} = $cgi->server_name;
    $self->{-server_port} = $cgi->server_port;
    $self->{-postdata} = $cgi->param('POSTDATA');
    $self->{-soap_action} = $cgi->http('SOAPACTION');
    $self->{-user_agent} = $cgi->user_agent;
    $self->{-server_protocol} = $cgi->server_protocol;
    $self->{-param} = $cgi->param;
    $self->{-url_rel} = $cgi->url(-relative => 1);
    $self->{-url_abs} = $cgi->url(-absolute => 1);
    $self->{-url_full} = $cgi->url();
    $self->{-query_string} = $ENV{'QUERY_STRING'};
    $self->{-script_filename} = $ENV{'SCRIPT_FILENAME'};
    return 1;
}

sub DESTROY {
    print "called wsrequest destroy";
}

1;


