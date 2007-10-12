#ifndef AXIS2_STOMP_FRAME_H
#define AXIS2_STOMP_FRAME_H

#include <axutil_network_handler.h>
#include <axutil_stream.h>
#include <axutil_array_list.h>
#include <axutil_env.h>
#include <axutil_utils.h>
#include <axutil_utils_defines.h>
#include <axutil_string.h>


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define AXIS2_STOMP_CONNECT "CONNECT"
#define AXIS2_STOMP_SUBSCRIBE "SUBSCRIBE"
#define AXIS2_STOMP_UNSUBSCRIBE "UNSUBSCRIBE"
#define AXIS2_STOMP_SEND "SEND"
#define AXIS2_STOMP_DISCONNECT "DISCONNECT"
#define AXIS2_STOMP_ACK "ACK"
#define AXIS2_STOMP_ABORT "ABORT"
#define AXIS2_STOMP_COMMIT "COMMIT"
    
    typedef struct axutil_stomp_frame 
    {
        axis2_char_t *command;
        axutil_array_list_t *headers;
        axis2_char_t *body;
    }axutil_stomp_frame_t;
    
    axutil_stomp_frame_t *
    axutil_stomp_frame_create (
        const axutil_env_t *env);

    void
    axutil_stomp_frame_free (
        axutil_stomp_frame_t *frame,
        const axutil_env_t *env);

    axis2_status_t
    axutil_stomp_frame_set_command (
        axutil_stomp_frame_t *frame,
        const axutil_env_t *env,
        axis2_char_t *command);
    
    axis2_status_t
    axutil_stomp_frame_set_header (
        axutil_stomp_frame_t *frame,
        const axutil_env_t *env,
        axis2_char_t *header,
        axis2_char_t *value);
    
    axis2_status_t 
    axutil_stomp_frame_set_body (
        axutil_stomp_frame_t *frame,
        const axutil_env_t *env,
        axis2_char_t *body);

    int
    axutil_stomp_frame_write (
        axutil_stomp_frame_t *frame,
        const axutil_env_t *env,
        axutil_stream_t *stream);

    axutil_stomp_frame_t *
    axutil_stomp_frame_read (
        const axutil_env_t *env,
        axutil_stream_t *stream);

    void
    axutil_stomp_frame_reset (
        axutil_stomp_frame_t *frame,
        const axutil_env_t *env);



#ifdef __cplusplus
}
#endif

#endif  /* AXIS2_STOMP_FRAME_H */





