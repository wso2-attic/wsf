#pragma once

class CUploadStatus
{
	public:
		CUploadStatus (CString _sAvailableQuota, int _iRemainingSetCount, bool _bPro);
		~CUploadStatus (void);

		CString		s_AvailableQuota;
		int			i_RemainingSetCount;
		bool		b_Pro;
};
