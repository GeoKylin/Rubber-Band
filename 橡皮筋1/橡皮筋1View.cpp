
// 橡皮筋1View.cpp : C橡皮筋1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "橡皮筋1.h"
#endif

#include "橡皮筋1Doc.h"
#include "橡皮筋1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C橡皮筋1View

IMPLEMENT_DYNCREATE(C橡皮筋1View, CView)

BEGIN_MESSAGE_MAP(C橡皮筋1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_APP_jvxing, &C橡皮筋1View::OnAppjvxing)
	ON_UPDATE_COMMAND_UI(ID_APP_jvxing, &C橡皮筋1View::OnUpdateAppjvxing)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C橡皮筋1View 构造/析构

C橡皮筋1View::C橡皮筋1View()
: jvxing(false)
, j1(false)
{
	// TODO:  在此处添加构造代码

}

C橡皮筋1View::~C橡皮筋1View()
{
}

BOOL C橡皮筋1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C橡皮筋1View 绘制

void C橡皮筋1View::OnDraw(CDC* /*pDC*/)
{
	C橡皮筋1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// C橡皮筋1View 打印

BOOL C橡皮筋1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C橡皮筋1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void C橡皮筋1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// C橡皮筋1View 诊断

#ifdef _DEBUG
void C橡皮筋1View::AssertValid() const
{
	CView::AssertValid();
}

void C橡皮筋1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C橡皮筋1Doc* C橡皮筋1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C橡皮筋1Doc)));
	return (C橡皮筋1Doc*)m_pDocument;
}
#endif //_DEBUG


// C橡皮筋1View 消息处理程序

CPoint fir;
CPoint sec;

void C橡皮筋1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (j1)
	{
		sec=fir = point;
		jvxing = true;
	};


	CView::OnLButtonDown(nFlags, point);
}


void C橡皮筋1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (j1)
	{
		jvxing = false;
		CDC*pDC = GetDC();
		//CPen P2(PS_SOLID, 1, RGB(0, 0, 0));
		//pDC->SelectObject(&P2);
		pDC->Rectangle(CRect(fir, point));
	}

	CView::OnLButtonUp(nFlags, point);
}


void C橡皮筋1View::OnAppjvxing()
{
	// TODO:  在此添加命令处理程序代码
	j1 = true; 
}


void C橡皮筋1View::OnUpdateAppjvxing(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
}


void C橡皮筋1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if(jvxing)
	{
		CDC*pDC = GetDC();
		CPen P1(PS_SOLID, 1, RGB(255, 255, 255));
		pDC->SelectObject(&P1);
		pDC->Rectangle(CRect(fir, sec));

		pDC = GetDC();
		//CPen P2(PS_SOLID, 1, RGB(0, 0, 0));
		//pDC->SelectObject(&P2);
		pDC->Rectangle(CRect(fir, point));
		sec = point;
	}

	CView::OnMouseMove(nFlags, point);
}
