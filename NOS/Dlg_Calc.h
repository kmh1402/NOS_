#pragma once
#include "btnenh.h"

// CDlg_Calc 대화 상자입니다.

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

	CDlg_Calc(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_Calc();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_CALC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
