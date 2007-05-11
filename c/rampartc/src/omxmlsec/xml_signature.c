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
#include <axis2_util.h>
#include <oxs_constants.h>
#include <oxs_error.h>
#include <oxs_buffer.h>
#include <oxs_cipher.h>
#include <oxs_c14n.h>
#include <oxs_axiom.h>
#include <oxs_utility.h>
#include <openssl_rsa.h>
#include <openssl_digest.h>
#include <oxs_sign_ctx.h>
#include <oxs_sign_part.h>
#include <oxs_xml_signature.h>
#include <oxs_signature.h>
#include <oxs_transform.h>
#include <oxs_transforms_factory.h>
#include <oxs_tokens.h>
/*Private functions*/


/*This method is common for both signing and verification*/
static axis2_char_t *
oxs_xml_sig_transform_n_digest(const axutil_env_t *env,
                               axiom_node_t *node,
                               axutil_array_list_t *transforms,
                               axis2_char_t *digest_mtd)
{
    axis2_char_t *serialized_node = NULL;
    axis2_char_t *digest = NULL;
    int i = 0;

    if((transforms) && (0 < axutil_array_list_size(transforms, env))){
        oxs_tr_dtype_t output_dtype = OXS_TRANSFORM_TYPE_UNKNOWN;/*This will always be the current dtype*/
        void *tr_output = NULL;
        output_dtype = OXS_TRANSFORM_TYPE_NODE; /*We always begin with a node*/

        tr_output = node; /*The first transformation is applied to the node*/

        /*LOOP: Apply transforms. For example exclusive C14N*/
        for (i = 0; i < axutil_array_list_size(transforms, env); i++){
            oxs_transform_t *tr = NULL;
            oxs_transform_tr_func tr_func = NULL;
            oxs_tr_dtype_t input_dtype = OXS_TRANSFORM_TYPE_UNKNOWN;
            void *tr_input = NULL;
            axis2_char_t *tr_id = NULL;

            /*Get the ith transform*/
            tr = (oxs_transform_t*)axutil_array_list_get(transforms, env, i);
            tr_id = oxs_transform_get_id(tr, env);
            tr_func = oxs_transform_get_transform_function(tr, env);
            input_dtype = oxs_transform_get_input_data_type(tr, env);

            /*Prepare the input*/
            /*If the required input type is CHAR and what we have is a NODE*/
            if((input_dtype == OXS_TRANSFORM_TYPE_CHAR) && (output_dtype == OXS_TRANSFORM_TYPE_NODE)){
                /*Serialize*/
                tr_input = axiom_node_to_string((axiom_node_t*)tr_output, env);
                /*If the required input type is NODE and what we have is a CHAR*/
            }else if((input_dtype == OXS_TRANSFORM_TYPE_NODE) && (output_dtype == OXS_TRANSFORM_TYPE_CHAR)){
                /*De-serialize*/
                tr_input =  oxs_axiom_deserialize_node(env, (axis2_char_t *)tr_output);
            }else{
                /*Let it go as it is. */
                tr_input = tr_output;
            }
            /*Apply transform*/
            if(tr_func){
                output_dtype = (*tr_func)(env, tr_input, input_dtype, &tr_output);
            }else{
                oxs_error(env, ERROR_LOCATION, OXS_ERROR_TRANSFORM_FAILED,"Cannot get the transform implementation for %s", tr_id);
            }
            /*If the output data type is unknown OR the output is NULL its an error*/
            if((output_dtype == OXS_TRANSFORM_TYPE_UNKNOWN) || (!tr_output)){
                oxs_error(env, ERROR_LOCATION, OXS_ERROR_TRANSFORM_FAILED,"Transform failed for %s", tr_id);
                return NULL;
            }
        }/*eof for loop*/
        /*We have applied all our transforms now*/
        /*Serialize node*/
        if(OXS_TRANSFORM_TYPE_NODE == output_dtype ){
            serialized_node = axiom_node_to_string((axiom_node_t*)tr_output, env);
        }else if(OXS_TRANSFORM_TYPE_CHAR == output_dtype){
            serialized_node = (axis2_char_t*)tr_output;
        }else{
            /*Error*/
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_TRANSFORM_FAILED,"Unsupported transform data type  %d", output_dtype);
        }
    }else{
        /*No transforms defined. Thus we simply direct the node, to make the digest*/
        serialized_node = axiom_node_to_string(node, env);
    }

    if(0 == axutil_strcmp( OXS_HREF_SHA1 , digest_mtd)){
        digest = openssl_sha1(env, serialized_node, axutil_strlen(serialized_node));
    }else{
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_TRANSFORM_FAILED,"Unsupported digest method  %s", digest_mtd);
        return NULL;
    }
    return digest;
}

/*parent is ds:SignedInfo*/
static axis2_status_t
oxs_xml_sig_build_reference(const axutil_env_t *env,
                            axiom_node_t *parent,
                            oxs_sign_part_t *sign_part)
{
    axis2_char_t *digest = NULL;
    axis2_char_t *digest_mtd = NULL;
    axis2_char_t *ref_id = NULL;
    axis2_char_t *id = NULL;
    axutil_array_list_t *transforms = NULL;
    axiom_node_t *node = NULL;
    axiom_node_t *reference_node = NULL;
    axiom_node_t *digest_value_node = NULL;
    axiom_node_t *digest_mtd_node = NULL;
    int i=0;

    /*Get the node to digest*/
    node = oxs_sign_part_get_node(sign_part, env);

    /*Get the reference ID from the node and hence to the ds:Reference node*/
    id = oxs_axiom_get_attribute_value_of_node_by_name(env, node, "wsu:Id");

    ref_id = axutil_stracat(env, "#", id);/* <ds:Reference URI="#id">*/
    reference_node = oxs_token_build_ds_reference_element(env, parent ,NULL, ref_id, NULL);

    /*Get transforms if any*/
    transforms = oxs_sign_part_get_transforms(sign_part, env);
    /*Get the digest method*/
    digest_mtd = oxs_sign_part_get_digest_mtd(sign_part, env);

    /*Transform and Digest*/
    digest = oxs_xml_sig_transform_n_digest(env, node, transforms, digest_mtd);

    /*Build ds:Transforms node and its children*/
    if((transforms) && (0 < axutil_array_list_size(transforms, env))){
        axiom_node_t *transforms_node = NULL;

        transforms_node = oxs_token_build_transforms_element(env, reference_node);
        for (i = 0; i < axutil_array_list_size(transforms, env); i++){
            oxs_transform_t *tr = NULL;
            axis2_char_t *tr_id = NULL;

            /*Get the ith transform*/
            tr = (oxs_transform_t*)axutil_array_list_get(transforms, env, i);
            tr_id = oxs_transform_get_id(tr, env);
            oxs_token_build_transform_element(env, transforms_node, tr_id);
        }
    }
    /*Construct nodes*/
    digest_mtd_node = oxs_token_build_digest_method_element(env, reference_node, digest_mtd);
    digest_value_node = oxs_token_build_digest_value_element(env, reference_node, digest);

    return AXIS2_SUCCESS;
}
/**
 *  C14N -> Serialize -> Sign the <SignedInfo> element
 */
static axis2_status_t
oxs_xml_sig_sign_signed_info(const axutil_env_t *env,
                             axiom_node_t *signature_node,
                             axiom_node_t *signed_info_node,
                             oxs_sign_ctx_t *sign_ctx)
{
    axis2_char_t *signature_val = NULL;
    axis2_char_t *serialized_signed_info = NULL;
    axis2_char_t *c14n_algo = NULL;
    axis2_char_t *c14nized = NULL;
    axiom_node_t *signature_val_node = NULL;
    axiom_document_t *doc = NULL;
    oxs_buffer_t *input_buf = NULL;
    oxs_buffer_t *output_buf = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    /*Cannonicalize <SignedInfo>*/
    c14n_algo = oxs_sign_ctx_get_c14n_mtd(sign_ctx, env);
    doc = axiom_node_get_document(signed_info_node, env);

    /*oxs_c14n_apply(env, doc, AXIS2_FALSE, &c14nized, AXIS2_TRUE, NULL, signed_info_node); */
    oxs_c14n_apply_algo(env, doc,  &c14nized, NULL, signed_info_node, c14n_algo);
    AXIS2_LOG_INFO(env->log, "[oxs][xml_sig] C14N (sig)= %s ", c14nized );

    /*Then serialize <SignedInfo>*/
    serialized_signed_info = c14nized; /*axiom_node_to_string(signed_info_node, env);*/

    /*Make the input and out put buffers*/
    input_buf = oxs_buffer_create(env);
    output_buf = oxs_buffer_create(env);

    oxs_buffer_populate(input_buf, env, (unsigned char *)serialized_signed_info, axutil_strlen(serialized_signed_info));
    /*Then sign... NOTE: The signature process includes making the digest. e.g. rsa-sha1 => RSA(SHA-1(contents))*/
    status = oxs_sig_sign(env, sign_ctx, input_buf, output_buf);

    signature_val = (axis2_char_t*)oxs_buffer_get_data(output_buf, env);

    /*Construct <SignatureValue>*/
    signature_val_node = oxs_token_build_signature_value_element(env, signature_node, signature_val);

    return status;
}

/*Public functions*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_sig_sign(const axutil_env_t *env,
                 oxs_sign_ctx_t *sign_ctx,
                 axiom_node_t *parent,
                 axiom_node_t **sig_node)
{
    axiom_node_t *signed_info_node = NULL;
    axiom_node_t *signature_node = NULL;
    axiom_node_t *signature_mtd_node = NULL;
    axiom_node_t *c14n_mtd_node = NULL;
    axis2_char_t *sign_algo = NULL;
    axis2_char_t *c14n_algo = NULL;
    axutil_array_list_t *sign_parts = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    int i=0;

    /*Construct the <Signature> element*/
    signature_node = oxs_token_build_signature_element(env, parent,  oxs_util_generate_id(env,OXS_SIG_ID));

    /*Construct the <SignedInfo>  */
    signed_info_node = oxs_token_build_signed_info_element(env, signature_node);

    /*Construct the <CanonicalizationMethod> */
    c14n_algo = oxs_sign_ctx_get_c14n_mtd(sign_ctx, env);
    c14n_mtd_node = oxs_token_build_c14n_method_element(env, signed_info_node, c14n_algo);

    /*Construct the <SignatureMethod>  */
    sign_algo = oxs_sign_ctx_get_sign_mtd_algo(sign_ctx, env);
    signature_mtd_node = oxs_token_build_signature_method_element(env, signed_info_node, sign_algo);

    /*Look for signature parts*/
    sign_parts = oxs_sign_ctx_get_sign_parts(sign_ctx , env);

    /*For each and every signature part in sig ctx,*/
    for (i = 0; i < axutil_array_list_size(sign_parts, env); i++){
        oxs_sign_part_t *sign_part =  NULL;

        /*Get ith sign_part*/
        sign_part = (oxs_sign_part_t*)axutil_array_list_get(sign_parts, env, i);
        /*Create <ds:Reference> elements */
        oxs_xml_sig_build_reference(env, signed_info_node, sign_part);

    }
    /*At this point we have a complete <SignedInfo> node. Now we need to sign it*/
    status = oxs_xml_sig_sign_signed_info(env, signature_node, signed_info_node, sign_ctx);

    *sig_node = signature_node;
    return status;
}

/*******************************Verification specific*****************************/

/*Populates a sign_part according to the <ds:Reference> node*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_sig_process_ref_node(const axutil_env_t *env,
                             oxs_sign_part_t *sign_part,
                             axiom_node_t *ref_node,
                             axiom_node_t *scope_node)
{
    axis2_char_t *ref_id = NULL;
    axis2_char_t *ref_id2 = NULL;
    axis2_char_t *child_node_name = NULL;
    axiom_node_t *reffed_node = NULL;
    axiom_node_t *child_node = NULL;

    ref_id =  oxs_token_get_ds_reference(env, ref_node);
    oxs_sign_part_set_id(sign_part, env, ref_id);

    /*Remove the # from the id*/
    ref_id2 =  axutil_string_substring_starting_at(axutil_strdup(env, ref_id), 1);

    /*Find the node refered by this ref_id2 and set to the sign part*/
    reffed_node = oxs_axiom_get_node_by_id(env, scope_node, "wsu:Id", ref_id2 );
    if(reffed_node){
        oxs_sign_part_set_node(sign_part, env, reffed_node);
    }else{
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Cannot find node with Id=%s ", ref_id2 );
        return AXIS2_FAILURE; /*No such node. Its an error*/
    }

    /*First child is optional Transforms element*/
    child_node = axiom_node_get_first_element(ref_node, env);
    child_node_name = axiom_util_get_localname(child_node, env);
    if(0 == axutil_strcmp(child_node_name, OXS_NODE_TRANSFORMS)){
        /*Transforms found*/
        axiom_node_t *tr_node = NULL;
        axutil_array_list_t *tr_list = NULL;

        /*Create a list to hold transforms*/
        tr_list = axutil_array_list_create(env, 1);
        tr_node = axiom_node_get_first_element(child_node, env);
        /*Iterate thru all the <ds:Transform> nodes in <ds:Transforms>*/
        while(tr_node)
        {
            axis2_char_t *node_name = NULL;

            node_name = axiom_util_get_localname(tr_node, env);
            if( 0 == axutil_strcmp(OXS_NODE_TRANSFORM, node_name)){
                axis2_char_t *tr_id = NULL;
                oxs_transform_t *tr = NULL;

                tr_id = oxs_token_get_transform(env, tr_node);
                /*Get the transform given the id*/
                tr = oxs_transforms_factory_produce_transform(env, tr_id);
                if(!tr) {
                    /*The transform not supported*/
                    oxs_error(env, ERROR_LOCATION, OXS_ERROR_TRANSFORM_FAILED,"Cannot produce the transform for %s", tr_id);
                    return AXIS2_FAILURE;
                }
                /*Add the transform to the list*/
                axutil_array_list_add(tr_list, env, tr);
            }else{
                /*<ds:Transforms> cant have any other element*/
                oxs_error(env, ERROR_LOCATION, OXS_ERROR_TRANSFORM_FAILED,"<ds:Transforms> cannot have node %s ", node_name );
                return AXIS2_FAILURE;
            }
            /*Set the next node to be precessed*/
            tr_node = axiom_node_get_next_sibling(tr_node, env);
        }/*eof while*/
        /*Set transforms for this signature part*/
        oxs_sign_part_set_transforms(sign_part, env, tr_list);

        /*At the end, set the next node as the child node*/
        child_node = axiom_node_get_next_sibling(child_node, env);
    }else{
        /*There are no transforms for this sign part*/
    }

    /* Process mandatory ds:DigestMethod*/
    child_node_name = axiom_util_get_localname(child_node, env);
    if(0 == axutil_strcmp(child_node_name, OXS_NODE_DIGEST_METHOD)){
        axis2_char_t *digest_mtd = NULL;
        /*ds:DigestMethod found*/
        digest_mtd = oxs_token_get_digest_method(env, child_node);
        oxs_sign_part_set_digest_mtd(sign_part, env, digest_mtd);

        /*At the end, set the next node as the child node*/
        child_node = axiom_node_get_next_sibling(child_node, env);
    }else{
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Cannot find <ds:DigestMethod> " );
        return AXIS2_FAILURE;
    }

    /* Process mandatory ds:DigestValue*/
    child_node_name = axiom_util_get_localname(child_node, env);
    if(0 == axutil_strcmp(child_node_name, OXS_NODE_DIGEST_VALUE)){
        /*ds:DigestValue found*/
        axis2_char_t *digest_val = NULL;
        digest_val = oxs_token_get_digest_value(env, child_node);
        oxs_sign_part_set_digest_val(sign_part, env, digest_val);
    }else{
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Cannot find <ds:DigestValue> " );
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;

}

/*Process Signature Node along with its most loving child ds:SignedInfo.
 * We need to populate 
 * 1. Sig_mtd
 * 2. C14N Mtd
 * 3. Sign parts
 *      3.1. Id
 *      3.2  Digest mtd
 *      3.3. Transforms*/

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_sig_process_signature_node(const axutil_env_t *env,
                                   oxs_sign_ctx_t *sign_ctx,
                                   axiom_node_t *signature_node,
                                   axiom_node_t *scope_node)
{
    axiom_node_t *cur_node = NULL;
    axiom_node_t *signed_info_node = NULL;
    axiom_node_t *sig_val_node = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axutil_array_list_t *sign_part_list = NULL;

    signed_info_node = oxs_axiom_get_first_child_node_by_name(env, signature_node,
                       OXS_NODE_SIGNEDINFO, OXS_DSIG_NS, OXS_DS );

    /*signed_info_node = oxs_axiom_get_first_child_node_by_name(env, signature_node,
                            OXS_NODE_SIGNEDINFO, NULL,NULL);*/

    if(!signed_info_node){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Cannot find <ds:SignedInfo> " );
        return AXIS2_FAILURE;
    }
    /*Create the list for sign parts*/
    sign_part_list = axutil_array_list_create(env,5);

    /*Process signed info element*/
    cur_node = axiom_node_get_first_element(signed_info_node, env);
    /*Iterate thru children of <SignedInfo>*/
    while(cur_node){
        axis2_char_t *localname =  NULL;

        localname  = axiom_util_get_localname(cur_node, env);

        if(0 == axutil_strcmp(localname, OXS_NODE_CANONICALIZATION_METHOD)){
            axis2_char_t *c14n_mtd = NULL;
            c14n_mtd = oxs_token_get_c14n_method(env, cur_node);
            oxs_sign_ctx_set_c14n_mtd(sign_ctx, env, c14n_mtd);

        }else if(0 == axutil_strcmp(localname, OXS_NODE_SIGNATURE_METHOD)){
            axis2_char_t *sig_mtd = NULL;
            sig_mtd = oxs_token_get_signature_method(env, cur_node);
            oxs_sign_ctx_set_sign_mtd_algo(sign_ctx, env, sig_mtd);

        }else if(0 == axutil_strcmp(localname, OXS_NODE_REFERENCE)){
            oxs_sign_part_t *sign_part = NULL;

            /* There might be multiple references.
             * For each create a sign_part and add to sign_part_list in the sign_ctx*/
            sign_part = oxs_sign_part_create(env);
            status = oxs_xml_sig_process_ref_node(env, sign_part, cur_node, scope_node);
            if(status == AXIS2_FAILURE){
                oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"<ds:Reference> node processing failed " );
                return AXIS2_FAILURE;
            }

            /*Now we have a new sign_part. Add it to the list.*/
            axutil_array_list_add(sign_part_list, env, sign_part);

        }else{
            /*We do not process*/
        }
        cur_node = axiom_node_get_next_sibling(cur_node, env);
    }

    oxs_sign_ctx_set_sign_parts(sign_ctx, env, sign_part_list);
    /*Finished processing SignedInfo. Now we are processing the Signature Value element*/
    /*The very next child of SignedInfo Should be the ds:SignatureValue*/
    sig_val_node = axiom_node_get_next_sibling(signed_info_node, env);
    if(0 == axutil_strcmp( OXS_NODE_SIGNATURE_VALUE, axiom_util_get_localname(sig_val_node, env))){
        axis2_char_t *sig_val = NULL;
        axis2_char_t *newline_removed = NULL;

        sig_val = oxs_token_get_signature_value(env, sig_val_node);
        if(!sig_val)
        {
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Cannot find signature value. " );
            return AXIS2_FAILURE;
        }
        /*We now remove \n in this text.Otherwise verifications failed.*/
        newline_removed = oxs_util_get_newline_removed_string(env,sig_val);
        if(!newline_removed)
        {
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Cannot Remove new lines. " );
            return AXIS2_FAILURE;
        }
        oxs_sign_ctx_set_sig_val(sign_ctx, env, newline_removed);

    }else{
        /*Error the node should be the ds:SignatureValue*/
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Cannot find <ds:SignatureValue> " );
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_sig_verify_sign_part(const axutil_env_t *env,
                             oxs_sign_part_t *sign_part)
{
    axis2_char_t *id = NULL;
    axis2_char_t *digest_mtd = NULL;
    axis2_char_t *digest_val = NULL;
    axis2_char_t *new_digest = NULL;
    axiom_node_t *node = NULL;
    axutil_array_list_t *transforms = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    id =            oxs_sign_part_get_id(sign_part, env);
    digest_mtd =    oxs_sign_part_get_digest_mtd(sign_part, env);
    digest_val =    oxs_sign_part_get_digest_val(sign_part, env);
    node =          oxs_sign_part_get_node(sign_part, env);
    transforms =    oxs_sign_part_get_transforms(sign_part, env);

    AXIS2_LOG_INFO(env->log, "[oxs][xml_sig] Verifying signature part %s ", id );

    /*Do transforms to the node*/
    new_digest = oxs_xml_sig_transform_n_digest(env, node, transforms, digest_mtd);

    /*Compare values*/
    if(0 == axutil_strcmp(new_digest, digest_val)){
        AXIS2_LOG_INFO(env->log, "[oxs][xml_sig] Digest verification success for node Id= %s ", id );
        status = AXIS2_SUCCESS;
    }else{
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Digest verification failed for node Id= %s  ", id );
        status =  AXIS2_FAILURE;
    }

    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_sig_verify_digests(const axutil_env_t *env,
                           oxs_sign_ctx_t *sign_ctx)
{
    axis2_status_t status = AXIS2_FAILURE;
    axutil_array_list_t *sign_parts = NULL;
    int i = 0 ;

    /*Get the sign_part list*/
    sign_parts =  oxs_sign_ctx_get_sign_parts(sign_ctx, env);
    /*For each and every signature part in sig ctx,*/
    for (i = 0; i < axutil_array_list_size(sign_parts, env); i++){
        oxs_sign_part_t *sign_part =  NULL;

        /*Get ith sign_part*/
        sign_part = (oxs_sign_part_t*)axutil_array_list_get(sign_parts, env, i);
        status = oxs_xml_sig_verify_sign_part(env, sign_part);
        if(AXIS2_FAILURE == status){
            return AXIS2_FAILURE;
        }
    }

    return status;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_sig_verify(const axutil_env_t *env,
                   oxs_sign_ctx_t *sign_ctx,
                   axiom_node_t *signature_node,
                   axiom_node_t *scope_node)
{
    axis2_status_t status = AXIS2_FAILURE;
    axiom_node_t *signed_info_node = NULL;
    axiom_document_t *doc = NULL;
    axis2_char_t *c14n_mtd = NULL;
    axis2_char_t *content = NULL;
    axis2_char_t *signature_val = NULL;

    /*Set operation to verify*/
    oxs_sign_ctx_set_operation(sign_ctx, env, OXS_SIGN_OPERATION_VERIFY);

    /*Populate the sign_ctx by inspecting the ds:Signature node*/
    status = oxs_xml_sig_process_signature_node(env, sign_ctx, signature_node, scope_node);
    if(status != AXIS2_SUCCESS){
        /*Something went wrong while processing the Signature node!!! :(*/
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"<ds:Signature> node processing failed " );
        return AXIS2_FAILURE;
    }

    /*-----------------------------------------------------------------------------------------*/
    /*At this point we have a ready to process signature context. So start verification process*/
    /*-----------------------------------------------------------------------------------------*/

    /*Verify the integrity of the signed parts by comparing the digest values of each and every reference.*/
    status = oxs_xml_sig_verify_digests(env, sign_ctx);

    if(AXIS2_FAILURE == status){
        return AXIS2_FAILURE;
    }else{
        AXIS2_LOG_INFO(env->log, "[oxs][xml_sig] Digests verification SUCCESS " );
    }

    /*At this point we have compared the digest. Next step is to compare the Signature value */
    /*First get the signature value from the context*/
    signature_val = oxs_sign_ctx_get_sig_val(sign_ctx, env);

    /*Then we apply the C14N for the ds:SignedInfo*/
    signed_info_node = oxs_axiom_get_first_child_node_by_name(env, signature_node,
                       OXS_NODE_SIGNEDINFO, OXS_DSIG_NS, OXS_DS );

    /*signed_info_node = oxs_axiom_get_first_child_node_by_name(env, signature_node,
                                OXS_NODE_SIGNEDINFO, NULL,NULL );*/

    c14n_mtd = oxs_sign_ctx_get_c14n_mtd(sign_ctx, env);
    doc = axiom_node_get_document(signed_info_node, env);

    AXIS2_LOG_INFO(env->log, "[oxs][xml_sig] C14N (verif1)= %s ", axiom_node_to_string(signed_info_node, env) );
    /*    oxs_c14n_apply(env, doc, AXIS2_FALSE, &content, AXIS2_TRUE, NULL, signed_info_node);*/

    oxs_c14n_apply_algo(env, doc, &content, NULL, signed_info_node, c14n_mtd);

    AXIS2_LOG_INFO(env->log, "[oxs][xml_sig] C14N (verif2)=\n\n%s\n\n", content );

    /*In the final step we Verify*/
    status = oxs_sig_verify(env, sign_ctx, content , signature_val);
    if(AXIS2_FAILURE == status){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Signature is not valid " );
        return AXIS2_FAILURE;
    }else{
        return AXIS2_SUCCESS;
    }


}
