#pragma once
#include "btnenh.h"

// CDlg_LogIN 대화 상자입니다.

class CDlg_LogIN : public CDialog
{
	DECLARE_DYNAMIC(CDlg_LogIN)

public:
	CString	m_EdtPW;
	CString m_csPW;
	CListBox m_List;
	int m_nCnt;
	CDlg_LogIN(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_LogIN();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
