/* * Licensed to the Apache Software Foundation (ASF) under one or more
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
#include <stdlib.h> 
#include <axiom.h>
#include <axis2_util.h>
#include <axiom_soap.h>
#include <axis2_client.h>
#include <string.h>
#include <wchar.h>
#include <md5/md5.h>

axis2_status_t
launch(axis2_char_t *file_name);
axis2_char_t *
get_frob(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, 
        const axis2_char_t *flickr_key);

axis2_char_t *
get_auth_url(const axutil_env_t *env, 
		axis2_char_t *frob, axis2_char_t *perms, axis2_bool_t fresh);
	
axis2_char_t *
devide(axis2_char_t *in_string, 
		int no, const axis2_char_t *dev_string);


axis2_char_t *
get_auth(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, const axis2_char_t *frob);

axis2_status_t 
upload_image(const axutil_env_t *env, axis2_char_t *file_name, 
		axis2_char_t *auth_token);

axis2_char_t *
get_info(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *nsid);

axis2_char_t *
tags_get_related(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *tag);

axis2_char_t *
tags_get_hot_list(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key);

axis2_char_t *
get_list_user_popular(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *nsid);

axis2_char_t *
urls_get_user_photos(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *nsid);
		
axis2_char_t *
urls_get_user_profile(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *nsid);

axis2_char_t *
photosets_get_list(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *nsid);

axis2_char_t *
test_login(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *auth_token);

axis2_char_t *
get_upload_status(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *auth_token);



void print_invalid_om(const axutil_env_t *env, axiom_node_t *ret_node);
axis2_char_t * get_md5 (axis2_char_t *buffer, const axutil_env_t *env);


int main(int argc, char** argv)
{
	axis2_status_t status=AXIS2_FAILURE;
	axis2_char_t *file_name="/home/pini/car/DSC02990.JPG";

    if (argc > 1)
        file_name = argv[1];

	status = launch(file_name);
    return 0;
}

axis2_status_t
launch(axis2_char_t *file_name)
{    
	const axutil_env_t *env = NULL;
    const axis2_char_t *address = NULL;
    axis2_endpoint_ref_t* endpoint_ref = NULL;
    axis2_options_t *options = NULL;
    const axis2_char_t *client_home = NULL;
    axis2_svc_client_t* svc_client = NULL;

    const axis2_char_t *flickr_key = NULL;
    axis2_char_t *frob=NULL;
	axis2_char_t *auth_url = NULL;
	axis2_char_t *auth= NULL;
	axis2_char_t *auth_token = NULL;
	axis2_char_t *user_info= NULL;
	axis2_char_t *login_status= NULL;
	axis2_char_t *user_photos= NULL;
	axis2_char_t *user_profile= NULL;
	axis2_char_t *hot_list= NULL;
	/*axis2_char_t *related= NULL;*/
	axis2_char_t *list_user_popular= NULL;
	axis2_char_t *photoset_list= NULL;
	axis2_char_t *upload_status= NULL;
	axis2_char_t *nsid= NULL;
	/*axis2_char_t *tmpstr= NULL;*/
	char tmpchar;

    flickr_key = "4176cdc1597a07ea0961617b01ecef10";

    /* Set up the environment */
    env = axutil_env_create_all("flickr_client.log", AXIS2_LOG_LEVEL_TRACE);

    /* Set end point reference of flickr service */
    address = "http://api.flickr.com/services/soap/";

    printf("Using endpoint : %s\n", address);
    printf("\nInvoking with params %s and \n", flickr_key);

    /* Create EPR with given address */
    endpoint_ref = axis2_endpoint_ref_create(env, address);

    /* Setup options */
    options = axis2_options_create(env);
    axis2_options_set_to(options, env, endpoint_ref);

    /* Set up deploy folder.*/
    client_home = AXIS2_GETENV("WSFC_HOME");
    if (!client_home || !strcmp (client_home, ""))
        client_home = "../..";
    /* Create service client */
    svc_client = axis2_svc_client_create(env, client_home);
    if (!svc_client)
    {
        printf("Error creating service client, Please check WSFC_HOME again\n");
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
                " %d :: %s", env->error->error_number,
                AXIS2_ERROR_GET_MESSAGE(env->error));
		  return -1;
    }

    /* Set service client options */
    axis2_svc_client_set_options(svc_client, env, options);

    /* Build the SOAP request message payload using OM API.*/
    frob = get_frob(env, svc_client, flickr_key);
	auth_url = get_auth_url(env, frob, "write", 0);
	printf("\n\n\nauth url %s\n\n\n", auth_url);
	while (( tmpchar = getchar()) != 'y' );
	auth= get_auth(env, svc_client, flickr_key, frob);
	printf("\n\n\n%s\n\n\n", auth);
	nsid = devide(auth, 1, "\"");
	printf("\n\n\nnsid %s\n\n\n", nsid);

	auth_token = devide(auth, 4, "<>");
	printf("\n\n\nauth token %s\n\n\n", auth_token);
/*	tmpstr = auth;
	printf("\n\n\n%s\n\n\n", tmpstr);
	auth_token = devide(tmpstr, 4, "<>");
	tmpstr = auth;
	printf("\n\n\n%s\n\n\n", tmpstr);
	nsid = devide(tmpstr, 1, "\"");
	printf("\n\n%s\n\n", auth_token);
	printf("\n\n%s\n\n", nsid);*/
/*	nsid = devide(auth_token, 4, "\n");
	printf("\n\n%s\n\n", nsid);*/

	user_info=get_info(env, svc_client, flickr_key, nsid);
	upload_status=get_upload_status(env, svc_client, flickr_key, auth_token);
	photoset_list=photosets_get_list(env, svc_client, flickr_key, nsid);
	hot_list=tags_get_hot_list(env, svc_client, flickr_key);
	list_user_popular=get_list_user_popular(env, svc_client, flickr_key, nsid);
	login_status=test_login(env, svc_client, flickr_key, auth_token);
	user_photos=urls_get_user_photos(env, svc_client, flickr_key, nsid);
	user_profile=urls_get_user_profile(env, svc_client, flickr_key, nsid);
/*	related =tags_get_related(env, svc_client, flickr_key, tag);*/

	/*printf("\n\n\n%s\n\n\n", file_name);
	printf("\n\n\n%s\n\n\n", auth_token);
	upload_image(env, file_name, auth_token);*/

	return AXIS2_SUCCESS;

}

axis2_char_t *
get_frob(const axutil_env_t *env,
		axis2_svc_client_t *svc_client, 
        const axis2_char_t *flickr_key)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
	axiom_node_t *ret_node = NULL;
	axiom_node_t *child = NULL;
    axis2_char_t *buffer = NULL;
    axis2_char_t *frob = NULL;
    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    buffer = "flickr.auth.getFrob";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, "55617840965d736612eecc3795ddaabd", text_om_node);

    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    ret_node = axis2_svc_client_send_receive(svc_client, env, flickr_om_node);
    child = axiom_node_get_first_child(ret_node, env);
 
	buffer = axiom_node_to_string(child, env);
	frob= strtok( buffer, "<>");
	frob= strtok( NULL, "<>" );
	frob= strtok( NULL, "<>" );
    return frob;
}

axis2_char_t *
get_auth_url(const axutil_env_t *env, axis2_char_t *frob, axis2_char_t *perms, axis2_bool_t fresh)
{
	axis2_char_t *sign_str = NULL;
	axis2_char_t *md5_str = NULL;
	axis2_char_t *auth_url = NULL;
	sign_str=axutil_strcat(env,"d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10frob" , frob, "perms", perms, NULL);
	md5_str = get_md5(sign_str, env);
	if(fresh)
	auth_url =axutil_strcat(env, "http://flickr.com/services/auth/fresh?api_key=4176cdc1597a07ea0961617b01ecef10&perms=", perms, "&frob=", frob, "&api_sig=", md5_str, NULL);
	else
	auth_url =axutil_strcat(env, "http://flickr.com/services/auth?api_key=4176cdc1597a07ea0961617b01ecef10&perms=", perms, "&frob=", frob, "&api_sig=", md5_str, NULL);

	return auth_url;
	
}

axis2_char_t *
get_auth(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, const axis2_char_t *frob)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
    axiom_node_t *ret_node = NULL;
    axiom_node_t *child= NULL;
    axis2_char_t *buffer = NULL;
	axis2_char_t *sign_str = NULL;	
	axis2_char_t *api_sig= NULL;	
	axis2_char_t *auth_token= NULL;	

	sign_str=axutil_strcat(env,"d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10frob" , frob, "methodflickr.auth.getToken", NULL);
	api_sig = get_md5(sign_str, env);



    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    buffer = "flickr.auth.getToken";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "frob", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, frob, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, api_sig, text_om_node);

    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    ret_node = axis2_svc_client_send_receive(svc_client, env, flickr_om_node);
    child = axiom_node_get_first_child(ret_node, env);
/*	auth_token= strtok( axiom_node_to_string(child,env), "&lt;");
	auth_token = strtok( NULL, "<>" );
	auth_token= strtok( NULL, "<>" );
	auth_token = strtok( NULL, "<>" );
	auth_token= strtok( NULL, "<>" );*/
	auth_token = axiom_node_to_string(child, env);
	
    return auth_token;
}

axis2_char_t *
get_info(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *nsid)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_node_t* ret_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
    axis2_char_t *buffer = NULL;

	axis2_char_t *sign_str;
	axis2_char_t *user_info;
	axis2_char_t *md5_str;
	sign_str=axutil_strcat(env, "d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10methodflickr.people.getInfouser_id", nsid,  NULL);
	md5_str=get_md5(sign_str, env);


    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    buffer = "flickr.people.getInfo";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "user_id", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, nsid, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, md5_str, text_om_node);



    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    ret_node = axis2_svc_client_send_receive(svc_client, env, flickr_om_node);
	user_info= axiom_node_to_string(ret_node, env);
	printf("\n\n\n%s\n\n\n", user_info);
    return user_info;
}

void print_invalid_om(const axutil_env_t *env, axiom_node_t *ret_node)
{
    axis2_char_t *buffer = NULL;
    buffer = axiom_node_get_data_element(ret_node, env);
    printf("\nReceived OM as result : %s\n", buffer);
}

axis2_char_t * get_md5 (axis2_char_t *buffer, const axutil_env_t *env)
{
    axutil_md5_ctx_t * context;
    int i;
    unsigned char digest[16];
    axis2_char_t *str;
    context = axutil_md5_ctx_create(env);
    axutil_md5_update(context, env, buffer, strlen(buffer));
    axutil_md5_final(context, env, digest);
    axutil_md5_ctx_free(context, env);
	str = AXIS2_MALLOC(env->allocator, sizeof (digest)*2+1);
	str[33]='\0';
    for (i = 0; i < 16; i++)
    {
        sprintf (str+2*i, "%02x", digest[i]);
    }
	return str;

}


axis2_status_t upload_image(const axutil_env_t *env, axis2_char_t *file_name, 
		axis2_char_t *auth_token)
{		
	axis2_char_t *sign_str;
	axis2_char_t *md5_str;
	axis2_char_t *upload_str;
	sign_str=axutil_strcat(env, "d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10auth_token",auth_token, NULL);
	md5_str=get_md5(sign_str, env);
	upload_str=axutil_strcat(env, "curl -F api_key=4176cdc1597a07ea0961617b01ecef10 -F auth_token=", auth_token, " -F api_sig=", md5_str, " -F photo=@", file_name, " http://api.flickr.com/services/upload/", NULL);
	printf("\n\nuploading file %s\n\n", file_name);
	if ( system(upload_str)==1 )
	{
		printf("Upload Failed");
	}
    else 
	{
		printf("Done\n");
    }
	return AXIS2_SUCCESS;
}
		
axis2_char_t *devide(axis2_char_t *in_str, 
		int no, const axis2_char_t *dev_string)
{
	axis2_char_t *ret_string=NULL;
	int i;
	ret_string = strtok(in_str, dev_string);
	for(i = 0; i < no; i++)
		ret_string = strtok( NULL, dev_string );
/*	auth_token = strtok( NULL, "<>" );
	auth_token= strtok( NULL, "<>" );
	auth_token = strtok( NULL, "<>" );
	auth_token= strtok( NULL, "<>" );*/
	return ret_string;

}


axis2_char_t *
get_upload_status(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *auth_token)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_node_t* ret_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
    axis2_char_t *buffer = NULL;

	axis2_char_t *sign_str;
	axis2_char_t *upload_status;
	axis2_char_t *md5_str;
	sign_str=axutil_strcat(env, "d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10auth_token", auth_token, "methodflickr.people.getUploadStatus",  NULL);
	md5_str=get_md5(sign_str, env);


    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    buffer = "flickr.people.getUploadStatus";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "auth_token", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, auth_token, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, md5_str, text_om_node);



    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    ret_node = axis2_svc_client_send_receive(svc_client, env, flickr_om_node);
	upload_status= axiom_node_to_string(ret_node, env);
	printf("\n\n\n%s\n\n\n", upload_status);
    return upload_status;
}

axis2_char_t *
photosets_get_list(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *nsid)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_node_t* ret_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
    axis2_char_t *buffer = NULL;

	axis2_char_t *sign_str;
	axis2_char_t *photosets_get_list;
	axis2_char_t *md5_str;
	sign_str=axutil_strcat(env, "d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10methodflickr.photosets.getListuser_id", nsid,  NULL);
	md5_str=get_md5(sign_str, env);


    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    buffer = "flickr.photosets.getList";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "user_id", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, nsid, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, md5_str, text_om_node);



    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    ret_node = axis2_svc_client_send_receive(svc_client, env, flickr_om_node);
	photosets_get_list = axiom_node_to_string(ret_node, env);
	printf("\n\n\n%s\n\n\n", photosets_get_list);
    return photosets_get_list;
}

axis2_char_t *
tags_get_hot_list(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_node_t* ret_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
    axis2_char_t *buffer = NULL;

	axis2_char_t *sign_str;
	axis2_char_t *hot_list;
	axis2_char_t *md5_str;
	sign_str=axutil_strcat(env, "d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10methodflickr.tags.getHotList", NULL);
	md5_str=get_md5(sign_str, env);


    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    buffer = "flickr.tags.getHotList";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, md5_str, text_om_node);



    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    ret_node = axis2_svc_client_send_receive(svc_client, env, flickr_om_node);
	hot_list= axiom_node_to_string(ret_node, env);
	printf("\n\n\n%s\n\n\n", hot_list);
    return hot_list;
}

axis2_char_t *
get_list_user_popular(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *nsid)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_node_t* ret_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
    axis2_char_t *buffer = NULL;

	axis2_char_t *sign_str;
	axis2_char_t *list_user_popular;
	axis2_char_t *md5_str;
	sign_str=axutil_strcat(env, "d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10methodflickr.tags.getListUserPopularuser_id", nsid, NULL);
	md5_str=get_md5(sign_str, env);


    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    buffer = "flickr.tags.getListUserPopular";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "user_id", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, nsid, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, md5_str, text_om_node);



    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    ret_node = axis2_svc_client_send_receive(svc_client, env, flickr_om_node);
	list_user_popular= axiom_node_to_string(ret_node, env);
	printf("\n\n\n%s\n\n\n", list_user_popular);
    return list_user_popular;
}

axis2_char_t *
tags_get_related(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *tag)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_node_t* ret_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
    axis2_char_t *buffer = NULL;

	axis2_char_t *sign_str;
	axis2_char_t *related;
	axis2_char_t *md5_str;
	sign_str=axutil_strcat(env, "d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10methodflickr.tags.getRelatedtag", tag, NULL);
	md5_str=get_md5(sign_str, env);


    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    buffer = "flickr.tags.getRelated";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "tag", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, tag, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, md5_str, text_om_node);



    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    ret_node = axis2_svc_client_send_receive(svc_client, env, flickr_om_node);
	related= axiom_node_to_string(ret_node, env);
	printf("\n\n\n%s\n\n\n", related);
    return related;
}

axis2_char_t *
test_login(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *auth_token)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_node_t* ret_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
    axis2_char_t *buffer = NULL;

	axis2_char_t *sign_str;
	axis2_char_t *login_status;
	axis2_char_t *md5_str;
	sign_str=axutil_strcat(env, "d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10auth_token", auth_token, "methodflickr.test.login",  NULL);
	md5_str=get_md5(sign_str, env);


    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    buffer = "flickr.test.login";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "auth_token", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, auth_token, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, md5_str, text_om_node);



    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    ret_node = axis2_svc_client_send_receive(svc_client, env, flickr_om_node);
	login_status= axiom_node_to_string(ret_node, env);
	printf("\n\n\n%s\n\n\n", login_status);
    return login_status;
}

axis2_char_t *
urls_get_user_photos(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *nsid)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_node_t* ret_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
    axis2_char_t *buffer = NULL;

	axis2_char_t *sign_str;
	axis2_char_t *user_photos;
	axis2_char_t *md5_str;
	sign_str=axutil_strcat(env, "d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10methodflickr.urls.getUserPhotosuser_id", nsid,  NULL);
	md5_str=get_md5(sign_str, env);


    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    buffer = "flickr.urls.getUserPhotos";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "user_id", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, nsid, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, md5_str, text_om_node);



    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    ret_node = axis2_svc_client_send_receive(svc_client, env, flickr_om_node);
	user_photos= axiom_node_to_string(ret_node, env);
	printf("\n\n\n%s\n\n\n", user_photos);
    return user_photos;
}

axis2_char_t *
urls_get_user_profile(const axutil_env_t *env,
        axis2_svc_client_t *svc_client, const axis2_char_t *flickr_key, axis2_char_t *nsid)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_node_t* ret_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
    axis2_char_t *buffer = NULL;

	axis2_char_t *sign_str;
	axis2_char_t *user_profile;
	axis2_char_t *md5_str;
	sign_str=axutil_strcat(env, "d158127cfb15da0fapi_key4176cdc1597a07ea0961617b01ecef10methodflickr.urls.getUserProfileuser_id", nsid,  NULL);
	md5_str=get_md5(sign_str, env);


    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    buffer = "flickr.urls.getUserProfile";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "user_id", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, nsid, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, md5_str, text_om_node);



    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    ret_node = axis2_svc_client_send_receive(svc_client, env, flickr_om_node);
	user_profile= axiom_node_to_string(ret_node, env);
	printf("\n\n\n%s\n\n\n", user_profile);
    return user_profile;
}


