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

int main(int argc, char *argv[])
{
    string operation = "add";
    string param1 = "40";
    string param2 = "8";
    string end_point = "http://localhost:9090/axis2/services/math";

	Environment::initialize("math.log", AXIS2_LOG_LEVEL_TRACE);

    if (argc > 1)
    {
        if (string (argv[1]).compare("-h") == 0)
        {
            cout << "Usage : " << argv[0] << " [operation] [param1] [param2] [end_point]" << endl;
            cout << "use -h for help" << endl;
            cout << "default operation " << operation << endl;
            cout << "default param1 " << param1 << endl;
            cout << "default param2 " << param2 << endl;
            cout << "default end_point " << end_point << endl;
            cout << "NOTE: command line arguments must appear in given order, with trailing ones being optional" << endl;
            return 0;
        }
        else
            operation = argv[1];
    }
    if (argc > 2)
        param1 = argv[2];
    if (argc > 3)
        param2 = argv[3];
    if (argc > 4)
        end_point = argv[4];
    
    ServiceClient sc(end_point);
    sc.engageModule(AXIS2_MODULE_ADDRESSING);

    OMNamespace * ns = new OMNamespace("http://ws.apache.org/axis2/services/math", "ns1");
    OMElement * payload = new OMElement(NULL,operation, ns);
    OMElement * child1 = new OMElement(payload,"param1", NULL);
    child1->setText(param1);
    OMElement * child2 = new OMElement(payload,"param2", NULL);
    child2->setText(param2);
    cout << endl << "Request: " << payload << endl;
    
    try
    {
        OMElement * response = sc.request(payload, "http://ws.apache.org/axis2/c/samples/mathSample");
        if (response)
        {
            cout << endl << "Response: " << response << endl;
        }
    }
    catch (WSFault & e)
    {
        if (sc.getLastSOAPFault())
        {
            cout << endl << "Fault: " << sc.getLastSOAPFault() << endl;
        }
        else
        {
            cout << endl << "Error: " << e << endl;
        }
    }
    delete payload;
}

