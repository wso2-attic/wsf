#include "stdafx.h"
#include "ShellExtInterface.h"
#include "FlickrUploaderModule.h"
#include "FileUploaderDialog.h"

extern CFlickrUploaderModule _AtlModule;

CShellExtInterface::CShellExtInterface (void)
{
	hbmp_WS = LoadBitmap (((CComModule*)&_AtlModule)->GetModuleInstance(), MAKEINTRESOURCE(IDB_BITMAP_WS));
	hbmp_Flickr = LoadBitmap (((CComModule*)&_AtlModule)->GetModuleInstance(), MAKEINTRESOURCE(IDB_BITMAP_FLICKR));
}


CShellExtInterface::~CShellExtInterface (void)
{
	if (NULL != hbmp_WS)
		DeleteObject (hbmp_WS);
	if (NULL != hbmp_Flickr)
		DeleteObject (hbmp_Flickr);

	// Exit GDI+
	GdiplusShutdown (m_pGdiToken);
}


STDMETHODIMP CShellExtInterface::Initialize (LPCITEMIDLIST pidlFolder, LPDATAOBJECT pDataObj, HKEY hProgID)
{
	FORMATETC fmt = {CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL};
	STGMEDIUM stg = {TYMED_HGLOBAL};
	HDROP     hDrop;

	// Look for CF_HDROP data in the data object.
	if (FAILED (pDataObj->GetData (&fmt, &stg)))
	{
		// Nope! Return an "invalid argument" error back to Explorer.
		return E_INVALIDARG;
	}

	// Get a pointer to the actual data.
	hDrop = (HDROP)GlobalLock (stg.hGlobal);

	// Make sure it worked.
	if (NULL == hDrop)
		return E_INVALIDARG;

	// Sanity check - make sure there is at least one filename.
	UINT uNumFiles = DragQueryFile (hDrop, 0xFFFFFFFF, NULL, 0);
	
	TCHAR zFileName[MAX_PATH];
	for (UINT uFile = 0; uFile < uNumFiles; uFile++)
    {
		// Get the next filename.
		if (0 == DragQueryFile (hDrop, uFile, zFileName, MAX_PATH))
			continue;

		lst_FileName.push_back (zFileName);
	}

	GlobalUnlock (stg.hGlobal);
	ReleaseStgMedium (&stg);

	// Initialize GDI+
	GdiplusStartup (&m_pGdiToken, &m_gdiplusStartupInput, NULL);
	
	return ((lst_FileName.size() > 0) ? S_OK : E_INVALIDARG);
}


STDMETHODIMP CShellExtInterface::QueryContextMenu (HMENU hMenu, UINT uMenuIndex, UINT uidFirstCmd, UINT uidLastCmd, UINT uFlags)
{
	BOOL bAppendItems;
	if ((uFlags & 0x000F) == CMF_NORMAL)
		bAppendItems = TRUE;
	else if (uFlags & CMF_VERBSONLY)
		bAppendItems = TRUE;
	else if (uFlags & CMF_EXPLORE)
		bAppendItems = TRUE;
	else if (uFlags & CMF_DEFAULTONLY)
		bAppendItems = FALSE;
	else
		bAppendItems = FALSE;

	if (bAppendItems)
	{
		int iMenuItemIndex = -1;

		// Check if the Web Services menu is added by another module already
		int iMenuItemCount = GetMenuItemCount (hMenu);
		for (int i = 0; i < iMenuItemCount; ++i)
		{
			// Get Item Text
			MENUITEMINFO mii;
			mii.cbSize = sizeof (MENUITEMINFO);
			mii.fMask = MIIM_STRING;
			mii.dwTypeData = NULL;
			
			GetMenuItemInfo (hMenu, i, TRUE, &mii);
			
			TCHAR* zBuffer = new TCHAR[mii.cch+1];

			MENUITEMINFO mii2;
			mii2.cbSize = sizeof (MENUITEMINFO);
			mii2.fMask = MIIM_STRING;
			mii2.dwTypeData = zBuffer;
			mii2.cch = mii.cch+1;

			GetMenuItemInfo (hMenu, i, TRUE, &mii2);

			CString sItemText = zBuffer;
			delete [] zBuffer;

			if (sItemText == "WeSCli")
			{
				iMenuItemIndex = i;
				break;
			}
		}
		
		HMENU hSubMenu = NULL;
		
		// Get Sub Menu
		if (iMenuItemIndex != -1)
		{
			MENUITEMINFO mii;
			mii.cbSize = sizeof (MENUITEMINFO);
			mii.fMask = MIIM_SUBMENU;

			GetMenuItemInfo (hMenu, iMenuItemIndex, TRUE, &mii);		

			hSubMenu = mii.hSubMenu;
		}
		else
		{
			// Create the popup menu
			hSubMenu = ::CreatePopupMenu ();
		}

		UINT idCmd = uidFirstCmd;

		if (hSubMenu)
		{
			// Append Flickr Upload Item
			int iItemIndex = GetMenuItemCount (hSubMenu);
			InsertMenu (hSubMenu, iItemIndex, MF_STRING | MF_BYPOSITION, idCmd++, _T("Upload to Flickr"));
			SetMenuItemBitmaps (hSubMenu, iItemIndex, MF_BYPOSITION, hbmp_Flickr, hbmp_Flickr);

			/*MENUITEMINFO mii;
			mii.cbSize = sizeof (MENUITEMINFO);
			mii.fMask = MIIM_ID | MIIM_SUBMENU | MIIM_STRING | MIIM_CHECKMARKS;
			mii.wID = idCmd++;
			mii.hSubMenu = hSubMenu;
			mii.dwTypeData = _T("Use Web Services");
			mii.hbmpChecked = hbmp_WS;
			mii.hbmpUnchecked = hbmp_WS;

			InsertMenu (hMenu, uMenuIndex++, MF_SEPARATOR | MF_BYPOSITION, 0, NULL);
			InsertMenuItem (hMenu, uMenuIndex++, TRUE, &mii);
			InsertMenu (hMenu, uMenuIndex++, MF_SEPARATOR | MF_BYPOSITION, 0, NULL);*/
		}

		if (iMenuItemIndex == -1) // Sub menu is not added already
		{
			MENUITEMINFO mii;
			mii.cbSize = sizeof (MENUITEMINFO);
			mii.fMask = MIIM_ID | MIIM_SUBMENU | MIIM_STRING | MIIM_CHECKMARKS;
			mii.wID = idCmd++;
			mii.hSubMenu = hSubMenu;
			mii.dwTypeData = _T("WeSCli");
			mii.hbmpChecked = hbmp_WS;
			mii.hbmpUnchecked = hbmp_WS;

			InsertMenu (hMenu, uMenuIndex++, MF_SEPARATOR | MF_BYPOSITION, 0, NULL);
			InsertMenuItem (hMenu, uMenuIndex++, TRUE, &mii);
			InsertMenu (hMenu, uMenuIndex++, MF_SEPARATOR | MF_BYPOSITION, 0, NULL);
		}

		return MAKE_HRESULT (SEVERITY_SUCCESS, FACILITY_NULL, idCmd - uidFirstCmd);
	}

	return MAKE_HRESULT (SEVERITY_SUCCESS, FACILITY_NULL, 0);//return NOERROR;
}


STDMETHODIMP CShellExtInterface::GetCommandString (UINT idCmd, UINT uFlags, UINT* pwReserved, LPSTR pszName, UINT cchMax)
{
	USES_CONVERSION;

	// Check idCmd, it must be 0 since we have only one menu item.
	if (0 != idCmd)
		return E_INVALIDARG;

	// If Explorer is asking for a help string, copy our string into the
	// supplied buffer.
	if (uFlags & GCS_HELPTEXT)
	{
		LPCTSTR szText = _T("Upload to www.flickr.com");

		if (uFlags & GCS_UNICODE)
		{
			// We need to cast pszName to a Unicode string, and then use the
			// Unicode string copy API.
			lstrcpynW ((LPWSTR)pszName, T2CW(szText), cchMax);
		}
		else
		{
			// Use the ANSI string copy API to return the help string.
			lstrcpynA (pszName, T2CA(szText), cchMax);
		}

		return S_OK;
	}

	return E_INVALIDARG;
}


STDMETHODIMP CShellExtInterface::InvokeCommand (LPCMINVOKECOMMANDINFO pCmdInfo)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState()); // This is essential to use MFC

	// If lpVerb really points to a string, ignore this function call and bail out.
	if (0 != HIWORD(pCmdInfo->lpVerb))
		return E_INVALIDARG;

	// Get the command index - the only valid one is 0.
	switch (LOWORD(pCmdInfo->lpVerb))
	{
		case 0:
			{
				CFileUploaderDialog oDialog;
				oDialog.SetFileNames (lst_FileName);

				oDialog.DoModal ();

				return S_OK;
			}
			break;

		default:
			return E_INVALIDARG;
			break;
	}
}
