// wwd262View.cpp : implementation of the CWwd262View class
//

#include "stdafx.h"
#include "wwd262.h"
#include <complex>
using namespace std;

#include "wwd262Doc.h"
#include "wwd262View.h"
#include "DlgHistogram.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWwd262View

IMPLEMENT_DYNCREATE(CWwd262View, CScrollView)

BEGIN_MESSAGE_MAP(CWwd262View, CScrollView)
	//{{AFX_MSG_MAP(CWwd262View)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_GRAY, OnGray)
	ON_UPDATE_COMMAND_UI(ID_HISTOGRAM, OnUpdateHistogram)
	ON_COMMAND(ID_HISTOGRAM, OnHistogram)
	ON_UPDATE_COMMAND_UI(ID_GRAY, OnUpdateGray)
	ON_COMMAND(ID_LINERTRANS, OnLinertrans)
	ON_UPDATE_COMMAND_UI(ID_LINERTRANS, OnUpdateLinertrans)
	ON_COMMAND(ID_EQUALIZE, OnEqualize)
	ON_UPDATE_COMMAND_UI(ID_EQUALIZE, OnUpdateEqualize)
	ON_COMMAND(ID_FT, OnFt)
	ON_UPDATE_COMMAND_UI(ID_FT, OnUpdateFt)
	ON_COMMAND(ID_IFT, OnIft)
	ON_UPDATE_COMMAND_UI(ID_IFT, OnUpdateIft)
	ON_COMMAND(ID_FFT, OnFft)
	ON_UPDATE_COMMAND_UI(ID_FFT, OnUpdateFft)
	ON_COMMAND(ID_IFFT, OnIfft)
	ON_UPDATE_COMMAND_UI(ID_IFFT, OnUpdateIfft)
	ON_COMMAND(ID_AVERAGEFILTER, OnAveragefilter)
	ON_COMMAND(ID_MEDIANFILTER, OnMedianfilter)
	ON_COMMAND(ID_GRADSHARP, OnGradsharp)
	ON_COMMAND(ID_RAPLASSHARP, OnRaplassharp)
	ON_UPDATE_COMMAND_UI(ID_AVERAGEFILTER, OnUpdateAveragefilter)
	ON_UPDATE_COMMAND_UI(ID_MEDIANFILTER, OnUpdateMedianfilter)
	ON_UPDATE_COMMAND_UI(ID_GRADSHARP, OnUpdateGradsharp)
	ON_UPDATE_COMMAND_UI(ID_RAPLASSHARP, OnUpdateRaplassharp)
	ON_COMMAND(ID_LOW, OnLow)
	ON_COMMAND(ID_HIGH, OnHigh)
	ON_UPDATE_COMMAND_UI(ID_LOW, OnUpdateLow)
	ON_UPDATE_COMMAND_UI(ID_HIGH, OnUpdateHigh)
	ON_COMMAND(ID_BLOW, OnBlow)
	ON_COMMAND(ID_BHIGH, OnBhigh)
	ON_UPDATE_COMMAND_UI(ID_BLOW, OnUpdateBlow)
	ON_UPDATE_COMMAND_UI(ID_BHIGH, OnUpdateBhigh)
	ON_COMMAND(ID_SHOW_ORIGIN, OnShowOrigin)
	ON_UPDATE_COMMAND_UI(ID_SHOW_ORIGIN, OnUpdateShowOrigin)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWwd262View construction/destruction

extern BITMAPINFO *lpBitsInfo;
extern BITMAPINFO *lpDIB_FFT;
extern BITMAPINFO *lpDIB_IFFT;
extern LPBITMAPINFO  lpBitsInfo_backup;
extern complex<double> *gFD;
CWwd262View::CWwd262View()
{
	// TODO: add construction code here
	if (lpBitsInfo)
		free(lpBitsInfo);
	if (lpBitsInfo_backup )
		free(lpBitsInfo_backup );
	if (lpDIB_FFT)
		free(lpDIB_FFT);

}

CWwd262View::~CWwd262View()
{
}

BOOL CWwd262View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWwd262View drawing


void CWwd262View::OnDraw(CDC* pDC)
{
	CWwd262Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	
	if(NULL == lpBitsInfo)
		return;


	LPVOID lpBits = (LPVOID)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	StretchDIBits( 
		pDC->GetSafeHdc(),
		0,0,
		lpBitsInfo->bmiHeader.biWidth,
		lpBitsInfo->bmiHeader.biHeight,
		0,0,
		lpBitsInfo->bmiHeader.biWidth,
		lpBitsInfo->bmiHeader.biHeight,
		
		lpBits, 
		lpBitsInfo,

		DIB_RGB_COLORS,
		SRCCOPY
	);

	if (lpDIB_FFT)
	{
		lpBits = (LPVOID)&lpDIB_FFT->bmiColors[lpDIB_FFT->bmiHeader.biClrUsed];
		StretchDIBits( 
			pDC->GetSafeHdc(),
			600,0,
			lpDIB_FFT->bmiHeader.biWidth,
			lpDIB_FFT->bmiHeader.biHeight,
			0,0,
			lpDIB_FFT->bmiHeader.biWidth,
			lpDIB_FFT->bmiHeader.biHeight,
			lpBits,
			lpDIB_FFT, // bitmap data 
			DIB_RGB_COLORS,
			SRCCOPY);
	}

	if (lpDIB_IFFT)
	{
		lpBits = (LPVOID)&lpDIB_IFFT->bmiColors[lpDIB_IFFT->bmiHeader.biClrUsed];
		StretchDIBits( 
			pDC->GetSafeHdc(),
			0,600,
			lpDIB_IFFT->bmiHeader.biWidth,
			lpDIB_IFFT->bmiHeader.biHeight,
			0,0,
			lpDIB_IFFT->bmiHeader.biWidth,
			lpDIB_IFFT->bmiHeader.biHeight,
			lpBits,
			lpDIB_IFFT, // bitmap data 
			DIB_RGB_COLORS,
			SRCCOPY);
	}



}



void CWwd262View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 1120;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CWwd262View printing

BOOL CWwd262View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWwd262View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWwd262View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWwd262View diagnostics

#ifdef _DEBUG
void CWwd262View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CWwd262View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CWwd262Doc* CWwd262View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWwd262Doc)));
	return (CWwd262Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWwd262View message handlers


void pixel(int i,int j);
void CWwd262View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	pixel(point.y,point.x);
	
	CScrollView::OnLButtonDown(nFlags, point);
}



void Gray();
void CWwd262View::OnGray() 
{
	// TODO: Add your command handler code here
	Gray();
	Invalidate();

	
}

void CWwd262View::OnUpdateGray(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo!=NULL&&lpBitsInfo->bmiHeader.biBitCount==24);
	
}


//恢复到原图
void recover();

void CWwd262View::OnShowOrigin() 
{
	// TODO: Add your command handler code here
	recover();

	if(lpDIB_FFT != NULL){
		free(lpDIB_FFT);
		lpDIB_FFT= NULL;
	}

	Invalidate();
}

void CWwd262View::OnUpdateShowOrigin(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
	
}
//---------------------------实验二：计算直方图、点运算、均衡化响应函数部分---------------------------------/

void CWwd262View::OnHistogram() 
{
	// TODO: Add your command handler code here
	CDlgHistogram dlg;
	dlg.DoModal();


	
}

void CWwd262View::OnUpdateHistogram(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo!=NULL&&lpBitsInfo->bmiHeader.biBitCount==8);
	
}


void LinerTrans(float,float);

void CWwd262View::OnLinertrans() 
{
	// TODO: Add your command handler code here
	LinerTrans(2,-100);
	Invalidate();

	
}



void CWwd262View::OnUpdateLinertrans(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
	
}


void Equalize();
void CWwd262View::OnEqualize() 
{
	// TODO: Add your command handler code here
	Equalize();
	Invalidate();
	
}

void CWwd262View::OnUpdateEqualize(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
	
}





//---------------------------实验三：傅里叶变换与傅里叶反变换响应函数部分---------------------------/
void FastFourier();
void CWwd262View::OnFft() 
{
	// TODO: Add your command handler code here
	if (lpDIB_FFT)
		free(lpDIB_FFT);

	
	FastFourier();
	Invalidate();
			
}

void CWwd262View::OnUpdateFft(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL && lpBitsInfo->bmiHeader.biBitCount == 8);
}


void IfastFourier();
void CWwd262View::OnIfft() 
{
	// TODO: Add your command handler code here
	if (lpDIB_IFFT)
		free(lpDIB_IFFT);

	IfastFourier();
	Invalidate();
	
}

void CWwd262View::OnUpdateIfft(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpDIB_FFT != NULL);
}


void Fourier();
void CWwd262View::OnFt() 
{
	// TODO: Add your command handler code here
	Fourier();
	Invalidate();
	
}

void CWwd262View::OnUpdateFt(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
	
}

void  IFourier();
void CWwd262View::OnIft() 
{
	// TODO: Add your command handler code here
	IFourier();
	Invalidate();
	
}

 

void CWwd262View::OnUpdateIft(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(gFD != NULL);
	
}

//---------------------------------实验四：空域滤波相应函数部分------------------------------------------/
void AverageFilter();
void MedianFilter();
void GradSharp();
void RaplasSharp();

void CWwd262View::OnAveragefilter() 
{
	// TODO: Add your command handler code here
	AverageFilter();
	Invalidate();
}

void CWwd262View::OnMedianfilter() 
{
	// TODO: Add your command handler code here
	MedianFilter();
	Invalidate();
}

void CWwd262View::OnGradsharp() 
{
	// TODO: Add your command handler code here
	GradSharp();
	Invalidate();
}

void CWwd262View::OnRaplassharp() 
{
	// TODO: Add your command handler code here
	RaplasSharp();
	Invalidate();
}


void CWwd262View::OnUpdateAveragefilter(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
}

void CWwd262View::OnUpdateMedianfilter(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
}

void CWwd262View::OnUpdateGradsharp(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
}

void CWwd262View::OnUpdateRaplassharp(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
}
//---------------------------------实验五：频域滤波响应函数部分--------------------------------------/
//理想频域滤波函数
void Ideal_Filter_FFT(int D);

void CWwd262View::OnLow() 
{
	// TODO: Add your command handler code here
	Ideal_Filter_FFT(40);
	Invalidate();
	
}

void CWwd262View::OnHigh() 
{
	// TODO: Add your command handler code here
	Ideal_Filter_FFT(-40);
	Invalidate();
	
}


void CWwd262View::OnUpdateLow(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpDIB_FFT != NULL);
	
}

void CWwd262View::OnUpdateHigh(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpDIB_FFT != NULL);
	
}

//巴特沃斯频域滤波函数
void Butterworth_Filter_FFT(int D);

void CWwd262View::OnBlow() 
{
	// TODO: Add your command handler code here
	Butterworth_Filter_FFT(40);
	Invalidate();
	
}

void CWwd262View::OnBhigh() 
{
	// TODO: Add your command handler code here
	Butterworth_Filter_FFT(-40);
	Invalidate();
	
}



void CWwd262View::OnUpdateBlow(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpDIB_FFT != NULL);
}

void CWwd262View::OnUpdateBhigh(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpDIB_FFT != NULL);
}




