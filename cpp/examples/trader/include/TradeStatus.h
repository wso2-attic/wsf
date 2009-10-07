

        #ifndef TRADESTATUS_H
        #define TRADESTATUS_H

       /**
        * TradeStatus.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  TradeStatus class
        */

        namespace org_wso2_www_types{
            class TradeStatus;
        }
        

        

        #include <stdio.h>
        #include <OMElement.h>
        #include <ServiceClient.h>
        #include <ADBDefines.h>

namespace org_wso2_www_types
{
        
        

        class TradeStatus {

        private:
             bool property_Status;

                
                bool isValidStatus;
            std::string property_Reason;

                
                bool isValidReason;
            

        /*** Private methods ***/
          

        bool WSF_CALL
        setStatusNil();
            

        bool WSF_CALL
        setReasonNil();
            



        /******************************* public functions *********************************/

        public:

        /**
         * Constructor for class TradeStatus
         */

        TradeStatus();

        /**
         * Destructor TradeStatus
         */
        ~TradeStatus();


       

        /**
         * Constructor for creating TradeStatus
         * @param 
         * @param Status bool
         * @param Reason std::string
         * @return newly created TradeStatus object
         */
        TradeStatus(bool arg_Status,std::string arg_Reason);
        
        
        /********************************** Class get set methods **************************************/
        
        

        /**
         * Getter for status. 
         * @return bool
         */
        WSF_EXTERN bool WSF_CALL
        getStatus();

        /**
         * Setter for status.
         * @param arg_Status bool
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setStatus(bool  arg_Status);

        /**
         * Re setter for status
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetStatus();
        
        

        /**
         * Getter for reason. 
         * @return std::string*
         */
        WSF_EXTERN std::string WSF_CALL
        getReason();

        /**
         * Setter for reason.
         * @param arg_Reason std::string*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setReason(const std::string  arg_Reason);

        /**
         * Re setter for reason
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetReason();
        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether status is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isStatusNil();


        

        /**
         * Check whether reason is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isReasonNil();


        

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
         * @param TradeStatus_om_node node to serialize from
         * @param TradeStatus_om_element parent element to serialize from
         * @param tag_closed Whether the parent tag is closed or not
         * @param namespaces hash of namespace uris to prefixes
         * @param next_ns_index an int which contains the next namespace index
         * @return axiom_node_t on success,NULL otherwise.
         */
        axiom_node_t* WSF_CALL
        serialize(axiom_node_t* TradeStatus_om_node, axiom_element_t *TradeStatus_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the TradeStatus is a particle class (E.g. group, inner sequence)
         * @return true if this is a particle class, false otherwise.
         */
        bool WSF_CALL
        isParticle();



        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

      
        

        /**
         * Getter for status by property number (1)
         * @return bool
         */

        bool WSF_CALL
        getProperty1();

    
        

        /**
         * Getter for reason by property number (2)
         * @return std::string
         */

        std::string WSF_CALL
        getProperty2();

    

};

}        
 #endif /* TRADESTATUS_H */
    

