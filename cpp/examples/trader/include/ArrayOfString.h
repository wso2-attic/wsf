

        #ifndef ARRAYOFSTRING_H
        #define ARRAYOFSTRING_H

       /**
        * ArrayOfString.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  ArrayOfString class
        */

        namespace org_wso2_www_types{
            class ArrayOfString;
        }
        

        

        #include <stdio.h>
        #include <OMElement.h>
        #include <ServiceClient.h>
        #include <ADBDefines.h>

namespace org_wso2_www_types
{
        
        

        class ArrayOfString {

        private:
             std::vector<std::string*>* property_Value;

                
                bool isValidValue;
            

        /*** Private methods ***/
          

        bool WSF_CALL
        setValueNil();
            



        /******************************* public functions *********************************/

        public:

        /**
         * Constructor for class ArrayOfString
         */

        ArrayOfString();

        /**
         * Destructor ArrayOfString
         */
        ~ArrayOfString();


       

        /**
         * Constructor for creating ArrayOfString
         * @param 
         * @param Value std::vector<std::string*>*
         * @return newly created ArrayOfString object
         */
        ArrayOfString(std::vector<std::string*>* arg_Value);
        
        
        /********************************** Class get set methods **************************************/
        /******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/
        

        /**
         * Getter for value. Deprecated for array types, Use getValueAt instead
         * @return Array of std::strings.
         */
        WSF_EXTERN std::vector<std::string*>* WSF_CALL
        getValue();

        /**
         * Setter for value.Deprecated for array types, Use setValueAt
         * or addValue instead.
         * @param arg_Value Array of std::strings.
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        setValue(std::vector<std::string*>*  arg_Value);

        /**
         * Re setter for value
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        resetValue();
        
        /****************************** Get Set methods for Arrays **********************************/
        /************ Array Specific Operations: get_at, set_at, add, remove_at, sizeof *****************/

        /**
         * E.g. use of get_at, set_at, add and sizeof
         *
         * for(i = 0; i < adb_element->sizeofProperty(); i ++ )
         * {
         *     // Getting ith value to property_object variable
         *     property_object = adb_element->getPropertyAt(i);
         *
         *     // Setting ith value from property_object variable
         *     adb_element->setPropertyAt(i, property_object);
         *
         *     // Appending the value to the end of the array from property_object variable
         *     adb_element->addProperty(property_object);
         *
         *     // Removing the ith value from an array
         *     adb_element->removePropertyAt(i);
         *     
         * }
         *
         */

        
        
        /**
         * Get the ith element of value.
        * @param i index of the item to be obtained
         * @return ith std::string of the array
         */
        WSF_EXTERN std::string WSF_CALL
        getValueAt(int i);

        /**
         * Set the ith element of value. (If the ith already exist, it will be replaced)
         * @param i index of the item to return
         * @param arg_Value element to set std::string to the array
         * @return ith std::string of the array
         */
        WSF_EXTERN bool WSF_CALL
        setValueAt(int i,
                const std::string arg_Value);


        /**
         * Add to value.
         * @param arg_Value element to add std::string to the array
         * @return true on success, false otherwise.
         */
        WSF_EXTERN bool WSF_CALL
        addValue(
            const std::string arg_Value);

        /**
         * Get the size of the value array.
         * @return the size of the value array.
         */
        WSF_EXTERN int WSF_CALL
        sizeofValue();

        /**
         * Remove the ith element of value.
         * @param i index of the item to remove
         * @return true on success, false otherwise.
         */
        WSF_EXTERN bool WSF_CALL
        removeValueAt(int i);

        


        /******************************* Checking and Setting NIL values *********************************/
        /* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether value is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        isValueNil();


        

        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) < minOccurs
         */
        
        /**
         * Check whether value is Nill at position i
         * @param i index of the item to return.
         * @return true if the value is Nil at position i, false otherwise
         */
        bool WSF_CALL
        isValueNilAt(int i);
 
       
        /**
         * Set value to NILL at the  position i.
         * @param i . The index of the item to be set Nill.
         * @return true on success, false otherwise.
         */
        bool WSF_CALL
        setValueNilAt(int i);

        

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
         * @param ArrayOfString_om_node node to serialize from
         * @param ArrayOfString_om_element parent element to serialize from
         * @param tag_closed Whether the parent tag is closed or not
         * @param namespaces hash of namespace uris to prefixes
         * @param next_ns_index an int which contains the next namespace index
         * @return axiom_node_t on success,NULL otherwise.
         */
        axiom_node_t* WSF_CALL
        serialize(axiom_node_t* ArrayOfString_om_node, axiom_element_t *ArrayOfString_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the ArrayOfString is a particle class (E.g. group, inner sequence)
         * @return true if this is a particle class, false otherwise.
         */
        bool WSF_CALL
        isParticle();



        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

      
        

        /**
         * Getter for value by property number (1)
         * @return Array of std::strings.
         */

        std::vector<std::string*>* WSF_CALL
        getProperty1();

    

};

}        
 #endif /* ARRAYOFSTRING_H */
    

