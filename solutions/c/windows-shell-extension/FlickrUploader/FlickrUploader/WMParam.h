#pragma once

#include "PhotoSetInfo.h"

class CWMParam
{
	public:
		CWMParam (void);
		~CWMParam (void);

		int			i_PhotoIndex;
		CString		s_PhotoID;
		CString		s_PhotoTitle;
		CString		s_PhotoSetName;
		CString		s_PhotoSetID;
		bool		b_Success;
		CString		s_PhotosURL;
		CString		s_ProfileURL;
		CString		s_AvailableQuota;
		int			i_RemainingSetCount;
		bool		b_Pro;
		CString		s_Frob;
		CString		s_AuthURL;
		CString		s_Token;
		CString		s_NSID;
		CString		s_Username;
		CPhotoSetInfo::PhotoSetInfo_lst_t lst_PhotoSetInfo;
};
