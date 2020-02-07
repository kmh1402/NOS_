#pragma once
#include "btnenh.h"
#include "afxwin.h"

// CDlg_Motion 대화 상자입니다.

class CDlg_Motion : public CDialog
{
	DECLARE_DYNAMIC(CDlg_Motion)

public:
	CBtnEnh m_X_Elm;
	CBtnEnh m_Y_Elm;
	CBtnEnh m_Z_Elm;
	CBtnEnh m_X_Elp;
	CBtnEnh m_Y_Elp;
	CBtnEnh m_Z_Elp;
	CBtnEnh m_X_Org;
	CBtnEnh m_Y_Org;
	CBtnEnh m_Z_Org;
	CBtnEnh m_X_Alarm;
	CBtnEnh m_Y_Alarm;


	int m_nOldElM_X1;
	int m_nOldElP_X1;
	int m_nOldORG_X1;
	int m_nOldARM_X1;
	
	int m_nOldElM_Y1;
	int m_nOldElP_Y1;
	int m_nOldORG_Y1;
	int m_nOldARM_Y1;

	int m_nOldElM_Z1;
	int m_nOldElP_Z1;
	int m_nOldORG_Z1;

	CString CalcCall(CString BeforData);
	void GetMotionStatus();
	void Display();
	void DataSave();

	CDlg_Motion(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_Motion();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_MOTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EVENTSINK_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	
protected:
	virtual void PostNcDestroy();
public:
	virtual BOOL DestroyWindow();
// 	void DblClickXMovepos();
// 	void DblClickYMovepos();
// 	void DblClickZMovepos();
	void ClickOkBtn();
	void MouseUpJogRight(short Button, short Shift, long x, long y);
	void ClickJogLow();
	void ClickJogMid();
	void ClickJogHigh();
	CBtnEnh m_Jog_Low;
	CBtnEnh m_Jog_Mid;
	CBtnEnh m_Jog_High;
	CBtnEnh m_X_FeedBack;
	CBtnEnh m_Y_FeedBack;
	CBtnEnh m_Z_FeedBack;
	CBtnEnh m_X_Move_Speed;
	CBtnEnh m_X_AccDec;
	CBtnEnh m_X_Home_Speed;
	CBtnEnh m_X_Jog_Speed;
	CBtnEnh m_Y_Move_Speed;
	CBtnEnh m_Y_AccDec;
	CBtnEnh m_Y_Home_Speed;
	CBtnEnh m_Y_Jog_Speed;
	CBtnEnh m_Z_FH;
	CBtnEnh m_Z_Acc;
	CBtnEnh m_Z_Home_Speed;
	CBtnEnh m_Z_Jog_Speed;
	CBtnEnh m_X_Move_Speed2;
	CBtnEnh m_X_AccDec2;
	CBtnEnh m_Y_Move_Speed2;
	CBtnEnh m_Y_AccDec2;
	void ClickSaveBtn();
	void DblClickXMoveSpeed2();
	void DblClickXAccdec2();
	void DblClickYMoveSpeed2();
	void DblClickYAccdec2();

	void DblClickXMoveSpeed();
	void DblClickXAccdec();
	void DblClickXHomeSpeed();
	void DblClickXJogSpeed();

	void DblClickYMoveSpeed();
	void DblClickYAccdec();
	void DblClickYHomeSpeed();
	void DblClickYJogSpeed();

	void DblClickZMoveSpeed();
	void DblClickZAccdec();
	void DblClickZHomeSpeed();
	void DblClickZJogSpeed();
	
};
