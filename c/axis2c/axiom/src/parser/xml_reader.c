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

#include <axiom_xml_reader.h>

AXIS2_EXTERN int AXIS2_CALL
axiom_xml_reader_next(axiom_xml_reader_t *parser,
    const axutil_env_t *env)
{
    return (parser)->ops->next(parser, env);
}

AXIS2_EXTERN  void AXIS2_CALL 
axiom_xml_reader_free(axiom_xml_reader_t *parser,
    const axutil_env_t *env)
{
    (parser)->ops->free(parser, env);
}

AXIS2_EXTERN  int AXIS2_CALL
axiom_xml_reader_get_attribute_count(axiom_xml_reader_t *parser,
    const axutil_env_t *env)
{
    return (parser)->ops->get_attribute_count(parser, env);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL
axiom_xml_reader_get_attribute_name_by_number(axiom_xml_reader_t *parser,
    const axutil_env_t *env,
    int i)
{
    return (parser)->ops->get_attribute_name_by_number(parser, env, i);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_attribute_prefix_by_number(axiom_xml_reader_t *parser,
    const axutil_env_t *env,
    int i)
{
    return (parser)->ops->get_attribute_prefix_by_number(parser, env, i);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_attribute_value_by_number(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     int i)
{
    return (parser)->ops->get_attribute_value_by_number(parser,env, i);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_attribute_namespace_by_number(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     int i)
{
    return (parser)->ops->get_attribute_namespace_by_number(parser, env, i);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_value(axiom_xml_reader_t *parser,
     const axutil_env_t *env)
{
    return (parser)->ops->get_value(parser, env);
}

AXIS2_EXTERN  int AXIS2_CALL 
axiom_xml_reader_get_namespace_count(axiom_xml_reader_t *parser,
    const axutil_env_t *env)
{
    return (parser)->ops->get_namespace_count(parser, env);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_namespace_uri_by_number(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     int i)
{
    return (parser)->ops->get_namespace_uri_by_number(parser, env, i);    
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_namespace_prefix_by_number(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     int i)
{
    return (parser)->ops->get_namespace_prefix_by_number(parser, env, i);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_prefix(axiom_xml_reader_t *parser,
     const axutil_env_t *env)
{
    return (parser)->ops->get_prefix(parser, env);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_name(axiom_xml_reader_t *parser,
     const axutil_env_t *env)
{
    return (parser)->ops->get_name(parser, env);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_pi_target(axiom_xml_reader_t *parser,
      const axutil_env_t *env)
{
    return (parser)->ops->get_pi_target(parser, env);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_pi_data(axiom_xml_reader_t *parser,
     const axutil_env_t *env)
{
    return (parser)->ops->get_pi_data(parser, env);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_dtd(axiom_xml_reader_t *parser,
     const axutil_env_t *env)
{
    return (parser)->ops->get_dtd(parser, env);
}

AXIS2_EXTERN  void AXIS2_CALL 
axiom_xml_reader_xml_free(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     void *data)
{
    (parser)->ops->xml_free(parser, env, data);
}


AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_char_set_encoding(axiom_xml_reader_t *parser,
     const axutil_env_t *env)
{
    return (parser)->ops->get_char_set_encoding(parser, env);
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_namespace_uri(axiom_xml_reader_t *parser,
     const axutil_env_t *env)
{
    return (parser)->ops->get_namespace_uri(parser, env);    
}

AXIS2_EXTERN  axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_namespace_uri_by_prefix(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     axis2_char_t *prefix)
{
    return (parser)->ops->get_namespace_uri_by_prefix(parser, env, prefix);
}
