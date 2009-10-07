

        #ifndef SELLREQUEST_H
        #define SELLREQUEST_H

       /**
        * SellRequest.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  SellRequest class
        */

        namespace org_wso2_www_types{
            class SellRequest;
        }
        

        
        #include <axutil_qname.h>
        

        #include <stdio.h>
        #include <OMElement.h>
        #include <ServiceClient.h>
        #include <ADBDefines.h>

namespace org_wso2_www_types
{
        
        

        class SellRequest {

        private:
             
                axutil_qname_t* qname;
            std::string property_Userid;

                
                bool isValidUserid;
            std::string property_Password;

                
                bool isValidPassword;
            std::string property_Symbol;

                
                bool isValidSymbol;
            int property_Qty;

                
                bool isValidQty;
            

        /*** Private methods ***/
          

        bool WSF_CALL
        setUseridNil();
            

        bool WSF_CALL
        setPasswordNil();
            

        bool WSF_CALL
        setSymbolNil();
            

        bool WSF_CALL
        setQtyNil();
            



        /******************************* public functions *********************************/

        public:

        /**
         * Constructor for class SellRequest
         */

        SellRequest();

        /**
         * Destructor SellRequest
         */
        ~SellRequest();


       

        /**
         * Constructor for creating SellRequest
         * @param 
         * @param Userid std::string
         * @param Password std::string
         * @param Symbol std::string
         * @param Qty int
         * @return newly created SellRequest object
         */
        SellRequest(std::string arg_Userid,std::string arg_Password,std::string arg_Symbol,int arg_Qty);
        
        
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
         * Getter for symbol. 
         * @return std::string*
         */
        WSF_EXTERN std::string WSF_CALL
        getSymbol();

        /**
         * Setter for symbol.
         * @param arg_Symbol std::string*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setSymbol(const std::string  arg_Symbol);

        /**
         * Re setter for symbol
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetSymbol();
        
        

        /**
         * Getter for qty. 
         * @return int*
         */
        WSF_EXTERN int WSF_CALL
        getQty();

        /**
         * Setter for qty.
         * @param arg_Qty int*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setQty(const int  arg_Qty);

        /**
         * Re setter for qty
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetQty();
        


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


        

        /**
         * Check whether password is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isPasswordNil();


        

        /**
         * Check whether symbol is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isSymbolNil();


        

        /**
         * Check whether qty is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isQtyNil();


        

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
         * @param SellRequest_om_node node to serialize from
         * @param SellRequest_om_element parent element to serialize from
         * @param tag_closed Whether the parent tag is closed or not
         * @param namespaces hash of namespace uris to prefixes
         * @param next_ns_index an int which contains the next namespace index
         * @return axiom_node_t on success,NULL otherwise.
         */
        axiom_node_t* WSF_CALL
        serialize(axiom_node_t* SellRequest_om_node, axiom_element_t *SellRequest_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the SellRequest is a particle class (E.g. group, inner sequence)
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

    
        

        /**
         * Getter for password by property number (2)
         * @return std::string
         */

        std::string WSF_CALL
        getProperty2();

    
        

        /**
         * Getter for symbol by property number (3)
         * @return std::string
         */

        std::string WSF_CALL
        getProperty3();

    
        

        /**
         * Getter for qty by property number (4)
         * @return int
         */

        int WSF_CALL
        getProperty4();

    

};

}        
 #endif /* SELLREQUEST_H */
    

