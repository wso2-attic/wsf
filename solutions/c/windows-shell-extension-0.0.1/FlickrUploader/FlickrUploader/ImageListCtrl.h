#pragma once

#include <list>
using namespace std;

#define	THUMBNAIL_WIDTH		100
#define	THUMBNAIL_HEIGHT	78

class CImageListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CImageListCtrl)

	public:
		CImageListCtrl ();
		virtual ~CImageListCtrl ();

		typedef list<CString>		FileName_lst_t;
		void	ShowImageThumbnails	(FileName_lst_t _lstFileName);

		afx_msg int  OnCreate      (LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnLButtonDown (UINT nFlags, CPoint point);		  // To save details
		afx_msg void OnNMClick     (NMHDR *pNMHDR, LRESULT *pResult); // To show details

	protected:
		CImageList	m_ImageList;

	DECLARE_MESSAGE_MAP ()
};
