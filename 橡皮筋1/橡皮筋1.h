
// ��Ƥ��1.h : ��Ƥ��1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��Ƥ��1App:
// �йش����ʵ�֣������ ��Ƥ��1.cpp
//

class C��Ƥ��1App : public CWinApp
{
public:
	C��Ƥ��1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��Ƥ��1App theApp;
