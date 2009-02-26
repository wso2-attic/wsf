
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



#include <stdio.h>
#include <axutil_env.h>
#include "Version.h"
#include <ServiceSkeleton.h>

using namespace wso2wsf;

WSF_SERVICE_INIT(Version)

OMElement* Version::invoke(OMElement *ele, MessageContext *msgCtx)
{
	OMNamespace *ns = new OMNamespace("urn:WSFCPPWebServices","ns1");
	OMElement *resultEle = new OMElement("Result",ns);
	resultEle->setText("Version 1.1");
	return resultEle;
}

OMElement* Version::onFault(OMElement *ele)
{
	OMElement *responseEle = new OMElement("VersionServiceErrorResponse");
	return respnseEle->setText("Version Service Failed");
}
