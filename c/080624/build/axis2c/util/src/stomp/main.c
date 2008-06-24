#include <stdlib.h>
#include "axutil_stomp_frame.h"
#include "axutil_stomp.h"
#include <ctype.h>

int
main (int argc, char *argv[])
{
  const axutil_env_t *env;
  axis2_char_t buff[50000];
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

  axutil_stomp_t *stomp = NULL;

  env = axutil_env_create_all ("stomp.log", AXIS2_LOG_LEVEL_DEBUG);
  stomp = axutil_stomp_create (env, "localhost", 61613);

  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_CONNECT);
  axutil_stomp_set_header (stomp, env, "login", "dinesh");
  axutil_stomp_set_header (stomp, env, "passcode", "123");
  axutil_stomp_set_header (stomp, env, "persistent", "true");
  axutil_stomp_write (stomp, env);
  axutil_stomp_frame_reset (stomp->frame, env);

  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_SUBSCRIBE);
  axutil_stomp_set_header (stomp, env, "destination", "/queue/AutoBots");
  axutil_stomp_write (stomp, env);
  axutil_stomp_frame_reset (stomp->frame, env);

  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_SEND);
  axutil_stomp_set_header (stomp, env, "destination", "/queue/AutoBots");
  axutil_stomp_set_body (stomp, env, buff);
  axutil_stomp_write (stomp, env);
  axutil_stomp_frame_reset (stomp->frame, env);  

  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_UNSUBSCRIBE);
  axutil_stomp_set_header (stomp, env, "destination", "/queue/AutoBots");
  axutil_stomp_write (stomp, env);
  axutil_stomp_frame_reset (stomp->frame, env);

  axutil_stomp_set_command (stomp, env, AXIS2_STOMP_DISCONNECT);
  axutil_stomp_write (stomp, env);
  axutil_stomp_frame_reset (stomp->frame, env);

  axutil_stomp_free (stomp, env);
  return 0;
}

