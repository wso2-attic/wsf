#!/bin/bash
if [ -w /etc/opt ]
then
	if [ ! -d /etc/opt/wso2 ]
	then
		mkdir /etc/opt/wso2
	fi

	if [ ! -d /etc/opt/wso2/wsf_c ]
	then
		mkdir /etc/opt/wso2/wsf_c
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/axis2.xml ]
	then
		ln -s $1/axis2.xml /etc/opt/wso2/wsf_c/axis2.xml
	fi
else
	exit 0
fi




