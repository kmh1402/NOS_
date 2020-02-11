// Dlg_Init.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_Init.h"
#include "pmiMApi.h"
#include "pmiMApiDefs.h"
#include "VarEx.h"
#include "FuncEx.h"
#include "Thread.h"

// CDlg_Init 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_Init, CDialog)

CDlg_Init::CDlg_Init(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Init::IDD, pParent)
{

}

CDlg_Init::~CDlg_Init()
{
}

void CDlg_Init::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MESSAGE, m_Message);
	DDX_Control(pDX, IDC_PERCENT, m_Percent);
	DDX_Control(pDX, IDC_PROGRESS, m_Progress);
}


BEGIN_MESSAGE_MAP(CDlg_Init, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlg_Init 메시지 처리기입니다.

BOOL CDlg_Init::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_Progress.SetRange(0,100);
	m_Progress.SetPos(0);
	m_Message.SetCaption("");
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlg_Init::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	KillTimer(1) ;
	//vision Init
	int nI = 0;
	int nStatus = 0;
	int nSleep = 20;//프로그레스바의 진행 속도를 결정한다. 
	CString csData;
	csData = "Initialize..";
	m_Message.SetCaption(csData);
	/////////////////////////////////////////////////////////////////
	MotionDataLoad();
	DataInit();
	CountLoad();

	
	for(nI = 0; nI < 10 ; nI++)
	{
		Sleep(nSleep);
		csData.Format("%02d %%",nI);
		m_Percent.SetCaption(csData);
		m_Progress.SetPos(nI);
	}

	csData = "I/O Conectting...";
	
	m_Message.SetCaption(csData);
	
	for(nI = 10; nI < 20 ; nI++)
	{
		Sleep(nSleep);
		csData.Format("%02d %%",nI);
		m_Percent.SetCaption(csData);
		m_Progress.SetPos(nI);
	}
	
	
	m_Message.SetCaption("NetWork Conectting");
	for(nI = 20; nI < 30 ; nI++)
	{
		Sleep(nSleep);
		csData.Format("%02d %%",nI);
		m_Percent.SetCaption(csData);
		m_Progress.SetPos(nI);
	}

	for(nI = 30; nI < 40 ; nI++)
	{
		Sleep(nSleep);
		csData.Format("%02d %%",nI);
		m_Percent.SetCaption(csData);
		m_Progress.SetPos(nI);
	}

	
	m_Message.SetCaption("Setting Data Load");
	for(nI = 40; nI < 50 ; nI++)
	{
		Sleep(nSleep);
		csData.Format("%02d %%",nI);
		m_Percent.SetCaption(csData);
		m_Progress.SetPos(nI);	
	}

	
	m_Message.SetCaption("Recovery Data Load");
	for(nI = 50; nI < 60 ; nI++)
	{
		Sleep(nSleep);
		csData.Format("%02d %%",nI);
		m_Percent.SetCaption(csData);
		m_Progress.SetPos(nI);
	}
		
	m_Message.SetCaption("Teaching DataLoad");
	for(nI = 60; nI < 70 ; nI++)
	{
		Sleep(nSleep);
		csData.Format("%02d %%",nI);
		m_Percent.SetCaption(csData);
		m_Progress.SetPos(nI);
	}
	MotionDataLoad();
	m_Message.SetCaption("Motion Data Load");
	for(nI = 70; nI < 80 ; nI++)
	{
		Sleep(nSleep);
		csData.Format("%02d %%",nI);
		m_Percent.SetCaption(csData);
		m_Progress.SetPos(nI);
	}
	
	m_Message.SetCaption("Work Data Load");
	for(nI = 80; nI < 90 ; nI++)
	{
		Sleep(nSleep);
		csData.Format("%02d %%",nI);
		m_Percent.SetCaption(csData);
		m_Progress.SetPos(nI);
	}
	 
	
	m_Message.SetCaption("Dispenser Conetting..");
	for(nI = 90; nI <= 100 ; nI++)
	{
		Sleep(nSleep);
		csData.Format("%02d %%",nI);
		m_Percent.SetCaption(csData);
		m_Progress.SetPos(nI);
	}

	m_Progress.SetPos(100);
	m_Percent.SetCaption("Complette 100 %");
	PWLoad();
	
	
	m_Thread[0] = AfxBeginThread(Thread_UtilityFunction,this);	// m_Thread[0]	
	m_Thread[1] = AfxBeginThread(Thread_Main,this);				// m_Thread[1]
	
	

	gbThreadEnd = true;
	SpeedSetting();
	CountLoad();
	
	
	EndDialog(IDOK) ;
	CDialog::OnTimer(nIDEvent);
}

void CDlg_Init::DataInit()
{
	int iRet = 0;
	int iConNum = 0;
	int nI = 0;
	
	iRet = pmiSysLoad( TMC_FALSE, &iConNum );

	if(iRet >= 0)
	{
		// 파라미터 파일은 MotionComposer.ini 파일에 Parameter_File = 경로를 쫓아 간다.
		iRet = pmiConParamLoad(NULL);
	}
	else
	{		
		AfxMessageBox("Motion InitFail");
	}

	pmiAxSetServoOn(0,M_X1,1);
	pmiAxSetServoOn(0,M_Y1,1);
	pmiAxSetServoOn(0,M_Z1,1);
	//폴더생성
	CString csFileName,csCreateName;
	CString csYear,csMonth, csDay;
	CString csData;

	GetCurDay(&csYear, &csMonth, &csDay);
	csFileName = GetRunDirectory();

	csCreateName = csFileName + "\\Setting\\";
	DirectoryCreate(csCreateName);

	csCreateName = csFileName + "\\Data\\";
	DirectoryCreate(csCreateName);

	csCreateName = "C:\\Data\\";
	DirectoryCreate(csCreateName);


	csCreateName = csCreateName + csYear + "\\";
	DirectoryCreate(csCreateName);

	csCreateName = csCreateName + csMonth + "\\";
	DirectoryCreate(csCreateName);

	csCreateName = csCreateName + csDay + "\\";
	DirectoryCreate(csCreateName);

	//gcsCSVFileName = csCreateName;

	csCreateName = csFileName + "\\Log\\";
	DirectoryCreate(csCreateName);

	csCreateName = csCreateName + csYear + "\\";
	DirectoryCreate(csCreateName);

	csCreateName = csCreateName + csMonth + "\\";
	DirectoryCreate(csCreateName);

	csCreateName = csCreateName + csDay + "\\";
	DirectoryCreate(csCreateName);
}

void CDlg_Init::InitMotionDevices()
{
	/*
	CString csFileName;
	csFileName = GetRunDirectory();
	csFileName = csFileName + "\\Motion.cme2" ;

	if(cmmGnInitFromFile(csFileName) != cmERR_NONE){
		cmmErrShowLast(NULL); // 에러 발생하였으면 에러 디스플레이.
	}
	else
	{
		////////////////////////////////////////////////////////////////////////////////////////
		// CME 파일에서 정의한 축수와 실제 장착되어 있는 모션 축수를 비교확인 하고자할 때는 
		// 아래와 같이 하면 됩니다.
		
		
		long nNumAxes_installed;
		cmmAdvGetNumAvailAxes(&nNumAxes_installed); // 현재 실제로 PC에 장착되어 있는 모션축 수 (cmmGnDeviceLoad() 함수에서 반환하는 축수와 동일)
	}
	*/
}