#!/usr/bin/env bash

wsfc_home=$(./get_wsfc_home.rb)

cd wsdlc
sh autogen.sh
./configure --prefix="$wsfc_home"
make
make install

cd ..

ruby extconf.rb
make
make install

cd wsservice
ruby extconf.rb 
make
make install
