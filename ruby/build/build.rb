#!/usr/bin/env ruby

system(%{./configure.rb;
        make;
        make install;
        cd wsservice;
        ./configure.rb;
        make;
        make install;})
