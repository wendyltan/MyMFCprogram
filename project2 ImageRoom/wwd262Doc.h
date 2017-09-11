// wwd262Doc.h : interface of the CWwd262Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WWD262DOC_H__3A1000F6_5A8F_45C2_AADD_26BF0FF580CF__INCLUDED_)
#define AFX_WWD262DOC_H__3A1000F6_5A8F_45C2_AADD_26BF0FF580CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWwd262Doc : public CDocument
{
protected: // create from serialization only
	CWwd262Doc();
	DECLARE_DYNCREATE(CWwd262Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWwd262Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWwd262Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWwd262Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WWD262DOC_H__3A1000F6_5A8F_45C2_AADD_26BF0FF580CF__INCLUDED_)
