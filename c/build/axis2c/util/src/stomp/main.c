#include <stdlib.h>
#include "axutil_stomp_frame.h"
#include "axutil_stomp.h"


int
main (int argc, char *argv[])
{
  const axutil_env_t *env;
  axutil_stream_t *stream;
  axis2_status_t rc;
  int len = 0;
  axis2_char_t buffer[500];
  axis2_socket_t socket;
  axis2_char_t *command;
  axis2_char_t *header;
  axis2_char_t *body;

  axutil_stomp_frame_t *frame;
  axutil_stomp_t *stomp;

  env = axutil_env_create_all ("stomp.log", AXIS2_LOG_LEVEL_DEBUG);
  stomp = axutil_stomp_create (env, "localhost", 61613);

  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_CONNECT);
  axutil_stomp_set_header (stomp, env, "dinesh", "123");
  axutil_stomp_write (stomp, env);

  frame = axutil_stomp_frame_read (env, stomp->stream);
  if (frame && frame->command)
    printf ("%s\n", frame->command);

  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_SUBSCRIBE);
  axutil_stomp_set_header (stomp, env, "destination", "/queue/test.q");
  axutil_stomp_write (stomp, env);

  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_SEND);
  axutil_stomp_set_header (stomp, env, "destination", "/queue/test.q");
  axutil_stomp_set_body (stomp, env, "This is a test for Axi2/C stop client");
  axutil_stomp_write (stomp, env);

  frame = axutil_stomp_frame_read (env, stomp->stream);
  if (frame && frame->body)
    printf ("%s\n", frame->body);


  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_DISCONNECT);
  axutil_stomp_write (stomp, env);

  return 0;
}
