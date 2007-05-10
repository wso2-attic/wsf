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
 
#ifndef SANDESHA2_MSG_NUMBER_H
#define SANDESHA2_MSG_NUMBER_H

/**
  * @file sandesha2_msg_number.h
  * @brief 
  */

#include <sandesha2_iom_rm_element.h>
#include <sandesha2_error.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_msg_number
 * @ingroup sandesha2_wsrm
 * @{
 */
typedef struct sandesha2_msg_number_ops sandesha2_msg_number_ops_t;
typedef struct sandesha2_msg_number sandesha2_msg_number_t;
 
/**
 * @brief Message Number ops struct
 * Encapsulator struct for ops of sandesha2_msg_number
 */
AXIS2_DECLARE_DATA struct sandesha2_msg_number_ops
{
    long (AXIS2_CALL *
        get_msg_num)
            (sandesha2_msg_number_t *msg_number,
            const axutil_env_t *env);

    axis2_status_t (AXIS2_CALL *
        set_msg_num)
            (sandesha2_msg_number_t *msg_number,
            const axutil_env_t *env, 
            long value);
};

/**
 * @brief sandesha2_msg_number
 *    sandesha2_msg_number
 */
AXIS2_DECLARE_DATA struct sandesha2_msg_number
{
    sandesha2_iom_rm_element_t element;
    sandesha2_msg_number_ops_t *ops;
};

AXIS2_EXTERN sandesha2_msg_number_t* AXIS2_CALL
sandesha2_msg_number_create(
						const axutil_env_t *env,
					    axis2_char_t *ns_value);

/************************** Start of function macros **************************/
#define SANDESHA2_MSG_NUMBER_SET_MSG_NUM(msg_number, env, value) \
    ((msg_number)->ops->set_msg_num (msg_number, env, value))
#define SANDESHA2_MSG_NUMBER_GET_MSG_NUM(msg_number, env) \
    ((msg_number)->ops->get_msg_num (msg_number, env))
/************************** End of function macros ****************************/

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_MSG_NUMBER_H */

