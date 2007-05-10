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
 
#include <sandesha2_make_connection.h>
#include <sandesha2_constants.h>
#include <axiom_soap_header.h>
#include <axiom_soap_body.h>
#include <axiom_soap_header_block.h>
#include <stdio.h>

/** 
 * @brief Make Connection struct impl
 *	Sandesha2 IOM Make Connection
 */
typedef struct sandesha2_make_connection_impl sandesha2_make_connection_impl_t;  
  
struct sandesha2_make_connection_impl
{
	sandesha2_make_connection_t make_conn;
	sandesha2_identifier_t *identifier;
	sandesha2_address_t *address;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(make_conn) \
    ((sandesha2_make_connection_impl_t *)(make_conn))

/***************************** Function headers *******************************/
static axis2_char_t* AXIS2_CALL 
sandesha2_make_connection_get_namespace_value (
    sandesha2_iom_rm_element_t *make_conn,
	const axutil_env_t *env);
    
static void* AXIS2_CALL 
sandesha2_make_connection_from_om_node(
    sandesha2_iom_rm_element_t *make_conn,
    const axutil_env_t *env, 
    axiom_node_t *om_node);
    
static axiom_node_t* AXIS2_CALL 
sandesha2_make_connection_to_om_node(
    sandesha2_iom_rm_element_t *make_conn,
    const axutil_env_t *env, 
    void *om_node);
                    	
static axis2_bool_t AXIS2_CALL 
sandesha2_make_connection_is_namespace_supported(
    sandesha2_iom_rm_element_t *make_conn,
    const axutil_env_t *env, 
    axis2_char_t *namespace);

static axis2_status_t AXIS2_CALL
sandesha2_make_connection_to_soap_envelope(
    sandesha2_iom_rm_part_t *make_conn,
    const axutil_env_t *env, 
    axiom_soap_envelope_t *envelope);
                    	                    	
static axis2_status_t AXIS2_CALL 
sandesha2_make_connection_free (
    sandesha2_iom_rm_element_t *make_conn, 
	const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_make_connection_t* AXIS2_CALL
sandesha2_make_connection_create(
    const axutil_env_t *env,  
    axis2_char_t *ns_val)
{
    sandesha2_make_connection_impl_t *make_conn_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    
    if(!sandesha2_make_connection_is_namespace_supported(
        (sandesha2_iom_rm_element_t*)make_conn_impl, env, 
        ns_val))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNSUPPORTED_NS, 
            AXIS2_FAILURE);
        return NULL;
    }    
    make_conn_impl =  (sandesha2_make_connection_impl_t *)AXIS2_MALLOC 
        (env->allocator, sizeof(sandesha2_make_connection_impl_t));
	
    if(!make_conn_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    make_conn_impl->ns_val = NULL;
    make_conn_impl->identifier = NULL;
    make_conn_impl->address = NULL;
    make_conn_impl->make_conn.part.ops = NULL;
    make_conn_impl->make_conn.part.element.ops = NULL;
    
    make_conn_impl->make_conn.part.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_part_ops_t));
    if(!make_conn_impl->make_conn.part.ops)
	{
		sandesha2_make_connection_free((sandesha2_iom_rm_element_t*)
            make_conn_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    make_conn_impl->make_conn.part.element.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_element_ops_t));
    if(!make_conn_impl->make_conn.part.element.ops)
	{
		sandesha2_make_connection_free((sandesha2_iom_rm_element_t*)
            make_conn_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    make_conn_impl->ns_val = (axis2_char_t *)axutil_strdup(env, ns_val);
    
    make_conn_impl->make_conn.part.element.ops->get_namespace_value = 
                        sandesha2_make_connection_get_namespace_value;
    make_conn_impl->make_conn.part.element.ops->from_om_node = 
    					sandesha2_make_connection_from_om_node;
    make_conn_impl->make_conn.part.element.ops->to_om_node = 
    					sandesha2_make_connection_to_om_node;
    make_conn_impl->make_conn.part.element.ops->is_namespace_supported = 
    					sandesha2_make_connection_is_namespace_supported;
    make_conn_impl->make_conn.part.ops->to_soap_env = 
    					sandesha2_make_connection_to_soap_envelope;
    make_conn_impl->make_conn.part.element.ops->free = 
        sandesha2_make_connection_free;
    
	return &(make_conn_impl->make_conn);
}

axis2_status_t AXIS2_CALL
sandesha2_make_connection_free_void_arg(
    void *make_conn,
    const axutil_env_t *env)
{
    sandesha2_iom_rm_element_t *make_conn_l = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    make_conn_l = (sandesha2_iom_rm_element_t *) make_conn;
    return sandesha2_make_connection_free(make_conn_l, env);
}

static axis2_status_t AXIS2_CALL 
sandesha2_make_connection_free (
    sandesha2_iom_rm_element_t *make_conn, 
	const axutil_env_t *env)
{
    sandesha2_make_connection_impl_t *make_conn_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    make_conn_impl = SANDESHA2_INTF_TO_IMPL(make_conn);
    
    if(make_conn_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, make_conn_impl->ns_val);
        make_conn_impl->ns_val = NULL;
    }
    make_conn_impl->identifier = NULL;
    make_conn_impl->address = NULL;
    if(make_conn->ops)
        AXIS2_FREE(env->allocator, make_conn->ops);
    
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(make_conn));
	return AXIS2_SUCCESS;
}

static axis2_char_t* AXIS2_CALL 
sandesha2_make_connection_get_namespace_value (
    sandesha2_iom_rm_element_t *make_conn,
	const axutil_env_t *env)
{
	sandesha2_make_connection_impl_t *make_conn_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	
	make_conn_impl = SANDESHA2_INTF_TO_IMPL(make_conn);
	return make_conn_impl->ns_val;
}

static void* AXIS2_CALL 
sandesha2_make_connection_from_om_node(
    sandesha2_iom_rm_element_t *make_conn,
    const axutil_env_t *env, 
    axiom_node_t *om_node)
{
	sandesha2_make_connection_impl_t *make_conn_impl = NULL;
    axiom_element_t *om_element = NULL;
    axiom_element_t *identifier_element = NULL;
    axiom_node_t *identifier_node = NULL;
    axiom_element_t *address_element = NULL;
    axiom_node_t *address_node = NULL;
    axutil_qname_t *identifier_qname = NULL; 
    axutil_qname_t *address_qname = NULL; 
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    make_conn_impl = SANDESHA2_INTF_TO_IMPL(make_conn);
    om_element = axiom_node_get_data_element(om_node, env);
    if(!om_element)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
                        AXIS2_FAILURE);
        return NULL;
    }
    identifier_qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_IDENTIFIER,
                        make_conn_impl->ns_val, NULL);
    if(!identifier_qname)
    {
        return NULL;
    }
    address_qname = axutil_qname_create(env, SANDESHA2_WSA_ADDRESS,
                        make_conn_impl->ns_val, NULL);
    if(!address_qname)
    {
        return NULL;
    }
    identifier_element = axiom_element_get_first_child_with_qname(om_element, env,
                        identifier_qname, om_node, &identifier_node);
    address_element = axiom_element_get_first_child_with_qname(om_element, env,
                        address_qname, om_node, &address_node);
    if(!identifier_element && !address_element)
    {
        AXIS2_ERROR_SET(env->error, 
            SANDESHA2_ERROR_MAKE_CONNECTION_ELEMENT_SHOULD_HAVE_AT_LEAST_ADDRESS_OR_IDENTIFIER, 
            AXIS2_FAILURE);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "MakeConnection element " \
            "should have at lease one of Address and Identifier subelements");
        return NULL;
    }
    if(identifier_element)
    {
        make_conn_impl->identifier = sandesha2_identifier_create(env, 
            make_conn_impl->ns_val);
        if(!make_conn_impl->identifier)
        {
            return NULL;
        }
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
                make_conn_impl->identifier, env, om_node);
    }
    if(address_element)
    {
        make_conn_impl->address = sandesha2_address_create(env, 
                        make_conn_impl->ns_val, NULL);
        if(!make_conn_impl->address)
        {
            return NULL;
        }
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
                make_conn_impl->address, env, om_node);
    }
    return make_conn;
}


static axiom_node_t* AXIS2_CALL 
sandesha2_make_connection_to_om_node(
    sandesha2_iom_rm_element_t *make_conn,
    const axutil_env_t *env, 
    void *om_node)
{
	sandesha2_make_connection_impl_t *make_conn_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axiom_node_t *make_conn_node = NULL;
    axiom_element_t *make_conn_element = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    
    make_conn_impl = SANDESHA2_INTF_TO_IMPL(make_conn);
    soap_body = (axiom_soap_body_t*)om_node;
    if(!make_conn_impl->identifier && !make_conn_impl->address)
    {
        AXIS2_ERROR_SET(env->error, 
            SANDESHA2_ERROR_INVALID_MAKE_CONNECTION_BOTH_IDENTIFER_AND_ADDRESS_NULL, 
            AXIS2_FAILURE);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Invalid MakeConnection " \
            "object. Both Identifier and Address are null");
        return NULL;
    }
    rm_ns = axiom_namespace_create(env, make_conn_impl->ns_val,
        SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
    if(!rm_ns)
    {
        return NULL;
    }
    make_conn_element = axiom_element_create(env, NULL, 
        SANDESHA2_WSRM_COMMON_MAKE_CONNECTION, rm_ns, &make_conn_node);
    if(!make_conn_element)
    {
        return NULL;
    }
    if(make_conn_impl->identifier)
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            make_conn_impl->identifier, env, make_conn_node);
    if(make_conn_impl->address)
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            make_conn_impl->address, env, make_conn_node);
    axiom_soap_body_add_child(soap_body, env, make_conn_node);
    return axiom_soap_body_get_base_node(soap_body, env);
}

static axis2_bool_t AXIS2_CALL 
sandesha2_make_connection_is_namespace_supported(
    sandesha2_iom_rm_element_t *make_conn,
    const axutil_env_t *env, 
    axis2_char_t *namespace)
{
	sandesha2_make_connection_impl_t *make_conn_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    make_conn_impl = SANDESHA2_INTF_TO_IMPL(make_conn);
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

sandesha2_identifier_t * AXIS2_CALL
sandesha2_make_connection_get_identifier(
    sandesha2_make_connection_t *element,
    const axutil_env_t *env)
{
	sandesha2_make_connection_impl_t *make_conn_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	make_conn_impl = SANDESHA2_INTF_TO_IMPL(element);
	
	return make_conn_impl->identifier;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_make_connection_set_identifier(
    sandesha2_make_connection_t *make_conn,
    const axutil_env_t *env, 
    sandesha2_identifier_t *identifier)
{
	sandesha2_make_connection_impl_t *make_conn_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	make_conn_impl = SANDESHA2_INTF_TO_IMPL(make_conn);
	make_conn_impl->identifier = identifier;
 	return AXIS2_SUCCESS;
}

sandesha2_address_t * AXIS2_CALL
sandesha2_make_connection_get_address(
    sandesha2_make_connection_t *make_conn,
    const axutil_env_t *env)
{
	sandesha2_make_connection_impl_t *make_conn_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	make_conn_impl = SANDESHA2_INTF_TO_IMPL(make_conn);
	
	return make_conn_impl->address;
}                    	

axis2_status_t AXIS2_CALL                 
sandesha2_make_connection_set_address(
    sandesha2_make_connection_t *make_conn,
    const axutil_env_t *env, 
    sandesha2_address_t *address)
{
	sandesha2_make_connection_impl_t *make_conn_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	make_conn_impl = SANDESHA2_INTF_TO_IMPL(make_conn);
	make_conn_impl->address = address;
 	return AXIS2_SUCCESS;
}

static axis2_status_t AXIS2_CALL
sandesha2_make_connection_to_soap_envelope(
    sandesha2_iom_rm_part_t *make_conn,
    const axutil_env_t *env, 
    axiom_soap_envelope_t *envelope)
{
	sandesha2_make_connection_impl_t *make_conn_impl = NULL;
	axiom_soap_body_t *soap_body = NULL;
    axiom_node_t *body_node = NULL;
    axiom_element_t *body_element = NULL;
    axiom_node_t *node = NULL;
    axiom_element_t *element = NULL;
    axutil_qname_t *make_conn_qname = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, envelope, AXIS2_FAILURE);
	
	make_conn_impl = SANDESHA2_INTF_TO_IMPL(make_conn);
    soap_body = axiom_soap_envelope_get_body(envelope, env);
    if(soap_body)
        body_node = axiom_soap_body_get_base_node(soap_body, env);
    if(body_node)
        body_element = axiom_node_get_data_element(body_node, env);
    make_conn_qname = axutil_qname_create(env, 
        SANDESHA2_WSRM_COMMON_MAKE_CONNECTION, make_conn_impl->ns_val, NULL);
    if(!make_conn_qname)
    {
        return AXIS2_FAILURE;
    }
    if(body_element)
        element = axiom_element_get_first_child_with_qname(body_element, env,
            make_conn_qname, body_node, &node);
    /**
     * Detach if already exists
     */
    if(node)
        axiom_node_detach(node, env);
    sandesha2_make_connection_to_om_node((sandesha2_iom_rm_element_t*)make_conn, 
            env, soap_body);
	return AXIS2_SUCCESS;
}

