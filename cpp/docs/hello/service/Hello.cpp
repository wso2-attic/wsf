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


#include <ServiceSkeleton.h>
#include <iostream>
#include <stdio.h>
#include <axutil_env.h>
#include <Environment.h>
#include <OMText.h>
#include "Hello.h"


using namespace wso2wsf;
using namespace std;

/** Load the service into axis2 engine */
WSF_SERVICE_INIT(Hello)

OMElement* Hello::invoke(OMElement *ele, MessageContext *msgCtx)
{
	return greet(ele);
}

OMElement* Hello::onFault(OMElement *ele)
{
	OMElement *responseEle = new OMElement("HelloServiceErrorResponse");
	responseEle->setText("Hello Service Failed");
	return responseEle;
}

void Hello::init()
{

}

OMElement* Hello::greet(OMElement* inMsg)
{
	string greet;
	if(inMsg)
	{	
		try
		{	
			if(inMsg->getFirstChild() && inMsg->getFirstChild()->nodeType() == AXIOM_TEXT)
			{
				OMText *text = dynamic_cast<OMText*>(inMsg->getFirstChild());
				greet = text->getValue();
				cout << "Client greeted Saying" << greet << endl;				
			}
		}catch (bad_cast) 
		{
			return NULL;
		}
		OMElement *helloEle = new OMElement("greetResponse");
		OMElement *text = new OMElement("text");
		helloEle->setText(greet);
		return helloEle;
	}
	return NULL;
}
