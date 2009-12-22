

          #ifndef EXCHANGETRADER_H
          #define EXCHANGETRADER_H

        /**
         * ExchangeTrader.h
         *
         * This file was auto-generated from WSDL for "ExchangeTrader|http://www.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  ExchangeTrader
         */

#include <ServiceSkeleton.h>
#include <stdio.h>
#include <axis2_svc.h>

using namespace wso2wsf;


using namespace org_wso2_www;



#define WSF_SERVICE_SKEL_INIT(class_name) \
ExchangeTraderSkeleton* wsfGetExchangeTraderSkeleton(){ return new class_name(); }

ExchangeTraderSkeleton* wsfGetExchangeTraderSkeleton(); 



        class ExchangeTrader : public ServiceSkeleton
        {
            private:
                ExchangeTraderSkeleton *skel;

            public:

               union {
                     
               } fault;


              WSF_EXTERN WSF_CALL ExchangeTrader();

              OMElement* WSF_CALL invoke(OMElement *message, MessageContext *msgCtx);

              OMElement* WSF_CALL onFault(OMElement *message);

              bool WSF_CALL init();

              ~ExchangeTrader(); 
      };



#endif    //     EXCHANGETRADER_H

    

