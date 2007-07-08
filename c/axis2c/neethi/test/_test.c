#include <axiom.h>
#include <axutil_utils.h>
#include <axutil_env.h>
#include <axutil_log_default.h>
#include <axutil_error_default.h>
#include <stdio.h>
#include <axiom_xml_reader.h>
#include <neethi_engine.h>

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

    root = axiom_document_get_root_element(document, env);
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
                    neethi_policy_t *normalized = NULL;
                    printf("Policy object successfuly created\n");
                    normalized = neethi_engine_normalize(env, neethi_policy,NULL,AXIS2_TRUE);
                }
            }
        }
    }
    printf("Successful\n");
    return 0;

}


