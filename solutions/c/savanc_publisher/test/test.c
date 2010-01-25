#include "../src/reg_client_constants.h"
#include "../src/reg_client_rest_client.h"
#include "../src/reg_client_remote_reg.h"
#include <axutil_url.h>
#include <axutil_string.h>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>
#include <axiom_xml_reader.h>
#include <axiom_stax_builder.h>
#include <axiom_document.h>
#include <axiom_node.h>
#include <axiom_element.h>

int main(void)
{
    axutil_env_t *env = NULL;
    reg_client_remote_reg_t *remote_reg = NULL;
    axis2_char_t *root = "/topics";

    env = axutil_env_create_all("./test.log", AXIS2_LOG_LEVEL_DEBUG);

    reg_client_remote_reg_init(env);
    remote_reg = reg_client_remote_reg_create(env, NULL, NULL);
    reg_client_remote_reg_get(remote_reg, env, root, NULL, NULL);  

    reg_client_remote_reg_free(remote_reg, env);
    return 0;
}

/*int main(void)
{
    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *om_builder = NULL;
    axiom_document_t *document = NULL;
    axutil_env_t *env = NULL;
    axiom_node_t *sub_node = NULL;
    axiom_element_t *sub_elem = NULL;

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);
    
    reader = axiom_xml_reader_create_for_file(env, "./atom_data.xml", NULL);
    if(reader)
    {
        om_builder = axiom_stax_builder_create(env, reader);
        document = axiom_stax_builder_get_document(om_builder, env);
        axiom_document_build_all(document, env);
        if(document)
        {
            sub_node = axiom_document_get_root_element(document, env);
            sub_elem = (axiom_element_t*) axiom_node_get_data_element(sub_node, env);
    
            if(sub_elem)
            {
                axutil_qname_t *qname = NULL;
                axiom_node_t *id_node = NULL;
                axiom_element_t *id_elem = NULL;

                qname = axutil_qname_create(env, "Identifier", "http://schemas.xmlsoap.org/ws/2004/08/eventing", NULL);
                id_elem = axiom_element_get_first_child_with_qname(sub_elem, env, qname, sub_node, &id_node);
                axutil_qname_free(qname, env);
               
                if(id_elem)
                {
                    axis2_char_t *sub_id = NULL;

                    sub_id = axiom_element_get_text(id_elem, env, id_node);
                    if(sub_id)
                    {
                        printf("sub_id:%s\n", sub_id);
                    }
                }
            }
        }
    }
    return 0;
}
*/
