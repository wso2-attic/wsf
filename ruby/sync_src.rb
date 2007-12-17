#!/usr/bin/env ruby

# Generate WSFC Wrapper
system('swig -ruby -Iswig/ -o WSFC_wrapper.c -outdir ./ -Wall WSFC.i') unless File.exists?('WSFC_wrapper.c')
