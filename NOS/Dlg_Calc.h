#pragma once
#include "btnenh.h"

// CDlg_Calc ��ȭ �����Դϴ�.

class CDlg_Calc : public CDialog
{
	DECLARE_DYNAMIC(CDlg_Calc)

public:
	CString m_NewValue;
	CString	m_OldValue;
	bool bNewValueIn;
	bool bNewValueFlag;
	int iCalVal;
	double dOldCalData;

	CDlg_Calc(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_Calc();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_CALC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EVENTSINK_MAP()
	void ClickNum1();
	void ClickNum2();
	void ClickNum3();
	void ClickNum4();
	void ClickNum5();
	void ClickNum6();
	void ClickNum7();
	void ClickNum8();
	void ClickNum9();
	void ClickNum10();
	void ClickDotBtn();
	void ClickBuhoBtn();
	void ClickBackSpace();
	void ClickPlusBtn();
	void ClickClearBtn();
	void ClickSubBtn();
	void ClickDivBtn();
	void ClickMulBtn();
	void ClickEqualBtn();
	void ClickOkBtn();
	void ClickCancelBtn();
	int LimitNum();
	
	CBtnEnh	m_New_Value;
	CBtnEnh	m_Old_Value;
	virtual BOOL OnInitDialog();
};
