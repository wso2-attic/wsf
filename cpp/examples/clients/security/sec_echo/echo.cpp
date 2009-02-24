/*
* Copyright 2005,2009 WSO2, Inc. http://wso2.com
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
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
#include <NeethiPolicy.h>
#include <OMText.h>

using namespace std;
using namespace wso2wsf;

int main(int argc, char *argv[])
{
    string end_point;
    int iterations;
    WSSOAPClient * sc;
	NeethiPolicy * policy = NULL;
	string client_repo = "";
	string policy_file = "";

	end_point = "http://localhost:9090/axis2/services/sec_echo"; 
	iterations = 1;

    if (argc > 2)
    {   
        if (string (argv[1]).compare("-h") == 0)
        {   
            cout << "Usage : " << argv[0] << " [end_point] [client_repo]" << endl;
            cout << "use -h for help" << endl;
            cout << "default end_point " << end_point << endl;
            return 0;
        }   
        else
            end_point = argv[1];
			client_repo = argv[2];
    }  

	if (client_repo.compare("") == 0)
    {
        client_repo = AXIS2_GETENV("WSFCPP_HOME");
	}

	if(client_repo.compare("")!= 0)
    {
		string file_name = client_repo;
		
		policy_file = file_name.append("\\policy.xml");
	               
    }else{
        cout << "Client Home not Specified\n" << endl;
        cout << "echo client invoke FAILED!\n" << endl;
        return 0;
    }

	sc = new WSSOAPClient(client_repo, end_point);
    cout << endl << "Using end_point: " << end_point << endl;
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
	sc->engageModule("rampart");
	
	/*creating apolicy from the the file
	*/
	try
	{
		cout << "Create policy from the file" << policy_file <<endl;
		policy = new NeethiPolicy(policy_file);
		if (policy)
		{	
			sc->setPolicy(policy);
		}
	}
	catch (NeethiException & e)
	{
		cout << endl << "Error: " << e << endl; 

		getchar();
		return 0;
	}
	
	
	
    for (int i = 0; i < iterations; i++)
    {
        OMNamespace * ns = new OMNamespace("http://ws.apache.org/rampart/c/samples", "ns1");
        OMElement * payload = new OMElement(NULL,"echoIn", ns);
        OMElement * child = new OMElement(payload,"text", NULL);
        child->setText("Hello World!");
		
        cout << endl << "Request: " << payload << endl;
        OMElement * response;
        try
        {
            response = sc->request(payload, "http://example.com/ws/2004/09/policy/Test/EchoRequest");
            if (response)
            {
                cout << endl << "Response: " << response->getFirstElement() << endl;
            }
        }
        catch (AxisFault & e)
        {
            if (sc->getLastSOAPFault())
            {
                cout << endl << "Fault: " << sc->getLastSOAPFault() << endl;
            }
            else
            {
                cout << endl << "Error: " << e << endl;
            }
        }
        delete payload;
    }
	delete sc;
}

