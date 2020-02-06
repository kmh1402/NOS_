// Run_Utill.h: interface for the CRun_Util class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUN_UTILL_H__E4E2AD2C_2F82_4FA2_892B_B58F3E2B9C10__INCLUDED_)
#define AFX_RUN_UTILL_H__E4E2AD2C_2F82_4FA2_892B_B58F3E2B9C10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRun_Utill  
{
public:
	void Run_Start_Buzzer();

	long m_dwMIOState;
	BOOL m_bAMPState;
	long m_dwMIOStateChk;
	BOOL m_bAMPStateChk;
	int m_nOrgDispStep;
	int m_nCnt;
	int m_nBondSig_Step;
	int m_nBuzStep;
	int m_nOrgStep;
	int m_nInsertStep;
	long m_lMotorStatus;
	long m_nMotorRet[4];
	int m_nData;
	int m_nStep;
	int m_nBondStep;


	CString m_csData;
	double m_dPos;
	//kjh start X axis
	BYTE bToInt[8];
	unsigned int nToInt[8];


	bool m_bInitFlag;
	long m_lIOStatus[4];
	long lUtillTimeChk[4];
	long lFlinkTimeChk[4];
	long lCountTimeChk[4];
	long lBondTimeChk[4];
	long lStartBuzTimeChk[4];
	long lTestTimeChk[4];
	
	long m_lRad[2];
	void Run_Move();
	void Run_Variable_Init();
	void Thread_Run();
	void FLINK_DISP();
	
	
	CRun_Utill();
	virtual ~CRun_Utill();

};
extern CRun_Utill	Run_Utill;
#endif // !defined(AFX_RUN_UTIL_H__E4E2AD2C_2F82_4FA2_892B_B58F3E2B9C10__INCLUDED_)