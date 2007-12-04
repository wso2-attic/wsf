#!/usr/bin/env bash

ruby configure.rb
make
make install
cd wsservice
ruby configure.rb
make
make install
