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
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <guththila.h>

#define GUTHTHILA_VALIDATION_PARSER

static int GUTHTHILA_CALL guththila_next_char(guththila_t *m, int eof, const axutil_env_t *env);
static int GUTHTHILA_CALL guththila_next_no_char(guththila_t *m, int eof, char *bytes, int no, const axutil_env_t *env);
static void GUTHTHILA_CALL guththila_token_close(guththila_t *m, guththila_token_t *tok, int tok_type, int referer, const axutil_env_t *env);
static int GUTHTHILA_CALL guththila_process_xml_dec(guththila_t *m, const axutil_env_t *env);

#ifndef GUTHTHILA_SKIP_SPACES
#define GUTHTHILA_SKIP_SPACES(m, c, _env) while (0x20 == c || 0x9 == c || 0xD == c || 0xA == c){c = guththila_next_char(m, 0, _env);}
#endif

#ifndef GUTHTHILA_SKIP_SPACES_WITH_NEW_LINE
#define GUTHTHILA_SKIP_SPACES_WITH_NEW_LINE(m, c, _env) while (0x20 == c || 0x9 == c || 0xD == c || 0xA == c || '\n' == c){c = guththila_next_char(m, 0, _env);}
#endif

#ifndef GUTHTHILA_LAST_CHAR
#define GUTHTHILA_LAST_CHAR(m) (m->buffer.buff + m->buffer.next - 1)
#endif

#ifndef GUTHTHILA_TOKEN_OPEN
#define GUTHTHILA_TOKEN_OPEN(m, tok, _env)					\
	m->temp_tok = guththila_tok_list_get_token(&m->tokens, _env);	\
	m->temp_tok->type = _Unknown;							\
	m->temp_tok->_start = m->next;		\
	m->reader->last_start = m->next;	
#endif

#ifndef GUTHTHILA_PROCESS_EQU
#define GUTHTHILA_PROCESS_EQU(m, c, ic, _env)							\
	GUTHTHILA_SKIP_SPACES(m, c, _env);									\
    if (0x3D == c){												\
        ic = guththila_next_char(m, 0, _env);		\
		GUTHTHILA_SKIP_SPACES(m, ic, _env);	\
	}															
#endif    

#ifndef GUTHTHILA_ATTRIBUTE_INITIALIZE
#define GUTHTHILA_ATTRIBUTE_INITIALIZE(_attr, _pref, _name, _val)	\
	(_attr->pref = (_pref));							\
	(_attr->name = (_name));							\
	(_attr->val  = (_val));							
#endif

#ifndef GUTHTHILA_NAMESPACE_INITIALIZE
#define GUTHTHILA_NAMESPACE_INITIALIZE(_namesp, _name, _uri)	\
	(_namesp->name = _name);								\
	(_namesp->uri = _uri);
#endif

#ifndef GUTHTHILA_IS_SPACE
#define GUTHTHILA_IS_SPACE(c) (0x20 == c || 0xD == c || 0xA == c || 0x9 == c)     
#endif

#ifndef GUTHTHILA_IS_VALID_STRING_CHAR
#define GUTHTHILA_IS_VALID_STRING_CHAR(c) (isalpha(c) || '_' == c || ':' == c)
#endif


#ifndef GUTHTHILA_IS_VALID_STARTING_CHAR
#define GUTHTHILA_IS_VALID_STARTING_CHAR(c) (isalpha(c) || '_' == c || ':' == c)
#endif

static void GUTHTHILA_CALL guththila_token_close(guththila_t *m, guththila_token_t *tok, int tok_type, int referer, const axutil_env_t *env)
{
	guththila_attr_t *attr = NULL;
	guththila_element_t *elem = NULL;
	guththila_elem_namesp_t *e_namesp = NULL;
	guththila_namespace_t *namesp;
	int counter = 0, nmsp_no = 0, i = 0;
	m->temp_tok->type = tok_type;									
	m->temp_tok->size = m->next - m->temp_tok->_start;							
	m->temp_tok->start = GUTHTHILA_BUF_POS(m->buffer, m->next - 1) - m->temp_tok->size;
	m->temp_tok->ref = referer;	
	m->reader->last_start = -1;
	switch(tok_type){										
	case _attribute_name:									
		m->temp_name = m->temp_tok;							
		m->temp_tok = NULL;
		break;												
	case _char_data:										
		m->value = m->temp_tok;	
		m->temp_tok = NULL;
		break;												
	case _attribute_value:	
		if (m->temp_prefix && GUTHTHILA_TOKEN_LEN(m->temp_prefix) == 5 && (m->temp_prefix->start)[0] == 'x' && 
						(m->temp_prefix->start)[1] == 'm' && (m->temp_prefix->start)[2] == 'l' &&
						(m->temp_prefix->start)[3] == 'n' && (m->temp_prefix->start)[4] == 's' ){
#ifndef GUTHTHILA_VALIDATION_PARSER
			namesp = (guththila_namespace_t *) AXIS2_MALLOC(sizeof(guththila_namespace_t));
			GUTHTHILA_NAMESPACE_INITIALIZE(namesp, m->temp_name, m->temp_tok); 
			guththila_stack_push(&m->namesp, namesp);
#else
			elem = (guththila_element_t *)guththila_stack_peek(&m->elem, env);
			if (elem && !elem->is_namesp) {
				e_namesp = (guththila_elem_namesp_t *)AXIS2_MALLOC(env->allocator, sizeof(guththila_elem_namesp_t));
				if (e_namesp) {
					e_namesp->namesp = (guththila_namespace_t *)AXIS2_MALLOC(env->allocator, sizeof(guththila_namespace_t) * GUTHTHILA_NAMESPACE_DEF_SIZE);
					if (e_namesp->namesp) {
						e_namesp->no = 1;
						e_namesp->size = GUTHTHILA_NAMESPACE_DEF_SIZE;
						e_namesp->namesp[0].name = m->temp_name;
						e_namesp->namesp[0].uri = m->temp_tok;
						guththila_stack_push(&m->namesp, e_namesp, env);
						elem->is_namesp = 1;
					}
				}
			} else {
				e_namesp = (guththila_elem_namesp_t *)guththila_stack_peek(&m->namesp, env);
				if (e_namesp->no < e_namesp->size) {					
					e_namesp->namesp[e_namesp->no].name = m->temp_name;
					e_namesp->namesp[e_namesp->no].uri = m->temp_tok;
					e_namesp->no++;
				} else {
					/*e_namesp->namesp = (guththila_namespace_t *)realloc(e_namesp->namesp , sizeof(guththila_namespace_t) * e_namesp->size * 2);*/
					namesp = (guththila_namespace_t *)AXIS2_MALLOC(env->allocator , sizeof(guththila_namespace_t) * e_namesp->size * 2);
					for (i = 0; i < e_namesp->no; i++) {
						namesp[i].name = e_namesp->namesp[i].name;
						namesp[i].uri = e_namesp->namesp[i].uri;
					}
					AXIS2_FREE(env->allocator, e_namesp->namesp);
					e_namesp->namesp = namesp;
					if (e_namesp->namesp) {						
						e_namesp->size *= 2;
						e_namesp->namesp[e_namesp->no].name = m->temp_name;
						e_namesp->namesp[e_namesp->no].uri = m->temp_tok;						
						e_namesp->no++;
					}
				}
			}
#endif
		} else {
			attr = (guththila_attr_t *) AXIS2_MALLOC(env->allocator, sizeof(guththila_attr_t));			
#ifdef GUTHTHILA_VALIDATION_PARSER
			if (m->temp_prefix) {
				nmsp_no = GUTHTHILA_STACK_SIZE(m->namesp);				
				for (counter = 0; counter < nmsp_no; counter++) {
					e_namesp = (guththila_elem_namesp_t *)guththila_stack_get_by_index(&m->namesp, counter, env);
					for (i = 0; i < e_namesp->no; i++) {
						if (!guththila_tok_tok_cmp(e_namesp->namesp[i].name, m->temp_prefix, env)) {
							GUTHTHILA_ATTRIBUTE_INITIALIZE(attr, m->temp_prefix, m->temp_name, m->temp_tok);			
							guththila_stack_push(&m->attrib, attr, env);
							counter += nmsp_no;
							break;
						}
					}
				}
			} else {
				GUTHTHILA_ATTRIBUTE_INITIALIZE(attr, m->temp_prefix, m->temp_name, m->temp_tok);			
				guththila_stack_push(&m->attrib, attr, env);
			}
#else
			GUTHTHILA_ATTRIBUTE_INITIALIZE(attr, m->temp_prefix, m->temp_name, m->temp_tok);
			guththila_stack_push(&m->attrib, attr, env);
#endif
		}
		m->temp_prefix = NULL;
		m->temp_name = NULL;
		m->temp_tok = NULL;
		break;												
	case _prefix:											
		m->temp_prefix = m->temp_tok;							
		m->temp_tok = NULL;
		break;												
	default:												
		m->prefix = m->temp_prefix;										
		m->name = m->temp_tok;		
		m->temp_tok = NULL;		
		break;	
	}											
}

#ifndef GUTHTHILA_VARIABLE_INITIALZE
#define GUTHTHILA_VARIABLE_INITIALZE(m) \
	m->temp_prefix = NULL;	\
	m->temp_name = NULL;	\
	m->temp_tok = NULL;	\
	if (m->value) guththila_tok_list_release_token(&m->tokens, m->value, env);	\
	m->name = NULL; \
	m->prefix = NULL; \
	m->value = NULL; 
#endif

GUTHTHILA_EXPORT int GUTHTHILA_CALL guththila_init(guththila_t *m, void *reader, const axutil_env_t *env)
{
	if (!((guththila_reader_t *)reader)) return GUTHTHILA_FAILURE;
	m->reader = (guththila_reader_t *)reader;
	if (!guththila_tok_list_init(&m->tokens, env)){
		return GUTHTHILA_FAILURE;
	}

	if (m->reader->type == GUTHTHILA_MEMORY_READER) {
		guththila_buffer_init_for_buffer(&m->buffer, m->reader->buff, m->reader->buff_size, env);
	} else if (m->reader->type == GUTHTHILA_FILE_READER || GUTHTHILA_IO_READER) {
		guththila_buffer_init(&m->buffer, 0, env);
	}

	guththila_stack_init(&m->elem, env);
    guththila_stack_init(&m->attrib, env);
    guththila_stack_init(&m->namesp, env);

    m->name = NULL;
    m->prefix = NULL;
    m->value = NULL;

    m->status = S_1;

	m->guththila_event = -1;

	m->next = 0;
	m->last_start = -1;
	
	m->temp_name = NULL;
	m->temp_prefix = NULL;
	m->temp_tok = NULL;
    return GUTHTHILA_SUCCESS;
}

GUTHTHILA_EXPORT guththila_t* GUTHTHILA_CALL guththila_create(void *reader, const axutil_env_t *env)
{
	guththila_t *m = (guththila_t *) AXIS2_MALLOC(env->allocator, sizeof(guththila_t *));
	if (!m) return NULL;

	m->reader = (guththila_reader_t *)reader;
	if (!guththila_tok_list_init(&m->tokens, env)){
		AXIS2_FREE(env->allocator, m);		
		
return NULL;
	}
	if (m->reader->type == GUTHTHILA_MEMORY_READER) {
		guththila_buffer_init_for_buffer(&m->buffer, m->reader->buff, m->reader->buff_size, env);
	} else if (m->reader->type == GUTHTHILA_FILE_READER || GUTHTHILA_IO_READER) {
		guththila_buffer_init(&m->buffer, 0, env);
	}
	guththila_stack_init(&m->elem, env);
    guththila_stack_init(&m->attrib, env);
    guththila_stack_init(&m->namesp, env);

    m->name = NULL;
    m->prefix = NULL;
    m->value = NULL;

    m->status = S_1;
	m->guththila_event = -1;

	m->next = 0;
	m->last_start = -1;

	m->temp_name = NULL;
	m->temp_prefix = NULL;
	m->temp_tok = NULL;
	return m;
}

GUTHTHILA_EXPORT void GUTHTHILA_CALL guththila_free(guththila_t *m, const axutil_env_t *env)
{
	int size = 0, i = 0;
	guththila_namespace_t *namesp = NULL;
	guththila_attr_t *attr = NULL;
	if (m->prefix){
		guththila_tok_list_release_token(&m->tokens, m->prefix, env);
	}

	if (m->name){
		guththila_tok_list_release_token(&m->tokens, m->name, env);
	}

	if (m->value){
		guththila_tok_list_release_token(&m->tokens, m->value, env);
	}	

	if (m->temp_tok){
		guththila_tok_list_release_token(&m->tokens, m->temp_tok, env);
	}

	if (m->temp_name){
		guththila_tok_list_release_token(&m->tokens, m->temp_name, env);
	}

	if (m->temp_prefix){
		guththila_tok_list_release_token(&m->tokens, m->temp_prefix, env);
	}

	size = GUTHTHILA_STACK_SIZE(m->attrib);
	for ( i = 0; i < size; i++) {
		attr = (guththila_attr_t *)guththila_stack_pop(&m->attrib, env);
		if (attr) {
			if (attr->name) guththila_tok_list_release_token(&m->tokens, attr->name, env);
			if (attr->pref) guththila_tok_list_release_token(&m->tokens, attr->pref, env);
			AXIS2_FREE(env->allocator, attr);
		}
	}
	guththila_stack_un_init(&m->attrib, env);

	size = GUTHTHILA_STACK_SIZE(m->namesp);
	for ( i = 0; i < size; i++) {
		namesp = (guththila_namespace_t *)guththila_stack_pop(&m->namesp, env);
		if (namesp) {
			if (namesp->name) guththila_tok_list_release_token(&m->tokens, namesp->name, env);
			if (namesp->uri) guththila_tok_list_release_token(&m->tokens, namesp->uri, env);
			AXIS2_FREE(env->allocator, namesp);
		}
	}
	guththila_stack_un_init(&m->namesp, env);

	guththila_tok_list_free_data(&m->tokens, env);

	guththila_buffer_un_init(&m->buffer, env);
	AXIS2_FREE(env->allocator, m);
	return;
}

GUTHTHILA_EXPORT int GUTHTHILA_CALL guththila_un_init(guththila_t *m, const axutil_env_t *env)
{
	int size = 0, i = 0;
	guththila_namespace_t *namesp = NULL;
	guththila_attr_t *attr = NULL;
	if (m->prefix){
		guththila_tok_list_release_token(&m->tokens, m->prefix, env);
	}

	if (m->name){
		guththila_tok_list_release_token(&m->tokens, m->name, env);
	}

	if (m->value){
		guththila_tok_list_release_token(&m->tokens, m->value, env);
	}	

	if (m->temp_tok){
		guththila_tok_list_release_token(&m->tokens, m->temp_tok, env);
	}

	if (m->temp_name){
		guththila_tok_list_release_token(&m->tokens, m->temp_name, env);
	}

	if (m->temp_prefix){
		guththila_tok_list_release_token(&m->tokens, m->temp_prefix, env);
	}

	size = GUTHTHILA_STACK_SIZE(m->attrib);
	for ( i = 0; i < size; i++) {
		attr = (guththila_attr_t *)guththila_stack_pop(&m->attrib, env);
		if (attr) {
			if (attr->name) guththila_tok_list_release_token(&m->tokens, attr->name, env);
			if (attr->pref) guththila_tok_list_release_token(&m->tokens, attr->pref, env);
			AXIS2_FREE(env->allocator, attr);
		}
	}
	guththila_stack_un_init(&m->attrib, env);

	size = GUTHTHILA_STACK_SIZE(m->namesp);
	for ( i = 0; i < size; i++) {
		namesp = (guththila_namespace_t *)guththila_stack_pop(&m->namesp, env);
		if (namesp) {
			if (namesp->name) guththila_tok_list_release_token(&m->tokens, namesp->name, env);
			if (namesp->uri) guththila_tok_list_release_token(&m->tokens, namesp->uri, env);
			AXIS2_FREE(env->allocator, namesp);
		}
	}
	guththila_stack_un_init(&m->namesp, env);

	guththila_tok_list_free_data(&m->tokens, env);
	guththila_buffer_un_init(&m->buffer, env);
	return GUTHTHILA_SUCCESS;
}


GUTHTHILA_EXPORT int GUTHTHILA_CALL guththila_next(guththila_t *m, const axutil_env_t *env)
{
	guththila_element_t *elem = NULL;
	guththila_elem_namesp_t *nmsp = NULL;
	guththila_token_t *tok = NULL;
	int quote = 0, ref = 0;
	char c_arra[16] = {0};	
	int c = -1;
	guththila_attr_t *attr = NULL;
	int size = 0, i = 0, nmsp_counter, loop = 0, white_space = 0;

	size = GUTHTHILA_STACK_SIZE(m->attrib);
	for ( i = 0; i < size; i++) {
		attr = (guththila_attr_t *)guththila_stack_pop(&m->attrib, env);
		if (attr) {
			if (attr->name) guththila_tok_list_release_token(&m->tokens, attr->name, env);
			if (attr->pref) guththila_tok_list_release_token(&m->tokens, attr->pref, env);
			AXIS2_FREE(env->allocator, attr);
		}		
	}

	GUTHTHILA_VARIABLE_INITIALZE(m);
#ifdef GUTHTHILA_VALIDATION_PARSER
	if (m->guththila_event == GUTHTHILA_EMPTY_ELEMENT) {
		elem = (guththila_element_t *)guththila_stack_pop(&m->elem, env);
		if (elem->is_namesp) {
			nmsp = (guththila_elem_namesp_t *)guththila_stack_pop(&m->namesp, env);
			for (nmsp_counter = 0; nmsp_counter < nmsp->no; nmsp_counter++) {
				guththila_tok_list_release_token(&m->tokens, nmsp->namesp[i].name, env);
				guththila_tok_list_release_token(&m->tokens, nmsp->namesp[i].uri, env);
			}
			AXIS2_FREE(env->allocator, nmsp);
		}
		if (elem->name) guththila_tok_list_release_token(&m->tokens, elem->name, env);
		if (elem->prefix) guththila_tok_list_release_token(&m->tokens, elem->prefix, env);
		AXIS2_FREE(env->allocator, elem);
	}
#endif 
	do {
	loop = 0;
	c = guththila_next_char(m, 0, env);
	if (m->status == S_1){
        while (isspace(c)){
			c = guththila_next_char(m, 0, env);
            if (c == -1)
                return -1;
        }
		if ('<' == c) {
			m->status = S_2;
		} else {
			return -1;
		}
	} 
	if ('<' == c && m->status == S_2) {	
		c = guththila_next_char(m, 0, env);
		if (c != '?' && c != '!' && c != '/'){
			if (GUTHTHILA_IS_VALID_STARTING_CHAR(c)){
				GUTHTHILA_TOKEN_OPEN(m, tok, env);
				c = guththila_next_char(m, 0, env);
				while(!GUTHTHILA_IS_SPACE(c) && c != '>' && c != '/'){
					if (c != ':'){
						c = guththila_next_char(m, 0, env);
					} else {
						guththila_token_close(m, tok, _prefix, 0, env);							
						c = guththila_next_char(m, 0, env);
						GUTHTHILA_TOKEN_OPEN(m, tok, env);
					}
				}
				guththila_token_close(m, tok, _name, 0, env);
#ifdef GUTHTHILA_VALIDATION_PARSER		
				elem = (guththila_element_t *)AXIS2_MALLOC(env->allocator, sizeof(guththila_element_t));
				elem->name = m->name;
				elem->prefix = m->prefix;
				elem->is_namesp = 0;
				guththila_stack_push(&m->elem, elem, env);		
#endif 
			}
			GUTHTHILA_SKIP_SPACES(m, c, env);
			for(;;){
				if (c == '/') {					
					if ('>' == guththila_next_char(m, 0, env)){
						return m->guththila_event = GUTHTHILA_EMPTY_ELEMENT;
					} else {
						return -1;
					}
				} else if (c == '>') {
					m->guththila_event = GUTHTHILA_START_ELEMENT;
					return GUTHTHILA_START_ELEMENT;
				} else if (c != -1){
					if (GUTHTHILA_IS_VALID_STARTING_CHAR(c)){
						GUTHTHILA_TOKEN_OPEN(m, tok, env);
						c = guththila_next_char(m, 0, env);
						while(!GUTHTHILA_IS_SPACE(c) && c != '='){
							if (c != ':'){
								c = guththila_next_char(m, 0, env);
							} else if (c == ':'){
								guththila_token_close(m, tok, _prefix, 0, env);							
								c = guththila_next_char(m, 0, env);
								GUTHTHILA_TOKEN_OPEN(m, tok, env);
							} 
						}
						guththila_token_close(m, tok, _attribute_name, 0, env);
					} else {
						return -1;
					}
					GUTHTHILA_PROCESS_EQU(m, c, quote, env);
					
					if ('\'' == quote || '\"' == quote) {
						c = guththila_next_char(m, 0, env);
						GUTHTHILA_TOKEN_OPEN(m, tok, env);
						while (c != quote) {
							c = guththila_next_char(m, 0, env);							
						}
						guththila_token_close(m, tok, _attribute_value, 0, env);					
						c = guththila_next_char(m, 0, env);
						GUTHTHILA_SKIP_SPACES(m, c, env);						
					} else {
						return -1;
					}
				}  else {
					return -1;
				}
			}
		} else if (c == '/'){
			m->guththila_event = GUTHTHILA_END_ELEMENT;
			c = guththila_next_char(m, -1, env);
			if (GUTHTHILA_IS_VALID_STARTING_CHAR(c)){
				GUTHTHILA_TOKEN_OPEN(m, tok, env);
				c = guththila_next_char(m, 0, env);
				while(!GUTHTHILA_IS_SPACE(c) && c != '>'){
					if (c != ':'){
						c = guththila_next_char(m, 0, env);
					}else {
						guththila_token_close(m, tok, _prefix, 0, env);							
						c = guththila_next_char(m, 0, env);
						GUTHTHILA_TOKEN_OPEN(m, tok, env);
					} 					
				}
				guththila_token_close(m, tok, _name, 0, env);

#ifdef GUTHTHILA_VALIDATION_PARSER	
				elem = (guththila_element_t *)guththila_stack_pop(&m->elem, env);
				if (!elem || (!elem->prefix && m->prefix) || (elem->prefix && !m->prefix)) return -1;
				if (guththila_tok_tok_cmp(m->name, elem->name, env)) {
					return -1;
				}
				if (elem->prefix && m->prefix && guththila_tok_tok_cmp(m->prefix, elem->prefix, env)) {
					return -1;
				}
				if (elem->is_namesp) {
					nmsp = (guththila_elem_namesp_t *)guththila_stack_pop(&m->namesp, env);
					for (nmsp_counter = 0; nmsp_counter < nmsp->no; nmsp_counter++) {
						guththila_tok_list_release_token(&m->tokens, nmsp->namesp[i].name, env);
						guththila_tok_list_release_token(&m->tokens, nmsp->namesp[i].uri, env);
					}
					AXIS2_FREE(env->allocator, nmsp);
				}
				if (elem->name) guththila_tok_list_release_token(&m->tokens, elem->name, env);
				if (elem->prefix) guththila_tok_list_release_token(&m->tokens, elem->prefix, env);
				AXIS2_FREE(env->allocator, elem);
#endif 
				GUTHTHILA_SKIP_SPACES(m, c, env);
				if (c != '>')
					return -1;
				return GUTHTHILA_END_ELEMENT;
			}
			return -1;
		} else if(c == '!') { 
			if (2 == guththila_next_no_char(m, 0, c_arra, 2, env) && '-' == c_arra[0] && '-' == c_arra[1]){
				c = guththila_next_char(m, 0, env);
				GUTHTHILA_TOKEN_OPEN(m, tok, env);
				while (1) {
					c = guththila_next_char(m, 0, env);
					if ('-' == c) {						
						c = guththila_next_char(m,	0, env);
						if ('-' == c) {
							if ('>' == guththila_next_char(m, 0, env)){
								m->guththila_event = GUTHTHILA_COMMENT;								
								while (c != '<') {
									c = guththila_next_char(m, 0, env);
									if (c == -1)
										return -1;
								}
								guththila_token_close(m, tok, _char_data, 0, env);
								m->next--;
								return GUTHTHILA_COMMENT;
							}
							else {
								return -1;
							}
						}
					}
				}
			} else {
				c = guththila_next_char(m, 0, env);
				while ('<' != c)
					c = guththila_next_char(m, -1, env);
			}
		} else if (c == '?'){
			c = guththila_process_xml_dec(m, env);	
			if (c != -1)
				return GUTHTHILA_START_DOCUMENT;
			else 
				return -1;
		} 
	} else if (c != '<' && m->status == S_2 && c != -1){
		m->guththila_event = GUTHTHILA_CHARACTER;
		if (!GUTHTHILA_IS_SPACE(c)) 
			white_space = 0;
		else 
			white_space = 1;
		GUTHTHILA_TOKEN_OPEN(m, tok, env);		
		do {
			c = guththila_next_char(m, -1, env);
			if (!GUTHTHILA_IS_SPACE(c) && c != '<') 
				white_space = 0;
			if (c == -1) return -1; 
		} while (c != '<');
		guththila_token_close(m, tok, _char_data, ref, env);
		m->next--;
		if (white_space) {
			loop = 1;
			if (m->value) {
				guththila_tok_list_release_token(&m->tokens, m->value, env);
				m->value = NULL;
			}
		}
		else return GUTHTHILA_CHARACTER;
	} else {
        return -1;															
	}
	}while(loop);
	return c;
}


static int GUTHTHILA_CALL guththila_process_xml_dec(guththila_t *m, const axutil_env_t *env)
{
	guththila_token_t *tok = NULL;
	char c_arra[16] = {0};	
	int c = -1;
	int quote = -1;
	int nc = -1;

	if (3 == guththila_next_no_char(m, GUTHTHILA_EOF, c_arra, 3, env) && 'x' == c_arra[0] && 'm' == c_arra[1] && 'l' == c_arra[2]) {
		c = guththila_next_char(m, GUTHTHILA_EOF, env);
		GUTHTHILA_SKIP_SPACES(m, c, env);
		
		if (c == 'v') {
			GUTHTHILA_TOKEN_OPEN(m, tok, env); 
			if(6 == guththila_next_no_char(m, 0, c_arra, 6, env) && 
					'e' == c_arra[0] && 'r' == c_arra[1] &&
					's' == c_arra[2] && 'i' == c_arra[3] &&
					'o' == c_arra[4] && 'n' == c_arra[5]) {	
			
				c = guththila_next_char(m, 0, env);
				guththila_token_close(m, tok, _attribute_name, 0, env);
				GUTHTHILA_PROCESS_EQU(m, c, quote, env);

				nc = guththila_next_char(m, 0, env);

				GUTHTHILA_TOKEN_OPEN(m, tok, env);
				while(nc != quote)
					nc = guththila_next_char(m, 0, env);

				guththila_token_close(m, tok, _attribute_value, 0, env);

				c = guththila_next_char(m, 0, env);
				GUTHTHILA_SKIP_SPACES(m, c, env);
			} else{
				return -1;
			}
		}

		if (c == 'e') {
			GUTHTHILA_TOKEN_OPEN(m, tok, env);
			if(7 == guththila_next_no_char(m, 0, c_arra, 7, env) &&
				'n' == c_arra[0] && 'c' == c_arra[1] &&
				'o' == c_arra[2] && 'd' == c_arra[3] &&		
				'i' == c_arra[4] && 'n' == c_arra[5] &&		
				'g' == c_arra[6]) {
				
				c = guththila_next_char(m, 0, env);
				guththila_token_close(m, tok, _attribute_name, 0, env);
				GUTHTHILA_PROCESS_EQU(m, c, quote, env);

				nc = guththila_next_char(m, 0, env);

				GUTHTHILA_TOKEN_OPEN(m, tok, env);
				while(nc != quote)
					nc = guththila_next_char(m, 0, env);

				guththila_token_close(m, tok, _attribute_value, 0, env);

				c = guththila_next_char(m, 0, env);
				GUTHTHILA_SKIP_SPACES(m, c, env);				
			}
		}

		if (c == 's') {
			GUTHTHILA_TOKEN_OPEN(m, tok, env);			
			if(9 == guththila_next_no_char(m, 0, c_arra, 9, env) &&
				't' == c_arra[0] && 'a' == c_arra[1] &&
				'n' == c_arra[2] && 'd' == c_arra[3] &&		
				'a' == c_arra[4] && 'l' == c_arra[5] &&		
				'o' == c_arra[6] && 'n' == c_arra[7] &&
				'e' == c_arra[8]) {

				c = guththila_next_char(m, 0, env);
				guththila_token_close(m, tok, _attribute_name, 0, env);
				GUTHTHILA_PROCESS_EQU(m, c, quote, env);

				nc = guththila_next_char(m, 0, env);
				GUTHTHILA_TOKEN_OPEN(m, tok, env);								

				while(nc != quote)
					nc = guththila_next_char(m, 0, env);

				guththila_token_close(m, tok, _attribute_value, 0, env);

				c = guththila_next_char(m, 0, env);
				GUTHTHILA_SKIP_SPACES(m, c, env);																				
			}
		}

		if (c == '?') {
			if ('>' == guththila_next_char(m, 0, env)){
                m->guththila_event = GUTHTHILA_START_DOCUMENT;
			} else {
				return -1;
			}
		}
	}
	return c;
}


GUTHTHILA_EXPORT int GUTHTHILA_CALL guththila_get_attribute_count(guththila_t *m, const axutil_env_t *env)
{
	return GUTHTHILA_STACK_SIZE(m->attrib);
}
                                                
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_attribute_name(guththila_t * m, guththila_attr_t * att, const axutil_env_t *env)
{
	char *str = NULL;
	if (att) {
		GUTHTHILA_TOKEN_TO_STRING(att->name, str, env);  
		return str;
	}
	return NULL;
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_attribute_value (guththila_t *m, guththila_attr_t * att, const axutil_env_t *env)
{
	char *str = NULL;
	if (att) {
		GUTHTHILA_TOKEN_TO_STRING(att->val, str, env);  
		return str;
	}
	return NULL;
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_attribute_prefix (guththila_t *m, guththila_attr_t * att, const axutil_env_t *env)
{
	char *str = NULL;
	if (att) {
		GUTHTHILA_TOKEN_TO_STRING(att->pref, str, env);  
		return str;
	}
	return NULL;
}

GUTHTHILA_EXPORT guththila_attr_t * GUTHTHILA_CALL guththila_get_attribute (guththila_t * m, const axutil_env_t *env)
{
	return (guththila_attr_t *)guththila_stack_pop(&m->attrib, env);
}


GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_attribute_name_by_number (guththila_t * m, int i, const axutil_env_t *env)
{
	char *str = NULL;
	guththila_attr_t *attr = (guththila_attr_t *)guththila_stack_get_by_index(&m->attrib, i - 1, env);
	if (attr){
		GUTHTHILA_TOKEN_TO_STRING(attr->name, str, env);  
		return str;		
	}
	return NULL;
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_attribute_value_by_number (guththila_t * m, int i, const axutil_env_t *env)
{
	char *str = NULL;
	guththila_attr_t *attr = (guththila_attr_t *)guththila_stack_get_by_index(&m->attrib, i - 1, env);
	if (attr){
		GUTHTHILA_TOKEN_TO_STRING(attr->val, str, env);  
		return str;		
	}
	return NULL;
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_attribute_prefix_by_number (guththila_t * m, int i, const axutil_env_t *env)
{
	char *str = NULL;
	guththila_attr_t *attr = (guththila_attr_t *)guththila_stack_get_by_index(&m->attrib, i - 1, env);
	if (attr && attr->pref){
		GUTHTHILA_TOKEN_TO_STRING(attr->pref, str, env);  
		return str;		
	}
	return NULL;
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_name (guththila_t * m, const axutil_env_t *env)
{
	char *str = NULL;
	if (m->name){
		GUTHTHILA_TOKEN_TO_STRING(m->name, str, env);  
		return str;		
	}
	return NULL;
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_prefix (guththila_t * m, const axutil_env_t *env)
{
	char *str = NULL;
	if (m->prefix){
		GUTHTHILA_TOKEN_TO_STRING(m->prefix, str, env);  
		return str;		
	}
	return NULL;
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_value (guththila_t * m, const axutil_env_t *env)
{
	char *str = NULL;
	if (m->value){
		GUTHTHILA_TOKEN_TO_STRING(m->value, str, env);  
		return str;		
	}
	return NULL;
}

GUTHTHILA_EXPORT guththila_namespace_t * GUTHTHILA_CALL guththila_get_namespace (guththila_t * m, const axutil_env_t *env)
{
#ifndef GUTHTHILA_VALIDATION_PARSER
	return (guththila_namespace_t *)guththila_stack_pop(&m->namesp, env);
#else
	return NULL;
#endif
}

GUTHTHILA_EXPORT int GUTHTHILA_CALL guththila_get_namespace_count (guththila_t *m, const axutil_env_t *env)
{
#ifndef GUTHTHILA_VALIDATION_PARSER
	return GUTHTHILA_STACK_SIZE(m->namesp);
#else
	guththila_elem_namesp_t *nmsp = NULL;
	if (((guththila_element_t *)guththila_stack_peek(&m->elem, env))->is_namesp) {
		nmsp = (guththila_elem_namesp_t *)guththila_stack_peek(&m->namesp, env);
		return nmsp->no; 
	}
	return 0;
#endif
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_namespace_uri (guththila_t * m, guththila_namespace_t * ns, const axutil_env_t *env)
{
	char *str = NULL;
	if (ns->uri){
		GUTHTHILA_TOKEN_TO_STRING(ns->uri, str, env);  
		return str;		
	}
	return NULL;
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_namespace_prefix (guththila_t *m, guththila_namespace_t * ns, const axutil_env_t *env)
{
	char *str = NULL;
	if (ns->name){
		GUTHTHILA_TOKEN_TO_STRING(ns->name, str, env);  
		return str;		
	}
	return NULL;
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_namespace_prefix_by_number (guththila_t * m, int i, const axutil_env_t *env)
{
	char *str = NULL;
#ifndef GUTHTHILA_VALIDATION_PARSER
	if (GUTHTHILA_STACK_SIZE(m->namesp) >= i){
		namesp = guththila_stack_get_by_index(&m->namesp, i, env);
		if (namesp && namesp->name) {
			GUTHTHILA_TOKEN_TO_STRING(namesp->name, str, env);
			return str;
		}
	}
#else
	guththila_elem_namesp_t *nmsp = NULL;
	if (((guththila_element_t *)guththila_stack_peek(&m->elem, env))->is_namesp) {
		nmsp = (guththila_elem_namesp_t *)guththila_stack_peek(&m->namesp, env);
		if (nmsp && nmsp->no >= i) {
			GUTHTHILA_TOKEN_TO_STRING(nmsp->namesp[i - 1].name, str, env);
			return str;
		}
	}
#endif
	return NULL;
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_namespace_uri_by_number (guththila_t * m, int i, const axutil_env_t *env) 
{
	char *str = NULL;
	/*TODO check the given index, this can begn from 1, here I assume begin from 0*/
#ifndef GUTHTHILA_VALIDATION_PARSER
	if (GUTHTHILA_STACK_SIZE(m->namesp) > i){
		namesp = guththila_stack_get_by_index(&m->namesp, i, env);
		if (namesp && namesp->uri) {
			GUTHTHILA_TOKEN_TO_STRING(namesp->uri, str, env);
			return str;
		}
	}
#else
	guththila_elem_namesp_t *nmsp = NULL;
	if (((guththila_element_t *)guththila_stack_peek(&m->elem, env))->is_namesp) {
		nmsp = (guththila_elem_namesp_t *)guththila_stack_peek(&m->namesp, env);
		if (nmsp && nmsp->no >= i) {
			GUTHTHILA_TOKEN_TO_STRING(nmsp->namesp[i - 1].uri, str, env);
			return str;
		}
	}
#endif
	return NULL;

}
GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_attribute_namespace_by_number (guththila_t * m, int i, const axutil_env_t *env)
{
#ifndef GUTHTHILA_VALIDATION_PARSER
	return NULL;
#else
	guththila_attr_t *attr  = NULL;
	char *str = NULL;
	int j = 0, k = 0, count = 0;
	guththila_elem_namesp_t *nmsp = NULL;
	if ( i <= GUTHTHILA_STACK_SIZE(m->attrib)) {	
		attr = (guththila_attr_t *)guththila_stack_get_by_index(&m->attrib, i - 1, env);  
		if (attr && attr->pref) {
			count = GUTHTHILA_STACK_SIZE(m->namesp);
			for ( j = 0; j < count; j++) { 
				nmsp = (guththila_elem_namesp_t *)guththila_stack_get_by_index(&m->namesp, j, env);
				for (k = 0; k < nmsp->no; k++) {
					if (!guththila_tok_tok_cmp(nmsp->namesp[k].name, attr->pref, env)) {
						GUTHTHILA_TOKEN_TO_STRING(nmsp->namesp[k].uri, str, env);
						return str;
					}
				}
			}
		}
	}
	return NULL;
#endif
}

GUTHTHILA_EXPORT guththila_char * GUTHTHILA_CALL guththila_get_encoding (guththila_t *m, const axutil_env_t *env)
{
	return "UTF-8";
}

static int GUTHTHILA_CALL guththila_next_char(guththila_t *m, int eof, const axutil_env_t *env)
{
	int c = -1;
	size_t temp = 0, data_move = 0, i = 0;
	char **temp1 = NULL;
	size_t *temp2 = NULL, *temp3 = NULL;
	if (m->reader->type == GUTHTHILA_MEMORY_READER && m->next < GUTHTHILA_BUFFER_CURRENT_DATA_SIZE(m->buffer)){        		
		c = m->buffer.buff[0][m->next++];
		return c >= 0 ? c : -1;
	} else if (m->reader->type == GUTHTHILA_IO_READER || m->reader->type == GUTHTHILA_FILE_READER){
		if (m->next < GUTHTHILA_BUFFER_PRE_DATA_SIZE(m->buffer) + GUTHTHILA_BUFFER_CURRENT_DATA_SIZE(m->buffer) && m->buffer.cur_buff != -1) {
			c = m->buffer.buff[m->buffer.cur_buff][m->next++ - GUTHTHILA_BUFFER_PRE_DATA_SIZE(m->buffer)];			 
			return c >= 0 ? c : -1;
		} else if (m->next >= GUTHTHILA_BUFFER_PRE_DATA_SIZE(m->buffer) + GUTHTHILA_BUFFER_CURRENT_DATA_SIZE(m->buffer) && m->buffer.cur_buff != -1){
			if (m->buffer.cur_buff == m->buffer.no_buffers - 1) {				
				temp = m->buffer.no_buffers * 2;
				temp1 = (char **)AXIS2_MALLOC(env->allocator, sizeof(char *) * temp);
				temp2 = (size_t *)AXIS2_MALLOC(env->allocator, sizeof(size_t) * temp);
				temp3 = (size_t *)AXIS2_MALLOC(env->allocator, sizeof(size_t) * temp);
				for (i = 0; i < m->buffer.no_buffers; i++) {
					temp1[i] = m->buffer.buff[i];
					temp2[i] = m->buffer.buffs_size[i];
					temp3[i] = m->buffer.data_size[i];
				}
				AXIS2_FREE(env->allocator, m->buffer.buff);
				AXIS2_FREE(env->allocator, m->buffer.data_size);
				AXIS2_FREE(env->allocator, m->buffer.buffs_size);
				m->buffer.buff = temp1;
				m->buffer.buffs_size = temp2;
				m->buffer.data_size = temp3;
				m->buffer.no_buffers *= 2;				
			}
			m->buffer.cur_buff++;
			m->buffer.buff[m->buffer.cur_buff] = (char *)AXIS2_MALLOC(env->allocator, sizeof(char) * m->buffer.buffs_size[m->buffer.cur_buff - 1] * 2);    
			m->buffer.buffs_size[m->buffer.cur_buff] = m->buffer.buffs_size[m->buffer.cur_buff - 1] * 2;
			m->buffer.data_size[m->buffer.cur_buff] = 0;						
			
			if (m->last_start != -1) {
				data_move = m->buffer.data_size[m->buffer.cur_buff - 1] - (m->last_start - m->buffer.pre_tot_data);
				memcpy(m->buffer.buff[m->buffer.cur_buff], 
					m->buffer.buff[m->buffer.cur_buff - 1] + m->buffer.data_size[m->buffer.cur_buff] - data_move, 
					data_move); 
				m->buffer.data_size[m->buffer.cur_buff - 1] -= data_move; 
				m->buffer.data_size[m->buffer.cur_buff] += data_move; 				
			}
			m->buffer.pre_tot_data += m->buffer.data_size[m->buffer.cur_buff - 1];								
			temp = guththila_reader_read(m->reader, GUTHTHILA_BUFFER_CURRENT_BUFF(m->buffer), 0, GUTHTHILA_BUFFER_CURRENT_BUFF_SIZE(m->buffer), env);			
			if (temp > 0) {
				m->buffer.data_size[m->buffer.cur_buff] += temp; 
			} else {
				return -1;
			}
			c = m->buffer.buff[m->buffer.cur_buff][m->next++ - GUTHTHILA_BUFFER_PRE_DATA_SIZE(m->buffer)];
			return c >= 0 ? c : -1;
		} else if (m->buffer.cur_buff == -1){
			m->buffer.buff[0] = (char *) AXIS2_MALLOC(env->allocator, sizeof(char) * GUTHTHILA_BUFFER_DEF_SIZE);
			m->buffer.buffs_size[0] = GUTHTHILA_BUFFER_DEF_SIZE;
			m->buffer.cur_buff = 0;
			temp = guththila_reader_read(m->reader, m->buffer.buff[0], 0, GUTHTHILA_BUFFER_DEF_SIZE, env);
			m->buffer.data_size[0] = temp;
			c = m->buffer.buff[0][m->next++];
			return c >= 0 ? c : -1;
		}
	} 
	return -1;
}

static int GUTHTHILA_CALL guththila_next_no_char (guththila_t *m, int eof, char *bytes, int no, const axutil_env_t *env)
{
	int c = -1, temp = 0, data_move = 0, i = 0;
	char **temp1 = NULL;
	size_t *temp2 = NULL, *temp3 = NULL;
	if (m->reader->type == GUTHTHILA_MEMORY_READER && m->next + no - 1 < GUTHTHILA_BUFFER_CURRENT_DATA_SIZE(m->buffer) && m->buffer.cur_buff != -1){        
		for (i = 0; i < no; i++){
			bytes[i] = m->buffer.buff[0][m->next++];								
		}
		return no;
	} else if (m->reader->type == GUTHTHILA_IO_READER || m->reader->type == GUTHTHILA_FILE_READER){
		if (m->next < GUTHTHILA_BUFFER_PRE_DATA_SIZE(m->buffer) + GUTHTHILA_BUFFER_CURRENT_DATA_SIZE(m->buffer) + no && m->buffer.cur_buff != -1) {
			for (i = 0; i < no; i++){
				bytes[i] = m->buffer.buff[m->buffer.cur_buff][m->next++ - GUTHTHILA_BUFFER_PRE_DATA_SIZE(m->buffer)];	
			}
			return no;
		} else if (m->next >= GUTHTHILA_BUFFER_PRE_DATA_SIZE(m->buffer) + GUTHTHILA_BUFFER_CURRENT_DATA_SIZE(m->buffer) + no && m->buffer.cur_buff != -1){
			if (m->buffer.cur_buff == m->buffer.no_buffers - 1) {
				temp = m->buffer.no_buffers * 2;
				temp1 = (char **)AXIS2_MALLOC(env->allocator, sizeof(char *) * temp);
				temp2 = (size_t *)AXIS2_MALLOC(env->allocator, sizeof(size_t) * temp);
				temp3 = (size_t *)AXIS2_MALLOC(env->allocator, sizeof(size_t) * temp);
				for (i = 0; i < m->buffer.no_buffers; i++) {
					temp1[i] = m->buffer.buff[i];
					temp2[i] = m->buffer.buffs_size[i];
					temp3[i] = m->buffer.data_size[i];
				}
				AXIS2_FREE(env->allocator, m->buffer.buff);
				AXIS2_FREE(env->allocator, m->buffer.data_size);
				AXIS2_FREE(env->allocator, m->buffer.buffs_size);
				m->buffer.buff = temp1;
				m->buffer.buffs_size = temp2;
				m->buffer.data_size = temp3;
				m->buffer.no_buffers *= 2;
			}
			m->buffer.buff[m->buffer.cur_buff + 1] = (char *)AXIS2_MALLOC(env->allocator, sizeof(char) * m->buffer.data_size[m->buffer.cur_buff] * 2);    
			m->buffer.cur_buff++;
			m->buffer.buffs_size[m->buffer.cur_buff] = m->buffer.buffs_size[m->buffer.cur_buff - 1] * 2;
			m->buffer.data_size[m->buffer.cur_buff] = 0;						
			
			if (m->last_start != -1) {
				data_move = m->buffer.data_size[m->buffer.cur_buff - 1] - (m->last_start - m->buffer.pre_tot_data);
				memcpy(m->buffer.buff[m->buffer.cur_buff], 
					m->buffer.buff[m->buffer.cur_buff - 1] + m->buffer.data_size[m->buffer.cur_buff] - data_move, 
					data_move); 
				m->buffer.data_size[m->buffer.cur_buff - 1] -= data_move; 
				m->buffer.data_size[m->buffer.cur_buff] += data_move; 				
			}
			m->buffer.pre_tot_data += m->buffer.data_size[m->buffer.cur_buff - 1];								
			temp = guththila_reader_read(m->reader, GUTHTHILA_BUFFER_CURRENT_BUFF(m->buffer), 0, GUTHTHILA_BUFFER_CURRENT_BUFF_SIZE(m->buffer), env);			
			if (temp > 0) {
				m->buffer.data_size[m->buffer.cur_buff] += temp; 
			} else {
				return -1;
			}
			for (i = 0; i < no; i++){
				bytes[i] = m->buffer.buff[m->buffer.cur_buff][m->next++ - GUTHTHILA_BUFFER_PRE_DATA_SIZE(m->buffer)];
			}
			return no;
		} else if (m->buffer.cur_buff == -1){
			m->buffer.buff[0] = (char *) AXIS2_MALLOC(env->allocator, sizeof(char) * GUTHTHILA_BUFFER_DEF_SIZE);
			m->buffer.buffs_size[0] = GUTHTHILA_BUFFER_DEF_SIZE;
			m->buffer.cur_buff = 0;
			temp = guththila_reader_read(m->reader, m->buffer.buff[0], 0, GUTHTHILA_BUFFER_DEF_SIZE, env);
			m->buffer.data_size[0] = temp;
			for (i = 0; i < no; i++){
				bytes[i] = m->buffer.buff[m->buffer.cur_buff][m->next++ - GUTHTHILA_BUFFER_PRE_DATA_SIZE(m->buffer)];
			}
		    return no;
		}
	}
	return c >= 0 ? c : -1;
}

