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
#include <ServiceClient.h>
#include <OMElement.h>
#include <iostream>
#include <WSFault.h>
#include <Environment.h>


using namespace std;
using namespace wso2wsf;

int main()
{
	Environment::initialize("echo_blocking.log", AXIS2_LOG_LEVEL_TRACE);

	ServiceClient sc("http://localhost:9090/axis2/services/echo");
    
    OMNamespace * ns = new OMNamespace("http://ws.apache.org/axis2/services/echo", "ns1");
    OMElement * payload = new OMElement(NULL,"echoString", ns);
    OMElement * child = new OMElement(payload,"text", NULL);
    child->setText("Hello World!");
    cout << endl << "Request: " << payload << endl;
    
    try
    {
        OMElement * response = sc.request(payload, "");
        if (response)
        {
            cout << endl << "Response: " << response << endl;
        }
    }
    catch (WSFault & e)
    {
        if (sc.getLastSOAPFault())
        {
            cout << endl << "Response: " << sc.getLastSOAPFault() << endl;
        }
        else
        {
            cout << endl << "Response: " << e << endl;
        }
    }
    delete payload;
}

