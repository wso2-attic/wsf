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

int main(int argc, char *argv[])
{
	Environment::initialize("echo_non_blocking.log", AXIS2_LOG_LEVEL_TRACE);
    string end_point = "http://localhost:9090/axis2/services/echo";;
    int timeout = 10000;;

    if (argc > 1)
    {
        if (string (argv[1]).compare("-h") == 0)
        {
            cout << "Usage : " << argv[0] << " [timeout] [end_point]" << endl;
            cout << "use -h for help" << endl;
            cout << "default timeout " << timeout << endl;
            cout << "default end_point " << end_point << endl;
            cout << "NOTE: command line arguments must appear in given order, with trailing ones being optional" << endl;
            return 0;
        }
        else
            timeout = atoi(argv[1]);
    }
    if (argc > 2)
        end_point = argv[2];

    ServiceClient sc(end_point);

    OMNamespace * ns = new OMNamespace("http://ws.apache.org/axis2/services/echo", "ns1");
    OMElement * payload = new OMElement(NULL,"echoString", ns);
    OMElement * child = new OMElement(payload,"text", NULL);
    child->setText("Hello World!");
    cout << endl << "Request: " << payload << endl;
    
    EchoCallback callback;
    try
    {
        sc.request(payload, &callback, "");
    }
    catch (WSFault & e)
    {
        cout << "Error: " << e << endl;
    }

    int count = 0;
    while((count < timeout) && (!callback.isComplete))
    {
       	WSF_USLEEP(1000);
        count++;
    }

    cout << endl << endl << "Time: " << count << endl;
    delete payload;
}
