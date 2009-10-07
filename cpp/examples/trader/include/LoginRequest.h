

        #ifndef LOGINREQUEST_H
        #define LOGINREQUEST_H

       /**
        * LoginRequest.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  LoginRequest class
        */

        namespace org_wso2_www_types{
            class LoginRequest;
        }
        

        
        #include <axutil_qname.h>
        

        #include <stdio.h>
        #include <OMElement.h>
        #include <ServiceClient.h>
        #include <ADBDefines.h>

namespace org_wso2_www_types
{
        
        

        class LoginRequest {

        private:
             
                axutil_qname_t* qname;
            std::string property_Username;

                
                bool isValidUsername;
            std::string property_Password;

                
                bool isValidPassword;
            

        /*** Private methods ***/
          

        bool WSF_CALL
        setUsernameNil();
            

        bool WSF_CALL
        setPasswordNil();
            



        /******************************* public functions *********************************/

        public:

        /**
         * Constructor for class LoginRequest
         */

        LoginRequest();

        /**
         * Destructor LoginRequest
         */
        ~LoginRequest();


       

        /**
         * Constructor for creating LoginRequest
         * @param 
         * @param Username std::string
         * @param Password std::string
         * @return newly created LoginRequest object
         */
        LoginRequest(std::string arg_Username,std::string arg_Password);
        
        
        /********************************** Class get set methods **************************************/
        
        

        /**
         * Getter for username. 
         * @return std::string*
         */
        WSF_EXTERN std::string WSF_CALL
        getUsername();

        /**
         * Setter for username.
         * @param arg_Username std::string*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setUsername(const std::string  arg_Username);

        /**
         * Re setter for username
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetUsername();
        
        

        /**
         * Getter for password. 
         * @return std::string*
         */
        WSF_EXTERN std::string WSF_CALL
        getPassword();

        /**
         * Setter for password.
         * @param arg_Password std::string*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setPassword(const std::string  arg_Password);

        /**
         * Re setter for password
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetPassword();
        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether username is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isUsernameNil();


        

        /**
         * Check whether password is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isPasswordNil();


        

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
         * @param LoginRequest_om_node node to serialize from
         * @param LoginRequest_om_element parent element to serialize from
         * @param tag_closed Whether the parent tag is closed or not
         * @param namespaces hash of namespace uris to prefixes
         * @param next_ns_index an int which contains the next namespace index
         * @return axiom_node_t on success,NULL otherwise.
         */
        axiom_node_t* WSF_CALL
        serialize(axiom_node_t* LoginRequest_om_node, axiom_element_t *LoginRequest_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the LoginRequest is a particle class (E.g. group, inner sequence)
         * @return true if this is a particle class, false otherwise.
         */
        bool WSF_CALL
        isParticle();



        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

      
        

        /**
         * Getter for username by property number (1)
         * @return std::string
         */

        std::string WSF_CALL
        getProperty1();

    
        

        /**
         * Getter for password by property number (2)
         * @return std::string
         */

        std::string WSF_CALL
        getProperty2();

    

};

}        
 #endif /* LOGINREQUEST_H */
    

