/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mtom_util.h"

/* build SOAP request message content using OM */
axiom_node_t *
build_om_payload_for_mtom(
    const axutil_env_t *env,
    const axis2_char_t *image_name,
    const axis2_char_t *to_save_name)
{
    axiom_node_t *mtom_om_node = NULL;
    axiom_element_t* mtom_om_ele = NULL;
    axiom_node_t* image_om_node = NULL;
    axiom_element_t * image_om_ele = NULL;
    axiom_node_t* file_om_node = NULL;
    axiom_element_t * file_om_ele = NULL;
    axiom_node_t* data_om_node = NULL;
    axiom_text_t * data_text = NULL;
    axiom_namespace_t *ns1 = NULL;

    axiom_data_handler_t *data_handler = NULL;

    ns1 = axiom_namespace_create(env, 
            "http://ws.apache.org/axis2/c/samples/mtom", "ns1");
    mtom_om_ele = axiom_element_create(env, NULL, "mtomSample", ns1, 
            &mtom_om_node);

    file_om_ele = axiom_element_create(env, mtom_om_node, "fileName", ns1, 
            &file_om_node);
    axiom_element_set_text(file_om_ele, env, to_save_name, file_om_node);

    image_om_ele = axiom_element_create(env, mtom_om_node, "image", ns1, 
            &image_om_node);

    data_handler = axiom_data_handler_create(env, image_name, "image/jpeg");
    data_text = axiom_text_create_with_data_handler(env, image_om_node, 
            data_handler, &data_om_node);
    /*printf("%s", axiom_node_to_string(mtom_om_node, env));*/
    return mtom_om_node;
}

