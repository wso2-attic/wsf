#!/bin/bash
./autogen.sh
./configure --prefix=${AXIS2C_HOME} --enable-static=no 
make
make install
cd client/sec_echo
sh deploy_client_repo.sh
cd ../../secpolicy
sh deploy.sh scenario7
cd ../
echo "samples successfuly build.To run echo client cd to client/sec_echo and run update_n_run.sh"
