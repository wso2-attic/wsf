#!/usr/bin/env bash
set -e

# first check the env for WSFC_HOME, then the standard location, if both
# fails, crap out. Cannot continue without WSF/C
if [ "${WSFC_HOME}" != "" ]
then
    wsfc_home=$WSFC_HOME
elif [ -a "/opt/wso2/wsf_c" ]
then
    wsfc_home="/opt/wso2/wsf_c"
else
    echo "
Error: Cannot find WSF/C installation.

If you have installed WSF/C to a non-standard location please set WSFC_HOME
to where you have installed it. If you haven't installed WSF/C please install
WSF/C before installing WSF/Ruby.
"
    exit -1
fi

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
