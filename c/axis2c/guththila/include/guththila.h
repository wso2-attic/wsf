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
#ifndef GUTHTHILA_H
#define GUTHTHILA_H

#include <guththila_defines.h>
#include <guththila_token.h>
#include <guththila_reader.h>
#include <guththila_xml_writer.h>
#include <guththila_attribute.h>
#include <guththila_namespace.h>
#include <guththila_buffer.h>
#include <guththila_stack.h>
#include <guththila_error.h>

#include <axutil_utils.h>
/*
All the functions in this library does not check weather the given arguments are NULL. 
It is the responsblity of the user to check weather the arguments contain NULL values.
*/

EXTERN_C_START()

enum guththila_status
{
	S_0 = 0,
	S_1,
	S_2,
	S_3
};

enum guththila_UTF16_endianess
{ None = 1, LE, BE };

typedef enum guththila_type {
	type_file_name = 0,
	type_memory_buffer,
	type_reader,
	type_io
}guththila_type_t;

enum guththila_event_types
{
	GUTHTHILA_START_DOCUMENT = 0,    
	GUTHTHILA_END_ELEMENT,
    GUTHTHILA_CHARACTER,
    GUTHTHILA_ENTITY_REFERANCE,
    GUTHTHILA_COMMENT,
	GUTHTHILA_SPACE,
	GUTHTHILA_START_ELEMENT,
	GUTHTHILA_EMPTY_ELEMENT,
};

typedef struct guththila_s
{
	guththila_tok_list_t tokens;
	guththila_buffer_t buffer;

	guththila_reader_t *reader;
	guththila_token_t *prefix;
	guththila_token_t *name;
	guththila_token_t *value;

	guththila_stack_t elem;
	guththila_stack_t attrib;
	guththila_stack_t namesp;

	int is_whitespace;
	int is_char;
	int unicode_state;
	int status;
	int guththila_event;	
	int next;
	int last_start;
	guththila_token_t *temp_prefix;
	guththila_token_t *temp_name;
	guththila_token_t *temp_tok;
} guththila_t;

typedef struct guththila_elem_namesp_s {
	guththila_namespace_t *namesp;
	int no;
	int size;
} guththila_elem_namesp_t;

typedef struct guththila_element_s {
	guththila_token_t *name;
	guththila_token_t *prefix;
	int is_namesp;
} guththila_element_t;


GUTHTHILA_EXPORT int GUTHTHILA_CALL guththila_init(guththila_t *m, void *reader, const axutil_env_t *env);
GUTHTHILA_EXPORT guththila_t* GUTHTHILA_CALL guththila_create(void *reader, const axutil_env_t *env);
GUTHTHILA_EXPORT void GUTHTHILA_CALL guththila_free(guththila_t *m, const axutil_env_t *env);
GUTHTHILA_EXPORT int GUTHTHILA_CALL guththila_un_init(guththila_t *m, const axutil_env_t *env);



typedef void  (GUTHTHILA_CALL *guththila_error_func)(void *arg, 
						 const char *msg,
						 guththila_error_level level,
						 void *locator);

/*
Public functions for reading XML documents
*/
GUTHTHILA_EXPORT  int GUTHTHILA_CALL
guththila_next(guththila_t * p, const axutil_env_t *env);
                                                                                               
GUTHTHILA_EXPORT int GUTHTHILA_CALL
guththila_get_attribute_count(guththila_t *p, const axutil_env_t *env);
                                                                  
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_attribute_name(guththila_t * p, guththila_attr_t * att, const axutil_env_t *env);                                 
                                 
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_attribute_value (guththila_t *p, guththila_attr_t * att, const axutil_env_t *env);
                                 
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_attribute_prefix (guththila_t *p, guththila_attr_t * att, const axutil_env_t *env);
                                                                  
GUTHTHILA_EXPORT guththila_attr_t * GUTHTHILA_CALL
guththila_get_attribute (guththila_t * p, const axutil_env_t *env);
                                                                                  
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_attribute_name_by_number (guththila_t * p, int i, const axutil_env_t *env);
                                                                                  
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_attribute_value_by_number (guththila_t * p, int i, const axutil_env_t *env);
                                                                                  
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_attribute_prefix_by_number (guththila_t * p, int i, const axutil_env_t *env);
                                                                                  
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_name (guththila_t * p, const axutil_env_t *env);
                                                                        
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_prefix (guththila_t * p, const axutil_env_t *env);
                                                                            
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_value (guththila_t * p, const axutil_env_t *env);
                                                                          
GUTHTHILA_EXPORT guththila_namespace_t * GUTHTHILA_CALL
guththila_get_namespace (guththila_t * p, const axutil_env_t *env);
                                                                                  
GUTHTHILA_EXPORT int GUTHTHILA_CALL
guththila_get_namespace_count (guththila_t *p, const axutil_env_t *env);
                                                                                  
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_namespace_uri (guththila_t * p, guththila_namespace_t * ns, const axutil_env_t *env);
                                                                                          
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_namespace_prefix (guththila_t *p, guththila_namespace_t * ns, const axutil_env_t *env);
                                     
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_namespace_prefix_by_number (guththila_t * p, int i, const axutil_env_t *env);
                                                                          
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_namespace_uri_by_number (guththila_t * p, int i, const axutil_env_t *env);
                                                                              
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_attribute_namespace_by_number (guththila_t * p, int i, const axutil_env_t *env);

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL
guththila_get_encoding (guththila_t *p, const axutil_env_t *env);

GUTHTHILA_EXPORT void GUTHTHILA_CALL 
guththila_set_error_handler(guththila_t *m, guththila_error_func, const axutil_env_t *env);

EXTERN_C_END()

#endif
