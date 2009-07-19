#!/bin/bash

_SAML="20"
_SCEN="scenario"
_SMPL_DIR="$PWD"
_PORT=9090
_SLEEP=3

INST_DIR=$AXIS2C_HOME
CLIENT_REPO="$INST_DIR/client_repo/"
SERVICE_HOME="$INST_DIR/services"

echo "------------------------------------------------------------------------------"
echo ">Deploying $_SCEN$_SAML"
echo "------------------------------------------------------------------------------"
sh deploy.sh $_SCEN$_SAML

echo "Replacing settings in policy files."
if [ `uname -s` = Darwin ]
then
    sed -e 's,AXIS2C_HOME,'$INST_DIR',g' -e 's,\.so,\.dylib,g' $_SCEN$_SAML/sts-client-policy.xml > $CLIENT_REPO/sts_policy.xml
else
    sed 's,AXIS2C_HOME,'$INST_DIR',g' $_SCEN$_SAML/sts-client-policy.xml > $CLIENT_REPO/sts_policy.xml
fi

echo "Replacing settings in Configuration files."
if [ `uname -s` = Darwin ]
then
    sed -e 's,AXIS2C_HOME,'$INST_DIR',g' -e 's,\.so,\.dylib,g' $_SCEN$_SAML/sts-services.xml > $SERVICE_HOME/saml_sts/services.xml
else
    sed 's,AXIS2C_HOME,'$INST_DIR',g' $_SCEN$_SAML/sts-services.xml > $SERVICE_HOME/saml_sts/services.xml
fi

echo ">Killing server"
killall axis2_http_server
echo "Sleeping for $_SLEEP seconds"
sleep $_SLEEP
echo ">Go to $AXIS2CHOME"
cd $AXIS2C_HOME/bin
echo ">Start server @ $_PORT"
./axis2_http_server -p$_PORT &
echo ">Go to client directory"
cd $_SMPL_DIR/../client/issued_token
echo ">Run the sample"
sh update_n_run.sh
echo ">Jump back to samples dir : $_SMPL_DIR"
cd $_SMPL_DIR

