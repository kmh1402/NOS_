// Dlg_JogS.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_JogS.h"
#include "VarEx.h"
//#include "Cmmsdk.h"
#include "FuncEx.h"
#include "Dlg_Calc.h"

// CDlg_JogS ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlg_JogS, CDialog)

CDlg_JogS::CDlg_JogS(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_JogS::IDD, pParent)
{

}

CDlg_JogS::~CDlg_JogS()
{
}

void CDlg_JogS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_JOG_DIST, m_Jog_Dist);
	DDX_Control(pDX, IDC_DIST50, m_Dist_50);
	DDX_Control(pDX, IDC_DIST100, m_Dist_100);
	DDX_Control(pDX, IDC_DIST500, m_Dist_500);
	DDX_Control(pDX, IDC_DIST1000, m_Dist_1000);
	DDX_Control(pDX, IDC_DIST5000, m_Dist_5000);
	DDX_Control(pDX, IDC_DIST10000, m_Dist_10000);
}


BEGIN_MESSAGE_MAP(CDlg_JogS, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlg_JogS �޽��� ó�����Դϴ�.

BOOL CDlg_JogS::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	glJogPos = 1000;
	Display();
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlg_JogS::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	delete this;
	CDialog::PostNcDestroy();
}

BOOL CDlg_JogS::DestroyWindow()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CDialog::DestroyWindow();
}
BEGIN_EVENTSINK_MAP(CDlg_JogS, CDialog)
	ON_EVENT(CDlg_JogS, IDC_JOG_MOVE_LEFT, DISPID_CLICK, CDlg_JogS::ClickJogMoveLeft, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_JOG_MOVE_RIGHT, DISPID_CLICK, CDlg_JogS::ClickJogMoveRight, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_JOG_Y_UP5, DISPID_CLICK, CDlg_JogS::ClickJogYUp5, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_JOG_Y_DOWN, DISPID_CLICK, CDlg_JogS::ClickJogYDown, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_JOG_Z_UP, DISPID_CLICK, CDlg_JogS::ClickJogZUp, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_JOG_Z_DOWN, DISPID_CLICK, CDlg_JogS::ClickJogZDown, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_DIST50, DISPID_CLICK, CDlg_JogS::ClickDist50, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_DIST100, DISPID_CLICK, CDlg_JogS::ClickDist100, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_DIST500, DISPID_CLICK, CDlg_JogS::ClickDist500, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_DIST1000, DISPID_CLICK, CDlg_JogS::ClickDist1000, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_DIST5000, DISPID_CLICK, CDlg_JogS::ClickDist5000, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_DIST10000, DISPID_CLICK, CDlg_JogS::ClickDist10000, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_JOG_DIST, DISPID_DBLCLICK, CDlg_JogS::DblClickCamX, VTS_NONE)
	ON_EVENT(CDlg_JogS, IDC_OK_BTN, DISPID_CLICK, CDlg_JogS::ClickOkBtn, VTS_NONE)
END_EVENTSINK_MAP()

void CDlg_JogS::ClickJogMoveLeft()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxMove(M_X1, -glJogPos, cmFALSE);
}

void CDlg_JogS::ClickJogMoveRight()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxMove(M_X1, glJogPos, cmFALSE);
}

void CDlg_JogS::ClickJogYUp5()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxMove(M_Y1, -glJogPos, cmFALSE);
}

void CDlg_JogS::ClickJogYDown()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxMove(M_Y1, glJogPos, cmFALSE);
}

void CDlg_JogS::ClickJogZUp()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxMove(M_Z1, -glJogPos, cmFALSE);
}

void CDlg_JogS::ClickJogZDown()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//cmmSxMove(M_Z1, glJogPos, cmFALSE);
}

void CDlg_JogS::ClickDist50()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	glJogPos = 50;
	Display();
}

void CDlg_JogS::ClickDist100()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	glJogPos = 100;
	Display();
}

void CDlg_JogS::ClickDist500()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	glJogPos = 500;
	Display();
}

void CDlg_JogS::ClickDist1000()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	glJogPos = 1000;
	Display();
}

void CDlg_JogS::ClickDist5000()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	glJogPos = 5000;
	Display();
}

void CDlg_JogS::ClickDist10000()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	glJogPos = 10000;
	Display();
}

void CDlg_JogS::DblClickCamX()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CString sData;
	CString csData;
	sData = m_Jog_Dist.GetCaption();
	csData = CalcCall(sData);
	m_Jog_Dist.SetCaption(csData) ;
	glJogPos = atol(csData);
}

void CDlg_JogS::ClickOkBtn()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	DestroyWindow();
}

void CDlg_JogS::Display()
{
	CString csData;
	if(glJogPos == 50)
	{
		m_Dist_50.SetBackColor(RGB(0,250,0));
		m_Dist_100.SetBackColor(RGB(0,0,0));
		m_Dist_500.SetBackColor(RGB(0,0,0));
		m_Dist_1000.SetBackColor(RGB(0,0,0));
		m_Dist_5000.SetBackColor(RGB(0,0,0));
		m_Dist_10000.SetBackColor(RGB(0,0,0));
	}
	else if(glJogPos == 100)
	{
		m_Dist_50.SetBackColor(RGB(0,0,0));
		m_Dist_100.SetBackColor(RGB(0,250,0));
		m_Dist_500.SetBackColor(RGB(0,0,0));
		m_Dist_1000.SetBackColor(RGB(0,0,0));
		m_Dist_5000.SetBackColor(RGB(0,0,0));
		m_Dist_10000.SetBackColor(RGB(0,0,0));
	}
	else if(glJogPos == 500)
	{
		m_Dist_50.SetBackColor(RGB(0,0,0));
		m_Dist_100.SetBackColor(RGB(0,0,0));
		m_Dist_500.SetBackColor(RGB(0,250,0));
		m_Dist_1000.SetBackColor(RGB(0,0,0));
		m_Dist_5000.SetBackColor(RGB(0,0,0));
		m_Dist_10000.SetBackColor(RGB(0,0,0));
	}
	else if(glJogPos == 1000)
	{
		m_Dist_50.SetBackColor(RGB(0,0,0));
		m_Dist_100.SetBackColor(RGB(0,0,0));
		m_Dist_500.SetBackColor(RGB(0,0,0));
		m_Dist_1000.SetBackColor(RGB(0,250,0));
		m_Dist_5000.SetBackColor(RGB(0,0,0));
		m_Dist_10000.SetBackColor(RGB(0,0,0));
	}
	else if(glJogPos == 5000)
	{
		m_Dist_50.SetBackColor(RGB(0,0,0));
		m_Dist_100.SetBackColor(RGB(0,0,0));
		m_Dist_500.SetBackColor(RGB(0,0,0));
		m_Dist_1000.SetBackColor(RGB(0,0,0));
		m_Dist_5000.SetBackColor(RGB(0,250,0));
		m_Dist_10000.SetBackColor(RGB(0,0,0));
	}
	else if(glJogPos == 10000)
	{
		m_Dist_50.SetBackColor(RGB(0,0,0));
		m_Dist_100.SetBackColor(RGB(0,0,0));
		m_Dist_500.SetBackColor(RGB(0,0,0));
		m_Dist_1000.SetBackColor(RGB(0,0,0));
		m_Dist_5000.SetBackColor(RGB(0,0,0));
		m_Dist_10000.SetBackColor(RGB(0,250,0));
	}

	csData.Format("%d", glJogPos);
	m_Jog_Dist.SetCaption(csData);
}

CString CDlg_JogS::CalcCall(CString BeforData)
{
	CDlg_Calc dlg ;
	dlg.m_OldValue = BeforData ;

	if(BeforData=="0")  dlg.m_NewValue="" ;
	else                dlg.m_NewValue = BeforData ;
	if(dlg.DoModal()!=IDOK) return BeforData;
	
	return  dlg.m_NewValue ;   
}
void CDlg_JogS::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialog::OnTimer(nIDEvent);
}
