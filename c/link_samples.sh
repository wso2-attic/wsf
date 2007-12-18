#!/bin/bash
mkdir -p /etc/opt/wso2/wsf_c/services
mkdir -p /etc/opt/wso2/wsf_c/modules
ln -f -s $1/services /etc/opt/wso2/wsf_c/services
ln -f -s $1/modules /etc/opt/wso2/wsf_c/modules







