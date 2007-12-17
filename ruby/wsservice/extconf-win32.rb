#!/usr/bin/env ruby

require 'mkmf'
require 'rbconfig'


# Check the configurations
WSFC_HOME = Config::CONFIG['WSFC_HOME']
if(WSFC_HOME == nil)
  puts "Error in retrieving the WSFC_HOME from configuration, Add the WSFC_HOME in rbconfig.rb\n"
  exit(-1)
end

dir_config("wsservice", WSFC_HOME + '/include', WSFC_HOME + '/lib')

have_library('axutil')
have_library('axis2_minizip')
have_library('axis2_parser')
have_library('libxml2')
have_library('axiom')
have_library('axis2_engine')
have_library('axis2_http_common')
have_library('axis2_http_sender')
have_library('axis2_http_receiver')
have_library('axis2_engine')
have_library('neethi')
have_library('neethi_util')
have_library('mod_rampart')

$CFLAGS = $CFLAGS + " -DWIN32 -DSWIG_NOINCLUDE"

create_makefile("wsservice")
