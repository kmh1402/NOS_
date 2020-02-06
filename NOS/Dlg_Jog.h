#pragma once
#include "btnenh.h"

// CDlg_Jog 대화 상자입니다.

class CDlg_Jog : public CDialog
{
	DECLARE_DYNAMIC(CDlg_Jog)

public:
	CBtnEnh m_Jog_High;
	CBtnEnh m_Jog_Mid;
	CBtnEnh m_Jog_Low;
	CDlg_Jog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_Jog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_JOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	DECLARE_EVENTSINK_MAP()
	void MouseDownMessage128(short Button, short Shift, long x, long y);
	void MouseUpMessage128(short Button, short Shift, long x, long y);
	void MouseDownMessage50(short Button, short Shift, long x, long y);
	void MouseUpMessage50(short Button, short Shift, long x, long y);
	void MouseDownJogYUp5(short Button, short Shift, long x, long y);
	void MouseUpJogYUp5(short Button, short Shift, long x, long y);
	void MouseDownJogDown5(short Button, short Shift, long x, long y);
	void MouseUpJogDown5(short Button, short Shift, long x, long y);
	void MouseDownJogZUp(short Button, short Shift, long x, long y);
	void MouseUpJogZUp(short Button, short Shift, long x, long y);
	void MouseDownJogZDown(short Button, short Shift, long x, long y);
	void MouseUpJogZDown(short Button, short Shift, long x, long y);
	
	void ClickJogLow();
	void ClickJogMid();
	void ClickJogHigh();
	void ClickOkBtn();
	void GetMotionStatus();
protected:
	virtual void PostNcDestroy();
public:
	virtual BOOL DestroyWindow();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
