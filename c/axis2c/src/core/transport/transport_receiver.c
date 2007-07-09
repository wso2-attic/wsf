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

#include <axis2_transport_receiver.h>

AXIS2_EXTERN void AXIS2_CALL 
axis2_transport_receiver_free(axis2_transport_receiver_t *transport_receiver,
    const axutil_env_t *env)
{
      (transport_receiver->ops)->free (transport_receiver, env);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_transport_receiver_init(axis2_transport_receiver_t *transport_receiver,
    const axutil_env_t *env,
    struct axis2_conf_ctx *conf_ctx,
    struct axis2_transport_in_desc *transport_in)
{
      return (transport_receiver->ops)->init (transport_receiver, env, 
          conf_ctx, transport_in);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axis2_transport_receiver_start(axis2_transport_receiver_t *transport_receiver,
    const axutil_env_t *env)
{
    return (transport_receiver->ops)->start (transport_receiver, env);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axis2_transport_receiver_stop(axis2_transport_receiver_t *transport_receiver,
    const axutil_env_t *env)
{
    return (transport_receiver->ops)->stop (transport_receiver, env);
}

AXIS2_EXTERN axis2_endpoint_ref_t* AXIS2_CALL 
axis2_transport_receiver_get_reply_to_epr(axis2_transport_receiver_t *transport_receiver,
    const axutil_env_t *env,
    const axis2_char_t *svc_name)
{
    return (transport_receiver->ops)->get_reply_to_epr (transport_receiver, env, svc_name);
}

AXIS2_EXTERN struct axis2_conf_ctx *AXIS2_CALL 
axis2_transport_receiver_get_conf_ctx(axis2_transport_receiver_t *transport_receiver,
    const axutil_env_t *env)
{
    return (transport_receiver)->ops->get_conf_ctx(transport_receiver, env);
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_transport_receiver_is_running(axis2_transport_receiver_t *transport_receiver,
    const axutil_env_t *env)
{
    return (transport_receiver)->ops->is_running(transport_receiver, env);
}

