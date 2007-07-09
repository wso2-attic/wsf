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

#ifndef RAMPART_ENGINE_H
#define RAMPART_ENGINE_H

/** @defgroup rampart_engine
 * @ingroup rampart_engine
 * @{
 */

#include <rp_includes.h>
#include <rampart_context.h>
#include <rampart_constants.h>
#include <axis2_msg_ctx.h>


#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN rampart_context_t *AXIS2_CALL
    rampart_engine_build_configuration(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx,
        axis2_bool_t is_inflow);

#ifdef __cplusplus
}
#endif
#endif
