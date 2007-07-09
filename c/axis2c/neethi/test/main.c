#include <axiom.h>
#include <axutil_utils.h>
#include <axutil_env.h>
#include <axutil_log_default.h>
#include <axutil_error_default.h>
#include <stdio.h>
#include <axiom_xml_reader.h>
#include <neethi_engine.h>
#include <axutil_hash.h>

axis2_status_t AXIS2_CALL
om_node_serialize(
    axiom_node_t *node,
    const axutil_env_t *env);

/*axis2_status_t AXIS2_CALL
load_policy_array(
        axutil_array_list_t *arraylist,
        axis2_char_t *file_name,
        const axutil_env_t *env);
*/
axis2_status_t AXIS2_CALL
load_policy_array(
        axutil_array_list_t *arraylist,
        axiom_node_t *root,
        const axutil_env_t *env);

axiom_node_t * return_policy_element(axis2_char_t * name, const axutil_env_t * env, axis2_char_t * wsdl_name);

axis2_char_t * get_policy_ref(axiom_node_t *node, const axutil_env_t * env);

void get_all_policy(axis2_char_t * element_name, const axutil_env_t * env, axutil_array_list_t * policy_node_list, axis2_char_t *wsdl_name);



neethi_policy_t *AXIS2_CALL
merge_policylist(
    axutil_array_list_t *arraylist,
    const axutil_env_t *env);


int main(int argc, char **argv)
{
    axis2_status_t status = AXIS2_FAILURE;
    int i = 0;
    axutil_array_list_t *policy_list = NULL;
    axutil_array_list_t *policy_node_list = NULL;
    neethi_policy_t *resultant = NULL;
    axutil_allocator_t *allocator = axutil_allocator_init (NULL);
    axutil_error_t *error = axutil_error_create (allocator);
    const axutil_env_t *env = axutil_env_create_with_error(allocator, error);

    policy_list = axutil_array_list_create(env, 0);
    policy_node_list = axutil_array_list_create(env, 0);

    get_all_policy(argv[1], env, policy_node_list, argv[2]);


    for(i=0; i<axutil_array_list_size(policy_node_list, env); i++)
    {
        axiom_node_t *node = NULL;
        node = (axiom_node_t *)axutil_array_list_get(policy_node_list, env, i);
        status = load_policy_array(policy_list, node, env);       
    }        
        
    resultant = merge_policylist(policy_list, env);
    if(!resultant)
    {
        printf("Error Merging\n");
        return 0;
    }
    else
    {
        axiom_node_t *s_node = NULL;
        axis2_char_t *buff = NULL;
        s_node = neethi_engine_serialize(resultant, env);
        if(!s_node)
        {
            printf("Serializing failed\n");
            return 0;
        }
        buff = axiom_node_to_string(s_node, env);
        printf("\n%s",buff);
    }
    printf("Successful\n");
    return 0;

}

neethi_policy_t *AXIS2_CALL
merge_policylist(
    axutil_array_list_t *arraylist,
    const axutil_env_t *env)
{
    int i = 0;    
    neethi_policy_t *policy = NULL;
    neethi_policy_t *result = NULL;

    result = (neethi_policy_t *)axutil_array_list_get(arraylist, env, 0);
    result = (neethi_policy_t *)neethi_engine_get_normalize(env, AXIS2_FALSE, result);

    for(i=1; i<axutil_array_list_size(arraylist, env); i++)
    {
        policy = (neethi_policy_t *)axutil_array_list_get(arraylist, env, i);
        policy = (neethi_policy_t *)neethi_engine_get_normalize(env, AXIS2_FALSE, policy);
        result = (neethi_policy_t*) neethi_engine_merge(env,policy, result);
    }
    return result;
}




axis2_status_t AXIS2_CALL
om_node_serialize(
    axiom_node_t *node,
    const axutil_env_t *env)
{

    axiom_output_t *om_output = NULL;
    axiom_xml_writer_t *writer = NULL;
    axis2_char_t *output_buffer = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_TRUE, 0,
                                    AXIS2_XML_PARSER_TYPE_BUFFER);
    om_output = axiom_output_create(env, writer);

    status = axiom_node_serialize(node, env , om_output);
    if (status != AXIS2_SUCCESS)
    {
        printf("\naxiom_node_serialize failed\n");
        return 0;
    }
    else
        printf("\naxiom_node_serialize success\n");
        /* end serializing stuff */

    /*axiom_node_free_tree(node1, env);*/
    output_buffer = (axis2_char_t*)axiom_xml_writer_get_xml(writer, env);

    printf("\nend test_om_serialize\n");

}



axis2_status_t AXIS2_CALL
load_policy_array(
        axutil_array_list_t *arraylist,
        axiom_node_t *root,
        const axutil_env_t *env)
{
    
    axiom_element_t *root_ele = NULL;
        
    if(root)
    {
        if(axiom_node_get_node_type(root, env) == AXIOM_ELEMENT)
        {
            root_ele = (axiom_element_t*)axiom_node_get_data_element(root, env);
            if(root_ele)
            {
                neethi_policy_t *neethi_policy = NULL;
                neethi_policy = neethi_engine_get_policy(env,root,root_ele);
                if(!neethi_policy)
                {
                    printf("Policy Creation fails\n");
                    return AXIS2_FAILURE;
                }
                axutil_array_list_add(arraylist, env, neethi_policy);
            }
        }
    }
    return AXIS2_SUCCESS;
}


axiom_node_t * return_policy_element(axis2_char_t * name, const axutil_env_t * env, axis2_char_t * wsdl_name)
{
    axiom_element_t *ele1 = NULL, *ele2 = NULL;
    axiom_document_t *document = NULL;
    axiom_node_t *node1 = NULL, *node2 = NULL, *policy_node = NULL;
    axiom_namespace_t* ns = NULL;
    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *builder = NULL;
    char *buffer = NULL;
    axiom_attribute_t *attr = NULL;
    axis2_char_t * value = NULL;
    axis2_char_t * val = NULL;
    axutil_hash_t *attr_hash = NULL;
    axis2_char_t *xml_output = NULL;
    axutil_hash_index_t *hi;

/*
    f = fopen(wsdl_name, "r");
    if (!f)
        return NULL;

    reader = axiom_xml_reader_create_for_io(env, read_input, NULL , NULL, NULL);
*/
    reader = axiom_xml_reader_create_for_file(env, wsdl_name, NULL);

    if (!reader)
    {
        printf("ERROR CREATING PULLPARSER");
        return NULL;
    }

    builder = axiom_stax_builder_create(env, reader);

    if (!builder)
    {
        printf("ERROR CREATING PULL PARSER");
        return NULL;
    }

    document = axiom_stax_builder_get_document(builder, env);
    if (!document)
        return NULL;

    node1 = axiom_document_get_root_element(document, env);
    if (!node1)
    {
        printf(" root element null ");
        axiom_stax_builder_free(builder, env);
        return  NULL;
    }

    do
    {
        node2 = axiom_document_build_next(document , env);

        if (!node2)
            break;

        if (axiom_node_get_node_type(node2, env) == AXIOM_ELEMENT)
        {
            ele2 = (axiom_element_t*) axiom_node_get_data_element(node2, env);
            attr_hash = axiom_element_get_all_attributes(ele2, env);
            if (attr_hash)
            {
                hi = axutil_hash_first(attr_hash, env);
                axutil_hash_this(hi, NULL, NULL, &attr);

                if (axutil_strcmp(axiom_attribute_get_value(attr, env), name) == 0)
                {
                    policy_node = node2;
                 }
            }
        }
   }while (node2);
   return policy_node;
}

axis2_char_t * get_policy_ref(axiom_node_t *node, const axutil_env_t * env)
{
    axiom_element_t *policy_element = NULL;
    axiom_children_iterator_t *children_iter = NULL;
    axiom_node_t *child_node = NULL;
    axutil_qname_t *qname = NULL;
    axis2_char_t * value = NULL;
    axis2_char_t * val = NULL;
    axiom_attribute_t * attr = NULL;

    policy_element = (axiom_element_t *) axiom_node_get_data_element(node, env);
    children_iter = axiom_element_get_children(policy_element, env, node);

    while(axiom_children_iterator_has_next(children_iter, env))
    {
        child_node = axiom_children_iterator_next(children_iter, env);
        if(axiom_node_get_node_type(child_node, env) == AXIOM_ELEMENT)
        {
            policy_element = (axiom_element_t*) axiom_node_get_data_element(child_node, env);

            if (axutil_strcmp(axiom_element_get_localname(policy_element, env), "PolicyReference") == 0)
            {
                qname = axutil_qname_create(env, "URI", NULL, NULL);
                attr = axiom_element_get_attribute(policy_element, env, qname);

                if (attr)
                {
                    value = axiom_attribute_get_value(attr, env);
                    val = axutil_string_substring_starting_at(value, 1);
                    return val;
                }
            }
        }
    }
    return NULL;
}


void get_all_policy(axis2_char_t * element_name, const axutil_env_t * env, axutil_array_list_t * policy_node_list, axis2_char_t *wsdl_name)
{
    axutil_hash_t *attr_hash = NULL;
    axutil_hash_index_t *hi = NULL;
    axiom_element_t *element = NULL;
    axiom_attribute_t *attribute = NULL;
    axis2_char_t * attribute_val = NULL;
    axiom_node_t * parent_policy_node = NULL, *parent_node = NULL;

    parent_node = return_policy_element(element_name, env, wsdl_name);
    if (!parent_node)
        return;

    parent_policy_node = return_policy_element(get_policy_ref(parent_node, env), env, wsdl_name);
    axutil_array_list_add(policy_node_list, env, parent_policy_node);

    if (axiom_node_get_node_type(parent_node, env) == AXIOM_ELEMENT)
    {
        element = (axiom_element_t*) axiom_node_get_data_element(parent_node, env);
        attr_hash = axiom_element_get_all_attributes(element, env);
        if (attr_hash)
        {
            hi = axutil_hash_next(env, axutil_hash_first(attr_hash, env));
            do
            {
                if (hi)
                {
                    axutil_hash_this(hi, NULL, NULL, &attribute);
                    attribute_val = axiom_attribute_get_value(attribute, env);
                    attribute_val = axutil_rindex(attribute_val, ':');
                    attribute_val = axutil_string_substring_starting_at(attribute_val,1);
                    get_all_policy(attribute_val, env, policy_node_list, wsdl_name);
                    hi = axutil_hash_next(env, hi);
                }
            }while (hi);
        }
    }
    return;
}

