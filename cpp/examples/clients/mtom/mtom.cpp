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
#include <OMText.h>
#include <OMDataHandler.h>
#include <iostream>
#include <WSFault.h>
#include <Environment.h>


using namespace std;
using namespace wso2wsf;

int main(int argc, char *argv[])
{
    string end_point = "http://localhost:9090/axis2/services/mtom";
    string file_name = "resources/axis2.jpg";
	
	Environment::initialize("mtom.log",AXIS2_LOG_LEVEL_TRACE);

    if (argc > 1)
    {
        if (string (argv[1]).compare("-h") == 0)
        {
            cout << "Usage : " << argv[0] << " [end_point] [file_name]" << endl;
            cout << "use -h for help" << endl;
            cout << "default end_point " << end_point << endl;
            cout << "default file_name " << file_name << endl;
            cout << "NOTE: command line arguments must appear in given order, with trailing ones being optional" << endl;
            return 0;
        }
        else
            end_point = argv[1];
    }
    if (argc > 2)
        file_name = argv[2];

    ServiceClient sc(end_point);
    sc.engageModule(AXIS2_MODULE_ADDRESSING);
    
    Options * op = sc.getOptions();
    op->setSoapVersion(AXIOM_SOAP11);
    op->setEnableMTOM(true);

    OMNamespace * ns1 = new OMNamespace("http://ws.apache.org/axis2/c/samples/mtom", "ns1");
    OMElement * payload = new OMElement(NULL,"mtomSample", NULL);
    OMElement * child1 = new OMElement(payload,"fileName", NULL);
    child1->setText("test.jpg");
    OMElement * child2 = new OMElement(payload,"image", NULL);
    OMDataHandler * data_handler = new OMDataHandler(file_name, "image/jpeg");
    OMText * child3 = new OMText(child2, data_handler);
    child3->optimize(true);
    cout << endl << "Request: " << payload << endl;

    try
    {
        OMElement * response = sc.request(payload, "http://ws.apache.org/axis2/c/samples/mtomSample");
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

