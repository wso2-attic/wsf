#include "StdAfx.h"
#include "WMParam.h"

CWMParam::CWMParam (void)
{
	i_PhotoIndex = -1;
	s_PhotoID = "";
	s_PhotoTitle = "";
	s_PhotoSetName = "";
	s_PhotoSetID = "";
	b_Success = false;
	s_PhotosURL = "";
	s_ProfileURL = "";
	s_AvailableQuota = "";
	s_AvailableQuota = "";
	i_RemainingSetCount = 0;
	b_Pro = false;
	s_Frob = "";
	s_AuthURL = "";
	s_Token = "";
	s_NSID = "";
	s_Username = "";
}


CWMParam::~CWMParam (void)
{}
