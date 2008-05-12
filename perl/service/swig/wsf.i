%module "WSO2::WSF::Server"

%{
#include "wsf.h"
#include "wsf_xml_msg_recv.h"
#include "wsf_worker.h"
%}

%include "cpointer.i"
%include "typemaps.i"
%include "wsf_defs.h"

typedef char axis2_char_t;
typedef int axis2_bool_t;
typedef int axis2_status_t;
typedef int axis2_scope_t;
typedef unsigned int axis2_ssize_t;
typedef char axis2_byte_t;

%inline %{
    char*
        wsf_axutil_strdup (const axutil_env_t* env,
                           const char* ptr)
    {
        return (char*)axutil_strdup (env, (void*)ptr);
    }
%}

void 
wsf_init (axis2_char_t* path_to_log,
          int log_level);

axutil_env_t*
wsf_env_create (axis2_char_t* path_to_log,
                int log_level);

axis2_msg_recv_t*
wsf_xml_msg_recv_create (const axutil_env_t* env);

axis2_status_t 
axiom_xml_reader_init ();

wsf_worker_t* 
wsf_worker_create (const axutil_env_t* env,
                   axis2_char_t* repo_path);

wsf_worker_t *
wsf_get_worker();

axis2_conf_ctx_t* 
wsf_worker_get_conf_ctx (wsf_worker_t* worker,
                         const axutil_env_t* env);

int
wsf_worker_process_request (wsf_worker_t* worker,
                            axutil_env_t* env,
                            wsf_req_info_t* request,
                            wsf_svc_info_t* svc_info);

axutil_env_t *
wsf_get_env ();
