// Thread.cpp: implementation of the CThread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "afxmt.h"
#include "NOS.h"
#include "VarEx.h"
#include "Run_Main.h"
#include "Run_Utill.h"
#include "Thread.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CWinThread  *m_Thread[2] ;
CMutex mutex;

long   ThreadCount[2] ;
int All_Stop;
int nUtillEnd;
int nMainEnd;

//========Time Check ============
long   ThreadTime[3] = {0,0,0} ;
BOOL   ThreadTimeFlag = FALSE ;

///////////////////////////////////////////////////////////////////////


UINT  Thread_UtilityFunction(LPVOID  lParam)	// m_Thread[1]
{
	nUtillEnd = 0;
	CSingleLock sing(&mutex) ;
	while(!All_Stop)
	{
		sing.Lock() ;
		Run_Utill.Thread_Run();
		Sleep(0) ;
		sing.Unlock() ;
	}
	nUtillEnd = 1;
	return TRUE ;
}

UINT  Thread_Main(LPVOID lParam)	{		// m_Thread[2]
	nMainEnd = 0;
	CSingleLock sing(&mutex) ;
	while(!All_Stop)
	{
		sing.Lock() ;
		Run_Main.Thread_Run() ;
		Sleep(0) ;
		sing.Unlock() ;
	}
	nMainEnd = 1;
	return TRUE ;
}
