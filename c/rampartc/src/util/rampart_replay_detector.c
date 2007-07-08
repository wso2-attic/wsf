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
#include <axutil_utils.h>
#include <axutil_linked_list.h>
#include <rampart_replay_detector.h>
#include <axutil_property.h>
#include <rampart_constants.h>
#include <rampart_sec_processed_result.h>
#include <rampart_util.h>
/*Private functions*/
AXIS2_EXTERN axis2_bool_t AXIS2_CALL
rampart_replay_detector_linked_list_contains(axutil_linked_list_t *linked_list,
        const axutil_env_t *env,
        axis2_char_t *id)
{
#if 0
    entry_t *e = NULL;

    e = axutil_linked_list_get_first(linked_list, env);
    while (e)
    {
        if (0 == axutil_strcmp(id, (axis2_char_t*)e)){
            return AXIS2_TRUE;
        }
        if(e->next){
            e = e->next;
        }else{
            e = NULL;
        }
    }
    return AXIS2_FALSE;
#else
    int count = 0;
    int i = 0;

    count = axutil_linked_list_size(linked_list, env);
    for(i=0; i<count; i++){
        axis2_char_t *tmp_id = NULL;

        tmp_id = (axis2_char_t*)axutil_linked_list_get(linked_list, env, i);
        if(0 == axutil_strcmp(id, tmp_id)){
            return AXIS2_TRUE;
        }
    }
    return AXIS2_FALSE;

#endif
}


AXIS2_EXTERN axutil_linked_list_t *AXIS2_CALL
rampart_replay_detector_get_ll_db(const axutil_env_t *env,
                                  axis2_msg_ctx_t* msg_ctx)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_ctx_t *ctx = NULL;
    axutil_property_t *property = NULL;
    axutil_linked_list_t *ll = NULL;
    /*Get the conf ctx*/
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    if(!conf_ctx)
    {
        AXIS2_LOG_ERROR(env->log,AXIS2_LOG_SI, "[rampart][rrd] Conf context is NULL ");
        return NULL;
    }
    ctx = axis2_conf_ctx_get_base(conf_ctx,env);
    if(!ctx)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"[rampart][rrd] axis2 context is NULL ");
        return NULL;
    }
    /*Get the DB property*/
    property = axis2_ctx_get_property(ctx, env, RAMPART_RD_DB_PROP);
    if(property)
    {
        /*Get the DB*/
        ll = (axutil_linked_list_t*)axutil_property_get_value(property, env);
        return ll;
    }else{
        ll = rampart_replay_detector_set_ll_db(env, ctx);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[rampart][rrd] Cannot get the property %s from msg_ctx. Creating a new DB", RAMPART_RD_DB_PROP);
        return ll;
    }
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
rampart_replay_detector_get_default_db(const axutil_env_t *env,
                                       axis2_msg_ctx_t* msg_ctx)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_ctx_t *ctx = NULL;
    axutil_property_t *property = NULL;
    axutil_hash_t *hash = NULL;
    /*Get the conf ctx*/
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    if(!conf_ctx)
    {
        AXIS2_LOG_ERROR(env->log,AXIS2_LOG_SI, "[rampart][rrd] Conf context is NULL ");
        return NULL;
    }
    ctx = axis2_conf_ctx_get_base(conf_ctx,env);
    if(!ctx)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"[rampart][rrd] axis2 context is NULL ");
        return NULL;
    }
    /*Get the DB property*/
    property = axis2_ctx_get_property(ctx, env, RAMPART_RD_DB_PROP);
    if(property)
    {
        /*Get the DB*/
        hash = (axutil_hash_t*)axutil_property_get_value(property, env);
        return hash;
    }else{
        hash = rampart_replay_detector_set_default_db(env, ctx);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[rampart][rrd] Cannot get the property %s from msg_ctx. Creating a new DB", RAMPART_RD_DB_PROP);
        return hash;
    }
}

AXIS2_EXTERN axis2_char_t * AXIS2_CALL
rampart_replay_detector_get_ts(const axutil_env_t *env,
                               axis2_msg_ctx_t* msg_ctx)
{
    axis2_char_t  *ts = NULL;
    axutil_hash_t *hash = NULL;

    /*Get timestamp from security processed results*/
    hash = rampart_get_all_security_processed_results(env, msg_ctx);

    ts = axutil_hash_get(hash, RAMPART_SPR_TS_CREATED, AXIS2_HASH_KEY_STRING);
    return ts;
}
/*
AXIS2_EXTERN axis2_bool_t AXIS2_CALL
rampart_replay_detector_is_replayed(const axutil_env_t *env,
    const axis2_char_t *msg_id,
    const axis2_char_t *ts,
    const axis2_char_t *id,
    const axis2_char_t *val)
{
    if((0== axutil_strcmp(msg_id, id)) && (0== axutil_strcmp(ts, val))){
        return AXIS2_SUCCESS;
    }else{
        return AXIS2_FALSE;
    }        
}
*/

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
rampart_replay_detector_is_overdue(const axutil_env_t *env,
                                   int valid_duration,
                                   const axis2_char_t *val)
{
    axutil_date_time_comp_result_t res = AXIS2_DATE_TIME_COMP_RES_UNKNOWN;
    axutil_date_time_t *dt1 = NULL;
    axutil_date_time_t *dt2 = NULL;

    dt1 = axutil_date_time_create_with_offset(env, valid_duration);
    dt2 = axutil_date_time_create(env);

    axutil_date_time_deserialize_date_time(dt2, env, val);
    /*If the dt1(LIMIT) < dt2(TS) this returns expired*/
    /*printf("Comparing time(TIME, TS) %s >  %s\n", axutil_date_time_serialize_date_time(dt1, env), axutil_date_time_serialize_date_time(dt2, env));*/
    res = axutil_date_time_compare(dt2, env, dt1);
    if(AXIS2_DATE_TIME_COMP_RES_EXPIRED == res){
        return AXIS2_TRUE;
    }else{
        return AXIS2_FALSE;
    }
}

/*Public functions*/
AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
rampart_replay_detector_set_default_db(const axutil_env_t *env,
                                       axis2_ctx_t *ctx)
{
    axutil_hash_t *hash_db = NULL;
    axutil_property_t *hash_db_prop = NULL;

    if(!ctx){
        return NULL;
    }

    hash_db = axutil_hash_make(env);
    hash_db_prop = axutil_property_create(env);

    axutil_property_set_value(hash_db_prop, env, hash_db);
    axis2_ctx_set_property(ctx, env, RAMPART_RD_DB_PROP, hash_db_prop);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Setting dafult RD DB =%s", RAMPART_RD_DB_PROP);

    return hash_db;
}

AXIS2_EXTERN axutil_linked_list_t *AXIS2_CALL
rampart_replay_detector_set_ll_db(const axutil_env_t *env,
                                  axis2_ctx_t *ctx)
{
    axutil_linked_list_t *ll_db = NULL;
    axutil_property_t *ll_db_prop = NULL;

    if(!ctx){
        return NULL;
    }

    ll_db = axutil_linked_list_create(env);
    ll_db_prop = axutil_property_create(env);

    axutil_property_set_value(ll_db_prop, env, ll_db);
    axis2_ctx_set_property(ctx, env, RAMPART_RD_DB_PROP, ll_db_prop);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Setting linked_list RD DB =%s", RAMPART_RD_DB_PROP);

    return ll_db;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_replay_detector_final_cleanup(const axutil_env_t *env,
                                      axis2_msg_ctx_t* msg_ctx)
{
    axutil_linked_list_t *ll = NULL;
    int count = 0;
    int i = 0;

    ll = rampart_replay_detector_get_ll_db(env, msg_ctx);
    count = axutil_linked_list_size(ll, env);
    for(i=0; i<count; i++){
        axis2_char_t *tmp_id = NULL;

        tmp_id = (axis2_char_t*)axutil_linked_list_get(ll, env, i);
        AXIS2_FREE(env->allocator, tmp_id);
    }
    axutil_linked_list_free(ll, env);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_replay_detector_with_linked_list(const axutil_env_t *env,
        axis2_msg_ctx_t* msg_ctx,
        rampart_context_t *rampart_context)
{
    axutil_linked_list_t *ll = NULL;
    const axis2_char_t *msg_id = NULL;
    const axis2_char_t *ts = NULL;
    const axis2_char_t *addr_msg_id = NULL;
    int max_rcds = RAMPART_RD_DEF_MAX_RCDS;
    axis2_status_t status = AXIS2_FAILURE;

    /* By using just Timestamps we dont need addressing. But there is a chance that
     * two messages might generated exactly at the same time*/

    ts = rampart_replay_detector_get_ts( env, msg_ctx);
    addr_msg_id = axis2_msg_ctx_get_wsa_message_id(msg_ctx, env);

    if(!ts && addr_msg_id){
        msg_id = addr_msg_id;
    }else if(ts && !addr_msg_id){
        msg_id = ts;
    }else if(ts && addr_msg_id){
        msg_id = axutil_strcat(env, addr_msg_id, ts, NULL);
    }else{
        msg_id = NULL;
    }
    if(!msg_id){
        msg_id = "RAMPART-DEFAULT-TS";/*This has to be changed to generate the hash???*/
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] NO msg_id specified, using default = %s", msg_id);
    }

    ll = rampart_replay_detector_get_ll_db(env, msg_ctx);
    if(!ll){
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[rampart][rrd] Cannot get the linked-list for replay detection from msg_ctx");
        return AXIS2_FAILURE;
    }else{
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Number of records =%d", axutil_linked_list_size(ll, env));
        /*printf("[rampart][rrd] Number of records =%d", axutil_linked_list_size(ll, env)); */
        /*Get the valid duration for a record*/
        if(rampart_context_get_rd_val(rampart_context, env)){
            max_rcds = axutil_atoi(rampart_context_get_rd_val(rampart_context, env));
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Using the specified max_rcds  %d\n", max_rcds );
            /*printf("[rampart][rrd] Using the specified max_rcds  %d\n", max_rcds);*/
        }else{
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Using the default max_rcds  %d\n", max_rcds );
            /*printf("[rampart][rrd] Using the default max_rcds  %d\n", max_rcds);*/
        }

        /*If the table already have the same key it's a replay*/
        /*if(AXIS2_TRUE == axutil_linked_list_contains(ll, env, (void*)msg_id)){*/
        if(AXIS2_TRUE == rampart_replay_detector_linked_list_contains(ll, env, (void*)msg_id)){
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"[rampart][rrd] For ID=%s, a replay detected", msg_id);
            /*printf("[rampart][rrd] For ID=%s, a replay detected", msg_id);*/
            return AXIS2_FAILURE;
        }

        /*Clean up clean up.... :)*/
        while(axutil_linked_list_size(ll, env) > max_rcds){
            axis2_char_t *tmp_msg_id = NULL;
            tmp_msg_id = (axis2_char_t*)axutil_linked_list_remove_first(ll, env);
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Deleting record  %s\n", tmp_msg_id );
            /*printf("[rampart][rrd] Deleting record  %s\n", tmp_msg_id );*/
            AXIS2_FREE(env->allocator, tmp_msg_id);
            tmp_msg_id = NULL;
        }

        /*Add current record*/
        status = axutil_linked_list_add(ll, env, (void*)axutil_strdup(env,msg_id));
        if(AXIS2_SUCCESS == status){
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Adding record  %s\n", msg_id );
            /*printf("[rampart][rrd] Adding record  %s\n", msg_id );*/
            return AXIS2_SUCCESS;
        }else{
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"[rampart][rrd] Cannot add record %s\n", msg_id);
            /*printf("[rampart][rrd] Cannot add record %s\n", msg_id);*/
            return AXIS2_FAILURE;
        }
    }


}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_replay_detector_default(const axutil_env_t *env,
                                axis2_msg_ctx_t* msg_ctx,
                                rampart_context_t *rampart_context)
{
    axutil_hash_t *hash = NULL;
    axutil_hash_index_t *hi = NULL;
    const axis2_char_t *msg_id = NULL;
    const axis2_char_t *ts = NULL;
    int valid_duration = RAMPART_RD_DEF_VALID_DURATION;

    msg_id = axis2_msg_ctx_get_wsa_message_id(msg_ctx, env);
    if(!msg_id){
        msg_id = "MSG-ID";/*This has to be changed to generate the hash*/
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] NO msg_id specified, using default = %s", msg_id);
    }
    ts = rampart_replay_detector_get_ts( env, msg_ctx);
    /*Get the DB*/
    hash = rampart_replay_detector_get_default_db(env, msg_ctx);
    if(!hash){
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[rampart][rrd] Cannot get the default database for replay detection from msg_ctx");
        return AXIS2_FAILURE;
    }else{

        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Number of records =%d", axutil_hash_count(hash));

        /*Get the valid duration for a record*/
        if(rampart_context_get_rd_val(rampart_context, env)){
            valid_duration = axutil_atoi(rampart_context_get_rd_val(rampart_context, env));
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Using the specified valid duration  %d\n", valid_duration );
        }else{
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Using the default valid duration  %d\n", valid_duration );
        }

        /*If the table already have the same key it's a replay*/
        if(AXIS2_TRUE == axutil_hash_contains_key(hash, env, msg_id)){
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"[rampart][rrd] For ID=%s, a replay detected", msg_id);
            return AXIS2_FAILURE;
        }

        /*Iterate thru records*/
        /*printf("Iterate--------------------=%d\n", axutil_hash_count(hash));*/
        for (hi = axutil_hash_first(hash, env); hi; hi = axutil_hash_next(env, hi)) {
            axis2_char_t *id = NULL; /*Temp record id (of i'th recored)*/
            axis2_char_t *tmp_ts = NULL; /*Temp time stamp (of i'th recored))*/

            axutil_hash_this(hi, (void*)&id, NULL, (void*)&tmp_ts);
            /*tmp_ts = (axis2_char_t*)val;*/
            if(!id){
                /*printf("[rampart][rrd] ID is NULL. Cont loop\n");*/
                continue;
            }
            /*printf("[rampart][rrd] (id = tmp_ts) %s = %s\n", (axis2_char_t*)id, (axis2_char_t*)tmp_ts);*/
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] (id, tmp_ts) %s = %s\n", (axis2_char_t*)id, (axis2_char_t*)tmp_ts);

            /*Clean up old records*/

            if(AXIS2_TRUE == rampart_replay_detector_is_overdue(env , -valid_duration, tmp_ts)){ /*TODO*/
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Removing old record (id, tmp_ts) = (%s , %s)\n",
                                (axis2_char_t*)id, (axis2_char_t*)tmp_ts);
                /*printf("Deleting record... , (id = tmp_ts)  %s = %s\n", id, tmp_ts);*/
                axutil_hash_set(hash, id, AXIS2_HASH_KEY_STRING, NULL);
                if(id){
                    AXIS2_FREE(env->allocator, id);
                    id = NULL;
                }
                if(tmp_ts){
                    AXIS2_FREE(env->allocator, tmp_ts);
                    tmp_ts = NULL;
                }
            }
        }/*eof for loop*/
        /*If not replayed then we will insert the new record to the DB*/
        /*NOTE: We do a strdup here, 'coz we dont need these values to be lost once the msg cycle is over.*/
        /*printf("Adding record... , (id = ts)  %s = %s\n", msg_id, ts);*/
        axutil_hash_set(hash, axutil_strdup(env, msg_id), AXIS2_HASH_KEY_STRING, axutil_strdup(env, ts));
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Adding record key=%s to the DB", msg_id);
        return AXIS2_SUCCESS;
    }
}




