// Frm_Main.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "NOS.h"
#include "Frm_Main.h"
#include "VarEx.h"
#include "Var.h"
#include "FuncEx.h"
#include "func.h"
#include "Dlg_LogIN.h"
#include "Dlg_PW.h"
#include "Dlg_Init.h"
#include "Dlg_Calc.h"
#include "Dlg_Motion.h"

// CFrm_Main
IMPLEMENT_DYNCREATE(CFrm_Main, CFormView)

CFrm_Main::CFrm_Main()
	: CFormView(CFrm_Main::IDD)
{

}

CFrm_Main::~CFrm_Main()
{
}

void CFrm_Main::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATUS, m_Status);
	DDX_Control(pDX, IDC_ALARM_MESSAGE, m_AlarmMessage);
	DDX_Control(pDX, IDC_DISP_DATE, m_Date);
	DDX_Control(pDX, IDC_DISP_TIME, m_Time);
	DDX_Control(pDX, IDC_WORK_TIME, m_Work_Time);
	DDX_Control(pDX, IDC_CYCLE_TIME, m_Cycle_Time);
}

BEGIN_MESSAGE_MAP(CFrm_Main, CFormView)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CFrm_Main 진단입니다.

#ifdef _DEBUG
void CFrm_Main::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFrm_Main::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFrm_Main 메시지 처리기입니다.

void CFrm_Main::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if(gbSameProjectStart == true)
	{

		AfxGetMainWnd()->PostMessage(WM_CLOSE);
		return;
	}

	SetTimer(1, 100, NULL);
	SetTimer(2, 100, NULL);
}

void CFrm_Main::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(nIDEvent == 1)
	{
		if(gbInitDlgFirst == false)
		{
			KillTimer(1);
			//INIT DLG
			CDlg_Init	Dlg;
			Dlg.DoModal();
			gbInitDlgFirst = true;
		}
	}

	if(nIDEvent == 2)
	{
		DataDisplay();
		MainTime();
	}

	CFormView::OnTimer(nIDEvent);
}
BEGIN_EVENTSINK_MAP(CFrm_Main, CFormView)
	ON_EVENT(CFrm_Main, IDC_MAINEXIT_BTN, DISPID_CLICK, CFrm_Main::ClickMainexitBtn, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_START_BTN, DISPID_CLICK, CFrm_Main::ClickStartBtn, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_STOP_BTN, DISPID_CLICK, CFrm_Main::ClickStopBtn, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_MOTION_BTN, DISPID_CLICK, CFrm_Main::ClickMotionBtn, VTS_NONE)
END_EVENTSINK_MAP()

void CFrm_Main::ClickMainexitBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(AfxMessageBox("프로그램을 종료 하시겠습니까?", MB_YESNO) != IDYES)
	{
		return ;
	}
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}

void CFrm_Main::ClickStartBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(gbOrgEnd == false)
	{
		AfxMessageBox("홈체크후에 구동 가능합니다.");
		return; 
	}

	gNOS.bStart = true;
	gNOS.bStop = false;
	SpeedSetting();
}

void CFrm_Main::ClickStopBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	gNOS.bStart = false;
	gNOS.bStop = true;
	gNOS.bError = false;
}

void CFrm_Main::DataDisplay()
{	
	if(gNOS.bStart == true && gNOS.bStop == false && gNOS.bError == false)
	{
		m_Status.SetBackColor(RGB(0,200,0));
		m_Status.SetCaption("START");
	}
	else if(gNOS.bStart == false && gNOS.bStop == true && gNOS.bError == false)
	{
		m_Status.SetBackColor(RGB(0,0,200));
		m_Status.SetCaption("STOP");
		m_AlarmMessage.SetCaption("");
	}
	else if(gNOS.bStart == false && gNOS.bStop == true && gNOS.bError == true)
	{
		m_Status.SetBackColor(RGB(200,0,0));
		m_Status.SetCaption("ERROR");
		m_AlarmMessage.SetCaption(gNOS.csErrorCode);
	}


	CString csData;

	csData.Format("%.1f초",glTactTime1 * 0.001);
	m_Work_Time.SetCaption(csData);

	csData.Format("%.1f초",glCycleTime1 * 0.001);
	m_Cycle_Time.SetCaption(csData);	
}

void CFrm_Main::MainTime()
{
	CTime CurTime;
	CString csData;
	int iYear,iMonth,iDay,iHour,iMinute,iSecond;

	CurTime = CTime::GetCurrentTime();
	iMonth = CurTime.GetMonth();
	iDay = CurTime.GetDay();
	iYear = CurTime.GetYear();
	iHour = CurTime.GetHour();
	iMinute = CurTime.GetMinute();
	iSecond = CurTime.GetSecond();
	csData.Format("%02d년%02d월%02d일", iYear,iMonth,iDay);
	m_Date.SetCaption(csData);
	csData.Format("%02d시%02d분%02d초", iHour,iMinute,iSecond);
	m_Time.SetCaption(csData);
	
}
void CFrm_Main::ClickMotionBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CDlg_Motion Dlg;
	Dlg.DoModal();
}
