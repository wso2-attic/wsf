#!/bin/bash
if [ -w /etc/opt ]
then
	if [ ! -d /etc/opt/wso2/wsf_c/services ]
	then
		mkdir /etc/opt/wso2/wsf_c/services
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/echo ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/echo
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/echo/services.xml ]
	then
		ln -s $1/services/echo/services.xml /etc/opt/wso2/wsf_c/services/echo/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/math ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/math
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/math/services.xml ]
	then
		ln -s $1/services/math/services.xml /etc/opt/wso2/wsf_c/services/math/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/mtom ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/mtom
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/mtom/services.xml ]
	then
		ln -s $1/services/mtom/services.xml /etc/opt/wso2/wsf_c/services/mtom/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/sg_math ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/sg_math
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/sg_math/services.xml ]
	then
		ln -s $1/services/sg_math/services.xml /etc/opt/wso2/wsf_c/services/sg_math/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/Calculator ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/Calculator
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/Calculator/services.xml ]
	then
		ln -s $1/services/Calculator/services.xml /etc/opt/wso2/wsf_c/services/Calculator/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/exchangeclient ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/exchangeclient
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/exchangeclient/services.xml ]
	then
		ln -s $1/services/exchangeclient/services.xml /etc/opt/wso2/wsf_c/services/exchangeclient/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/exchangetrader ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/exchangetrader
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/exchangetrader/services.xml ]
	then
		ln -s $1/services/exchangetrader/services.xml /etc/opt/wso2/wsf_c/services/exchangetrader/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/listener ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/listener
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/listener/services.xml ]
	then
		ln -s $1/services/listener/services.xml /etc/opt/wso2/wsf_c/services/listener/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/notify ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/notify
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/notify/services.xml ]
	then
		ln -s $1/services/notify/services.xml /etc/opt/wso2/wsf_c/services/notify/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/publisher ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/publisher
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/publisher/services.xml ]
	then
		ln -s $1/services/publisher/services.xml /etc/opt/wso2/wsf_c/services/publisher/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/RMSampleService ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/RMSampleService
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/RMSampleService/services.xml ]
	then
		ln -s $1/services/RMSampleService/services.xml /etc/opt/wso2/wsf_c/services/RMSampleService/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/sec_echo ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/sec_echo
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/sec_echo/services.xml ]
	then
		ln -s $1/services/sec_echo/services.xml /etc/opt/wso2/wsf_c/services/sec_echo/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/subscription ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/subscription
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/subscription/services.xml ]
	then
		ln -s $1/services/subscription/services.xml /etc/opt/wso2/wsf_c/services/subscription/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/traderclient ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/traderclient
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/traderclient/services.xml ]
	then
		ln -s $1/services/traderclient/services.xml /etc/opt/wso2/wsf_c/services/traderclient/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/services/traderexchange ]
	then
		mkdir /etc/opt/wso2/wsf_c/services/traderexchange
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/services/traderexchange/services.xml ]
	then
		ln -s $1/services/traderexchange/services.xml /etc/opt/wso2/wsf_c/services/traderexchange/services.xml
	fi


	if [ ! -d /etc/opt/wso2/wsf_c/modules ]
	then
		mkdir /etc/opt/wso2/wsf_c/modules
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/modules/addressing ]
	then
		mkdir /etc/opt/wso2/wsf_c/modules/addressing
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/modules/addressing/module.xml ]
	then
		ln -s $1/modules/addressing/module.xml /etc/opt/wso2/wsf_c/modules/addressing/module.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/modules/logging ]
	then
		mkdir /etc/opt/wso2/wsf_c/modules/logging
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/modules/logging/module.xml ]
	then
		ln -s $1/modules/logging/module.xml /etc/opt/wso2/wsf_c/modules/logging/module.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/modules/rampart ]
	then
		mkdir /etc/opt/wso2/wsf_c/modules/rampart
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/modules/rampart/module.xml ]
	then
		ln -s $1/modules/rampart/module.xml /etc/opt/wso2/wsf_c/modules/rampart/module.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/modules/sandesha2 ]
	then
		mkdir /etc/opt/wso2/wsf_c/modules/sandesha2
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/modules/sandesha2/module.xml ]
	then
		ln -s $1/modules/sandesha2/module.xml /etc/opt/wso2/wsf_c/modules/sandesha2/module.xml
	fi

	if [ ! -d /etc/opt/wso2/wsf_c/modules/savan ]
	then
		mkdir /etc/opt/wso2/wsf_c/modules/savan
	fi

	if [ ! -f /etc/opt/wso2/wsf_c/modules/savan/module.xml ]
	then
		ln -s $1/modules/savan/module.xml /etc/opt/wso2/wsf_c/modules/savan/module.xml
	fi
else
	exit 0
fi







