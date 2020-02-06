// Dlg_Calc.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_Calc.h"
#include "math.h"
#include "VarEx.h"


// CDlg_Calc 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_Calc, CDialog)

CDlg_Calc::CDlg_Calc(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Calc::IDD, pParent)
{

}

CDlg_Calc::~CDlg_Calc()
{
}

void CDlg_Calc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NEW_VALUE, m_New_Value);
	DDX_Control(pDX, IDC_OLD_VALUE, m_Old_Value);
}


BEGIN_MESSAGE_MAP(CDlg_Calc, CDialog)
END_MESSAGE_MAP()


// CDlg_Calc 메시지 처리기입니다.
BEGIN_EVENTSINK_MAP(CDlg_Calc, CDialog)
	ON_EVENT(CDlg_Calc, IDC_NUM1, DISPID_CLICK, CDlg_Calc::ClickNum1, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_NUM2, DISPID_CLICK, CDlg_Calc::ClickNum2, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_NUM3, DISPID_CLICK, CDlg_Calc::ClickNum3, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_NUM4, DISPID_CLICK, CDlg_Calc::ClickNum4, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_NUM5, DISPID_CLICK, CDlg_Calc::ClickNum5, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_NUM6, DISPID_CLICK, CDlg_Calc::ClickNum6, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_NUM7, DISPID_CLICK, CDlg_Calc::ClickNum7, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_NUM8, DISPID_CLICK, CDlg_Calc::ClickNum8, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_NUM9, DISPID_CLICK, CDlg_Calc::ClickNum9, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_NUM10, DISPID_CLICK, CDlg_Calc::ClickNum10, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_DOT_BTN, DISPID_CLICK, CDlg_Calc::ClickDotBtn, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_BUHO_BTN, DISPID_CLICK, CDlg_Calc::ClickBuhoBtn, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_BACK_SPACE, DISPID_CLICK, CDlg_Calc::ClickBackSpace, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_PLUS_BTN, DISPID_CLICK, CDlg_Calc::ClickPlusBtn, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_CLEAR_BTN, DISPID_CLICK, CDlg_Calc::ClickClearBtn, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_SUB_BTN, DISPID_CLICK, CDlg_Calc::ClickSubBtn, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_DIV_BTN, DISPID_CLICK, CDlg_Calc::ClickDivBtn, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_MUL_BTN, DISPID_CLICK, CDlg_Calc::ClickMulBtn, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_EQUAL_BTN, DISPID_CLICK, CDlg_Calc::ClickEqualBtn, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_OK_BTN, DISPID_CLICK, CDlg_Calc::ClickOkBtn, VTS_NONE)
	ON_EVENT(CDlg_Calc, IDC_CANCEL_BTN, DISPID_CLICK, CDlg_Calc::ClickCancelBtn, VTS_NONE)
END_EVENTSINK_MAP()

void CDlg_Calc::ClickNum1()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nStatus;
	nStatus = LimitNum();
	if(nStatus == -1)
	{
		return;
	}

	if(bNewValueFlag == true)	{
		m_New_Value.SetCaption("");
		bNewValueFlag = false;
	}
	bNewValueIn = true;
	CString sData ;
	sData = m_New_Value.GetCaption() ;
	sData = sData +"1" ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickNum2()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nStatus;
	nStatus = LimitNum();
	if(nStatus == -1)
	{
		return;
	}

	if(bNewValueFlag == true)	{
		m_New_Value.SetCaption("");
		bNewValueFlag = false;
	}
	bNewValueIn = true;
	CString sData ;
	sData = m_New_Value.GetCaption() ;
	sData = sData +"2" ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickNum3()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nStatus;
	nStatus = LimitNum();
	if(nStatus == -1)
	{
		return;
	}

	if(bNewValueFlag == true)	{
		m_New_Value.SetCaption("");
		bNewValueFlag = false;
	}
	bNewValueIn = true;
	CString sData ;
	sData = m_New_Value.GetCaption() ;
	sData = sData +"3" ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickNum4()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nStatus;
	nStatus = LimitNum();
	if(nStatus == -1)
	{
		return;
	}


	if(bNewValueFlag == true)	{
		m_New_Value.SetCaption("");
		bNewValueFlag = false;
	}
	bNewValueIn = true;
	CString sData ;
	sData = m_New_Value.GetCaption() ;
	sData = sData +"4" ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickNum5()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nStatus;
	nStatus = LimitNum();
	if(nStatus == -1)
	{
		return;
	}

	if(bNewValueFlag == true)	{
		m_New_Value.SetCaption("");
		bNewValueFlag = false;
	}
	bNewValueIn = true;
	CString sData ;
	sData = m_New_Value.GetCaption() ;
	sData = sData +"5" ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickNum6()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nStatus;
	nStatus = LimitNum();
	if(nStatus == -1)
	{
		return;
	}

	if(bNewValueFlag == true)	{
		m_New_Value.SetCaption("");
		bNewValueFlag = false;
	}
	bNewValueIn = true;
	CString sData ;
	sData = m_New_Value.GetCaption() ;
	sData = sData +"6" ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickNum7()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nStatus;
	nStatus = LimitNum();
	if(nStatus == -1)
	{
		return;
	}

	if(bNewValueFlag == true)	{
		m_New_Value.SetCaption("");
		bNewValueFlag = false;
	}
	bNewValueIn = true;
	CString sData ;
	sData = m_New_Value.GetCaption() ;
	sData = sData +"7" ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickNum8()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nStatus;
	nStatus = LimitNum();
	if(nStatus == -1)
	{
		return;
	}

	if(bNewValueFlag == true)	{
		m_New_Value.SetCaption("");
		bNewValueFlag = false;
	}
	bNewValueIn = true;
	CString sData ;
	sData = m_New_Value.GetCaption() ;
	sData = sData +"8" ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickNum9()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nStatus;
	nStatus = LimitNum();
	if(nStatus == -1)
	{
		return;
	}

	if(bNewValueFlag == true)	{
		m_New_Value.SetCaption("");
		bNewValueFlag = false;
	}
	bNewValueIn = true;
	CString sData ;
	sData = m_New_Value.GetCaption() ;
	sData = sData +"9" ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickNum10()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nStatus;
	nStatus = LimitNum();
	if(nStatus == -1)
	{
		return;
	}

	if(bNewValueFlag == true)	{
		m_New_Value.SetCaption("");
		bNewValueFlag = false;
	}
	bNewValueIn = true;
	CString sData ;
	sData = m_New_Value.GetCaption() ;
	sData = sData +"0" ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickDotBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nStatus;
	nStatus = LimitNum();
	if(nStatus == -1)
	{
		return;
	}

	if(bNewValueFlag == true)	{
		m_New_Value.SetCaption("");
		bNewValueFlag = false;
	}
	bNewValueIn = true;
	CString sData ;
	sData = m_New_Value.GetCaption() ;
	sData = sData +"." ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickBuhoBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	double  DTemp ;
	CString sData ;
	sData = m_New_Value.GetCaption() ;

	DTemp = atof(sData);
	if(sData=="")  sData= "0" ;
	DTemp = atof(sData) ;
	DTemp = fabs(DTemp) ;
	DTemp = DTemp*-1 ;
	//sData.Format("%13.2f",DTemp) ;
	sData.Format("%10.3f",DTemp) ;
	m_New_Value.SetCaption(sData) ;
}

void CDlg_Calc::ClickBackSpace()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int   nCnt ;
	CString  sData ;

	sData=m_New_Value.GetCaption() ;
	if(sData=="") return ;
	
	nCnt=strlen(sData) ;
    CString s( _T(sData)) ;
	m_New_Value.SetCaption(s.Left(nCnt-1)) ;
}

void CDlg_Calc::ClickPlusBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	double DTemp;
	CString sData ;
	
	sData = m_New_Value.GetCaption() ;
	if(sData=="")  sData= "0" ;
	DTemp = atof(sData) ;
	//dOldCalData = DTemp + dOldCalData;
	dOldCalData = DTemp;
	bNewValueFlag = true;
	iCalVal = 1;
	bNewValueIn = false;
}

void CDlg_Calc::ClickClearBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_New_Value.SetCaption("");	
}

void CDlg_Calc::ClickSubBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	double DTemp;
	CString sData ;
	
	sData = m_New_Value.GetCaption() ;
	if(sData=="")  sData= "0" ;
	DTemp = atof(sData) ;
	//dOldCalData = DTemp - dOldCalData;
	dOldCalData = DTemp;
	bNewValueFlag = true;
	iCalVal = 2;
	bNewValueIn = false;
}

void CDlg_Calc::ClickDivBtn()	
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	double DTemp;
	CString sData ;
	
	sData = m_New_Value.GetCaption() ;
	if(sData=="")  sData= "0" ;
	DTemp = atof(sData) ;
	//dOldCalData = DTemp / dOldCalData;
	dOldCalData = DTemp;
	bNewValueFlag = true;
	iCalVal = 4;
	bNewValueIn = false;
}

void CDlg_Calc::ClickMulBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	double DTemp;
	CString sData ;
	
	sData = m_New_Value.GetCaption() ;
	if(sData=="")  sData= "0" ;
	DTemp = atof(sData) ;
	//dOldCalData = DTemp * dOldCalData;
	dOldCalData = DTemp;
	bNewValueFlag = true;
	iCalVal = 3;
	bNewValueIn = false;
}

void CDlg_Calc::ClickEqualBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	double DTemp;
	CString sData ;

	sData = m_New_Value.GetCaption() ;
	if(sData=="")  sData= "0" ;
	DTemp = atof(sData) ;
	
	if(bNewValueIn == true)	{
		switch(iCalVal)	{
		case 0:
			dOldCalData = DTemp;
			break;

		case 1:
			dOldCalData = dOldCalData + DTemp;
			break;

		case 2:
			dOldCalData = dOldCalData - DTemp;
			break;

		case 3:
			dOldCalData = dOldCalData * DTemp;
			break;

		case 4:
			dOldCalData = dOldCalData / DTemp;
			break;
		}
	}
	else	{
		dOldCalData = DTemp;
	}
		
	iCalVal = 0;
	sData.Format("%10.0f",dOldCalData) ;
	m_New_Value.SetCaption(sData) ;

	m_New_Value.SetCaption(sData) ;
	dOldCalData = 0;
	bNewValueFlag = true;
}

void CDlg_Calc::ClickOkBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString sData ;

	sData = m_New_Value.GetCaption() ;
	if(sData=="")	{
		sData= "0" ;
	}
	
	m_New_Value.SetCaption(sData) ;

	m_NewValue = m_New_Value.GetCaption() ;
	
	OnOK();
}

void CDlg_Calc::ClickCancelBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	OnOK();
}
int CDlg_Calc::LimitNum()
{
	CString csData;
	int nLength;
	csData = m_New_Value.GetCaption() ;
	nLength = csData.GetLength();
	if(nLength < 11)
	{
		return 1;
	}

	return -1;
}

BOOL CDlg_Calc::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_New_Value.SetCaption(0) ;
	dOldCalData=0;
	bNewValueFlag = true;
	bNewValueIn = false;
	iCalVal = 0;
	m_Old_Value.SetCaption(m_OldValue);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
