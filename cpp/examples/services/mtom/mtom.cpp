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
#include "MTOMService.h"
#include "OMElement.h"
#include "OMText.h"
#include <typeinfo>
using namespace std;
using namespace wso2wsf;


/** This macro is used to load the service to WSF Framework */
WSF_SERVICE_INIT(MTOMService)

/** Service invocation function. Overriding method */
OMElement* MTOMService::invoke(OMElement *ele, MessageContext *msgCtx)
{
	/* Expected request format is :-
	* <ns1:mtomSample xmlns:ns1="http://ws.apache.org/axis2/c/samples">
		<ns1:fileName>test.jpg</ns1:fileName>
		<ns1:image>
			<xop:Include xmlns:xop="http://www.w3.org/2004/08/xop/include" href="cid:1.dd5183d4-d58a-1da1-2578-001125b4c063@apache.org"></xop:Include>
		</ns1:image>
	</ns1:mtomSample>
	*/
	int length = 0;
	axis2_byte_t *data = NULL;
	if(ele)
	{	
		
		
		OMElement *fileNameEle = dynamic_cast<OMElement *>(ele->getFirstChild());
		
		if(fileNameEle && fileNameEle->getFirstChild() && fileNameEle->getFirstChild()->nodeType() == AXIOM_TEXT)
		{
				OMText *text = dynamic_cast<OMText*>(fileNameEle->getFirstChild());
				if(!text)
				{
					std::cout<<"Casting failed"<<std::endl;
					return NULL;
				}
				string filename = text->getValue();

				OMElement *imageEle = dynamic_cast<OMElement*>(fileNameEle->getNextSibling());
				if(imageEle)
				{
					OMText *imageText = dynamic_cast<OMText*>(imageEle->getFirstChild());
					if(imageText)
					{
						OMDataHandler *dh = imageText->getDataHandler();
						if(dh && !(dh->isCached()))
						{
							dh->writeTo(filename);
							length = dh->getInputStreamLength();
							data = dh->getInputStream();
						}
					}
				}
			}
		
		}
		/** Build the response payload */
		OMElement *resultEle = new OMElement("response", new OMNamespace("http://ws.apache.org/wsf/cpp/samples","ns1"));
		/** construct a datahandler with the received binary content */
		OMDataHandler *responseDh = new OMDataHandler();
		
		/** Write function duplicates the data and keep it as part of data handler*/
	
		responseDh->write(data, length);
		
		OMText *dhText = new OMText(responseDh);
		resultEle->addChild(dhText);
		msgCtx->setDoingMTOM(true);
		return resultEle;

	return NULL;
}

OMElement* MTOMService::onFault(OMElement *ele)
{
	OMElement *responseEle = new OMElement("MathServiceErrorResponse");
	responseEle->setText("Math Service Failed");
	return responseEle;
}

