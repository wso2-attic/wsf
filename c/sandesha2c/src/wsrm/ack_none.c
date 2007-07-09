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
 
#include <sandesha2_ack_none.h>
#include <sandesha2_constants.h>
/** 
 * @brief AckNone struct impl
 *	Sandesha2 IOM AckNone
 */
typedef struct sandesha2_ack_none_impl sandesha2_ack_none_impl_t;  
  
struct sandesha2_ack_none_impl
{
	sandesha2_ack_none_t ack_none;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(ack_none) \
						((sandesha2_ack_none_impl_t *)(ack_none))

/***************************** Function headers *******************************/
axis2_char_t* AXIS2_CALL 
sandesha2_ack_none_get_namespace_value (sandesha2_iom_rm_element_t *ack_none,
						const axutil_env_t *env);
    
void* AXIS2_CALL 
sandesha2_ack_none_from_om_node(sandesha2_iom_rm_element_t *ack_none,
                    	const axutil_env_t *env, axiom_node_t *om_node);
    
axiom_node_t* AXIS2_CALL 
sandesha2_ack_none_to_om_node(sandesha2_iom_rm_element_t *ack_none,
                    	const axutil_env_t *env, void *om_node);
                    	
axis2_bool_t AXIS2_CALL 
sandesha2_ack_none_is_namespace_supported(sandesha2_iom_rm_element_t *ack_none,
                    	const axutil_env_t *env, axis2_char_t *namespace);

axis2_status_t AXIS2_CALL 
sandesha2_ack_none_free (sandesha2_iom_rm_element_t *ack_none, 
                        const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_ack_none_t * AXIS2_CALL
sandesha2_ack_none_create(const axutil_env_t *env, axis2_char_t *ns_val)
{
    sandesha2_ack_none_impl_t *ack_none_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    
    if(AXIS2_FALSE == sandesha2_ack_none_is_namespace_supported(
                        (sandesha2_iom_rm_element_t*)ack_none_impl,
                        env, ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
                            AXIS2_FAILURE);
        return NULL;
    } 
    ack_none_impl =  (sandesha2_ack_none_impl_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_ack_none_impl_t));
	
    if(NULL == ack_none_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    ack_none_impl->ns_val = NULL;
    ack_none_impl->ack_none.element.ops = NULL;
    
    ack_none_impl->ack_none.element.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_element_ops_t));
    if(NULL == ack_none_impl->ack_none.element.ops)
	{
		sandesha2_ack_none_free((sandesha2_iom_rm_element_t*)
                         ack_none_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    ack_none_impl->ns_val = (axis2_char_t *)axutil_strdup( env , ns_val);
    ack_none_impl->ack_none.element.ops->get_namespace_value = 
                        sandesha2_ack_none_get_namespace_value;
    ack_none_impl->ack_none.element.ops->from_om_node = 
    					sandesha2_ack_none_from_om_node;
    ack_none_impl->ack_none.element.ops->to_om_node = 
    					sandesha2_ack_none_to_om_node;
    ack_none_impl->ack_none.element.ops->is_namespace_supported = 
    					sandesha2_ack_none_is_namespace_supported;
    ack_none_impl->ack_none.element.ops->free = sandesha2_ack_none_free;
                        
	return &(ack_none_impl->ack_none);
}


axis2_status_t AXIS2_CALL 
sandesha2_ack_none_free (sandesha2_iom_rm_element_t *ack_none, 
                        const axutil_env_t *env)
{
    sandesha2_ack_none_impl_t *ack_none_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    ack_none_impl = SANDESHA2_INTF_TO_IMPL(ack_none);
    
    if(NULL != ack_none_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, ack_none_impl->ns_val);
        ack_none_impl->ns_val = NULL;
    }
    if(NULL != ack_none_impl->ack_none.element.ops)
    {
        AXIS2_FREE(env->allocator, ack_none_impl->ack_none.element.ops);
        ack_none_impl->ack_none.element.ops = NULL;
    }
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(ack_none));
	return AXIS2_SUCCESS;
}

axis2_char_t* AXIS2_CALL 
sandesha2_ack_none_get_namespace_value (sandesha2_iom_rm_element_t *ack_none,
						const axutil_env_t *env)
{
	sandesha2_ack_none_impl_t *ack_none_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	ack_none_impl = SANDESHA2_INTF_TO_IMPL(ack_none);
	return ack_none_impl->ns_val;
}


void* AXIS2_CALL 
sandesha2_ack_none_from_om_node(sandesha2_iom_rm_element_t *ack_none,
                    	const axutil_env_t *env, axiom_node_t *om_node)
{
	sandesha2_ack_none_impl_t *ack_none_impl = NULL;
    axiom_element_t *om_element = NULL;
    axiom_element_t *none_part = NULL;
    axiom_node_t *none_node = NULL;
    axutil_qname_t *none_qname = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    ack_none_impl = SANDESHA2_INTF_TO_IMPL(ack_none);
    none_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_NONE, 
                    ack_none_impl->ns_val, NULL); 
    if(NULL == none_qname)
    {
        return NULL;
    }
    om_element = axiom_node_get_data_element(om_node, env);
    if(NULL == om_element)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    none_part = axiom_element_get_first_child_with_qname(om_element, env,
                        none_qname, om_node, &none_node);
    if(NULL == none_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    return ack_none;
}


axiom_node_t* AXIS2_CALL 
sandesha2_ack_none_to_om_node(sandesha2_iom_rm_element_t *ack_none,
                    	const axutil_env_t *env, void *om_node)
{
	sandesha2_ack_none_impl_t *ack_none_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_element_t *an_element = NULL;
    axiom_node_t *an_node = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    ack_none_impl = SANDESHA2_INTF_TO_IMPL(ack_none);
    rm_ns = axiom_namespace_create(env, ack_none_impl->ns_val,
                        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(NULL == rm_ns)
    {
        return NULL;
    }
    an_element = axiom_element_create(env, NULL, SANDESHA2_WSRM_COMMON_NONE,
                        rm_ns, &an_node);
    if(NULL == an_element)
    {
        return NULL;
    }
    axiom_node_add_child((axiom_node_t*)om_node, env, an_node);
    return (axiom_node_t*)om_node;
}

axis2_bool_t AXIS2_CALL 
sandesha2_ack_none_is_namespace_supported(sandesha2_iom_rm_element_t *ack_none,
                    	const axutil_env_t *env, axis2_char_t *namespace)
{
	sandesha2_ack_none_impl_t *ack_none_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    ack_none_impl = SANDESHA2_INTF_TO_IMPL(ack_none);
    if(0 == axutil_strcmp(namespace, SANDESHA2_SPEC_2005_02_NS_URI))
    {
        return AXIS2_FALSE;
    }
    if(0 == axutil_strcmp(namespace, SANDESHA2_SPEC_2006_08_NS_URI))
    {
        return AXIS2_TRUE;
    }
    return AXIS2_FALSE;
}
