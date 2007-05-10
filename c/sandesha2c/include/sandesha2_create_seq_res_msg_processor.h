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
 
#ifndef SANDESHA2_CREATE_SEQ_RES_MSG_PROCESSOR_H
#define SANDESHA2_CREATE_SEQ_RES_MSG_PROCESSOR_H

/**
  * @file sandesha2_ack_msg_processor.h
  * @brief 
  */

#include <sandesha2_msg_processor.h>
#include <axutil_utils_defines.h>
#include <axutil_env.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_create_seq_res_msg_processor
 * @ingroup sandesha2_msgprocessors
 * @{
 */
    
AXIS2_EXTERN sandesha2_msg_processor_t* AXIS2_CALL
sandesha2_create_seq_res_msg_processor_create(
    const axutil_env_t *env);
/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_CREATE_SEQ_RES_MSG_PROCESSOR_H */

