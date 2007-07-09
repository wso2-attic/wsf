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

#ifndef SAVAN_MSG_RECV_H
#define SAVAN_MSG_RECV_H

/** @defgroup savan_msg_recv savan in-out message receiver
 * @ingroup savan_msg_recv
 * @{
 */

/**
 * @file savan_msg_recv.h
 * @brief Savan In Out Message Receiver interface
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_qname.h>
#include <axis2_msg_recv.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Creates savan in out message receiver struct
     * @return pointer to newly created savan in out message receiver
     */
    AXIS2_EXTERN axis2_msg_recv_t *AXIS2_CALL
    savan_msg_recv_create(
        const axutil_env_t *env);

/** @} */

#ifdef __cplusplus
}
#endif

#endif  /* SAVAN_MSG_RECV_H */
