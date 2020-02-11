// Dlg_Model.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "NOS.h"
#include "Dlg_Model.h"
#include "VarEx.h"
#include "FuncEx.h"


// CDlg_Model 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_Model, CDialog)

CDlg_Model::CDlg_Model(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Model::IDD, pParent)
	, m_edtModel(_T(""))
{

}

CDlg_Model::~CDlg_Model()
{
}

void CDlg_Model::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MODEL_LIST, m_Model_List);
	DDX_Text(pDX, IDC_EDT_MODEL, m_edtModel);
	DDX_Control(pDX, IDC_MODEL_NAME, m_ModelName);
		
}


BEGIN_MESSAGE_MAP(CDlg_Model, CDialog)
END_MESSAGE_MAP()


// CDlg_Model 메시지 처리기입니다.
BEGIN_EVENTSINK_MAP(CDlg_Model, CDialog)
	ON_EVENT(CDlg_Model, IDC_OK_BTN, DISPID_CLICK, CDlg_Model::ClickOkBtn, VTS_NONE)
	ON_EVENT(CDlg_Model, IDC_DELETE_BTN, DISPID_CLICK, CDlg_Model::ClickDeleteBtn, VTS_NONE)
	ON_EVENT(CDlg_Model, IDC_LOAD_BTN, DISPID_CLICK, CDlg_Model::ClickLoadBtn, VTS_NONE)
	ON_EVENT(CDlg_Model, IDC_ADD_BTN, DISPID_CLICK, CDlg_Model::ClickAddBtn, VTS_NONE)
END_EVENTSINK_MAP()

void CDlg_Model::ClickOkBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	OnOK();
}
	

BOOL CDlg_Model::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	DataLoadSetCaption();
	ModelListLoad();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlg_Model::DataLoadSetCaption()
{
	m_ModelName.SetCaption(gcsModelName);
}

void CDlg_Model::ModelListLoad()
{
	bool bResult;
	CString csFileName;
	CString csFileRoot;
	CFileFind finder;
	int nLength;
	int nFind;
	CString csData;
	CString csOldModel[50];
	int nOldIndex = 0;
	int nChkCnt = 0;
	m_Model_List.ResetContent();
	csFileRoot = "d:\\NOS\\NOS";
	csFileRoot = csFileRoot + "\\Setting\\*.txt*";
	bResult = finder.FindFile(csFileRoot);
	
	while(bResult) 
	{
		bResult = finder.FindNextFile();
		csFileName = finder.GetFileName();
		if(csFileName != "." && csFileName != "..") 
		{
			nChkCnt = 0;
			nLength = csFileName.GetLength();
			nFind = csFileName.Find(".");
			csData = csFileName.Mid(0,nFind);
			for(int nI = 0; nI < 50; nI++)
			{
				if(csOldModel[nI] != csData)
				{
					nChkCnt++;
				}
			}

			if(nChkCnt != 0)
			{
				nChkCnt = 0;
				for(int nJ = 0; nJ < 50; nJ++)
				{
					if(csOldModel[nJ] == csData)
					{
						nChkCnt++;
					}
				}

				if(nChkCnt == 0)
				{
					for(int nQ = 0; nQ < 50; nQ++)
					{
						if(csOldModel[nQ] == "")
						{
							csOldModel[nQ] = csData;
							nQ = 50;
							m_Model_List.AddString(csData);
						}
					}
				}
			}
		}
	}

	finder.Close();
}
void CDlg_Model::ClickDeleteBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nSel;
	CString csData;
	CString csFileRoot;

	nSel = m_Model_List.GetCurSel();
	if(nSel < 0)
	{
		AfxMessageBox("Model Select");
		return;
	}
	
	m_Model_List.GetText(nSel, csData);
	
	csFileRoot = "d:\\NOS\\NOS";
	csFileRoot = csFileRoot + "\\Setting\\";
	csFileRoot = csFileRoot + csData;
	csFileRoot = csFileRoot + ".txt";
	FileDelete(csFileRoot);

	ModelListLoad();
	AfxMessageBox("Select File Delete");
}

void CDlg_Model::ClickLoadBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	int nSel;
	CString csData;
	CString csFileName;
	CString csOldName;

	nSel = m_Model_List.GetCurSel();
	if(nSel < 0)
	{
		AfxMessageBox("Model Select");
		return;
	}
	
	m_Model_List.GetText(nSel, csData);
	
	MotionDataLoad();
	gcsModelName = csData;
	csFileName = "d:\\NOS\\NOS";
	csFileName = csFileName + "\\Model.txt" ;
	WritePrivateProfileString("MODEL", "NAME", gcsModelName, csFileName);

	DataLoadSetCaption();
	AfxMessageBox("Model Load Complete");

	/*
	
	*/
}

void CDlg_Model::ClickAddBtn()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString csModel;
	CString csOldName;
	CString csFileName;
	UpdateData(TRUE);
	csModel = m_edtModel;

	csOldName = "d:\\NOS\\NOS";
	csOldName = csOldName + "\\Setting\\";
	csOldName = csOldName + csModel;
	csOldName = csOldName + ".txt";

	csFileName = "d:\\NOS\\NOS";
	csFileName = csFileName + "\\Setting\\";
	csFileName = csFileName + gcsModelName;
	csFileName = csFileName + ".txt";

	FileCopy(csOldName, csFileName,1);

	csOldName = "d:\\NOS\\NOS";
	csOldName = csOldName + "\\Setting\\";
	csOldName = csOldName + csModel;
	csOldName = csOldName + ".dat";

	csFileName = "d:\\NOS\\NOS";
	csFileName = csFileName + "\\Setting\\";
	csFileName = csFileName + gcsModelName;
	csFileName = csFileName + ".dat";

	FileCopy(csOldName, csFileName,1);

	ModelListLoad();
}
