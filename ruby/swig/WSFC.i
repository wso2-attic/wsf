%module "WSFC"

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
#include "axis2_key_type.h"
#include "axis2_conf.h"
#include "axutil_param.h"
#include "axis2_svc_ctx.h"
#include "axis2_desc.h"
#include "axis2_policy_include.h"
#include "rampart_context.h"
#include "axiom_document.h"
#include "axutil_utils_defines.h"
#include "axutil_param.h"
#include "neethi_options.h"
#include "rp_defines.h"
%}

%include wsf_ruby.i
%include wsf_constants.i

%include "cpointer.i"
%include "typemaps.i"

typedef char         axis2_char_t;
typedef int          axis2_bool_t;
typedef int          axis2_status_t;
typedef int          axis2_scope_t;
typedef unsigned int axis2_ssize_t;
typedef char         axis2_byte_t;

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

%inline %{
int
wsf_set_module_param_value(axutil_env_t       *env,
                            axis2_svc_client_t *svc_client,
                            axis2_char_t       *module_name,
                            axis2_char_t       *param_name,
                            axis2_char_t       *param_value)
{
  axis2_svc_ctx_t *svc_ctx = axis2_svc_client_get_svc_ctx(svc_client, env);
  if (svc_ctx == NULL)
    return AXIS2_FAILURE;
    
  axis2_conf_ctx_t *conf_ctx = axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
  if (conf_ctx == NULL)
    return AXIS2_FAILURE;
    
  axis2_conf_t *conf = axis2_conf_ctx_get_conf(conf_ctx, env);
  if (conf == NULL)
    return AXIS2_FAILURE;

  axutil_qname_t *module_qname = axutil_qname_create(env, module_name, NULL, NULL);
  if (module_qname == NULL)
    return AXIS2_FAILURE;
    
  axis2_module_desc_t *module_desc = axis2_conf_get_module(conf, env, module_qname);
  if (module_desc == NULL)
    return AXIS2_FAILURE;
    
  axutil_param_t *param = axis2_module_desc_get_param(module_desc, env, param_name);
  if (param == NULL)
    return AXIS2_FAILURE;
    
  axutil_param_set_value(param, env, axutil_strdup (env, param_value));
  
  axutil_qname_free(module_qname, env);
  
  return AXIS2_SUCCESS;
}
%}

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

%inline %{
axiom_element_t *
wsf_axiom_node_get_data_element(axiom_node_t       *om_node,
                                 const axutil_env_t *env)
{
  return (axiom_element_t *)axiom_node_get_data_element(om_node, env);
}
%}

%inline %{
axiom_text_t *
wsf_axiom_node_get_text_element(axiom_node_t       *om_node,
                                 const axutil_env_t *env)
{
  return (axiom_text_t *)axiom_node_get_data_element(om_node, env);
}
%}

%inline %{
axiom_node_t *
wsf_axiom_element_get_first_node(axiom_element_t    *element,
                                  axiom_node_t       *element_node,
                                  const axutil_env_t *env)
{
  axiom_node_t *child_node = axiom_node_get_first_child(element_node, env);

  while (child_node)
  {
    if (axiom_node_get_node_type(child_node, env) == AXIOM_ELEMENT)
      return child_node;
    else
      child_node = axiom_node_get_next_sibling(child_node, env);
  }

  return NULL;
}
%}

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

%inline %{
void
wsf_axiom_attach_content(const axutil_env_t *env,
                          axiom_node_t       *node,
                          axiom_node_t       *parent_node,
                          axis2_bool_t        enable_mtom,
                          axis2_char_t       *content_type,
                          const char         *content,
                          int                 content_length)
{
  void *data_buffer = AXIS2_MALLOC (env->allocator, sizeof (char) * content_length);
  if (data_buffer == NULL)
    return;

  memcpy (data_buffer, (void*)content, content_length);

  axiom_data_handler_t *data_handler = axiom_data_handler_create (env, NULL, content_type);
  if (data_handler == NULL)
    return;

  axiom_data_handler_set_binary_data (data_handler, env, (axis2_byte_t *)content, content_length);

  axiom_node_t *text_node = NULL;
  axiom_text_t *text = axiom_text_create_with_data_handler (env, parent_node, data_handler, &text_node);

  if (enable_mtom == AXIS2_FALSE)
    axiom_text_set_optimize (text, env, AXIS2_FALSE);

  axiom_node_detach (node, env);
}
%}

%inline %{
axiom_node_t *
wsf_str_to_axiom_node(const axutil_env_t *env,
                       char               *container,
                       int                 size)
{
  axiom_xml_reader_t *xml_reader = axiom_xml_reader_create_for_memory(env, container, size, "utf-8", AXIS2_XML_PARSER_TYPE_BUFFER);
  if (xml_reader == NULL)
    return NULL;

  axiom_stax_builder_t *stax_builder = axiom_stax_builder_create(env, xml_reader);
  if (stax_builder == NULL)
    return NULL;

  axiom_document_t *document = axiom_stax_builder_get_document(stax_builder, env);
  if (document == NULL)
    return NULL;

  axiom_node_t *axiom_node = axiom_document_get_root_element(document, env);
  if (axiom_node == NULL)
    return NULL;

  axiom_document_build_all(document, env);

  axiom_stax_builder_free_self(stax_builder, env);

  return axiom_node;
}
%}

%inline %{
axis2_char_t *
wsf_axiom_node_to_str(const axutil_env_t *env,
                       axiom_node_t       *axiom_node)
{
  axiom_xml_writer_t *xml_writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_TRUE, 0, AXIS2_XML_PARSER_TYPE_BUFFER);
  if (xml_writer == NULL)
    return NULL;
    
  axiom_output_t *axiom_output = axiom_output_create(env, xml_writer);
  if (axiom_output == NULL)
    return NULL;
    
  axiom_node_serialize(axiom_node, env, axiom_output);
  
  axis2_char_t *buffer = (axis2_char_t *) axiom_xml_writer_get_xml (xml_writer, env);
  unsigned int buffer_length = axutil_strlen (buffer);
  
  axis2_char_t *new_buffer = AXIS2_MALLOC (env->allocator, sizeof (axis2_char_t) * (buffer_length + 1));
  memcpy (new_buffer, buffer, buffer_length);
  new_buffer[buffer_length] = '\0';
  
  axiom_output_free(axiom_output, env);
  
  return new_buffer;
}
%}

%inline %{
axis2_char_t *
wsf_axiom_data_handler_get_base64_content(axiom_data_handler_t *data_handler,
                                           const axutil_env_t   *env)
{
  axis2_char_t *content = NULL;
  int           content_length = 0;

  axiom_data_handler_read_from (data_handler, env, &content, &content_length);

  if (content == NULL)
    return NULL;

  int encoded_length = axutil_base64_encode_len(content_length);
  axis2_char_t *encoded_str = AXIS2_MALLOC(env->allocator, encoded_length + 2);
                
  if (encoded_str == NULL)
    return NULL;

  encoded_length = axutil_base64_encode(encoded_str, content, content_length);
  encoded_str[encoded_length] = '\0';

  return encoded_str;
}
%}

%inline %{
int
wsf_file_put_base64_content(const char *file_name,
                             const char *base64_content)
{
  int decoded_length = axutil_base64_decode_len(base64_content);
  
  char *decoded_content = (char*)malloc(decoded_length);
  if (decoded_content == NULL)
    return 0;

  decoded_length = axutil_base64_decode(decoded_content, base64_content);
  if (decoded_content == NULL)
    return 0;

  FILE *file = fopen(file_name, "w");
  if (file == NULL)
    return 0;

  fwrite(decoded_content, sizeof(char), decoded_length, file);
  fclose(file);

  free(decoded_content);

  return 1;
}
%}

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

%inline %{
axutil_property_t *
wsf_axutil_property_create_with_args(const axutil_env_t *env,
                                      axis2_scope_t       scope,
                                      axis2_bool_t        own_value,
                                      char               *value)
{
  return axutil_property_create_with_args(env, scope, own_value, 0, (void *)value);
}
%}

axutil_property_t *
axutil_property_create(const axutil_env_t *env);

%inline %{
axis2_status_t
wsf_axutil_property_set_value(axutil_property_t  *property,
                               const axutil_env_t *env,
                               char               *value)
{
  return axutil_property_set_value(property, env, (void *)value);
}
%}

%inline %{
int
wsf_axutil_strcmp(const axis2_char_t *s1,
                   const axis2_char_t *s2)
{
  return ((axutil_strcmp(s1, s2) == 0) ? AXIS2_TRUE : AXIS2_FALSE);
}
%}

%inline %{
axis2_status_t
wsf_axis2_options_set_property(axis2_options_t    *options,
                                const axutil_env_t *env,
                                const axis2_char_t *property_key,
                                axutil_property_t  *property)
{
  return axis2_options_set_property(options, env, property_key, (void *)property);
}
%}

axutil_string_t * 
axutil_string_create(const axutil_env_t *env,
                     const axis2_char_t *str);

%inline %{
char *
wsf_axutil_strdup(const axutil_env_t *env,
                   const char         *ptr)
{
  return (char *)axutil_strdup(env, (void *)ptr);
}
%}

axis2_char_t *
axutil_uuid_gen(const axutil_env_t *env);

axis2_bool_t 
axis2_svc_client_get_last_response_has_fault(const axis2_svc_client_t *svc_client,
                                             const axutil_env_t       *env);

%inline %{
axiom_node_t *
wsf_get_last_soap_fault_base_node(const axis2_svc_client_t *svc_client,
                                   const axutil_env_t       *env)
{
  axiom_soap_envelope_t *soap_envelope = axis2_svc_client_get_last_response_soap_envelope(svc_client, env);
  if (soap_envelope == NULL)
    return NULL;
    
  axiom_soap_body_t *soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
  if (soap_body == NULL)
    return NULL;
    
  axiom_soap_fault_t *soap_fault = axiom_soap_body_get_fault(soap_body, env);
  if (soap_fault == NULL)
    return NULL;

  return axiom_soap_fault_get_base_node(soap_fault, env);
}
%}

axis2_status_t 
axis2_options_set_xml_parser_reset(axis2_options_t    *options,
                                   const axutil_env_t *env,
                                   const axis2_bool_t  paser_reset_flag);

%inline %{
void
axis2_log_debug(axutil_env_t *env,
                axis2_char_t *str)
{
  AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, str);
}
%}

%inline %{
void
axis2_log_critical(axutil_env_t *env,
                   axis2_char_t *str)
{
  AXIS2_LOG_CRITICAL(env->log, AXIS2_LOG_SI, str);
}
%}

%inline %{
void
axis2_log_error(axutil_env_t *env,
                axis2_char_t *str)
{
  AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, str);
}
%}

axis2_status_t 
axis2_conf_add_param(axis2_conf_t * conf,
                     const axutil_env_t * env,
                     axutil_param_t * param);



axutil_param_t *
axutil_param_create(const axutil_env_t * env,
                    axis2_char_t * name,
                    void *value);

%inline %{
axutil_param_t *
wsf_axutil_security_param_create(const axutil_env_t* env,
                                  axis2_char_t * name,
                                  rampart_context_t* rampart_context)
{
   return axutil_param_create(env, name, (void *)rampart_context);
}
%}

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

rampart_context_t *
rampart_context_create(const axutil_env_t *env);

axis2_status_t
rampart_context_set_prv_key(rampart_context_t *rampart_context,
                                const axutil_env_t *env,
                                void *prv_key);

%inline %{
axis2_status_t
wsf_rampart_context_set_prv_key(rampart_context_t *rampart_context,
                                 const axutil_env_t *env,
                                 axis2_char_t *prv_key)
{
    return rampart_context_set_prv_key(rampart_context, env, (void *)prv_key);
}
%}

axis2_status_t 
rampart_context_set_prv_key_type(rampart_context_t *rampart_context,
                                     const axutil_env_t *env,
                                     axis2_key_type_t type);

%inline %{
axis2_status_t
wsf_rampart_context_set_certificate(rampart_context_t* rampart_context,
                                     const axutil_env_t *env,
                                     axis2_char_t *certificate)
{
   return rampart_context_set_certificate(rampart_context, env, (void *)certificate);
}
%}

axis2_status_t 
rampart_context_set_certificate(rampart_context_t *rampart_context,
                                    const axutil_env_t *env,
                                    void *certificate);

axis2_status_t 
rampart_context_set_certificate_type(rampart_context_t *rampart_context,
                                         const axutil_env_t *env,
                                         axis2_key_type_t type);
%inline %{
axis2_status_t
wsf_rampart_context_set_receiver_certificate(rampart_context_t *rampart_context,
            const axutil_env_t *env,
            axis2_char_t *receiver_certificate)
{
   return rampart_context_set_receiver_certificate(rampart_context, env, (void *)receiver_certificate);
}
%}

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

%typemap(in) char *(callback_t callback, void *user_data)
{
  $1 = wrap_callback;
  $2 = (void *)$input;
}


%inline %{
axis2_char_t *
wsf_password_callback_fn(const axutil_env_t *env,
                          const axis2_char_t *username,
                          void *ctx)
{
   if (mycallback != NULL)
   {
      axis2_char_t* password =  mycallback(myuserdata, username);
      AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf-ruby] ruby_password_callback_fn");
      AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, password);
      return password;
   }   
   else
      return NULL;
}
%}

%inline %{
axis2_status_t
wsf_rampart_context_set_pwcb_function(rampart_context_t *rampart_context,
                                      const axutil_env_t *env,
                                      callback_t callback,
                                      void *ctx)
{
   mycallback = callback;
   myuserdata = ctx;
   
   AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf-ruby] ruby_rampart_context_set_pwcb_function");
    
   return rampart_context_set_pwcb_function(rampart_context, env, wsf_password_callback_fn, (void *)NULL);
}
%}


