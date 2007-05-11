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

#include <rp_layout.h>

struct rp_layout_t
{
    axis2_char_t *value;
};

AXIS2_EXTERN rp_layout_t *AXIS2_CALL 
rp_layout_create(const axutil_env_t *env)
{
    rp_layout_t *layout = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    layout =  (rp_layout_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_layout_t));

    if(layout == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    layout->value = RP_LAYOUT_STRICT;
    return layout;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_layout_free(rp_layout_t *layout,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(layout)
    {
        AXIS2_FREE(env->allocator, layout);
        layout = NULL;
    }
    return AXIS2_SUCCESS;
}


/* Implementations */

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_layout_get_value(rp_layout_t *layout,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return layout->value;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_layout_set_value(rp_layout_t *layout,
            const axutil_env_t *env,
            axis2_char_t *value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,value,AXIS2_FAILURE);    
    
    layout->value = value;
    return AXIS2_SUCCESS;
}

