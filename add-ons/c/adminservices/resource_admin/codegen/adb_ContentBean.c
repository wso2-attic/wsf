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
         * adb_ContentBean.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_ContentBean.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = ContentBean
                 * Namespace URI = http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd
                 * Namespace Prefix = ns3
                 */
           


        struct adb_ContentBean
        {
            axis2_char_t *property_Type;

            axis2_char_t* property_absent;

                
                axis2_bool_t is_valid_absent;
            axis2_bool_t property_collection;

                
                axis2_bool_t is_valid_collection;
            axis2_char_t* property_contentPath;

                
                axis2_bool_t is_valid_contentPath;
            axis2_bool_t property_loggedIn;

                
                axis2_bool_t is_valid_loggedIn;
            axis2_char_t* property_mediaType;

                
                axis2_bool_t is_valid_mediaType;
            axis2_char_t* property_pathWithVersion;

                
                axis2_bool_t is_valid_pathWithVersion;
            axis2_bool_t property_putAllowed;

                
                axis2_bool_t is_valid_putAllowed;
            axis2_char_t* property_realPath;

                
                axis2_bool_t is_valid_realPath;
            axis2_bool_t property_versionView;

                
                axis2_bool_t is_valid_versionView;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_ContentBean_set_collection_nil(
                        adb_ContentBean_t* _ContentBean,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ContentBean_set_loggedIn_nil(
                        adb_ContentBean_t* _ContentBean,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ContentBean_set_putAllowed_nil(
                        adb_ContentBean_t* _ContentBean,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ContentBean_set_versionView_nil(
                        adb_ContentBean_t* _ContentBean,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_ContentBean_t* AXIS2_CALL
        adb_ContentBean_create(
            const axutil_env_t *env)
        {
            adb_ContentBean_t *_ContentBean = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _ContentBean = (adb_ContentBean_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_ContentBean_t));

            if(NULL == _ContentBean)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_ContentBean, 0, sizeof(adb_ContentBean_t));

            _ContentBean->property_Type = axutil_strdup(env, "adb_ContentBean");
            _ContentBean->property_absent  = NULL;
                  _ContentBean->is_valid_absent  = AXIS2_FALSE;
            _ContentBean->is_valid_collection  = AXIS2_FALSE;
            _ContentBean->property_contentPath  = NULL;
                  _ContentBean->is_valid_contentPath  = AXIS2_FALSE;
            _ContentBean->is_valid_loggedIn  = AXIS2_FALSE;
            _ContentBean->property_mediaType  = NULL;
                  _ContentBean->is_valid_mediaType  = AXIS2_FALSE;
            _ContentBean->property_pathWithVersion  = NULL;
                  _ContentBean->is_valid_pathWithVersion  = AXIS2_FALSE;
            _ContentBean->is_valid_putAllowed  = AXIS2_FALSE;
            _ContentBean->property_realPath  = NULL;
                  _ContentBean->is_valid_realPath  = AXIS2_FALSE;
            _ContentBean->is_valid_versionView  = AXIS2_FALSE;
            

            return _ContentBean;
        }

        adb_ContentBean_t* AXIS2_CALL
        adb_ContentBean_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _absent,
                axis2_bool_t _collection,
                axis2_char_t* _contentPath,
                axis2_bool_t _loggedIn,
                axis2_char_t* _mediaType,
                axis2_char_t* _pathWithVersion,
                axis2_bool_t _putAllowed,
                axis2_char_t* _realPath,
                axis2_bool_t _versionView)
        {
            adb_ContentBean_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_ContentBean_create(env);

            
              status = adb_ContentBean_set_absent(
                                     adb_obj,
                                     env,
                                     _absent);
              if(status == AXIS2_FAILURE) {
                  adb_ContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ContentBean_set_collection(
                                     adb_obj,
                                     env,
                                     _collection);
              if(status == AXIS2_FAILURE) {
                  adb_ContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ContentBean_set_contentPath(
                                     adb_obj,
                                     env,
                                     _contentPath);
              if(status == AXIS2_FAILURE) {
                  adb_ContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ContentBean_set_loggedIn(
                                     adb_obj,
                                     env,
                                     _loggedIn);
              if(status == AXIS2_FAILURE) {
                  adb_ContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ContentBean_set_mediaType(
                                     adb_obj,
                                     env,
                                     _mediaType);
              if(status == AXIS2_FAILURE) {
                  adb_ContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ContentBean_set_pathWithVersion(
                                     adb_obj,
                                     env,
                                     _pathWithVersion);
              if(status == AXIS2_FAILURE) {
                  adb_ContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ContentBean_set_putAllowed(
                                     adb_obj,
                                     env,
                                     _putAllowed);
              if(status == AXIS2_FAILURE) {
                  adb_ContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ContentBean_set_realPath(
                                     adb_obj,
                                     env,
                                     _realPath);
              if(status == AXIS2_FAILURE) {
                  adb_ContentBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ContentBean_set_versionView(
                                     adb_obj,
                                     env,
                                     _versionView);
              if(status == AXIS2_FAILURE) {
                  adb_ContentBean_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_ContentBean_free_popping_value(
                        adb_ContentBean_t* _ContentBean,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _ContentBean->property_absent;

                    _ContentBean->property_absent = (axis2_char_t*)NULL;
                    adb_ContentBean_free(_ContentBean, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_ContentBean_free(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _ContentBean,
                env,
                "adb_ContentBean");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ContentBean_free_obj(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);

            if (_ContentBean->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _ContentBean->property_Type);
            }

            adb_ContentBean_reset_absent(_ContentBean, env);
            adb_ContentBean_reset_collection(_ContentBean, env);
            adb_ContentBean_reset_contentPath(_ContentBean, env);
            adb_ContentBean_reset_loggedIn(_ContentBean, env);
            adb_ContentBean_reset_mediaType(_ContentBean, env);
            adb_ContentBean_reset_pathWithVersion(_ContentBean, env);
            adb_ContentBean_reset_putAllowed(_ContentBean, env);
            adb_ContentBean_reset_realPath(_ContentBean, env);
            adb_ContentBean_reset_versionView(_ContentBean, env);
            

            if(_ContentBean)
            {
                AXIS2_FREE(env->allocator, _ContentBean);
                _ContentBean = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_ContentBean_deserialize(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _ContentBean,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_ContentBean");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ContentBean_deserialize_obj(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
           
             const axis2_char_t* text_value = NULL;
             axutil_qname_t *qname = NULL;
          
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               axis2_bool_t is_early_node_valid = AXIS2_TRUE;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for ContentBean : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building absent element
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
                                   
                                 element_qname = axutil_qname_create(env, "absent", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ContentBean_set_absent(_ContentBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for absent ");
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
                      * building collection element
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
                                 
                                 element_qname = axutil_qname_create(env, "collection", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ContentBean_set_collection(_ContentBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ContentBean_set_collection(_ContentBean, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element collection");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for collection ");
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
                      * building contentPath element
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
                                 
                                 element_qname = axutil_qname_create(env, "contentPath", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ContentBean_set_contentPath(_ContentBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for contentPath ");
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
                      * building loggedIn element
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
                                 
                                 element_qname = axutil_qname_create(env, "loggedIn", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ContentBean_set_loggedIn(_ContentBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ContentBean_set_loggedIn(_ContentBean, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element loggedIn");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for loggedIn ");
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
                      * building mediaType element
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
                                 
                                 element_qname = axutil_qname_create(env, "mediaType", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ContentBean_set_mediaType(_ContentBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for mediaType ");
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
                                            status = adb_ContentBean_set_pathWithVersion(_ContentBean, env,
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
                      * building putAllowed element
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
                                 
                                 element_qname = axutil_qname_create(env, "putAllowed", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ContentBean_set_putAllowed(_ContentBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ContentBean_set_putAllowed(_ContentBean, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element putAllowed");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for putAllowed ");
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
                      * building realPath element
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
                                 
                                 element_qname = axutil_qname_create(env, "realPath", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ContentBean_set_realPath(_ContentBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for realPath ");
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
                                                status = adb_ContentBean_set_versionView(_ContentBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ContentBean_set_versionView(_ContentBean, env,
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
          adb_ContentBean_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_ContentBean_declare_parent_namespaces(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_ContentBean_serialize(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_ContentBean == NULL)
            {
                return adb_ContentBean_serialize_obj(
                    _ContentBean, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _ContentBean, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_ContentBean");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_ContentBean_serialize_obj(
                adb_ContentBean_t* _ContentBean,
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
            
                    axis2_char_t *text_value_1;
                    axis2_char_t *text_value_1_temp;
                    
                    axis2_char_t text_value_2[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
                    axis2_char_t text_value_4[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
                    axis2_char_t *text_value_6;
                    axis2_char_t *text_value_6_temp;
                    
                    axis2_char_t text_value_7[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_8;
                    axis2_char_t *text_value_8_temp;
                    
                    axis2_char_t text_value_9[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _ContentBean, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"ContentBean\"", NULL);
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
            xsi_type_attri = axiom_attribute_create (env, "type", "ContentBean", xsi_ns);
            
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
                      

                   if (!_ContentBean->is_valid_absent)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("absent"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("absent")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing absent element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sabsent>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sabsent>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _ContentBean->property_absent;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_1_temp = axutil_xml_quote_string(env, text_value_1, AXIS2_TRUE);
                           if (text_value_1_temp)
                           {
                               axutil_stream_write(stream, env, text_value_1_temp, axutil_strlen(text_value_1_temp));
                               AXIS2_FREE(env->allocator, text_value_1_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
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
                      

                   if (!_ContentBean->is_valid_collection)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("collection"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("collection")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing collection element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%scollection>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%scollection>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_2, (_ContentBean->property_collection)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           
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
                      

                   if (!_ContentBean->is_valid_contentPath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("contentPath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("contentPath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing contentPath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%scontentPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%scontentPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _ContentBean->property_contentPath;
                           
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
                      

                   if (!_ContentBean->is_valid_loggedIn)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("loggedIn"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("loggedIn")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing loggedIn element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sloggedIn>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sloggedIn>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_4, (_ContentBean->property_loggedIn)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           
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
                      

                   if (!_ContentBean->is_valid_mediaType)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("mediaType"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("mediaType")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing mediaType element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%smediaType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%smediaType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_5 = _ContentBean->property_mediaType;
                           
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
                      

                   if (!_ContentBean->is_valid_pathWithVersion)
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
                    
                           text_value_6 = _ContentBean->property_pathWithVersion;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_6_temp = axutil_xml_quote_string(env, text_value_6, AXIS2_TRUE);
                           if (text_value_6_temp)
                           {
                               axutil_stream_write(stream, env, text_value_6_temp, axutil_strlen(text_value_6_temp));
                               AXIS2_FREE(env->allocator, text_value_6_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_6, axutil_strlen(text_value_6));
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
                      

                   if (!_ContentBean->is_valid_putAllowed)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("putAllowed"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("putAllowed")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing putAllowed element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sputAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sputAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_7, (_ContentBean->property_putAllowed)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_7, axutil_strlen(text_value_7));
                           
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
                      

                   if (!_ContentBean->is_valid_realPath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("realPath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("realPath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing realPath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%srealPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%srealPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_8 = _ContentBean->property_realPath;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_8_temp = axutil_xml_quote_string(env, text_value_8, AXIS2_TRUE);
                           if (text_value_8_temp)
                           {
                               axutil_stream_write(stream, env, text_value_8_temp, axutil_strlen(text_value_8_temp));
                               AXIS2_FREE(env->allocator, text_value_8_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_8, axutil_strlen(text_value_8));
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
                      

                   if (!_ContentBean->is_valid_versionView)
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
                    
                           strcpy(text_value_9, (_ContentBean->property_versionView)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_9, axutil_strlen(text_value_9));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for absent by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentBean_get_property1(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env)
            {
                return adb_ContentBean_get_absent(_ContentBean,
                                             env);
            }

            /**
             * getter for absent.
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentBean_get_absent(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ContentBean, NULL);
                  

                return _ContentBean->property_absent;
             }

            /**
             * setter for absent
             */
            axis2_status_t AXIS2_CALL
            adb_ContentBean_set_absent(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_absent)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
                
                if(_ContentBean->is_valid_absent &&
                        arg_absent == _ContentBean->property_absent)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentBean_reset_absent(_ContentBean, env);

                
                if(NULL == arg_absent)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ContentBean->property_absent = (axis2_char_t *)axutil_strdup(env, arg_absent);
                        if(NULL == _ContentBean->property_absent)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for absent");
                            return AXIS2_FAILURE;
                        }
                        _ContentBean->is_valid_absent = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for absent
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_reset_absent(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
               

               
            
                
                if(_ContentBean->property_absent != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ContentBean->property_absent);
                     _ContentBean->property_absent = NULL;
                }
            
                
                
                _ContentBean->is_valid_absent = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether absent is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentBean_is_absent_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_TRUE);
               
               return !_ContentBean->is_valid_absent;
           }

           /**
            * Set absent to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_set_absent_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               return adb_ContentBean_reset_absent(_ContentBean, env);
           }

           

            /**
             * Getter for collection by  Property Number 2
             */
            axis2_bool_t AXIS2_CALL
            adb_ContentBean_get_property2(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env)
            {
                return adb_ContentBean_get_collection(_ContentBean,
                                             env);
            }

            /**
             * getter for collection.
             */
            axis2_bool_t AXIS2_CALL
            adb_ContentBean_get_collection(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ContentBean, (axis2_bool_t)0);
                  

                return _ContentBean->property_collection;
             }

            /**
             * setter for collection
             */
            axis2_status_t AXIS2_CALL
            adb_ContentBean_set_collection(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_collection)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
                
                if(_ContentBean->is_valid_collection &&
                        arg_collection == _ContentBean->property_collection)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentBean_reset_collection(_ContentBean, env);

                _ContentBean->property_collection = arg_collection;
                        _ContentBean->is_valid_collection = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for collection
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_reset_collection(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
               

               _ContentBean->is_valid_collection = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether collection is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentBean_is_collection_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_TRUE);
               
               return !_ContentBean->is_valid_collection;
           }

           /**
            * Set collection to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_set_collection_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               return adb_ContentBean_reset_collection(_ContentBean, env);
           }

           

            /**
             * Getter for contentPath by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentBean_get_property3(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env)
            {
                return adb_ContentBean_get_contentPath(_ContentBean,
                                             env);
            }

            /**
             * getter for contentPath.
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentBean_get_contentPath(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ContentBean, NULL);
                  

                return _ContentBean->property_contentPath;
             }

            /**
             * setter for contentPath
             */
            axis2_status_t AXIS2_CALL
            adb_ContentBean_set_contentPath(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_contentPath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
                
                if(_ContentBean->is_valid_contentPath &&
                        arg_contentPath == _ContentBean->property_contentPath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentBean_reset_contentPath(_ContentBean, env);

                
                if(NULL == arg_contentPath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ContentBean->property_contentPath = (axis2_char_t *)axutil_strdup(env, arg_contentPath);
                        if(NULL == _ContentBean->property_contentPath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for contentPath");
                            return AXIS2_FAILURE;
                        }
                        _ContentBean->is_valid_contentPath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for contentPath
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_reset_contentPath(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
               

               
            
                
                if(_ContentBean->property_contentPath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ContentBean->property_contentPath);
                     _ContentBean->property_contentPath = NULL;
                }
            
                
                
                _ContentBean->is_valid_contentPath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether contentPath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentBean_is_contentPath_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_TRUE);
               
               return !_ContentBean->is_valid_contentPath;
           }

           /**
            * Set contentPath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_set_contentPath_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               return adb_ContentBean_reset_contentPath(_ContentBean, env);
           }

           

            /**
             * Getter for loggedIn by  Property Number 4
             */
            axis2_bool_t AXIS2_CALL
            adb_ContentBean_get_property4(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env)
            {
                return adb_ContentBean_get_loggedIn(_ContentBean,
                                             env);
            }

            /**
             * getter for loggedIn.
             */
            axis2_bool_t AXIS2_CALL
            adb_ContentBean_get_loggedIn(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ContentBean, (axis2_bool_t)0);
                  

                return _ContentBean->property_loggedIn;
             }

            /**
             * setter for loggedIn
             */
            axis2_status_t AXIS2_CALL
            adb_ContentBean_set_loggedIn(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_loggedIn)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
                
                if(_ContentBean->is_valid_loggedIn &&
                        arg_loggedIn == _ContentBean->property_loggedIn)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentBean_reset_loggedIn(_ContentBean, env);

                _ContentBean->property_loggedIn = arg_loggedIn;
                        _ContentBean->is_valid_loggedIn = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for loggedIn
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_reset_loggedIn(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
               

               _ContentBean->is_valid_loggedIn = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether loggedIn is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentBean_is_loggedIn_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_TRUE);
               
               return !_ContentBean->is_valid_loggedIn;
           }

           /**
            * Set loggedIn to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_set_loggedIn_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               return adb_ContentBean_reset_loggedIn(_ContentBean, env);
           }

           

            /**
             * Getter for mediaType by  Property Number 5
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentBean_get_property5(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env)
            {
                return adb_ContentBean_get_mediaType(_ContentBean,
                                             env);
            }

            /**
             * getter for mediaType.
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentBean_get_mediaType(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ContentBean, NULL);
                  

                return _ContentBean->property_mediaType;
             }

            /**
             * setter for mediaType
             */
            axis2_status_t AXIS2_CALL
            adb_ContentBean_set_mediaType(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_mediaType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
                
                if(_ContentBean->is_valid_mediaType &&
                        arg_mediaType == _ContentBean->property_mediaType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentBean_reset_mediaType(_ContentBean, env);

                
                if(NULL == arg_mediaType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ContentBean->property_mediaType = (axis2_char_t *)axutil_strdup(env, arg_mediaType);
                        if(NULL == _ContentBean->property_mediaType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for mediaType");
                            return AXIS2_FAILURE;
                        }
                        _ContentBean->is_valid_mediaType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for mediaType
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_reset_mediaType(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
               

               
            
                
                if(_ContentBean->property_mediaType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ContentBean->property_mediaType);
                     _ContentBean->property_mediaType = NULL;
                }
            
                
                
                _ContentBean->is_valid_mediaType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether mediaType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentBean_is_mediaType_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_TRUE);
               
               return !_ContentBean->is_valid_mediaType;
           }

           /**
            * Set mediaType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_set_mediaType_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               return adb_ContentBean_reset_mediaType(_ContentBean, env);
           }

           

            /**
             * Getter for pathWithVersion by  Property Number 6
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentBean_get_property6(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env)
            {
                return adb_ContentBean_get_pathWithVersion(_ContentBean,
                                             env);
            }

            /**
             * getter for pathWithVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentBean_get_pathWithVersion(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ContentBean, NULL);
                  

                return _ContentBean->property_pathWithVersion;
             }

            /**
             * setter for pathWithVersion
             */
            axis2_status_t AXIS2_CALL
            adb_ContentBean_set_pathWithVersion(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_pathWithVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
                
                if(_ContentBean->is_valid_pathWithVersion &&
                        arg_pathWithVersion == _ContentBean->property_pathWithVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentBean_reset_pathWithVersion(_ContentBean, env);

                
                if(NULL == arg_pathWithVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ContentBean->property_pathWithVersion = (axis2_char_t *)axutil_strdup(env, arg_pathWithVersion);
                        if(NULL == _ContentBean->property_pathWithVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for pathWithVersion");
                            return AXIS2_FAILURE;
                        }
                        _ContentBean->is_valid_pathWithVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for pathWithVersion
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_reset_pathWithVersion(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
               

               
            
                
                if(_ContentBean->property_pathWithVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ContentBean->property_pathWithVersion);
                     _ContentBean->property_pathWithVersion = NULL;
                }
            
                
                
                _ContentBean->is_valid_pathWithVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether pathWithVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentBean_is_pathWithVersion_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_TRUE);
               
               return !_ContentBean->is_valid_pathWithVersion;
           }

           /**
            * Set pathWithVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_set_pathWithVersion_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               return adb_ContentBean_reset_pathWithVersion(_ContentBean, env);
           }

           

            /**
             * Getter for putAllowed by  Property Number 7
             */
            axis2_bool_t AXIS2_CALL
            adb_ContentBean_get_property7(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env)
            {
                return adb_ContentBean_get_putAllowed(_ContentBean,
                                             env);
            }

            /**
             * getter for putAllowed.
             */
            axis2_bool_t AXIS2_CALL
            adb_ContentBean_get_putAllowed(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ContentBean, (axis2_bool_t)0);
                  

                return _ContentBean->property_putAllowed;
             }

            /**
             * setter for putAllowed
             */
            axis2_status_t AXIS2_CALL
            adb_ContentBean_set_putAllowed(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_putAllowed)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
                
                if(_ContentBean->is_valid_putAllowed &&
                        arg_putAllowed == _ContentBean->property_putAllowed)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentBean_reset_putAllowed(_ContentBean, env);

                _ContentBean->property_putAllowed = arg_putAllowed;
                        _ContentBean->is_valid_putAllowed = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for putAllowed
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_reset_putAllowed(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
               

               _ContentBean->is_valid_putAllowed = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether putAllowed is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentBean_is_putAllowed_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_TRUE);
               
               return !_ContentBean->is_valid_putAllowed;
           }

           /**
            * Set putAllowed to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_set_putAllowed_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               return adb_ContentBean_reset_putAllowed(_ContentBean, env);
           }

           

            /**
             * Getter for realPath by  Property Number 8
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentBean_get_property8(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env)
            {
                return adb_ContentBean_get_realPath(_ContentBean,
                                             env);
            }

            /**
             * getter for realPath.
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentBean_get_realPath(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ContentBean, NULL);
                  

                return _ContentBean->property_realPath;
             }

            /**
             * setter for realPath
             */
            axis2_status_t AXIS2_CALL
            adb_ContentBean_set_realPath(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_realPath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
                
                if(_ContentBean->is_valid_realPath &&
                        arg_realPath == _ContentBean->property_realPath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentBean_reset_realPath(_ContentBean, env);

                
                if(NULL == arg_realPath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ContentBean->property_realPath = (axis2_char_t *)axutil_strdup(env, arg_realPath);
                        if(NULL == _ContentBean->property_realPath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for realPath");
                            return AXIS2_FAILURE;
                        }
                        _ContentBean->is_valid_realPath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for realPath
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_reset_realPath(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
               

               
            
                
                if(_ContentBean->property_realPath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ContentBean->property_realPath);
                     _ContentBean->property_realPath = NULL;
                }
            
                
                
                _ContentBean->is_valid_realPath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether realPath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentBean_is_realPath_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_TRUE);
               
               return !_ContentBean->is_valid_realPath;
           }

           /**
            * Set realPath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_set_realPath_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               return adb_ContentBean_reset_realPath(_ContentBean, env);
           }

           

            /**
             * Getter for versionView by  Property Number 9
             */
            axis2_bool_t AXIS2_CALL
            adb_ContentBean_get_property9(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env)
            {
                return adb_ContentBean_get_versionView(_ContentBean,
                                             env);
            }

            /**
             * getter for versionView.
             */
            axis2_bool_t AXIS2_CALL
            adb_ContentBean_get_versionView(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ContentBean, (axis2_bool_t)0);
                  

                return _ContentBean->property_versionView;
             }

            /**
             * setter for versionView
             */
            axis2_status_t AXIS2_CALL
            adb_ContentBean_set_versionView(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_versionView)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
                
                if(_ContentBean->is_valid_versionView &&
                        arg_versionView == _ContentBean->property_versionView)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentBean_reset_versionView(_ContentBean, env);

                _ContentBean->property_versionView = arg_versionView;
                        _ContentBean->is_valid_versionView = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for versionView
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_reset_versionView(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_FAILURE);
               

               _ContentBean->is_valid_versionView = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether versionView is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentBean_is_versionView_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentBean, AXIS2_TRUE);
               
               return !_ContentBean->is_valid_versionView;
           }

           /**
            * Set versionView to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentBean_set_versionView_nil(
                   adb_ContentBean_t* _ContentBean,
                   const axutil_env_t *env)
           {
               return adb_ContentBean_reset_versionView(_ContentBean, env);
           }

           

