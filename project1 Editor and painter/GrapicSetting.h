#if !defined(AFX_GRAPICSETTING_H__F71EAD86_2600_4324_A6FA_77B41E54D170__INCLUDED_)
#define AFX_GRAPICSETTING_H__F71EAD86_2600_4324_A6FA_77B41E54D170__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GrapicSetting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGrapicSetting dialog

class CGrapicSetting : public CDialog
{
// Construction
public:
	CGrapicSetting(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGrapicSetting)
	enum { IDD = IDD_DIALOG1 };
	UINT		m_LineWidth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrapicSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGrapicSetting)
	afx_msg void OnSolid();
	afx_msg void OnDash();
	afx_msg void OnDotted();
	afx_msg void OnDot();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnEllipse();
	afx_msg void OnChangeLineWidth();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	int m_ShapeIndex;
	int m_LineStyle;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPICSETTING_H__F71EAD86_2600_4324_A6FA_77B41E54D170__INCLUDED_)
