// Dlg_LogIN.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_LogIN.h"
#include "Dlg_PW.h"
#include "FuncEx.h"
#include "VarEx.h"

// CDlg_LogIN ��ȭ �����Դϴ�.

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


// CDlg_LogIN �޽��� ó�����Դϴ�.
BOOL CDlg_LogIN::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	m_csPW = "";
	m_nCnt = 0;
		
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	m_csPW = m_csPW + "1";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password�� �´��� Ʋ���� ó���Ѵ� 
		//������ ���̾�α׸� �ݰ� �Ѿ� �����ֵ��� 
		if(m_csPW == gcsNewPW) // ������ 
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	m_csPW = m_csPW + "2";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password�� �´��� Ʋ���� ó���Ѵ� 
		//������ ���̾�α׸� �ݰ� �Ѿ� �����ֵ��� 
		if(m_csPW == gcsNewPW) // ������ 
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	m_csPW = m_csPW + "3";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password�� �´��� Ʋ���� ó���Ѵ� 
		//������ ���̾�α׸� �ݰ� �Ѿ� �����ֵ��� 
		if(m_csPW == gcsNewPW) // ������ 
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	m_csPW = m_csPW + "4";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password�� �´��� Ʋ���� ó���Ѵ� 
		//������ ���̾�α׸� �ݰ� �Ѿ� �����ֵ��� 
		if(m_csPW == gcsNewPW) // ������ 
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	m_csPW = m_csPW + "5";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password�� �´��� Ʋ���� ó���Ѵ� 
		//������ ���̾�α׸� �ݰ� �Ѿ� �����ֵ��� 
		if(m_csPW == gcsNewPW) // ������ 
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	m_csPW = m_csPW + "6";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password�� �´��� Ʋ���� ó���Ѵ� 
		//������ ���̾�α׸� �ݰ� �Ѿ� �����ֵ��� 
		if(m_csPW == gcsNewPW) // ������ 
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	m_csPW = m_csPW + "7";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password�� �´��� Ʋ���� ó���Ѵ� 
		//������ ���̾�α׸� �ݰ� �Ѿ� �����ֵ��� 
		if(m_csPW == gcsNewPW) // ������ 
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	m_csPW = m_csPW + "8";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password�� �´��� Ʋ���� ó���Ѵ� 
		//������ ���̾�α׸� �ݰ� �Ѿ� �����ֵ��� 
		if(m_csPW == gcsNewPW) // ������ 
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	m_csPW = m_csPW + "9";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password�� �´��� Ʋ���� ó���Ѵ� 
		//������ ���̾�α׸� �ݰ� �Ѿ� �����ֵ��� 
		if(m_csPW == gcsNewPW) // ������ 
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	m_csPW = m_csPW + "0";
	m_EdtPW = m_csPW;
	UpdateData(FALSE);
	m_nCnt ++;

	if(m_nCnt == 4)
	{
		//Password�� �´��� Ʋ���� ó���Ѵ� 
		//������ ���̾�α׸� �ݰ� �Ѿ� �����ֵ��� 
		if(m_csPW == gcsNewPW) // ������ 
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CDlg_PW Dlg;
	Dlg.DoModal();
}

void CDlg_LogIN::ClickOkBtn()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	gbPWFail = true;
	OnOK();
}
