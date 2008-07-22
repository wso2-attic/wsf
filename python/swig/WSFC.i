#ifdef SWIGRUBY
%module "WSFC"
#elif SWIGPERL5
%module "WSO2::WSF::C"
#elif SWIGPYTHON
%module "WSFC"
#endif

%{
#include "axiom.h"
#include "axis2_svc.h"
#include "axis2_msg_recv.h"
#include "axis2_const.h"
#include "axis2_defines.h"
#include "axutil_env.h"
#include "axutil_utils.h"
#include "axutil_string.h"
#include "axis2_conf_ctx.h"
#include "axiom_node.h"
#include "axis2_options.h"
#include "axis2_svc_client.h"
#include "axutil_qname.h"
#include "axutil_log.h"
/*#include "axis2_key_type.h"*/
#include "axis2_conf.h"
#include "axutil_param.h"
#include "axis2_svc_ctx.h"
#include "axis2_desc.h"
#include "axis2_policy_include.h"
/*#include "rampart_context.h"*/
#include "axiom_document.h"
#include "axutil_utils_defines.h"
#include "axutil_param.h"
#include "neethi_engine.h"
#include "neethi_options.h"
#include "rp_defines.h"

#define WSF_PROP_NAME_SERVER_CERT "SERVER_CERT"
#define WSF_PROP_NAME_KEY_FILE "KEY_FILE"
#define WSF_PROP_NAME_SSL_PASSPHRASE "SSL_PASSPHRASE" 

#define WSF_RAMPART_CONFIGURATION "RampartConfiguration"

#define WSF_ELEMENT_LN_SOAP12_FAULT_CODE    "Code"
#define WSF_ELEMENT_LN_SOAP12_FAULT_REASON  "Reason"
#define WSF_ELEMENT_LN_SOAP12_FAULT_DETAIL  "Detail"
#define WSF_ELEMENT_LN_SOAP12_FAULT_ROLE    "Role"
#define WSF_ELEMENT_LN_SOAP11_FAULT_CODE    "faultcode"
#define WSF_ELEMENT_LN_SOAP11_FAULT_REASON  "faultstring"
#define WSF_ELEMENT_LN_SOAP11_FAULT_DETAIL  "detail"
#define WSF_ELEMENT_LN_SOAP11_FAULT_ROLE    "faultactor"

%}

#define WSF_CP_SEC_TOKEN     "security_token"

typedef char         axis2_char_t;
typedef int          axis2_bool_t;
typedef int          axis2_status_t;
typedef int          axis2_scope_t;
typedef unsigned int axis2_ssize_t;
typedef char         axis2_byte_t;

%include wsf_constants.i
%include wsf_inlines.i
%include wsf_python.i

%include "cpointer.i"
%include "typemaps.i"


%pointer_functions(axiom_node_t *, axiom_node_t_pp);

axutil_env_t *
axutil_env_create_all(const axis2_char_t        *log_file,
                      const axutil_log_levels_t  log_level);

axis2_endpoint_ref_t *
axis2_endpoint_ref_create(const axutil_env_t *env,
                          const axis2_char_t *address);

axis2_status_t 
axis2_options_set_to(axis2_options_t      *options,
                     const axutil_env_t   *env,
                     axis2_endpoint_ref_t *to);

axis2_status_t
axis2_options_set_from(axis2_options_t      *options,
                       const axutil_env_t   *env,
                       axis2_endpoint_ref_t *from);

void
axis2_options_set_action(axis2_options_t    *options,
                         const axutil_env_t *env,
                         const axis2_char_t *action);

axis2_status_t
axis2_options_set_enable_rest(axis2_options_t    *options,
                              const axutil_env_t *env,
                              const axis2_bool_t  enable_rest);

axis2_status_t
axis2_options_set_http_method(axis2_options_t    *options,
                              const axutil_env_t *env,
                              const axis2_char_t *http_method);

axis2_status_t
axis2_options_set_soap_version(axis2_options_t    *options,
                               const axutil_env_t *env,
                               const int           soap_version);

axis2_status_t 
axis2_options_set_soap_action(axis2_options_t    *options,
                              const axutil_env_t *env,
                              axutil_string_t    *soap_action);

axis2_status_t 
axis2_options_set_reply_to(axis2_options_t      *options,
                           const axutil_env_t   *env,
                           axis2_endpoint_ref_t *reply_to);

axis2_status_t 
axis2_options_set_fault_to(axis2_options_t      *options,
                           const axutil_env_t   *env,
                           axis2_endpoint_ref_t *fault_to);

axis2_status_t
axis2_options_set_enable_mtom(axis2_options_t    *options,
                              const axutil_env_t *env,
                              axis2_bool_t        enable_mtom);

axis2_svc_client_t *
axis2_svc_client_create(const axutil_env_t *env,
                        const axis2_char_t *client_home);

axis2_status_t
axis2_svc_client_engage_module(axis2_svc_client_t *svc_client,
                               const axutil_env_t *env,
                               const axis2_char_t *module_name);

axis2_char_t * 
axiom_node_to_string(axiom_node_t       *om_node,
                     const axutil_env_t *env);

axiom_types_t
axiom_node_get_node_type(axiom_node_t       *om_node,
                         const axutil_env_t *env);

axiom_node_t *
axiom_node_get_first_child(axiom_node_t       *om_node,
                           const axutil_env_t *env);

axiom_node_t *
axiom_node_get_next_sibling(axiom_node_t       *om_node,
                            const axutil_env_t *env);   

axiom_node_t *
axiom_node_get_first_element(axiom_node_t       *om_node,
                             const axutil_env_t *env);

axis2_char_t *
axiom_element_get_text(axiom_element_t    *om_element,
                       const axutil_env_t *env,
                       axiom_node_t       *element_node);

axiom_child_element_iterator_t *
axiom_element_get_child_elements(axiom_element_t    *om_element,
                                 const axutil_env_t *env,
                                 axiom_node_t       *element_node);

axiom_node_t *
axiom_child_element_iterator_next(axiom_child_element_iterator_t *iterator,
                                  const axutil_env_t             *env);

axis2_char_t *
axiom_element_get_localname(axiom_element_t    *om_element,
                            const axutil_env_t *env);

axiom_namespace_t *
axiom_element_get_namespace(axiom_element_t    *om_element,
                            const axutil_env_t *env,
                            axiom_node_t       *ele_node);

axis2_char_t *
axiom_namespace_get_uri(axiom_namespace_t  *om_namespace,
                        const axutil_env_t *env);

axis2_char_t *
axiom_element_get_attribute_value_by_name(axiom_element_t    *om_ele,
                                          const axutil_env_t *env,
                                          axis2_char_t       *attr_name);

axiom_node_t *
axiom_node_detach(axiom_node_t       *om_node,
                  const axutil_env_t *env);

axiom_data_handler_t *
axiom_data_handler_create(const axutil_env_t *env,
                          const axis2_char_t *file_name,
                          const axis2_char_t *mime_type);

axiom_data_handler_t *
axiom_text_get_data_handler(axiom_text_t       *om_text,
                            const axutil_env_t *env);

axis2_char_t *
axiom_data_handler_get_content_type(axiom_data_handler_t *data_handler,
                                    const axutil_env_t   *env);

axis2_char_t *
axiom_text_get_content_id(axiom_text_t       *om_text,
                          const axutil_env_t *env);

axiom_node_t * 
axis2_svc_client_send_receive(axis2_svc_client_t *svc_client,
                              const axutil_env_t *env,
                              const axiom_node_t *payload);

axis2_status_t
axis2_svc_client_send_robust(axis2_svc_client_t *svc_client,
                             const axutil_env_t *env,
                             const axiom_node_t *payload);

axis2_options_t *
axis2_svc_client_get_options(const axis2_svc_client_t *svc_client,
                             const axutil_env_t       *env);

axis2_options_t *
axis2_options_create(const axutil_env_t *env);

axis2_status_t
axis2_svc_client_set_options(axis2_svc_client_t    *svc_client,
                             const axutil_env_t    *env,
                             const axis2_options_t *options);

void 
axiom_xml_reader_free(axiom_xml_reader_t *parser,
                      const axutil_env_t *env);

axis2_status_t 
axis2_svc_client_set_proxy(axis2_svc_client_t *svc_client,
                           const axutil_env_t *env,
                           axis2_char_t       *proxy_host,
                           axis2_char_t       *proxy_port);

axutil_property_t *
axutil_property_create(const axutil_env_t *env);

axutil_string_t * 
axutil_string_create(const axutil_env_t *env,
                     const axis2_char_t *str);

axis2_char_t *
axutil_uuid_gen(const axutil_env_t *env);

axis2_bool_t 
axis2_svc_client_get_last_response_has_fault(const axis2_svc_client_t *svc_client,
                                             const axutil_env_t       *env);

axis2_status_t 
axis2_options_set_xml_parser_reset(axis2_options_t    *options,
                                   const axutil_env_t *env,
                                   const axis2_bool_t  paser_reset_flag);

axis2_status_t 
axis2_conf_add_param(axis2_conf_t * conf,
                     const axutil_env_t * env,
                     axutil_param_t * param);

axutil_param_t *
axutil_param_create(const axutil_env_t * env,
                    axis2_char_t * name,
                    void *value);

axis2_svc_t *
axis2_svc_client_get_svc(const axis2_svc_client_t * svc_client,
                         const axutil_env_t * env);

axis2_desc_t *
axis2_svc_get_base(const axis2_svc_t * svc,
                   const axutil_env_t * env);

axis2_svc_ctx_t *
axis2_svc_client_get_svc_ctx(const axis2_svc_client_t * svc_client,
                             const axutil_env_t * env);

axis2_conf_ctx_t *
axis2_svc_ctx_get_conf_ctx(const axis2_svc_ctx_t * svc_ctx,
                           const axutil_env_t * env);

axis2_conf_t *
axis2_conf_ctx_get_conf(const axis2_conf_ctx_t * conf_ctx,
                        const axutil_env_t * env);

axis2_policy_include_t *
axis2_desc_get_policy_include(axis2_desc_t * desc,
                              const axutil_env_t * env);

axis2_status_t 
axis2_policy_include_add_policy_element(axis2_policy_include_t * policy_include,
                                        const axutil_env_t * env,
                                        int type,
                                        neethi_policy_t * policy);

neethi_options_t *
neethi_options_create(const axutil_env_t *env);

axis2_status_t 
neethi_options_set_include_timestamp(neethi_options_t *options,
                                     const axutil_env_t *env,
                                     axis2_bool_t include_timestamp);

axis2_status_t
neethi_options_set_is_username_token(neethi_options_t *options,
                                     const axutil_env_t *env,
                                     axis2_bool_t is_username_token);

axis2_status_t 
neethi_options_set_encrypt_body(neethi_options_t *options,
                                const axutil_env_t *env,
                                axis2_bool_t encrypt_body);

axis2_status_t 
neethi_options_set_algorithmsuite(neethi_options_t *options,
                                  const axutil_env_t *env,
                                  axis2_char_t *algorithmsuite);

axis2_status_t 
neethi_options_set_keyidentifier(neethi_options_t *options,
                                 const axutil_env_t *env,
                                 axis2_char_t *keyidentifier);

axis2_status_t 
neethi_options_set_sign_body(neethi_options_t *options,
                             const axutil_env_t *env,
                             axis2_bool_t sign_body);

axis2_status_t 
neethi_options_set_signature_protection(neethi_options_t *options,
                                        const axutil_env_t *env,
                                        axis2_bool_t signature_protection);

axis2_status_t 
neethi_options_set_encrypt_before_sign(neethi_options_t *options,
                                       const axutil_env_t *env,
                                       axis2_bool_t encrypt_before_sign);

axiom_node_t *
neethi_options_get_root_node(neethi_options_t *options,
                             const axutil_env_t *env);

neethi_policy_t *
neethi_engine_get_policy(const axutil_env_t * env,
                         axiom_node_t * node,
                         axiom_element_t * element);
/*
rampart_context_t *
rampart_context_create(const axutil_env_t *env);

axis2_status_t
rampart_context_set_prv_key(rampart_context_t *rampart_context,
                            const axutil_env_t *env,
                            void *prv_key);

axis2_status_t 
rampart_context_set_prv_key_type(rampart_context_t *rampart_context,
                                 const axutil_env_t *env,
                                 axis2_key_type_t type);

axis2_status_t 
rampart_context_set_certificate(rampart_context_t *rampart_context,
                                const axutil_env_t *env,
                                void *certificate);

axis2_status_t 
rampart_context_set_certificate_type(rampart_context_t *rampart_context,
                                     const axutil_env_t *env,
                                     axis2_key_type_t type);

axis2_status_t
rampart_context_set_receiver_certificate(rampart_context_t *rampart_context,
                                         const axutil_env_t *env,
                                         void *receiver_certificate);

axis2_status_t 
rampart_context_set_receiver_certificate_type(rampart_context_t *rampart_context,
                                              const axutil_env_t *env,
                                              axis2_key_type_t type);

axis2_status_t
rampart_context_set_user(rampart_context_t *rampart_context,
                         const axutil_env_t *env,
                         axis2_char_t *user);

axis2_status_t 
rampart_context_set_password(rampart_context_t *rampart_context,
                             const axutil_env_t *env,
                             axis2_char_t *password);

axis2_status_t 
rampart_context_set_password_type(rampart_context_t *rampart_context,
                                  const axutil_env_t *env,
                                  axis2_char_t *password_type);

axis2_status_t 
rampart_context_set_ttl(rampart_context_t *rampart_context,
                        const axutil_env_t *env,
                        int ttl);

axis2_status_t 
rampart_context_set_pwcb_function(rampart_context_t *rampart_context,
                                  const axutil_env_t *env,
                                  password_callback_fn pwcb_function,
                                  void *ctx);
*/
axiom_namespace_t *axiom_namespace_create(const axutil_env_t * env,
					  const axis2_char_t * uri,
					  const axis2_char_t * prefix);

axiom_element_t *axiom_element_create(const axutil_env_t * env,
				      axiom_node_t * parent,
				      const axis2_char_t * localname,
				      axiom_namespace_t * ns,
				      axiom_node_t ** node);

axiom_attribute_t *axiom_attribute_create(const axutil_env_t * env,
					  const axis2_char_t * localname,
					  const axis2_char_t * value,
					  axiom_namespace_t * ns);

axis2_status_t axiom_element_add_attribute(axiom_element_t * om_element,
					   const axutil_env_t * env,
					   axiom_attribute_t * attribute,
					   axiom_node_t * node);

axis2_status_t axiom_element_set_text(axiom_element_t * om_element,
				      const axutil_env_t * env,
				      const axis2_char_t * text,
				      axiom_node_t * element_node);

axis2_status_t axis2_svc_client_add_header(axis2_svc_client_t * svc_client,
					   const axutil_env_t * env,
					   axiom_node_t * header);



