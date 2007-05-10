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
 
#include <sandesha2_address.h>
#include <sandesha2_constants.h>
#include <axis2_addr.h>
/** 
 * @brief Address struct impl
 *	Sandesha2 IOM Address
 */
typedef struct sandesha2_address_impl sandesha2_address_impl_t;  
  
struct sandesha2_address_impl
{
	sandesha2_address_t address;
	axis2_endpoint_ref_t *epr;
	axis2_char_t *ns_val;
};

#define SANDESHA2_INTF_TO_IMPL(address) \
						((sandesha2_address_impl_t *)(address))

/***************************** Function headers *******************************/
axis2_char_t* AXIS2_CALL 
sandesha2_address_get_namespace_value (
    sandesha2_iom_rm_element_t *address,
    const axutil_env_t *env);
    
void* AXIS2_CALL 
sandesha2_address_from_om_node(
    sandesha2_iom_rm_element_t *address,
    const axutil_env_t *env, 
    axiom_node_t *om_node);
    
axiom_node_t* AXIS2_CALL 
sandesha2_address_to_om_node(
    sandesha2_iom_rm_element_t *address,
    const axutil_env_t *env, 
    void *om_node);
                    	
axis2_bool_t AXIS2_CALL 
sandesha2_address_is_namespace_supported(
    sandesha2_iom_rm_element_t *address,
   	const axutil_env_t *env, 
    axis2_char_t *namespace);
                    	
/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_address_t* AXIS2_CALL
sandesha2_address_create(
    const axutil_env_t *env, 
    axis2_char_t *ns_val, 
	axis2_endpoint_ref_t *epr)
{
    sandesha2_address_impl_t *address_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    
    address_impl =  (sandesha2_address_impl_t *)AXIS2_MALLOC 
        (env->allocator, sizeof(sandesha2_address_impl_t));
	
    if(!address_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    address_impl->ns_val = axutil_strdup(env, ns_val);
    address_impl->epr = epr;
    address_impl->address.element.ops = NULL;
    
    address_impl->address.element.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_iom_rm_element_ops_t));
    if(!address_impl->address.element.ops)
	{
		sandesha2_address_free((sandesha2_iom_rm_element_t*)
            address_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    address_impl->address.element.ops->get_namespace_value = 
                        sandesha2_address_get_namespace_value;
    address_impl->address.element.ops->from_om_node = 
    					sandesha2_address_from_om_node;
    address_impl->address.element.ops->to_om_node = 
    					sandesha2_address_to_om_node;
    address_impl->address.element.ops->is_namespace_supported = 
    					sandesha2_address_is_namespace_supported;
    address_impl->address.element.ops->free = sandesha2_address_free;
	return &(address_impl->address);
}


axis2_status_t AXIS2_CALL 
sandesha2_address_free (
    sandesha2_iom_rm_element_t *address, 
    const axutil_env_t *env)
{
    sandesha2_address_impl_t *address_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    address_impl = SANDESHA2_INTF_TO_IMPL(address);
    
    if(address_impl->ns_val)
    {
        AXIS2_FREE(env->allocator, address_impl->ns_val);
        address_impl->ns_val = NULL;
    }
    address_impl->epr = NULL;
    if(address_impl->address.element.ops)
    {
        AXIS2_FREE(env->allocator, address_impl->address.element.ops);
        address_impl->address.element.ops = NULL;
    }
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(address));
	return AXIS2_SUCCESS;
}

axis2_char_t* AXIS2_CALL 
sandesha2_address_get_namespace_value (
    sandesha2_iom_rm_element_t *element,
	const axutil_env_t *env)
{
	sandesha2_address_impl_t *address_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	address_impl = SANDESHA2_INTF_TO_IMPL(element);
	return address_impl->ns_val;
}


void* AXIS2_CALL 
sandesha2_address_from_om_node(
    sandesha2_iom_rm_element_t *address,
   	const axutil_env_t *env, axiom_node_t *om_node)
{
	sandesha2_address_impl_t *address_impl = NULL;
    axiom_element_t *om_element = NULL;
    axiom_element_t *addr_part = NULL;
    axiom_node_t *addr_node = NULL;
    axutil_qname_t *addr_qname = NULL;
    axis2_char_t *str_address = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    address_impl = SANDESHA2_INTF_TO_IMPL(address);
    om_element = axiom_node_get_data_element(om_node, env);
    if(!om_element)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
           AXIS2_FAILURE);
        return NULL;
    }
    addr_qname = axutil_qname_create(env, SANDESHA2_WSA_ADDRESS, 
           address_impl->ns_val, NULL);
    if(!addr_qname)
    {
        return NULL;
    } 
    addr_part = axiom_element_get_first_child_with_qname(om_element, env, 
            addr_qname, om_node, &addr_node);
    if(!addr_part)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_OM_ELEMENT,
            AXIS2_FAILURE);
        return NULL;
    }
    str_address = axiom_element_get_text(addr_part, env, addr_node);
    if(!str_address || 0 == axutil_strlen(str_address))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_EMPTY_OM_ELEMENT,
            AXIS2_FAILURE);
        return NULL;
    }
    address_impl->epr = axis2_endpoint_ref_create(env, str_address);
    if(!address_impl->epr)
    {
        return NULL;
    }
    return address;
}


axiom_node_t* AXIS2_CALL 
sandesha2_address_to_om_node(
    sandesha2_iom_rm_element_t *address,
   	const axutil_env_t *env, 
    void *om_node)
{
	sandesha2_address_impl_t *address_impl = NULL;
    axiom_namespace_t *rm_ns = NULL;
    axiom_element_t *addr_element = NULL;
    axiom_node_t *addr_node = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);
    address_impl = SANDESHA2_INTF_TO_IMPL(address);
    if(!address_impl->epr || !axis2_endpoint_ref_get_address(
            address_impl->epr, env) || 0 == axutil_strlen(
            axis2_endpoint_ref_get_address(address_impl->epr, env)))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_OM_NULL_ELEMENT, 
            AXIS2_FAILURE);
        return NULL;
    }
    rm_ns = axiom_namespace_create(env, address_impl->ns_val,
        AXIS2_WSA_DEFAULT_PREFIX);
    if(!rm_ns)
    {
        return NULL;
    }
    addr_element = axiom_element_create(env, NULL, 
            SANDESHA2_WSA_ADDRESS, rm_ns, &addr_node);
    if(!addr_element)
    {
        return NULL;
    }
    axiom_element_set_text(addr_element, env, 
            axis2_endpoint_ref_get_address(address_impl->epr, env), 
            addr_node);
    axiom_node_add_child((axiom_node_t*)om_node, env, addr_node);
    return (axiom_node_t*)om_node;
}

axis2_bool_t AXIS2_CALL 
sandesha2_address_is_namespace_supported(
    sandesha2_iom_rm_element_t *address,
   	const axutil_env_t *env, 
    axis2_char_t *namespace)
{
	sandesha2_address_impl_t *address_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    address_impl = SANDESHA2_INTF_TO_IMPL(address);
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

axis2_endpoint_ref_t * AXIS2_CALL                    	
sandesha2_address_get_epr(
    sandesha2_address_t *address,
   	const axutil_env_t *env)
{
	sandesha2_address_impl_t *address_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    address_impl = SANDESHA2_INTF_TO_IMPL(address);
    return address_impl->epr;
}

                  	
axis2_status_t AXIS2_CALL
sandesha2_address_set_epr(
    sandesha2_address_t *address,
   	const axutil_env_t *env, 
    axis2_endpoint_ref_t *epr)
{
	sandesha2_address_impl_t *address_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, epr, AXIS2_FAILURE);
    address_impl = SANDESHA2_INTF_TO_IMPL(address);
	address_impl->epr = epr;
    return AXIS2_SUCCESS;
}

