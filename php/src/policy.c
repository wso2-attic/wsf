/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "php.h"
#include <axis2_addr.h>
#include "wsf.h"
#include "wsf_util.h"
#include <axis2_error_default.h>
#include <axis2_log_default.h>
#include <axis2_uuid_gen.h>
#include <axiom_util.h>
#include "wsf_policy.h"
#include <axiom.h>

axiom_node_t *
create_policy_node(const axis2_env_t *env,
                   axiom_node_t *node);

axiom_node_t *
create_initiator_token(const axis2_env_t *env,
                       axiom_node_t *node,
		       zval **optionVal);

axiom_node_t *
create_recipient_token(const axis2_env_t *env,
                       axiom_node_t *node,
		       zval **optionVal);

axiom_node_t*
create_algorithm_suite(const axis2_env_t *env,
                       axiom_node_t *node,
		       zval **optionVal);

axiom_node_t *
create_layout(const axis2_env_t *env,
              axiom_node_t *node,
	      zval **optionVal);

int get_security_policy_options(const axis2_env_t *env,
				zval **sec_options);

int set_policy_options(const axis2_env_t *env,
		       HashTable *ht)
{
    zval **tmp = NULL;

    if (!ht)
	return FALSE;

/* for security policy related things */
    if(zend_hash_find(ht, "security", sizeof("security"), (void **)&tmp) == SUCCESS &&
       Z_TYPE_PP(tmp) == IS_ARRAY)
    {
	get_security_policy_options(env, tmp);
    }
    
    /** for RM policy */
    if(zend_hash_find(ht, "RM", sizeof("action"), (void **)&tmp) == SUCCESS &&
       Z_TYPE_PP(tmp) == IS_STRING)
    {
	/* ***** */
    }
	return 0;
}

/* Implementation of security policy related things */
int get_security_policy_options(const axis2_env_t *env,
				zval **sec_options)
{
    axiom_node_t *root_om_node = NULL;
    axiom_node_t* exact_om_node = NULL;
    axiom_node_t *all_om_node = NULL;
    axiom_node_t *asymmetric_om_node = NULL;
    axiom_node_t *policy_om_node1 = NULL;
    axiom_node_t *init_om_node = NULL;
    axiom_node_t *rec_om_node = NULL;
    axiom_node_t *timestamp_om_node = NULL;

    axiom_element_t* root_om_ele = NULL;
    axiom_element_t * exact_om_ele = NULL;
    axiom_element_t *all_om_ele = NULL;
    axiom_element_t *asymmetric_om_ele = NULL;

    axiom_namespace_t *wsp_ns = NULL;
    axiom_namespace_t *exactly_ns = NULL;
    axiom_namespace_t *sp_ns = NULL;

    axis2_char_t *om_str = NULL;
    FILE *fp = NULL;

	HashTable *ht = NULL;
    
    zval **tmp = NULL;

    if (sec_options == NULL)
	return FALSE;

	ht = Z_ARRVAL_PP(sec_options);
    if (!ht)
	return FALSE;


    wsp_ns = axiom_namespace_create(env, "http://schemas.xmlsoap.org/ws/2004/09/policy", "wsp");
    root_om_ele = axiom_element_create(env, NULL, "policy", wsp_ns, &root_om_node);

    exact_om_ele = axiom_element_create(env, root_om_node, "ExactlyOne", wsp_ns, &exact_om_node);
    all_om_ele = axiom_element_create(env, exact_om_node, "All", wsp_ns, &all_om_node);

    sp_ns = axiom_namespace_create(env, "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy", "sp");
    asymmetric_om_ele = axiom_element_create(env, all_om_node, "AsymmetricBinding", sp_ns, &asymmetric_om_node);

    policy_om_node1 = create_policy_node(env, asymmetric_om_node);

    /*  if the sigining part is included in the user options */
    if (zend_hash_find(ht, "sign", sizeof("sign"), (void **)&tmp) == SUCCESS)
    {
	create_initiator_token(env, policy_om_node1, tmp);
    }

    /* if the encryption is included */
    if (zend_hash_find(ht, "encrypt", sizeof("encrypt"), (void **)&tmp) == SUCCESS)
    {
	create_recipient_token(env, policy_om_node1, tmp);
    }
    /* if algorithm suite is presence in the options */
    if (zend_hash_find(ht, "algorithmSuite", sizeof("algorithmSuite"), (void **)&tmp) == SUCCESS)
    {
	create_algorithm_suite(env, policy_om_node1, tmp);
    }
    /*if the Layout is presence call this function */
    if (zend_hash_find(ht, "Layout", sizeof("Layout"), (void **)&tmp) == SUCCESS)
    {
	create_layout(env, policy_om_node1, tmp);
    }
    /* for timestamp */
    axiom_element_create(env, policy_om_node1, "IncludeTimestamp", sp_ns, &timestamp_om_node);

 /*    om_str = AXIOM_NODE_TO_STRING(root_om_node, env); */
/*     if (om_str) */
/*     { */
/*         fp = fopen("new.xml", "w"); */
/*         fprintf(fp, "%s", om_str); */

/*         printf("\n Result OM : %s\n", om_str); */
/*         AXIS2_FREE(env->allocator, om_str); */
/*         om_str =  NULL; */
/*     } */
	return 0;
}

/* create a policy node since this node is needed every where in the
 * policy.xml*/
axiom_node_t *
create_policy_node(const axis2_env_t *env,
                   axiom_node_t *parent_om_node)
{
    axiom_node_t *policy_om_node = NULL;
    axiom_element_t *policy_om_ele = NULL;
    axiom_namespace_t *wsp_ns = NULL;

    wsp_ns = axiom_namespace_create(env, "http://schemas.xmlsoap.org/ws/2004/09/policy", "wsp");
    policy_om_ele = axiom_element_create(env, parent_om_node, "policy", wsp_ns, &policy_om_node);

    return policy_om_node;


}

/* this finction for creating the initiator token which use for
   signing */
axiom_node_t *
create_initiator_token(const axis2_env_t *env,
                       axiom_node_t *parent_om_node, 
		       zval **tmp)
{
    axiom_node_t *in_token_om_node = NULL;
    axiom_node_t *policy_om_node1 = NULL;
    axiom_node_t *x509_om_node = NULL;
    axiom_node_t *policy_om_node2 = NULL;
    axiom_node_t *incl_token_om_node = NULL;
    axiom_node_t *token_id_om_node = NULL;

    axiom_element_t *in_token_om_ele = NULL;
    axiom_element_t *x509_om_ele = NULL;
    axiom_element_t *incl_token_om_ele = NULL;

    axiom_attribute_t *attr = NULL;

    axiom_namespace_t *sp_ns = NULL;
    char *token_name = NULL;

    sp_ns = axiom_namespace_create(env,"http://schemas.xmlsoap.org/ws/2005/07/securitypolicy", "sp");

    in_token_om_ele = axiom_element_create(env, parent_om_node, "InitiatorToken", sp_ns, &in_token_om_node);
    policy_om_node1 = create_policy_node(env, in_token_om_node);
    
    /* for x509 token and kerberose tokens.. can be extend later */
    if( tmp != NULL && Z_TYPE_PP(tmp) == IS_STRING)
    {
	token_name = Z_STRVAL_PP(tmp);
	if (stricmp(token_name, "x509") == 0)
	{
		x509_om_ele = axiom_element_create(env, policy_om_node1, "X509Token", sp_ns, &x509_om_node);
	    attr = axiom_attribute_create(env, "IncludeToken", "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy/IncludeToken/Always",
					  sp_ns);
	    AXIOM_ELEMENT_ADD_ATTRIBUTE(x509_om_ele, env, attr, x509_om_node);
	    policy_om_node2 = create_policy_node(env, x509_om_node);
	    axiom_element_create(env, policy_om_node2, "WssX509V3Token10", sp_ns, &token_id_om_node);
	}
	/** implement for othertoken types */

    }
	
    if (tmp != NULL && Z_TYPE_PP(tmp) == IS_BOOL)
    {
	x509_om_ele = axiom_element_create(env, policy_om_node1, "X509Token", sp_ns, &x509_om_node);
	
	attr = axiom_attribute_create(env, "IncludeToken", "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy/IncludeToken/Always",
				      sp_ns);
	AXIOM_ELEMENT_ADD_ATTRIBUTE(x509_om_ele, env, attr, x509_om_node);
	policy_om_node2 = create_policy_node(env, x509_om_node);
	axiom_element_create(env, policy_om_node2, "WssX509V3Token10", sp_ns, &token_id_om_node);
   
    }
    
    return token_id_om_node;
}


/** for encryption part of the policy file */

axiom_node_t *
create_recipient_token(const axis2_env_t *env,
		       axiom_node_t *parent_om_node,
		       zval **tmp)
{
    axiom_node_t *rec_token_om_node = NULL;
    axiom_node_t *policy_om_node1 = NULL;
    axiom_node_t *x509_om_node = NULL;
    axiom_node_t *policy_om_node2 = NULL;
    axiom_node_t *incl_token_om_node = NULL;
    axiom_node_t *token_id_om_node = NULL;

    axiom_element_t *rec_token_om_ele = NULL;
    axiom_element_t *x509_om_ele = NULL;
    axiom_element_t *incl_token_om_ele = NULL;

    axiom_attribute_t *attr = NULL;

    axiom_namespace_t *sp_ns = NULL;

    sp_ns = axiom_namespace_create(env,"http://schemas.xmlsoap.org/ws/2005/07/securitypolicy", "sp");

    rec_token_om_ele = axiom_element_create(env, parent_om_node, "RecipientToken", sp_ns, &rec_token_om_node);
    policy_om_node1 = create_policy_node(env, rec_token_om_node);
    x509_om_ele = axiom_element_create(env, policy_om_node1, "X509Token", sp_ns, &x509_om_node);

/* Here uri may change according to the options difined in policy spec
 * e.g - 'Always' may be changed as 'Never'*/
    attr = axiom_attribute_create(env, "IncludeToken", "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy/IncludeToken/Always",
				  sp_ns);
    AXIOM_ELEMENT_ADD_ATTRIBUTE(x509_om_ele, env, attr, x509_om_node);
    policy_om_node2 = create_policy_node(env, x509_om_node);
    axiom_element_create(env, policy_om_node2, "WssX509V3Token10", sp_ns, &token_id_om_node);


    return token_id_om_node;

}


axiom_node_t *
create_algorithm_suite(const axis2_env_t *env,
                       axiom_node_t *parent_node,
		       zval **tmp)
{
    axiom_node_t *alg_om_node = NULL;
    axiom_node_t *alg_name_om_node = NULL;
    axiom_node_t *policy_om_node = NULL;

    axiom_namespace_t *sp_ns = NULL;

    sp_ns = axiom_namespace_create(env, "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy", "sp");
    axiom_element_create(env, parent_node, "AlgorithmSuite", sp_ns, &alg_om_node);
    policy_om_node = create_policy_node(env, alg_om_node);
    axiom_element_create(env, policy_om_node, "Basic256Rsa15", sp_ns, &alg_name_om_node);

    return alg_name_om_node;


}

axiom_node_t *
create_layout(const axis2_env_t *env,
              axiom_node_t *parent_node,
	      zval **tmp)
{
    axiom_node_t *layout_om_node = NULL;
    axiom_node_t *policy_om_node = NULL;
    axiom_node_t *strict_om_node = NULL;

    axiom_namespace_t *sp_ns = NULL;

    sp_ns = axiom_namespace_create(env, "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy", "sp");
    axiom_element_create(env, parent_node, "Layout", sp_ns, &layout_om_node);
    policy_om_node = create_policy_node(env, layout_om_node);
    axiom_element_create(env, policy_om_node, "Strict", sp_ns, &strict_om_node);
    return strict_om_node;
}












