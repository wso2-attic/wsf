

#ifndef IEXCHANGETRADERCALLBACK_H
#define IEXCHANGETRADERCALLBACK_H
/**
 * IExchangeTraderCallback.h
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis2 version: #axisVersion# #today#
 */
       
#include "RegisterClientResponse.h"
        

#include "ExchangeTraderStub.h" 

 namespace org_wso2_www
   {

    /**
     *  IExchangeTraderCallback Callback class, Users can extend this class and implement
     *  their own receiveResult and receiveError methods.
     */

    class IExchangeTraderCallback
{


    protected:

    void* clientData;

    public:

    /**
    * User can pass in any object that needs to be accessed once the NonBlocking
    * Web service call is finished and appropriate method of this CallBack is called.
    * @param clientData Object mechanism by which the user can pass in user data
    * that will be available at the time this callback is called.
    */
    IExchangeTraderCallback(void* clientData);

    /**
    * Please use this constructor if you don't want to set any clientData
    */
    IExchangeTraderCallback();


    /**
     * Get the client data
     */

     void* getClientData();

    
           // No methods generated for meps other than in-out
            
           /**
            * auto generated WSF/C++ call back method for registerClient method
            * override this method for handling normal response from registerClient operation
            */
          virtual void receiveResult_registerClient(
              
                    org_wso2_www_types::RegisterClientResponse* result
                    
                    ){}


          /**
           * auto generated WSF/C++ Error handler
           * override this method for handling error response from registerClient operation
           */
           virtual void receiveError_registerClient(int exception){}
            
           // No methods generated for meps other than in-out
            
           // No methods generated for meps other than in-out
            
           // No methods generated for meps other than in-out
            


    };
}

#endif  //IEXCHANGETRADERCALLBACK_H
    

