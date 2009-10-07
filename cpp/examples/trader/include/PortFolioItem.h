

        #ifndef PORTFOLIOITEM_H
        #define PORTFOLIOITEM_H

       /**
        * PortFolioItem.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  PortFolioItem class
        */

        namespace org_wso2_www_types{
            class PortFolioItem;
        }
        

        

        #include <stdio.h>
        #include <OMElement.h>
        #include <ServiceClient.h>
        #include <ADBDefines.h>

namespace org_wso2_www_types
{
        
        

        class PortFolioItem {

        private:
             std::string property_Symbol;

                
                bool isValidSymbol;
            int property_Amount;

                
                bool isValidAmount;
            

        /*** Private methods ***/
          

        bool WSF_CALL
        setSymbolNil();
            

        bool WSF_CALL
        setAmountNil();
            



        /******************************* public functions *********************************/

        public:

        /**
         * Constructor for class PortFolioItem
         */

        PortFolioItem();

        /**
         * Destructor PortFolioItem
         */
        ~PortFolioItem();


       

        /**
         * Constructor for creating PortFolioItem
         * @param 
         * @param Symbol std::string
         * @param Amount int
         * @return newly created PortFolioItem object
         */
        PortFolioItem(std::string arg_Symbol,int arg_Amount);
        
        
        /********************************** Class get set methods **************************************/
        
        

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
         * Getter for amount. 
         * @return int*
         */
        WSF_EXTERN int WSF_CALL
        getAmount();

        /**
         * Setter for amount.
         * @param arg_Amount int*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setAmount(const int  arg_Amount);

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
         * Check whether symbol is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isSymbolNil();


        

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
         * @param PortFolioItem_om_node node to serialize from
         * @param PortFolioItem_om_element parent element to serialize from
         * @param tag_closed Whether the parent tag is closed or not
         * @param namespaces hash of namespace uris to prefixes
         * @param next_ns_index an int which contains the next namespace index
         * @return axiom_node_t on success,NULL otherwise.
         */
        axiom_node_t* WSF_CALL
        serialize(axiom_node_t* PortFolioItem_om_node, axiom_element_t *PortFolioItem_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the PortFolioItem is a particle class (E.g. group, inner sequence)
         * @return true if this is a particle class, false otherwise.
         */
        bool WSF_CALL
        isParticle();



        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

      
        

        /**
         * Getter for symbol by property number (1)
         * @return std::string
         */

        std::string WSF_CALL
        getProperty1();

    
        

        /**
         * Getter for amount by property number (2)
         * @return int
         */

        int WSF_CALL
        getProperty2();

    

};

}        
 #endif /* PORTFOLIOITEM_H */
    

