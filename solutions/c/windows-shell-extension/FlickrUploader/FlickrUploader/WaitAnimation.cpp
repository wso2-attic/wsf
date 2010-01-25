#include "stdafx.h"
#include "WaitAnimation.h"

IMPLEMENT_DYNAMIC (CWaitAnimation, CWnd)

CWaitAnimation::CWaitAnimation (void)
{
	i_BlockIndex = 0;

	o_BrushGreen.CreateSolidBrush (RGB (20, 150, 20));
	o_BrushAsh.CreateSolidBrush (RGB (150, 150, 150));
	o_BorderBrushBlack.CreateSolidBrush (RGB (0, 0, 0));	
}

CWaitAnimation::~CWaitAnimation(void)
{
	o_BrushGreen.DeleteObject ();
	o_BrushAsh.DeleteObject ();
	o_BorderBrushBlack.DeleteObject ();
}


void CWaitAnimation::Reset (void)
{
	i_BlockIndex = 0;
}


BEGIN_MESSAGE_MAP (CWaitAnimation, CWnd)	
	ON_WM_TIMER ()
	ON_WM_CREATE ()
	ON_WM_PAINT ()
END_MESSAGE_MAP ()


int CWaitAnimation::OnCreate (LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate (lpCreateStruct) == -1)
		return -1;

	i_BlockIndex = 0;

	SetTimer (TID_DRAW_BLOCK, 100, NULL);

	return 0;
}


void CWaitAnimation::OnPaint ()
{
	CPaintDC dc (this);
	
	// Create Buffer
	CDC oDC;
	oDC.CreateCompatibleDC (&dc);

	CRect oRect;
	GetClientRect (oRect);
	
	CBitmap oBitmap;
	oBitmap.CreateDiscardableBitmap (&dc, oRect.Width (), oRect.Height ());

	oDC.SelectObject (&oBitmap);

	oDC.FillSolidRect (oRect, RGB (236, 233, 216));
 
	// Draw Animation into the Buffer
	// Draw Block Frames
	for (int i = 0; i < NUM_OF_BLOCKS; i++)
	{
		CPoint ptBlock ((oRect.TopLeft ().x + i * (3 + oRect.Height ())), oRect.TopLeft ().y);
		CSize szBlock (oRect.Height (), oRect.Height ());
		CRect rcBlock (ptBlock, szBlock);

		oDC.FrameRect (rcBlock, &o_BrushAsh);
	}

	// Current Highlighted Block
	CPoint ptBlock ((oRect.TopLeft ().x + i_BlockIndex * (3 + oRect.Height ())), oRect.TopLeft ().y);
	CSize szBlock (oRect.Height (), oRect.Height ());
	CRect rcBlock (ptBlock, szBlock);

	oDC.FillRect (rcBlock, &o_BrushGreen);
	oDC.FrameRect (rcBlock, &o_BorderBrushBlack);

	// Draw Animation into the Screen
	dc.BitBlt (0, 0, oRect.Width (), oRect.Height (), &oDC, 0, 0, SRCCOPY);

	oBitmap.DeleteObject ();
	oDC.DeleteDC ();
}


void CWaitAnimation::OnTimer (UINT nIDEvent)
{
	if (nIDEvent == TID_DRAW_BLOCK)
	{
		if (i_BlockIndex == NUM_OF_BLOCKS - 1)
			i_BlockIndex = 0;
		else
			i_BlockIndex++;

		RedrawWindow ();
	}
	
	CWnd::OnTimer (nIDEvent);
}
