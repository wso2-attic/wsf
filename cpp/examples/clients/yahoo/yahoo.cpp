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

void printHelp()
{
     cout<<"./yahoosearch string_to_search \n"<<endl;
     exit(0);
}


int main(int argc, char* argv[])
{
    char *searchString = "finance";
    
    Environment::initialize("yahoo_rest_search.log", AXIS2_LOG_LEVEL_TRACE);

    if(argc > 1)
    {

        if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
        {
            printHelp();
        }
        else
            searchString = argv[1];
    }

	ServiceClient sc("http://search.yahooapis.com/WebSearchService/V1/webSearch");
    
    sc.engageModule(AXIS2_MODULE_ADDRESSING);
    Options * op = sc.getOptions();
	op->setEnableREST(true);
    op->setHTTPMethod(AXIS2_HTTP_GET);
    
    OMElement * payload = new OMElement(NULL,"yahoo_rest_search", NULL);
    OMElement * child1 = new OMElement(payload,"appid", NULL);
    child1->setText("YahooDemo");
    OMElement * child2 = new OMElement(payload,"query", NULL);
    child2->setText(searchString);
    
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
        cout << endl << "Error: " << e << endl;
    }
    delete payload;

}

