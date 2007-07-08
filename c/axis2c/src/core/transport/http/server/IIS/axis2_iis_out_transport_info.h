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

#ifndef AXIS2_IIS_OUT_TRANSPORT_INFO_H
#define AXIS2_IIS_OUT_TRANSPORT_INFO_H

/** 
 * @ingroup axis2_core_transport_http
 * @{
 */

/**
 * @file axis2_iis_out_transport_info.h
 * @brief axis2 IIS Out Transport Info
 */

#include <axis2_http_out_transport_info.h>
#include <httpext.h>
#ifdef __cplusplus
extern "C" 
{
#endif

axis2_http_out_transport_info_t *AXIS2_CALL 
axis2_iis_out_transport_info_create(
    const axutil_env_t *env,
	LPEXTENSION_CONTROL_BLOCK lpECB);

/**
 * Free http_out_transport_info passed as void pointer. This will be
 * cast into appropriate type and then pass the cast object
 * into the http_out_transport_info structure's free method
 */
void AXIS2_CALL 
axis2_iis_out_transport_info_free_void_arg(
    void *transport_info,
    const axutil_env_t *env);

axis2_char_t *axis2_iis_out_transport_get_content(axis2_http_out_transport_info_t *out_transport_info);

#ifdef __cplusplus
}
#endif
#endif	/* AXIS2_IIS_OUT_TRANSPORT_INFO_H */
