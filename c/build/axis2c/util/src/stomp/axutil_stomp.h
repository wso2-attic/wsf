#ifndef AXIS2_STOMP_H
#define AXIS2_STOMP_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "axutil_stomp_frame.h"

    typedef struct axutil_stomp 
    {
        axutil_stomp_frame_t *frame;
        axutil_stream_t *stream;
        axis2_socket_t socket;
    }axutil_stomp_t;


    axutil_stomp_t *
    axutil_stomp_create (
        const axutil_env_t *env,
        char *host,
        int port);


    axis2_status_t
    axutil_stomp_set_command (
        axutil_stomp_t *stomp,
        const axutil_env_t *env,
        axis2_char_t *command);


    axis2_status_t
    axutil_stomp_set_body (
        axutil_stomp_t *stomp,
        const axutil_env_t *env,
        axis2_char_t *body);


    axis2_status_t
    axutil_stomp_set_header (
        axutil_stomp_t *stomp,
        const axutil_env_t *env,
        axis2_char_t *header,
        axis2_char_t *value);

    int 
    axutil_stomp_write (
        axutil_stomp_t *stomp,
        const axutil_env_t *env);

    axutil_stomp_frame_t *
    axutil_stomp_read (
        axutil_stomp_t *stomp,
        const axutil_env_t *env);

    void
    axutil_stomp_reset (
        axutil_stomp_t *stomp,
        const axutil_env_t *env);

    void 
    axutil_stomp_free (
        axutil_stomp_t *stomp,
        const axutil_env_t *env);





#ifdef __cplusplus
}
#endif

#endif  /* AXIS2_STOMP_H */





