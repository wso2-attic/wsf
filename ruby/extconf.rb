#!/usr/bin/env ruby

require 'mkmf'
require 'rbconfig'
require 'fileutils'

# Check the configurations
wsfc_Home = '/opt/wso2/wsf_c'

# recording the dir we're at
pwd = FileUtils.pwd()

# check for the environment variable
if not ENV['WSFC_HOME'].nil?
  wsfc_Home = ENV['WSFC_HOME']
else
  begin
    FileUtils.cd(wsfc_Home)
    # ah, we came here, so the standard directory exists
    # let's go back then
    FileUtils.cd(pwd)
  rescue Exception => e
    puts <<E
WSF/C not found. If you have installed WSF/C into a non standard location
please set wsfc_Home environment variable to where you have installed it.
E
    exit -1
  end
end
puts "Using WSF/C installed in #{wsfc_Home}"

dir_config('wsdlc', './wsdlc/include', './wsdlc/lib')

# Add Build Rules
if /mswin32|bccwin32/ =~ RUBY_PLATFORM
    dir_config('WSFC', wsfc_Home + '/include', wsfc_Home + '/lib')
    $CFLAGS = $CFLAGS + " -DWIN32 -DSWIG_NOINCLUDE"
    have_library('libxml2')
    have_library('axiom')
else
    dir_config('WSFC', wsfc_Home + '/include/axis2-1.4.0', wsfc_Home + '/lib')
    dir_config('Rampart', wsfc_Home + '/include/rampart-1.2.0', wsfc_Home + '/modules/rampart')
    have_library('axis2_axiom')
end

have_library('wsdlc')
have_library('axutil')
have_library('axis2_parser')
have_library('axis2_engine')
have_library('axis2_http_common')
have_library('axis2_http_sender')
have_library('axis2_http_receiver')
have_library('omxmlsec')
have_library('oxstokens')
have_library('saml')
have_library('omopenssl')
have_library('neethi')
have_library('neethi_util')
have_library('mod_rampart')
have_library('sandesha2_client')

create_makefile('WSFC')
