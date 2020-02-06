#include "StdAfx.h"
#include "NOS.h"
#include "Run_Main.h"
#include "VarEx.h"
#include "FuncEx.h"

#include <math.h>

CRun_Main		Run_Main;
CRun_Main::CRun_Main(void)
{
	m_bInitFlag = true;
}

CRun_Main::~CRun_Main(void)
{
}

void CRun_Main::Thread_Run()
{	
	
	if(gbThreadEnd == false)	{
		return;
	}
	
	if(gbOriginStart == true || gbOrgEnd == false)
	{
		return;
	}	
	

	if(gNOS.bStop == TRUE || gNOS.bStart == FALSE || gNOS.bError == TRUE)	
	{
		
		return;
	}
	
	if(m_bInitFlag == true)	
	{
		Run_Variable_Init();
	}


	Run_Move();
}

void CRun_Main::Run_Variable_Init()
{
	m_nStep = 100;
	m_bInitFlag = false;
	m_nXCnt = 0;
	m_nYCnt = 0;
}

void CRun_Main::Run_Move()
{
	switch(m_nStep)
	{
	case 100:
		break;
	}
}

void CRun_Main::MovePosCalcPick(int nX, int nY, long *lXPos, long *lYPos)
{
	long lX = 0;
	long lY = 0;
	
	*lXPos = lX;
	*lYPos = lY;
}
