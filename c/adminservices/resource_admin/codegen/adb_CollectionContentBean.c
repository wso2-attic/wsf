/*
* Copyright 2009-2010 WSO2, Inc. http://wso2.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


        /**
         * adb_CollectionContentBean.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_CollectionContentBean.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = CollectionContentBean
                 * Namespace URI = http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd
                 * Namespace Prefix = ns3
                 */
           


        struct adb_CollectionContentBean
        {
            axis2_char_t *property_Type;

            int property_childCount;

                
                axis2_bool_t is_valid_childCount;
            axutil_array_list_t* property_childPaths;

                
                axis2_bool_t is_valid_childPaths;
            axutil_array_list_t* property_collectionTypes;

                
                axis2_bool_t is_valid_collectionTypes;
            axis2_char_t* property_pathWithVersion;

                
                axis2_bool_t is_valid_pathWithVersion;
            axutil_array_list_t* property_remoteInstances;

                
                axis2_bool_t is_valid_remoteInstances;
            axis2_bool_t property_versionView;

                
                axis2_bool_t is_valid_versionView;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_CollectionContentBean_set_childCount_nil(
                        adb_CollectionContentBean_t* _CollectionContentBean,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_CollectionContentBean_set_versionView_nil(
                        adb_CollectionContentBean_t* _CollectionContentBean,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_CollectionContentBean_t* AXIS2_CALL
        adb_CollectionContentBean_create(
            const axutil_env_t *env)
        {
            adb_CollectionContentBean_t *_CollectionContentBean = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _CollectionContentBean = (adb_CollectionContentBean_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_CollectionContentBean_t));

            if(NULL == _CollectionContentBean)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_CollectionContentBean, 0, sizeof(adb_CollectionContentBean_t));

            _CollectionContentBean->property_Type = axutil_strdup(env, "adb_CollectionContentBean");
            _CollectionContentBean->is_valid_childCount  = AXIS2_FALSE;
            _CollectionContentBean->property_childPaths  = NULL;
                  _CollectionContentBean->is_valid_childPaths  = AXIS2_FALSE;
            _CollectionContentBean->property_collectionTypes  = NULL;
                  _CollectionContentBean->is_valid_collectionTypes  = AXIS2_FALSE;
            _CollectionContentBean->property_pathWithVersion  = NULL;
                  _CollectionContentBean->is_valid_pathWithVersion  = AXIS2_FALSE;
            _CollectionContentBean->property_remoteInstances  = NULL;
                  _CollectionContentBean->is_valid_remoteInstances  = AXIS2_FALSE;
            _CollectionContentBean->is_valid_versionView  = AXIS2_FALSE;
            

            return _CollectionContentBean;
        }

        adb_CollectionContentBean_t* AXIS2_CALL
        adb_CollectionContentBean_create_with_values(
            const axutil_env_t *env,
                int _childCount,
                axutil_array_list_t* _childPaths,
                axutil_array_list_t* _collectionTypes,
                axis2_char_t* _pathWithVersion,
                axutil_array_list_t* _remoteInstances,
                axis2_bool_t _versionView)
        {
            adb_CollectionContentBean_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_CollectionContentBean_create(env);

            
              status = adb_CollectionContentBean_set_childCount(
                                     adb_obj,
                                     env,
                                     _childCount);
              if(status == AXIS2_FAILURE) {
                  adb_CollectionContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CollectionContentBean_set_childPaths(
                                     adb_obj,
                                     env,
                                     _childPaths);
              if(status == AXIS2_FAILURE) {
                  adb_CollectionContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CollectionContentBean_set_collectionTypes(
                                     adb_obj,
                                     env,
                                     _collectionTypes);
              if(status == AXIS2_FAILURE) {
                  adb_CollectionContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CollectionContentBean_set_pathWithVersion(
                                     adb_obj,
                                     env,
                                     _pathWithVersion);
              if(status == AXIS2_FAILURE) {
                  adb_CollectionContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CollectionContentBean_set_remoteInstances(
                                     adb_obj,
                                     env,
                                     _remoteInstances);
              if(status == AXIS2_FAILURE) {
                  adb_CollectionContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CollectionContentBean_set_versionView(
                                     adb_obj,
                                     env,
                                     _versionView);
              if(status == AXIS2_FAILURE) {
                  adb_CollectionContentBean_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        int AXIS2_CALL
                adb_CollectionContentBean_free_popping_value(
                        adb_CollectionContentBean_t* _CollectionContentBean,
                        const axutil_env_t *env)
                {
                    int value;

                    
                    
                    value = _CollectionContentBean->property_childCount;

                    adb_CollectionContentBean_free(_CollectionContentBean, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_free(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _CollectionContentBean,
                env,
                "adb_CollectionContentBean");
            
        }

        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_free_obj(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);

            if (_CollectionContentBean->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _CollectionContentBean->property_Type);
            }

            adb_CollectionContentBean_reset_childCount(_CollectionContentBean, env);
            adb_CollectionContentBean_reset_childPaths(_CollectionContentBean, env);
            adb_CollectionContentBean_reset_collectionTypes(_CollectionContentBean, env);
            adb_CollectionContentBean_reset_pathWithVersion(_CollectionContentBean, env);
            adb_CollectionContentBean_reset_remoteInstances(_CollectionContentBean, env);
            adb_CollectionContentBean_reset_versionView(_CollectionContentBean, env);
            

            if(_CollectionContentBean)
            {
                AXIS2_FREE(env->allocator, _CollectionContentBean);
                _CollectionContentBean = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_deserialize(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _CollectionContentBean,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_CollectionContentBean");
            
        }

        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_deserialize_obj(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
          
              void *element = NULL;
           
             const axis2_char_t* text_value = NULL;
             axutil_qname_t *qname = NULL;
          
               int i = 0;
               axutil_array_list_t *arr_list = NULL;
            
               int sequence_broken = 0;
               axiom_node_t *tmp_node = NULL;
            
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               axis2_bool_t is_early_node_valid = AXIS2_TRUE;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for CollectionContentBean : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building childCount element
                      */
                     
                     
                     
                                   current_node = first_node;
                                   is_early_node_valid = AXIS2_FALSE;
                                   
                                   
                                    while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                    {
                                        current_node = axiom_node_get_next_sibling(current_node, env);
                                    }
                                    if(current_node != NULL)
                                    {
                                        current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                        qname = axiom_element_get_qname(current_element, env, current_node);
                                    }
                                   
                                 element_qname = axutil_qname_create(env, "childCount", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            status = adb_CollectionContentBean_set_childCount(_CollectionContentBean, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element childCount");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for childCount ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building childPaths array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building childPaths element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "childPaths", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                  
                               
                               for (i = 0, sequence_broken = 0, current_node = (is_early_node_valid?axiom_node_get_next_sibling(current_node, env):current_node); !sequence_broken && current_node != NULL;) 
                                             
                               {
                                  if(axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                  {
                                     current_node =axiom_node_get_next_sibling(current_node, env);
                                     is_early_node_valid = AXIS2_FALSE;
                                     continue;
                                  }
                                  
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                  qname = axiom_element_get_qname(current_element, env, current_node);

                                  if ( 
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          text_value = axiom_element_get_text(current_element, env, current_node);
                                          if(text_value != NULL)
                                          {
                                              axutil_array_list_add_at(arr_list, env, i, axutil_strdup(env, text_value));
                                          }
                                          
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for childPaths ");
                                         if(element_qname)
                                         {
                                            axutil_qname_free(element_qname, env);
                                         }
                                         if(arr_list)
                                         {
                                            axutil_array_list_free(arr_list, env);
                                         }
                                         return AXIS2_FAILURE;
                                     }

                                     i ++;
                                    current_node = axiom_node_get_next_sibling(current_node, env);
                                  }
                                  else
                                  {
                                      is_early_node_valid = AXIS2_FALSE;
                                      sequence_broken = 1;
                                  }
                                  
                               }

                               
                                   if (i < 0)
                                   {
                                     /* found element out of order */
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "childPaths (@minOccurs = '0') only have %d elements", i);
                                     if(element_qname)
                                     {
                                        axutil_qname_free(element_qname, env);
                                     }
                                     if(arr_list)
                                     {
                                        axutil_array_list_free(arr_list, env);
                                     }
                                     return AXIS2_FAILURE;
                                   }
                               

                               if(0 == axutil_array_list_size(arr_list,env))
                               {
                                    axutil_array_list_free(arr_list, env);
                               }
                               else
                               {
                                    status = adb_CollectionContentBean_set_childPaths(_CollectionContentBean, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building collectionTypes array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building collectionTypes element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "collectionTypes", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                  
                               
                               for (i = 0, sequence_broken = 0, current_node = (is_early_node_valid?axiom_node_get_next_sibling(current_node, env):current_node); !sequence_broken && current_node != NULL;) 
                                             
                               {
                                  if(axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                  {
                                     current_node =axiom_node_get_next_sibling(current_node, env);
                                     is_early_node_valid = AXIS2_FALSE;
                                     continue;
                                  }
                                  
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                  qname = axiom_element_get_qname(current_element, env, current_node);

                                  if ( 
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          text_value = axiom_element_get_text(current_element, env, current_node);
                                          if(text_value != NULL)
                                          {
                                              axutil_array_list_add_at(arr_list, env, i, axutil_strdup(env, text_value));
                                          }
                                          
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for collectionTypes ");
                                         if(element_qname)
                                         {
                                            axutil_qname_free(element_qname, env);
                                         }
                                         if(arr_list)
                                         {
                                            axutil_array_list_free(arr_list, env);
                                         }
                                         return AXIS2_FAILURE;
                                     }

                                     i ++;
                                    current_node = axiom_node_get_next_sibling(current_node, env);
                                  }
                                  else
                                  {
                                      is_early_node_valid = AXIS2_FALSE;
                                      sequence_broken = 1;
                                  }
                                  
                               }

                               
                                   if (i < 0)
                                   {
                                     /* found element out of order */
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "collectionTypes (@minOccurs = '0') only have %d elements", i);
                                     if(element_qname)
                                     {
                                        axutil_qname_free(element_qname, env);
                                     }
                                     if(arr_list)
                                     {
                                        axutil_array_list_free(arr_list, env);
                                     }
                                     return AXIS2_FAILURE;
                                   }
                               

                               if(0 == axutil_array_list_size(arr_list,env))
                               {
                                    axutil_array_list_free(arr_list, env);
                               }
                               else
                               {
                                    status = adb_CollectionContentBean_set_collectionTypes(_CollectionContentBean, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building pathWithVersion element
                      */
                     
                     
                     
                                    /*
                                     * because elements are ordered this works fine
                                     */
                                  
                                   
                                   if(current_node != NULL && is_early_node_valid)
                                   {
                                       current_node = axiom_node_get_next_sibling(current_node, env);
                                       
                                       
                                        while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                        {
                                            current_node = axiom_node_get_next_sibling(current_node, env);
                                        }
                                        if(current_node != NULL)
                                        {
                                            current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                            qname = axiom_element_get_qname(current_element, env, current_node);
                                        }
                                       
                                   }
                                   is_early_node_valid = AXIS2_FALSE;
                                 
                                 element_qname = axutil_qname_create(env, "pathWithVersion", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            status = adb_CollectionContentBean_set_pathWithVersion(_CollectionContentBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for pathWithVersion ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building remoteInstances array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building remoteInstances element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "remoteInstances", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                  
                               
                               for (i = 0, sequence_broken = 0, current_node = (is_early_node_valid?axiom_node_get_next_sibling(current_node, env):current_node); !sequence_broken && current_node != NULL;) 
                                             
                               {
                                  if(axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                  {
                                     current_node =axiom_node_get_next_sibling(current_node, env);
                                     is_early_node_valid = AXIS2_FALSE;
                                     continue;
                                  }
                                  
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                  qname = axiom_element_get_qname(current_element, env, current_node);

                                  if ( 
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          text_value = axiom_element_get_text(current_element, env, current_node);
                                          if(text_value != NULL)
                                          {
                                              axutil_array_list_add_at(arr_list, env, i, axutil_strdup(env, text_value));
                                          }
                                          
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for remoteInstances ");
                                         if(element_qname)
                                         {
                                            axutil_qname_free(element_qname, env);
                                         }
                                         if(arr_list)
                                         {
                                            axutil_array_list_free(arr_list, env);
                                         }
                                         return AXIS2_FAILURE;
                                     }

                                     i ++;
                                    current_node = axiom_node_get_next_sibling(current_node, env);
                                  }
                                  else
                                  {
                                      is_early_node_valid = AXIS2_FALSE;
                                      sequence_broken = 1;
                                  }
                                  
                               }

                               
                                   if (i < 0)
                                   {
                                     /* found element out of order */
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "remoteInstances (@minOccurs = '0') only have %d elements", i);
                                     if(element_qname)
                                     {
                                        axutil_qname_free(element_qname, env);
                                     }
                                     if(arr_list)
                                     {
                                        axutil_array_list_free(arr_list, env);
                                     }
                                     return AXIS2_FAILURE;
                                   }
                               

                               if(0 == axutil_array_list_size(arr_list,env))
                               {
                                    axutil_array_list_free(arr_list, env);
                               }
                               else
                               {
                                    status = adb_CollectionContentBean_set_remoteInstances(_CollectionContentBean, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building versionView element
                      */
                     
                     
                     
                                    /*
                                     * because elements are ordered this works fine
                                     */
                                  
                                   
                                   if(current_node != NULL && is_early_node_valid)
                                   {
                                       current_node = axiom_node_get_next_sibling(current_node, env);
                                       
                                       
                                        while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                        {
                                            current_node = axiom_node_get_next_sibling(current_node, env);
                                        }
                                        if(current_node != NULL)
                                        {
                                            current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                            qname = axiom_element_get_qname(current_element, env, current_node);
                                        }
                                       
                                   }
                                   is_early_node_valid = AXIS2_FALSE;
                                 
                                 element_qname = axutil_qname_create(env, "versionView", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            if (!axutil_strcasecmp(text_value , "true"))
                                            {
                                                status = adb_CollectionContentBean_set_versionView(_CollectionContentBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_CollectionContentBean_set_versionView(_CollectionContentBean, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element versionView");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for versionView ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_CollectionContentBean_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_CollectionContentBean_declare_parent_namespaces(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_CollectionContentBean_serialize(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_CollectionContentBean == NULL)
            {
                return adb_CollectionContentBean_serialize_obj(
                    _CollectionContentBean, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _CollectionContentBean, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_CollectionContentBean");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_CollectionContentBean_serialize_obj(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
             axis2_char_t *string_to_stream;
            
         
         axiom_node_t* current_node = NULL;
         int tag_closed = 0;
         
         axis2_char_t* xsi_prefix = NULL;
         
         axis2_char_t* type_attrib = NULL;
         axiom_namespace_t* xsi_ns = NULL;
         axiom_attribute_t* xsi_type_attri = NULL;
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
                axis2_bool_t ns_already_defined;
            
               int i = 0;
               int count = 0;
               void *element = NULL;
             
                    axis2_char_t text_value_1[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_2;
                    axis2_char_t *text_value_2_temp;
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
                    axis2_char_t text_value_6[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, NULL);
            
            
                    current_node = parent;
                    data_source = (axiom_data_source_t *)axiom_node_get_data_element(current_node, env);
                    if (!data_source)
                        return NULL;
                    stream = axiom_data_source_get_stream(data_source, env); /* assume parent is of type data source */
                    if (!stream)
                        return NULL;
                  
            if(!parent_tag_closed)
            {
            
              
 
              if(!(xsi_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING)))
              {
                  /* it is better to stick with the standard prefix */
                  xsi_prefix = (axis2_char_t*)axutil_strdup(env, "xsi");
                  
                  axutil_hash_set(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING, xsi_prefix);

                  if(parent_element)
                  {
                        axiom_namespace_t *element_ns = NULL;
                        element_ns = axiom_namespace_create(env, "http://www.w3.org/2001/XMLSchema-instance",
                                                            xsi_prefix);
                        axiom_element_declare_namespace_assume_param_ownership(parent_element, env, element_ns);
                  }
              }
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"CollectionContentBean\"", NULL);
              axutil_stream_write(stream, env, type_attrib, axutil_strlen(type_attrib));

              AXIS2_FREE(env->allocator, type_attrib);
                
              string_to_stream = ">"; 
              axutil_stream_write(stream, env, string_to_stream, axutil_strlen(string_to_stream));
              tag_closed = 1;
            
            }
            else {
              /* if the parent tag closed we would be able to declare the type directly on the parent element */ 
              if(!(xsi_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING)))
              {
                  /* it is better to stick with the standard prefix */
                  xsi_prefix = (axis2_char_t*)axutil_strdup(env, "xsi");
                  
                  axutil_hash_set(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING, xsi_prefix);

                  if(parent_element)
                  {
                        axiom_namespace_t *element_ns = NULL;
                        element_ns = axiom_namespace_create(env, "http://www.w3.org/2001/XMLSchema-instance",
                                                            xsi_prefix);
                        axiom_element_declare_namespace_assume_param_ownership(parent_element, env, element_ns);
                  }
              }
            }
            xsi_ns = axiom_namespace_create (env,
                                 "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "CollectionContentBean", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CollectionContentBean->is_valid_childCount)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("childCount"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("childCount")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing childCount element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%schildCount>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%schildCount>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_1, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _CollectionContentBean->property_childCount);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CollectionContentBean->is_valid_childPaths)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("childPaths"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("childPaths")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing childPaths array
                      */
                     if (_CollectionContentBean->property_childPaths != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%schildPaths>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%schildPaths>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_CollectionContentBean->property_childPaths, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_CollectionContentBean->property_childPaths, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing childPaths element
                      */

                    
                    
                           text_value_2 = (axis2_char_t*)element;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_2_temp = axutil_xml_quote_string(env, text_value_2, AXIS2_TRUE);
                           if (text_value_2_temp)
                           {
                               axutil_stream_write(stream, env, text_value_2_temp, axutil_strlen(text_value_2_temp));
                               AXIS2_FREE(env->allocator, text_value_2_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CollectionContentBean->is_valid_collectionTypes)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("collectionTypes"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("collectionTypes")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing collectionTypes array
                      */
                     if (_CollectionContentBean->property_collectionTypes != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%scollectionTypes>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%scollectionTypes>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_CollectionContentBean->property_collectionTypes, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_CollectionContentBean->property_collectionTypes, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing collectionTypes element
                      */

                    
                    
                           text_value_3 = (axis2_char_t*)element;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_3_temp = axutil_xml_quote_string(env, text_value_3, AXIS2_TRUE);
                           if (text_value_3_temp)
                           {
                               axutil_stream_write(stream, env, text_value_3_temp, axutil_strlen(text_value_3_temp));
                               AXIS2_FREE(env->allocator, text_value_3_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CollectionContentBean->is_valid_pathWithVersion)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("pathWithVersion"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("pathWithVersion")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing pathWithVersion element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spathWithVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spathWithVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _CollectionContentBean->property_pathWithVersion;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_4_temp = axutil_xml_quote_string(env, text_value_4, AXIS2_TRUE);
                           if (text_value_4_temp)
                           {
                               axutil_stream_write(stream, env, text_value_4_temp, axutil_strlen(text_value_4_temp));
                               AXIS2_FREE(env->allocator, text_value_4_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CollectionContentBean->is_valid_remoteInstances)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("remoteInstances"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("remoteInstances")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing remoteInstances array
                      */
                     if (_CollectionContentBean->property_remoteInstances != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%sremoteInstances>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sremoteInstances>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_CollectionContentBean->property_remoteInstances, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_CollectionContentBean->property_remoteInstances, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing remoteInstances element
                      */

                    
                    
                           text_value_5 = (axis2_char_t*)element;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_5_temp = axutil_xml_quote_string(env, text_value_5, AXIS2_TRUE);
                           if (text_value_5_temp)
                           {
                               axutil_stream_write(stream, env, text_value_5_temp, axutil_strlen(text_value_5_temp));
                               AXIS2_FREE(env->allocator, text_value_5_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_5, axutil_strlen(text_value_5));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CollectionContentBean->is_valid_versionView)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("versionView"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("versionView")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing versionView element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sversionView>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sversionView>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_6, (_CollectionContentBean->property_versionView)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_6, axutil_strlen(text_value_6));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for childCount by  Property Number 1
             */
            int AXIS2_CALL
            adb_CollectionContentBean_get_property1(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env)
            {
                return adb_CollectionContentBean_get_childCount(_CollectionContentBean,
                                             env);
            }

            /**
             * getter for childCount.
             */
            int AXIS2_CALL
            adb_CollectionContentBean_get_childCount(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, (int)0);
                  

                return _CollectionContentBean->property_childCount;
             }

            /**
             * setter for childCount
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_set_childCount(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env,
                    const int  arg_childCount)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
                
                if(_CollectionContentBean->is_valid_childCount &&
                        arg_childCount == _CollectionContentBean->property_childCount)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_CollectionContentBean_reset_childCount(_CollectionContentBean, env);

                _CollectionContentBean->property_childCount = arg_childCount;
                        _CollectionContentBean->is_valid_childCount = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for childCount
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_reset_childCount(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
               

               _CollectionContentBean->is_valid_childCount = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether childCount is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CollectionContentBean_is_childCount_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_TRUE);
               
               return !_CollectionContentBean->is_valid_childCount;
           }

           /**
            * Set childCount to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_set_childCount_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               return adb_CollectionContentBean_reset_childCount(_CollectionContentBean, env);
           }

           

            /**
             * Getter for childPaths by  Property Number 2
             */
            axutil_array_list_t* AXIS2_CALL
            adb_CollectionContentBean_get_property2(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env)
            {
                return adb_CollectionContentBean_get_childPaths(_CollectionContentBean,
                                             env);
            }

            /**
             * getter for childPaths.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_CollectionContentBean_get_childPaths(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, NULL);
                  

                return _CollectionContentBean->property_childPaths;
             }

            /**
             * setter for childPaths
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_set_childPaths(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_childPaths)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
                
                if(_CollectionContentBean->is_valid_childPaths &&
                        arg_childPaths == _CollectionContentBean->property_childPaths)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_childPaths, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "childPaths has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_childPaths, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_CollectionContentBean_reset_childPaths(_CollectionContentBean, env);

                
                if(NULL == arg_childPaths)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _CollectionContentBean->property_childPaths = arg_childPaths;
                        if(non_nil_exists)
                        {
                            _CollectionContentBean->is_valid_childPaths = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of childPaths.
             */
            axis2_char_t* AXIS2_CALL
            adb_CollectionContentBean_get_childPaths_at(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, NULL);
                  

                if(_CollectionContentBean->property_childPaths == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_CollectionContentBean->property_childPaths, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of childPaths.
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_set_childPaths_at(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_childPaths)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
                
                if( _CollectionContentBean->is_valid_childPaths &&
                    _CollectionContentBean->property_childPaths &&
                
                    arg_childPaths == (axis2_char_t*)axutil_array_list_get(_CollectionContentBean->property_childPaths, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_childPaths)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_CollectionContentBean->property_childPaths != NULL)
                        {
                            size = axutil_array_list_size(_CollectionContentBean->property_childPaths, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_CollectionContentBean->property_childPaths, env, i))
                                {
                                    non_nil_count ++;
                                    non_nil_exists = AXIS2_TRUE;
                                    if(non_nil_count >= 0)
                                    {
                                        break;
                                    }
                                }
                            }

                        
                        }
                    }
                  

                if(_CollectionContentBean->property_childPaths == NULL)
                {
                    _CollectionContentBean->property_childPaths = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_CollectionContentBean->property_childPaths, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _CollectionContentBean->is_valid_childPaths = AXIS2_FALSE;
                        axutil_array_list_set(_CollectionContentBean->property_childPaths , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_CollectionContentBean->property_childPaths , env, i, axutil_strdup(env, arg_childPaths));
                  _CollectionContentBean->is_valid_childPaths = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to childPaths.
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_add_childPaths(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_childPaths)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);

                
                    if(NULL == arg_childPaths)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_CollectionContentBean->property_childPaths == NULL)
                {
                    _CollectionContentBean->property_childPaths = axutil_array_list_create(env, 10);
                }
                if(_CollectionContentBean->property_childPaths == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for childPaths");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_CollectionContentBean->property_childPaths , env, axutil_strdup(env, arg_childPaths));
                  _CollectionContentBean->is_valid_childPaths = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the childPaths array.
             */
            int AXIS2_CALL
            adb_CollectionContentBean_sizeof_childPaths(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, -1);
                if(_CollectionContentBean->property_childPaths == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_CollectionContentBean->property_childPaths, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_remove_childPaths_at(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env, int i)
            {
                return adb_CollectionContentBean_set_childPaths_nil_at(_CollectionContentBean, env, i);
            }

            

           /**
            * resetter for childPaths
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_reset_childPaths(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
               

               
                  if (_CollectionContentBean->property_childPaths != NULL)
                  {
                      count = axutil_array_list_size(_CollectionContentBean->property_childPaths, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_CollectionContentBean->property_childPaths, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_CollectionContentBean->property_childPaths, env);
                  }
                _CollectionContentBean->is_valid_childPaths = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether childPaths is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CollectionContentBean_is_childPaths_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_TRUE);
               
               return !_CollectionContentBean->is_valid_childPaths;
           }

           /**
            * Set childPaths to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_set_childPaths_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               return adb_CollectionContentBean_reset_childPaths(_CollectionContentBean, env);
           }

           
           /**
            * Check whether childPaths is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_CollectionContentBean_is_childPaths_nil_at(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_TRUE);
               
               return (_CollectionContentBean->is_valid_childPaths == AXIS2_FALSE ||
                        NULL == _CollectionContentBean->property_childPaths || 
                        NULL == axutil_array_list_get(_CollectionContentBean->property_childPaths, env, i));
           }

           /**
            * Set childPaths to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_set_childPaths_nil_at(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);

                if(_CollectionContentBean->property_childPaths == NULL ||
                            _CollectionContentBean->is_valid_childPaths == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_CollectionContentBean->property_childPaths, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_CollectionContentBean->property_childPaths, env, i))
                        {
                            k ++;
                            non_nil_exists = AXIS2_TRUE;
                            if( k >= 0)
                            {
                                break;
                            }
                        }
                    }
                }
                

                if( k < 0)
                {
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of childPaths is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_CollectionContentBean->property_childPaths == NULL)
                {
                    _CollectionContentBean->is_valid_childPaths = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_CollectionContentBean->property_childPaths, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _CollectionContentBean->is_valid_childPaths = AXIS2_FALSE;
                        axutil_array_list_set(_CollectionContentBean->property_childPaths , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_CollectionContentBean->property_childPaths , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for collectionTypes by  Property Number 3
             */
            axutil_array_list_t* AXIS2_CALL
            adb_CollectionContentBean_get_property3(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env)
            {
                return adb_CollectionContentBean_get_collectionTypes(_CollectionContentBean,
                                             env);
            }

            /**
             * getter for collectionTypes.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_CollectionContentBean_get_collectionTypes(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, NULL);
                  

                return _CollectionContentBean->property_collectionTypes;
             }

            /**
             * setter for collectionTypes
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_set_collectionTypes(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_collectionTypes)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
                
                if(_CollectionContentBean->is_valid_collectionTypes &&
                        arg_collectionTypes == _CollectionContentBean->property_collectionTypes)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_collectionTypes, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "collectionTypes has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_collectionTypes, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_CollectionContentBean_reset_collectionTypes(_CollectionContentBean, env);

                
                if(NULL == arg_collectionTypes)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _CollectionContentBean->property_collectionTypes = arg_collectionTypes;
                        if(non_nil_exists)
                        {
                            _CollectionContentBean->is_valid_collectionTypes = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of collectionTypes.
             */
            axis2_char_t* AXIS2_CALL
            adb_CollectionContentBean_get_collectionTypes_at(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, NULL);
                  

                if(_CollectionContentBean->property_collectionTypes == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_CollectionContentBean->property_collectionTypes, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of collectionTypes.
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_set_collectionTypes_at(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_collectionTypes)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
                
                if( _CollectionContentBean->is_valid_collectionTypes &&
                    _CollectionContentBean->property_collectionTypes &&
                
                    arg_collectionTypes == (axis2_char_t*)axutil_array_list_get(_CollectionContentBean->property_collectionTypes, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_collectionTypes)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_CollectionContentBean->property_collectionTypes != NULL)
                        {
                            size = axutil_array_list_size(_CollectionContentBean->property_collectionTypes, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_CollectionContentBean->property_collectionTypes, env, i))
                                {
                                    non_nil_count ++;
                                    non_nil_exists = AXIS2_TRUE;
                                    if(non_nil_count >= 0)
                                    {
                                        break;
                                    }
                                }
                            }

                        
                        }
                    }
                  

                if(_CollectionContentBean->property_collectionTypes == NULL)
                {
                    _CollectionContentBean->property_collectionTypes = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_CollectionContentBean->property_collectionTypes, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _CollectionContentBean->is_valid_collectionTypes = AXIS2_FALSE;
                        axutil_array_list_set(_CollectionContentBean->property_collectionTypes , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_CollectionContentBean->property_collectionTypes , env, i, axutil_strdup(env, arg_collectionTypes));
                  _CollectionContentBean->is_valid_collectionTypes = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to collectionTypes.
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_add_collectionTypes(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_collectionTypes)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);

                
                    if(NULL == arg_collectionTypes)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_CollectionContentBean->property_collectionTypes == NULL)
                {
                    _CollectionContentBean->property_collectionTypes = axutil_array_list_create(env, 10);
                }
                if(_CollectionContentBean->property_collectionTypes == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for collectionTypes");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_CollectionContentBean->property_collectionTypes , env, axutil_strdup(env, arg_collectionTypes));
                  _CollectionContentBean->is_valid_collectionTypes = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the collectionTypes array.
             */
            int AXIS2_CALL
            adb_CollectionContentBean_sizeof_collectionTypes(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, -1);
                if(_CollectionContentBean->property_collectionTypes == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_CollectionContentBean->property_collectionTypes, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_remove_collectionTypes_at(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env, int i)
            {
                return adb_CollectionContentBean_set_collectionTypes_nil_at(_CollectionContentBean, env, i);
            }

            

           /**
            * resetter for collectionTypes
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_reset_collectionTypes(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
               

               
                  if (_CollectionContentBean->property_collectionTypes != NULL)
                  {
                      count = axutil_array_list_size(_CollectionContentBean->property_collectionTypes, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_CollectionContentBean->property_collectionTypes, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_CollectionContentBean->property_collectionTypes, env);
                  }
                _CollectionContentBean->is_valid_collectionTypes = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether collectionTypes is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CollectionContentBean_is_collectionTypes_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_TRUE);
               
               return !_CollectionContentBean->is_valid_collectionTypes;
           }

           /**
            * Set collectionTypes to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_set_collectionTypes_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               return adb_CollectionContentBean_reset_collectionTypes(_CollectionContentBean, env);
           }

           
           /**
            * Check whether collectionTypes is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_CollectionContentBean_is_collectionTypes_nil_at(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_TRUE);
               
               return (_CollectionContentBean->is_valid_collectionTypes == AXIS2_FALSE ||
                        NULL == _CollectionContentBean->property_collectionTypes || 
                        NULL == axutil_array_list_get(_CollectionContentBean->property_collectionTypes, env, i));
           }

           /**
            * Set collectionTypes to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_set_collectionTypes_nil_at(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);

                if(_CollectionContentBean->property_collectionTypes == NULL ||
                            _CollectionContentBean->is_valid_collectionTypes == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_CollectionContentBean->property_collectionTypes, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_CollectionContentBean->property_collectionTypes, env, i))
                        {
                            k ++;
                            non_nil_exists = AXIS2_TRUE;
                            if( k >= 0)
                            {
                                break;
                            }
                        }
                    }
                }
                

                if( k < 0)
                {
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of collectionTypes is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_CollectionContentBean->property_collectionTypes == NULL)
                {
                    _CollectionContentBean->is_valid_collectionTypes = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_CollectionContentBean->property_collectionTypes, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _CollectionContentBean->is_valid_collectionTypes = AXIS2_FALSE;
                        axutil_array_list_set(_CollectionContentBean->property_collectionTypes , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_CollectionContentBean->property_collectionTypes , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for pathWithVersion by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_CollectionContentBean_get_property4(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env)
            {
                return adb_CollectionContentBean_get_pathWithVersion(_CollectionContentBean,
                                             env);
            }

            /**
             * getter for pathWithVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_CollectionContentBean_get_pathWithVersion(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, NULL);
                  

                return _CollectionContentBean->property_pathWithVersion;
             }

            /**
             * setter for pathWithVersion
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_set_pathWithVersion(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_pathWithVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
                
                if(_CollectionContentBean->is_valid_pathWithVersion &&
                        arg_pathWithVersion == _CollectionContentBean->property_pathWithVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_CollectionContentBean_reset_pathWithVersion(_CollectionContentBean, env);

                
                if(NULL == arg_pathWithVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _CollectionContentBean->property_pathWithVersion = (axis2_char_t *)axutil_strdup(env, arg_pathWithVersion);
                        if(NULL == _CollectionContentBean->property_pathWithVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for pathWithVersion");
                            return AXIS2_FAILURE;
                        }
                        _CollectionContentBean->is_valid_pathWithVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for pathWithVersion
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_reset_pathWithVersion(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
               

               
            
                
                if(_CollectionContentBean->property_pathWithVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _CollectionContentBean->property_pathWithVersion);
                     _CollectionContentBean->property_pathWithVersion = NULL;
                }
            
                
                
                _CollectionContentBean->is_valid_pathWithVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether pathWithVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CollectionContentBean_is_pathWithVersion_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_TRUE);
               
               return !_CollectionContentBean->is_valid_pathWithVersion;
           }

           /**
            * Set pathWithVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_set_pathWithVersion_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               return adb_CollectionContentBean_reset_pathWithVersion(_CollectionContentBean, env);
           }

           

            /**
             * Getter for remoteInstances by  Property Number 5
             */
            axutil_array_list_t* AXIS2_CALL
            adb_CollectionContentBean_get_property5(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env)
            {
                return adb_CollectionContentBean_get_remoteInstances(_CollectionContentBean,
                                             env);
            }

            /**
             * getter for remoteInstances.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_CollectionContentBean_get_remoteInstances(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, NULL);
                  

                return _CollectionContentBean->property_remoteInstances;
             }

            /**
             * setter for remoteInstances
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_set_remoteInstances(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_remoteInstances)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
                
                if(_CollectionContentBean->is_valid_remoteInstances &&
                        arg_remoteInstances == _CollectionContentBean->property_remoteInstances)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_remoteInstances, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "remoteInstances has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_remoteInstances, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_CollectionContentBean_reset_remoteInstances(_CollectionContentBean, env);

                
                if(NULL == arg_remoteInstances)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _CollectionContentBean->property_remoteInstances = arg_remoteInstances;
                        if(non_nil_exists)
                        {
                            _CollectionContentBean->is_valid_remoteInstances = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of remoteInstances.
             */
            axis2_char_t* AXIS2_CALL
            adb_CollectionContentBean_get_remoteInstances_at(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, NULL);
                  

                if(_CollectionContentBean->property_remoteInstances == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_CollectionContentBean->property_remoteInstances, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of remoteInstances.
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_set_remoteInstances_at(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_remoteInstances)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
                
                if( _CollectionContentBean->is_valid_remoteInstances &&
                    _CollectionContentBean->property_remoteInstances &&
                
                    arg_remoteInstances == (axis2_char_t*)axutil_array_list_get(_CollectionContentBean->property_remoteInstances, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_remoteInstances)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_CollectionContentBean->property_remoteInstances != NULL)
                        {
                            size = axutil_array_list_size(_CollectionContentBean->property_remoteInstances, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_CollectionContentBean->property_remoteInstances, env, i))
                                {
                                    non_nil_count ++;
                                    non_nil_exists = AXIS2_TRUE;
                                    if(non_nil_count >= 0)
                                    {
                                        break;
                                    }
                                }
                            }

                        
                        }
                    }
                  

                if(_CollectionContentBean->property_remoteInstances == NULL)
                {
                    _CollectionContentBean->property_remoteInstances = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_CollectionContentBean->property_remoteInstances, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _CollectionContentBean->is_valid_remoteInstances = AXIS2_FALSE;
                        axutil_array_list_set(_CollectionContentBean->property_remoteInstances , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_CollectionContentBean->property_remoteInstances , env, i, axutil_strdup(env, arg_remoteInstances));
                  _CollectionContentBean->is_valid_remoteInstances = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to remoteInstances.
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_add_remoteInstances(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_remoteInstances)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);

                
                    if(NULL == arg_remoteInstances)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_CollectionContentBean->property_remoteInstances == NULL)
                {
                    _CollectionContentBean->property_remoteInstances = axutil_array_list_create(env, 10);
                }
                if(_CollectionContentBean->property_remoteInstances == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for remoteInstances");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_CollectionContentBean->property_remoteInstances , env, axutil_strdup(env, arg_remoteInstances));
                  _CollectionContentBean->is_valid_remoteInstances = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the remoteInstances array.
             */
            int AXIS2_CALL
            adb_CollectionContentBean_sizeof_remoteInstances(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, -1);
                if(_CollectionContentBean->property_remoteInstances == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_CollectionContentBean->property_remoteInstances, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_remove_remoteInstances_at(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env, int i)
            {
                return adb_CollectionContentBean_set_remoteInstances_nil_at(_CollectionContentBean, env, i);
            }

            

           /**
            * resetter for remoteInstances
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_reset_remoteInstances(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
               

               
                  if (_CollectionContentBean->property_remoteInstances != NULL)
                  {
                      count = axutil_array_list_size(_CollectionContentBean->property_remoteInstances, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_CollectionContentBean->property_remoteInstances, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_CollectionContentBean->property_remoteInstances, env);
                  }
                _CollectionContentBean->is_valid_remoteInstances = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether remoteInstances is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CollectionContentBean_is_remoteInstances_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_TRUE);
               
               return !_CollectionContentBean->is_valid_remoteInstances;
           }

           /**
            * Set remoteInstances to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_set_remoteInstances_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               return adb_CollectionContentBean_reset_remoteInstances(_CollectionContentBean, env);
           }

           
           /**
            * Check whether remoteInstances is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_CollectionContentBean_is_remoteInstances_nil_at(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_TRUE);
               
               return (_CollectionContentBean->is_valid_remoteInstances == AXIS2_FALSE ||
                        NULL == _CollectionContentBean->property_remoteInstances || 
                        NULL == axutil_array_list_get(_CollectionContentBean->property_remoteInstances, env, i));
           }

           /**
            * Set remoteInstances to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_set_remoteInstances_nil_at(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);

                if(_CollectionContentBean->property_remoteInstances == NULL ||
                            _CollectionContentBean->is_valid_remoteInstances == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_CollectionContentBean->property_remoteInstances, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_CollectionContentBean->property_remoteInstances, env, i))
                        {
                            k ++;
                            non_nil_exists = AXIS2_TRUE;
                            if( k >= 0)
                            {
                                break;
                            }
                        }
                    }
                }
                

                if( k < 0)
                {
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of remoteInstances is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_CollectionContentBean->property_remoteInstances == NULL)
                {
                    _CollectionContentBean->is_valid_remoteInstances = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_CollectionContentBean->property_remoteInstances, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _CollectionContentBean->is_valid_remoteInstances = AXIS2_FALSE;
                        axutil_array_list_set(_CollectionContentBean->property_remoteInstances , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_CollectionContentBean->property_remoteInstances , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for versionView by  Property Number 6
             */
            axis2_bool_t AXIS2_CALL
            adb_CollectionContentBean_get_property6(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env)
            {
                return adb_CollectionContentBean_get_versionView(_CollectionContentBean,
                                             env);
            }

            /**
             * getter for versionView.
             */
            axis2_bool_t AXIS2_CALL
            adb_CollectionContentBean_get_versionView(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, (axis2_bool_t)0);
                  

                return _CollectionContentBean->property_versionView;
             }

            /**
             * setter for versionView
             */
            axis2_status_t AXIS2_CALL
            adb_CollectionContentBean_set_versionView(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_versionView)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
                
                if(_CollectionContentBean->is_valid_versionView &&
                        arg_versionView == _CollectionContentBean->property_versionView)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_CollectionContentBean_reset_versionView(_CollectionContentBean, env);

                _CollectionContentBean->property_versionView = arg_versionView;
                        _CollectionContentBean->is_valid_versionView = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for versionView
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_reset_versionView(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_FAILURE);
               

               _CollectionContentBean->is_valid_versionView = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether versionView is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CollectionContentBean_is_versionView_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CollectionContentBean, AXIS2_TRUE);
               
               return !_CollectionContentBean->is_valid_versionView;
           }

           /**
            * Set versionView to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CollectionContentBean_set_versionView_nil(
                   adb_CollectionContentBean_t* _CollectionContentBean,
                   const axutil_env_t *env)
           {
               return adb_CollectionContentBean_reset_versionView(_CollectionContentBean, env);
           }

           

