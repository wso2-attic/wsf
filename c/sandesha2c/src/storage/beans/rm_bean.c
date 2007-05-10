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

#include <sandesha2_rm_bean.h>
#include <sandesha2_transaction.h>
#include <string.h>
#include <axutil_string.h>
#include <axutil_utils.h>

/* rm_bean struct */
typedef struct sandesha2_rm_bean_impl
{
    sandesha2_rm_bean_t rm_bean;
	long id;
    sandesha2_transaction_t *transaction;
} sandesha2_rm_bean_impl_t;

#define SANDESHA2_INTF_TO_IMPL(rm_bean) ((sandesha2_rm_bean_impl_t *) rm_bean)
static const sandesha2_rm_bean_ops_t rm_bean_ops =
{
    sandesha2_rm_bean_free,
    NULL,
    sandesha2_rm_bean_set_id,
    sandesha2_rm_bean_get_id,
    sandesha2_rm_bean_set_transaction,
    sandesha2_rm_bean_get_transaction,
    NULL
};

AXIS2_EXTERN sandesha2_rm_bean_t* AXIS2_CALL
sandesha2_rm_bean_create(const axutil_env_t *env)
{
	sandesha2_rm_bean_impl_t *rm_bean_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	rm_bean_impl = (sandesha2_rm_bean_impl_t *)AXIS2_MALLOC(env->allocator,
	    sizeof(sandesha2_rm_bean_impl_t));
	if(!rm_bean_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}
	/* init the properties. */
	rm_bean_impl->id = -1;
    rm_bean_impl->transaction = NULL;
    rm_bean_impl->rm_bean.ops = rm_bean_ops;
	return &(rm_bean_impl->rm_bean);
}

void AXIS2_CALL
sandesha2_rm_bean_free (
    sandesha2_rm_bean_t *rm_bean,
	const axutil_env_t *env)
{
}

sandesha2_rm_bean_t * AXIS2_CALL
sandesha2_rm_bean_get_base( 
    sandesha2_rm_bean_t *rm_bean,
    const axutil_env_t *env)
{
    return rm_bean->ops.get_base(rm_bean, env);
}

axis2_char_t *AXIS2_CALL
sandesha2_rm_bean_get_key(
    sandesha2_rm_bean_t *rm_bean,
    const axutil_env_t *env)
{
    return rm_bean->ops.get_key(rm_bean, env);
}

void AXIS2_CALL
sandesha2_rm_bean_set_id( 
    sandesha2_rm_bean_t *rm_bean,
	const axutil_env_t *env, 
    long id)
{
    sandesha2_rm_bean_impl_t *rm_bean_impl = NULL;
    rm_bean_impl = SANDESHA2_INTF_TO_IMPL(rm_bean);
    rm_bean_impl->id = id;
}

long AXIS2_CALL
sandesha2_rm_bean_get_id( 
    sandesha2_rm_bean_t *rm_bean,
	const axutil_env_t *env)
{
    sandesha2_rm_bean_impl_t *rm_bean_impl = NULL;
    rm_bean_impl = SANDESHA2_INTF_TO_IMPL(rm_bean);
    return rm_bean_impl->id;
}

void AXIS2_CALL
sandesha2_rm_bean_set_transaction( 
    sandesha2_rm_bean_t *rm_bean,
	const axutil_env_t *env, 
    sandesha2_transaction_t *transaction)
{
    sandesha2_rm_bean_impl_t *rm_bean_impl = NULL;
    rm_bean_impl = SANDESHA2_INTF_TO_IMPL(rm_bean);
    rm_bean_impl->transaction = transaction;
}

sandesha2_transaction_t *AXIS2_CALL
sandesha2_rm_bean_get_transaction( 
    sandesha2_rm_bean_t *rm_bean,
	const axutil_env_t *env)
{
    sandesha2_rm_bean_impl_t *rm_bean_impl = NULL;
    rm_bean_impl = SANDESHA2_INTF_TO_IMPL(rm_bean);
    return rm_bean_impl->transaction;
}


