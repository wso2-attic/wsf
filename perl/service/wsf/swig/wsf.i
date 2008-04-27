%module "WSO2::WSF::WSFC"

%{
#include "wsf.h"
#include "wsf_xml_msg_recv.h"
#include "wsf_worker.h"
%}

#%include "cpointer.i"
#%include "typemaps.i"

typedef char axis2_char_t;
typedef int axis2_bool_t;
typedef int axis2_status_t;
typedef int axis2_scope_t;
typedef unsigned int axis2_ssize_t;
typedef char axis2_byte_t;

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


%inline %{
    char*
        wsf_axutil_strdup (const axutil_env_t* env,
                           const char* ptr)
    {
        return (char*)axutil_strdup (env, (void*)ptr);
    }
%}


