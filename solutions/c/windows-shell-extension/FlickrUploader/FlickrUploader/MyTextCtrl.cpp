#include "stdafx.h"
#include "FlickrUploader.h"
#include "MyTextCtrl.h"

IMPLEMENT_DYNAMIC (CMyTextCtrl, CWnd)

CMyTextCtrl::CMyTextCtrl ()
{
	s_Text = "";
}


void CMyTextCtrl::Init (COLORREF _crTextColor, bool _bBold, int _iFontHeight)
{
	cr_TextColor = _crTextColor;

	// Create Font
	int iWeight = _bBold ? FW_BOLD : FW_NORMAL;

	o_Font.CreateFont (_iFontHeight,                // nHeight
					   0,							// nWidth
					   0,							// nEscapement
					   0,							// nOrientation
					   iWeight,						// nWeight
					   FALSE,						// bItalic
					   FALSE,						// bUnderline
					   FALSE,						// cStrikeOut
					   ANSI_CHARSET,				// nCharSet
					   OUT_DEFAULT_PRECIS,			// nOutPrecision
					   CLIP_DEFAULT_PRECIS,			// nClipPrecision
					   CLEARTYPE_QUALITY,           // nQuality
					   DEFAULT_PITCH | FF_SWISS,	// nPitchAndFamily
					   _T("Microsoft Sans Serif"));	// lpszFacename);
}


CMyTextCtrl::~CMyTextCtrl ()
{
	o_Font.DeleteObject ();
}


BEGIN_MESSAGE_MAP (CMyTextCtrl, CWnd)
	ON_WM_PAINT ()
END_MESSAGE_MAP ()


void CMyTextCtrl::OnPaint ()
{
	CPaintDC dc (this);
	
	// Set Current Drawing Properties
	CFont* pCurrentFont = dc.SelectObject (&o_Font);
	COLORREF crCurrentTextColor = dc.SetTextColor (cr_TextColor);

	CRect rc;
	GetWindowRect (&rc);
	ScreenToClient (rc);
	
	dc.SetBkMode (TRANSPARENT);

	dc.DrawText (s_Text, rc, DT_SINGLELINE | DT_LEFT | DT_VCENTER | DT_END_ELLIPSIS);
	
	// Reset Drawing Properties
	dc.SelectObject (pCurrentFont);
	dc.SetTextColor (crCurrentTextColor);
}


void CMyTextCtrl::SetText (CString _sText)
{
	s_Text = _sText;	
}
