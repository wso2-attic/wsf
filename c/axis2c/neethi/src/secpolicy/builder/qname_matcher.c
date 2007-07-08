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


#include <rp_qname_matcher.h>

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
rp_match_secpolicy_qname(
            const axutil_env_t *env,
            const axis2_char_t *local_name,
            axiom_node_t *node,
            axiom_element_t *element)
{
    
	axutil_qname_t *qname = NULL;
    axutil_qname_t *node_qname = NULL;
	
	AXIS2_ENV_CHECK(env,AXIS2_FALSE);

    node_qname = axiom_element_get_qname(element,env,node);

    if(!node_qname)
    {
        axutil_qname_free(qname,env);
    }
    else
    {
        qname = axutil_qname_create(env,local_name,RP_SP_NS,RP_SP_PREFIX);
        if(!qname)
            return AXIS2_FALSE;
    }
    if(axutil_qname_equals(qname,env,node_qname))
    {
        axutil_qname_free(qname,env);
        qname = NULL;        
        return AXIS2_TRUE;
    }
    else
    {
        axutil_qname_free(qname,env);
        qname = NULL;
        return AXIS2_FALSE;
    }
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
rp_match_policy_qname(
            const axutil_env_t *env,
            const axis2_char_t *local_name,
            axiom_node_t *node,
            axiom_element_t *element)
{
    
	axutil_qname_t *qname = NULL;
    axutil_qname_t *node_qname = NULL;
	
	AXIS2_ENV_CHECK(env,AXIS2_FALSE);

    qname = axutil_qname_create(env,local_name,RP_POLICY_NS,RP_POLICY_PREFIX);
    if(!qname)
        return AXIS2_FALSE;

    node_qname = axiom_element_get_qname(element,env,node);

    if(!node_qname)
    {
        return AXIS2_FALSE;
    }
    else
    {
        qname = axutil_qname_create(env,local_name,RP_POLICY_NS,RP_POLICY_PREFIX);
        if(!qname)
            return AXIS2_FALSE;
    }
    if(axutil_qname_equals(qname,env,node_qname))
    {        
        axutil_qname_free(qname,env);
        qname = NULL;
        return AXIS2_TRUE;
    }
    else
    {
        axutil_qname_free(qname,env);
        qname = NULL;
        return AXIS2_FALSE;
    }
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
rp_match_rampart_config_qname(
            const axutil_env_t *env,
            const axis2_char_t *local_name,
            axiom_node_t *node,
            axiom_element_t *element)
{
    
	axutil_qname_t *qname = NULL;
    axutil_qname_t *node_qname = NULL;

	AXIS2_ENV_CHECK(env,AXIS2_FALSE);

    node_qname = axiom_element_get_qname(element,env,node);

    if(!node_qname)
    {
        return AXIS2_FALSE;
    }
    else
    {
        qname = axutil_qname_create(env,local_name,RP_RAMPART_NS,RP_RAMPART_PREFIX);
        if(!qname)
            return AXIS2_FALSE;
    }        
    if(axutil_qname_equals(qname,env,node_qname))
    {        
        axutil_qname_free(qname,env);
        qname = NULL;
        return AXIS2_TRUE;
    }
    else
    {        
        axutil_qname_free(qname,env);
        qname = NULL;
        return AXIS2_FALSE;
    }
}
