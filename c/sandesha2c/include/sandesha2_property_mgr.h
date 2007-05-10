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
 
#ifndef SANDESHA2_PROPERTY_MGR_H
#define SANDESHA2_PROPERTY_MGR_H

#include <axiom_soap_envelope.h>

/**
  * @file sandesha2_property_mgr.h
  * @brief 
  */

#include <sandesha2_storage_mgr.h>
#include <axis2_conf_ctx.h>
#include <axis2_conf.h>
#include <axiom_soap_envelope.h>
#include <axutil_qname.h>
#include <axutil_array_list.h>
#include <axis2_op.h>
#include <sandesha2_property_bean.h>
#include <sandesha2_msg_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_property_mgr
 * @ingroup sandesha2_util
 * @{
 */
AXIS2_EXTERN  sandesha2_property_bean_t* AXIS2_CALL
sandesha2_property_mgr_load_properties_from_def_values(
    const axutil_env_t *env);

AXIS2_EXTERN  sandesha2_property_bean_t* AXIS2_CALL
sandesha2_property_mgr_load_properties_from_module_desc(
    const axutil_env_t *env,
    axis2_module_desc_t *module_desc);
                        

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_PROPERTY_MGR_H */

