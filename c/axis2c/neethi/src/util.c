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



#include <neethi_util.h>



AXIS2_EXTERN neethi_policy_t *AXIS2_CALL 
neethi_util_create_policy_from_file(
        const axutil_env_t *env,
        axis2_char_t *file_name)
{

    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_document_t *document = NULL;
    axiom_node_t *root_node = NULL;


    reader = axiom_xml_reader_create_for_file(env, file_name, NULL);

    if (!reader)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CREATING_XML_STREAM_READER,
                AXIS2_FAILURE);
        return NULL;
    }

    builder = axiom_stax_builder_create(env, reader);
    if(!builder)
    {
        axiom_xml_reader_free(reader, env);
        return NULL;
    }
    document = axiom_stax_builder_get_document(builder, env);

    if(!document)
    {
        axiom_stax_builder_free(builder, env);
        return NULL;
    }

    root_node = axiom_document_build_all(document, env);
    if(!root_node)
    {
        axiom_stax_builder_free(builder, env);
        return NULL;
    }   

    return neethi_util_create_policy_from_om(env, root_node);
     
}


AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
neethi_util_create_policy_from_om(
        const axutil_env_t *env,
        axiom_node_t *root_node)
{

    axiom_element_t *root_ele = NULL;    

    if(axiom_node_get_node_type(root_node, env) == AXIOM_ELEMENT)
    {
        root_ele = (axiom_element_t *)axiom_node_get_data_element(root_node, env);
        if(root_ele)
        {
            neethi_policy_t *neethi_policy = NULL;
            neethi_policy = neethi_engine_get_policy(env, root_node, root_ele);
            if(!neethi_policy)
            {
                return NULL;
            }
            return neethi_policy;
        }
        else return NULL;
    }
    else return NULL;
}
