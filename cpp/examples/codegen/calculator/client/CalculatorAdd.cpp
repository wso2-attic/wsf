#include "CalculatorStub.h"
#include <Environment.h>

using namespace wso2wsf;
using namespace localhost_axis_calculator;
using namespace std;

int 
main(
    int argc,
    char *argv) 
{
	Environment::initialize("calculator.log", AXIS2_LOG_LEVEL_TRACE);
	string endpointUri;
	string clientHome;
	AddResponse* addRes = NULL;
	Add *addIn = NULL;
	CalculatorStub *stub = NULL;

	endpointUri = "http://localhost:9090/axis2/services/Calculator";
	clientHome = AXIS2_GETENV("WSFCPP_HOME");

	stub = new CalculatorStub(clientHome, endpointUri);

	addIn = new Add();
	addIn->setArg_0_0(10);
	addIn->setArg_1_0(10);
	addRes = stub->add(addIn);
	if(addRes)
	{
		cout<<addRes->getAddReturn()<<endl;
	}

	delete stub;	
}


