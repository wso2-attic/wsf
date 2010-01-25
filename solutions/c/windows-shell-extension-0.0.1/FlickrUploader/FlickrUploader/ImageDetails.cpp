#include "StdAfx.h"
#include "ImageDetails.h"

CImageDetails::CImageDetails (void)
{
	s_FileName = "";
	s_FileSize = "";
	s_Title = "";
	s_Description = "";
	s_Tags = "";
	c_OnlyMe = 1;
	c_Family = 0;
	c_Friends = 0;
	c_Anyone = 0;
	c_SafetyLevel = 0;
	c_Hidden = 0;
	c_ContentType = 0;;
}

CImageDetails::~CImageDetails (void)
{}
