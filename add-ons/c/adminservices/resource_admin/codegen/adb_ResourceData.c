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
         * adb_ResourceData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_ResourceData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = ResourceData
                 * Namespace URI = http://common.registry.carbon.wso2.org/xsd
                 * Namespace Prefix = ns4
                 */
           


        struct adb_ResourceData
        {
            axis2_char_t *property_Type;

            axis2_char_t* property_absent;

                
                axis2_bool_t is_valid_absent;
            axis2_char_t* property_authorUserName;

                
                axis2_bool_t is_valid_authorUserName;
            float property_averageRating;

                
                axis2_bool_t is_valid_averageRating;
            axutil_array_list_t* property_averageStars;

                
                axis2_bool_t is_valid_averageStars;
            axutil_date_time_t* property_createdOn;

                
                axis2_bool_t is_valid_createdOn;
            axis2_bool_t property_deleteAllowed;

                
                axis2_bool_t is_valid_deleteAllowed;
            axis2_char_t* property_description;

                
                axis2_bool_t is_valid_description;
            axis2_bool_t property_externalLink;

                
                axis2_bool_t is_valid_externalLink;
            axis2_char_t* property_formattedCreatedOn;

                
                axis2_bool_t is_valid_formattedCreatedOn;
            axis2_bool_t property_getAllowed;

                
                axis2_bool_t is_valid_getAllowed;
            axis2_bool_t property_link;

                
                axis2_bool_t is_valid_link;
            axis2_bool_t property_mounted;

                
                axis2_bool_t is_valid_mounted;
            axis2_char_t* property_name;

                
                axis2_bool_t is_valid_name;
            axis2_bool_t property_putAllowed;

                
                axis2_bool_t is_valid_putAllowed;
            axis2_char_t* property_realPath;

                
                axis2_bool_t is_valid_realPath;
            axis2_char_t* property_relativePath;

                
                axis2_bool_t is_valid_relativePath;
            axis2_char_t* property_resourcePath;

                
                axis2_bool_t is_valid_resourcePath;
            axis2_char_t* property_resourceType;

                
                axis2_bool_t is_valid_resourceType;
            axutil_array_list_t* property_tagCounts;

                
                axis2_bool_t is_valid_tagCounts;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_ResourceData_set_averageRating_nil(
                        adb_ResourceData_t* _ResourceData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ResourceData_set_deleteAllowed_nil(
                        adb_ResourceData_t* _ResourceData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ResourceData_set_externalLink_nil(
                        adb_ResourceData_t* _ResourceData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ResourceData_set_getAllowed_nil(
                        adb_ResourceData_t* _ResourceData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ResourceData_set_link_nil(
                        adb_ResourceData_t* _ResourceData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ResourceData_set_mounted_nil(
                        adb_ResourceData_t* _ResourceData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ResourceData_set_putAllowed_nil(
                        adb_ResourceData_t* _ResourceData,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_ResourceData_t* AXIS2_CALL
        adb_ResourceData_create(
            const axutil_env_t *env)
        {
            adb_ResourceData_t *_ResourceData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _ResourceData = (adb_ResourceData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_ResourceData_t));

            if(NULL == _ResourceData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_ResourceData, 0, sizeof(adb_ResourceData_t));

            _ResourceData->property_Type = axutil_strdup(env, "adb_ResourceData");
            _ResourceData->property_absent  = NULL;
                  _ResourceData->is_valid_absent  = AXIS2_FALSE;
            _ResourceData->property_authorUserName  = NULL;
                  _ResourceData->is_valid_authorUserName  = AXIS2_FALSE;
            _ResourceData->is_valid_averageRating  = AXIS2_FALSE;
            _ResourceData->property_averageStars  = NULL;
                  _ResourceData->is_valid_averageStars  = AXIS2_FALSE;
            _ResourceData->property_createdOn  = NULL;
                  _ResourceData->is_valid_createdOn  = AXIS2_FALSE;
            _ResourceData->is_valid_deleteAllowed  = AXIS2_FALSE;
            _ResourceData->property_description  = NULL;
                  _ResourceData->is_valid_description  = AXIS2_FALSE;
            _ResourceData->is_valid_externalLink  = AXIS2_FALSE;
            _ResourceData->property_formattedCreatedOn  = NULL;
                  _ResourceData->is_valid_formattedCreatedOn  = AXIS2_FALSE;
            _ResourceData->is_valid_getAllowed  = AXIS2_FALSE;
            _ResourceData->is_valid_link  = AXIS2_FALSE;
            _ResourceData->is_valid_mounted  = AXIS2_FALSE;
            _ResourceData->property_name  = NULL;
                  _ResourceData->is_valid_name  = AXIS2_FALSE;
            _ResourceData->is_valid_putAllowed  = AXIS2_FALSE;
            _ResourceData->property_realPath  = NULL;
                  _ResourceData->is_valid_realPath  = AXIS2_FALSE;
            _ResourceData->property_relativePath  = NULL;
                  _ResourceData->is_valid_relativePath  = AXIS2_FALSE;
            _ResourceData->property_resourcePath  = NULL;
                  _ResourceData->is_valid_resourcePath  = AXIS2_FALSE;
            _ResourceData->property_resourceType  = NULL;
                  _ResourceData->is_valid_resourceType  = AXIS2_FALSE;
            _ResourceData->property_tagCounts  = NULL;
                  _ResourceData->is_valid_tagCounts  = AXIS2_FALSE;
            

            return _ResourceData;
        }

        adb_ResourceData_t* AXIS2_CALL
        adb_ResourceData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _absent,
                axis2_char_t* _authorUserName,
                float _averageRating,
                axutil_array_list_t* _averageStars,
                axutil_date_time_t* _createdOn,
                axis2_bool_t _deleteAllowed,
                axis2_char_t* _description,
                axis2_bool_t _externalLink,
                axis2_char_t* _formattedCreatedOn,
                axis2_bool_t _getAllowed,
                axis2_bool_t _link,
                axis2_bool_t _mounted,
                axis2_char_t* _name,
                axis2_bool_t _putAllowed,
                axis2_char_t* _realPath,
                axis2_char_t* _relativePath,
                axis2_char_t* _resourcePath,
                axis2_char_t* _resourceType,
                axutil_array_list_t* _tagCounts)
        {
            adb_ResourceData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_ResourceData_create(env);

            
              status = adb_ResourceData_set_absent(
                                     adb_obj,
                                     env,
                                     _absent);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_authorUserName(
                                     adb_obj,
                                     env,
                                     _authorUserName);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_averageRating(
                                     adb_obj,
                                     env,
                                     _averageRating);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_averageStars(
                                     adb_obj,
                                     env,
                                     _averageStars);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_createdOn(
                                     adb_obj,
                                     env,
                                     _createdOn);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_deleteAllowed(
                                     adb_obj,
                                     env,
                                     _deleteAllowed);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_description(
                                     adb_obj,
                                     env,
                                     _description);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_externalLink(
                                     adb_obj,
                                     env,
                                     _externalLink);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_formattedCreatedOn(
                                     adb_obj,
                                     env,
                                     _formattedCreatedOn);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_getAllowed(
                                     adb_obj,
                                     env,
                                     _getAllowed);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_link(
                                     adb_obj,
                                     env,
                                     _link);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_mounted(
                                     adb_obj,
                                     env,
                                     _mounted);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_name(
                                     adb_obj,
                                     env,
                                     _name);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_putAllowed(
                                     adb_obj,
                                     env,
                                     _putAllowed);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_realPath(
                                     adb_obj,
                                     env,
                                     _realPath);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_relativePath(
                                     adb_obj,
                                     env,
                                     _relativePath);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_resourcePath(
                                     adb_obj,
                                     env,
                                     _resourcePath);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_resourceType(
                                     adb_obj,
                                     env,
                                     _resourceType);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ResourceData_set_tagCounts(
                                     adb_obj,
                                     env,
                                     _tagCounts);
              if(status == AXIS2_FAILURE) {
                  adb_ResourceData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_ResourceData_free_popping_value(
                        adb_ResourceData_t* _ResourceData,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _ResourceData->property_absent;

                    _ResourceData->property_absent = (axis2_char_t*)NULL;
                    adb_ResourceData_free(_ResourceData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_ResourceData_free(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _ResourceData,
                env,
                "adb_ResourceData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ResourceData_free_obj(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);

            if (_ResourceData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _ResourceData->property_Type);
            }

            adb_ResourceData_reset_absent(_ResourceData, env);
            adb_ResourceData_reset_authorUserName(_ResourceData, env);
            adb_ResourceData_reset_averageRating(_ResourceData, env);
            adb_ResourceData_reset_averageStars(_ResourceData, env);
            adb_ResourceData_reset_createdOn(_ResourceData, env);
            adb_ResourceData_reset_deleteAllowed(_ResourceData, env);
            adb_ResourceData_reset_description(_ResourceData, env);
            adb_ResourceData_reset_externalLink(_ResourceData, env);
            adb_ResourceData_reset_formattedCreatedOn(_ResourceData, env);
            adb_ResourceData_reset_getAllowed(_ResourceData, env);
            adb_ResourceData_reset_link(_ResourceData, env);
            adb_ResourceData_reset_mounted(_ResourceData, env);
            adb_ResourceData_reset_name(_ResourceData, env);
            adb_ResourceData_reset_putAllowed(_ResourceData, env);
            adb_ResourceData_reset_realPath(_ResourceData, env);
            adb_ResourceData_reset_relativePath(_ResourceData, env);
            adb_ResourceData_reset_resourcePath(_ResourceData, env);
            adb_ResourceData_reset_resourceType(_ResourceData, env);
            adb_ResourceData_reset_tagCounts(_ResourceData, env);
            

            if(_ResourceData)
            {
                AXIS2_FREE(env->allocator, _ResourceData);
                _ResourceData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_ResourceData_deserialize(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _ResourceData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_ResourceData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ResourceData_deserialize_obj(
                adb_ResourceData_t* _ResourceData,
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
            AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for ResourceData : "
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
                                   
                                 element_qname = axutil_qname_create(env, "absent", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ResourceData_set_absent(_ResourceData, env,
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
                      * building authorUserName element
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
                                 
                                 element_qname = axutil_qname_create(env, "authorUserName", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ResourceData_set_authorUserName(_ResourceData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for authorUserName ");
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
                      * building averageRating element
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
                                 
                                 element_qname = axutil_qname_create(env, "averageRating", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ResourceData_set_averageRating(_ResourceData, env,
                                                                   atof(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element averageRating");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for averageRating ");
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
                     * building averageStars array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building averageStars element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "averageStars", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for averageStars ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "averageStars (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_ResourceData_set_averageStars(_ResourceData, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building createdOn element
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
                                 
                                 element_qname = axutil_qname_create(env, "createdOn", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                          element = (void*)axutil_date_time_create(env);
                                          status = axutil_date_time_deserialize_date_time((axutil_date_time_t*)element, env,
                                                                          text_value);
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              if(element != NULL)
                                              {
                                                  axutil_date_time_free((axutil_date_time_t*)element, env);
                                              }
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element createdOn ");
                                          }
                                          else
                                          {
                                            status = adb_ResourceData_set_createdOn(_ResourceData, env,
                                                                       (axutil_date_time_t*)element);
                                          }
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for createdOn ");
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
                      * building deleteAllowed element
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
                                 
                                 element_qname = axutil_qname_create(env, "deleteAllowed", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ResourceData_set_deleteAllowed(_ResourceData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ResourceData_set_deleteAllowed(_ResourceData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element deleteAllowed");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for deleteAllowed ");
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
                                 
                                 element_qname = axutil_qname_create(env, "description", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ResourceData_set_description(_ResourceData, env,
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
                      * building externalLink element
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
                                 
                                 element_qname = axutil_qname_create(env, "externalLink", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ResourceData_set_externalLink(_ResourceData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ResourceData_set_externalLink(_ResourceData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element externalLink");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for externalLink ");
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
                                 
                                 element_qname = axutil_qname_create(env, "formattedCreatedOn", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ResourceData_set_formattedCreatedOn(_ResourceData, env,
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
                      * building getAllowed element
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
                                 
                                 element_qname = axutil_qname_create(env, "getAllowed", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ResourceData_set_getAllowed(_ResourceData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ResourceData_set_getAllowed(_ResourceData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element getAllowed");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for getAllowed ");
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
                      * building link element
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
                                 
                                 element_qname = axutil_qname_create(env, "link", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ResourceData_set_link(_ResourceData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ResourceData_set_link(_ResourceData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element link");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for link ");
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
                      * building mounted element
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
                                 
                                 element_qname = axutil_qname_create(env, "mounted", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ResourceData_set_mounted(_ResourceData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ResourceData_set_mounted(_ResourceData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element mounted");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for mounted ");
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
                      * building name element
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
                                 
                                 element_qname = axutil_qname_create(env, "name", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ResourceData_set_name(_ResourceData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for name ");
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
                                 
                                 element_qname = axutil_qname_create(env, "putAllowed", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ResourceData_set_putAllowed(_ResourceData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ResourceData_set_putAllowed(_ResourceData, env,
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
                                 
                                 element_qname = axutil_qname_create(env, "realPath", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ResourceData_set_realPath(_ResourceData, env,
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
                      * building relativePath element
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
                                 
                                 element_qname = axutil_qname_create(env, "relativePath", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ResourceData_set_relativePath(_ResourceData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for relativePath ");
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
                      * building resourcePath element
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
                                 
                                 element_qname = axutil_qname_create(env, "resourcePath", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ResourceData_set_resourcePath(_ResourceData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for resourcePath ");
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
                      * building resourceType element
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
                                 
                                 element_qname = axutil_qname_create(env, "resourceType", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ResourceData_set_resourceType(_ResourceData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for resourceType ");
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
                     * building tagCounts array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building tagCounts element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "tagCounts", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if (adb_TagCount_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_TagCount");
                                          
                                          status =  adb_TagCount_deserialize((adb_TagCount_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element tagCounts ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for tagCounts ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "tagCounts (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_ResourceData_set_tagCounts(_ResourceData, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_ResourceData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_ResourceData_declare_parent_namespaces(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_ResourceData_serialize(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_ResourceData == NULL)
            {
                return adb_ResourceData_serialize_obj(
                    _ResourceData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _ResourceData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_ResourceData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_ResourceData_serialize_obj(
                adb_ResourceData_t* _ResourceData,
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
                    
                    axis2_char_t text_value_6[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_7;
                    axis2_char_t *text_value_7_temp;
                    
                    axis2_char_t text_value_8[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_9;
                    axis2_char_t *text_value_9_temp;
                    
                    axis2_char_t text_value_10[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_11[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_12[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_13;
                    axis2_char_t *text_value_13_temp;
                    
                    axis2_char_t text_value_14[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_15;
                    axis2_char_t *text_value_15_temp;
                    
                    axis2_char_t *text_value_16;
                    axis2_char_t *text_value_16_temp;
                    
                    axis2_char_t *text_value_17;
                    axis2_char_t *text_value_17_temp;
                    
                    axis2_char_t *text_value_18;
                    axis2_char_t *text_value_18_temp;
                    
                    axis2_char_t text_value_19[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"ResourceData\"", NULL);
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
                                 "http://common.registry.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "ResourceData", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_absent)
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
                    
                           text_value_1 = _ResourceData->property_absent;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_authorUserName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("authorUserName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("authorUserName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing authorUserName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sauthorUserName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sauthorUserName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _ResourceData->property_authorUserName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_averageRating)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("averageRating"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("averageRating")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing averageRating element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%saverageRating>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%saverageRating>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_3, "%f", (float)_ResourceData->property_averageRating);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_averageStars)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("averageStars"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("averageStars")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing averageStars array
                      */
                     if (_ResourceData->property_averageStars != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%saverageStars>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%saverageStars>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_ResourceData->property_averageStars, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_ResourceData->property_averageStars, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing averageStars element
                      */

                    
                    
                           text_value_4 = (axis2_char_t*)element;
                           
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
                           
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_createdOn)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("createdOn"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("createdOn")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing createdOn element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%screatedOn>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%screatedOn>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                          text_value_5 = axutil_date_time_serialize_date_time(_ResourceData->property_createdOn, env);
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_5, axutil_strlen(text_value_5));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_deleteAllowed)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("deleteAllowed"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("deleteAllowed")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing deleteAllowed element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdeleteAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdeleteAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_6, (_ResourceData->property_deleteAllowed)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_6, axutil_strlen(text_value_6));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_description)
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
                    
                           text_value_7 = _ResourceData->property_description;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_externalLink)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("externalLink"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("externalLink")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing externalLink element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sexternalLink>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sexternalLink>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_8, (_ResourceData->property_externalLink)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_8, axutil_strlen(text_value_8));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_formattedCreatedOn)
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
                    
                           text_value_9 = _ResourceData->property_formattedCreatedOn;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_getAllowed)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("getAllowed"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("getAllowed")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing getAllowed element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sgetAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sgetAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_10, (_ResourceData->property_getAllowed)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_10, axutil_strlen(text_value_10));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_link)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("link"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("link")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing link element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slink>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slink>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_11, (_ResourceData->property_link)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_11, axutil_strlen(text_value_11));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_mounted)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("mounted"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("mounted")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing mounted element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%smounted>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%smounted>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_12, (_ResourceData->property_mounted)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_12, axutil_strlen(text_value_12));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_name)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("name"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("name")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing name element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sname>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sname>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_13 = _ResourceData->property_name;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_putAllowed)
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
                    
                           strcpy(text_value_14, (_ResourceData->property_putAllowed)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_14, axutil_strlen(text_value_14));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_realPath)
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
                    
                           text_value_15 = _ResourceData->property_realPath;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_relativePath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("relativePath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("relativePath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing relativePath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%srelativePath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%srelativePath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_16 = _ResourceData->property_relativePath;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_16_temp = axutil_xml_quote_string(env, text_value_16, AXIS2_TRUE);
                           if (text_value_16_temp)
                           {
                               axutil_stream_write(stream, env, text_value_16_temp, axutil_strlen(text_value_16_temp));
                               AXIS2_FREE(env->allocator, text_value_16_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_16, axutil_strlen(text_value_16));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_resourcePath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("resourcePath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("resourcePath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing resourcePath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sresourcePath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sresourcePath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_17 = _ResourceData->property_resourcePath;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_17_temp = axutil_xml_quote_string(env, text_value_17, AXIS2_TRUE);
                           if (text_value_17_temp)
                           {
                               axutil_stream_write(stream, env, text_value_17_temp, axutil_strlen(text_value_17_temp));
                               AXIS2_FREE(env->allocator, text_value_17_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_17, axutil_strlen(text_value_17));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_resourceType)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("resourceType"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("resourceType")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing resourceType element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sresourceType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sresourceType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_18 = _ResourceData->property_resourceType;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_18_temp = axutil_xml_quote_string(env, text_value_18, AXIS2_TRUE);
                           if (text_value_18_temp)
                           {
                               axutil_stream_write(stream, env, text_value_18_temp, axutil_strlen(text_value_18_temp));
                               AXIS2_FREE(env->allocator, text_value_18_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_18, axutil_strlen(text_value_18));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ResourceData->is_valid_tagCounts)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("tagCounts"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("tagCounts")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing tagCounts array
                      */
                     if (_ResourceData->property_tagCounts != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%stagCounts",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%stagCounts>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_ResourceData->property_tagCounts, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_ResourceData->property_tagCounts, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing tagCounts element
                      */

                    
                     
                            if(!adb_TagCount_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_TagCount_serialize((adb_TagCount_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_TagCount_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_TagCount_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for absent by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_property1(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_absent(_ResourceData,
                                             env);
            }

            /**
             * getter for absent.
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_absent(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_absent;
             }

            /**
             * setter for absent
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_absent(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_absent)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_absent &&
                        arg_absent == _ResourceData->property_absent)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_absent(_ResourceData, env);

                
                if(NULL == arg_absent)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_absent = (axis2_char_t *)axutil_strdup(env, arg_absent);
                        if(NULL == _ResourceData->property_absent)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for absent");
                            return AXIS2_FAILURE;
                        }
                        _ResourceData->is_valid_absent = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for absent
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_absent(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
            
                
                if(_ResourceData->property_absent != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ResourceData->property_absent);
                     _ResourceData->property_absent = NULL;
                }
            
                
                
                _ResourceData->is_valid_absent = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether absent is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_absent_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_absent;
           }

           /**
            * Set absent to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_absent_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_absent(_ResourceData, env);
           }

           

            /**
             * Getter for authorUserName by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_property2(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_authorUserName(_ResourceData,
                                             env);
            }

            /**
             * getter for authorUserName.
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_authorUserName(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_authorUserName;
             }

            /**
             * setter for authorUserName
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_authorUserName(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_authorUserName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_authorUserName &&
                        arg_authorUserName == _ResourceData->property_authorUserName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_authorUserName(_ResourceData, env);

                
                if(NULL == arg_authorUserName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_authorUserName = (axis2_char_t *)axutil_strdup(env, arg_authorUserName);
                        if(NULL == _ResourceData->property_authorUserName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for authorUserName");
                            return AXIS2_FAILURE;
                        }
                        _ResourceData->is_valid_authorUserName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for authorUserName
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_authorUserName(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
            
                
                if(_ResourceData->property_authorUserName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ResourceData->property_authorUserName);
                     _ResourceData->property_authorUserName = NULL;
                }
            
                
                
                _ResourceData->is_valid_authorUserName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether authorUserName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_authorUserName_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_authorUserName;
           }

           /**
            * Set authorUserName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_authorUserName_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_authorUserName(_ResourceData, env);
           }

           

            /**
             * Getter for averageRating by  Property Number 3
             */
            float AXIS2_CALL
            adb_ResourceData_get_property3(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_averageRating(_ResourceData,
                                             env);
            }

            /**
             * getter for averageRating.
             */
            float AXIS2_CALL
            adb_ResourceData_get_averageRating(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (float)0);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, (float)0);
                  

                return _ResourceData->property_averageRating;
             }

            /**
             * setter for averageRating
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_averageRating(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    const float  arg_averageRating)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_averageRating &&
                        arg_averageRating == _ResourceData->property_averageRating)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_averageRating(_ResourceData, env);

                _ResourceData->property_averageRating = arg_averageRating;
                        _ResourceData->is_valid_averageRating = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for averageRating
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_averageRating(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               _ResourceData->is_valid_averageRating = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether averageRating is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_averageRating_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_averageRating;
           }

           /**
            * Set averageRating to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_averageRating_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_averageRating(_ResourceData, env);
           }

           

            /**
             * Getter for averageStars by  Property Number 4
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ResourceData_get_property4(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_averageStars(_ResourceData,
                                             env);
            }

            /**
             * getter for averageStars.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ResourceData_get_averageStars(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_averageStars;
             }

            /**
             * setter for averageStars
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_averageStars(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_averageStars)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_averageStars &&
                        arg_averageStars == _ResourceData->property_averageStars)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_averageStars, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "averageStars has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_averageStars, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_ResourceData_reset_averageStars(_ResourceData, env);

                
                if(NULL == arg_averageStars)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_averageStars = arg_averageStars;
                        if(non_nil_exists)
                        {
                            _ResourceData->is_valid_averageStars = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of averageStars.
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_averageStars_at(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                if(_ResourceData->property_averageStars == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_ResourceData->property_averageStars, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of averageStars.
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_averageStars_at(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_averageStars)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if( _ResourceData->is_valid_averageStars &&
                    _ResourceData->property_averageStars &&
                
                    arg_averageStars == (axis2_char_t*)axutil_array_list_get(_ResourceData->property_averageStars, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_averageStars)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_ResourceData->property_averageStars != NULL)
                        {
                            size = axutil_array_list_size(_ResourceData->property_averageStars, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_ResourceData->property_averageStars, env, i))
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
                  

                if(_ResourceData->property_averageStars == NULL)
                {
                    _ResourceData->property_averageStars = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_ResourceData->property_averageStars, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ResourceData->is_valid_averageStars = AXIS2_FALSE;
                        axutil_array_list_set(_ResourceData->property_averageStars , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_ResourceData->property_averageStars , env, i, axutil_strdup(env, arg_averageStars));
                  _ResourceData->is_valid_averageStars = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to averageStars.
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_add_averageStars(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_averageStars)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);

                
                    if(NULL == arg_averageStars)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_ResourceData->property_averageStars == NULL)
                {
                    _ResourceData->property_averageStars = axutil_array_list_create(env, 10);
                }
                if(_ResourceData->property_averageStars == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for averageStars");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_ResourceData->property_averageStars , env, axutil_strdup(env, arg_averageStars));
                  _ResourceData->is_valid_averageStars = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the averageStars array.
             */
            int AXIS2_CALL
            adb_ResourceData_sizeof_averageStars(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, -1);
                if(_ResourceData->property_averageStars == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_ResourceData->property_averageStars, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_remove_averageStars_at(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env, int i)
            {
                return adb_ResourceData_set_averageStars_nil_at(_ResourceData, env, i);
            }

            

           /**
            * resetter for averageStars
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_averageStars(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
                  if (_ResourceData->property_averageStars != NULL)
                  {
                      count = axutil_array_list_size(_ResourceData->property_averageStars, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_ResourceData->property_averageStars, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_ResourceData->property_averageStars, env);
                  }
                _ResourceData->is_valid_averageStars = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether averageStars is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_averageStars_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_averageStars;
           }

           /**
            * Set averageStars to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_averageStars_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_averageStars(_ResourceData, env);
           }

           
           /**
            * Check whether averageStars is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_averageStars_nil_at(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return (_ResourceData->is_valid_averageStars == AXIS2_FALSE ||
                        NULL == _ResourceData->property_averageStars || 
                        NULL == axutil_array_list_get(_ResourceData->property_averageStars, env, i));
           }

           /**
            * Set averageStars to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_averageStars_nil_at(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);

                if(_ResourceData->property_averageStars == NULL ||
                            _ResourceData->is_valid_averageStars == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_ResourceData->property_averageStars, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_ResourceData->property_averageStars, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of averageStars is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_ResourceData->property_averageStars == NULL)
                {
                    _ResourceData->is_valid_averageStars = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_ResourceData->property_averageStars, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ResourceData->is_valid_averageStars = AXIS2_FALSE;
                        axutil_array_list_set(_ResourceData->property_averageStars , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_ResourceData->property_averageStars , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for createdOn by  Property Number 5
             */
            axutil_date_time_t* AXIS2_CALL
            adb_ResourceData_get_property5(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_createdOn(_ResourceData,
                                             env);
            }

            /**
             * getter for createdOn.
             */
            axutil_date_time_t* AXIS2_CALL
            adb_ResourceData_get_createdOn(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_createdOn;
             }

            /**
             * setter for createdOn
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_createdOn(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    axutil_date_time_t*  arg_createdOn)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_createdOn &&
                        arg_createdOn == _ResourceData->property_createdOn)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_createdOn(_ResourceData, env);

                
                if(NULL == arg_createdOn)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_createdOn = arg_createdOn;
                        _ResourceData->is_valid_createdOn = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for createdOn
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_createdOn(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
            
                
                if(_ResourceData->property_createdOn != NULL)
                {
                   
                   
                      axutil_date_time_free(_ResourceData->property_createdOn, env);
                     _ResourceData->property_createdOn = NULL;
                }
            
                
                
                _ResourceData->is_valid_createdOn = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether createdOn is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_createdOn_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_createdOn;
           }

           /**
            * Set createdOn to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_createdOn_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_createdOn(_ResourceData, env);
           }

           

            /**
             * Getter for deleteAllowed by  Property Number 6
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_property6(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_deleteAllowed(_ResourceData,
                                             env);
            }

            /**
             * getter for deleteAllowed.
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_deleteAllowed(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, (axis2_bool_t)0);
                  

                return _ResourceData->property_deleteAllowed;
             }

            /**
             * setter for deleteAllowed
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_deleteAllowed(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_deleteAllowed)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_deleteAllowed &&
                        arg_deleteAllowed == _ResourceData->property_deleteAllowed)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_deleteAllowed(_ResourceData, env);

                _ResourceData->property_deleteAllowed = arg_deleteAllowed;
                        _ResourceData->is_valid_deleteAllowed = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for deleteAllowed
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_deleteAllowed(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               _ResourceData->is_valid_deleteAllowed = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether deleteAllowed is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_deleteAllowed_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_deleteAllowed;
           }

           /**
            * Set deleteAllowed to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_deleteAllowed_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_deleteAllowed(_ResourceData, env);
           }

           

            /**
             * Getter for description by  Property Number 7
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_property7(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_description(_ResourceData,
                                             env);
            }

            /**
             * getter for description.
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_description(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_description;
             }

            /**
             * setter for description
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_description(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_description)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_description &&
                        arg_description == _ResourceData->property_description)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_description(_ResourceData, env);

                
                if(NULL == arg_description)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_description = (axis2_char_t *)axutil_strdup(env, arg_description);
                        if(NULL == _ResourceData->property_description)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for description");
                            return AXIS2_FAILURE;
                        }
                        _ResourceData->is_valid_description = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for description
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_description(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
            
                
                if(_ResourceData->property_description != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ResourceData->property_description);
                     _ResourceData->property_description = NULL;
                }
            
                
                
                _ResourceData->is_valid_description = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether description is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_description_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_description;
           }

           /**
            * Set description to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_description_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_description(_ResourceData, env);
           }

           

            /**
             * Getter for externalLink by  Property Number 8
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_property8(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_externalLink(_ResourceData,
                                             env);
            }

            /**
             * getter for externalLink.
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_externalLink(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, (axis2_bool_t)0);
                  

                return _ResourceData->property_externalLink;
             }

            /**
             * setter for externalLink
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_externalLink(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_externalLink)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_externalLink &&
                        arg_externalLink == _ResourceData->property_externalLink)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_externalLink(_ResourceData, env);

                _ResourceData->property_externalLink = arg_externalLink;
                        _ResourceData->is_valid_externalLink = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for externalLink
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_externalLink(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               _ResourceData->is_valid_externalLink = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether externalLink is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_externalLink_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_externalLink;
           }

           /**
            * Set externalLink to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_externalLink_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_externalLink(_ResourceData, env);
           }

           

            /**
             * Getter for formattedCreatedOn by  Property Number 9
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_property9(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_formattedCreatedOn(_ResourceData,
                                             env);
            }

            /**
             * getter for formattedCreatedOn.
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_formattedCreatedOn(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_formattedCreatedOn;
             }

            /**
             * setter for formattedCreatedOn
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_formattedCreatedOn(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_formattedCreatedOn)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_formattedCreatedOn &&
                        arg_formattedCreatedOn == _ResourceData->property_formattedCreatedOn)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_formattedCreatedOn(_ResourceData, env);

                
                if(NULL == arg_formattedCreatedOn)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_formattedCreatedOn = (axis2_char_t *)axutil_strdup(env, arg_formattedCreatedOn);
                        if(NULL == _ResourceData->property_formattedCreatedOn)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for formattedCreatedOn");
                            return AXIS2_FAILURE;
                        }
                        _ResourceData->is_valid_formattedCreatedOn = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for formattedCreatedOn
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_formattedCreatedOn(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
            
                
                if(_ResourceData->property_formattedCreatedOn != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ResourceData->property_formattedCreatedOn);
                     _ResourceData->property_formattedCreatedOn = NULL;
                }
            
                
                
                _ResourceData->is_valid_formattedCreatedOn = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether formattedCreatedOn is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_formattedCreatedOn_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_formattedCreatedOn;
           }

           /**
            * Set formattedCreatedOn to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_formattedCreatedOn_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_formattedCreatedOn(_ResourceData, env);
           }

           

            /**
             * Getter for getAllowed by  Property Number 10
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_property10(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_getAllowed(_ResourceData,
                                             env);
            }

            /**
             * getter for getAllowed.
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_getAllowed(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, (axis2_bool_t)0);
                  

                return _ResourceData->property_getAllowed;
             }

            /**
             * setter for getAllowed
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_getAllowed(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_getAllowed)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_getAllowed &&
                        arg_getAllowed == _ResourceData->property_getAllowed)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_getAllowed(_ResourceData, env);

                _ResourceData->property_getAllowed = arg_getAllowed;
                        _ResourceData->is_valid_getAllowed = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for getAllowed
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_getAllowed(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               _ResourceData->is_valid_getAllowed = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether getAllowed is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_getAllowed_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_getAllowed;
           }

           /**
            * Set getAllowed to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_getAllowed_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_getAllowed(_ResourceData, env);
           }

           

            /**
             * Getter for link by  Property Number 11
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_property11(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_link(_ResourceData,
                                             env);
            }

            /**
             * getter for link.
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_link(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, (axis2_bool_t)0);
                  

                return _ResourceData->property_link;
             }

            /**
             * setter for link
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_link(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_link)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_link &&
                        arg_link == _ResourceData->property_link)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_link(_ResourceData, env);

                _ResourceData->property_link = arg_link;
                        _ResourceData->is_valid_link = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for link
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_link(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               _ResourceData->is_valid_link = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether link is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_link_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_link;
           }

           /**
            * Set link to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_link_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_link(_ResourceData, env);
           }

           

            /**
             * Getter for mounted by  Property Number 12
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_property12(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_mounted(_ResourceData,
                                             env);
            }

            /**
             * getter for mounted.
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_mounted(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, (axis2_bool_t)0);
                  

                return _ResourceData->property_mounted;
             }

            /**
             * setter for mounted
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_mounted(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_mounted)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_mounted &&
                        arg_mounted == _ResourceData->property_mounted)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_mounted(_ResourceData, env);

                _ResourceData->property_mounted = arg_mounted;
                        _ResourceData->is_valid_mounted = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for mounted
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_mounted(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               _ResourceData->is_valid_mounted = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether mounted is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_mounted_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_mounted;
           }

           /**
            * Set mounted to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_mounted_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_mounted(_ResourceData, env);
           }

           

            /**
             * Getter for name by  Property Number 13
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_property13(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_name(_ResourceData,
                                             env);
            }

            /**
             * getter for name.
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_name(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_name;
             }

            /**
             * setter for name
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_name(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_name)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_name &&
                        arg_name == _ResourceData->property_name)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_name(_ResourceData, env);

                
                if(NULL == arg_name)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_name = (axis2_char_t *)axutil_strdup(env, arg_name);
                        if(NULL == _ResourceData->property_name)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for name");
                            return AXIS2_FAILURE;
                        }
                        _ResourceData->is_valid_name = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for name
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_name(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
            
                
                if(_ResourceData->property_name != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ResourceData->property_name);
                     _ResourceData->property_name = NULL;
                }
            
                
                
                _ResourceData->is_valid_name = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether name is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_name_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_name;
           }

           /**
            * Set name to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_name_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_name(_ResourceData, env);
           }

           

            /**
             * Getter for putAllowed by  Property Number 14
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_property14(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_putAllowed(_ResourceData,
                                             env);
            }

            /**
             * getter for putAllowed.
             */
            axis2_bool_t AXIS2_CALL
            adb_ResourceData_get_putAllowed(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, (axis2_bool_t)0);
                  

                return _ResourceData->property_putAllowed;
             }

            /**
             * setter for putAllowed
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_putAllowed(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_putAllowed)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_putAllowed &&
                        arg_putAllowed == _ResourceData->property_putAllowed)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_putAllowed(_ResourceData, env);

                _ResourceData->property_putAllowed = arg_putAllowed;
                        _ResourceData->is_valid_putAllowed = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for putAllowed
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_putAllowed(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               _ResourceData->is_valid_putAllowed = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether putAllowed is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_putAllowed_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_putAllowed;
           }

           /**
            * Set putAllowed to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_putAllowed_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_putAllowed(_ResourceData, env);
           }

           

            /**
             * Getter for realPath by  Property Number 15
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_property15(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_realPath(_ResourceData,
                                             env);
            }

            /**
             * getter for realPath.
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_realPath(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_realPath;
             }

            /**
             * setter for realPath
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_realPath(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_realPath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_realPath &&
                        arg_realPath == _ResourceData->property_realPath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_realPath(_ResourceData, env);

                
                if(NULL == arg_realPath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_realPath = (axis2_char_t *)axutil_strdup(env, arg_realPath);
                        if(NULL == _ResourceData->property_realPath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for realPath");
                            return AXIS2_FAILURE;
                        }
                        _ResourceData->is_valid_realPath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for realPath
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_realPath(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
            
                
                if(_ResourceData->property_realPath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ResourceData->property_realPath);
                     _ResourceData->property_realPath = NULL;
                }
            
                
                
                _ResourceData->is_valid_realPath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether realPath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_realPath_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_realPath;
           }

           /**
            * Set realPath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_realPath_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_realPath(_ResourceData, env);
           }

           

            /**
             * Getter for relativePath by  Property Number 16
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_property16(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_relativePath(_ResourceData,
                                             env);
            }

            /**
             * getter for relativePath.
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_relativePath(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_relativePath;
             }

            /**
             * setter for relativePath
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_relativePath(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_relativePath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_relativePath &&
                        arg_relativePath == _ResourceData->property_relativePath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_relativePath(_ResourceData, env);

                
                if(NULL == arg_relativePath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_relativePath = (axis2_char_t *)axutil_strdup(env, arg_relativePath);
                        if(NULL == _ResourceData->property_relativePath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for relativePath");
                            return AXIS2_FAILURE;
                        }
                        _ResourceData->is_valid_relativePath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for relativePath
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_relativePath(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
            
                
                if(_ResourceData->property_relativePath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ResourceData->property_relativePath);
                     _ResourceData->property_relativePath = NULL;
                }
            
                
                
                _ResourceData->is_valid_relativePath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether relativePath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_relativePath_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_relativePath;
           }

           /**
            * Set relativePath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_relativePath_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_relativePath(_ResourceData, env);
           }

           

            /**
             * Getter for resourcePath by  Property Number 17
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_property17(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_resourcePath(_ResourceData,
                                             env);
            }

            /**
             * getter for resourcePath.
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_resourcePath(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_resourcePath;
             }

            /**
             * setter for resourcePath
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_resourcePath(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_resourcePath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_resourcePath &&
                        arg_resourcePath == _ResourceData->property_resourcePath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_resourcePath(_ResourceData, env);

                
                if(NULL == arg_resourcePath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_resourcePath = (axis2_char_t *)axutil_strdup(env, arg_resourcePath);
                        if(NULL == _ResourceData->property_resourcePath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for resourcePath");
                            return AXIS2_FAILURE;
                        }
                        _ResourceData->is_valid_resourcePath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for resourcePath
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_resourcePath(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
            
                
                if(_ResourceData->property_resourcePath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ResourceData->property_resourcePath);
                     _ResourceData->property_resourcePath = NULL;
                }
            
                
                
                _ResourceData->is_valid_resourcePath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether resourcePath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_resourcePath_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_resourcePath;
           }

           /**
            * Set resourcePath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_resourcePath_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_resourcePath(_ResourceData, env);
           }

           

            /**
             * Getter for resourceType by  Property Number 18
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_property18(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_resourceType(_ResourceData,
                                             env);
            }

            /**
             * getter for resourceType.
             */
            axis2_char_t* AXIS2_CALL
            adb_ResourceData_get_resourceType(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_resourceType;
             }

            /**
             * setter for resourceType
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_resourceType(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_resourceType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_resourceType &&
                        arg_resourceType == _ResourceData->property_resourceType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ResourceData_reset_resourceType(_ResourceData, env);

                
                if(NULL == arg_resourceType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_resourceType = (axis2_char_t *)axutil_strdup(env, arg_resourceType);
                        if(NULL == _ResourceData->property_resourceType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for resourceType");
                            return AXIS2_FAILURE;
                        }
                        _ResourceData->is_valid_resourceType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for resourceType
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_resourceType(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
            
                
                if(_ResourceData->property_resourceType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ResourceData->property_resourceType);
                     _ResourceData->property_resourceType = NULL;
                }
            
                
                
                _ResourceData->is_valid_resourceType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether resourceType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_resourceType_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_resourceType;
           }

           /**
            * Set resourceType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_resourceType_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_resourceType(_ResourceData, env);
           }

           

            /**
             * Getter for tagCounts by  Property Number 19
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ResourceData_get_property19(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env)
            {
                return adb_ResourceData_get_tagCounts(_ResourceData,
                                             env);
            }

            /**
             * getter for tagCounts.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ResourceData_get_tagCounts(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                return _ResourceData->property_tagCounts;
             }

            /**
             * setter for tagCounts
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_tagCounts(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_tagCounts)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if(_ResourceData->is_valid_tagCounts &&
                        arg_tagCounts == _ResourceData->property_tagCounts)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_tagCounts, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "tagCounts has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_tagCounts, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_ResourceData_reset_tagCounts(_ResourceData, env);

                
                if(NULL == arg_tagCounts)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ResourceData->property_tagCounts = arg_tagCounts;
                        if(non_nil_exists)
                        {
                            _ResourceData->is_valid_tagCounts = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of tagCounts.
             */
            adb_TagCount_t* AXIS2_CALL
            adb_ResourceData_get_tagCounts_at(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env, int i)
            {
                adb_TagCount_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ResourceData, NULL);
                  

                if(_ResourceData->property_tagCounts == NULL)
                {
                    return (adb_TagCount_t*)0;
                }
                ret_val = (adb_TagCount_t*)axutil_array_list_get(_ResourceData->property_tagCounts, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of tagCounts.
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_set_tagCounts_at(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env, int i,
                    adb_TagCount_t* arg_tagCounts)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
                
                if( _ResourceData->is_valid_tagCounts &&
                    _ResourceData->property_tagCounts &&
                
                    arg_tagCounts == (adb_TagCount_t*)axutil_array_list_get(_ResourceData->property_tagCounts, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_tagCounts)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_ResourceData->property_tagCounts != NULL)
                        {
                            size = axutil_array_list_size(_ResourceData->property_tagCounts, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_ResourceData->property_tagCounts, env, i))
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
                  

                if(_ResourceData->property_tagCounts == NULL)
                {
                    _ResourceData->property_tagCounts = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_ResourceData->property_tagCounts, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_TagCount_free((adb_TagCount_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ResourceData->is_valid_tagCounts = AXIS2_FALSE;
                        axutil_array_list_set(_ResourceData->property_tagCounts , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_ResourceData->property_tagCounts , env, i, arg_tagCounts);
                  _ResourceData->is_valid_tagCounts = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to tagCounts.
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_add_tagCounts(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env,
                    adb_TagCount_t* arg_tagCounts)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);

                
                    if(NULL == arg_tagCounts)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_ResourceData->property_tagCounts == NULL)
                {
                    _ResourceData->property_tagCounts = axutil_array_list_create(env, 10);
                }
                if(_ResourceData->property_tagCounts == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for tagCounts");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_ResourceData->property_tagCounts , env, arg_tagCounts);
                  _ResourceData->is_valid_tagCounts = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the tagCounts array.
             */
            int AXIS2_CALL
            adb_ResourceData_sizeof_tagCounts(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, -1);
                if(_ResourceData->property_tagCounts == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_ResourceData->property_tagCounts, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_ResourceData_remove_tagCounts_at(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env, int i)
            {
                return adb_ResourceData_set_tagCounts_nil_at(_ResourceData, env, i);
            }

            

           /**
            * resetter for tagCounts
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_reset_tagCounts(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);
               

               
                  if (_ResourceData->property_tagCounts != NULL)
                  {
                      count = axutil_array_list_size(_ResourceData->property_tagCounts, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_ResourceData->property_tagCounts, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_TagCount_free((adb_TagCount_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_ResourceData->property_tagCounts, env);
                  }
                _ResourceData->is_valid_tagCounts = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether tagCounts is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_tagCounts_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return !_ResourceData->is_valid_tagCounts;
           }

           /**
            * Set tagCounts to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_tagCounts_nil(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env)
           {
               return adb_ResourceData_reset_tagCounts(_ResourceData, env);
           }

           
           /**
            * Check whether tagCounts is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_ResourceData_is_tagCounts_nil_at(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_TRUE);
               
               return (_ResourceData->is_valid_tagCounts == AXIS2_FALSE ||
                        NULL == _ResourceData->property_tagCounts || 
                        NULL == axutil_array_list_get(_ResourceData->property_tagCounts, env, i));
           }

           /**
            * Set tagCounts to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_ResourceData_set_tagCounts_nil_at(
                   adb_ResourceData_t* _ResourceData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ResourceData, AXIS2_FAILURE);

                if(_ResourceData->property_tagCounts == NULL ||
                            _ResourceData->is_valid_tagCounts == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_ResourceData->property_tagCounts, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_ResourceData->property_tagCounts, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of tagCounts is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_ResourceData->property_tagCounts == NULL)
                {
                    _ResourceData->is_valid_tagCounts = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_ResourceData->property_tagCounts, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_TagCount_free((adb_TagCount_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ResourceData->is_valid_tagCounts = AXIS2_FALSE;
                        axutil_array_list_set(_ResourceData->property_tagCounts , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_ResourceData->property_tagCounts , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

