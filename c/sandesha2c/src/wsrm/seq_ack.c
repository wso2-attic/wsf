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
 
#include <sandesha2_seq_ack.h>
#include <sandesha2_constants.h>
#include <sandesha2_spec_specific_consts.h>
#include <axiom_soap_header.h>
#include <axiom_soap_header_block.h>

/** 
 * @brief SequenceAcknowledgement struct impl
 *	Sandesha2 IOM SequenceAcknowledgement
 */
typedef struct sandesha2_seq_ack_impl sandesha2_seq_ack_impl_t;  
  
struct sandesha2_seq_ack_impl
{
	sandesha2_seq_ack_t seq_ack;
	sandesha2_identifier_t *identifier;
	axutil_array_list_t *ack_range_list;
	axutil_array_list_t *nack_list;
	sandesha2_ack_none_t *ack_none;
	sandesha2_ack_final_t *ack_final;
	axis2_bool_t must_understand;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(seq_ack) \
						((sandesha2_seq_ack_impl_t *)(seq_ack))

/***************************** Function headers *******************************/
static axis2_char_t* AXIS2_CALL 
sandesha2_seq_ack_get_namespace_value (
    sandesha2_iom_rm_element_t *seq_ack,
    const axutil_env_t *env);
    
static void* AXIS2_CALL 
sandesha2_seq_ack_from_om_node(
   sandesha2_iom_rm_element_t *seq_ack,
   const axutil_env_t *env, axiom_node_t *om_node);
    
static axiom_node_t* AXIS2_CALL 
sandesha2_seq_ack_to_om_node(
   sandesha2_iom_rm_element_t *seq_ack,
   const axutil_env_t *env, void *om_node);
                    	
static axis2_bool_t AXIS2_CALL 
sandesha2_seq_ack_is_namespace_supported(
    sandesha2_iom_rm_element_t *seq_ack,
    const axutil_env_t *env, axis2_char_t *namespace);
                    	
static axis2_status_t AXIS2_CALL
sandesha2_seq_ack_to_soap_env(
    sandesha2_iom_rm_part_t *seq_ack,
    const axutil_env_t *env, 
    axiom_soap_envelope_t *envelope);
                    	
static axis2_status_t AXIS2_CALL 
sandesha2_seq_ack_free (
    sandesha2_iom_rm_element_t *seq_ack, 
    const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_seq_ack_t* AXIS2_CALL
sandesha2_seq_ack_create(const axutil_env_t *env,  axis2_char_t *ns_val)
{
    sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    
    if(AXIS2_FALSE == sandesha2_seq_ack_is_namespace_supported(
                        (sandesha2_iom_rm_element_t*)seq_ack_impl, env, ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
                            AXIS2_FAILURE);
        return NULL;
    }    
    seq_ack_impl =  (sandesha2_seq_ack_impl_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_seq_ack_impl_t));
	
    if(NULL == seq_ack_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    seq_ack_impl->ns_val = NULL;
    seq_ack_impl->identifier = NULL;
    seq_ack_impl->ack_range_list = NULL;
    seq_ack_impl->nack_list = NULL;
    seq_ack_impl->ack_none = NULL;
    seq_ack_impl->ack_final = NULL;
    seq_ack_impl->must_understand = AXIS2_FALSE;
    seq_ack_impl->seq_ack.part.ops = NULL;
    seq_ack_impl->seq_ack.part.element.ops = NULL;
    
    seq_ack_impl->seq_ack.part.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_part_ops_t));
    if(NULL == seq_ack_impl->seq_ack.part.ops)
	{
		sandesha2_seq_ack_free((sandesha2_iom_rm_element_t*)
                         seq_ack_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    seq_ack_impl->seq_ack.part.element.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_element_ops_t));
    if(NULL == seq_ack_impl->seq_ack.part.element.ops)
	{
		sandesha2_seq_ack_free((sandesha2_iom_rm_element_t*)
                         seq_ack_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    seq_ack_impl->ns_val = (axis2_char_t *)axutil_strdup(env, ns_val);
    seq_ack_impl->ack_range_list = axutil_array_list_create(env, 
    					AXIS2_ARRAY_LIST_DEFAULT_CAPACITY);
    seq_ack_impl->nack_list = axutil_array_list_create(env, 
    					AXIS2_ARRAY_LIST_DEFAULT_CAPACITY);

    seq_ack_impl->seq_ack.part.element.ops->get_namespace_value = 
                        sandesha2_seq_ack_get_namespace_value;
    seq_ack_impl->seq_ack.part.element.ops->from_om_node = 
    					sandesha2_seq_ack_from_om_node;
    seq_ack_impl->seq_ack.part.element.ops->to_om_node = 
    					sandesha2_seq_ack_to_om_node;
    seq_ack_impl->seq_ack.part.element.ops->is_namespace_supported = 
    					sandesha2_seq_ack_is_namespace_supported;
    seq_ack_impl->seq_ack.part.ops->to_soap_env = sandesha2_seq_ack_to_soap_env;
    seq_ack_impl->seq_ack.part.element.ops->free = sandesha2_seq_ack_free;
                        
	return &(seq_ack_impl->seq_ack);
}


static axis2_status_t AXIS2_CALL 
sandesha2_seq_ack_free (
    sandesha2_iom_rm_element_t *seq_ack, 
    const axutil_env_t *env)
{
    sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
    
    if(NULL != seq_ack_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, seq_ack_impl->ns_val);
        seq_ack_impl->ns_val = NULL;
    }
    seq_ack_impl->identifier = NULL;
    seq_ack_impl->ack_none = NULL;
    seq_ack_impl->ack_final = NULL;
    seq_ack_impl->must_understand = AXIS2_FALSE;

    if(NULL != seq_ack_impl->ack_range_list)
    {
        axutil_array_list_free(seq_ack_impl->ack_range_list, env);
        seq_ack_impl->ack_range_list = NULL;
    }
    if(NULL != seq_ack_impl->nack_list)
    {
        axutil_array_list_free(seq_ack_impl->nack_list, env);
        seq_ack_impl->nack_list = NULL;
    }
    if(NULL != seq_ack_impl->seq_ack.part.ops)
    {
        AXIS2_FREE(env->allocator, seq_ack_impl->seq_ack.part.ops);
        seq_ack_impl->seq_ack.part.ops = NULL;
    }
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(seq_ack));
	return AXIS2_SUCCESS;
}

static axis2_char_t* AXIS2_CALL 
sandesha2_seq_ack_get_namespace_value (
    sandesha2_iom_rm_element_t *seq_ack,
    const axutil_env_t *env)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
	return seq_ack_impl->ns_val;
}


static void* AXIS2_CALL 
sandesha2_seq_ack_from_om_node(
    sandesha2_iom_rm_element_t *seq_ack,
    const axutil_env_t *env, 
    axiom_node_t *sa_node)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
    axiom_element_t *sa_part = NULL;
    axiom_children_qname_iterator_t *ack_iter = NULL;
    axiom_children_qname_iterator_t *nack_iter= NULL;
    axutil_qname_t *ack_range_qname = NULL;
    axutil_qname_t *nack_qname = NULL;
    axis2_char_t *rm_spec_ver = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axis2_char_t *prefix = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, sa_node, NULL);
    
    seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
    sa_part = axiom_node_get_data_element(sa_node, env);
    if(!sa_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
            AXIS2_FAILURE);
        return NULL;
    }
    rm_ns = axiom_element_get_namespace(sa_part, env, sa_node);
    prefix = axiom_namespace_get_prefix(rm_ns, env);
    seq_ack_impl->identifier = sandesha2_identifier_create(env, 
                        seq_ack_impl->ns_val);
    if(!seq_ack_impl->identifier)
    {
        return NULL;
    }
    sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
        seq_ack_impl->identifier, env, sa_node);
    ack_range_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_ACK_RANGE,
        seq_ack_impl->ns_val, prefix);
    if(!ack_range_qname)
    {
        return NULL;
    }
    ack_iter = axiom_element_get_children_with_qname(sa_part, env, 
        ack_range_qname, sa_node);
    if(!ack_iter)
    {
        return NULL;
    }
    while(axiom_children_qname_iterator_has_next(ack_iter, env))
    {
        axiom_node_t *ack_node = NULL;
        sandesha2_ack_range_t *ack_range = NULL;
        ack_node = axiom_children_qname_iterator_next(ack_iter, env);
        if(ack_node)
        {
            ack_range = sandesha2_ack_range_create(env, seq_ack_impl->ns_val, 
                prefix);
            if(!ack_range)
            {
                return NULL;
            } 
            if(sandesha2_iom_rm_element_from_om_node
                ((sandesha2_iom_rm_element_t *)ack_range, env, ack_node))
                axutil_array_list_add(seq_ack_impl->ack_range_list, env, 
                    ack_range);
        }
    }
    nack_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_NACK, 
        seq_ack_impl->ns_val, NULL);
    if(!nack_qname)
    {
        return NULL;
    }
    nack_iter = axiom_element_get_children_with_qname(sa_part, env, nack_qname, 
        sa_node);
    if(!nack_iter)
    {
        return NULL;
    } 
    while(axiom_children_qname_iterator_has_next(nack_iter, env))
    {
        axiom_node_t *nack_node = NULL;
        sandesha2_nack_t *nack = NULL;
        nack_node = axiom_children_qname_iterator_next(nack_iter, env);
        if(NULL != nack_iter)
        {
            nack = sandesha2_nack_create(env, seq_ack_impl->ns_val);
            if(!nack)
            {
                return NULL;
            }
            sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
                nack, env, nack_node);
            axutil_array_list_add(seq_ack_impl->nack_list, env, nack);
        }
    }
    rm_spec_ver = sandesha2_spec_specific_consts_get_spec_ver_str(env, 
        seq_ack_impl->ns_val);
    if(sandesha2_spec_specific_consts_is_ack_final_allowed(env, rm_spec_ver))
    {
        axiom_element_t *af_part = NULL;
        axiom_node_t *af_node = NULL;
        axutil_qname_t *af_qname = NULL;
       
        af_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_FINAL, 
            seq_ack_impl->ns_val, NULL); 
        if(!af_qname)
        {
            return NULL;
        }
        af_part = axiom_element_get_first_child_with_qname(sa_part, env, 
            af_qname, sa_node, &af_node);
        if(af_part)
        {
            seq_ack_impl->ack_final = sandesha2_ack_final_create(env, 
                seq_ack_impl->ns_val);
            if(!seq_ack_impl->ack_final)
            {
                return NULL;
            }
            sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
                seq_ack_impl->ack_final, env, sa_node);
        }
    }
    if(sandesha2_spec_specific_consts_is_ack_none_allowed(env, rm_spec_ver))
    {
        axiom_element_t *an_part = NULL;
        axiom_node_t *an_node = NULL;
        axutil_qname_t *an_qname = NULL;

        an_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_NONE,
            seq_ack_impl->ns_val, NULL);
        an_part = axiom_element_get_first_child_with_qname(sa_part, env,
            an_qname, sa_node, &an_node);
        if(an_part)
        {
            if(!an_qname)
            {
                return NULL;
            }
            seq_ack_impl->ack_none = sandesha2_ack_none_create(env, 
                seq_ack_impl->ns_val);
            if(!seq_ack_impl->ack_none)
            {
                return NULL;
            }
            sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
                seq_ack_impl->ack_none, env, sa_node);
        }
    }
    return seq_ack;
}


static axiom_node_t* AXIS2_CALL 
sandesha2_seq_ack_to_om_node(
    sandesha2_iom_rm_element_t *seq_ack,
    const axutil_env_t *env, void *om_node)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_node_t *sa_node = NULL;
    axiom_soap_header_t *soap_header = NULL;
    axiom_soap_header_block_t *sa_block = NULL;
    int i = 0;
    axis2_char_t *rm_spec_ver = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
    soap_header = (axiom_soap_header_t*)om_node;
    rm_ns = axiom_namespace_create(env, seq_ack_impl->ns_val,
                        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(NULL == rm_ns)
    {
        return NULL;
    }
    sa_block = axiom_soap_header_add_header_block(soap_header, env, 
                        SANDESHA2_WSRM_COMMON_SEQ_ACK, rm_ns);
    if(NULL == sa_block)
    {
        return NULL;
    }
    if(NULL == seq_ack_impl->identifier)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_OM_NULL_ELEMENT, 
                        AXIS2_FAILURE);
        return NULL;
    }
    axiom_soap_header_block_set_must_understand_with_bool(sa_block, env, 
                        seq_ack_impl->must_understand);
    sa_node = axiom_soap_header_block_get_base_node(sa_block, env);
    sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)seq_ack_impl->identifier, env, sa_node);
    for(i = 0; i < axutil_array_list_size(seq_ack_impl->ack_range_list, env); i++)
    {
        sandesha2_ack_range_t *ack_range = NULL;
        ack_range = (sandesha2_ack_range_t*)axutil_array_list_get(
                        seq_ack_impl->ack_range_list, env, i);
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)ack_range, env, sa_node);
    }
    for(i = 0; i < axutil_array_list_size(seq_ack_impl->nack_list, env); i++)
    {
        sandesha2_nack_t *nack = NULL;
        nack = (sandesha2_nack_t*)axutil_array_list_get(
                        seq_ack_impl->nack_list, env, i);
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)nack, env, sa_node);
    }
    rm_spec_ver = sandesha2_spec_specific_consts_get_spec_ver_str(env,
                        seq_ack_impl->ns_val);
    if(NULL == seq_ack_impl->ack_none && 0 == axutil_array_list_size(
                        seq_ack_impl->ack_range_list, env) &&
                        0 == axutil_array_list_size(seq_ack_impl->nack_list, env)
                        && AXIS2_TRUE == 
                        sandesha2_spec_specific_consts_is_ack_none_allowed(env,
                        rm_spec_ver))
    {
        seq_ack_impl->ack_none = sandesha2_ack_none_create(env, 
                        seq_ack_impl->ns_val);
        if(NULL == seq_ack_impl->ack_none)
        {
            return NULL;
        }
    }
    if(NULL != seq_ack_impl->ack_none)
    {
        if(AXIS2_TRUE != sandesha2_spec_specific_consts_is_ack_none_allowed(env,
                        rm_spec_ver) || 0 != axutil_array_list_size(
                        seq_ack_impl->ack_range_list, env) || 0 != 
                        axutil_array_list_size(seq_ack_impl->nack_list, env))
        {
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_ACK_NONE_NOT_ALLOWED, 
                        AXIS2_FAILURE);
            return NULL;
        }
        else
        {
            sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)seq_ack_impl->ack_none, env, 
                        sa_node);   
        }                            
    }
    if(NULL != seq_ack_impl->ack_final)
    {
        if(AXIS2_TRUE != sandesha2_spec_specific_consts_is_ack_final_allowed(
                        env, rm_spec_ver) ||  0 != axutil_array_list_size(
                        seq_ack_impl->nack_list, env))
        {
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_ACK_FINAL_NOT_ALLOWED, 
                        AXIS2_FAILURE);
            return NULL;
        }
        else
        {
            sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)seq_ack_impl->ack_final, env, 
                        sa_node);  
        }
    }
    /**
     *  we do not need to add the header block as it is already done
     */
    return sa_node;
}

static axis2_bool_t AXIS2_CALL 
sandesha2_seq_ack_is_namespace_supported(
    sandesha2_iom_rm_element_t *seq_ack,
    const axutil_env_t *env, axis2_char_t *namespace)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
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
sandesha2_seq_ack_get_identifier(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
	
	return seq_ack_impl->identifier;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_seq_ack_set_identifier(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env,
    sandesha2_identifier_t *identifier)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
	seq_ack_impl->identifier = identifier;
 	return AXIS2_SUCCESS;
}

axutil_array_list_t * AXIS2_CALL
sandesha2_seq_ack_get_nack_list(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
	
	return seq_ack_impl->nack_list;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_seq_ack_set_ack_final(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env, 
    sandesha2_ack_final_t *ack_final)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
	seq_ack_impl->ack_final = ack_final;
 	return AXIS2_SUCCESS;
}

axutil_array_list_t * AXIS2_CALL
sandesha2_seq_ack_get_ack_range_list(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
	
	return seq_ack_impl->ack_range_list;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_seq_ack_add_ack_range(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env, 
    sandesha2_ack_range_t *ack_range)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
	axutil_array_list_add(seq_ack_impl->ack_range_list, env, ack_range);
 	return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
sandesha2_seq_ack_is_must_understand(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FALSE);
	
	seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
	return seq_ack_impl->must_understand;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_seq_ack_set_must_understand(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env, axis2_bool_t mu)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
    
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
	seq_ack_impl->must_understand = mu;
 	return AXIS2_SUCCESS;
}


static axis2_status_t AXIS2_CALL
sandesha2_seq_ack_to_soap_env(
    sandesha2_iom_rm_part_t *seq_ack,
    const axutil_env_t *env, axiom_soap_envelope_t *envelope)
{
	sandesha2_seq_ack_impl_t *seq_ack_impl = NULL;
    axiom_soap_header_t *soap_header = NULL;
    axutil_qname_t *seq_ack_qname = NULL;
    
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, envelope, AXIS2_FAILURE);
    
	seq_ack_impl = SANDESHA2_INTF_TO_IMPL(seq_ack);
    soap_header = axiom_soap_envelope_get_header(envelope, env);
    /**
     * Remove if old exists
     */
    seq_ack_qname = axutil_qname_create(env, 
                        SANDESHA2_WSRM_COMMON_SEQ_ACK,
                        seq_ack_impl->ns_val, NULL);
    if(NULL == seq_ack_qname)
    {
        return AXIS2_FAILURE;
    }
    axiom_soap_header_remove_header_block(soap_header, env, seq_ack_qname);
    sandesha2_seq_ack_to_om_node((sandesha2_iom_rm_element_t*)seq_ack, env, 
                        soap_header);
	return AXIS2_SUCCESS;
}

