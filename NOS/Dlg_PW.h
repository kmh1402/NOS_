#pragma once
#include "btnenh.h"

// CDlg_PW 대화 상자입니다.

class CDlg_PW : public CDialog
{
	DECLARE_DYNAMIC(CDlg_PW)

public:
	CString	m_OldPW;
	CString	m_NewPW;
	int m_nOldCnt;
	int m_nNewCnt;
	bool m_bSelPW;
	CBtnEnh m_Sel_OldPW;
	CBtnEnh m_Sel_NewPW;
	CString m_csOld;
	CString m_csNew;
	void DataSave();

	CDlg_PW(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_PW();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_PW };

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
	void ClickSelOldpw();
	void ClickSelNewPw();
	void ClickOkBtn();
	void ClickExitBtn2();
};
