#!/bin/bash
export WSFC_HOME=$PWD/../..
../wsclient http://localhost:9090/axis2/services/echo < ../samples/data/echo.xml

