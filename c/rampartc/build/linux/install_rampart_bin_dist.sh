#!/bin/bash
#This script should be placed in rampart/c home directory
PWDIR=$PWD
echo "Copy rampart module"
#Copy rampart module
cp  -r $PWD/modules/rampart $AXIS2C_HOME/modules/

echo "Copy sec_echo sample"
#Copy sec_echo sample
cp -r $PWD/samples/server/sec_echo $AXIS2C_HOME/services/

echo "Please go to directory $PWD/samples/secpolicy"
echo "Deploy and run a scenario using"
echo "\t%sh test_scen.sh scenarioX server-port"
