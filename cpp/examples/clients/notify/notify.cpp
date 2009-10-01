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

	Environment::initialize("notify.log", AXIS2_LOG_LEVEL_TRACE);

    ServiceClient sc("http://localhost:9090/axis2/services/notify");
    sc.engageModule(AXIS2_MODULE_ADDRESSING);

    OMNamespace * ns = new OMNamespace("http://example.org/notify", "m");
    OMElement * payload = new OMElement(NULL,"notify", ns);
    payload->setText("notify5");
    cout << endl << "Request: " << payload << endl;
    
    try
    {
        bool status = sc.send(payload, "http://example.org/action/notify");
        if (status)
        {
            cout << endl << "notify client invoke SUCCESSFUL!" << endl;
        }
        else
        {
            cout << endl << "notify client invoke FAILED!" << endl;
        }
    }
    catch (WSFault & e)
    {
        cout << endl << "Error: " << e << endl;
    }
    
    delete payload;
}
