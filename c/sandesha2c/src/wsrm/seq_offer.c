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
 
#include <sandesha2_seq_offer.h>
#include <sandesha2_constants.h>

/** 
 * @brief SequenceOffer struct impl
 *	Sandesha2 IOM SequenceOffer
 */
typedef struct sandesha2_seq_offer_impl sandesha2_seq_offer_impl_t;  
  
struct sandesha2_seq_offer_impl
{
    sandesha2_seq_offer_t seq_offer;
	sandesha2_identifier_t *identifier;
	sandesha2_expires_t *expires;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(seq_offer) \
						((sandesha2_seq_offer_impl_t *)(seq_offer))

/***************************** Function headers *******************************/
static axis2_char_t* AXIS2_CALL 
sandesha2_seq_offer_get_namespace_value (sandesha2_iom_rm_element_t *seq_offer,
						const axutil_env_t *env);
    
static void* AXIS2_CALL 
sandesha2_seq_offer_from_om_node(sandesha2_iom_rm_element_t *seq_offer,
                    	const axutil_env_t *env, axiom_node_t *om_node);
    
static axiom_node_t* AXIS2_CALL 
sandesha2_seq_offer_to_om_node(sandesha2_iom_rm_element_t *seq_offer,
                    	const axutil_env_t *env, void *om_node);
                    	
static axis2_bool_t AXIS2_CALL 
sandesha2_seq_offer_is_namespace_supported(
                        sandesha2_iom_rm_element_t *seq_offer,
                    	const axutil_env_t *env, axis2_char_t *namespace);
                    	
static axis2_status_t AXIS2_CALL 
sandesha2_seq_offer_free (sandesha2_iom_rm_element_t *seq_offer, 
						const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_seq_offer_t* AXIS2_CALL
sandesha2_seq_offer_create(
    const axutil_env_t *env,  
    axis2_char_t *ns_val)
{
    sandesha2_seq_offer_impl_t *seq_offer_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    
    if(AXIS2_FALSE == sandesha2_seq_offer_is_namespace_supported(
                        (sandesha2_iom_rm_element_t*)seq_offer_impl, env, 
                        ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
                            AXIS2_FAILURE);
        return NULL;
    }    
    seq_offer_impl =  (sandesha2_seq_offer_impl_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_seq_offer_impl_t));
	
    if(NULL == seq_offer_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    seq_offer_impl->ns_val = (axis2_char_t *)axutil_strdup(env, ns_val);
    seq_offer_impl->identifier = NULL;
    seq_offer_impl->expires = NULL;
    seq_offer_impl->seq_offer.element.ops = NULL;
    seq_offer_impl->seq_offer.element.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_element_ops_t));
    if(NULL == seq_offer_impl->seq_offer.element.ops)
	{
		sandesha2_seq_offer_free((sandesha2_iom_rm_element_t*)
                         seq_offer_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    seq_offer_impl->seq_offer.element.ops->get_namespace_value = 
                        sandesha2_seq_offer_get_namespace_value;
    seq_offer_impl->seq_offer.element.ops->from_om_node = 
    					sandesha2_seq_offer_from_om_node;
    seq_offer_impl->seq_offer.element.ops->to_om_node = 
    					sandesha2_seq_offer_to_om_node;
    seq_offer_impl->seq_offer.element.ops->is_namespace_supported = 
    					sandesha2_seq_offer_is_namespace_supported;
    seq_offer_impl->seq_offer.element.ops->free = sandesha2_seq_offer_free;
                        
	return &(seq_offer_impl->seq_offer);
}


static axis2_status_t AXIS2_CALL 
sandesha2_seq_offer_free (
     sandesha2_iom_rm_element_t *seq_offer, 
	const axutil_env_t *env)
{
    sandesha2_seq_offer_impl_t *seq_offer_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    seq_offer_impl = SANDESHA2_INTF_TO_IMPL(seq_offer);
    
    if(NULL != seq_offer_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, seq_offer_impl->ns_val);
        seq_offer_impl->ns_val = NULL;
    }
    seq_offer_impl->identifier = NULL;
    seq_offer_impl->expires = NULL;
    if(NULL != seq_offer_impl->seq_offer.element.ops)
    {
        AXIS2_FREE(env->allocator, seq_offer_impl->seq_offer.element.ops);
        seq_offer_impl->seq_offer.element.ops = NULL;
    }
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(seq_offer));
	return AXIS2_SUCCESS;
}

static axis2_char_t* AXIS2_CALL 
sandesha2_seq_offer_get_namespace_value (
    sandesha2_iom_rm_element_t *seq_offer,
	const axutil_env_t *env)
{
	sandesha2_seq_offer_impl_t *seq_offer_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_offer_impl = SANDESHA2_INTF_TO_IMPL(seq_offer);
	return seq_offer_impl->ns_val;
}


static void* AXIS2_CALL 
sandesha2_seq_offer_from_om_node(
    sandesha2_iom_rm_element_t *seq_offer,
    const axutil_env_t *env, 
    axiom_node_t *om_node)
{
	sandesha2_seq_offer_impl_t *seq_offer_impl = NULL;
    axiom_element_t *om_element = NULL;
    axiom_element_t *so_part = NULL;
    axiom_element_t *exp_part = NULL;
    axiom_node_t *so_node = NULL;
    axiom_node_t *exp_node = NULL;
    axutil_qname_t *so_qname = NULL;
    axutil_qname_t *exp_qname = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    seq_offer_impl = SANDESHA2_INTF_TO_IMPL(seq_offer);
    om_element = axiom_node_get_data_element(om_node, env);
    if(NULL == om_element)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    so_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_SEQ_OFFER,
                        seq_offer_impl->ns_val, NULL);
    if(NULL == so_qname)
    {
        return NULL;
    }
    so_part = axiom_element_get_first_child_with_qname(om_element, env,
                        so_qname, om_node, &so_node);
    if(NULL == so_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    seq_offer_impl->identifier = sandesha2_identifier_create(env, 
                        seq_offer_impl->ns_val); 
    if(NULL == seq_offer_impl->identifier)
    {
        return NULL;
    }
    sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            seq_offer_impl->identifier, env, so_node);
    exp_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_EXPIRES,
                        seq_offer_impl->ns_val, NULL);
    if(NULL == exp_qname)
    {
        return NULL;
    }
    exp_part = axiom_element_get_first_child_with_qname(so_part, env,
                        exp_qname, so_node, &exp_node); 
    if(NULL != exp_part)
    {
        seq_offer_impl->expires = sandesha2_expires_create(env, 
                        seq_offer_impl->ns_val);
        if(NULL == seq_offer_impl->expires)
        {
            return NULL;
        }
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
                seq_offer_impl->expires, env, exp_node);
    }
    return seq_offer;
}


static axiom_node_t* AXIS2_CALL 
sandesha2_seq_offer_to_om_node(
    sandesha2_iom_rm_element_t *seq_offer,
    const axutil_env_t *env, void *om_node)
{
	sandesha2_seq_offer_impl_t *seq_offer_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_element_t *so_element = NULL;
    axiom_node_t *so_node = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    seq_offer_impl = SANDESHA2_INTF_TO_IMPL(seq_offer);
    if(NULL == seq_offer_impl->identifier)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_OM_NULL_ELEMENT, 
                        AXIS2_FAILURE);
        return NULL;
    }
    rm_ns = axiom_namespace_create(env, seq_offer_impl->ns_val,
                        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(NULL == rm_ns)
    {
        return NULL;
    }
    so_element = axiom_element_create(env, NULL, 
                        SANDESHA2_WSRM_COMMON_SEQ_OFFER, rm_ns, &so_node);
    if(NULL == so_element)
    {
        return NULL;
    }
    sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            seq_offer_impl->identifier, env, so_node);
    if(NULL != seq_offer_impl->expires)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
                seq_offer_impl->expires, env, so_node);
    }
    axiom_node_add_child((axiom_node_t*)om_node, env, so_node);
    return (axiom_node_t*)om_node;
}

static axis2_bool_t AXIS2_CALL 
sandesha2_seq_offer_is_namespace_supported(
    sandesha2_iom_rm_element_t *seq_offer,
    const axutil_env_t *env, 
    axis2_char_t *namespace)
{
	sandesha2_seq_offer_impl_t *seq_offer_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    seq_offer_impl = SANDESHA2_INTF_TO_IMPL(seq_offer);
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

sandesha2_identifier_t * AXIS2_CALL
sandesha2_seq_offer_get_identifier(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env)
{
	sandesha2_seq_offer_impl_t *seq_offer_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_offer_impl = SANDESHA2_INTF_TO_IMPL(seq_offer);
	
	return seq_offer_impl->identifier;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_seq_offer_set_identifier(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env, 
    sandesha2_identifier_t *identifier)
{
	sandesha2_seq_offer_impl_t *seq_offer_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	seq_offer_impl = SANDESHA2_INTF_TO_IMPL(seq_offer);
 	if(NULL != seq_offer_impl->identifier)
	{
	/*
		SANDESHA2_IDENTIFIER_FREE(seq_offer_impl->identifier, env);
		seq_offer_impl->identifier = NULL;
    */		
	}
	seq_offer_impl->identifier = identifier;
 	return AXIS2_SUCCESS;
}

sandesha2_expires_t * AXIS2_CALL                    	
sandesha2_seq_offer_get_expires(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env)
{
	sandesha2_seq_offer_impl_t *seq_offer_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_offer_impl = SANDESHA2_INTF_TO_IMPL(seq_offer);
	return seq_offer_impl->expires;
}

axis2_status_t AXIS2_CALL
sandesha2_seq_offer_set_expires(
    sandesha2_seq_offer_t *seq_offer,
    const axutil_env_t *env, sandesha2_expires_t *expires)
{
	sandesha2_seq_offer_impl_t *seq_offer_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	seq_offer_impl = SANDESHA2_INTF_TO_IMPL(seq_offer);
	seq_offer_impl->expires = expires;
 	return AXIS2_SUCCESS;
}

