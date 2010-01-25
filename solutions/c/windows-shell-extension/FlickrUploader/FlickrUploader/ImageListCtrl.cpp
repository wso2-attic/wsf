#include "stdafx.h"
#include "FlickrUploader.h"
#include "FileUploaderDialog.h"
#include "ImageListCtrl.h"

IMPLEMENT_DYNAMIC (CImageListCtrl, CListCtrl)

CImageListCtrl::CImageListCtrl ()
{}


CImageListCtrl::~CImageListCtrl ()
{}


BEGIN_MESSAGE_MAP (CImageListCtrl, CListCtrl)
	ON_WM_CREATE ()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_NOTIFY_REFLECT(NM_CLICK, &CImageListCtrl::OnNMClick)
END_MESSAGE_MAP ()


void CImageListCtrl::ShowImageThumbnails (FileName_lst_t _lstFileName)
{
	// hold the window update to avoid flicking
	SetRedraw (FALSE);

	// set the size of the image list
	m_ImageList.SetImageCount ((UINT)_lstFileName.size ());
	
	CBitmap mfcBmp;			// mfc bitmap that we must put in the image list
	Bitmap* pGdiBmp = NULL; // gdi+ bitmap we load
	Bitmap* pThumb = NULL;  // thumbnail
	HBITMAP hBmp = NULL;
	int iImageIndex = 0;

	while (_lstFileName.empty () == false)
	{
		CString sFileName = _lstFileName.front ();
				
		pGdiBmp = Bitmap::FromFile (sFileName);
		if (pGdiBmp != NULL)
		{
			if ((pGdiBmp->GetHeight () == THUMBNAIL_HEIGHT) && 
				(pGdiBmp->GetWidth () == THUMBNAIL_WIDTH))
			{
				pThumb = pGdiBmp;  
			}
			else
			{
				pThumb = (Bitmap*)pGdiBmp->GetThumbnailImage (THUMBNAIL_WIDTH, THUMBNAIL_HEIGHT);
			}

			if (pThumb != NULL)
			{
				pThumb->GetHBITMAP (Color(255,255,255), &hBmp);		

				mfcBmp.Attach (hBmp);

				// add bitmap to our image list
				m_ImageList.Replace (iImageIndex, &mfcBmp, NULL);

				// put item to display
				// set the image file name as item text
				CString sFileNameDisp = sFileName.Right (sFileName.GetLength() - sFileName.ReverseFind ('\\') - 1);
				InsertItem (iImageIndex, sFileNameDisp, iImageIndex);

				iImageIndex++;

				mfcBmp.Detach ();
				if (pThumb != pGdiBmp)
					delete pThumb; //delete it only if it was creted separately
				delete pGdiBmp;		
				::DeleteObject (hBmp);
				pGdiBmp = pThumb = NULL;
				hBmp = NULL;
			}
		}

		_lstFileName.pop_front ();
	}

	//SetItemState (0, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);

	SetRedraw (TRUE);
	SetFocus ();
}


int CImageListCtrl::OnCreate (LPCREATESTRUCT lpCreateStruct)
{
	if (CListCtrl::OnCreate (lpCreateStruct) == -1)
		return -1;

	m_ImageList.Create (THUMBNAIL_WIDTH, THUMBNAIL_HEIGHT, ILC_COLOR24, 0, 1);
	SetImageList (&m_ImageList, LVSIL_NORMAL);

	return 0;
}


void CImageListCtrl::OnLButtonDown (UINT nFlags, CPoint point)
{
	int iItemIndex = GetNextItem (-1, LVNI_SELECTED);
	if (iItemIndex != -1) // Index of the Item Selected at the Moment
	{
		((CFileUploaderDialog*)GetParent ())->StoreImageDetails (iItemIndex);
	}

	CListCtrl::OnLButtonDown (nFlags, point);
}


void CImageListCtrl::OnNMClick (NMHDR *pNMHDR, LRESULT *pResult)
{
	int iItemIndex = GetNextItem (-1, LVNI_SELECTED);
	
	if (iItemIndex != -1) // Item Selected
	{
		((CFileUploaderDialog*)GetParent ())->ShowImageDetails (iItemIndex);
		((CFileUploaderDialog*)GetParent ())->EnableImageControls (TRUE);
	}
	else
	{
		((CFileUploaderDialog*)GetParent ())->EnableImageControls (FALSE);
	}

	*pResult = 0;
}
