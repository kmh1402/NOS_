// NOS.h : NOS ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CNOSApp:
// �� Ŭ������ ������ ���ؼ��� NOS.cpp�� �����Ͻʽÿ�.
//

class CNOSApp : public CWinApp
{
public:
	CNOSApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CNOSApp theApp;