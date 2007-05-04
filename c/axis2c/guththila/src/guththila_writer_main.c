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
#include <guththila.h>
int main()
{
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    axutil_env_t *env = axutil_env_create(allocator);
    guththila_t *parser = guththila_create(env, NULL);
    guththila_create_xml_stream_writer(env, parser, "w.xml");
    guththila_write_start_document(env, parser);
    guththila_write_start_element(env, parser, "person");
    guththila_write_start_element(env, parser, "name");
    guththila_write_characters(env, parser, "guththila");
    guththila_write_start_element(env, parser, "escape");
    guththila_write_escape_character(env, parser, "&");
    guththila_write_escape_character(env, parser, ">");
    guththila_write_end_element(env, parser);
    guththila_write_start_element(env, parser, "escape");
    guththila_write_default_namespace(env, parser, "http://www.cse.mrt.ac.lk");
    guththila_write_namespace(env, parser, "a", "http://ws.apache.org");
    guththila_write_attribute_with_prefix(env, parser, "a", "web", "false");
    guththila_write_start_element(env, parser, "one");
    guththila_write_start_element_with_prefix(env, parser, "a", "two");
    guththila_write_characters(env, parser, "it works !");
    guththila_write_end_document(env, parser);
    guththila_xml_writer_free(env, parser);
    guththila_free(env, parser);
    axutil_allocator_free(allocator);
    axutil_env_free(env);
    return 0;
}
