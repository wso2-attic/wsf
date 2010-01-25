#include "StdAfx.h"
#include "UploadStatus.h"

CUploadStatus::CUploadStatus (CString _sAvailableQuota, int _iRemainingSetCount, bool _bPro)
{
	s_AvailableQuota = _sAvailableQuota;
	i_RemainingSetCount = _iRemainingSetCount;
	b_Pro = _bPro;
}


CUploadStatus::~CUploadStatus (void)
{}
