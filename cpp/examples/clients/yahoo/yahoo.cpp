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
#include <WSRESTClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main()
{
    Process::initialize("yahoo_rest_search.log", AXIS2_LOG_LEVEL_TRACE);

    WSRESTClient sc("http://search.yahooapis.com/WebSearchService/V1/webSearch");
    
    sc.engageModule(AXIS2_MODULE_ADDRESSING);
    Options * op = sc.getOptions();
    op->setHTTPMethod(AXIS2_HTTP_GET);
    
    OMElement * payload = new OMElement(NULL,"yahoo_rest_search", NULL);
    OMElement * child1 = new OMElement(payload,"appid", NULL);
    child1->setText("YahooDemo");
    OMElement * child2 = new OMElement(payload,"query", NULL);
    child2->setText("finance");
    
    cout << endl << "Request: " << payload << endl;
    
    try
    {
        OMElement * response = sc.request(payload, "");
        if (response)
        {
            cout << endl << "Response: " << response << endl;
        }
    }
    catch (AxisFault & e)
    {
        cout << endl << "Error: " << e << endl;
    }
    delete payload;
}

