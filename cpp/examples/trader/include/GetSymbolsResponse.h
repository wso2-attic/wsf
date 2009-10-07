

        #ifndef GETSYMBOLSRESPONSE_H
        #define GETSYMBOLSRESPONSE_H

       /**
        * GetSymbolsResponse.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  GetSymbolsResponse class
        */

        namespace org_wso2_www_types{
            class GetSymbolsResponse;
        }
        

        
       #include "ArrayOfString.h"
          
        #include <axutil_qname.h>
        

        #include <stdio.h>
        #include <OMElement.h>
        #include <ServiceClient.h>
        #include <ADBDefines.h>

namespace org_wso2_www_types
{
        
        

        class GetSymbolsResponse {

        private:
             
                axutil_qname_t* qname;
            org_wso2_www_types::ArrayOfString* property__return;

                
                bool isValid_return;
            

        /*** Private methods ***/
          

        bool WSF_CALL
        set_returnNil();
            



        /******************************* public functions *********************************/

        public:

        /**
         * Constructor for class GetSymbolsResponse
         */

        GetSymbolsResponse();

        /**
         * Destructor GetSymbolsResponse
         */
        ~GetSymbolsResponse();


       

        /**
         * Constructor for creating GetSymbolsResponse
         * @param 
         * @param _return org_wso2_www_types::ArrayOfString*
         * @return newly created GetSymbolsResponse object
         */
        GetSymbolsResponse(org_wso2_www_types::ArrayOfString* arg__return);
        
        
        /********************************** Class get set methods **************************************/
        
        

        /**
         * Getter for return. 
         * @return org_wso2_www_types::ArrayOfString*
         */
        WSF_EXTERN org_wso2_www_types::ArrayOfString* WSF_CALL
        get_return();

        /**
         * Setter for return.
         * @param arg__return org_wso2_www_types::ArrayOfString*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        set_return(org_wso2_www_types::ArrayOfString*  arg__return);

        /**
         * Re setter for return
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        reset_return();
        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether return is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        is_returnNil();


        

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
         * @param GetSymbolsResponse_om_node node to serialize from
         * @param GetSymbolsResponse_om_element parent element to serialize from
         * @param tag_closed Whether the parent tag is closed or not
         * @param namespaces hash of namespace uris to prefixes
         * @param next_ns_index an int which contains the next namespace index
         * @return axiom_node_t on success,NULL otherwise.
         */
        axiom_node_t* WSF_CALL
        serialize(axiom_node_t* GetSymbolsResponse_om_node, axiom_element_t *GetSymbolsResponse_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the GetSymbolsResponse is a particle class (E.g. group, inner sequence)
         * @return true if this is a particle class, false otherwise.
         */
        bool WSF_CALL
        isParticle();



        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

      
        

        /**
         * Getter for return by property number (1)
         * @return org_wso2_www_types::ArrayOfString
         */

        org_wso2_www_types::ArrayOfString* WSF_CALL
        getProperty1();

    

};

}        
 #endif /* GETSYMBOLSRESPONSE_H */
    

