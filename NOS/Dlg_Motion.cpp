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
	// 	DDX_Control(pDX, IDC_X_FEED, m_X_Feed);
	// 	DDX_Control(pDX, IDC_Y_FEED, m_Y_Feed);
	// 	DDX_Control(pDX, IDC_Z_FEED, m_Z_Feed);
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


END_EVENTSINK_MAP()

void CDlg_Motion::GetMotionStatus()
{
// 	long dwMIOState;
// 	BOOL bELPState;
// 	BOOL bELMState;
// 	BOOL bAMPState;
// 	BOOL bORGState;
// 	BOOL bINPState;
// 	CString csData;
// 	double dPos;
// 
// 	cmmStReadMioStatuses(M_X1, &dwMIOState);
// 	bELPState = (dwMIOState >> cmIOST_ELP) & 0x1;
// 	bELMState = (dwMIOState >> cmIOST_ELN) & 0x1;
// 	bAMPState = (dwMIOState >> cmIOST_ALM) & 0x1;
// 	bORGState = (dwMIOState >> cmIOST_ORG) & 0x1;
// 	bINPState = (dwMIOState >> cmIOST_INP) & 0x1;

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

BOOL CDlg_Motion::OnInitDialog()
{
	CDialog::OnInitDialog();
	gnJogSpeed = JOGLOW;	
	SetTimer(1,100,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
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

// void CDlg_Motion::DblClickXMovepos()
// {
// 	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
// 	CString csData;
// 	csData = m_X_MovePos.GetCaption();
// 	csData = CalcCall(csData);
// 	m_X_MovePos.SetCaption(csData) ;
// }
// 
// void CDlg_Motion::DblClickYMovepos()
// {
// 	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
// 	CString csData;
// 	csData = m_Y_MovePos.GetCaption();
// 	csData = CalcCall(csData);
// 	m_Y_MovePos.SetCaption(csData) ;
// }
// 
// void CDlg_Motion::DblClickZMovepos()
// {
// 	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
// 	CString csData;
// 	csData = m_Z_MovePos.GetCaption();
// 	csData = CalcCall(csData);
// 	m_Z_MovePos.SetCaption(csData) ;
// }

void CDlg_Motion::ClickOkBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	DestroyWindow();
}

// void CDlg_Motion::ClickXMove()
// {
// 	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
// 	long lData;
// 	lData = atol(m_X_MovePos.GetCaption()) ;
// 	MoveTo(M_X1, lData);
// }
// 
// void CDlg_Motion::ClickYMove()
// {
// 	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
// 	long lData;
// 	lData = atol(m_X_MovePos.GetCaption()) ;
// 	MoveTo(M_Y1, lData);
// }
// 
// void CDlg_Motion::ClickZMove()
// {
// 	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
// 	long lData;
// 	lData = atol(m_X_MovePos.GetCaption()) ;
// 	MoveTo(M_Z1, lData);
// }

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