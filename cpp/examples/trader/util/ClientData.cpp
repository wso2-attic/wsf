#include "ClientData.h"

using namespace org_wso2_www;

ClientData::ClientData(std::string ssn, std::string name, std::string password)
{
	_ssn = ssn;
	_name = name;
	_password = password;
	creditAmount = 0;
}

ClientData::~ClientData(void)
{
}

std::string org_wso2_www::ClientData::getSSN()
{
	return _ssn;
}

std::string org_wso2_www::ClientData::getPassword()
{
	return _password;
}

std::string org_wso2_www::ClientData::getName()
{
	return _name;
}



double org_wso2_www::ClientData::getCredit()
{
	return creditAmount;
}

void org_wso2_www::ClientData::setCredit( double credit )
{
	creditAmount = credit;
}



void org_wso2_www::ClientData::setName( std::string name )
{
	_name = name;
}

void org_wso2_www::ClientData::setPassword( std::string password )
{
	_password = password;
}

void org_wso2_www::ClientData::setSSN( std::string ssn )
{
	_ssn = ssn;
}

void org_wso2_www::ClientData::setStock( std::string symbol,int newvalue)
{
	if(stockHoldings[symbol])
	{
	 stockHoldings[symbol] = newvalue;
	}
	return;
}
int org_wso2_www::ClientData::getStock( std::string symbol )
{
	if(stockHoldings[symbol])
		return stockHoldings[symbol];
	return -1;
}