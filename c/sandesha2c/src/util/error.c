/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
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

#include <stdlib.h>
#include <sandesha2_error.h>
#include <axutil_error_default.h>

AXIS2_IMPORT extern const axis2_char_t* axutil_error_messages[];

axis2_status_t AXIS2_CALL
sandesha2_error_init()
{
    /* A namespace that is not supported by Sandesha2 */
    axutil_error_messages[SANDESHA2_ERROR_UNSUPPORTED_NS] = 
    "A namespace that is not supported by Sandesha2";
    /* Object cannot generated since the om_element corresponding to
     * that is NULL 
     */
    axutil_error_messages[SANDESHA2_ERROR_NULL_OM_ELEMENT] = 
    "Object cannot generated since the om_element corresponding to \
        that is NULL";
    /* The om element has no child elements or attributes */
    axutil_error_messages[SANDESHA2_ERROR_EMPTY_OM_ELEMENT] = 
    "The om element has no child elements or attributes";
    /*  om_element cannot be generated since the element corresponding 
     * to that is NULL
     */
    axutil_error_messages[SANDESHA2_ERROR_TO_OM_NULL_ELEMENT] = 
    "om_element cannot be generated since the element corresponding \
        to that is NULL";
    /* Required OM attribute is NULL */
    axutil_error_messages[SANDESHA2_ERROR_NULL_OM_ATTRIBUTE] = 
    "Required OM attribute is NULL";
    /* An invalid number found during object to om conversion  */
    axutil_error_messages[SANDESHA2_ERROR_TO_OM_INVALID_NUMBER] = 
    "An invalid number found during object to om conversion";
    /* Ack Final now allowed in the spec  */
    axutil_error_messages[SANDESHA2_ERROR_ACK_FINAL_NOT_ALLOWED] = 
    "Ack Final now allowed in the spec";
    /* Ack None now allowed in the spec  */
    axutil_error_messages[SANDESHA2_ERROR_ACK_NONE_NOT_ALLOWED] = 
    "Ack None now allowed in the spec";

    /* 'To' Address is not set */
    axutil_error_messages[SANDESHA2_ERROR_TO_ADDRESS_NOT_SET] = 
        "'To' address is not set";
    /* Service Context is NULL */
    axutil_error_messages[SANDESHA2_ERROR_SVC_CTX_NULL] = 
        "Service context is NULL";
    axutil_error_messages[SANDESHA2_ERROR_SVC_NULL]=
        "Service is NULL";
    /* Non Unique Result */
    axutil_error_messages[SANDESHA2_ERROR_NON_UNIQUE_RESULT] = 
        "Result is Not Unique";
    /* Key is NULL. Cannot insert */
    axutil_error_messages[SANDESHA2_ERROR_KEY_IS_NULL] = 
        "Key is NULL, Cannot insert";
    /* Storage Map not present */
    axutil_error_messages[SANDESHA2_ERROR_STORAGE_MAP_NOT_PRESENT] = 
        "Storage Map not present";
    axutil_error_messages[SANDESHA2_ERROR_ENTRY_IS_NOT_PRESENT_FOR_UPDATING] =
        "Entry is not present for updating";
    axutil_error_messages[SANDESHA2_ERROR_INVALID_NS_URI] = 
        "Invalid namespace uri";
    axutil_error_messages[SANDESHA2_ERROR_INVALID_SPEC_VERSION] = 
        "Invalid Spec Version";
    axutil_error_messages[
        SANDESHA2_ERROR_INCOMING_SEQ_REPORT_NOT_PRESENT_FOR_GIVEN_SEQ_ID] = 
        "An incoming seq report is not present for the given seqID";
    axutil_error_messages[SANDESHA2_ERROR_TO_EPR_NOT_SET] = 
        "To EPR is not set";   
    axutil_error_messages[SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET] = 
        "Options object is not set";
    axutil_error_messages[SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE] = 
        "Unknown specification error message"; 
    axutil_error_messages[SANDESHA2_ERROR_COULD_NOT_SEND_TERMINATE_MESSAGE] = 
        "Could not send the terminate message";
    axutil_error_messages[SANDESHA2_ERROR_RM_SPEC_VERSION_DOES_NOT_DEFINE_A_SEQ_CLOSE_ACTION] =
        "This rm spec version does not define a sequence close action";
    axutil_error_messages[SANDESHA2_ERROR_COULD_NOT_SEND_THE_CLOSE_SEQ_MESSAGE] =
        "Could not send the close sequence message";
    axutil_error_messages[SANDESHA2_ERROR_CLOSE_SEQ_FEATURE_ONLY_AVAILABLE_FOR_WSRM1_1] =
        "Close Sequence feature is only available for WSRM 1.1";
    axutil_error_messages[SANDESHA2_ERROR_CANNOT_FIND_SEQ_REPORT_FOR_GIVEN_DATA] = 
        "Cannnot find a seq report for the given data";   
    axutil_error_messages[SANDESHA2_ERROR_CANNOT_FIND_SEQ_REPORT_FOR_GIVEN_SEQ_ID] = 
        "Cannnot find a seq report for the given sequence id";
    axutil_error_messages[SANDESHA2_ERROR_SEQ_NOT_IN_ACTIVE_STATE] = 
        "Sequence is not in a active state. Either create seq response has not \
            being received or seq has been terminated, cannot get seqID";
    axutil_error_messages[SANDESHA2_ERROR_SEQ_ID_BEAN_NOT_SET] =
        "Sequence id bean is not set";
    axutil_error_messages[SANDESHA2_ERROR_EMPTY_ACK_REQUEST_MESSAGE] =
        "Empty AckRequest messages can only be sent with the v1_1 spec"; 
    axutil_error_messages[SANDESHA2_ERROR_CANNOT_GENERATE_SEQ_REPORT_FOR_GIVEN_INTERNAL_SEQ_ID] =
        "Cannot generate the sequence report for the given internalSequenceID";
    axutil_error_messages[SANDESHA2_ERROR_CANNOT_SEND_ACK_REQUEST_MESSAGE_SINCE_IS_NOT_ACTIVE] =
        "Canot send the ackRequest message since it is not active";
    axutil_error_messages[SANDESHA2_ERROR_SPEC_VERSION_DOES_NOT_DEFINE_A_ACK_REQUEST_ACTION] =
        "This spec version does not define a ackRequest action";
    axutil_error_messages[SANDESHA2_ERROR_SPEC_VERSION_DOES_NOT_DEFINE_A_ACK_REQUEST_SOAP_ACTION] = 
        "This spec version does not define a ackRequest soap action";
    axutil_error_messages[SANDESHA2_ERROR_CANNOT_FIND_SEQ_ID] =
        "Cannot find the sequence id";
    axutil_error_messages[SANDESHA2_ERROR_RM_VERSION_DOES_NOT_ALLOW_SEQ_CLOSING] =
        "This RM version does not allow sequence closing";
    axutil_error_messages[NOT_A_VALID_TERMINATED_SEQ] = 
        "Not a valid terminated sequence. Internal sequence Bean is not \
         available for the given sequence";
    axutil_error_messages[NOT_A_VALID_TIMEDOUT_SEQ] =
        "Not a valid timedout sequence. Internal sequence Bean is not \
         available for the given sequence";
    axutil_error_messages[SANDESHA2_ERROR_COMPLETED_MSGS_BEAN_IS_NULL] =
        "Completed messages bean is null, for the sequence"; 
    axutil_error_messages[SANDESHA2_ERROR_UNRECORDED_SEQ_ID] =
        "Sequence id is not recoreded"; 
    axutil_error_messages[SANDESHA2_ERROR_TO_IS_NULL] =
        "To is NULL";
    axutil_error_messages[SANDESHA2_ERROR_CREATE_SEQ_PART_IS_NULL] =
        "Create Sequence Part is NULL";
    axutil_error_messages[SANDESHA2_ERROR_ACKS_TO_IS_NULL] =
        "AcksTo is NULL";
    axutil_error_messages[SANDESHA2_ERROR_CREATE_SEQ_MSG_DOES_NOT_HAVE_WSA_ACTION_VALUE] = 
        "Create sequence message does not have the WSA:Action value";
    axutil_error_messages[SANDESHA2_ERROR_CREATE_SEQ_MSG_DOES_NOT_HAVE_VALID_RM_NS_VALUE]=
        "Create sequence message does not has a valid RM namespace value. \
        Can't decide the RM version";
    axutil_error_messages[SANDESHA2_ERROR_APPLICATION_MSG_NULL]=
        "Application message is NULL";
    axutil_error_messages[SANDESHA2_ERROR_CONF_CTX_NULL]=
        "Configuration Context is NULL";
    axutil_error_messages[SANDESHA2_ERROR_CANNOT_FIND_RM_VERSION_OF_GIVEN_MSG]=
        "Cannot find the rmVersion of the given message";
    axutil_error_messages[SANDESHA2_ERROR_RM_NS_VALUE_IS_DIFFERENT_FROM_REGISTERED_NS_FOR_SEQ]=
        "Given message has rmNamespace value, which is different from the \
                        reqistered namespace for the sequence";
    axutil_error_messages[SANDESHA2_ERROR_CANNOT_INIT_MSG]=
        "Cannot initialize the message";
    axutil_error_messages[SANDESHA2_ERROR_CANNOT_PROCESS_MSG]=
        "Error in processing the message";
    axutil_error_messages[SANDESHA2_ERROR_INVALID_STRING_ARRAY]=
        "String array is invalid";
    axutil_error_messages[SANDESHA2_ERROR_PENDING_HEADER_MUST_HAVE_ATTRIBUTE_PENDING]=
        "MessagePending header must have an attribute named 'pending'";
    axutil_error_messages[SANDESHA2_ERROR_ATTRIBUTE_PENDING_MUST_HAVE_VALUE_TRUE_OR_FALSE]=
        "Attribute 'pending' must have value 'true' or 'false'";
    axutil_error_messages[SANDESHA2_ERROR_MAKE_CONNECTION_ELEMENT_SHOULD_HAVE_AT_LEAST_ADDRESS_OR_IDENTIFIER]=
        "MakeConnection element should have at lease one of Address and Identifier subelements";
    /* Invalid MakeConnection object. Both Identifier and Address are null */
    axutil_error_messages[SANDESHA2_ERROR_INVALID_MAKE_CONNECTION_BOTH_IDENTIFER_AND_ADDRESS_NULL]=
        "Invalid MakeConnection object. Both Identifier and Address are null";
    axutil_error_messages[SANDESHA2_ERROR_MAKE_CONNECTION_IS_NOT_SUPPORTED_IN_THIS_RM_VERSION]=
        "MakeConnection is not supported in this RM version";
    axutil_error_messages[SANDESHA2_ERROR_INVALID_MAKE_CONNECTION_MSG]=
        "Invalid MakeConnection message. Either Address or Identifier must be present";
    axutil_error_messages[SANDESHA2_ERROR_CANNOT_OPEN_DATABASE]=
        "Database cannot be opened";
    axutil_error_messages[SANDESHA2_ERROR_SQL_ERROR]=
        "There is an sql error. Please refer logs";
    axutil_error_messages[SANDESHA2_ERROR_CANNOT_BUILD_MSG_CTX_WHEN_SVC_NOT_PRESENT]=
        "Cannot build message context since service is not present";
    axutil_error_messages[SANDESHA2_ERROR_CANNOT_FIND_OP_FOR_GENERATED_MSG]=
        "Cannot find a operation for generated message";
    axutil_error_messages[SANDESHA2_ERROR_INVALID_PERSISTENCE_PROPERTY_STRING]=
        "Invalid persistence property string";

    return AXIS2_SUCCESS;
}

