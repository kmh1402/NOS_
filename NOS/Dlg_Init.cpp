// Dlg_Init.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_Init.h"
#include "pmiMApi.h"
#include "pmiMApiDefs.h"
#include "VarEx.h"
#include "FuncEx.h"
#include "Thread.h"

// CDlg_Init ��ȭ �����Դϴ�.

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


// CDlg_Init �޽��� ó�����Դϴ�.

BOOL CDlg_Init::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_Progress.SetRange(0,100);
	m_Progress.SetPos(0);
	m_Message.SetCaption("");
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlg_Init::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	KillTimer(1) ;
	//vision Init
	int nI = 0;
	int nStatus = 0;
	int nSleep = 20;//���α׷������� ���� �ӵ��� �����Ѵ�. 
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
		// �Ķ���� ������ MotionComposer.ini ���Ͽ� Parameter_File = ��θ� �Ѿ� ����.
		iRet = pmiConParamLoad(NULL);
	}
	else
	{		
		AfxMessageBox("Motion InitFail");
	}

	pmiAxSetServoOn(0,M_X1,1);
	pmiAxSetServoOn(0,M_Y1,1);
	pmiAxSetServoOn(0,M_Z1,1);
	//��������
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
		cmmErrShowLast(NULL); // ���� �߻��Ͽ����� ���� ���÷���.
	}
	else
	{
		////////////////////////////////////////////////////////////////////////////////////////
		// CME ���Ͽ��� ������ ����� ���� �����Ǿ� �ִ� ��� ����� ��Ȯ�� �ϰ����� ���� 
		// �Ʒ��� ���� �ϸ� �˴ϴ�.
		
		
		long nNumAxes_installed;
		cmmAdvGetNumAvailAxes(&nNumAxes_installed); // ���� ������ PC�� �����Ǿ� �ִ� ����� �� (cmmGnDeviceLoad() �Լ����� ��ȯ�ϴ� ����� ����)
	}
	*/
}