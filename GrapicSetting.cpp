// GrapicSetting.cpp : implementation file
//

#include "stdafx.h"
#include "课程作业大杂烩.h"
#include "GrapicSetting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGrapicSetting dialog


CGrapicSetting::CGrapicSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CGrapicSetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGrapicSetting)
	m_LineWidth = 0;
	//}}AFX_DATA_INIT
}


void CGrapicSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGrapicSetting)
	DDX_Text(pDX, IDC_LINE_WIDTH, m_LineWidth);
	DDV_MinMaxInt(pDX, m_LineWidth, 0, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGrapicSetting, CDialog)
	//{{AFX_MSG_MAP(CGrapicSetting)
	ON_BN_CLICKED(IDC_SOLID, OnSolid)
	ON_BN_CLICKED(IDC_DASH, OnDash)
	ON_BN_CLICKED(IDC_DOTTED, OnDotted)
	ON_BN_CLICKED(IDC_DOT, OnDot)
	ON_BN_CLICKED(IDC_LINE, OnLine)
	ON_BN_CLICKED(IDC_RECTANGLE, OnRectangle)
	ON_BN_CLICKED(IDC_ELLIPSE, OnEllipse)
	ON_EN_CHANGE(IDC_LINE_WIDTH, OnChangeLineWidth)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrapicSetting message handlers

void CGrapicSetting::OnSolid() 
{
	// TODO: Add your control notification handler code here
	m_LineStyle = 0;
	
}

void CGrapicSetting::OnDash() 
{
	// TODO: Add your control notification handler code here
	m_LineStyle = 1;
	
}

void CGrapicSetting::OnDotted() 
{
	// TODO: Add your control notification handler code here
	m_LineStyle = 2;
	
}

void CGrapicSetting::OnDot() 
{
	// TODO: Add your control notification handler code here
	m_ShapeIndex = 1;
	
}

void CGrapicSetting::OnLine() 
{
	// TODO: Add your control notification handler code here
	m_ShapeIndex = 2;
	
}

void CGrapicSetting::OnRectangle() 
{
	// TODO: Add your control notification handler code here
	m_ShapeIndex = 3;
	
}

void CGrapicSetting::OnEllipse() 
{
	// TODO: Add your control notification handler code here
	m_ShapeIndex = 4;
	
}

void CGrapicSetting::OnChangeLineWidth() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

	m_LineWidth = GetDlgItemInt(IDC_LINE_WIDTH);

}

void CGrapicSetting::OnOK() 
{
	// TODO: Add extra validation here
	
	EndDialog(IDOK);
}
