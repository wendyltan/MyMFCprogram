// 课程作业大杂烩View.h : interface of the CMyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEW_H__B7D8D59A_E525_4E0A_B0A0_C3356877B37F__INCLUDED_)
#define AFX_VIEW_H__B7D8D59A_E525_4E0A_B0A0_C3356877B37F__INCLUDED_
#include "课程作业大杂烩Doc.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GrapicSetting.h"

typedef struct imageinfo
{
	CPoint point;
	CString string;
}ImageInfo;

class CMyView : public CView
{
protected: // create from serialization only
	CMyView();
	DECLARE_DYNCREATE(CMyView)

// Attributes
public:
	CMyDoc* GetDocument();
	void DeleteandAdd();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyView)
	afx_msg void OnColor();
	afx_msg void OnShape();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSetFont();
	afx_msg void OnEmptyClient();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnModeDraw();
	afx_msg void OnModeTextEdit();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTextSave();
	afx_msg void OnTextLoad();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_charCounter;
	int m_infoCounter;

	CPoint m_ptOrigin;
	COLORREF m_clr;
	int m_ShapeIndex;
	UINT m_LineWidth;
	int m_LineStyle;
	CGrapicSetting m_Graphic;
	CMetaFileDC m_dcMetaFile;
	CString m_strFontName;
	CFont m_font;
	CString m_strLine;
	ImageInfo info[100];
public:
	int m_modeID;
};

#ifndef _DEBUG  // debug version in 课程作业大杂烩View.cpp
inline CMyDoc* CMyView::GetDocument()
   { return (CMyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW_H__B7D8D59A_E525_4E0A_B0A0_C3356877B37F__INCLUDED_)
