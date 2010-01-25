#include "StdAfx.h"
#include "PhotoSetInfo.h"

CPhotoSetInfo::CPhotoSetInfo (CString _sName, CString _sDescription, CString _sID, bool _bNew)
{
	s_Name = _sName;
	s_Description = _sDescription;
	s_ID = _sID;
	b_New = _bNew;
}


CPhotoSetInfo::~CPhotoSetInfo (void)
{}


CPhotoSetInfo* CPhotoSetInfo::Clone (void)
{
	return (new CPhotoSetInfo (s_Name, s_Description, s_ID, b_New));
}

