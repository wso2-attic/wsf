#pragma once

#include "resource.h"

#include "PhotoSetInfo.h"

class CCreateNewSetDialog : public CDialog
{
	DECLARE_DYNAMIC (CCreateNewSetDialog)

	public:
		CCreateNewSetDialog (CWnd* pParent = NULL);
		virtual ~CCreateNewSetDialog ();

		void SetPhotoSetInfo (CPhotoSetInfo::PhotoSetInfoByName_map_t* _pPhotoSetInfoByName);

		enum { IDD = IDD_DIALOG_CREATE_NEW_SET };

	protected:
		virtual void DoDataExchange (CDataExchange* pDX);
		virtual void OnOK ();

		DECLARE_MESSAGE_MAP ()
	
	public:
		CString		s_Name;
		CString		s_Description;

	private:
		CPhotoSetInfo::PhotoSetInfoByName_map_t*	p_PhotoSetInfoByName;
};
