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

#ifndef OXS_TRANSFORM_H
#define OXS_TRANSFORM_H


/**
  * @file oxs_transform.h
  * @brief The class representing a single step of transformation. 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axiom_node.h>

#ifdef __cplusplus
extern "C"
{
#endif


    /*The input or output data type*/
    typedef enum  {
        OXS_TRANSFORM_TYPE_UNKNOWN = 0,
        OXS_TRANSFORM_TYPE_CHAR,
        OXS_TRANSFORM_TYPE_NODE
    } oxs_tr_dtype_t;


    /*Function interface for any transform*/
    typedef oxs_tr_dtype_t (AXIS2_CALL*
                            oxs_transform_tr_func)(const axutil_env_t *env,
                                                   void *input,
                                                   oxs_tr_dtype_t input_dtype,
                                                   void **output);

    typedef struct oxs_transform_t oxs_transform_t;


    /*Create function*/
    AXIS2_EXTERN oxs_transform_t *AXIS2_CALL
    oxs_transform_create(const axutil_env_t *env);

    /*Free*/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_transform_free(oxs_transform_t *ctx,
                       const axutil_env_t *env);


    /**********************Getter functions******************************************/
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_transform_get_id(
        const oxs_transform_t *transform,
        const axutil_env_t *env);

    AXIS2_EXTERN oxs_tr_dtype_t AXIS2_CALL
    oxs_transform_get_input_data_type(
        const oxs_transform_t *transform,
        const axutil_env_t *env);

    AXIS2_EXTERN oxs_tr_dtype_t AXIS2_CALL
    oxs_transform_get_output_data_type(
        const oxs_transform_t *transform,
        const axutil_env_t *env);

    AXIS2_EXTERN oxs_transform_tr_func AXIS2_CALL
    oxs_transform_get_transform_function(
        const oxs_transform_t *transform,
        const axutil_env_t *env);

    /**********************Setter functions******************************************/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_transform_set_id(
        oxs_transform_t *transform,
        const axutil_env_t *env,
        axis2_char_t *id);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_transform_set_input_data_type(
        oxs_transform_t *transform,
        const axutil_env_t *env,
        oxs_tr_dtype_t input_data_type);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_transform_set_output_data_type(
        oxs_transform_t *transform,
        const axutil_env_t *env,
        oxs_tr_dtype_t output_data_type);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_transform_set_transform_func(
        oxs_transform_t *transform,
        const axutil_env_t *env,
        oxs_transform_tr_func transform_func);

    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_TRANSFORM_H */
