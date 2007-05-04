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

#ifndef GUTHTHILA_XML_PULL_PARSER_H
#define GUTHTHILA_XML_PULL_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "guththila_buffer.h"
#include "guththila_reader.h"
#include "guththila_xml_writer.h"
#include "guththila_token.h"
#include "guththila_namespace.h"
#include "guththila_depth.h"
#include "guththila_attribute.h"
#include "guththila_unicode.h"
#include "guththila_defines.h"

#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_stack.h>
#include <axutil_string.h>

#define p_FILE __FILE__         /* file name */
#define LINE __LINE__           /* line number */

/*NOTE:
 *-----
 *The above defined p_FILE and LINE should provide as parameters when
 *   throwing Xml_PullParser_Exception
 */

enum guththila_status
  {
    S_0 = 0,
    S_1,
    S_2,
    S_3,
    S_4
  };

enum guththila_event_types
  {
    GUTHTHILA_START_DOCUMENT = 0,
    GUTHTHILA_START_ELEMENT,
    GUTHTHILA_END_ELEMENT,
	GUTHTHILA_EMPTY_ELEMENT,
    GUTHTHILA_CHARACTER,
    GUTHTHILA_ENTITY_REFERANCE,
    GUTHTHILA_COMMENT,
	GUTHTHILA_SPACE,
  };




typedef struct guththila_s
{
  guththila_buffer_t *buffer;
  guththila_reader_t *reader;
  guththila_xml_writer_t *xsw;
  guththila_token_t *prefix;
  guththila_token_t *name;
  guththila_token_t *value;
  axutil_stack_t *stack;
  axutil_stack_t *attrib;
  axutil_stack_t *namesp;
	axutil_stack_t *dep;
	axutil_stack_t *other;
  int _next;
  int offset;
  int last;
  int unicode_state;
  int reader_type;
  int is_whitespace;
  int is_char;
  enum guththila_status status;
  enum guththila_event_types guththila_event;
} guththila_t;


AXIS2_EXTERN int AXIS2_CALL
guththila_read (axutil_env_t * environment,
				guththila_t * p);
                                
int AXIS2_CALL
guththila_next_char (axutil_env_t *environment,
				     guththila_t * p,
				     int eof);

int AXIS2_CALL
guththila_tokenize (axutil_env_t *environment,
				    guththila_t * p);
                                        
                                        
AXIS2_EXTERN int AXIS2_CALL
guththila_exception (guththila_char_t * s, int line, int error_code);

int AXIS2_CALL
guththila_skip_spaces (axutil_env_t *environment,
				       guththila_t *p,
				       int c);
                                           
int AXIS2_CALL
guththila_process_xml_decl(axutil_env_t *environment,
					   guththila_t * p);
                                            
int AXIS2_CALL
guththila_process_version_info(axutil_env_t * environment,
                                               guththila_t * p);
                                               
                                               
int AXIS2_CALL
guththila_process_encoding_decl (axutil_env_t * environment,
                                                 guththila_t * p);
                                                 
int AXIS2_CALL
guththila_process_sd_decl (axutil_env_t *environment,
                                           guththila_t *p);
                                           
void AXIS2_CALL
guththila_open_token (axutil_env_t *environment,
                                      guththila_t *p);
                                      
void AXIS2_CALL
guththila_close_token (axutil_env_t *environment,
                                       guththila_t *p,
                                       int t,
                                       int refer);
                                       
guththila_char_t * AXIS2_CALL
guththila_last_char (axutil_env_t *environment,
                                     guththila_t *p);
                                     
int AXIS2_CALL
guththila_process_eq (axutil_env_t *environment,
                                      guththila_t *p,
                                      int c);
                                      
void AXIS2_CALL
guththila_add_attribute (axutil_env_t *environment,
                                         guththila_t *p,
                                         guththila_token_t * name,
                                         guththila_token_t * value);
                                         
void AXIS2_CALL
guththila_add_attribute_with_prefix (axutil_env_t *environment,
						     guththila_t *p,
						     guththila_token_t * prefix,
						     guththila_token_t * name,
						     guththila_token_t * value);
                                         
int AXIS2_CALL
guththila_process_char_data (axutil_env_t *environment,
                                             guththila_t *p);
                                             
int AXIS2_CALL
guththila_process_space_tag_or_empty_element (axutil_env_t * environment,
							      guththila_t *p);
                                             
int AXIS2_CALL
guththila_process_comment (axutil_env_t *environment,
                                           guththila_t *p);
                                           
int AXIS2_CALL
guththila_process_pi (axutil_env_t *environment,
                                      guththila_t *p);
                                      
int AXIS2_CALL
guththila_process_end_tag (axutil_env_t *environment,
					   guththila_t *p);
                                             
void AXIS2_CALL
guththila_reset (axutil_env_t *environment,
                                 guththila_t * p);
                                 
int AXIS2_CALL
guththila_process_name (axutil_env_t *environment,
                                        guththila_t *p);
                                        
int AXIS2_CALL
guththila_process_attribute (axutil_env_t  *environment,
                                             guththila_t *p,
                                             int c);
                                             
int AXIS2_CALL
guththila_process_attribute_value (axutil_env_t * environment,
						   guththila_t * p,
						   int c);
                                              
                                              
int AXIS2_CALL
guththila_is_space (axutil_env_t *environment, int c);


/*void AXIS2_CALL
guththila_relocate_tokens (axutil_env_t *environment,
                                           guththila_t *p,
                                           int offset);*/
                                           
void AXIS2_CALL
guththila_shift (axutil_env_t *environment,
                                 guththila_t * p);
                                 
void AXIS2_CALL
guththila_add_namespace (axutil_env_t *environment,
                                         guththila_t *p,
                                         guththila_token_t * name,
                                         guththila_token_t * uri);
                                         
void AXIS2_CALL
guththila_open_element (axutil_env_t *environment,
                                        guththila_t *p);
                                        
void AXIS2_CALL
guththila_close_element (axutil_env_t *environment,
                                         guththila_t *p);
                                         
int AXIS2_CALL
guththila_from_utf16 (axutil_env_t *environment,
                                      guththila_t *p,
                                      int eof);
                                      
int AXIS2_CALL
guththila_is_valid_starting_char (axutil_env_t * environment,
						  guththila_t * p,
						  int c);
                                         

AXIS2_EXTERN  int AXIS2_CALL
guththila_next (axutil_env_t * environment,
				guththila_t * p);
                                
AXIS2_EXTERN guththila_t * AXIS2_CALL
guththila_create (axutil_env_t * environment,
				  guththila_reader_t * r);
                                  
AXIS2_EXTERN void AXIS2_CALL
guththila_free (axutil_env_t * environment,
				guththila_t * parser);
                               
AXIS2_EXTERN int AXIS2_CALL
guththila_get_attribute_count (axutil_env_t * environment,
					       guththila_t *p);
                                 
                                 
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_attribute_name (axutil_env_t *environment,
					      guththila_t * p,
					      guththila_attribute_t * att);
                                 
                                 
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_attribute_value (axutil_env_t *environment,
					       guththila_t *p,
					       guththila_attribute_t * att);
                                 
                                 
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_attribute_prefix (axutil_env_t *environment,
						guththila_t *p,
						guththila_attribute_t * att);
                                 
                                 
AXIS2_EXTERN guththila_attribute_t * AXIS2_CALL
guththila_get_attribute (axutil_env_t *environment,
					 guththila_t * p);
                                         
                                         
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_attribute_name_by_number (axutil_env_t * environment,
							guththila_t * p,
							int i);
                                         
                                         
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_attribute_value_by_number (axutil_env_t * environment,
							 guththila_t * p,
							 int i);
                                         
                                         
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_attribute_prefix_by_number (axutil_env_t * environment,
							  guththila_t * p,
							  int i);
                                         
                                         
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_name (axutil_env_t * environment,
				    guththila_t * p);
                                    
                                    
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_prefix (axutil_env_t * environment,
				      guththila_t * p);
                                      
                                      
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_value (axutil_env_t * environment,
				     guththila_t * p);
                                     
                                     
AXIS2_EXTERN guththila_namespace_t * AXIS2_CALL
guththila_get_namespace (axutil_env_t *environment,
					 guththila_t * p);
                                         
                                         
AXIS2_EXTERN int AXIS2_CALL
guththila_get_namespace_count (axutil_env_t *environment,
					       guththila_t *p);
                                         
                                         
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_namespace_uri (axutil_env_t *environment,
					     guththila_t * p,
					     guththila_namespace_t * ns);
                                             
                                             
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_namespace_prefix (axutil_env_t *environment,
						guththila_t *p,
						guththila_namespace_t * ns);
                                     

AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_namespace_prefix_by_number (axutil_env_t * environment,
							  guththila_t * p,
							  int i);
                                     
                                     
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_namespace_uri_by_number (axutil_env_t *environment,
						       guththila_t * p,
						       int i);
                                       
                                       
AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_attribute_namespace_by_number (axutil_env_t * environment,
							     guththila_t * p,
							     int i);

AXIS2_EXTERN guththila_char_t * AXIS2_CALL
guththila_get_encoding (axutil_env_t *environment,
					guththila_t *p);

/* --------------writer api --------------------------*/

AXIS2_EXTERN void  AXIS2_CALL
guththila_create_xml_stream_writer (axutil_env_t *environment, 
						    guththila_t *p, 
						    char *fp);

AXIS2_EXTERN void  AXIS2_CALL
guththila_create_xml_stream_writer_for_memory (axutil_env_t *environment, 
						    guththila_t *p);

AXIS2_EXTERN void AXIS2_CALL
guththila_write_to_buffer (axutil_env_t *env, 
					   guththila_t *p,
					   const char *buff);


void AXIS2_CALL
guththila_close_start_element (axutil_env_t *environment,
					       guththila_t *p);


void AXIS2_CALL
guththila_close_depth_element (axutil_env_t *environment,
					       guththila_t *p);


void AXIS2_CALL
guththila_check_name_validity (axutil_env_t *environment,
					       guththila_t *p,
					       char *start_element);


void AXIS2_CALL
guththila_open_depth_element (axutil_env_t *environment,
					      guththila_t *p);


void AXIS2_CALL
guththila_do_write_attribute (axutil_env_t *environment, 
					      guththila_t *p, 
					      const char *local_name, 
					      const char *value);


int AXIS2_CALL
guththila_check_default_namespace (axutil_env_t *env, 
						   guththila_t *p, 
						   char *ns_uri);


void AXIS2_CALL
guththila_do_write_default_namespace (axutil_env_t *env, 
						      guththila_t *p, 
						      char *ns_uri);


int  AXIS2_CALL
guththila_check_prefix_validity (axutil_env_t *env, 
						 guththila_t *p, 
						 char *prefix, 
						 char *uri);

AXIS2_EXTERN void  AXIS2_CALL
guththila_write_namespace (axutil_env_t *env, 
					   guththila_t *p, 
					   char *prefix, 
					   char *uri);


int  AXIS2_CALL
guththila_check_xml_stream_writer (axutil_env_t *environment, 
						   guththila_t *p);


void AXIS2_CALL
guththila_do_write_namespace (axutil_env_t *env, 
					      guththila_t *p, 
					      char *prefix, 
					      char *uri);

AXIS2_EXTERN void AXIS2_CALL
guththila_do_write_attribute_with_prefix_and_namespace (axutil_env_t *env, 
									guththila_t *p,
									const char *prefix, 
									const char *namespace_uri,
									const char *local_name, 
									const char *value);


int AXIS2_CALL
guththila_is_exsisting_prefix (axutil_env_t *env, 
					       guththila_t *p, 
					       const char *prefix);


AXIS2_EXTERN void   AXIS2_CALL
guththila_write_start_document (axutil_env_t *environment, 
						guththila_t *p);


void AXIS2_CALL
guththila_do_write_attribute_with_prefix (axutil_env_t *env, 
							  guththila_t *p, 
							  const char *prefix,
							  const char *local_name, 
							  const char *value);


AXIS2_EXTERN char * AXIS2_CALL
guththila_get_prefix_for_namespace (axutil_env_t *env, 
						    guththila_t *p, 
						    const char *namespace);



AXIS2_EXTERN void   AXIS2_CALL
guththila_write_start_element (axutil_env_t *environment, 
						     guththila_t *p, 
						     char *start_element);


AXIS2_EXTERN void   AXIS2_CALL
guththila_write_end_element (axutil_env_t *environment, 
					     guththila_t *p);


AXIS2_EXTERN void  AXIS2_CALL
guththila_close (axutil_env_t *environment, 
				 guththila_t *p);


AXIS2_EXTERN void   AXIS2_CALL
guththila_write_characters (axutil_env_t *environment, 
					    guththila_t *p,
					    const char  *buff);


AXIS2_EXTERN void   AXIS2_CALL
guththila_write_comment (axutil_env_t *environment, 
					 guththila_t *p, 
					 const char *buff);

AXIS2_EXTERN void   AXIS2_CALL
guththila_write_escape_character (axutil_env_t *environment, 
						  guththila_t *p, 
						  const char *buff);


AXIS2_EXTERN void   AXIS2_CALL
guththila_write_empty_element (axutil_env_t *environment, 
					       guththila_t *p, 
					       char *empty_element);


AXIS2_EXTERN void  AXIS2_CALL
guththila_write_default_namespace (axutil_env_t *environment, 
						   guththila_t *p, 
						   char *namespace_uri);


AXIS2_EXTERN void  AXIS2_CALL
guththila_write_namespace (axutil_env_t *environment, 
					   guththila_t *p, 
					   char *prefix, char *uri);


AXIS2_EXTERN void   AXIS2_CALL
guththila_write_attribute (axutil_env_t *environment, 
					  guththila_t *p, 
					  const char *localname, 
					  const char *value);


AXIS2_EXTERN void   AXIS2_CALL
guththila_write_attribute_with_prefix_and_namespace (axutil_env_t *environment, 
								     guththila_t *p,
								     const char *prefix, 
								     const char *namespace_uri,
								     const char *localname, const char *value);


AXIS2_EXTERN void   AXIS2_CALL
guththila_write_attribute_with_prefix (axutil_env_t *environment, 
						       guththila_t *p,
						       const char *prefix,
						       const char *localname, const char *value);


AXIS2_EXTERN void   AXIS2_CALL
guththila_write_attribute_with_namespace (axutil_env_t *environment, 
							  guththila_t *p,
							  const char *namespace,
							  const char *localname, const char *value);


AXIS2_EXTERN void  AXIS2_CALL
guththila_write_start_element_with_prefix_and_namespace (axutil_env_t *environment, 
									 guththila_t *p, 
									 const char* prefix,
									 const char *namespace_uri, const char *local_name);


AXIS2_EXTERN void  AXIS2_CALL
guththila_write_start_element_with_namespace (axutil_env_t *environment, 
							      guththila_t *p, 
							      const char *namespace_uri, 
							      const char *local_name);


AXIS2_EXTERN void  AXIS2_CALL
guththila_write_start_element_with_prefix (axutil_env_t *environment, 
							   guththila_t *p, 
							   const char *prefix, 
							   const char *local_name);


AXIS2_EXTERN void  AXIS2_CALL
guththila_write_empty_element_with_prefix_and_namespace (axutil_env_t *environment, 
									 guththila_t *p, 
									 const char* prefix,
									 const char *namespace_uri, 
									 const char *local_name);


AXIS2_EXTERN void  AXIS2_CALL
guththila_write_empty_element_with_namespace (axutil_env_t *environment, 
							      guththila_t *p, 
							      const char *namespace_uri, 
							      const char *local_name);


AXIS2_EXTERN void  AXIS2_CALL
guththila_write_empty_element_with_prefix (axutil_env_t *environment, 
							   guththila_t *p, 
							   const char *prefix, 
							   const char *local_name);


AXIS2_EXTERN void  AXIS2_CALL
guththila_write_end_document (axutil_env_t *environment, 
					      guththila_t *p);


AXIS2_EXTERN void  AXIS2_CALL
guththila_write_line (axutil_env_t *environment, 
				      guththila_t *p, 
				      char *element_name, 
				      char *characters);

AXIS2_EXTERN char * AXIS2_CALL
guththila_get_memory_buffer (axutil_env_t *environemnt, 
					     guththila_t *p);

AXIS2_EXTERN unsigned int AXIS2_CALL
guththila_get_memory_buffer_size(axutil_env_t *env, 
								 guththila_t *p);


AXIS2_EXTERN void AXIS2_CALL
guththila_xml_writer_free (axutil_env_t *environment,
					   guththila_t *t);

#endif /* GUTHTHILA_XML_PULL_PARSER_H */
