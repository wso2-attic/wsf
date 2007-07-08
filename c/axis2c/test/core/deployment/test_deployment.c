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
#include <axis2_op.h>
#include <axis2_module_desc.h>
#include <axis2_phases_info.h>
#include <stdio.h>
#include <axis2_op.h>
#include <axis2_dep_engine.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_class_loader.h>
#include <axutil_error_default.h>
#include <axutil_log_default.h>
#include <axis2_transport_sender.h>
#include <axis2_transport_receiver.h>
#include <axis2_core_utils.h>

const axutil_env_t *env = NULL;

int axis2_test_dep_engine_load()
{
    axis2_dep_engine_t *dep_engine = NULL;
    axis2_conf_t *conf = NULL;
    axutil_hash_t *svc_map = NULL;
    axutil_array_list_t *in_phases = NULL;
    axis2_char_t *axis2c_home = NULL;

    printf("******************************************\n");
    printf("testing dep_engine_load method \n");
    printf("******************************************\n");


    axis2c_home = AXIS2_GETENV("AXIS2C_HOME");
    dep_engine = axis2_dep_engine_create_with_repos_name(env,
            axis2c_home);
    if (!dep_engine)
    {
        printf("dep engine is not created \n");
        return -1;
    }
    conf = axis2_dep_engine_load(dep_engine, env);
     axis2_conf_set_dep_engine(conf, env, dep_engine);
    if (!conf)
    {
        printf("conf is NULL\n)");
        return -1;
    }

    svc_map =  axis2_conf_get_all_svcs(conf, env);
    if (svc_map)
        printf("svc_map count = %d\n", axutil_hash_count(svc_map));
    else
        printf("svc_map count = zero\n");

    if (svc_map)
    {
        axutil_hash_index_t *hi = NULL;
        void *service = NULL;
        for (hi = axutil_hash_first(svc_map, env);
                hi; hi = axutil_hash_next(env, hi))
        {
            axutil_hash_t *ops = NULL;
            axis2_svc_t *svc = NULL;
            axutil_param_t *impl_info_param = NULL;

            axutil_hash_this(hi, NULL, NULL, &service);
            svc = (axis2_svc_t *) service;
            impl_info_param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_CLASS);
            if (!impl_info_param)
            {
                printf("imple_info_param is null\n");
            }
            ops = axis2_svc_get_all_ops(svc, env);
            if (ops)
            {
                printf("ops count = %d\n", axutil_hash_count(ops));

                axutil_hash_index_t *hi2 = NULL;
                void *op = NULL;
                axis2_char_t *oname = NULL;

                for (hi2 = axutil_hash_first(ops, env); hi2; hi2 = axutil_hash_next(env, hi2))
                {
                    if (!hi2)
                        break;
                    axutil_hash_this(hi2, NULL, NULL, &op);
                    if (op)
                    {
                        const axutil_qname_t *qname = NULL;
                        qname = axis2_op_get_qname((axis2_op_t *)op, env);
                        oname = axutil_qname_get_localpart(qname, env);
                        printf("op name = %s\n", oname);
                    }
                }
            }
            else
                printf("ops count = zero\n");
        }
    }

    in_phases =
         axis2_conf_get_in_phases_upto_and_including_post_dispatch(
            conf, env);
    if (!in_phases)
    {
        printf("in phases up to and including post dispatch is NULL\n");
    }
    else
    {
        printf("dep engine load is successfull\n");
    }
     axis2_conf_free(conf, env);

    return 0;
}

int axis2_test_transport_receiver_load()
{
    axutil_dll_desc_t *dll_desc = NULL;
    axis2_char_t *dll_name = NULL;
    axis2_transport_receiver_t *transport_recv = NULL;
    axutil_param_t *impl_info_param = NULL;
    axis2_bool_t is_running = AXIS2_FALSE;
    axis2_char_t *axis2c_home = NULL;

    printf("******************************************\n");
    printf("testing axis2_transport_recv load\n");
    printf("******************************************\n");

    dll_desc = axutil_dll_desc_create(env);

    axis2c_home = AXIS2_GETENV("AXIS2C_HOME");
    dll_name = axutil_stracat(env, axis2c_home, "/lib/libaxis2_http_receiver.so");
    printf("transport receiver name:%s\n", dll_name);
     axutil_dll_desc_set_name(dll_desc, env, dll_name);
     axutil_dll_desc_set_type(dll_desc, env, AXIS2_TRANSPORT_RECV_DLL);
    impl_info_param = axutil_param_create(env, NULL, NULL);
    axutil_param_set_value(impl_info_param, env, dll_desc);
    axutil_class_loader_init(env);
    transport_recv = (axis2_transport_receiver_t *) axutil_class_loader_create_dll(env,
            impl_info_param);
    is_running = axis2_transport_receiver_is_running(transport_recv, env);
    printf("is_running:%d\n", is_running);
    AXIS2_FREE(env->allocator, dll_name);
    printf("transport receiver load test successful\n");
    return 0;
}

int axis2_test_transport_sender_load()
{
    axutil_dll_desc_t *dll_desc = NULL;
    axis2_char_t *dll_name = NULL;
    axis2_transport_sender_t *transport_sender = NULL;
    axutil_param_t *impl_info_param = NULL;
    axis2_char_t *axis2c_home = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;

    printf("******************************************\n");
    printf("testing axis2_transport_sender load\n");
    printf("******************************************\n");

    msg_ctx = (axis2_msg_ctx_t *) AXIS2_MALLOC(env->allocator, 5);
    dll_desc = axutil_dll_desc_create(env);

    axis2c_home = AXIS2_GETENV("AXIS2C_HOME");
    dll_name = axutil_stracat(env, axis2c_home, "/lib/libaxis2_http_sender.so");
    printf("transport sender name:%s\n", dll_name);
     axutil_dll_desc_set_name(dll_desc, env, dll_name);
     axutil_dll_desc_set_type(dll_desc, env, AXIS2_TRANSPORT_SENDER_DLL);
    impl_info_param = axutil_param_create(env, NULL, NULL);
    axutil_param_set_value(impl_info_param, env, dll_desc);
    axutil_class_loader_init(env);
    transport_sender = (axis2_transport_sender_t *) axutil_class_loader_create_dll(env,
            impl_info_param);

    AXIS2_FREE(env->allocator, dll_name);
    printf("transport sender load test successful\n");
    return 0;
}

int axis2_test_default_module_version()
{

    axis2_conf_t *axis_conf = NULL;
    axutil_qname_t *mod_qname1 = NULL;
    axutil_qname_t *mod_qname2 = NULL;
    axutil_qname_t *mod_qname3 = NULL;
    axutil_qname_t *mod_qname4 = NULL;
    axutil_qname_t *mod_qname5 = NULL;
    axis2_module_desc_t *module1 = NULL;
    axis2_module_desc_t *module2 = NULL;
    axis2_module_desc_t *module3 = NULL;
    axis2_module_desc_t *module4 = NULL;
    axis2_module_desc_t *module5 = NULL;
    axis2_module_desc_t *def_mod = NULL;
    axutil_array_list_t *engaged_modules = NULL;
    axutil_qname_t *engage_qname = NULL;
    axis2_bool_t found1 = AXIS2_FALSE;
    axis2_bool_t found2 = AXIS2_FALSE;
    axis2_bool_t found3 = AXIS2_FALSE;

    printf("******************************************\n");
    printf("testing axis2_default_module_version\n");
    printf("******************************************\n");


    axis_conf = axis2_conf_create(env);
    mod_qname1 = axutil_qname_create(env, "module1", NULL, NULL);
    module1 = axis2_module_desc_create_with_qname(env, mod_qname1);
     axis2_conf_add_module(axis_conf, env, module1);

    mod_qname2 = axutil_qname_create(env, "module2-0.90", NULL, NULL);
    module2 = axis2_module_desc_create_with_qname(env, mod_qname2);
     axis2_conf_add_module(axis_conf, env, module2);

    mod_qname3 = axutil_qname_create(env, "module2-0.92", NULL, NULL);
    module3 = axis2_module_desc_create_with_qname(env, mod_qname3);
     axis2_conf_add_module(axis_conf, env, module3);

    mod_qname4 = axutil_qname_create(env, "module2-0.91", NULL, NULL);
    module4 = axis2_module_desc_create_with_qname(env, mod_qname4);
     axis2_conf_add_module(axis_conf, env, module4);

    mod_qname5 = axutil_qname_create(env, "test_module-1.92", NULL, NULL);
    module5 = axis2_module_desc_create_with_qname(env, mod_qname5);
     axis2_conf_add_module(axis_conf, env, module5);

    axis2_core_utils_calculate_default_module_version(env,  axis2_conf_get_all_modules(
                axis_conf, env), axis_conf);
    def_mod =  axis2_conf_get_default_module(axis_conf, env, "module1");
    if (def_mod != module1)
    {
        printf("axis2_default_module_version (module1) .. FAILED\n");
        return AXIS2_FAILURE;
    }
    def_mod =  axis2_conf_get_default_module(axis_conf, env, "module2");
    if (def_mod != module3)
    {
        printf("axis2_default_module_version (module2) .. FAILED\n");
        return AXIS2_FAILURE;
    }
    def_mod =  axis2_conf_get_default_module(axis_conf, env, "test_module");
    if (def_mod != module5)
    {
        printf("axis2_default_module_version (test_module) .. FAILED\n");
        return AXIS2_FAILURE;
    }
    engage_qname = axutil_qname_create(env, "module2", NULL, NULL);
     axis2_conf_engage_module(axis_conf, env, engage_qname);
    axutil_qname_free(engage_qname, env);
    engage_qname = NULL;

    engage_qname = axutil_qname_create(env, "module1", NULL, NULL);
     axis2_conf_engage_module(axis_conf, env, engage_qname);
    axutil_qname_free(engage_qname, env);
    engage_qname = NULL;

     axis2_conf_engage_module_with_version(axis_conf, env, "test_module", "1.92");

    engaged_modules =  axis2_conf_get_all_engaged_modules(axis_conf, env);

    if (engaged_modules)
    {
        int list_size = 0;
        int i = 0;
        list_size = axutil_array_list_size(engaged_modules, env);
        for (i = 0; i < list_size; i++)
        {
            axutil_qname_t *engaged_mod_qname = NULL;
            engaged_mod_qname = axutil_array_list_get(engaged_modules, env, i);
            if (0 == axutil_strcmp("module2-0.92",
                    axutil_qname_get_localpart(engaged_mod_qname, env)))
            {
                found1 = AXIS2_TRUE;
            }
            if (0 == axutil_strcmp("module1",
                    axutil_qname_get_localpart(engaged_mod_qname, env)))
            {
                found2 = AXIS2_TRUE;
            }
            if (0 == axutil_strcmp("test_module-1.92",
                    axutil_qname_get_localpart(engaged_mod_qname, env)))
            {
                found3 = AXIS2_TRUE;
            }

        }
    }
    if (AXIS2_FALSE == found1)
    {
        printf("axis2_default_module_version (module2 engaging) .. FAILED\n");
        return AXIS2_FAILURE;
    }
    if (AXIS2_FALSE == found2)
    {
        printf("axis2_default_module_version (module1 engaging) .. FAILED\n");
        return AXIS2_FAILURE;
    }
    if (AXIS2_FALSE == found3)
    {
        printf("axis2_default_module_version (test_module engaging) .. FAILED\n");
        return AXIS2_FAILURE;
    }
    printf("axis2_default_module_version  .. SUCCESS\n");
     axis2_conf_free(axis_conf, env);
    return AXIS2_SUCCESS;
}

int main()
{
    axutil_allocator_t *allocator = NULL;
    axutil_error_t *error = NULL;
    axutil_log_t *log = NULL;

    allocator = axutil_allocator_init(NULL);
    error = axutil_error_create(allocator);
    log = axutil_log_create(allocator, NULL, "test_deployment.log");
    env = axutil_env_create_with_error_log(allocator, error, log);
    env->log->level = AXIS2_LOG_LEVEL_INFO;
    /*axis2_test_transport_receiver_load();
    axis2_test_transport_sender_load();*/
    axis2_test_dep_engine_load();
    axis2_test_default_module_version();
    return 0;
}
