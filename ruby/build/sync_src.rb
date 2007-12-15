#!/usr/bin/env ruby

# Generate WSFC Wrapper
system('swig -ruby -I../swig/ -o WSFC_wrapper.c -outdir ./ -Wall WSFC.i') unless File.exists?('WSFC_wrapper.c')

# Create "lib" Directory
Dir.mkdir('lib') unless (FileTest.exist?('lib') && FileTest.directory?('lib'))

system('rsync -r --exclude=wsservice --exclude=.svn ../src/* lib')
system('rsync -r --exclude=.svn ../src/wsservice .')
