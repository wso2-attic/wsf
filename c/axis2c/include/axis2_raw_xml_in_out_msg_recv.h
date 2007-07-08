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

#ifndef AXIS2_RAW_XML_IN_OUT_MSG_RECV_H
#define AXIS2_RAW_XML_IN_OUT_MSG_RECV_H

/** @defgroup axis2_raw_xml_in_out_msg_recv raw XML in-out message receiver
 * @ingroup axis2_receivers
 * @{
 */

/**
 * @file axis2_ws_info.h
 * @brief Axis2 Raw Xml In Out Message Receiver interface
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
     * Creates raw xml in out message receiver struct
     * @return pointer to newly created raw xml in out message receiver
     */
    AXIS2_EXTERN axis2_msg_recv_t *AXIS2_CALL
    axis2_raw_xml_in_out_msg_recv_create(
        const axutil_env_t *env);

/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_RAW_XML_IN_OUT_MSG_RECV_H */
