#!/bin/bash
if test -z $WSFC_HOME; then 
    WSFC_HOME=$PWD/../../..
fi
$WSFC_HOME/bin/wsclient --soap --no-mtom --no-wsa --soap-header '<dam:Pick xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope" soapenv:mustUnderstand="0" xmlns:dam="http://www.w3.org/2004/09/fly">http://ws.apache.org/axis2/c</dam:Pick>' http://localhost:9090/axis2/services/echo <$WSFC_HOME/samples/bin/wsclient/data/echo.xml
