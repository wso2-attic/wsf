#!/usr/bin/env ruby

# Generate WSFC Wrapper
system('swig -ruby -I../swig/ -o WSFC_wrapper.c -outdir ./ -Wall WSFC.i') unless File.exists?('WSFC_wrapper.c')
