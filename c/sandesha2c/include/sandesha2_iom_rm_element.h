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
 
#ifndef SANDESHA2_IOM_RM_ELEMENT_H
#define SANDESHA2_IOM_RM_ELEMENT_H

/**
  * @file sandesha2_iom_rm_element.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axiom_soap_envelope.h>
#include <axiom_element.h>
#include <sandesha2_error.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup sandesha2_wsrm
 * @{
 */
 
 typedef struct sandesha2_iom_rm_element_ops sandesha2_iom_rm_element_ops_t;
 typedef struct sandesha2_iom_rm_element sandesha2_iom_rm_element_t;
 /**
 * @brief IOM RM Element ops struct
 * Encapsulator struct for ops of sandesha2_iom_rm_element
 */
AXIS2_DECLARE_DATA struct sandesha2_iom_rm_element_ops
{	
    axis2_status_t (AXIS2_CALL *free)
        (sandesha2_iom_rm_element_t *element,
        const axutil_env_t *env);

    axis2_char_t* (AXIS2_CALL *get_namespace_value) 
        (sandesha2_iom_rm_element_t *element,
        const axutil_env_t *env);

    void* (AXIS2_CALL *from_om_node) 
        (sandesha2_iom_rm_element_t *element,
        const axutil_env_t *env, axiom_node_t *om_node);

    axiom_node_t* (AXIS2_CALL *to_om_node) 
        (sandesha2_iom_rm_element_t *element,
        const axutil_env_t *env, 
        void *om_node);

	axis2_bool_t (AXIS2_CALL *is_namespace_supported) 
        (sandesha2_iom_rm_element_t *element,
        const axutil_env_t *env, axis2_char_t *ns);
};

/**
 * @brief sandesha2_iom_rm_element
 *    sandesha2_iom_rm_element
 */
AXIS2_DECLARE_DATA struct sandesha2_iom_rm_element
{
    sandesha2_iom_rm_element_ops_t *ops;
};

axis2_status_t AXIS2_CALL
sandesha2_iom_rm_element_free(
    sandesha2_iom_rm_element_t *element,
    const axutil_env_t *env);
    
axis2_char_t* AXIS2_CALL
sandesha2_iom_rm_element_get_namespace_value( 
    sandesha2_iom_rm_element_t *element,
    const axutil_env_t *env);

void* AXIS2_CALL
sandesha2_iom_rm_element_from_om_node(
    sandesha2_iom_rm_element_t *element,
    const axutil_env_t *env, 
    axiom_node_t *om_node);

axiom_node_t * AXIS2_CALL
sandesha2_iom_rm_element_to_om_node(
    sandesha2_iom_rm_element_t *element,
    const axutil_env_t *env, 
    void *om_node);

axis2_bool_t AXIS2_CALL
sandesha2_iom_rm_element_is_namespace_supported( 
    sandesha2_iom_rm_element_t *element,
    const axutil_env_t *env, 
    axis2_char_t *ns);

 /** @} */
#ifdef __cplusplus
}
#endif

#endif /*SANDESHA2_IOM_RM_ELEMENT_H*/
