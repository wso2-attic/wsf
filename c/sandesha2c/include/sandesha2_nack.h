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
 
#ifndef SANDESHA2_NACK_H
#define SANDESHA2_NACK_H

/**
  * @file sandesha2_nack.h
  * @brief 
  */
#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <sandesha2_iom_rm_element.h>
#include <sandesha2_error.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_nack
 * @ingroup sandesha2_wsrm
 * @{
 */
typedef struct sandesha2_nack_ops sandesha2_nack_ops_t;
typedef struct sandesha2_nack sandesha2_nack_t;
 
/**
 * @brief Nack ops struct
 * Encapsulator struct for ops of sandesha2_nack
 */
AXIS2_DECLARE_DATA struct sandesha2_nack_ops
{
    long (AXIS2_CALL *
        get_nack_num)
            (sandesha2_nack_t *element,
            const axutil_env_t *env);

    axis2_status_t (AXIS2_CALL *
        set_nack_num)
            (sandesha2_nack_t *element,
            const axutil_env_t *env,
            long value);
};

/**
 * @brief sandesha2_nack
 *    sandesha2_nack
 */
AXIS2_DECLARE_DATA struct sandesha2_nack
{
    sandesha2_iom_rm_element_t element;
    sandesha2_nack_ops_t *ops;
};

AXIS2_EXTERN sandesha2_nack_t* AXIS2_CALL
sandesha2_nack_create(
						const axutil_env_t *env,
					    axis2_char_t *ns_value);

/************************** Start of function macros **************************/
#define SANDESHA2_NACK_SET_NACK_NUM(nack, env, value) \
    ((nack)->ops->set_nack_num (nack, env, acks_to))
#define SANDESHA2_NACK_GET_NACK_NUM(nack, env) \
    ((nack)->ops->get_nack_num (nack, env))
/************************** End of function macros ****************************/
/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_NACK_H */

