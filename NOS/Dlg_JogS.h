#pragma once
#include "btnenh.h"

// CDlg_JogS 대화 상자입니다.

class CDlg_JogS : public CDialog
{
	DECLARE_DYNAMIC(CDlg_JogS)

public:
	CBtnEnh m_Jog_Dist;
	CBtnEnh m_Dist_50;
	CBtnEnh m_Dist_100;
	CBtnEnh m_Dist_500;
	CBtnEnh m_Dist_1000;
	CBtnEnh m_Dist_5000;
	CBtnEnh m_Dist_10000;
	CDlg_JogS(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_JogS();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_JOGS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void PostNcDestroy();
public:
	virtual BOOL DestroyWindow();
	DECLARE_EVENTSINK_MAP()
	void ClickJogMoveLeft();
	void ClickJogMoveRight();
	void ClickJogYUp5();
	void ClickJogYDown();
	void ClickJogZUp();
	void ClickJogZDown();
	void ClickDist50();
	void ClickDist100();
	void ClickDist500();
	void ClickDist1000();
	void ClickDist5000();
	void ClickDist10000();
	void DblClickCamX();
	void ClickOkBtn();
	void Display();
	CString CalcCall(CString BeforData);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
