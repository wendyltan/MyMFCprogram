// wwd262.h : main header file for the WWD262 application
//

#if !defined(AFX_WWD262_H__AEE8B38E_92F1_4148_8CDC_447F2A48F30D__INCLUDED_)
#define AFX_WWD262_H__AEE8B38E_92F1_4148_8CDC_447F2A48F30D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWwd262App:
// See wwd262.cpp for the implementation of this class
//

class CWwd262App : public CWinApp
{
public:
	CWwd262App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWwd262App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWwd262App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WWD262_H__AEE8B38E_92F1_4148_8CDC_447F2A48F30D__INCLUDED_)
