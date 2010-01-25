#pragma once

#include "resource.h"
#include "DialogExpander.h"
#include "ImageListCtrl.h"
#include "ImageDetails.h"
#include <list>
#include "afxcmn.h"
#include "afxwin.h"

using namespace std;

class CFileUploaderDialog : public CDialog
{
	DECLARE_DYNAMIC(CFileUploaderDialog)

	public:
		CFileUploaderDialog (CWnd* pParent = NULL);
		virtual ~CFileUploaderDialog ();

		enum { IDD = IDD_DIALOG_FILE_UPLOADER };

		typedef list<CString>	FileName_lst_t;
		
		void	SetFileNames	   (FileName_lst_t _lstFileName);
		void	EnableUploadButton (BOOL _bEnable);
		void	ShowImageDetails   (int _iItemIndex);
		void	StoreImageDetails  (int _iItemIndex);

	protected:
		virtual void DoDataExchange (CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()

	private:
		virtual BOOL OnInitDialog ();
		afx_msg void OnButtonAPIKey ();
		afx_msg void OnButtonUpload ();

		CString	GetFileSize  (CString _sFileName);
		void	ShowHelpText (void);
		
		FileName_lst_t									lst_FileName;
		CImageDetails::ImageDetailsByItemIndex_map_t	map_ImageDetailsByItemIndex;

		CExpandDialog		m_ExpandDialog;
		CImageListCtrl		m_ImageListCtrl;
		CEdit				m_TitleEdit;
		CEdit				m_DescriptionEdit;
		CEdit				m_TagsEdit;
		CButton				m_OnlyMeRadioButton;
		CButton				m_FamilyCheckBox;
		CButton				m_FriendsCheckBox;
		CButton				m_AnyoneRadioButton;
		CComboBox			m_SafetyLevelCombo;
		CComboBox			m_HiddenCombo;
		CComboBox			m_ContentTypeCombo;
		CButton				m_UploadButton;
		CEdit				m_APIKeyEdit;
		CButton				m_RememberKeyCheckBox;
		CStatic				m_FileName;
		CStatic				m_FileSize;
		CAnimateCtrl		m_AnimateCtrl;
		CStatic				m_UploadStatus;
		CStatic				m_MessageText;
};
