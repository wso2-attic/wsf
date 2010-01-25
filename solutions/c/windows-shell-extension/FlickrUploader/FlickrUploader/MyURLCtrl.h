#pragma once

class CMyURLCtrl : public CWnd
{
	DECLARE_DYNAMIC (CMyURLCtrl)

	public:
		CMyURLCtrl ();
		virtual ~CMyURLCtrl ();

		void SetText (CString _sText);

		afx_msg void OnPaint       (void);
		afx_msg void OnMouseMove   (UINT nFlags, CPoint point);
		afx_msg void OnLButtonDown (UINT nFlags, CPoint point);
		afx_msg void OnLButtonUp   (UINT nFlags, CPoint point);

	protected:
		DECLARE_MESSAGE_MAP ()

		CString		s_Text;
		CFont		o_Font;
};
