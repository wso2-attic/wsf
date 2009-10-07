#include <stdio.h>
#include <OMElement.h>
#include <Stub.h>
#include <DepositRequest.h>

#include <DepositResponse.h>

#include <GetSymbolsRequest.h>

#include <GetSymbolsResponse.h>

#include <GetQuoteRequest.h>

#include <GetQuoteResponse.h>

#include <CreateAccountRequest.h>

#include <CreateAccountResponse.h>

#include <SellRequest.h>

#include <SellResponse.h>

#include <BuyRequest.h>

#include <BuyResponse.h>

#include <GetPortfolioRequest.h>

#include <GetPortfolioResponse.h>

#include <TraderClientStub.h>

using namespace std;
using namespace org_wso2_www;
using namespace org_wso2_www_types;

bool createAccount(std::string user, 
				   std::string password,
				   std::string epr,
				   std::string clientHome)
{

	ClientInfo *clientinfo = new ClientInfo();
	clientinfo->setName(user);
	clientinfo->setSsn("1111");
	CreateAccountRequest *request = new CreateAccountRequest();
	request->setClientinfo(clientinfo);
	request->setPassword(password);

	TraderClientStub *stub = new TraderClientStub(clientHome,epr);
	
	if(stub)
	{
		CreateAccountResponse *response = stub->createAccount(request);
		if(response)
		std::cout<<"RESULTS , Your user id is "<<response->getUserid()<<std::endl;

		delete stub;
		return true;
	}
	return false;
}


bool buy(std::string user, 
		 std::string password,
		 std::string symbol,
		 std::string qty,
		 std::string epr,
		 std::string clientHome)
{
	BuyRequest *request = new BuyRequest();
	request->setUserid(user);
	request->setPassword(password);
	request->setSymbol(symbol);
	request->setQty(atoi(qty.c_str()));
	TraderClientStub *stub = new TraderClientStub(clientHome, epr);
	bool status = false;
	BuyResponse *response = stub->buy(request);
	if(response)
	{
		TradeStatus *sts = response->getTrade_status();
		if(sts)
		{
			std::cout<<"RESULTS: " << sts->getReason()<<std::endl;
			status = sts->getStatus();
		}
	}

	delete stub;
	return status;
}

bool sell(std::string user,
		  std::string password,
		  std::string symbol,
		  std::string qty,
		  std::string epr,
		  std::string clientHome)
{

	SellRequest *request = new SellRequest();
	request->setUserid(user);
	request->setPassword(password);
	request->setSymbol(symbol);
	request->setQty(atoi(qty.c_str()));

	TraderClientStub *stub = new TraderClientStub(clientHome, epr);
	SellResponse *response = stub->sell(request);
	bool status = false;
	if(response)
	{
		TradeStatus *sts = response->getTrade_status();
		if(sts)
		{
			std::cout<<"RESULTS: "<<sts->getReason()<<std::endl;
			status = sts->getStatus();
		}
	}

	delete stub;
	return status;
}

int main(int argc, char *argv[])
{
	
	bool status = false;
	wso2wsf::Environment::initialize("traderclient.log",AXIS2_LOG_LEVEL_TRACE);
	std::string clientHome = AXIS2_GETENV("WSFCPP_HOME");
	std::string operation ="";
	if(clientHome.empty())
	{
		std::cout<<"Please check the WSFCPP_HOME environment variable"<<std::endl;
		return 0;
	}

	std::string address = "http://localhost:9090/axis2/services/TraderClient";
	if (argc > 1)
	{
		operation = argv[1];
	}
	else
	{
		std::cout<<"Type ./trader -h for usage\n"<<std::endl;
		return 0;
	}    

	if(operation.compare("-h") ==  0)
	{
		printf("Usage : %s [create-account] [username] [password] [endpoint_url]\n", argv[0]);
		printf("Usage : %s [buy] [username] [password] [symbol] [quantity] [endpoint_url]\n", argv[0]);
		printf("Usage : %s [sell] [username] [password] [symbol] [quantity] [endpoint_url]\n", argv[0]);
		printf("use -h for help\n");
		printf("NOTE: command line arguments must appear in given order, with trailing ones being optional\n");
		return 0;
	}

	std::cout<<"Using Endpoint "<<address<<std::endl;

	if(operation.compare("create-account") == 0)
	{
		if(argc < 4)
		{
			printf("Some arguments are missing\n .use -h for help\n");   
			return 0;
		}  
		else if(argc > 4)
		{    
			address = argv[4]; 
		}
		status = createAccount(argv[2], argv[3], address, clientHome);
	}
	else if(operation.compare("buy") == 0)
	{
		if(argc < 6)
		{
			printf("Some arguments are missing\n .use -h for help\n");
			return 0;
		}
		else if(argc > 6)
		{    
			address = argv[6];    
		}    
		status = buy(argv[2], argv[3], argv[4], argv[5], address, clientHome);
	}    
	else if(axutil_strcmp(operation.c_str(), "sell") == 0)
	{
		if(argc < 6)
		{
			printf("Some arguments are missing\n .use -h for help\n");
			return 0;
		}
		else if(argc > 6)
		{
			address = argv[6];
		}    
		status = sell(argv[2], argv[3], argv[4], argv[5], address, clientHome);
	}    

	else
	{
		printf("Unknown operation \n");
	}

	if(!status)
	{
		printf("Trader-Client invoke failed\n");
	}
	else
	{
		printf("Trader-Client invoke Successful\n");
	}
}