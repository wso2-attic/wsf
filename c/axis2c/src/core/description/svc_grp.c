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

#include <axis2_svc_grp.h>
#include <axis2_conf_ctx.h>

struct axis2_svc_grp
{
    /** service group name */
    axis2_char_t *svc_grp_name;
    /** map of services */
    axutil_hash_t *svcs;
    /** to store service group modules QNames */
    axutil_array_list_t *module_qnames;
    /** to store module ref at deploy time parsing */
    axis2_conf_t *parent;
    /** list of module references */
    axutil_array_list_t *module_list;
    /** parameter container to hold service related parameters */
    axutil_param_container_t *param_container;
};

AXIS2_EXTERN axis2_svc_grp_t *AXIS2_CALL
axis2_svc_grp_create(
    const axutil_env_t *env)
{
    axis2_svc_grp_t *svc_grp = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    svc_grp = (axis2_svc_grp_t *)
            AXIS2_MALLOC(env->allocator, sizeof(axis2_svc_grp_t));

    if (! svc_grp)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svc_grp->param_container = NULL;
    svc_grp->module_qnames = NULL;
    svc_grp->svcs = NULL;
    svc_grp->parent = NULL;
    svc_grp->svc_grp_name = NULL;
    svc_grp->module_list = NULL;

    svc_grp->param_container =  axutil_param_container_create(env);
    if (!svc_grp->param_container)
    {
        axis2_svc_grp_free(svc_grp, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svc_grp->module_qnames = axutil_array_list_create(env, 20);
    if (!svc_grp->module_qnames)
    {
        axis2_svc_grp_free(svc_grp, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svc_grp->module_list = axutil_array_list_create(env, 0);
    if (!svc_grp->module_list)
    {
        axis2_svc_grp_free(svc_grp, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svc_grp->svcs = axutil_hash_make(env);
    if (!svc_grp->svcs)
    {
        axis2_svc_grp_free(svc_grp, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return svc_grp;
}

AXIS2_EXTERN axis2_svc_grp_t *AXIS2_CALL
axis2_svc_grp_create_with_conf(
    const axutil_env_t *env,
    axis2_conf_t *conf)
{
    axis2_svc_grp_t *svc_grp = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, conf, NULL);

    svc_grp = (axis2_svc_grp_t *) axis2_svc_grp_create(env);
    if (svc_grp)
        svc_grp->parent = conf;

    return svc_grp;

}

AXIS2_EXTERN void AXIS2_CALL
axis2_svc_grp_free(
    axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (svc_grp->param_container)
    {
        axutil_param_container_free(svc_grp->param_container,
                env);
    }

    if (svc_grp->svc_grp_name)
    {
        AXIS2_FREE(env->allocator, svc_grp->svc_grp_name);
    }

    if (svc_grp->svcs)
    {
        /* services are freed by arch_file_data */
        axutil_hash_free(svc_grp->svcs, env);
    }

    if (svc_grp->module_qnames)
    {
        axutil_array_list_free(svc_grp->module_qnames, env);
    }

    if (svc_grp->module_list)
    {
        axutil_array_list_free(svc_grp->module_list, env);
    }

    if (svc_grp)
    {
        AXIS2_FREE(env->allocator, svc_grp);
    }
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_set_name(
    axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    const axis2_char_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc_grp->svc_grp_name)
        AXIS2_FREE(env->allocator, svc_grp->svc_grp_name);
    svc_grp->svc_grp_name = axutil_strdup(env, name);
    if (!svc_grp->svc_grp_name)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_svc_grp_get_name(
    const axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env)
{
    return svc_grp->svc_grp_name;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_add_svc(
    axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    axis2_svc_t *svc)
{
    axis2_phase_resolver_t *handler_resolver = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    const axutil_qname_t *svc_qname = NULL;
    axis2_char_t *svc_name = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc, AXIS2_FAILURE);

    if (!svc_grp->svcs)
    {
        svc_grp->svcs = axutil_hash_make(env);
        if (!svc_grp->svcs)
            return AXIS2_FAILURE;
    }
    svc_qname = axis2_svc_get_qname(svc, env);
    svc_name = axutil_qname_to_string((axutil_qname_t *)svc_qname, env);
    axutil_hash_set(svc_grp->svcs, svc_name, AXIS2_HASH_KEY_STRING, svc);

    handler_resolver = axis2_phase_resolver_create_with_config_and_svc(env,
            svc_grp->parent, svc);

    if (!handler_resolver)
    {
        /* remove the previously added service */
        axutil_hash_set(svc_grp->svcs, svc_name, AXIS2_HASH_KEY_STRING,
                NULL);

        return AXIS2_FAILURE;
    }

    status = axis2_phase_resolver_build_chains(handler_resolver, env);
    if (AXIS2_SUCCESS != status)
    {
        /* remove the previously added service */
        axutil_hash_set(svc_grp->svcs, svc_name, AXIS2_HASH_KEY_STRING, NULL);
        axis2_phase_resolver_free(handler_resolver, env);
        return status;
    }

    status = axis2_svc_set_last_update(svc, env);
    if (AXIS2_SUCCESS != status)
    {
        /* remove the previously added service */
        axutil_hash_set(svc_grp->svcs, svc_name, AXIS2_HASH_KEY_STRING, NULL);
        axis2_phase_resolver_free(handler_resolver, env);
        return status;
    }

    status = axis2_svc_set_parent(svc, env, svc_grp);
    if (AXIS2_SUCCESS != status)
    {
        /* remove the previously added service */
        axutil_hash_set(svc_grp->svcs, svc_name, AXIS2_HASH_KEY_STRING, NULL);
        axis2_phase_resolver_free(handler_resolver, env);
        return status;
    }

    axis2_phase_resolver_free(handler_resolver, env);
    return status;
}

AXIS2_EXTERN axis2_svc_t *AXIS2_CALL
axis2_svc_grp_get_svc(
    const axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    const axutil_qname_t *qname)
{
    axis2_char_t *name = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, qname, NULL);

    name = axutil_qname_to_string((axutil_qname_t *)qname, env);
    return (axis2_svc_t *) axutil_hash_get(svc_grp->svcs, name,
            AXIS2_HASH_KEY_STRING);
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_svc_grp_get_all_svcs(
    const axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env)
{
    return svc_grp->svcs;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_remove_svc(
    axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    const axutil_qname_t *svc_qname)
{
    axis2_svc_t *svc = NULL;
    axis2_char_t *svc_name = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc_name, AXIS2_FAILURE);

    svc = axis2_svc_grp_get_svc(svc_grp, env, svc_qname);

    svc_name = axutil_qname_to_string((axutil_qname_t *)svc_qname, env);
    axutil_hash_set(svc_grp->svcs, svc_name,
            AXIS2_HASH_KEY_STRING, NULL);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_add_param(
    axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    axutil_param_t *param)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, param, AXIS2_FAILURE);

    if (AXIS2_TRUE == axis2_svc_grp_is_param_locked(svc_grp, env,
            axutil_param_get_name(param, env)))
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_PARAMETER_LOCKED_CANNOT_OVERRIDE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    else
    {
        return axutil_param_container_add_param(svc_grp->param_container, env, param);
    }

    return AXIS2_FAILURE;
}

AXIS2_EXTERN axutil_param_t *AXIS2_CALL
axis2_svc_grp_get_param(
    const axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    const axis2_char_t *name)
{
    axutil_param_t *param = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, name, NULL);

    param = axutil_param_container_get_param(svc_grp->param_container, env, name);
    if (param == NULL && svc_grp->parent)
    {
        param =  axis2_conf_get_param(svc_grp->parent, env, name);
    }
    return param;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_svc_grp_get_all_params(
    const axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return axutil_param_container_get_params(svc_grp->param_container, env);
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_svc_grp_is_param_locked(
    axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    const axis2_char_t *param_name)
{
    axis2_bool_t locked = AXIS2_FALSE;
    axis2_conf_t *parent = NULL;
    axutil_param_t *param = NULL;
    axis2_bool_t ret = AXIS2_FALSE;

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, param_name, AXIS2_FALSE);

    parent = axis2_svc_grp_get_parent(svc_grp, env);
    /* checking the locked value of parent */
    if (parent)
    {
        locked =   axis2_conf_is_param_locked(parent, env, param_name);
    }
    if (AXIS2_TRUE == locked)
    {
        ret = AXIS2_TRUE;
    }
    param = axis2_svc_grp_get_param(svc_grp, env, param_name);
    if (param && AXIS2_TRUE == axutil_param_is_locked(param, env))
    {
        ret = AXIS2_TRUE;
    }
    else
    {
        ret = AXIS2_FALSE;
    }
    return ret;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_add_module_qname(
    axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    const axutil_qname_t *module_qname)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return axutil_array_list_add(svc_grp->module_qnames, env,
            module_qname);
}

AXIS2_EXTERN axis2_conf_t *AXIS2_CALL
axis2_svc_grp_get_parent(
    const axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env)
{
    return svc_grp->parent;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_set_parent(
    axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    axis2_conf_t *parent)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, parent, AXIS2_FAILURE);

    if (svc_grp->parent)
         axis2_conf_free(svc_grp->parent, env);
    svc_grp->parent = parent;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_engage_module(
    axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    const axutil_qname_t *module_name)
{
    int i = 0;
    axis2_status_t status = AXIS2_FAILURE;
    axutil_qname_t *modu = NULL;
    axis2_char_t *modu_local = NULL;
    axis2_char_t *module_name_local = NULL;
    axutil_hash_t *svc_map = NULL;
    axis2_phase_resolver_t *phase_resolver = NULL;
    axis2_module_desc_t *module = NULL;

    int size = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_name, AXIS2_FAILURE);

    size = axutil_array_list_size(svc_grp->module_qnames, env);
    if (AXIS2_TRUE != AXIS2_ERROR_GET_STATUS_CODE(env->error))
    {
        return AXIS2_FAILURE;
    }
    for (i = 0; size; i++)
    {
        modu = axutil_array_list_get(svc_grp->module_qnames, env, i);
        modu_local = axutil_qname_get_localpart(modu, env);
        module_name_local = axutil_qname_get_localpart(module_name, env);
        if (0 == axutil_strcmp(modu_local, module_name_local))
        {
            AXIS2_ERROR_SET(env->error,
                    AXIS2_ERROR_MODULE_ALREADY_ENGAGED_TO_SVC_GRP, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    svc_map = axis2_svc_grp_get_all_svcs(svc_grp, env);
    if (!svc_map)
    {
        return AXIS2_FAILURE;
    }

    phase_resolver = axis2_phase_resolver_create_with_config(env, svc_grp->
            parent);

    if (!phase_resolver)
    {
        return AXIS2_FAILURE;
    }

    module =  axis2_conf_get_module(svc_grp->parent, env, module_name);
    if (module)
    {
        axis2_svc_t *axis_svc = NULL;
        axutil_hash_index_t *index = NULL;

        index = axutil_hash_first(svc_map, env);
        while (index)
        {
            void *v = NULL;
            /* engage in per each service */
            axutil_hash_this(index, NULL, NULL, &v);
            axis_svc = (axis2_svc_t *) v;
            status = axis2_phase_resolver_engage_module_to_svc(phase_resolver,
                    env, axis_svc, module);
            if (!status)
            {
                if (phase_resolver)
                {
                    axis2_phase_resolver_free(phase_resolver, env);
                }
                return status;
            }
            index = axutil_hash_next(env, index);
        }
    }
    if (phase_resolver)
    {
        axis2_phase_resolver_free(phase_resolver, env);
    }

    return axis2_svc_grp_add_module_qname(svc_grp, env, module_name);
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_svc_grp_get_all_module_qnames(
    const axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env)
{
    return svc_grp->module_qnames;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_add_module_ref(
    axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    const axutil_qname_t *moduleref)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, moduleref, AXIS2_FAILURE);

    if (!svc_grp->module_list)
    {
        svc_grp->module_list = axutil_array_list_create(env, 0);
        if (!svc_grp->module_list)
            return AXIS2_FAILURE;
    }
    return axutil_array_list_add(svc_grp->module_list, env, moduleref);
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_svc_grp_get_all_module_refs(
    const axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env)
{
    return svc_grp->module_list;
}

AXIS2_EXTERN axis2_svc_grp_ctx_t *AXIS2_CALL
axis2_svc_grp_get_svc_grp_ctx(
    const axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env,
    axis2_conf_ctx_t *parent)
{
    axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, parent, NULL);

    svc_grp_ctx = axis2_svc_grp_ctx_create(env, (axis2_svc_grp_t *) svc_grp, parent);
    if (!svc_grp_ctx)
    {
        return NULL;
    }
    return svc_grp_ctx;
}

AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
axis2_svc_grp_get_param_container(const axis2_svc_grp_t *svc_grp,
    const axutil_env_t *env)
{
    return svc_grp->param_container;
}


