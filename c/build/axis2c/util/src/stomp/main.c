#include <stdlib.h>
#include "axutil_stomp_frame.h"
#include "axutil_stomp.h"
#include <ctype.h>

int
main (int argc, char *argv[])
{
  const axutil_env_t *env;
  axutil_stream_t *stream;
  axis2_status_t rc;
  int len = 0;
  axis2_char_t buffer[500];
  axis2_char_t buff[50000];
  axis2_socket_t socket;
  axis2_char_t *command = NULL;
  axis2_char_t *header = NULL;
  axis2_char_t *body = NULL;
  FILE *file;

  if (argv[1])
  {
      file = fopen (argv[1], "r");
      if (argv[2])
          fread (buff, atoi(argv[2]), 1, file);
      else
      fread (buff, 100, 1, file);
  }
  else
  {
      file = fopen ("x", "r");
      fread (buff, 100, 1, file);
  }

  buff[strlen(buff)] = 0;
  axutil_stomp_frame_t *frame = NULL;
  axutil_stomp_t *stomp = NULL;

  env = axutil_env_create_all ("stomp.log", AXIS2_LOG_LEVEL_DEBUG);
  stomp = axutil_stomp_create (env, "localhost", 61613);

  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_CONNECT);
  axutil_stomp_set_header (stomp, env, "login", "dinesh");
  axutil_stomp_set_header (stomp, env, "passcode", "123");
  axutil_stomp_set_header (stomp, env, "persistent", "true");
  axutil_stomp_write (stomp, env);

  frame = axutil_stomp_frame_read (env, stomp->stream);
  if (frame && frame->command)
    printf ("%s\n", frame->command);

  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_SUBSCRIBE);
  axutil_stomp_set_header (stomp, env, "destination", "/topic/test.q");
  axutil_stomp_write (stomp, env);

  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_SEND); 
  axutil_stomp_set_header (stomp, env, "destination", "/topic/test.q"); 
  axutil_stomp_set_body (stomp, env, buff);
  axutil_stomp_write (stomp, env); 

  frame = axutil_stomp_frame_read (env, stomp->stream);
  if (frame && frame->body)
    printf ("%s\n", frame->body);
  fflush (stdout);


  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_DISCONNECT);
  axutil_stomp_write (stomp, env);

  return 0;
}
