#include <tcpmon_session.h>
#include <tcpmon_entry.h>

axis2_status_t
tcpmon_session_add_new_entry( tcpmon_session_t* session,
                              const axutil_env_t* env, tcpmon_entry_t* entry);

TCPMON_SESSION_TRANS_ERROR_FUNCT
tcpmon_session_get_on_trans_fault (tcpmon_session_t *session,
                        const axutil_env_t *env );

TCPMON_SESSION_NEW_ENTRY_FUNCT
tcpmon_session_get_on_new_entry (tcpmon_session_t *session,
                        const axutil_env_t *env );
