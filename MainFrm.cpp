// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "课程作业大杂烩.h"
#include "课程作业大杂烩View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(IDM_MODE_DRAW, OnUpdateModeDraw)
	ON_UPDATE_COMMAND_UI(IDM_MODE_TEXT_EDIT, OnUpdateModeTextEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	IDS_TIMER,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_bAutoMenuEnable = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//new toolbar
	CTime t = CTime::GetCurrentTime();
	CString str = t.Format("%H:%M:%S");
	//m_wndStatusBar.SetPaneText(1,str);
	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	int index=0;
	index = m_wndStatusBar.CommandToIndex(IDS_TIMER);
	m_wndStatusBar.SetPaneInfo(index,IDS_TIMER,SBPS_NORMAL,sz.cx);
	m_wndStatusBar.SetPaneText(index,str);
	SetTimer(1,1000,NULL);

	
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers





void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	
	CTime t = CTime::GetCurrentTime();
	CString str = t.Format("%H:%M:%S");

	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	m_wndStatusBar.SetPaneInfo(1,IDS_TIMER,SBPS_NORMAL,sz.cx);
	m_wndStatusBar.SetPaneText(1,str);

	CFrameWnd::OnTimer(nIDEvent);
}


void CMainFrame::OnUpdateModeDraw(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here


	//GetMenu()->EnableMenuItem(5,MF_BYPOSITION   |MF_DISABLED);
	for(int i=0;i<3;i++)
	{
		GetMenu()->GetSubMenu(4)->EnableMenuItem(i,MF_BYPOSITION|MF_DISABLED);	
		GetMenu()->GetSubMenu(5)->EnableMenuItem(i,MF_BYPOSITION|MF_ENABLED);
	}
	


}

void CMainFrame::OnUpdateModeTextEdit(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code herev	

	for(int i=0;i<3;i++)
	{
		GetMenu()->GetSubMenu(5)->EnableMenuItem(i,MF_BYPOSITION|MF_DISABLED);	
		GetMenu()->GetSubMenu(4)->EnableMenuItem(i,MF_BYPOSITION|MF_ENABLED);
	}
	

}
