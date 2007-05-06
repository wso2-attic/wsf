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

#include <axiom_xml_writer.h>
#include <stdio.h>

#include "listener.h"

axiom_node_t *
axis2_listener_notify(const axutil_env_t *env, axiom_node_t *node)
{
    axiom_node_t *pres_node = NULL;
    axiom_node_t *status_node = NULL;
    axiom_element_t *body_elem = NULL;
    axiom_element_t *pres_elem = NULL;
    axiom_element_t *status_elem = NULL;
    axiom_attribute_t *attr_from = NULL;
    axutil_qname_t *qname= NULL;
    axis2_char_t *str = NULL;
    axis2_char_t *from = NULL;
    axis2_char_t *status = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    
    str = axiom_node_to_string(node, env);

    body_elem = axiom_node_get_data_element(node, env);

    qname = axutil_qname_create(env, "presence", NULL, NULL);
    pres_elem = axiom_element_get_first_child_with_qname(body_elem, env, qname,
                        node, &pres_node);
    axutil_qname_free(qname, env);

    if (pres_elem)
    {
        qname = axutil_qname_create(env, "from", NULL, NULL);
        attr_from = axiom_element_get_attribute(pres_elem, env, qname);
        axutil_qname_free(qname, env);
        if (attr_from)
        {
            from = axiom_attribute_get_value(attr_from, env);
        }
        
        qname = axutil_qname_create(env, "status", NULL, NULL);
        status_elem = axiom_element_get_first_child_with_qname(pres_elem, env, qname,
                            pres_node, &status_node);
        axutil_qname_free(qname, env);
        if (status_elem)
        {
            status = axiom_element_get_text(status_elem, env, status_node);
        }
    }

    printf("\n************************************************************\n");
    printf("Received presence notification:\n\n");
    printf("From: %s\n", from);
    printf("Status: %s\n", status);
    printf("\nFull notification:\n%s\n\n", str);

    return NULL;
}
