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
#include <axutil_env.h>
#include <axis2_engine.h>
#include <axis2_conf_ctx.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_builder.h>

int   axis2_test_engine_send()
{
    axis2_status_t status = AXIS2_FAILURE;
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    const axutil_env_t *env = axutil_env_create(allocator);
    struct axis2_conf *conf = NULL;
    conf = axis2_conf_create(env);

    struct axis2_conf_ctx *conf_ctx;
    struct axis2_msg_ctx *msg_ctx;
    struct axis2_op_ctx *op_ctx;
    struct axis2_op *op;
    struct axis2_svc *svc;
    struct axis2_svc_ctx *svc_ctx;
    struct axis2_svc_grp *svc_grp;
    struct axis2_svc_grp_ctx *svc_grp_ctx;
    struct axutil_qname *qname;

    conf_ctx = axis2_conf_ctx_create(env, conf);

    svc_grp = axis2_svc_grp_create(env);
    svc_grp_ctx = axis2_svc_grp_ctx_create(env, svc_grp, conf_ctx);

    qname = axutil_qname_create(env, "name1", NULL, NULL);
    svc = axis2_svc_create_with_qname(env, qname);
    svc_ctx = axis2_svc_ctx_create(env, svc, svc_grp_ctx);

    op  = axis2_op_create(env);
    op_ctx = axis2_op_ctx_create(env, op, svc_ctx);

    msg_ctx = axis2_msg_ctx_create(env, conf_ctx, NULL, NULL);

     axis2_msg_ctx_set_conf_ctx(msg_ctx, env, conf_ctx);
     axis2_msg_ctx_set_op_ctx(msg_ctx, env, op_ctx);
     axis2_msg_ctx_set_svc_ctx(msg_ctx, env, svc_ctx);

    axis2_engine_t *engine = axis2_engine_create(env, conf_ctx);
    status = axis2_engine_send(engine, env, msg_ctx);
    if (status != AXIS2_SUCCESS)
    {
        printf("axis2_test_engine_send ERROR %d\n", status);
    }
    else
        printf("axis2_test_engine_send SUCCESS\n");

     axis2_conf_ctx_free(conf_ctx, env);
     axis2_msg_ctx_free(msg_ctx, env);
    axutil_qname_free(qname, env);
     axis2_svc_grp_ctx_free(svc_grp_ctx, env);
     axis2_svc_ctx_free(svc_ctx, env);
    axis2_svc_free(svc, env);
     axis2_op_ctx_free(op_ctx, env);
    axis2_op_free(op, env);
     axis2_engine_free(engine, env);
    return 0;
}

int   axis2_test_engine_receive()
{
    axis2_status_t status = AXIS2_FAILURE;
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    const axutil_env_t *env = axutil_env_create(allocator);
    axis2_conf_t *conf = NULL;
    conf = axis2_conf_create(env);

    struct axis2_conf_ctx *conf_ctx;
    struct axis2_msg_ctx *msg_ctx;
    conf_ctx = axis2_conf_ctx_create(env, conf);

    msg_ctx = axis2_msg_ctx_create(env, conf_ctx, NULL, NULL);

    axis2_engine_t *engine = axis2_engine_create(env, conf_ctx);

    status =  axis2_engine_receive(engine, env, msg_ctx);
    if (status != AXIS2_SUCCESS)
    {
        printf("axis2_test_engine_receive ERROR %d\n", status);
    }
    else
        printf("axis2_test_engine_receive SUCCESS\n");
     axis2_conf_ctx_free(conf_ctx, env);
     axis2_msg_ctx_free(msg_ctx, env);
     axis2_engine_free(engine, env);
    return 0;
}


int main()
{
    axis2_test_engine_send();
    axis2_test_engine_receive();
    return 0;
}
