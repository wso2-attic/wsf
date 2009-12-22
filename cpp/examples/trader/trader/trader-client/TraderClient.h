

          #ifndef TRADERCLIENT_H
          #define TRADERCLIENT_H

        /**
         * TraderClient.h
         *
         * This file was auto-generated from WSDL for "TraderClient|http://www.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  TraderClient
         */

#include <ServiceSkeleton.h>
#include <stdio.h>
#include <axis2_svc.h>

using namespace wso2wsf;


using namespace org_wso2_www;



#define WSF_SERVICE_SKEL_INIT(class_name) \
TraderClientSkeleton* wsfGetTraderClientSkeleton(){ return new class_name(); }

TraderClientSkeleton* wsfGetTraderClientSkeleton(); 



        class TraderClient : public ServiceSkeleton
        {
            private:
                TraderClientSkeleton *skel;

            public:

               union {
                     
               } fault;


              WSF_EXTERN WSF_CALL TraderClient();

              OMElement* WSF_CALL invoke(OMElement *message, MessageContext *msgCtx);

              OMElement* WSF_CALL onFault(OMElement *message);

              bool WSF_CALL init();

              ~TraderClient(); 
      };



#endif    //     TRADERCLIENT_H

    

