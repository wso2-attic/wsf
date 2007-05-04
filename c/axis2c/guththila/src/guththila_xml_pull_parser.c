/*
 * licensed to the Apache Software Foundation (ASF) under one or more
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

#include <guththila.h>

AXIS2_EXTERN guththila_t * AXIS2_CALL
guththila_create(axutil_env_t * environment,
				 guththila_reader_t * r)
{
    guththila_t *parser =
        (guththila_t *) AXIS2_MALLOC(
            environment->allocator, sizeof(guththila_t));
    guththila_reader_impl_t *reader_impl = NULL;
    if (r)
    {
        reader_impl = (guththila_reader_impl_t *)r;
        parser->reader_type = reader_impl->reader.guththila_reader_type;
    }

    if (reader_impl && reader_impl->reader.guththila_reader_type == GUTHTHILA_MEMORY_READER)
    {
        guththila_buffer_t *reader_buffer = NULL;
        reader_buffer = guththila_buffer_create_for_buffer(environment, 
														   reader_impl->buffer, 
														   reader_impl->buffer_size);
        parser->buffer = reader_buffer;
    }
    else
        parser->buffer = guththila_buffer_create(environment, GUTHTHILA_BUFFER_SIZE);

    parser->stack = axutil_stack_create(environment);
    parser->attrib = axutil_stack_create(environment);
    parser->namesp = axutil_stack_create(environment);
    parser->dep = axutil_stack_create(environment);
	parser->other = axutil_stack_create (environment);
    parser->name = NULL;
    parser->prefix = NULL;
    parser->value = NULL;
    parser->reader = r;
    parser->_next = 0;
    parser->offset = 0;
    parser->last = -1;
    parser->status = S_1;
    parser->unicode_state = None;
    parser->xsw = NULL;
    parser->is_whitespace = 0;
    parser->is_char = 0;
	parser->guththila_event = -1;
    return parser;
}


AXIS2_EXTERN  void AXIS2_CALL
guththila_free(axutil_env_t * environment,
			   guththila_t * parser)
{
	int ii = 0;
    if (parser->buffer)
        guththila_buffer_free(environment, (void *) parser->buffer);

	if (parser->name)
		guththila_token_free (environment, parser->name);


    if (parser->stack)
	{
		ii = axutil_stack_size(parser->stack, environment);
		for (; ii > 0; ii--)
		{
			guththila_token_t *d;
			d = (guththila_token_t *)axutil_stack_pop(parser->stack, environment);
			guththila_token_free (environment, d);
		}

        axutil_stack_free(parser->stack, environment);
	}

    if (parser->attrib)
	{
		int ii = axutil_stack_size(parser->attrib, environment);
		guththila_attribute_t *attribute;
		for (; ii > 0; ii--)
		{
			attribute = axutil_stack_pop(parser->attrib, environment);
			guththila_attribute_free (environment, attribute);
		}
        axutil_stack_free(parser->attrib, environment);
	}

    if (parser->namesp)
	{
		int ii = axutil_stack_size(parser->namesp, environment);
		guththila_namespace_t *namespace;

		for (; ii > 0; ii--)
		{
			namespace = (guththila_namespace_t *) axutil_stack_pop(parser->namesp, environment);
			if (namespace->name)
			{
				AXIS2_FREE(environment->allocator, namespace->name);
				namespace->name = NULL;
			}
			if (namespace->uri)
			{
				AXIS2_FREE(environment->allocator, namespace->uri);
				namespace->uri = NULL;
			}
			AXIS2_FREE (environment->allocator, namespace);
		}
		axutil_stack_free(parser->namesp, environment);
	}

    if (parser->dep)
	{
		int ii = axutil_stack_size(parser->dep, environment);
		guththila_depth_t *depth;
		for (; ii > 0; ii--)
		{
			depth = (guththila_depth_t *)axutil_stack_pop(parser->dep, environment);
			AXIS2_FREE(environment->allocator, depth);
		}
        axutil_stack_free(parser->dep, environment);
	}

    if (parser->other)
	{
		int ii = axutil_stack_size(parser->other, environment);
		void *element = NULL;
		for (; ii > 0; ii--)
		{
			element = axutil_stack_pop(parser->other, environment);
			AXIS2_FREE(environment->allocator, element);
		}
        axutil_stack_free(parser->other, environment);
	}

    AXIS2_FREE(environment->allocator, (void *) parser);
}


AXIS2_EXTERN  int AXIS2_CALL
guththila_exception(guththila_char_t * file, int line, int error_code)
{
    printf("Throws guththila_exception \t %s \t %d \n", file,
		   line);
    return error_code;
}




void AXIS2_CALL
guththila_shift(axutil_env_t * environment,
				guththila_t * parser)
{
    memmove(parser->buffer->buff, parser->buffer->buff + (parser->offset),
            (parser->_next) - (parser->offset));
    parser->_next -= parser->offset;
    parser->last -= parser->offset;
    parser->offset = 0;
}


AXIS2_EXTERN int AXIS2_CALL
guththila_read(axutil_env_t * environment,
			   guththila_t * parser)
{
    int c = 0;
    if (parser->_next == parser->buffer->size)
    {
        if (parser->offset > 0)
        {
            guththila_relocate_tokens(environment, parser->stack,
									  parser->offset);
            guththila_shift(environment, parser);
        }
        else
        {
            int b = 0;
			guththila_char_t *buff;
			buff = parser->buffer->buff;
			b = parser->buffer->size;
            parser->buffer =
                guththila_buffer_grow(environment, parser->buffer, parser->_next);
			guththila_relocate_tokens(environment, parser->stack, 
									  (buff - parser->buffer->buff));
			axutil_stack_push(parser->other, environment, buff);
        }
    }
    c = guththila_reader_read(environment, (parser->buffer->buff),
							  (parser->_next),
							  (parser->buffer->size) - (parser->_next),
							  parser->reader);
    parser->last += c;
    return !c;
}


int AXIS2_CALL
guththila_from_utf16(axutil_env_t * environment,
					 guththila_t * parser,
					 int eof)
{
    int c = parser->buffer->buff[parser->_next++];
    if (((parser->_next) > (parser->last))
		&& guththila_read(environment, parser))
    {
        if (eof)
            return -1;
        else
            guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_UNEXPECTED_UTF16_EOF);
    }
    while (!c)
        c = parser->buffer->buff[parser->_next++];
    return c;
}


int AXIS2_CALL
guththila_next_char(axutil_env_t * environment,
					guththila_t * parser,
					int eof)
{

    if (parser->reader_type == GUTHTHILA_MEMORY_READER)
    {
        if (parser->_next > parser->last)
            return -1;
    }
    else  if (((parser->_next) > (parser->last))
			  && guththila_read(environment, parser))
    {
        if (eof)
            return -1;
        else
            guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_UNEXPECTED_EOF);
    }

/*    if (parser->_next == 0)
	  {
	  guththila_UTF8_char iu =
	  (guththila_UTF8_char) parser->buffer->buff[parser->_next++];

	  if (0xff == iu
	  && 0xfe ==
	  (guththila_UTF8_char) parser->buffer->buff[parser->_next++])
	  {
	  parser->unicode_state = LE;
	  }
	  else if (0xfe == iu
	  && 0xff ==
	  (guththila_UTF8_char) parser->buffer->buff[parser->_next++])
	  {
	  parser->unicode_state = BE;
	  }
	  else if (0xef == iu
	  && 0xbb ==
	  (guththila_UTF8_char) parser->buffer->buff[parser->_next++]
	  && 0xbf ==
	  (guththila_UTF8_char) parser->buffer->buff[parser->_next++])
	  {
	  parser->unicode_state = None;
	  }
	  else
	  {
	  parser->unicode_state = None;
	  parser->_next = 0;
	  }
	  }*/

/*    if (parser->unicode_state == None)*/
	return parser->buffer->buff[parser->_next++];
/*    else
	  return guththila_from_utf16(environment, parser,
	  eof);*/
}


guththila_char_t * AXIS2_CALL
guththila_last_char(axutil_env_t * environment,
					guththila_t * parser)
{
    return parser->buffer->buff + (parser->_next - 1);
}


void AXIS2_CALL
guththila_open_token(axutil_env_t * environment,
					 guththila_t * parser)
{
    guththila_token_t *t =
        (guththila_token_t *) AXIS2_MALLOC(environment->allocator,
										   sizeof(guththila_token_t));
    t->type = Unknown;
    t->start = guththila_last_char(environment, parser);
    axutil_stack_push(parser->stack, environment, t);
}


void AXIS2_CALL
guththila_close_token(axutil_env_t * environment,
					  guththila_t * parser,
					  int t, int refer)
{
    guththila_token_t *token =
        (guththila_token_t *) axutil_stack_get(parser->stack, environment);
    token->type = t;
    token->ref = refer;
    token->end =
        guththila_last_char(environment, parser) - 1;
}


int AXIS2_CALL
guththila_skip_spaces(axutil_env_t * environment,
					  guththila_t * parser,
					  int c)
{
    while (0x20 == c || 0x9 == c || 0xD == c || 0xA == c)
        c = guththila_next_char(environment, parser, 0);
    return c;
}


int AXIS2_CALL
guththila_process_eq(axutil_env_t * environment,
					 guththila_t * parser,
					 int c)
{
    int ic;
    if (0x3D ==
		guththila_skip_spaces(environment, parser, c))
    {
        ic = guththila_next_char(environment, parser, 0);
        return guththila_skip_spaces(environment, parser,
									 ic);
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_PROCESS_EQUAL);
    return 0;
}


int AXIS2_CALL
guththila_process_version_info(axutil_env_t *
							   environment,
							   guththila_t *
							   parser)
{
    int ic;
    int quote;
    int nc;
    ic = guththila_next_char(environment, parser, 0);
    ic = guththila_skip_spaces(environment, parser, ic);
    if (ic == 'v')
    {
        guththila_open_token(environment, parser);
        if ('e' ==
			guththila_next_char(environment, parser, 0)
			&& 'r' == guththila_next_char(environment,
										  parser, 0)
			&& 's' == guththila_next_char(environment,
										  parser, 0)
			&& 'i' == guththila_next_char(environment,
										  parser, 0)
			&& 'o' == guththila_next_char(environment,
										  parser, 0)
			&& 'n' == guththila_next_char(environment,
										  parser, 0))
        {
            ic = guththila_next_char(environment, parser, 0);
            guththila_close_token(environment, parser,
								  _attribute, 0);
            quote =
                guththila_process_eq(environment, parser,
									 ic);
            nc = guththila_next_char(environment, parser, 0);
            /* 0, since we don't expect EOF line here */
            guththila_open_token(environment, parser);
            while (quote != nc)
                nc = guththila_next_char(environment, parser,
										 0);
            guththila_close_token(environment, parser,
								  _attribute_value, 0);
            nc = guththila_next_char(environment, parser, 0);
            return guththila_skip_spaces(environment, parser,
										 nc);
        }
        else
            guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_INCORRECT_VERSION_INFO);
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_VERSION_INFO_NOT_FOUND);
    return 0;
}


int AXIS2_CALL
guththila_process_encoding_decl(axutil_env_t *
								environment,
								guththila_t *
								parser)
{
    int quote;
    int nc;
    int ic;
    guththila_open_token(environment, parser);
    if ('n' == guththila_next_char(environment, parser, 0)
		&& 'c' == guththila_next_char(environment, parser, 0)
		&& 'o' == guththila_next_char(environment, parser, 0)
		&& 'd' == guththila_next_char(environment, parser, 0)
		&& 'i' == guththila_next_char(environment, parser, 0)
		&& 'n' == guththila_next_char(environment, parser, 0)
		&& 'g' == guththila_next_char(environment, parser,
									  0))
    {
        ic = guththila_next_char(environment, parser, 0);
        guththila_close_token(environment, parser,
							  _attribute, 0);
        quote =
            guththila_process_eq(environment, parser, ic);
        nc = guththila_next_char(environment, parser, 0);
        guththila_open_token(environment, parser);
        while (quote != nc)
            nc = guththila_next_char(environment, parser, 0);
        guththila_close_token(environment, parser,
							  _attribute_value, 0);
        nc = guththila_next_char(environment, parser, 0);
        return guththila_skip_spaces(environment, parser,
									 nc);
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_ENCODING_DECLARATION_ERROR);
    return 0;
}


int AXIS2_CALL
guththila_process_sd_decl(axutil_env_t *
						  environment,
						  guththila_t *
						  parser)
{
    int quote = 0;
    int nc = 0;
    int ic = 0;
    guththila_open_token(environment, parser);
    if ('t' == guththila_next_char(environment, parser, 0)
		&& 'a' == guththila_next_char(environment, parser, 0)
		&& 'n' == guththila_next_char(environment, parser, 0)
		&& 'd' == guththila_next_char(environment, parser, 0)
		&& 'a' == guththila_next_char(environment, parser, 0)
		&& 'l' == guththila_next_char(environment, parser, 0)
		&& 'o' == guththila_next_char(environment, parser, 0)
		&& 'n' == guththila_next_char(environment, parser, 0)
		&& 'e' == guththila_next_char(environment, parser,
									  0))
        ic = guththila_next_char(environment, parser, 0);
    guththila_close_token(environment, parser, _attribute,
						  0);
    quote = guththila_process_eq(environment, parser, ic);
    nc = guththila_next_char(environment, parser, 0);
    guththila_open_token(environment, parser);
    while (quote != nc)
    {
        if ('y' == nc)
        {
            if ('e' !=
				guththila_next_char(environment, parser, 0)
				|| 's' != guththila_next_char(environment,
											  parser, 0))
                guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_STANDALONE_ERROR_IN_YES);
            else
                nc = guththila_next_char(environment, parser,
										 0);
        }
        else if ('n' == nc)
        {
            if ('o' !=
				guththila_next_char(environment, parser, 0))
                guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_STANDALONE_ERROR_IN_NO);
            else
                nc = guththila_next_char(environment, parser,
										 0);
        }
        else
            guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_STANDALONE_ERROR_YES_OR_NO_NOT_AVAILABLE);
    }
    guththila_close_token(environment, parser,
						  _attribute_value, 0);
    nc = guththila_next_char(environment, parser, 0);
    return guththila_skip_spaces(environment, parser, nc);
}


int AXIS2_CALL
guththila_process_xml_decl(axutil_env_t *
						   environment,
						   guththila_t *
						   parser)
{
    int ix;
    if ('x' == guththila_next_char(environment, parser, 0)
		&& 'm' == guththila_next_char(environment, parser, 0)
		&& 'l' == guththila_next_char(environment, parser,
									  0))
    {
        ix = guththila_process_version_info(environment,
											parser);

        if ('e' == ix)
            ix = guththila_process_encoding_decl(environment,
												 parser);

        if ('s' == ix)
            ix = guththila_process_sd_decl(environment,
										   parser);

        if ('?' == ix)
        {
            if ('>' !=
				guththila_next_char(environment, parser, 0))
                guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_MISSING_GREATER_SIGN_IN_XML_DECLARATION);
            else
            {
                while (guththila_is_space(environment, guththila_next_char(environment, parser, 0)));
                parser->_next--;
                parser->guththila_event = GUTHTHILA_START_DOCUMENT;
            }
        }
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_INCORRECT_XML_DECLARATION);
    return 0;
}


void AXIS2_CALL
guththila_reset(axutil_env_t * environment,
				guththila_t * parser)
{
    int ii;
    parser->offset = parser->_next;
	if (parser->name)
	{
		guththila_token_free (environment, parser->name);
		parser->name = NULL;
	}

	if (parser->prefix)
	{
		guththila_token_free (environment, parser->prefix);
		parser->prefix = NULL;
	}

	if (parser->value)
	{
		guththila_token_free (environment, parser->value);
		parser->value = NULL;
	}

    parser->is_whitespace = 0;
    parser->is_char = 0;

    ii = axutil_stack_size(parser->attrib, environment);
    for (; ii > 0; ii--)
    {
        guththila_attribute_t  *attribute;
        attribute = (guththila_attribute_t *) axutil_stack_pop(parser->attrib, 
															  environment);
		guththila_attribute_free (environment, attribute);
    }

    ii = axutil_stack_size(parser->stack, environment);
    for (; ii > 0; ii--)
    {
        guththila_token_t *d;
        d = (guththila_token_t *)axutil_stack_pop(parser->stack, environment);
		guththila_token_free (environment, d);
    }

    if (parser->guththila_event == GUTHTHILA_END_ELEMENT
		|| parser->guththila_event == GUTHTHILA_EMPTY_ELEMENT)
        guththila_close_element(environment, parser);
}


int AXIS2_CALL
guththila_is_space(axutil_env_t * environment,
				   int c)
{
    if (0x20 == c || 0xD == c || 0xA == c || 0x9 == c)
        return 1;
    else
        return 0;
}


int AXIS2_CALL
guththila_is_valid_starting_char(axutil_env_t *
								 environment,
								 guththila_t
								 * parser, int c)
{
    if (isalpha(c) || '_' == c || ':' == c)
        return 1;
    else
        return 0;
}


int AXIS2_CALL
guththila_process_name(axutil_env_t * environment,
					   guththila_t * parser)
{
    int c;
    guththila_char_t *x;
    x = guththila_last_char(environment, parser);
    if (!guththila_is_valid_starting_char
		(environment, parser, x[0]))
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_INVALID_NAME_STARTING_CHARACTER);

    guththila_open_token(environment, parser);
    c = guththila_next_char(environment, parser, 0);
    while (!
		   (guththila_is_space(environment, c) || '/' == c
			|| '=' == c || '?' == c || '>' == c))
    {
        if (':' == c)
        {
            guththila_close_token(environment, parser,
								  _prefix, 0);
            c = guththila_next_char(environment, parser, 0);
            guththila_open_token(environment, parser);
        }
        else
            c = guththila_next_char(environment, parser, 0);
    }
    guththila_close_token(environment, parser, _name, 0);

    return c;
}


int AXIS2_CALL
guththila_process_attribute_value(axutil_env_t *
								  environment,
								  guththila_t
								  * parser, int quote)
{
    int c = 0;
    if ('\'' == quote || '\"' == quote)
    {
        c = guththila_next_char(environment, parser, 0);
        guththila_open_token(environment, parser);
        do
        {
            c = guththila_next_char(environment, parser, 0);
            if (quote == c)
            {
                guththila_close_token(environment, parser,
									  _attribute_value, 0);
                return guththila_next_char(environment,
										   parser, 0);
            }
        }
        while ('<' != c || '&' != c);
    }
    else
        guththila_exception(p_FILE, LINE,  GUTHTHILA_ERROR_QUOTES_NOT_FOUND_BEFORE_ATTRIBUTE_VALUE);
    return c;
}


int AXIS2_CALL
guththila_process_attribute(axutil_env_t *
							environment,
							guththila_t *
							parser, int c)
{
    int q;
    q = guththila_skip_spaces(environment, parser, c);
    q = guththila_process_name(environment, parser);
    q = guththila_process_eq(environment, parser, q);
    q = guththila_process_attribute_value(environment,
										  parser, q);
    return q;
}


int AXIS2_CALL
guththila_processSTagOrEmptyElem(axutil_env_t *
								 environment,
								 guththila_t
								 * parser)
{
    int c;
    c = guththila_process_name(environment, parser);
    c = guththila_skip_spaces(environment, parser, c);
    parser->guththila_event = GUTHTHILA_START_ELEMENT;
    for (;;)
    {
        if ('/' == c)
        {
            parser->guththila_event = GUTHTHILA_EMPTY_ELEMENT;
            if ('>' ==
				guththila_next_char(environment, parser, 0))
                return c;
            else
                guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_EMPTY_ELEMENT_NOT_CLOSED);
        }
        else if ('>' == c)
            return c;
        else
        {
            c = guththila_process_attribute(environment,
											parser, c);
            c = guththila_skip_spaces(environment, parser,
									  c);
        }
    }
}


int AXIS2_CALL
guththila_process_char_data(axutil_env_t *
							environment,
							guththila_t *
							parser)
{
    int c = 0;
    int ref = 0;
    parser->is_whitespace = 0;
    parser->is_char = 0;

    parser->guththila_event = GUTHTHILA_CHARACTER;
    guththila_open_token(environment, parser);

    c = parser->buffer->buff [parser->_next - 1];

    if (isspace(c))
    {
        parser->is_whitespace = 1;
    }

    do
    {

        c = guththila_next_char(environment, parser, -1);

        if (isspace(c))
        {
            if (!parser->is_char)
                parser->is_whitespace = 1;
            else
                parser->is_whitespace = 0;
        }
        else if (c == '&')
            ref = 1;
        else if (c == -1)		/* first should check for eof then
								   only check of r != < */
        {
            guththila_close_token(environment, parser,
								  _char_data, ref);
            return 0;
        }
        else if (c != '<')
        {
            parser->is_whitespace = 0;
            parser->is_char = 1;
        }

    }
    while (c != '<');

    guththila_close_token(environment, parser, _char_data,
						  ref);
    return c;
}


int AXIS2_CALL
guththila_process_end_tag(axutil_env_t *
						  environment,
						  guththila_t *
						  parser)
{
    int c;
    c = guththila_next_char(environment, parser, 0);
    c = guththila_process_name(environment, parser);
    c = guththila_skip_spaces(environment, parser, c);
    if ('>' == c)
        parser->guththila_event = GUTHTHILA_END_ELEMENT;
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_END_TAG_NOT_CLOSED);
    return c;
}


int AXIS2_CALL
guththila_process_pi(axutil_env_t * environment,
					 guththila_t * parser)
{
    int c;
    parser->guththila_event = GUTHTHILA_COMMENT;
    c = guththila_next_char(environment, parser, 0);
    while ('<' != c)
        c = guththila_next_char(environment, parser, 0);
    return c;
}


int AXIS2_CALL
guththila_process_comment(axutil_env_t *
						  environment,
						  guththila_t *
						  parser)
{
    int c;
    if ('-' == guththila_next_char(environment, parser, 0)
		&& '-' == guththila_next_char(environment, parser,
									  0))
    {
        c = guththila_next_char(environment, parser, 0);
        while (1)
        {
            c = guththila_next_char(environment, parser, 0);
            if ('-' == c)
            {
                c = guththila_next_char(environment, parser,
										0);
                if ('-' == c)
                {
                    if ('>' ==
						guththila_next_char(environment,
											parser, 0))
                    {
                        parser->guththila_event = GUTHTHILA_COMMENT;
                        while ('<' != c)
                        {
                            c = guththila_next_char
								(environment, parser, -1);
                            if (c == -1)
                                return c;
                        }
                        return c;
                    }
                    else
                        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_MORE_HYPENS_OCCURED_IN_COMMENT);
                }
            }
        }
    }
    else
    {
        c = guththila_next_char(environment, parser, 0);
        while ('<' != c)
            c = guththila_next_char(environment, parser, -1);
    }
    return 0;
}


int AXIS2_CALL
guththila_tokenize(axutil_env_t * environment,
				   guththila_t * parser)
{
    do
    {
        int c;
        c = guththila_next_char(environment, parser, -1);
        if (c == -1)
            return -1;

        switch (parser->status)
        {
            case S_1:
                while (isspace(c))
                {
                    c = guththila_next_char(environment, parser, -1);
                    if (c == -1)
                        return -1;
                }

                if ('<' == c)
                    parser->status = S_2;
                else
                    parser->status = S_0;
                break;
            case S_2:
            {
                if ('?' == c)
                {
                    guththila_process_xml_decl(environment,
											   parser);
                    parser->status = S_3;
                }
                else if ('!' == c)
                {
                    guththila_process_comment(environment,
											  parser);
                    parser->status = S_4;
                }
                else
                {
                    guththila_processSTagOrEmptyElem
						(environment, parser);
                    parser->status = S_3;
                }
            }
            break;
            case S_3:
                if ('<' == c)
                    parser->status = S_4;
                else
                {
                    c = guththila_process_char_data(environment,
													parser);
                    if ('<' == c)
                    {
                        parser->status = S_4;
                        return parser->guththila_event;
                    }
                    else if ('\0' == c)
                        parser->status = S_3;
                    else
                        parser->status = S_0;
                }
                break;
            case S_4:
                if ('/' == c)
                {
                    guththila_process_end_tag(environment,
											  parser);
                    parser->status = S_3;
                }
                else if ('?' == c)
                    guththila_process_pi(environment, parser);
                else if ('!' == c)
                    guththila_process_comment(environment,
											  parser);
                else
                {
                    guththila_processSTagOrEmptyElem(environment,
													 parser);
                    parser->status = S_3;
                }
                break;
            case S_0:
                guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_TOKENIZE_ERROR);
        }
    }
    while (parser->status != S_3);
    return parser->guththila_event;
}


AXIS2_EXTERN  int AXIS2_CALL
guththila_next(axutil_env_t * environment,
			   guththila_t * parser)
{
    int ix;
    guththila_reset(environment, parser);
    ix = guththila_tokenize(environment, parser);
    switch (ix)
    {
        case - 1:
            return -1;

        case GUTHTHILA_START_DOCUMENT:
        {
            int ix;
            guththila_token_t *token;
            guththila_token_t *att_name;
            guththila_token_t *att_value;
            ix = axutil_stack_size(parser->stack, environment);
            for (; ix > 0; ix--)
            {
                token = (guththila_token_t *)axutil_stack_pop(parser->stack, environment);
                if (token->type == _attribute_value)
                {
                    att_value = token;
                    token = (guththila_token_t *)axutil_stack_pop(parser->stack, environment);
                    ix--;
                    att_name = token;
                    guththila_add_attribute(environment,
											parser, att_name,
											att_value);
                }
            }
        }
        break;
        case GUTHTHILA_START_ELEMENT:
        case GUTHTHILA_EMPTY_ELEMENT:
        {
            int is = 0;
            guththila_token_t *token;
            guththila_token_t *name = NULL;
            guththila_token_t *value = NULL;
            is = axutil_stack_size(parser->stack, environment);
            for (;
				 is > 0 && 	axutil_stack_size(parser->stack, environment);
				 is--)
            {
                token = (guththila_token_t *) axutil_stack_pop(parser->stack, environment);
                /* be careful about memory leaks, when we pull it we get
                   seperate _element need to free it properly */
                if (token->type == _attribute_value)
                {
                    value = token;
                    token = (guththila_token_t *) axutil_stack_pop(parser->stack, environment);
                    is--;
                    name = token;
                    if (!guththila_token_compare
						(environment, token, "xmlns", 5,
						 parser->unicode_state))
					{
                        guththila_add_namespace(environment,
												parser, name,
												value);
					guththila_token_free (environment, name);
					guththila_token_free (environment, value);
					}
                    else
                        guththila_add_attribute(environment,
												parser, name,
												value);

                }
                else if (token->type == _name)
                {
                    name = token;
                    parser->name = name;
                    parser->prefix = NULL;

                }
                else if (token->type == _prefix)
                {
                    guththila_attribute_t *attribute;
                    if (!guththila_token_compare
						(environment, token, "xmlns", 5,
						 parser->unicode_state))
                    {
                        attribute = (guththila_attribute_t *) axutil_stack_pop(parser->attrib, environment);
                        guththila_add_namespace(environment,
												parser,
												attribute->
												name,
												attribute->
												value);
						guththila_attribute_free (environment, attribute);
						guththila_token_free (environment, token);
                    }
                    else
                    {
                        if (parser->name)
                            parser->prefix = token;
                        else
                        {
                            attribute = (guththila_attribute_t *) axutil_stack_pop(parser->attrib, environment);
                            guththila_add_attribute_with_prefix
								(environment, parser, token,
								 attribute->name, attribute->value);
							axutil_stack_push (parser->other, environment, (void *) attribute);
                        }
                    }
                }
                else
                    guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_INVALID_TOKEN_TYPE);
            }
            guththila_open_element(environment, parser);
        }
        break;
        case GUTHTHILA_END_ELEMENT:
        {
            guththila_token_t *token;
            token = (guththila_token_t *) axutil_stack_pop(parser->stack, environment);
            if (token->type == _name)
			{
                parser->name = token;
			}

            if (axutil_stack_size(parser->stack, environment))
            {
                token = (guththila_token_t *) axutil_stack_pop(parser->stack, environment);
                if (token->type == _prefix)
                    parser->prefix = token;
            }
        }
        break;
        case GUTHTHILA_CHARACTER:
        {
            guththila_token_t *token;
            token = (guththila_token_t *) axutil_stack_pop(parser->stack, environment);
            parser->value = token;
        }
        break;
        case GUTHTHILA_ENTITY_REFERANCE:
            break;
        case GUTHTHILA_COMMENT:
            break;

    };
    return parser->guththila_event;
}


void AXIS2_CALL
guththila_open_element(axutil_env_t * environment,
					   guththila_t * parser)
{
    int ii;
    guththila_depth_t *m =
        (guththila_depth_t *) AXIS2_MALLOC(environment->allocator,
										   sizeof(guththila_depth_t));
    guththila_depth_t *l = NULL;
    guththila_depth_t *depth;
    ii = axutil_stack_size(parser->dep, environment);
    if (!ii)
    {
        m->first = 0;
        m->total = axutil_stack_size(parser->namesp, environment);
        m->count = m->total;
        axutil_stack_push(parser->dep, environment, m);
    }
    else
    {
        depth = (guththila_depth_t *) axutil_stack_get(parser->dep, environment);
        l = depth;
        m->first = l->first + l->count;
        m->total = axutil_stack_size(parser->namesp, environment);
        m->count = m->total - l->total;
        axutil_stack_push(parser->dep, environment, m);
    }
}


void AXIS2_CALL
guththila_close_element(axutil_env_t *
						environment,
						guththila_t * parser)
{
    guththila_depth_t *depth;
    guththila_namespace_t *namespace;
    int ii;
    depth = (guththila_depth_t *) axutil_stack_pop(parser->dep, environment);
    ii = depth->count;
    for (; ii > 0; ii--)
    {
        namespace = (guththila_namespace_t *) axutil_stack_pop(parser->namesp, environment);
        if (namespace->name)
        {
            AXIS2_FREE(environment->allocator, namespace->name);
            namespace->name = NULL;
        }
        if (namespace->uri)
        {
            AXIS2_FREE(environment->allocator, namespace->uri);
            namespace->uri = NULL;
        }
		AXIS2_FREE (environment->allocator, namespace);
    }
	if (depth)
		AXIS2_FREE (environment->allocator, depth);
}


void AXIS2_CALL
guththila_add_attribute(axutil_env_t *
						environment,
						guththila_t * parser,
						guththila_token_t * name,
						guththila_token_t * value)
{
    guththila_attribute_t *att = NULL;
	att = guththila_attribute_create (environment, NULL, name, value, NULL);
    axutil_stack_push(parser->attrib, environment, att);
}


void AXIS2_CALL
guththila_add_attribute_with_prefix(axutil_env_t *
									environment,
									guththila_t
									* parser,
									guththila_token_t *
									prefix,
									guththila_token_t * name,
									guththila_token_t *
									value)
{
    guththila_attribute_t *att;
	att = guththila_attribute_create (environment, prefix, name, value, NULL);
    axutil_stack_push(parser->attrib, environment, att);
}

void AXIS2_CALL
guththila_add_namespace(axutil_env_t *
						environment,
						guththila_t * parser,
						guththila_token_t * name,
						guththila_token_t * uri)
{
    guththila_namespace_t *ns;
    ns = (guththila_namespace_t *) AXIS2_MALLOC(environment->allocator,
												sizeof (guththila_namespace_t));
    ns->name = guththila_token_to_string(environment, 
										 name, 
										 parser->unicode_state);
    ns->length = axutil_strlen(ns->name);
    ns->uri = guththila_token_to_string(environment, 
										uri, 
										parser->unicode_state);
    ns->lengthuri = axutil_strlen(ns->uri);
    axutil_stack_push(parser->namesp, environment, ns);
}


AXIS2_EXTERN  int AXIS2_CALL
guththila_get_attribute_count(axutil_env_t *
							  environment,
							  guththila_t *
							  parser)
{
    return axutil_stack_size(parser->attrib, environment);
}


AXIS2_EXTERN  guththila_attribute_t * AXIS2_CALL
guththila_get_attribute(axutil_env_t *
						environment,
						guththila_t * parser)
{
    guththila_attribute_t *attribute;
    attribute = (guththila_attribute_t *) axutil_stack_pop(parser->attrib, environment);
    if (attribute)
        return attribute;
    else
        return NULL;
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_attribute_name(axutil_env_t *
							 environment,
							 guththila_t *
							 parser,
							 guththila_attribute_t * att)
{
    if (!att)
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_NULL_ATTRIBUTE_NAME);
    if (att->name->end)
        return guththila_token_to_string(environment, att->name,
										 parser->unicode_state);
    return NULL;
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_attribute_value(axutil_env_t *
							  environment,
							  guththila_t *
							  parser,
							  guththila_attribute_t * att)
{
    if (!att)
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_NULL_ATTRIBUTE_VALUE);
    if (att->value->end)
        return guththila_token_to_string(environment, att->value,
										 parser->unicode_state);
    return NULL;
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_attribute_prefix(axutil_env_t *
							   environment,
							   guththila_t *
							   parser,
							   guththila_attribute_t * att)
{
    if (!att)
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_NULL_ATTRIBUTE_PREFIX);
    if (att->prefix->end)
        return guththila_token_to_string(environment, att->prefix,
										 parser->unicode_state);
    return NULL;
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_attribute_prefix_by_number(axutil_env_t * environment, guththila_t * parser, int i)
{
    int ix = axutil_stack_size(parser->attrib, environment);
    guththila_attribute_t *attribute = NULL;
    if (i > ix)
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_REQUESTED_NUMBER_GREATER_THAN_STACK_SIZE);
    else
    {
        attribute = (guththila_attribute_t *) axutil_stack_get_at(parser->attrib, environment, ix - i);
    }
    return guththila_token_to_string(environment, attribute->prefix,
									 parser->unicode_state);
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_attribute_name_by_number(axutil_env_t * environment, guththila_t * parser, int i)
{
    int ix = axutil_stack_size(parser->attrib, environment);
    guththila_attribute_t *attribute = NULL;
    if (i > ix)
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_REQUESTED_NUMBER_GREATER_THAN_STACK_SIZE);
    else
    {
        attribute = (guththila_attribute_t *) axutil_stack_get_at(parser->attrib, environment, ix - i);
    }
    return guththila_token_to_string(environment, attribute->name,
									 parser->unicode_state);
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_attribute_value_by_number(axutil_env_t * environment,
										guththila_t * parser, int i)
{
    int ix = axutil_stack_size(parser->attrib, environment);
    guththila_attribute_t *attribute = NULL;
    if (i > ix)
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_REQUESTED_NUMBER_GREATER_THAN_STACK_SIZE);
    else
    {
        attribute = (guththila_attribute_t *) axutil_stack_get_at(parser->attrib, environment, ix - i);
    }
    return guththila_token_to_string(environment, attribute->value,
									 parser->unicode_state);
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_name(axutil_env_t * environment,
				   guththila_t * parser)
{
    if (parser->name->end)
        return guththila_token_to_string(environment, parser->name,
										 parser->unicode_state);
    return NULL;
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_value(axutil_env_t * environment,
					guththila_t * parser)
{
    if (parser->value->end)
        return guththila_token_to_string(environment, parser->value,
										 parser->unicode_state);
    else
        return NULL;
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_prefix(axutil_env_t * environment,
					 guththila_t * parser)
{
    if (parser->prefix)
        return guththila_token_to_string(environment, parser->prefix,
										 parser->unicode_state);
    return NULL;
}


AXIS2_EXTERN  int AXIS2_CALL
guththila_get_namespace_count(
	axutil_env_t *
	environment,
	guththila_t *
	parser)
{
    if (parser->namesp)
        return axutil_stack_size(parser->namesp, environment);
    else
        return 0;
}


AXIS2_EXTERN  guththila_namespace_t * AXIS2_CALL
guththila_get_namespace(
	axutil_env_t * environment,
	guththila_t * parser)
{
    guththila_namespace_t *namespace;
    namespace = (guththila_namespace_t *) axutil_stack_get(parser->namesp, environment);
    if (namespace)
        return namespace;
    else
        return NULL;
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_namespace_prefix(axutil_env_t *
							   environment,
							   guththila_t *
							   parser,
							   guththila_namespace_t * ns)
{
    if (ns)
        return axutil_strdup(environment, ns->name);
    else
        return NULL;
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_namespace_uri(axutil_env_t *
							environment,
							guththila_t *
							parser,
							guththila_namespace_t * ns)
{
    if (ns)
        return axutil_strdup(environment, ns->uri);
    else
        return NULL;
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_namespace_prefix_by_number(axutil_env_t * environment,
										 guththila_t * parser,
										 int i)
{
    int ix = axutil_stack_size(parser->namesp, environment);
    guththila_namespace_t *ns = NULL;
    if (i > ix)
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_REQUESTED_NUMBER_GREATER_THAN_STACK_SIZE);
    else
    {
        ns = (guththila_namespace_t *) axutil_stack_get_at(parser->namesp, environment, ix - i);
    }
    return axutil_strdup(environment, ns->name);
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_namespace_uri_by_number(axutil_env_t
									  * environment,
									  guththila_t
									  * parser, int i)
{
    int ix = axutil_stack_size(parser->namesp, environment);
    guththila_namespace_t *ns = NULL;
    if (i > ix)
        guththila_exception(p_FILE, LINE, GUTHTHILA_ERROR_REQUESTED_NUMBER_GREATER_THAN_STACK_SIZE);
    else
    {
        ns = (guththila_namespace_t *) axutil_stack_get_at(parser->namesp, environment, ix - i);
    }
    return axutil_strdup(environment, ns->uri);
}


AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_attribute_namespace_by_number(axutil_env_t * environment,
											guththila_t * parser,
											int i)
{
    guththila_char_t *att_prefix;
    int ii;
    int ix = axutil_stack_size(parser->namesp, environment);
    guththila_namespace_t *ns = NULL;
    att_prefix =
        guththila_get_attribute_prefix_by_number(environment,
												 parser, i);

    for (ii = 0; ii <= ix; ii++)
    {
        ns = (guththila_namespace_t *) axutil_stack_get_at(parser->namesp, environment, ix - ii);
        if (ns)
        {
            if (ns && att_prefix)
            {
                if (!
					(axutil_strcmp
					 (ns->name, att_prefix)))
                    return axutil_strdup(environment, ns->uri);
            }
        }
    }
    return 0;
}

AXIS2_EXTERN  guththila_char_t * AXIS2_CALL
guththila_get_encoding(axutil_env_t *environment,
					   guththila_t *parser)
{
    /* parser will find character encoding base on Byte Order Mark
       (BOM). */
    switch (parser->unicode_state)
    {
        case None:
            return "UTF-8";
        case BE:
            return "UTF-16";
        case LE:
            return "UTF-16";
        default:
            return (guththila_char_t *) GUTHTHILA_ERROR_INVALID_ENCODING_DECLARATION;
    };
}
