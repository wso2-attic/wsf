#!/bin/bash
if [ -w /etc/opt ]
then
	if [ ! -d /etc/opt/wso2/wsf_c/services ]
	then
		mkdir /etc/opt/wso2/wsf_c/services
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/ ]
	then
		ln -s $1/services /etc/opt/wso2/wsf_c/services
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/modules ]
	then
		ln -s $1/modules /etc/opt/wso2/wsf_c/modules
	fi
else
	exit 0
fi







