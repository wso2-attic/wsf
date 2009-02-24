#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main()
{
    WSSOAPClient * sc = new WSSOAPClient("http://api.flickr.com/services/soap/");
    try 
    {   
        //sc->initializeClient("flickr_client.log", AXIS2_LOG_LEVEL_TRACE);
    }   
    catch (AxisFault & e)
    {   
        cout << endl << "Error: " << e << endl;
        return 0;
    }
    {
        OMNamespace * ns = new OMNamespace("urn:flickr", "x");
        OMElement * payload = new OMElement(NULL,"FlickrRequest", ns);
        OMElement * child1 = new OMElement(payload,"method", NULL);
        child1->setText("flickr.photos.search");
        OMElement * child2 = new OMElement(payload,"api_key", NULL);
        child2->setText("00000000000000000000000000000000");
        OMElement * child3 = new OMElement(payload,"tags", NULL);
        child3->setText("home");
        cout << endl << "Request: " << payload << endl;
        OMElement * response;
        try
        {
            response = sc->request(payload, "");
            if (response)
            {
                cout << endl << "Response: " << response << endl;
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

