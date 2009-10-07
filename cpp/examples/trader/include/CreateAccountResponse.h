

        #ifndef CREATEACCOUNTRESPONSE_H
        #define CREATEACCOUNTRESPONSE_H

       /**
        * CreateAccountResponse.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  CreateAccountResponse class
        */

        namespace org_wso2_www_types{
            class CreateAccountResponse;
        }
        

        
        #include <axutil_qname.h>
        

        #include <stdio.h>
        #include <OMElement.h>
        #include <ServiceClient.h>
        #include <ADBDefines.h>

namespace org_wso2_www_types
{
        
        

        class CreateAccountResponse {

        private:
             
                axutil_qname_t* qname;
            std::string property_Userid;

                
                bool isValidUserid;
            

        /*** Private methods ***/
          

        bool WSF_CALL
        setUseridNil();
            



        /******************************* public functions *********************************/

        public:

        /**
         * Constructor for class CreateAccountResponse
         */

        CreateAccountResponse();

        /**
         * Destructor CreateAccountResponse
         */
        ~CreateAccountResponse();


       

        /**
         * Constructor for creating CreateAccountResponse
         * @param 
         * @param Userid std::string
         * @return newly created CreateAccountResponse object
         */
        CreateAccountResponse(std::string arg_Userid);
        
        
        /********************************** Class get set methods **************************************/
        
        

        /**
         * Getter for userid. 
         * @return std::string*
         */
        WSF_EXTERN std::string WSF_CALL
        getUserid();

        /**
         * Setter for userid.
         * @param arg_Userid std::string*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setUserid(const std::string  arg_Userid);

        /**
         * Re setter for userid
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetUserid();
        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether userid is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isUseridNil();


        

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
         * @param CreateAccountResponse_om_node node to serialize from
         * @param CreateAccountResponse_om_element parent element to serialize from
         * @param tag_closed Whether the parent tag is closed or not
         * @param namespaces hash of namespace uris to prefixes
         * @param next_ns_index an int which contains the next namespace index
         * @return axiom_node_t on success,NULL otherwise.
         */
        axiom_node_t* WSF_CALL
        serialize(axiom_node_t* CreateAccountResponse_om_node, axiom_element_t *CreateAccountResponse_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the CreateAccountResponse is a particle class (E.g. group, inner sequence)
         * @return true if this is a particle class, false otherwise.
         */
        bool WSF_CALL
        isParticle();



        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

      
        

        /**
         * Getter for userid by property number (1)
         * @return std::string
         */

        std::string WSF_CALL
        getProperty1();

    

};

}        
 #endif /* CREATEACCOUNTRESPONSE_H */
    

