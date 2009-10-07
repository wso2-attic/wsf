

#ifndef ITRADERCLIENTCALLBACK_H
#define ITRADERCLIENTCALLBACK_H
/**
 * ITraderClientCallback.h
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis2 version: #axisVersion# #today#
 */
       
#include "DepositResponse.h"
        
#include "GetSymbolsResponse.h"
        
#include "GetQuoteResponse.h"
        
#include "CreateAccountResponse.h"
        
#include "SellResponse.h"
        
#include "BuyResponse.h"
        
#include "GetPortfolioResponse.h"
        

#include "TraderClientStub.h" 

 namespace org_wso2_www
   {

    /**
     *  ITraderClientCallback Callback class, Users can extend this class and implement
     *  their own receiveResult and receiveError methods.
     */

    class ITraderClientCallback
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
    ITraderClientCallback(void* clientData);

    /**
    * Please use this constructor if you don't want to set any clientData
    */
    ITraderClientCallback();


    /**
     * Get the client data
     */

     void* getClientData();

    
           /**
            * auto generated WSF/C++ call back method for deposit method
            * override this method for handling normal response from deposit operation
            */
          virtual void receiveResult_deposit(
              
                    org_wso2_www_types::DepositResponse* result
                    
                    ){}


          /**
           * auto generated WSF/C++ Error handler
           * override this method for handling error response from deposit operation
           */
           virtual void receiveError_deposit(int exception){}
            
           /**
            * auto generated WSF/C++ call back method for getSymbols method
            * override this method for handling normal response from getSymbols operation
            */
          virtual void receiveResult_getSymbols(
              
                    org_wso2_www_types::GetSymbolsResponse* result
                    
                    ){}


          /**
           * auto generated WSF/C++ Error handler
           * override this method for handling error response from getSymbols operation
           */
           virtual void receiveError_getSymbols(int exception){}
            
           /**
            * auto generated WSF/C++ call back method for getQuote method
            * override this method for handling normal response from getQuote operation
            */
          virtual void receiveResult_getQuote(
              
                    org_wso2_www_types::GetQuoteResponse* result
                    
                    ){}


          /**
           * auto generated WSF/C++ Error handler
           * override this method for handling error response from getQuote operation
           */
           virtual void receiveError_getQuote(int exception){}
            
           /**
            * auto generated WSF/C++ call back method for createAccount method
            * override this method for handling normal response from createAccount operation
            */
          virtual void receiveResult_createAccount(
              
                    org_wso2_www_types::CreateAccountResponse* result
                    
                    ){}


          /**
           * auto generated WSF/C++ Error handler
           * override this method for handling error response from createAccount operation
           */
           virtual void receiveError_createAccount(int exception){}
            
           /**
            * auto generated WSF/C++ call back method for sell method
            * override this method for handling normal response from sell operation
            */
          virtual void receiveResult_sell(
              
                    org_wso2_www_types::SellResponse* result
                    
                    ){}


          /**
           * auto generated WSF/C++ Error handler
           * override this method for handling error response from sell operation
           */
           virtual void receiveError_sell(int exception){}
            
           /**
            * auto generated WSF/C++ call back method for buy method
            * override this method for handling normal response from buy operation
            */
          virtual void receiveResult_buy(
              
                    org_wso2_www_types::BuyResponse* result
                    
                    ){}


          /**
           * auto generated WSF/C++ Error handler
           * override this method for handling error response from buy operation
           */
           virtual void receiveError_buy(int exception){}
            
           /**
            * auto generated WSF/C++ call back method for getPortfolio method
            * override this method for handling normal response from getPortfolio operation
            */
          virtual void receiveResult_getPortfolio(
              
                    org_wso2_www_types::GetPortfolioResponse* result
                    
                    ){}


          /**
           * auto generated WSF/C++ Error handler
           * override this method for handling error response from getPortfolio operation
           */
           virtual void receiveError_getPortfolio(int exception){}
            


    };
}

#endif  //ITRADERCLIENTCALLBACK_H
    

