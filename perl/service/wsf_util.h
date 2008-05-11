#ifndef WSF_UTIL_H
#define WSF_UTIL_H

#include <axiom.h>
#include <axis2_svc.h>
#include <axis2_msg_recv.h>
#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_utils.h>
#include <axutil_string.h>
#include <axis2_conf_ctx.h>
#include <axiom_node.h>
#include <axis2_options.h>
#include <axutil_qname.h>
#include <axutil_log.h>

#include <axis2_conf.h>
#include <axutil_param.h>
#include <axis2_svc_ctx.h>
#include <axis2_desc.h>
#include <axis2_policy_include.h>

#include <axiom_document.h>
#include <axutil_utils_defines.h>
#include <axutil_param.h>
#ifdef WIN32
   #include "neethi_engine.h"
#endif
#include "neethi_options.h"
#include "wsf_defs.h"
#include "wsf_constants.h"

axutil_env_t*
wsf_env_create (const axis2_char_t *log_path);

axutil_env_t*
wsf_env_create_svr (const axis2_char_t *log_path);

#endif  /* WSF_UTIL_H */
