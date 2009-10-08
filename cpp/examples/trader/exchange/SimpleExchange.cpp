#include "SimpleExchange.h"

using namespace org_wso2_www;

void SimpleExchange::createClientData()
{
	char ssn[][5] = {("11"),("22"),("33"),("44")};
	char name[][10] = {("damitha"),("nandika"),("shankar"),("sanjaya")};

	for(int i = 0; i < 4; i++)
	{
		ClientData clientData(ssn[i], name[i], name[i]);
		registeredClients[name[i]] = clientData;
	}
}


SimpleExchange::SimpleExchange(void)
{
	createClientData();
}

SimpleExchange::~SimpleExchange(void)
{
	

}

int SimpleExchange::buy(int quantity)
{
	totalTradedStocks = totalTradedStocks + quantity;
	return totalTradedStocks;
}

int SimpleExchange::sell(int quantity)
{
	totalTradedStocks -= quantity;
	return totalTradedStocks;
}

std::string org_wso2_www::SimpleExchange::registerClient( ClientInfo *clientInfo )
{
	if(!clientInfo)
	{
		std::cout<<"Client Info NULL"<<std::endl;
		return "";
	}
	std::string ssn = clientInfo->getSsn();
	std::string name = clientInfo->getName();
	
	ClientData clientData(ssn, name, name);
	clientData.setCredit(200);
	registeredClients[name] = clientData;
	return name;
}
