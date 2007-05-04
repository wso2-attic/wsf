/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <guththila_buffer.h>
#include <guththila_reader.h>
#include <guththila_writer.h>
#include <guththila.h>
#include <axis2_util.h>
#define MAXA 100000
int main(int argc, char *argv[])
{
    char *t;
    axutil_allocator_t *allocator;
    axutil_env_t *env ;
    guththila_t *parser ;
	char *xml = NULL;
	FILE *file = NULL;
    allocator = axutil_allocator_init(NULL);
    env = axutil_env_create(allocator);
    parser = guththila_create(env, NULL);
	guththila_create_xml_stream_writer_for_memory(env, parser);
	guththila_write_start_element(env, parser, "two");
    guththila_write_default_namespace(env, parser, "http://another.host.com");
	guththila_write_start_element_with_prefix_and_namespace (env, parser, "ws", "http://www.wso2.org", "wso2");
	guththila_write_start_element_with_prefix (env, parser, "ws", "stacks");
	guththila_write_attribute_with_prefix (env, parser, "ws", "stack", "axis2");
	guththila_write_characters (env, parser, "testadfjaldjf;ajf;lkajdfa;lkjfd;ajdf11111111111122334455");
    guththila_write_end_document(env, parser);

	xml = (char *) AXIS2_MALLOC (env->allocator, MAXA + 1);
	memset (xml, 0, MAXA + 1);
	if (!argv[1])
	{
		file = fopen ("/home/dinesh/tmp/mbox_backup/mbox.archived", "r");
	}
	else
		file = fopen (argv[1], "r");

	if (file)
		fread (xml, 1, MAXA, file);

	guththila_write_to_buffer (env, parser, xml);
    t = guththila_writer_get_buffer(env, parser->xsw->writer);
    printf("%s \n", t);
	free (xml);
	fclose (file);
    guththila_xml_writer_free(env, parser);
    guththila_free(env, parser);
    axutil_env_free(env);
    return 0;
}
