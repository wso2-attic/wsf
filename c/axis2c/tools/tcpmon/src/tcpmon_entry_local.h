#include <axutil_env.h>
#include "tcpmon_entry.h"
#include "tcpmon_session_local.h"

typedef struct tcpmon_entry_request_data
{
    const axutil_env_t* env;
    int socket;
    tcpmon_session_t* session;
} tcpmon_entry_request_data_t;

void* AXIS2_CALL tcpmon_entry_new_entry_funct(axutil_thread_t *thd, void* data);

