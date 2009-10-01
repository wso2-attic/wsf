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
#include <WSFDefines.h>
#include <Environment.h>


using namespace std;
using namespace wso2wsf;

class EchoCallback: public ICallback
{
public:
    bool isComplete;

    WSF_CALL EchoCallback()
    {
        isComplete = false;
    }

    void WSF_CALL onComplete(OMElement* message)
    {
        cout << endl << "Response: " << message->toString() << endl;
        isComplete = true;
    }

    void WSF_CALL onFault(OMElement* message)
    {
        cout << endl << "Fault: " << message->toString() << endl;
        isComplete = true;
    }

    WSF_CALL ~EchoCallback()
    {
    }
};

int main()
{
	Environment::initialize("echo_non_blocking_dual.log", AXIS2_LOG_LEVEL_TRACE);

    ServiceClient * sc = new ServiceClient("http://localhost:9090/axis2/services/echo");
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
    Options * op = sc->getOptions();
    op->setUseSeparateListener(true);
    op->setReplyTo("http://localhost:6060/axis2/services/__ANONYMOUS_SERVICE__/__OPERATION_OUT_IN__");
    sc->setOptions(op);
    
    OMNamespace * ns = new OMNamespace("http://ws.apache.org/axis2/services/echo", "ns1");
    OMElement * payload = new OMElement(NULL,"echoString", ns);
    OMElement * child = new OMElement(payload,"text", NULL);
    child->setText("Hello World!");
    cout << endl << "Request: " << payload << endl;

    EchoCallback callback;
    try
    {
        sc->request(payload, &callback, "http://ws.apache.org/axis2/c/samples/echoString");
    }
    catch (WSFault & e)
    {
        cout << "Error: " << e << endl;
    }
     
    int count = 0, timeout = 10000;  
    while((count < timeout) && (!callback.isComplete))
    {
        count++;
    }
    cout << endl << endl << "Time: " << count << endl;
    delete payload;
    delete sc;
}
