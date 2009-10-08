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

int main(int argc, char* argv[])
{
	const char *apiKey= "00000000000000000000000000000000";
	const char *searchString = "home";
	Environment::initialize("flicker.log", AXIS2_LOG_LEVEL_TRACE);

	if(argc == 3)
	{
			apiKey = argv[1];
			searchString = argv[2];
	}else
	{
		cout<<"./flicker <APIKEY> <Search String>"<<endl;
		exit(0);
	}
    ServiceClient * sc = new ServiceClient("http://api.flickr.com/services/soap/");

    OMNamespace * ns = new OMNamespace("urn:flickr", "x");
    OMElement * payload = new OMElement(NULL,"FlickrRequest", ns);
    OMElement * child1 = new OMElement(payload,"method", NULL);
    child1->setText("flickr.photos.search");
    OMElement * child2 = new OMElement(payload,"api_key", NULL);
    child2->setText(apiKey);
    OMElement * child3 = new OMElement(payload,"tags", NULL);
    child3->setText("home");
    cout << endl << "Request: " << payload << endl;

    try
    {
        OMElement * response = sc->request(payload, "");
        if (response)
        {
            cout << endl << "Response: " << response << endl;
        }
    }
    catch (WSFault & e)
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
    delete sc;
}

