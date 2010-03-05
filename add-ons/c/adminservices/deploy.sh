#!/bin/bash
set -e

if [ $# -ne 2 ]
then
    echo "Usage : $0 scenarioX"
    exit
fi
if [ ! -d $1 ];then
echo "Home directory $1 does not exist"
exit
fi

if [ ! -e $2 ];then
echo "Policy Configuration file $2 does not exist"
exit
fi

echo "Replacing settings in policy files."
if [ `uname -s` = Darwin ];then
   echo  sed -e 's,AXIS2C_HOME,'$INST_DIR',g' -e 's,\.so,\.dylib,g' $2 > /tmp/policy.xml
   cp -f /tmp/policy.xml $2
else
    sed 's,AXIS2C_HOME,'$1',g' $2 > /tmp/policy.xml
    cp -f /tmp/policy.xml $2
fi
