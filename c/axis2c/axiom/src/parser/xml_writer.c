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

#include <axiom_xml_writer.h>

AXIS2_EXTERN void AXIS2_CALL
axiom_xml_writer_free(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    (writer)->ops->free(writer,env);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname)
{
    return (writer)->ops->write_start_element(writer, env, localname);

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_end_start_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    return (writer)->ops->end_start_element(writer,env);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_element_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri)
{
    return (writer)->ops->write_start_element_with_namespace(writer, env, 
        localname, namespace_uri);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_element_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix)
{
    return (writer)->ops->write_start_element_with_namespace_prefix(writer, 
        env, localname, namespace_uri, prefix);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_empty_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname)
{
    return (writer)->ops->write_empty_element(writer, env, localname);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_empty_element_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri)
{
    return (writer)->ops->write_empty_element_with_namespace(writer, env, 
        localname, namespace_uri);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_empty_element_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix)
{
    return (writer)->ops->write_empty_element_with_namespace_prefix(writer, 
        env, localname, namespace_uri, prefix);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_end_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    return (writer)->ops->write_end_element(writer,env);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_end_document(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    return (writer)->ops->write_end_document(writer,env);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_attribute(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value)
{
    return (writer)->ops->write_attribute(writer,env, localname, value);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_attribute_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value,
    axis2_char_t *namespace_uri)
{
    return (writer)->ops->write_attribute_with_namespace(writer, env, 
        localname, value, namespace_uri);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_attribute_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix)
{
    return (writer)->ops->write_attribute_with_namespace_prefix(writer, env, 
        localname, value, namespace_uri, prefix);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *prefix,
    axis2_char_t *namespace_uri)
{
    return (writer)->ops->write_namespace(writer, env, prefix, namespace_uri);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_default_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *namespace_uri)
{
    return (writer)->ops->write_default_namespace(writer, env, namespace_uri);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_comment(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *value)
{
    return (writer)->ops->write_comment(writer, env, value);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_processing_instruction(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *target)
{
    return (writer)->ops->write_processing_instruction(writer, env, target);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_processing_instruction_data(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *target,
    axis2_char_t *data)
{
    return (writer)->ops->write_processing_instruction_data(writer, env, 
        target, data);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_cdata(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *data)
{
    return (writer)->ops->write_cdata(writer, env, data);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_dtd(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *dtd)
{
    return (writer)->ops->write_cdata(writer, env, dtd);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_entity_ref(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *name)
{
    return (writer)->ops->write_entity_ref(writer, env, name);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_document(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    return (writer)->ops->write_start_document(writer,env);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_document_with_version(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *version)
{
    return (writer)->ops->write_start_document_with_version(writer, env, 
        version);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_document_with_version_encoding(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *version,
    axis2_char_t *encoding)
{
    return (writer)->ops->write_start_document_with_version_encoding(writer, env,
        version, encoding);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_characters(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *text)
{
    return (writer)->ops->write_characters(writer, env, text);
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axiom_xml_writer_get_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *uri)
{
    return (writer)->ops->get_prefix(writer, env, uri);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_set_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *prefix,
    axis2_char_t *uri)
{
    return (writer)->ops->set_prefix(writer, env, prefix, uri);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_set_default_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *uri)
{
    return (writer)->ops->set_default_prefix(writer, env, uri);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_encoded(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *text,
    int in_attr)
{
    return (writer)->ops->write_encoded(writer, env, text, in_attr);
}

AXIS2_EXTERN void* AXIS2_CALL
axiom_xml_writer_get_xml(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    return (writer)->ops->get_xml(writer, env);
}

AXIS2_EXTERN unsigned int AXIS2_CALL
axiom_xml_writer_get_xml_size(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    return (writer)->ops->get_xml_size(writer, env);
}

AXIS2_EXTERN int AXIS2_CALL
axiom_xml_writer_get_type(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    return (writer)->ops->get_type(writer, env);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_raw(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *content)
{
    return (writer)->ops->write_raw(writer, env, content);
}

AXIS2_EXTERN axis2_status_t  AXIS2_CALL
axiom_xml_writer_flush(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    return (writer)->ops->flush(writer, env);
}
