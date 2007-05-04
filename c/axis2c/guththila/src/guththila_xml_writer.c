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

#include "guththila.h"


AXIS2_EXTERN void AXIS2_CALL
guththila_create_xml_stream_writer(axutil_env_t *env, guththila_t *p, char *file)
{
    if (p || file)
    {
        p->xsw = (guththila_xml_writer_t *) AXIS2_MALLOC(env->allocator, 
														 sizeof(guththila_xml_writer_t));
        p->xsw->writer = guththila_writer_create_for_file(env, file);
        p->xsw->element = axutil_stack_create(env);
        p->xsw->attribute = axutil_stack_create(env);
        p->xsw->namespace = axutil_stack_create(env);
        p->xsw->depth = axutil_stack_create(env);
        p->xsw->next = 0;
        p->xsw->offset = 0;
        p->xsw->last = GUTHTHILA_BUFFER_SIZE;	/* size of the buffer */
        p->xsw->start_element_open = -1;
        p->xsw->empty_element_open = -1;
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);
}


AXIS2_EXTERN void AXIS2_CALL
guththila_create_xml_stream_writer_for_memory(axutil_env_t *env, guththila_t *p)
{
    if (p)
    {
        p->xsw = (guththila_xml_writer_t *) AXIS2_MALLOC(env->allocator, 
														 sizeof(guththila_xml_writer_t));
        p->xsw->writer = guththila_writer_create_for_memory(env);
        p->xsw->element = axutil_stack_create(env);
        p->xsw->attribute = axutil_stack_create(env);
        p->xsw->namespace = axutil_stack_create(env);
        p->xsw->depth = axutil_stack_create(env);
        p->xsw->next = 0;
        p->xsw->offset = 0;
        p->xsw->last = GUTHTHILA_BUFFER_SIZE;	/* size of the buffer */
        p->xsw->start_element_open = -1;
        p->xsw->empty_element_open = -1;
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);
}

AXIS2_EXTERN void AXIS2_CALL
guththila_xml_writer_free(axutil_env_t *env, guththila_t *p)
{

    int size;
    size = 0;

    
    /*   guththila_flush (env, p); */
    guththila_write_end_document(env, p);
    
    if (p->xsw->element)
    {
        void *element;
        size = 0;

        size = axutil_stack_size(p->xsw->element, env);
        if (size)
        {
            for (; size > 0; size--)
            {
                element = axutil_stack_pop(p->xsw->element, env);
                AXIS2_FREE(env->allocator, element);
                element = NULL;
            }
        }
        axutil_stack_free(p->xsw->element, env);
        p->xsw->element = NULL;
    }


    if (p->xsw->attribute)
    {
        size = 0;
        size = axutil_stack_size(p->xsw->attribute, env);
        if (size)
        {
            guththila_attribute_t* att;
            for (;size > 0; size--)
            {
                att = (guththila_attribute_t *)axutil_stack_pop(p->xsw->attribute, env);
				guththila_attribute_free (env, att);
                att = NULL;
            }
        }
        axutil_stack_free(p->xsw->attribute, env);
        p->xsw->attribute = NULL;
    }


    if (p->xsw->namespace)
    {
        size = 0;
        size = axutil_stack_size(p->xsw->namespace, env);
        if (size)
        {
            guththila_namespace_t* ns;
            for (;size > 0; size--)
            {
                ns = (guththila_namespace_t *)axutil_stack_pop(p->xsw->namespace, env);
                AXIS2_FREE(env->allocator, ns);
                ns = NULL;
            }
        }
		axutil_stack_free(p->xsw->namespace, env);
		p->xsw->namespace = NULL;
    }


    if (p->xsw->depth)
    {
        size = 0;
        size = axutil_stack_size(p->xsw->depth, env);
        if (size)
        {
            guththila_depth_t* depth;
            for (;size > 0; size--)
            {
                depth = (guththila_depth_t *)axutil_stack_pop(p->xsw->depth, env);
                AXIS2_FREE(env->allocator, depth);
                depth = NULL;
            }
        }
		axutil_stack_free(p->xsw->depth, env);
		p->xsw->depth = NULL;

    }

    if (p->xsw->writer)
    {
        guththila_writer_free(env, p->xsw->writer);
        p->xsw->writer = NULL;
    }


    if (p->xsw)
    {
        AXIS2_FREE(env->allocator, p->xsw);
        p->xsw = NULL;
    }
}


int AXIS2_CALL
guththila_check_xml_stream_writer(axutil_env_t *env, guththila_t *p)
{
    if (!p->xsw->writer)
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_WRITER);
    else
        return 1;
    return 0;
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_start_document(axutil_env_t *env,
							   guththila_t *p)
{
    char *sd =  NULL;
    
    sd  = "<?xml version = \"1.0\" encoding = \"utf-8\" ?>";
    guththila_write_to_buffer(env, p, sd);
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_end_element(axutil_env_t *env, guththila_t *p)
{
    void *element = NULL;
    
    element = axutil_stack_pop(p->xsw->element, env);
    if (p->xsw->empty_element_open)
    {
        guththila_close_start_element(env, p);
    }
    else
    {
        guththila_close_start_element(env, p);
        if (element)
        {
            guththila_write_to_buffer(env, p, "</");
            guththila_write_to_buffer(env, p, element);
            guththila_write_to_buffer(env, p, ">");
            guththila_close_depth_element(env, p);
        }
        else
            guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);
    }
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_start_element(axutil_env_t *env, guththila_t *p, char *start_element)
{
    int size;
    void *element;
    if (!p || !start_element)
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);
    else
    {
        
        guththila_close_start_element(env, p);
        guththila_open_depth_element(env, p);
        size = axutil_stack_size(p->xsw->element, env);

        if (size)
        {
            element = axutil_stack_get_at(p->xsw->element, env, 0);
            if (!strcmp((char *)element, start_element))
                guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_MATCHING_ELEMENTS);
        }

        guththila_check_name_validity(env, p, start_element);
        p->xsw->start_element_open = 1;

        if (!p->xsw->empty_element_open)
            axutil_stack_push(p->xsw->element, env, start_element);
        guththila_write_to_buffer(env, p, "<");
        guththila_write_to_buffer(env, p, start_element);
    }
}


AXIS2_EXTERN void  AXIS2_CALL
guththila_write_to_buffer(axutil_env_t *env, guththila_t *p, const char *buff)
{
    int c = 0;
    int ii = 0;
    guththila_writer_impl_t *writer_impl;
	unsigned int size = 0;
	guththila_char_t *init_buffer = NULL;
    if (buff)
    {
        ii = strlen (buff);
		if (p->xsw->writer->guththila_writer_type == GUTHTHILA_WRITER_MEMORY)
		{
			writer_impl = (guththila_writer_impl_t *)p->xsw->writer;
			
			if (writer_impl->buffer->buff)
				size = writer_impl->buffer->next;
			
			if ((size + ii) > writer_impl->buffer->size)
			{
				init_buffer = writer_impl->buffer->buff;
				writer_impl->buffer = guththila_buffer_grow(env, writer_impl->buffer, ii);
				p->xsw->last = writer_impl->buffer->size;
 				axutil_stack_push (p->other, env, init_buffer);;
			}
		}
        c = guththila_writer_write(env, (char *)buff, 0, ii, p->xsw->writer);
		p->xsw->offset = p->xsw->next;
		p->xsw->next += c;
	}
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_characters(axutil_env_t *env, guththila_t *p, const char *buff)
{
    
    guththila_close_start_element(env, p);

    if (buff)
    {
        guththila_write_to_buffer(env, p, buff);
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_INVALID_BUFFER);
}


void AXIS2_CALL
guththila_close_start_element(axutil_env_t *env, guththila_t *p)
{
    int stack_size = 0;
    if (p->xsw->start_element_open != -1 && p->xsw->empty_element_open != -1)
    {
        if (p->xsw->start_element_open && p->xsw->empty_element_open)
        {
            p->xsw->start_element_open = 0;
            p->xsw->empty_element_open = 0;
            guththila_write_to_buffer(env, p, "/>");
        }

        if (p->xsw->start_element_open && !p->xsw->empty_element_open)
        {
            p->xsw->start_element_open = 0;
            guththila_write_to_buffer(env, p, ">");
        }

        stack_size = axutil_stack_size(p->xsw->attribute, env);
        if (stack_size)
        {
            guththila_attribute_t* att = NULL;
            for (;stack_size > 0; stack_size--)
            {
                att = (guththila_attribute_t *)axutil_stack_pop(p->xsw->attribute, env);
/* 				guththila_attribute_free (env, att); */
                att = NULL;
            }
        }

    }
    else
    {
        p->xsw->start_element_open = 0;
        p->xsw->empty_element_open = 0;
    }

    /*   guththila_open_depth_element (env, p); */
}


void  AXIS2_CALL
guththila_check_name_validity(axutil_env_t *env, guththila_t *p, char *name)
{
    int length;
    int ii;
    length = strlen(name);
    /* ideograhic characters are also valid for name_starting charactes
     * need to add them to here isIdeograpic function doesn't
     * functionning correctly yet*/
    if (!(isalpha(name[0]) || name[0] == '_' || name[0] == ':'))
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_INVALID_CHAR_IN_NAME);

    /* xml in any case combination isn't allow */
    if ((name[0] == 'x' || name[0] == 'X')
		&& (name[1] == 'm' || name[1] == 'M')
		&& (name[2] == 'l' || name[2] == 'L'))
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_XML_STRING_IN_NAME);

    /* some punctuation's not allowed */
    for (ii = 1; ii < length; ii++)
    {
        if ((name[ii] == '$' || name[ii] == '^' || name[ii] == '%'
			 || name[ii] == ';' || name[ii] == '\'' || name[ii] == '"'
			 || name[ii] == '&' || name[ii] == '<' || name[ii] == '>'
			 || isspace(name[ii])))
            guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_INVALID_CHAR_IN_NAME);
    }
}


int AXIS2_CALL
guththila_is_ideographic(char *id)
{
    int ii;
    short *xy = (short *)id;
    for (ii = 0x4e00 ; ii < 0x9fa5; ii ++)
    {
        if (ii == xy[0])
            return 1;
    }

    if (0x3007 == xy[0])
        return 1;

    for (ii = 0x3021 ; ii <  0x3029; ii ++)
    {
        if (ii == xy[0])
            return 1;
    }
    return 0;
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_comment(axutil_env_t *env, guththila_t *p, const char *buff)
{
    char *s = NULL;
    
    guththila_close_start_element(env, p);
    s   = strchr(buff, '-');
    if (s && s[1] == '-')
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EXCESS_HYPENS_IN_COMMENT);
    guththila_write_to_buffer(env, p, "<!--");
    guththila_write_to_buffer(env, p, buff);
    guththila_write_to_buffer(env, p, "-->");
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_escape_character(axutil_env_t *env, guththila_t *p, const char *buff)
{
    guththila_close_start_element(env, p);
    if (buff)
    {
        switch (buff[0])
        {
            case '>':
            {
                guththila_write_to_buffer(env, p, "&gt;");
            }
            break;
            case '<':
            {
                guththila_write_to_buffer(env, p, "&lt;");
            }
            break;
            case '\'':
            {
                guththila_write_to_buffer(env, p, "&apos;");
            }
            break;
            case '"':
            {
                guththila_write_to_buffer(env, p, "&quot;");
            }
            break;
            case '&':
            {
                guththila_write_to_buffer(env, p, "&amp;");
            }
            break;
        };
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_INVALID_BUFFER);
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_attribute(axutil_env_t *env, guththila_t *p, const char *local_name, const char *value)
{
    int size = 0;
    void *element;
    guththila_attribute_t *attr;

    if (!p->xsw->start_element_open)
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);

    size = axutil_stack_size(p->xsw->attribute, env);
    if (size)
    {
        int ii;
        for (ii = 0; ii <= size; ii++)
        {
            element = axutil_stack_get_at(p->xsw->attribute, env, size - ii);
            if (element)
            {
                attr = (guththila_attribute_t *)element;
                if (strcmp((char *)attr->name, local_name))
                {
                    guththila_do_write_attribute(env, p, local_name, value);
                    break;
                }
                else
                    guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_SAME_ATTRIBUTE_REPEAT);
            }
        }


    }
    else
    {
        guththila_do_write_attribute(env, p, local_name, value);
    }
}


void AXIS2_CALL
guththila_do_write_attribute(axutil_env_t *env,
							 guththila_t *p,
							 const char *local_name,
							 const char *value)
{
    guththila_attribute_t *attr = (guththila_attribute_t *) AXIS2_MALLOC(env->allocator, sizeof(guththila_attribute_t));

    if (local_name)
        attr->name = (guththila_token_t *)local_name;
    if (value)
        attr->value = (guththila_token_t *)value;
    if (local_name && value)
    {
        axutil_stack_push(p->xsw->attribute, env, attr);
    }

    guththila_check_name_validity(env, p, (char *)local_name);

    if (strrchr(value, '&')
		|| strrchr(value, '<')
		|| strrchr(value, '\"'))
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_INVALID_CHAR_IN_ATTRIBUTE);

    guththila_write_to_buffer(env, p, " ");
    guththila_write_to_buffer(env, p, local_name);
    guththila_write_to_buffer(env, p, " = \"");
    guththila_write_to_buffer(env, p, value);
    guththila_write_to_buffer(env, p, "\"");
}


void AXIS2_CALL
guththila_write_empty_element(axutil_env_t *env, guththila_t *p, char *empty_element)
{
    
    guththila_close_start_element(env, p);
    p->xsw->start_element_open = 0;
    p->xsw->empty_element_open = 1;
    guththila_write_start_element(env, p, empty_element);
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_default_namespace(axutil_env_t *env, guththila_t *p, char *namespace_uri)
{
    if (!p->xsw->start_element_open)
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);
    else
    {

        if (guththila_check_default_namespace(env, p, namespace_uri))
        {
            guththila_do_write_default_namespace(env, p, namespace_uri);
        }
    }
}


int AXIS2_CALL
guththila_check_default_namespace(axutil_env_t *env, guththila_t *p, char *ns_uri)
{
    int size;
    int ii;
    void *element;
    guththila_namespace_t *ns;
    size = axutil_stack_size(p->xsw->namespace, env);
    if (size)
    {
        for (ii = 0; ii <= size; ii++)
        {
            element = axutil_stack_get_at(p->xsw->namespace, env, size - ii);
            if (element)
            {
                ns = (guththila_namespace_t *)element;
                if (ns)
                {
                    if (!ns->length || !strcmp(ns->uri, ns_uri))
                        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_MATCHING_ELEMENTS);
                }
            }
        }
        return 1;

    }
    else
        return 1;
}


void AXIS2_CALL
guththila_do_write_default_namespace(axutil_env_t *env, guththila_t *p, char *ns_uri)
{
    guththila_namespace_t *ns = (guththila_namespace_t *) AXIS2_MALLOC(env->allocator, sizeof(guththila_namespace_t));
    ns->name = NULL;
    ns->length = 0;
    ns->uri = ns_uri;
    ns->lengthuri = strlen(ns_uri);
    axutil_stack_push(p->xsw->namespace, env, (void *)ns);

    guththila_write_to_buffer(env, p, " ");
    guththila_write_to_buffer(env, p, "xmlns");
    guththila_write_to_buffer(env, p, "=\'");
    guththila_write_to_buffer(env, p, ns_uri);
    guththila_write_to_buffer(env, p, "\'");
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_namespace(axutil_env_t *env, guththila_t *p, char *prefix, char *uri)
{
    if (!p->xsw->start_element_open)
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);

    if (!prefix || !strcmp(prefix, ""))
        guththila_do_write_default_namespace(env, p, uri);
    else
    {
        if (guththila_check_prefix_validity(env, p, prefix, uri))
            guththila_do_write_namespace(env, p, prefix, uri);
    }


}


int AXIS2_CALL
guththila_check_prefix_validity(axutil_env_t *env, guththila_t *p, char *prefix, char *uri)
{
    int size = 0;
    int ii = 0;
    void *element = NULL;
    guththila_namespace_t *ns = NULL;
    size = axutil_stack_size(p->xsw->namespace, env);
    if (size)
    {
        for (ii = 0; ii <= size; ii++)
        {
            element = axutil_stack_get_at(p->xsw->namespace, env, size - ii);
            if (element)
            {
                ns = (guththila_namespace_t *)element;
                if (ns->name && prefix)
                {
                    if (!strcmp(ns->name, prefix))
                    {
                        if (ns->uri && uri)
                        {
                            if (strcmp(ns->uri, uri))
                                guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_MATCHING_ELEMENTS);
                            else
                                return 0;
                        }

                    }
                }
            }
        }
        return 1;
    }
    else
        return 1;
}


void AXIS2_CALL
guththila_do_write_namespace(axutil_env_t *env, guththila_t *p, char *prefix, char *uri)
{
    guththila_namespace_t *ns = (guththila_namespace_t *) AXIS2_MALLOC(env->allocator, sizeof(guththila_namespace_t));
    ns->name = prefix;
    ns->length = strlen(prefix);
    ns->uri = uri;
    ns->lengthuri = strlen(uri);
    axutil_stack_push(p->xsw->namespace, env, (void *)ns);

    guththila_write_to_buffer(env, p, " ");
    guththila_write_to_buffer(env, p, "xmlns:");
    guththila_write_to_buffer(env, p, prefix);
    guththila_write_to_buffer(env, p, " = \'");
    guththila_write_to_buffer(env, p, uri);
    guththila_write_to_buffer(env, p, "\'");
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_attribute_with_prefix_and_namespace(axutil_env_t *env, guththila_t *p,
													const char *prefix, const char *namespace,
													const char *local_name, const char *value)
{
    int size = 0;
    void *element;
    guththila_attribute_t *attr;

    if (!p->xsw->start_element_open)
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);

    if (prefix && namespace)
        guththila_write_namespace(env, p, (char *)prefix, (char *)namespace);

    size = axutil_stack_size(p->xsw->attribute, env);
    if (size)
    {
        int ii;
        for (ii = 0; ii <= size; ii++)
        {
            element = axutil_stack_get_at(p->xsw->attribute, env, size - ii);
            if (element)
            {
                attr = (guththila_attribute_t *)element;
                /* We want to make sure that out checking attribute has
				   the prefix otherwise we don't wan't to worry */
                if (attr->name && attr->prefix)
                {
                    if (!strcmp((char *)attr->name, local_name) && !strcmp((char *)attr->prefix, prefix))
                        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_MATCHING_ELEMENTS);
                    else
                    {
                        guththila_do_write_attribute_with_prefix_and_namespace(env, p, prefix, namespace, local_name, value);
                        break;
                    }
                }
                else
                {
                    /* since att->prefix is null im going to write it here */
                    guththila_do_write_attribute_with_prefix_and_namespace(env, p, prefix, namespace, local_name, value);
                    break;
                }
            }
        }

    }
    else
    {
        guththila_do_write_attribute_with_prefix_and_namespace(env, p, prefix, namespace, local_name, value);
    }

}


void AXIS2_CALL
guththila_do_write_attribute_with_prefix_and_namespace(axutil_env_t *env, guththila_t *p,
													   const char *prefix, const char *namespace_uri,
													   const char *local_name, const char *value)
{
    guththila_attribute_t *attr = (guththila_attribute_t *) AXIS2_MALLOC(env->allocator, sizeof(guththila_attribute_t));

    if (prefix)
        attr->prefix = (guththila_token_t *)prefix;
    if (namespace_uri)
        attr->namespace_uri = (guththila_token_t *)namespace_uri;
    if (local_name)
        attr->name = (guththila_token_t *)local_name;
    if (value)
        attr->value = (guththila_token_t *)value;

	axutil_stack_push(p->xsw->attribute, env, (void *)attr);
	axutil_stack_push(p->other, env, attr);
	guththila_check_name_validity(env, p, (char *)local_name);

    if (strrchr(value, '&')
		|| strrchr(value, '<')
		|| strrchr(value, '\''))
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_INVALID_CHAR_IN_ATTRIBUTE);

    guththila_write_to_buffer(env, p, " ");
    if (prefix)
    {
        guththila_write_to_buffer(env, p, prefix);
        guththila_write_to_buffer(env, p, ":");
    }
    guththila_write_to_buffer(env, p, local_name);
    guththila_write_to_buffer(env, p, " = \'");
    guththila_write_to_buffer(env, p, value);
    guththila_write_to_buffer(env, p, "\'");
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_attribute_with_prefix(axutil_env_t *env, guththila_t *p, const char *prefix,
									  const char *local_name, const char *value)
{
    int size = 0;
    void *element;
    guththila_attribute_t *attr;

    if (!p->xsw->start_element_open)
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);
    /* actually here we want exsisting prefix , that's why we check it
       exsists or not. */
    if (guththila_is_exsisting_prefix(env, p, prefix))
    {
        size = axutil_stack_size(p->xsw->attribute, env);
        if (size)
        {
            int ii;
            for (ii = 0; ii <= size; ii++)
            {
                element = axutil_stack_get_at(p->xsw->attribute, env,  ii);
                if (element)
                {
                    attr = (guththila_attribute_t *)element;
                    /* We want to make sure that out checking attribute has
                       the prefix otherwise we don't wan't to worry */
                    if (attr->name && attr->prefix)
                    {
                        if (!strcmp((char *)attr->name, local_name) && !strcmp((char *)attr->prefix, prefix))
                            guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_MATCHING_ELEMENTS);
                        else
                        {
                            guththila_do_write_attribute_with_prefix(env, p, prefix, local_name, value);
                            break;
                        }
                    }
                    else
                    {
                        /* since att->prefix is null im going to write it here */
                        guththila_do_write_attribute_with_prefix(env, p, prefix, local_name, value);
                        break;
                    }
                }
            }

        }
        else
        {
            guththila_do_write_attribute_with_prefix(env, p, prefix, local_name, value);
        }
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_EXSISTING_PREFIX);

}


void AXIS2_CALL
guththila_do_write_attribute_with_prefix(axutil_env_t *env, guththila_t *p, const char *prefix,
										 const char *local_name, const char *value)
{
    guththila_do_write_attribute_with_prefix_and_namespace(env, p, prefix, NULL, local_name, value);
}


int AXIS2_CALL
guththila_is_exsisting_prefix(axutil_env_t *env, guththila_t *p, const char *prefix)
{
    int size;
    int ii;
    void *element;
    guththila_namespace_t *ns;
    size = axutil_stack_size(p->xsw->namespace, env);
    if (size)
    {
        for (ii = 0; ii <= size; ii++)
        {
            element = axutil_stack_get_at(p->xsw->namespace, env, ii);
            if (element)
            {
                ns = (guththila_namespace_t *)element;
                if (ns->name)
                {
                    if (!strcmp(ns->name, prefix))
                        return 1;
                }
            }
        }
        return 0;
    }
    else
        return 0;
}


int
guththila_is_exsisting_namespace_uri(axutil_env_t *env, guththila_t *p, const char *uri)
{
    int size;
    int ii;
    void *element;
    guththila_namespace_t *ns;
    size = axutil_stack_size(p->xsw->namespace, env);
    if (size)
    {
        for (ii = 0; ii <= size; ii++)
        {
            element = axutil_stack_get_at(p->xsw->namespace, env , size - ii);
            if (element)
            {
                ns = (guththila_namespace_t *)element;
                if (ns->uri)
                {
                    if (!strcmp(ns->uri, uri))
                        return 1;
                }
            }
        }
        return 0;
    }
    else
        return 0;
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_attribute_with_namespace(axutil_env_t *env, guththila_t *p, const char *namespace,
										 const char *local_name, const char *value)
{
    int size = 0;
    void *element;
    guththila_attribute_t *attr;
    if (!p->xsw->start_element_open)
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);
    /* actually here we want exsisting namespace , that's why we check it
       exsists or not. */
    if (guththila_is_exsisting_namespace_uri(env, p, namespace))
    {
        char *prefix;
        prefix = guththila_get_prefix_for_namespace(env, p, namespace);
        size = axutil_stack_size(p->xsw->attribute, env);
        if (size)
        {
            int ii;
            for (ii = 0; ii <= size; ii++)
            {
                element = axutil_stack_get_at(p->xsw->attribute, env, size - ii);
                if (element)
                {
                    attr = (guththila_attribute_t *)element;
                    /* We want to make sure that out checking attribute has
                       the namespace otherwise we don't wan't to worry */
                    if (attr->name && attr->prefix)
                    {
                        if (!strcmp((char *)attr->name, local_name) && !strcmp((char *)attr->prefix, prefix))
                            guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_MATCHING_ELEMENTS);
                        else
                        {
                            guththila_do_write_attribute_with_prefix(env, p, prefix, local_name, value);
                            break;
                        }
                    }
                    else
                    {
                        /* since att->prefix is null im going to write it here */
                        guththila_do_write_attribute_with_prefix(env, p, prefix, local_name, value);
                        break;
                    }
                }
            }

        }
        else
        {
            guththila_do_write_attribute_with_prefix(env, p, prefix, local_name, value);
        }
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_EXSISTING_URI);
}



AXIS2_EXTERN char* AXIS2_CALL
guththila_get_prefix_for_namespace(axutil_env_t *env, guththila_t *p, const char *namespace)
{
    int size;
    int ii;
    void *element;
    guththila_namespace_t *ns;
    size = axutil_stack_size(p->xsw->namespace, env);
    if (size)
    {
        for (ii = 0; ii <= size; ii++)
        {
            element = axutil_stack_get_at(p->xsw->namespace, env, size - ii);
            if (element)
            {
                ns = (guththila_namespace_t *)element;
                if (ns->uri)
                {
                    if (!strcmp(ns->uri, namespace))
                        return (char *)ns->name;
                }
            }
        }
        return 0;
    }
    else
        return 0;
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_start_element_with_prefix_and_namespace(axutil_env_t *env, guththila_t *p, const char *prefix,
														const char *namespace_uri, const char *local_name)
{
    int size;
    void *element;
    char *start_element = NULL;
	unsigned int length = 0;
	unsigned int prefix_length = 0;
	unsigned int name_length = 0;

    if (prefix && local_name)
	{
		prefix_length = strlen(prefix);
		name_length = strlen (local_name);
		length = prefix_length + name_length + 2;
        start_element = (char *) AXIS2_MALLOC (env->allocator, length);
		memset (start_element, 0, length);
	}
    if (!p || !local_name)
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);
    else
    {
        
        guththila_close_start_element(env, p);
        guththila_open_depth_element(env, p);

        if (prefix)
        { 
			memcpy (start_element, prefix, prefix_length);
            memcpy (start_element + prefix_length, ":", 1);
            memcpy (start_element + (prefix_length + 1), local_name, name_length);
        }
        else
            start_element = (char *)local_name;

        size = axutil_stack_size(p->xsw->element, env);
        if (size)
        {
            element = axutil_stack_get_at(p->xsw->element, env, size);
            if (start_element && element)
            {
                if (!strcmp((char *)element, start_element))
                    guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_MATCHING_ELEMENTS);
            }
        }
		axutil_stack_push(p->other, env, start_element);
        guththila_check_name_validity(env, p, start_element);
        p->xsw->start_element_open = 1;

        if (!p->xsw->empty_element_open)
            axutil_stack_push(p->xsw->element, env, start_element);
        guththila_write_to_buffer(env, p, "<");
        guththila_write_to_buffer(env, p, start_element);
        guththila_write_namespace(env, p, (char *)prefix, (char *)namespace_uri);
    }
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_start_element_with_namespace(axutil_env_t *env, guththila_t *p, const char *namespace_uri, const char *local_name)
{
    int size;
    void *element;
    char *start_element;
    if (guththila_is_exsisting_namespace_uri(env, p, namespace_uri))
    {
        if (!p || !local_name)
            guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);
        else
        {
            char *prefix = NULL;
            
            guththila_close_start_element(env, p);
            prefix = guththila_get_prefix_for_namespace(env, p, namespace_uri);

            if (prefix)
                start_element = (char *) calloc((strlen(prefix) + strlen(local_name) + 2), 1);
            else
                start_element = (char *) calloc((strlen(local_name) + 2), 1);

            if (prefix)
            {
                strcat(start_element, prefix);
                strcat(start_element, ":");
                strcat(start_element, local_name);
            }
            else
                strcat(start_element, local_name);

            size = axutil_stack_size(p->xsw->element, env);

            if (size)
            {
                element = axutil_stack_get_at(p->xsw->element, env, size);
                if (!strcmp((char *)element, start_element))
                    guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_MATCHING_ELEMENTS);
            }

            guththila_check_name_validity(env, p, start_element);
            p->xsw->start_element_open = 1;

            if (!p->xsw->empty_element_open)
                axutil_stack_push(p->xsw->element, env, start_element);
            guththila_write_to_buffer(env, p, "<");
            guththila_write_to_buffer(env, p, start_element);
        }
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_EXSISTING_URI);
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_start_element_with_prefix (axutil_env_t *env, guththila_t *p, const char *prefix, const char *local_name)
{
    int size;
    void *element;
    char *start_element = NULL;
	unsigned int prefix_length = 0;
	unsigned int name_length = 0;
	unsigned int length = 0;

    if (guththila_is_exsisting_prefix(env, p, prefix))
    {

    if (prefix && local_name)
	{
		prefix_length = strlen(prefix);
		name_length = strlen (local_name);
		length = prefix_length + name_length + 2;
        start_element = (char *) AXIS2_MALLOC (env->allocator, length);
		memset (start_element, 0, length);
	}

	if (!p || !local_name)
		guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_EMPTY_ARGUMENTS);
	else
	{
		guththila_close_start_element(env, p);
		guththila_open_depth_element(env, p);
		
		if (prefix)
		{
			memcpy (start_element, prefix, prefix_length);
            memcpy (start_element + prefix_length, ":", 1);
            memcpy (start_element + (prefix_length + 1), local_name, name_length);
		}

            size = axutil_stack_size(p->xsw->element, env);
            if (size)
            {
                element = axutil_stack_get_at(p->xsw->element, env, size - 1);
                if (!strcmp((char *)element, start_element))
                    guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_MATCHING_ELEMENTS);
            }

			axutil_stack_push(p->other, env, start_element);
            guththila_check_name_validity(env, p, start_element);
            p->xsw->start_element_open = 1;

            if (!p->xsw->empty_element_open)
                axutil_stack_push(p->xsw->element, env, start_element);
            guththila_write_to_buffer(env, p, "<");
            guththila_write_to_buffer(env, p, start_element);
        }
    }
    else
        guththila_exception(p_FILE, LINE, GUTHTHILA_WRITER_ERROR_NON_EXSISTING_PREFIX);
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_empty_element_with_prefix_and_namespace(axutil_env_t *env, guththila_t *p, const char *prefix,
														const char *namespace_uri, const char *empty_element)
{
    
    guththila_close_start_element(env, p);
    p->xsw->start_element_open = 0;
    p->xsw->empty_element_open = 1;
    guththila_write_start_element_with_prefix_and_namespace(env, p, prefix, namespace_uri, empty_element);
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_empty_element_with_namespace(axutil_env_t *env, guththila_t *p, const char *namespace_uri, const char *empty_element)
{
    
    guththila_close_start_element(env, p);
    p->xsw->start_element_open = 0;
    p->xsw->empty_element_open = 1;
    guththila_write_start_element_with_namespace(env, p, namespace_uri, empty_element);
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_empty_element_with_prefix(axutil_env_t *env, guththila_t *p, const char *prefix, const char *empty_element)
{
    
    guththila_close_start_element(env, p);
    p->xsw->start_element_open = 0;
    p->xsw->empty_element_open = 1;
    guththila_write_start_element_with_prefix(env, p, prefix, empty_element);
}


void AXIS2_CALL
guththila_open_depth_element(axutil_env_t *env, guththila_t *p)
{
    int size = axutil_stack_size(p->xsw->depth, env);
    guththila_depth_t *d = (guththila_depth_t *) AXIS2_MALLOC(env->allocator, sizeof(guththila_depth_t));

    if (size)
    {
        void *e = NULL;
        guththila_depth_t *l = NULL;
        e = axutil_stack_get(p->xsw->depth, env);
        l = (guththila_depth_t *)e;
        d->total = axutil_stack_size(p->xsw->namespace, env);
        d->first = l->first + l->count;
        d->count = d->total - l->total;
        axutil_stack_push(p->xsw->depth, env, (void *)d);
    }
    else
    {
        d->first = 0;
        d->total = axutil_stack_size(p->xsw->namespace, env);
        d->count = d->total;
        axutil_stack_push(p->xsw->depth, env, (void *)d);
    }
}


void AXIS2_CALL
guththila_close_depth_element(axutil_env_t *env, guththila_t *p)
{
    void *e = axutil_stack_pop(p->xsw->depth, env);
    guththila_depth_t *d = (guththila_depth_t *)e;
    void *elem = NULL;
    if (d->count)
    {
        for (; d->count > 0; d->count --)
        {
            elem = axutil_stack_pop(p->xsw->namespace, env);
            if (elem)
                AXIS2_FREE(env->allocator, elem);
        }
    }
	AXIS2_FREE (env->allocator, e);
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_end_document(axutil_env_t *env, guththila_t *p)
{
    int ii = 0;
    if (p->xsw->start_element_open || p->xsw->empty_element_open)
        guththila_close_start_element(env, p);
    ii = axutil_stack_size(p->xsw->element, env);
    for (; ii > 0; ii --)
        guththila_write_end_element(env, p);
/*     guththila_flush(env, p); */
}


AXIS2_EXTERN void AXIS2_CALL
guththila_close(axutil_env_t *env,
				guththila_t *p)
{
/*     guththila_flush(env, p); */
    fclose(((guththila_writer_impl_t *)p->xsw->writer)->outputstream);
}


AXIS2_EXTERN void AXIS2_CALL
guththila_write_line(axutil_env_t *env, guththila_t *p, char *local_name, char *characters)
{
    guththila_write_start_element(env, p, local_name);
    guththila_write_characters(env, p, characters);
    guththila_write_end_element(env, p);
    guththila_write_characters(env, p, "\n");
}

AXIS2_EXTERN char* AXIS2_CALL
guththila_get_memory_buffer(axutil_env_t *env, guththila_t *p)
{
    char *buffer = NULL;
    if (p->xsw)
        buffer = guththila_writer_get_buffer(env, p->xsw->writer);
    return buffer;
}

AXIS2_EXTERN unsigned int AXIS2_CALL
guththila_get_memory_buffer_size(axutil_env_t *env, guththila_t *p)
{
	return guththila_writer_get_buffer_size (env, p->xsw->writer);
}
