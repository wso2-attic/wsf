#!/bin/bash
if [ $# -ne 1 ]
then
    echo "Usage : $0 scenarioX"
    exit
fi

INST_DIR=$AXIS2C_HOME
CLIENT_REPO="$INST_DIR/client_repo/"
SERVICE_HOME="$INST_DIR/services/sec_echo"

echo "Copying server's axis2.xml to " $AXIS2C_HOME
cp ../server/sec_echo/server_axis2.xml $AXIS2C_HOME/axis2.xml

#COPYING THE RELEVENT POLICY FILES TO CLIENT AND SERVER


echo "Replacing settings in policy files."
if [ `uname -s` = Darwin ]
then
    sed -e 's,AXIS2C_HOME,'$INST_DIR',g' -e 's,\.so,\.dylib,g' $1/client-policy.xml > $CLIENT_REPO/policy.xml
else
    sed 's,AXIS2C_HOME,'$INST_DIR',g' $1/client-policy.xml > $CLIENT_REPO/policy.xml
fi

echo "Replacing settings in Configuration files."
if [ `uname -s` = Darwin ]
then
    sed -e 's,AXIS2C_HOME,'$INST_DIR',g' -e 's,\.so,\.dylib,g' $1/services.xml > $SERVICE_HOME/services.xml
else
    sed 's,AXIS2C_HOME,'$INST_DIR',g' $1/services.xml > $SERVICE_HOME/services.xml
fi

