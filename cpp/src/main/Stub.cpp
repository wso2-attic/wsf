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
using namespace std;
using namespace wso2wsf;

Options* Stub::_getOptions()
{
	return _options;
}

ServiceClient*  Stub::_getServiceClient()
{
	return _serviceClient;
}

bool Stub::_setServiceClient(ServiceClient *client)
{
	if(_serviceClient)
		delete _serviceClient;
	_serviceClient = client;
}

bool Stub::_engageModule(std::string moduleName)
{
	_serviceClient->engageModule(moduleName);
	return true;
}


void Stub::_addAnonymousOperations()
{	
	
}