#pragma once

#define		TID_DRAW_BLOCK			50
#define		NUM_OF_BLOCKS			15

// CWaitAnimation

class CWaitAnimation : public CWnd
{
	DECLARE_DYNAMIC (CWaitAnimation)

	public:
		CWaitAnimation (void);
		virtual ~CWaitAnimation (void);

		void	Reset		  (void);

		afx_msg void OnTimer  (UINT nIDEvent);
		afx_msg int  OnCreate (LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnPaint  ();
		
	protected:
		int		i_BlockIndex;

		// Fill Brushes
		CBrush	o_BrushGreen;
		CBrush	o_BrushAsh;
		
		// Border Brushes
		CBrush	o_BorderBrushBlack;

		DECLARE_MESSAGE_MAP ()		
};


