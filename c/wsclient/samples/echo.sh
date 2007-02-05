#!/bin/bash
export WSFC_HOME=$PWD/../..
../wsclient --soap --no-mtom --no-wsa http://localhost:9090/axis2/services/echo <../samples/data/echo.xml
