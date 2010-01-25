#include "stdafx.h"
#include "FlickrUploader.h"
#include "CreateNewSetDialog.h"
#include "FileUploaderDialog.h"
#include "AvailableSetsListCtrl.h"

IMPLEMENT_DYNAMIC (CAvailableSetsListCtrl, CListCtrl)

CAvailableSetsListCtrl::CAvailableSetsListCtrl ()
{
	p_Button = NULL;
	p_PhotoSetInfoByName = NULL;
	b_UserSignedIn = false;
	b_Pro = false;
	i_RemainingSetCount = 0;
}

CAvailableSetsListCtrl::~CAvailableSetsListCtrl ()
{}


void CAvailableSetsListCtrl::SetButton (CButton* _pButton)
{
	p_Button = _pButton;
}


void CAvailableSetsListCtrl::SetPhotoSetInfo (CPhotoSetInfo::PhotoSetInfoByName_map_t* _pPhotoSetInfoByName)
{
	p_PhotoSetInfoByName = _pPhotoSetInfoByName;
}


void CAvailableSetsListCtrl::SetUserSignedIn (bool _bUserSignedIn)
{
	b_UserSignedIn = _bUserSignedIn;
}


void CAvailableSetsListCtrl::SetPro (bool _bPro)
{
	b_Pro = _bPro;
}


void CAvailableSetsListCtrl::SetRemainingSetCount (int _iRemainingSetCount)
{
	i_RemainingSetCount = _iRemainingSetCount;
}


BEGIN_MESSAGE_MAP (CAvailableSetsListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT (NM_CLICK, &CAvailableSetsListCtrl::OnNMClick)
	ON_WM_CONTEXTMENU ()
	ON_COMMAND (ID_CONTEXT_MENU_CREATE_NEW_SET, &CAvailableSetsListCtrl::OnCreateNewSet)
	ON_COMMAND (ID_CONTEXT_MENU_REMOVE_SET, &CAvailableSetsListCtrl::OnRemoveSet)
END_MESSAGE_MAP ()


void CAvailableSetsListCtrl::OnNMClick (NMHDR *pNMHDR, LRESULT *pResult)
{
	if (p_Button == NULL)
		return;

	int iItemIndex = GetNextItem (-1, LVNI_SELECTED);

	if (iItemIndex == -1) // Not Selected
		p_Button->EnableWindow (false);
	else // Selected
		p_Button->EnableWindow (true);

	*pResult = 0;
}


void CAvailableSetsListCtrl::OnContextMenu (CWnd* pWnd, CPoint point)
{
	CMenu oMenu;
	if (oMenu.LoadMenu (IDR_CONTEXT_MENU))
	{
		CMenu* pPopup = oMenu.GetSubMenu (0);

		// Disable Menu Items
		// Create New
		if ((false == b_UserSignedIn) || ((false == b_Pro) && (0 == i_RemainingSetCount)))
			pPopup->EnableMenuItem (0, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);

		// Remove
		int iItemIndex = GetNextItem (-1, LVNI_SELECTED);
		if (iItemIndex != -1)
		{
			CString sName = GetItemText (iItemIndex, 0);
			CPhotoSetInfo* pPhotoSetInfo = ((CFileUploaderDialog*)GetParent ())->GetPhotoSetInfo (sName);

			if ((pPhotoSetInfo != NULL) && (pPhotoSetInfo->b_New == true))
				pPopup->EnableMenuItem (2, MF_BYPOSITION | MF_ENABLED);
		}

		pPopup->TrackPopupMenu (TPM_LEFTALIGN | TPM_RIGHTBUTTON,
								point.x, 
								point.y,
								this);
	}
}


void CAvailableSetsListCtrl::OnCreateNewSet ()
{
	if (NULL == p_PhotoSetInfoByName)
		return;

	CCreateNewSetDialog oDialog;
	oDialog.SetPhotoSetInfo (p_PhotoSetInfoByName);

	if (IDOK == oDialog.DoModal ())
	{
		// Store New Set Data
		p_PhotoSetInfoByName->insert (make_pair (oDialog.s_Name, new CPhotoSetInfo (oDialog.s_Name, oDialog.s_Description, _T(""), true)));

		// Show New Set Data
		InsertItem (GetItemCount (), oDialog.s_Name, 1);

		i_RemainingSetCount--;
	}
}


void CAvailableSetsListCtrl::OnRemoveSet ()
{
	int iItemIndex = GetNextItem (-1, LVNI_SELECTED);
	if (iItemIndex != -1)
	{
		CString sName = GetItemText (iItemIndex, 0);
		
		// Remove Set Data from the Data Structures
		((CFileUploaderDialog*)GetParent ())->RemovePhotoSetInfo (sName);

		// Remove Set from the ListCtrl
		DeleteItem (iItemIndex);

		i_RemainingSetCount++;
	}
}
