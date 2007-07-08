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

#include <stdio.h>
#include <axis2_util.h>
#include <oxs_constants.h>
#include <oxs_error.h>
#include <oxs_buffer.h>
#include <oxs_transform.h>
#include <oxs_transforms_factory.h>
#include <oxs_buffer.h>
#include <oxs_c14n.h>

/*Functions that implements transforms*/
oxs_tr_dtype_t AXIS2_CALL
oxs_transforms_exc_c14n(const axutil_env_t *env,
                        axiom_node_t *input,
                        oxs_tr_dtype_t input_dtype,
                        axis2_char_t **output)
{
    axiom_document_t *doc = NULL;
    axis2_char_t *algo = NULL;
    axis2_char_t *c14nized = NULL;
    oxs_tr_dtype_t output_dtype = OXS_TRANSFORM_TYPE_UNKNOWN;

    if(input_dtype != OXS_TRANSFORM_TYPE_NODE){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_TRANSFORM_FAILED,"Transform expects a NODE.");
        return OXS_TRANSFORM_TYPE_UNKNOWN;
    }

    doc = axiom_node_get_document(input, env);
    algo = OXS_HREF_TRANSFORM_XML_EXC_C14N;
    oxs_c14n_apply_algo(env, doc, &c14nized, NULL, input, algo);
    /*oxs_c14n_apply(env, doc, AXIS2_FALSE, &c14nized, AXIS2_TRUE, NULL, (axiom_node_t*)input);*/
    AXIS2_LOG_INFO(env->log, "[rampart][c14n-OutPut] is\n\n%s\n\n",c14nized);
    *output= c14nized;
    output_dtype = OXS_TRANSFORM_TYPE_CHAR;
    return output_dtype;
}

/*Public functions*/
AXIS2_EXTERN oxs_transform_t *AXIS2_CALL
oxs_transforms_factory_produce_transform(const axutil_env_t *env,
        axis2_char_t *id)
{
    oxs_transform_t *tr =  NULL;

    /*Inspect the id and produce a transform*/
    if(0== axutil_strcmp(id, OXS_HREF_TRANSFORM_XML_EXC_C14N)){
        tr = oxs_transform_create(env);
        oxs_transform_set_id(tr, env, id);
        oxs_transform_set_input_data_type(tr, env, OXS_TRANSFORM_TYPE_NODE);
        oxs_transform_set_output_data_type(tr, env, OXS_TRANSFORM_TYPE_CHAR);
        oxs_transform_set_transform_func(tr, env, (oxs_transform_tr_func)oxs_transforms_exc_c14n);
        return tr;
    }else{
        /*Error we do not support*/
        return NULL;
    }
}

