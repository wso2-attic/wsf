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
 
#include <sandesha2_close_seq.h>
#include <sandesha2_constants.h>
#include <sandesha2_utils.h>
#include <axiom_soap_body.h>
/** 
 * @brief CloseSeq struct impl
 *	Sandesha2 IOM CloseSeq
 */
typedef struct sandesha2_close_seq_impl sandesha2_close_seq_impl_t;  
  
struct sandesha2_close_seq_impl
{
	sandesha2_close_seq_t close_seq;
	sandesha2_identifier_t *identifier;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(close_seq) \
						((sandesha2_close_seq_impl_t *)(close_seq))

/***************************** Function headers *******************************/
axis2_char_t* AXIS2_CALL 
sandesha2_close_seq_get_namespace_value (sandesha2_iom_rm_element_t *close_seq,
						const axutil_env_t *env);
    
void* AXIS2_CALL 
sandesha2_close_seq_from_om_node(sandesha2_iom_rm_element_t *close_seq,
                    	const axutil_env_t *env, axiom_node_t *om_node);
    
axiom_node_t* AXIS2_CALL 
sandesha2_close_seq_to_om_node(sandesha2_iom_rm_element_t *close_seq,
                    	const axutil_env_t *env, void *om_node);
                    	
axis2_bool_t AXIS2_CALL 
sandesha2_close_seq_is_namespace_supported(
                        sandesha2_iom_rm_element_t *close_seq,
                    	const axutil_env_t *env, axis2_char_t *namespace);
                    	
axis2_status_t AXIS2_CALL
sandesha2_close_seq_to_soap_env(sandesha2_iom_rm_part_t *close_seq,
                    	const axutil_env_t *env, axiom_soap_envelope_t *envelope);
                    	                    	
axis2_status_t AXIS2_CALL 
sandesha2_close_seq_free (sandesha2_iom_rm_element_t *close_seq, 
						const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_close_seq_t* AXIS2_CALL
sandesha2_close_seq_create(const axutil_env_t *env,  axis2_char_t *ns_val)
{
    sandesha2_close_seq_impl_t *close_seq_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    
    if(AXIS2_FALSE == sandesha2_close_seq_is_namespace_supported(
                        (sandesha2_iom_rm_element_t*)close_seq_impl, env, 
                        ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
                            AXIS2_FAILURE);
        return NULL;
    }    
    close_seq_impl =  (sandesha2_close_seq_impl_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_close_seq_impl_t));
	
    if(!close_seq_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    close_seq_impl->ns_val = NULL;
    close_seq_impl->identifier = NULL;
    close_seq_impl->close_seq.part.ops = NULL;
    close_seq_impl->close_seq.part.element.ops = NULL;
    
    close_seq_impl->close_seq.part.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_part_ops_t));
    if(!close_seq_impl->close_seq.part.ops)
	{
		sandesha2_close_seq_free((sandesha2_iom_rm_element_t*)
                         close_seq_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}    
    close_seq_impl->close_seq.part.element.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_element_ops_t));
    if(!close_seq_impl->close_seq.part.element.ops)
	{
		sandesha2_close_seq_free((sandesha2_iom_rm_element_t*)
                         close_seq_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    close_seq_impl->ns_val = (axis2_char_t *)axutil_strdup(env, ns_val);
    
    close_seq_impl->close_seq.part.element.ops->get_namespace_value = 
                        sandesha2_close_seq_get_namespace_value;
    close_seq_impl->close_seq.part.element.ops->from_om_node = 
    					sandesha2_close_seq_from_om_node;
    close_seq_impl->close_seq.part.element.ops->to_om_node = 
    					sandesha2_close_seq_to_om_node;
    close_seq_impl->close_seq.part.element.ops->is_namespace_supported = 
    					sandesha2_close_seq_is_namespace_supported;
    close_seq_impl->close_seq.part.ops->to_soap_env = 
                        sandesha2_close_seq_to_soap_env;
    close_seq_impl->close_seq.part.element.ops->free = sandesha2_close_seq_free;
                        
	return &(close_seq_impl->close_seq);
}


axis2_status_t AXIS2_CALL 
sandesha2_close_seq_free (
    sandesha2_iom_rm_element_t *close_seq, 
    const axutil_env_t *env)
{
    sandesha2_close_seq_impl_t *close_seq_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    close_seq_impl = SANDESHA2_INTF_TO_IMPL(close_seq);
    
    if(close_seq_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, close_seq_impl->ns_val);
        close_seq_impl->ns_val = NULL;
    }
    close_seq_impl->identifier = NULL;
    if(close_seq->ops)
    {
        AXIS2_FREE(env->allocator, close_seq->ops);
        close_seq->ops = NULL;
    }
    if(close_seq_impl->close_seq.part.ops)
    {
        AXIS2_FREE(env->allocator, close_seq_impl->close_seq.part.ops);
        close_seq_impl->close_seq.part.ops = NULL;
    }
    if(close_seq_impl->close_seq.part.element.ops)
    {
        AXIS2_FREE(env->allocator, close_seq_impl->close_seq.part.element.ops);
        close_seq_impl->close_seq.part.element.ops = NULL;
    }
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(close_seq));
	return AXIS2_SUCCESS;
}

axis2_char_t* AXIS2_CALL 
sandesha2_close_seq_get_namespace_value (
    sandesha2_iom_rm_element_t *close_seq,
	const axutil_env_t *env)
{
	sandesha2_close_seq_impl_t *close_seq_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	close_seq_impl = SANDESHA2_INTF_TO_IMPL(close_seq);
	return close_seq_impl->ns_val;
}

void* AXIS2_CALL 
sandesha2_close_seq_from_om_node(
    sandesha2_iom_rm_element_t *close_seq,
    const axutil_env_t *env, 
    axiom_node_t *close_seq_node)
{
	sandesha2_close_seq_impl_t *close_seq_impl = NULL;
    axiom_element_t *close_seq_part = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, close_seq_node, NULL);
    
    close_seq_impl = SANDESHA2_INTF_TO_IMPL(close_seq);
    close_seq_part = axiom_node_get_data_element(close_seq_node, env);
    if(!close_seq_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
            AXIS2_FAILURE);
        return NULL;
    }
   close_seq_impl->identifier = sandesha2_identifier_create(env, 
        close_seq_impl->ns_val); 
    if(!close_seq_impl->identifier)
    {
        return NULL;
    }
    if(!sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
        close_seq_impl->identifier, env, close_seq_node))
    {
        return NULL;   
    }
    return close_seq;
}


axiom_node_t* AXIS2_CALL 
sandesha2_close_seq_to_om_node(
    sandesha2_iom_rm_element_t *close_seq,
    const axutil_env_t *env, void *om_node)
{
	sandesha2_close_seq_impl_t *close_seq_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_element_t *cs_element = NULL;
    axiom_node_t *cs_node = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    close_seq_impl = SANDESHA2_INTF_TO_IMPL(close_seq);
    if(!close_seq_impl->identifier)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_OM_NULL_ELEMENT, 
                        AXIS2_FAILURE);
        return NULL;
    }
    rm_ns = axiom_namespace_create(env, close_seq_impl->ns_val,
                        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(!rm_ns)
    {
        return NULL;
    }
    cs_element = axiom_element_create(env, NULL, 
                        SANDESHA2_WSRM_COMMON_CLOSE_SEQ, rm_ns, 
                        &cs_node);
    if(!cs_element)
    {
        return NULL;
    }
    sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            close_seq_impl->identifier, env, cs_node);
    axiom_node_add_child((axiom_node_t*)om_node, env, cs_node);
    return (axiom_node_t*)om_node;
}

axis2_bool_t AXIS2_CALL 
sandesha2_close_seq_is_namespace_supported(
    sandesha2_iom_rm_element_t *close_seq,
    const axutil_env_t *env, 
    axis2_char_t *namespace)
{
	sandesha2_close_seq_impl_t *close_seq_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    close_seq_impl = SANDESHA2_INTF_TO_IMPL(close_seq);
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
sandesha2_close_seq_get_identifier(
    sandesha2_close_seq_t *element,
    const axutil_env_t *env)
{
	sandesha2_close_seq_impl_t *close_seq_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	close_seq_impl = SANDESHA2_INTF_TO_IMPL(element);
	
	return close_seq_impl->identifier;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_close_seq_set_identifier(
    sandesha2_close_seq_t *close_seq,
    const axutil_env_t *env, 
    sandesha2_identifier_t *identifier)
{
	sandesha2_close_seq_impl_t *close_seq_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	
	close_seq_impl = SANDESHA2_INTF_TO_IMPL(close_seq);
 	if(close_seq_impl->identifier)
	{
	    /*
		SANDESHA2_IDENTIFIER_FREE(close_seq_impl->identifier, env);
		close_seq_impl->identifier = NULL;
		*/
	}
	close_seq_impl->identifier = identifier;
 	return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
sandesha2_close_seq_to_soap_env(
    sandesha2_iom_rm_part_t *close_seq,
    const axutil_env_t *env, 
    axiom_soap_envelope_t *envelope)
{
	sandesha2_close_seq_impl_t *close_seq_impl = NULL;
    axiom_node_t *body_node = NULL;
    axutil_qname_t *close_seq_qname = NULL;
    
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, envelope, AXIS2_FAILURE);
	
	close_seq_impl = SANDESHA2_INTF_TO_IMPL(close_seq);

    /**
     * Remove if old exists
     */
    close_seq_qname = axutil_qname_create(env, 
                        SANDESHA2_WSRM_COMMON_CLOSE_SEQ, 
                        close_seq_impl->ns_val, NULL);
    if(!close_seq_qname)
    {
        return AXIS2_FAILURE;
    }
    sandesha2_utils_remove_soap_body_part(env, envelope, close_seq_qname);
    body_node = axiom_soap_body_get_base_node(axiom_soap_envelope_get_body(
                        envelope, env), env);  
    sandesha2_close_seq_to_om_node(((sandesha2_iom_rm_element_t*)close_seq), env,
                        body_node);
	return AXIS2_SUCCESS;
}

