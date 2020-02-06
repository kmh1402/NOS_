extern CWinThread  *m_Thread[2];
extern 	long  ThreadCount[2];


extern	UINT  Thread_UtilityFunction(LPVOID  lParam);		// m_Thread[1]			
extern	UINT  Thread_Main(LPVOID lParam);					// m_Thread[2]	

extern int All_Stop;
extern int nUtillEnd;
extern int nMainEnd;
