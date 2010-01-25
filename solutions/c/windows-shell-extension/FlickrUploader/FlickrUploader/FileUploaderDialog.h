#pragma once

#include "resource.h"
#include "ImageListCtrl.h"
#include "ImageDetails.h"
#include <list>
#include "afxcmn.h"
#include "afxwin.h"
#include "MyTextCtrl.h"
#include "MyURLCtrl.h"
#include "AvailableSetsListCtrl.h"
#include "SelectedSetsListCtrl.h"
#include "PhotoSetInfo.h"
#include "FlickrClient.h"
#include "MyRadioButton.h"
#include "WaitAnimation.h"

using namespace std;

class CFileUploaderDialog : public CDialog
{
	DECLARE_DYNAMIC(CFileUploaderDialog)

	public:
		CFileUploaderDialog (CWnd* pParent = NULL);
		virtual ~CFileUploaderDialog ();

		enum { IDD = IDD_DIALOG_FILE_UPLOADER };

		typedef list<CString>	FileName_lst_t;
		
		void			SetFileNames		(FileName_lst_t _lstFileName);
		void			ShowImageDetails	(int _iItemIndex);
		void			StoreImageDetails	(int _iItemIndex);
		void			EnableImageControls	(BOOL _bEnable);
		CPhotoSetInfo*  GetPhotoSetInfo		(CString _sName);
		void		    RemovePhotoSetInfo	(CString _sName);

	protected:
		virtual void DoDataExchange (CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()

	private:
		virtual BOOL OnInitDialog          (void);
		afx_msg void OnTimer		       (UINT_PTR nIDEvent);
		afx_msg void OnButtonSignIn        (void);
		afx_msg void OnButtonReady	       (void);
		afx_msg void OnButtonSignOut       (void);
		afx_msg void OnButtonAddSet	       (void);
		afx_msg void OnButtonRemoveSet     (void);
		afx_msg void OnButtonUpload        (void);
		afx_msg void OnClose			   (void);
		afx_msg void OnSysCommand		   (UINT nID, LPARAM lParam);
		afx_msg LRESULT OnWaitAnimationMessage   (WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT OnRestoreUserDone        (WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT OnGetFrobDone		     (WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT OnCreateUserDone	     (WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT OnCreateNewSet		     (WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT OnCreateNewSetDone	     (WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT OnAddToSet	             (WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT OnFileUploadDone         (WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT OnUpdateUploadStatusDone (WPARAM wParam, LPARAM lParam);

		void	ShowOfflineMessage		   (void);
		void	ShowWaitAnimation		   (void);
		void	ShowLoginContinueMessage   (void);
		void	ShowOnlineMessage		   (CString _sUsername, CString _sPhotosURL, CString _sProfileURL, CString _sAvailableQuota);
		void	ShowHelpText			   (void);
		
		CString	GetFileSize				   (CString _sFileName);

		CFlickrClient			o_FlickrClient;

		FileName_lst_t									lst_FileName;
		CImageDetails::ImageDetailsByItemIndex_map_t	map_ImageDetailsByItemIndex;

		CPhotoSetInfo::PhotoSetInfoByName_map_t			map_PhotoSetInfoByName;

		CWaitAnimation			m_WaitAnimation;
		CStatic					m_WaitAnimationMessage;

		CMyTextCtrl				m_UsenameText;
		CMyURLCtrl				m_UserPhotosURLCtrl;
		CMyURLCtrl				m_UserProfileURLCtrl;
		CMyTextCtrl				m_AvailableQuotaText;

		bool					b_SignedIn;
		CString					s_WSFCHome;
				
		// User Bitmap
		CStatic					m_UserBitmap;
		HBITMAP					hbmp_Online;
		HBITMAP					hbmp_Offline;
		HBITMAP					hbmp_Timer;
		HICON					hico_FlickrPal16;
		HICON					hico_FlickrPal32;

		CImageListCtrl			m_ImageListCtrl;
		
		// Image Controls
		CStatic					m_ImageDetailsGroupBox;
		CStatic					m_TitleCaption;
		CEdit					m_TitleEdit;
		CStatic					m_DescriptionCaption;
		CEdit					m_DescriptionEdit;
		CStatic					m_TagsCaption;
		CEdit					m_TagsEdit;
		CStatic					m_WhoCanSeeGroupBox;
		CMyRadioButton			m_OnlyMeRadioButton;
		CButton					m_FamilyCheckBox;
		CButton					m_FriendsCheckBox;
		CMyRadioButton			m_AnyoneRadioButton;
		CStatic					m_SafetyLevelCaption;
		CComboBox				m_SafetyLevelCombo;
		CStatic					m_HiddenCaption;
		CComboBox				m_HiddenCombo;
		CStatic					m_ContentTypeCaption;
		CComboBox				m_ContentTypeCombo;
		CStatic					m_AvailableSetsCaption;
		CAvailableSetsListCtrl	m_AvailableSetsListCtrl;
		CStatic					m_SelectedSetsCaption;
		CSelectedSetsListCtrl	m_SelectedSetsListCtrl;
		CImageList				m_SetsImageList;
		CButton					m_AddSetButton;
		CButton					m_RemoveSetButton;
		CStatic					m_FileNameCaption;
		CStatic					m_FileName;
		CStatic					m_FileSizeCaption;
		CStatic					m_FileSize;
		
		CButton					m_UploadButton;
		CAnimateCtrl			m_AnimateCtrl;
		CStatic					m_UploadStatus;
		CStatic					m_MessageText;
		CStatic					m_MessageBitmap;
		HBITMAP					hbmp_Help;
		HBITMAP					hbmp_Success;
		HBITMAP					hbmp_Error;

		// User Profile Data
		CString					s_Frob;
		CString					s_Username;
		CString					s_NSID;
		CString					s_Token;
};
