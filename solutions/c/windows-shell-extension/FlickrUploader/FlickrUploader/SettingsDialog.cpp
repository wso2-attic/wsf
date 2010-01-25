#include "stdafx.h"
#include "FlickrUploader.h"
#include "SettingsDialog.h"

IMPLEMENT_DYNAMIC (CSettingsDialog, CDialog)

CSettingsDialog::CSettingsDialog (CWnd* pParent) : CDialog (CSettingsDialog::IDD, pParent)
{
	s_WSFCHome = "";
}


CSettingsDialog::~CSettingsDialog ()
{}


void CSettingsDialog::DoDataExchange (CDataExchange* pDX)
{
	CDialog::DoDataExchange (pDX);
	DDX_Control (pDX, IDC_WSFC_HOME_LIST_CTRL, m_WSFCHomeListCtrl);
}


BEGIN_MESSAGE_MAP (CSettingsDialog, CDialog)
END_MESSAGE_MAP ()


BOOL CSettingsDialog::OnInitDialog (void)
{
	CDialog::OnInitDialog ();

	// Initialize WSF/C Home ListCtrl
	m_WSFCHomeListCtrl.SetExtendedStyle (LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT);

	m_WSFCHomeListCtrl.InsertColumn (0, _T(""), 0, 430);

	// Load WSF/C Homes
	CRegKey regKey;
	LONG    lResult;

	// Get Home Count
	int iHomeCount = 0;
	lResult = regKey.Open (HKEY_CURRENT_USER, _T("Software\\WSO2\\WeSCli\\FlickrUploader\\WSFCHomes"));

	if (ERROR_SUCCESS == lResult)
	{
		// Count
		TCHAR zCount[5];
		ULONG nCharsCount = 5;
		lResult = regKey.QueryStringValue (_T("Count"), zCount, &nCharsCount);
		
		if (ERROR_SUCCESS == lResult)
			iHomeCount = atoi ((char*)zCount);
	}

	// Get Homes
	for (int i = 0; i < iHomeCount; ++i)
	{
		CString sKey;
		sKey.Format (_T("Software\\WSO2\\WeSCli\\FlickrUploader\\WSFCHomes\\Home%d"), i + 1);

		lResult = regKey.Open (HKEY_CURRENT_USER, sKey);

		if (ERROR_SUCCESS == lResult)
		{
			CString sLocation = "";
			CString sCurrent = "";

			// Location
			TCHAR zLocation[MAX_PATH];
			ULONG nCharsLocation = MAX_PATH;
			lResult = regKey.QueryStringValue (_T("Location"), zLocation, &nCharsLocation);

			if (ERROR_SUCCESS == lResult)
				sLocation = zLocation;

			// Current
			TCHAR zCurrent[2];
			ULONG nCharsCurrent = 2;
			lResult = regKey.QueryStringValue (_T("Current"), zCurrent, &nCharsCurrent);

			if (ERROR_SUCCESS == lResult)
				sCurrent = zCurrent;

			m_WSFCHomeListCtrl.InsertItem (i, sLocation);

			if (sCurrent == "T")
				m_WSFCHomeListCtrl.SetCheck (i, TRUE);
			else
				m_WSFCHomeListCtrl.SetCheck (i, FALSE);
		}
	}

	return TRUE;
}


void CSettingsDialog::OnOK ()
{
	// Check if WSF/C Home is Set
	int iWSFCHomeItemIndex = -1;
	for (int iItemIndex = 0; iItemIndex < m_WSFCHomeListCtrl.GetItemCount (); ++iItemIndex)
	{
		if (TRUE == m_WSFCHomeListCtrl.GetCheck (iItemIndex))
		{
			iWSFCHomeItemIndex = iItemIndex;
			break;
		}
	}

	if (-1 != iWSFCHomeItemIndex) // Successful Operation
	{
		s_WSFCHome = m_WSFCHomeListCtrl.GetItemText (iWSFCHomeItemIndex, 0);

		// Save WSF/C Homes
		CRegKey regKey;
		LONG    lResult;

		// Number of Homes
		CString sHomeCount;
		sHomeCount.Format (_T("%d"), m_WSFCHomeListCtrl.GetItemCount ());
		lResult = regKey.Open (HKEY_CURRENT_USER, _T("Software\\WSO2\\WeSCli\\FlickrUploader\\WSFCHomes"));
		if (ERROR_SUCCESS == lResult)
			regKey.SetStringValue (_T("Count"), sHomeCount);

		// Homes one-by-one
		for (int iItemIndex = 0; iItemIndex < m_WSFCHomeListCtrl.GetItemCount (); ++iItemIndex)
		{
			CString sKey;
			sKey.Format (_T("Software\\WSO2\\WeSCli\\FlickrUploader\\WSFCHomes\\Home%d"), iItemIndex + 1);

			lResult = regKey.Create (HKEY_CURRENT_USER, sKey);

			if (ERROR_SUCCESS == lResult)
			{
				// Set Path
				regKey.SetStringValue (_T("Location"), m_WSFCHomeListCtrl.GetItemText (iItemIndex, 0));

				// Set if it is Current
				CString sCurrent = "F";
				if (TRUE == m_WSFCHomeListCtrl.GetCheck (iItemIndex))
					sCurrent = "T";

				regKey.SetStringValue (_T("Current"), sCurrent);
			}
		}

		CDialog::OnOK ();
	}
	else
	{
		AfxMessageBox (_T("Please Select Your WSF/C Home !!!"), MB_ICONEXCLAMATION | MB_OK);
	}
}
