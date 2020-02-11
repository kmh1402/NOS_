// Dlg_Skip3.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_Skip3.h"
#include "VarEx.h"
#include "FuncEx.h"


// CDlg_Skip3 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_Skip3, CDialog)

CDlg_Skip3::CDlg_Skip3(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Skip3::IDD, pParent)
{

}

CDlg_Skip3::~CDlg_Skip3()
{
}

void CDlg_Skip3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_Skip3, CDialog)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlg_Skip3 메시지 처리기입니다.

BOOL CDlg_Skip3::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetTimer(1,100,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlg_Skip3::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	delete this;
	CDialog::PostNcDestroy();
}

BOOL CDlg_Skip3::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialog::DestroyWindow();
}

void CDlg_Skip3::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nX = 0;
	int nY = 0;
	nX = ((point.x - 76) / 72);
	nY = ((point.y - 81) / 49);
	
	if(gnSkip3[nX][nY] == UNIT_IN)
	{
		gnSkip3[nX][nY] = UNIT_OUT;
	}
	else
	{
		gnSkip3[nX][nY] = UNIT_IN;
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CDlg_Skip3::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(nIDEvent == 1)
	{	
		CDC* pDC;
		pDC = GetDC();
		Rect1(pDC);
		ReleaseDC(pDC);
	}
	CDialog::OnTimer(nIDEvent);
}

void CDlg_Skip3::Rect1(CDC* pDC)
{
	int nX = 0;
	int nY = 0;
	int nOffSetX = 0;
	int nOffSetY = 0;
	int nJ = 0;
	int nI = 0;
	int nXPos = 0;
	int nYPos = 0;

	bool bChange = 0;
	int nConvX;
	int nStatus;
	CString csData;

	CPen myPen;
	CPen* pOldPen;
	
	myPen.CreatePen(0,1, RGB(0,0,0));
	pOldPen = pDC->SelectObject(&myPen);

	nOffSetX = 70;
	nOffSetY = 47;

	nX = 76;
	nY = 81;

	for(int nK = 0; nK < gnJigYCnt; nK ++)
	{
		for(int nL = 0; nL < gnJigXCnt; nL ++)
		{
			//Dir_Convert(nX, &nConvX);//오른족에서 부터 0으로 시작할경우
			nConvX = nL;//왼쪽에서 부터 0 으로 시작할경우 
			nXPos = nX + (nOffSetX * nL) + (2 * nL);
			nYPos = nY + (nOffSetY * nK) + (2 * nK);
			
			
			nStatus = gnSkip3[nL][nK];
				
			if(nStatus == UNIT_IN)
			{
				pDC->FillSolidRect(nXPos, nYPos, nOffSetX, nOffSetY,RGB(255,255,220));
			}
			else if(nStatus == UNIT_OUT)
			{
				pDC->FillSolidRect(nXPos, nYPos, nOffSetX, nOffSetY,RGB(50,50,50));
			}		
		}
	}

	myPen.DeleteObject();
	pOldPen->DeleteObject();
}BEGIN_EVENTSINK_MAP(CDlg_Skip3, CDialog)
ON_EVENT(CDlg_Skip3, IDC_OK_BTN, DISPID_CLICK, CDlg_Skip3::ClickOkBtn, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X1, DISPID_CLICK, CDlg_Skip3::ClickSkipX1, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X2, DISPID_CLICK, CDlg_Skip3::ClickSkipX2, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X3, DISPID_CLICK, CDlg_Skip3::ClickSkipX3, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X6, DISPID_CLICK, CDlg_Skip3::ClickSkipX6, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X7, DISPID_CLICK, CDlg_Skip3::ClickSkipX7, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X8, DISPID_CLICK, CDlg_Skip3::ClickSkipX8, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X9, DISPID_CLICK, CDlg_Skip3::ClickSkipX9, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X10, DISPID_CLICK, CDlg_Skip3::ClickSkipX10, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X11, DISPID_CLICK, CDlg_Skip3::ClickSkipX11, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X4, DISPID_CLICK, CDlg_Skip3::ClickSkipX4, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_Y1, DISPID_CLICK, CDlg_Skip3::ClickSkipY1, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_Y2, DISPID_CLICK, CDlg_Skip3::ClickSkipY2, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_Y3, DISPID_CLICK, CDlg_Skip3::ClickSkipY3, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_Y4, DISPID_CLICK, CDlg_Skip3::ClickSkipY4, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_Y5, DISPID_CLICK, CDlg_Skip3::ClickSkipY5, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_Y6, DISPID_CLICK, CDlg_Skip3::ClickSkipY6, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_Y7, DISPID_CLICK, CDlg_Skip3::ClickSkipY7, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_Y8, DISPID_CLICK, CDlg_Skip3::ClickSkipY8, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_Y9, DISPID_CLICK, CDlg_Skip3::ClickSkipY9, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_Y10, DISPID_CLICK, CDlg_Skip3::ClickSkipY10, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X12, DISPID_CLICK, CDlg_Skip3::ClickSkipX12, VTS_NONE)
ON_EVENT(CDlg_Skip3, IDC_SKIP_X13, DISPID_CLICK, CDlg_Skip3::ClickSkipX13, VTS_NONE)
END_EVENTSINK_MAP()

void CDlg_Skip3::ClickOkBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	DataSave();
	DestroyWindow();
}

void CDlg_Skip3::DataSave()
{
	CString csFileName;
	CString csRet;
	CString csData;
	
	csFileName = "d:\\NOS\\NOS";
	csFileName = csFileName + "\\Setting\\";
	csFileName = csFileName + gcsModelName;
	csFileName = csFileName + ".txt" ;
	
	for(int nY = 0; nY < 10; nY++)
	{
		for(int nX = 0; nX < 10; nX++)
		{
			csData.Format("X%d Y%d", nX, nY);
			csRet.Format("%d", gnSkip3[nX][nY]);
			WritePrivateProfileString("SKIP3", csData, csRet, csFileName);
		}
	}
}
void CDlg_Skip3::ClickSkipX1()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bX1 == false)
	{
		m_bX1 = true;
		gnSkip3[0][0] = UNIT_IN;
		gnSkip3[1][0] = UNIT_IN;
		gnSkip3[2][0] = UNIT_IN;
		gnSkip3[3][0] = UNIT_IN;
		gnSkip3[4][0] = UNIT_IN;
		gnSkip3[5][0] = UNIT_IN;
		gnSkip3[6][0] = UNIT_IN;
		gnSkip3[7][0] = UNIT_IN;
		gnSkip3[8][0] = UNIT_IN;
		gnSkip3[9][0] = UNIT_IN;	
	}
	else
	{
		m_bX1 = false;
		gnSkip3[0][0] = UNIT_OUT;
		gnSkip3[1][0] = UNIT_OUT;
		gnSkip3[2][0] = UNIT_OUT;
		gnSkip3[3][0] = UNIT_OUT;
		gnSkip3[4][0] = UNIT_OUT;
		gnSkip3[5][0] = UNIT_OUT;
		gnSkip3[6][0] = UNIT_OUT;
		gnSkip3[7][0] = UNIT_OUT;
		gnSkip3[8][0] = UNIT_OUT;
		gnSkip3[9][0] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipX2()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bX2 == false)
	{
		m_bX2 = true;
		gnSkip3[0][1] = UNIT_IN;
		gnSkip3[1][1] = UNIT_IN;
		gnSkip3[2][1] = UNIT_IN;
		gnSkip3[3][1] = UNIT_IN;
		gnSkip3[4][1] = UNIT_IN;
		gnSkip3[5][1] = UNIT_IN;
		gnSkip3[6][1] = UNIT_IN;
		gnSkip3[7][1] = UNIT_IN;
		gnSkip3[8][1] = UNIT_IN;
		gnSkip3[9][1] = UNIT_IN;	
	}
	else
	{
		m_bX2 = false;
		gnSkip3[0][1] = UNIT_OUT;
		gnSkip3[1][1] = UNIT_OUT;
		gnSkip3[2][1] = UNIT_OUT;
		gnSkip3[3][1] = UNIT_OUT;
		gnSkip3[4][1] = UNIT_OUT;
		gnSkip3[5][1] = UNIT_OUT;
		gnSkip3[6][1] = UNIT_OUT;
		gnSkip3[7][1] = UNIT_OUT;
		gnSkip3[8][1] = UNIT_OUT;
		gnSkip3[9][1] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipX3()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bX3 == false)
	{
		m_bX3 = true;
		gnSkip3[0][2] = UNIT_IN;
		gnSkip3[1][2] = UNIT_IN;
		gnSkip3[2][2] = UNIT_IN;
		gnSkip3[3][2] = UNIT_IN;
		gnSkip3[4][2] = UNIT_IN;
		gnSkip3[5][2] = UNIT_IN;
		gnSkip3[6][2] = UNIT_IN;
		gnSkip3[7][2] = UNIT_IN;
		gnSkip3[8][2] = UNIT_IN;
		gnSkip3[9][2] = UNIT_IN;	
	}
	else
	{
		m_bX3 = false;
		gnSkip3[0][2] = UNIT_OUT;
		gnSkip3[1][2] = UNIT_OUT;
		gnSkip3[2][2] = UNIT_OUT;
		gnSkip3[3][2] = UNIT_OUT;
		gnSkip3[4][2] = UNIT_OUT;
		gnSkip3[5][2] = UNIT_OUT;
		gnSkip3[6][2] = UNIT_OUT;
		gnSkip3[7][2] = UNIT_OUT;
		gnSkip3[8][2] = UNIT_OUT;
		gnSkip3[9][2] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipX4()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bX4 == false)
	{
		m_bX4 = true;
		gnSkip3[0][3] = UNIT_IN;
		gnSkip3[1][3] = UNIT_IN;
		gnSkip3[2][3] = UNIT_IN;
		gnSkip3[3][3] = UNIT_IN;
		gnSkip3[4][3] = UNIT_IN;
		gnSkip3[5][3] = UNIT_IN;
		gnSkip3[6][3] = UNIT_IN;
		gnSkip3[7][3] = UNIT_IN;
		gnSkip3[8][3] = UNIT_IN;
		gnSkip3[9][3] = UNIT_IN;	
	}
	else
	{
		m_bX4 = false;
		gnSkip3[0][3] = UNIT_OUT;
		gnSkip3[1][3] = UNIT_OUT;
		gnSkip3[2][3] = UNIT_OUT;
		gnSkip3[3][3] = UNIT_OUT;
		gnSkip3[4][3] = UNIT_OUT;
		gnSkip3[5][3] = UNIT_OUT;
		gnSkip3[6][3] = UNIT_OUT;
		gnSkip3[7][3] = UNIT_OUT;
		gnSkip3[8][3] = UNIT_OUT;
		gnSkip3[9][3] = UNIT_OUT;
	}
}


void CDlg_Skip3::ClickSkipX6()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bX5 == false)
	{
		m_bX5 = true;
		gnSkip3[0][4] = UNIT_IN;
		gnSkip3[1][4] = UNIT_IN;
		gnSkip3[2][4] = UNIT_IN;
		gnSkip3[3][4] = UNIT_IN;
		gnSkip3[4][4] = UNIT_IN;
		gnSkip3[5][4] = UNIT_IN;
		gnSkip3[6][4] = UNIT_IN;
		gnSkip3[7][4] = UNIT_IN;
		gnSkip3[8][4] = UNIT_IN;
		gnSkip3[9][4] = UNIT_IN;	
	}
	else
	{
		m_bX5 = false;
		gnSkip3[0][4] = UNIT_OUT;
		gnSkip3[1][4] = UNIT_OUT;
		gnSkip3[2][4] = UNIT_OUT;
		gnSkip3[3][4] = UNIT_OUT;
		gnSkip3[4][4] = UNIT_OUT;
		gnSkip3[5][4] = UNIT_OUT;
		gnSkip3[6][4] = UNIT_OUT;
		gnSkip3[7][4] = UNIT_OUT;
		gnSkip3[8][4] = UNIT_OUT;
		gnSkip3[9][4] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipX7()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bX6 == false)
	{
		m_bX6 = true;
		gnSkip3[0][5] = UNIT_IN;
		gnSkip3[1][5] = UNIT_IN;
		gnSkip3[2][5] = UNIT_IN;
		gnSkip3[3][5] = UNIT_IN;
		gnSkip3[4][5] = UNIT_IN;
		gnSkip3[5][5] = UNIT_IN;
		gnSkip3[6][5] = UNIT_IN;
		gnSkip3[7][5] = UNIT_IN;
		gnSkip3[8][5] = UNIT_IN;
		gnSkip3[9][5] = UNIT_IN;	
	}
	else
	{
		m_bX6 = false;
		gnSkip3[0][5] = UNIT_OUT;
		gnSkip3[1][5] = UNIT_OUT;
		gnSkip3[2][5] = UNIT_OUT;
		gnSkip3[3][5] = UNIT_OUT;
		gnSkip3[4][5] = UNIT_OUT;
		gnSkip3[5][5] = UNIT_OUT;
		gnSkip3[6][5] = UNIT_OUT;
		gnSkip3[7][5] = UNIT_OUT;
		gnSkip3[8][5] = UNIT_OUT;
		gnSkip3[9][5] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipX8()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bX7 == false)
	{
		m_bX7 = true;
		gnSkip3[0][6] = UNIT_IN;
		gnSkip3[1][6] = UNIT_IN;
		gnSkip3[2][6] = UNIT_IN;
		gnSkip3[3][6] = UNIT_IN;
		gnSkip3[4][6] = UNIT_IN;
		gnSkip3[5][6] = UNIT_IN;
		gnSkip3[6][6] = UNIT_IN;
		gnSkip3[7][6] = UNIT_IN;
		gnSkip3[8][6] = UNIT_IN;
		gnSkip3[9][6] = UNIT_IN;	
	}
	else
	{
		m_bX7 = false;
		gnSkip3[0][6] = UNIT_OUT;
		gnSkip3[1][6] = UNIT_OUT;
		gnSkip3[2][6] = UNIT_OUT;
		gnSkip3[3][6] = UNIT_OUT;
		gnSkip3[4][6] = UNIT_OUT;
		gnSkip3[5][6] = UNIT_OUT;
		gnSkip3[6][6] = UNIT_OUT;
		gnSkip3[7][6] = UNIT_OUT;
		gnSkip3[8][6] = UNIT_OUT;
		gnSkip3[9][6] = UNIT_OUT;
	}
}


void CDlg_Skip3::ClickSkipX9()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bX8 == false)
	{
		m_bX8 = true;
		gnSkip3[0][7] = UNIT_IN;
		gnSkip3[1][7] = UNIT_IN;
		gnSkip3[2][7] = UNIT_IN;
		gnSkip3[3][7] = UNIT_IN;
		gnSkip3[4][7] = UNIT_IN;
		gnSkip3[5][7] = UNIT_IN;
		gnSkip3[6][7] = UNIT_IN;
		gnSkip3[7][7] = UNIT_IN;
		gnSkip3[8][7] = UNIT_IN;
		gnSkip3[9][7] = UNIT_IN;	
	}
	else
	{
		m_bX8 = false;
		gnSkip3[0][7] = UNIT_OUT;
		gnSkip3[1][7] = UNIT_OUT;
		gnSkip3[2][7] = UNIT_OUT;
		gnSkip3[3][7] = UNIT_OUT;
		gnSkip3[4][7] = UNIT_OUT;
		gnSkip3[5][7] = UNIT_OUT;
		gnSkip3[6][7] = UNIT_OUT;
		gnSkip3[7][7] = UNIT_OUT;
		gnSkip3[8][7] = UNIT_OUT;
		gnSkip3[9][7] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipX10()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bX9 == false)
	{
		m_bX9 = true;
		gnSkip3[0][8] = UNIT_IN;
		gnSkip3[1][8] = UNIT_IN;
		gnSkip3[2][8] = UNIT_IN;
		gnSkip3[3][8] = UNIT_IN;
		gnSkip3[4][8] = UNIT_IN;
		gnSkip3[5][8] = UNIT_IN;
		gnSkip3[6][8] = UNIT_IN;
		gnSkip3[7][8] = UNIT_IN;
		gnSkip3[8][8] = UNIT_IN;
		gnSkip3[9][8] = UNIT_IN;	
	}
	else
	{
		m_bX9 = false;
		gnSkip3[0][8] = UNIT_OUT;
		gnSkip3[1][8] = UNIT_OUT;
		gnSkip3[2][8] = UNIT_OUT;
		gnSkip3[3][8] = UNIT_OUT;
		gnSkip3[4][8] = UNIT_OUT;
		gnSkip3[5][8] = UNIT_OUT;
		gnSkip3[6][8] = UNIT_OUT;
		gnSkip3[7][8] = UNIT_OUT;
		gnSkip3[8][8] = UNIT_OUT;
		gnSkip3[9][8] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipX11()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bX10 == false)
	{
		m_bX10 = true;
		gnSkip3[0][9] = UNIT_IN;
		gnSkip3[1][9] = UNIT_IN;
		gnSkip3[2][9] = UNIT_IN;
		gnSkip3[3][9] = UNIT_IN;
		gnSkip3[4][9] = UNIT_IN;
		gnSkip3[5][9] = UNIT_IN;
		gnSkip3[6][9] = UNIT_IN;
		gnSkip3[7][9] = UNIT_IN;
		gnSkip3[8][9] = UNIT_IN;
		gnSkip3[9][9] = UNIT_IN;	
	}
	else
	{
		m_bX10 = false;
		gnSkip3[0][9] = UNIT_OUT;
		gnSkip3[1][9] = UNIT_OUT;
		gnSkip3[2][9] = UNIT_OUT;
		gnSkip3[3][9] = UNIT_OUT;
		gnSkip3[4][9] = UNIT_OUT;
		gnSkip3[5][9] = UNIT_OUT;
		gnSkip3[6][9] = UNIT_OUT;
		gnSkip3[7][9] = UNIT_OUT;
		gnSkip3[8][9] = UNIT_OUT;
		gnSkip3[9][9] = UNIT_OUT;
	}
}


void CDlg_Skip3::ClickSkipY1()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bY1 == false)
	{
		m_bY1 = true;
		gnSkip3[0][0] = UNIT_IN;
		gnSkip3[0][1] = UNIT_IN;
		gnSkip3[0][2] = UNIT_IN;
		gnSkip3[0][3] = UNIT_IN;
		gnSkip3[0][4] = UNIT_IN;
		gnSkip3[0][5] = UNIT_IN;
		gnSkip3[0][6] = UNIT_IN;
		gnSkip3[0][7] = UNIT_IN;
		gnSkip3[0][8] = UNIT_IN;
		gnSkip3[0][9] = UNIT_IN;	
	}
	else
	{
		m_bY1 = false;
		gnSkip3[0][0] = UNIT_OUT;
		gnSkip3[0][1] = UNIT_OUT;
		gnSkip3[0][2] = UNIT_OUT;
		gnSkip3[0][3] = UNIT_OUT;
		gnSkip3[0][4] = UNIT_OUT;
		gnSkip3[0][5] = UNIT_OUT;
		gnSkip3[0][6] = UNIT_OUT;
		gnSkip3[0][7] = UNIT_OUT;
		gnSkip3[0][8] = UNIT_OUT;
		gnSkip3[0][9] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipY2()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bY2 == false)
	{
		m_bY2 = true;
		gnSkip3[1][0] = UNIT_IN;
		gnSkip3[1][1] = UNIT_IN;
		gnSkip3[1][2] = UNIT_IN;
		gnSkip3[1][3] = UNIT_IN;
		gnSkip3[1][4] = UNIT_IN;
		gnSkip3[1][5] = UNIT_IN;
		gnSkip3[1][6] = UNIT_IN;
		gnSkip3[1][7] = UNIT_IN;
		gnSkip3[1][8] = UNIT_IN;
		gnSkip3[1][9] = UNIT_IN;	
	}
	else
	{
		m_bY2 = false;
		gnSkip3[1][0] = UNIT_OUT;
		gnSkip3[1][1] = UNIT_OUT;
		gnSkip3[1][2] = UNIT_OUT;
		gnSkip3[1][3] = UNIT_OUT;
		gnSkip3[1][4] = UNIT_OUT;
		gnSkip3[1][5] = UNIT_OUT;
		gnSkip3[1][6] = UNIT_OUT;
		gnSkip3[1][7] = UNIT_OUT;
		gnSkip3[1][8] = UNIT_OUT;
		gnSkip3[1][9] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipY3()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bY3 == false)
	{
		m_bY3 = true;
		gnSkip3[2][0] = UNIT_IN;
		gnSkip3[2][1] = UNIT_IN;
		gnSkip3[2][2] = UNIT_IN;
		gnSkip3[2][3] = UNIT_IN;
		gnSkip3[2][4] = UNIT_IN;
		gnSkip3[2][5] = UNIT_IN;
		gnSkip3[2][6] = UNIT_IN;
		gnSkip3[2][7] = UNIT_IN;
		gnSkip3[2][8] = UNIT_IN;
		gnSkip3[2][9] = UNIT_IN;	
	}
	else
	{
		m_bY3 = false;
		gnSkip3[2][0] = UNIT_OUT;
		gnSkip3[2][1] = UNIT_OUT;
		gnSkip3[2][2] = UNIT_OUT;
		gnSkip3[2][3] = UNIT_OUT;
		gnSkip3[2][4] = UNIT_OUT;
		gnSkip3[2][5] = UNIT_OUT;
		gnSkip3[2][6] = UNIT_OUT;
		gnSkip3[2][7] = UNIT_OUT;
		gnSkip3[2][8] = UNIT_OUT;
		gnSkip3[2][9] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipY4()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bY4 == false)
	{
		m_bY4 = true;
		gnSkip3[3][0] = UNIT_IN;
		gnSkip3[3][1] = UNIT_IN;
		gnSkip3[3][2] = UNIT_IN;
		gnSkip3[3][3] = UNIT_IN;
		gnSkip3[3][4] = UNIT_IN;
		gnSkip3[3][5] = UNIT_IN;
		gnSkip3[3][6] = UNIT_IN;
		gnSkip3[3][7] = UNIT_IN;
		gnSkip3[3][8] = UNIT_IN;
		gnSkip3[3][9] = UNIT_IN;	
	}
	else
	{
		m_bY4 = false;
		gnSkip3[3][0] = UNIT_OUT;
		gnSkip3[3][1] = UNIT_OUT;
		gnSkip3[3][2] = UNIT_OUT;
		gnSkip3[3][3] = UNIT_OUT;
		gnSkip3[3][4] = UNIT_OUT;
		gnSkip3[3][5] = UNIT_OUT;
		gnSkip3[3][6] = UNIT_OUT;
		gnSkip3[3][7] = UNIT_OUT;
		gnSkip3[3][8] = UNIT_OUT;
		gnSkip3[3][9] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipY5()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bY5 == false)
	{
		m_bY5 = true;
		gnSkip3[4][0] = UNIT_IN;
		gnSkip3[4][1] = UNIT_IN;
		gnSkip3[4][2] = UNIT_IN;
		gnSkip3[4][3] = UNIT_IN;
		gnSkip3[4][4] = UNIT_IN;
		gnSkip3[4][5] = UNIT_IN;
		gnSkip3[4][6] = UNIT_IN;
		gnSkip3[4][7] = UNIT_IN;
		gnSkip3[4][8] = UNIT_IN;
		gnSkip3[4][9] = UNIT_IN;	
	}
	else
	{
		m_bY5 = false;
		gnSkip3[4][0] = UNIT_OUT;
		gnSkip3[4][1] = UNIT_OUT;
		gnSkip3[4][2] = UNIT_OUT;
		gnSkip3[4][3] = UNIT_OUT;
		gnSkip3[4][4] = UNIT_OUT;
		gnSkip3[4][5] = UNIT_OUT;
		gnSkip3[4][6] = UNIT_OUT;
		gnSkip3[4][7] = UNIT_OUT;
		gnSkip3[4][8] = UNIT_OUT;
		gnSkip3[4][9] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipY6()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bY6 == false)
	{
		m_bY6 = true;
		gnSkip3[5][0] = UNIT_IN;
		gnSkip3[5][1] = UNIT_IN;
		gnSkip3[5][2] = UNIT_IN;
		gnSkip3[5][3] = UNIT_IN;
		gnSkip3[5][4] = UNIT_IN;
		gnSkip3[5][5] = UNIT_IN;
		gnSkip3[5][6] = UNIT_IN;
		gnSkip3[5][7] = UNIT_IN;
		gnSkip3[5][8] = UNIT_IN;
		gnSkip3[5][9] = UNIT_IN;	
	}
	else
	{
		m_bY6 = false;
		gnSkip3[5][0] = UNIT_OUT;
		gnSkip3[5][1] = UNIT_OUT;
		gnSkip3[5][2] = UNIT_OUT;
		gnSkip3[5][3] = UNIT_OUT;
		gnSkip3[5][4] = UNIT_OUT;
		gnSkip3[5][5] = UNIT_OUT;
		gnSkip3[5][6] = UNIT_OUT;
		gnSkip3[5][7] = UNIT_OUT;
		gnSkip3[5][8] = UNIT_OUT;
		gnSkip3[5][9] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipY7()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bY7 == false)
	{
		m_bY7 = true;
		gnSkip3[6][0] = UNIT_IN;
		gnSkip3[6][1] = UNIT_IN;
		gnSkip3[6][2] = UNIT_IN;
		gnSkip3[6][3] = UNIT_IN;
		gnSkip3[6][4] = UNIT_IN;
		gnSkip3[6][5] = UNIT_IN;
		gnSkip3[6][6] = UNIT_IN;
		gnSkip3[6][7] = UNIT_IN;
		gnSkip3[6][8] = UNIT_IN;
		gnSkip3[6][9] = UNIT_IN;	
	}
	else
	{
		m_bY7 = false;
		gnSkip3[6][0] = UNIT_OUT;
		gnSkip3[6][1] = UNIT_OUT;
		gnSkip3[6][2] = UNIT_OUT;
		gnSkip3[6][3] = UNIT_OUT;
		gnSkip3[6][4] = UNIT_OUT;
		gnSkip3[6][5] = UNIT_OUT;
		gnSkip3[6][6] = UNIT_OUT;
		gnSkip3[6][7] = UNIT_OUT;
		gnSkip3[6][8] = UNIT_OUT;
		gnSkip3[6][9] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipY8()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bY8 == false)
	{
		m_bY8 = true;
		gnSkip3[7][0] = UNIT_IN;
		gnSkip3[7][1] = UNIT_IN;
		gnSkip3[7][2] = UNIT_IN;
		gnSkip3[7][3] = UNIT_IN;
		gnSkip3[7][4] = UNIT_IN;
		gnSkip3[7][5] = UNIT_IN;
		gnSkip3[7][6] = UNIT_IN;
		gnSkip3[7][7] = UNIT_IN;
		gnSkip3[7][8] = UNIT_IN;
		gnSkip3[7][9] = UNIT_IN;	
	}
	else
	{
		m_bY8 = false;
		gnSkip3[7][0] = UNIT_OUT;
		gnSkip3[7][1] = UNIT_OUT;
		gnSkip3[7][2] = UNIT_OUT;
		gnSkip3[7][3] = UNIT_OUT;
		gnSkip3[7][4] = UNIT_OUT;
		gnSkip3[7][5] = UNIT_OUT;
		gnSkip3[7][6] = UNIT_OUT;
		gnSkip3[7][7] = UNIT_OUT;
		gnSkip3[7][8] = UNIT_OUT;
		gnSkip3[7][9] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipY9()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bY9 == false)
	{
		m_bY9 = true;
		gnSkip3[8][0] = UNIT_IN;
		gnSkip3[8][1] = UNIT_IN;
		gnSkip3[8][2] = UNIT_IN;
		gnSkip3[8][3] = UNIT_IN;
		gnSkip3[8][4] = UNIT_IN;
		gnSkip3[8][5] = UNIT_IN;
		gnSkip3[8][6] = UNIT_IN;
		gnSkip3[8][7] = UNIT_IN;
		gnSkip3[8][8] = UNIT_IN;
		gnSkip3[8][9] = UNIT_IN;	
	}
	else
	{
		m_bY9 = false;
		gnSkip3[8][0] = UNIT_OUT;
		gnSkip3[8][1] = UNIT_OUT;
		gnSkip3[8][2] = UNIT_OUT;
		gnSkip3[8][3] = UNIT_OUT;
		gnSkip3[8][4] = UNIT_OUT;
		gnSkip3[8][5] = UNIT_OUT;
		gnSkip3[8][6] = UNIT_OUT;
		gnSkip3[8][7] = UNIT_OUT;
		gnSkip3[8][8] = UNIT_OUT;
		gnSkip3[8][9] = UNIT_OUT;
	}
}

void CDlg_Skip3::ClickSkipY10()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bY10 == false)
	{
		m_bY10 = true;
		gnSkip3[9][0] = UNIT_IN;
		gnSkip3[9][1] = UNIT_IN;
		gnSkip3[9][2] = UNIT_IN;
		gnSkip3[9][3] = UNIT_IN;
		gnSkip3[9][4] = UNIT_IN;
		gnSkip3[9][5] = UNIT_IN;
		gnSkip3[9][6] = UNIT_IN;
		gnSkip3[9][7] = UNIT_IN;
		gnSkip3[9][8] = UNIT_IN;
		gnSkip3[9][9] = UNIT_IN;	
	}
	else
	{
		m_bY10 = false;
		gnSkip3[9][0] = UNIT_OUT;
		gnSkip3[9][1] = UNIT_OUT;
		gnSkip3[9][2] = UNIT_OUT;
		gnSkip3[9][3] = UNIT_OUT;
		gnSkip3[9][4] = UNIT_OUT;
		gnSkip3[9][5] = UNIT_OUT;
		gnSkip3[9][6] = UNIT_OUT;
		gnSkip3[9][7] = UNIT_OUT;
		gnSkip3[9][8] = UNIT_OUT;
		gnSkip3[9][9] = UNIT_OUT;
	}
}
void CDlg_Skip3::ClickSkipX12()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	for(int nA = 0; nA < 10; nA++)
	{
		for(int nB = 0; nB < 10; nB++)
		{
			gnSkip3[nA][nB] = UNIT_IN;
		}
	}
}

void CDlg_Skip3::ClickSkipX13()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	for(int nA = 0; nA < 10; nA++)
	{
		for(int nB = 0; nB < 10; nB++)
		{
			gnSkip3[nA][nB] = UNIT_OUT;
		}
	}
}
