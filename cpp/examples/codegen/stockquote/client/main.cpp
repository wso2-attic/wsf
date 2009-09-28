#include <stdio.h>
#include <iostream>
#include <Environment.h>

#include "SimpleStockQuoteServiceStub.h"
#include <GetQuote.h>
#include <GetQuoteE7.h>
#include <GetQuoteResponse.h>
#include <axis2_options.h>

using namespace std;
using namespace wso2wsf;
using namespace samples_services;

void getQuote(SimpleStockQuoteServiceStub *stub, std::string symbol)
{
	double last = 0;
	SimpleStockQuoteService_getQuote_fault fault;
	GetQuoteE7 *getQuoteE7 = new GetQuoteE7();
	GetQuote *quote = new GetQuote();
	quote->setSymbol(symbol);
	getQuoteE7->setRequest(quote);

	GetQuoteResponseE2 *getQuoteResponseE2= stub->getQuote(getQuoteE7, &fault);
	if(getQuoteResponseE2)
	{	
		GetQuoteResponse *response = getQuoteResponseE2->get_return();
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
	axis2_options_t *axis2options = options->getAxis2Options();
	axis2_options_set_action(axis2options, Environment::getEnv(), "urn:getQuote");
	options->setSoapVersion(AXIOM_SOAP12);
	getQuote(stub, "WSO2");
	
}



