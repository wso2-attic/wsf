#!/bin/bash
if [ $# -ne 1 ]
then
    echo "Usage : $0 scenarioX"
    exit
fi

CLIENT_REPO="$AXIS2C_HOME/client_repo"
SERVICE_HOME="$AXIS2C_HOME/services/sec_echo/"

#COPYING THE RELEVENT POLICY FILES TO CLIENT AND SERVER

#copy client policy files to CLIENT_REPO
echo "Copying client policy files to $CLIENT_REPO"
cp $1/client-outgoing-secpolicy.xml $CLIENT_REPO/outgoing-secpolicy.xml
cp $1/client-incoming-secpolicy.xml $CLIENT_REPO/incoming-secpolicy.xml

echo "replacing username in policy files."
sed -i 's/AXIS2_USER/'$USER'/g' $CLIENT_REPO/outgoing-secpolicy.xml
sed -i 's/AXIS2_USER/'$USER'/g' $CLIENT_REPO/incoming-secpolicy.xml


#copy service policy files to SERVICE_HOME
echo "Copying service policy files to $SERVICE_HOME"
cp $1/service-outgoing-secpolicy.xml $SERVICE_HOME/outgoing-secpolicy.xml
cp $1/service-incoming-secpolicy.xml $SERVICE_HOME/incoming-secpolicy.xml

echo "replacing username in policy files."
sed -i 's/AXIS2_USER/'$USER'/g' $SERVICE_HOME/outgoing-secpolicy.xml
sed -i 's/AXIS2_USER/'$USER'/g' $SERVICE_HOME/incoming-secpolicy.xml

