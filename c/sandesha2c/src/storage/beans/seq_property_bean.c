/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <sandesha2_seq_property_bean.h>
#include <sandesha2_transaction.h>
#include <sandesha2_rm_bean.h>
#include <string.h>
#include <axutil_string.h>
#include <axutil_utils.h>


/*seq_property_bean struct */
typedef struct sandesha2_seq_property_bean_impl
{
    sandesha2_seq_property_bean_t seq_property_bean;
    sandesha2_rm_bean_t *rm_bean_impl;
	axis2_char_t *seq_id;
	axis2_char_t *name;
	axis2_char_t *value;
} sandesha2_seq_property_bean_impl_t;

#define SANDESHA2_INTF_TO_IMPL(seq_property_bean) \
    ((sandesha2_seq_property_bean_impl_t *) seq_property_bean)

axis2_char_t* AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_get_key(
    sandesha2_rm_bean_t *seq_property_bean,
    const axutil_env_t *env);

static const sandesha2_rm_bean_ops_t rm_bean_ops =
{
    sandesha2_seq_property_bean_free,
    sandesha2_seq_property_bean_get_base,
    sandesha2_seq_property_bean_set_id,
    sandesha2_seq_property_bean_get_id,
    sandesha2_seq_property_bean_set_transaction,
    sandesha2_seq_property_bean_get_transaction,
    sandesha2_inmemory_seq_property_mgr_get_key
};

AXIS2_EXTERN sandesha2_seq_property_bean_t* AXIS2_CALL
sandesha2_seq_property_bean_create(
    const axutil_env_t *env)
{
	sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);

	seq_property_bean_impl = (sandesha2_seq_property_bean_impl_t *)AXIS2_MALLOC(
        env->allocator, sizeof(sandesha2_seq_property_bean_impl_t));

	if(!seq_property_bean_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}

	/* initialize properties */
	seq_property_bean_impl->seq_id = NULL;
	seq_property_bean_impl->name = NULL;
	seq_property_bean_impl->value = NULL;
    seq_property_bean_impl->rm_bean_impl = sandesha2_rm_bean_create(env);
    seq_property_bean_impl->seq_property_bean.rm_bean.ops = rm_bean_ops;

	return &(seq_property_bean_impl->seq_property_bean);
}

AXIS2_EXTERN sandesha2_seq_property_bean_t* AXIS2_CALL
sandesha2_seq_property_bean_create_with_data(
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *prop_name,
    axis2_char_t *value)

{
	sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);

	seq_property_bean_impl = (sandesha2_seq_property_bean_impl_t *)AXIS2_MALLOC(
        env->allocator, sizeof(sandesha2_seq_property_bean_impl_t));

	if(!seq_property_bean_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}
	/* initialize properties */
	seq_property_bean_impl->seq_id = (axis2_char_t *)axutil_strdup(env, seq_id);
	seq_property_bean_impl->name = (axis2_char_t *)axutil_strdup(env, prop_name);
	seq_property_bean_impl->value = (axis2_char_t *)axutil_strdup(env, value);
    seq_property_bean_impl->rm_bean_impl = sandesha2_rm_bean_create(env);
    seq_property_bean_impl->seq_property_bean.rm_bean.ops = rm_bean_ops;

	return &(seq_property_bean_impl->seq_property_bean);
}


void AXIS2_CALL
sandesha2_seq_property_bean_free (
    sandesha2_rm_bean_t *seq_property_bean,
    const axutil_env_t *env)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
/*	if(seq_property_bean_impl->rm_bean_impl)
	{
		sandesha2_rm_bean_free(seq_property_bean_impl->rm_bean_impl, env);
		seq_property_bean_impl->rm_bean_impl= NULL;
	}
	if(seq_property_bean_impl->seq_id)
	{
		AXIS2_FREE(env->allocator, seq_property_bean_impl->seq_id);
		seq_property_bean_impl->seq_id = NULL;
	}
	if(seq_property_bean_impl->name)
	{
		AXIS2_FREE(env->allocator, seq_property_bean_impl->name);
		seq_property_bean_impl->name = NULL;
	}
	if(seq_property_bean_impl->value)
	{
		AXIS2_FREE(env->allocator,  seq_property_bean_impl->value);
		seq_property_bean_impl->value = NULL;
	}
	if(seq_property_bean_impl)
	{
		AXIS2_FREE(env->allocator,  seq_property_bean_impl);
		seq_property_bean_impl = NULL;
	}
    */
}

sandesha2_rm_bean_t * AXIS2_CALL
sandesha2_seq_property_bean_get_base( 
    sandesha2_rm_bean_t *seq_property_bean,
    const axutil_env_t *env)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
	return seq_property_bean_impl->rm_bean_impl;
}	

void AXIS2_CALL
sandesha2_seq_property_bean_set_base (
    sandesha2_seq_property_bean_t *seq_property_bean,
    const axutil_env_t *env, 
    sandesha2_rm_bean_t* rm_bean)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
	seq_property_bean_impl->rm_bean_impl = rm_bean;
}

axis2_char_t *AXIS2_CALL
sandesha2_seq_property_bean_get_name (
    sandesha2_seq_property_bean_t *seq_property_bean,
    const axutil_env_t *env)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
	return seq_property_bean_impl->name;
}

void AXIS2_CALL 
sandesha2_seq_property_bean_set_name (
    sandesha2_seq_property_bean_t *seq_property_bean,
    const axutil_env_t *env,
    axis2_char_t *name)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
	if(seq_property_bean_impl->name)
	{
		AXIS2_FREE(env->allocator, seq_property_bean_impl->name);
		seq_property_bean_impl->name = NULL;
	}
    if(name)
        seq_property_bean_impl->name = (axis2_char_t *)axutil_strdup(env, name);
}

axis2_char_t *AXIS2_CALL
sandesha2_seq_property_bean_get_seq_id (
    sandesha2_seq_property_bean_t *seq_property_bean,
    const axutil_env_t *env)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
	return seq_property_bean_impl->seq_id;
}


void AXIS2_CALL
sandesha2_seq_property_bean_set_seq_id (
    sandesha2_seq_property_bean_t *seq_property_bean,
    const axutil_env_t *env,
    axis2_char_t *seq_id)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
	if(seq_property_bean_impl->seq_id)
	{
		AXIS2_FREE(env->allocator, seq_property_bean_impl->seq_id);
		seq_property_bean_impl->seq_id = NULL;
	}
    if(seq_id)
        seq_property_bean_impl->seq_id = (axis2_char_t *)axutil_strdup(env, seq_id);
}

axis2_char_t* AXIS2_CALL
sandesha2_seq_property_bean_get_value (
    sandesha2_seq_property_bean_t *seq_property_bean,
    const axutil_env_t *env)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
	return seq_property_bean_impl->value;
}


void AXIS2_CALL
sandesha2_seq_property_bean_set_value (
    sandesha2_seq_property_bean_t *seq_property_bean,
    const axutil_env_t *env,
    axis2_char_t *value)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
	if(seq_property_bean_impl->value)
	{
		AXIS2_FREE(env->allocator, seq_property_bean_impl->value);
		seq_property_bean_impl->value = NULL;
	}
    if(value)
        seq_property_bean_impl->value = (axis2_char_t *)axutil_strdup(env, value);

}

void AXIS2_CALL
sandesha2_seq_property_bean_set_id(
    sandesha2_rm_bean_t *seq_property_bean,
    const axutil_env_t *env,
    long id)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
    sandesha2_rm_bean_set_id(seq_property_bean_impl->rm_bean_impl, env, id);
}

long AXIS2_CALL
sandesha2_seq_property_bean_get_id(
    sandesha2_rm_bean_t *seq_property_bean,
    const axutil_env_t *env)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
    return sandesha2_rm_bean_get_id(seq_property_bean_impl->rm_bean_impl, env);
}

void AXIS2_CALL
sandesha2_seq_property_bean_set_transaction(
    sandesha2_rm_bean_t *seq_property_bean,
    const axutil_env_t *env,
    sandesha2_transaction_t *transaction)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
    sandesha2_rm_bean_set_transaction(seq_property_bean_impl->rm_bean_impl, env,
        transaction);
}

sandesha2_transaction_t *AXIS2_CALL
sandesha2_seq_property_bean_get_transaction(
    sandesha2_rm_bean_t *seq_property_bean,
    const axutil_env_t *env)
{
    sandesha2_seq_property_bean_impl_t *seq_property_bean_impl = NULL;
    seq_property_bean_impl = SANDESHA2_INTF_TO_IMPL(seq_property_bean);
    return sandesha2_rm_bean_get_transaction(seq_property_bean_impl->rm_bean_impl,
        env);
}

axis2_char_t* AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_get_key(
    sandesha2_rm_bean_t *seq_property_bean,
    const axutil_env_t *env)
{
    axis2_char_t *seq_id = NULL;
    axis2_char_t *name = NULL;
    axis2_char_t *id = NULL;

    seq_id = sandesha2_seq_property_bean_get_seq_id(
        (sandesha2_seq_property_bean_t *) seq_property_bean, env);
    name = sandesha2_seq_property_bean_get_name(
        (sandesha2_seq_property_bean_t *) seq_property_bean, env);
    id = axutil_strcat(env, seq_id, ":", name, NULL);

    return id;
}

