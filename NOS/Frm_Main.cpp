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
#include "Dlg_Model.h"
#include "Dlg_Skip.h"
#include "Dlg_Skip2.h"
#include "Dlg_Skip3.h"
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
	DDX_Control(pDX, IDC_MODEL_NAME, m_Model_Name);
	DDX_Control(pDX, IDC_JIG1, m_Jig1);
	DDX_Control(pDX, IDC_JIG2, m_Jig2);
	DDX_Control(pDX, IDC_JIG6, m_Jig3);
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
	DataLoadSetCaption();
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
			DataLoadSetCaption();
		}
	}

	if(nIDEvent == 2)
	{
		DataDisplay();
		MainTime();
	}

	CFormView::OnTimer(nIDEvent);
}
void CFrm_Main::DataLoadSetCaption()
{

}
BEGIN_EVENTSINK_MAP(CFrm_Main, CFormView)
	ON_EVENT(CFrm_Main, IDC_MAINEXIT_BTN, DISPID_CLICK, CFrm_Main::ClickMainexitBtn, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_START_BTN, DISPID_CLICK, CFrm_Main::ClickStartBtn, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_STOP_BTN, DISPID_CLICK, CFrm_Main::ClickStopBtn, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_MOTION_BTN, DISPID_CLICK, CFrm_Main::ClickMotionBtn, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_MODEL_NAME, DISPID_DBLCLICK, CFrm_Main::DblClickModelName, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_JIG1, DISPID_CLICK, CFrm_Main::ClickJig1, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_JIG2, DISPID_CLICK, CFrm_Main::ClickJig2, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_JIG6, DISPID_CLICK, CFrm_Main::ClickJig6, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_JIG3, DISPID_CLICK, CFrm_Main::ClickJig3, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_JIG4, DISPID_CLICK, CFrm_Main::ClickJig4, VTS_NONE)
	ON_EVENT(CFrm_Main, IDC_JIG5, DISPID_CLICK, CFrm_Main::ClickJig5, VTS_NONE)
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

	if(m_nOldJigSel != gnJigSel)
	{
		m_nOldJigSel = gnJigSel;
		if(gnJigSel == 0)
		{
			m_Jig1.SetBackColor(RGB(0,255,0));
			m_Jig2.SetBackColor(RGB(0,0,0));
			m_Jig3.SetBackColor(RGB(0,0,0));
		}
		else if(gnJigSel == 1)
		{
			m_Jig2.SetBackColor(RGB(0,255,0));
			m_Jig1.SetBackColor(RGB(0,0,0));
			m_Jig3.SetBackColor(RGB(0,0,0));
		}
		else if(gnJigSel == 2)
		{
			m_Jig2.SetBackColor(RGB(0,0,0));
			m_Jig1.SetBackColor(RGB(0,0,0));
			m_Jig3.SetBackColor(RGB(0,255,0));
		}
	}

	CString csData;

	csData.Format("%.1f초",glTactTime1 * 0.001);
	m_Work_Time.SetCaption(csData);

	csData.Format("%.1f초",glCycleTime1 * 0.001);
	m_Cycle_Time.SetCaption(csData);	

	if(m_csOldModel != gcsModelName)
	{
		m_csOldModel = gcsModelName;
		m_Model_Name.SetCaption(gcsModelName);
	}
}

void CFrm_Main::Rect1(CDC* pDC, int nSite)
{
	int nX = 370;
	int nY = 702;
	int nOffSetX = 15;
	int nOffSetY = 14;
	int nJ = 0;
	int nI = 0;
	int nXPos = 0;
	int nYPos = 0;

	bool bChange = 0;
	int nStatus;
	CString csData;


	if(m_nSite == 0)
	{
		nX = 1091;
		nY = 132;
	}
	else
	{
		nX = 1091;
		nY = 322;
	}


	CPen myPen;
	CPen* pOldPen;

	myPen.CreatePen(0,1, RGB(255,255,255));
	pOldPen = pDC->SelectObject(&myPen);

	for(int nK = 0; nK < gnJigYCnt; nK ++)
	{
		for(int nL = 0; nL < gnJigXCnt; nL ++)
		{
			nXPos = nX + (nOffSetX * nL) + (2 * nL);
			nYPos = nY + (nOffSetY * nK) + (2 * nK);

			if(m_nSite == 0)
			{
				nStatus = gnLensStatus[nL][nK];
			}
			else
			{
				nStatus = gnLensStatusOld[nL][nK];
			}

			if(nStatus == LENSGOOD)
			{
				pDC->FillSolidRect(nXPos, nYPos, nOffSetX, nOffSetY,RGB(0,200,0));
			}
			else if(nStatus == LENSSORT)
			{
				pDC->FillSolidRect(nXPos, nYPos, nOffSetX, nOffSetY,RGB(100,100,100));
			}
			else if(nStatus == LENSNG)
			{
				pDC->FillSolidRect(nXPos, nYPos, nOffSetX, nOffSetY,RGB(200,0,0));
			}
			else if(nStatus == LENS_SPOT)
			{
				pDC->FillSolidRect(nXPos, nYPos, nOffSetX, nOffSetY,RGB(0,0,150));
			}
			else if(nStatus == LENS_VINET)
			{
				pDC->FillSolidRect(nXPos, nYPos, nOffSetX, nOffSetY,RGB(255,255,0));
			}			
		}
	}
	myPen.DeleteObject();
	pOldPen->DeleteObject();
}

void CFrm_Main::FillBitmapInfo(BITMAPINFO* bmi, int width, int height, int bpp, int origin)
{
	//assert(bmi && width >=0 && height >=0 && (bpp == 8 || bpp == 24 || bpp == 32));
	_ASSERT(bmi && width >=0 && height >=0 && (bpp == 8 || bpp == 24 || bpp == 32));
	BITMAPINFOHEADER* bmih = &(bmi->bmiHeader);
	memset(bmih,0,sizeof(*bmih));
	bmih->biSize = sizeof(BITMAPINFOHEADER);
	bmih->biWidth = width;
	bmih->biHeight = origin ? abs(height) : -abs(height);
	bmih->biPlanes = 1;
	bmih->biBitCount = (unsigned short)bpp;
	bmih->biCompression = BI_RGB;
	if(bpp==8)
	{
		RGBQUAD* palette = bmi->bmiColors;
		int i;
		for(i=0;i<256;i++)
		{
			palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = (BYTE)i;
			palette[i].rgbReserved = 0;
		}
	}
}

void CFrm_Main::FillBitmapInfo2(BITMAPINFO* bmi, int width, int height, int bpp, int origin)
{
	//assert(bmi && width >=0 && height >=0 && (bpp == 8 || bpp == 24 || bpp == 32));
	_ASSERT(bmi && width >=0 && height >=0 && (bpp == 8 || bpp == 24 || bpp == 32));
	BITMAPINFOHEADER* bmih = &(bmi->bmiHeader);
	memset(bmih,0,sizeof(*bmih));
	bmih->biSize = sizeof(BITMAPINFOHEADER);
	bmih->biWidth = width;
	bmih->biHeight = origin ? abs(height) : -abs(height);
	bmih->biPlanes = 1;
	bmih->biBitCount = (unsigned short)bpp;
	bmih->biCompression = BI_RGB;
	if(bpp==8)
	{
		RGBQUAD* palette = bmi->bmiColors;
		int i;
		for(i=0;i<256;i++)
		{
			palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = (BYTE)i;
			palette[i].rgbReserved = 0;
		}
	}
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

void CFrm_Main::DblClickModelName()
{
	CString csFileName;
	CString csRet;
	CString csData;

		CDlg_Model Dlg;
		Dlg.DoModal();

	csFileName = "d:\\NOS\\NOS";
	csFileName = csFileName + "\\Model.txt" ;
	WritePrivateProfileString("MODEL", "NAME", gcsModelName, csFileName);
	MotionDataLoad();
}

void CFrm_Main::ClickJig1()
{
	gnJigSel = 0;
}

void CFrm_Main::ClickJig2()
{
	gnJigSel = 1;
}

void CFrm_Main::ClickJig6()
{
	gnJigSel = 2;
}

void CFrm_Main::ClickJig3()
{
	CDlg_Skip		*dlg = new CDlg_Skip;//동적으로 생성해준다
	dlg -> Create(IDD_DLG_SKIP,NULL);//모달리스는 반드시 Create로 띄워야한다. 
	dlg ->ShowWindow(SW_SHOW);
}

void CFrm_Main::ClickJig4()
{
	CDlg_Skip2		*dlg = new CDlg_Skip2;//동적으로 생성해준다
	dlg -> Create(IDD_DLG_SKIP2,NULL);//모달리스는 반드시 Create로 띄워야한다. 
	dlg ->ShowWindow(SW_SHOW);
}

void CFrm_Main::ClickJig5()
{
	CDlg_Skip3		*dlg = new CDlg_Skip3;//동적으로 생성해준다
	dlg -> Create(IDD_DLG_SKIP3,NULL);//모달리스는 반드시 Create로 띄워야한다. 
	dlg ->ShowWindow(SW_SHOW);
}
