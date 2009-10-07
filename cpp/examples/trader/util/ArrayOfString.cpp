

        /**
         * ArrayOfString.cpp
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "ArrayOfString.h"
        #include <Environment.h>
        #include <WSFError.h>


        using namespace wso2wsf;
        using namespace std;
        
        using namespace org_wso2_www_types;
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = ArrayOfString
                 * Namespace URI = http://www.wso2.org/types
                 * Namespace Prefix = ns1
                 */
           org_wso2_www_types::ArrayOfString::ArrayOfString()
        {

        
                property_Value  = NULL;
              
            isValidValue  = false;
        
        }

       org_wso2_www_types::ArrayOfString::ArrayOfString(std::vector<std::string*>* arg_Value)
        {
             
               property_Value  = NULL;
             
            isValidValue  = true;
            
                    property_Value = arg_Value;
            
        }
        org_wso2_www_types::ArrayOfString::~ArrayOfString()
        {

        }

        

        bool WSF_CALL
        org_wso2_www_types::ArrayOfString::deserialize(axiom_node_t** dp_parent,bool *dp_is_early_node_valid, bool dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          bool status = AXIS2_SUCCESS;
           
         const axis2_char_t* text_value = NULL;
         axutil_qname_t *mqname = NULL;
          
               int i = 0;
            
               int sequence_broken = 0;
               axiom_node_t *tmp_node = NULL;
            
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               bool is_early_node_valid = true;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
              
              while(parent && axiom_node_get_node_type(parent, Environment::getEnv()) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, Environment::getEnv());
              }
              if (NULL == parent)
              {   
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, Environment::getEnv());
                      
                    
                       { 
                    /*
                     * building Value array
                     */
                       std::vector<std::string*>* arr_list =new std::vector<std::string*>();
                   

                     
                     /*
                      * building value element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(Environment::getEnv(), "value", NULL, NULL);
                                  
                               
                               for (i = 0, sequence_broken = 0, current_node = first_node; !sequence_broken && current_node != NULL;)
                                             
                               {
                                  if(axiom_node_get_node_type(current_node, Environment::getEnv()) != AXIOM_ELEMENT)
                                  {
                                     current_node =axiom_node_get_next_sibling(current_node, Environment::getEnv());
                                     is_early_node_valid = false;
                                     continue;
                                  }
                                  
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, Environment::getEnv());
                                  mqname = axiom_element_get_qname(current_element, Environment::getEnv(), current_node);

                                  if (axutil_qname_equals(element_qname, Environment::getEnv(), mqname) || !axutil_strcmp("value", axiom_element_get_localname(current_element, Environment::getEnv())))
                                  {
                                  
                                      is_early_node_valid = true;
                                      
                                     
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              arr_list->push_back(new string(text_value));
                                          }
                                          
                                          else
                                          {
                                              /*
                                               * axis2_qname_t *qname = NULL;
                                               * axiom_attribute_t *the_attri = NULL;
                                               * 
                                               * qname = axutil_qname_create(Environment::getEnv(), "nil", "http://www.w3.org/2001/XMLSchema-instance", "xsi");
                                               * the_attri = axiom_element_get_attribute(current_element, Environment::getEnv(), qname);
                                               */
                                           
                                              /* currently thereis a bug in the axiom_element_get_attribute, so we have to go to this bad method */
                                             
                                              axiom_attribute_t *the_attri = NULL;
                                              axis2_char_t *attrib_text = NULL;
                                              axutil_hash_t *attribute_hash = NULL;
                                             
                                              attribute_hash = axiom_element_get_all_attributes(current_element, Environment::getEnv());
                                             
                                              attrib_text = NULL;
                                              if(attribute_hash)
                                              {
                                                   axutil_hash_index_t *hi;
                                                   void *val;
                                                   const void *key;
                                             
                                                   for (hi = axutil_hash_first(attribute_hash, Environment::getEnv()); hi; hi = axutil_hash_next(Environment::getEnv(), hi))
                                                   {
                                                       axutil_hash_this(hi, &key, NULL, &val);
                                                       
                                                       if(strstr((axis2_char_t*)key, "nil|http://www.w3.org/2001/XMLSchema-instance"))
                                                       {
                                                           the_attri = (axiom_attribute_t*)val;
                                                           break;
                                                       }
                                                   }
                                              }
                                             
                                              if(the_attri)
                                              {
                                                  attrib_text = axiom_attribute_get_value(the_attri, Environment::getEnv());
                                              }
                                              else
                                              {
                                                  /* this is hoping that attribute is stored in "http://www.w3.org/2001/XMLSchema-instance", this happnes when name is in default namespace */
                                                  attrib_text = axiom_element_get_attribute_value_by_name(current_element, Environment::getEnv(), "nil");
                                              }
                                             
                                              if(attrib_text && 0 == axutil_strcmp(attrib_text, "1"))
                                              {
					      WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element value");
                                                  status = AXIS2_FAILURE;
                                              }
                                              else
                                              {
                                                  /* after all, we found this is a empty string */
                                                  arr_list->push_back(new string(""));
                                              }
                                          }
                                          
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "failed in setting the value for value ");
                                         if(element_qname)
                                         {
                                            axutil_qname_free(element_qname, Environment::getEnv());
                                         }
                                         if(arr_list)
                                         {
                                            delete arr_list;
                                         }
                                         return false;
                                     }

                                     i++;
                                    current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv());
                                  }
                                  else
                                  {
                                      is_early_node_valid = false;
                                      sequence_broken = 1;
                                  }
                                  
                               }

                               
                                   if (i < 0)
                                   {
                                     /* found element out of order */
                                     WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"value (@minOccurs = '0') only have %d elements", i);
                                     if(element_qname)
                                     {
                                        axutil_qname_free(element_qname, Environment::getEnv());
                                     }
                                     if(arr_list)
                                     {
                                        delete arr_list;
                                     }
                                     return false;
                                   }
                               

                               if(0 == arr_list->size())
                               {
                                    delete arr_list;
                               }
                               else
                               {
                                    status = setValue(arr_list);
                               }

                              
                            } 
                        
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, Environment::getEnv());
                     element_qname = NULL;
                  }
                 
          return status;
       }

          bool WSF_CALL
          org_wso2_www_types::ArrayOfString::isParticle()
          {
            
                 return false;
              
          }


          void WSF_CALL
          org_wso2_www_types::ArrayOfString::declareParentNamespaces(
                    axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* WSF_CALL
	org_wso2_www_types::ArrayOfString::serialize(axiom_node_t *parent, 
			axiom_element_t *parent_element, 
			int parent_tag_closed, 
			axutil_hash_t *namespaces, 
			int *next_ns_index)
        {
            
            
             axis2_char_t *string_to_stream;
            
         
         axiom_node_t *current_node = NULL;
         int tag_closed = 0;

         
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
            
               int i = 0;
               int count = 0;
               void *element = NULL;
             
                    axis2_char_t *text_value_1;
                    axis2_char_t *text_value_1_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            
                    current_node = parent;
                    data_source = (axiom_data_source_t *)axiom_node_get_data_element(current_node, Environment::getEnv());
                    if (!data_source)
                        return NULL;
                    stream = axiom_data_source_get_stream(data_source, Environment::getEnv()); /* assume parent is of type data source */
                    if (!stream)
                        return NULL;
                  
            if(!parent_tag_closed)
            {
            
              string_to_stream = ">"; 
              axutil_stream_write(stream, Environment::getEnv(), string_to_stream, axutil_strlen(string_to_stream));
              tag_closed = 1;
            
            }
            
                       p_prefix = NULL;
                      

                   if (!isValidValue)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("value"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("value")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing Value array
                      */
                     if (property_Value != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%svalue>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%svalue>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = property_Value->size();
                         for(i = 0; i < count; i++)
                         {
                            std::string* element = (*property_Value)[i];

                            if(NULL == element) 
                            {
                                continue;
                            }

                    
                     
                     /*
                      * parsing value element
                      */

                    
                    
                           text_value_1 = (axis2_char_t*)(*element).c_str();
                           
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           
                            
                           text_value_1_temp = axutil_xml_quote_string(Environment::getEnv(), text_value_1, true);
                           if (text_value_1_temp)
                           {
                               axutil_stream_write(stream, Environment::getEnv(), text_value_1_temp, axutil_strlen(text_value_1_temp));
                               AXIS2_FREE(Environment::getEnv()->allocator, text_value_1_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, Environment::getEnv(), text_value_1, axutil_strlen(text_value_1));
                           }
                           
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           
                         }
                     }
                   
                     
                     AXIS2_FREE(Environment::getEnv()->allocator,start_input_str);
                     AXIS2_FREE(Environment::getEnv()->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for value by  Property Number 1
             */
            std::vector<std::string*>* WSF_CALL
            org_wso2_www_types::ArrayOfString::getProperty1()
            {
                return getValue();
            }

            /**
             * getter for value.
             */
            std::vector<std::string*>* WSF_CALL
            org_wso2_www_types::ArrayOfString::getValue()
             {
                return property_Value;
             }

            /**
             * setter for value
             */
            bool WSF_CALL
            org_wso2_www_types::ArrayOfString::setValue(
                    std::vector<std::string*>*  arg_Value)
             {
                
                 int size = 0;
                 int i = 0;
                 bool non_nil_exists = false;
                

                if(isValidValue &&
                        arg_Value == property_Value)
                {
                    
                    return true;
                }

                
                 size = arg_Value->size();
                 
                 if (size < 0)
                 {
                     WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"value has less than minOccurs(0)");
                     return false;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != (*arg_Value)[i])
                     {
                         non_nil_exists = true;
                         break;
                     }
                 }

                 

                
                resetValue();

                
                    if(NULL == arg_Value)
                         
                {
                    /* We are already done */
                    return true;
                }
                
                        property_Value = arg_Value;
                        if(non_nil_exists)
                        {
                            isValidValue = true;
                        }
                        
                    
                return true;
             }

            
            /**
             * Get ith element of value.
             */
            std::string WSF_CALL
            org_wso2_www_types::ArrayOfString::getValueAt(int i)
            {
                std::string* ret_val;
                if(property_Value == NULL)
                {
                    return (std::string)0;
                }
                ret_val =   (*property_Value)[i];
                
                    if(ret_val)
                    {
                        return *ret_val;
                    }
                    return (std::string)0;
                  
            }

            /**
             * Set the ith element of value.
             */
           bool WSF_CALL
            org_wso2_www_types::ArrayOfString::setValueAt(int i,
                    const std::string arg_Value)
            {
                 std::string* element;
                int size = 0;

                bool non_nil_exists = false;

                 

                if( isValidValue &&
                    property_Value &&
                  
                    arg_Value == *((*property_Value)[i]))
                  
                 {
                    
                    return AXIS2_SUCCESS; 
                }

                   
                     non_nil_exists = true;
                  

                if(property_Value == NULL)
                {
                    property_Value = new std::vector<std::string*>();
                }
                else{
                /* check whether there already exist an element */
                element = (*property_Value)[i];
                }

                
                    if(!non_nil_exists)
                    {
                        
                        isValidValue = true;
                        (*property_Value)[i]= NULL;
                        
                        return AXIS2_SUCCESS;
                    }
                
                    (*property_Value)[i]= new string(arg_Value.c_str());
                  

               isValidValue = true;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to value.
             */
            bool WSF_CALL
            org_wso2_www_types::ArrayOfString::addValue(
                    const std::string arg_Value)
             {

                
                    if(
                      arg_Value.empty()
                       
                     )
                    {
                      
                           return true; 
                        
                    }
                  

                if(property_Value == NULL)
                {
                    property_Value = new std::vector<std::string*>();
                }
              
               property_Value->push_back(new string(arg_Value.c_str()));
              
                isValidValue = true;
                return true;
             }

            /**
             * Get the size of the value array.
             */
            int WSF_CALL
            org_wso2_www_types::ArrayOfString::sizeofValue()
            {

                if(property_Value == NULL)
                {
                    return 0;
                }
                return property_Value->size();
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            bool WSF_CALL
            org_wso2_www_types::ArrayOfString::removeValueAt(int i)
            {
                return setValueNilAt(i);
            }

            

           /**
            * resetter for value
            */
           bool WSF_CALL
           org_wso2_www_types::ArrayOfString::resetValue()
           {
               int i = 0;
               int count = 0;


               
                    if(NULL != property_Value)
                 delete property_Value;
                
               isValidValue = false; 
               return true;
           }

           /**
            * Check whether value is nill
            */
           bool WSF_CALL
           org_wso2_www_types::ArrayOfString::isValueNil()
           {
               return !isValidValue;
           }

           /**
            * Set value to nill (currently the same as reset)
            */
           bool WSF_CALL
           org_wso2_www_types::ArrayOfString::setValueNil()
           {
               return resetValue();
           }

           
           /**
            * Check whether value is nill at i
            */
           bool WSF_CALL
           org_wso2_www_types::ArrayOfString::isValueNilAt(int i)
           {
               return (isValidValue == false ||
                       NULL == property_Value ||
                     NULL == (*property_Value)[i]);
            }

           /**
            * Set value to nil at i
            */
           bool WSF_CALL
           org_wso2_www_types::ArrayOfString::setValueNilAt(int i)
           {
                int size = 0;
                int j;
                bool non_nil_exists = false;

                int k = 0;

                if(property_Value == NULL ||
                            isValidValue == false)
                {
                    
                    non_nil_exists = false;
                }
                else
                {
                    size = property_Value->size();
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != (*property_Value)[i])
                        {
                            k++;
                            non_nil_exists = true;
                            if( k >= 0)
                            {
                                break;
                            }
                        }
                    }
                }
                

                if( k < 0)
                {
                       WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "Size of the array of value is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(property_Value == NULL)
                {
                    isValidValue = false;
                    
                    return true;
                }
                 
                    if(!non_nil_exists)
                    {
                        
                        isValidValue = false;
                        (*property_Value)[i] = NULL;
                        return AXIS2_SUCCESS;
                    }
                

                
                (*property_Value)[i] = NULL;
                
                return AXIS2_SUCCESS;

           }

           

