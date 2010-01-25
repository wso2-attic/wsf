#pragma once

#include "afxcmn.h"
#include "WSFCHomeListCtrl.h"

class CSettingsDialog : public CDialog
{
	DECLARE_DYNAMIC (CSettingsDialog)

	public:
		CSettingsDialog (CWnd* pParent = NULL);
		virtual ~CSettingsDialog ();

		enum { IDD = IDD_DIALOG_SETTINGS };

		virtual BOOL OnInitDialog (void);
		virtual void OnOK		  (void);

		CString		s_WSFCHome;

	protected:
		virtual void DoDataExchange (CDataExchange* pDX);

		DECLARE_MESSAGE_MAP ()

	private:
		CWSFCHomeListCtrl	m_WSFCHomeListCtrl;
};
