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

#include "echo_util.h"

/* build SOAP request message content using OM */
axiom_node_t *
build_om_payload_for_echo_svc(
   const axutil_env_t *env,
   axis2_char_t *text,
   axis2_char_t *seq)
{
    axiom_node_t *echo_om_node = NULL;
    axiom_element_t* echo_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_node_t* seq_om_node = NULL;
    axiom_element_t * seq_om_ele = NULL;
    axiom_namespace_t *ns1 = NULL;
    axis2_char_t *om_str = NULL;
    axis2_char_t *ns = NULL;

    ns = "http://tempuri.org/";
    
    ns1 = axiom_namespace_create (env, ns, "ns1");
    echo_om_ele = axiom_element_create(env, NULL, "echoString", ns1, &echo_om_node);
    text_om_ele = axiom_element_create(env, echo_om_node, "Text", ns1, &text_om_node);
    seq_om_ele = axiom_element_create(env, echo_om_node, "Sequence", ns1, &seq_om_node);
    axiom_element_set_text(text_om_ele, env, text, text_om_node);
    axiom_element_set_text(text_om_ele, env, seq, seq_om_node);
    
    om_str = axiom_node_to_string(echo_om_node, env);
    if (om_str)
        printf("\nSending OM : %s\n", om_str);

    return echo_om_node;
}
