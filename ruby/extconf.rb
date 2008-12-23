#!/usr/bin/env ruby

require 'mkmf'
require 'rbconfig'
require 'fileutils'

# Check the configurations
WSFC_HOME = '/opt/wso2/wsf_c'

# recording the dir we're at
pwd = FileUtils.pwd()

# check for the environment variable
if not ENV['WSFC_HOME'].nil?
  WSFC_HOME = ENV['WSFC_HOME']
else
  begin
    FileUtils.cd(WSFC_HOME)
    # ah, we came here, so the standard directory exists
    # let's go back then
    FileUtils.cd(pwd)
  rescue Exception => e
    puts <<E
WSF/C not found. If you have installed WSF/C into a non standard location
please set WSFC_HOME environment variable to where you have installed it.
E
    exit -1
  end
end
puts "Using WSF/C installed in #{WSFC_HOME}"

dir_config('wsdlc', './wsdlc/include', './wsdlc/lib')

# Add Build Rules
if /mswin32|bccwin32/ =~ RUBY_PLATFORM
    dir_config('WSFC', WSFC_HOME + '/include', WSFC_HOME + '/lib')
    $CFLAGS = $CFLAGS + " -DWIN32 -DSWIG_NOINCLUDE"
    have_library('libxml2')
    have_library('axiom')
else
    dir_config('WSFC', WSFC_HOME + '/include/axis2-1.4.0', WSFC_HOME + '/lib')
    dir_config('Rampart', WSFC_HOME + '/include/rampart-1.2.0', WSFC_HOME + '/modules/rampart')
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
