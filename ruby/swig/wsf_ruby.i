%{
typedef char *(*callback_t) (void *user_data, const char *other_data);

callback_t mycallback = NULL;
void* myuserdata = NULL;
%}

%inline %{
char *
wrap_callback(void *user_data, const char *other_data)
{
  VALUE proc = (VALUE)user_data;
  VALUE password = rb_funcall(proc, rb_intern("call"), 1, rb_str_new2(other_data));
  return RSTRING(password)->ptr;
}
%}

%inline %{
axis2_status_t
wsf_set_security_token_data_to_rampart_context(const axutil_env_t * env,
                                                rampart_context_t *rampart_context,
                                                VALUE security_token)
{
   char* prv_key = NULL;
   VALUE private_key = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("private_key"));
   if (!NIL_P(private_key) && (TYPE(private_key) == T_STRING))
   {
        prv_key = RSTRING(private_key)->ptr;
 
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf-ruby] checkcheck ");
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, prv_key);

        if ((prv_key != NULL) && (rampart_context_set_prv_key(rampart_context, env, (void *)prv_key) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pvt key  ");
   
        if ((prv_key != NULL) && (rampart_context_set_prv_key_type(rampart_context, env, AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pvt key format ");
   }

   char* certificate = NULL;
   VALUE cert = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("certificate"));
   if (!NIL_P(cert) && (TYPE(cert) == T_STRING))
   {
        certificate = RSTRING(cert)->ptr;

        if ((certificate != NULL) && (rampart_context_set_certificate(rampart_context, env, (void *)certificate) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pub key  ");

        if ((certificate != NULL) && (rampart_context_set_certificate_type(rampart_context, env, AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pub key type ");
   }

   char* receiver_certificate = NULL;
   VALUE rec_cert = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("receiver_certificate"));
   if (!NIL_P(rec_cert) && (TYPE(rec_cert) == T_STRING))
   {
        receiver_certificate = RSTRING(rec_cert)->ptr;

        if ((receiver_certificate != NULL) && (rampart_context_set_receiver_certificate(rampart_context, env, receiver_certificate) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting receiver pub key");

        if ((receiver_certificate != NULL) && (rampart_context_set_receiver_certificate_type(rampart_context, env, AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS)) 
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting receiver pub key format");
   }

   char* username = NULL;
   VALUE usr = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("user"));
   if (!NIL_P(usr) && (TYPE(usr) == T_STRING))
   {
        username = RSTRING(usr)->ptr;

        if ((username != NULL) && (rampart_context_set_user(rampart_context, env, username) == AXIS2_SUCCESS)) 
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting username ");
   }

   char* password = NULL;
   VALUE pwd = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("password"));
   if (!NIL_P(pwd) && (TYPE(pwd) == T_STRING))
   {
        password = RSTRING(pwd)->ptr;

        if ((password != NULL) && (rampart_context_set_password(rampart_context, env, password) == AXIS2_SUCCESS)) 
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting password ");
   }

   char* password_type = NULL;
   VALUE pwd_type = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("password_type"));
   if (!NIL_P(pwd_type) && (TYPE(pwd_type) == T_STRING))
   {
        password_type = RSTRING(pwd_type)->ptr;

        if ((password_type != NULL) && (rampart_context_set_password_type(rampart_context, env, password_type) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting password type ");
   }

   int ttl = -1;
   VALUE time_to_live = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("ttl"));
   if (!NIL_P(time_to_live) && (TYPE(time_to_live) == T_FIXNUM))
   {
        ttl = FIX2INT(time_to_live);

        if (rampart_context_set_ttl(rampart_context, env, ttl) == AXIS2_SUCCESS) 
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy) setting ttl");
   }
   
   char* callback_function_name = NULL;
   VALUE callback_fn =  rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("password_callback"));
   if (!NIL_P(callback_fn) && (TYPE(callback_fn) == T_STRING))
   {
        callback_function_name = RSTRING(callback_fn)->ptr;
          
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_ruby] password_callback function name received; ");
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, callback_function_name);
       
        //if ((password_type != NULL) && (rampart_context_set_password_type(rampart_context, env, password_type) == AXIS2_SUCCESS))
        //        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting password type ");
   }

   /*#option = sec_token.option("password_callback")
    #if not option.nil?
    #   if (WSFC::ruby_rampart_context_set_pwcb_function(rampart_context, @env, nil, option) == WSFC::AXIS2_SUCCESS) then
    #      WSFC::axis2_log_debug(@env, "[wsf_sec_policy] setting callback function")
    #   end
    #endn */

   return AXIS2_SUCCESS;

}
%}
