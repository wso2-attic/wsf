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

#include <axis2_conf_init.h>
#include <axis2_transport_sender.h>
#include <axis2_transport_receiver.h>
#include <axis2_const.h>
#include <axutil_error.h>
#include <axutil_allocator.h>
#include <axutil_class_loader.h>
#include <axis2_dep_engine.h>
#include <axis2_module.h>

axis2_status_t AXIS2_CALL
axis2_init_modules(const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx);

static axis2_status_t AXIS2_CALL
axis2_load_services(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx);

axis2_status_t AXIS2_CALL
axis2_init_transports(const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx);

AXIS2_EXTERN axis2_conf_ctx_t *AXIS2_CALL
axis2_build_conf_ctx(const axutil_env_t *env,
    const axis2_char_t *repo_name)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_dep_engine_t *dep_engine = NULL;
    axis2_conf_t *conf = NULL;
    axis2_phase_resolver_t *phase_resolver = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    dep_engine = axis2_dep_engine_create_with_repos_name(env, repo_name);
    if (!dep_engine)
    {
        return NULL;
    }

    conf = axis2_dep_engine_load(dep_engine, env);
    if (!conf)
    {
        return NULL;
    }
     axis2_conf_set_dep_engine(conf, env, dep_engine);

    phase_resolver = axis2_phase_resolver_create_with_config(env, conf);
    if (!phase_resolver)
    {
        return NULL;
    }

    conf_ctx = axis2_conf_ctx_create(env, conf);

    axis2_phase_resolver_build_chains(phase_resolver, env);

    axis2_init_modules(env, conf_ctx);
    axis2_load_services(env, conf_ctx);
    axis2_init_transports(env, conf_ctx);

    axis2_phase_resolver_free(phase_resolver, env);

    return conf_ctx;
}

axis2_conf_ctx_t *AXIS2_CALL
axis2_build_client_conf_ctx(const axutil_env_t *env,
    const axis2_char_t *axis2_home)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_dep_engine_t *dep_engine = NULL;
    axis2_conf_t *conf = NULL;
    axis2_phase_resolver_t *phase_resolver = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    dep_engine = axis2_dep_engine_create(env);
    if (!dep_engine)
    {
        return NULL;
    }

    conf = axis2_dep_engine_load_client(dep_engine, env, axis2_home);
    if (!conf)
    {
        return NULL;
    }
    axis2_conf_set_dep_engine(conf, env, dep_engine);

    phase_resolver = axis2_phase_resolver_create_with_config(env, conf);
    if (!phase_resolver)
    {
        return NULL;
    }

    conf_ctx = axis2_conf_ctx_create(env, conf);
    if (!conf_ctx)
    {
        return NULL;
    }

    axis2_phase_resolver_build_chains(phase_resolver, env);

    axis2_init_modules(env, conf_ctx);
    axis2_init_transports(env, conf_ctx);

    axis2_phase_resolver_free(phase_resolver, env);

    return conf_ctx;
}

axis2_status_t AXIS2_CALL
axis2_init_modules(const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    axis2_conf_t *conf = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);

    conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
    if (conf)
    {
        axutil_hash_t *module_map =  axis2_conf_get_all_modules(conf, env);
        if (module_map)
        {
            axutil_hash_index_t *hi = NULL;
            void *module = NULL;
            for (hi = axutil_hash_first(module_map, env);
                hi; hi = axutil_hash_next(env, hi))
            {
                axutil_hash_this(hi, NULL, NULL, &module);
                if (module)
                {
                    axis2_module_desc_t *mod_desc = (axis2_module_desc_t*)module;
                    if (mod_desc)
                    {
                        axis2_module_t *mod = axis2_module_desc_get_module(mod_desc, env);
                        if (mod)
                        {
                            AXIS2_MODULE_INIT(mod, env, conf_ctx, mod_desc);
                        }
                    }
                }
            }
        }
        status = AXIS2_SUCCESS;
    }

    return status;
}

static axis2_status_t AXIS2_CALL
axis2_load_services(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    axis2_conf_t *conf = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);

    conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
    if (conf)
    {
        axutil_hash_t *svc_map =  axis2_conf_get_all_svcs_to_load(conf, env);
        if (svc_map)
        {
            axutil_hash_index_t *hi = NULL;
            void *svc = NULL;
            for (hi = axutil_hash_first(svc_map, env);
                hi; hi = axutil_hash_next(env, hi))
            {
                axutil_hash_this(hi, NULL, NULL, &svc);
                if (svc)
                {
                    axis2_svc_t *svc_desc = (axis2_svc_t*)svc;
                    if (svc_desc)
                    {
                        axutil_param_t *impl_info_param = NULL;
                        void *impl_class = NULL;
                        impl_info_param = axis2_svc_get_param(svc_desc, env, 
                            AXIS2_SERVICE_CLASS);
                        if (!impl_info_param)
                        {
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_STATE_SVC,
                                AXIS2_FAILURE);
                            return AXIS2_FAILURE;
                        }
                        axutil_allocator_switch_to_global_pool(env->allocator);
                        axutil_class_loader_init(env);
                        impl_class = axutil_class_loader_create_dll(env, impl_info_param);
                        axis2_svc_set_impl_class(svc_desc, env, impl_class);
                        AXIS2_SVC_SKELETON_INIT_WITH_CONF(
                            (axis2_svc_skeleton_t *)impl_class, env, conf);
                        axutil_allocator_switch_to_local_pool(env->allocator);
                    }
                }
            }
        }
        status = AXIS2_SUCCESS;
    }

    return status;
}

axis2_status_t AXIS2_CALL
axis2_init_transports(const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    axis2_conf_t *conf = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);

    conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
    if (conf)
    {
        axis2_transport_in_desc_t **transport_in_map = NULL;
        axis2_transport_out_desc_t **transport_out_map = NULL;
        int i = 0;

        transport_in_map =  axis2_conf_get_all_in_transports(conf, env);
        for (i = 0; i < AXIS2_TRANSPORT_ENUM_MAX; i++)
        {
            if (transport_in_map[i])
            {
                axis2_transport_receiver_t *listener = 
                    axis2_transport_in_desc_get_recv(transport_in_map[i], env);
                if (listener)
                {
                    status = axis2_transport_receiver_init(listener, env, conf_ctx, 
                        transport_in_map[i]);
                }

            }
        }

        transport_out_map =  axis2_conf_get_all_out_transports(conf, env);
        for (i = 0; i < AXIS2_TRANSPORT_ENUM_MAX; i++)
        {
            if (transport_out_map[i])
            {
                axis2_transport_sender_t *sender = 
                    axis2_transport_out_desc_get_sender(transport_out_map[i], env);
                if (sender)
                {
                    status = AXIS2_TRANSPORT_SENDER_INIT(sender, env, conf_ctx, 
                        transport_out_map[i]);
                }

            }
        }
        status = AXIS2_SUCCESS;
    }

    return status;
}

