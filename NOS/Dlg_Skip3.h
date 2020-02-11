#pragma once


// CDlg_Skip3 대화 상자입니다.

class CDlg_Skip3 : public CDialog
{
	DECLARE_DYNAMIC(CDlg_Skip3)

public:
	bool m_bX1;
	bool m_bX2;
	bool m_bX3;
	bool m_bX4;
	bool m_bX5;
	bool m_bX6;
	bool m_bX7;
	bool m_bX8;
	bool m_bX9;
	bool m_bX10;
	bool m_bY1;
	bool m_bY2;
	bool m_bY3;
	bool m_bY4;
	bool m_bY5;
	bool m_bY6;
	bool m_bY7;
	bool m_bY8;
	bool m_bY9;
	bool m_bY10;

	CDlg_Skip3(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_Skip3();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_SKIP3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void PostNcDestroy();
public:
	virtual BOOL DestroyWindow();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void Rect1(CDC* pDC);
	DECLARE_EVENTSINK_MAP()
	void ClickOkBtn();
	void DataSave();
	void ClickSkipX1();
	void ClickSkipX2();
	void ClickSkipX3();
	void ClickSkipX4();
	void ClickSkipX6();
	void ClickSkipX7();
	void ClickSkipX8();
	void ClickSkipX9();
	void ClickSkipX10();
	void ClickSkipX11();
	void ClickSkipY1();
	void ClickSkipY2();
	void ClickSkipY3();
	void ClickSkipY4();
	void ClickSkipY5();
	void ClickSkipY6();
	void ClickSkipY7();
	void ClickSkipY8();
	void ClickSkipY9();
	void ClickSkipY10();
	void ClickSkipX12();
	void ClickSkipX13();
};
