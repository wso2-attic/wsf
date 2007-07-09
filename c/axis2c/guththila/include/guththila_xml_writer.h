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
#ifndef GUTHTHILA_XML_WRITER_H
#define GUTHTHILA_XML_WRITER_H

#include <guththila_token.h>
#include <guththila_defines.h>
#include <guththila_buffer.h>
#include <guththila.h>
#include <axutil_utils.h>

EXTERN_C_START()

#define GUTHTHILA_XML_WRITER_TOKEN
/*
Design notes:-
namesp member of guththila_xml_writer_s is populated with malloc created objects. 
Providing a list for this seems expensive because most of the times only few 
namespaces are present in a XML document.  

element member of guththila_xml_writer_s must be povided the list capablity. This 
is particularly important in very deep XML documents.
*/
typedef enum guththila_writer_type_s
{
	GUTHTHILA_WRITER_FILE = 1,
	GUTHTHILA_WRITER_MEMORY
} guththila_writer_type_t;

typedef struct guththila_writer_s
{
	short type;
	FILE *out_stream;
	guththila_buffer_t *buffer;
	int next;
} guththila_writer_t;

typedef enum guththila_writer_status_s
{
	/*Started writing a non empty element*/
	START = 1,
	/*Started writing a empty element*/
	START_EMPTY,
	/*We are in a position to begin wrting an element*/
	BEGINING
} guththila_writer_status_t;

/*Main structure which provides the writer capability*/
typedef struct guththila_xml_writer_s
{
	guththila_stack_t element;
	guththila_stack_t namesp;
	guththila_writer_t *writer;
#ifdef GUTHTHILA_XML_WRITER_TOKEN
	guththila_tok_list_t tok_list;
#endif
	/* Type of this writer. Can be file writer or memory writer*/ 
	guththila_writer_type_t type;

	FILE *out_stream;
	guththila_buffer_t buffer;
	guththila_writer_status_t status;
	int next;
} guththila_xml_writer_t;

/*TODO: we need to came up with common implementation of followng two structures in writer and reader*/
/* 
This is a private structure for keeping track of the elements. When we start to write an element this structure will be pop
*/
typedef struct guththila_xml_writer_element_s
{
#ifdef GUTHTHILA_XML_WRITER_TOKEN
	guththila_token_t *prefix;
	guththila_token_t *name;	
#else 
	guththila_char *prefix;
	guththila_char *name;
#endif
	/* contains the number of the stack which holds the namespaces 
	for this element. When we close this element all the namespaces 
	that are below this should also must be closed*/
	int name_sp_stack_no;
} guththila_xml_writer_element_t;

typedef struct guththila_xml_writer_namesp_s
{
	/* These are double pointers because a single element may contain multple 
	namespace declarations */
#ifdef GUTHTHILA_XML_WRITER_TOKEN
	guththila_token_t **name;
	guththila_token_t **uri;	
#else
	guththila_char **name;
	guththila_char **uri;
#endif
	int no;	/*number of namespaces*/
	int size;
} guththila_xml_writer_namesp_t;

#define GUTHTHILA_XML_WRITER_NAMESP_DEF_SIZE 4

/*Writer functions*/
GUTHTHILA_EXPORT guththila_xml_writer_t *  GUTHTHILA_CALL
guththila_create_xml_stream_writer(char *file_name, const axutil_env_t *env);

GUTHTHILA_EXPORT guththila_xml_writer_t *  GUTHTHILA_CALL
guththila_create_xml_stream_writer_for_memory(const axutil_env_t *env);

GUTHTHILA_EXPORT int GUTHTHILA_CALL
guththila_write_to_buffer (guththila_xml_writer_t *wr, char *buff, int size, const axutil_env_t *env);

GUTHTHILA_EXPORT int  GUTHTHILA_CALL
guththila_write_namespace (guththila_xml_writer_t *wr, char *prefix, char *uri, const axutil_env_t *env);

GUTHTHILA_EXPORT int GUTHTHILA_CALL
guththila_do_write_attribute_with_prefix_and_namespace (guththila_xml_writer_t *wr,
									char *prefix, 
									char *namespace_uri,
									char *local_name, 
									char *value,
									const axutil_env_t *env);

GUTHTHILA_EXPORT int   GUTHTHILA_CALL
guththila_write_start_document (guththila_xml_writer_t *wr, const axutil_env_t *env);

GUTHTHILA_EXPORT int   GUTHTHILA_CALL
guththila_write_start_element ( guththila_xml_writer_t *wr, char *start_element, const axutil_env_t *env);


GUTHTHILA_EXPORT int   GUTHTHILA_CALL
guththila_write_end_element ( guththila_xml_writer_t *wr, const axutil_env_t *env);


GUTHTHILA_EXPORT int  GUTHTHILA_CALL
guththila_close ( guththila_xml_writer_t *wr, const axutil_env_t *env);


GUTHTHILA_EXPORT int   GUTHTHILA_CALL
guththila_write_characters (guththila_xml_writer_t *wr, char  *buff, const axutil_env_t *env);


GUTHTHILA_EXPORT int   GUTHTHILA_CALL
guththila_write_comment (guththila_xml_writer_t *wr, char *buff, const axutil_env_t *env);

GUTHTHILA_EXPORT int   GUTHTHILA_CALL
guththila_write_escape_character (guththila_xml_writer_t *wr, char *buff, const axutil_env_t *env);


GUTHTHILA_EXPORT int   GUTHTHILA_CALL
guththila_write_empty_element (guththila_xml_writer_t *wr, char *empty_element, const axutil_env_t *env);


GUTHTHILA_EXPORT int  GUTHTHILA_CALL
guththila_write_default_namespace (guththila_xml_writer_t *wr, char *namespace_uri, const axutil_env_t *env);



GUTHTHILA_EXPORT int   GUTHTHILA_CALL
guththila_write_attribute (guththila_xml_writer_t *wr, char *localname, char *value, const axutil_env_t *env);


GUTHTHILA_EXPORT int   GUTHTHILA_CALL
guththila_write_attribute_with_prefix_and_namespace (guththila_xml_writer_t *wr, char *prefix, 
								     char *namespace_uri, char *localname, char *value, const axutil_env_t *env);


GUTHTHILA_EXPORT int   GUTHTHILA_CALL
guththila_write_attribute_with_prefix ( guththila_xml_writer_t *wr, char *prefix,
						       char *localname, char *value, const axutil_env_t *env);


GUTHTHILA_EXPORT int   GUTHTHILA_CALL
guththila_write_attribute_with_namespace (guththila_xml_writer_t *wr, char *namesp,
	char *localname, char *value, const axutil_env_t *env);


GUTHTHILA_EXPORT int  GUTHTHILA_CALL
guththila_write_start_element_with_prefix_and_namespace (guththila_xml_writer_t *wr, char* prefix,
									 char *namespace_uri, char *local_name, const axutil_env_t *env);


GUTHTHILA_EXPORT int  GUTHTHILA_CALL
guththila_write_start_element_with_namespace (guththila_xml_writer_t *wr, char *namespace_uri, 
							      char *local_name, const axutil_env_t *env);


GUTHTHILA_EXPORT int  GUTHTHILA_CALL
guththila_write_start_element_with_prefix ( guththila_xml_writer_t *wr, char *prefix, char *local_name, const axutil_env_t *env);


GUTHTHILA_EXPORT int  GUTHTHILA_CALL
guththila_write_empty_element_with_prefix_and_namespace (guththila_xml_writer_t *wr, char* prefix,
									 char *namespace_uri, char *local_name, const axutil_env_t *env);


GUTHTHILA_EXPORT int  GUTHTHILA_CALL
guththila_write_empty_element_with_namespace ( guththila_xml_writer_t *wr, char *namespace_uri, char *local_name, const axutil_env_t *env);


GUTHTHILA_EXPORT int  GUTHTHILA_CALL
guththila_write_empty_element_with_prefix ( guththila_xml_writer_t *wr, char *prefix, char *local_name, const axutil_env_t *env);


GUTHTHILA_EXPORT int  GUTHTHILA_CALL
guththila_write_end_document ( guththila_xml_writer_t *wr, const axutil_env_t *env);


GUTHTHILA_EXPORT int  GUTHTHILA_CALL
guththila_write_line ( guththila_xml_writer_t *wr, char *element_name, char *characters, const axutil_env_t *env);

GUTHTHILA_EXPORT char * GUTHTHILA_CALL
guththila_get_memory_buffer (guththila_xml_writer_t *wr, const axutil_env_t *env);

GUTHTHILA_EXPORT unsigned int GUTHTHILA_CALL
guththila_get_memory_buffer_size(guththila_xml_writer_t *wr, const axutil_env_t *env);


GUTHTHILA_EXPORT void GUTHTHILA_CALL
guththila_xml_writer_free (guththila_xml_writer_t *wr, const axutil_env_t *env);


GUTHTHILA_EXPORT char * GUTHTHILA_CALL
guththila_get_prefix_for_namespace (guththila_xml_writer_t *wr, 
								 char *namespace, const axutil_env_t *env);

/**@description 
  *
  */
int GUTHTHILA_CALL 
guththila_write(guththila_xml_writer_t *wr, 
			 char *buff, 
			 size_t buff_size, const axutil_env_t *env);

/**@description 
  *
  */
int GUTHTHILA_CALL 
guththila_write_token(guththila_xml_writer_t *wr, 
				   guththila_token_t *tok, const axutil_env_t *env);

/**@description 
  *
  */
int GUTHTHILA_CALL guththila_write_xtoken(guththila_xml_writer_t *wr, char *buff, size_t buff_len, const axutil_env_t *env);
EXTERN_C_END()

#endif

