/*
* Licensed to the Apache Software Foundation (ASF) under one or more
* contributor license agreements.  See the NOTICE file distributed with
* this work for additional information regarding copyright ownership.
* The ASF licenses this file to You under the Apache License, Version 2.0
* (the "License"); you may not use this file except in compliance with
* the License.  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef AXIOM_ATTRIBUTE_H
#define AXIOM_ATTRIBUTE_H

/**
* @file axiom_attribute.h
* @brief om attribute struct represents an xml attribute
*/
#include <axutil_env.h>
#include <axutil_qname.h>
#include <axiom_namespace.h>
#include <axiom_output.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axiom_attribute attribute
     * @ingroup axiom_om
     * @{
     */


    typedef struct axiom_attribute axiom_attribute_t;

    /**
      * creates an om_attribute struct 
      * @param env Environment. MUST NOT be NULL
      * @param localname localname of the attribute, should not be a null value.
      * @param value normalized attribute value. cannot be NULL
      * @param ns namespace, if any, of the attribute. Optional, can be NULL
      * @return a pointer to newly created attribute struct, returns NULL on error with 
      *           error code set in environment's error. 
      */
    AXIS2_EXTERN axiom_attribute_t * AXIS2_CALL
    axiom_attribute_create(const axutil_env_t *env,
            const axis2_char_t *localname,
            const axis2_char_t *value,
            axiom_namespace_t *ns);
    /**
     * Free om attribute passed as void pointer. This will be
     * cast into appropriate type and then pass the cast object
     * into the om_attribute structure's free method
     */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_attribute_free_void_arg(
        void *om_attribute,
        const axutil_env_t *env);

    /**
      * Free an axiom_attribute struct
      * @param  om_attribute pointer to attribute struct to be freed
      * @param  env Environment. MUST NOT be NULL
      * @return satus of the op. AXIS2_SUCCESS on success 
      *         else AXIS2_FAILURE
      */

    AXIS2_EXTERN void AXIS2_CALL
    axiom_attribute_free(struct axiom_attribute *om_attribute,
            const axutil_env_t *env);

    /**
      * Creates and returns a qname struct for this attribute
      * @param om_attribute pointer to attribute struct 
      *        for which the qname is to be returned
      * @param env Environment. MUST NOT be NULL
      * @return returns qname for given attribute.NULL on error 
      */

    AXIS2_EXTERN axutil_qname_t * AXIS2_CALL
    axiom_attribute_get_qname(struct axiom_attribute *om_attribute,
            const axutil_env_t *env);

    /**
      * Serialize op
      * @param om_attribute pointer to attribute struct to be serialized
      * @param env Environment. MUST NOT be NULL,
      * @param om_output AXIOM output handler to be used in serializing
      * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE.
      */

    AXIS2_EXTERN int AXIS2_CALL
    axiom_attribute_serialize(struct axiom_attribute *om_attribute,
            const axutil_env_t *env,
            axiom_output_t *om_output);

    /**  returns the localname of this attribute
     *@param om_attribute pointer to attribute struct 
     *@param env environment. MUST NOT not be NULL.
     *@return localname returns NULL on error.
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axiom_attribute_get_localname(struct axiom_attribute *om_attribute,
            const axutil_env_t *env);
    /**
     * returns value of this attribute 
     *@param om_attribute pointer to om_attribute struct 
     *@param env environment N not be null
     *@return value , null on error
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axiom_attribute_get_value(struct axiom_attribute *om_attribute,
            const axutil_env_t *env);
    /**
     * returns namespace of this attribute 
     *@param om_attribute
     *@param env environment MUST NOT be NULL
     *@return a pointer to om_namespace struct , returns NULL on error.
     */
    AXIS2_EXTERN axiom_namespace_t* AXIS2_CALL
    axiom_attribute_get_namespace(struct axiom_attribute *om_attribute,
            const axutil_env_t *env);

    /** sets the localname of the attribute
     *@param om_attribute pointer to om attribute struct. 
     *@param env environment, MUST NOT be null.
     *@param localname localname that should be set for this attribute 
     *@return status code AXIS2_SUCCESS on success and AXIS2_FAILURE on error.
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_attribute_set_localname(struct axiom_attribute *om_attribute,
            const axutil_env_t *env,
            const axis2_char_t *localname);

    /** set the attribute value
     *@param om_attribute a pointer to om_attribute struct.
     *@param env environment, MUST NOT be NULL.
     *@param value value that should be set for this attribute 
     *@return status code, AXIS2_SUCCESS on success and AXIS2_FAILURE on error.
     */

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_attribute_set_value(struct axiom_attribute *om_attribute,
            const axutil_env_t *env,
            const axis2_char_t *value);

    /** set namespace of the attribute
     *@param om_attribute a pointer to om_attribute struct  
     *@param env environment, MUST NOT be NULL.
     *@param om_namespace a pointer to om_namespace struct that should be set 
     *                    for this attribute 
     *@return status code, AXIS2_SUCCESS on success and AXIS2_FAILURE on error.
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_attribute_set_namespace(struct axiom_attribute *om_attribute,
            const axutil_env_t *env,
            axiom_namespace_t *om_namespace);

    /**
     * clones an om attribute
     * @param om_attibute 
     * @param env environment
     * @returns pointer to cloned om attribute struct on success
     * NULL otherwise
     */
    AXIS2_EXTERN struct axiom_attribute* AXIS2_CALL
                axiom_attribute_clone(struct axiom_attribute *om_attribute,
                        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_attribute_increment_ref(struct axiom_attribute *om_attribute,
            const axutil_env_t *env);

    AXIS2_EXTERN axiom_attribute_t* AXIS2_CALL
    axiom_attribute_create_str(const axutil_env_t *env,
        axutil_string_t * localname,
        axutil_string_t * value,
        axiom_namespace_t * ns);

    AXIS2_EXTERN axutil_string_t* AXIS2_CALL
    axiom_attribute_get_localname_str(axiom_attribute_t *attribute,
        const axutil_env_t *env);

    AXIS2_EXTERN axutil_string_t* AXIS2_CALL
    axiom_attribute_get_value_str(axiom_attribute_t *attribute,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_attribute_set_localname_str(axiom_attribute_t *attribute,
        const axutil_env_t *env,
        axutil_string_t *localname);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_attribute_set_value_str(axiom_attribute_t *attribute,
        const axutil_env_t *env,
        axutil_string_t *value);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif  /* AXIOM_ATTRIBUTE_H */
