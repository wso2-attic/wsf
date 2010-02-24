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
         * adb_MetadataBean.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_MetadataBean.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = MetadataBean
                 * Namespace URI = http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd
                 * Namespace Prefix = ns3
                 */
           


        struct adb_MetadataBean
        {
            axis2_char_t *property_Type;

            axis2_char_t* property_activeResourcePath;

                
                axis2_bool_t is_valid_activeResourcePath;
            axis2_char_t* property_author;

                
                axis2_bool_t is_valid_author;
            axis2_bool_t property_collection;

                
                axis2_bool_t is_valid_collection;
            axis2_char_t* property_contentPath;

                
                axis2_bool_t is_valid_contentPath;
            axis2_char_t* property_description;

                
                axis2_bool_t is_valid_description;
            axis2_char_t* property_formattedCreatedOn;

                
                axis2_bool_t is_valid_formattedCreatedOn;
            axis2_char_t* property_formattedLastModified;

                
                axis2_bool_t is_valid_formattedLastModified;
            axis2_char_t* property_lastUpdater;

                
                axis2_bool_t is_valid_lastUpdater;
            axis2_char_t* property_mediaType;

                
                axis2_bool_t is_valid_mediaType;
            axutil_array_list_t* property_navigatablePaths;

                
                axis2_bool_t is_valid_navigatablePaths;
            axis2_char_t* property_path;

                
                axis2_bool_t is_valid_path;
            axis2_char_t* property_pathWithVersion;

                
                axis2_bool_t is_valid_pathWithVersion;
            axis2_char_t* property_permalink;

                
                axis2_bool_t is_valid_permalink;
            axis2_bool_t property_putAllowed;

                
                axis2_bool_t is_valid_putAllowed;
            axis2_char_t* property_serverBaseURL;

                
                axis2_bool_t is_valid_serverBaseURL;
            axis2_bool_t property_versionView;

                
                axis2_bool_t is_valid_versionView;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_MetadataBean_set_collection_nil(
                        adb_MetadataBean_t* _MetadataBean,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_MetadataBean_set_putAllowed_nil(
                        adb_MetadataBean_t* _MetadataBean,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_MetadataBean_set_versionView_nil(
                        adb_MetadataBean_t* _MetadataBean,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_MetadataBean_t* AXIS2_CALL
        adb_MetadataBean_create(
            const axutil_env_t *env)
        {
            adb_MetadataBean_t *_MetadataBean = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _MetadataBean = (adb_MetadataBean_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_MetadataBean_t));

            if(NULL == _MetadataBean)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_MetadataBean, 0, sizeof(adb_MetadataBean_t));

            _MetadataBean->property_Type = axutil_strdup(env, "adb_MetadataBean");
            _MetadataBean->property_activeResourcePath  = NULL;
                  _MetadataBean->is_valid_activeResourcePath  = AXIS2_FALSE;
            _MetadataBean->property_author  = NULL;
                  _MetadataBean->is_valid_author  = AXIS2_FALSE;
            _MetadataBean->is_valid_collection  = AXIS2_FALSE;
            _MetadataBean->property_contentPath  = NULL;
                  _MetadataBean->is_valid_contentPath  = AXIS2_FALSE;
            _MetadataBean->property_description  = NULL;
                  _MetadataBean->is_valid_description  = AXIS2_FALSE;
            _MetadataBean->property_formattedCreatedOn  = NULL;
                  _MetadataBean->is_valid_formattedCreatedOn  = AXIS2_FALSE;
            _MetadataBean->property_formattedLastModified  = NULL;
                  _MetadataBean->is_valid_formattedLastModified  = AXIS2_FALSE;
            _MetadataBean->property_lastUpdater  = NULL;
                  _MetadataBean->is_valid_lastUpdater  = AXIS2_FALSE;
            _MetadataBean->property_mediaType  = NULL;
                  _MetadataBean->is_valid_mediaType  = AXIS2_FALSE;
            _MetadataBean->property_navigatablePaths  = NULL;
                  _MetadataBean->is_valid_navigatablePaths  = AXIS2_FALSE;
            _MetadataBean->property_path  = NULL;
                  _MetadataBean->is_valid_path  = AXIS2_FALSE;
            _MetadataBean->property_pathWithVersion  = NULL;
                  _MetadataBean->is_valid_pathWithVersion  = AXIS2_FALSE;
            _MetadataBean->property_permalink  = NULL;
                  _MetadataBean->is_valid_permalink  = AXIS2_FALSE;
            _MetadataBean->is_valid_putAllowed  = AXIS2_FALSE;
            _MetadataBean->property_serverBaseURL  = NULL;
                  _MetadataBean->is_valid_serverBaseURL  = AXIS2_FALSE;
            _MetadataBean->is_valid_versionView  = AXIS2_FALSE;
            

            return _MetadataBean;
        }

        adb_MetadataBean_t* AXIS2_CALL
        adb_MetadataBean_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _activeResourcePath,
                axis2_char_t* _author,
                axis2_bool_t _collection,
                axis2_char_t* _contentPath,
                axis2_char_t* _description,
                axis2_char_t* _formattedCreatedOn,
                axis2_char_t* _formattedLastModified,
                axis2_char_t* _lastUpdater,
                axis2_char_t* _mediaType,
                axutil_array_list_t* _navigatablePaths,
                axis2_char_t* _path,
                axis2_char_t* _pathWithVersion,
                axis2_char_t* _permalink,
                axis2_bool_t _putAllowed,
                axis2_char_t* _serverBaseURL,
                axis2_bool_t _versionView)
        {
            adb_MetadataBean_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_MetadataBean_create(env);

            
              status = adb_MetadataBean_set_activeResourcePath(
                                     adb_obj,
                                     env,
                                     _activeResourcePath);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_author(
                                     adb_obj,
                                     env,
                                     _author);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_collection(
                                     adb_obj,
                                     env,
                                     _collection);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_contentPath(
                                     adb_obj,
                                     env,
                                     _contentPath);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_description(
                                     adb_obj,
                                     env,
                                     _description);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_formattedCreatedOn(
                                     adb_obj,
                                     env,
                                     _formattedCreatedOn);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_formattedLastModified(
                                     adb_obj,
                                     env,
                                     _formattedLastModified);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_lastUpdater(
                                     adb_obj,
                                     env,
                                     _lastUpdater);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_mediaType(
                                     adb_obj,
                                     env,
                                     _mediaType);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_navigatablePaths(
                                     adb_obj,
                                     env,
                                     _navigatablePaths);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_path(
                                     adb_obj,
                                     env,
                                     _path);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_pathWithVersion(
                                     adb_obj,
                                     env,
                                     _pathWithVersion);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_permalink(
                                     adb_obj,
                                     env,
                                     _permalink);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_putAllowed(
                                     adb_obj,
                                     env,
                                     _putAllowed);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_serverBaseURL(
                                     adb_obj,
                                     env,
                                     _serverBaseURL);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_MetadataBean_set_versionView(
                                     adb_obj,
                                     env,
                                     _versionView);
              if(status == AXIS2_FAILURE) {
                  adb_MetadataBean_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_MetadataBean_free_popping_value(
                        adb_MetadataBean_t* _MetadataBean,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _MetadataBean->property_activeResourcePath;

                    _MetadataBean->property_activeResourcePath = (axis2_char_t*)NULL;
                    adb_MetadataBean_free(_MetadataBean, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_MetadataBean_free(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _MetadataBean,
                env,
                "adb_MetadataBean");
            
        }

        axis2_status_t AXIS2_CALL
        adb_MetadataBean_free_obj(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);

            if (_MetadataBean->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _MetadataBean->property_Type);
            }

            adb_MetadataBean_reset_activeResourcePath(_MetadataBean, env);
            adb_MetadataBean_reset_author(_MetadataBean, env);
            adb_MetadataBean_reset_collection(_MetadataBean, env);
            adb_MetadataBean_reset_contentPath(_MetadataBean, env);
            adb_MetadataBean_reset_description(_MetadataBean, env);
            adb_MetadataBean_reset_formattedCreatedOn(_MetadataBean, env);
            adb_MetadataBean_reset_formattedLastModified(_MetadataBean, env);
            adb_MetadataBean_reset_lastUpdater(_MetadataBean, env);
            adb_MetadataBean_reset_mediaType(_MetadataBean, env);
            adb_MetadataBean_reset_navigatablePaths(_MetadataBean, env);
            adb_MetadataBean_reset_path(_MetadataBean, env);
            adb_MetadataBean_reset_pathWithVersion(_MetadataBean, env);
            adb_MetadataBean_reset_permalink(_MetadataBean, env);
            adb_MetadataBean_reset_putAllowed(_MetadataBean, env);
            adb_MetadataBean_reset_serverBaseURL(_MetadataBean, env);
            adb_MetadataBean_reset_versionView(_MetadataBean, env);
            

            if(_MetadataBean)
            {
                AXIS2_FREE(env->allocator, _MetadataBean);
                _MetadataBean = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_MetadataBean_deserialize(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _MetadataBean,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_MetadataBean");
            
        }

        axis2_status_t AXIS2_CALL
        adb_MetadataBean_deserialize_obj(
                adb_MetadataBean_t* _MetadataBean,
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
            AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for MetadataBean : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building activeResourcePath element
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
                                   
                                 element_qname = axutil_qname_create(env, "activeResourcePath", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_MetadataBean_set_activeResourcePath(_MetadataBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for activeResourcePath ");
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
                      * building author element
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
                                 
                                 element_qname = axutil_qname_create(env, "author", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_MetadataBean_set_author(_MetadataBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for author ");
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
                                                status = adb_MetadataBean_set_collection(_MetadataBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_MetadataBean_set_collection(_MetadataBean, env,
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
                                            status = adb_MetadataBean_set_contentPath(_MetadataBean, env,
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
                      * building description element
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
                                 
                                 element_qname = axutil_qname_create(env, "description", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_MetadataBean_set_description(_MetadataBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for description ");
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
                      * building formattedCreatedOn element
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
                                 
                                 element_qname = axutil_qname_create(env, "formattedCreatedOn", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_MetadataBean_set_formattedCreatedOn(_MetadataBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for formattedCreatedOn ");
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
                      * building formattedLastModified element
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
                                 
                                 element_qname = axutil_qname_create(env, "formattedLastModified", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_MetadataBean_set_formattedLastModified(_MetadataBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for formattedLastModified ");
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
                      * building lastUpdater element
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
                                 
                                 element_qname = axutil_qname_create(env, "lastUpdater", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_MetadataBean_set_lastUpdater(_MetadataBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for lastUpdater ");
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
                                            status = adb_MetadataBean_set_mediaType(_MetadataBean, env,
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
                     * building navigatablePaths array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building navigatablePaths element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "navigatablePaths", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if (adb_WebResourcePath_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_WebResourcePath");
                                          
                                          status =  adb_WebResourcePath_deserialize((adb_WebResourcePath_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element navigatablePaths ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for navigatablePaths ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "navigatablePaths (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_MetadataBean_set_navigatablePaths(_MetadataBean, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building path element
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
                                 
                                 element_qname = axutil_qname_create(env, "path", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_MetadataBean_set_path(_MetadataBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for path ");
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
                                            status = adb_MetadataBean_set_pathWithVersion(_MetadataBean, env,
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
                      * building permalink element
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
                                 
                                 element_qname = axutil_qname_create(env, "permalink", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_MetadataBean_set_permalink(_MetadataBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for permalink ");
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
                                                status = adb_MetadataBean_set_putAllowed(_MetadataBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_MetadataBean_set_putAllowed(_MetadataBean, env,
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
                      * building serverBaseURL element
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
                                 
                                 element_qname = axutil_qname_create(env, "serverBaseURL", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_MetadataBean_set_serverBaseURL(_MetadataBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serverBaseURL ");
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
                                                status = adb_MetadataBean_set_versionView(_MetadataBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_MetadataBean_set_versionView(_MetadataBean, env,
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
          adb_MetadataBean_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_MetadataBean_declare_parent_namespaces(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_MetadataBean_serialize(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_MetadataBean == NULL)
            {
                return adb_MetadataBean_serialize_obj(
                    _MetadataBean, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _MetadataBean, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_MetadataBean");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_MetadataBean_serialize_obj(
                adb_MetadataBean_t* _MetadataBean,
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
             
                    axis2_char_t *text_value_1;
                    axis2_char_t *text_value_1_temp;
                    
                    axis2_char_t *text_value_2;
                    axis2_char_t *text_value_2_temp;
                    
                    axis2_char_t text_value_3[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
                    axis2_char_t *text_value_6;
                    axis2_char_t *text_value_6_temp;
                    
                    axis2_char_t *text_value_7;
                    axis2_char_t *text_value_7_temp;
                    
                    axis2_char_t *text_value_8;
                    axis2_char_t *text_value_8_temp;
                    
                    axis2_char_t *text_value_9;
                    axis2_char_t *text_value_9_temp;
                    
                    axis2_char_t text_value_10[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_11;
                    axis2_char_t *text_value_11_temp;
                    
                    axis2_char_t *text_value_12;
                    axis2_char_t *text_value_12_temp;
                    
                    axis2_char_t *text_value_13;
                    axis2_char_t *text_value_13_temp;
                    
                    axis2_char_t text_value_14[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_15;
                    axis2_char_t *text_value_15_temp;
                    
                    axis2_char_t text_value_16[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"MetadataBean\"", NULL);
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
            xsi_type_attri = axiom_attribute_create (env, "type", "MetadataBean", xsi_ns);
            
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
                      

                   if (!_MetadataBean->is_valid_activeResourcePath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("activeResourcePath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("activeResourcePath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing activeResourcePath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sactiveResourcePath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sactiveResourcePath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _MetadataBean->property_activeResourcePath;
                           
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
                      

                   if (!_MetadataBean->is_valid_author)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("author"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("author")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing author element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sauthor>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sauthor>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _MetadataBean->property_author;
                           
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
                      

                   if (!_MetadataBean->is_valid_collection)
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
                    
                           strcpy(text_value_3, (_MetadataBean->property_collection)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           
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
                      

                   if (!_MetadataBean->is_valid_contentPath)
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
                    
                           text_value_4 = _MetadataBean->property_contentPath;
                           
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
                      

                   if (!_MetadataBean->is_valid_description)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("description"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("description")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing description element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdescription>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdescription>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_5 = _MetadataBean->property_description;
                           
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
                      

                   if (!_MetadataBean->is_valid_formattedCreatedOn)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("formattedCreatedOn"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("formattedCreatedOn")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing formattedCreatedOn element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sformattedCreatedOn>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sformattedCreatedOn>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_6 = _MetadataBean->property_formattedCreatedOn;
                           
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
                      

                   if (!_MetadataBean->is_valid_formattedLastModified)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("formattedLastModified"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("formattedLastModified")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing formattedLastModified element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sformattedLastModified>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sformattedLastModified>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_7 = _MetadataBean->property_formattedLastModified;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_7_temp = axutil_xml_quote_string(env, text_value_7, AXIS2_TRUE);
                           if (text_value_7_temp)
                           {
                               axutil_stream_write(stream, env, text_value_7_temp, axutil_strlen(text_value_7_temp));
                               AXIS2_FREE(env->allocator, text_value_7_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_7, axutil_strlen(text_value_7));
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
                      

                   if (!_MetadataBean->is_valid_lastUpdater)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("lastUpdater"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("lastUpdater")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing lastUpdater element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slastUpdater>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slastUpdater>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_8 = _MetadataBean->property_lastUpdater;
                           
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
                      

                   if (!_MetadataBean->is_valid_mediaType)
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
                    
                           text_value_9 = _MetadataBean->property_mediaType;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_9_temp = axutil_xml_quote_string(env, text_value_9, AXIS2_TRUE);
                           if (text_value_9_temp)
                           {
                               axutil_stream_write(stream, env, text_value_9_temp, axutil_strlen(text_value_9_temp));
                               AXIS2_FREE(env->allocator, text_value_9_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_9, axutil_strlen(text_value_9));
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
                      

                   if (!_MetadataBean->is_valid_navigatablePaths)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("navigatablePaths"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("navigatablePaths")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing navigatablePaths array
                      */
                     if (_MetadataBean->property_navigatablePaths != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%snavigatablePaths",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%snavigatablePaths>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_MetadataBean->property_navigatablePaths, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_MetadataBean->property_navigatablePaths, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing navigatablePaths element
                      */

                    
                     
                            if(!adb_WebResourcePath_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_WebResourcePath_serialize((adb_WebResourcePath_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_WebResourcePath_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_WebResourcePath_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
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
                      

                   if (!_MetadataBean->is_valid_path)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("path"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("path")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing path element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_11 = _MetadataBean->property_path;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_11_temp = axutil_xml_quote_string(env, text_value_11, AXIS2_TRUE);
                           if (text_value_11_temp)
                           {
                               axutil_stream_write(stream, env, text_value_11_temp, axutil_strlen(text_value_11_temp));
                               AXIS2_FREE(env->allocator, text_value_11_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_11, axutil_strlen(text_value_11));
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
                      

                   if (!_MetadataBean->is_valid_pathWithVersion)
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
                    
                           text_value_12 = _MetadataBean->property_pathWithVersion;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_12_temp = axutil_xml_quote_string(env, text_value_12, AXIS2_TRUE);
                           if (text_value_12_temp)
                           {
                               axutil_stream_write(stream, env, text_value_12_temp, axutil_strlen(text_value_12_temp));
                               AXIS2_FREE(env->allocator, text_value_12_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_12, axutil_strlen(text_value_12));
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
                      

                   if (!_MetadataBean->is_valid_permalink)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("permalink"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("permalink")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing permalink element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spermalink>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spermalink>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_13 = _MetadataBean->property_permalink;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_13_temp = axutil_xml_quote_string(env, text_value_13, AXIS2_TRUE);
                           if (text_value_13_temp)
                           {
                               axutil_stream_write(stream, env, text_value_13_temp, axutil_strlen(text_value_13_temp));
                               AXIS2_FREE(env->allocator, text_value_13_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_13, axutil_strlen(text_value_13));
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
                      

                   if (!_MetadataBean->is_valid_putAllowed)
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
                    
                           strcpy(text_value_14, (_MetadataBean->property_putAllowed)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_14, axutil_strlen(text_value_14));
                           
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
                      

                   if (!_MetadataBean->is_valid_serverBaseURL)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serverBaseURL"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serverBaseURL")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serverBaseURL element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserverBaseURL>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserverBaseURL>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_15 = _MetadataBean->property_serverBaseURL;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_15_temp = axutil_xml_quote_string(env, text_value_15, AXIS2_TRUE);
                           if (text_value_15_temp)
                           {
                               axutil_stream_write(stream, env, text_value_15_temp, axutil_strlen(text_value_15_temp));
                               AXIS2_FREE(env->allocator, text_value_15_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_15, axutil_strlen(text_value_15));
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
                      

                   if (!_MetadataBean->is_valid_versionView)
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
                    
                           strcpy(text_value_16, (_MetadataBean->property_versionView)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_16, axutil_strlen(text_value_16));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for activeResourcePath by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property1(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_activeResourcePath(_MetadataBean,
                                             env);
            }

            /**
             * getter for activeResourcePath.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_activeResourcePath(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_activeResourcePath;
             }

            /**
             * setter for activeResourcePath
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_activeResourcePath(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_activeResourcePath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_activeResourcePath &&
                        arg_activeResourcePath == _MetadataBean->property_activeResourcePath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_activeResourcePath(_MetadataBean, env);

                
                if(NULL == arg_activeResourcePath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_activeResourcePath = (axis2_char_t *)axutil_strdup(env, arg_activeResourcePath);
                        if(NULL == _MetadataBean->property_activeResourcePath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for activeResourcePath");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_activeResourcePath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for activeResourcePath
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_activeResourcePath(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_activeResourcePath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_activeResourcePath);
                     _MetadataBean->property_activeResourcePath = NULL;
                }
            
                
                
                _MetadataBean->is_valid_activeResourcePath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether activeResourcePath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_activeResourcePath_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_activeResourcePath;
           }

           /**
            * Set activeResourcePath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_activeResourcePath_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_activeResourcePath(_MetadataBean, env);
           }

           

            /**
             * Getter for author by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property2(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_author(_MetadataBean,
                                             env);
            }

            /**
             * getter for author.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_author(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_author;
             }

            /**
             * setter for author
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_author(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_author)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_author &&
                        arg_author == _MetadataBean->property_author)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_author(_MetadataBean, env);

                
                if(NULL == arg_author)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_author = (axis2_char_t *)axutil_strdup(env, arg_author);
                        if(NULL == _MetadataBean->property_author)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for author");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_author = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for author
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_author(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_author != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_author);
                     _MetadataBean->property_author = NULL;
                }
            
                
                
                _MetadataBean->is_valid_author = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether author is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_author_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_author;
           }

           /**
            * Set author to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_author_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_author(_MetadataBean, env);
           }

           

            /**
             * Getter for collection by  Property Number 3
             */
            axis2_bool_t AXIS2_CALL
            adb_MetadataBean_get_property3(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_collection(_MetadataBean,
                                             env);
            }

            /**
             * getter for collection.
             */
            axis2_bool_t AXIS2_CALL
            adb_MetadataBean_get_collection(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, (axis2_bool_t)0);
                  

                return _MetadataBean->property_collection;
             }

            /**
             * setter for collection
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_collection(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_collection)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_collection &&
                        arg_collection == _MetadataBean->property_collection)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_collection(_MetadataBean, env);

                _MetadataBean->property_collection = arg_collection;
                        _MetadataBean->is_valid_collection = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for collection
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_collection(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               _MetadataBean->is_valid_collection = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether collection is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_collection_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_collection;
           }

           /**
            * Set collection to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_collection_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_collection(_MetadataBean, env);
           }

           

            /**
             * Getter for contentPath by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property4(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_contentPath(_MetadataBean,
                                             env);
            }

            /**
             * getter for contentPath.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_contentPath(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_contentPath;
             }

            /**
             * setter for contentPath
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_contentPath(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_contentPath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_contentPath &&
                        arg_contentPath == _MetadataBean->property_contentPath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_contentPath(_MetadataBean, env);

                
                if(NULL == arg_contentPath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_contentPath = (axis2_char_t *)axutil_strdup(env, arg_contentPath);
                        if(NULL == _MetadataBean->property_contentPath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for contentPath");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_contentPath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for contentPath
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_contentPath(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_contentPath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_contentPath);
                     _MetadataBean->property_contentPath = NULL;
                }
            
                
                
                _MetadataBean->is_valid_contentPath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether contentPath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_contentPath_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_contentPath;
           }

           /**
            * Set contentPath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_contentPath_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_contentPath(_MetadataBean, env);
           }

           

            /**
             * Getter for description by  Property Number 5
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property5(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_description(_MetadataBean,
                                             env);
            }

            /**
             * getter for description.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_description(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_description;
             }

            /**
             * setter for description
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_description(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_description)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_description &&
                        arg_description == _MetadataBean->property_description)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_description(_MetadataBean, env);

                
                if(NULL == arg_description)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_description = (axis2_char_t *)axutil_strdup(env, arg_description);
                        if(NULL == _MetadataBean->property_description)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for description");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_description = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for description
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_description(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_description != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_description);
                     _MetadataBean->property_description = NULL;
                }
            
                
                
                _MetadataBean->is_valid_description = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether description is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_description_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_description;
           }

           /**
            * Set description to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_description_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_description(_MetadataBean, env);
           }

           

            /**
             * Getter for formattedCreatedOn by  Property Number 6
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property6(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_formattedCreatedOn(_MetadataBean,
                                             env);
            }

            /**
             * getter for formattedCreatedOn.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_formattedCreatedOn(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_formattedCreatedOn;
             }

            /**
             * setter for formattedCreatedOn
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_formattedCreatedOn(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_formattedCreatedOn)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_formattedCreatedOn &&
                        arg_formattedCreatedOn == _MetadataBean->property_formattedCreatedOn)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_formattedCreatedOn(_MetadataBean, env);

                
                if(NULL == arg_formattedCreatedOn)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_formattedCreatedOn = (axis2_char_t *)axutil_strdup(env, arg_formattedCreatedOn);
                        if(NULL == _MetadataBean->property_formattedCreatedOn)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for formattedCreatedOn");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_formattedCreatedOn = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for formattedCreatedOn
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_formattedCreatedOn(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_formattedCreatedOn != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_formattedCreatedOn);
                     _MetadataBean->property_formattedCreatedOn = NULL;
                }
            
                
                
                _MetadataBean->is_valid_formattedCreatedOn = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether formattedCreatedOn is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_formattedCreatedOn_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_formattedCreatedOn;
           }

           /**
            * Set formattedCreatedOn to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_formattedCreatedOn_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_formattedCreatedOn(_MetadataBean, env);
           }

           

            /**
             * Getter for formattedLastModified by  Property Number 7
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property7(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_formattedLastModified(_MetadataBean,
                                             env);
            }

            /**
             * getter for formattedLastModified.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_formattedLastModified(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_formattedLastModified;
             }

            /**
             * setter for formattedLastModified
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_formattedLastModified(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_formattedLastModified)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_formattedLastModified &&
                        arg_formattedLastModified == _MetadataBean->property_formattedLastModified)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_formattedLastModified(_MetadataBean, env);

                
                if(NULL == arg_formattedLastModified)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_formattedLastModified = (axis2_char_t *)axutil_strdup(env, arg_formattedLastModified);
                        if(NULL == _MetadataBean->property_formattedLastModified)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for formattedLastModified");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_formattedLastModified = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for formattedLastModified
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_formattedLastModified(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_formattedLastModified != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_formattedLastModified);
                     _MetadataBean->property_formattedLastModified = NULL;
                }
            
                
                
                _MetadataBean->is_valid_formattedLastModified = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether formattedLastModified is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_formattedLastModified_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_formattedLastModified;
           }

           /**
            * Set formattedLastModified to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_formattedLastModified_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_formattedLastModified(_MetadataBean, env);
           }

           

            /**
             * Getter for lastUpdater by  Property Number 8
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property8(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_lastUpdater(_MetadataBean,
                                             env);
            }

            /**
             * getter for lastUpdater.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_lastUpdater(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_lastUpdater;
             }

            /**
             * setter for lastUpdater
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_lastUpdater(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_lastUpdater)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_lastUpdater &&
                        arg_lastUpdater == _MetadataBean->property_lastUpdater)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_lastUpdater(_MetadataBean, env);

                
                if(NULL == arg_lastUpdater)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_lastUpdater = (axis2_char_t *)axutil_strdup(env, arg_lastUpdater);
                        if(NULL == _MetadataBean->property_lastUpdater)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for lastUpdater");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_lastUpdater = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for lastUpdater
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_lastUpdater(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_lastUpdater != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_lastUpdater);
                     _MetadataBean->property_lastUpdater = NULL;
                }
            
                
                
                _MetadataBean->is_valid_lastUpdater = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether lastUpdater is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_lastUpdater_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_lastUpdater;
           }

           /**
            * Set lastUpdater to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_lastUpdater_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_lastUpdater(_MetadataBean, env);
           }

           

            /**
             * Getter for mediaType by  Property Number 9
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property9(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_mediaType(_MetadataBean,
                                             env);
            }

            /**
             * getter for mediaType.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_mediaType(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_mediaType;
             }

            /**
             * setter for mediaType
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_mediaType(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_mediaType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_mediaType &&
                        arg_mediaType == _MetadataBean->property_mediaType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_mediaType(_MetadataBean, env);

                
                if(NULL == arg_mediaType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_mediaType = (axis2_char_t *)axutil_strdup(env, arg_mediaType);
                        if(NULL == _MetadataBean->property_mediaType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for mediaType");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_mediaType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for mediaType
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_mediaType(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_mediaType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_mediaType);
                     _MetadataBean->property_mediaType = NULL;
                }
            
                
                
                _MetadataBean->is_valid_mediaType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether mediaType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_mediaType_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_mediaType;
           }

           /**
            * Set mediaType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_mediaType_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_mediaType(_MetadataBean, env);
           }

           

            /**
             * Getter for navigatablePaths by  Property Number 10
             */
            axutil_array_list_t* AXIS2_CALL
            adb_MetadataBean_get_property10(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_navigatablePaths(_MetadataBean,
                                             env);
            }

            /**
             * getter for navigatablePaths.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_MetadataBean_get_navigatablePaths(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_navigatablePaths;
             }

            /**
             * setter for navigatablePaths
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_navigatablePaths(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_navigatablePaths)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_navigatablePaths &&
                        arg_navigatablePaths == _MetadataBean->property_navigatablePaths)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_navigatablePaths, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "navigatablePaths has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_navigatablePaths, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_MetadataBean_reset_navigatablePaths(_MetadataBean, env);

                
                if(NULL == arg_navigatablePaths)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_navigatablePaths = arg_navigatablePaths;
                        if(non_nil_exists)
                        {
                            _MetadataBean->is_valid_navigatablePaths = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of navigatablePaths.
             */
            adb_WebResourcePath_t* AXIS2_CALL
            adb_MetadataBean_get_navigatablePaths_at(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env, int i)
            {
                adb_WebResourcePath_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                if(_MetadataBean->property_navigatablePaths == NULL)
                {
                    return (adb_WebResourcePath_t*)0;
                }
                ret_val = (adb_WebResourcePath_t*)axutil_array_list_get(_MetadataBean->property_navigatablePaths, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of navigatablePaths.
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_navigatablePaths_at(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env, int i,
                    adb_WebResourcePath_t* arg_navigatablePaths)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if( _MetadataBean->is_valid_navigatablePaths &&
                    _MetadataBean->property_navigatablePaths &&
                
                    arg_navigatablePaths == (adb_WebResourcePath_t*)axutil_array_list_get(_MetadataBean->property_navigatablePaths, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_navigatablePaths)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_MetadataBean->property_navigatablePaths != NULL)
                        {
                            size = axutil_array_list_size(_MetadataBean->property_navigatablePaths, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_MetadataBean->property_navigatablePaths, env, i))
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
                  

                if(_MetadataBean->property_navigatablePaths == NULL)
                {
                    _MetadataBean->property_navigatablePaths = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_MetadataBean->property_navigatablePaths, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_WebResourcePath_free((adb_WebResourcePath_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _MetadataBean->is_valid_navigatablePaths = AXIS2_FALSE;
                        axutil_array_list_set(_MetadataBean->property_navigatablePaths , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_MetadataBean->property_navigatablePaths , env, i, arg_navigatablePaths);
                  _MetadataBean->is_valid_navigatablePaths = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to navigatablePaths.
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_add_navigatablePaths(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    adb_WebResourcePath_t* arg_navigatablePaths)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);

                
                    if(NULL == arg_navigatablePaths)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_MetadataBean->property_navigatablePaths == NULL)
                {
                    _MetadataBean->property_navigatablePaths = axutil_array_list_create(env, 10);
                }
                if(_MetadataBean->property_navigatablePaths == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for navigatablePaths");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_MetadataBean->property_navigatablePaths , env, arg_navigatablePaths);
                  _MetadataBean->is_valid_navigatablePaths = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the navigatablePaths array.
             */
            int AXIS2_CALL
            adb_MetadataBean_sizeof_navigatablePaths(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, -1);
                if(_MetadataBean->property_navigatablePaths == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_MetadataBean->property_navigatablePaths, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_remove_navigatablePaths_at(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env, int i)
            {
                return adb_MetadataBean_set_navigatablePaths_nil_at(_MetadataBean, env, i);
            }

            

           /**
            * resetter for navigatablePaths
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_navigatablePaths(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
                  if (_MetadataBean->property_navigatablePaths != NULL)
                  {
                      count = axutil_array_list_size(_MetadataBean->property_navigatablePaths, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_MetadataBean->property_navigatablePaths, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_WebResourcePath_free((adb_WebResourcePath_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_MetadataBean->property_navigatablePaths, env);
                  }
                _MetadataBean->is_valid_navigatablePaths = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether navigatablePaths is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_navigatablePaths_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_navigatablePaths;
           }

           /**
            * Set navigatablePaths to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_navigatablePaths_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_navigatablePaths(_MetadataBean, env);
           }

           
           /**
            * Check whether navigatablePaths is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_navigatablePaths_nil_at(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return (_MetadataBean->is_valid_navigatablePaths == AXIS2_FALSE ||
                        NULL == _MetadataBean->property_navigatablePaths || 
                        NULL == axutil_array_list_get(_MetadataBean->property_navigatablePaths, env, i));
           }

           /**
            * Set navigatablePaths to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_navigatablePaths_nil_at(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);

                if(_MetadataBean->property_navigatablePaths == NULL ||
                            _MetadataBean->is_valid_navigatablePaths == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_MetadataBean->property_navigatablePaths, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_MetadataBean->property_navigatablePaths, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of navigatablePaths is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_MetadataBean->property_navigatablePaths == NULL)
                {
                    _MetadataBean->is_valid_navigatablePaths = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_MetadataBean->property_navigatablePaths, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_WebResourcePath_free((adb_WebResourcePath_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _MetadataBean->is_valid_navigatablePaths = AXIS2_FALSE;
                        axutil_array_list_set(_MetadataBean->property_navigatablePaths , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_MetadataBean->property_navigatablePaths , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for path by  Property Number 11
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property11(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_path(_MetadataBean,
                                             env);
            }

            /**
             * getter for path.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_path(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_path;
             }

            /**
             * setter for path
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_path(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_path)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_path &&
                        arg_path == _MetadataBean->property_path)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_path(_MetadataBean, env);

                
                if(NULL == arg_path)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_path = (axis2_char_t *)axutil_strdup(env, arg_path);
                        if(NULL == _MetadataBean->property_path)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for path");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_path = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for path
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_path(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_path != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_path);
                     _MetadataBean->property_path = NULL;
                }
            
                
                
                _MetadataBean->is_valid_path = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether path is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_path_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_path;
           }

           /**
            * Set path to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_path_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_path(_MetadataBean, env);
           }

           

            /**
             * Getter for pathWithVersion by  Property Number 12
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property12(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_pathWithVersion(_MetadataBean,
                                             env);
            }

            /**
             * getter for pathWithVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_pathWithVersion(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_pathWithVersion;
             }

            /**
             * setter for pathWithVersion
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_pathWithVersion(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_pathWithVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_pathWithVersion &&
                        arg_pathWithVersion == _MetadataBean->property_pathWithVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_pathWithVersion(_MetadataBean, env);

                
                if(NULL == arg_pathWithVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_pathWithVersion = (axis2_char_t *)axutil_strdup(env, arg_pathWithVersion);
                        if(NULL == _MetadataBean->property_pathWithVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for pathWithVersion");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_pathWithVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for pathWithVersion
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_pathWithVersion(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_pathWithVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_pathWithVersion);
                     _MetadataBean->property_pathWithVersion = NULL;
                }
            
                
                
                _MetadataBean->is_valid_pathWithVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether pathWithVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_pathWithVersion_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_pathWithVersion;
           }

           /**
            * Set pathWithVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_pathWithVersion_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_pathWithVersion(_MetadataBean, env);
           }

           

            /**
             * Getter for permalink by  Property Number 13
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property13(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_permalink(_MetadataBean,
                                             env);
            }

            /**
             * getter for permalink.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_permalink(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_permalink;
             }

            /**
             * setter for permalink
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_permalink(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_permalink)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_permalink &&
                        arg_permalink == _MetadataBean->property_permalink)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_permalink(_MetadataBean, env);

                
                if(NULL == arg_permalink)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_permalink = (axis2_char_t *)axutil_strdup(env, arg_permalink);
                        if(NULL == _MetadataBean->property_permalink)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for permalink");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_permalink = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for permalink
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_permalink(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_permalink != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_permalink);
                     _MetadataBean->property_permalink = NULL;
                }
            
                
                
                _MetadataBean->is_valid_permalink = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether permalink is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_permalink_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_permalink;
           }

           /**
            * Set permalink to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_permalink_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_permalink(_MetadataBean, env);
           }

           

            /**
             * Getter for putAllowed by  Property Number 14
             */
            axis2_bool_t AXIS2_CALL
            adb_MetadataBean_get_property14(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_putAllowed(_MetadataBean,
                                             env);
            }

            /**
             * getter for putAllowed.
             */
            axis2_bool_t AXIS2_CALL
            adb_MetadataBean_get_putAllowed(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, (axis2_bool_t)0);
                  

                return _MetadataBean->property_putAllowed;
             }

            /**
             * setter for putAllowed
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_putAllowed(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_putAllowed)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_putAllowed &&
                        arg_putAllowed == _MetadataBean->property_putAllowed)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_putAllowed(_MetadataBean, env);

                _MetadataBean->property_putAllowed = arg_putAllowed;
                        _MetadataBean->is_valid_putAllowed = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for putAllowed
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_putAllowed(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               _MetadataBean->is_valid_putAllowed = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether putAllowed is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_putAllowed_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_putAllowed;
           }

           /**
            * Set putAllowed to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_putAllowed_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_putAllowed(_MetadataBean, env);
           }

           

            /**
             * Getter for serverBaseURL by  Property Number 15
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_property15(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_serverBaseURL(_MetadataBean,
                                             env);
            }

            /**
             * getter for serverBaseURL.
             */
            axis2_char_t* AXIS2_CALL
            adb_MetadataBean_get_serverBaseURL(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, NULL);
                  

                return _MetadataBean->property_serverBaseURL;
             }

            /**
             * setter for serverBaseURL
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_serverBaseURL(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serverBaseURL)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_serverBaseURL &&
                        arg_serverBaseURL == _MetadataBean->property_serverBaseURL)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_serverBaseURL(_MetadataBean, env);

                
                if(NULL == arg_serverBaseURL)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _MetadataBean->property_serverBaseURL = (axis2_char_t *)axutil_strdup(env, arg_serverBaseURL);
                        if(NULL == _MetadataBean->property_serverBaseURL)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serverBaseURL");
                            return AXIS2_FAILURE;
                        }
                        _MetadataBean->is_valid_serverBaseURL = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serverBaseURL
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_serverBaseURL(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               
            
                
                if(_MetadataBean->property_serverBaseURL != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _MetadataBean->property_serverBaseURL);
                     _MetadataBean->property_serverBaseURL = NULL;
                }
            
                
                
                _MetadataBean->is_valid_serverBaseURL = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serverBaseURL is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_serverBaseURL_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_serverBaseURL;
           }

           /**
            * Set serverBaseURL to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_serverBaseURL_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_serverBaseURL(_MetadataBean, env);
           }

           

            /**
             * Getter for versionView by  Property Number 16
             */
            axis2_bool_t AXIS2_CALL
            adb_MetadataBean_get_property16(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env)
            {
                return adb_MetadataBean_get_versionView(_MetadataBean,
                                             env);
            }

            /**
             * getter for versionView.
             */
            axis2_bool_t AXIS2_CALL
            adb_MetadataBean_get_versionView(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _MetadataBean, (axis2_bool_t)0);
                  

                return _MetadataBean->property_versionView;
             }

            /**
             * setter for versionView
             */
            axis2_status_t AXIS2_CALL
            adb_MetadataBean_set_versionView(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_versionView)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
                
                if(_MetadataBean->is_valid_versionView &&
                        arg_versionView == _MetadataBean->property_versionView)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_MetadataBean_reset_versionView(_MetadataBean, env);

                _MetadataBean->property_versionView = arg_versionView;
                        _MetadataBean->is_valid_versionView = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for versionView
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_reset_versionView(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_FAILURE);
               

               _MetadataBean->is_valid_versionView = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether versionView is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_MetadataBean_is_versionView_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _MetadataBean, AXIS2_TRUE);
               
               return !_MetadataBean->is_valid_versionView;
           }

           /**
            * Set versionView to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_MetadataBean_set_versionView_nil(
                   adb_MetadataBean_t* _MetadataBean,
                   const axutil_env_t *env)
           {
               return adb_MetadataBean_reset_versionView(_MetadataBean, env);
           }

           

