#include "StdAfx.h"
#include "md5.h"
#include "WMParam.h"
#include "FlickrClient.h"

CFlickrClient::CFlickrClient (void)
{
	p_PhotoSetInfoByName = NULL;
	p_UpdateUploadStatusThread = NULL;
	p_UploadImageThread = NULL;
	p_CreateUserThread = NULL;
	p_GetFrobThread = NULL;
	p_RestoreUserThread = NULL;
}


CFlickrClient::~CFlickrClient (void)
{
	if (p_UpdateUploadStatusThread != NULL)
		delete p_UpdateUploadStatusThread;

	if (p_UploadImageThread != NULL)
		delete p_UploadImageThread;
	
	if (p_CreateUserThread != NULL)
		delete p_CreateUserThread;
	
	if (p_GetFrobThread != NULL)
		delete p_GetFrobThread;
	
	if (p_RestoreUserThread != NULL)
		delete p_RestoreUserThread;
}


void CFlickrClient::SetPhotoSetInfo (CPhotoSetInfo::PhotoSetInfoByName_map_t* _pPhotoSetInfoByName)
{
	p_PhotoSetInfoByName = _pPhotoSetInfoByName;
}


axis2_char_t* get_md5 (axis2_char_t* buffer, const axutil_env_t* env)
{
    axutil_md5_ctx_t * context;
    int i;
    unsigned char digest[16];
    axis2_char_t *str;
    
	context = axutil_md5_ctx_create(env);
    axutil_md5_update(context, env, buffer, strlen(buffer));
    axutil_md5_final(context, env, digest);
    axutil_md5_ctx_free(context, env);
	
	str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (digest)*2+1);
	str[33]='\0';
    
	for (i = 0; i < 16; i++)
    {
        sprintf (str+2*i, "%02x", digest[i]);
    }
	
	return str;
}


bool CheckToken (RestoreUserThreadInfo* _pThreadInfo)
{	
	axis2_char_t* api_sig_str= NULL;
	axis2_char_t* api_sig = NULL;

	axiom_namespace_t* ns0 = NULL;
	axiom_node_t*      flickr_om_node = NULL;
	axiom_element_t*   flickr_om_ele = NULL;
	axiom_element_t*   text_om_ele = NULL;
	axiom_node_t*      text_om_node = NULL;
	axiom_node_t*      ret_node = NULL;

	// Create API Key String Buffer
	int iSize = _pThreadInfo->s_APIKey.GetLength ();
	char* zAPIKey = new char [iSize + 1];
	memset (zAPIKey, 0, iSize + 1);
	wcstombs (zAPIKey, _pThreadInfo->s_APIKey, iSize + 1);

	// Create Token String Buffer
	iSize = _pThreadInfo->s_Token.GetLength ();
	char* zToken = new char [iSize + 1];
	memset (zToken, 0, iSize + 1);
	wcstombs (zToken, _pThreadInfo->s_Token, iSize + 1);

	// Get API Signature
	api_sig_str = axutil_strcat (_pThreadInfo->env, "d158127cfb15da0f",
							     "api_key", zAPIKey,
							     "auth_token", zToken,
								 "method", "flickr.auth.checkToken", NULL);
	api_sig = get_md5 (api_sig_str, _pThreadInfo->env);

	// Create Payload
	ns0 = axiom_namespace_create (_pThreadInfo->env, "urn:flickr", "x");
    flickr_om_ele = axiom_element_create (_pThreadInfo->env, NULL, "FlickrRequest", ns0, &flickr_om_node);

	text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zAPIKey, text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "auth_token", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zToken, text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, "flickr.auth.checkToken", text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, api_sig, text_om_node);

	// Get Response
	ret_node = axis2_svc_client_send_receive (_pThreadInfo->svc_client, _pThreadInfo->env, flickr_om_node);
	
	delete [] zAPIKey;
	delete [] zToken;
	
	if (NULL == ret_node)
		return false;

	if (axis2_svc_client_get_last_response_has_fault (_pThreadInfo->svc_client, _pThreadInfo->env) == AXIS2_TRUE)
		return false;
	
	return true;
}


CString GetUserPhotosURL (RestoreUserThreadInfo* _pThreadInfo)
{
	axis2_char_t* api_sig_str= NULL;
	axis2_char_t* api_sig = NULL;

	axiom_namespace_t* ns0 = NULL;
	axiom_node_t*      flickr_om_node = NULL;
	axiom_element_t*   flickr_om_ele = NULL;
	axiom_element_t*   text_om_ele = NULL;
	axiom_node_t*      text_om_node = NULL;
	axiom_node_t*      ret_node = NULL;

	// Create API Key String Buffer
	int iSize = _pThreadInfo->s_APIKey.GetLength ();
	char* zAPIKey = new char [iSize + 1];
	memset (zAPIKey, 0, iSize + 1);
	wcstombs (zAPIKey, _pThreadInfo->s_APIKey, iSize + 1);
	
	// Create NSID String Buffer
	iSize = _pThreadInfo->s_NSID.GetLength ();
	char* zNSID = new char [iSize + 1];
	memset (zNSID, 0, iSize + 1);
	wcstombs (zNSID, _pThreadInfo->s_NSID, iSize + 1);

	// Get API Signature
	api_sig_str = axutil_strcat (_pThreadInfo->env, "d158127cfb15da0f",
							     "api_key", zAPIKey,
							     "method", "flickr.urls.getUserPhotos",
								 "user_id", zNSID, NULL);
	api_sig = get_md5 (api_sig_str, _pThreadInfo->env);

	// Create Payload
    ns0 = axiom_namespace_create (_pThreadInfo->env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create (_pThreadInfo->env, NULL, "FlickrRequest", ns0, &flickr_om_node);

	text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zAPIKey, text_om_node);
	
	text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, "flickr.urls.getUserPhotos", text_om_node);    

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "user_id", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zNSID, text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, api_sig, text_om_node);

	// Get Response
	ret_node = axis2_svc_client_send_receive (_pThreadInfo->svc_client, _pThreadInfo->env, flickr_om_node);
	
	delete [] zAPIKey;
	delete [] zNSID;

	if (NULL == ret_node)
		return "";

	if (axis2_svc_client_get_last_response_has_fault (_pThreadInfo->svc_client, _pThreadInfo->env) == AXIS2_TRUE)
		return "";

	// Get URL
	CString sPayload = axiom_node_to_string (ret_node, _pThreadInfo->env);
	
	int iStartIndex = sPayload.Find (_T("url=&quot;"));
	if (-1 == iStartIndex)
		return "";

	sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 10)); // 10 -> url=&quot;

	iStartIndex = sPayload.Find (_T("&quot;"));
	if (-1 == iStartIndex)
		return "";
	
	return sPayload.Left (iStartIndex);
}


CString GetUserProfileURL (RestoreUserThreadInfo* _pThreadInfo)
{
	axis2_char_t* api_sig_str= NULL;
	axis2_char_t* api_sig = NULL;

	axiom_namespace_t* ns0 = NULL;
	axiom_node_t*      flickr_om_node = NULL;
	axiom_element_t*   flickr_om_ele = NULL;
	axiom_element_t*   text_om_ele = NULL;
	axiom_node_t*      text_om_node = NULL;
	axiom_node_t*      ret_node = NULL;

	// Create API Key String Buffer
	int iSize = _pThreadInfo->s_APIKey.GetLength ();
	char* zAPIKey = new char [iSize + 1];
	memset (zAPIKey, 0, iSize + 1);
	wcstombs (zAPIKey, _pThreadInfo->s_APIKey, iSize + 1);

	// Create NSID String Buffer
	iSize = _pThreadInfo->s_NSID.GetLength ();
	char* zNSID = new char [iSize + 1];
	memset (zNSID, 0, iSize + 1);
	wcstombs (zNSID, _pThreadInfo->s_NSID, iSize + 1);

	// Get API Signature
	api_sig_str = axutil_strcat (_pThreadInfo->env, "d158127cfb15da0f",
							     "api_key", zAPIKey,
							     "method", "flickr.urls.getUserProfile",
								 "user_id", zNSID, NULL);
	api_sig = get_md5 (api_sig_str, _pThreadInfo->env);

	// Create Payload
    ns0 = axiom_namespace_create (_pThreadInfo->env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create (_pThreadInfo->env, NULL, "FlickrRequest", ns0, &flickr_om_node);

	text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zAPIKey, text_om_node);
	
	text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, "flickr.urls.getUserProfile", text_om_node);    

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "user_id", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zNSID, text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, api_sig, text_om_node);

    // Get Response
	ret_node = axis2_svc_client_send_receive (_pThreadInfo->svc_client, _pThreadInfo->env, flickr_om_node);
	
	delete [] zAPIKey;
	delete [] zNSID;

	if (NULL == ret_node)
		return "";

	if (axis2_svc_client_get_last_response_has_fault (_pThreadInfo->svc_client, _pThreadInfo->env) == AXIS2_TRUE)
		return "";

	// Get URL
	CString sPayload = axiom_node_to_string (ret_node, _pThreadInfo->env);
	
	int iStartIndex = sPayload.Find (_T("url=&quot;"));
	if (-1 == iStartIndex)
		return "";

	sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 10)); // 10 -> url=&quot;

	iStartIndex = sPayload.Find (_T("&quot;"));
	if (-1 == iStartIndex)
		return "";
	
	return sPayload.Left (iStartIndex);
}


CUploadStatus* GetUploadStatus (RestoreUserThreadInfo* _pThreadInfo)
{
	axis2_char_t* api_sig_str= NULL;
	axis2_char_t* api_sig = NULL;

	axiom_namespace_t* ns0 = NULL;
	axiom_node_t*      flickr_om_node = NULL;
	axiom_element_t*   flickr_om_ele = NULL;
	axiom_element_t*   text_om_ele = NULL;
	axiom_node_t*      text_om_node = NULL;
	axiom_node_t*      ret_node = NULL;

	// Create API Key String Buffer
	int iSize = _pThreadInfo->s_APIKey.GetLength ();
	char* zAPIKey = new char [iSize + 1];
	memset (zAPIKey, 0, iSize + 1);
	wcstombs (zAPIKey, _pThreadInfo->s_APIKey, iSize + 1);

	// Create Token String Buffer
	iSize = _pThreadInfo->s_Token.GetLength ();
	char* zToken = new char [iSize + 1];
	memset (zToken, 0, iSize + 1);
	wcstombs (zToken, _pThreadInfo->s_Token, iSize + 1);

	// Get API Signature
	api_sig_str = axutil_strcat (_pThreadInfo->env, "d158127cfb15da0f",
							     "api_key", zAPIKey,
							     "auth_token", zToken,
								 "method", "flickr.people.getUploadStatus", NULL);
	api_sig = get_md5 (api_sig_str, _pThreadInfo->env);

	// Create Payload
	ns0 = axiom_namespace_create (_pThreadInfo->env, "urn:flickr", "x");
    flickr_om_ele = axiom_element_create (_pThreadInfo->env, NULL, "FlickrRequest", ns0, &flickr_om_node);

	text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zAPIKey, text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "auth_token", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zToken, text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, "flickr.people.getUploadStatus", text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, api_sig, text_om_node);

	// Get Response
	ret_node = axis2_svc_client_send_receive (_pThreadInfo->svc_client, _pThreadInfo->env, flickr_om_node);
	
	delete [] zAPIKey;
	delete [] zToken;

	if (NULL == ret_node)
		return NULL;

	if (axis2_svc_client_get_last_response_has_fault (_pThreadInfo->svc_client, _pThreadInfo->env) == AXIS2_TRUE)
	{
		/*axiom_soap_envelope_t *soap_envelope = NULL;
        axiom_soap_body_t *soap_body = NULL;
        axiom_soap_fault_t *soap_fault = NULL;

            soap_envelope =
            axis2_svc_client_get_last_response_soap_envelope(_pThreadInfo->svc_client, _pThreadInfo->env);
        if (soap_envelope)
            soap_body = axiom_soap_envelope_get_body(soap_envelope, _pThreadInfo->env);
        if (soap_body)
            soap_fault = axiom_soap_body_get_fault(soap_body, _pThreadInfo->env);
        if (soap_fault)
        {
              AfxMessageBox (CString (axiom_node_to_string(axiom_soap_fault_get_base_node
                                        (soap_fault, _pThreadInfo->env), _pThreadInfo->env)));

			  AfxMessageBox (CString (axiom_node_to_string(ret_node, _pThreadInfo->env)));
        }*/

		return NULL;
	}

	// Get Upload Status
	CString sPayload = axiom_node_to_string (ret_node, _pThreadInfo->env);

	bool bPro = false;
	CString sAvailableQuota = "";
	int iRemainingSetCount = 0;

	// Get Pro
	int iStartIndex = sPayload.Find (_T("ispro=&quot;"));
	if (-1 == iStartIndex)
		return NULL;

	sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 12)); // 12 -> ispro=&quot;

	iStartIndex = sPayload.Find (_T("&quot;"));
	if (-1 == iStartIndex)
		return NULL;
	
	CString sPro = sPayload.Left (iStartIndex);
	bPro = (sPro == "1") ? true : false;

	// Get Available Quota
	iStartIndex = sPayload.Find (_T("remainingkb=&quot;"));
	if (-1 == iStartIndex)
		return NULL;

	sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 18)); // 18 -> remainingkb=&quot;;

	iStartIndex = sPayload.Find (_T("&quot;"));
	if (-1 == iStartIndex)
		return NULL;
	
	CString sAvailableQuotaKB = sPayload.Left (iStartIndex);

	double dAvailableQuotaKB;
	_stscanf (sAvailableQuotaKB, _T("%lf"), &dAvailableQuotaKB);
	double dAvailableQuotaMB = dAvailableQuotaKB / 1024;

	(dAvailableQuotaMB >= 1) ? sAvailableQuota.Format (_T("%.2f MB"), dAvailableQuotaMB) : sAvailableQuota.Format (_T("%.2f KB"), dAvailableQuotaKB);

	// Get Remaining Set Count
	iStartIndex = sPayload.Find (_T("&lt;sets"));
	if (-1 == iStartIndex)
		return NULL;

	sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 8)); // 8 -> &lt;sets

	iStartIndex = sPayload.Find (_T("remaining=&quot;"));
	if (-1 == iStartIndex)
		return NULL;

	sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 16)); // 16 -> remaining=&quot;

	iStartIndex = sPayload.Find (_T("&quot;"));
	if (-1 == iStartIndex)
		return NULL;
	
	CString sRemainingSetCount = sPayload.Left (iStartIndex);
	if (false == bPro)
		_stscanf (sRemainingSetCount, _T("%d"), &iRemainingSetCount);

	return (new CUploadStatus (sAvailableQuota, iRemainingSetCount, bPro));
}


CPhotoSetInfo::PhotoSetInfo_lst_t GetPhotoSetInfo (RestoreUserThreadInfo* _pThreadInfo)
{
	CPhotoSetInfo::PhotoSetInfo_lst_t lstPhotoInfo;

	axis2_char_t* api_sig_str= NULL;
	axis2_char_t* api_sig = NULL;

	axiom_namespace_t* ns0 = NULL;
	axiom_node_t*      flickr_om_node = NULL;
	axiom_element_t*   flickr_om_ele = NULL;
	axiom_element_t*   text_om_ele = NULL;
	axiom_node_t*      text_om_node = NULL;
	axiom_node_t*      ret_node = NULL;

	// Create API Key String Buffer
	int iSize = _pThreadInfo->s_APIKey.GetLength ();
	char* zAPIKey = new char [iSize + 1];
	memset (zAPIKey, 0, iSize + 1);
	wcstombs (zAPIKey, _pThreadInfo->s_APIKey, iSize + 1);

	// Create NSID String Buffer
	iSize = _pThreadInfo->s_NSID.GetLength ();
	char* zNSID = new char [iSize + 1];
	memset (zNSID, 0, iSize + 1);
	wcstombs (zNSID, _pThreadInfo->s_NSID, iSize + 1);

	// Get API Signature
	api_sig_str = axutil_strcat (_pThreadInfo->env, "d158127cfb15da0f",
							     "api_key", zAPIKey,
							     "method", "flickr.photosets.getList",
								 "user_id", zNSID, NULL);
	api_sig = get_md5 (api_sig_str, _pThreadInfo->env);

	// Create Payload
    ns0 = axiom_namespace_create (_pThreadInfo->env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create (_pThreadInfo->env, NULL, "FlickrRequest", ns0, &flickr_om_node);

	text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zAPIKey, text_om_node);
	
	text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, "flickr.photosets.getList", text_om_node);    

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "user_id", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zNSID, text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, api_sig, text_om_node);

    // Get Response
	ret_node = axis2_svc_client_send_receive (_pThreadInfo->svc_client, _pThreadInfo->env, flickr_om_node);
	
	delete [] zAPIKey;
	delete [] zNSID;

	if (NULL == ret_node)
		return lstPhotoInfo;

	if (axis2_svc_client_get_last_response_has_fault (_pThreadInfo->svc_client, _pThreadInfo->env) == AXIS2_TRUE)
		return lstPhotoInfo;

	// Get URL
	CString sPayload = axiom_node_to_string (ret_node, _pThreadInfo->env);

	/*CFile a = CFile (_T("C:\\aa.txt"), CFile::modeCreate | CFile::modeWrite);
	iSize = s.GetLength ();
	char* z = new char [iSize + 1];
	memset (z, 0, iSize + 1);
	wcstombs (z, s, iSize + 1);
	a.Write (z, iSize);*/

	int iPhotoSetStartIndex = sPayload.Find (_T("&lt;photoset"));
	while (-1 != iPhotoSetStartIndex)
	{
		sPayload = sPayload.Right (sPayload.GetLength () - (iPhotoSetStartIndex + 12)); // 12 -> &lt;photoset

		int iStartIndex = sPayload.Find (_T("id=&quot;"));
		if (-1 != iStartIndex)
		{
			CString	sID = "";
			CString sName = "";
			
			// ID
			sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 9)); // 9 -> id=&quot;

			iStartIndex = sPayload.Find (_T("&quot;"));
			if (-1 != iStartIndex)
				sID = sPayload.Left (iStartIndex);

			// Name
			iStartIndex = sPayload.Find (_T("&lt;title&gt;"));
			if (-1 != iStartIndex)
			{
				sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 13)); // 13 -> &lt;title&gt;

				iStartIndex = sPayload.Find (_T("&lt;/title&gt;"));
				if (-1 != iStartIndex)
					sName = sPayload.Left (iStartIndex);
			}
			
			if ((sID != "") && (sName != ""))
				lstPhotoInfo.push_back (new CPhotoSetInfo (sName, "", sID));
		}

		iPhotoSetStartIndex = sPayload.Find (_T("&lt;photoset"));
	}
	
	return lstPhotoInfo;
}


UINT RestoreUserThreadFunc (LPVOID lParam)
{
	RestoreUserThreadInfo* pThreadInfo = (RestoreUserThreadInfo*)lParam;
	if (NULL == pThreadInfo)
		return 0;

	CWMParam* pParam = new CWMParam;
	pParam->b_Success = false;

	// Create Service Client
	// Set up the Environment
	axutil_env_t* env = axutil_env_create_all ("FlickrUploader-RestoreUser.log", AXIS2_LOG_LEVEL_TRACE);
	if (NULL == env)
	{
		AfxMessageBox (_T("Failed to create WSF environment !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_RESTORE_USER_DONE, (WPARAM)pParam, 0);
		return 0;
	}

	pThreadInfo->env = env;

	// Get up Deploy Folder
	int iSize = pThreadInfo->s_WSFCHome.GetLength ();
	char* client_home = new char [iSize + 1];
	memset (client_home, 0, iSize + 1);
	wcstombs (client_home, pThreadInfo->s_WSFCHome, iSize + 1);

    /*const axis2_char_t* client_home = AXIS2_GETENV ("WSFC_HOME");
    if (!client_home || !strcmp (client_home, ""))
    {
		AfxMessageBox (_T("Failed to read WSFC_HOME !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_RESTORE_USER_DONE, (WPARAM)pParam, 0);
		return 0;
	}*/

	// Create Client
    axis2_svc_client_t*	svc_client = axis2_svc_client_create (env, client_home);
	delete [] client_home;
    if (!svc_client)
    {
        AfxMessageBox (_T("Error while creating service client, Please check WSFC_HOME again !!!"), MB_OK | MB_ICONEXCLAMATION);
		AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code: %d :: %s", env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_RESTORE_USER_DONE, (WPARAM)pParam, 0);
		return 0;
    }

	pThreadInfo->svc_client = svc_client;

	// Set Options
	axis2_options_t* client_options = axis2_options_create (env);

	iSize = pThreadInfo->s_EndpointRef.GetLength ();
	char* endpoint_ref_str = new char [iSize + 1];
	memset (endpoint_ref_str, 0, iSize + 1);
	wcstombs (endpoint_ref_str, pThreadInfo->s_EndpointRef, iSize + 1);

	axis2_endpoint_ref_t* endpoint_ref = axis2_endpoint_ref_create (env, endpoint_ref_str);
	axis2_options_set_to (client_options, env, endpoint_ref);

	delete [] endpoint_ref_str;
	
	axis2_options_set_xml_parser_reset (client_options, env, AXIS2_FALSE);
    
    axis2_svc_client_set_options (svc_client, env, client_options);

	// Restore User Profile
	(pThreadInfo->p_MessageReceiver)->PostMessage (WM_WAIT_ANIMATION_MESSAGE, (WPARAM)(new CString (_T("Checking Token ..."))), 0);

	if (true == CheckToken (pThreadInfo)) // The Saved Profile is Valid
	{
		// Get Photos URL
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_WAIT_ANIMATION_MESSAGE, (WPARAM)(new CString (_T("Retrieving Photos URL ..."))), 0);
		pParam->s_PhotosURL = GetUserPhotosURL (pThreadInfo);
		
		// Get Profile URL
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_WAIT_ANIMATION_MESSAGE, (WPARAM)(new CString (_T("Retrieving Profile URL ..."))), 0);
		pParam->s_ProfileURL = GetUserProfileURL (pThreadInfo);
		
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_WAIT_ANIMATION_MESSAGE, (WPARAM)(new CString (_T("Retrieving Upload Status ..."))), 0);

		CUploadStatus* pUploadStatus = GetUploadStatus (pThreadInfo);
		if (NULL != pUploadStatus)
		{
			pParam->s_AvailableQuota = pUploadStatus->s_AvailableQuota;
			pParam->i_RemainingSetCount = pUploadStatus->i_RemainingSetCount;
			pParam->b_Pro = pUploadStatus->b_Pro;

			delete pUploadStatus;
		}

		// Get Photo Set Names
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_WAIT_ANIMATION_MESSAGE, (WPARAM)(new CString (_T("Retrieving Photo Set Info ..."))), 0);
		pParam->lst_PhotoSetInfo = GetPhotoSetInfo (pThreadInfo);
		
		pParam->b_Success = true;
	}
	
	(pThreadInfo->p_MessageReceiver)->PostMessage (WM_RESTORE_USER_DONE, (WPARAM)pParam, 0); // pParam->b_Success == false if the profile is not saved

	delete pThreadInfo;

	return 1;
}


void CFlickrClient::RestoreUser (CString _sWSFCHome, CString _sToken, CString _sNSID, CWnd* _pMessageReceiver)
{
	RestoreUserThreadInfo* pThreadInfo = new RestoreUserThreadInfo;

	pThreadInfo->p_MessageReceiver = _pMessageReceiver;
	pThreadInfo->s_WSFCHome = _sWSFCHome;
	pThreadInfo->s_APIKey = FLICKR_API_KEY;
	pThreadInfo->s_EndpointRef = ENDPOINT_REF;
	pThreadInfo->s_Token = _sToken;
	pThreadInfo->s_NSID = _sNSID;
	
	p_RestoreUserThread = AfxBeginThread (RestoreUserThreadFunc, pThreadInfo, THREAD_PRIORITY_NORMAL, 0, 0);
}


CString GetAuthURL (GetFrobThreadInfo* _pThreadInfo, CString _sFrob)
{
	axis2_char_t* api_sig_str= NULL;
	axis2_char_t* api_sig = NULL;

	// Create Frob String Buffer
	int iSize = _sFrob.GetLength ();
	char* zFrob = new char [iSize + 1];
	memset (zFrob, 0, iSize + 1);
	wcstombs (zFrob, _sFrob, iSize + 1);

	// Get API Signature
	api_sig_str = axutil_strcat (_pThreadInfo->env, "d158127cfb15da0f",
							     "api_key", "4176cdc1597a07ea0961617b01ecef10",
							     "frob", zFrob,
								 "perms", "write", NULL);
	api_sig = get_md5 (api_sig_str, _pThreadInfo->env);

	delete [] zFrob;

	// Create Auth URL
	CString sAuthURL = "http://flickr.com/services/auth/fresh?";
	sAuthURL+= "api_key=";
	sAuthURL+= "4176cdc1597a07ea0961617b01ecef10";
	sAuthURL+= "&";
	sAuthURL+= "perms=write&";
	sAuthURL+= "frob=";
	sAuthURL+= _sFrob;
	sAuthURL+= "&";
	sAuthURL+= "api_sig=";
	sAuthURL+= api_sig;

	return sAuthURL;
}


CString GetFrob (GetFrobThreadInfo* _pThreadInfo)
{
	axis2_char_t* api_sig_str= NULL;
	axis2_char_t* api_sig = NULL;

	axiom_namespace_t* ns0 = NULL;
	axiom_node_t*      flickr_om_node = NULL;
	axiom_element_t*   flickr_om_ele = NULL;
	axiom_element_t*   text_om_ele = NULL;
	axiom_node_t*      text_om_node = NULL;
	axiom_node_t*      ret_node = NULL;

	// Create API Key String Buffer
	int iSize = _pThreadInfo->s_APIKey.GetLength ();
	char* zAPIKey = new char [iSize + 1];
	memset (zAPIKey, 0, iSize + 1);
	wcstombs (zAPIKey, _pThreadInfo->s_APIKey, iSize + 1);

	// Get API Signature
	api_sig_str = axutil_strcat (_pThreadInfo->env, "d158127cfb15da0f",
								 "api_key", zAPIKey,
							     "method", "flickr.auth.getFrob", NULL);
	api_sig = get_md5 (api_sig_str, _pThreadInfo->env);

	// Create Payload
	ns0 = axiom_namespace_create (_pThreadInfo->env, "urn:flickr", "x");
    flickr_om_ele = axiom_element_create (_pThreadInfo->env, NULL, "FlickrRequest", ns0, &flickr_om_node);

	text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zAPIKey, text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, "flickr.auth.getFrob", text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, api_sig, text_om_node);

	// Get Response
	ret_node = axis2_svc_client_send_receive (_pThreadInfo->svc_client, _pThreadInfo->env, flickr_om_node);
	
	delete [] zAPIKey;

	if (NULL == ret_node)
		return "";

	if (axis2_svc_client_get_last_response_has_fault (_pThreadInfo->svc_client, _pThreadInfo->env) == AXIS2_TRUE)
		return "";

	// Get Available Quota
	CString sPayload = axiom_node_to_string (ret_node, _pThreadInfo->env);

	int iStartIndex = sPayload.Find (_T("&lt;frob&gt;"));
	if (-1 == iStartIndex)
		return "";

	sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 12)); // 12 -> &lt;frob&gt;

	iStartIndex = sPayload.Find (_T("&lt;/frob&gt;"));
	if (-1 == iStartIndex)
		return "";
	
	sPayload = sPayload.Left (iStartIndex);

	return sPayload;
}


UINT GetFrobThreadFunc (LPVOID lParam)
{
	GetFrobThreadInfo* pThreadInfo = (GetFrobThreadInfo*)lParam;
	if (NULL == pThreadInfo)
		return 0;

	CWMParam* pWMParam = new CWMParam;
	pWMParam->b_Success = false;

	// Create Service Client
	// Set up the Environment
	axutil_env_t* env = axutil_env_create_all ("FlickrUploader-GetFrob.log", AXIS2_LOG_LEVEL_TRACE);
	if (NULL == env)
	{
		AfxMessageBox (_T("Failed to create WSF environment !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_GET_FROB_DONE, (WPARAM)pWMParam, 0);
		return 0;
	}

	pThreadInfo->env = env;

	// Get up Deploy Folder
	int iSize = pThreadInfo->s_WSFCHome.GetLength ();
	char* client_home = new char [iSize + 1];
	memset (client_home, 0, iSize + 1);
	wcstombs (client_home, pThreadInfo->s_WSFCHome, iSize + 1);

    /*const axis2_char_t* client_home = AXIS2_GETENV ("WSFC_HOME");
    if (!client_home || !strcmp (client_home, ""))
    {
		AfxMessageBox (_T("Failed to read WSFC_HOME !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_GET_FROB_DONE, (WPARAM)pWMParam, 0);
		return 0;
	}*/

	// Create Client
    axis2_svc_client_t*	svc_client = axis2_svc_client_create (env, client_home);
	delete [] client_home;
    if (!svc_client)
    {
        AfxMessageBox (_T("Error while creating service client, Please check WSFC_HOME again !!!"), MB_OK | MB_ICONEXCLAMATION);
		AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code: %d :: %s", env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_GET_FROB_DONE, (WPARAM)pWMParam, 0);
		return 0;
    }

	pThreadInfo->svc_client = svc_client;

	// Set Options
	axis2_options_t* client_options = axis2_options_create (env);

	iSize = pThreadInfo->s_EndpointRef.GetLength ();
	char* endpoint_ref_str = new char [iSize + 1];
	memset (endpoint_ref_str, 0, iSize + 1);
	wcstombs (endpoint_ref_str, pThreadInfo->s_EndpointRef, iSize + 1);

	axis2_endpoint_ref_t* endpoint_ref = axis2_endpoint_ref_create (env, endpoint_ref_str);
	axis2_options_set_to (client_options, env, endpoint_ref);

	delete [] endpoint_ref_str;
	
	axis2_options_set_xml_parser_reset (client_options, env, AXIS2_FALSE);
    
    axis2_svc_client_set_options (svc_client, env, client_options);

	// Get Frob
	CString sFrob = GetFrob (pThreadInfo);
	if (sFrob == "")
	{
		AfxMessageBox (_T("Failed to Get Frob !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_GET_FROB_DONE, (WPARAM)pWMParam, 0);
		return 0;
	}

	pWMParam->s_Frob = sFrob;

	// Get Auth URL
	CString sAuthURL = GetAuthURL (pThreadInfo, sFrob);
	if (sAuthURL == "")
	{
		AfxMessageBox (_T("Failed to Get Auth URL !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_GET_FROB_DONE, (WPARAM)pWMParam, 0);
		return 0;
	}

	pWMParam->s_AuthURL = sAuthURL;
	pWMParam->b_Success = true;

	(pThreadInfo->p_MessageReceiver)->PostMessage (WM_GET_FROB_DONE, (WPARAM)pWMParam, 0);

	delete pThreadInfo;

	return 1;
}


void CFlickrClient::GetFrob (CString _sWSFCHome,CWnd* _pMessageReceiver)
{
    GetFrobThreadInfo* pThreadInfo = new GetFrobThreadInfo;

	pThreadInfo->p_MessageReceiver = _pMessageReceiver;
	pThreadInfo->s_WSFCHome = _sWSFCHome;
	pThreadInfo->s_APIKey = FLICKR_API_KEY;
	pThreadInfo->s_EndpointRef = ENDPOINT_REF;
	
	p_GetFrobThread = AfxBeginThread (GetFrobThreadFunc, pThreadInfo, THREAD_PRIORITY_NORMAL, 0, 0);
}


CUserAuthInfo* GetUserAuthInfo (CreateUserThreadInfo* _pThreadInfo)
{
	axis2_char_t* api_sig_str= NULL;
	axis2_char_t* api_sig = NULL;

	axiom_namespace_t* ns0 = NULL;
	axiom_node_t*      flickr_om_node = NULL;
	axiom_element_t*   flickr_om_ele = NULL;
	axiom_element_t*   text_om_ele = NULL;
	axiom_node_t*      text_om_node = NULL;
	axiom_node_t*      ret_node = NULL;

	// Create API Key String Buffer
	int iSize = _pThreadInfo->s_APIKey.GetLength ();
	char* zAPIKey = new char [iSize + 1];
	memset (zAPIKey, 0, iSize + 1);
	wcstombs (zAPIKey, _pThreadInfo->s_APIKey, iSize + 1);

	// Create Frob String Buffer
	iSize = _pThreadInfo->s_Frob.GetLength ();
	char* zFrob = new char [iSize + 1];
	memset (zFrob, 0, iSize + 1);
	wcstombs (zFrob, _pThreadInfo->s_Frob, iSize + 1);

	// Get API Signature
	api_sig_str = axutil_strcat (_pThreadInfo->env, "d158127cfb15da0f",
							     "api_key", zAPIKey,
							     "frob", zFrob,
								 "method", "flickr.auth.getToken", NULL);
	api_sig = get_md5 (api_sig_str, _pThreadInfo->env);

	// Create Payload
	ns0 = axiom_namespace_create (_pThreadInfo->env, "urn:flickr", "x");
    flickr_om_ele = axiom_element_create (_pThreadInfo->env, NULL, "FlickrRequest", ns0, &flickr_om_node);

	text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zAPIKey, text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "frob", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, zFrob, text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, "flickr.auth.getToken", text_om_node);

    text_om_ele = axiom_element_create (_pThreadInfo->env, flickr_om_node, "api_sig", NULL, &text_om_node);
    axiom_element_set_text (text_om_ele, _pThreadInfo->env, api_sig, text_om_node);

	// Get Response
	ret_node = axis2_svc_client_send_receive (_pThreadInfo->svc_client, _pThreadInfo->env, flickr_om_node);
	
	delete [] zAPIKey;
	delete [] zFrob;

	if (NULL == ret_node)
		return NULL;

	if (axis2_svc_client_get_last_response_has_fault (_pThreadInfo->svc_client, _pThreadInfo->env) == AXIS2_TRUE)
		return NULL;

	// Get User Auth Info
	CString sPayload = axiom_node_to_string (ret_node, _pThreadInfo->env);
	
	CString sToken = "";
	CString sNSID = "";
	CString sUsername = "";

	// Get Token
	int iStartIndex = sPayload.Find (_T("&lt;token&gt;"));
	if (-1 == iStartIndex)
		return NULL;

	sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 13)); // 13 -> &lt;token&gt;

	iStartIndex = sPayload.Find (_T("&lt;/token&gt;"));
	if (-1 == iStartIndex)
		return NULL;
	
	sToken = sPayload.Left (iStartIndex);

	// Get NSID
	iStartIndex = sPayload.Find (_T("nsid=&quot;"));
	if (-1 == iStartIndex)
		return NULL;

	sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 11)); // 11 -> nsid=&quot;

	iStartIndex = sPayload.Find (_T("&quot;"));
	if (-1 == iStartIndex)
		return NULL;
	
	sNSID = sPayload.Left (iStartIndex);

	// Get Username
	iStartIndex = sPayload.Find (_T("username=&quot;"));
	if (-1 == iStartIndex)
		return NULL;

	sPayload = sPayload.Right (sPayload.GetLength () - (iStartIndex + 15)); // 15 -> username=&quot;

	iStartIndex = sPayload.Find (_T("&quot;"));
	if (-1 == iStartIndex)
		return NULL;
	
	sUsername = sPayload.Left (iStartIndex);

	return (new CUserAuthInfo (sToken, sNSID, sUsername));
}


UINT CreateUserThreadFunc (LPVOID lParam)
{
	CreateUserThreadInfo* pThreadInfo = (CreateUserThreadInfo*)lParam;
	if (NULL == pThreadInfo)
		return 0;

	CWMParam* pWMParam = new CWMParam;
	pWMParam->b_Success = false;

	// Create Service Client
	// Set up the Environment
	axutil_env_t* env = axutil_env_create_all ("FlickrUploader-CreateUser.log", AXIS2_LOG_LEVEL_TRACE);
	if (NULL == env)
	{
		AfxMessageBox (_T("Failed to create WSF environment !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_CREATE_NEW_USER_DONE, (WPARAM)pWMParam, 0);
		return 0;
	}

	pThreadInfo->env = env;

	// Get up Deploy Folder
	int iSize = pThreadInfo->s_WSFCHome.GetLength ();
	char* client_home = new char [iSize + 1];
	memset (client_home, 0, iSize + 1);
	wcstombs (client_home, pThreadInfo->s_WSFCHome, iSize + 1);

    /*const axis2_char_t* client_home = AXIS2_GETENV ("WSFC_HOME");
    if (!client_home || !strcmp (client_home, ""))
    {
		AfxMessageBox (_T("Failed to read WSFC_HOME !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_CREATE_NEW_USER_DONE, (WPARAM)pWMParam, 0);
		return 0;
	}*/

	// Create Client
    axis2_svc_client_t*	svc_client = axis2_svc_client_create (env, client_home);
	delete [] client_home;
    if (!svc_client)
    {
        AfxMessageBox (_T("Error while creating service client, Please check WSFC_HOME again !!!"), MB_OK | MB_ICONEXCLAMATION);
		AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code: %d :: %s", env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_CREATE_NEW_USER_DONE, (WPARAM)pWMParam, 0);
		return 0;
    }

	pThreadInfo->svc_client = svc_client;

	// Set Options
	axis2_options_t* client_options = axis2_options_create (env);

	iSize = pThreadInfo->s_EndpointRef.GetLength ();
	char* endpoint_ref_str = new char [iSize + 1];
	memset (endpoint_ref_str, 0, iSize + 1);
	wcstombs (endpoint_ref_str, pThreadInfo->s_EndpointRef, iSize + 1);

	axis2_endpoint_ref_t* endpoint_ref = axis2_endpoint_ref_create (env, endpoint_ref_str);
	axis2_options_set_to (client_options, env, endpoint_ref);

	delete [] endpoint_ref_str;
	
	axis2_options_set_xml_parser_reset (client_options, env, AXIS2_FALSE);
    
    axis2_svc_client_set_options (svc_client, env, client_options);

	// Get User Auth Info
	(pThreadInfo->p_MessageReceiver)->PostMessage (WM_WAIT_ANIMATION_MESSAGE, (WPARAM)(new CString (_T("Authenticating ..."))), 0);

	CUserAuthInfo* pUserAuthInfo = GetUserAuthInfo (pThreadInfo);	
	if (NULL == pUserAuthInfo)
	{
		AfxMessageBox (_T("Error while retrieving user authentication information !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_CREATE_NEW_USER_DONE, (WPARAM)pWMParam, 0);
		return 0;
	}
	
	pWMParam->s_Token = pUserAuthInfo->s_Token;
	pWMParam->s_NSID = pUserAuthInfo->s_NSID;
	pWMParam->s_Username = pUserAuthInfo->s_Username;

	RestoreUserThreadInfo oThreadInfo;

	oThreadInfo.s_APIKey = pThreadInfo->s_APIKey;
	oThreadInfo.s_Token = pUserAuthInfo->s_Token;
	oThreadInfo.s_NSID = pUserAuthInfo->s_NSID;
	oThreadInfo.env = pThreadInfo->env;
	oThreadInfo.svc_client = pThreadInfo->svc_client;

	delete pUserAuthInfo;

	// Get Photos URL
	(pThreadInfo->p_MessageReceiver)->PostMessage (WM_WAIT_ANIMATION_MESSAGE, (WPARAM)(new CString (_T("Retrieving Photos URL ..."))), 0);
	pWMParam->s_PhotosURL = GetUserPhotosURL (&oThreadInfo);
	
	// Get Profile URL
	(pThreadInfo->p_MessageReceiver)->PostMessage (WM_WAIT_ANIMATION_MESSAGE, (WPARAM)(new CString (_T("Retrieving Profile URL ..."))), 0);
	pWMParam->s_ProfileURL = GetUserProfileURL (&oThreadInfo);
	
	(pThreadInfo->p_MessageReceiver)->PostMessage (WM_WAIT_ANIMATION_MESSAGE, (WPARAM)(new CString (_T("Retrieving Upload Status ..."))), 0);

	CUploadStatus* pUploadStatus = GetUploadStatus (&oThreadInfo);
	if (NULL != pUploadStatus)
	{
		pWMParam->s_AvailableQuota = pUploadStatus->s_AvailableQuota;
		pWMParam->i_RemainingSetCount = pUploadStatus->i_RemainingSetCount;
		pWMParam->b_Pro = pUploadStatus->b_Pro;

		delete pUploadStatus;
	}

	// Get Photo Set Names
	(pThreadInfo->p_MessageReceiver)->PostMessage (WM_WAIT_ANIMATION_MESSAGE, (WPARAM)(new CString (_T("Retrieving Photo Set Info ..."))), 0);
	pWMParam->lst_PhotoSetInfo = GetPhotoSetInfo (&oThreadInfo);

	pWMParam->b_Success = true;

	(pThreadInfo->p_MessageReceiver)->PostMessage (WM_CREATE_NEW_USER_DONE, (WPARAM)pWMParam, 0);

	delete pThreadInfo;

	return 1;
}


void CFlickrClient::CreateUser (CString _sWSFCHome, CString _sFrob, CWnd* _pMessageReceiver)
{
	CreateUserThreadInfo* pThreadInfo = new CreateUserThreadInfo;

	pThreadInfo->p_MessageReceiver = _pMessageReceiver;
	pThreadInfo->s_WSFCHome = _sWSFCHome;
	pThreadInfo->s_APIKey = FLICKR_API_KEY;
	pThreadInfo->s_EndpointRef = ENDPOINT_REF;
	pThreadInfo->s_Frob = _sFrob;
	
	p_CreateUserThread = AfxBeginThread (CreateUserThreadFunc, pThreadInfo, THREAD_PRIORITY_NORMAL, 0, 0);
}


CString UploadImage (UploadImageThreadInfo* _pThreadInfo)
{
	CString sPhotoID = "";

	// Create API Signature String Buffer
	CString sAPISigString = "d158127cfb15da0f";
			sAPISigString+= "api_key";
			sAPISigString+= _pThreadInfo->s_APIKey;
			sAPISigString+= "auth_token";
			sAPISigString+= _pThreadInfo->s_Token;
			sAPISigString+= "content_type";

			CString sContentType;
			sContentType.Format (_T("%d"), _pThreadInfo->i_ContentType);
			sAPISigString+= sContentType;

			if (_pThreadInfo->s_Description != "")
			{
				sAPISigString+= "description";
				sAPISigString+= _pThreadInfo->s_Description;
			}
			
			sAPISigString+= "hidden";

			CString sHidden;
			sHidden.Format (_T("%d"), _pThreadInfo->i_Hidden);
			sAPISigString+= sHidden;
			
			sAPISigString+= "is_family";
			sAPISigString+= _pThreadInfo->b_Family ? "1" : "0";
			sAPISigString+= "is_friend";
			sAPISigString+= _pThreadInfo->b_Friends ? "1" : "0";
			sAPISigString+= "is_public";
			sAPISigString+= _pThreadInfo->b_Anyone ? "1" : "0";
			sAPISigString+= "safety_level";

			CString sSafetyLevel;
			sSafetyLevel.Format (_T("%d"), _pThreadInfo->i_SafetyLevel);
			sAPISigString+= sSafetyLevel;
			
			if (_pThreadInfo->s_Tags != "")
			{
				sAPISigString+= "tags";
				sAPISigString+= _pThreadInfo->s_Tags;
			}
			
			if (_pThreadInfo->s_Title != "")
			{
				sAPISigString+= "title";
				sAPISigString+= _pThreadInfo->s_Title;
			}
			
	int iSize = sAPISigString.GetLength ();
	char* zAPISigString = new char [iSize + 1];
	memset (zAPISigString, 0, iSize + 1);
	wcstombs (zAPISigString, sAPISigString, iSize + 1);

	// Get API Signature
	axis2_char_t* api_sig = NULL;
	api_sig = get_md5 ((axis2_char_t*)zAPISigString, _pThreadInfo->env);

	// Create Command
	CString sCommand = "curl -F ";
			sCommand+= "api_key=";
			sCommand+= _pThreadInfo->s_APIKey;
			sCommand+= " -F auth_token=";
			sCommand+= _pThreadInfo->s_Token;
			sCommand+= " -F api_sig=";
			sCommand+= api_sig;
			sCommand+= " -F photo=@\"";
			sCommand+= _pThreadInfo->s_FileName;
			sCommand+= "\" -F content_type=";
			sCommand+= sContentType;

			if (_pThreadInfo->s_Description != "")
			{
				sCommand+= " -F description=\"";
				sCommand+= _pThreadInfo->s_Description;
				sCommand+= "\"";
			}
			
			sCommand+= " -F hidden=";
			sCommand+= sHidden;
			sCommand+= " -F is_family=";
			sCommand+= _pThreadInfo->b_Family ? "1" : "0";
			sCommand+= " -F is_friend=";
			sCommand+= _pThreadInfo->b_Friends ? "1" : "0";
			sCommand+= " -F is_public=";
			sCommand+= _pThreadInfo->b_Anyone ? "1" : "0";
			sCommand+= " -F safety_level=";
			sCommand+= sSafetyLevel;
			
			if (_pThreadInfo->s_Tags != "")
			{
				sCommand+= " -F tags=\"";
				sCommand+= _pThreadInfo->s_Tags;
				sCommand+= "\"";
			}
			
			if (_pThreadInfo->s_Title != "")
			{
				sCommand+= " -F title=\"";
				sCommand+= _pThreadInfo->s_Title;
				sCommand+= "\"";
			}

			sCommand+= " http://api.flickr.com/services/upload/";
			
	// Create Process to Run curl
	SECURITY_ATTRIBUTES sa;
	ZeroMemory (&sa, sizeof (sa));
	sa.nLength = sizeof (sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	HANDLE hStatusFile = CreateFile (_T("FlickrUploaderStatus.txt"),
							         GENERIC_READ | GENERIC_WRITE,
									 FILE_SHARE_READ | FILE_SHARE_WRITE,
									 &sa,
									 CREATE_ALWAYS, // Always create it
									 FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_WRITE_THROUGH,
									 0);

	STARTUPINFO			si;
	PROCESS_INFORMATION	pi;
		
	ZeroMemory (&si, sizeof (si));
	si.cb = sizeof (si);
	si.dwFlags = STARTF_USESTDHANDLES;
	si.hStdInput = NULL;
	si.hStdOutput = hStatusFile;
	si.hStdError = hStatusFile;
	ZeroMemory (&pi, sizeof (pi));

	if (CreateProcess (NULL,
					   (LPTSTR)(LPCTSTR)sCommand,
					   NULL,
					   NULL,
					   TRUE,
					   CREATE_NO_WINDOW,
					   NULL,
					   NULL,
					   &si,
					   &pi))
	{
		// Wait until Child Process that Runs "curl" Exits.
		WaitForSingleObject (pi.hProcess, INFINITE);

		// Read Photo ID from the Status File
		CFile oStatusFile = CFile (hStatusFile);
		unsigned long ulContentLength = oStatusFile.GetLength ();
		oStatusFile.SeekToBegin ();

		char* zBuffer = new char [ulContentLength];
		oStatusFile.Read (zBuffer, ulContentLength);
		CString sContent = zBuffer;
		delete [] zBuffer;

		// Get Photo ID
		int iStartIndex = sContent.Find (_T("<photoid>"));
		if (-1 != iStartIndex)
		{
			sContent = sContent.Right (sContent.GetLength () - (iStartIndex + 9)); // 9 -> <photoid> 

			iStartIndex = sContent.Find (_T("</photoid>"));
			if (-1 != iStartIndex)
				sPhotoID = sContent.Left (iStartIndex);
		}

		// Close Child Process and Thread Handles.
		CloseHandle (pi.hProcess);
		CloseHandle (pi.hThread);
	}

	delete [] zAPISigString;
	CloseHandle (hStatusFile);

	return sPhotoID;
}


CString CreateNewSet (UploadImageThreadInfo* _pThreadInfo, CPhotoSetInfo* _pPhotoSetInfo, CString _sPrimaryPhotoID)
{
	CString sPhotoSetID = "";

	// Create API Signature String Buffer
	CString sAPISigString = "d158127cfb15da0f";
			sAPISigString+= "api_key";
			sAPISigString+= _pThreadInfo->s_APIKey;
			sAPISigString+= "auth_token";
			sAPISigString+= _pThreadInfo->s_Token;
			
			if (_pPhotoSetInfo->s_Description != "")
			{
				sAPISigString+= "description";
				sAPISigString+= _pPhotoSetInfo->s_Description;
			}
			
			sAPISigString+= "methodflickr.photosets.create";
			sAPISigString+= "primary_photo_id";
			sAPISigString+= _sPrimaryPhotoID;
			sAPISigString+= "title";
			sAPISigString+= _pPhotoSetInfo->s_Name;	
			
	int iSize = sAPISigString.GetLength ();
	char* zAPISigString = new char [iSize + 1];
	memset (zAPISigString, 0, iSize + 1);
	wcstombs (zAPISigString, sAPISigString, iSize + 1);

	// Get API Signature
	axis2_char_t* api_sig = NULL;
	api_sig = get_md5 ((axis2_char_t*)zAPISigString, _pThreadInfo->env);

	// Create Command
	CString sCommand = "curl -F ";
			sCommand+= "api_key=";
			sCommand+= _pThreadInfo->s_APIKey;
			sCommand+= " -F auth_token=";
			sCommand+= _pThreadInfo->s_Token;
			sCommand+= " -F api_sig=";
			sCommand+= api_sig;
			sCommand+= " -F title=\"";
			sCommand+= _pPhotoSetInfo->s_Name;
			sCommand+= "\"";

			if (_pPhotoSetInfo->s_Description != "")
			{
				sCommand+= " -F description=\"";
				sCommand+= _pPhotoSetInfo->s_Description;
				sCommand+= "\"";
			}

			sCommand+= " -F primary_photo_id=";
			sCommand+= _sPrimaryPhotoID;
			sCommand+= " -F method=flickr.photosets.create";
			sCommand+= " http://api.flickr.com/services/rest/";
			
	// Create Process to Run curl
	SECURITY_ATTRIBUTES sa;
	ZeroMemory (&sa, sizeof (sa));
	sa.nLength = sizeof (sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	HANDLE hStatusFile = CreateFile (_T("FlickrUploaderStatus.txt"),
							         GENERIC_READ | GENERIC_WRITE,
									 FILE_SHARE_READ | FILE_SHARE_WRITE,
									 &sa,
									 CREATE_ALWAYS, // Always create it
									 FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_WRITE_THROUGH,
									 0);
			
	STARTUPINFO			si;
	PROCESS_INFORMATION	pi;
		
	ZeroMemory (&si, sizeof (si));
	si.cb = sizeof (si);
	si.dwFlags = STARTF_USESTDHANDLES;
	si.hStdInput = NULL;
	si.hStdOutput = hStatusFile;
	si.hStdError = hStatusFile;
	ZeroMemory (&pi, sizeof (pi));

	if (CreateProcess (NULL,
					   (LPTSTR)(LPCTSTR)sCommand,
					   NULL,
					   NULL,
					   TRUE,
					   CREATE_NO_WINDOW,
					   NULL,
					   NULL,
					   &si,
					   &pi))
	{
		// Wait until Child Process that Runs "curl" Exits.
		WaitForSingleObject (pi.hProcess, INFINITE);

		// Read Photo Set ID from the Status File
		CFile oStatusFile = CFile (hStatusFile);
		unsigned long ulContentLength = oStatusFile.GetLength ();
		oStatusFile.SeekToBegin ();

		char* zBuffer = new char [ulContentLength];
		oStatusFile.Read (zBuffer, ulContentLength);
		CString sContent = zBuffer;
		delete [] zBuffer;

		// Get Photo Set ID
		int iStartIndex = sContent.Find (_T("<photoset"));
		if (-1 != iStartIndex)
		{
			sContent = sContent.Right (sContent.GetLength () - (iStartIndex + 9)); // 9 -> <photoset 

			iStartIndex = sContent.Find (_T("id=\""));
			if (-1 != iStartIndex)
			{
				sContent = sContent.Right (sContent.GetLength () - (iStartIndex + 4)); // 4 -> id="
				
				iStartIndex = sContent.Find (_T("\""));
				if (-1 != iStartIndex)
					sPhotoSetID = sContent.Left (iStartIndex);
			}
		}

		// Close Child Process and Thread Handles.
		CloseHandle (pi.hProcess);
		CloseHandle (pi.hThread);
	}

	delete [] zAPISigString;
	CloseHandle (hStatusFile);

	return sPhotoSetID;
}


UINT AddToSet (UploadImageThreadInfo* _pThreadInfo, CPhotoSetInfo* _pPhotoSetInfo, CString _sPhotoID)
{
	// Creat API Signature String Buffer
	CString sAPISigString = "d158127cfb15da0f";
			sAPISigString+= "api_key";
			sAPISigString+= _pThreadInfo->s_APIKey;
			sAPISigString+= "auth_token";
			sAPISigString+= _pThreadInfo->s_Token;
			sAPISigString+= "methodflickr.photosets.addPhoto";
			sAPISigString+= "photo_id";
			sAPISigString+= _sPhotoID;
			sAPISigString+= "photoset_id";
			sAPISigString+= _pPhotoSetInfo->s_ID;
			
	int iSize = sAPISigString.GetLength ();
	char* zAPISigString = new char [iSize + 1];
	memset (zAPISigString, 0, iSize + 1);
	wcstombs (zAPISigString, sAPISigString, iSize + 1);

	// Get API Signature
	axis2_char_t* api_sig = NULL;
	api_sig = get_md5 ((axis2_char_t*)zAPISigString, _pThreadInfo->env);

	// Create Command
	CString sCommand = "curl -F ";
			sCommand+= "api_key=";
			sCommand+= _pThreadInfo->s_APIKey;
			sCommand+= " -F auth_token=";
			sCommand+= _pThreadInfo->s_Token;
			sCommand+= " -F api_sig=";
			sCommand+= api_sig;
			sCommand+= " -F photo_id=";
			sCommand+= _sPhotoID;
			sCommand+= " -F photoset_id=";
			sCommand+= _pPhotoSetInfo->s_ID;
			sCommand+= " -F method=flickr.photosets.addPhoto";
			sCommand+= " http://api.flickr.com/services/rest/";
			
	// Create Process to Run curl
	SECURITY_ATTRIBUTES sa;
	ZeroMemory (&sa, sizeof (sa));
	sa.nLength = sizeof (sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	HANDLE hStatusFile = CreateFile (_T("FlickrUploaderStatus.txt"),
							         GENERIC_READ | GENERIC_WRITE,
									 FILE_SHARE_READ | FILE_SHARE_WRITE,
									 &sa,
									 CREATE_ALWAYS, // Always create it
									 FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_WRITE_THROUGH,
									 0);
			
	STARTUPINFO			si;
	PROCESS_INFORMATION	pi;
		
	ZeroMemory (&si, sizeof (si));
	si.cb = sizeof (si);
	si.dwFlags = STARTF_USESTDHANDLES;
	si.hStdInput = NULL;
	si.hStdOutput = hStatusFile;
	si.hStdError = hStatusFile;
	ZeroMemory (&pi, sizeof (pi));

	if (CreateProcess (NULL,
					   (LPTSTR)(LPCTSTR)sCommand,
					   NULL,
					   NULL,
					   TRUE,
					   CREATE_NO_WINDOW,
					   NULL,
					   NULL,
					   &si,
					   &pi))
	{
		// Wait until Child Process that Runs "curl" Exits.
		WaitForSingleObject (pi.hProcess, INFINITE);

		// Close Child Process and Thread Handles.
		CloseHandle (pi.hProcess);
		CloseHandle (pi.hThread);
	}

	delete [] zAPISigString;
	CloseHandle (hStatusFile);

	return 1;
}


UINT UploadImageThreadFunc (LPVOID lParam)
{
	UploadImageThreadInfo* pThreadInfo = (UploadImageThreadInfo*)lParam;
	if (NULL == pThreadInfo)
		return 0;

	CWMParam* pWMParam = new CWMParam;
	
	pWMParam->b_Success = false;
	pWMParam->s_PhotoTitle = pThreadInfo->s_Title;

	// Create Service Client
	// Set up the Environment
	axutil_env_t* env = axutil_env_create_all ("FlickrUploader-UploadImage.log", AXIS2_LOG_LEVEL_TRACE);
	if (NULL == env)
	{
		AfxMessageBox (_T("Failed to create WSF environment !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_FILE_UPLOAD_DONE, (WPARAM)pWMParam, 0);
		return 0;
	}

	pThreadInfo->env = env;

	// Get up Deploy Folder
	int iSize = pThreadInfo->s_WSFCHome.GetLength ();
	char* client_home = new char [iSize + 1];
	memset (client_home, 0, iSize + 1);
	wcstombs (client_home, pThreadInfo->s_WSFCHome, iSize + 1);

    /*const axis2_char_t* client_home = AXIS2_GETENV ("WSFC_HOME");
    if (!client_home || !strcmp (client_home, ""))
    {
		AfxMessageBox (_T("Failed to read WSFC_HOME !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_FILE_UPLOAD_DONE, (WPARAM)pWMParam, 0);
		return 0;
	}*/

	// Create Client
    axis2_svc_client_t*	svc_client = axis2_svc_client_create (env, client_home);
	delete [] client_home;
    if (!svc_client)
    {
        AfxMessageBox (_T("Error while creating service client, Please check WSFC_HOME again !!!"), MB_OK | MB_ICONEXCLAMATION);
		AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code: %d :: %s", env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_FILE_UPLOAD_DONE, (WPARAM)pWMParam, 0);
		return 0;
    }

	// Set Options
	axis2_options_t* client_options = axis2_options_create (env);

	iSize = pThreadInfo->s_EndpointRef.GetLength ();
	char* endpoint_ref_str = new char [iSize + 1];
	memset (endpoint_ref_str, 0, iSize + 1);
	wcstombs (endpoint_ref_str, pThreadInfo->s_EndpointRef, iSize + 1);

	axis2_endpoint_ref_t* endpoint_ref = axis2_endpoint_ref_create (env, endpoint_ref_str);
	axis2_options_set_to (client_options, env, endpoint_ref);

	delete [] endpoint_ref_str;
	
	axis2_options_set_xml_parser_reset (client_options, env, AXIS2_FALSE);
    
    axis2_svc_client_set_options (svc_client, env, client_options);
	
	// Upload Image
	CString sPhotoID = UploadImage (pThreadInfo);
	if (sPhotoID == "") // Failed !!! - Send Message to Dialog
	{
		AfxMessageBox (_T("Failed to Upload Image !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_FILE_UPLOAD_DONE, (WPARAM)pWMParam, 0);
		return 0;
	}
	
	pWMParam->b_Success = true;

	// Add to Sets ; Creae New Sets
	CImageDetails::PhotoSetName_set_t::iterator itePhotoSetNames;
	CImageDetails::PhotoSetName_set_t::iterator iteStartPhotoSetNames = pThreadInfo->set_SelectedSets.begin ();
	CImageDetails::PhotoSetName_set_t::iterator iteEndPhotoSetNames = pThreadInfo->set_SelectedSets.end ();

	for (itePhotoSetNames = iteStartPhotoSetNames; itePhotoSetNames != iteEndPhotoSetNames; ++itePhotoSetNames)
	{
		CString sPhotoSetName = *itePhotoSetNames;
		
		CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
		itePhotoSetInfo = pThreadInfo->map_PhotoSetInfoByName.find (sPhotoSetName);
		if (itePhotoSetInfo == pThreadInfo->map_PhotoSetInfoByName.end ())
			continue;

		CPhotoSetInfo* pPhotoSetInfo = itePhotoSetInfo->second;

		if (true == pPhotoSetInfo->b_New) // New Set
		{
			CString* pParm = new CString (itePhotoSetInfo->first); // Set Name

			(pThreadInfo->p_MessageReceiver)->PostMessage (WM_CREATE_NEW_SET, (WPARAM)pParm, 0);

			// Create Set
			CString sPhotoSetID = CreateNewSet (pThreadInfo, pPhotoSetInfo, sPhotoID);

			if (sPhotoSetID != "") // Photo Set Created
			{
				CWMParam* pParm = new CWMParam;

				pParm->s_PhotoSetName = itePhotoSetInfo->first;
				pParm->s_PhotoSetID = sPhotoSetID;

				(pThreadInfo->p_MessageReceiver)->PostMessage (WM_CREATE_NEW_SET_DONE, (WPARAM)pParm, 0);
			}
		}
		else
		{
			CString* pParm = new CString (itePhotoSetInfo->first);

			(pThreadInfo->p_MessageReceiver)->PostMessage (WM_ADD_TO_SET, (WPARAM)pParm, 0);

			// Add Photo to Photo Set
			AddToSet (pThreadInfo, pPhotoSetInfo, sPhotoID);
		}
	}

	// Successful Operation
	(pThreadInfo->p_MessageReceiver)->PostMessage (WM_FILE_UPLOAD_DONE, (WPARAM)pWMParam, 0);

	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator iteStartPhotoSetInfo = pThreadInfo->map_PhotoSetInfoByName.begin ();
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator iteEndPhotoSetInfo = pThreadInfo->map_PhotoSetInfoByName.end ();
	
	for (itePhotoSetInfo = iteStartPhotoSetInfo; itePhotoSetInfo != iteEndPhotoSetInfo; ++itePhotoSetInfo)
		delete itePhotoSetInfo->second;

	delete pThreadInfo;

	return 1;
}


void CFlickrClient::UploadImage (CString _sWSFCHome, CString _sToken, CImageDetails* _pImageDetails, CWnd* _pMessageReceiver)
{
	if ((NULL == _pImageDetails) || (NULL == _pMessageReceiver))
		return;

	UploadImageThreadInfo* pThreadInfo = new UploadImageThreadInfo;

	pThreadInfo->p_MessageReceiver = _pMessageReceiver;
	pThreadInfo->s_WSFCHome = _sWSFCHome;
	pThreadInfo->s_Token = _sToken;
	pThreadInfo->s_APIKey = FLICKR_API_KEY;
	pThreadInfo->s_EndpointRef = ENDPOINT_REF;
	pThreadInfo->s_Title = _pImageDetails->s_Title;
	pThreadInfo->s_Description = _pImageDetails->s_Description;
	pThreadInfo->s_Tags = _pImageDetails->s_Tags;
	pThreadInfo->b_OnlyMe = _pImageDetails->b_OnlyMe;
	pThreadInfo->b_Family = _pImageDetails->b_Family;
	pThreadInfo->b_Friends = _pImageDetails->b_Friends;
	pThreadInfo->b_Anyone = _pImageDetails->b_Anyone;
	pThreadInfo->i_SafetyLevel = _pImageDetails->i_SafetyLevel;
	pThreadInfo->i_Hidden = _pImageDetails->i_Hidden;
	pThreadInfo->i_ContentType = _pImageDetails->i_ContentType;
	pThreadInfo->s_FileName = _pImageDetails->s_FileName;
	pThreadInfo->set_SelectedSets = _pImageDetails->set_SelectedSets;

	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator iteStartPhotoSetInfo = p_PhotoSetInfoByName->begin ();
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator iteEndPhotoSetInfo = p_PhotoSetInfoByName->end ();

	for (itePhotoSetInfo = iteStartPhotoSetInfo; itePhotoSetInfo != iteEndPhotoSetInfo; ++itePhotoSetInfo)
		pThreadInfo->map_PhotoSetInfoByName.insert (make_pair (itePhotoSetInfo->first, itePhotoSetInfo->second->Clone ()));
	
	// Create New Thread
	p_UploadImageThread = AfxBeginThread (UploadImageThreadFunc, pThreadInfo, THREAD_PRIORITY_NORMAL, 0, 0);
}


UINT UpdateUploadStatusThreadFunc (LPVOID lParam)
{
	RestoreUserThreadInfo* pThreadInfo = (RestoreUserThreadInfo*)lParam;
	if (NULL == pThreadInfo)
		return 0;

	CWMParam* pParam = new CWMParam;
	pParam->b_Success = false;

	// Create Service Client
	// Set up the Environment
	axutil_env_t* env = axutil_env_create_all ("FlickrUploader-RestoreUser.log", AXIS2_LOG_LEVEL_TRACE);
	if (NULL == env)
	{
		AfxMessageBox (_T("Failed to create WSF environment !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_RESTORE_USER_DONE, (WPARAM)pParam, 0);
		return 0;
	}

	pThreadInfo->env = env;

	// Get up Deploy Folder
	int iSize = pThreadInfo->s_WSFCHome.GetLength ();
	char* client_home = new char [iSize + 1];
	memset (client_home, 0, iSize + 1);
	wcstombs (client_home, pThreadInfo->s_WSFCHome, iSize + 1);

    /*const axis2_char_t* client_home = AXIS2_GETENV ("WSFC_HOME");
    if (!client_home || !strcmp (client_home, ""))
    {
		AfxMessageBox (_T("Failed to read WSFC_HOME !!!"), MB_OK | MB_ICONEXCLAMATION);
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_RESTORE_USER_DONE, (WPARAM)pParam, 0);
		return 0;
	}*/

	// Create Client
    axis2_svc_client_t*	svc_client = axis2_svc_client_create (env, client_home);
	delete [] client_home;
    if (!svc_client)
    {
        AfxMessageBox (_T("Error while creating service client, Please check WSFC_HOME again !!!"), MB_OK | MB_ICONEXCLAMATION);
		AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code: %d :: %s", env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));
		(pThreadInfo->p_MessageReceiver)->PostMessage (WM_RESTORE_USER_DONE, (WPARAM)pParam, 0);
		return 0;
    }

	pThreadInfo->svc_client = svc_client;

	// Set Options
	axis2_options_t* client_options = axis2_options_create (env);

	iSize = pThreadInfo->s_EndpointRef.GetLength ();
	char* endpoint_ref_str = new char [iSize + 1];
	memset (endpoint_ref_str, 0, iSize + 1);
	wcstombs (endpoint_ref_str, pThreadInfo->s_EndpointRef, iSize + 1);

	axis2_endpoint_ref_t* endpoint_ref = axis2_endpoint_ref_create (env, endpoint_ref_str);
	axis2_options_set_to (client_options, env, endpoint_ref);

	delete [] endpoint_ref_str;
	
	axis2_options_set_xml_parser_reset (client_options, env, AXIS2_FALSE);
    
    axis2_svc_client_set_options (svc_client, env, client_options);

	// Get Upload Status
	CUploadStatus* pUploadStatus = GetUploadStatus (pThreadInfo);
	if (NULL != pUploadStatus)
	{
		pParam->s_AvailableQuota = pUploadStatus->s_AvailableQuota;
		pParam->i_RemainingSetCount = pUploadStatus->i_RemainingSetCount;
		pParam->b_Pro = pUploadStatus->b_Pro;

		pParam->b_Success = true;

		delete pUploadStatus;
	}
		
	(pThreadInfo->p_MessageReceiver)->PostMessage (WM_UPDATE_UPLOAD_STATUS_DONE, (WPARAM)pParam, 0);

	delete pThreadInfo;

	return 1;
}


void CFlickrClient::UpdateUploadStatus (CString _sWSFCHome, CString _sToken, CString _sNSID, CWnd* _pMessageReceiver)
{
	RestoreUserThreadInfo* pThreadInfo = new RestoreUserThreadInfo;

	pThreadInfo->p_MessageReceiver = _pMessageReceiver;
	pThreadInfo->s_WSFCHome = _sWSFCHome;
	pThreadInfo->s_APIKey = FLICKR_API_KEY;
	pThreadInfo->s_EndpointRef = ENDPOINT_REF;
	pThreadInfo->s_Token = _sToken;
	pThreadInfo->s_NSID = _sNSID;
	
	// Create New Thread
	p_UpdateUploadStatusThread = AfxBeginThread (UpdateUploadStatusThreadFunc, pThreadInfo, THREAD_PRIORITY_NORMAL, 0, 0);
}


void CFlickrClient::DestroyThreads (void)
{
	if (p_UpdateUploadStatusThread != NULL)
		p_UpdateUploadStatusThread->SuspendThread ();

	if (p_UploadImageThread != NULL)
		p_UploadImageThread->SuspendThread ();
	
	if (p_CreateUserThread != NULL)
		p_CreateUserThread->SuspendThread ();
	
	if (p_GetFrobThread != NULL)
		p_GetFrobThread->SuspendThread ();
	
	if (p_RestoreUserThread != NULL)
		p_RestoreUserThread->SuspendThread ();
}