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
 
#include <sandesha2_identifier.h>
#include <sandesha2_constants.h>
/** 
 * @brief Identifier struct impl
 *	Sandesha2 IOM Identifier
 */
typedef struct sandesha2_identifier_impl sandesha2_identifier_impl_t;  
  
struct sandesha2_identifier_impl
{
	sandesha2_identifier_t identifier;
	axis2_char_t *str_id;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(identifier) \
						((sandesha2_identifier_impl_t *)(identifier))

/***************************** Function headers *******************************/
static axis2_char_t* AXIS2_CALL 
sandesha2_identifier_get_namespace_value (
    sandesha2_iom_rm_element_t *identifier,
    const axutil_env_t *env);
    
static void* AXIS2_CALL 
sandesha2_identifier_from_om_node(
    sandesha2_iom_rm_element_t *identifier,
    const axutil_env_t *env, axiom_node_t *om_node);
    
static axiom_node_t* AXIS2_CALL 
sandesha2_identifier_to_om_node(
    sandesha2_iom_rm_element_t *identifier,
    const axutil_env_t *env, void *om_node);
                    	
static axis2_bool_t AXIS2_CALL 
sandesha2_identifier_is_namespace_supported(
    sandesha2_iom_rm_element_t *identifier,
    const axutil_env_t *env, axis2_char_t *namespace);

static axis2_status_t AXIS2_CALL 
sandesha2_identifier_free (
    sandesha2_iom_rm_element_t *identifier, 
    const axutil_env_t *env);	
						
/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_identifier_t* AXIS2_CALL
sandesha2_identifier_create(
        const axutil_env_t *env,  
        axis2_char_t *ns_val)
{
    sandesha2_identifier_impl_t *identifier_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);

    identifier_impl =  (sandesha2_identifier_impl_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_identifier_impl_t));
	
    if(NULL == identifier_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    identifier_impl->ns_val = NULL;
    identifier_impl->str_id = NULL;
    identifier_impl->identifier.element.ops = NULL;
    
    if(AXIS2_FALSE == sandesha2_identifier_is_namespace_supported(
                        (sandesha2_iom_rm_element_t*)identifier_impl, env, 
                        ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
                            AXIS2_FAILURE);
        return NULL;
    }        
    
    identifier_impl->identifier.element.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_element_ops_t));

    if(NULL == identifier_impl->identifier.element.ops)
	{
		sandesha2_identifier_free((sandesha2_iom_rm_element_t*)
                         identifier_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    identifier_impl->ns_val = (axis2_char_t *)axutil_strdup(env, ns_val);
    
    identifier_impl->identifier.element.ops->get_namespace_value = 
                        sandesha2_identifier_get_namespace_value;
    identifier_impl->identifier.element.ops->from_om_node = 
    					sandesha2_identifier_from_om_node;
    identifier_impl->identifier.element.ops->to_om_node = 
    					sandesha2_identifier_to_om_node;
    identifier_impl->identifier.element.ops->is_namespace_supported = 
    					sandesha2_identifier_is_namespace_supported;
    identifier_impl->identifier.element.ops->free = sandesha2_identifier_free;
    
	return &(identifier_impl->identifier);
}


static axis2_status_t AXIS2_CALL 
sandesha2_identifier_free (
    sandesha2_iom_rm_element_t *identifier, 
	const axutil_env_t *env)
{
    sandesha2_identifier_impl_t *identifier_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    identifier_impl = SANDESHA2_INTF_TO_IMPL(identifier);
    
    if(identifier_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, identifier_impl->ns_val);
        identifier_impl->ns_val = NULL;
    }
    if(identifier_impl->str_id)
    {
    	AXIS2_FREE(env->allocator, identifier_impl->str_id);
        identifier_impl->str_id = NULL;
    }
    if(identifier_impl->identifier.element.ops)
    {
        AXIS2_FREE(env->allocator, identifier_impl->identifier.element.ops);
        identifier_impl->identifier.element.ops = NULL;
    }    
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(identifier));
	return AXIS2_SUCCESS;
}

static axis2_char_t* AXIS2_CALL 
sandesha2_identifier_get_namespace_value (
    sandesha2_iom_rm_element_t *identifier,
	const axutil_env_t *env)
{
	sandesha2_identifier_impl_t *identifier_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	identifier_impl = SANDESHA2_INTF_TO_IMPL(identifier);
	return identifier_impl->ns_val;
}


static void* AXIS2_CALL 
sandesha2_identifier_from_om_node(
    sandesha2_iom_rm_element_t *identifier,
    const axutil_env_t *env, 
    axiom_node_t *om_node)
{
	sandesha2_identifier_impl_t *identifier_impl = NULL;
    axiom_element_t *om_element = NULL;
    axiom_element_t *ident_part = NULL;
    axiom_node_t *ident_node = NULL;
    axutil_qname_t *ident_qname = NULL;
    axis2_char_t *ident_str = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    identifier_impl = SANDESHA2_INTF_TO_IMPL(identifier);
    om_element = axiom_node_get_data_element(om_node, env);
    if(NULL == om_element)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    ident_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_IDENTIFIER, 
                        identifier_impl->ns_val, NULL); 
    if(NULL == ident_qname)
    {
        return NULL;
    }
    ident_part = axiom_element_get_first_child_with_qname(om_element, env,
                        ident_qname, om_node, &ident_node);
    if(NULL == ident_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    ident_str = axiom_element_get_text(ident_part, env, ident_node);
    if(NULL == ident_str)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_EMPTY_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    identifier_impl->str_id = axutil_strdup(env, ident_str);
    if(NULL == identifier_impl->str_id)
    {
        return NULL;
    }
    return identifier;
}


static axiom_node_t* AXIS2_CALL 
sandesha2_identifier_to_om_node(
    sandesha2_iom_rm_element_t *identifier,
    const axutil_env_t *env, void *om_node)
{
	sandesha2_identifier_impl_t *identifier_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_element_t *id_element = NULL;
    axiom_node_t *id_node = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    identifier_impl = SANDESHA2_INTF_TO_IMPL(identifier);
    if(!identifier_impl->str_id || 0 == axutil_strlen(
                        identifier_impl->str_id))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_OM_NULL_ELEMENT, 
                        AXIS2_FAILURE);
        return NULL;
    }
    rm_ns = axiom_namespace_create(env, identifier_impl->ns_val,
                        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(!rm_ns)
    {
        return NULL;
    }
    id_element = axiom_element_create(env, NULL, 
                        SANDESHA2_WSRM_COMMON_IDENTIFIER, rm_ns, &id_node);
    if(!id_element)
    {
        return NULL;
    }
    axiom_element_set_text(id_element, env, identifier_impl->str_id, 
                        id_node);
    axiom_node_add_child((axiom_node_t*)om_node, env, id_node);
    return (axiom_node_t*)om_node;
}

static axis2_bool_t AXIS2_CALL 
sandesha2_identifier_is_namespace_supported(
    sandesha2_iom_rm_element_t *identifier,
    const axutil_env_t *env, 
    axis2_char_t *namespace)
{
	sandesha2_identifier_impl_t *identifier_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    identifier_impl = SANDESHA2_INTF_TO_IMPL(identifier);
    if(0 == axutil_strcmp(namespace, SANDESHA2_SPEC_2005_02_NS_URI))
    {
        return AXIS2_TRUE;
    }
    if(0 == axutil_strcmp(namespace, SANDESHA2_SPEC_2006_08_NS_URI))
    {
        return AXIS2_TRUE;
    }
    return AXIS2_FALSE;
}

axis2_char_t * AXIS2_CALL
sandesha2_identifier_get_identifier(
    sandesha2_identifier_t *identifier,
    const axutil_env_t *env)
{
	sandesha2_identifier_impl_t *identifier_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	identifier_impl = SANDESHA2_INTF_TO_IMPL(identifier);
	
	return identifier_impl->str_id;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_identifier_set_identifier(
    sandesha2_identifier_t *identifier,
    const axutil_env_t *env, 
    axis2_char_t *str_id)
{
	sandesha2_identifier_impl_t *identifier_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	identifier_impl = SANDESHA2_INTF_TO_IMPL(identifier);
 	if(identifier_impl->str_id)
	{
		AXIS2_FREE(env->allocator, identifier_impl->str_id);
		identifier_impl->str_id = NULL;
	}
	
	identifier_impl->str_id = (axis2_char_t *)axutil_strdup(env, str_id);
 	return AXIS2_SUCCESS;
}

