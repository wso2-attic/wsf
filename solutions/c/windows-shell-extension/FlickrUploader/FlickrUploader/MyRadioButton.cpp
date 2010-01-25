#include "stdafx.h"
#include "FlickrUploader.h"
#include "MyRadioButton.h"

IMPLEMENT_DYNAMIC (CMyRadioButton, CButton)

CMyRadioButton::CMyRadioButton ()
{
	b_Enable = false;
	p_FamilyCheckBox = NULL;
	p_FriendsCheckBox = NULL;
}


CMyRadioButton::~CMyRadioButton ()
{}


void CMyRadioButton::SetEnable (bool _bEnable)
{
	b_Enable = _bEnable;
}


void CMyRadioButton::SetFamilyCheckBox (CButton* _pFamilyCheckBox)
{
	p_FamilyCheckBox = _pFamilyCheckBox;
}


void CMyRadioButton::SetFriendsCheckBox (CButton* _pFriendsCheckBox)
{
	p_FriendsCheckBox = _pFriendsCheckBox;
}


BEGIN_MESSAGE_MAP (CMyRadioButton, CButton)
	ON_WM_LBUTTONUP ()
END_MESSAGE_MAP ()


void CMyRadioButton::OnLButtonUp (UINT nFlags, CPoint point)
{
	if ((p_FamilyCheckBox == NULL) || (p_FriendsCheckBox == NULL))
		return;

	// Reset Values
	p_FamilyCheckBox->SetCheck (false);
	p_FriendsCheckBox->SetCheck (false);

	// Enable/Disable
	p_FamilyCheckBox->EnableWindow (b_Enable);
	p_FriendsCheckBox->EnableWindow (b_Enable);

	CButton::OnLButtonUp (nFlags, point);
}
