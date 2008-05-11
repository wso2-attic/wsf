/*
 * Copyright 2005 - 2008 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "wsf.h"
#include "wsf_worker.h"
#include "wsf_util.h"

static axutil_env_t *env;
static int ws_is_svr;
axis2_msg_recv_t *wsf_msg_recv;
wsf_worker_t *worker;

void
wsf_init (const axis2_char_t *path_to_log,
          int log_level)
{
    axis2_char_t *repo_path = "/home/dinesh/wsf_c/deploy";
    env = wsf_env_create (path_to_log);
    if (!env)
    {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, 
                         "unable to create environment, given log path is %s \
and log level is %d", path_to_log, log_level);
        return;
    }
	env->log->level = log_level;

    wsf_msg_recv = (axis2_msg_recv_t* )wsf_xml_msg_recv_create (env);

    if (!wsf_msg_recv)
    {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
                         "wsf perl msg receiver creation failed \n");
        return;
    }
    axiom_xml_reader_init ();

    /* repo path need to be given for worker creation */
    worker = wsf_worker_create (env, 
                                repo_path);
    if (!worker)
    {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
                         "wsf perl worker creation failed for repo path %s", 
                         repo_path);
        return;
    }
    AXIS2_LOG_INFO (env->log, "wsf perl successfully initialized");
}

wsf_worker_t *
wsf_get_worker ()
{
    if (!worker)
        return NULL;
    return worker;
}


