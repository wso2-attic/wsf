#include "stdafx.h"
#include "FlickrUploader.h"
#include "FileUploaderDialog.h"

IMPLEMENT_DYNAMIC (CFileUploaderDialog, CDialog)

CFileUploaderDialog::CFileUploaderDialog (CWnd* pParent) : CDialog (CFileUploaderDialog::IDD, pParent)
{}


CFileUploaderDialog::~CFileUploaderDialog ()
{
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator ite;
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator iteStart = map_ImageDetailsByItemIndex.begin ();
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator iteEnd = map_ImageDetailsByItemIndex.end ();

	for (ite = iteStart; ite != iteEnd; ++ite)
		delete ite->second;

	map_ImageDetailsByItemIndex.clear ();

	//m_AnimateCtrl.Close ();
}


void CFileUploaderDialog::DoDataExchange (CDataExchange* pDX)
{
	CDialog::DoDataExchange (pDX);
	DDX_Control(pDX, IDC_EDIT_TITLE, m_TitleEdit);
	DDX_Control(pDX, IDC_EDIT_DESCRIPTION, m_DescriptionEdit);
	DDX_Control(pDX, IDC_EDIT_TAGS, m_TagsEdit);
	DDX_Control(pDX, IDC_RADIO_ONLY_ME, m_OnlyMeRadioButton);
	DDX_Control(pDX, IDC_CHECK_FAMILY, m_FamilyCheckBox);
	DDX_Control(pDX, IDC_CHECK_FRIENDS, m_FriendsCheckBox);
	DDX_Control(pDX, IDC_RADIO_ANYONE, m_AnyoneRadioButton);
	DDX_Control(pDX, IDC_COMBO_SAFETY_LEVEL, m_SafetyLevelCombo);
	DDX_Control(pDX, IDC_COMBO_HIDDEN, m_HiddenCombo);
	DDX_Control(pDX, IDC_COMBO_CONTENT_TYPE, m_ContentTypeCombo);
	DDX_Control(pDX, IDC_BUTTON_UPLOAD, m_UploadButton);
	DDX_Control(pDX, IDC_EDIT_API_KEY, m_APIKeyEdit);
	DDX_Control(pDX, IDC_CHECK_REMEMBER_KEY, m_RememberKeyCheckBox);	
	DDX_Control(pDX, IDC_ANIMATE_FILE_UPLOAD, m_AnimateCtrl);
	DDX_Control(pDX, IDC_FILE_NAME, m_FileName);
	DDX_Control(pDX, IDC_FILE_SIZE, m_FileSize);
	DDX_Control(pDX, IDC_UPLOAD_STATUS, m_UploadStatus);
	DDX_Control(pDX, IDC_MESSAGE_TEXT, m_MessageText);
}


BEGIN_MESSAGE_MAP (CFileUploaderDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_API_KEY, &CFileUploaderDialog::OnButtonAPIKey)
	ON_BN_CLICKED(IDC_BUTTON_UPLOAD, &CFileUploaderDialog::OnButtonUpload)	
END_MESSAGE_MAP ()


void CFileUploaderDialog::SetFileNames (FileName_lst_t _lstFileName)
{
	lst_FileName = _lstFileName;
}


void CFileUploaderDialog::EnableUploadButton (BOOL _bEnable)
{
	m_UploadButton.EnableWindow (_bEnable);
}


void CFileUploaderDialog::ShowImageDetails (int _iItemIndex)
{
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator ite;
	ite = map_ImageDetailsByItemIndex.find (_iItemIndex);

	if (ite != map_ImageDetailsByItemIndex.end ())
	{
		CImageDetails* pImageDetails = ite->second;

		m_TitleEdit.SetWindowText (pImageDetails->s_Title);
		m_DescriptionEdit.SetWindowText (pImageDetails->s_Description);
		m_TagsEdit.SetWindowText (pImageDetails->s_Tags);
		m_OnlyMeRadioButton.SetCheck (pImageDetails->c_OnlyMe);
		m_FamilyCheckBox.SetCheck (pImageDetails->c_Family);
		m_FriendsCheckBox.SetCheck (pImageDetails->c_Friends);
		m_AnyoneRadioButton.SetCheck (pImageDetails->c_Anyone);
		m_SafetyLevelCombo.SetCurSel (pImageDetails->c_SafetyLevel);
		m_HiddenCombo.SetCurSel (pImageDetails->c_Hidden);
		m_ContentTypeCombo.SetCurSel (pImageDetails->c_ContentType);
		m_FileName.SetWindowText (pImageDetails->s_FileName);
		m_FileSize.SetWindowText (pImageDetails->s_FileSize);
	}
}


void CFileUploaderDialog::StoreImageDetails (int _iItemIndex)
{
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator ite;
	ite = map_ImageDetailsByItemIndex.find (_iItemIndex);

	if (ite != map_ImageDetailsByItemIndex.end ())
	{
		CImageDetails* pImageDetails = ite->second;

		m_TitleEdit.GetWindowText (pImageDetails->s_Title);
		m_DescriptionEdit.GetWindowText (pImageDetails->s_Description);
		m_TagsEdit.GetWindowText (pImageDetails->s_Tags);
		pImageDetails->c_OnlyMe = m_OnlyMeRadioButton.GetCheck ();
		pImageDetails->c_Family = m_FamilyCheckBox.GetCheck ();
		pImageDetails->c_Friends = m_FriendsCheckBox.GetCheck ();
		pImageDetails->c_Anyone = m_AnyoneRadioButton.GetCheck ();
		pImageDetails->c_SafetyLevel = m_SafetyLevelCombo.GetCurSel ();
		pImageDetails->c_Hidden = m_HiddenCombo.GetCurSel ();
		pImageDetails->c_ContentType = m_ContentTypeCombo.GetCurSel ();
	}
}


BOOL CFileUploaderDialog::OnInitDialog ()
{
	CDialog::OnInitDialog ();

	// Create Image Thumbnail List View
	CRect rect;
	CWnd* pListCtrlRef = GetDlgItem (IDC_IMAGE_THUMBNAIL_LC_REF);
	pListCtrlRef->GetWindowRect (rect);
	ScreenToClient (rect);

	m_ImageListCtrl.Create (WS_CHILD | WS_VSCROLL | LVS_ICON | WS_VISIBLE | LVS_SINGLESEL, rect, this, IDC_IMAGE_THUMBNAIL_LC_REF);
	
	// Show Thumbnails
	m_ImageListCtrl.ShowImageThumbnails (lst_FileName);

	// Store Image Data
	int iItemIndex = 0;
	while (lst_FileName.empty () == false)
	{
		CString sFileName = lst_FileName.front ();

		CImageDetails* pImageDetails = new CImageDetails;

		// Set File Name
		pImageDetails->s_FileName = sFileName;
		// Set File Name as the Title
		CString sTitle = sFileName.Right (sFileName.GetLength() - sFileName.ReverseFind ('\\') - 1); // With the extension
		pImageDetails->s_Title = sTitle.Left (sTitle.Find ('.')); // Without the extension
		// Set File Size
		pImageDetails->s_FileSize = GetFileSize (sFileName);

		map_ImageDetailsByItemIndex.insert (make_pair (iItemIndex++, pImageDetails));

		lst_FileName.pop_front ();
	}
	
	// Initialize Dialog Expander
	m_ExpandDialog.Initialize (this, false, IDC_BUTTON_API_KEY, IDC_COLLAPSED_MARK, IDC_COLLAPSED_TEXT);

	// Set Default Values
	m_OnlyMeRadioButton.SetCheck (TRUE);
	m_SafetyLevelCombo.SetCurSel (0);
	m_HiddenCombo.SetCurSel (0);
	m_ContentTypeCombo.SetCurSel (0);

	// Read API Key from the Registry
	CRegKey regKey;
    LONG    lResult;

	lResult = regKey.Open (HKEY_CURRENT_USER, _T("Software\\WSO2\\WeSCli\\FlickrUploader"));

    if (ERROR_SUCCESS == lResult)
	{
		TCHAR zAPIKey[50];
		ULONG nChars = 50;
		lResult = regKey.QueryStringValue (_T("APIKey"), zAPIKey, &nChars);

		if (ERROR_SUCCESS == lResult)
			m_APIKeyEdit.SetWindowText (zAPIKey);
	}

	// Initialize Animate Control
	m_AnimateCtrl.Open (_T("C:\\upload.avi"));

	// Show Initial Help Message
	ShowHelpText ();

	return TRUE;
}


void CFileUploaderDialog::OnButtonAPIKey ()
{
	m_ExpandDialog.OnExpandButton ();
}


void CFileUploaderDialog::OnButtonUpload ()
{
	// Get API key
	CString sAPIKey;
	m_APIKeyEdit.GetWindowText (sAPIKey);
	sAPIKey.Trim ();

	if (sAPIKey == "")
	{
		AfxMessageBox (_T("Please enter your Flickr API Key !!!"));
		return;
	}

	// Save API key
	if (m_RememberKeyCheckBox.GetCheck ())
	{
		CRegKey regKey;
		LONG    lResult;

		lResult = regKey.Create (HKEY_CURRENT_USER, _T("Software\\WSO2\\WeSCli\\FlickrUploader"));

		if (ERROR_SUCCESS == lResult)
		{
			CString sAPIKey;
			m_APIKeyEdit.GetWindowText (sAPIKey);

			regKey.SetStringValue (_T("APIKey"), sAPIKey);
		}
	}

	// Hide Message Text
	m_MessageText.ShowWindow (SW_HIDE);

	// Show Animation
	m_AnimateCtrl.ShowWindow (SW_SHOW);
	m_AnimateCtrl.Play (0, -1, -1);

	// Show Upload Status
	m_UploadStatus.ShowWindow (SW_SHOW);

	// Run Process------------------------
}


CString	CFileUploaderDialog::GetFileSize (CString _sFileName)
{
	BOOL                        fOk;
	WIN32_FILE_ATTRIBUTE_DATA   fileInfo;

	fOk = GetFileAttributesEx (_sFileName, GetFileExInfoStandard, (void*)&fileInfo);
	if (!fOk)
		return "";

	long lFileSizeBytes = (long)fileInfo.nFileSizeLow;
	double dFileSizeKB = (double)lFileSizeBytes / 1024;
	double dFileSizeMB = dFileSizeKB / 1024;

	CString sFileSize;
	(dFileSizeMB >= 1) ? sFileSize.Format (_T("%.2f MB"), dFileSizeMB) : sFileSize.Format (_T("%.2f KB"), dFileSizeKB);			

	return sFileSize;
}


void CFileUploaderDialog::ShowHelpText (void)
{
	// Hide Animation
	m_AnimateCtrl.Stop ();
	m_AnimateCtrl.ShowWindow (SW_HIDE);

	// Hide Upload Status
	m_UploadStatus.ShowWindow (SW_HIDE);

	// Show Message Text
	m_MessageText.ShowWindow (SW_SHOW);
}