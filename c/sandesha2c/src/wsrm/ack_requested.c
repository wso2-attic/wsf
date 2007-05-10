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
 
#include <sandesha2_ack_requested.h>
#include <axiom_soap_header.h>
#include <axiom_soap_header_block.h>
#include <sandesha2_constants.h>

typedef struct sandesha2_ack_requested_impl sandesha2_ack_requested_impl_t;
/** 
 * @brief AckRequested struct impl
 *	Sandesha2 IOM AckRequested
 */
struct sandesha2_ack_requested_impl
{
    sandesha2_ack_requested_t ack_requested;
	sandesha2_identifier_t *identifier;
	sandesha2_msg_number_t *msg_num;
	axis2_bool_t must_understand;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(ack_requested) \
						((sandesha2_ack_requested_impl_t *)(ack_requested))

static axis2_char_t* AXIS2_CALL 
sandesha2_ack_requested_get_namespace_value (
                        sandesha2_iom_rm_element_t *ack_requested,
						const axutil_env_t *env);
    
static void* AXIS2_CALL 
sandesha2_ack_requested_from_om_node(sandesha2_iom_rm_element_t *ack_requested,
                    	const axutil_env_t *env, axiom_node_t *om_node);
    
static axiom_node_t* AXIS2_CALL 
sandesha2_ack_requested_to_om_node(sandesha2_iom_rm_element_t *element,
                    	const axutil_env_t *env, void *om_node);
                    	
static axis2_bool_t AXIS2_CALL 
sandesha2_ack_requested_is_namespace_supported(
                        sandesha2_iom_rm_element_t *ack_requested,
                    	const axutil_env_t *env, axis2_char_t *namespace);
                    	
static axis2_status_t AXIS2_CALL
sandesha2_ack_requested_to_soap_env(sandesha2_iom_rm_part_t *ack_requested,
                    	const axutil_env_t *env, axiom_soap_envelope_t *envelope);
                    	
static axis2_status_t AXIS2_CALL 
sandesha2_ack_requested_free (sandesha2_iom_rm_element_t *ack_requested, 
						const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_ack_requested_t* AXIS2_CALL
sandesha2_ack_requested_create(const axutil_env_t *env,  axis2_char_t *ns_val)
{
    sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    if(AXIS2_FALSE == sandesha2_ack_requested_is_namespace_supported(
                        (sandesha2_iom_rm_element_t*)ack_requested_impl, env, 
                        ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
                            AXIS2_FAILURE);
        return NULL;
    }    
    ack_requested_impl =  (sandesha2_ack_requested_impl_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_ack_requested_impl_t));
	
    if(!ack_requested_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    ack_requested_impl->ns_val = NULL;
    ack_requested_impl->identifier = NULL;
    ack_requested_impl->msg_num = NULL;
    ack_requested_impl->must_understand = AXIS2_FALSE;
    ack_requested_impl->ack_requested.part.ops = NULL;
    ack_requested_impl->ack_requested.part.element.ops = NULL;
    
    ack_requested_impl->ack_requested.part.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_part_ops_t));
    if(!ack_requested_impl->ack_requested.part.ops)
	{
		sandesha2_ack_requested_free((sandesha2_iom_rm_element_t*)
                         ack_requested_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    ack_requested_impl->ack_requested.part.element.ops = AXIS2_MALLOC(
        env->allocator, sizeof(sandesha2_iom_rm_element_ops_t));
    if(!ack_requested_impl->ack_requested.part.element.ops)
	{
		sandesha2_ack_requested_free((sandesha2_iom_rm_element_t*)
                         ack_requested_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    ack_requested_impl->ns_val = (axis2_char_t *)axutil_strdup(env , ns_val);
    
    ack_requested_impl->ack_requested.part.element.ops->get_namespace_value = 
                        sandesha2_ack_requested_get_namespace_value;
    ack_requested_impl->ack_requested.part.element.ops->from_om_node = 
    					sandesha2_ack_requested_from_om_node;
    ack_requested_impl->ack_requested.part.element.ops->to_om_node = 
    					sandesha2_ack_requested_to_om_node;
    ack_requested_impl->ack_requested.part.element.ops->is_namespace_supported = 
    					sandesha2_ack_requested_is_namespace_supported;
    ack_requested_impl->ack_requested.part.ops->to_soap_env = 
    					sandesha2_ack_requested_to_soap_env;
    ack_requested_impl->ack_requested.part.element.ops->free = 
                        sandesha2_ack_requested_free;
                        
	return &(ack_requested_impl->ack_requested);
}


static axis2_status_t AXIS2_CALL 
sandesha2_ack_requested_free (sandesha2_iom_rm_element_t *ack_requested, 
						const axutil_env_t *env)
{
    sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
    
    if(ack_requested_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, ack_requested_impl->ns_val);
        ack_requested_impl->ns_val = NULL;
    }
    ack_requested_impl->identifier = NULL;
    ack_requested_impl->msg_num = NULL;
    
    if(ack_requested_impl->ack_requested.part.ops)
    {
        AXIS2_FREE(env->allocator, ack_requested_impl->ack_requested.part.ops);
        ack_requested_impl->ack_requested.part.ops = NULL;
    }
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(ack_requested));
	return AXIS2_SUCCESS;
}

static axis2_char_t* AXIS2_CALL 
sandesha2_ack_requested_get_namespace_value (
                        sandesha2_iom_rm_element_t *ack_requested,
						const axutil_env_t *env)
{
	sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
	return ack_requested_impl->ns_val;
}


static void* AXIS2_CALL 
sandesha2_ack_requested_from_om_node(
    sandesha2_iom_rm_element_t *ack_requested,
    const axutil_env_t *env, 
    axiom_node_t *requested_node)
{
	sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
    axiom_element_t *requested_part = NULL;
    axiom_element_t *msg_num_part = NULL;
    axiom_node_t *msg_num_node = NULL;
    axutil_qname_t *msg_num_qname = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, requested_node, NULL);
    
    ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
    requested_part = axiom_node_get_data_element(requested_node, env);
    if(!requested_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    ack_requested_impl->identifier = sandesha2_identifier_create(env, 
                        ack_requested_impl->ns_val);
    if(!ack_requested_impl->identifier)
    {
        return NULL;
    }
    if(!sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
        ack_requested_impl->identifier, env, requested_node))
    {
        return NULL;
    }
    msg_num_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_MSG_NUMBER,
        ack_requested_impl->ns_val, NULL);
    if(!msg_num_qname)
    {
        return NULL;
    }
    msg_num_part = axiom_element_get_first_child_with_qname(requested_part, env, 
        msg_num_qname, requested_node, &msg_num_node);
    if(msg_num_part)
    {
        ack_requested_impl->msg_num = sandesha2_msg_number_create(env, 
            ack_requested_impl->ns_val);
        if(!ack_requested_impl->msg_num)
        {
            return NULL;
        }
        if(!sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            ack_requested_impl->msg_num, env, requested_node))
        {
            return NULL;
        }
    }
    return ack_requested;
}


static axiom_node_t* AXIS2_CALL 
sandesha2_ack_requested_to_om_node(
        sandesha2_iom_rm_element_t *ack_requested,
       	const axutil_env_t *env, 
        void *om_node)
{
	sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_node_t *ar_node = NULL;
    axiom_soap_header_t *soap_header = NULL;
    axiom_soap_header_block_t *ar_header_blk = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
    soap_header = (axiom_soap_header_t*)om_node;
    if(!ack_requested_impl->identifier)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_OM_NULL_ELEMENT, 
                        AXIS2_FAILURE);
        return NULL;
    }
    rm_ns = axiom_namespace_create(env, ack_requested_impl->ns_val,
                        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(!rm_ns)
    {
        return NULL;
    }
    ar_header_blk = axiom_soap_header_add_header_block(soap_header, env, 
                        SANDESHA2_WSRM_COMMON_ACK_REQUESTED, rm_ns);
    axiom_soap_header_block_set_must_understand_with_bool(ar_header_blk, env,
                        ack_requested_impl->must_understand);
    ar_node = axiom_soap_header_block_get_base_node(ar_header_blk, env);
    sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            ack_requested_impl->identifier, env, ar_node);
    if(ack_requested_impl->msg_num)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
                ack_requested_impl->msg_num, env, ar_node);
    }
    return ar_node;
}

static axis2_bool_t AXIS2_CALL 
sandesha2_ack_requested_is_namespace_supported(
                        sandesha2_iom_rm_element_t *ack_requested,
                    	const axutil_env_t *env, axis2_char_t *namespace)
{
	sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
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

static axis2_status_t AXIS2_CALL
sandesha2_ack_requested_to_soap_env(
        sandesha2_iom_rm_part_t *ack_requested,
       	const axutil_env_t *env, 
        axiom_soap_envelope_t *envelope)
{
	sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
    axiom_soap_header_t *soap_header = NULL;
    axutil_qname_t *requested_qname = NULL;
    
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, envelope, AXIS2_FAILURE);
	
	ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
    soap_header = axiom_soap_envelope_get_header(envelope, env);
    /**
     * Remove if header block exists
     */
    requested_qname = axutil_qname_create(env, 
                        SANDESHA2_WSRM_COMMON_ACK_REQUESTED,
                        ack_requested_impl->ns_val, NULL);
    if(!requested_qname)
    {
        return AXIS2_FAILURE;
    } 
    axiom_soap_header_remove_header_block(soap_header, env, requested_qname);
    sandesha2_ack_requested_to_om_node((sandesha2_iom_rm_element_t*)
                        ack_requested, env, soap_header);
	return AXIS2_SUCCESS;
}

sandesha2_identifier_t * AXIS2_CALL
sandesha2_ack_requested_get_identifier(sandesha2_ack_requested_t *ack_requested,
                    	const axutil_env_t *env)
{
	sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
	
	return ack_requested_impl->identifier;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_ack_requested_set_identifier(sandesha2_ack_requested_t *ack_requested,
                    	const axutil_env_t *env, sandesha2_identifier_t *identifier)
{
	sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
 	if(ack_requested_impl->identifier)
	{
		/*
		SANDESHA2_IDENTIFIER_FREE(ack_requested_impl->identifier, env);
		ack_requested_impl->identifier = NULL;
		*/
	}
	ack_requested_impl->identifier = identifier;
 	return AXIS2_SUCCESS;
}

sandesha2_msg_number_t * AXIS2_CALL                    	
sandesha2_ack_requested_get_msg_number(sandesha2_ack_requested_t *ack_requested,
                    	const axutil_env_t *env)
{
	sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
	return ack_requested_impl->msg_num;
}

axis2_status_t AXIS2_CALL
sandesha2_ack_requested_set_msg_number(sandesha2_ack_requested_t *ack_requested,
                    	const axutil_env_t *env, 
                        sandesha2_msg_number_t *msg_number)
{
	sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
 	if(ack_requested_impl->msg_num)
	{
	    /*
		SANDESHA2_MSG_NUMBER_FREE(ack_requested_impl->msg_num, env);
		ack_requested_impl->msg_num = NULL;
		*/
	}
	ack_requested_impl->msg_num = msg_number;
 	return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
sandesha2_ack_requested_is_must_understand(
                        sandesha2_ack_requested_t *ack_requested,
                    	const axutil_env_t *env)
{
	sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
	return ack_requested_impl->must_understand;
}
                    	
axis2_status_t AXIS2_CALL
sandesha2_ack_requested_set_must_understand(
                        sandesha2_ack_requested_t *ack_requested,
                    	const axutil_env_t *env, axis2_bool_t mu)
{
	sandesha2_ack_requested_impl_t *ack_requested_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	ack_requested_impl = SANDESHA2_INTF_TO_IMPL(ack_requested);
	ack_requested_impl->must_understand = mu;
	return AXIS2_SUCCESS;
}

