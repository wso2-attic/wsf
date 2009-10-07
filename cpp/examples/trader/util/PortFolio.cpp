

        /**
         * PortFolio.cpp
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "PortFolio.h"
        #include <Environment.h>
        #include <WSFError.h>


        using namespace wso2wsf;
        using namespace std;
        
        using namespace org_wso2_www_types;
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = PortFolio
                 * Namespace URI = http://www.wso2.org/types
                 * Namespace Prefix = ns1
                 */
           org_wso2_www_types::PortFolio::PortFolio()
        {

        
                property_PortFolioItem  = NULL;
              
            isValidPortFolioItem  = false;
        
        }

       org_wso2_www_types::PortFolio::PortFolio(std::vector<org_wso2_www_types::PortFolioItem*>* arg_PortFolioItem)
        {
             
               property_PortFolioItem  = NULL;
             
            isValidPortFolioItem  = true;
            
                    property_PortFolioItem = arg_PortFolioItem;
            
        }
        org_wso2_www_types::PortFolio::~PortFolio()
        {

        }

        

        bool WSF_CALL
        org_wso2_www_types::PortFolio::deserialize(axiom_node_t** dp_parent,bool *dp_is_early_node_valid, bool dont_care_minoccurs)
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
                     * building PortFolioItem array
                     */
                       std::vector<org_wso2_www_types::PortFolioItem*>* arr_list =new std::vector<org_wso2_www_types::PortFolioItem*>();
                   

                     
                     /*
                      * building portFolioItem element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(Environment::getEnv(), "portFolioItem", NULL, NULL);
                                  
                               
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

                                  if (axutil_qname_equals(element_qname, Environment::getEnv(), mqname) || !axutil_strcmp("portFolioItem", axiom_element_get_localname(current_element, Environment::getEnv())))
                                  {
                                  
                                      is_early_node_valid = true;
                                      
                                     org_wso2_www_types::PortFolioItem* element = new org_wso2_www_types::PortFolioItem();
                                          
                                          status =  element->deserialize(&current_node, &is_early_node_valid, false);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
					  WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "failed in building element portFolioItem ");
                                          }
                                          else
                                          {
                                            arr_list->push_back(element);
                                            
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "failed in setting the value for portFolioItem ");
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
                                     WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"portFolioItem (@minOccurs = '0') only have %d elements", i);
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
                                    status = setPortFolioItem(arr_list);
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
          org_wso2_www_types::PortFolio::isParticle()
          {
            
                 return false;
              
          }


          void WSF_CALL
          org_wso2_www_types::PortFolio::declareParentNamespaces(
                    axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* WSF_CALL
	org_wso2_www_types::PortFolio::serialize(axiom_node_t *parent, 
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
                      

                   if (!isValidPortFolioItem)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("portFolioItem"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("portFolioItem")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing PortFolioItem array
                      */
                     if (property_PortFolioItem != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%sportFolioItem",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sportFolioItem>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = property_PortFolioItem->size();
                         for(i = 0; i < count; i++)
                         {
                            org_wso2_www_types::PortFolioItem* element = (*property_PortFolioItem)[i];

                            if(NULL == element) 
                            {
                                continue;
                            }

                    
                     
                     /*
                      * parsing portFolioItem element
                      */

                    
                     
                            if(!element->isParticle())
                            {
                                axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                            }
                            element->serialize(current_node, parent_element,
                                                                                 element->isParticle() || false, namespaces, next_ns_index);
                            
                            if(!element->isParticle())
                            {
                                axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
                     AXIS2_FREE(Environment::getEnv()->allocator,start_input_str);
                     AXIS2_FREE(Environment::getEnv()->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for portFolioItem by  Property Number 1
             */
            std::vector<org_wso2_www_types::PortFolioItem*>* WSF_CALL
            org_wso2_www_types::PortFolio::getProperty1()
            {
                return getPortFolioItem();
            }

            /**
             * getter for portFolioItem.
             */
            std::vector<org_wso2_www_types::PortFolioItem*>* WSF_CALL
            org_wso2_www_types::PortFolio::getPortFolioItem()
             {
                return property_PortFolioItem;
             }

            /**
             * setter for portFolioItem
             */
            bool WSF_CALL
            org_wso2_www_types::PortFolio::setPortFolioItem(
                    std::vector<org_wso2_www_types::PortFolioItem*>*  arg_PortFolioItem)
             {
                
                 int size = 0;
                 int i = 0;
                 bool non_nil_exists = false;
                

                if(isValidPortFolioItem &&
                        arg_PortFolioItem == property_PortFolioItem)
                {
                    
                    return true;
                }

                
                 size = arg_PortFolioItem->size();
                 
                 if (size < 0)
                 {
                     WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"portFolioItem has less than minOccurs(0)");
                     return false;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != (*arg_PortFolioItem)[i])
                     {
                         non_nil_exists = true;
                         break;
                     }
                 }

                 

                
                resetPortFolioItem();

                
                    if(NULL == arg_PortFolioItem)
                         
                {
                    /* We are already done */
                    return true;
                }
                
                        property_PortFolioItem = arg_PortFolioItem;
                        if(non_nil_exists)
                        {
                            isValidPortFolioItem = true;
                        }
                        
                    
                return true;
             }

            
            /**
             * Get ith element of portFolioItem.
             */
            org_wso2_www_types::PortFolioItem* WSF_CALL
            org_wso2_www_types::PortFolio::getPortFolioItemAt(int i)
            {
                org_wso2_www_types::PortFolioItem* ret_val;
                if(property_PortFolioItem == NULL)
                {
                    return (org_wso2_www_types::PortFolioItem*)0;
                }
                ret_val =   (*property_PortFolioItem)[i];
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of portFolioItem.
             */
           bool WSF_CALL
            org_wso2_www_types::PortFolio::setPortFolioItemAt(int i,
                    org_wso2_www_types::PortFolioItem* arg_PortFolioItem)
            {
                 org_wso2_www_types::PortFolioItem* element;
                int size = 0;

                int non_nil_count;
                bool non_nil_exists = false;

                 

                if( isValidPortFolioItem &&
                    property_PortFolioItem &&
                  
                    arg_PortFolioItem == (*property_PortFolioItem)[i])
                  
                 {
                    
                    return AXIS2_SUCCESS; 
                }

                   
                     non_nil_exists = true;
                  

                if(property_PortFolioItem == NULL)
                {
                    property_PortFolioItem = new std::vector<org_wso2_www_types::PortFolioItem*>();
                }
                else{
                /* check whether there already exist an element */
                element = (*property_PortFolioItem)[i];
                }

                
                        if(NULL != element)
                        {
                          
                          
                          
                                delete element;
                             
                        }
                        
                    
                    if(!non_nil_exists)
                    {
                        
                        isValidPortFolioItem = true;
                        (*property_PortFolioItem)[i]= NULL;
                        
                        return AXIS2_SUCCESS;
                    }
                
                    (*property_PortFolioItem)[i] = arg_PortFolioItem;
                  

               isValidPortFolioItem = true;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to portFolioItem.
             */
            bool WSF_CALL
            org_wso2_www_types::PortFolio::addPortFolioItem(
                    org_wso2_www_types::PortFolioItem* arg_PortFolioItem)
             {

                
                    if( NULL == arg_PortFolioItem
                     )
                    {
                      
                           return true; 
                        
                    }
                  

                if(property_PortFolioItem == NULL)
                {
                    property_PortFolioItem = new std::vector<org_wso2_www_types::PortFolioItem*>();
                }
              
               property_PortFolioItem->push_back(arg_PortFolioItem);
              
                isValidPortFolioItem = true;
                return true;
             }

            /**
             * Get the size of the portFolioItem array.
             */
            int WSF_CALL
            org_wso2_www_types::PortFolio::sizeofPortFolioItem()
            {

                if(property_PortFolioItem == NULL)
                {
                    return 0;
                }
                return property_PortFolioItem->size();
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            bool WSF_CALL
            org_wso2_www_types::PortFolio::removePortFolioItemAt(int i)
            {
                return setPortFolioItemNilAt(i);
            }

            

           /**
            * resetter for portFolioItem
            */
           bool WSF_CALL
           org_wso2_www_types::PortFolio::resetPortFolioItem()
           {
               int i = 0;
               int count = 0;


               
                if (property_PortFolioItem != NULL)
                {
                  std::vector<org_wso2_www_types::PortFolioItem*>::iterator it =  property_PortFolioItem->begin();
                  for( ; it <  property_PortFolioItem->end() ; ++it)
                  {
                     org_wso2_www_types::PortFolioItem* element = *it;
                
            
                

                if(element != NULL)
                {
                   
                   
                         delete  element;
                     

                   }

                
                
                
               }

             }
                
                    if(NULL != property_PortFolioItem)
                 delete property_PortFolioItem;
                
               isValidPortFolioItem = false; 
               return true;
           }

           /**
            * Check whether portFolioItem is nill
            */
           bool WSF_CALL
           org_wso2_www_types::PortFolio::isPortFolioItemNil()
           {
               return !isValidPortFolioItem;
           }

           /**
            * Set portFolioItem to nill (currently the same as reset)
            */
           bool WSF_CALL
           org_wso2_www_types::PortFolio::setPortFolioItemNil()
           {
               return resetPortFolioItem();
           }

           
           /**
            * Check whether portFolioItem is nill at i
            */
           bool WSF_CALL
           org_wso2_www_types::PortFolio::isPortFolioItemNilAt(int i)
           {
               return (isValidPortFolioItem == false ||
                       NULL == property_PortFolioItem ||
                     NULL == (*property_PortFolioItem)[i]);
            }

           /**
            * Set portFolioItem to nil at i
            */
           bool WSF_CALL
           org_wso2_www_types::PortFolio::setPortFolioItemNilAt(int i)
           {
                int size = 0;
                int j;
                bool non_nil_exists = false;

                int k = 0;

                if(property_PortFolioItem == NULL ||
                            isValidPortFolioItem == false)
                {
                    
                    non_nil_exists = false;
                }
                else
                {
                    size = property_PortFolioItem->size();
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != (*property_PortFolioItem)[i])
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
                       WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "Size of the array of portFolioItem is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(property_PortFolioItem == NULL)
                {
                    isValidPortFolioItem = false;
                    
                    return true;
                }
                 
                 /* check whether there already exist an element */
                 org_wso2_www_types::PortFolioItem* element = (*property_PortFolioItem)[i];
                if(NULL != element)
                {
                  
                  
                  
                        delete element;
                     
                 }
                 
                    if(!non_nil_exists)
                    {
                        
                        isValidPortFolioItem = false;
                        (*property_PortFolioItem)[i] = NULL;
                        return AXIS2_SUCCESS;
                    }
                

                
                (*property_PortFolioItem)[i] = NULL;
                
                return AXIS2_SUCCESS;

           }

           

