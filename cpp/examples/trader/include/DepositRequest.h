

        #ifndef DEPOSITREQUEST_H
        #define DEPOSITREQUEST_H

       /**
        * DepositRequest.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  DepositRequest class
        */

        namespace org_wso2_www_types{
            class DepositRequest;
        }
        

        
        #include <axutil_qname.h>
        

        #include <stdio.h>
        #include <OMElement.h>
        #include <ServiceClient.h>
        #include <ADBDefines.h>

namespace org_wso2_www_types
{
        
        

        class DepositRequest {

        private:
             
                axutil_qname_t* qname;
            std::string property_Useridr;

                
                bool isValidUseridr;
            std::string property_Password;

                
                bool isValidPassword;
            float property_Amount;

                
                bool isValidAmount;
            

        /*** Private methods ***/
          

        bool WSF_CALL
        setUseridrNil();
            

        bool WSF_CALL
        setPasswordNil();
            

        bool WSF_CALL
        setAmountNil();
            



        /******************************* public functions *********************************/

        public:

        /**
         * Constructor for class DepositRequest
         */

        DepositRequest();

        /**
         * Destructor DepositRequest
         */
        ~DepositRequest();


       

        /**
         * Constructor for creating DepositRequest
         * @param 
         * @param Useridr std::string
         * @param Password std::string
         * @param Amount float
         * @return newly created DepositRequest object
         */
        DepositRequest(std::string arg_Useridr,std::string arg_Password,float arg_Amount);
        
        
        /********************************** Class get set methods **************************************/
        
        

        /**
         * Getter for useridr. 
         * @return std::string*
         */
        WSF_EXTERN std::string WSF_CALL
        getUseridr();

        /**
         * Setter for useridr.
         * @param arg_Useridr std::string*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setUseridr(const std::string  arg_Useridr);

        /**
         * Re setter for useridr
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetUseridr();
        
        

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
        
        

        /**
         * Getter for amount. 
         * @return float*
         */
        WSF_EXTERN float WSF_CALL
        getAmount();

        /**
         * Setter for amount.
         * @param arg_Amount float*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setAmount(const float  arg_Amount);

        /**
         * Re setter for amount
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetAmount();
        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether useridr is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isUseridrNil();


        

        /**
         * Check whether password is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isPasswordNil();


        

        /**
         * Check whether amount is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isAmountNil();


        

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
         * @param DepositRequest_om_node node to serialize from
         * @param DepositRequest_om_element parent element to serialize from
         * @param tag_closed Whether the parent tag is closed or not
         * @param namespaces hash of namespace uris to prefixes
         * @param next_ns_index an int which contains the next namespace index
         * @return axiom_node_t on success,NULL otherwise.
         */
        axiom_node_t* WSF_CALL
        serialize(axiom_node_t* DepositRequest_om_node, axiom_element_t *DepositRequest_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the DepositRequest is a particle class (E.g. group, inner sequence)
         * @return true if this is a particle class, false otherwise.
         */
        bool WSF_CALL
        isParticle();



        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

      
        

        /**
         * Getter for useridr by property number (1)
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

    
        

        /**
         * Getter for amount by property number (3)
         * @return float
         */

        float WSF_CALL
        getProperty3();

    

};

}        
 #endif /* DEPOSITREQUEST_H */
    

