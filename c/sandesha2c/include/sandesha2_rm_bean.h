/*
 * copyright 1999-2004 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#ifndef SANDESHA2_RM_BEAN_H
#define SANDESHA2_RM_BEAN_H

#include <axutil_qname.h>
#include <axutil_env.h>
#include <axutil_utils.h>
#include <axutil_utils_defines.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct sandesha2_rm_bean sandesha2_rm_bean_t;
typedef struct sandesha2_rm_bean_ops sandesha2_rm_bean_ops_t;
struct sandesha2_transaction;

AXIS2_DECLARE_DATA struct sandesha2_rm_bean_ops
{
    void (AXIS2_CALL *
            free) ( 
                sandesha2_rm_bean_t *rm_bean,
                const axutil_env_t *env);

    sandesha2_rm_bean_t * (AXIS2_CALL *
            get_base) ( 
                sandesha2_rm_bean_t *rm_bean,
                const axutil_env_t *env);
    
    void (AXIS2_CALL *
            set_id) ( 
                sandesha2_rm_bean_t *rm_bean,
                const axutil_env_t *env, 
                long id);

    long (AXIS2_CALL *
            get_id) ( 
                sandesha2_rm_bean_t *rm_bean,
                const axutil_env_t *env);

    void (AXIS2_CALL *
            set_transaction) ( 
                sandesha2_rm_bean_t *rm_bean,
                const axutil_env_t *env, 
                struct sandesha2_transaction *transaction);

    struct sandesha2_transaction *(AXIS2_CALL *
            get_transaction) ( 
                sandesha2_rm_bean_t *rm_bean,
                const axutil_env_t *env);
    
    axis2_char_t *(AXIS2_CALL *
            get_key) ( 
                sandesha2_rm_bean_t *rm_bean,
                const axutil_env_t *env);
};

AXIS2_DECLARE_DATA struct sandesha2_rm_bean
{
    sandesha2_rm_bean_ops_t ops;
};

/* constructors 
 */
AXIS2_EXTERN sandesha2_rm_bean_t* AXIS2_CALL
sandesha2_rm_bean_create(
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_rm_bean_free( 
    sandesha2_rm_bean_t *rm_bean,
	const axutil_env_t *env);

sandesha2_rm_bean_t * AXIS2_CALL
sandesha2_rm_bean_get_base( 
    sandesha2_rm_bean_t *rm_bean,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_rm_bean_set_id( 
    sandesha2_rm_bean_t *rm_bean,
	const axutil_env_t *env, 
    long id);

long AXIS2_CALL
sandesha2_rm_bean_get_id( 
    sandesha2_rm_bean_t *rm_bean,
	const axutil_env_t *env);

void AXIS2_CALL
sandesha2_rm_bean_set_transaction( 
    sandesha2_rm_bean_t *rm_bean,
	const axutil_env_t *env, 
    struct sandesha2_transaction *transaction);

struct sandesha2_transaction *AXIS2_CALL
sandesha2_rm_bean_get_transaction( 
    sandesha2_rm_bean_t *rm_bean,
	const axutil_env_t *env);

axis2_char_t *AXIS2_CALL
sandesha2_rm_bean_get_key( 
    sandesha2_rm_bean_t *rm_bean,
	const axutil_env_t *env);

#ifdef __cplusplus
}

#endif
	
#endif /* End of SANDESHA2_RM_BEAN_H */
