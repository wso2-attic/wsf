#!/bin/bash

CLIENT_REPO="$AXIS2C_HOME/client_repo"
echo "Start creating a client repository at $CLIENT_REPO"

if [ -d  $CLIENT_REPO ]; 
then
    echo "$CLIENT_REPO exists. "
else
    #Create client repo
    echo "Creating a new directory for client repo"
    mkdir $CLIENT_REPO
fi

#copy [client]axis2.xml to CLIENT_REPO
echo "Copying axis2.xml to $CLIENT_REPO"
cp ../data/client_axis2.xml $CLIENT_REPO/axis2.xml

#copy libs to client_repo
echo "Copying libraries to $CLIENT_REPO"
cp -r $AXIS2C_HOME/lib $CLIENT_REPO/

#INSTALL MODULES to make sure that both server and client have the same module.
echo "Copying latest modules to $CLIENT_REPO"
cp -r $AXIS2C_HOME/modules $CLIENT_REPO/

echo "WARNING: Make sure that you have correct configurations in sec_echo/services.xml and $CLIENT_REPO/axis2.xml file."
