#!/bin/bash
if [ -w /etc/opt ]
then
	if [ ! -d /etc/opt/wso2/wsfc/services ]
	then
		mkdir /etc/opt/wso2/wsfc/services
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/echo ]
	then
		mkdir /etc/opt/wso2/wsfc/services/echo
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/echo/services.xml ]
	then
		ln -s $1/services/echo/services.xml /etc/opt/wso2/wsfc/services/echo/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/math ]
	then
		mkdir /etc/opt/wso2/wsfc/services/math
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/math/services.xml ]
	then
		ln -s $1/services/math/services.xml /etc/opt/wso2/wsfc/services/math/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/mtom ]
	then
		mkdir /etc/opt/wso2/wsfc/services/mtom
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/mtom/services.xml ]
	then
		ln -s $1/services/mtom/services.xml /etc/opt/wso2/wsfc/services/mtom/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/sg_math ]
	then
		mkdir /etc/opt/wso2/wsfc/services/sg_math
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/sg_math/services.xml ]
	then
		ln -s $1/services/sg_math/services.xml /etc/opt/wso2/wsfc/services/sg_math/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/Calculator ]
	then
		mkdir /etc/opt/wso2/wsfc/services/Calculator
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/Calculator/services.xml ]
	then
		ln -s $1/services/Calculator/services.xml /etc/opt/wso2/wsfc/services/Calculator/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/exchangeclient ]
	then
		mkdir /etc/opt/wso2/wsfc/services/exchangeclient
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/exchangeclient/services.xml ]
	then
		ln -s $1/services/exchangeclient/services.xml /etc/opt/wso2/wsfc/services/exchangeclient/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/exchangetrader ]
	then
		mkdir /etc/opt/wso2/wsfc/services/exchangetrader
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/exchangetrader/services.xml ]
	then
		ln -s $1/services/exchangetrader/services.xml /etc/opt/wso2/wsfc/services/exchangetrader/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/listener ]
	then
		mkdir /etc/opt/wso2/wsfc/services/listener
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/listener/services.xml ]
	then
		ln -s $1/services/listener/services.xml /etc/opt/wso2/wsfc/services/listener/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/notify ]
	then
		mkdir /etc/opt/wso2/wsfc/services/notify
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/notify/services.xml ]
	then
		ln -s $1/services/notify/services.xml /etc/opt/wso2/wsfc/services/notify/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/publisher ]
	then
		mkdir /etc/opt/wso2/wsfc/services/publisher
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/publisher/services.xml ]
	then
		ln -s $1/services/publisher/services.xml /etc/opt/wso2/wsfc/services/publisher/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/RMSampleService ]
	then
		mkdir /etc/opt/wso2/wsfc/services/RMSampleService
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/RMSampleService/services.xml ]
	then
		ln -s $1/services/RMSampleService/services.xml /etc/opt/wso2/wsfc/services/RMSampleService/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/sec_echo ]
	then
		mkdir /etc/opt/wso2/wsfc/services/sec_echo
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/sec_echo/services.xml ]
	then
		ln -s $1/services/sec_echo/services.xml /etc/opt/wso2/wsfc/services/sec_echo/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/subscription ]
	then
		mkdir /etc/opt/wso2/wsfc/services/subscription
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/subscription/services.xml ]
	then
		ln -s $1/services/subscription/services.xml /etc/opt/wso2/wsfc/services/subscription/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/traderclient ]
	then
		mkdir /etc/opt/wso2/wsfc/services/traderclient
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/traderclient/services.xml ]
	then
		ln -s $1/services/traderclient/services.xml /etc/opt/wso2/wsfc/services/traderclient/services.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/services/traderexchange ]
	then
		mkdir /etc/opt/wso2/wsfc/services/traderexchange
	fi

	if [ ! -f /etc/opt/wso2/wsfc/services/traderexchange/services.xml ]
	then
		ln -s $1/services/traderexchange/services.xml /etc/opt/wso2/wsfc/services/traderexchange/services.xml
	fi


	if [ ! -d /etc/opt/wso2/wsfc/modules ]
	then
		mkdir /etc/opt/wso2/wsfc/modules
	fi

	if [ ! -d /etc/opt/wso2/wsfc/modules/addressing ]
	then
		mkdir /etc/opt/wso2/wsfc/modules/addressing
	fi

	if [ ! -f /etc/opt/wso2/wsfc/modules/addressing/module.xml ]
	then
		ln -s $1/modules/addressing/module.xml /etc/opt/wso2/wsfc/modules/addressing/module.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/modules/logging ]
	then
		mkdir /etc/opt/wso2/wsfc/modules/logging
	fi

	if [ ! -f /etc/opt/wso2/wsfc/modules/logging/module.xml ]
	then
		ln -s $1/modules/logging/module.xml /etc/opt/wso2/wsfc/modules/logging/module.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/modules/rampart ]
	then
		mkdir /etc/opt/wso2/wsfc/modules/rampart
	fi

	if [ ! -f /etc/opt/wso2/wsfc/modules/rampart/module.xml ]
	then
		ln -s $1/modules/rampart/module.xml /etc/opt/wso2/wsfc/modules/rampart/module.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/modules/sandesha2 ]
	then
		mkdir /etc/opt/wso2/wsfc/modules/sandesha2
	fi

	if [ ! -f /etc/opt/wso2/wsfc/modules/sandesha2/module.xml ]
	then
		ln -s $1/modules/sandesha2/module.xml /etc/opt/wso2/wsfc/modules/sandesha2/module.xml
	fi

	if [ ! -d /etc/opt/wso2/wsfc/modules/savan ]
	then
		mkdir /etc/opt/wso2/wsfc/modules/savan
	fi

	if [ ! -f /etc/opt/wso2/wsfc/modules/savan/module.xml ]
	then
		ln -s $1/modules/savan/module.xml /etc/opt/wso2/wsfc/modules/savan/module.xml
	fi
else
	exit 0
fi







