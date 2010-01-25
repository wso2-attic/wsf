#include "StdAfx.h"
#include "ImageDetails.h"

CImageDetails::CImageDetails (void)
{
	s_Title = "";
	s_Description = "";
	s_Tags = "";
	b_OnlyMe = true;
	b_Family = false;
	b_Friends = false;
	b_Anyone = false;
	i_SafetyLevel = 1;
	i_Hidden = 1;
	i_ContentType = 1;
	s_FileName = "";
	s_FileSize = "";
}

CImageDetails::~CImageDetails (void)
{}
