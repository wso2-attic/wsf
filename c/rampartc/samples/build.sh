#!/bin/bash
./autogen.sh
./configure --prefix=${AXIS2C_HOME} --enable-static=no --with-axis2=${AXIS2C_HOME}/include/axis2-1.1
make
make install
cd client/sec_echo
sh deploy_client_repo.sh
cd ../../secpolicy
sh deploy.sh scenario5
cd ../
echo "samples successfuly build. To run echo client cd to client/sec_echo and run update_n_run.sh"
