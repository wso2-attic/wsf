
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


#include <ServiceSkeleton.h>
#include <stdio.h>
#include <axutil_env.h>
#include <Process.h>
#include "Echo.h"

using namespace wso2wsf;

OMElement* Echo::invoke(OMElement *ele, MessageContext *msgCtx)
{

}

OMElement* Echo::onFault(OMElement *ele)
{
	return NULL;
}

#ifdef __cplusplus
extern "C"
{
#endif

WSF_EXTERN int
axis2_get_instance(
				   ServiceSkeleton ** inst,
				   const axutil_env_t * env)
{
	*inst = new Echo();
	if (!(*inst))
	{
		return AXIS2_FAILURE;
	}

	return AXIS2_SUCCESS;
}

WSF_EXTERN int
axis2_remove_instance(
axis2_svc_skeleton_t * inst,
const axutil_env_t * env)
{
	axis2_status_t status = AXIS2_FAILURE;
	if (inst)
	{
		status = AXIS2_SVC_SKELETON_FREE(inst, env);
	}
	return status;
}

#ifdef __cplusplus
}
#endif