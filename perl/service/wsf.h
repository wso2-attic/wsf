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

#ifndef WSF_H
#define WSF_H

#include "axiom.h"
#include "axis2_svc.h"
#include "axis2_msg_recv.h"
#include "axis2_const.h"
#include "axis2_defines.h"
#include "axutil_env.h"
#include "axutil_utils.h"
#include "axutil_string.h"
#include "axis2_conf_ctx.h"
#include "axiom_node.h"
#include "axis2_options.h"
#include "axutil_qname.h"
#include "axutil_log.h"

#include "axis2_conf.h"
#include "axutil_param.h"
#include "axis2_svc_ctx.h"
#include "axis2_desc.h"
#include "axis2_policy_include.h"

#include "axiom_document.h"
#include "axutil_utils_defines.h"
#include "axutil_param.h"
#ifdef WIN32
   #include "neethi_engine.h"
#endif
#include "neethi_options.h"
#include "wsf_defs.h"
#include "wsf_constants.h"

/* To create WSFC environment */

axutil_env_t *wsf_env_create(axis2_char_t *path_to_log, int log_level);

#endif
