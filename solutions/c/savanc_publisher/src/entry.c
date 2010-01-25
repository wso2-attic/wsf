#include <stdio.h>
#include <raptor.h>
#include <stdlib.h>
#include <axutil_string.h>
#include <axutil_env.h>
#include <reg_client_entry.h>

AXIS2_EXTERN reg_client_entry_t* AXIS2_CALL
reg_client_entry_create(
    const axutil_env_t *env)
{
    reg_client_entry_t *entry = NULL;

    entry =  (reg_client_entry_t *)AXIS2_MALLOC(env->allocator, 
            sizeof(reg_client_entry_t));
	
    if(!entry)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}

    entry->title = NULL;
    entry->link_list = axutil_array_list_create(env, 0);
    
	return entry;

}
                        
void AXIS2_CALL 
reg_client_entry_free(
    reg_client_entry_t *entry, 
    const axutil_env_t *env)
{
    if(entry->title)
    {
        AXIS2_FREE(env->allocator, entry->title);
        entry->title = NULL;
    }
    
    if(entry->link_list)
    {
        axutil_array_list_free(entry->link_list, env);
        entry->link_list = NULL;
    }

    if(entry)
    {
        AXIS2_FREE(env->allocator,entry);
    }
}

