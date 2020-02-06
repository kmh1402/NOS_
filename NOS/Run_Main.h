#pragma once

class CRun_Main
{
public:
	
	int m_nStep;
	int m_nXCnt;
	int m_nYCnt;
	long lCountTimeChk[4];
	long lCountTimeChk2[4];
	long lTactTimeChk[4];
	long lCycleTimeChk[4];
	bool m_bInitFlag;
	void Run_Variable_Init();
	void Thread_Run();
	void Run_Move();
	void MovePosCalcPick(int nX, int nY, long *lXPos, long *lYPos);
	
	CRun_Main(void);
	~CRun_Main(void);
};
extern CRun_Main		Run_Main;