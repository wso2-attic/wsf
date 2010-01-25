#include "stdafx.h"
#include "FlickrUploader.h"
#include "WSFCHomeListCtrl.h"

IMPLEMENT_DYNAMIC (CWSFCHomeListCtrl, CListCtrl)

CWSFCHomeListCtrl::CWSFCHomeListCtrl ()
{}


CWSFCHomeListCtrl::~CWSFCHomeListCtrl ()
{}


BEGIN_MESSAGE_MAP (CWSFCHomeListCtrl, CListCtrl)
	ON_WM_CONTEXTMENU ()
	ON_NOTIFY_REFLECT (LVN_ITEMCHANGING, &CWSFCHomeListCtrl::OnLvnItemchanging)
	ON_COMMAND (ID_CONTEXT_MENU_ADD_NEW_HOME, &CWSFCHomeListCtrl::OnAddNew)
	ON_COMMAND (ID_CONTEXT_MENU_REMOVE_HOME, &CWSFCHomeListCtrl::OnRemove)
END_MESSAGE_MAP ()


void CWSFCHomeListCtrl::OnContextMenu (CWnd* pWnd, CPoint point)
{
	CMenu oMenu;
	if (oMenu.LoadMenu (IDR_CONTEXT_MENU))
	{
		CMenu* pPopup = oMenu.GetSubMenu (1);

		int iItemIndex = GetNextItem (-1, LVNI_SELECTED);
		if (iItemIndex != -1)
			pPopup->EnableMenuItem (2, MF_BYPOSITION | MF_ENABLED);

		pPopup->TrackPopupMenu (TPM_LEFTALIGN | TPM_RIGHTBUTTON,
								point.x, 
								point.y,
								this);
	}
}


void CWSFCHomeListCtrl::OnLvnItemchanging (NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
	if ((!IsChecked (pNMLV->uOldState)) && (IsChecked (pNMLV->uNewState))) // Item Checked
	{
		for (int iItemIndex = 0; iItemIndex < GetItemCount (); ++iItemIndex)
		{
			if (iItemIndex != pNMLV->iItem)
				SetCheck (iItemIndex, FALSE);
		}
	}

	*pResult = 0;
}


BOOL CWSFCHomeListCtrl::IsChecked (UINT uState)
{
	return (uState ? ((uState & LVIS_STATEIMAGEMASK) >> 12) - 1 : FALSE);
}

CString	s_TempPath;

int CALLBACK BrowseCallbackProc (HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	TCHAR zDir[MAX_PATH];
	
	switch (uMsg)
	{
		case BFFM_INITIALIZED:
			if (lpData)
			{
				strcpy ((char*)zDir, (char*)s_TempPath.GetBuffer (s_TempPath.GetLength ()));
				::SendMessage (hwnd, BFFM_SETSELECTION, TRUE, (LPARAM)zDir);
			}

			break;
		
		case BFFM_SELCHANGED:
			if (SHGetPathFromIDList ((LPITEMIDLIST) lParam , zDir))
			{
				::SendMessage (hwnd, BFFM_SETSTATUSTEXT, 0, (LPARAM)zDir);
			}
			
			break;
		
		default:
		   break;
	}
         
	return 0;
}


BOOL CWSFCHomeListCtrl::GetFolder(CString*    _pSelectedFolder,
								  const char* _zTitle,
								  const HWND  _hwndOwner, 
								  const char* _zRootFolder, 
								  const char* _zStartFolder)
{
	char pszDisplayName[MAX_PATH];
	LPITEMIDLIST lpID;
	BROWSEINFOA bi;

	bi.hwndOwner = _hwndOwner;

	if (_zRootFolder == NULL)
	{
		bi.pidlRoot = NULL;
	}else
	{
		LPITEMIDLIST  pIdl = NULL;
		IShellFolder* pDesktopFolder;
		char          zPath[MAX_PATH];
		OLECHAR       olePath[MAX_PATH];
		ULONG         chEaten;
		ULONG         dwAttributes;

		strcpy((char*)zPath, _zRootFolder);

		if (SUCCEEDED (SHGetDesktopFolder (&pDesktopFolder)))
		{
			MultiByteToWideChar (CP_ACP, MB_PRECOMPOSED, zPath, -1, olePath, MAX_PATH);
			pDesktopFolder->ParseDisplayName (NULL, NULL, olePath, &chEaten, &pIdl, &dwAttributes);
			pDesktopFolder->Release ();
		}
		
		bi.pidlRoot = pIdl;
	}

	bi.pszDisplayName = pszDisplayName;
	bi.lpszTitle = _zTitle;
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT;
	bi.lpfn = BrowseCallbackProc;

	if (_zStartFolder == NULL)
	{
		bi.lParam = FALSE;
	}else
	{
		s_TempPath.Format (_T("%s"), _zStartFolder);
		bi.lParam = TRUE;
	}

	bi.iImage = NULL;
	lpID = SHBrowseForFolderA (&bi);
	
	if (lpID != NULL)
	{
		BOOL b = SHGetPathFromIDList (lpID, (LPWSTR)pszDisplayName);
		if (b == TRUE)
		{
			_pSelectedFolder->Format (_T("%s"), pszDisplayName);
			return TRUE;
		}
	}else
	{
		_pSelectedFolder->Empty ();
	}

	return FALSE;
}


void CWSFCHomeListCtrl::OnAddNew (void)
{
	// Get WSF/C Home Path
	CString sPath;
	if (FALSE == GetFolder (&sPath, "Find WSF/C Home Location.", this->m_hWnd, NULL, NULL))
		return;
	
	// Validate Path
	if (true == sPath.IsEmpty ())
		return;

	CString sAxis2XMLFile = sPath;
	if (sAxis2XMLFile[sAxis2XMLFile.GetLength () - 1] != '\\')
		sAxis2XMLFile+= "\\";
	sAxis2XMLFile+= "axis2.xml";

	CFile oAxis2XMLFile;
	if (FALSE == oAxis2XMLFile.Open (sAxis2XMLFile, CFile::modeRead | CFile::shareDenyNone))
	{
		CString sMessage = "\"";
				sMessage+= sPath;
				sMessage+= "\" is not a valid WSF/C home !!!";
		AfxMessageBox (sMessage, MB_ICONEXCLAMATION | MB_OK);

		return;
	}

	// Add Path to List Ctrl
	InsertItem (GetItemCount (), sPath);
}


void CWSFCHomeListCtrl::OnRemove (void)
{
	int iItemIndex = GetNextItem (-1, LVNI_SELECTED);
	if (iItemIndex != -1)
		DeleteItem (iItemIndex);
}
