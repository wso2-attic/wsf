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
#include <sandesha2_create_seq_res.h>
#include <sandesha2_constants.h>
#include <axiom_soap_body.h>
#include <sandesha2_utils.h>
/** 
 * @brief CreateSeqenceResponse struct impl
 *	Sandesha2 IOM CreateSeqenceResponse
 */
typedef struct sandesha2_create_seq_res_impl sandesha2_create_seq_res_impl_t;  
  
struct sandesha2_create_seq_res_impl
{
	sandesha2_create_seq_res_t create_seq_res;
	sandesha2_identifier_t *identifier;
	sandesha2_accept_t *accept;
	sandesha2_expires_t *expires;
	axis2_char_t *rm_ns_val;
    axis2_char_t *addr_ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(create_seq_res) \
						((sandesha2_create_seq_res_impl_t *)(create_seq_res))

/***************************** Function headers *******************************/
static axis2_char_t* AXIS2_CALL 
sandesha2_create_seq_res_get_namespace_value (
    sandesha2_iom_rm_element_t *create_seq_res,
    const axutil_env_t *env);
    
static void* AXIS2_CALL 
sandesha2_create_seq_res_from_om_node(
   sandesha2_iom_rm_element_t *create_seq_res,
   const axutil_env_t *env, 
   axiom_node_t *om_node);
    
static axiom_node_t* AXIS2_CALL 
    sandesha2_create_seq_res_to_om_node(
    sandesha2_iom_rm_element_t *create_seq_res,
    const axutil_env_t *env, 
    void *om_node);
                    	
static axis2_bool_t AXIS2_CALL 
sandesha2_create_seq_res_is_namespace_supported(
    sandesha2_iom_rm_element_t *create_seq_res, 
    const axutil_env_t *env, 
    axis2_char_t *namespace);

static axis2_status_t AXIS2_CALL
sandesha2_create_seq_res_to_soap_env(sandesha2_iom_rm_part_t *create_seq_res,
   const axutil_env_t *env, 
   axiom_soap_envelope_t *envelope);  

static axis2_status_t AXIS2_CALL 
sandesha2_create_seq_res_free (
    sandesha2_iom_rm_element_t *create_seq_res,
	const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_create_seq_res_t* AXIS2_CALL
sandesha2_create_seq_res_create(const axutil_env_t *env,  axis2_char_t *rm_ns_val, 
					    axis2_char_t *addr_ns_val)
{
    sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, rm_ns_val, NULL);
    AXIS2_PARAM_CHECK(env->error, addr_ns_val, NULL);
    
    if(AXIS2_FALSE == sandesha2_create_seq_res_is_namespace_supported(
                        (sandesha2_iom_rm_element_t*)create_seq_res_impl, env, 
                        rm_ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
                            AXIS2_FAILURE);
        return NULL;
    }    
    create_seq_res_impl =  (sandesha2_create_seq_res_impl_t *)AXIS2_MALLOC 
                        (env->allocator, 
                        sizeof(sandesha2_create_seq_res_impl_t));
	
    if(!create_seq_res_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    create_seq_res_impl->rm_ns_val = NULL;
    create_seq_res_impl->addr_ns_val = NULL;
    create_seq_res_impl->identifier = NULL;
    create_seq_res_impl->accept = NULL;
    create_seq_res_impl->expires = NULL;
    create_seq_res_impl->create_seq_res.part.ops = NULL;
    create_seq_res_impl->create_seq_res.part.element.ops = NULL;
    
    create_seq_res_impl->create_seq_res.part.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_part_ops_t));
    if(!create_seq_res_impl->create_seq_res.part.ops)
	{
		sandesha2_create_seq_res_free((sandesha2_iom_rm_element_t*)
                         create_seq_res_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    create_seq_res_impl->create_seq_res.part.element.ops = AXIS2_MALLOC(
        env->allocator, sizeof(sandesha2_iom_rm_element_ops_t));
    if(!create_seq_res_impl->create_seq_res.part.element.ops)
	{
		sandesha2_create_seq_res_free((sandesha2_iom_rm_element_t*)
                         create_seq_res_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    create_seq_res_impl->rm_ns_val = (axis2_char_t *)axutil_strdup(env, rm_ns_val);
    create_seq_res_impl->addr_ns_val = (axis2_char_t *)axutil_strdup(env, addr_ns_val);
    
    create_seq_res_impl->create_seq_res.part.element.ops->get_namespace_value = 
                        sandesha2_create_seq_res_get_namespace_value;
    create_seq_res_impl->create_seq_res.part.element.ops->from_om_node = 
    					sandesha2_create_seq_res_from_om_node;
    create_seq_res_impl->create_seq_res.part.element.ops->to_om_node = 
    				    sandesha2_create_seq_res_to_om_node;
    create_seq_res_impl->create_seq_res.part.element.ops->is_namespace_supported
                        = sandesha2_create_seq_res_is_namespace_supported;
    create_seq_res_impl->create_seq_res.part.ops->to_soap_env = 
    					sandesha2_create_seq_res_to_soap_env;
    create_seq_res_impl->create_seq_res.part.element.ops->free = 
    					sandesha2_create_seq_res_free;
                        
	return &(create_seq_res_impl->create_seq_res);
}


static axis2_status_t AXIS2_CALL 
sandesha2_create_seq_res_free (
    sandesha2_iom_rm_element_t *create_seq_res, 
    const axutil_env_t *env)
{
    sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
    
    if(create_seq_res_impl->addr_ns_val)
    {
        AXIS2_FREE(env->allocator, create_seq_res_impl->addr_ns_val);
        create_seq_res_impl->addr_ns_val = NULL;
    }
    if(create_seq_res_impl->rm_ns_val)
    {
        AXIS2_FREE(env->allocator, create_seq_res_impl->rm_ns_val);
        create_seq_res_impl->rm_ns_val = NULL;
    }
    if(create_seq_res_impl->create_seq_res.part.ops)
    {
        AXIS2_FREE(env->allocator, create_seq_res_impl->create_seq_res.part.ops);
        create_seq_res_impl->create_seq_res.part.ops = NULL;
    }
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(create_seq_res));
	return AXIS2_SUCCESS;
}

static axis2_char_t* AXIS2_CALL 
sandesha2_create_seq_res_get_namespace_value (
    sandesha2_iom_rm_element_t *create_seq_res, 
    const axutil_env_t *env)
{
	sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
	return create_seq_res_impl->rm_ns_val;
}


static void* AXIS2_CALL 
sandesha2_create_seq_res_from_om_node(
    sandesha2_iom_rm_element_t *create_seq_res,
    const axutil_env_t *env, 
    axiom_node_t *csr_node)
{
	sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
    axiom_element_t *csr_part = NULL;
    axiom_element_t *exp_part = NULL;
    axiom_element_t *acc_part = NULL;
    axiom_node_t *exp_node = NULL;
    axiom_node_t *acc_node = NULL;
    axutil_qname_t *exp_qname = NULL;
    axutil_qname_t *acc_qname = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, csr_node, NULL);
    
    create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
    csr_part =axiom_node_get_data_element(csr_node, env);
    if(!csr_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
            AXIS2_FAILURE);
        return NULL;
    }
    create_seq_res_impl->identifier = sandesha2_identifier_create(env, 
        create_seq_res_impl->rm_ns_val);
    if(!create_seq_res_impl->identifier)
    {
        return NULL;
    }
    if(!sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
        create_seq_res_impl->identifier, env, csr_node))
    {
        return NULL;
    }
    exp_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_EXPIRES, 
        create_seq_res_impl->rm_ns_val, NULL);
    if(!exp_qname)
    {
        return NULL;
    }
    exp_part = axiom_element_get_first_child_with_qname(csr_part, env, 
        exp_qname, csr_node, &exp_node);
    if(exp_part)
    {
        create_seq_res_impl->expires = sandesha2_expires_create(env, 
            create_seq_res_impl->rm_ns_val);
        if(!create_seq_res_impl->expires)
        {
            return NULL;
        }
        if(!sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            create_seq_res_impl->expires, env, csr_node))
        {
            return NULL;
        }
    }
    acc_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_ACCEPT, 
        create_seq_res_impl->rm_ns_val, NULL);
    if(!acc_qname)
    {
        return NULL;
    } 
    acc_part = axiom_element_get_first_child_with_qname(csr_part, env, 
        acc_qname, csr_node, &acc_node);
    if(acc_part)
    {
        create_seq_res_impl->accept = sandesha2_accept_create(env, 
            create_seq_res_impl->rm_ns_val, create_seq_res_impl->addr_ns_val);
        if(!create_seq_res_impl->accept)
        {
            return NULL;
        }
        if(!sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            create_seq_res_impl->accept, env, csr_node))
        {
            return NULL;
        }
    } 
    return create_seq_res;
}


static axiom_node_t* AXIS2_CALL 
sandesha2_create_seq_res_to_om_node(
    sandesha2_iom_rm_element_t *create_seq_res,
    const axutil_env_t *env, 
    void *om_node)
{
	sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_element_t *csr_element = NULL;
    axiom_node_t *csr_node = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
    if(!create_seq_res_impl->identifier)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_OM_NULL_ELEMENT, 
                        AXIS2_FAILURE);
        return NULL;
    }
    rm_ns = axiom_namespace_create(env, create_seq_res_impl->rm_ns_val,
                        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(!rm_ns)
    {
        return NULL;
    }
    csr_element = axiom_element_create(env, NULL, 
                        SANDESHA2_WSRM_COMMON_CREATE_SEQ_RESPONSE, rm_ns, 
                        &csr_node);
    if(!csr_element)
    {
        return NULL;
    }
    sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)create_seq_res_impl->identifier, env,
                        csr_node);
    if(create_seq_res_impl->accept)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)create_seq_res_impl->accept, env, 
                        csr_node);
    }
    if(create_seq_res_impl->expires)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)create_seq_res_impl->expires, env, 
                        csr_node);
    }
    axiom_node_add_child((axiom_node_t*)om_node, env, csr_node);
    return (axiom_node_t*)om_node;
}

static axis2_bool_t AXIS2_CALL 
sandesha2_create_seq_res_is_namespace_supported(
    sandesha2_iom_rm_element_t *create_seq_res, 
    const axutil_env_t *env, 
    axis2_char_t *namespace)
{
	sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
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

axis2_status_t AXIS2_CALL
sandesha2_create_seq_res_set_identifier(
    sandesha2_create_seq_res_t *create_seq_res,
    const axutil_env_t *env, 
    sandesha2_identifier_t *identifier)
{
	sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
    create_seq_res_impl->identifier = identifier;
    return AXIS2_SUCCESS;
}


sandesha2_identifier_t * AXIS2_CALL
sandesha2_create_seq_res_get_identifier(
    sandesha2_create_seq_res_t *create_seq_res,
    const axutil_env_t *env)
{
	sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    
    create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
    return create_seq_res_impl->identifier;
} 

axis2_status_t AXIS2_CALL
sandesha2_create_seq_res_set_accept(
    sandesha2_create_seq_res_t *create_seq_res,
    const axutil_env_t *env, sandesha2_accept_t *accept)
{
	sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
    create_seq_res_impl->accept = accept;
    return AXIS2_SUCCESS;
}


sandesha2_accept_t * AXIS2_CALL
sandesha2_create_seq_res_get_accept(
    sandesha2_create_seq_res_t *create_seq_res,
    const axutil_env_t *env)
{
	sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    
    create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
    return create_seq_res_impl->accept;
}

axis2_status_t AXIS2_CALL
sandesha2_create_seq_res_set_expires(
    sandesha2_create_seq_res_t *create_seq_res,
    const axutil_env_t *env, sandesha2_expires_t *expires)
{
	sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
    create_seq_res_impl->expires = expires;
    return AXIS2_SUCCESS;
}


sandesha2_expires_t * AXIS2_CALL
sandesha2_create_seq_res_get_expires(
    sandesha2_create_seq_res_t *create_seq_res,
    const axutil_env_t *env)
{
	sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    
    create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
    return create_seq_res_impl->expires;
}

static axis2_status_t AXIS2_CALL
sandesha2_create_seq_res_to_soap_env(
    sandesha2_iom_rm_part_t *create_seq_res,
    const axutil_env_t *env, axiom_soap_envelope_t *envelope)
{
    sandesha2_create_seq_res_impl_t *create_seq_res_impl = NULL;
    axiom_node_t *body_node = NULL;
    axutil_qname_t *create_seq_res_qname = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, envelope, AXIS2_FAILURE);
    
    create_seq_res_impl = SANDESHA2_INTF_TO_IMPL(create_seq_res);
    /**
     * Remove if old exists
     */
    create_seq_res_qname = axutil_qname_create(env, 
                        SANDESHA2_WSRM_COMMON_CREATE_SEQ_RESPONSE, 
                        create_seq_res_impl->rm_ns_val, NULL);
    if(!create_seq_res_qname)
    {
        return AXIS2_FAILURE;
    }
    sandesha2_utils_remove_soap_body_part(env, envelope, create_seq_res_qname);
    body_node = axiom_soap_body_get_base_node(axiom_soap_envelope_get_body(
                        envelope, env), env);
    sandesha2_create_seq_res_to_om_node((sandesha2_iom_rm_element_t*)
                        create_seq_res, env, body_node);
    return AXIS2_SUCCESS;
}

