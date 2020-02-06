#pragma once
#include "btnenh.h"


// CFrm_Main �� ���Դϴ�.

class CFrm_Main : public CFormView
{
	DECLARE_DYNCREATE(CFrm_Main)

public:
	CFrm_Main();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CFrm_Main();

public:

	CBtnEnh m_Status;
	CBtnEnh m_AlarmMessage;
	CBtnEnh m_Date;
	CBtnEnh m_Time;
	CBtnEnh m_Work_Time;
	CBtnEnh m_Cycle_Time;


	enum { IDD = IDD_FRM_MAIN };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_EVENTSINK_MAP()
	void ClickMainexitBtn();
	void ClickStartBtn();
	void ClickStopBtn();
	void DataDisplay();
	void MainTime();
	void ClickMotionBtn();
};


