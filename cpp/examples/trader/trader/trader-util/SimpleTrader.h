#ifndef SIMPLETRADER_H
#define SIMPLETRADER_H

#include <ClientData.h>
#include <ExchangeTraderStub.h>
#include <StockQuote.h>

namespace org_wso2_www
{
	class SimpleTrader
	{
	private:
		std::map<std::string,org_wso2_www::ClientData*> clientInformation;

		std::map<std::string, org_wso2_www_types::StockQuote*> stockMarket;

		std::string exchangeEpr;

		std::string myEpr;

		std::string clientHome;

		void createStockMarket();

		void createClientData();

	public:
		std::string createAccount(std::string ssn, std::string name, std::string password);

		ClientData* getClientData(std::string username, std::string password);

		bool buy(std::string username, std::string password, std::string symbol, int qty);

		bool sell(std::string username, std::string password, std::string symbol, int qty);

		SimpleTrader(void);
		~SimpleTrader(void);
	};
}


#endif /* SIMPLETRADER_H */
