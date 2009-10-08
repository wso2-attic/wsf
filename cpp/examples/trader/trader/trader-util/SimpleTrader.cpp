#include "SimpleTrader.h"
#include <StockQuote.h>
#include <BuyRequest.h>
#include <BuyRequest_ex.h>
#include <SellRequest_ex.h>
#include <Options.h>
#include <string>

using namespace org_wso2_www;
using namespace org_wso2_www_types;

SimpleTrader::SimpleTrader(void)
{
	createStockMarket();
	createClientData();

	exchangeEpr = "http://localhost:9090/axis2/services/ExchangeTrader";
	myEpr = "http://localhost:9090/axis2/services/TraderClient";
	clientHome = AXIS2_GETENV("WSFCPP_HOME");
	if(clientHome.empty())
	{
		std::cout<<"WSFCPP_HOME Not set. Unable to continue";
	}
}

SimpleTrader::~SimpleTrader(void)
{
}

void org_wso2_www::SimpleTrader::createStockMarket()
{
	char symbol[][10] = {{"ibm"},{"wso2"},{"msft"},{"sun"}};
	char symbolName[][10] = {{"IBM"},{"WSO2"},{"MICROSOFT"},{"SUN"}};
	for(int i = 0; i < 4; i++)
	{
		StockQuote *stockquote = new  StockQuote();
		stockquote->setName(symbolName[i]);
		stockquote->setSymbol(symbol[i]);
		stockquote->setPrice(i*100);
		stockMarket[symbol[i]] = stockquote;
	}
}

std::string org_wso2_www::SimpleTrader::createAccount( std::string ssn, std::string name, std::string password )
{
	ExchangeTraderStub *stub = NULL;
	

	ClientData	*clientData = new ClientData(ssn, name, password);

	clientInformation[name] = clientData;
	stub = new ExchangeTraderStub(clientHome, exchangeEpr);
	stub->engageModule(AXIS2_MODULE_ADDRESSING);
	wso2wsf::Options *op = stub->getOptions();
	op->setAction("registerClient");
	if(stub)
	{
		RegisterClientRequest *clientRequest = new RegisterClientRequest();
		ClientInfo *clientInfo = new ClientInfo();
		clientInfo->setName(name);
		clientInfo->setSsn(ssn);
		clientRequest->setClientInfo(clientInfo);
		RegisterClientResponse *clientResponse = stub->registerClient(clientRequest);
		if(clientResponse)
		{
			return clientResponse->getUserid();
		}
	}
	std::cout<<"Operation Failed "<<std::endl;
	return "";
}

ClientData* org_wso2_www::SimpleTrader::getClientData( std::string username, std::string password )
{

	if(username == "" && password =="")
	{
		return NULL;
	}

	if(clientInformation[username])
	{
		ClientData *clientdata = clientInformation[username];
		std::string pass = clientdata->getPassword();
		if(pass.compare(password) == 0)
		{
			return clientdata;
		}
	}
	return NULL;
}

bool org_wso2_www::SimpleTrader::buy( std::string username, std::string password, std::string symbol, int qty )
{

	ClientData *clientdata = getClientData(username, password);
	if(!clientdata)
	{
		std::cout<<"Client Information Does Not exist"<<std::endl;
		return false;
	}
	StockQuote *quote = stockMarket[symbol];
	
	if(!quote)
	{    
		std::cout<<"Stock Details Unavailable"<<std::endl;
		return false;
	}

	double credit = clientdata->getCredit();

	double amountRequired = (quote->getPrice())*qty;

	if(credit < amountRequired)
	{
		std::cout<<"Not enough credit for the complete transaction"<<std::endl;
		return false;
	}
	clientdata->setCredit(credit - amountRequired);

	int stockvlaue = 0;
	stockvlaue = clientdata->getStock(symbol);

	if(stockvlaue != -1)
	{
		int newvalue = stockvlaue + qty;
		clientdata->setStock(symbol, newvalue);
	}
	
	ExchangeTraderStub *stub = new ExchangeTraderStub(clientHome, exchangeEpr);
	stub->engageModule(AXIS2_MODULE_ADDRESSING);
	wso2wsf::Options *op = stub->getOptions();
	op->setAction("buy");
	org_wso2_www_types::BuyRequest_ex *buyrequest = new org_wso2_www_types::BuyRequest_ex();
	buyrequest->setUserid(username);
	buyrequest->setSymbol(symbol);
	buyrequest->setQty(qty);
	
	bool status = stub->buy(buyrequest);

	delete stub;
	return status;
}

bool org_wso2_www::SimpleTrader::sell( std::string username, std::string password, std::string symbol, int qty )
{
	ClientData *clientdata = getClientData(username, password);
	if(clientdata)
	{
		std::cout<<"Client Information Does Not exist"<<std::endl;
		return false;
	}
	StockQuote *quote = stockMarket[symbol];

	if(!quote)
	{    
		std::cout<<"Stock Details Unavailable"<<std::endl;
		return false;
	}

	
	int stockvlaue = 0;
	stockvlaue = clientdata->getStock(symbol);

	if(stockvlaue < qty)
	{
		std::cout<<"cannot sell more stocks that you own"<<std::endl;
	}

	clientdata->setStock(symbol, stockvlaue - qty);


	ExchangeTraderStub *stub = new ExchangeTraderStub(clientHome, exchangeEpr);
	stub->engageModule(AXIS2_MODULE_ADDRESSING);
	wso2wsf::Options *op = stub->getOptions();
	op->setAction("sell");
	org_wso2_www_types::SellRequest_ex *sellrequest = new org_wso2_www_types::SellRequest_ex();
	sellrequest->setUserid(username);
	sellrequest->setSymbol(symbol);
	sellrequest->setQty(qty);
	bool status = stub->sell(sellrequest);
	delete stub;
	return status;
}

void org_wso2_www::SimpleTrader::createClientData()
{
	char ssn[][4] = {("11"),("22"),("33"),("44")};
	char name[][10] = {("damitha"),("nandika"),("shankar"),("sanjaya")};

	for(int i = 0; i < 4; i++)
	{
		ClientData *clientData = new ClientData(ssn[i], name[i], name[i]);
		clientData->setCredit(i*200);
		clientInformation[name[i]] = clientData;
	}
}
