// 课程作业大杂烩View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "课程作业大杂烩.h"

#include "课程作业大杂烩Doc.h"
#include "课程作业大杂烩View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_COMMAND(IDM_COLOR, OnColor)
	ON_COMMAND(IDM_SHAPE, OnShape)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_SET_FONT, OnSetFont)
	ON_COMMAND(IDM_EMPTY_CLIENT, OnEmptyClient)
	ON_WM_CHAR()
	ON_COMMAND(IDM_MODE_DRAW, OnModeDraw)
	ON_COMMAND(IDM_MODE_TEXT_EDIT, OnModeTextEdit)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView construction/destruction

CMyView::CMyView()
{
	// TODO: add construction code here

	m_LineWidth=0;
	m_LineStyle=1;
	m_ShapeIndex=0;
	m_clr = RGB(255,0,0);
	m_dcMetaFile.Create();
	m_strFontName="";
	m_strLine = "";
	m_modeID=0;
}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyView drawing

void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	HMETAFILE hmetaFile;
	hmetaFile = m_dcMetaFile.Close();
	//播放元文件
	pDC->PlayMetaFile(hmetaFile);
	//再创建一个元文件设备上下文对象以便再次绘制
	m_dcMetaFile.Create();
	m_dcMetaFile.PlayMetaFile(hmetaFile);
	//释放元文件资源
	DeleteMetaFile(hmetaFile);

}

/////////////////////////////////////////////////////////////////////////////
// CMyView printing

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers



void CMyView::OnColor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	//设置颜色对话框初始选择的颜色,不能给flag直接赋值
	dlg.m_cc.Flags |= CC_RGBINIT |CC_FULLOPEN;//与之前的标记组合起来
	dlg.m_cc.rgbResult=m_clr;
	if(IDOK==dlg.DoModal())
	{
		m_clr = dlg.m_cc.rgbResult;
	}
	
}

void CMyView::OnShape() 
{
	// TODO: Add your command handler code here
	CGrapicSetting dlg;
	dlg.m_LineWidth = m_LineWidth;
	dlg.m_LineStyle = m_LineStyle;
	dlg.m_ShapeIndex = m_ShapeIndex;
	if(IDOK==dlg.DoModal())
	{
		m_LineWidth = dlg.m_LineWidth;
		m_LineStyle = dlg.m_LineStyle;
		m_ShapeIndex = dlg.m_ShapeIndex;
	}
	
}

void CMyView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(m_modeID==1)
	{
		SetCaretPos(point);
		m_strLine.Empty();
		m_ptOrigin = point;
	}
	m_ptOrigin = point;
	
	CView::OnLButtonDown(nFlags, point);
}

void CMyView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CPen pen(m_LineStyle,m_LineWidth,m_clr);
	CPen *pOldpen = m_dcMetaFile.SelectObject(&pen);

	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	m_dcMetaFile.SelectObject(pBrush);

	switch(m_ShapeIndex)
	{
	case 1://draw dot
		 m_dcMetaFile.SetPixel(point,m_clr);
		 Invalidate();
		 break;
    case 2://draw line
		 m_dcMetaFile.MoveTo(m_ptOrigin);
		 m_dcMetaFile.LineTo(point);
		 Invalidate();
		 break;
	case 3://draw rectangle
		m_dcMetaFile.Rectangle(CRect(m_ptOrigin,point));
		Invalidate();
		 break;
	case 4:
	    m_dcMetaFile.Ellipse(CRect(m_ptOrigin,point));
		Invalidate();
		 break;
	}


	
	
	CView::OnLButtonUp(nFlags, point);
}

void CMyView::OnSetFont() 
{
	// TODO: Add your command handler code here
	CFontDialog dlg;
	if(IDOK==dlg.DoModal())
	{
		m_font.CreateFontIndirect(dlg.m_cf.lpLogFont);
		m_strFontName=dlg.m_cf.lpLogFont->lfFaceName;
	}
	if(m_font.m_hObject)
	{
		m_font.DeleteObject();
	}
	Invalidate();
}

void CMyView::OnEmptyClient() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH));
	m_dcMetaFile.SelectObject(pBrush);
	m_dcMetaFile.FillRect(rect,pBrush);
	Invalidate();
	
}

void CMyView::OnModeDraw() 
{
	// TODO: Add your command handler code here
	m_modeID = 0;
	OnEmptyClient();
	HideCaret();
}

void CMyView::OnModeTextEdit() 
{
	// TODO: Add your command handler code here
	
	m_modeID=1;
	OnEmptyClient();

	CClientDC dc(this);
	m_ptOrigin.x = 0;
	m_ptOrigin.y = 0;
	dc.TextOut(m_ptOrigin.x,m_ptOrigin.y,m_strLine);
	ShowCaret();
}


void CMyView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default



	if(m_modeID==1)
	{
	    CClientDC dc(this);
		TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);
	   if(0x0d == nChar)//回车字符十六进制值是0x0d，
		{
			//清空字符区，新的行输入
			m_strLine.Empty();
			//光标下移
			m_ptOrigin.y += tm.tmHeight;
		}
		else if(0x08 == nChar)//退格键是0x08
		{
			//用背景色输出一次字符串（返回值是原来的字体颜色！）
			COLORREF clr = dc.SetTextColor(dc.GetBkColor());
			dc.TextOut(m_ptOrigin.x,m_ptOrigin.y,m_strLine);
			//删减字符串，然后再打印一次字符串
			m_strLine = m_strLine.Left(m_strLine.GetLength()-1);
			dc.SetTextColor(clr);
		}
		else
		{
			//不是以上两种情况，则把字符串存到字符区
			m_strLine += nChar;
		}
		//获得插入字符宽度
		CSize sz =dc.GetTextExtent(m_strLine);
		CPoint pt;
		//定义点，其坐标应该是光标移动的新位置。即原位置加上字体的
		//宽度，高度不变。
		pt.x = m_ptOrigin.x + sz.cx;
		pt.y = m_ptOrigin.y;
		SetCaretPos(pt);

		dc.TextOut(m_ptOrigin.x,m_ptOrigin.y,m_strLine);

		
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}






int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CClientDC dc(this);
	TEXTMETRIC tm;
	//获得设备描述表中的文本信息
	dc.GetTextMetrics(&tm);
	//根据字体大小创建合适的插入符
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);//除以8是经验值
	
	
	return 0;
}
