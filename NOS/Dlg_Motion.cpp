// Dlg_Motion.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_Motion.h"
#include "Dlg_Calc.h"
#include "pmiMApi.h"
#include "pmiMApiDefs.h"
#include "VarEx.h"
#include "FuncEx.h"


// CDlg_Motion 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_Motion, CDialog)

CDlg_Motion::CDlg_Motion(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Motion::IDD, pParent)
{

}

CDlg_Motion::~CDlg_Motion()
{
}

void CDlg_Motion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_X_ELM, m_X_Elm);
	DDX_Control(pDX, IDC_Y_ELM, m_Y_Elm);
	DDX_Control(pDX, IDC_Z_ELM, m_Z_Elm);
	DDX_Control(pDX, IDC_X_ELP, m_X_Elp);
	DDX_Control(pDX, IDC_Y_ELP, m_Y_Elp);
	DDX_Control(pDX, IDC_Z_ELP, m_Z_Elp);
	DDX_Control(pDX, IDC_X_ORG, m_X_Org);
	DDX_Control(pDX, IDC_Y_ORG, m_Y_Org);
	DDX_Control(pDX, IDC_Z_ORG, m_Z_Org);
	DDX_Control(pDX, IDC_X_ALARM, m_X_Alarm);
	DDX_Control(pDX, IDC_Y_ALARM, m_Y_Alarm);

	DDX_Control(pDX, IDC_JOG_LOW, m_Jog_Low);
	DDX_Control(pDX, IDC_JOG_MID, m_Jog_Mid);
	DDX_Control(pDX, IDC_JOG_HIGH, m_Jog_High);


	DDX_Control(pDX, IDC_X_FEEDBACK, m_X_FeedBack);
	DDX_Control(pDX, IDC_Y_FEEDBACK, m_Y_FeedBack);
	DDX_Control(pDX, IDC_Z_FEEDBACK, m_Z_FeedBack);
	DDX_Control(pDX, IDC_X_MOVE_SPEED, m_X_Move_Speed);
	DDX_Control(pDX, IDC_X_ACCDEC, m_X_AccDec);
	DDX_Control(pDX, IDC_X_HOME_SPEED, m_X_Home_Speed);
	DDX_Control(pDX, IDC_X_JOG_SPEED, m_X_Jog_Speed);
	DDX_Control(pDX, IDC_Y_MOVE_SPEED, m_Y_Move_Speed);
	DDX_Control(pDX, IDC_Y_ACCDEC, m_Y_AccDec);
	DDX_Control(pDX, IDC_Y_HOME_SPEED, m_Y_Home_Speed);
	DDX_Control(pDX, IDC_Y_JOG_SPEED, m_Y_Jog_Speed);
	DDX_Control(pDX, IDC_Z_MOVE_SPEED, m_Z_FH);
	DDX_Control(pDX, IDC_Z_ACCDEC, m_Z_Acc);
	DDX_Control(pDX, IDC_Z_HOME_SPEED, m_Z_Home_Speed);
	DDX_Control(pDX, IDC_Z_JOG_SPEED, m_Z_Jog_Speed);

	DDX_Control(pDX, IDC_X_MOVE_SPEED2, m_X_Move_Speed2);
	DDX_Control(pDX, IDC_X_ACCDEC2, m_X_AccDec2);
	DDX_Control(pDX, IDC_Y_MOVE_SPEED2, m_Y_Move_Speed2);
	DDX_Control(pDX, IDC_Y_ACCDEC2, m_Y_AccDec2);
	DDX_Control(pDX, IDC_RDY_X, m_Rdy_X);
	DDX_Control(pDX, IDC_RDY_Y, m_Rdy_Y);
	DDX_Control(pDX, IDC_RDY_Z, m_Rdy_Z);
	DDX_Control(pDX, IDC_POS_Z_DW, m_Pos_Z_DW);
	DDX_Control(pDX, IDC_X_POS1, m_X_Pos1);
	DDX_Control(pDX, IDC_Y_POS1, m_Y_Pos1);
	DDX_Control(pDX, IDC_POS_Z_UP, m_Pos_Z_UP);
	DDX_Control(pDX, IDC_X_POS2, m_X_Pos2);
	DDX_Control(pDX, IDC_Y_POS2, m_Y_Pos2);
	DDX_Control(pDX, IDC_POS_Z_UP2, m_Pos_Z_UP2);
	DDX_Control(pDX, IDC_X_POS3, m_X_Pos3);
	DDX_Control(pDX, IDC_Y_POS3, m_Y_Pos3);
	DDX_Control(pDX, IDC_POS_Z_UP3, m_Pos_Z_UP3);
	DDX_Control(pDX, IDC_X_POS4, m_X_Pos4);
	DDX_Control(pDX, IDC_Y_POS4, m_Y_Pos4);
	DDX_Control(pDX, IDC_POS_Z_UP4, m_Pos_Z_UP4);
	DDX_Control(pDX, IDC_INTER_Z, m_Inter_Z);
	DDX_Control(pDX, IDC_X_MOVEPOS, m_X_MovePos);
	DDX_Control(pDX, IDC_Y_MOVEPOS, m_Y_MovePos);
	DDX_Control(pDX, IDC_Z_MOVEPOS, m_Z_MovePos);
}


BEGIN_MESSAGE_MAP(CDlg_Motion, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlg_Motion 메시지 처리기입니다.
BEGIN_EVENTSINK_MAP(CDlg_Motion, CDialog)
// 	ON_EVENT(CDlg_Motion, IDC_X_MOVEPOS, DISPID_DBLCLICK, CDlg_Motion::DblClickXMovepos, VTS_NONE)
// 	ON_EVENT(CDlg_Motion, IDC_Y_MOVEPOS, DISPID_DBLCLICK, CDlg_Motion::DblClickYMovepos, VTS_NONE)
// 	ON_EVENT(CDlg_Motion, IDC_Z_MOVEPOS, DISPID_DBLCLICK, CDlg_Motion::DblClickZMovepos, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_OK_BTN, DISPID_CLICK, CDlg_Motion::ClickOkBtn, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_JOG_RIGHT, DISPID_MOUSEUP, CDlg_Motion::MouseUpJogRight, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Motion, IDC_JOG_LOW, DISPID_CLICK, CDlg_Motion::ClickJogLow, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_JOG_MID, DISPID_CLICK, CDlg_Motion::ClickJogMid, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_JOG_HIGH, DISPID_CLICK, CDlg_Motion::ClickJogHigh, VTS_NONE)
	
	ON_EVENT(CDlg_Motion, IDC_X_MOVE_SPEED, DISPID_DBLCLICK, CDlg_Motion::DblClickXMoveSpeed, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_ACCDEC, DISPID_DBLCLICK, CDlg_Motion::DblClickXAccdec, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_HOME_SPEED, DISPID_DBLCLICK, CDlg_Motion::DblClickXHomeSpeed, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_JOG_SPEED, DISPID_DBLCLICK, CDlg_Motion::DblClickXJogSpeed, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_MOVE_SPEED, DISPID_DBLCLICK, CDlg_Motion::DblClickYMoveSpeed, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_ACCDEC, DISPID_DBLCLICK, CDlg_Motion::DblClickYAccdec, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_HOME_SPEED, DISPID_DBLCLICK, CDlg_Motion::DblClickYHomeSpeed, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_JOG_SPEED, DISPID_DBLCLICK, CDlg_Motion::DblClickYJogSpeed, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_SAVE_BTN, DISPID_CLICK, CDlg_Motion::ClickSaveBtn, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Z_MOVE_SPEED, DISPID_DBLCLICK, CDlg_Motion::DblClickZMoveSpeed, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Z_ACCDEC, DISPID_DBLCLICK, CDlg_Motion::DblClickZAccdec, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_MOVE_SPEED2, DISPID_DBLCLICK, CDlg_Motion::DblClickXMoveSpeed2, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_ACCDEC2, DISPID_DBLCLICK, CDlg_Motion::DblClickXAccdec2, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_MOVE_SPEED2, DISPID_DBLCLICK, CDlg_Motion::DblClickYMoveSpeed2, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_ACCDEC2, DISPID_DBLCLICK, CDlg_Motion::DblClickYAccdec2, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Z_HOME_SPEED, DISPID_DBLCLICK, CDlg_Motion::DblClickZHomeSpeed, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Z_JOG_SPEED, DISPID_DBLCLICK, CDlg_Motion::DblClickZJogSpeed, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_JOG_Y_UP, DISPID_MOUSEDOWN, CDlg_Motion::MouseDownJogYUp, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Motion, IDC_JOG_Y_UP, DISPID_MOUSEUP, CDlg_Motion::MouseUpJogYUp, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Motion, IDC_JOG_LEFT, DISPID_MOUSEDOWN, CDlg_Motion::MouseDownJogLeft, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Motion, IDC_JOG_LEFT, DISPID_MOUSEUP, CDlg_Motion::MouseUpJogLeft, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Motion, IDC_JOG_DOWN, DISPID_MOUSEDOWN, CDlg_Motion::MouseDownJogDown, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Motion, IDC_JOG_DOWN, DISPID_MOUSEUP, CDlg_Motion::MouseUpJogDown, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Motion, IDC_JOG_RIGHT, DISPID_MOUSEDOWN, CDlg_Motion::MouseDownJogRight, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Motion, IDC_JOG_Z_UP, DISPID_MOUSEDOWN, CDlg_Motion::MouseDownJogZUp, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Motion, IDC_JOG_Z_UP, DISPID_MOUSEUP, CDlg_Motion::MouseUpJogZUp, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Motion, IDC_RDY_X, DISPID_DBLCLICK, CDlg_Motion::DblClickRdyX, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_RDY_Y, DISPID_DBLCLICK, CDlg_Motion::DblClickRdyY, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_RDY_Z, DISPID_DBLCLICK, CDlg_Motion::DblClickRdyZ, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_RDY_X_MOVE, DISPID_CLICK, CDlg_Motion::ClickRdyXMove, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_RDY_Y_MOVE, DISPID_CLICK, CDlg_Motion::ClickRdyYMove, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_RDY_Z_MOVE, DISPID_CLICK, CDlg_Motion::ClickRdyZMove, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_DW, DISPID_DBLCLICK, CDlg_Motion::DblClickPosZDw, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_DW_MOVE, DISPID_CLICK, CDlg_Motion::ClickPosZDwMove, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_RDY_X_SET, DISPID_CLICK, CDlg_Motion::ClickRdyXSet, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_RDY_Y_SET, DISPID_CLICK, CDlg_Motion::ClickRdyYSet, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_RDY_Z_SET, DISPID_CLICK, CDlg_Motion::ClickRdyZSet, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_DW_SET, DISPID_CLICK, CDlg_Motion::ClickPosZDwSet, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS1, DISPID_DBLCLICK, CDlg_Motion::DblClickXPos1, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS1, DISPID_DBLCLICK, CDlg_Motion::DblClickYPos1, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_UP, DISPID_DBLCLICK, CDlg_Motion::DblClickPosZUp, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS2, DISPID_DBLCLICK, CDlg_Motion::DblClickXPos2, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS2, DISPID_DBLCLICK, CDlg_Motion::DblClickYPos2, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_UP2, DISPID_DBLCLICK, CDlg_Motion::DblClickPosZUp2, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS3, DISPID_DBLCLICK, CDlg_Motion::DblClickXPos3, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS3, DISPID_DBLCLICK, CDlg_Motion::DblClickYPos3, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_UP3, DISPID_DBLCLICK, CDlg_Motion::DblClickPosZUp3, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS4, DISPID_DBLCLICK, CDlg_Motion::DblClickXPos4, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS4, DISPID_DBLCLICK, CDlg_Motion::DblClickYPos4, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_UP4, DISPID_DBLCLICK, CDlg_Motion::DblClickPosZUp4, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_INTER_Z, DISPID_DBLCLICK, CDlg_Motion::DblClickInterZ, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS1_MOVE, DISPID_CLICK, CDlg_Motion::ClickXPos1Move, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS1_MOVE, DISPID_CLICK, CDlg_Motion::ClickYPos1Move, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_MOVE, DISPID_CLICK, CDlg_Motion::ClickPosZMove, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS2_MOVE, DISPID_CLICK, CDlg_Motion::ClickXPos2Move, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS2_MOVE, DISPID_CLICK, CDlg_Motion::ClickYPos2Move, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_MOVE2, DISPID_CLICK, CDlg_Motion::ClickPosZMove2, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS3_MOVE, DISPID_CLICK, CDlg_Motion::ClickXPos3Move, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS3_MOVE, DISPID_CLICK, CDlg_Motion::ClickYPos3Move, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_MOVE3, DISPID_CLICK, CDlg_Motion::ClickPosZMove3, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS4_MOVE, DISPID_CLICK, CDlg_Motion::ClickXPos4Move, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS4_MOVE, DISPID_CLICK, CDlg_Motion::ClickYPos4Move, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_MOVE4, DISPID_CLICK, CDlg_Motion::ClickPosZMove4, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_DW_MOVE2, DISPID_CLICK, CDlg_Motion::ClickPosZDwMove2, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS1_SET, DISPID_CLICK, CDlg_Motion::ClickXPos1Set, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS1_SET, DISPID_CLICK, CDlg_Motion::ClickYPos1Set, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_UP_SET, DISPID_CLICK, CDlg_Motion::ClickPosZUpSet, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS2_SET, DISPID_CLICK, CDlg_Motion::ClickXPos2Set, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS2_SET, DISPID_CLICK, CDlg_Motion::ClickYPos2Set, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_UP_SET2, DISPID_CLICK, CDlg_Motion::ClickPosZUpSet2, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS3_SET, DISPID_CLICK, CDlg_Motion::ClickXPos3Set, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS3_SET, DISPID_CLICK, CDlg_Motion::ClickYPos3Set, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_UP_SET3, DISPID_CLICK, CDlg_Motion::ClickPosZUpSet3, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_POS4_SET, DISPID_CLICK, CDlg_Motion::ClickXPos4Set, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_POS4_SET, DISPID_CLICK, CDlg_Motion::ClickYPos4Set, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_UP_SET4, DISPID_CLICK, CDlg_Motion::ClickPosZUpSet4, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_POS_Z_DW_SET2, DISPID_CLICK, CDlg_Motion::ClickPosZDwSet2, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_MOVEPOS, DISPID_DBLCLICK, CDlg_Motion::DblClickXMovepos, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_MOVEPOS, DISPID_DBLCLICK, CDlg_Motion::DblClickYMovepos, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Z_MOVEPOS, DISPID_DBLCLICK, CDlg_Motion::DblClickZMovepos, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_X_MOVE, DISPID_CLICK, CDlg_Motion::ClickXMove, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Y_MOVE, DISPID_CLICK, CDlg_Motion::ClickYMove, VTS_NONE)
	ON_EVENT(CDlg_Motion, IDC_Z_MOVE, DISPID_CLICK, CDlg_Motion::ClickZMove, VTS_NONE)
END_EVENTSINK_MAP()

void CDlg_Motion::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent == 1)
	{
		GetMotionStatus();
	}
	if(nIDEvent == 2)
	{
		Display();
	}
	CDialog::OnTimer(nIDEvent);
}

void CDlg_Motion::GetMotionStatus()
{

	union {
		unsigned int mem;

		struct {
			USHORT EMG:1;
			USHORT ALM:1;
			USHORT P_LMT:1;
			USHORT N_LMT:1;
			USHORT ORG:1;
			USHORT DIR:1;
			USHORT H_OK:1;
			USHORT PCS:1;
			USHORT CRC:1;
			USHORT EZ:1;
			USHORT CLR:1;
			USHORT LAT:1;
			USHORT SD:1;
			USHORT INP:1;
			USHORT SON:1;
			USHORT RST:1;
			USHORT STA:1;
		}mem_bit;
	}udtCardStatus, udtOldCardStatus;
	udtCardStatus.mem = 0;
	udtOldCardStatus.mem = 0;


	unsigned int bELPState;
	unsigned int bELMState;
	unsigned int bAMPState;
	unsigned int bORGState;
	unsigned int bINPState;
	CString csData;
	double dPos;

	pmiAxGetMechanical( 0, M_X1, &udtCardStatus.mem);
	bELPState = udtCardStatus.mem_bit.P_LMT;
	bELMState = udtCardStatus.mem_bit.N_LMT;
	bAMPState = udtCardStatus.mem_bit.ALM;
	bORGState = udtCardStatus.mem_bit.ORG;
	bINPState = udtCardStatus.mem_bit.INP;

	if(m_nOldElP_X1 != bELPState)
	{
		m_nOldElP_X1 = bELPState;
		if(bELPState)
		{
			m_X_Elp.SetBackColor(RGB(128,255,0));
		}
		else
		{
			m_X_Elp.SetBackColor(RGB(200,200,200));
		}
	}

	if(m_nOldElM_X1 != bELMState)
	{
		m_nOldElM_X1 = bELMState;
		if(bELMState) 
		{
			m_X_Elm.SetBackColor(RGB(128,255,0));
		}  
		else
		{
			m_X_Elm.SetBackColor(RGB(200,200,200));
		}
	}
	
	if(m_nOldARM_X1 != bAMPState) 
	{
		m_nOldARM_X1 = bAMPState;
		if(bAMPState)
		{
			m_X_Alarm.SetBackColor(RGB(255,50,0));  
		}
		else
		{
			m_X_Alarm.SetBackColor(RGB(200,200,200));
		}
	}  

	if(m_nOldORG_X1 != bORGState) 
	{
		m_nOldORG_X1 = bORGState;
		if(bORGState)
		{
			m_X_Org.SetBackColor(RGB(255,50,0));  
		}
		else
		{
			m_X_Org.SetBackColor(RGB(200,200,200));
		}
	}  
	pmiAxGetActPos(0,M_X1, &dPos);
	csData.Format("%.f", dPos);
	m_X_FeedBack.SetCaption(csData);


	pmiAxGetMechanical(0,M_Y1, &udtCardStatus.mem);
	bELPState = udtCardStatus.mem_bit.P_LMT;
	bELMState = udtCardStatus.mem_bit.N_LMT;
	bAMPState = udtCardStatus.mem_bit.ALM;
	bORGState = udtCardStatus.mem_bit.ORG;
	bINPState = udtCardStatus.mem_bit.INP;
	
	if(m_nOldElP_Y1 != bELPState)
	{
		m_nOldElP_Y1 = bELPState;
		if(bELPState)
		{
			m_Y_Elp.SetBackColor(RGB(128,255,0));
		}
		else
		{
			m_Y_Elp.SetBackColor(RGB(200,200,200));
		}
	}

	if(m_nOldElM_Y1 != bELMState)
	{
		m_nOldElM_Y1 = bELMState;
		if(bELMState) 
		{
			m_Y_Elm.SetBackColor(RGB(128,255,0));
		}  
		else
		{
			m_Y_Elm.SetBackColor(RGB(200,200,200));
		}
	}
	
	if(m_nOldARM_Y1 != bAMPState) 
	{
		m_nOldARM_Y1 = bAMPState;
		if(bAMPState)
		{
			m_Y_Alarm.SetBackColor(RGB(255,50,0));  
		}
		else
		{
			m_Y_Alarm.SetBackColor(RGB(200,200,200));
		}
	}  

	if(m_nOldORG_Y1 != bORGState) 
	{
		m_nOldORG_Y1 = bORGState;
		if(bORGState)
		{
			m_Y_Org.SetBackColor(RGB(255,50,0));  
		}
		else
		{
			m_Y_Org.SetBackColor(RGB(200,200,200));
		}
	}  

	pmiAxGetActPos(0,M_Y1, &dPos);
	csData.Format("%.f", dPos);
	m_Y_FeedBack.SetCaption(csData);


	pmiAxGetMechanical(0,M_Z1, &udtCardStatus.mem);
	bELPState = udtCardStatus.mem_bit.P_LMT;
	bELMState = udtCardStatus.mem_bit.N_LMT;
	bAMPState = udtCardStatus.mem_bit.ALM;
	bORGState = udtCardStatus.mem_bit.ORG;
	bINPState = udtCardStatus.mem_bit.INP;
	
	if(m_nOldElP_Z1 != bELPState)
	{
		m_nOldElP_Z1 = bELPState;
		if(bELPState)
		{
			m_Z_Elp.SetBackColor(RGB(128,255,0));
		}
		else
		{
			m_Z_Elp.SetBackColor(RGB(200,200,200));
		}
	}

	if(m_nOldElM_Z1 != bELMState)
	{
		m_nOldElM_Z1 = bELMState;
		if(bELMState) 
		{
			m_Z_Elm.SetBackColor(RGB(128,255,0));
		}  
		else
		{
			m_Z_Elm.SetBackColor(RGB(200,200,200));
		}
	}
	
	
	if(m_nOldORG_Z1 != bORGState) 
	{
		m_nOldORG_Z1 = bORGState;
		if(bORGState)
		{
			m_Z_Org.SetBackColor(RGB(255,50,0));  
		}
		else
		{
			m_Z_Org.SetBackColor(RGB(200,200,200));
		}
	}  

	pmiAxGetActPos(0,M_Z1, &dPos);
	csData.Format("%.f", dPos);
	m_Z_FeedBack.SetCaption(csData);
}

void CDlg_Motion::Display()
{
	CString csData;
	if(gnJogSpeed == JOGLOW)
	{
		m_Jog_Low.SetBackColor(RGB(128,255,128));
		m_Jog_Mid.SetBackColor(RGB(192,255,192));
		m_Jog_High.SetBackColor(RGB(192,255,192));
	}
	else if(gnJogSpeed == JOGMID)
	{
		m_Jog_Low.SetBackColor(RGB(192,255,192));
		m_Jog_Mid.SetBackColor(RGB(128,255,128));
		m_Jog_High.SetBackColor(RGB(192,255,192));
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		m_Jog_Low.SetBackColor(RGB(192,255,192));
		m_Jog_Mid.SetBackColor(RGB(192,255,192));
		m_Jog_High.SetBackColor(RGB(128,255,128));
	}
}

void CDlg_Motion::DataSave()
{
	CString csFileName;
	CString csRet;
	CString csData;

	csFileName = GetRunDirectory();
	csFileName = csFileName + "\\Setting\\MotionData.dat" ;

	csData = m_X_Move_Speed.GetCaption();
	SpeedFH.lX1 = atol(csData) ;
	csRet.Format("%d",SpeedFH.lX1); 
	WritePrivateProfileString("SPEED", "X MOVE", csRet, csFileName);

	csData = m_X_AccDec.GetCaption();
	SpeedAcc.lX1 = atol(csData) ;
	csRet.Format("%d",SpeedAcc.lX1); 
	WritePrivateProfileString("SPEED", "X ACCDEC", csRet, csFileName);

	csData = m_X_Home_Speed.GetCaption();
	SpeedHome.lX1 = atol(csData) ;
	csRet.Format("%d",SpeedHome.lX1); 
	WritePrivateProfileString("SPEED", "X HOME", csRet, csFileName);

	csData = m_X_Jog_Speed.GetCaption();
	SpeedJog.lX1 = atol(csData) ;
	csRet.Format("%d",SpeedJog.lX1); 
	WritePrivateProfileString("SPEED", "X JOG", csRet, csFileName);

	csData = m_Y_Move_Speed.GetCaption();
	SpeedFH.lY1 = atol(csData) ;
	csRet.Format("%d",SpeedFH.lY1); 
	WritePrivateProfileString("SPEED", "Y MOVE", csRet, csFileName);

	csData = m_Y_AccDec.GetCaption();
	SpeedAcc.lY1 = atol(csData) ;
	csRet.Format("%d",SpeedAcc.lY1); 
	WritePrivateProfileString("SPEED", "Y ACCDEC", csRet, csFileName);

	csData = m_Y_Home_Speed.GetCaption();
	SpeedHome.lY1 = atol(csData) ;
	csRet.Format("%d",SpeedHome.lY1); 
	WritePrivateProfileString("SPEED", "Y HOME", csRet, csFileName);

	csData = m_Y_Jog_Speed.GetCaption();
	SpeedJog.lY1 = atol(csData) ;
	csRet.Format("%d",SpeedJog.lY1); 
	WritePrivateProfileString("SPEED", "Y JOG", csRet, csFileName);

	csData = m_Z_FH.GetCaption();
	SpeedFH.lZ1 = atol(csData) ;
	csRet.Format("%d",SpeedFH.lZ1); 
	WritePrivateProfileString("SPEED", "Z MOVE", csRet, csFileName);

	csData = m_Z_Acc.GetCaption();
	SpeedAcc.lZ1 = atol(csData) ;
	csRet.Format("%d",SpeedAcc.lZ1); 
	WritePrivateProfileString("SPEED", "Z ACC", csRet, csFileName);

	csData = m_Z_Home_Speed.GetCaption();
	SpeedHome.lZ1 = atol(csData) ;
	csRet.Format("%d",SpeedHome.lZ1); 
	WritePrivateProfileString("SPEED", "Z HOME", csRet, csFileName);

	csData = m_Z_Jog_Speed.GetCaption();
	SpeedJog.lZ1 = atol(csData) ;
	csRet.Format("%d",SpeedJog.lZ1); 
	WritePrivateProfileString("SPEED", "Z JOG", csRet, csFileName);	

	csData = m_X_Move_Speed2.GetCaption();
	SpeedFH.lX2 = atol(csData) ;
	csRet.Format("%d",SpeedFH.lX2); 
	WritePrivateProfileString("SPEED", "X MOVE2", csRet, csFileName);

	csData = m_X_AccDec2.GetCaption();
	SpeedAcc.lX2 = atol(csData) ;
	csRet.Format("%d",SpeedAcc.lX2); 
	WritePrivateProfileString("SPEED", "X ACCDEC2", csRet, csFileName);


	csData = m_Y_Move_Speed2.GetCaption();
	SpeedFH.lY2 = atol(csData) ;
	csRet.Format("%d",SpeedFH.lY2); 
	WritePrivateProfileString("SPEED", "Y MOVE2", csRet, csFileName);

	csData = m_Y_AccDec2.GetCaption();
	SpeedAcc.lY2 = atol(csData) ;
	csRet.Format("%d",SpeedAcc.lY2); 
	WritePrivateProfileString("SPEED", "Y ACCDEC2", csRet, csFileName);
	SpeedSetting();

	csData = m_Rdy_X.GetCaption();
	gTeach.lRdyX = atol(csData) ;
	csRet.Format("%d", gTeach.lRdyX); 
	WritePrivateProfileString("TEACH", "RDY X", csRet, csFileName);

	csData = m_Rdy_Y.GetCaption();
	gTeach.lRdyY = atol(csData) ;
	csRet.Format("%d", gTeach.lRdyY); 
	WritePrivateProfileString("TEACH", "RDY Y", csRet, csFileName);

	csData = m_Rdy_Z.GetCaption();
	gTeach.lRdyZ = atol(csData) ;
	csRet.Format("%d", gTeach.lRdyZ); 
	WritePrivateProfileString("TEACH", "RDY Z", csRet, csFileName);

	csData = m_Pos_Z_UP.GetCaption();
	gTeach.lUpPos = atol(csData) ;
	csRet.Format("%d", gTeach.lUpPos); 
	WritePrivateProfileString("TEACH", "UP POS Z", csRet, csFileName);

	csData = m_Pos_Z_UP2.GetCaption();
	gTeach.lUpPos2 = atol(csData) ;
	csRet.Format("%d", gTeach.lUpPos2); 
	WritePrivateProfileString("TEACH", "UP POS Z2", csRet, csFileName);

	csData = m_Pos_Z_UP3.GetCaption();
	gTeach.lUpPos3 = atol(csData) ;
	csRet.Format("%d", gTeach.lUpPos3); 
	WritePrivateProfileString("TEACH", "UP POS Z3", csRet, csFileName);

	csData = m_Pos_Z_UP4.GetCaption();
	gTeach.lUpPos4 = atol(csData) ;
	csRet.Format("%d", gTeach.lUpPos4); 
	WritePrivateProfileString("TEACH", "UP POS Z4", csRet, csFileName);

	csData = m_Pos_Z_DW.GetCaption();
	gTeach.lDownPos = atol(csData) ;
	csRet.Format("%d", gTeach.lDownPos); 
	WritePrivateProfileString("TEACH", "DOWN POS Z", csRet, csFileName);


	csData = m_X_Pos1.GetCaption();
	gTeach.lX1 = atol(csData) ;
	csRet.Format("%d", gTeach.lX1); 
	WritePrivateProfileString("TEACH", "POS X1", csRet, csFileName);

	csData = m_X_Pos2.GetCaption();
	gTeach.lX2 = atol(csData) ;
	csRet.Format("%d", gTeach.lX2); 
	WritePrivateProfileString("TEACH", "POS X2", csRet, csFileName);

	csData = m_X_Pos3.GetCaption();
	gTeach.lX3 = atol(csData) ;
	csRet.Format("%d", gTeach.lX3); 
	WritePrivateProfileString("TEACH", "POS X3", csRet, csFileName);

	csData = m_X_Pos4.GetCaption();
	gTeach.lX4 = atol(csData) ;
	csRet.Format("%d", gTeach.lX4); 
	WritePrivateProfileString("TEACH", "POS X4", csRet, csFileName);

	csData = m_Y_Pos1.GetCaption();
	gTeach.lY1 = atol(csData) ;
	csRet.Format("%d", gTeach.lY1); 
	WritePrivateProfileString("TEACH", "POS Y1", csRet, csFileName);

	csData = m_Y_Pos2.GetCaption();
	gTeach.lY2 = atol(csData) ;
	csRet.Format("%d", gTeach.lY2); 
	WritePrivateProfileString("TEACH", "POS Y2", csRet, csFileName);

	csData = m_Y_Pos3.GetCaption();
	gTeach.lY3 = atol(csData) ;
	csRet.Format("%d", gTeach.lY3); 
	WritePrivateProfileString("TEACH", "POS Y3", csRet, csFileName);

	csData = m_Y_Pos4.GetCaption();
	gTeach.lY4 = atol(csData) ;
	csRet.Format("%d", gTeach.lY4); 
	WritePrivateProfileString("TEACH", "POS Y4", csRet, csFileName);

	csData = m_Inter_Z.GetCaption();
	gTeach.lInterZ = atol(csData) ;
	csRet.Format("%d", gTeach.lInterZ); 
	WritePrivateProfileString("TEACH", "INTERLOCK Z", csRet, csFileName);
}

CString CDlg_Motion::CalcCall(CString BeforData)
{
	CDlg_Calc dlg ;
	//dlg.m_CalculateTitle=Message ;
	dlg.m_OldValue = BeforData ;
	if(BeforData=="0")  dlg.m_NewValue="" ;
	else                dlg.m_NewValue = BeforData ;
	if(dlg.DoModal()!=IDOK) return BeforData;

	return  dlg.m_NewValue ;   
}

BOOL CDlg_Motion::OnInitDialog()
{
	CDialog::OnInitDialog();
	gnJogSpeed = JOGLOW;	
	SetTimer(1,100,NULL);
	DataLoadSetCaption();
	return TRUE;  
}

void CDlg_Motion::DataLoadSetCaption()
{
	CString csData;
	char CData[20];

	_ltoa_s(gTeach.lRdyX, CData,10) ;
	m_Rdy_X.SetCaption(CData);

	_ltoa_s(gTeach.lRdyY, CData,10) ;
	m_Rdy_Y.SetCaption(CData);

	_ltoa_s(gTeach.lRdyZ, CData,10) ;
	m_Rdy_Z.SetCaption(CData);


	_ltoa_s(gTeach.lUpPos, CData,10) ;
	m_Pos_Z_UP.SetCaption(CData);

	_ltoa_s(gTeach.lUpPos2, CData,10) ;
	m_Pos_Z_UP2.SetCaption(CData);

	_ltoa_s(gTeach.lUpPos3, CData,10) ;
	m_Pos_Z_UP3.SetCaption(CData);

	_ltoa_s(gTeach.lUpPos4, CData,10) ;
	m_Pos_Z_UP4.SetCaption(CData);

	_ltoa_s(gTeach.lDownPos, CData,10) ;
	m_Pos_Z_DW.SetCaption(CData);

	_ltoa_s(gTeach.lX1, CData,10) ;
	m_X_Pos1.SetCaption(CData);

	_ltoa_s(gTeach.lX2, CData,10) ;
	m_X_Pos2.SetCaption(CData);

	_ltoa_s(gTeach.lX3, CData,10) ;
	m_X_Pos3.SetCaption(CData);

	_ltoa_s(gTeach.lX4, CData,10) ;
	m_X_Pos4.SetCaption(CData);

	_ltoa_s(gTeach.lY1, CData,10) ;
	m_Y_Pos1.SetCaption(CData);

	_ltoa_s(gTeach.lY2, CData,10) ;
	m_Y_Pos2.SetCaption(CData);

	_ltoa_s(gTeach.lY3, CData,10) ;
	m_Y_Pos3.SetCaption(CData);

	_ltoa_s(gTeach.lY4, CData,10) ;
	m_Y_Pos4.SetCaption(CData);

	_ltoa_s(gTeach.lInterZ, CData,10) ;
	m_Inter_Z.SetCaption(CData);

	_ltoa_s(SpeedFH.lX1, CData,10) ;
	m_X_Move_Speed.SetCaption(CData);

	_ltoa_s(SpeedAcc.lX1, CData,10) ;
	m_X_AccDec.SetCaption(CData);

	_ltoa_s(SpeedHome.lX1, CData,10) ;
	m_X_Home_Speed.SetCaption(CData);

	_ltoa_s(SpeedJog.lX1, CData,10) ;
	m_X_Jog_Speed.SetCaption(CData);


	_ltoa_s(SpeedFH.lY1, CData,10) ;
	m_Y_Move_Speed.SetCaption(CData);

	_ltoa_s(SpeedAcc.lY1, CData,10) ;
	m_Y_AccDec.SetCaption(CData);

	_ltoa_s(SpeedHome.lY1, CData,10) ;
	m_Y_Home_Speed.SetCaption(CData);

	_ltoa_s(SpeedJog.lY1, CData,10) ;
	m_Y_Jog_Speed.SetCaption(CData);

	_ltoa_s(SpeedFH.lX2, CData,10) ;
	m_X_Move_Speed2.SetCaption(CData);

	_ltoa_s(SpeedAcc.lX2, CData,10) ;
	m_X_AccDec2.SetCaption(CData);

	_ltoa_s(SpeedFH.lY2, CData,10) ;
	m_Y_Move_Speed2.SetCaption(CData);

	_ltoa_s(SpeedAcc.lY2, CData,10) ;
	m_Y_AccDec2.SetCaption(CData);

	_ltoa_s(SpeedFH.lZ1, CData,10) ;
	m_Z_FH.SetCaption(CData);

	_ltoa_s(SpeedAcc.lZ1, CData,10) ;
	m_Z_Acc.SetCaption(CData);

	_ltoa_s(SpeedHome.lZ1, CData,10) ;
	m_Z_Home_Speed.SetCaption(CData);

	_ltoa_s(SpeedJog.lZ1, CData,10) ;
	m_Z_Jog_Speed.SetCaption(CData);

	_ltoa_s(gTeach.lInterZ, CData,10) ;
	m_Inter_Z.SetCaption(CData);
}
void CDlg_Motion::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	delete this;
	CDialog::PostNcDestroy();
}

BOOL CDlg_Motion::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialog::DestroyWindow();
}


void CDlg_Motion::ClickOkBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	DestroyWindow();
}

void CDlg_Motion::MouseUpJogRight(short Button, short Shift, long x, long y)
{
	pmiAxStop(0, M_X1);
	SpeedSetting();
}

void CDlg_Motion::ClickJogLow()
{
	gnJogSpeed = JOGLOW;
	RunLog("JOG 속도 LOW");
}

void CDlg_Motion::ClickJogMid()
{
	gnJogSpeed = JOGMID;
	RunLog("JOG 속도 MID");
}

void CDlg_Motion::ClickJogHigh()
{
	gnJogSpeed = JOGHIGH;
	RunLog("JOG 속도 HIGH");
}

void CDlg_Motion::ClickSaveBtn()
{
	if(AfxMessageBox("Data를 저장하시겠습니까?", MB_YESNO) != IDYES)
	{
		return ;
	}
	DataSave();
	RunLog("Data Save");
}

void CDlg_Motion::DblClickXMoveSpeed2()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_X_Move_Speed2.GetCaption();
	csData = CalcCall(sData);
	m_X_Move_Speed2.SetCaption(csData) ;
}

void CDlg_Motion::DblClickXAccdec2()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_X_AccDec2.GetCaption();
	csData = CalcCall(sData);
	m_X_AccDec2.SetCaption(csData) ;
}

void CDlg_Motion::DblClickYMoveSpeed2()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_Y_Move_Speed2.GetCaption();
	csData = CalcCall(sData);
	m_Y_Move_Speed2.SetCaption(csData) ;
}

void CDlg_Motion::DblClickYAccdec2()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_Y_AccDec2.GetCaption();
	csData = CalcCall(sData);
	m_Y_AccDec2.SetCaption(csData) ;
}
void CDlg_Motion::DblClickXMoveSpeed()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_X_Move_Speed.GetCaption();
	csData = CalcCall(sData);

	m_X_Move_Speed.SetCaption(csData) ;
}

void CDlg_Motion::DblClickXAccdec()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_X_AccDec.GetCaption();
	csData = CalcCall(sData);

	m_X_AccDec.SetCaption(csData) ;
}

void CDlg_Motion::DblClickXHomeSpeed()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_X_Home_Speed.GetCaption();
	csData = CalcCall(sData);
	csData = csData + "um/S";
	m_X_Home_Speed.SetCaption(csData) ;
}

void CDlg_Motion::DblClickXJogSpeed()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_X_Jog_Speed.GetCaption();
	csData = CalcCall(sData);
	csData = csData + "um/S";
	m_X_Jog_Speed.SetCaption(csData) ;
}

void CDlg_Motion::DblClickYMoveSpeed()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_Y_Move_Speed.GetCaption();
	csData = CalcCall(sData);
	csData = csData + "um/S";
	m_Y_Move_Speed.SetCaption(csData) ;
}

void CDlg_Motion::DblClickYAccdec()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_Y_AccDec.GetCaption();
	csData = CalcCall(sData);
	csData = csData + "um/S";
	m_Y_AccDec.SetCaption(csData) ;
}

void CDlg_Motion::DblClickYHomeSpeed()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_Y_Home_Speed.GetCaption();
	csData = CalcCall(sData);
	csData = csData + "um/S";
	m_Y_Home_Speed.SetCaption(csData) ;
}

void CDlg_Motion::DblClickYJogSpeed()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_Y_Jog_Speed.GetCaption();
	csData = CalcCall(sData);
	csData = csData + "um/S";
	m_Y_Jog_Speed.SetCaption(csData) ;
}
void CDlg_Motion::DblClickZMoveSpeed()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_Z_FH.GetCaption();
	csData = CalcCall(sData);
	m_Z_FH.SetCaption(csData) ;
}

void CDlg_Motion::DblClickZAccdec()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_Z_Acc.GetCaption();
	csData = CalcCall(sData);
	m_Z_Acc.SetCaption(csData) ;
}
void CDlg_Motion::DblClickZHomeSpeed()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_Z_Home_Speed.GetCaption();
	csData = CalcCall(sData);
	m_Z_Home_Speed.SetCaption(csData) ;
}

void CDlg_Motion::DblClickZJogSpeed()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData;
	CString csData;
	sData = m_Z_Jog_Speed.GetCaption();
	csData = CalcCall(sData);
	m_Z_Jog_Speed.SetCaption(csData) ;
}
void CDlg_Motion::MouseDownJogYUp(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(gnJogSpeed == JOGLOW)
	{
		pmiAxSetJogVelProf(0,M_Y1,2, SpeedJog.lY1 , 100);
	}
	else if(gnJogSpeed == JOGMID)
	{
		pmiAxSetJogVelProf(0,M_Y1,2, SpeedJog.lY1 * 3, 100);
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		pmiAxSetJogVelProf(0,M_Y1,2, SpeedJog.lY1 * 5, 100);
	}
	pmiAxJogMove(0, M_Y1, 0);
}

void CDlg_Motion::MouseUpJogYUp(short Button, short Shift, long x, long y)
{
	pmiAxStop(0, M_Y1);
	SpeedSetting();
}

void CDlg_Motion::MouseDownJogLeft(short Button, short Shift, long x, long y)
{
	if(gnJogSpeed == JOGLOW)
	{
		pmiAxSetJogVelProf(0,M_X1,2, SpeedJog.lX1 , 100);
	}
	else if(gnJogSpeed == JOGMID)
	{
		pmiAxSetJogVelProf(0,M_X1,2, SpeedJog.lX1 * 3, 100);
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		pmiAxSetJogVelProf(0,M_X1,2, SpeedJog.lX1 * 5, 100);
	}
	pmiAxJogMove(0, M_X1, 1);
}

void CDlg_Motion::MouseUpJogLeft(short Button, short Shift, long x, long y)
{
	pmiAxStop(0, M_X1);
	SpeedSetting();
}

void CDlg_Motion::MouseDownJogDown(short Button, short Shift, long x, long y)
{
	if(gnJogSpeed == JOGLOW)
	{
		pmiAxSetJogVelProf(0,M_Y1,2, SpeedJog.lY1 , 100);
	}
	else if(gnJogSpeed == JOGMID)
	{
		pmiAxSetJogVelProf(0,M_Y1,2, SpeedJog.lY1 * 3, 100);
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		pmiAxSetJogVelProf(0,M_Y1,2, SpeedJog.lY1 * 5, 100);
	}
	pmiAxJogMove(0, M_Y1, 1);
}

void CDlg_Motion::MouseUpJogDown(short Button, short Shift, long x, long y)
{
	pmiAxStop(0, M_Y1);
	SpeedSetting();
}

void CDlg_Motion::MouseDownJogRight(short Button, short Shift, long x, long y)
{
	if(gnJogSpeed == JOGLOW)
	{
		pmiAxSetJogVelProf(0,M_X1,2, SpeedJog.lX1 , 100);
	}
	else if(gnJogSpeed == JOGMID)
	{
		pmiAxSetJogVelProf(0,M_X1,2, SpeedJog.lX1 * 3, 100);
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		pmiAxSetJogVelProf(0,M_X1,2, SpeedJog.lX1 * 5, 100);
	}
	pmiAxJogMove(0, M_X1, 0);
}

void CDlg_Motion::MouseDownJogZUp(short Button, short Shift, long x, long y)
{
	if(gnJogSpeed == JOGLOW)
	{
		pmiAxSetJogVelProf(0,M_Z1,2, SpeedJog.lZ1 , 100);
	}
	else if(gnJogSpeed == JOGMID)
	{
		pmiAxSetJogVelProf(0,M_Z1,2, SpeedJog.lZ1 * 3, 100);
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		pmiAxSetJogVelProf(0,M_Z1,2, SpeedJog.lZ1 * 5, 100);
	}
	pmiAxJogMove(0, M_Z1, 1);
}

void CDlg_Motion::MouseUpJogZUp(short Button, short Shift, long x, long y)
{
	pmiAxStop(0, M_Z1);
	SpeedSetting();
}

void CDlg_Motion::DblClickRdyX()
{
	CString csData;
	csData = m_Rdy_X.GetCaption();
	csData = CalcCall(csData);
	m_Rdy_X.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickRdyY()
{
	CString csData;
	csData = m_Rdy_Y.GetCaption();
	csData = CalcCall(csData);
	m_Rdy_Y.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickRdyZ()
{
	CString csData;
	csData = m_Rdy_Z.GetCaption();
	csData = CalcCall(csData);
	m_Rdy_Z.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::ClickRdyXMove()
{
	long lData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	if(dPos > gTeach.lRdyX + 10)
	{
		return;
	}

	lData = atol(m_Rdy_X.GetCaption()) ;
	MoveTo(M_X1, lData);
}

void CDlg_Motion::ClickRdyYMove()
{
	long lData;

	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	if(dPos > gTeach.lRdyY + 10)
	{
		return;
	}
	lData = atol(m_Rdy_Y.GetCaption()) ;
	MoveTo(M_Y1, lData);
}

void CDlg_Motion::ClickRdyZMove()
{
	long lData;
	lData = atol(m_Rdy_Z.GetCaption()) ;
	MoveTo(M_Z1, lData);

}

void CDlg_Motion::DblClickPosZDw()
{
	CString csData;
	csData = m_Pos_Z_DW.GetCaption();
	csData = CalcCall(csData);
	m_Pos_Z_DW.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::ClickPosZDwMove()
{
	long lData;
	lData = atol(m_Pos_Z_DW.GetCaption()) ;
	MoveTo(M_Z1, lData);
}

void CDlg_Motion::ClickRdyXSet()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_X1, &dPos);
	csData.Format("%.f", dPos);
	m_Rdy_X.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickRdyYSet()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Y1, &dPos);
	csData.Format("%.f", dPos);
	m_Rdy_Y.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickRdyZSet()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	csData.Format("%.f", dPos);
	m_Rdy_Z.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickPosZDwSet()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	csData.Format("%.f", dPos);
	m_Pos_Z_DW.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::DblClickXPos1()
{
	CString csData;
	csData = m_X_Pos1.GetCaption();
	csData = CalcCall(csData);
	m_X_Pos1.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickYPos1()
{
	CString csData;
	csData = m_Y_Pos1.GetCaption();
	csData = CalcCall(csData);
	m_Y_Pos1.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickPosZUp()
{
	CString csData;
	csData = m_Pos_Z_UP.GetCaption();
	csData = CalcCall(csData);
	m_Pos_Z_UP.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickXPos2()
{
	CString csData;
	csData = m_X_Pos2.GetCaption();
	csData = CalcCall(csData);
	m_X_Pos2.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickYPos2()
{
	CString csData;
	csData = m_Y_Pos2.GetCaption();
	csData = CalcCall(csData);
	m_Y_Pos2.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickPosZUp2()
{
	CString csData;
	csData = m_Pos_Z_UP2.GetCaption();
	csData = CalcCall(csData);
	m_Pos_Z_UP2.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickXPos3()
{
	CString csData;
	csData = m_X_Pos3.GetCaption();
	csData = CalcCall(csData);
	m_X_Pos3.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickYPos3()
{
	CString csData;
	csData = m_Y_Pos3.GetCaption();
	csData = CalcCall(csData);
	m_Y_Pos3.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickPosZUp3()
{
	CString csData;
	csData = m_Pos_Z_UP3.GetCaption();
	csData = CalcCall(csData);
	m_Pos_Z_UP3.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickXPos4()
{
	CString csData;
	csData = m_X_Pos4.GetCaption();
	csData = CalcCall(csData);
	m_X_Pos4.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickYPos4()
{
	CString csData;
	csData = m_Y_Pos4.GetCaption();
	csData = CalcCall(csData);
	m_Y_Pos4.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickPosZUp4()
{
	CString csData;
	csData = m_Pos_Z_UP4.GetCaption();
	csData = CalcCall(csData);
	m_Pos_Z_UP4.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::DblClickInterZ()
{
	CString csData;
	csData = m_Inter_Z.GetCaption();
	csData = CalcCall(csData);
	m_Inter_Z.SetCaption(csData) ;
	DataSave();
}

void CDlg_Motion::ClickXPos1Move()
{
	long lData;

	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	if(dPos > gTeach.lDownPos + 10)
	{
		return;
	}

	lData = atol(m_X_Pos1.GetCaption()) ;
	MoveTo(M_X1, lData);
}

void CDlg_Motion::ClickYPos1Move()
{
	long lData;

	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	if(dPos > gTeach.lDownPos + 10)
	{
		return;
	}
	lData = atol(m_Y_Pos1.GetCaption()) ;
	MoveTo(M_Y1, lData);
}

void CDlg_Motion::ClickPosZMove()
{
	long lData;
	lData = atol(m_Pos_Z_UP.GetCaption()) ;
	MoveTo(M_Z1, lData);
}

void CDlg_Motion::ClickXPos2Move()
{
	long lData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	if(dPos > gTeach.lDownPos + 10)
	{
		return;
	}
	lData = atol(m_X_Pos2.GetCaption()) ;
	MoveTo(M_X1, lData);
}

void CDlg_Motion::ClickYPos2Move()
{
	long lData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	if(dPos > gTeach.lDownPos + 10)
	{
		return;
	}
	lData = atol(m_Y_Pos2.GetCaption()) ;
	MoveTo(M_Y1, lData);
}

void CDlg_Motion::ClickPosZMove2()
{
	long lData;
	lData = atol(m_Pos_Z_UP2.GetCaption()) ;
	MoveTo(M_Z1, lData);
}

void CDlg_Motion::ClickXPos3Move()
{
	long lData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	if(dPos > gTeach.lDownPos + 10)
	{
		return;
	}
	lData = atol(m_X_Pos3.GetCaption()) ;
	MoveTo(M_X1, lData);
}

void CDlg_Motion::ClickYPos3Move()
{
	long lData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	if(dPos > gTeach.lDownPos + 10)
	{
		return;
	}
	lData = atol(m_Y_Pos3.GetCaption()) ;
	MoveTo(M_Y1, lData);
}

void CDlg_Motion::ClickPosZMove3()
{
	long lData;
	lData = atol(m_Pos_Z_UP3.GetCaption()) ;
	MoveTo(M_Z1, lData);
}

void CDlg_Motion::ClickXPos4Move()
{
	long lData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	if(dPos > gTeach.lDownPos + 10)
	{
		return;
	}
	lData = atol(m_X_Pos4.GetCaption()) ;
	MoveTo(M_X1, lData);
}

void CDlg_Motion::ClickYPos4Move()
{
	long lData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	if(dPos > gTeach.lDownPos + 10)
	{
		return;
	}
	lData = atol(m_Y_Pos4.GetCaption()) ;
	MoveTo(M_Y1, lData);
}

void CDlg_Motion::ClickPosZMove4()
{
	long lData;
	lData = atol(m_Pos_Z_UP4.GetCaption()) ;
	MoveTo(M_Z1, lData);
}

void CDlg_Motion::ClickPosZDwMove2()
{
	long lData;
	lData = atol(m_Inter_Z.GetCaption()) ;

	MoveTo(M_Z1, lData);
}

void CDlg_Motion::ClickXPos1Set()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_X1, &dPos);
	csData.Format("%.f", dPos);
	m_X_Pos1.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickYPos1Set()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Y1, &dPos);
	csData.Format("%.f", dPos);
	m_Y_Pos1.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickPosZUpSet()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	csData.Format("%.f", dPos);
	m_Pos_Z_UP.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickXPos2Set()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_X1, &dPos);
	csData.Format("%.f", dPos);
	m_X_Pos2.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickYPos2Set()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Y1, &dPos);
	csData.Format("%.f", dPos);
	m_Y_Pos2.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickPosZUpSet2()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	csData.Format("%.f", dPos);
	m_Pos_Z_UP2.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickXPos3Set()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_X1, &dPos);
	csData.Format("%.f", dPos);
	m_X_Pos3.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickYPos3Set()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Y1, &dPos);
	csData.Format("%.f", dPos);
	m_Y_Pos3.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickPosZUpSet3()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	csData.Format("%.f", dPos);
	m_Pos_Z_UP3.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickXPos4Set()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_X1, &dPos);
	csData.Format("%.f", dPos);
	m_X_Pos4.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickYPos4Set()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Y1, &dPos);
	csData.Format("%.f", dPos);
	m_Y_Pos4.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickPosZUpSet4()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	csData.Format("%.f", dPos);
	m_Pos_Z_UP4.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::ClickPosZDwSet2()
{
	CString csData;
	double dPos;

	pmiAxGetActPos(0,M_Z1, &dPos);
	csData.Format("%.f", dPos);
	m_Inter_Z.SetCaption(csData);
	DataSave();
}

void CDlg_Motion::DblClickXMovepos()
{
	CString csData;
	csData = m_X_MovePos.GetCaption();
	csData = CalcCall(csData);
	m_X_MovePos.SetCaption(csData) ;
}

void CDlg_Motion::DblClickYMovepos()
{
	CString csData;
	csData = m_Y_MovePos.GetCaption();
	csData = CalcCall(csData);
	m_Y_MovePos.SetCaption(csData) ;
}

void CDlg_Motion::DblClickZMovepos()
{
	CString csData;
	csData = m_Z_MovePos.GetCaption();
	csData = CalcCall(csData);
	m_Z_MovePos.SetCaption(csData) ;
}

void CDlg_Motion::ClickXMove()
{
	long lData;
	lData = atol(m_X_MovePos.GetCaption()) ;
	MoveTo(M_X1, lData);
}

void CDlg_Motion::ClickYMove()
{
	long lData;
	lData = atol(m_Y_MovePos.GetCaption()) ;
	MoveTo(M_Y1, lData);
}

void CDlg_Motion::ClickZMove()
{
	long lData;
	lData = atol(m_Z_MovePos.GetCaption()) ;
	MoveTo(M_Z1, lData);
}
