// Dlg_Jog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_Jog.h"
#include "VarEx.h"
//#include "Cmmsdk.h"
#include "FuncEx.h"


// CDlg_Jog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_Jog, CDialog)

CDlg_Jog::CDlg_Jog(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Jog::IDD, pParent)
{

}

CDlg_Jog::~CDlg_Jog()
{
}

void CDlg_Jog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_JOG_HIGH, m_Jog_High);
	DDX_Control(pDX, IDC_JOG_MID, m_Jog_Mid);
	DDX_Control(pDX, IDC_JOG_LOW, m_Jog_Low);
}


BEGIN_MESSAGE_MAP(CDlg_Jog, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlg_Jog 메시지 처리기입니다.

BOOL CDlg_Jog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetTimer(1,10,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
BEGIN_EVENTSINK_MAP(CDlg_Jog, CDialog)
	ON_EVENT(CDlg_Jog, IDC_MESSAGE128, DISPID_MOUSEDOWN, CDlg_Jog::MouseDownMessage128, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Jog, IDC_MESSAGE128, DISPID_MOUSEUP, CDlg_Jog::MouseUpMessage128, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Jog, IDC_MESSAGE50, DISPID_MOUSEDOWN, CDlg_Jog::MouseDownMessage50, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Jog, IDC_MESSAGE50, DISPID_MOUSEUP, CDlg_Jog::MouseUpMessage50, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Jog, IDC_JOG_Y_UP5, DISPID_MOUSEDOWN, CDlg_Jog::MouseDownJogYUp5, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Jog, IDC_JOG_Y_UP5, DISPID_MOUSEUP, CDlg_Jog::MouseUpJogYUp5, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Jog, IDC_JOG_DOWN5, DISPID_MOUSEDOWN, CDlg_Jog::MouseDownJogDown5, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Jog, IDC_JOG_DOWN5, DISPID_MOUSEUP, CDlg_Jog::MouseUpJogDown5, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Jog, IDC_JOG_Z_UP, DISPID_MOUSEDOWN, CDlg_Jog::MouseDownJogZUp, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Jog, IDC_JOG_Z_UP, DISPID_MOUSEUP, CDlg_Jog::MouseUpJogZUp, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Jog, IDC_JOG_Z_DOWN, DISPID_MOUSEDOWN, CDlg_Jog::MouseDownJogZDown, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CDlg_Jog, IDC_JOG_Z_DOWN, DISPID_MOUSEUP, CDlg_Jog::MouseUpJogZDown, VTS_I2 VTS_I2 VTS_I4 VTS_I4)	
	ON_EVENT(CDlg_Jog, IDC_JOG_LOW, DISPID_CLICK, CDlg_Jog::ClickJogLow, VTS_NONE)
	ON_EVENT(CDlg_Jog, IDC_JOG_MID, DISPID_CLICK, CDlg_Jog::ClickJogMid, VTS_NONE)
	ON_EVENT(CDlg_Jog, IDC_JOG_HIGH, DISPID_CLICK, CDlg_Jog::ClickJogHigh, VTS_NONE)
	ON_EVENT(CDlg_Jog, IDC_OK_BTN, DISPID_CLICK, CDlg_Jog::ClickOkBtn, VTS_NONE)
END_EVENTSINK_MAP()

void CDlg_Jog::MouseDownMessage128(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(gnJogSpeed == JOGLOW)
	{
		glJogSpeed = SpeedJog.lX1;
	}
	else if(gnJogSpeed == JOGMID)
	{
		glJogSpeed = SpeedJog.lX1 * 3;
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		glJogSpeed = SpeedJog.lX1 * 5;
	}

	//cmmCfgSetSpeedPattern(M_X1, cmSMODE_S, glJogSpeed, glJogSpeed * 3, glJogSpeed * 3);
	//cmmSxVMoveStart(M_X1, cmDIR_N);	
}

void CDlg_Jog::MouseUpMessage128(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//cmmSxStop(M_X1, cmFALSE, cmFALSE);
	SpeedSetting();
}

void CDlg_Jog::MouseDownMessage50(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(gnJogSpeed == JOGLOW)
	{
		glJogSpeed = SpeedJog.lX1;
	}
	else if(gnJogSpeed == JOGMID)
	{
		glJogSpeed = SpeedJog.lX1 * 3;
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		glJogSpeed = SpeedJog.lX1 * 5;
	}

	//cmmCfgSetSpeedPattern(M_X1, cmSMODE_S, glJogSpeed, glJogSpeed * 3, glJogSpeed * 3);
	//cmmSxVMoveStart(M_X1, cmDIR_P);	
}

void CDlg_Jog::MouseUpMessage50(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//cmmSxStop(M_X1, cmFALSE, cmFALSE);
	SpeedSetting();
}

void CDlg_Jog::MouseDownJogYUp5(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(gnJogSpeed == JOGLOW)
	{
		glJogSpeed = SpeedJog.lY1;
	}
	else if(gnJogSpeed == JOGMID)
	{
		glJogSpeed = SpeedJog.lY1 * 3;
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		glJogSpeed = SpeedJog.lY1 * 5;
	}
	
	//cmmCfgSetSpeedPattern(M_Y1, cmSMODE_S, glJogSpeed, glJogSpeed * 3, glJogSpeed * 3);
	//cmmSxVMoveStart(M_Y1, cmDIR_N);	
	
}

void CDlg_Jog::MouseUpJogYUp5(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//cmmSxStop(M_Y1, cmFALSE, cmFALSE);
	SpeedSetting();
}

void CDlg_Jog::MouseDownJogDown5(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(gnJogSpeed == JOGLOW)
	{
		glJogSpeed = SpeedJog.lY1;
	}
	else if(gnJogSpeed == JOGMID)
	{
		glJogSpeed = SpeedJog.lY1 * 3;
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		glJogSpeed = SpeedJog.lY1 * 5;
	}

	//cmmCfgSetSpeedPattern(M_Y1, cmSMODE_S, glJogSpeed, glJogSpeed * 3, glJogSpeed * 3);
	//cmmSxVMoveStart(M_Y1, cmDIR_P);	
}

void CDlg_Jog::MouseUpJogDown5(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//cmmSxStop(M_Y1, cmFALSE, cmFALSE);
	SpeedSetting();
}

void CDlg_Jog::MouseDownJogZUp(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(gnJogSpeed == JOGLOW)
	{
		glJogSpeed = SpeedJog.lZ1;
	}
	else if(gnJogSpeed == JOGMID)
	{
		glJogSpeed = SpeedJog.lZ1 * 3;
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		glJogSpeed = SpeedJog.lZ1 * 5;
	}

	//cmmCfgSetSpeedPattern(M_Z1, cmSMODE_S, glJogSpeed, glJogSpeed * 3, glJogSpeed * 3);
	//cmmSxVMoveStart(M_Z1, cmDIR_N);	
}

void CDlg_Jog::MouseUpJogZUp(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//cmmSxStop(M_Z1, cmFALSE, cmFALSE);
	SpeedSetting();
}

void CDlg_Jog::MouseDownJogZDown(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(gnJogSpeed == JOGLOW)
	{
		glJogSpeed = SpeedJog.lZ1;
	}
	else if(gnJogSpeed == JOGMID)
	{
		glJogSpeed = SpeedJog.lZ1 * 3;
	}
	else if(gnJogSpeed == JOGHIGH)
	{
		glJogSpeed = SpeedJog.lZ1 * 5;
	}

	//cmmCfgSetSpeedPattern(M_Z1, cmSMODE_S, glJogSpeed, glJogSpeed * 3, glJogSpeed * 3);
	//cmmSxVMoveStart(M_Z1, cmDIR_P);	
}

void CDlg_Jog::MouseUpJogZDown(short Button, short Shift, long x, long y)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//cmmSxStop(M_Z1, cmFALSE, cmFALSE);
	SpeedSetting();
}


void CDlg_Jog::ClickJogLow()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	gnJogSpeed = JOGLOW;
}

void CDlg_Jog::ClickJogMid()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	gnJogSpeed = JOGMID;
}

void CDlg_Jog::ClickJogHigh()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	gnJogSpeed = JOGHIGH;
}

void CDlg_Jog::ClickOkBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	DestroyWindow();
}

void CDlg_Jog::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	delete this;
	CDialog::PostNcDestroy();
}

BOOL CDlg_Jog::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialog::DestroyWindow();
}

void CDlg_Jog::GetMotionStatus()
{
	////////////////////////////////////////////////IAI////////////////////////////////////////////
	if(gnJogSpeed == JOGHIGH)
	{
		m_Jog_High.SetBackColor(RGB(0,200,0));
		m_Jog_Mid.SetBackColor(RGB(0,0,0));
		m_Jog_Low.SetBackColor(RGB(0,0,0));
	}
	else if(gnJogSpeed == JOGMID)
	{
		m_Jog_High.SetBackColor(RGB(0,0,0));
		m_Jog_Mid.SetBackColor(RGB(0,200,0));
		m_Jog_Low.SetBackColor(RGB(0,0,0));
	}
	else if(gnJogSpeed == JOGLOW)
	{
		m_Jog_High.SetBackColor(RGB(0,0,0));
		m_Jog_Mid.SetBackColor(RGB(0,0,0));
		m_Jog_Low.SetBackColor(RGB(0,200,0));
	}


}
void CDlg_Jog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(nIDEvent == 1)
	{
		GetMotionStatus();
	}

	CDialog::OnTimer(nIDEvent);
}
