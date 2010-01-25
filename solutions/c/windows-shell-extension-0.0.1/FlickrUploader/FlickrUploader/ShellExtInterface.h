#pragma once

#include "resource.h"       // main symbols
#include <shlobj.h>
#include <comdef.h>
#include "FlickrUploader.h"
#include <list>

using namespace std;

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

// CShellExtInterface

class ATL_NO_VTABLE CShellExtInterface :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CShellExtInterface, &CLSID_ShellExtInterface>,
	public IShellExtInit,
	public IContextMenu
{
	public:
		CShellExtInterface (void);
		~CShellExtInterface (void);

		DECLARE_REGISTRY_RESOURCEID(IDR_SHELLEXTINTERFACE)

		DECLARE_NOT_AGGREGATABLE(CShellExtInterface)

		BEGIN_COM_MAP(CShellExtInterface)
			COM_INTERFACE_ENTRY(IShellExtInit)
			COM_INTERFACE_ENTRY_IID(IID_IContextMenu,IContextMenu)
		END_COM_MAP()

		DECLARE_PROTECT_FINAL_CONSTRUCT()

		HRESULT FinalConstruct()
		{
			return S_OK;
		}

		void FinalRelease()
		{
		}

		// IShellExtInit
		STDMETHODIMP Initialize		  (LPCITEMIDLIST pidlFolder, LPDATAOBJECT pDataObj, HKEY hProgID);

		// IContextMenu
		STDMETHODIMP QueryContextMenu (HMENU hMenu, UINT uMenuIndex, UINT uidFirstCmd, UINT uidLastCmd, UINT uFlags);
		STDMETHODIMP GetCommandString (UINT idCmd, UINT uFlags, UINT* pwReserved, LPSTR pszName, UINT cchMax);
		STDMETHODIMP InvokeCommand	  (LPCMINVOKECOMMANDINFO pCmdInfo);
	
	protected:
		typedef list<CString>	FileName_lst_t;

		HBITMAP					hbmp_WS;
		HBITMAP					hbmp_Flickr;
		FileName_lst_t			lst_FileName;
		GdiplusStartupInput		m_gdiplusStartupInput;
		ULONG_PTR				m_pGdiToken;
};

OBJECT_ENTRY_AUTO(__uuidof(ShellExtInterface), CShellExtInterface)
