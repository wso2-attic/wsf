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

#ifndef AXIS2_PHASE_META_H
#define AXIS2_PHASE_META_H

/**
 * @defgroup axis2_phase_meta phase meta data
 * @ingroup axis2_engine
 * @{
 */

/**
 * @file axis2_conf.h
 * @brief Axis2 configuration interface
 */

#include <axis2_defines.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** Axis2 in flow */
/*#define  AXIS2_IN_FLOW  1*/
/** Axis2 out flow */
/*#define  AXIS2_OUT_FLOW 2*/
/** Axis2 fault in flow */
/*#define  AXIS2_FAULT_IN_FLOW 3*/
/** Axis2 fault out flow */
/*#define  AXIS2_FAULT_OUT_FLOW 4*/

/** phase transport in */
#define AXIS2_PHASE_TRANSPORT_IN "Transport"
/** phase pre dispatch */
#define AXIS2_PHASE_PRE_DISPATCH "PreDispatch"
/** phase dispatch */
#define AXIS2_PHASE_DISPATCH "Dispatch"
/** phase post dispatch */
#define AXIS2_PHASE_POST_DISPATCH "PostDispatch"
/** phase policy determination */
#define AXIS2_PHASE_POLICY_DETERMINATION "PolicyDetermination"
/** phase message processing */
#define AXIS2_PHASE_MESSAGE_PROCESSING "MessageProcessing"

/** phase message out */
#define AXIS2_PHASE_MESSAGE_OUT "MessageOut"

/**
 * All the handlers inside transport_sender and tranport_recievre in axis2.xml gose
 * to this phase
*/
#define AXIS2_TRANSPORT_PHASE "TRANSPORT"


/** @} */

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_PHASE_META_H */
