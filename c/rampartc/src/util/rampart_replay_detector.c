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
#include <rampart_replay_detector.h>
#include <axutil_property.h>
#include <rampart_constants.h>
#include <rampart_sec_processed_result.h>
#include <rampart_util.h>
/*Private functions*/
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
         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[rampart][rrd] Cannot get the property %s from msg_ctx. Creating a new", RAMPART_RD_DB_PROP);
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

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
rampart_replay_detector_is_replayed(const axutil_env_t *env,
    const axis2_char_t *msg_id,
    const axis2_char_t *ts,
    const axis2_char_t *id,
    const axis2_char_t *val)
{
    /*If both has the same msg-id and the timestamp its a replay*/
    if((0== axutil_strcmp(msg_id, id)) && (0== axutil_strcmp(ts, val))){
        return AXIS2_SUCCESS;
    }else{
        return AXIS2_FALSE;
    }        
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
rampart_replay_detector_is_overdue(const axutil_env_t *env,
    const axis2_char_t *val,
    const axis2_char_t *ref)
{
    axutil_date_time_comp_result_t res = AXIS2_DATE_TIME_COMP_RES_UNKNOWN;
    axutil_date_time_t *dt1 = NULL;
    axutil_date_time_t *dt2 = NULL;

    dt1 = axutil_date_time_create(env);
    dt2 = axutil_date_time_create(env);

    axutil_date_time_deserialize_time(dt1, env, val);
    axutil_date_time_deserialize_time(dt2, env, ref);
    /*If dt1(val) < dt2(ref) then its expired*/
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

    return hash_db;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_replay_detector_default(const axutil_env_t *env,
                                axis2_msg_ctx_t* msg_ctx)
{
    axutil_hash_t *hash = NULL;
    axutil_hash_index_t *hi = NULL;
    const axis2_char_t *msg_id = NULL;
    const axis2_char_t *ts = NULL;
   
    msg_id = axis2_msg_ctx_get_wsa_message_id(msg_ctx, env); 
    if(!msg_id){
        msg_id = "MSG-ID";/*This has to be changed*/
    }
    ts = rampart_replay_detector_get_ts( env, msg_ctx); 
    /*Get the DB*/    
    hash = rampart_replay_detector_get_default_db(env, msg_ctx);
    if(!hash){
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[rampart][rrd] Cannot get the default database for replay detection from msg_ctx");
        return AXIS2_FAILURE;
    }else{
        void *id = NULL; /*Temp record id*/
        void *val = NULL; /*Temp time stamp*/
     
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] Number of records =%d", axutil_hash_count(hash));

        /*If matches ERROR*/
        for (hi = axutil_hash_first(hash, env); hi; hi = axutil_hash_next(env, hi)) {
            axutil_hash_this(hi, (const void**)&id, NULL, &val);
            printf("[rampart][rrd] (id, val) %s = %s\n", (axis2_char_t*)id, (axis2_char_t*)val);
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] (id, val) %s = %s\n", (axis2_char_t*)id, (axis2_char_t*)val);
            /*If replayed, return a FAILRE*/
            if(AXIS2_TRUE == rampart_replay_detector_is_replayed(env, msg_id, ts, id, val)){
                return AXIS2_FAILURE;
            }
            /*Clean up old records*/
            if(AXIS2_TRUE == rampart_replay_detector_is_overdue(env , ts, val)){
                /*Remove the record*/
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[rampart][rrd] removing record (id, val) = (%s , %s)\n", (axis2_char_t*)id, (axis2_char_t*)val);
                AXIS2_FREE(env->allocator, id);
                id = NULL;
                AXIS2_FREE(env->allocator, val);
                ts = NULL;
            }
        }/*eof for loop*/   
        /*If not replayed then we will insert the new record to the DB*/
        axutil_hash_set(hash, msg_id, AXIS2_HASH_KEY_STRING, ts);

        return AXIS2_SUCCESS;
      }
}




