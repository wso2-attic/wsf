#ifndef SIMPLEEXCHANGE_H
#define SIMPLEEXCHANGE_H

#include <ClientInfo.h>
#include <ClientData.h>

using namespace org_wso2_www_types;

namespace org_wso2_www
{
	class SimpleExchange
	{

	private:
		std::map<std::string, org_wso2_www::ClientData> registeredClients;

		int totalTradedStocks;

		void createClientData();

	public:
		/** Constructor */
		SimpleExchange(void);
		/** Destructor */
		~SimpleExchange(void);

		/**
		*  Registers a client with the stock market and returns the name 
		*  Of the registered client.
		*/
		std::string registerClient(ClientInfo *clientInfo);

		/**
		* Buys stocks of a given quantity.                                                   
		*/
		int buy(int quantity);
		/**
		* Sells stocks of a given quantity                                                   
		*/
		int sell(int quantity);

	};
}

#endif