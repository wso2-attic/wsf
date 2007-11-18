#!/usr/bin/env ruby

system(%{ruby configure.rb;
        make;
        make install;
        cd wsservice;
        ruby configure.rb;
        make;
        make install;})
