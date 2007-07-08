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
#include <axis2_conf.h>
#include <axis2_module_desc.h>
#include <axis2_phases_info.h>
#include <axutil_env.h>
#include <axutil_allocator.h>

struct axis2_module_desc *create_module_desc(const axutil_env_t *env);

int axis2_test_op_engage_module()
{
    struct axis2_module_desc *moduleref = NULL;
    axis2_conf_t *conf = NULL;

    axis2_status_t status = AXIS2_FAILURE;

    printf("******************************************\n");
    printf("testing axis2_op_engage_module\n");
    printf("******************************************\n");

    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    axutil_env_t *env = axutil_env_create(allocator);
    axis2_op_t *op = axis2_op_create(env);

    moduleref = axis2_module_desc_create(env);
    conf = axis2_conf_create(env);

    status = axis2_op_engage_module(op, env, moduleref, conf);
    moduleref = NULL;
    if (status != AXIS2_SUCCESS)
    {
        axis2_op_free(op, env);
        printf("ERROR %d\n", status);
    }

    axis2_op_free(op, env);
    axutil_env_free(env);
    return 0;
}

int axis2_test_svc_add_module_ops()
{
    struct axis2_svc *svc = NULL;
    struct axutil_qname *qname = NULL;
    struct axis2_module_desc *module_desc = NULL;
    struct axis2_conf *axis2_config = NULL;

    axis2_status_t status = AXIS2_FAILURE;


    printf("******************************************\n");
    printf("testing axis2_svc_add_module_ops\n");
    printf("******************************************\n");

    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    const axutil_env_t *env = axutil_env_create(allocator);
    qname = axutil_qname_create(env, "name1", NULL, NULL);
    svc = axis2_svc_create_with_qname(env, qname);
    module_desc = axis2_module_desc_create(env);
    axis2_config = axis2_conf_create(env);
    status = axis2_svc_add_module_ops(svc, env, module_desc, axis2_config);
    if (status != AXIS2_SUCCESS)
    {
        printf("axis2_test_description_add_module_ops ERROR %d\n", status);
    }
    else
        printf("axis2_test_add_module_ops SUCCESS\n");

    axis2_svc_free(svc, env);
    axutil_qname_free(qname, env);
    axis2_module_desc_free(module_desc, env);
     axis2_conf_free(axis2_config, env);

    return 0;
}

int axis2_test_svc_engage_module()
{
    axis2_svc_t *svc = NULL;
    axutil_qname_t *qname = NULL;
    axis2_module_desc_t *moduleref = NULL;
    axis2_conf_t *axis2_config = NULL;
    axis2_status_t status = AXIS2_FAILURE;


    printf("******************************************\n");
    printf("testing axis2_svc_engage_module\n");
    printf("******************************************\n");

    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    const axutil_env_t *env = axutil_env_create(allocator);
    qname = axutil_qname_create(env, "name1", NULL, NULL);
    svc = axis2_svc_create_with_qname(env, qname);
    moduleref = axis2_module_desc_create(env);
    axis2_config = axis2_conf_create(env);

    status = axis2_svc_engage_module(svc, env, moduleref, axis2_config);
    moduleref = NULL;
    if (status != AXIS2_SUCCESS)
    {
        printf("axis2_test_description_svc_engage_module ERROR %d\n", status);
    }
    else
        printf("axis2_test_svc_engage_module SUCCESS\n");

    axis2_svc_free(svc, env);
    axutil_qname_free(qname, env);
     axis2_conf_free(axis2_config, env);

    return 0;
}

int axis2_test_svc_get_op()
{
    struct axis2_svc *svc = NULL;
    struct axutil_qname *qname = NULL;
    struct axutil_hash_t *ops = NULL;
    struct axis2_op *op = NULL;
    axis2_status_t status = AXIS2_SUCCESS;


    printf("******************************************\n");
    printf("testing axis2_svc_get_op\n");
    printf("******************************************\n");

    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    const axutil_env_t *env = axutil_env_create(allocator);
    qname = axutil_qname_create(env, "op1", NULL, NULL);
    op = axis2_op_create_with_qname(env, qname);
    qname = axutil_qname_create(env, "svc1", NULL, NULL);
    svc = axis2_svc_create_with_qname(env, qname);

    status = axis2_svc_add_op(svc, env, op);

    qname = axutil_qname_create(env, "op2", NULL, NULL);
    op = axis2_op_create_with_qname(env, qname);
    status = axis2_svc_add_op(svc, env, op);

    ops = axis2_svc_get_all_ops(svc, env);

    if (ops)
        printf("SUCCESS AXIS2_SVC_GET_OPS\n");
    else
    {
        printf("ERROR AXIS2_SVC_GET_OPS\n");
        return -1;
    }

    if (ops)
    {
        printf("ops count = %d\n", axutil_hash_count(ops));

        axutil_hash_index_t *hi2 = NULL;
        void *op2 = NULL;
        axis2_char_t *oname = NULL;
        int count = 0;

        for (hi2 = axutil_hash_first(ops, env); hi2; hi2 = axutil_hash_next(env, hi2))
        {
            printf("count = %d \n", count++);
            axis2_svc_get_all_ops(svc, env);
            if (!(hi2))
                break;
            axutil_hash_this(hi2, NULL, NULL, &op2);
            if (op2)
            {
                const axutil_qname_t *qname = NULL;
                qname = axis2_op_get_qname((axis2_op_t *)op2, env);
                oname = axutil_qname_get_localpart(qname, env);
                printf("op name = %s\n", oname);
            }
        }
    }
    else
        printf("ops count = zero\n");


    return 0;
}

int main()
{
    axis2_test_op_engage_module();
    axis2_test_svc_add_module_ops();
    axis2_test_svc_engage_module();
    axis2_test_svc_get_op();
    return 0;
}
