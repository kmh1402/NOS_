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
	
	void MouseDownJogYUp(short Button, short Shift, long x, long y);
	void MouseUpJogYUp(short Button, short Shift, long x, long y);
	void MouseDownJogLeft(short Button, short Shift, long x, long y);
	void MouseUpJogLeft(short Button, short Shift, long x, long y);
	void MouseDownJogDown(short Button, short Shift, long x, long y);
	void MouseUpJogDown(short Button, short Shift, long x, long y);
	void MouseDownJogRight(short Button, short Shift, long x, long y);
	void MouseDownJogZUp(short Button, short Shift, long x, long y);
	void MouseUpJogZUp(short Button, short Shift, long x, long y);
	void DblClickRdyX();
	void DblClickRdyY();
	void DblClickRdyZ();
	void ClickRdyXMove();
	void ClickRdyYMove();
	void ClickRdyZMove();
	CBtnEnh m_Rdy_X;
	CBtnEnh m_Rdy_Y;
	CBtnEnh m_Rdy_Z;
	void DblClickPosZDw();
	CBtnEnh m_Pos_Z_DW;
	void ClickPosZDwMove();
	void ClickRdyXSet();
	void ClickRdyYSet();
	void ClickRdyZSet();
	void ClickPosZDwSet();
	void DblClickXPos1();
	void DblClickYPos1();
	void DblClickPosZUp();
//	void ClickXPos2();
	void DblClickXPos2();
	void DblClickYPos2();
	void DblClickPosZUp2();
	void DblClickXPos3();
	void DblClickYPos3();
	void DblClickPosZUp3();
	void DblClickXPos4();
	void DblClickYPos4();
	void DblClickPosZUp4();
	void DblClickInterZ();
	CBtnEnh m_X_Pos1;
	CBtnEnh m_Y_Pos1;
	CBtnEnh m_Pos_Z_UP;
	CBtnEnh m_X_Pos2;
	CBtnEnh m_Y_Pos2;
	CBtnEnh m_Pos_Z_UP2;
	CBtnEnh m_X_Pos3;
	CBtnEnh m_Y_Pos3;
	CBtnEnh m_Pos_Z_UP3;
	CBtnEnh m_X_Pos4;
	CBtnEnh m_Y_Pos4;
	CBtnEnh m_Pos_Z_UP4;
	void ClickXPos1Move();
	void ClickYPos1Move();
	void ClickPosZMove();
	void ClickXPos2Move();
	void ClickYPos2Move();
	void ClickPosZMove2();
	void ClickXPos3Move();
	void ClickYPos3Move();
	void ClickPosZMove3();
	void ClickXPos4Move();
	void ClickYPos4Move();
	void ClickPosZMove4();
	void ClickPosZDwMove2();
	CBtnEnh m_Inter_Z;
	void ClickXPos1Set();
	void ClickYPos1Set();
	void ClickPosZUpSet();
	void ClickXPos2Set();
	void ClickYPos2Set();
	void ClickPosZUpSet2();
	void ClickXPos3Set();
	void ClickYPos3Set();
	void ClickPosZUpSet3();
	void ClickXPos4Set();
	void ClickYPos4Set();
	void ClickPosZUpSet4();
	void ClickPosZDwSet2();
	void DataLoadSetCaption();
	void DblClickXMovepos();
	void DblClickYMovepos();
	void DblClickZMovepos();
	CBtnEnh m_X_MovePos;
	CBtnEnh m_Y_MovePos;
	CBtnEnh m_Z_MovePos;
	void ClickXMove();
	void ClickYMove();
	void ClickZMove();
};
