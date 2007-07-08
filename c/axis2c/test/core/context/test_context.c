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

#include <axis2_conf_ctx.h>
#include <axis2_svc_grp.h>
#include <axis2_const.h>
#include <axutil_allocator.h>
#include <axutil_env.h>
#include <stdio.h>

void axis2_test_conf_ctx_init()
{
    struct axis2_conf *conf = NULL;
    struct axis2_svc_grp_ctx *svc_grp_ctx1 = NULL;
    struct axis2_svc_grp_ctx *svc_grp_ctx2 = NULL;
    struct axis2_svc_grp *svc_grp1 = NULL;
    struct axis2_svc_grp *svc_grp2 = NULL;
    struct axis2_conf_ctx *conf_ctx = NULL;
    struct axis2_svc_ctx *svc_ctx1 = NULL;
    struct axis2_svc_ctx *svc_ctx2 = NULL;
    struct axis2_svc *svc1 = NULL;
    struct axis2_svc *svc2 = NULL;
    struct axutil_qname *qname1 = NULL;
    struct axutil_qname *qname2 = NULL;
    struct axis2_op_ctx *op_ctx1 = NULL;
    struct axis2_op_ctx *op_ctx2 = NULL;
    struct axis2_op *op = NULL;
    struct axutil_hash_t *op_ctx_map = NULL;
    struct axutil_hash_t *svc_ctx_map = NULL;
    struct axutil_hash_t *svc_grp_ctx_map = NULL;

    axis2_status_t status = AXIS2_FAILURE;
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    const axutil_env_t *env = axutil_env_create(allocator);

    conf = axis2_conf_create(env);

    op = axis2_op_create(env);

    conf_ctx = axis2_conf_ctx_create(env, conf);

    svc_grp1 = axis2_svc_grp_create(env);
    svc_grp2 = axis2_svc_grp_create(env);

    svc_grp_ctx1 = axis2_svc_grp_ctx_create(env, svc_grp1, conf_ctx);
    svc_grp_ctx2 = axis2_svc_grp_ctx_create(env, svc_grp2, conf_ctx);

    qname1 = axutil_qname_create(env, "name1", NULL, NULL);
    qname2 = axutil_qname_create(env, "name2", NULL, NULL);

    svc1 = axis2_svc_create_with_qname(env, qname1);
    svc2 = axis2_svc_create_with_qname(env, qname2);

    svc_ctx1 = axis2_svc_ctx_create(env, svc1, svc_grp_ctx1);
    svc_ctx2 = axis2_svc_ctx_create(env, svc2, svc_grp_ctx2);

    op = axis2_op_create(env);
    op_ctx1 = axis2_op_ctx_create(env, op, svc_ctx1);
    op_ctx2 = axis2_op_ctx_create(env, op, svc_ctx2);

    op_ctx_map =  axis2_conf_ctx_get_op_ctx_map(conf_ctx, env);

    if (op_ctx_map)
    {
        axutil_hash_set(op_ctx_map, "op_ctx1", AXIS2_HASH_KEY_STRING, op_ctx1);
        axutil_hash_set(op_ctx_map, "op_ctx2", AXIS2_HASH_KEY_STRING, op_ctx2);
    }

    svc_ctx_map =  axis2_conf_ctx_get_svc_ctx_map(conf_ctx, env);

    if (svc_ctx_map)
    {
        axutil_hash_set(svc_ctx_map, "svc_ctx1", AXIS2_HASH_KEY_STRING, svc_ctx1);
        axutil_hash_set(svc_ctx_map, "svc_ctx2", AXIS2_HASH_KEY_STRING, svc_ctx2);
    }

    svc_grp_ctx_map =  axis2_conf_ctx_get_svc_grp_ctx_map(conf_ctx, env);

    if (svc_grp_ctx_map)
    {
        axutil_hash_set(svc_ctx_map, "svc_grp_ctx1", AXIS2_HASH_KEY_STRING, svc_grp_ctx1);
        axutil_hash_set(svc_ctx_map, "svc_grp_ctx2", AXIS2_HASH_KEY_STRING, svc_grp_ctx2);
    }

    status =  axis2_conf_ctx_init(conf_ctx, env, conf);

    if (status != AXIS2_SUCCESS)
    {
        printf("ERROR %d\n", status);
    }
    else
        printf("SUCCESS\n");

     axis2_conf_ctx_free(conf_ctx, env);
}

int main()
{
    axis2_test_conf_ctx_init();
    return 0;
}
