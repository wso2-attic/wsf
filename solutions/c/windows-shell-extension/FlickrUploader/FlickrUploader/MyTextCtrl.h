#pragma once

class CMyTextCtrl : public CWnd
{
	DECLARE_DYNAMIC (CMyTextCtrl)

	public:
		CMyTextCtrl ();
		virtual ~CMyTextCtrl ();

		void Init	 (COLORREF _crTextColor, bool _bBold = false, int _iFontHeight = 14);
		void SetText (CString _sText);

		afx_msg void OnPaint ();

	protected:
		DECLARE_MESSAGE_MAP ()

		CString		s_Text;
		COLORREF	cr_TextColor;
		CFont		o_Font;
};