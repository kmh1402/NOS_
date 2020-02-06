#pragma once
#include "btnenh.h"

// CDlg_Init ��ȭ �����Դϴ�.

class CDlg_Init : public CDialog
{
	DECLARE_DYNAMIC(CDlg_Init)

public:
	CBtnEnh	m_Message;
	CBtnEnh m_Percent;
	CProgressCtrl m_Progress;
	CDlg_Init(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_Init();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_INIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void DataInit();
	void InitMotionDevices();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
