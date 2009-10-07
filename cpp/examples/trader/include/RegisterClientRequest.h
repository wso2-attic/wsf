

        #ifndef REGISTERCLIENTREQUEST_H
        #define REGISTERCLIENTREQUEST_H

       /**
        * RegisterClientRequest.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  RegisterClientRequest class
        */

        namespace org_wso2_www_types{
            class RegisterClientRequest;
        }
        

        
       #include "ClientInfo.h"
          
        #include <axutil_qname.h>
        

        #include <stdio.h>
        #include <OMElement.h>
        #include <ServiceClient.h>
        #include <ADBDefines.h>

namespace org_wso2_www_types
{
        
        

        class RegisterClientRequest {

        private:
             
                axutil_qname_t* qname;
            org_wso2_www_types::ClientInfo* property_ClientInfo;

                
                bool isValidClientInfo;
            

        /*** Private methods ***/
          

        bool WSF_CALL
        setClientInfoNil();
            



        /******************************* public functions *********************************/

        public:

        /**
         * Constructor for class RegisterClientRequest
         */

        RegisterClientRequest();

        /**
         * Destructor RegisterClientRequest
         */
        ~RegisterClientRequest();


       

        /**
         * Constructor for creating RegisterClientRequest
         * @param 
         * @param ClientInfo org_wso2_www_types::ClientInfo*
         * @return newly created RegisterClientRequest object
         */
        RegisterClientRequest(org_wso2_www_types::ClientInfo* arg_ClientInfo);
        
        
        /********************************** Class get set methods **************************************/
        
        

        /**
         * Getter for ClientInfo. 
         * @return org_wso2_www_types::ClientInfo*
         */
        WSF_EXTERN org_wso2_www_types::ClientInfo* WSF_CALL
        getClientInfo();

        /**
         * Setter for ClientInfo.
         * @param arg_ClientInfo org_wso2_www_types::ClientInfo*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setClientInfo(org_wso2_www_types::ClientInfo*  arg_ClientInfo);

        /**
         * Re setter for ClientInfo
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetClientInfo();
        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether ClientInfo is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isClientInfoNil();


        

        /**************************** Serialize and De serialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Deserialize the ADB object to an XML
         * @param dp_parent double pointer to the parent node to be deserialized
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return true on success, false otherwise
         */
        bool WSF_CALL
        deserialize(axiom_node_t** omNode, bool *isEarlyNodeValid, bool dontCareMinoccurs);
                         
            

       /**
         * Declare namespace in the most parent node 
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
        void WSF_CALL
        declareParentNamespaces(axiom_element_t *parent_element, axutil_hash_t *namespaces, int *next_ns_index);


        

        /**
         * Serialize the ADB object to an xml
         * @param RegisterClientRequest_om_node node to serialize from
         * @param RegisterClientRequest_om_element parent element to serialize from
         * @param tag_closed Whether the parent tag is closed or not
         * @param namespaces hash of namespace uris to prefixes
         * @param next_ns_index an int which contains the next namespace index
         * @return axiom_node_t on success,NULL otherwise.
         */
        axiom_node_t* WSF_CALL
        serialize(axiom_node_t* RegisterClientRequest_om_node, axiom_element_t *RegisterClientRequest_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the RegisterClientRequest is a particle class (E.g. group, inner sequence)
         * @return true if this is a particle class, false otherwise.
         */
        bool WSF_CALL
        isParticle();



        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

      
        

        /**
         * Getter for ClientInfo by property number (1)
         * @return org_wso2_www_types::ClientInfo
         */

        org_wso2_www_types::ClientInfo* WSF_CALL
        getProperty1();

    

};

}        
 #endif /* REGISTERCLIENTREQUEST_H */
    

