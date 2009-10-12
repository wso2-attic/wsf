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
		cout<<"Please Set WSFCPP_HOME environment variable"<<endl;
	/**
	*  Create a new calculator stub and invokes the methods                                                   
	*/	
	CalculatorStub *stub = NULL;
	stub = new CalculatorStub(clientHome, endpointUri);
	int addResult = stub->add(10,10);
	cout<<"Calculation 10 + 10, result is " <<addResult<<endl;
	
	int subResult = stub->sub(20,10);
	cout<<"Calculation 20 - 10, is "<<subResult<<endl;
	
	int divResult = stub->div(100,10);
	cout<<"Calculation 100/10, is "<<divResult<<endl;

	int mulResult = stub->mul(15,15);
	cout<<"Calculation 15*15, is "<<mulResult<<endl;
	
	delete stub;	
}


