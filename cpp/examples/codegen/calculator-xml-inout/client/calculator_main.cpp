
/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "CalculatorStub.h"
#include <iostream>
#include <typeinfo>
#include <Environment.h>
#include <OMElement.h>

using namespace std;
using namespace wso2wsf;
using namespace localhost_axis_calculator;

OMElement* CreateRequestXML()
{
	OMNamespace *ns1 = new OMNamespace("http://localhost/axis2/Calculator", "ns1");
	OMElement *operationElem = new OMElement("add",ns1);
	OMElement *value1 = new OMElement("a");
	value1->setText("10");
	operationElem->addChild(value1);
	OMElement *value2 = new OMElement("b");
	value2->setText("20");
	operationElem->addChild(value2);
	return operationElem;

}

void handleResponse(OMElement *response)
{
	if(!response)
	{
		std::cout<<"Empty Response"<<std::endl;
	}
	try{
		OMElement *childEle =  dynamic_cast<OMElement*>(response->getFirstChild());
		if(childEle)
		{
			std::cout<<childEle->getText()<<endl;
		}
	}catch(bad_cast){
		std::cout<<"Bad Cast Exception"<<endl;
	}
}

int
main(
    int argc,
    char **argv)
{
	Environment::initialize("calc_xmlinout.log", AXIS2_LOG_LEVEL_TRACE);
	std::string	endpointUri = "http://localhost:9090/axis2/services/Calculator";

	std::string clientHome = AXIS2_GETENV("WSFCPP_HOME");
	if(clientHome.empty())
	{
		std::cout<<"Please check your WSFCPP_HOME environment variable";
		return 0;
	}
	
	CalculatorStub stub(clientHome, endpointUri);
		
	OMElement *requestPayload = CreateRequestXML();

    /* invoke the web service method */
	OMElement *responsePayload = stub.add(requestPayload);

	handleResponse(responsePayload);
	requestPayload->setAxiomNode(NULL);
	delete requestPayload;
	responsePayload->setAxiomNode(NULL);
	delete responsePayload;

	return 0;
}

