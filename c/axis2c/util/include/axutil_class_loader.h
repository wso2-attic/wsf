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
 
#ifndef AXUTIL_CLASS_LOADER_H
#define AXUTIL_CLASS_LOADER_H

/**
  * @file axutil_class_loader.h
  * @brief axis2 class loader interface
  */

#include <axutil_utils_defines.h>
#include <axutil_qname.h>
#include <axutil_error.h>
#include <axutil_utils.h>
#include <axutil_dll_desc.h>
#include <axutil_param.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup axutil_class_loader class loader 
 * @ingroup axis2_util
 * @{
 */
    
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_class_loader_init(const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_class_loader_delete_dll (const axutil_env_t *env,
                                    axutil_dll_desc_t *dll_desc);

AXIS2_EXTERN void * AXIS2_CALL
axutil_class_loader_create_dll (const axutil_env_t *env,
                                axutil_param_t *impl_info_param);
    
 
/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* AXIS2_CLASS_LOADER_H */
