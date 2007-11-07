enum axis2_status_codes
{
    /** Critical Failure state */
    AXIS2_CRITICAL_FAILURE = -1,

    /** Failure state */
    AXIS2_FAILURE,

    /** Success state */
    AXIS2_SUCCESS
};

typedef enum axutil_log_levels
{
    /** Critical level, logs only critical errors */
    AXIS2_LOG_LEVEL_CRITICAL = 0,
    /** Error level, logs only errors */
    AXIS2_LOG_LEVEL_ERROR,
    /** Warning level, logs only warnings */
    AXIS2_LOG_LEVEL_WARNING,
    /** Info level, logs information */
    AXIS2_LOG_LEVEL_INFO,
    /** Debug level, logs everything */
    AXIS2_LOG_LEVEL_DEBUG,
    /** Trace level, Enable with compiler time option AXIS2_TRACE */
    AXIS2_LOG_LEVEL_TRACE
} axutil_log_levels_t;

typedef enum _axis2_xml_parser_type
{
    AXIS2_XML_PARSER_TYPE_BUFFER = 1,
    AXIS2_XML_PARSER_TYPE_FILE,
    AXIS2_XML_PARSER_TYPE_DOC
} axis2_xml_parser_type;

typedef enum soap_version
{
    AXIOM_SOAP_VERSION_NOT_SET = 0,
    AXIOM_SOAP11,
    AXIOM_SOAP12
} axiom_soap_version;

typedef enum axiom_types_t
{
    AXIOM_INVALID = 0,
    AXIOM_DOCUMENT,
    AXIOM_ELEMENT,
    AXIOM_DOCTYPE,
    AXIOM_COMMENT,
    AXIOM_ATTRIBUTE,
    AXIOM_NAMESPACE,
    AXIOM_PROCESSING_INSTRUCTION,
    AXIOM_TEXT,
    AXIOM_DATA_SOURCE
} axiom_types_t;

typedef enum axis2_policy_types
{
     AXIS2_POLICY = 0,
     AXIS2_MODULE_POLICY,
     AXIS2_SERVICE_POLICY,
     AXIS2_OPERATION_POLICY,
     AXIS2_MESSAGE_POLICY,
     AXIS2_PORT_POLICY,
     AXIS2_PORT_TYPE_POLICY,
     AXIS2_BINDING_POLICY,
     AXIS2_BINDING_OPERATION_POLICY,
     AXIS2_INPUT_POLICY,
     AXIS2_OUTPUT_POLICY,
     AXIS2_BINDING_INPUT_POLICY,
     AXIS2_BINDING_OUTPUT_POLICY,
     AXIS2_MODULE_OPERATION_POLICY,
     AXIS2_POLICY_REF,
     AXIS2_ANON_POLICY
} axis2_policy_types_t;

/****************************** rampart ***************************************/

typedef enum axis2_key_type_t
{
    AXIS2_KEY_TYPE_UNKNOWN = 0,
    AXIS2_KEY_TYPE_PEM,
    AXIS2_KEY_TYPE_DER
} axis2_key_type_t;
 

/* AXIS2_TRANSPORT_H */

#define AXIS2_HTTP_GET          "GET"
#define AXIS2_HTTP_METHOD       "HTTP_METHOD"
#define AXIS2_VALUE_TRUE "true"

/* end AXIS2_TRANSPORT_H */

#define AXIS2_LOG_SI __FILE__,__LINE__

#define AXIS2_TRUE 1
#define AXIS2_FALSE 0

#define AXIS2_WSA_NAMESPACE_SUBMISSION "http://schemas.xmlsoap.org/ws/2004/08/addressing"
#define AXIS2_WSA_VERSION "WSAddressingVersion"

/**
 * Field SOAP_STYLE_RPC_ENCODED
 */
#define AXIOM_SOAP_STYLE_RPC_ENCODED 1000

/**
 * Field SOAP_STYLE_RPC_LITERAL
 */
/*#define AXIOM_SOAP_STYLE_RPC_LITERAL 1001 */

/**
 * Field SOAP_STYLE_DOC_LITERAL_WRAPPED
 */
#define AXIOM_SOAP_STYLE_DOC_LITERAL_WRAPPED 1002

#define AXIS2_SCOPE "scope"

/**
 * Field APPLICATION_SCOPE
 */
#define AXIS2_APPLICATION_SCOPE "application"

/**
 * Field SESSION_SCOPE
 */
#define AXIS2_SESSION_SCOPE "session"

/**
 * Field GLOBAL_SCOPE
 */
#define AXIS2_MESSAGE_SCOPE "message"
/**
 * Field PHASE_SERVICE
 */
#define AXIS2_PHASE_SERVICE "service"

/**
 * Field PHASE_TRANSPORT
 */
#define AXIS2_PHASE_TRANSPORT "transport"

/**
 * Field PHASE_GLOBAL
 */
#define AXIS2_PHASE_GLOBAL "global"

/**
 * Field SESSION_CONTEXT_PROPERTY
 */
#define AXIS2_SESSION_CONTEXT_PROPERTY "SessionContext"

/**
 * TRANSPORT constants
 */
#define AXIS2_TRANSPORT_HTTP "http"
#define AXIS2_TRANSPORT_SMTP "smtp"
#define AXIS2_TRANSPORT_TCP "tcp"
#define AXIS2_TRANSPORT_XMPP "xmpp"
#define AXIS2_TRANSPORT_HTTPS "https"

typedef enum
{
    AXIS2_TRANSPORT_ENUM_HTTP = 0,
    AXIS2_TRANSPORT_ENUM_SMTP,
    AXIS2_TRANSPORT_ENUM_TCP,
    AXIS2_TRANSPORT_ENUM_XMPP,
        AXIS2_TRANSPORT_ENUM_HTTPS,
    AXIS2_TRANSPORT_ENUM_MAX
} AXIS2_TRANSPORT_ENUMS;

/**
 * Field LISTSERVICES
 */
#define AXIS2_REQUEST_URL_PREFIX "/services"

#define AXIS2_LISTSERVICES "listServices"

#define AXIS2_LIST_SERVICE_FOR_MODULE_ENGAMNET "listop"


/**
 * List service for adminpagse
 */
#define AXIS2_ADMIN_LISTSERVICES "listService"

#define AXIS2_LIST_MODULES "listModules"

#define AXIS2_LIST_GLOABLLY_ENGAGED_MODULES "globalModules"

#define AXIS2_LIST_PHASES "listPhases"

#define AXIS2_ENGAGE_GLOBAL_MODULE "engagingglobally"
#define AXIS2_ENGAGE_MODULE_TO_SERVICE "engageToService"
#define AXIS2_ENGAGE_MODULE_TO_SERVICE_GROUP "engageToServiceGroup"

#define AXIS2_ADMIN_LOGIN "adminlogin"

#define AXIS2_LIST_CONTEXTS "listContexts"
#define AXIS2_LOGOUT "logout"

#define AXIS2_VIEW_GLOBAL_HANDLERS "viewGlobalHandlers"
#define AXIS2_SELECT_SERVICE "selectService"
#define AXIS2_EDIR_SERVICE_PARA "editServicepara"
#define AXIS2_SELECT_SERVICE_FOR_PARA_EDIT "selectServiceParaEdit"
#define AXIS2_VIEW_SERVICE_HANDLERS "viewServiceHandlers"
#define AXIS2_LIST_SERVIC_GROUPS "listServciceGroups"

/**
 * Field SERVICE_MAP
 */
#define AXIS2_SERVICE_MAP "servicemap"
#define AXIS2_SERVICE_GROUP_MAP "serviceGroupmap"

#define AXIS2_CONFIG_CONTEXT "config_context"
#define AXIS2_ACTION_MAPPING "actionMapping"
#define AXIS2_OUTPUT_ACTION_MAPPING "outputActionMapping"
#define AXI2_FAULT_ACTION_MAPPING "faultActionMapping"

#define AXIS2_SERVICE "service"

#define AXIS2_OPEARTION_MAP "opmap"
/**
 * Field Available modules
 */
#define AXIS2_MODULE_ADDRESSING "addressing"

#define AXIS2_USER_NAME "userName"
#define AXIS2_PASSWORD "password"

/**
 * Field SINGLE_SERVICE
 */
#define AXIS2_SINGLE_SERVICE "singleservice"
#define AXIS2_WSDL_CONTENT "wsdl"
#define AXIS2_REQUEST_WSDL "?wsdl"
#define AXIS2_STYLE_RPC  "rpc"
#define AXIS2_STYLE_DOC  "doc"
#define AXIS2_STYLE_MSG  "msg"

typedef enum axis2_wsdl_msg_labels
{
    AXIS2_WSDL_MESSAGE_LABEL_IN = 0,
    AXIS2_WSDL_MESSAGE_LABEL_OUT,
    AXIS2_WSDL_MESSAGE_LABEL_MAX
}axis2_wsdl_msg_labels_t;

/*********************Message Exchange Pattern Constants***********************/
/**
 * Field MEP_URI_IN_ONLY
 */
#define AXIS2_MEP_URI_IN_ONLY "http://www.w3.org/2004/08/wsdl/in-only"

#define AXIS2_MEP_CONSTANT_IN_ONLY 10

/**
 * Field MEP_URI_ROBUST_IN_ONLY
 */
#define AXIS2_MEP_URI_ROBUST_IN_ONLY "http://www.w3.org/2004/08/wsdl/robust-in-only"

#define AXIS2_MEP_CONSTANT_ROBUST_IN_ONLY 11

/**
 * Field MEP_URI_IN_OUT
 */
#define AXIS2_MEP_URI_IN_OUT "http://www.w3.org/2004/08/wsdl/in-out"

#define AXIS2_MEP_CONSTANT_IN_OUT 12
/**
 * Field MEP_URI_IN_OPTIONAL_OUT
 */
#define AXIS2_MEP_URI_IN_OPTIONAL_OUT "http://www.w3.org/2004/08/wsdl/in-opt-out"

#define AXIS2_MEP_CONSTANT_IN_OPTIONAL_OUT 13

/**
 * Field MEP_URI_OUT_ONLY
 */
#define AXIS2_MEP_URI_OUT_ONLY "http://www.w3.org/2004/08/wsdl/out-only"

#define AXIS2_MEP_CONSTANT_OUT_ONLY 14

/**
 * Field MEP_URI_ROBUST_OUT_ONLY
 */
#define AXIS2_MEP_URI_ROBUST_OUT_ONLY "http://www.w3.org/2004/08/wsdl/robust-out-only"

#define AXIS2_MEP_CONSTANT_ROBUST_OUT_ONLY 15

/**
 * Field MEP_URI_OUT_IN
 */
#define AXIS2_MEP_URI_OUT_IN "http://www.w3.org/2004/08/wsdl/out-in"

#define AXIS2_MEP_CONSTANT_OUT_IN 16

/**
 * Field MEP_URI_OUT_OPTIONL_IN
 */
#define AXIS2_MEP_URI_OUT_OPTIONAL_IN "http://www.w3.org/2004/08/wsdl/out-opt-in"

#define AXIS2_MEP_CONSTANT_OUT_OPTIONAL_IN 17
#define AXIS2_MEP_CONSTANT_INVALID -1

/**
 * Field WSDL_MESSAGE_DIRECTION_IN
 */
#define AXIS2_WSDL_MESSAGE_DIRECTION_IN "in"


/**
 * Field WSDL_MESSAGE_DIRECTION_OUT
 */
#define AXIS2_WSDL_MESSAGE_DIRECTION_OUT "out"


/**
 * Field METHOD_NAME_ESCAPE_CHARACTOR
 */
/* static const char METHOD_NAME_ESCAPE_CHARACTOR '?' */

#define AXIS2_LOGGED "Logged"


/* static const char SERVICE_NAME_SPLIT_CHAR':' */


/*********************Configuration *******************************************/

#define AXIS2_ENABLE_REST "enableREST"
#define AXIS2_ENABLE_REST_THROUGH_GET "restThroughGet"
/* globally enable MTOM */
#define AXIS2_ENABLE_MTOM "enableMTOM"
#define AXIS2_ATTACHMENT_TEMP_DIR "attachmentDIR"
#define AXIS2_CACHE_ATTACHMENTS "cacheAttachments"
#define AXIS2_FILE_SIZE_THRESHOLD "sizeThreshold"
/* op_ctx persistance */
#define AXIS2_PERSIST_OP_CTX "persistOperationContext"

/******************************************************************************/

#define AXIS2_VALUE_FALSE "false"
#define AXIS2_CONTAINER_MANAGED "ContainerManaged"
#define AXIS2_RESPONSE_WRITTEN "CONTENT_WRITTEN"

#define AXIS2_TESTING_PATH "target/test-resources/"

#define AXIS2_TESTING_REPOSITORY "target/test-resources/samples"

/* Indicate whether the axis2 service should be loaded at start up */
#define AXIS2_LOAD_SVC_STARTUP "loadServiceAtStartup"


/*************************** REST_WITH_GET ************************************/

#define AXIS2_GET_PARAMETER_OP "op"
#define AXIS2_GET_PARAMETER_URL "http://ws.apache.org/goGetWithREST"

/******************************************************************************/


#define AXIS2_NAMESPACE_PREFIX "axis2"
#define AXIS2_NAMESPACE_URI "http://ws.apache.org/namespaces/axis2"

#define AXIS2_SVC_GRP_ID "ServiceGroupId"    


#define AXIS2_RESPONSE_SOAP_ENVELOPE "Axis2ResponseEnvelope"    
#define AXIS2_HANDLER_ALREADY_VISITED "handler_already_visited"


/**************************  WS_POLICY ***************************************/
#define WS_POLICY "Policy"

#define WS_IN_POLICY "inpolicy"
#define WS_OUT_POLICY "outpolicy"

#define WS_SIGN "sign"
#define WS_ENCRYPT "encrypt"
#define WS_ALGORITHM "algorithmSuite"
#define WS_LAYOUT "layOut"
#define WS_TIMESTAMP "includeTimeStamp"
#define WS_PROTECTION_ORDER "protectionOrder"
#define WS_UT "useUsernameToken"
#define WS_TOKEN_REFERENCE "securityTokenReference"
#define WS_ENCRYPT_SIGNATURE "encryptSignature"

#define WS_DEFAULT_TOKEN_VAL "X509"
#define WS_X509_TOKEN_VAL "X509Token"
#define WS_INITIATOR_VAL "InitiatorToken"
#define WS_INCLUDE_TOKEN_URI "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy/IncludeToken/Always"
#define WS_INCLUDE_TOKEN "IncludeToken"
#define WS_RECIPIENT_TOKEN "RecipientToken"
#define WS_USERNAMETOKEN "UsernameToken"
#define WS_SIGNSUPPORTING_TOKEN "SignedSupportingTokens"
#define WS_ALGO_SUITE "AlgorithmSuite"
#define WS_ONLY_SIGN_HEADER_AND_BODY "OnlySignEntireHeadersAndBody"
#define WS_ENCRYPTPARTS "EncryptedParts"
#define WS_BODY "Body"
#define WS_LAYOUT_VAL "Layout"
#define WS_STRICT "Strict"
#define WS_WSS10 "Wss10"


/** ws_security_token options */
#define WS_USER "user"
#define WS_CERTIFICATE "certificate"
#define WS_PASSWORD_TYPE "passwordType"
#define WS_PASSWORD "password"
#define WS_PRIVATE_KEY "privateKey"
#define WS_TTL "ttl"
/* #define WS_CERTIFICATE_FORMAT "certificateFormat" */
/* #define WS_PVT_KEY_FORMAT "privateKeyFormat" */
#define WS_RECEIVER_CERTIFICATE "receiverCertificate"
/* #define WS_RECEIVER_CERTIFICATE_FORMAT "receiverCertificateFormat" */
/* #define WS_INFLOW_SECURITY_POLICY  "InflowRampartContext" */
/* #define WS_OUTFLOW_SECURITY_POLICY "OutflowRampartContext" */
#define WS_RAMPART_CONFIGURATION "RampartConfiguration"
#define WS_DIGEST "Digest"
#define WS_PLAINTEXT "plainText"
#define WS_PASSWORD_CALL_BACK "passwordCallback"

#define BASIC256 "Basic256"
#define BASIC192 "Basic192"
#define BASIC128 "Basic128"
#define TRIPLEDES "TripleDes"
#define BASIC256_RSA15 "Basic256Rsa15"
#define BASIC192_RSA15 "Basic192Rsa15"
#define BASIC128_RSA15 "Basic128Rsa15"
#define TRIPLEDES_RSA15 "TripleDesRsa15"

#define ISSUER_SERIAL "IssuerSerial"
#define KEYIDENTIFIER "KeyIdentifier"
#define EMBEDDEDTOKEN "EmbeddedToken"
#define THUMBPRINT "Thumbprint"
#define DIRECT "Direct"
#define ISSUER_SERIAL_VAL "MustSupportRefIssuerSerial"
#define KEYIDENTIFIER_VAL "MustSupportRefKeyIdentifier"
#define EMBEDDEDTOKEN_VAL "MustSupportRefEmbeddedToken"
#define THUMBPRINT_VAL "MustSupportRefThumbprint"

#define SIGN_BEFORE "SignBeforeEncrypt"
#define ENCRYPT_BEFORE "EncryptBeforeSigning"

#define RP_REQUIRE_KEY_IDENTIFIRE_REFERENCE "RequireKeyIdentifireReference"
#define RP_REQUIRE_ISSUER_SERIAL_REFERENCE "RequireIssuerSerialReference"
#define RP_REQUIRE_EMBEDDED_TOKEN_REFERENCE "RequireEmbeddedTokenReference"
#define RP_REQUIRE_THUMBPRINT_REFERENCE "RequireThumbprintReference"
#define RP_REQUIRE_DERIVED_KEYS "RequireDerivedKeys"

