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
#ifndef GUTHTHILA_TOKEN_H
#define GUTHTHILA_TOKEN_H

#include <guththila_defines.h>
#include <guththila_stack.h>

EXTERN_C_START()

typedef struct guththila_token_s
{
	short type;
	char *start;
	int _start;
	size_t size;
	int last;
	int ref;	
} guththila_token_t;

enum guththila_token_type
{  
	_Unknown = 1,
    _name,
	_attribute_name,
    _attribute_value,
    _prefix,
    _char_data
};

typedef struct guththila_tok_list_s
{
	guththila_stack_t fr_stack;
	guththila_token_t **list;
	int no_list;
	int cur_list;	
	int *capacity;
} guththila_tok_list_t;

#ifndef GUTHTHILA_TOK_DEF_SIZE
#define GUTHTHILA_TOK_DEF_SIZE 4
#endif

#ifndef GUTHTHILA_TOK_DEF_LIST_SIZE
#define GUTHTHILA_TOK_DEF_LIST_SIZE 16
#endif

#ifndef GUTHTHILA_TOKEN_LEN
#define GUTHTHILA_TOKEN_LEN(tok) (tok->size)
#endif

#ifndef GUTHTHILA_TOKEN_TO_STRING
#define GUTHTHILA_TOKEN_TO_STRING(tok, string, _env) \
	string = (char *)AXIS2_MALLOC(_env->allocator, (GUTHTHILA_TOKEN_LEN(tok) + 1) * sizeof (char));	\
	memcpy(string, (tok)->start, GUTHTHILA_TOKEN_LEN(tok));						\
	string[GUTHTHILA_TOKEN_LEN(tok)] = 0;										
#endif

guththila_tok_list_t * GUTHTHILA_CALL guththila_tok_list_create(const axutil_env_t *env);
int GUTHTHILA_CALL guththila_tok_list_init(guththila_tok_list_t *tok_list, const axutil_env_t *env);
void GUTHTHILA_CALL guththila_tok_list_free(guththila_tok_list_t *tok_list, const axutil_env_t *env);
guththila_token_t * GUTHTHILA_CALL guththila_tok_list_get_token(guththila_tok_list_t *tok_list, const axutil_env_t *env);
int GUTHTHILA_CALL guththila_tok_list_release_token(guththila_tok_list_t *tok_list, guththila_token_t *token, const axutil_env_t *env);
void GUTHTHILA_CALL guththila_tok_list_free_data(guththila_tok_list_t *tok_list, const axutil_env_t *env);
int GUTHTHILA_CALL guththila_tok_list_grow(guththila_tok_list_t *tok_list, const axutil_env_t *env);

int GUTHTHILA_CALL guththila_tok_str_cmp(guththila_token_t *tok, char *str, size_t str_len, const axutil_env_t *env);
int GUTHTHILA_CALL guththila_tok_tok_cmp(guththila_token_t *tok1, guththila_token_t *tok2, const axutil_env_t *env);

EXTERN_C_END()

#endif

