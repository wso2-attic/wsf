// Expanding and collapsing dialogs
//
// Michael Walz (walz@epsitec.ch)
// Dec. 99
//

#include "stdafx.h"
#include "DialogExpander.h"

void ShrinkDialog(CWnd *pDlg, int idmark)
{   
  ASSERT(pDlg != NULL) ;  
  CWnd *pWndMark = pDlg->GetDlgItem(idmark) ;
  ASSERT(pWndMark != NULL) ;
  CRect markrect ;
  CRect dlgrect ;
  CRect clientrect ;
  CWnd *pParentWnd = pDlg->GetParent() ;
  int offset ;

  pDlg->GetClientRect(&clientrect) ;  // clientrect of the dialog
  pDlg->GetWindowRect(&dlgrect) ;	  // rectangle of the dialog window

  // get height of the title bar
  offset = dlgrect.Height() - clientrect.bottom ;

  pWndMark->GetWindowRect(&markrect) ;
 

  pDlg->ScreenToClient(&markrect) ;

  // calculate the new rectangle of the dialog window
  dlgrect.bottom = dlgrect.top + markrect.bottom + offset;

  pDlg->MoveWindow (dlgrect.left, dlgrect.top, dlgrect.Width(), dlgrect.Height()) ;
}


CExpandDialog::CExpandDialog()
{
  m_bIsInitialized = FALSE ;
}


void CExpandDialog::Initialize(CWnd *pDialog, BOOL bInitiallyExpanded,
						  int IdExpandButton, int IdCollapsedMark,
						  int IdCollapsedText)
{
  m_IdExpandButton = IdExpandButton;
  m_IdCollapsedMark = IdCollapsedMark;
  m_IdCollapsedText = IdCollapsedText;
  m_bIsInitialized = TRUE ;
  m_pDialog = pDialog ;
  m_bIsExpanded = TRUE ;

  m_pDialog->GetWindowRect(&m_dialogrect) ;	  // rectangle of the dialog window
  m_pDialog->GetDlgItemText(IdExpandButton, m_sTextMore) ; 
  m_pDialog->GetDlgItemText(IdCollapsedText, m_sTextLess) ; 

  CWnd *pWndMark = m_pDialog->GetDlgItem(m_IdCollapsedText) ;
  pWndMark->ShowWindow(SW_HIDE);	// hide the "delimiting" control

  pWndMark = m_pDialog->GetDlgItem(m_IdCollapsedMark) ;
  pWndMark->ShowWindow(SW_HIDE);	// hide the "delimiting" control

  if (bInitiallyExpanded)
  {
	CWnd *pButton = m_pDialog->GetDlgItem(m_IdExpandButton) ;
	pButton->SetWindowText(m_sTextLess ) ;
  }
  else
	OnExpandButton() ;
}


void CExpandDialog::OnExpandButton()
{
  ASSERT(m_bIsInitialized) ;

  CWnd *pButton ;
  m_bIsExpanded = !m_bIsExpanded ;	

  if (m_bIsExpanded)
  {
	// ShrinkDialog(m_pDialog, m_IdExpandedMark) ;
	CRect rect ;
	m_pDialog->GetWindowRect(&rect) ;
	rect.bottom = rect.top + m_dialogrect.Height() ;
	rect.right = rect.left + m_dialogrect.Width() ;
	m_pDialog->MoveWindow (&rect) ;
  }
  else
	ShrinkDialog(m_pDialog, m_IdCollapsedMark ) ;

  
  pButton = m_pDialog->GetDlgItem(m_IdExpandButton) ;
  pButton->SetWindowText(!m_bIsExpanded ? m_sTextMore : m_sTextLess ) ;

}