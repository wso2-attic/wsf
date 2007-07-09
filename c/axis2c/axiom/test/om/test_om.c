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

#include <axiom_stax_builder.h>
#include <axiom_document.h>
#include <axiom_node.h>
#include <axiom_element.h>
#include <axiom_text.h>
#include <axiom_data_source.h>
#include <axutil_stream.h>
#include <axutil_log_default.h>
#include <axutil_error_default.h>
#include <axiom_xml_reader.h>
#include <stdio.h>
#include <axiom_xml_writer.h>
#include <axutil_env.h>
/**
   Define the environment related variables globaly so that they are available
   for both functions
*/

axutil_allocator_t *allocator = NULL;
axutil_env_t *environment = NULL;
axutil_stream_t *stream = NULL;
axutil_error_t *error = NULL;
axutil_log_t *axis_log     = NULL;
FILE *f = NULL;
/** a method that demonstrate creating a om model using an xml file */


int read_input(char *buffer, int size, void* ctx)
{
    int len = 0;
    char* pos = NULL;
    len = fread(buffer, sizeof(char), size, f);
    if (buffer)
        pos = strstr(buffer, "---");
    if (pos)
    {
        len = pos - buffer;
        *pos = '\0';
    }
    return len;
}

int
test_om_build(const char *filename)
{
    axiom_element_t *ele1 = NULL, *ele2 = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_text_t *text = NULL;
    axiom_document_t *document = NULL;
    axiom_node_t *node1 = NULL, *node2 = NULL;
    axiom_node_t *node3 = NULL;
    axiom_output_t *om_output = NULL;
    axiom_namespace_t* ns = NULL;
    axiom_xml_reader_t *reader = NULL;
    axiom_xml_writer_t *writer = NULL;
    char *buffer = NULL;
    
    printf("\nstart test_om_build\n");
        
    f = fopen(filename, "r");
    if (!f)
        return -1;

    /** create pull parser */
    reader = axiom_xml_reader_create_for_io(environment, read_input, NULL , NULL, NULL);

    if (!reader)
    {
        printf("ERROR CREATING PULLPARSER");
        return -1;
    }
    /** create axiom_stax_builder by parsing pull_parser struct */

    builder = axiom_stax_builder_create(environment, reader);

    if (!builder)
    {
        printf("ERROR CREATING PULL PARSER");
        return -1;
    }
    /**
        create an om document
        document is the container of om model created using builder 
    */

    document = axiom_stax_builder_get_document(builder, environment);
    /**
        get root element , building starts hear 
     */
    if (!document)
        return -1;

    node1 = axiom_document_get_root_element(document, environment);
    if (!node1)
    {
        printf(" root element null ");
        axiom_stax_builder_free(builder, environment);
        return -1;
    }
    if (node1)
    {
        /** print root node information */


        ele1 = axiom_node_get_data_element(node1, environment);
        if (ele1)

            printf("root localname %s\n", axiom_element_get_localname(ele1, environment));

        ns = axiom_element_get_namespace(ele1, environment, node1);

        if (ns)
        {
            printf("root ns prefix %s\n", axiom_namespace_get_prefix(ns, environment));
            printf("root ns uri %s\n", axiom_namespace_get_uri(ns, environment));

        }
    }
    /** build the document continuously untill all the xml file is built in to a om model */


    node2 = axiom_document_build_next(document , environment);
    do
    {

        if (!node2)
            break;

        switch (axiom_node_get_node_type(node2, environment))
        {
            case AXIOM_ELEMENT:
                ele2 = (axiom_element_t*) axiom_node_get_data_element(node2, environment);
                if (ele2 && axiom_element_get_localname(ele2, environment))
                {
                    printf("\n localname %s\n" , axiom_element_get_localname(ele2, environment));
                }
                if (!node3)
                    node3 = node2;

                break;
            case AXIOM_TEXT:

                text = (axiom_text_t *)axiom_node_get_data_element(node2, environment);
                if (text && axiom_text_get_value(text , environment))
                    printf("\n text value  %s \n", axiom_text_get_value(text, environment));
                break;

            default:
                break;
        }

        node2 = axiom_document_build_next(document , environment);
    }
    while (node2);
    printf("END: pull document\n");

    printf("Serialize pulled document\n");

    writer = axiom_xml_writer_create_for_memory(environment, NULL, AXIS2_TRUE, 0,
            AXIS2_XML_PARSER_TYPE_BUFFER);
    om_output = axiom_output_create(environment, writer);

    axiom_node_serialize_sub_tree(node3, environment , om_output);

    buffer = (axis2_char_t*)axiom_xml_writer_get_xml(writer, environment);

    if (buffer)
        printf("%s", buffer);

    axiom_output_free(om_output, environment);

    axiom_stax_builder_free(builder, environment);
/*     if (buffer) */
/*         AXIS2_FREE(environment->allocator, buffer); */
    printf("\nend test_om_build\n");
    fclose(f);
    return 0;
}



int
test_om_serialize()
{

    /*
       <book xmlns:axiomc="http://ws.apache.org/axis2/c/om" xmlns:isbn="urn:ISBN:0-395-74341-6">
       <title>Axis2/C OM HOWTO</title>
       <isbn:number>1748491379</isbn:number>
       <author title="Mr" name="Axitoc Oman" />
       <notes>
       <p xmlns="urn:w3-org-ns:HTML">
       This is <i>vey good</i> book on OM!
       </p>
       </notes>
       </book>
    */
    int status;
    axiom_element_t *ele1 = NULL, *ele2 = NULL, *ele3 = NULL, *ele4 =
                NULL;
    axiom_node_t *node1 = NULL, *node2 = NULL, *node3 = NULL, *node4 =
                NULL, *node5 = NULL, *node6 = NULL;
    axiom_data_source_t *data_source = NULL;
    axutil_stream_t *stream = NULL;
    axiom_attribute_t *attr1 = NULL, *attr2 = NULL;
    axiom_namespace_t *ns1 = NULL, *ns2 = NULL;
    axiom_text_t *text1 = NULL;
    axiom_output_t *om_output = NULL;
    axiom_xml_writer_t *writer = NULL;
    axis2_char_t *output_buffer = NULL;
    
    printf("\nstart test_om_serialize\n");

    ns1 =
        axiom_namespace_create(environment,
                "http://ws.apache.org/axis2/c/om",
                "axiom");
    ns2 =
        axiom_namespace_create(environment, "urn:ISBN:0-395-74341-6",
                "isbn");
    ele1 = axiom_element_create(environment, NULL, "book", ns1, &node1);
    axiom_element_declare_namespace(ele1, environment, node1, ns2);

    ele2 = axiom_element_create(environment, node1, "title", ns1, &node2);
    attr1 = axiom_attribute_create(environment, "title22", NULL, NULL);

    axiom_element_add_attribute(ele2, environment, attr1, node2);

    text1 = axiom_text_create(environment, node2, "Axis2/C OM HOWTO", &node3);

    ele3 = axiom_element_create(environment, node1, "number", ns2, &node4);

    text1 = axiom_text_create(environment, node4, "1748491379", &node5);

    ele4 = axiom_element_create(environment, node1, "author", ns1, &node6);

    attr1 = axiom_attribute_create(environment, "title", "Mr", ns1);

    axiom_element_add_attribute(ele4, environment, attr1, node6);

    attr2 = axiom_attribute_create(environment, "name", "Axitoc Oman", ns1);

    axiom_element_add_attribute(ele4, environment, attr2, node6);

    data_source = axiom_data_source_create(environment, node1, &node6);
    stream = axiom_data_source_get_stream(data_source, environment);
    if (stream)
    {
        axutil_stream_write(stream, environment, "<this xmlns:axiom=\"http://ws.apache.org/axis2/c/om\">is a test</this>", 
            axutil_strlen("<this xmlns:axiom=\"http://ws.apache.org/axis2/c/om\">is a test</this>"));
    }

    /* serializing stuff */
    writer = axiom_xml_writer_create_for_memory(environment, NULL, AXIS2_TRUE, 0,
            AXIS2_XML_PARSER_TYPE_BUFFER);
    om_output = axiom_output_create(environment, writer);

    printf("Serialize built document\n");
    status = axiom_node_serialize(node1, environment , om_output);
    if (status != AXIS2_SUCCESS)
    {
        printf("\naxiom_node_serialize failed\n");
        return status;
    }
    else
        printf("\naxiom_node_serialize success\n");
    /* end serializing stuff */

    axiom_node_free_tree(node1, environment);
    output_buffer = (axis2_char_t*)axiom_xml_writer_get_xml(writer, environment);

    axiom_output_free(om_output, environment);
	/*    if (output_buffer) */
	/*     { */
	/*         printf("%s", output_buffer); */
	/*         AXIS2_FREE(environment->allocator, output_buffer); */
	/*     } */

    printf("\nend test_om_serialize\n");

    return 0;
}


int
main(int argc, char *argv[])
{
    const char *file_name = "../../resources/xml/om/test.xml";
    if (argc > 1)
        file_name = argv[1];
    allocator = axutil_allocator_init(NULL);
    axis_log = axutil_log_create(allocator, NULL, NULL);
    error = axutil_error_create(allocator);

    environment = axutil_env_create_with_error_log(allocator, error,  axis_log);
    test_om_build(file_name);
    test_om_serialize();

    axutil_env_free(environment);
    return 0;
}


