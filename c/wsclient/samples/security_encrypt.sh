#!/bin/bash
if test -z $WSFC_HOME; then 
    WSFC_HOME=$PWD/../../..
fi
$WSFC_HOME/bin/wsclient --soap --no-mtom --timestamp --sign-body --key $WSFC_HOME/bin/samples/rampart/keys/ahome/alice_key.pem --certificate $WSFC_HOME/bin/samples/rampart/keys/ahome/alice_cert.cert --recipient-certificate $WSFC_HOME/bin/samples/rampart/keys/ahome/bob_cert.cert --encrypt-payload http://localhost:9090/axis2/services/sec_echo <$WSFC_HOME/bin/samples/wsclient/data/echo.xml
