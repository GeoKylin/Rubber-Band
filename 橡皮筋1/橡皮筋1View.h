
// ��Ƥ��1View.h : C��Ƥ��1View ��Ľӿ�
//

#pragma once


class C��Ƥ��1View : public CView
{
protected: // �������л�����
	C��Ƥ��1View();
	DECLARE_DYNCREATE(C��Ƥ��1View)

// ����
public:
	C��Ƥ��1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C��Ƥ��1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnAppjvxing();
	afx_msg void OnUpdateAppjvxing(CCmdUI *pCmdUI);
	bool jvxing;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	bool j1;
};

#ifndef _DEBUG  // ��Ƥ��1View.cpp �еĵ��԰汾
inline C��Ƥ��1Doc* C��Ƥ��1View::GetDocument() const
   { return reinterpret_cast<C��Ƥ��1Doc*>(m_pDocument); }
#endif

