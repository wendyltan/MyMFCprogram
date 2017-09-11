// wwd262Doc.cpp : implementation of the CWwd262Doc class
//

#include "stdafx.h"
#include "wwd262.h"

#include "wwd262Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWwd262Doc

IMPLEMENT_DYNCREATE(CWwd262Doc, CDocument)

BEGIN_MESSAGE_MAP(CWwd262Doc, CDocument)
	//{{AFX_MSG_MAP(CWwd262Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWwd262Doc construction/destruction

CWwd262Doc::CWwd262Doc()
{
	// TODO: add one-time construction code here

}

CWwd262Doc::~CWwd262Doc()
{
}

BOOL CWwd262Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWwd262Doc serialization

void CWwd262Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWwd262Doc diagnostics

#ifdef _DEBUG
void CWwd262Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWwd262Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWwd262Doc commands


BOOL LoadBmpFile(char* BmpFileName);
BOOL CWwd262Doc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	LoadBmpFile((char*)lpszPathName);
	return TRUE;
}
