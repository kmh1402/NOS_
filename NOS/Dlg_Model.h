#pragma once
#include "afxwin.h"
#include "btnenh.h"

// CDlg_Model ��ȭ �����Դϴ�.

class CDlg_Model : public CDialog
{
	DECLARE_DYNAMIC(CDlg_Model)

public:
	CBtnEnh m_ModelName;
	CDlg_Model(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_Model();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_MODEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
