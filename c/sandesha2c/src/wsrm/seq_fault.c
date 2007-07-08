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
 
#include <sandesha2_seq_fault.h>
#include <sandesha2_constants.h>
#include <sandesha2_iom_rm_element.h>

/** 
 * @brief SequenceFault struct impl
 *	Sandesha2 IOM SequenceFault
 */
typedef struct sandesha2_seq_fault_impl sandesha2_seq_fault_impl_t;  
  
struct sandesha2_seq_fault_impl
{
	sandesha2_seq_fault_t seq_fault;
	sandesha2_fault_code_t *fault_code;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(seq_fault) \
						((sandesha2_seq_fault_impl_t *)(seq_fault))

/***************************** Function headers *******************************/
static axis2_char_t* AXIS2_CALL 
sandesha2_seq_fault_get_namespace_value (sandesha2_iom_rm_element_t *seq_fault,
						const axutil_env_t *env);
    
static void* AXIS2_CALL 
sandesha2_seq_fault_from_om_node(sandesha2_iom_rm_element_t *seq_fault,
                    	const axutil_env_t *env, axiom_node_t *om_node);
    
static axiom_node_t* AXIS2_CALL 
sandesha2_seq_fault_to_om_node(sandesha2_iom_rm_element_t *seq_fault,
                    	const axutil_env_t *env, void *om_node);
                    	
static axis2_bool_t AXIS2_CALL 
sandesha2_seq_fault_is_namespace_supported(
                        sandesha2_iom_rm_element_t *seq_fault,
                    	const axutil_env_t *env, axis2_char_t *namespace);
                    	
static axis2_status_t AXIS2_CALL 
sandesha2_seq_fault_free (sandesha2_iom_rm_element_t *seq_fault, 
						const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_seq_fault_t* AXIS2_CALL
sandesha2_seq_fault_create(const axutil_env_t *env,  axis2_char_t *ns_val)
{
    sandesha2_seq_fault_impl_t *seq_fault_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    
    if(AXIS2_FALSE == sandesha2_seq_fault_is_namespace_supported(
                        (sandesha2_iom_rm_element_t*)seq_fault_impl, env, 
                        ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
                            AXIS2_FAILURE);
        return NULL;
    }    
    seq_fault_impl =  (sandesha2_seq_fault_impl_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_seq_fault_impl_t));
	
    if(NULL == seq_fault_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    seq_fault_impl->ns_val = NULL;
    seq_fault_impl->fault_code = NULL;
    seq_fault_impl->seq_fault.element.ops = NULL;
    
    seq_fault_impl->seq_fault.element.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_element_ops_t));
    if(NULL == seq_fault_impl->seq_fault.element.ops)
	{
		sandesha2_seq_fault_free((sandesha2_iom_rm_element_t*)
                         seq_fault_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    seq_fault_impl->ns_val = (axis2_char_t *)axutil_strdup(env, ns_val);
    
    seq_fault_impl->seq_fault.element.ops->get_namespace_value = 
                        sandesha2_seq_fault_get_namespace_value;
    seq_fault_impl->seq_fault.element.ops->from_om_node = 
    					sandesha2_seq_fault_from_om_node;
    seq_fault_impl->seq_fault.element.ops->to_om_node = 
    					sandesha2_seq_fault_to_om_node;
    seq_fault_impl->seq_fault.element.ops->is_namespace_supported = 
    					sandesha2_seq_fault_is_namespace_supported;
    seq_fault_impl->seq_fault.element.ops->free = sandesha2_seq_fault_free;
                        
	return &(seq_fault_impl->seq_fault);
}


static axis2_status_t AXIS2_CALL 
sandesha2_seq_fault_free (sandesha2_iom_rm_element_t *seq_fault, 
						const axutil_env_t *env)
{
    sandesha2_seq_fault_impl_t *seq_fault_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    seq_fault_impl = SANDESHA2_INTF_TO_IMPL(seq_fault);
    
    if(seq_fault_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, seq_fault_impl->ns_val);
        seq_fault_impl->ns_val = NULL;
    }
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(seq_fault));
	return AXIS2_SUCCESS;
}

static axis2_char_t* AXIS2_CALL 
sandesha2_seq_fault_get_namespace_value (sandesha2_iom_rm_element_t *seq_fault,
						const axutil_env_t *env)
{
	sandesha2_seq_fault_impl_t *seq_fault_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_fault_impl = SANDESHA2_INTF_TO_IMPL(seq_fault);
	return seq_fault_impl->ns_val;
}


static void* AXIS2_CALL 
sandesha2_seq_fault_from_om_node(sandesha2_iom_rm_element_t *seq_fault,
                    	const axutil_env_t *env, axiom_node_t *om_node)
{
	sandesha2_seq_fault_impl_t *seq_fault_impl = NULL;
    axiom_element_t *om_element = NULL;
    axiom_element_t *sf_part = NULL;
    axiom_element_t *fc_part = NULL;
    axiom_node_t *sf_node = NULL;
    axiom_node_t *fc_node = NULL;
    axutil_qname_t *sf_qname = NULL;
    axutil_qname_t *fc_qname = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    seq_fault_impl = SANDESHA2_INTF_TO_IMPL(seq_fault);
    om_element = axiom_node_get_data_element(om_node, env);
    if(NULL == om_element)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    sf_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_SEQ_FAULT,
                        seq_fault_impl->ns_val, NULL);
    if(NULL == sf_qname)
    {
        return NULL;
    }
    sf_part = axiom_element_get_first_child_with_qname(om_element, env,
                        sf_qname, om_node, &sf_node);
    if(NULL == sf_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL; 
    }
    fc_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_FAULT_CODE,
                        seq_fault_impl->ns_val, NULL);
    if(NULL == fc_qname)
    {
        return NULL;
    }
    fc_part = axiom_element_get_first_child_with_qname(om_element, env,
                        sf_qname, sf_node, &fc_node);
    if(NULL != fc_part)
    {
        seq_fault_impl->fault_code = sandesha2_fault_code_create(env, 
                        seq_fault_impl->ns_val);
        if(NULL == seq_fault_impl->fault_code)
        {
            return NULL;
        }
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)seq_fault_impl->fault_code, env, 
                        sf_node);
    }    
    return seq_fault;    
}


static axiom_node_t* AXIS2_CALL 
sandesha2_seq_fault_to_om_node(sandesha2_iom_rm_element_t *seq_fault,
                    	const axutil_env_t *env, void *om_node)
{
	sandesha2_seq_fault_impl_t *seq_fault_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_element_t *sf_element = NULL;
    axiom_node_t *sf_node = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    seq_fault_impl = SANDESHA2_INTF_TO_IMPL(seq_fault);
    rm_ns = axiom_namespace_create(env, seq_fault_impl->ns_val,
                        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(NULL == rm_ns)
    {
        return NULL;
    }
    sf_element = axiom_element_create(env, NULL, 
                        SANDESHA2_WSRM_COMMON_SEQ_FAULT, rm_ns, &sf_node);
    if(NULL == sf_element)
    {
        return NULL;
    }
    if(NULL != seq_fault_impl->fault_code)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)seq_fault_impl->fault_code, env, 
                        sf_node);
    }
    axiom_node_add_child((axiom_node_t*)om_node, env, sf_node);
    return (axiom_node_t*)om_node;
}

static axis2_bool_t AXIS2_CALL 
sandesha2_seq_fault_is_namespace_supported(
                        sandesha2_iom_rm_element_t *seq_fault,
                    	const axutil_env_t *env, axis2_char_t *namespace)
{
	sandesha2_seq_fault_impl_t *seq_fault_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    seq_fault_impl = SANDESHA2_INTF_TO_IMPL(seq_fault);
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

sandesha2_fault_code_t * AXIS2_CALL
sandesha2_seq_fault_get_fault_code(sandesha2_seq_fault_t *seq_fault,
                    	const axutil_env_t *env)
{
	sandesha2_seq_fault_impl_t *seq_fault_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	seq_fault_impl = SANDESHA2_INTF_TO_IMPL(seq_fault);
	
	return seq_fault_impl->fault_code;
}                    	


axis2_status_t AXIS2_CALL                 
sandesha2_seq_fault_set_fault_code(sandesha2_seq_fault_t *seq_fault,
                    	const axutil_env_t *env, 
                        sandesha2_fault_code_t *fault_code)
{
	sandesha2_seq_fault_impl_t *seq_fault_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	seq_fault_impl = SANDESHA2_INTF_TO_IMPL(seq_fault);
	seq_fault_impl->fault_code = fault_code;
	return AXIS2_SUCCESS;
}
