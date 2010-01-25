#include "stdafx.h"
#include "FlickrUploader.h"
#include "FlickrUploaderModule.h"
#include "WMParam.h"
#include "FileUploaderDialog.h"
#include "SettingsDialog.h"

extern CFlickrUploaderModule _AtlModule;

IMPLEMENT_DYNAMIC (CFileUploaderDialog, CDialog)

#define	TID_USER_PROFILE_RESTORE	1

CFileUploaderDialog::CFileUploaderDialog (CWnd* pParent) : CDialog (CFileUploaderDialog::IDD, pParent)
{
	b_SignedIn = false;
	s_WSFCHome = "";

	// Load Bitmaps
	hbmp_Offline = LoadBitmap (((CComModule*)&_AtlModule)->GetModuleInstance(), MAKEINTRESOURCE(IDB_BITMAP_USER_OFFLINE));
	hbmp_Online = LoadBitmap (((CComModule*)&_AtlModule)->GetModuleInstance(), MAKEINTRESOURCE(IDB_BITMAP_USER_ONLINE));
	hbmp_Timer = LoadBitmap (((CComModule*)&_AtlModule)->GetModuleInstance(), MAKEINTRESOURCE(IDB_BITMAP_TIMER));

	hbmp_Help = LoadBitmap (((CComModule*)&_AtlModule)->GetModuleInstance(), MAKEINTRESOURCE(IDB_BITMAP_HELP));
	hbmp_Success = LoadBitmap (((CComModule*)&_AtlModule)->GetModuleInstance(), MAKEINTRESOURCE(IDB_BITMAP_SUCCESS));
	hbmp_Error = LoadBitmap (((CComModule*)&_AtlModule)->GetModuleInstance(), MAKEINTRESOURCE(IDB_BITMAP_ERROR));

	// Load Icons
	hico_FlickrPal16 = LoadIcon (((CComModule*)&_AtlModule)->GetModuleInstance(), MAKEINTRESOURCE(IDI_ICON_FLICKR_PAL_16));
	hico_FlickrPal32 = LoadIcon (((CComModule*)&_AtlModule)->GetModuleInstance(), MAKEINTRESOURCE(IDI_ICON_FLICKR_PAL_32));

	// User Profile Data
	s_Frob = "";
	s_Username = "";
	s_NSID = "";
	s_Token = "";
}


CFileUploaderDialog::~CFileUploaderDialog ()
{
	// Clean Image Details
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator iteImageDetails;
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator iteStartImageDetails = map_ImageDetailsByItemIndex.begin ();
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator iteEndImageDetails = map_ImageDetailsByItemIndex.end ();

	for (iteImageDetails = iteStartImageDetails; iteImageDetails != iteEndImageDetails; ++iteImageDetails)
		delete iteImageDetails->second;

	map_ImageDetailsByItemIndex.clear ();

	//m_AnimateCtrl.Close ();

	if (NULL != hbmp_Offline)
		DeleteObject (hbmp_Offline);
	if (NULL != hbmp_Online)
		DeleteObject (hbmp_Online);
	if (NULL != hbmp_Timer)
		DeleteObject (hbmp_Timer);

	if (NULL != hbmp_Help)
		DeleteObject (hbmp_Help);
	if (NULL != hbmp_Success)
		DeleteObject (hbmp_Success);
	if (NULL != hbmp_Error)
		DeleteObject (hbmp_Error);

	if (NULL != hico_FlickrPal16)
		DeleteObject (hico_FlickrPal16);
	if (NULL != hico_FlickrPal32)
		DeleteObject (hico_FlickrPal32);

	// Clean PhotoSet Details
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator iteStartPhotoSetInfo = map_PhotoSetInfoByName.begin ();
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator iteEndPhotoSetInfo = map_PhotoSetInfoByName.end ();

	for (itePhotoSetInfo = iteStartPhotoSetInfo; itePhotoSetInfo != iteEndPhotoSetInfo; ++itePhotoSetInfo)
		delete itePhotoSetInfo->second;

	map_PhotoSetInfoByName.clear ();
}


void CFileUploaderDialog::DoDataExchange (CDataExchange* pDX)
{
	CDialog::DoDataExchange (pDX);
	DDX_Control (pDX, IDC_EDIT_TITLE, m_TitleEdit);
	DDX_Control (pDX, IDC_EDIT_DESCRIPTION, m_DescriptionEdit);
	DDX_Control (pDX, IDC_EDIT_TAGS, m_TagsEdit);
	DDX_Control (pDX, IDC_RADIO_ONLY_ME, m_OnlyMeRadioButton);
	DDX_Control (pDX, IDC_CHECK_FAMILY, m_FamilyCheckBox);
	DDX_Control (pDX, IDC_CHECK_FRIENDS, m_FriendsCheckBox);
	DDX_Control (pDX, IDC_RADIO_ANYONE, m_AnyoneRadioButton);
	DDX_Control (pDX, IDC_COMBO_SAFETY_LEVEL, m_SafetyLevelCombo);
	DDX_Control (pDX, IDC_COMBO_HIDDEN, m_HiddenCombo);
	DDX_Control (pDX, IDC_COMBO_CONTENT_TYPE, m_ContentTypeCombo);
	DDX_Control (pDX, IDC_BUTTON_UPLOAD, m_UploadButton);
	DDX_Control (pDX, IDC_ANIMATE_FILE_UPLOAD, m_AnimateCtrl);
	DDX_Control (pDX, IDC_FILE_NAME, m_FileName);
	DDX_Control (pDX, IDC_FILE_SIZE, m_FileSize);
	DDX_Control (pDX, IDC_UPLOAD_STATUS, m_UploadStatus);
	DDX_Control (pDX, IDC_MESSAGE_TEXT, m_MessageText);
	DDX_Control (pDX, IDC_LIST_AVAILABLE_SETS, m_AvailableSetsListCtrl);
	DDX_Control (pDX, IDC_LIST_SELECTED_SETS, m_SelectedSetsListCtrl);
	DDX_Control (pDX, IDC_USER_BITMAP, m_UserBitmap);
	DDX_Control (pDX, IDC_IMAGE_DETAILS_GROUP_BOX, m_ImageDetailsGroupBox);
	DDX_Control (pDX, IDC_TITLE_CAPTION, m_TitleCaption);
	DDX_Control (pDX, IDC_DESCRIPTION_CAPTION, m_DescriptionCaption);
	DDX_Control (pDX, IDC_TAGS_CAPTION, m_TagsCaption);
	DDX_Control (pDX, IDC_WHO_CAN_SEE_GROUP_BOX, m_WhoCanSeeGroupBox);
	DDX_Control (pDX, IDC_SAFETY_LEVEL_CAPTION, m_SafetyLevelCaption);
	DDX_Control (pDX, IDC_HIDDEN_CAPTION, m_HiddenCaption);
	DDX_Control (pDX, IDC_CONTENT_TYPE_CAPTION, m_ContentTypeCaption);
	DDX_Control (pDX, IDC_AVAILABLE_SETS_CAPTION, m_AvailableSetsCaption);
	DDX_Control (pDX, IDC_SELECTED_SETS_CAPTION, m_SelectedSetsCaption);
	DDX_Control (pDX, IDC_BUTTON_ADD_SET, m_AddSetButton);
	DDX_Control (pDX, IDC_BUTTON_REMOVE_SET, m_RemoveSetButton);
	DDX_Control (pDX, IDC_FILE_NAME_CAPTION, m_FileNameCaption);
	DDX_Control (pDX, IDC_FILE_SIZE_CAPTION, m_FileSizeCaption);
	DDX_Control (pDX, IDC_MESSAGE_BITMAP, m_MessageBitmap);
	DDX_Control (pDX, IDC_WAIT_ANIMATION_MESSAGE, m_WaitAnimationMessage);
}


BEGIN_MESSAGE_MAP (CFileUploaderDialog, CDialog)	
	ON_WM_TIMER   ()	
	ON_BN_CLICKED (IDC_BUTTON_SIGN_IN, &CFileUploaderDialog::OnButtonSignIn)
	ON_BN_CLICKED (IDC_BUTTON_READY, &CFileUploaderDialog::OnButtonReady)
	ON_BN_CLICKED (IDC_BUTTON_SIGN_OUT, &CFileUploaderDialog::OnButtonSignOut)
	ON_BN_CLICKED (IDC_BUTTON_ADD_SET, &CFileUploaderDialog::OnButtonAddSet)
	ON_BN_CLICKED (IDC_BUTTON_REMOVE_SET, &CFileUploaderDialog::OnButtonRemoveSet)
	ON_BN_CLICKED (IDC_BUTTON_UPLOAD, &CFileUploaderDialog::OnButtonUpload)
	ON_MESSAGE    (WM_WAIT_ANIMATION_MESSAGE, OnWaitAnimationMessage)
	ON_MESSAGE    (WM_RESTORE_USER_DONE, OnRestoreUserDone)
	ON_MESSAGE    (WM_GET_FROB_DONE, OnGetFrobDone)
	ON_MESSAGE    (WM_CREATE_NEW_USER_DONE, OnCreateUserDone)
	ON_MESSAGE    (WM_CREATE_NEW_SET, OnCreateNewSet)
	ON_MESSAGE    (WM_CREATE_NEW_SET_DONE, OnCreateNewSetDone)
	ON_MESSAGE    (WM_ADD_TO_SET, OnAddToSet)
	ON_MESSAGE    (WM_FILE_UPLOAD_DONE, OnFileUploadDone)
	ON_MESSAGE    (WM_UPDATE_UPLOAD_STATUS_DONE, OnUpdateUploadStatusDone)
	ON_WM_CLOSE   ()
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP ()


void CFileUploaderDialog::SetFileNames (FileName_lst_t _lstFileName)
{
	lst_FileName = _lstFileName;
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
		m_OnlyMeRadioButton.SetCheck (pImageDetails->b_OnlyMe);
		m_FamilyCheckBox.SetCheck (pImageDetails->b_Family);
		m_FriendsCheckBox.SetCheck (pImageDetails->b_Friends);
		m_AnyoneRadioButton.SetCheck (pImageDetails->b_Anyone);
		m_SafetyLevelCombo.SetCurSel (pImageDetails->i_SafetyLevel - 1);
		m_HiddenCombo.SetCurSel (pImageDetails->i_Hidden - 1);
		m_ContentTypeCombo.SetCurSel (pImageDetails->i_ContentType - 1);

		// Refresh Available Sets List
		m_AvailableSetsListCtrl.DeleteAllItems ();

		CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
		CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfoStart = map_PhotoSetInfoByName.begin ();
		CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfoEnd = map_PhotoSetInfoByName.end ();

		for (itePhotoSetInfo = itePhotoSetInfoStart; itePhotoSetInfo != itePhotoSetInfoEnd; ++itePhotoSetInfo)
		{
			if (pImageDetails->set_SelectedSets.find (itePhotoSetInfo->first) == pImageDetails->set_SelectedSets.end ()) // Photo Set not Selected
			{
				int iImageIndex = itePhotoSetInfo->second->b_New ? 1 : 0;

				m_AvailableSetsListCtrl.InsertItem (m_AvailableSetsListCtrl.GetItemCount (), itePhotoSetInfo->first, iImageIndex);
			}
		}

		// Refresh Selected Sets List
		m_SelectedSetsListCtrl.DeleteAllItems ();
		
		CImageDetails::PhotoSetName_set_t::iterator itePhotoSetName;
		CImageDetails::PhotoSetName_set_t::iterator itePhotoSetNameStart = pImageDetails->set_SelectedSets.begin ();
		CImageDetails::PhotoSetName_set_t::iterator itePhotoSetNameEnd = pImageDetails->set_SelectedSets.end ();

		for (itePhotoSetName = itePhotoSetNameStart; itePhotoSetName != itePhotoSetNameEnd; ++itePhotoSetName)
		{
			CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
			itePhotoSetInfo = map_PhotoSetInfoByName.find (*itePhotoSetName);

			if (itePhotoSetInfo != map_PhotoSetInfoByName.end ())
			{
				int iImageIndex = itePhotoSetInfo->second->b_New ? 1 : 0;

				m_SelectedSetsListCtrl.InsertItem (m_SelectedSetsListCtrl.GetItemCount (), *itePhotoSetName, iImageIndex);
			}
		}
		
		m_FileName.SetWindowText (pImageDetails->s_FileName);
		m_FileSize.SetWindowText (pImageDetails->s_FileSize);

		ShowHelpText ();

		//RedrawWindow ();
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
		pImageDetails->b_OnlyMe = m_OnlyMeRadioButton.GetCheck () ? true : false;
		pImageDetails->b_Family = m_FamilyCheckBox.GetCheck () ? true : false;
		pImageDetails->b_Friends = m_FriendsCheckBox.GetCheck () ? true : false;
		pImageDetails->b_Anyone = m_AnyoneRadioButton.GetCheck () ? true : false;
		pImageDetails->i_SafetyLevel = m_SafetyLevelCombo.GetCurSel () + 1;
		pImageDetails->i_Hidden = m_HiddenCombo.GetCurSel () + 1;
		pImageDetails->i_ContentType = m_ContentTypeCombo.GetCurSel () + 1;

		// Refresh Selected Photo Sets List
		pImageDetails->set_SelectedSets.clear ();

		int iItemCount = m_SelectedSetsListCtrl.GetItemCount ();
		for (int i = 0; i < iItemCount; ++i)
			pImageDetails->set_SelectedSets.insert (m_SelectedSetsListCtrl.GetItemText (i, 0));
	}
}


void CFileUploaderDialog::EnableImageControls (BOOL _bEnable)
{
	m_ImageDetailsGroupBox.EnableWindow (_bEnable);
	m_TitleCaption.EnableWindow (_bEnable);
	m_TitleEdit.EnableWindow (_bEnable);
	m_DescriptionCaption.EnableWindow (_bEnable);
	m_DescriptionEdit.EnableWindow (_bEnable);
	m_TagsCaption.EnableWindow (_bEnable);
	m_TagsEdit.EnableWindow (_bEnable);
	m_WhoCanSeeGroupBox.EnableWindow (_bEnable);
	m_OnlyMeRadioButton.EnableWindow (_bEnable);
	m_FamilyCheckBox.EnableWindow (_bEnable);
	m_FriendsCheckBox.EnableWindow (_bEnable);
	m_AnyoneRadioButton.EnableWindow (_bEnable);
	m_SafetyLevelCaption.EnableWindow (_bEnable);
	m_SafetyLevelCombo.EnableWindow (_bEnable);
	m_HiddenCaption.EnableWindow (_bEnable);
	m_HiddenCombo.EnableWindow (_bEnable);
	m_ContentTypeCaption.EnableWindow (_bEnable);
	m_ContentTypeCombo.EnableWindow (_bEnable);
	m_AvailableSetsCaption.EnableWindow (_bEnable);
	m_AvailableSetsListCtrl.EnableWindow (_bEnable);
	m_SelectedSetsCaption.EnableWindow (_bEnable);
	m_SelectedSetsListCtrl.EnableWindow (_bEnable);
	m_AddSetButton.EnableWindow (FALSE); // Has to be Disabled all the Time
	m_RemoveSetButton.EnableWindow (FALSE); // Has to be Disabled all the Time
	m_FileNameCaption.EnableWindow (_bEnable);
	m_FileName.EnableWindow (_bEnable);
	m_FileSizeCaption.EnableWindow (_bEnable);
	m_FileSize.EnableWindow (_bEnable);

	m_UploadButton.EnableWindow (_bEnable);

	//RedrawWindow ();
}


CPhotoSetInfo* CFileUploaderDialog::GetPhotoSetInfo (CString _sName)
{
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
	itePhotoSetInfo = map_PhotoSetInfoByName.find (_sName);

	if (itePhotoSetInfo == map_PhotoSetInfoByName.end ())
		return NULL;

	return itePhotoSetInfo->second;
}


void CFileUploaderDialog::RemovePhotoSetInfo (CString _sName)
{
	// Clean PhotoSet Details
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
	itePhotoSetInfo = map_PhotoSetInfoByName.find (_sName);

	if (itePhotoSetInfo != map_PhotoSetInfoByName.end ())
	{
		delete itePhotoSetInfo->second;
		map_PhotoSetInfoByName.erase (itePhotoSetInfo);
	}

	// Remove from Selected Photo Sets of Images
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator iteImageDetails;
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator iteStartImageDetails = map_ImageDetailsByItemIndex.begin ();
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator iteEndImageDetails = map_ImageDetailsByItemIndex.end ();

	for (iteImageDetails = iteStartImageDetails; iteImageDetails != iteEndImageDetails; ++iteImageDetails)
		iteImageDetails->second->set_SelectedSets.erase (_sName);

}


BOOL CFileUploaderDialog::OnInitDialog (void)
{
	CDialog::OnInitDialog ();

	// Initialize FlickrClient
	o_FlickrClient.SetPhotoSetInfo (&map_PhotoSetInfoByName);

	// Add Items to the System Menu
	CMenu* pSysMenu = GetSystemMenu (FALSE);
    if (pSysMenu != NULL)
	{
		pSysMenu->AppendMenu (MF_SEPARATOR);
		pSysMenu->AppendMenu (MF_STRING, IDM_SETTINGS, _T("&Settings ..."));
    }

	// Set System Icons
	SetIcon (hico_FlickrPal16, FALSE);
	SetIcon (hico_FlickrPal32, TRUE);

	// Create Wait Animation
	CRect oWaitAnimationRect;
	GetDlgItem (IDC_WAIT_ANIMATION_RECT)->GetWindowRect (oWaitAnimationRect);
	ScreenToClient (oWaitAnimationRect);

	m_WaitAnimation.Create (NULL,
							_T("WaitAnimation"),
							WS_CHILD,
							oWaitAnimationRect,
							this,
							IDC_WAIT_ANIMATION_RECT);

	// Create Username Ctrl
	CRect oUsernameTextRect;
	GetDlgItem (IDC_USERNAME_RECT)->GetWindowRect (oUsernameTextRect);
	ScreenToClient (oUsernameTextRect);
	
	m_UsenameText.Create (NULL,
						  _T("UsernameText"),
						  WS_CHILD,
						  oUsernameTextRect,
						  this,
						  IDC_USERNAME_RECT);

	m_UsenameText.Init (RGB (0, 200, 0));

	// Create User Photos URL
	CRect oUserPhotosURLRect;
	GetDlgItem (IDC_USER_PHOTOS_URL_RECT)->GetWindowRect (oUserPhotosURLRect);
	ScreenToClient (oUserPhotosURLRect);
	
	m_UserPhotosURLCtrl.Create (NULL,
								_T("UserPhotosURL"),
								WS_CHILD,
								oUserPhotosURLRect,
								this,
								IDC_USER_PHOTOS_URL_RECT);
		
	// Create User Profile URL
	CRect oUserProfileURLRect;
	GetDlgItem (IDC_USER_PROFILE_URL_RECT)->GetWindowRect (oUserProfileURLRect);
	ScreenToClient (oUserProfileURLRect);
	
	m_UserProfileURLCtrl.Create (NULL,
								 _T("UserProfileURL"),
								 WS_CHILD,
								 oUserProfileURLRect,
								 this,
								 IDC_USER_PROFILE_URL_RECT);
		
	// Create Available Quota Ctrl
	CRect oAvailableQuotaRect;
	GetDlgItem (IDC_AVAILABLE_QUOTA_RECT)->GetWindowRect (oAvailableQuotaRect);
	ScreenToClient (oAvailableQuotaRect);

	m_AvailableQuotaText.Create (NULL,
								 _T("AvailableQuotaText"),
								 WS_CHILD,
								 oAvailableQuotaRect,
								 this,
								 IDC_AVAILABLE_QUOTA_RECT);

	m_AvailableQuotaText.Init (RGB (0, 100, 50), true);

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

	// Initialize Only Me Radio Button
	m_OnlyMeRadioButton.SetEnable (true);
	m_OnlyMeRadioButton.SetFamilyCheckBox (&m_FamilyCheckBox);
	m_OnlyMeRadioButton.SetFriendsCheckBox (&m_FriendsCheckBox);

	// Initialize Anyone Radio Button
	m_AnyoneRadioButton.SetEnable (false);
	m_AnyoneRadioButton.SetFamilyCheckBox (&m_FamilyCheckBox);
	m_AnyoneRadioButton.SetFriendsCheckBox (&m_FriendsCheckBox);
	
	// Initialize Sets Lists
	m_SetsImageList.Create (16, 16, ILC_COLOR32 | ILC_MASK, 0, 4);
	CBitmap bmListItem; // Existing Item
	bmListItem.LoadBitmap (IDB_BITMAP_SET_LIST_ITEM);
	m_SetsImageList.Add (&bmListItem, RGB(0, 0, 0));

	CBitmap bmListItemNew; // New Item
	bmListItemNew.LoadBitmap (IDB_BITMAP_SET_LIST_ITEM_NEW);
	m_SetsImageList.Add (&bmListItemNew, RGB(0, 0, 0));
	
	m_AvailableSetsListCtrl.SetImageList (&m_SetsImageList, LVSIL_SMALL);
	m_AvailableSetsListCtrl.InsertColumn (0, _T(""), 0, 150);
	m_AvailableSetsListCtrl.SetButton ((CButton*)GetDlgItem (IDC_BUTTON_ADD_SET));
	m_AvailableSetsListCtrl.SetPhotoSetInfo (&map_PhotoSetInfoByName);

	m_SelectedSetsListCtrl.SetImageList (&m_SetsImageList, LVSIL_SMALL);
	m_SelectedSetsListCtrl.InsertColumn (0, _T(""), 0, 150);
	m_SelectedSetsListCtrl.SetButton ((CButton*)GetDlgItem (IDC_BUTTON_REMOVE_SET));

	// Initialize Animate Control
	TCHAR zWindowsDirectory [MAX_PATH];
	GetWindowsDirectory (zWindowsDirectory, MAX_PATH);
	
	CString sAnimationFileName = zWindowsDirectory;
	if (sAnimationFileName[sAnimationFileName.GetLength () - 1] != '\\')
		sAnimationFileName+= '\\';
	sAnimationFileName+= "upload.avi";

	m_AnimateCtrl.Open (sAnimationFileName);

	// Show Offline Message
	ShowOfflineMessage ();

	// Set Default Values
	m_OnlyMeRadioButton.SetCheck (TRUE);
	m_SafetyLevelCombo.SetCurSel (0);
	m_HiddenCombo.SetCurSel (0);
	m_ContentTypeCombo.SetCurSel (0);

	// Disable Image Controls by Default
	EnableImageControls (FALSE);

	// Show Initial Help Message
	ShowHelpText ();

	// Create User Profile Restore Timer
	SetTimer (TID_USER_PROFILE_RESTORE, 10, NULL);

	return TRUE;
}


void CFileUploaderDialog::OnTimer (UINT_PTR nIDEvent)
{
	if (nIDEvent == TID_USER_PROFILE_RESTORE) // Restore User Profile
	{
		KillTimer (nIDEvent);

		// Read Profile from the Registry
		CRegKey regKey;
		LONG    lResult;

		lResult = regKey.Open (HKEY_CURRENT_USER, _T("Software\\WSO2\\WeSCli\\FlickrUploader"));

		if (ERROR_SUCCESS == lResult)
		{
			// Username
			TCHAR zUsername[100];
			ULONG nCharsUsername = 100;
			lResult = regKey.QueryStringValue (_T("Username"), zUsername, &nCharsUsername);

			if (ERROR_SUCCESS == lResult)
				s_Username = zUsername;

			// NSID
			TCHAR zNSID[50];
			ULONG nCharsNSID = 50;
			lResult = regKey.QueryStringValue (_T("NSID"), zNSID, &nCharsNSID);

			if (ERROR_SUCCESS == lResult)
				s_NSID = zNSID;

			// Token
			TCHAR zToken[50];
			ULONG nCharsToken = 50;
			lResult = regKey.QueryStringValue (_T("Token"), zToken, &nCharsToken);

			if (ERROR_SUCCESS == lResult)
				s_Token = zToken;

			// WSF/C Home
			TCHAR zWSFCHome[MAX_PATH];
			ULONG nCharsWSFCHome = MAX_PATH;
			lResult = regKey.QueryStringValue (_T("WSFCHome"), zWSFCHome, &nCharsWSFCHome);

			if (ERROR_SUCCESS == lResult)
				s_WSFCHome = zWSFCHome;
		}

		if ((s_Token != "") && (s_WSFCHome != "")) // Restore Saved Profile
		{
			ShowWaitAnimation ();

			o_FlickrClient.RestoreUser (s_WSFCHome, s_Token, s_NSID, this);
		}
		else // Profile not Saved
		{
			// Update UI
			ShowOfflineMessage ();
			ShowHelpText ();

			b_SignedIn = false;
		}
	}

	CDialog::OnTimer (nIDEvent);
}


void CFileUploaderDialog::OnButtonSignIn (void)
{
	if (s_WSFCHome == "")
	{
		AfxMessageBox (_T("Please set your WSF/C home !!!"), MB_ICONEXCLAMATION | MB_OK);
		return;
	}

	o_FlickrClient.GetFrob (s_WSFCHome, this);
}


void CFileUploaderDialog::OnButtonReady (void)
{
	if (s_WSFCHome == "")
	{
		AfxMessageBox (_T("Please set your WSF/C home !!!"), MB_ICONEXCLAMATION | MB_OK);
		return;
	}

	ShowWaitAnimation ();

	o_FlickrClient.CreateUser (s_WSFCHome, s_Frob, this);
}


void CFileUploaderDialog::OnButtonSignOut (void)
{
	// Update UI
	ShowOfflineMessage ();
	ShowHelpText ();

	// Clean PhotoSet Details
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator iteStartPhotoSetInfo = map_PhotoSetInfoByName.begin ();
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator iteEndPhotoSetInfo = map_PhotoSetInfoByName.end ();

	for (itePhotoSetInfo = iteStartPhotoSetInfo; itePhotoSetInfo != iteEndPhotoSetInfo; ++itePhotoSetInfo)
		delete itePhotoSetInfo->second;

	map_PhotoSetInfoByName.clear ();

	// Clear Selected Photo Sets of Images
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator iteImageDetails;
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator iteStartImageDetails = map_ImageDetailsByItemIndex.begin ();
	CImageDetails::ImageDetailsByItemIndex_map_t::iterator iteEndImageDetails = map_ImageDetailsByItemIndex.end ();

	for (iteImageDetails = iteStartImageDetails; iteImageDetails != iteEndImageDetails; ++iteImageDetails)
		iteImageDetails->second->set_SelectedSets.clear ();

	// Set Available Photo Set Status
	m_AvailableSetsListCtrl.SetUserSignedIn (false);

	// Update Selected Image Details
	int iItemIndex = m_ImageListCtrl.GetNextItem (-1, LVNI_SELECTED);
	if (iItemIndex != -1)
		ShowImageDetails (iItemIndex);

	// Clear User Profile Data
	CRegKey regKey;
	LONG    lResult;

	lResult = regKey.Create (HKEY_CURRENT_USER, _T("Software\\WSO2\\WeSCli\\FlickrUploader"));

	if (ERROR_SUCCESS == lResult)
	{
		// Username
		regKey.DeleteValue (_T("Username"));
		// NSID
		regKey.DeleteValue (_T("NSID"));
		// Token
		regKey.DeleteValue (_T("Token"));
		// WSFCHome
		regKey.DeleteValue (_T("WSFCHome"));
	}

	b_SignedIn = false;
}


void CFileUploaderDialog::ShowOfflineMessage (void)
{
	// Hide Login Permission Await Message
	GetDlgItem (IDC_AWAIT_MESSAGE)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_AWAIT_MESSAGE_DETAILS)->ShowWindow (SW_HIDE);

	// Hide Username
	GetDlgItem (IDC_USERNAME_CAPTION)->ShowWindow (SW_HIDE);
	m_UsenameText.ShowWindow (SW_HIDE);

	// Hide Photos URL
	GetDlgItem (IDC_USER_PHOTOS_URL_CAPTION)->ShowWindow (SW_HIDE);
	m_UserPhotosURLCtrl.ShowWindow (SW_HIDE);

	// Hide Profile URL
	GetDlgItem (IDC_USER_PROFILE_URL_CAPTION)->ShowWindow (SW_HIDE);
	m_UserProfileURLCtrl.ShowWindow (SW_HIDE);

	// Hide Available Quota
	GetDlgItem (IDC_AVAILABLE_QUOTA_CAPTION)->ShowWindow (SW_HIDE);
	m_AvailableQuotaText.ShowWindow (SW_HIDE);

	// Hide "Sign Out" and "Ready" Buttons
	GetDlgItem (IDC_BUTTON_SIGN_OUT)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_BUTTON_READY)->ShowWindow (SW_HIDE);

	// Hide Wait Animation
	m_WaitAnimation.ShowWindow (SW_HIDE);
	m_WaitAnimationMessage.ShowWindow (SW_HIDE);
	GetDlgItem (IDC_WAIT_ANIMATION_TITLE)->ShowWindow (SW_HIDE);

	// Show Offline Message
	GetDlgItem (IDC_OFFLINE_MESSAGE)->ShowWindow (SW_SHOW);	
	GetDlgItem (IDC_OFFLINE_MESSAGE_DETAILS)->ShowWindow (SW_SHOW);

	// Show Offline Bitmap
	m_UserBitmap.SetBitmap (hbmp_Offline);

	// Show "Sign In" Button
	GetDlgItem (IDC_BUTTON_SIGN_IN)->EnableWindow (TRUE);
	GetDlgItem (IDC_BUTTON_SIGN_IN)->ShowWindow (SW_SHOW);

	RedrawWindow ();
}


void CFileUploaderDialog::ShowWaitAnimation (void)
{
	// Hide Offline Message
	GetDlgItem (IDC_OFFLINE_MESSAGE)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_OFFLINE_MESSAGE_DETAILS)->ShowWindow (SW_HIDE);

	// Hide Username
	GetDlgItem (IDC_USERNAME_CAPTION)->ShowWindow (SW_HIDE);
	m_UsenameText.ShowWindow (SW_HIDE);

	// Hide Photos URL
	GetDlgItem (IDC_USER_PHOTOS_URL_CAPTION)->ShowWindow (SW_HIDE);
	m_UserPhotosURLCtrl.ShowWindow (SW_HIDE);

	// Hide Profile URL
	GetDlgItem (IDC_USER_PROFILE_URL_CAPTION)->ShowWindow (SW_HIDE);
	m_UserProfileURLCtrl.ShowWindow (SW_HIDE);

	// Hide Available Quota
	GetDlgItem (IDC_AVAILABLE_QUOTA_CAPTION)->ShowWindow (SW_HIDE);
	m_AvailableQuotaText.ShowWindow (SW_HIDE);

	// Hide Login Permission Await Message
	GetDlgItem (IDC_AWAIT_MESSAGE)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_AWAIT_MESSAGE_DETAILS)->ShowWindow (SW_HIDE);

	// Disable "Sign In" and "Ready" Buttons
	GetDlgItem (IDC_BUTTON_SIGN_IN)->EnableWindow (FALSE);
	GetDlgItem (IDC_BUTTON_READY)->EnableWindow (FALSE);

	// Show Wait Animation
	m_WaitAnimation.Reset ();
	m_WaitAnimation.ShowWindow (SW_SHOW);
	m_WaitAnimationMessage.ShowWindow (SW_SHOW);
	GetDlgItem (IDC_WAIT_ANIMATION_TITLE)->ShowWindow (SW_SHOW);

	RedrawWindow ();
}


void CFileUploaderDialog::ShowLoginContinueMessage (void)
{
	// Hide Offline Message
	GetDlgItem (IDC_OFFLINE_MESSAGE)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_OFFLINE_MESSAGE_DETAILS)->ShowWindow (SW_HIDE);

	// Hide Username
	GetDlgItem (IDC_USERNAME_CAPTION)->ShowWindow (SW_HIDE);
	m_UsenameText.ShowWindow (SW_HIDE);

	// Hide Photos URL
	GetDlgItem (IDC_USER_PHOTOS_URL_CAPTION)->ShowWindow (SW_HIDE);
	m_UserPhotosURLCtrl.ShowWindow (SW_HIDE);

	// Hide Profile URL
	GetDlgItem (IDC_USER_PROFILE_URL_CAPTION)->ShowWindow (SW_HIDE);
	m_UserProfileURLCtrl.ShowWindow (SW_HIDE);

	// Hide Available Quota
	GetDlgItem (IDC_AVAILABLE_QUOTA_CAPTION)->ShowWindow (SW_HIDE);
	m_AvailableQuotaText.ShowWindow (SW_HIDE);

	// Hide "Sign In" and "Sign Out" Buttons
	GetDlgItem (IDC_BUTTON_SIGN_IN)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_BUTTON_SIGN_OUT)->ShowWindow (SW_HIDE);

	// Hide Wait Animation
	m_WaitAnimation.ShowWindow (SW_HIDE);
	m_WaitAnimationMessage.ShowWindow (SW_HIDE);
	GetDlgItem (IDC_WAIT_ANIMATION_TITLE)->ShowWindow (SW_HIDE);

	// Show Login Permission Await Message
	GetDlgItem (IDC_AWAIT_MESSAGE)->ShowWindow (SW_SHOW);
	GetDlgItem (IDC_AWAIT_MESSAGE_DETAILS)->ShowWindow (SW_SHOW);

	// Show Login Continue Bitmap
	m_UserBitmap.SetBitmap (hbmp_Timer);

	// Show "Ready" Button
	GetDlgItem (IDC_BUTTON_READY)->EnableWindow (TRUE);
	GetDlgItem (IDC_BUTTON_READY)->ShowWindow (SW_SHOW);

	RedrawWindow ();
}


void CFileUploaderDialog::ShowOnlineMessage (CString _sUsername, CString _sPhotosURL, CString _sProfileURL, CString _sAvailableQuota)
{
	// Hide Offline Message
	GetDlgItem (IDC_OFFLINE_MESSAGE)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_OFFLINE_MESSAGE_DETAILS)->ShowWindow (SW_HIDE);

	// Hide Login Permission Await Message
	GetDlgItem (IDC_AWAIT_MESSAGE)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_AWAIT_MESSAGE_DETAILS)->ShowWindow (SW_HIDE);

	// Hide "Sign In" and "Ready" Buttons
	GetDlgItem (IDC_BUTTON_SIGN_IN)->ShowWindow (SW_HIDE);
	GetDlgItem (IDC_BUTTON_READY)->ShowWindow (SW_HIDE);

	// Hide Wait Animation
	m_WaitAnimation.ShowWindow (SW_HIDE);
	m_WaitAnimationMessage.ShowWindow (SW_HIDE);
	GetDlgItem (IDC_WAIT_ANIMATION_TITLE)->ShowWindow (SW_HIDE);

	// Show Username
	GetDlgItem (IDC_USERNAME_CAPTION)->ShowWindow (SW_SHOW);
	m_UsenameText.SetText (_sUsername);
	m_UsenameText.ShowWindow (SW_SHOW);

	// Show Photos URL
	GetDlgItem (IDC_USER_PHOTOS_URL_CAPTION)->ShowWindow (SW_SHOW);
	m_UserPhotosURLCtrl.SetText (_sPhotosURL);
	m_UserPhotosURLCtrl.ShowWindow (SW_SHOW);

	// Show Profile URL
	GetDlgItem (IDC_USER_PROFILE_URL_CAPTION)->ShowWindow (SW_SHOW);
	m_UserProfileURLCtrl.SetText (_sProfileURL);
	m_UserProfileURLCtrl.ShowWindow (SW_SHOW);

	// Show Available Quota
	GetDlgItem (IDC_AVAILABLE_QUOTA_CAPTION)->ShowWindow (SW_SHOW);
	m_AvailableQuotaText.SetText (_sAvailableQuota);
	m_AvailableQuotaText.ShowWindow (SW_SHOW);

	// Show Online Bitmap
	m_UserBitmap.SetBitmap (hbmp_Online);

	// Show "Sign Out" Button
	GetDlgItem (IDC_BUTTON_SIGN_OUT)->ShowWindow (SW_SHOW);

	RedrawWindow ();
}


void CFileUploaderDialog::ShowHelpText (void)
{
	// Hide Animation
	m_AnimateCtrl.Stop ();
	m_AnimateCtrl.ShowWindow (SW_HIDE);

	// Hide Upload Status
	m_UploadStatus.ShowWindow (SW_HIDE);

	// Show Message Bitmap
	m_MessageBitmap.SetBitmap (hbmp_Help);
	m_MessageBitmap.ShowWindow (SW_SHOW);

	// Show Message Text
	m_MessageText.SetWindowText (_T("Click on a thumbnail to set image properties. It is possible to set image properties while staying offline. Sign in and upload images one by one ..."));
	m_MessageText.ShowWindow (SW_SHOW);

	RedrawWindow ();
}


void CFileUploaderDialog::OnButtonAddSet (void)
{
	// Get Item Text
	int iItemIndex = m_AvailableSetsListCtrl.GetNextItem (-1, LVNI_SELECTED);
	CString sItemText = m_AvailableSetsListCtrl.GetItemText (iItemIndex, 0);

	// Add Item to the Selected List
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
	itePhotoSetInfo = map_PhotoSetInfoByName.find (sItemText);

	if (itePhotoSetInfo != map_PhotoSetInfoByName.end ())
	{
		int iImageIndex = itePhotoSetInfo->second->b_New ? 1 : 0;

		m_SelectedSetsListCtrl.InsertItem (m_SelectedSetsListCtrl.GetItemCount (), sItemText, iImageIndex);
	}
	
	// Remove Item from the Available List
	m_AvailableSetsListCtrl.DeleteItem (iItemIndex);

	// Disable Button
	GetDlgItem (IDC_BUTTON_ADD_SET)->EnableWindow (false);
}


void CFileUploaderDialog::OnButtonRemoveSet (void)
{
	// Get Item Text
	int iItemIndex = m_SelectedSetsListCtrl.GetNextItem (-1, LVNI_SELECTED);
	CString sItemText = m_SelectedSetsListCtrl.GetItemText (iItemIndex, 0);

	// Add Item to the Available List
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
	itePhotoSetInfo = map_PhotoSetInfoByName.find (sItemText);

	if (itePhotoSetInfo != map_PhotoSetInfoByName.end ())
	{
		int iImageIndex = itePhotoSetInfo->second->b_New ? 1 : 0;

		m_AvailableSetsListCtrl.InsertItem (m_AvailableSetsListCtrl.GetItemCount (), sItemText, iImageIndex);
	}

	// Remove Item from the Selected List
	m_SelectedSetsListCtrl.DeleteItem (iItemIndex);

	// Disable Button
	GetDlgItem (IDC_BUTTON_REMOVE_SET)->EnableWindow (false);
}


void CFileUploaderDialog::OnButtonUpload (void)
{
	if (false == b_SignedIn)
	{
		AfxMessageBox (_T("You need to sign in before you upload photos !!!"), MB_ICONEXCLAMATION | MB_OK);
		return;
	}
	
	if (s_WSFCHome == "")
	{
		AfxMessageBox (_T("Please set your WSF/C home !!!"), MB_ICONEXCLAMATION | MB_OK);
		return;
	}

	int iItemIndex = m_ImageListCtrl.GetNextItem (-1, LVNI_SELECTED);
	if  (-1 == iItemIndex)
		return;

	// Save Current Changes
	StoreImageDetails (iItemIndex);

	CImageDetails::ImageDetailsByItemIndex_map_t::iterator ite;
	ite = map_ImageDetailsByItemIndex.find (iItemIndex);
	if (ite == map_ImageDetailsByItemIndex.end ())
		return;
	
	// Hide Message Bitmap
	m_MessageBitmap.ShowWindow (SW_HIDE);

	// Hide Message Text
	m_MessageText.ShowWindow (SW_HIDE);

	// Show Animation
	m_AnimateCtrl.ShowWindow (SW_SHOW);
	m_AnimateCtrl.Play (0, -1, -1);

	// Show Upload Status
	CString sImageTitle;
	m_TitleEdit.GetWindowText (sImageTitle);
	
	CString sUploadStatus = "Uploading \"";
			sUploadStatus+= sImageTitle;
			sUploadStatus+= "\" ...";
	m_UploadStatus.SetWindowText (sUploadStatus);
	m_UploadStatus.ShowWindow (SW_SHOW);

	// Disable Upload Button 
	m_UploadButton.EnableWindow (FALSE);

	RedrawWindow ();

	o_FlickrClient.UploadImage (s_WSFCHome, s_Token, ite->second, this);
}


LRESULT CFileUploaderDialog::OnWaitAnimationMessage (WPARAM wParam, LPARAM lParam)
{
	CString* pParam = (CString*)wParam;

	m_WaitAnimationMessage.SetWindowText (*pParam);

	delete pParam;
	
	return 0;
}


LRESULT CFileUploaderDialog::OnRestoreUserDone (WPARAM wParam, LPARAM lParam)
{
	CWMParam* pParam = (CWMParam*)wParam;

	if (true == pParam->b_Success)
	{
		ShowOnlineMessage (s_Username, pParam->s_PhotosURL, pParam->s_ProfileURL, pParam->s_AvailableQuota);

		// Set Available Photo Set Status
		m_AvailableSetsListCtrl.SetPro (pParam->b_Pro);
		m_AvailableSetsListCtrl.SetRemainingSetCount (pParam->i_RemainingSetCount);
		m_AvailableSetsListCtrl.SetUserSignedIn (true);

		while (false == pParam->lst_PhotoSetInfo.empty ())
		{
			map_PhotoSetInfoByName.insert (make_pair (pParam->lst_PhotoSetInfo.front ()->s_Name, pParam->lst_PhotoSetInfo.front ()));
			
			pParam->lst_PhotoSetInfo.pop_front ();
		}
		
		b_SignedIn = true;
	}
	else
	{
		ShowOfflineMessage ();
		
		b_SignedIn = false;
	}

	ShowHelpText ();

	delete pParam;
	
	return 0;
}


LRESULT CFileUploaderDialog::OnGetFrobDone (WPARAM wParam, LPARAM lParam)
{
	CWMParam* pParam = (CWMParam*)wParam;

	if (true == pParam->b_Success)
	{
		s_Frob = pParam->s_Frob;

		// Get Auth URL and Open it using the Default Web Browser
		ShellExecute (NULL, _T("open"), pParam->s_AuthURL, NULL, NULL, SW_SHOWNORMAL);

		// Update UI
		ShowLoginContinueMessage ();
	}
	else
	{
		ShowOfflineMessage ();
	}

	ShowHelpText ();

	delete pParam;
	
	return 0;
}


LRESULT CFileUploaderDialog::OnCreateUserDone (WPARAM wParam, LPARAM lParam)
{
	CWMParam* pParam = (CWMParam*)wParam;

	if (true == pParam->b_Success)
	{
		s_Username = pParam->s_Username;
		s_NSID = pParam->s_NSID;
		s_Token = pParam->s_Token;

		ShowOnlineMessage (s_Username, pParam->s_PhotosURL, pParam->s_ProfileURL, pParam->s_AvailableQuota);
		
		// Set Available Photo Set Status
		m_AvailableSetsListCtrl.SetPro (pParam->b_Pro);
		m_AvailableSetsListCtrl.SetRemainingSetCount (pParam->i_RemainingSetCount);
		m_AvailableSetsListCtrl.SetUserSignedIn (true);

		// Get Photo Set Names
		while (false == pParam->lst_PhotoSetInfo.empty ())
		{
			map_PhotoSetInfoByName.insert (make_pair (pParam->lst_PhotoSetInfo.front ()->s_Name, pParam->lst_PhotoSetInfo.front ()));
			
			pParam->lst_PhotoSetInfo.pop_front ();
		}

		// Update Selected Image Details
		int iItemIndex = m_ImageListCtrl.GetNextItem (-1, LVNI_SELECTED);
		if (iItemIndex != -1)
			ShowImageDetails (iItemIndex);

		// Save User Profile Data
		CRegKey regKey;
		LONG    lResult;

		lResult = regKey.Create (HKEY_CURRENT_USER, _T("Software\\WSO2\\WeSCli\\FlickrUploader"));

		if (ERROR_SUCCESS == lResult)
		{
			// Username
			regKey.SetStringValue (_T("Username"), s_Username);
			// NSID
			regKey.SetStringValue (_T("NSID"), s_NSID);
			// Token
			regKey.SetStringValue (_T("Token"), s_Token);
		}

		b_SignedIn = true;
	}
	else
	{
		ShowOfflineMessage ();
		
		b_SignedIn = false;
	}

	ShowHelpText ();

	delete pParam;
	
	return 0;
}


LRESULT CFileUploaderDialog::OnCreateNewSet (WPARAM wParam, LPARAM lParam)
{
	CString* pParam = (CString*)wParam;

	CString sUploadStatus = "Creating photo set \"";
			sUploadStatus+= *pParam;
			sUploadStatus+= "\" ...";
	m_UploadStatus.SetWindowText (sUploadStatus);

	delete pParam;
	
	return 0;
}


LRESULT CFileUploaderDialog::OnCreateNewSetDone (WPARAM wParam, LPARAM lParam)
{
	CWMParam* pParam = (CWMParam*)wParam;

	// Update Photo Set Info
	CPhotoSetInfo::PhotoSetInfoByName_map_t::iterator itePhotoSetInfo;
	itePhotoSetInfo = map_PhotoSetInfoByName.find (pParam->s_PhotoSetName);
	if (itePhotoSetInfo != map_PhotoSetInfoByName.end ())
	{
		itePhotoSetInfo->second->b_New = false;
		itePhotoSetInfo->second->s_ID = pParam->s_PhotoSetID;
	}

	// Update UI
	CString sUploadStatus = "Photo set \"";
			sUploadStatus+= pParam->s_PhotoSetName;
			sUploadStatus+= "\" created successfully ...";
	m_UploadStatus.SetWindowText (sUploadStatus);

	// Update Photo Set Info
	int iItemIndex = m_ImageListCtrl.GetNextItem (-1, LVNI_SELECTED);
	if (iItemIndex != -1)
		ShowImageDetails (iItemIndex);

	delete pParam;
	
	return 0;
}


LRESULT CFileUploaderDialog::OnAddToSet (WPARAM wParam, LPARAM lParam)
{
	CString* pParam = (CString*)wParam;

	CString sUploadStatus = "Adding image to photo set \"";
			sUploadStatus+= *pParam;
			sUploadStatus+= "\" ...";
	m_UploadStatus.SetWindowText (sUploadStatus);

	delete pParam;
	
	return 0;
}


LRESULT CFileUploaderDialog::OnFileUploadDone (WPARAM wParam, LPARAM lParam)
{
	// Hide Animation
	m_AnimateCtrl.Stop ();
	m_AnimateCtrl.ShowWindow (SW_HIDE);

	// Hide Upload Status
	m_UploadStatus.ShowWindow (SW_HIDE);

	CWMParam* pWMParam = (CWMParam*)wParam;
		
	if (true == pWMParam->b_Success) // Photo Uploaded Successfully
	{
		// Show Message Text
		CString sMessage = "Image \"";
				sMessage+= pWMParam->s_PhotoTitle;
				sMessage+= "\" Uploaded Successfully ...";
		m_MessageText.SetWindowText (sMessage);
		m_MessageText.ShowWindow (SW_SHOW);

		// Set Bitmap
		m_MessageBitmap.SetBitmap (hbmp_Success);
		m_MessageBitmap.ShowWindow (SW_SHOW);

		// Update Upload Status
		o_FlickrClient.UpdateUploadStatus (s_WSFCHome, s_Token, s_NSID, this);
	}
	else // Error while Uploading Photo
	{
		// Show Message Text
		CString sMessage = "Error Occurred while Uploading Image \"";
				sMessage+= pWMParam->s_PhotoTitle;
				sMessage+= "\" ...";
		m_MessageText.SetWindowText (sMessage);
		m_MessageText.ShowWindow (SW_SHOW);

		// Set Bitmap
		m_MessageBitmap.SetBitmap (hbmp_Error);
		m_MessageBitmap.ShowWindow (SW_SHOW);
	}

	// Enable Upload Button
	m_UploadButton.EnableWindow (TRUE);

	RedrawWindow ();

	delete pWMParam;

	return 0;
}


LRESULT CFileUploaderDialog::OnUpdateUploadStatusDone (WPARAM wParam, LPARAM lParam)
{
	CWMParam* pParam = (CWMParam*)wParam;

	if (true == pParam->b_Success)
	{
		m_AvailableQuotaText.SetText (pParam->s_AvailableQuota);
		
		RedrawWindow ();
	}

	delete pParam;
	
	return 0;
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


void CFileUploaderDialog::OnClose ()
{
	o_FlickrClient.DestroyThreads ();

	CDialog::OnClose ();
}


void CFileUploaderDialog::OnSysCommand (UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_SETTINGS)
	{
		CSettingsDialog oDialog;
		if (IDOK == oDialog.DoModal ())
		{
			// Set WSF/C Home
			s_WSFCHome = oDialog.s_WSFCHome;

			// Save WSF/C Home
			CRegKey regKey;
			LONG    lResult;

			lResult = regKey.Create (HKEY_CURRENT_USER, _T("Software\\WSO2\\WeSCli\\FlickrUploader"));

			if (ERROR_SUCCESS == lResult)
				regKey.SetStringValue (_T("WSFCHome"), s_WSFCHome);
		}
	}

	CDialog::OnSysCommand (nID, lParam);
}
