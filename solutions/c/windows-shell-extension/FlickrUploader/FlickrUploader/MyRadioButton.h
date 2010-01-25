#pragma once

class CMyRadioButton : public CButton
{
	DECLARE_DYNAMIC (CMyRadioButton)

	public:
		CMyRadioButton ();
		virtual ~CMyRadioButton ();

		afx_msg void OnLButtonUp (UINT nFlags, CPoint point);

		void	SetEnable		   (bool _bEnable);
		void	SetFamilyCheckBox  (CButton* _pFamilyCheckBox);
		void	SetFriendsCheckBox (CButton* _pFriendsCheckBox);

	protected:
		DECLARE_MESSAGE_MAP ()

	private:
		bool		b_Enable;
		CButton*	p_FamilyCheckBox;
		CButton*	p_FriendsCheckBox;
};
