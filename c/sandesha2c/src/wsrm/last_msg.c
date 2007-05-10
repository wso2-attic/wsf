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
 
#include <sandesha2_last_msg.h>
#include <sandesha2_constants.h>

/** 
 * @brief LastMessage struct impl
 *	Sandesha2 IOM LastMessage
 */
typedef struct sandesha2_last_msg_impl sandesha2_last_msg_impl_t;  
  
struct sandesha2_last_msg_impl
{
	sandesha2_last_msg_t last_msg;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(last_msg) \
						((sandesha2_last_msg_impl_t *)(last_msg))

/***************************** Function headers *******************************/
axis2_char_t* AXIS2_CALL 
sandesha2_last_msg_get_namespace_value (sandesha2_iom_rm_element_t *last_msg,
						const axutil_env_t *env);
    
void* AXIS2_CALL 
sandesha2_last_msg_from_om_node(sandesha2_iom_rm_element_t *last_msg,
                    	const axutil_env_t *env, axiom_node_t *om_node);
    
axiom_node_t* AXIS2_CALL 
sandesha2_last_msg_to_om_node(sandesha2_iom_rm_element_t *last_msg,
                    	const axutil_env_t *env, void *om_node);
                    	
axis2_bool_t AXIS2_CALL 
sandesha2_last_msg_is_namespace_supported(sandesha2_iom_rm_element_t *last_msg,
                    	const axutil_env_t *env, axis2_char_t *namespace);

axis2_status_t AXIS2_CALL 
sandesha2_last_msg_free (sandesha2_iom_rm_element_t *last_msg, 
                        const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_last_msg_t* AXIS2_CALL
sandesha2_last_msg_create(
    const axutil_env_t *env, 
    axis2_char_t *ns_val)
{
    sandesha2_last_msg_impl_t *last_msg_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    
    if(AXIS2_FALSE == sandesha2_last_msg_is_namespace_supported(
                        (sandesha2_iom_rm_element_t*)last_msg_impl, env, 
                        ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
                            AXIS2_FAILURE);
        return NULL;
    }    
    last_msg_impl =  (sandesha2_last_msg_impl_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_last_msg_impl_t));
	
    if(NULL == last_msg_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    last_msg_impl->ns_val = NULL;
    last_msg_impl->last_msg.element.ops = NULL;
    
    last_msg_impl->last_msg.element.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_element_ops_t));
    if(NULL == last_msg_impl->last_msg.element.ops)
	{
		sandesha2_last_msg_free((sandesha2_iom_rm_element_t*)
                         last_msg_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    last_msg_impl->ns_val = (axis2_char_t *)axutil_strdup(env, ns_val);
    
    last_msg_impl->last_msg.element.ops->get_namespace_value = 
                        sandesha2_last_msg_get_namespace_value;
    last_msg_impl->last_msg.element.ops->from_om_node = 
    					sandesha2_last_msg_from_om_node;
    last_msg_impl->last_msg.element.ops->to_om_node = 
    					sandesha2_last_msg_to_om_node;
    last_msg_impl->last_msg.element.ops->is_namespace_supported = 
    					sandesha2_last_msg_is_namespace_supported;
    last_msg_impl->last_msg.element.ops->free = sandesha2_last_msg_free;
                        
	return &(last_msg_impl->last_msg);
}


axis2_status_t AXIS2_CALL 
sandesha2_last_msg_free (sandesha2_iom_rm_element_t *last_msg, 
                        const axutil_env_t *env)
{
    sandesha2_last_msg_impl_t *last_msg_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    last_msg_impl = SANDESHA2_INTF_TO_IMPL(last_msg);
    
    if(NULL != last_msg_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, last_msg_impl->ns_val);
        last_msg_impl->ns_val = NULL;
    }
    if(NULL != last_msg->ops)
    {
        AXIS2_FREE(env->allocator, last_msg->ops);
        last_msg->ops = NULL;
    }
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(last_msg));
	return AXIS2_SUCCESS;
}

axis2_char_t* AXIS2_CALL 
sandesha2_last_msg_get_namespace_value (sandesha2_iom_rm_element_t *last_msg,
						const axutil_env_t *env)
{
	sandesha2_last_msg_impl_t *last_msg_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	last_msg_impl = SANDESHA2_INTF_TO_IMPL(last_msg);
	return last_msg_impl->ns_val;
}


void* AXIS2_CALL 
sandesha2_last_msg_from_om_node(sandesha2_iom_rm_element_t *last_msg,
                    	const axutil_env_t *env, axiom_node_t *om_node)
{
	sandesha2_last_msg_impl_t *last_msg_impl = NULL;
    axiom_element_t *om_element = NULL;
    axiom_element_t *lm_part = NULL;
    axiom_node_t *lm_node = NULL;
    axutil_qname_t *lm_qname = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    last_msg_impl = SANDESHA2_INTF_TO_IMPL(last_msg);
    om_element = axiom_node_get_data_element(om_node, env);
    if(NULL == om_element)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    lm_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_LAST_MSG, 
                        last_msg_impl->ns_val, NULL);
    if(NULL == lm_qname)
    {
        return NULL;
    }
    lm_part = axiom_element_get_first_child_with_qname(om_element, env,
                        lm_qname, om_node, &lm_node);
    if(NULL == lm_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    return last_msg;
}


axiom_node_t* AXIS2_CALL 
sandesha2_last_msg_to_om_node(
    sandesha2_iom_rm_element_t *last_msg,
    const axutil_env_t *env, 
    void *om_node)
{
	sandesha2_last_msg_impl_t *last_msg_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_element_t *lm_element = NULL;
    axiom_node_t *lm_node = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    last_msg_impl = SANDESHA2_INTF_TO_IMPL(last_msg);
    rm_ns = axiom_namespace_create(env, last_msg_impl->ns_val,
                        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(NULL == rm_ns)
    {
        return NULL;
    }
    lm_element = axiom_element_create(env, NULL, 
                        SANDESHA2_WSRM_COMMON_LAST_MSG, rm_ns, &lm_node);
    if(NULL == lm_element)
    {
        return NULL;
    }
    axiom_node_add_child((axiom_node_t*)om_node, env, lm_node);
    return (axiom_node_t*)om_node;
}

axis2_bool_t AXIS2_CALL 
sandesha2_last_msg_is_namespace_supported(
    sandesha2_iom_rm_element_t *last_msg,
    const axutil_env_t *env, 
    axis2_char_t *namespace)
{
	sandesha2_last_msg_impl_t *last_msg_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    last_msg_impl = SANDESHA2_INTF_TO_IMPL(last_msg);
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
