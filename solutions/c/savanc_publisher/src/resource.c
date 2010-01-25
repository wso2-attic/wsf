/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 #include <reg_client_constants.h>
 #include <reg_client_resource.h>

/** 
 * @brief resource struct impl
 *	Registration Client Resource represent Resource
 */
  
AXIS2_EXTERN reg_client_resource_t* AXIS2_CALL
reg_client_resource_create(
    const axutil_env_t *env)
{
    reg_client_resource_t *resource = NULL;

    resource =  (reg_client_resource_t *)AXIS2_MALLOC(env->allocator, 
            sizeof(reg_client_resource_t));
	
    if(!resource)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}

    resource->properties = axutil_array_list_create(env, 0);
    resource->entries = axutil_array_list_create(env, 0);
    resource->is_directory = AXIS2_FALSE;
    
	return resource;
}


axis2_status_t AXIS2_CALL 
reg_client_resource_free(
    reg_client_resource_t *resource, 
    const axutil_env_t *env)
{
    if(resource->properties)
    {
        axutil_array_list_free(resource->properties, env);
        resource->properties = NULL;
    }

    if(resource->entries)
    {
        axutil_array_list_free(resource->entries, env);
        resource->entries = NULL;
    }
    
	AXIS2_FREE(env->allocator, resource);

	return AXIS2_SUCCESS;
}

