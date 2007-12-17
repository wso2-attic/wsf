#!/usr/bin/env ruby

require 'mkmf'
require 'rbconfig'


# Check the configurations
WSFC_HOME = Config::CONFIG['WSFC_HOME']
if(WSFC_HOME == nil)
  puts "Error in retrieving the WSFC_HOME from configuration, Add the WSFC_HOME in rbconfig.rb\n"
  exit(-1)
end

if /mswin32|bccwin32/ =~ RUBY_PLATFORM
    dir_config('WSFC', WSFC_HOME + '/include', WSFC_HOME + '/lib')
    $CFLAGS = $CFLAGS + " -DWIN32 -DSWIG_NOINCLUDE"
    have_library('libxml2')
    have_library('axiom')
else
    dir_config('WSFC', WSFC_HOME + '/include/axis2-1.2', WSFC_HOME + '/lib')
    dir_config('Rampart', WSFC_HOME + '/include/rampart-1.0', WSFC_HOME + '/modules/rampart')
    have_library('axis2_libxml2') 
    have_library('axis2_axiom')
  end
  
have_library('axutil')
have_library('axis2_minizip')
have_library('axis2_parser')
have_library('axis2_engine')
have_library('axis2_http_common')
have_library('axis2_http_sender')
have_library('axis2_http_receiver')
have_library('axis2_engine')



create_makefile("wsservice")
