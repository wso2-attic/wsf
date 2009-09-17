#include <stdio.h>
#include <iostream>
#include <Environment.h>
#include <SimpleStockQuoteServiceStub.h>
#include <GetQuote.h>
#include <GetQuoteE4.h>
#include <GetQuoteResponse.h>

using namespace std;
using namespace wso2wsf;
using namespace samples_services;
using namespace samples_services_xsd;

void getQuote(SimpleStockQuoteServiceStub *stub, std::string symbol)
{
	double last = 0;
	SimpleStockQuoteService_getQuote_fault fault;
	GetQuoteE4 *getQuoteE4 = new GetQuoteE4();
	GetQuote *quote = new GetQuote();
	quote->setSymbol(symbol);
	getQuoteE4->setRequest(quote);

	GetQuoteResponseE1 *getQuoteResponseE1 = stub->getQuote(getQuoteE4, &fault);
	if(getQuoteResponseE1)
	{	
		GetQuoteResponse *response = getQuoteResponseE1->get_return();
		last = response->getLast();
		cout<< "Standard::stock prince "<<last<<endl;
	}
}
int main(int argc, char *argv[])
{
	std::string endpointUri = "http://localhost:9090/services/SimpleStockQuoteService";
	if(argc > 1)
	{
		endpointUri = argv[1];
	}
	Environment::initialize("stockquote.log",AXIS2_LOG_LEVEL_DEBUG);
	std::string clientHome = AXIS2_GETENV("WSFCPP_HOME");
	SimpleStockQuoteServiceStub *stub = new SimpleStockQuoteServiceStub(clientHome,endpointUri);
	ServiceClient *client = stub->getServiceClient();
	client->engageModule(AXIS2_MODULE_ADDRESSING);
	Options *options = client->getOptions();
	options->setAction("urn:getQuote");
	options->setSoapVersion(AXIOM_SOAP12);
	getQuote(stub, "WSO2");
}



