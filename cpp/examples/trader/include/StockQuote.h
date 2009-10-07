

        #ifndef STOCKQUOTE_H
        #define STOCKQUOTE_H

       /**
        * StockQuote.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  StockQuote class
        */

        namespace org_wso2_www_types{
            class StockQuote;
        }
        

        

        #include <stdio.h>
        #include <OMElement.h>
        #include <ServiceClient.h>
        #include <ADBDefines.h>

namespace org_wso2_www_types
{
        
        

        class StockQuote {

        private:
             std::string property_Name;

                
                bool isValidName;
            std::string property_Symbol;

                
                bool isValidSymbol;
            float property_Price;

                
                bool isValidPrice;
            float property_High;

                
                bool isValidHigh;
            float property_Low;

                
                bool isValidLow;
            

        /*** Private methods ***/
          

        bool WSF_CALL
        setNameNil();
            

        bool WSF_CALL
        setSymbolNil();
            

        bool WSF_CALL
        setPriceNil();
            

        bool WSF_CALL
        setHighNil();
            

        bool WSF_CALL
        setLowNil();
            



        /******************************* public functions *********************************/

        public:

        /**
         * Constructor for class StockQuote
         */

        StockQuote();

        /**
         * Destructor StockQuote
         */
        ~StockQuote();


       

        /**
         * Constructor for creating StockQuote
         * @param 
         * @param Name std::string
         * @param Symbol std::string
         * @param Price float
         * @param High float
         * @param Low float
         * @return newly created StockQuote object
         */
        StockQuote(std::string arg_Name,std::string arg_Symbol,float arg_Price,float arg_High,float arg_Low);
        
        
        /********************************** Class get set methods **************************************/
        
        

        /**
         * Getter for name. 
         * @return std::string*
         */
        WSF_EXTERN std::string WSF_CALL
        getName();

        /**
         * Setter for name.
         * @param arg_Name std::string*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setName(const std::string  arg_Name);

        /**
         * Re setter for name
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetName();
        
        

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
         * Getter for price. 
         * @return float*
         */
        WSF_EXTERN float WSF_CALL
        getPrice();

        /**
         * Setter for price.
         * @param arg_Price float*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setPrice(const float  arg_Price);

        /**
         * Re setter for price
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetPrice();
        
        

        /**
         * Getter for high. 
         * @return float*
         */
        WSF_EXTERN float WSF_CALL
        getHigh();

        /**
         * Setter for high.
         * @param arg_High float*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setHigh(const float  arg_High);

        /**
         * Re setter for high
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetHigh();
        
        

        /**
         * Getter for low. 
         * @return float*
         */
        WSF_EXTERN float WSF_CALL
        getLow();

        /**
         * Setter for low.
         * @param arg_Low float*
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setLow(const float  arg_Low);

        /**
         * Re setter for low
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetLow();
        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether name is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isNameNil();


        

        /**
         * Check whether symbol is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isSymbolNil();


        

        /**
         * Check whether price is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isPriceNil();


        

        /**
         * Check whether high is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isHighNil();


        

        /**
         * Check whether low is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isLowNil();


        

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
         * @param StockQuote_om_node node to serialize from
         * @param StockQuote_om_element parent element to serialize from
         * @param tag_closed Whether the parent tag is closed or not
         * @param namespaces hash of namespace uris to prefixes
         * @param next_ns_index an int which contains the next namespace index
         * @return axiom_node_t on success,NULL otherwise.
         */
        axiom_node_t* WSF_CALL
        serialize(axiom_node_t* StockQuote_om_node, axiom_element_t *StockQuote_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the StockQuote is a particle class (E.g. group, inner sequence)
         * @return true if this is a particle class, false otherwise.
         */
        bool WSF_CALL
        isParticle();



        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

      
        

        /**
         * Getter for name by property number (1)
         * @return std::string
         */

        std::string WSF_CALL
        getProperty1();

    
        

        /**
         * Getter for symbol by property number (2)
         * @return std::string
         */

        std::string WSF_CALL
        getProperty2();

    
        

        /**
         * Getter for price by property number (3)
         * @return float
         */

        float WSF_CALL
        getProperty3();

    
        

        /**
         * Getter for high by property number (4)
         * @return float
         */

        float WSF_CALL
        getProperty4();

    
        

        /**
         * Getter for low by property number (5)
         * @return float
         */

        float WSF_CALL
        getProperty5();

    

};

}        
 #endif /* STOCKQUOTE_H */
    

