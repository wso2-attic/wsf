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

#include <tcpmon_util.h>
#include <axutil_string.h>
#include <axiom.h>
#include <axis2_util.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_ELEMENT 1
#define CHAR_VALUE 2
#define END_ELEMENT 3
#define EMPTY_ELEMENT 4

typedef struct tcpmon_util_allocator
{
  int allocated;
  int index;
  axis2_char_t* buffer;
}
tcpmon_util_allocator_t;

axis2_char_t* tcpmon_strcat(char *dest, char *source, int *cur_buf_s, const axutil_env_t *env);

/*static void add_string(const axutil_env_t* env,
		       tcpmon_util_allocator_t* allocator,
		       axis2_char_t* string);
*/

/*static void add_axis2_char_t(const axutil_env_t* env,
			     tcpmon_util_allocator_t* allocator,
			     axis2_char_t c,
			     int turns);
*/

axis2_char_t* 
tcpmon_util_format_as_xml(const axutil_env_t* env, axis2_char_t* data, int format)
{
    if(format)
    {
        int c;
        int tab_pos = 0;
        int has_value = 0;
        int has_space = 0;
        int start_ele = 0;
        int prev_case = 0;
        int buffer_size = 0;
	
        axis2_char_t *out;
	
        axiom_xml_reader_t *xml_reader = NULL;

        buffer_size = 2*strlen(data);
        out = AXIS2_MALLOC(env->allocator, buffer_size*sizeof(axis2_char_t));
    
        if (data)
        {  
            int size = 0;
            size = strlen (data);
            xml_reader =
    	    axiom_xml_reader_create_for_memory (env, data, size, "utf-8", AXIS2_XML_PARSER_TYPE_BUFFER);
            if (!xml_reader)
    	        return AXIS2_FAILURE;
        }

        axiom_xml_reader_init ();

        while ((c = axiom_xml_reader_next (xml_reader, env)) != -1)
        {
            switch (c)
	        {
	            case AXIOM_XML_READER_START_DOCUMENT:
    	        {
	                int ix;
	            
    	            tcpmon_strcat(out, "<?xml ", &buffer_size, env);
                
                
	                ix = axiom_xml_reader_get_attribute_count (xml_reader, env);
	                for (; ix > 0; ix--)
	                {
		                axis2_char_t *attr_prefix;
		                axis2_char_t *attr_name;
    		            axis2_char_t *attr_value;

	    	            attr_prefix = (axis2_char_t *)axiom_xml_reader_get_attribute_prefix_by_number (xml_reader, env, ix);
		                if (attr_prefix)
		                {
		                    tcpmon_strcat(out, attr_prefix, &buffer_size, env);
		                    tcpmon_strcat(out, ":", &buffer_size, env);
		                }
				        
    		            attr_name = (axis2_char_t *)axiom_xml_reader_get_attribute_name_by_number (xml_reader, env, ix);
	    	            if (attr_name)
		                {
		                    tcpmon_strcat(out, attr_name, &buffer_size, env);
		                    tcpmon_strcat(out, "=\"", &buffer_size, env);
		                }
		    			            
		                attr_value = (axis2_char_t *)axiom_xml_reader_get_attribute_value_by_number (xml_reader, env, ix);
		                if (attr_value)
    		            {
	    	                tcpmon_strcat(out, attr_value, &buffer_size, env);
		                    tcpmon_strcat(out, "\"", &buffer_size, env);
		                }
	                }

    	            printf ("?>");
	            }
	            break;
	            case AXIOM_XML_READER_START_ELEMENT:
	            {
	                int i, ix, has_prefix = 0;
	            
                    axis2_char_t *ele_name;
	                axis2_char_t *ele_prefix;

	                prev_case = START_ELEMENT;
	            
    	            has_value = 0;
	                has_space = 0;
								
	                if (start_ele != 0)
	                tcpmon_strcat(out, "\n", &buffer_size, env);
                    
    	            for (i = 0; i < tab_pos; i++)
	                    tcpmon_strcat(out, "\t", &buffer_size, env);
	            
	                tcpmon_strcat(out, "<", &buffer_size, env);
	            
	                ele_prefix =(axis2_char_t *)axiom_xml_reader_get_prefix (xml_reader, env);
	                if (ele_prefix)
    	            {
	    	            tcpmon_strcat(out, ele_prefix, &buffer_size, env);
		                tcpmon_strcat(out, ":", &buffer_size, env);                    
    	            }
	        
	                ele_name = (axis2_char_t *) axiom_xml_reader_get_name (xml_reader, env);
	                if (ele_name)
	                {
		                tcpmon_strcat(out, ele_name, &buffer_size, env);					                    
    	            }
                            
	                ix = axiom_xml_reader_get_attribute_count (xml_reader, env);
	                for (; ix > 0; ix--)
	                {
		                axis2_char_t *attr_prefix;
    		            axis2_char_t *attr_name;
    		            axis2_char_t *attr_value;
	                		
               		    attr_prefix = (axis2_char_t *)axiom_xml_reader_get_attribute_prefix_by_number (xml_reader, env, ix);
    		            if (attr_prefix)
	    	            {
		                    has_prefix = 1;
		                    tcpmon_strcat(out, " ", &buffer_size, env);
		                    tcpmon_strcat(out, attr_prefix, &buffer_size, env);
		                    tcpmon_strcat(out, ":", &buffer_size, env);
		                }
		  
    		            attr_name = (axis2_char_t *)axiom_xml_reader_get_attribute_name_by_number (xml_reader, env, ix);
    		            if (attr_name)
    		            {
    		                if(has_prefix)
    		                {
    			                tcpmon_strcat(out, attr_name, &buffer_size, env);
    			                tcpmon_strcat(out, "=\"", &buffer_size, env);
	    	                }
		                    else
    		                {
	    		                tcpmon_strcat(out, " ", &buffer_size, env);
		    	                tcpmon_strcat(out, attr_name, &buffer_size, env);
			                    tcpmon_strcat(out, "=\"", &buffer_size, env);
		                    }
		                
                            has_prefix = 0;
		                }

    		            attr_value = (axis2_char_t *)axiom_xml_reader_get_attribute_value_by_number (xml_reader, env, ix);
	    	            if (attr_value)
		                {
		                    tcpmon_strcat(out, attr_value, &buffer_size, env);
		                    tcpmon_strcat(out, "\"", &buffer_size, env);
		                }
    	            }
	            
	                tcpmon_strcat(out, ">", &buffer_size, env);
	            
                    tab_pos++;
	                start_ele = 1;
    	        }
	            break;
	            case AXIOM_XML_READER_CHARACTER:
	            {
    	            axis2_char_t *ele_value;
                
	                prev_case = CHAR_VALUE;

	                ele_value = axiom_xml_reader_get_value (xml_reader, env);
	                if (ele_value)
    	                tcpmon_strcat(out, ele_value, &buffer_size, env);
	            
	                has_value = 1;
                
	            }
	            break;
	            case AXIOM_XML_READER_EMPTY_ELEMENT:
	            {
	                int i, ix, has_prefix = 0;
	            
                    axis2_char_t *ele_name;
	                axis2_char_t *ele_prefix;

	                prev_case = EMPTY_ELEMENT;

	                has_value = 0;
	                has_space = 0;
                
	                if (start_ele != 0)
	                    tcpmon_strcat(out, "\n", &buffer_size, env);
	            
    	            for (i = 0; i < tab_pos; i++)
	                    tcpmon_strcat(out, "\t", &buffer_size, env);

	                tcpmon_strcat(out, "<", &buffer_size, env);
	            
	                ele_prefix = (axis2_char_t *) axiom_xml_reader_get_prefix (xml_reader, env);
    	            if (ele_prefix)
	                {
		                tcpmon_strcat(out, ele_prefix, &buffer_size, env);
		                tcpmon_strcat(out, ":", &buffer_size, env);                    
	                }
	     
    	            ele_name = (axis2_char_t *) axiom_xml_reader_get_name (xml_reader, env);
	                if (ele_name)
	                    tcpmon_strcat(out, ele_name, &buffer_size, env);
	      
	                ix = axiom_xml_reader_get_attribute_count (xml_reader, env);
    	            for (; ix > 0; ix--)
	                {
    		            axis2_char_t *attr_prefix;
	    	            axis2_char_t *attr_name;
		                axis2_char_t *attr_value;

		                attr_prefix = (axis2_char_t *)axiom_xml_reader_get_attribute_prefix_by_number (xml_reader, env, ix);
		                if (attr_prefix)
		                {
    		                has_prefix = 1;
	    	                tcpmon_strcat(out, " ", &buffer_size, env);
		                    tcpmon_strcat(out, attr_prefix, &buffer_size, env);
		                    tcpmon_strcat(out, ":", &buffer_size, env);
		                }

		                attr_name = (axis2_char_t *)axiom_xml_reader_get_attribute_name_by_number (xml_reader, env, ix);
    		            if (attr_name)
	    	            {
		                    if(has_prefix)
		                    {
			                    tcpmon_strcat(out, attr_name, &buffer_size, env);
			                    tcpmon_strcat(out, "=\"", &buffer_size, env);
		                    }
    		                else
	    	                {
		    	                tcpmon_strcat(out, " ", &buffer_size, env);
			                    tcpmon_strcat(out, attr_name, &buffer_size, env);
			                    tcpmon_strcat(out, "=\"", &buffer_size, env);
		                    }
		                    has_prefix = 0;
    		            }
		            
	    	            attr_value = (axis2_char_t *)axiom_xml_reader_get_attribute_value_by_number (xml_reader, env, ix);
		                if (attr_value)
		                {
		                    tcpmon_strcat(out, attr_value, &buffer_size, env);
		                    tcpmon_strcat(out, "\"", &buffer_size, env);
    		            }
	                }
    
                    tcpmon_strcat(out, "/>", &buffer_size, env);
    	            start_ele = 1;
                }
	            break;
    	        case AXIOM_XML_READER_END_ELEMENT:
	            {
	                int i;
	    
                    axis2_char_t *ele_prefix;
    	            axis2_char_t *ele_name;
				
	                tab_pos--;
				
	                if (has_value == 0 && prev_case != START_ELEMENT)
	                {
		                tcpmon_strcat(out, "\n", &buffer_size, env);
    		            for (i = 0; i < tab_pos; i++)
	        	            tcpmon_strcat(out, "\t", &buffer_size, env);
	                }

	                has_value = 0;
	            				
    	            tcpmon_strcat(out, "</", &buffer_size, env);

	                ele_prefix = (axis2_char_t *) axiom_xml_reader_get_prefix (xml_reader, env);
	                if (ele_prefix)
	                {
		                tcpmon_strcat(out, ele_prefix, &buffer_size, env);
		                tcpmon_strcat(out, ":", &buffer_size, env);                    
	                }
	      
    	            ele_name = (axis2_char_t *) axiom_xml_reader_get_name (xml_reader, env);
	                if (ele_name)
	                {
		                tcpmon_strcat(out, ele_name, &buffer_size, env);
		                tcpmon_strcat(out, ">", &buffer_size, env);
    	            }
	                prev_case = END_ELEMENT;
	            
	            }
	            break;
    	    }   
        }
        return out;
    }
    return data;
}

/*void add_string(const axutil_env_t* env,
		tcpmon_util_allocator_t* allocator,
		axis2_char_t* string)
{
  int additional_len = 0;
  void* dest = NULL;
  void* src = NULL;
  int count = 0;

  additional_len = axutil_strlen(string) + 1;
  if (allocator-> index + additional_len  >= allocator-> allocated)
    {
      if (allocator-> allocated == 0)
        {
	  allocator-> buffer =
	    AXIS2_MALLOC(env-> allocator, additional_len);
        }
      else
        {
	  allocator-> buffer =
	    AXIS2_REALLOC(env-> allocator, allocator-> buffer,
			  allocator-> allocated + additional_len);
        }
      allocator-> allocated += additional_len;
    }

  dest = allocator-> buffer + allocator-> index;
  src = string;
  count = additional_len; 
  memcpy(dest, src, count);

  allocator-> index += count - 1;
}
*/
/*void add_axis2_char_t(const axutil_env_t* env,
		      tcpmon_util_allocator_t* allocator,
		      axis2_char_t c,
		      int turns)
{
  int additional_len = 0;

  additional_len = turns + 1;
  if (allocator-> index + additional_len  >= allocator-> allocated)
    {
      if (allocator-> allocated == 0)
        {
	  allocator-> buffer =
	    AXIS2_MALLOC(env-> allocator, additional_len);
        }
      else
        {
	  allocator-> buffer =
	    AXIS2_REALLOC(env-> allocator, allocator-> buffer,
			  allocator-> allocated + additional_len);
        }
      allocator-> allocated += additional_len;
    }

  memset(allocator-> buffer + allocator-> index, c, turns);

  allocator-> index += turns;

} */

axis2_char_t* tcpmon_strcat(axis2_char_t *dest, axis2_char_t *source, int *buff_size, const axutil_env_t* env)
{
    int cur_len = 0;
    int source_len = 0;
  
    axis2_char_t *tmp;
    cur_len = strlen(dest);
    source_len = strlen(source);

    if ((*buff_size-cur_len) < source_len)
    {
        *buff_size = *buff_size + (*buff_size*2);
        tmp = (axis2_char_t*)AXIS2_REALLOC(env->allocator, dest, *buff_size*sizeof(axis2_char_t));
        dest = tmp;
        strcat((char*)dest, (char*)source);
    }
    else
    {
        strcat((char*)dest, (char*)source);
    }

    return dest;
}

