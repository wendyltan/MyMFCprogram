// wwd262View.h : interface of the CWwd262View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WWD262VIEW_H__FF6A77C0_702D_4727_95E4_57464587F1B2__INCLUDED_)
#define AFX_WWD262VIEW_H__FF6A77C0_702D_4727_95E4_57464587F1B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWwd262View : public CScrollView
{
protected: // create from serialization only
	CWwd262View();
	DECLARE_DYNCREATE(CWwd262View)

// Attributes
public:
	CWwd262Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWwd262View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWwd262View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWwd262View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnGray();
	afx_msg void OnUpdateHistogram(CCmdUI* pCmdUI);
	afx_msg void OnHistogram();
	afx_msg void OnUpdateGray(CCmdUI* pCmdUI);
	afx_msg void OnLinertrans();
	afx_msg void OnUpdateLinertrans(CCmdUI* pCmdUI);
	afx_msg void OnEqualize();
	afx_msg void OnUpdateEqualize(CCmdUI* pCmdUI);
	afx_msg void OnFt();
	afx_msg void OnUpdateFt(CCmdUI* pCmdUI);
	afx_msg void OnIft();
	afx_msg void OnUpdateIft(CCmdUI* pCmdUI);
	afx_msg void OnFft();
	afx_msg void OnUpdateFft(CCmdUI* pCmdUI);
	afx_msg void OnIfft();
	afx_msg void OnUpdateIfft(CCmdUI* pCmdUI);
	afx_msg void OnAveragefilter();
	afx_msg void OnMedianfilter();
	afx_msg void OnGradsharp();
	afx_msg void OnRaplassharp();
	afx_msg void OnUpdateAveragefilter(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMedianfilter(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGradsharp(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRaplassharp(CCmdUI* pCmdUI);
	afx_msg void OnLow();
	afx_msg void OnHigh();
	afx_msg void OnUpdateLow(CCmdUI* pCmdUI);
	afx_msg void OnUpdateHigh(CCmdUI* pCmdUI);
	afx_msg void OnBlow();
	afx_msg void OnBhigh();
	afx_msg void OnUpdateBlow(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBhigh(CCmdUI* pCmdUI);
	afx_msg void OnShowOrigin();
	afx_msg void OnUpdateShowOrigin(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in wwd262View.cpp
inline CWwd262Doc* CWwd262View::GetDocument()
   { return (CWwd262Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WWD262VIEW_H__FF6A77C0_702D_4727_95E4_57464587F1B2__INCLUDED_)
