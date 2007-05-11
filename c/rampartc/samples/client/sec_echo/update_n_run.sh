#!/bin/bash
#If your client repository is different, change the value.
CLIENT_REPO="$AXIS2C_HOME/client_repo"

#INSTALL MODULE to make sure that both server and client have the same module.
echo "Copying latest module to client_repo"
cp -r $AXIS2C_HOME/modules/rampart $CLIENT_REPO/modules

#RUN
./echo http://localhost:9090/axis2/services/sec_echo $CLIENT_REPO
