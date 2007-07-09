#include <axiom.h>
#include <axutil_utils.h>
#include <axutil_env.h>
#include <axutil_log_default.h>
#include <axutil_error_default.h>
#include <stdio.h>
#include <axiom_xml_reader.h>
#include <neethi_engine.h>


axis2_status_t AXIS2_CALL
om_node_serialize(
    axiom_node_t *node,
    const axutil_env_t *env);



int main(int argc, char **argv)
{
    axutil_allocator_t *allocator = axutil_allocator_init (NULL);
    axutil_error_t *error = axutil_error_create (allocator);
    const axutil_env_t *env = axutil_env_create_with_error(allocator, error);

    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_document_t *document = NULL;
    axiom_node_t *root = NULL;
    axiom_element_t *root_ele = NULL;

    reader = axiom_xml_reader_create_for_file(env,argv[1],NULL);

    if (!reader)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CREATING_XML_STREAM_READER,
                AXIS2_FAILURE);
        printf("xml reader creation failed\n");
        return 0;
    }
    
    builder = axiom_stax_builder_create(env, reader);
    if(!builder)
    {
        axiom_xml_reader_free(reader, env);
        printf("Builder creation failed\n");
        return 0;
    }
    document = axiom_stax_builder_get_document(builder, env);
    if(!document)
    {
        axiom_stax_builder_free(builder, env);
        printf("Document creation failed\n");
        return 0;
    }

    /*root = axiom_document_get_root_element(document, env);*/
    root = axiom_document_build_all(document, env);
    if(!root)
    {
        axiom_stax_builder_free(builder, env);
        return 0;
    }

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
                    return 0;
                }
                else
                {
                    axiom_node_t *s_node = NULL;
                    s_node = neethi_engine_serialize(neethi_policy, env);
                    if(!s_node)
                    {
                        printf("Serializing failed\n");
                        return 0;
                    }
                    if(om_node_serialize(s_node, env)!=AXIS2_SUCCESS)
                        return 0;
                }
            }
        }
    }
    
    printf("Successful\n");
    return 0;

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

    /*axiom_node_free_tree(node1, environment);*/
    output_buffer = (axis2_char_t*)axiom_xml_writer_get_xml(writer, env);

    printf("\nend test_om_serialize\n");

}



axutil_array_list_t *AXIS2_CALL
load_policy_array(
    int argc, 
    char **argv,
    const axutil_env_t *env)
{
    
    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_document_t *document = NULL;
    axiom_node_t *root = NULL;
    axiom_element_t *root_ele = NULL;
    int i = 0;    
    axutil_array_list *arraylist = NULL;

    arraylist = axutil_array_list_create(env, 0);

    for(i=1; i<argc; i++)
    {
        reader = axiom_xml_reader_create_for_file(env,argv[i],NULL);

        if (!reader)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CREATING_XML_STREAM_READER,
                    AXIS2_FAILURE);
            printf("xml reader creation failed\n");
            return NULL;
        }

        builder = axiom_stax_builder_create(env, reader);
        if(!builder)
        {
            axiom_xml_reader_free(reader, env);
            printf("Builder creation failed\n");
            return NULL;
        }
        document = axiom_stax_builder_get_document(builder, env);
        if(!document)
        {
            axiom_stax_builder_free(builder, env);
            printf("Document creation failed\n");
            return NULL;
        }

        /*root = axiom_document_get_root_element(document, env);*/
        root = axiom_document_build_all(document, env);
        if(!root)
        {
            axiom_stax_builder_free(builder, env);
            return NULL;
        }
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
                        return NULL;
                    }
                    axutil_array_list_add(arraylist, env, neethi_policy);
                }
            }
        }
    }
    return arraylist;
}

