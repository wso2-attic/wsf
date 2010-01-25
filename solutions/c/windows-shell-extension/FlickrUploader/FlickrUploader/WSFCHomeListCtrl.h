#pragma once

class CWSFCHomeListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC (CWSFCHomeListCtrl)
 
	public:
		CWSFCHomeListCtrl ();
		virtual ~CWSFCHomeListCtrl ();

		afx_msg void OnContextMenu     (CWnd* pWnd, CPoint point);
		afx_msg void OnLvnItemchanging (NMHDR *pNMHDR, LRESULT *pResult);
		afx_msg void OnAddNew          (void);
		afx_msg void OnRemove          (void);

	protected:
		DECLARE_MESSAGE_MAP ()

	private:
		BOOL IsChecked	(UINT uState);
		BOOL GetFolder	(CString*    _pSelectedFolder,
					     const char* _zTitle,
				         const HWND  _hwndOwner, 
				         const char* _zRootFolder, 
				         const char* _zStartFolder);
};
