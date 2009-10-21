#!/bin/bash
if test -z $WSFC_HOME; then 
    WSFC_HOME=$PWD/../../..
fi
$WSFC_HOME/bin/wsclient --soap --xop-in $WSFC_HOME/samples/bin/resources/axis2.jpg --xop-out $WSFC_HOME/samples/bin/wsclient/ --log-level debug  http://localhost:9090/axis2/services/mtom <$WSFC_HOME/samples/bin/wsclient/data/mtom_test.xml
