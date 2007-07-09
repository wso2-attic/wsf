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

#include <axis2_msg_info_headers.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axis2_endpoint_ref.h>
#include <stdio.h>

int axis2_test_msg_info_headers()
{
    axis2_endpoint_ref_t *to = NULL;
    axis2_endpoint_ref_t *from = NULL;
    axis2_endpoint_ref_t *reply_to = NULL;
    axis2_endpoint_ref_t *fault_to = NULL;
    axis2_endpoint_ref_t *axis2_endpoint_ref = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_msg_info_headers_t *axis2_msg_info_headers = NULL;
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    const axutil_env_t *env = axutil_env_create(allocator);
    const axis2_char_t *action = "test action";
    const axis2_char_t *get_action = NULL;
    to = axis2_endpoint_ref_create(env, "to");
    from = axis2_endpoint_ref_create(env, "from");
    reply_to = axis2_endpoint_ref_create(env, "reply to");
    fault_to = axis2_endpoint_ref_create(env, "fault to");

    axis2_msg_info_headers = axis2_msg_info_headers_create(env, NULL, action);
    if (axis2_msg_info_headers)
        printf("SUCCESS axis2_msg_info_headers_create\n");
    else
    {
        printf("ERROR AXIS2_MSG_INFO_HEADERS_CREATE\n");
        return -1;
    }

    status = axis2_msg_info_headers_set_to(axis2_msg_info_headers, env, to);

    if (status == AXIS2_SUCCESS)
        printf("SUCCESS axis2_msg_info_headers_set_to\n");
    else
    {
        printf("ERROR axis2_msg_info_headers_set_to");
        return -1;
    }

    axis2_endpoint_ref = axis2_msg_info_headers_get_to(axis2_msg_info_headers, env);

    if (axis2_endpoint_ref)
        printf("SUCCESS axis2_msg_info_headers_get_to\n");
    else
    {
        printf("ERROR axis2_msg_info_headers_get_to\n");
        return -1;
    }

    status = AXIS2_FAILURE;
    status = axis2_msg_info_headers_set_from(axis2_msg_info_headers, env, from);

    if (status)
        printf("SUCCESS axis2_msg_info_headers_set_from\n");
    else
    {
        printf("ERROR axis2_msg_info_headers_set_from\n");
        return -1;
    }

    axis2_endpoint_ref = NULL;
    axis2_endpoint_ref = axis2_msg_info_headers_get_from(axis2_msg_info_headers, env);

    if (axis2_endpoint_ref)
        printf("SUCCESS axis2_msg_info_headers_get_from\n");
    else
    {
        printf("ERROR axis2_msg_info_headers_get_from\n");
        return -1;
    }



    axis2_endpoint_ref = NULL;
    axis2_endpoint_ref = axis2_msg_info_headers_get_reply_to(axis2_msg_info_headers, env);

    if (status)
        printf("SUCCESS axis2_msg_info_headers_get_reply_to\n");
    else
    {
        printf("ERROR axis2_msg_info_headers_get_reply_to\n");
        return -1;
    }

    status = AXIS2_FAILURE;
    status = axis2_msg_info_headers_set_reply_to(axis2_msg_info_headers, env, reply_to);

    if (status)
        printf("SUCCESS axis2_msg_info_headers_set_reply_to\n");
    else
    {
        printf("ERROR axis2_msg_info_headers_set_reply_to\n");
        return -1;
    }

    status = AXIS2_FAILURE;
    status = axis2_msg_info_headers_set_fault_to(axis2_msg_info_headers, env, fault_to);
    if (status)
        printf("SUCCESS axis2_msg_info_headers_set_fault_to\n");
    else
    {
        printf("ERROR axis2_msg_info_headers_set_fault_to\n");
        return -1;
    }

    axis2_endpoint_ref = NULL;
    axis2_endpoint_ref = axis2_msg_info_headers_get_fault_to(axis2_msg_info_headers, env);
    if (axis2_endpoint_ref)
        printf("SUCCESS axis2_msg_info_headers_get_fault_to\n");
    else
    {
        printf("ERROR axis2_msg_info_headers_get_fault_to\n");
        return -1;
    }


    get_action = axis2_msg_info_headers_get_action(axis2_msg_info_headers, env);
    if (get_action)
        printf("SUCCESS axis2_msg_info_headers_get_action\n");
    else
    {
        printf("ERROR axis2_msg_info_headers_get_action\n");
        return -1;
    }

    status = AXIS2_FAILURE;
    status = axis2_msg_info_headers_set_action(axis2_msg_info_headers, env, action);
    if (status)
        printf("SUCCESS axis2_msg_info_headers_set_action\n");
    else
    {
        printf("ERROR axis2_msg_info_headers_set_action\n");
    }


    status = AXIS2_FAILURE;
   /* status = axis2_msg_info_headers_free(axis2_msg_info_headers, env);*/
    if (status)
        printf("SUCCESS axis2_msg_info_headers_free\n");
    else
    {
        printf("ERROR axis2_msg_info_headers_free\n");
    }
    return 0;
}

int main()
{
    axis2_test_msg_info_headers();
    return 0;
}
