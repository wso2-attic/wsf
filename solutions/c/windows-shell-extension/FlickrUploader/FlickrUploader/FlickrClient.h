#pragma once

#include "UserAuthInfo.h"
#include "UploadStatus.h"
#include "ImageDetails.h"
#include "PhotoSetInfo.h"

#include <axis2_util.h>
#include <axis2_client.h>

#include <set>
using namespace std;

#define	FLICKR_API_KEY	"4176cdc1597a07ea0961617b01ecef10"
#define ENDPOINT_REF	"http://api.flickr.com/services/soap/"

// Thread Info Structs
struct UploadImageThreadInfo
{
	CWnd*			p_MessageReceiver;
	CString			s_WSFCHome;
	CString			s_Token;
	CString			s_APIKey;
	CString			s_EndpointRef;
	CString			s_Title;
	CString			s_Description;
	CString			s_Tags;
	bool			b_OnlyMe;
	bool			b_Family;
	bool			b_Friends;
	bool			b_Anyone;
	int				i_SafetyLevel;
	int				i_Hidden;
	int				i_ContentType;	
	CString			s_FileName;
	axutil_env_t*	env;
	CImageDetails::PhotoSetName_set_t	    set_SelectedSets;
	CPhotoSetInfo::PhotoSetInfoByName_map_t map_PhotoSetInfoByName;
};

struct RestoreUserThreadInfo
{
	CWnd*			p_MessageReceiver;
	CString			s_WSFCHome;
	CString			s_Token;
	CString			s_APIKey;
	CString			s_EndpointRef;	
	CString			s_NSID;
	axutil_env_t*	env;
	axis2_svc_client_t*	svc_client;
};

struct GetFrobThreadInfo
{
	CWnd*			p_MessageReceiver;
	CString			s_WSFCHome;
	CString			s_APIKey;
	CString			s_EndpointRef;
	axutil_env_t*	env;
	axis2_svc_client_t*	svc_client;
};

struct CreateUserThreadInfo
{
	CWnd*			p_MessageReceiver;
	CString			s_WSFCHome;
	CString			s_APIKey;
	CString			s_EndpointRef;
	CString			s_Frob;
	axutil_env_t*	env;
	axis2_svc_client_t*	svc_client;
};

// Generate an MD5 Hash
axis2_char_t* get_md5 (axis2_char_t* buffer, const axutil_env_t* env);

// Restore User Thread Functions
bool 		   CheckToken		 (RestoreUserThreadInfo* _pThreadInfo);
CString		   GetUserPhotosURL  (RestoreUserThreadInfo* _pThreadInfo);
CString		   GetUserProfileURL (RestoreUserThreadInfo* _pThreadInfo);
CUploadStatus* GetUploadStatus	 (RestoreUserThreadInfo* _pThreadInfo);
CPhotoSetInfo::PhotoSetInfo_lst_t GetPhotoSetInfo (RestoreUserThreadInfo* _pThreadInfo);
UINT RestoreUserThreadFunc (LPVOID lParam);

// Get Frob Thread Functions
CString GetAuthURL (GetFrobThreadInfo* _pThreadInfo, CString _sFrob);
CString GetFrob	   (GetFrobThreadInfo* _pThreadInfo);
UINT GetFrobThreadFunc (LPVOID lParam);

// Create User Thread Functions
CUserAuthInfo* GetUserAuthInfo (CreateUserThreadInfo* _pThreadInfo);
UINT CreateUserThreadFunc (LPVOID lParam);

// Upload Image Thread Functions
CString UploadImage  (UploadImageThreadInfo* _pThreadInfo);
CString CreateNewSet (UploadImageThreadInfo* _pThreadInfo, CPhotoSetInfo* _pPhotoSetInfo, CString _sPrimaryPhotoID);
UINT	AddToSet	 (UploadImageThreadInfo* _pThreadInfo, CPhotoSetInfo* _pPhotoSetInfo, CString _sPhotoID);
UINT UploadImageThreadFunc (LPVOID lParam);

// Update Upload Status Thread Functions
UINT UpdateUploadStatusThreadFunc (LPVOID lParam);

class CFlickrClient
{
	public:
		CFlickrClient (void);
		~CFlickrClient (void);

		typedef	set<CString>	PhotoSetName_set_t;

		void	SetPhotoSetInfo	   (CPhotoSetInfo::PhotoSetInfoByName_map_t*	_pPhotoSetInfoByName);

		void	RestoreUser		   (CString _sWSFCHome, CString _sToken, CString _sNSID, CWnd* _pMessageReceiver);
		void	GetFrob			   (CString _sWSFCHome,CWnd* _pMessageReceiver);
		void	CreateUser		   (CString _sWSFCHome,CString _sFrob, CWnd* _pMessageReceiver);
		void	UploadImage		   (CString _sWSFCHome,CString _sToken, CImageDetails* _pImageDetails, CWnd* _pMessageReceiver);
		void	UpdateUploadStatus (CString _sWSFCHome,CString _sToken, CString _sNSID, CWnd* _pMessageReceiver);

		void	DestroyThreads	   (void);

	private:
		CPhotoSetInfo::PhotoSetInfoByName_map_t*	p_PhotoSetInfoByName;
		CWinThread*									p_UpdateUploadStatusThread;
		CWinThread*									p_UploadImageThread;
		CWinThread*									p_CreateUserThread;
		CWinThread*									p_GetFrobThread;
		CWinThread*									p_RestoreUserThread;
};
