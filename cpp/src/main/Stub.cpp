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

#include <stdio.h>
#include <Stub.h>
#include <Options.h>
#include <ServiceClient.h>
using namespace std;
using namespace wso2wsf;



void Stub::init(std::string& client_home, std::string& endpointUri)
{
	serviceClient = new ServiceClient(client_home, endpointUri);
	clientOptions = serviceClient->getOptions();
}

Options* Stub::getOptions()
{
	return clientOptions;
}

ServiceClient*  Stub::getServiceClient()
{
	return serviceClient;
}

bool Stub::setServiceClient(ServiceClient *client)
{
	if(serviceClient)
	{
		delete serviceClient;
		clientOptions = NULL;
	}
	serviceClient = client;
	if((clientOptions = serviceClient->getOptions())== NULL)
	{
		clientOptions = new Options();
		serviceClient->setOptions(clientOptions);
	}
	return true;
}

bool Stub::engageModule(std::string moduleName)
{
	serviceClient->engageModule(moduleName);
	return true;
}


void Stub::addAnonymousOperations()
{	
	
}

Stub::~Stub()
{
	delete serviceClient;
	serviceClient = NULL;
}

