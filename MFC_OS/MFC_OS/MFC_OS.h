
// MFC_OS.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_OSApp:
// �йش����ʵ�֣������ MFC_OS.cpp
//

struct MyStruct
{
	CString ID;
	CString NAME;
};
class CMFC_OSApp : public CWinApp
{
public:
	CMFC_OSApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_OSApp theApp;
extern MyStruct str[100];
extern int  i;
extern CString Time[100];