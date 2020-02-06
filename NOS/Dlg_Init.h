#pragma once
#include "btnenh.h"

// CDlg_Init 대화 상자입니다.

class CDlg_Init : public CDialog
{
	DECLARE_DYNAMIC(CDlg_Init)

public:
	CBtnEnh	m_Message;
	CBtnEnh m_Percent;
	CProgressCtrl m_Progress;
	CDlg_Init(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_Init();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_INIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void DataInit();
	void InitMotionDevices();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
