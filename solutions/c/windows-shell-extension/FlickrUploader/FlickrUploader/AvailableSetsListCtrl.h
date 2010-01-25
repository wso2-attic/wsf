#pragma once

#include "PhotoSetInfo.h"

class CAvailableSetsListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC (CAvailableSetsListCtrl)

	public:
		CAvailableSetsListCtrl ();
		virtual ~CAvailableSetsListCtrl ();

		void	SetButton			 (CButton* _pButton);
		void	SetPhotoSetInfo		 (CPhotoSetInfo::PhotoSetInfoByName_map_t* _pPhotoSetInfoByName);
		void	SetUserSignedIn		 (bool _bUserSignedIn);
		void	SetPro				 (bool _bPro);
		void	SetRemainingSetCount (int _iRemainingSetCount);

		afx_msg void OnNMClick		 (NMHDR *pNMHDR, LRESULT *pResult);
		afx_msg void OnContextMenu	 (CWnd* pWnd, CPoint point);
		afx_msg void OnCreateNewSet	 ();
		afx_msg void OnRemoveSet	 ();

	protected:
		DECLARE_MESSAGE_MAP ()

	private:
		CButton*									p_Button; // Button to Add Items to the Selected List
		CPhotoSetInfo::PhotoSetInfoByName_map_t*	p_PhotoSetInfoByName;
		bool										b_UserSignedIn;
		bool										b_Pro;
		int											i_RemainingSetCount;
};
