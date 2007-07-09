
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

#ifndef C14N_SORTED_LIST_H
#define C14N_SORTED_LIST_H

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct c14n_sorted_list c14n_sorted_list_t;


    struct c14n_sorted_list {
        void *val;
        c14n_sorted_list_t *right, *left;
    };

    void
    sorted_list_insert(
        c14n_sorted_list_t **node,
        void *val,
        const void *ctx,
        int(*compar)(const void *, const void *, const void *)
        );


    void
    sorted_list_iterate(
        c14n_sorted_list_t *root,
        const void *ctx,
        void(*perform)(const void *, const void *),
        const axutil_env_t *env
        );

    void
    sorted_list_free_container(
        c14n_sorted_list_t *root,
        const axutil_env_t *env
        );

#ifdef __cplusplus
}
#endif

#define C14N_SORTED_LIST_INSERT(list, val, ctx, compar, env)\
    sorted_list_insert(list, val, ctx, compar)

#define c14n_sorted_list_create(env) NULL

#define C14N_SORTED_LIST_FREE(list, fp_free, env) sorted_list_free(list, fp_free)

#define C14N_SORTED_LIST_ITERATE(list, ctx, fp_perform, env)\
    sorted_list_iterate(list, ctx, fp_perform, env)

#define C14N_SORTED_LIST_FREE_CONTAINER(list, env)\
    sorted_list_free_container(list, env);\
    AXIS2_FREE(env->allocator, list)

#endif
