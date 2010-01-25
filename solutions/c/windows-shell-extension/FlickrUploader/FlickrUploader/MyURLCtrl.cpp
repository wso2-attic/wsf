#include "stdafx.h"
#include "FlickrUploader.h"
#include "MyURLCtrl.h"

IMPLEMENT_DYNAMIC (CMyURLCtrl, CWnd)

CMyURLCtrl::CMyURLCtrl ()
{
	s_Text = "";

	// Create Font
	o_Font.CreateFont (14,			                // nHeight
					   0,							// nWidth
					   0,							// nEscapement
					   0,							// nOrientation
					   FW_NORMAL,					// nWeight
					   FALSE,						// bItalic
					   TRUE,						// bUnderline
					   FALSE,						// cStrikeOut
					   ANSI_CHARSET,				// nCharSet
					   OUT_DEFAULT_PRECIS,			// nOutPrecision
					   CLIP_DEFAULT_PRECIS,			// nClipPrecision
					   CLEARTYPE_QUALITY,           // nQuality
					   DEFAULT_PITCH | FF_SWISS,	// nPitchAndFamily
					   _T("Microsoft Sans Serif"));	// lpszFacename);
}


CMyURLCtrl::~CMyURLCtrl ()
{
	o_Font.DeleteObject ();
}


BEGIN_MESSAGE_MAP (CMyURLCtrl, CWnd)
	ON_WM_PAINT ()
	ON_WM_MOUSEMOVE ()
	ON_WM_LBUTTONDOWN ()
	ON_WM_LBUTTONUP ()
END_MESSAGE_MAP ()


void CMyURLCtrl::OnPaint (void)
{
	CPaintDC dc (this);

	// Set Current Drawing Properties
	CFont* pCurrentFont = dc.SelectObject (&o_Font);
	COLORREF crCurrentTextColor = dc.SetTextColor (RGB (0, 0, 255));

	CRect rc;
	GetWindowRect (&rc);
	ScreenToClient (rc);
	
	dc.SetBkMode (TRANSPARENT);

	dc.DrawText (s_Text, rc, DT_SINGLELINE | DT_LEFT | DT_VCENTER | DT_END_ELLIPSIS);
	
	// Reset Drawing Properties
	dc.SelectObject (pCurrentFont);
	dc.SetTextColor (crCurrentTextColor);
}


void CMyURLCtrl::SetText (CString _sText)
{
	s_Text = _sText;
}


void CMyURLCtrl::OnMouseMove (UINT nFlags, CPoint point)
{
	HCURSOR hCursor = LoadCursor (NULL, IDC_HAND);
	SetCursor (hCursor);

	CWnd::OnMouseMove (nFlags, point);
}


void CMyURLCtrl::OnLButtonDown (UINT nFlags, CPoint point)
{
	HCURSOR hCursor = LoadCursor (NULL, IDC_HAND);
	SetCursor (hCursor);

	// Launch the Default Web Browser and Open URL
	ShellExecute (NULL, _T("open"), s_Text, NULL, NULL, SW_SHOWNORMAL);

	CWnd::OnLButtonDown (nFlags, point);
}


void CMyURLCtrl::OnLButtonUp (UINT nFlags, CPoint point)
{
	HCURSOR hCursor = LoadCursor (NULL, IDC_WAIT);
	SetCursor (hCursor);

	CWnd::OnLButtonUp (nFlags, point);
}
