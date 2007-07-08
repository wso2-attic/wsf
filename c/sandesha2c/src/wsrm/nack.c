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
 
#include <sandesha2_nack.h>
#include <sandesha2_constants.h>
#include <stdio.h>

/** 
 * @brief Nack struct impl
 *	Sandesha2 IOM Nack
 */
typedef struct sandesha2_nack_impl sandesha2_nack_impl_t;  
  
struct sandesha2_nack_impl
{
	sandesha2_nack_t nack;
	long nack_num;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(nack) \
						((sandesha2_nack_impl_t *)(nack))

/***************************** Function headers *******************************/
axis2_char_t* AXIS2_CALL 
sandesha2_nack_get_namespace_value (sandesha2_iom_rm_element_t *nack,
						const axutil_env_t *env);
    
void* AXIS2_CALL 
sandesha2_nack_from_om_node(sandesha2_iom_rm_element_t *nack,
                    	const axutil_env_t *env, axiom_node_t *om_node);
    
axiom_node_t* AXIS2_CALL 
sandesha2_nack_to_om_node(sandesha2_iom_rm_element_t *nack,
                    	const axutil_env_t *env,void *om_node);
                    	
axis2_bool_t AXIS2_CALL 
sandesha2_nack_is_namespace_supported(sandesha2_iom_rm_element_t *nack,
                    	const axutil_env_t *env, axis2_char_t *namespace);
                    	
long AXIS2_CALL
sandesha2_nack_get_nack_num(sandesha2_nack_t *nack,
                    	const axutil_env_t *env);

axis2_status_t AXIS2_CALL                 
sandesha2_nack_set_nack_num(sandesha2_nack_t *nack,
                    	const axutil_env_t *env, long value);

axis2_status_t AXIS2_CALL 
sandesha2_nack_free (sandesha2_iom_rm_element_t *nack, 
						const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_nack_t* AXIS2_CALL
sandesha2_nack_create(const axutil_env_t *env,  axis2_char_t *ns_val)
{
    sandesha2_nack_impl_t *nack_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    
    if(AXIS2_FALSE == sandesha2_nack_is_namespace_supported(
                        (sandesha2_iom_rm_element_t*)nack_impl, env, ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
                            AXIS2_FAILURE);
        return NULL;
    }    
    nack_impl =  (sandesha2_nack_impl_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_nack_impl_t));
	
    if(NULL == nack_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    nack_impl->ns_val = NULL;
    nack_impl->nack_num = 0;
    nack_impl->nack.ops = NULL;
    nack_impl->nack.element.ops = NULL;
    
    nack_impl->nack.element.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_element_ops_t));
    if(NULL == nack_impl->nack.element.ops)
	{
		sandesha2_nack_free((sandesha2_iom_rm_element_t*)
                         nack_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    nack_impl->nack.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_nack_ops_t));
    if(NULL == nack_impl->nack.ops)
	{
		sandesha2_nack_free((sandesha2_iom_rm_element_t*)
                         nack_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    nack_impl->ns_val = (axis2_char_t *)axutil_strdup(env, ns_val);
    
    nack_impl->nack.element.ops->get_namespace_value = 
                        sandesha2_nack_get_namespace_value;
    nack_impl->nack.element.ops->from_om_node = 
    					sandesha2_nack_from_om_node;
    nack_impl->nack.element.ops->to_om_node = 
    					sandesha2_nack_to_om_node;
    nack_impl->nack.element.ops->is_namespace_supported = 
    					sandesha2_nack_is_namespace_supported;
    nack_impl->nack.ops->set_nack_num = sandesha2_nack_set_nack_num;
    nack_impl->nack.ops->get_nack_num = sandesha2_nack_get_nack_num;
    nack_impl->nack.element.ops->free = sandesha2_nack_free;
                        
	return &(nack_impl->nack);
}


axis2_status_t AXIS2_CALL 
sandesha2_nack_free (sandesha2_iom_rm_element_t *nack, 
						const axutil_env_t *env)
{
    sandesha2_nack_impl_t *nack_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    nack_impl = SANDESHA2_INTF_TO_IMPL(nack);
    
    if(NULL != nack_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, nack_impl->ns_val);
        nack_impl->ns_val = NULL;
    }
    nack_impl->nack_num = 0;
    
    if(NULL != nack->ops)
    {
        AXIS2_FREE(env->allocator, nack->ops);
        nack->ops = NULL;
    }
    if(NULL != nack_impl->nack.ops)
    {
        AXIS2_FREE(env->allocator, nack_impl->nack.ops);
        nack_impl->nack.ops = NULL;
    }
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(nack));
	return AXIS2_SUCCESS;
}

axis2_char_t* AXIS2_CALL 
sandesha2_nack_get_namespace_value (sandesha2_iom_rm_element_t *nack,
						const axutil_env_t *env)
{
	sandesha2_nack_impl_t *nack_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	nack_impl = SANDESHA2_INTF_TO_IMPL(nack);
	return nack_impl->ns_val;
}


void* AXIS2_CALL 
sandesha2_nack_from_om_node(sandesha2_iom_rm_element_t *nack,
                    	const axutil_env_t *env, axiom_node_t *om_node)
{
	sandesha2_nack_impl_t *nack_impl = NULL;
    axiom_element_t *om_element = NULL;
    axiom_element_t *nack_part = NULL;
    axiom_node_t *nack_node = NULL;
    axutil_qname_t *nack_qname = NULL;
    axis2_char_t *nack_text = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    nack_impl = SANDESHA2_INTF_TO_IMPL(nack);
    om_element = axiom_node_get_data_element(om_node, env);
    if(NULL == om_element)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    nack_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_NACK,
                        nack_impl->ns_val, NULL);
    if(NULL == nack_qname)
    {
        return NULL;
    }
    nack_part = axiom_element_get_first_child_with_qname(om_element, env,
                        nack_qname, om_node, &nack_node);
    if(NULL == nack_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    nack_text = axiom_element_get_text(nack_part, env, nack_node);
    if(NULL == nack_text)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_EMPTY_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    return nack;
}


axiom_node_t* AXIS2_CALL 
sandesha2_nack_to_om_node(sandesha2_iom_rm_element_t *nack,
                    	const axutil_env_t *env, void *om_node)
{
	sandesha2_nack_impl_t *nack_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_element_t *nack_element = NULL;
    axiom_node_t *nack_node = NULL;
    axis2_char_t *str_num = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    nack_impl = SANDESHA2_INTF_TO_IMPL(nack);
    if(nack_impl->nack_num <= 0)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_OM_INVALID_NUMBER, 
                        AXIS2_FAILURE);
        return NULL;
    }
    rm_ns = axiom_namespace_create(env, nack_impl->ns_val,
                        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(NULL == rm_ns)
    {
        return NULL;
    }
    nack_element = axiom_element_create(env, NULL, 
                        SANDESHA2_WSRM_COMMON_NACK, rm_ns, &nack_node);
    if(NULL == nack_element)
    {
        return NULL;
    }
    str_num = AXIS2_MALLOC(env->allocator, 32*sizeof(axis2_char_t));
    sprintf(str_num, "%ld", nack_impl->nack_num);
    axiom_element_set_text(nack_element, env, str_num, nack_node);
    axiom_node_add_child((axiom_node_t*)om_node, env, nack_node);
    
    return (axiom_node_t*)om_node;
}

axis2_bool_t AXIS2_CALL 
sandesha2_nack_is_namespace_supported(sandesha2_iom_rm_element_t *nack,
                    	const axutil_env_t *env, axis2_char_t *namespace)
{
	sandesha2_nack_impl_t *nack_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    nack_impl = SANDESHA2_INTF_TO_IMPL(nack);
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

long AXIS2_CALL
sandesha2_nack_get_nack_num(sandesha2_nack_t *nack,
                    	const axutil_env_t *env)
{
	sandesha2_nack_impl_t *nack_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	nack_impl = SANDESHA2_INTF_TO_IMPL(nack);
	return nack_impl->nack_num;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_nack_set_nack_num(sandesha2_nack_t *nack,
                    	const axutil_env_t *env, long value)
{
	sandesha2_nack_impl_t *nack_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	nack_impl = SANDESHA2_INTF_TO_IMPL(nack);
 	nack_impl->nack_num = value;
 	return AXIS2_SUCCESS;
}
