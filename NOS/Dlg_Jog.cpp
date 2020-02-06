// Dlg_Jog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_Jog.h"
#include "VarEx.h"
//#include "Cmmsdk.h"
#include "FuncEx.h"


// CDlg_Jog ��ȭ �����Դϴ�.

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


// CDlg_Jog �޽��� ó�����Դϴ�.

BOOL CDlg_Jog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetTimer(1,10,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxStop(M_X1, cmFALSE, cmFALSE);
	SpeedSetting();
}

void CDlg_Jog::MouseDownMessage50(short Button, short Shift, long x, long y)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxStop(M_X1, cmFALSE, cmFALSE);
	SpeedSetting();
}

void CDlg_Jog::MouseDownJogYUp5(short Button, short Shift, long x, long y)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxStop(M_Y1, cmFALSE, cmFALSE);
	SpeedSetting();
}

void CDlg_Jog::MouseDownJogDown5(short Button, short Shift, long x, long y)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxStop(M_Y1, cmFALSE, cmFALSE);
	SpeedSetting();
}

void CDlg_Jog::MouseDownJogZUp(short Button, short Shift, long x, long y)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxStop(M_Z1, cmFALSE, cmFALSE);
	SpeedSetting();
}

void CDlg_Jog::MouseDownJogZDown(short Button, short Shift, long x, long y)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxStop(M_Z1, cmFALSE, cmFALSE);
	SpeedSetting();
}


void CDlg_Jog::ClickJogLow()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	gnJogSpeed = JOGLOW;
}

void CDlg_Jog::ClickJogMid()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	gnJogSpeed = JOGMID;
}

void CDlg_Jog::ClickJogHigh()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	gnJogSpeed = JOGHIGH;
}

void CDlg_Jog::ClickOkBtn()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	DestroyWindow();
}

void CDlg_Jog::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	delete this;
	CDialog::PostNcDestroy();
}

BOOL CDlg_Jog::DestroyWindow()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(nIDEvent == 1)
	{
		GetMotionStatus();
	}

	CDialog::OnTimer(nIDEvent);
}
