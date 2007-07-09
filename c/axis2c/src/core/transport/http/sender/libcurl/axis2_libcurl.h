#ifndef AXIS2_LIBCURL_H
#define AXIS2_LIBCURL_H
#include <curl/curl.h>
#include <stdio.h>
#include <string.h>
#include <axis2_http_sender.h>
#include <axutil_string.h>
#include <axutil_types.h>
#include <axutil_generic_obj.h>
#include <axis2_const.h>
#include <axis2_util.h>
#include <axiom.h>

axis2_status_t AXIS2_CALL
axis2_libcurl_send (
    axiom_output_t *om_output,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
	axiom_soap_envelope_t *out,
    const axis2_char_t *str_url,
    const axis2_char_t *soap_action);


#endif	/* AXIS2_LIBCURL_H */
