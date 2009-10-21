#!/bin/bash
if test -z $WSFC_HOME; then 
    WSFC_HOME=$PWD/../../..
fi
$WSFC_HOME/bin/wsclient --soap --send-only --no-mtom --no-wsa http://localhost:9090/axis2/services/notify <$WSFC_HOME/samples/bin/wsclient/data/notify.xml
