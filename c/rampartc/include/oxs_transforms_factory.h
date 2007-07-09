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

#ifndef OXS_TRANSFORMS_FACTORY_H
#define OXS_TRANSFORMS_FACTORY_H


/**
  * @file oxs_transforms_factory.h
  * @brief Produces transforms for OMXMLSecurity  
  */

#include <axis2_defines.h>
#include <oxs_ctx.h>
#include <axutil_env.h>
#include <axiom_node.h>
#include <axiom_element.h>
#include <axutil_qname.h>
#include <oxs_transform.h>

#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN oxs_transform_t *AXIS2_CALL
    oxs_transforms_factory_produce_transform(const axutil_env_t *env,
            axis2_char_t *id);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_TRANSFORMS_FACTORY_H */
