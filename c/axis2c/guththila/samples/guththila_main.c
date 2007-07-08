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

#include "guththila.h"
#include "guththila_defines.h"

int
main(int argc, char *argv[])
{
    int c;
    axutil_allocator_t *allocator;
    guththila_reader_t *red;
    axutil_env_t *environment;
    guththila_t *parser;
    char *xml_buffer;
    allocator = axutil_allocator_init(NULL);
    xml_buffer = "<?xml version = \"1.0\"?><test a=\"din\">addddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd123</test>";
    environment =
        axutil_env_create(allocator);

    if (argc > 1)
        red = guththila_reader_create_for_file(environment, argv[1]);
    else
    {
        if (xml_buffer)
        {
            int size = 0;
            size = strlen(xml_buffer);
            red = guththila_reader_create_for_memory(environment, (void *)xml_buffer, size, NULL);
        }
    }

    parser = guththila_create(environment, red);
    guththila_read(environment, parser);

    while ((c = guththila_next(environment, parser)) != -1)
    {
        switch (c)
        {
            case GUTHTHILA_START_DOCUMENT:
            {
                int ix;
                printf("<?xml ");

                ix = guththila_get_attribute_count
                        (environment, parser);
                for (; ix > 0; ix--)
                {
                    guththila_attribute_t *a;
                    char *p;
                    a = guththila_get_attribute(environment,
                            parser);
                    p = guththila_get_attribute_name
                            (environment, parser, a);
                    printf("%s=\"", p);
                    AXIS2_FREE (allocator, p);
                    p = guththila_get_attribute_value
                            (environment, parser, a);
                    printf("%s\" ", p);
                     AXIS2_FREE (allocator, p);
					guththila_attribute_free (environment, a);
                }
                printf("?>\n");
            }
            break;
            case GUTHTHILA_START_ELEMENT:
            case GUTHTHILA_EMPTY_ELEMENT:
            {
                int ia;
                int d;
                char *p;
                guththila_depth_t *depth;

                printf("<");
                p = guththila_get_prefix(environment,
                        parser);
                if (p)
                {
                    printf("%s:", p);
                    AXIS2_FREE(allocator, p);
                }
                p = guththila_get_name(environment, parser);
                printf("%s", p);
                AXIS2_FREE(allocator, p);

                ia = guththila_get_attribute_count
                        (environment, parser);
                for (; ia > 0; ia--)
                {
                    /* p = guththila_get_attribute_prefix_by_number
                       (parser, ia); */
                    p =	guththila_get_attribute_prefix_by_number(environment, parser, ia);
                    if (p)
                    {
                        printf(" %s:", p);
                        AXIS2_FREE(allocator, p);
                        p = guththila_get_attribute_name_by_number(environment, parser, ia);
                        printf("%s=\"", p);
                        AXIS2_FREE(allocator, p);
                        p = guththila_get_attribute_value_by_number(environment, parser, ia);
                        printf("%s\"", p);
                        AXIS2_FREE(allocator, p);
                    }
                    else
                    {
                        p = guththila_get_attribute_name_by_number(environment, parser, ia);
                        printf(" %s=\"", p);
                        AXIS2_FREE(allocator, p);
                        p = guththila_get_attribute_value_by_number(environment, parser, ia);
                        printf("%s\"", p);
                        AXIS2_FREE(allocator, p);
                    }
                }
                depth = (guththila_depth_t *) axutil_stack_get(parser->dep, environment);
                d = depth->count;
                for (; d > 0; d--)
                {
                    p = guththila_get_namespace_prefix_by_number(environment, parser, d);
                    if (strncmp(p, "xmlns", 5))
					{
                        printf(" xmlns:");
						printf("%s=\"", p);
					}
					else
						printf (" xmlns=\"");
                    AXIS2_FREE(allocator, p);
                    p = guththila_get_namespace_uri_by_number
                            (environment, parser, d);
                    printf("%s\"", p);
                    AXIS2_FREE(allocator, p);
                }
                if (parser->guththila_event == GUTHTHILA_START_ELEMENT)
                    printf(">");
                else if (parser->guththila_event == GUTHTHILA_EMPTY_ELEMENT)
                    printf("/>");
				else
					printf ("error \n");

            }
            break;
            case GUTHTHILA_END_ELEMENT:
            {
                char *p;
                printf("</");
                p = guththila_get_prefix(environment,
                        parser);
                if (p)
                {
                    printf("%s:", p);
                    AXIS2_FREE(allocator, p);
                }
                p = guththila_get_name(environment, parser);
                printf("%s", p);
                AXIS2_FREE(allocator, p);
                printf(">");
            }
            break;
            case GUTHTHILA_CHARACTER:
            {
                char *p = NULL;
                p = guththila_get_value(environment, parser);
				/*    if (!parser->is_whitespace) */
				/*                 { */
				/*                     printf(p); */
				/*                 } */
				printf ("%s",p);
				AXIS2_FREE(allocator, p);
            }
            break;
            case GUTHTHILA_COMMENT:
                break;
        };
    }
    guththila_reader_free(environment, red);
    guththila_free(environment, parser);
    axutil_env_free(environment);
    return 0;
}
