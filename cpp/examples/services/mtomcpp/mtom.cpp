
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

#include <ServiceSkeleton.h>
#include <stdio.h>
#include <axutil_env.h>
#include "MTOMService.h"
#include "OMElement.h"
#include "OMText.h"
#include <typeinfo>
using namespace std;
using namespace wso2wsf;

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
	if(ele)
	{	
		OMElement *fileNameEle,*imageEle;
		OMText *text = NULL;
		OMDataHandler *dh = NULL;
		try
		{	
			fileNameEle = dynamic_cast<OMElement *>(ele->getFirstChild());

			if(fileNameEle && fileNameEle->getFirstChild() && fileNameEle->getFirstChild()->nodeType() == AXIOM_TEXT)
			{
				text = dynamic_cast<OMText*>(fileNameEle->getFirstChild());
				string filename = text->getValue();

				imageEle = dynamic_cast<OMElement*>(fileNameEle->getNextSibling());
				if(imageEle)
				{
					
					OMText *imageText = dynamic_cast<OMText*>(imageEle->getFirstChild());
					if(imageText)
					{
						dh = imageText->getDataHandler();
						if(dh && !(dh->isCached()))
						{
							dh->setFileName(filename);
							dh->writeTo();
						}
						dh->getInputStream()
					}
				}
			}
		}catch (bad_cast) 
		{

		}
		OMElement *resultEle = new OMElement("response", new OMNamespace("http://ws.apache.org/wsf/cpp/samples","ns1"));
		OMDataHandler *reponseDh = new OMDataHandler();

	}
	
	return NULL;
}

OMElement* MTOMService::onFault(OMElement *ele)
{
	return NULL;
}

#ifdef __cplusplus
extern "C"
{
#endif

	WSF_EXTERN int
		axis2_get_instance(
		ServiceSkeleton ** inst,
		const axutil_env_t * env)
	{
		*inst = new MTOMService();
		if (!(*inst))
		{
			return AXIS2_FAILURE;
		}

		return AXIS2_SUCCESS;
	}

	WSF_EXTERN int
		axis2_remove_instance(
		axis2_svc_skeleton_t * inst,
		const axutil_env_t * env)
	{
		axis2_status_t status = AXIS2_FAILURE;
		if (inst)
		{
			status = AXIS2_SVC_SKELETON_FREE(inst, env);
		}
		return status;
	}

#ifdef __cplusplus
}
#endif