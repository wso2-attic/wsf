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

#include <axis2_ctx.h>
#include <axis2_const.h>
#include <axutil_hash.h>

struct axis2_ctx
{
    /** non persistent map */
    axutil_hash_t *property_map;
    /** non persistent map is a deep copy */
    axis2_bool_t property_map_deep_copy;
};

AXIS2_EXTERN axis2_ctx_t *AXIS2_CALL
axis2_ctx_create(const axutil_env_t *env)
{
    axis2_ctx_t *ctx = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    ctx = AXIS2_MALLOC(env->allocator, sizeof(axis2_ctx_t));
    if (!ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    ctx->property_map = NULL;

    ctx->property_map = axutil_hash_make(env);
    ctx->property_map_deep_copy = AXIS2_TRUE;
    if (!(ctx->property_map))
    {
        axis2_ctx_free(ctx, env);
        return NULL;
    }

    return ctx;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_ctx_set_property(struct axis2_ctx *ctx,
    const axutil_env_t *env,
    const axis2_char_t *key,
    axutil_property_t *value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (value)
    {
        /* handle the case where we are setting a new value with the 
           same key, we would have to free the existing value */
        axutil_property_t *temp_value = axutil_hash_get(ctx->property_map, 
            key, 
            AXIS2_HASH_KEY_STRING);
		if (temp_value)
		{
			void *temp_value_value =  axutil_property_get_value (temp_value, env);
			void *value_value =  axutil_property_get_value (value, env);
			if (temp_value_value != value_value)
			{
				axutil_property_free(temp_value, env);
			}
		}
    }
    if (ctx->property_map)
    {
        axutil_hash_set(ctx->property_map, key,
            AXIS2_HASH_KEY_STRING, value);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_property_t *AXIS2_CALL
axis2_ctx_get_property(const axis2_ctx_t *ctx,
    const axutil_env_t *env,
    const axis2_char_t *key)
{
    axutil_property_t *ret = NULL;

    if (ctx->property_map)
    {
        ret = axutil_hash_get(ctx->property_map, key, 
            AXIS2_HASH_KEY_STRING);
    }
    /** it is the responsibility of the caller to look-up parent if key is not found here
        Note that in C implementation it is the responsibility of the deriving struct to 
        handle the parent as we do not have the inheritance facility. In case of 
        context it is not worth trying to mimic inheritance. */

    return ret;
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_ctx_get_all_properties(const axis2_ctx_t *ctx,
    const axutil_env_t *env)
{
    return ctx->property_map;
}


AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_ctx_get_property_map(const axis2_ctx_t *ctx,
    const axutil_env_t *env)
{
    return ctx->property_map;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_ctx_free(struct axis2_ctx *ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (ctx->property_map && ctx->property_map_deep_copy)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;
        const void *key = NULL;
        for (hi = axutil_hash_first(ctx->property_map, env);
            hi; hi = axutil_hash_next(env, hi))
        {
            axutil_property_t *property = NULL;

            axutil_hash_this(hi, &key, NULL, &val);
            property = (axutil_property_t *) val;

            if (property)
            {
                axutil_property_free(property, env);
            }
        }
        axutil_hash_free(ctx->property_map, env);
    }

    AXIS2_FREE(env->allocator, ctx);

    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_ctx_set_property_map(struct axis2_ctx *ctx,
    const axutil_env_t *env,
    axutil_hash_t *map)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (ctx->property_map && ctx->property_map_deep_copy)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;
        const void *key = NULL;
        for (hi = axutil_hash_first(ctx->property_map, env);
            hi; hi = axutil_hash_next(env, hi))
        {
            axutil_property_t *property = NULL;

            axutil_hash_this(hi, &key, NULL, &val);
            property = (axutil_property_t *) val;

            if (property)
            {
                axutil_property_free(property, env);
            }
        }
        if (ctx->property_map != map) /* handle repeated invocation case */
        {
            axutil_hash_free(ctx->property_map, env);
        }
    }

    ctx->property_map = map;
    ctx->property_map_deep_copy = AXIS2_FALSE;

    return AXIS2_SUCCESS;
}

