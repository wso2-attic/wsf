/*
 *   Copyright 2004,2005 The Apache Software Foundation.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *   
 */

#ifndef GUTHTHILA_ATTRIBUTE_H
#define GUTHTHILA_ATTRIBUTE_H

#include "guththila_token.h"

typedef struct guththila_attribute_s
{
    guththila_token_t *prefix;
    guththila_token_t *name;
    guththila_token_t *value;
	guththila_token_t *namespace_uri;
} guththila_attribute_t;

AXIS2_EXTERN guththila_attribute_t * AXIS2_CALL
guththila_attribute_create (
	axutil_env_t *env, 
	guththila_token_t *prefix, 
	guththila_token_t *name, 
	guththila_token_t *value,
	guththila_token_t *ns);


AXIS2_EXTERN void AXIS2_CALL
guththila_attribute_free (
	axutil_env_t *env,
	guththila_attribute_t *attribute);


#endif /* GUTHTHILA_ATTRIBUTE_H */
