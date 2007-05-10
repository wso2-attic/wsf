/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#ifndef SANDESHA2_ERROR_H
#define SANDESHA2_ERROR_H

#include <axutil_error.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @defgroup sandesha2_error
 * @ingroup Sandesha2 Error
 * @{
 */
   /**
    * Since we use the same env->error from Axis2 we need to start from
    * a AXIS2_ERROR_LAST + some number to prevent ambiguity 
    */  
    #define SANDESHA2_ERROR_CODES_START (AXIS2_ERROR_LAST + 1000)
	/**
    * \brief Sandesha2 error codes
    *
    * Set of error codes for Sandesha2
    */
    typedef enum sandesha2_error_codes sandesha2_error_codes_t;
    enum sandesha2_error_codes
    { 
        /* No error */
        SANDESHA2_ERROR_NONE = SANDESHA2_ERROR_CODES_START,
        /* A namespace that is not supported by Sandesha2 */
        SANDESHA2_ERROR_UNSUPPORTED_NS,
        /* Object cannot generated since the om_element corresponding to
         * that is NULL */
        SANDESHA2_ERROR_NULL_OM_ELEMENT,
        /* The om element has no child elements or attributes */
        SANDESHA2_ERROR_EMPTY_OM_ELEMENT,
        /* om_element cannot be generated since the element corresponding 
         * to that is NULL*/
        SANDESHA2_ERROR_TO_OM_NULL_ELEMENT,
        /* Required OM attribute is NULL */
        SANDESHA2_ERROR_NULL_OM_ATTRIBUTE,
        /* An invalid number found during object to om conversion*/
        SANDESHA2_ERROR_TO_OM_INVALID_NUMBER,
        /* Ack Final now allowed in the spec */
        SANDESHA2_ERROR_ACK_FINAL_NOT_ALLOWED,
        /* 'To' address is not set */
        SANDESHA2_ERROR_TO_ADDRESS_NOT_SET,
        /* Service Context is NULL */
        SANDESHA2_ERROR_SVC_CTX_NULL,
        /* Service is NULL */
        SANDESHA2_ERROR_SVC_NULL,
        /* Result is not unique */
        SANDESHA2_ERROR_NON_UNIQUE_RESULT,
        /* Key is NULL. Cannot insert */
        SANDESHA2_ERROR_KEY_IS_NULL,
        /* Ack None now allowed in the spec */
        SANDESHA2_ERROR_ACK_NONE_NOT_ALLOWED,
        /* unknown storage mgr */
        SANDESHA2_ERROR_UNKNOWN_STORAGE_MGR,
        /* Sandesha configuration is not set in axis2 conf*/
        SANDESHA2_ERROR_CONFIGURATION_NOT_SET,
        /* NULL msg context */
        SANDESHA2_ERROR_NULL_MSG_CTX,
        /* Error occured while sending fault */
        SANDESHA2_ERROR_SENDING_FAULT,
        /* Invalid message number specified */
        SANDESHA2_ERROR_INVALID_MSG_NUM,
        /* Specified seq does not exist */
        SANDESHA2_ERROR_SEQ_NOT_EXIST,
        /* RM Spec version is invalid */
        SANDESHA2_ERROR_INVALID_SPEC_VERSION,
        /* Error occured while sending ack */
        SANDESHA2_ERROR_SENDING_ACK,
        /* NULL to epr is specified */
        SANDESHA2_ERROR_NULL_TO,
        /* Required msg part missing */
        SANDESHA2_ERROR_REQD_MSG_PART_MISSING,
        /* NULL sequnce given for processing */
        SANDESHA2_ERROR_NULL_SEQ,
        /* Storage Map not present */
        SANDESHA2_ERROR_STORAGE_MAP_NOT_PRESENT,
        /* Entry is not present for updating */
        SANDESHA2_ERROR_ENTRY_IS_NOT_PRESENT_FOR_UPDATING,
        /* Invalid namespace uri */
        SANDESHA2_ERROR_INVALID_NS_URI,
        /* An incoming seq report is not present for the given seqID */
        SANDESHA2_ERROR_INCOMING_SEQ_REPORT_NOT_PRESENT_FOR_GIVEN_SEQ_ID,
        /* To EPR is not set */
        SANDESHA2_ERROR_TO_EPR_NOT_SET,
        /* Options object is not set */
        SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET,
        /* Unknown specification error message */
        SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE,
        /* Could not send the terminate message */
        SANDESHA2_ERROR_COULD_NOT_SEND_TERMINATE_MESSAGE, 
        /* This rm spec version does not define a sequence close action */
        SANDESHA2_ERROR_RM_SPEC_VERSION_DOES_NOT_DEFINE_A_SEQ_CLOSE_ACTION,
        /* Could not send the close sequence message */
        SANDESHA2_ERROR_COULD_NOT_SEND_THE_CLOSE_SEQ_MESSAGE,
        /* Close Sequence feature is only available for WSRM 1.1 */
        SANDESHA2_ERROR_CLOSE_SEQ_FEATURE_ONLY_AVAILABLE_FOR_WSRM1_1,
        /* Cannnot find a seq report for the given data */
        SANDESHA2_ERROR_CANNOT_FIND_SEQ_REPORT_FOR_GIVEN_DATA, 
        /* Cannnot find a seq report for the given sequence id */
        SANDESHA2_ERROR_CANNOT_FIND_SEQ_REPORT_FOR_GIVEN_SEQ_ID, 
        /* Sequence is not in a active state. Either create seq response has not
         * being received or seq has been terminated, cannot get seqID
         */
        SANDESHA2_ERROR_SEQ_NOT_IN_ACTIVE_STATE,
        /* Sequence id bean is not set */
        SANDESHA2_ERROR_SEQ_ID_BEAN_NOT_SET,
        /* Empty AckRequest messages can only be sent with the v1_1 spec */
        SANDESHA2_ERROR_EMPTY_ACK_REQUEST_MESSAGE,
        /* Cannot generate the sequence report for the given internalSequenceID */
        SANDESHA2_ERROR_CANNOT_GENERATE_SEQ_REPORT_FOR_GIVEN_INTERNAL_SEQ_ID,
        /* Canot send the ackRequest message since it is not active */
        SANDESHA2_ERROR_CANNOT_SEND_ACK_REQUEST_MESSAGE_SINCE_IS_NOT_ACTIVE,
        /* This spec version does not define a ackRequest action */
        SANDESHA2_ERROR_SPEC_VERSION_DOES_NOT_DEFINE_A_ACK_REQUEST_ACTION,
        /* This spec version does not define a ackRequest soap action */
        SANDESHA2_ERROR_SPEC_VERSION_DOES_NOT_DEFINE_A_ACK_REQUEST_SOAP_ACTION,
        /* Invalid endpoint reference */
        SANDESHA2_ERROR_INVALID_EPR,
        /* Cannot find the sequence id */
        SANDESHA2_ERROR_CANNOT_FIND_SEQ_ID,
        /* This RM version does not allow sequence closing */
        SANDESHA2_ERROR_RM_VERSION_DOES_NOT_ALLOW_SEQ_CLOSING,
        /* "Not a valid terminated sequence. Internal sequence Bean is not
         * available for the given sequence
         */
        NOT_A_VALID_TERMINATED_SEQ,
        /* "Not a valid timedout sequence. Internal sequence Bean is not
         * available for the given sequence
         */
        NOT_A_VALID_TIMEDOUT_SEQ,
        /* Completed messages bean is null, for the sequence */
        SANDESHA2_ERROR_COMPLETED_MSGS_BEAN_IS_NULL,
        /* Sequence id is not recoreded */
        SANDESHA2_ERROR_UNRECORDED_SEQ_ID,
        /* relates_to not found or invalid*/
        SANDESHA2_ERROR_INVALID_RELATES_TO,
        /* To is NULL */
        SANDESHA2_ERROR_TO_IS_NULL,
        /* Create Sequence Part is NULL */
        SANDESHA2_ERROR_CREATE_SEQ_PART_IS_NULL,
        /* AcksTo is NULL */
        SANDESHA2_ERROR_ACKS_TO_IS_NULL,
        /* Create sequence message does not have the WSA:Action value */
        SANDESHA2_ERROR_CREATE_SEQ_MSG_DOES_NOT_HAVE_WSA_ACTION_VALUE,
        /* Create sequence message does not has a valid RM namespace value. 
         * Can't decide the RM version
         */
        SANDESHA2_ERROR_CREATE_SEQ_MSG_DOES_NOT_HAVE_VALID_RM_NS_VALUE,

        /* Application message is NULL */
        SANDESHA2_ERROR_APPLICATION_MSG_NULL, 
        /* Configuration Context is NULL */
        SANDESHA2_ERROR_CONF_CTX_NULL,
        /* Cannot find the rmVersion of the given message */
        SANDESHA2_ERROR_CANNOT_FIND_RM_VERSION_OF_GIVEN_MSG,
        /* Given message has rmNamespace value, which is different from the
         * reqistered namespace for the sequence
         */
        SANDESHA2_ERROR_RM_NS_VALUE_IS_DIFFERENT_FROM_REGISTERED_NS_FOR_SEQ,
        /* Cannot initialize the message */
        SANDESHA2_ERROR_CANNOT_INIT_MSG,
        /* Error in processing the message */
        SANDESHA2_ERROR_CANNOT_PROCESS_MSG,
        /* String array is invalid */
        SANDESHA2_ERROR_INVALID_STRING_ARRAY,
        /** The following has to be the last error value all the time.
            All other error codes should appear above this.
            SANDESHA_ERROR_LAST is used to track the number of error codes present
            for the purpose of sizing the error message array.
          */
        /* MessagePending header must have an attribute named 'pending'" */
        SANDESHA2_ERROR_PENDING_HEADER_MUST_HAVE_ATTRIBUTE_PENDING,
        /* Attribute 'pending' must have value 'true' or 'false' */
        SANDESHA2_ERROR_ATTRIBUTE_PENDING_MUST_HAVE_VALUE_TRUE_OR_FALSE,
        /* MakeConnection element should have at lease one of Address and Identifier subelements */
        SANDESHA2_ERROR_MAKE_CONNECTION_ELEMENT_SHOULD_HAVE_AT_LEAST_ADDRESS_OR_IDENTIFIER,
        /* Invalid MakeConnection object. Both Identifier and Address are null */
        SANDESHA2_ERROR_INVALID_MAKE_CONNECTION_BOTH_IDENTIFER_AND_ADDRESS_NULL,
        /* MakeConnection is not supported in this RM version */
        SANDESHA2_ERROR_MAKE_CONNECTION_IS_NOT_SUPPORTED_IN_THIS_RM_VERSION,
        /* Invalid MakeConnection message. Either Address or Identifier must be present */
        SANDESHA2_ERROR_INVALID_MAKE_CONNECTION_MSG,
        /* Database cannot be opened */
        SANDESHA2_ERROR_CANNOT_OPEN_DATABASE,
        /* There is an sql error. Please refer logs */
        SANDESHA2_ERROR_SQL_ERROR,
        /* Cannot build message context since service is not present */
        SANDESHA2_ERROR_CANNOT_BUILD_MSG_CTX_WHEN_SVC_NOT_PRESENT,
        /* Cannot find a operation for generated message */
        SANDESHA2_ERROR_CANNOT_FIND_OP_FOR_GENERATED_MSG,
        /* Invalid persistence property string */
        SANDESHA2_ERROR_INVALID_PERSISTENCE_PROPERTY_STRING,
        SANDESHA2_ERROR_LAST
    };
        
axis2_status_t AXIS2_CALL
sandesha2_error_init();

/** @} */
#ifdef __cplusplus
}
#endif
 
#endif /*SANDESHA2_ERROR_H*/
