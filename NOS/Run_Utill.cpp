// Run_Utill.cpp: implementation of the CRun_UV class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NOS.h"
#include "Run_Utill.h"
#include "Define.h"
#include "FuncEx.h"
#include "VarEx.h"
#include "math.h"
#include "Run_Main.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
CRun_Utill		Run_Utill;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRun_Utill::CRun_Utill()
{
	m_bInitFlag = true;
}

CRun_Utill::~CRun_Utill()
{
	
}

void CRun_Utill::Thread_Run()
{
	
	if(gbThreadEnd == false)	{
		return;
	}
	//Initial Flag를 보고 Initial 동작 중이라면 해주어야 할 동작들을 여기에 정의한다
	if(m_bInitFlag == true)	
	{
		Run_Variable_Init();
	}

	Run_Move();
	FLINK_DISP();
	
}

void CRun_Utill::Run_Variable_Init()
{
	// 임시 디버깅용, Error 검사용
	m_nOrgStep = 100;
	m_nStep = 100;
	m_bInitFlag = false;
	m_nCnt = 0; 
	m_nOrgDispStep = 100;
	m_nBondStep = 100;
	m_nBondSig_Step = 100;
}

void CRun_Utill::Run_Start_Buzzer()
{
	switch(m_nBuzStep)
	{
	case 100:
		m_nBuzStep = 200;
		lStartBuzTimeChk[0] = GetCurrentTime();
		break; 

	case 200:
		lStartBuzTimeChk[1] = GetCurrentTime();
		lStartBuzTimeChk[2] = lStartBuzTimeChk[1] - lStartBuzTimeChk[0];
		if(lStartBuzTimeChk[2] > 1000)	{
			m_nBuzStep = 300;
			//cmmDoPutOne(O_TOWER_LAMP_BUZZER , 0);
			lStartBuzTimeChk[0] = GetCurrentTime();
		}
		break;

	case 300:
		lStartBuzTimeChk[1] = GetCurrentTime();
		lStartBuzTimeChk[2] = lStartBuzTimeChk[1] - lStartBuzTimeChk[0];
		if(lStartBuzTimeChk[2] > 500)	{
			if(m_nCnt > 0)
			{
				m_nCnt = 0; 
				m_nBuzStep = 400;
			}
			else
			{
				m_nCnt++;
				m_nBuzStep = 100;
			}
		}
		break;

	case 400:
		
		m_nBuzStep = 100;
		//cmmDoPutOne(O_TOWER_LAMP_BUZZER , 0);
		break;
	}
}

void CRun_Utill::Run_Move()
{
	switch(m_nStep)
	{
	case 100:
		if(gNOS.bStart == true && gNOS.bStop == false && gNOS.bError == false)
		{
			//cmmDoPutOne(O_TOWER_LAMP_GREEN , 1);
			//cmmDoPutOne(O_TOWER_LAMP_YELLOW , 0);
			//cmmDoPutOne(O_TOWER_LAMP_RED , 0);
		}
		m_nStep = 200;
		break;

	case 200:
		if(gNOS.bStart == false && gNOS.bStop == true && gNOS.bError == false)
		{
			//cmmDoPutOne(O_TOWER_LAMP_GREEN , 0);
			//cmmDoPutOne(O_TOWER_LAMP_YELLOW , 1);
			//cmmDoPutOne(O_TOWER_LAMP_RED , 0);
			
		}
		m_nStep = 300;
		break; 

	case 300:
		if(gNOS.bStart == false && gNOS.bStop == true && gNOS.bError == true)
		{
			//cmmDoPutOne(O_TOWER_LAMP_GREEN , 0);
			//cmmDoPutOne(O_TOWER_LAMP_YELLOW , 0);
			//cmmDoPutOne(O_TOWER_LAMP_RED , 1);
			//cmmDoPutOne(O_TOWER_LAMP_BUZZER , 1);
			//cmmDoPutOne(O_DISP1 , 0);
		}
		m_nStep = 400;
		break; 

	case 400:
		//Start신호가 들어오면 Start로 변경 
		//cmmDiGetOne(I_START_SW1 , &m_lIOStatus[0]);
		//cmmDiGetOne(I_RESET_SW1 , &m_lIOStatus[1]);
		//cmmDiGetOne(I_STOP_SW1 , &m_lIOStatus[2]);
		//cmmDiGetOne(I_START_SW2 , &m_lIOStatus[3]);

		if(m_lIOStatus[0] == 1 && m_lIOStatus[1] == 0 && m_lIOStatus[2] == 0 && m_lIOStatus[3] == 1)
		{
			if(gbOrgEnd == true && gbOriginStart == false)
			{
				gNOS.bStart = true;
				gNOS.bStop = false;
			}
		}
		m_nStep = 500;
		break; 

	case 500:
		//Start신호가 들어오면 Start로 변경 
		//cmmDiGetOne(I_START_SW1 , &m_lIOStatus[0]);
		//cmmDiGetOne(I_RESET_SW1 , &m_lIOStatus[1]);
		//cmmDiGetOne(I_STOP_SW1 , &m_lIOStatus[2]);

		if(m_lIOStatus[0] == 0 && m_lIOStatus[1] == 0 && m_lIOStatus[2] == 1)
		{
			gNOS.bStart = false;
			gNOS.bStop = true;
			//cmmDoPutOne(O_JIG_VAC , 0);
			//cmmDoPutOne(O_DISP1 , 0);
			
		}
		m_nStep = 600;
		break; 

	case 600: 
		//cmmDiGetOne(I_RESET_SW1 , &m_lIOStatus[0]);
		//cmmDiGetOne(I_STOP_SW1 , &m_lIOStatus[1]);
		//Reset 신호가 들어오면 Alarm만 Reset
		if(m_lIOStatus[0] == 1 && m_lIOStatus[1] == 0)
		{
			//gLB1.bStart = false;
			gNOS.bStop = true;
			gNOS.bError = false;
			//cmmDoPutOne(O_TOWER_LAMP_BUZZER , 0);
		}
		m_nStep = 700;
		break; 

	case 700:
		//cmmDiGetOne(I_RESET_SW1 , &m_lIOStatus[0]);
		//cmmDiGetOne(I_STOP_SW1 , &m_lIOStatus[1]);
		//두개가 같이 눌려진다면 전체 초기화를 할수있도록 한다. 
		if(m_lIOStatus[0] == 1 && m_lIOStatus[1] == 1)
		{
			gNOS.bStart = false;
			gNOS.bStop = true;
			gNOS.bError = false;
			m_nStep = 750;
			//cmmDoPutOne(O_JIG_VAC , 0);
		}
		else
		{
			m_nStep = 800;
		}
		break;

	case 750:
		gbOriginStart = true;
		m_nStep = 100;
		break;

	case 800:
		m_nStep = 100;
		break;

	
	}
}

void CRun_Utill::FLINK_DISP()
{
	switch(m_nOrgDispStep)
	{
	case 100:
		if(gbOrgEnd == false && gbOriginStart == false)
		{
			//cmmDoPutOne(O_RESET_SW_LAMP1 , 1);
			//cmmDoPutOne(O_STOP_SW_LAMP1 , 1);
		}

		if(gbOrgEnd == true) 
		{
			if(gNOS.bStart == false && gNOS.bStop == true && gNOS.bError == false)
			{
				//cmmDoPutOne(O_STOP_SW_LAMP1 , 0);
				//cmmDoPutOne(O_RESET_SW_LAMP1 , 0);
				//cmmDoPutOne(O_START_SW_LAMP1 , 1);
				//cmmDoPutOne(O_START_SW_LAMP2 , 1);
			}
			
			if(gNOS.bStart == false && gNOS.bStop == true && gNOS.bError == true)
			{
				//cmmDoPutOne(O_STOP_SW_LAMP1 , 0);
				//cmmDoPutOne(O_RESET_SW_LAMP1 , 1);
				//cmmDoPutOne(O_START_SW_LAMP1 , 0);
				//cmmDoPutOne(O_START_SW_LAMP2 , 0);
			}
		}
		m_nOrgDispStep = 200;
		lFlinkTimeChk[0] = GetCurrentTime();
		break; 

	case 200:
		lFlinkTimeChk[1] = GetCurrentTime();
		lFlinkTimeChk[2] = lFlinkTimeChk[1] - lFlinkTimeChk[0];
		if(lFlinkTimeChk[2] > 200)	{
			m_nOrgDispStep = 300;
		}
		break; 

	case 300:
		if(gbOrgEnd == false && gbOriginStart == false)
		{
			//cmmDoPutOne(O_STOP_SW_LAMP1 , 0);
			//cmmDoPutOne(O_RESET_SW_LAMP1 , 0);
		}

		if(gbOrgEnd == true)
		{
			if(gNOS.bStart == false && gNOS.bStop == true && gNOS.bError == false)
			{
				//cmmDoPutOne(O_STOP_SW_LAMP1 , 0);
				//cmmDoPutOne(O_RESET_SW_LAMP1 , 0);
				//cmmDoPutOne(O_START_SW_LAMP1 , 0);
				//cmmDoPutOne(O_START_SW_LAMP2 , 0);
			}

			if(gNOS.bStart == false && gNOS.bStop == true && gNOS.bError == true)
			{
				//cmmDoPutOne(O_STOP_SW_LAMP1 , 0);
				//cmmDoPutOne(O_RESET_SW_LAMP1 , 0);
				//cmmDoPutOne(O_START_SW_LAMP1 , 0);
				//cmmDoPutOne(O_START_SW_LAMP2 , 0);
			}
		}

		m_nOrgDispStep = 400;
		lFlinkTimeChk[0] = GetCurrentTime();
		break; 

	case 400:
		lFlinkTimeChk[1] = GetCurrentTime();
		lFlinkTimeChk[2] = lFlinkTimeChk[1] - lFlinkTimeChk[0];
		if(lFlinkTimeChk[2] > 200)	{
			m_nOrgDispStep = 500;
		}
		break;
		////////////////////////////////////////////////////////////////////////////
	

	case 500:
		m_nOrgDispStep = 100;
		break;
	}
}
