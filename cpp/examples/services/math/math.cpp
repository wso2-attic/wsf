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
#include <stdio.h>
#include <axutil_env.h>
#include "MATHService.h"
#include "OMElement.h"
#include "OMText.h"
#include <typeinfo>

using namespace std;
using namespace wso2wsf;

WSF_SERVICE_INIT(MathService)

OMElement* MathService::add(OMElement *ele)
{
	
	OMElement *param1 = NULL, *param2 = NULL;
	OMText *param1Text = NULL, *param2Text = NULL;

	param1 = dynamic_cast<OMElement*>(ele->getFirstChild());
	if(!param1)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	param1Text = dynamic_cast<OMText*>(param1->getFirstChild());
	if(!param1Text)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	string param1Str = param1Text->getValue();
	param2 = dynamic_cast<OMElement*>(param1->getNextSibling());
	if(!param2)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	param2Text = dynamic_cast<OMText*>(param2->getFirstChild());
	if(!param2Text)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	string param2Str = param2Text->getValue();
	if(!param2Str.empty() && !param1Str.empty())
	{
		long int value1, value2, result;
		axis2_char_t result_str[255];

		value1 = strtol(param1Str.c_str(), NULL, 10);
		value2 = strtol(param2Str.c_str(), NULL, 10);
		result = value1 + value2;

		sprintf(result_str, "%ld", result);

		OMNamespace *ns = new OMNamespace("http://wso2/wsf/cpp/namespace1", "ns1");
		OMElement   *responseEle  =new OMElement("Result",ns);
		responseEle->setText(result_str);
		return responseEle;
	}
	return NULL;	
}

OMElement* MathService::sub(OMElement *ele)
{

	OMElement *param1 = NULL, *param2 = NULL;
	OMText *param1Text = NULL, *param2Text = NULL;

	param1 = dynamic_cast<OMElement*>(ele->getFirstChild());
	if(!param1)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	param1Text = dynamic_cast<OMText*>(param1->getFirstChild());
	if(!param1Text)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	string param1Str = param1Text->getValue();

	param2 = dynamic_cast<OMElement*>(param1->getNextSibling());
	if(!param2)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	param2Text = dynamic_cast<OMText*>(param2->getFirstChild());
	if(!param2Text)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	string param2Str = param2Text->getValue();

	if(!param2Str.empty() && !param1Str.empty())
	{
		long int value1, value2, result;
		axis2_char_t result_str[255];

		value1 = strtol(param1Str.c_str(), NULL, 10);
		value2 = strtol(param2Str.c_str(), NULL, 10);
		result = value1 - value2;

		sprintf(result_str, "%ld", result);

		OMNamespace *ns = new OMNamespace("http://wso2/wsf/cpp/namespace1", "ns1");
		OMElement   *responseEle  =new OMElement("Result",ns);
		responseEle->setText(result_str);

		return responseEle;

	}
return NULL;	
}

OMElement* MathService::mul(OMElement *ele)
{
	OMElement *param1 = NULL, *param2 = NULL;
	OMText *param1Text = NULL, *param2Text = NULL;

	param1 = dynamic_cast<OMElement*>(ele->getFirstChild());
	if(!param1)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	param1Text = dynamic_cast<OMText*>(param1->getFirstChild());
	if(!param1Text)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	string param1Str = param1Text->getValue();

	param2 = dynamic_cast<OMElement*>(param1->getNextSibling());
	if(!param2){
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	param2Text = dynamic_cast<OMText*>(param2->getFirstChild());
	if(!param2Text)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	string param2Str = param2Text->getValue();

	if(!param2Str.empty() && !param1Str.empty())
	{
		long int value1, value2, result;
		axis2_char_t result_str[255];

		value1 = strtol(param1Str.c_str(), NULL, 10);
		value2 = strtol(param2Str.c_str(), NULL, 10);
		result = value1 * value2;

		sprintf(result_str, "%ld", result);

		OMNamespace *ns = new OMNamespace("http://wso2/wsf/cpp/namespace1", "ns1");
		OMElement   *responseEle  =new OMElement("Result",ns);
		responseEle->setText(result_str);

		return responseEle;

	}
	return NULL;	
}

OMElement* MathService::div(OMElement *ele)
{
	OMElement *param1 = NULL, *param2 = NULL;
	OMText *param1Text = NULL, *param2Text = NULL;

	param1 = dynamic_cast<OMElement*>(ele->getFirstChild());
	if(!param1)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	param1Text = dynamic_cast<OMText*>(param1->getFirstChild());

	string param1Str = param1Text->getValue();
	if(!param1Text)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	param2 = dynamic_cast<OMElement*>(param1->getNextSibling());
	if(!param2)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	param2Text = dynamic_cast<OMText*>(param2->getFirstChild());
	if(!param2Text)
	{
		std::cout<<"Casting Failed"<<std::endl;
		return NULL;
	}
	string param2Str = param2Text->getValue();

	if(!param2Str.empty() && !param1Str.empty())
	{
		long int value1, value2, result;
		axis2_char_t result_str[255];

		value1 = strtol(param1Str.c_str(), NULL, 10);
		value2 = strtol(param2Str.c_str(), NULL, 10);
		if(value2)
		{
			result = value1 / value2;
		}
		sprintf(result_str, "%ld", result);

		OMNamespace *ns = new OMNamespace("http://wso2/wsf/cpp/namespace1", "ns1");
		OMElement   *responseEle  =new OMElement("Result",ns);
		responseEle->setText(result_str);

		return responseEle;

	}
	return NULL;	
}

OMElement *MathService::invoke(OMElement *ele, MessageContext *msgCtx)
{
	if(ele)
	{
		string localname = ele->getLocalname();
		if(localname.compare("add") == 0)
		{
			return add(ele);
		}
		if(localname.compare("sub") ==0)
		{
			return sub(ele);
		}
		if(localname.compare("div") ==0)
		{
			return div(ele);
		}
		if(localname.compare("mul") == 0)
		{
			return mul(ele);
		}
	}
	return NULL;
}

OMElement *MathService::onFault(OMElement *ele)
{
	OMElement *responseEle = new OMElement("MathServiceErrorResponse");
	responseEle->setText("Error occurred in math Service");
	return responseEle;
}