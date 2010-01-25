#pragma once

class CUserAuthInfo
{
	public:
		CUserAuthInfo (CString _sToken, CString _sNSID, CString _sUsername);
		~CUserAuthInfo (void);

		CString		s_Token;
		CString		s_NSID;
		CString		s_Username;
};
