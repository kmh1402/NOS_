// Dlg_LogIN.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_LogIN.h"
#include "Dlg_PW.h"
#include "FuncEx.h"
#include "VarEx.h"

// CDlg_LogIN 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_LogIN, CDialog)

CDlg_LogIN::CDlg_LogIN(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_LogIN::IDD, pParent)
{
	m_EdtPW = _T("");
}

CDlg_LogIN::~CDlg_LogIN()
{
}

void CDlg_LogIN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PW, m_EdtPW);
	DDX_Control(pDX, IDC_LIST, m_List);
}


BEGIN_MESSAGE_MAP(CDlg_LogIN, CDialog)
	
END_MESSAGE_MAP()


// CDlg_LogIN 메시지 처리기입니다.
BOOL CDlg_LogIN::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	m_csPW = "";
	m_nCnt = 0;
		
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
BEGIN_EVENTSINK_MAP(CDlg_LogIN, CDialog)
	ON_EVENT(CDlg_LogIN, IDC_PW1, DISPID_CLICK, CDlg_LogIN::ClickPw1, VTS_NONE)
	ON_EVENT(CDlg_LogIN, IDC_PW2, DISPID_CLICK, CDlg_LogIN::ClickPw2, VTS_NONE)
	ON_EVENT(CDlg_LogIN, IDC_PW3, DISPID_CLICK, CDlg_LogIN::ClickPw3, VTS_NONE)
	ON_EVENT(CDlg_LogIN, IDC_PW4, DISPID_CLICK, CDlg_LogIN::ClickPw4, VTS_NONE)
	ON_EVENT(CDlg_LogIN, IDC_PW5, DISPID_CLICK, CDlg_LogIN::ClickPw5, VTS_NONE)
	ON_EVENT(CDlg_LogIN, IDC_PW6, DISPID_CLICK, CDlg_LogIN::ClickPw6, VTS_NONE)
	ON_EVENT(CDlg_LogIN, IDC_PW7, DISPID_CLICK, CDlg_LogIN::ClickPw7, VTS_NONE)
	ON_EVENT(CDlg_LogIN, IDC_PW8, DISPID_CLICK, CDlg_LogIN::ClickPw8, VTS_NONE)
	ON_EVENT(CDlg_LogIN, IDC_PW9, DISPID_CLICK, CDlg_LogIN::ClickPw9, VTS_NONE)
	ON_EVENT(CDlg_LogIN, IDC_PW0, DISPID_CLICK, CDlg_LogIN::ClickPw0, VTS_NONE)
	ON_EVENT(CDlg_LogIN, IDC_PW_CHANGE, DISPID_CLICK, CDlg_LogIN::ClickPwChange, VTS_NONE)
	ON_EVENT(CDlg_LogIN, IDC_OK_BTN, DISPID_CLICK, CDlg_LogIN::ClickOkBtn, VTS_NONE)
END_EVENTSINK_MAP()

void CDlg_LogIN::ClickPw1()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	m_csPW = m_csPW + "1";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password가 맞는지 틀린지 처리한다 
		//맞으면 다이얼로그를 닫고 넘어 갈수있도록 
		if(m_csPW == gcsNewPW) // 맞으면 
		{
			gbPWFail = false; 
			OnOK();
		}
		else
		{
			AfxMessageBox("Password Fail");
			gbPWFail = true;
			m_EdtPW = "";
			m_csPW = "";
			UpdateData(FALSE);
			m_nCnt = 0;
		}
	}
}

void CDlg_LogIN::ClickPw2()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	m_csPW = m_csPW + "2";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password가 맞는지 틀린지 처리한다 
		//맞으면 다이얼로그를 닫고 넘어 갈수있도록 
		if(m_csPW == gcsNewPW) // 맞으면 
		{
			gbPWFail = false; 
			OnOK();
		}
		else
		{
			AfxMessageBox("Password Fail");
			gbPWFail = true;
			m_EdtPW = "";
			m_csPW = "";
			UpdateData(FALSE);
			m_nCnt = 0;
		}
	}
}

void CDlg_LogIN::ClickPw3()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	m_csPW = m_csPW + "3";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password가 맞는지 틀린지 처리한다 
		//맞으면 다이얼로그를 닫고 넘어 갈수있도록 
		if(m_csPW == gcsNewPW) // 맞으면 
		{
			gbPWFail = false; 
			OnOK();
		}
		else
		{
			AfxMessageBox("Password Fail");
			gbPWFail = true;
			m_EdtPW = "";
			m_csPW = "";
			UpdateData(FALSE);
			m_nCnt = 0;
		}
	}
}

void CDlg_LogIN::ClickPw4()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	m_csPW = m_csPW + "4";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password가 맞는지 틀린지 처리한다 
		//맞으면 다이얼로그를 닫고 넘어 갈수있도록 
		if(m_csPW == gcsNewPW) // 맞으면 
		{
			gbPWFail = false; 
			OnOK();
		}
		else
		{
			AfxMessageBox("Password Fail");
			gbPWFail = true;
			m_EdtPW = "";
			m_csPW = "";
			UpdateData(FALSE);
			m_nCnt = 0;
		}
	}
}

void CDlg_LogIN::ClickPw5()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	m_csPW = m_csPW + "5";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password가 맞는지 틀린지 처리한다 
		//맞으면 다이얼로그를 닫고 넘어 갈수있도록 
		if(m_csPW == gcsNewPW) // 맞으면 
		{
			gbPWFail = false; 
			OnOK();
		}
		else
		{
			AfxMessageBox("Password Fail");
			gbPWFail = true;
			m_EdtPW = "";
			m_csPW = "";
			UpdateData(FALSE);
			m_nCnt = 0;
		}
	}
}

void CDlg_LogIN::ClickPw6()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	m_csPW = m_csPW + "6";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password가 맞는지 틀린지 처리한다 
		//맞으면 다이얼로그를 닫고 넘어 갈수있도록 
		if(m_csPW == gcsNewPW) // 맞으면 
		{
			gbPWFail = false; 
			OnOK();
		}
		else
		{
			AfxMessageBox("Password Fail");
			gbPWFail = true;
			m_EdtPW = "";
			m_csPW = "";
			UpdateData(FALSE);
			m_nCnt = 0;
		}
	}
}

void CDlg_LogIN::ClickPw7()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	m_csPW = m_csPW + "7";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password가 맞는지 틀린지 처리한다 
		//맞으면 다이얼로그를 닫고 넘어 갈수있도록 
		if(m_csPW == gcsNewPW) // 맞으면 
		{
			gbPWFail = false; 
			OnOK();
		}
		else
		{
			AfxMessageBox("Password Fail");
			gbPWFail = true;
			m_EdtPW = "";
			m_csPW = "";
			UpdateData(FALSE);
			m_nCnt = 0;
		}
	}
}

void CDlg_LogIN::ClickPw8()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	m_csPW = m_csPW + "8";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password가 맞는지 틀린지 처리한다 
		//맞으면 다이얼로그를 닫고 넘어 갈수있도록 
		if(m_csPW == gcsNewPW) // 맞으면 
		{
			gbPWFail = false; 
			OnOK();
		}
		else
		{
			AfxMessageBox("Password Fail");
			gbPWFail = true;
			m_EdtPW = "";
			m_csPW = "";
			UpdateData(FALSE);
			m_nCnt = 0;
		}
	}
}

void CDlg_LogIN::ClickPw9()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	m_csPW = m_csPW + "9";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password가 맞는지 틀린지 처리한다 
		//맞으면 다이얼로그를 닫고 넘어 갈수있도록 
		if(m_csPW == gcsNewPW) // 맞으면 
		{
			gbPWFail = false; 
			OnOK();
		}
		else
		{
			AfxMessageBox("Password Fail");
			gbPWFail = true;
			m_EdtPW = "";
			m_csPW = "";
			UpdateData(FALSE);
			m_nCnt = 0;
		}
	}
}

void CDlg_LogIN::ClickPw0()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	m_csPW = m_csPW + "0";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password가 맞는지 틀린지 처리한다 
		//맞으면 다이얼로그를 닫고 넘어 갈수있도록 
		if(m_csPW == gcsNewPW) // 맞으면 
		{
			gbPWFail = false; 
			OnOK();
		}
		else
		{
			AfxMessageBox("Password Fail");
			gbPWFail = true;
			m_EdtPW = "";
			m_csPW = "";
			UpdateData(FALSE);
			m_nCnt = 0;
		}
	}
}

void CDlg_LogIN::ClickPwChange()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CDlg_PW Dlg;
	Dlg.DoModal();
}

void CDlg_LogIN::ClickOkBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	gbPWFail = true;
	OnOK();
}
