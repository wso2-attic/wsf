#include "StdAfx.h"
#include "UserAuthInfo.h"

CUserAuthInfo::CUserAuthInfo (CString _sToken, CString _sNSID, CString _sUsername)
{
	s_Token = _sToken;
	s_NSID = _sNSID;
	s_Username = _sUsername;
}


CUserAuthInfo::~CUserAuthInfo (void)
{}
