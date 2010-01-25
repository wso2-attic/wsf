#include "stdafx.h"
#include "FlickrUploader.h"
#include "SelectedSetsListCtrl.h"

IMPLEMENT_DYNAMIC (CSelectedSetsListCtrl, CListCtrl)

CSelectedSetsListCtrl::CSelectedSetsListCtrl ()
{
	p_Button = NULL;
}


CSelectedSetsListCtrl::~CSelectedSetsListCtrl ()
{}


void CSelectedSetsListCtrl::SetButton (CButton* _pButton)
{
	p_Button = _pButton;
}


BEGIN_MESSAGE_MAP (CSelectedSetsListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CLICK, &CSelectedSetsListCtrl::OnNMClick)
END_MESSAGE_MAP ()


void CSelectedSetsListCtrl::OnNMClick (NMHDR *pNMHDR, LRESULT *pResult)
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
