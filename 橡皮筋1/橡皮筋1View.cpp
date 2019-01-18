
// ��Ƥ��1View.cpp : C��Ƥ��1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��Ƥ��1.h"
#endif

#include "��Ƥ��1Doc.h"
#include "��Ƥ��1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��Ƥ��1View

IMPLEMENT_DYNCREATE(C��Ƥ��1View, CView)

BEGIN_MESSAGE_MAP(C��Ƥ��1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_APP_jvxing, &C��Ƥ��1View::OnAppjvxing)
	ON_UPDATE_COMMAND_UI(ID_APP_jvxing, &C��Ƥ��1View::OnUpdateAppjvxing)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C��Ƥ��1View ����/����

C��Ƥ��1View::C��Ƥ��1View()
: jvxing(false)
, j1(false)
{
	// TODO:  �ڴ˴���ӹ������

}

C��Ƥ��1View::~C��Ƥ��1View()
{
}

BOOL C��Ƥ��1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��Ƥ��1View ����

void C��Ƥ��1View::OnDraw(CDC* /*pDC*/)
{
	C��Ƥ��1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��Ƥ��1View ��ӡ

BOOL C��Ƥ��1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��Ƥ��1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��Ƥ��1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// C��Ƥ��1View ���

#ifdef _DEBUG
void C��Ƥ��1View::AssertValid() const
{
	CView::AssertValid();
}

void C��Ƥ��1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��Ƥ��1Doc* C��Ƥ��1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��Ƥ��1Doc)));
	return (C��Ƥ��1Doc*)m_pDocument;
}
#endif //_DEBUG


// C��Ƥ��1View ��Ϣ�������

CPoint fir;
CPoint sec;

void C��Ƥ��1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (j1)
	{
		sec=fir = point;
		jvxing = true;
	};


	CView::OnLButtonDown(nFlags, point);
}


void C��Ƥ��1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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


void C��Ƥ��1View::OnAppjvxing()
{
	// TODO:  �ڴ���������������
	j1 = true; 
}


void C��Ƥ��1View::OnUpdateAppjvxing(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
}


void C��Ƥ��1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
