#pragma once
#include "btnenh.h"

// CDlg_LogIN ��ȭ �����Դϴ�.

class CDlg_LogIN : public CDialog
{
	DECLARE_DYNAMIC(CDlg_LogIN)

public:
	CString	m_EdtPW;
	CString m_csPW;
	CListBox m_List;
	int m_nCnt;
	CDlg_LogIN(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_LogIN();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	DECLARE_EVENTSINK_MAP()
	void ClickPw1();
	void ClickPw2();
	void ClickPw3();
	void ClickPw4();
	void ClickPw5();
	void ClickPw6();
	void ClickPw7();
	void ClickPw8();
	void ClickPw9();
	void ClickPw0();
	void ClickPwChange();
	void ClickOkBtn();
	
};
