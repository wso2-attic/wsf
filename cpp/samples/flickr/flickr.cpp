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
    sc->initializeClient("flicker_client.log", AXIS2_LOG_LEVEL_TRACE);
    {
        OMNamespace * ns = new OMNamespace("urn:flickr", "x");
        OMElement * payload = new OMElement(NULL,"FlickrRequest", ns);
        OMElement * child1 = new OMElement(payload,"method", NULL);
        child1->setText("flickr.photos.search");
        OMElement * child2 = new OMElement(payload,"api_key", NULL);
        child2->setText("00000000000000000000000000000000");
        OMElement * child3 = new OMElement(payload,"tags", NULL);
        child3->setText("home");
        printf ((payload->toString()).c_str());
        cout << endl;
        OMElement * response = NULL;
        try
        {
            response = sc->request(payload, "");
        }
        catch (AxisFault e)
        {
            cout << endl << "Response: " << sc->getLastResponseSoapEnvelopeString() << endl;
            cout << endl << "Response: " << (sc->getLastSOAPFault())->toString() << endl;
        }
        if (response)
        {
            cout << endl << "Response: " << response->toString() << endl;
            cout << endl << "Response: " << sc->getLastResponseSoapEnvelopeString() << endl;
        }
        delete payload;
    }
    delete sc;
}

