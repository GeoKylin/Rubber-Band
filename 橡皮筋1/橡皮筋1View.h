
// 橡皮筋1View.h : C橡皮筋1View 类的接口
//

#pragma once


class C橡皮筋1View : public CView
{
protected: // 仅从序列化创建
	C橡皮筋1View();
	DECLARE_DYNCREATE(C橡皮筋1View)

// 特性
public:
	C橡皮筋1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C橡皮筋1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // 橡皮筋1View.cpp 中的调试版本
inline C橡皮筋1Doc* C橡皮筋1View::GetDocument() const
   { return reinterpret_cast<C橡皮筋1Doc*>(m_pDocument); }
#endif

