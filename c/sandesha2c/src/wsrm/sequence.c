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
 
#include <sandesha2_seq.h>
#include <sandesha2_constants.h>
#include <axiom_soap_header.h>
#include <axiom_soap_header_block.h>

/** 
 * @brief Sequence struct impl
 *	Sandesha2 IOM Sequence
 */
typedef struct sandesha2_seq_impl sandesha2_seq_impl_t;  
  
struct sandesha2_seq_impl
{
	sandesha2_seq_t seq;
	sandesha2_identifier_t *identifier;
	sandesha2_msg_number_t *msg_num;
	sandesha2_last_msg_t *last_msg;
	axis2_bool_t must_understand;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(seq) \
						((sandesha2_seq_impl_t *)(seq))

/***************************** Function headers *******************************/
static axis2_char_t* AXIS2_CALL 
sandesha2_seq_get_namespace_value (
    sandesha2_iom_rm_element_t *seq,
	const axutil_env_t *env);
    
static void* AXIS2_CALL 
sandesha2_seq_from_om_node(
    sandesha2_iom_rm_element_t *seq,
    const axutil_env_t *env, 
    axiom_node_t *om_node);
    
static axiom_node_t* AXIS2_CALL 
sandesha2_seq_to_om_node(
    sandesha2_iom_rm_element_t *seq,
    const axutil_env_t *env, 
    void *om_node);
                    	
static axis2_bool_t AXIS2_CALL 
sandesha2_seq_is_namespace_supported(
    sandesha2_iom_rm_element_t *seq,
    const axutil_env_t *env, 
    axis2_char_t *namespace);

static axis2_status_t AXIS2_CALL
sandesha2_seq_to_soap_env(
    sandesha2_iom_rm_part_t *seq,
    const axutil_env_t *env, 
    axiom_soap_envelope_t *envelope);
                    	                    	
static axis2_status_t AXIS2_CALL 
sandesha2_seq_free (
    sandesha2_iom_rm_element_t *seq, 
	const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_seq_t* AXIS2_CALL
sandesha2_seq_create(const axutil_env_t *env,  axis2_char_t *ns_val)
{
    sandesha2_seq_impl_t *seq_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    
    if(AXIS2_FALSE == sandesha2_seq_is_namespace_supported(
                        (sandesha2_iom_rm_element_t*)seq_impl, env, 
                        ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
                            AXIS2_FAILURE);
        return NULL;
    }    
    seq_impl =  (sandesha2_seq_impl_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_seq_impl_t));
	
    if(!seq_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    seq_impl->ns_val = NULL;
    seq_impl->identifier = NULL;
    seq_impl->msg_num = NULL;
    seq_impl->last_msg = NULL;
    seq_impl->must_understand = AXIS2_TRUE;
    seq_impl->seq.part.ops = NULL;
    seq_impl->seq.part.element.ops = NULL;
    
    seq_impl->seq.part.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_part_ops_t));
    if(!seq_impl->seq.part.ops)
	{
		sandesha2_seq_free((sandesha2_iom_rm_element_t*)
                         seq_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    seq_impl->seq.part.element.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_element_ops_t));
    if(!seq_impl->seq.part.element.ops)
	{
		sandesha2_seq_free((sandesha2_iom_rm_element_t*)
                         seq_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    seq_impl->ns_val = (axis2_char_t *)axutil_strdup(env, ns_val);
    
    seq_impl->seq.part.element.ops->get_namespace_value = 
                        sandesha2_seq_get_namespace_value;
    seq_impl->seq.part.element.ops->from_om_node = 
    					sandesha2_seq_from_om_node;
    seq_impl->seq.part.element.ops->to_om_node = 
    					sandesha2_seq_to_om_node;
    seq_impl->seq.part.element.ops->is_namespace_supported = 
    					sandesha2_seq_is_namespace_supported;
    seq_impl->seq.part.ops->to_soap_env = 
    					sandesha2_seq_to_soap_env;
    seq_impl->seq.part.element.ops->free = sandesha2_seq_free;
    
                        
	return &(seq_impl->seq);
}

axis2_status_t AXIS2_CALL
sandesha2_seq_free_void_arg(
    void *seq,
    const axutil_env_t *env)
{
    sandesha2_iom_rm_element_t *seq_l = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    seq_l = (sandesha2_iom_rm_element_t *) seq;
    return sandesha2_seq_free(seq_l, env);
}

static axis2_status_t AXIS2_CALL 
sandesha2_seq_free (
    sandesha2_iom_rm_element_t *seq, 
	const axutil_env_t *env)
{
    sandesha2_seq_impl_t *seq_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
    
    if(seq_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, seq_impl->ns_val);
        seq_impl->ns_val = NULL;
    }
    seq_impl->identifier = NULL;
    seq_impl->msg_num = NULL;
    seq_impl->last_msg = NULL;
    if(seq->ops)
        AXIS2_FREE(env->allocator, seq->ops);
    
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(seq));
	return AXIS2_SUCCESS;
}

static axis2_char_t* AXIS2_CALL 
sandesha2_seq_get_namespace_value (
    sandesha2_iom_rm_element_t *seq,
	const axutil_env_t *env)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
	return seq_impl->ns_val;
}


static void* AXIS2_CALL 
sandesha2_seq_from_om_node(
    sandesha2_iom_rm_element_t *seq,
    const axutil_env_t *env, 
    axiom_node_t *seq_node)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
    axiom_element_t *seq_part = NULL;
    axiom_element_t *lm_part = NULL;
    axiom_node_t *lm_node = NULL;
    axutil_qname_t *lm_qname = NULL; 
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, seq_node, NULL);
    
    seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
    seq_part = axiom_node_get_data_element(seq_node, env);
    if(!seq_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
            AXIS2_FAILURE);
        return NULL;
    }
    seq_impl->identifier = sandesha2_identifier_create(env, seq_impl->ns_val);
    if(!seq_impl->identifier)
    {
        return NULL;
    }
    sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
        seq_impl->identifier, env, seq_node);
    seq_impl->msg_num= sandesha2_msg_number_create(env, seq_impl->ns_val);
    if(!seq_impl->msg_num)
    {
        return NULL;
    }
    sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
        seq_impl->msg_num, env, seq_node);
    lm_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_LAST_MSG,
        seq_impl->ns_val, NULL);
    if(!lm_qname)
    {
        return NULL;
    }
    lm_part = axiom_element_get_first_child_with_qname(seq_part, env, 
        lm_qname, seq_node, &lm_node);
    if(lm_part)
    {
        seq_impl->last_msg = sandesha2_last_msg_create(env, 
            seq_impl->ns_val);
        if(!seq_impl->last_msg)
        {
            return NULL;
        }
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            seq_impl->last_msg, env, lm_node);
    }
    return seq;
}


static axiom_node_t* AXIS2_CALL 
sandesha2_seq_to_om_node(
    sandesha2_iom_rm_element_t *seq,
    const axutil_env_t *env, void *om_node)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_soap_header_t *soap_header = NULL;
    axiom_soap_header_block_t *seq_block = NULL;
    axiom_node_t *seq_node = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
    soap_header = (axiom_soap_header_t*)om_node;
    if(!seq_impl->identifier || !seq_impl->msg_num)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_OM_NULL_ELEMENT, 
                        AXIS2_FAILURE);
        return NULL;
    }
    rm_ns = axiom_namespace_create(env, seq_impl->ns_val,
                        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(!rm_ns)
    {
        return NULL;
    }
    seq_block = axiom_soap_header_add_header_block(soap_header, env, 
                        SANDESHA2_WSRM_COMMON_SEQ, rm_ns);
    if(!seq_block)
    {
        return NULL;
    }
    axiom_soap_header_block_set_must_understand_with_bool(seq_block, env, 
                        seq_impl->must_understand);
    seq_node = axiom_soap_header_block_get_base_node(seq_block, env);
    sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)seq_impl->identifier, env, seq_node);
    sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)seq_impl->msg_num, env, seq_node);
    if(seq_impl->last_msg)
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)seq_impl->last_msg, env, 
                        seq_node);
    return seq_node;
}

static axis2_bool_t AXIS2_CALL 
sandesha2_seq_is_namespace_supported(
    sandesha2_iom_rm_element_t *seq,
    const axutil_env_t *env, axis2_char_t *namespace)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
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
sandesha2_seq_get_identifier(
    sandesha2_seq_t *element,
    const axutil_env_t *env)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_impl = SANDESHA2_INTF_TO_IMPL(element);
	
	return seq_impl->identifier;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_seq_set_identifier(
    sandesha2_seq_t *seq,
    const axutil_env_t *env, 
    sandesha2_identifier_t *identifier)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
	seq_impl->identifier = identifier;
 	return AXIS2_SUCCESS;
}

sandesha2_msg_number_t * AXIS2_CALL
sandesha2_seq_get_msg_num(
    sandesha2_seq_t *seq,
    const axutil_env_t *env)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
	
	return seq_impl->msg_num;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_seq_set_msg_num(
    sandesha2_seq_t *seq,
    const axutil_env_t *env, sandesha2_msg_number_t *msg_num)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
	seq_impl->msg_num = msg_num;
 	return AXIS2_SUCCESS;
}

sandesha2_last_msg_t * AXIS2_CALL
sandesha2_seq_get_last_msg(
    sandesha2_seq_t *seq,
    const axutil_env_t *env)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
	
	return seq_impl->last_msg;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_seq_set_last_msg(
    sandesha2_seq_t *seq,
    const axutil_env_t *env, sandesha2_last_msg_t *last_msg)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
	seq_impl->last_msg = last_msg;
 	return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
sandesha2_seq_is_must_understand(
    sandesha2_seq_t *seq,
    const axutil_env_t *env)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FALSE);
	
	seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
	return seq_impl->must_understand;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_seq_set_must_understand(
    sandesha2_seq_t *seq,
    const axutil_env_t *env, axis2_bool_t mu)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
	seq_impl->must_understand = mu;
 	return AXIS2_SUCCESS;
}


static axis2_status_t AXIS2_CALL
sandesha2_seq_to_soap_env(
    sandesha2_iom_rm_part_t *seq,
    const axutil_env_t *env, 
    axiom_soap_envelope_t *envelope)
{
	sandesha2_seq_impl_t *seq_impl = NULL;
	axiom_soap_header_t *soap_header = NULL;
    axutil_qname_t *seq_qname = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, envelope, AXIS2_FAILURE);
	
	seq_impl = SANDESHA2_INTF_TO_IMPL(seq);
    soap_header = axiom_soap_envelope_get_header(envelope, env);
    /**
     * Remove if old exists
     */
    seq_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_SEQ, 
                        seq_impl->ns_val, NULL);
    if(!seq_qname)
    {
        return AXIS2_FAILURE;
    }
    axiom_soap_header_remove_header_block(soap_header, env, seq_qname);
    sandesha2_seq_to_om_node((sandesha2_iom_rm_element_t*)seq, env, 
                        soap_header);
	return AXIS2_SUCCESS;
}

