#include <stdio.h>
#include <WSRESTClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main()
{
    WSRESTClient * sc = new WSRESTClient("http://search.yahooapis.com/WebSearchService/V1/webSearch");
    sc->initializeClient("yahoo_rest_search.log", AXIS2_LOG_LEVEL_TRACE);
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
    Options * op = sc->getOptions();
    op->setHTTPMethod(AXIS2_HTTP_GET);
    sc->setOptions(op);
    {
        OMElement * payload = new OMElement(NULL,"yahoo_rest_search", NULL);
        OMElement * child1 = new OMElement(payload,"appid", NULL);
        child1->setText("YahooDemo");
        OMElement * child2 = new OMElement(payload,"query", NULL);
        child2->setText("finance");
        printf ((payload->toString()).c_str());
        cout << endl;
        OMElement * response;
        try
        {
            response = sc->request(payload, "");
            if (response)
            {
                cout << endl << "Response: " << response->toString() << endl;
            }
        }
        catch (AxisFault e)
        {
            cout << endl << "Fault: " << (sc->getLastSOAPFault())->toString() << endl;
        }
        delete payload;
    }
    delete sc;
}

