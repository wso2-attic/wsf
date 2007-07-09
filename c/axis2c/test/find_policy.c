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

axiom_node_t * return_policy_element(axis2_char_t *name, const axutil_env_t *env, axis2_char_t *wsdl_name);
axis2_char_t * get_policy_ref(axiom_node_t * node, const axutil_env_t * env);
void get_all_policy(axis2_char_t * element_name,  const axutil_env_t * env, axutil_array_list_t * policy_node_list, axis2_char_t *wsdl_name);
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
FILE *o = NULL;
/** a method that demonstrate creating a om model using an xml file */


int AXIS2_CALL read_input(char *buffer, int size, void* ctx)
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
main(int argc, char *argv[])
{
	axutil_qname_t * qname = NULL;
	axiom_node_t *policy_node = NULL, *node = NULL;

	axiom_xml_writer_t *writer = NULL;
	axiom_output_t *om_output = NULL;
	axis2_char_t * pol_ref = NULL;
	axiom_element_t * policy_element = NULL, *ele = NULL;
	axiom_node_t *child_node = NULL;
	axutil_array_list_t * policy_array = NULL;

	char *buffer = NULL;
	
    const char *file_name = "C:\\OMWsdl\\wsdltest\\debug\\PolicyAttachments.wsdl";
	const char *out_file_name = "C:\\OMWsdl\\wsdltest\\debug\\out.xml";
    
    allocator = axutil_allocator_init(NULL);
    axis_log = axutil_log_create(allocator, NULL, NULL);
    error = axutil_error_create(allocator);

    environment = axutil_env_create_with_error_log(allocator, error,  axis_log);
    
	policy_array = axutil_array_list_create(environment, 10);
	
	//get all the policy values of "Binding_2B"
	get_all_policy("Binding-2B", environment, policy_array, file_name);


	node = (axiom_node_t *) axutil_array_list_get(policy_array, environment, 2);

	ele = (axiom_element_t *)axiom_node_get_data_element(node, environment);

	qname = axiom_element_get_qname(ele, environment, node);
	
	printf("qname %s\n", axutil_qname_get_uri(qname, environment));



	writer = axiom_xml_writer_create_for_memory(environment, NULL, AXIS2_TRUE, 0,
            AXIS2_XML_PARSER_TYPE_BUFFER);
    om_output = axiom_output_create(environment, writer);

	axiom_node_serialize(node, environment , om_output);

	buffer = (axis2_char_t*)axiom_xml_writer_get_xml(writer, environment);

    if (buffer)
	{
		//printf(outfilename);
		o = fopen("C:\\OMWsdl\\wsdltest\\debug\\out.xml","w");
		if (!o)
			return -1;
		printf("Printing the Buffer...\n");
        printf("%s", buffer);
		fprintf(o,"<?xml version=\"1.0\" ?>\n%s",buffer); 
	}
	axiom_output_free(om_output, environment);
    fclose(f);

    axutil_env_free(environment);
    return 0;
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
	axiom_attribute_t * attr = NULL;
	axis2_char_t * value = NULL;
    axis2_char_t * val = NULL;
	axutil_hash_t *attr_hash = NULL;
	axis2_char_t *xml_output = NULL;
	axutil_hash_index_t *hi;

	f = fopen(wsdl_name, "r");
    if (!f)
        return NULL;

    reader = axiom_xml_reader_create_for_io(environment, read_input, NULL , NULL, NULL);

    if (!reader)
    {
        printf("ERROR CREATING PULLPARSER");
        return NULL;
    }
    
    builder = axiom_stax_builder_create(environment, reader);

    if (!builder)
    {
        printf("ERROR CREATING PULL PARSER");
        return NULL;
    }
    
    document = axiom_stax_builder_get_document(builder, environment);
    if (!document)
        return NULL;

	node1 = axiom_document_get_root_element(document, environment);
    if (!node1)
    {
        printf(" root element null ");
		axiom_stax_builder_free(builder, environment);
		return  NULL;
    }
    
    do
    {
		node2 = axiom_document_build_next(document , environment);
		
		if (!node2)
            break;

        if (axiom_node_get_node_type(node2, environment) == AXIOM_ELEMENT)
        {
            ele2 = (axiom_element_t*) axiom_node_get_data_element(node2, environment);
			attr_hash = axiom_element_get_all_attributes(ele2, environment);
			if (attr_hash)
			{
				hi = axutil_hash_first(attr_hash, environment);
				axutil_hash_this(hi, NULL, NULL, &attr);

				if (axutil_strcmp(axiom_attribute_get_value(attr, environment), name) == 0)
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
		if(axiom_node_get_node_type(child_node, environment) == AXIOM_ELEMENT)
		{
			policy_element = (axiom_element_t*) axiom_node_get_data_element(child_node, environment);
			
			if (axutil_strcmp(axiom_element_get_localname(policy_element, environment), "PolicyReference") == 0)
			{
				qname = axutil_qname_create(environment, "URI", NULL, NULL);
				attr = axiom_element_get_attribute(policy_element, environment, qname);
				
				if (attr)
				{
					value = axiom_attribute_get_value(attr, environment);
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