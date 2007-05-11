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

#ifndef RAMPART_RD_RECORD_H
#define RAMPART_RD_RECORD_H

/** @defgroup rampart_context
 * @ingroup rampart_context
 * @{
 */

#include <rampart_util.h>

#ifdef __cplusplus
extern "C"
{
#endif

 typedef struct rampart_rd_record_t rampart_rd_record_t;
/*Create function*/
AXIS2_EXTERN rampart_rd_record_t *AXIS2_CALL
rampart_rd_record_create(const axutil_env_t *env);

/*Free*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_rd_record_free(rampart_rd_record_t *rd_record,
                  const axutil_env_t *env);


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
rampart_rd_record_get_id(
    const rampart_rd_record_t *rd_record,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
rampart_rd_record_get_timestamp(
    const rampart_rd_record_t *rd_record,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_rd_record_set_id(
    rampart_rd_record_t *rd_record,
    const axutil_env_t *env,
    axis2_char_t *id);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_rd_record_set_timestamp(
    rampart_rd_record_t *rd_record,
    const axutil_env_t *env,
    axis2_char_t *timestamp);

AXIS2_EXTERN rampart_rd_record_t *AXIS2_CALL
rampart_rd_record_create(const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_rd_record_free(rampart_rd_record_t *rd_record,
                  const axutil_env_t *env);



#ifdef __cplusplus
}
#endif
#endif
