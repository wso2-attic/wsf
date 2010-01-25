#include "stdafx.h"
#include "FlickrUploader.h"
#include "CreateNewSetDialog.h"

IMPLEMENT_DYNAMIC (CCreateNewSetDialog, CDialog)

CCreateNewSetDialog::CCreateNewSetDialog (CWnd* pParent) : CDialog (CCreateNewSetDialog::IDD, pParent)
, s_Name (_T(""))
, s_Description (_T(""))
, p_PhotoSetInfoByName (NULL)
{}


CCreateNewSetDialog::~CCreateNewSetDialog ()
{}


void CCreateNewSetDialog::SetPhotoSetInfo (CPhotoSetInfo::PhotoSetInfoByName_map_t* _pPhotoSetInfoByName)
{
	p_PhotoSetInfoByName = _pPhotoSetInfoByName;
}


void CCreateNewSetDialog::DoDataExchange (CDataExchange* pDX)
{
	CDialog::DoDataExchange (pDX);

	DDX_Text(pDX, IDC_EDIT_NAME, s_Name);
	DDX_Text(pDX, IDC_EDIT_DESCRIPTION, s_Description);
}


BEGIN_MESSAGE_MAP (CCreateNewSetDialog, CDialog)
END_MESSAGE_MAP ()

void CCreateNewSetDialog::OnOK ()
{
	UpdateData ();

	// Validate Name
	s_Name.Trim ();
	if (s_Name == "")
	{
		AfxMessageBox (_T("Please enter photo set name !!!"), MB_ICONEXCLAMATION);
		return;
	}

	if ((p_PhotoSetInfoByName != NULL) && (p_PhotoSetInfoByName->find (s_Name) != p_PhotoSetInfoByName->end ()))
	{
		AfxMessageBox (_T("Photo set name already exits !!!"), MB_ICONEXCLAMATION);
		return;
	}

	s_Description.Trim ();

	CDialog::OnOK ();
}
