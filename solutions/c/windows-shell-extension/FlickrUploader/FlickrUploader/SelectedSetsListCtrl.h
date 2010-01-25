#pragma once

class CSelectedSetsListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC (CSelectedSetsListCtrl)

	public:
		CSelectedSetsListCtrl ();
		virtual ~CSelectedSetsListCtrl ();

		void	SetButton	(CButton* _pButton);

		afx_msg void OnNMClick	(NMHDR *pNMHDR, LRESULT *pResult);

	protected:
		DECLARE_MESSAGE_MAP ()

	private:
		CButton*	p_Button; // Button to Remove Items from the Selected List
};
