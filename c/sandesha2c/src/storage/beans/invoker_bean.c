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

#include <sandesha2_invoker_bean.h>
#include <sandesha2_transaction.h>
#include <sandesha2_rm_bean.h>
#include <axutil_string.h>
#include <axutil_utils.h>

typedef struct sandesha2_invoker_bean_impl
{
    sandesha2_invoker_bean_t invoker_bean;
    sandesha2_rm_bean_t *rm_bean_impl;
	/*  This is the messageContextRefKey that is obtained after saving a message context in a storage. */
	axis2_char_t *msg_ctx_ref_key;

	/* The message number of the message. */
	long msg_no;

	/*  The seq ID of the seq the message belong to. */
	axis2_char_t *seq_id;

	/* Weather the message has been invoked by the invoker.*/
	axis2_bool_t invoked;

} sandesha2_invoker_bean_impl_t;

#define SANDESHA2_INTF_TO_IMPL(invoker_bean) \
        ((sandesha2_invoker_bean_impl_t *) invoker_bean)

static const sandesha2_rm_bean_ops_t rm_bean_ops =
{
    sandesha2_invoker_bean_free,
    sandesha2_invoker_bean_get_base,
    sandesha2_invoker_bean_set_id,
    sandesha2_invoker_bean_get_id,
    sandesha2_invoker_bean_set_transaction,
    sandesha2_invoker_bean_get_transaction,
    sandesha2_invoker_bean_get_msg_ctx_ref_key
};

AXIS2_EXTERN sandesha2_invoker_bean_t* AXIS2_CALL
sandesha2_invoker_bean_create(
    const axutil_env_t *env )
{
	sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);

	invoker_bean_impl = (sandesha2_invoker_bean_impl_t *) AXIS2_MALLOC(
        env->allocator, sizeof(sandesha2_invoker_bean_impl_t) );

	if (!invoker_bean_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}

	/* init the properties. */
	invoker_bean_impl->msg_ctx_ref_key = NULL;
	invoker_bean_impl->msg_no = -1;
	invoker_bean_impl->seq_id = NULL;	
	invoker_bean_impl->invoked = AXIS2_FALSE;
    invoker_bean_impl->rm_bean_impl = sandesha2_rm_bean_create(env);
    invoker_bean_impl->invoker_bean.rm_bean.ops = rm_bean_ops;

	return &(invoker_bean_impl->invoker_bean);
}

AXIS2_EXTERN sandesha2_invoker_bean_t* AXIS2_CALL
sandesha2_invoker_bean_create_with_data(
    const axutil_env_t *env,
    axis2_char_t *ref_key,
    long msg_no,
    axis2_char_t *seq_id,
    axis2_bool_t invoked)
{
	sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
	AXIS2_ENV_CHECK(env, NULL);
    
    invoker_bean_impl = (sandesha2_invoker_bean_impl_t *) AXIS2_MALLOC(
        env->allocator, sizeof(sandesha2_invoker_bean_impl_t) );

	if (!invoker_bean_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}
	/* init the properties. */
	if(!ref_key)
		invoker_bean_impl->msg_ctx_ref_key = NULL;
	else
		invoker_bean_impl->msg_ctx_ref_key = (axis2_char_t*)axutil_strdup(
            env, ref_key);

	if(!seq_id)
		invoker_bean_impl->seq_id = NULL;	
	else
		invoker_bean_impl->seq_id = (axis2_char_t*)axutil_strdup(env, seq_id);

	invoker_bean_impl->msg_no = msg_no;
	invoker_bean_impl->invoked = invoked;
    invoker_bean_impl->rm_bean_impl = sandesha2_rm_bean_create(env);
    invoker_bean_impl->invoker_bean.rm_bean.ops = rm_bean_ops;

	return &(invoker_bean_impl->invoker_bean);
}

void AXIS2_CALL
sandesha2_invoker_bean_free(
    sandesha2_rm_bean_t *invoker_bean,
    const axutil_env_t *env)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
	if(invoker_bean_impl->rm_bean_impl)
	{
		sandesha2_rm_bean_free(invoker_bean_impl->rm_bean_impl, env);
		invoker_bean_impl->rm_bean_impl= NULL;
	}
	if(invoker_bean_impl->msg_ctx_ref_key)
	{
		AXIS2_FREE(env->allocator, invoker_bean_impl->msg_ctx_ref_key);
		invoker_bean_impl->msg_ctx_ref_key= NULL;
	}
		
	if(!invoker_bean_impl->seq_id)
	{
		AXIS2_FREE(env->allocator, invoker_bean_impl->seq_id);
		invoker_bean_impl->seq_id= NULL;
	}
    if(invoker_bean_impl)
    {
        AXIS2_FREE(env->allocator, invoker_bean_impl->seq_id);
        invoker_bean_impl = NULL;
    }
}

sandesha2_rm_bean_t * AXIS2_CALL
sandesha2_invoker_bean_get_base( 
    sandesha2_rm_bean_t *invoker_bean,
    const axutil_env_t *env)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
	return invoker_bean_impl->rm_bean_impl;

}	

void AXIS2_CALL
sandesha2_invoker_bean_set_base (
    sandesha2_invoker_bean_t *invoker_bean,
    const axutil_env_t *env, 
    sandesha2_rm_bean_t* rm_bean)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
	invoker_bean_impl->rm_bean_impl = rm_bean;
}

axis2_char_t* AXIS2_CALL 
sandesha2_invoker_bean_get_msg_ctx_ref_key(
        sandesha2_rm_bean_t *invoker_bean,
		const axutil_env_t *env)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
	return invoker_bean_impl->msg_ctx_ref_key;
}

void AXIS2_CALL 
sandesha2_invoker_bean_set_msg_ctx_ref_key(
    sandesha2_invoker_bean_t *invoker_bean,
    const axutil_env_t *env, axis2_char_t* context_ref_id)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
	if(invoker_bean_impl->msg_ctx_ref_key)
		AXIS2_FREE(env->allocator, invoker_bean_impl->msg_ctx_ref_key);

	invoker_bean_impl->msg_ctx_ref_key = 
        (axis2_char_t*)axutil_strdup(env, context_ref_id);
}
	

long AXIS2_CALL 
sandesha2_invoker_bean_get_msg_no(
    sandesha2_invoker_bean_t *invoker_bean,
    const axutil_env_t *env)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
	return invoker_bean_impl->msg_no;
}
	
void AXIS2_CALL
sandesha2_invoker_bean_set_msg_no(
    sandesha2_invoker_bean_t *invoker_bean,
    const axutil_env_t *env, long msgno)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
	invoker_bean_impl->msg_no = msgno;
}

axis2_char_t* AXIS2_CALL
sandesha2_invoker_bean_get_seq_id(
    sandesha2_invoker_bean_t *invoker_bean,
    const axutil_env_t *env)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
	return invoker_bean_impl->seq_id;
}

void AXIS2_CALL
sandesha2_invoker_bean_set_seq_id(
    sandesha2_invoker_bean_t *invoker_bean,
    const axutil_env_t *env, axis2_char_t* int_seq_id)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
	invoker_bean_impl->seq_id = (axis2_char_t*)axutil_strdup(env ,int_seq_id);

}

axis2_bool_t AXIS2_CALL
sandesha2_invoker_bean_is_invoked (
    sandesha2_invoker_bean_t *invoker_bean,
    const axutil_env_t *env)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
	return invoker_bean_impl->invoked;
}

void AXIS2_CALL 
sandesha2_invoker_bean_set_invoked( 
    sandesha2_invoker_bean_t *invoker_bean,
    const axutil_env_t *env,
    axis2_bool_t invoked)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
	invoker_bean_impl->invoked = invoked;
}

void AXIS2_CALL
sandesha2_invoker_bean_set_id( 
    sandesha2_rm_bean_t *invoker_bean,
	const axutil_env_t *env, 
    long id)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
    sandesha2_rm_bean_set_id(invoker_bean_impl->rm_bean_impl, env, id);
}

long AXIS2_CALL
sandesha2_invoker_bean_get_id( 
    sandesha2_rm_bean_t *invoker_bean,
	const axutil_env_t *env)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
    return sandesha2_rm_bean_get_id(invoker_bean_impl->rm_bean_impl, env);
}

void AXIS2_CALL
sandesha2_invoker_bean_set_transaction( 
    sandesha2_rm_bean_t *invoker_bean,
	const axutil_env_t *env, 
    sandesha2_transaction_t *transaction)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
    sandesha2_rm_bean_set_transaction(invoker_bean_impl->rm_bean_impl, env, 
        transaction);
}

sandesha2_transaction_t *AXIS2_CALL
sandesha2_invoker_bean_get_transaction( 
    sandesha2_rm_bean_t *invoker_bean,
	const axutil_env_t *env)
{
    sandesha2_invoker_bean_impl_t *invoker_bean_impl = NULL;
    invoker_bean_impl = SANDESHA2_INTF_TO_IMPL(invoker_bean);
    return sandesha2_rm_bean_get_transaction(invoker_bean_impl->rm_bean_impl, 
        env);
}

