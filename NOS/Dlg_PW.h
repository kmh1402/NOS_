#pragma once
#include "btnenh.h"

// CDlg_PW ��ȭ �����Դϴ�.

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

	CDlg_PW(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_PW();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_PW };

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
	void ClickSelOldpw();
	void ClickSelNewPw();
	void ClickOkBtn();
	void ClickExitBtn2();
};
