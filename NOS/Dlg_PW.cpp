// Dlg_PW.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_PW.h"
#include "VarEx.h"
#include "FuncEx.h"

// CDlg_PW 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_PW, CDialog)

CDlg_PW::CDlg_PW(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_PW::IDD, pParent)
{
	m_OldPW = _T("");
	m_NewPW = _T("");
}

CDlg_PW::~CDlg_PW()
{
}

void CDlg_PW::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OLD_PW, m_OldPW);
	DDX_Text(pDX, IDC_EDIT_NEW_PW, m_NewPW);
	DDX_Control(pDX, IDC_SEL_OLDPW, m_Sel_OldPW);
	DDX_Control(pDX, IDC_SEL_NEW_PW, m_Sel_NewPW);
}


BEGIN_MESSAGE_MAP(CDlg_PW, CDialog)
END_MESSAGE_MAP()


// CDlg_PW 메시지 처리기입니다.
BOOL CDlg_PW::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
BEGIN_EVENTSINK_MAP(CDlg_PW, CDialog)
	ON_EVENT(CDlg_PW, IDC_PW1, DISPID_CLICK, CDlg_PW::ClickPw1, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_PW2, DISPID_CLICK, CDlg_PW::ClickPw2, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_PW3, DISPID_CLICK, CDlg_PW::ClickPw3, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_PW4, DISPID_CLICK, CDlg_PW::ClickPw4, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_PW5, DISPID_CLICK, CDlg_PW::ClickPw5, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_PW6, DISPID_CLICK, CDlg_PW::ClickPw6, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_PW7, DISPID_CLICK, CDlg_PW::ClickPw7, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_PW8, DISPID_CLICK, CDlg_PW::ClickPw8, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_PW9, DISPID_CLICK, CDlg_PW::ClickPw9, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_PW0, DISPID_CLICK, CDlg_PW::ClickPw0, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_SEL_OLDPW, DISPID_CLICK, CDlg_PW::ClickSelOldpw, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_SEL_NEW_PW, DISPID_CLICK, CDlg_PW::ClickSelNewPw, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_OK_BTN, DISPID_CLICK, CDlg_PW::ClickOkBtn, VTS_NONE)
	ON_EVENT(CDlg_PW, IDC_EXIT_BTN2, DISPID_CLICK, CDlg_PW::ClickExitBtn2, VTS_NONE)
END_EVENTSINK_MAP()

void CDlg_PW::ClickPw1()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bSelPW == false)
	{
		if(m_nOldCnt == 3)
		{
			m_csOld = m_csOld + "1";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;

			if(gcsNewPW == m_csOld)
			{
				return;
			}
			else
			{
				AfxMessageBox("Password Fail!!");
				m_csOld = "";
				m_nOldCnt = 0;
				m_OldPW = "";
				return;
			}
		}
		else
		{
		
			m_csOld = m_csOld + "1";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;
		}
	}
	else
	{
		if(m_nNewCnt == 4)
		{
			return;
		}
		else
		{
			m_csNew = m_csNew + "1";
			m_NewPW = m_csNew;
			UpdateData(FALSE);
			m_nNewCnt++;
		}
	}
}

void CDlg_PW::ClickPw2()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bSelPW == false)
	{
		if(m_nOldCnt == 3)
		{
			m_csOld = m_csOld + "2";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;

			if(gcsNewPW == m_csOld)
			{
				return;
			}
			else
			{
				AfxMessageBox("Password Fail!!");
				m_csOld = "";
				m_nOldCnt = 0;
				m_OldPW = "";
				return;
			}
		}
		else
		{
		
			m_csOld = m_csOld + "2";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;
		}
	}
	else
	{
		if(m_nNewCnt == 4)
		{
			return;
		}
		else
		{
			m_csNew = m_csNew + "2";
			m_NewPW = m_csNew;
			UpdateData(FALSE);
			m_nNewCnt++;
		}
	}
}

void CDlg_PW::ClickPw3()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bSelPW == false)
	{
		if(m_nOldCnt == 3)
		{
			m_csOld = m_csOld + "3";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;

			if(gcsNewPW == m_csOld)
			{
				return;
			}
			else
			{
				AfxMessageBox("Password Fail!!");
				m_csOld = "";
				m_nOldCnt = 0;
				m_OldPW = "";
				return;
			}
		}
		else
		{
		
			m_csOld = m_csOld + "3";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;
		}
	}
	else
	{
		if(m_nNewCnt == 4)
		{
			return;
		}
		else
		{
			m_csNew = m_csNew + "3";
			m_NewPW = m_csNew;
			UpdateData(FALSE);
			m_nNewCnt++;
		}
	}
}

void CDlg_PW::ClickPw4()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bSelPW == false)
	{
		if(m_nOldCnt == 3)
		{
			m_csOld = m_csOld + "4";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;

			if(gcsNewPW == m_csOld)
			{
				return;
			}
			else
			{
				AfxMessageBox("Password Fail!!");
				m_csOld = "";
				m_nOldCnt = 0;
				m_OldPW = "";
				return;
			}
		}
		else
		{
		
			m_csOld = m_csOld + "4";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;
		}
	}
	else
	{
		if(m_nNewCnt == 4)
		{
			return;
		}
		else
		{
			m_csNew = m_csNew + "4";
			m_NewPW = m_csNew;
			UpdateData(FALSE);
			m_nNewCnt++;
		}
	}
}

void CDlg_PW::ClickPw5()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bSelPW == false)
	{
		if(m_nOldCnt == 3)
		{
			m_csOld = m_csOld + "5";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;

			if(gcsNewPW == m_csOld)
			{
				return;
			}
			else
			{
				AfxMessageBox("Password Fail!!");
				m_csOld = "";
				m_nOldCnt = 0;
				m_OldPW = "";
				return;
			}
		}
		else
		{
		
			m_csOld = m_csOld + "5";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;
		}
	}
	else
	{
		if(m_nNewCnt == 4)
		{
			return;
		}
		else
		{
			m_csNew = m_csNew + "5";
			m_NewPW = m_csNew;
			UpdateData(FALSE);
			m_nNewCnt++;
		}
	}
}

void CDlg_PW::ClickPw6()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bSelPW == false)
	{
		if(m_nOldCnt == 3)
		{
			m_csOld = m_csOld + "6";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;

			if(gcsNewPW == m_csOld)
			{
				return;
			}
			else
			{
				AfxMessageBox("Password Fail!!");
				m_csOld = "";
				m_nOldCnt = 0;
				m_OldPW = "";
				return;
			}
		}
		else
		{
		
			m_csOld = m_csOld + "6";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;
		}
	}
	else
	{
		if(m_nNewCnt == 4)
		{
			return;
		}
		else
		{
			m_csNew = m_csNew + "6";
			m_NewPW = m_csNew;
			UpdateData(FALSE);
			m_nNewCnt++;
		}
	}
}

void CDlg_PW::ClickPw7()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bSelPW == false)
	{
		if(m_nOldCnt == 3)
		{
			m_csOld = m_csOld + "7";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;

			if(gcsNewPW == m_csOld)
			{
				return;
			}
			else
			{
				AfxMessageBox("Password Fail!!");
				m_csOld = "";
				m_nOldCnt = 0;
				m_OldPW = "";
				return;
			}
		}
		else
		{
		
			m_csOld = m_csOld + "7";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;
		}
	}
	else
	{
		if(m_nNewCnt == 4)
		{
			return;
		}
		else
		{
			m_csNew = m_csNew + "7";
			m_NewPW = m_csNew;
			UpdateData(FALSE);
			m_nNewCnt++;
		}
	}
}

void CDlg_PW::ClickPw8()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bSelPW == false)
	{
		if(m_nOldCnt == 3)
		{
			m_csOld = m_csOld + "8";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;

			if(gcsNewPW == m_csOld)
			{
				return;
			}
			else
			{
				AfxMessageBox("Password Fail!!");
				m_csOld = "";
				m_nOldCnt = 0;
				m_OldPW = "";
				return;
			}
		}
		else
		{
		
			m_csOld = m_csOld + "8";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;
		}
	}
	else
	{
		if(m_nNewCnt == 4)
		{
			return;
		}
		else
		{
			m_csNew = m_csNew + "8";
			m_NewPW = m_csNew;
			UpdateData(FALSE);
			m_nNewCnt++;
		}
	}
}

void CDlg_PW::ClickPw9()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bSelPW == false)
	{
		if(m_nOldCnt == 3)
		{
			m_csOld = m_csOld + "9";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;

			if(gcsNewPW == m_csOld)
			{
				return;
			}
			else
			{
				AfxMessageBox("Password Fail!!");
				m_csOld = "";
				m_nOldCnt = 0;
				m_OldPW = "";
				return;
			}
		}
		else
		{
		
			m_csOld = m_csOld + "9";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;
		}
	}
	else
	{
		if(m_nNewCnt == 4)
		{
			return;
		}
		else
		{
			m_csNew = m_csNew + "9";
			m_NewPW = m_csNew;
			UpdateData(FALSE);
			m_nNewCnt++;
		}
	}
}

void CDlg_PW::ClickPw0()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_bSelPW == false)
	{
		if(m_nOldCnt == 3)
		{
			m_csOld = m_csOld + "0";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;

			if(gcsNewPW == m_csOld)
			{
				return;
			}
			else
			{
				AfxMessageBox("Password Fail!!");
				m_csOld = "";
				m_nOldCnt = 0;
				m_OldPW = "";
				return;
			}
		}
		else
		{
		
			m_csOld = m_csOld + "0";
			m_OldPW = m_csOld;
			UpdateData(FALSE);
			m_nOldCnt++;
		}
	}
	else
	{
		if(m_nNewCnt == 4)
		{
			return;
		}
		else
		{
			m_csNew = m_csNew + "0";
			m_NewPW = m_csNew;
			UpdateData(FALSE);
			m_nNewCnt++;
		}
	}
}

void CDlg_PW::ClickSelOldpw()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_bSelPW = false;
	m_Sel_NewPW.SetBackColor(RGB(0,0,0));
	m_Sel_OldPW.SetBackColor(RGB(0,0,255));
}

void CDlg_PW::ClickSelNewPw()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_bSelPW = true;
	m_Sel_NewPW.SetBackColor(RGB(0,0,255));
	m_Sel_OldPW.SetBackColor(RGB(0,0,0));
}

void CDlg_PW::ClickOkBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString csData, csData1;
	UpdateData(TRUE);
	csData = m_OldPW;
	csData1 = m_NewPW;
	if(gcsNewPW == csData)
	{
		if(csData1 == "")
		{
			AfxMessageBox("NEW PASSWORD EMPTY!!");
			m_nNewCnt = 0;
			m_nOldCnt = 0;
			return;
		}
		else
		{
			gcsNewPW = csData1;
			m_nNewCnt = 0;
			m_nOldCnt = 0;
			DataSave();
			OnOK();
		}
	}
	else 
	{
		m_NewPW = "";
		m_csNew = "";
		m_nNewCnt = 0; 
		UpdateData(FALSE);
	}
}

void CDlg_PW::ClickExitBtn2()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_nNewCnt = 0;
	m_nOldCnt = 0;
	OnOK();
}

void CDlg_PW::DataSave()
{
	CString	csData;
	CString csRet;
	CString csFileName;
	csFileName = GetRunDirectory();
	csFileName = csFileName + "\\Setting\\";
	csFileName = csFileName + "PW.dat";
	
	WritePrivateProfileString("PW", "DATA", gcsNewPW, csFileName);
}