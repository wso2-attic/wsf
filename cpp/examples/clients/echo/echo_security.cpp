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
    string end_point = "http://localhost:9090/axis2/services/sec_echo";
    string client_repo = AXIS2_GETENV("WSFCPP_HOME");
           client_repo+="/client_repo";
    string policy_file = "policy.xml";

	Environment::initialize("echo_security.log", AXIS2_LOG_LEVEL_TRACE);


    if (argc > 1)
    {
        if (string (argv[1]).compare("-h") == 0)
        {
            cout << "Usage : " << argv[0] << " [end_point] [client_repo] [policy_file]" << endl;
            cout << "use -h for help" << endl;
            cout << "default end_point " << end_point << endl;
            cout << "default client_repo " << client_repo << endl;
            cout << "default policy_file " << policy_file << endl;
            cout << "NOTE: command line arguments must appear in given order, with trailing ones being optional" << endl;
            cout << "IMPORTANT: please add a trailing slash (or back-slash) after client_repo location" << endl;
            return 0;
        }
        else
            end_point = argv[1];
    }
    if (argc > 2)
        client_repo = argv[2];
    if (argc > 3)
        policy_file = argv[3];

    ServiceClient sc(client_repo, end_point);
	if(!sc.isValidClient())
	{
		cout<<"Client Initialization Failed"<<endl;
		exit(0);
	}
		
    sc.engageModule(AXIS2_MODULE_ADDRESSING);
    sc.setPolicy(new NeethiPolicy(client_repo + "/" + policy_file));

    OMNamespace * ns = new OMNamespace("http://ws.apache.org/rampart/c/samples", "ns1");
    OMElement * payload = new OMElement(NULL,"echoIn", ns);
    OMElement * child = new OMElement(payload,"text", NULL);
    child->setText("Hello");
    cout << endl << "Request: " << payload << endl;

    try
    {
        OMElement* response = sc.request(payload, "http://example.com/ws/2004/09/policy/Test/EchoRequest");
        if (response)
        {
            //cout << endl << "ResponseEnvelope: " << sc.getLastResponseSoapEnvelopeString() << endl;
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

