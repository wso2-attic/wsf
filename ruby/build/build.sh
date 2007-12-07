#!/usr/bin/env bash

ruby extconf.rb
make
make install
cd wsservice
ruby extconf.rb 
make
make install
