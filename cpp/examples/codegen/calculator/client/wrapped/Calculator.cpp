/*
* Copyright 2005-2009 WSO2, Inc. http://wso2.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "CalculatorStub.h"
#include <Environment.h>

using namespace wso2wsf;
using namespace localhost_axis_calculator;
using namespace std;

int 
main(
    int argc,
    char *argv[]) 
{
	Environment::initialize("calculator.log", AXIS2_LOG_LEVEL_TRACE);
	string endpointUri = "http://localhost:9090/axis2/services/Calculator";
	string clientHome = AXIS2_GETENV("WSFCPP_HOME");
	if(clientHome.empty())
	{
		cout<<"Please set the WSFCPP_HOME environment variable"<<endl;
	}
	CalculatorStub *stub = new CalculatorStub(clientHome, endpointUri);
	Add *addIn = new Add();
	addIn->setA(10);
	addIn->setB(10);
	AddResponse *addResponse  = stub->add(addIn);
	if(addResponse)
	{
		cout<<"Calculation, 10 + 10 result is "<<addResponse->getAddReturn()<<endl;
	}

	Sub *subIn = new Sub();
	subIn->setA(20);
	subIn->setB(10);
	SubResponse *subResponse = stub->sub(subIn);
	if(subResponse)
	{
		cout<<"Calculation, 20 - 10 result is "<<subResponse->getSubReturn()<<endl;
	}

	Mul *mulIn =  new Mul();
	mulIn->setA(15);
	mulIn->setB(15);
	MulResponse *mulResponse = stub->mul(mulIn);
	if(mulResponse)
	{
		cout<<"Calculation, 15 * 15 result is "<<mulResponse->getMulReturn() <<endl;
	}

	Div *divIn = new Div();
	divIn->setA(100);
	divIn->setB(10);
	DivResponse *divResponse = stub->div(divIn);
	if(divResponse)
	{
		cout<<"Calculation, 100/10 result is "<<divResponse->getDivReturn()<<endl;
	}
	delete stub;
}


