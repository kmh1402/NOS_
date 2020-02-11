#pragma once
#include "afxwin.h"
#include "btnenh.h"

// CDlg_Model 대화 상자입니다.

class CDlg_Model : public CDialog
{
	DECLARE_DYNAMIC(CDlg_Model)

public:
	CBtnEnh m_ModelName;
	CDlg_Model(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_Model();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_MODEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_Model_List;
	CString m_edtModel;
	DECLARE_EVENTSINK_MAP()
	void ClickOkBtn();
	void DataLoadSetCaption();
	void ModelListLoad();
	virtual BOOL OnInitDialog();
	void ClickDeleteBtn();
	void ClickLoadBtn();
	void ClickAddBtn();
	
protected:
	
};
