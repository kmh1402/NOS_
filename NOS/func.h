#define GOOD			1
#define FAIL			-1

#include "share.h"
#include "pmiMApi.h"
#include "pmiMApiDefs.h"

#include "Run_Main.h"
#include <math.h>

CString GetRunDirectory()
{
	char buf[128];
	CString csreturnDir;
	GetCurrentDirectory(128,buf);
	csreturnDir.Format("%s",buf);
	return (csreturnDir);
}

int FileDelete(CString csFileName)
{
	if(DeleteFile(csFileName) != 0)
		return(GOOD);
	else
		return(FAIL);
}

int FileCopy(CString objectFile, CString sourceFile, bool overWrite)
{
	if(CopyFile(sourceFile, objectFile, !overWrite != 0))
		return(GOOD);
	else
		return(FAIL);
}

int DirectoryCreate(CString dirPath)
{
	int returnVal;
	returnVal = CreateDirectory(dirPath, NULL);
	return(returnVal);
}

void SpeedSetting()
{
	/*
	cmmCfgSetSpeedPattern(M_X1, cmSMODE_S, SpeedFH.lX1, SpeedAcc.lX1, SpeedAcc.lX1);
	cmmCfgSetSpeedPattern(M_Y1, cmSMODE_S, SpeedFH.lY1, SpeedAcc.lY1, SpeedAcc.lY1);
	cmmCfgSetSpeedPattern(M_Z1, cmSMODE_S, SpeedFH.lZ1, SpeedAcc.lZ1, SpeedAcc.lZ1);
	cmmCfgSetSpeedPattern(M_T1, cmSMODE_S, SpeedFH.lT1, SpeedAcc.lT1, SpeedAcc.lT1);
	*/
	pmiAxSetVelProf( 0, M_X1, 2, double(SpeedFH.lX1), double(SpeedAcc.lX1), double(SpeedAcc.lX1) );	
	pmiAxSetVelProf( 0, M_Y1, 2, double(SpeedFH.lY1), double(SpeedAcc.lY1), double(SpeedAcc.lY1) );	
	pmiAxSetVelProf( 0, M_Z1, 2, double(SpeedFH.lZ1), double(SpeedAcc.lZ1), double(SpeedAcc.lZ1) );	
	
}

void MotorStop()
{
	
}

void RunLog(CString csMessage)
{
	FILE* pFile;
	CString csDate;
	CString csPath;
	CString csLog;
	CString csYear, csMonth, csDay;

	////////////////이벤트 발생시간////////////////////
	CTime CurTime;
	CString csEventTime, csCreateName;
	CString csH,csM,csS;
	int nH,nM,nS;

	CString csFileName;
	
	CString csData;

	GetCurDay(&csYear, &csMonth, &csDay);
	csFileName = GetRunDirectory();

	csCreateName = csFileName + "\\Log\\";

	CurTime = CTime::GetCurrentTime();
	nH = CurTime.GetHour();
	nM = CurTime.GetMinute();
	nS = CurTime.GetSecond();
	csH.Format("%02d시",nH);
	csM.Format("%02d분",nM);
	csS.Format("%02d초",nS);
	csEventTime = csH + csM + csS;
	/////////////////////////////////////////////////////
	DirectoryCreate(csCreateName);
	csCreateName = csCreateName + csYear + "\\";
	DirectoryCreate(csCreateName);

	csCreateName = csCreateName + csMonth + "\\";
	DirectoryCreate(csCreateName);

	csCreateName = csCreateName + csDay + "\\";
	DirectoryCreate(csCreateName);

	csPath = csCreateName + csH + "\\";
	DirectoryCreate(csPath);


	csPath = csPath + "Log.txt";
	pFile = _fsopen(csPath, "a+", _SH_DENYNO);
	if(pFile != NULL)
	{
		csLog.Format("%s === > %s \n",csEventTime, csMessage);
		fprintf(pFile, csLog);
	}
	fclose(pFile);
}

void GetCurDay(CString *csYear, CString *csMonth, CString *csDay)
{
	CTime CurTime;
	CString csData;
	int iYear,iMonth,iDay;

	CurTime = CTime::GetCurrentTime();
	iMonth = CurTime.GetMonth();
	csData.Format("%d월",iMonth);
	*csMonth = csData;

	iDay = CurTime.GetDay();
	csData.Format("%d일",iDay);
	*csDay = csData;

	iYear = CurTime.GetYear();
	csData.Format("%d년",iYear);
	*csYear = csData;
}

void GetCurTime(CString *csHour, CString *csMin, CString *csSec)
{
	CTime CurTime;
	CString csData;
	int iHour,iMinute,iSecond;

	CurTime = CTime::GetCurrentTime();
	iHour = CurTime.GetHour();
	csData.Format("%d시",iHour);
	*csHour = csData;

	iMinute = CurTime.GetMinute();
	csData.Format("%d분",iMinute);
	*csMin = csData;

	iSecond = CurTime.GetSecond();
	csData.Format("%d초",iSecond);
	*csSec = csData;
}

void MoveTo(int nAxis, long lPos)
{
	// Motor를 이동시키기전 이부분에 인터락을 걸어주도록 한다. 
	/*
	BOOL bAMPState;
	long dwMIOState;
	CString csData;
	int nInterLockCheck;
	double dPos;
	
	nInterLockCheck = 1;
		
	if(gbOrgEnd == false)
	{
		AfxMessageBox("Home Check 후에 사용하시기 바랍니다."); 
		return;
	}
	
	if(nAxis == M_X1 || nAxis == M_Y1)
	{
		cmmStGetPosition(M_Z1,cmCNT_FEED, &dPos);
		if(gTeach.lInter_Z + 10 < dPos)
		{
			nInterLockCheck = 0;
		}
	}

	cmmStReadMioStatuses(nAxis, &dwMIOState);
	bAMPState = (dwMIOState >> cmIOST_ALM) & 0x1;
	
	if(bAMPState == 1)
	{
		nInterLockCheck = 0;
	}

	if(nInterLockCheck == 1)
	{
		cmmSxMoveTo(nAxis, lPos, cmFALSE);
	}
	else
	{
		gLB1.bStart = false;
		gLB1.bStop = true;
		gLB1.bError = true;
		gLB1.csErrorCode = "MOTION INTERLOCK ERROR!!"; 
	}
	*/
}

int MoveToStart(int nAxis, long lPos)
{
	/*
	int nInterLockCheck;
	BOOL bAMPState;
	long dwMIOState;
	CString csData;
	double dPos;

	if(gbOrgEnd == false)
	{
		return 0;
	}
	
	nInterLockCheck = 1;
	if(nAxis == M_X1 || nAxis == M_Y1)
	{
		cmmStGetPosition(M_Z1,cmCNT_FEED, &dPos);
		if(gTeach.lInter_Z + 10 < dPos)
		{
			if(gnInterLockFree == 0)
			{
				nInterLockCheck = 0;
			}
		}
	}

	cmmStReadMioStatuses(nAxis, &dwMIOState);
	bAMPState = (dwMIOState >> cmIOST_ALM) & 0x1;
	
	if(bAMPState == 1)
	{
		nInterLockCheck = 0;
	}

	gnInterLockFree = 0;
	if(nInterLockCheck == 1)
	{
		cmmSxMoveToStart(nAxis, lPos);
	}
	else
	{
		if(gLB1.bStop == FALSE && gLB1.bStart == TRUE)	
		{
			return 0;
		}
		else
		{
			AfxMessageBox("Motion InterLock Error");
		}
	}
	*/
	return 1;
}

void MotionDataLoad()
{
	CString csFileName;	
	CString csData;
	
	char MData[20];//불러올변수저장공간및 확보
	char MRData[50];//불러올변수저장공간및 확보
	csFileName = GetRunDirectory();
	csFileName = csFileName + "\\";
	csFileName = csFileName + "Setting\\";
	csFileName = csFileName + "\\MotionData.dat" ;

 	csFileName = "d:\\NOS\\NOS";
 	csFileName = csFileName + "\\Model.txt" ;

 	GetPrivateProfileString("MODEL", "NAME", "Default", MRData, 50, csFileName);
 	gcsModelName = MRData;


// 	csFileName = "d:\\NOS\\NOS";
// 	csFileName = csFileName + "\\Setting\\";
// 	csFileName = csFileName + gcsModelName;
// 	csFileName = csFileName + ".txt" ;
	
	GetPrivateProfileString("TEACH", "RDY X", "Default", MData, 20, csFileName);
	gTeach.lRdyX = atol(MData) ;

	GetPrivateProfileString("TEACH", "RDY Y", "Default", MData, 20, csFileName);
	gTeach.lRdyY = atol(MData) ;

	GetPrivateProfileString("TEACH", "RDY Z", "Default", MData, 20, csFileName);
	gTeach.lRdyZ = atol(MData) ;

	GetPrivateProfileString("SPEED", "X MOVE", "Default", MData, 20, csFileName);
	SpeedFH.lX1 = atol(MData) ;

	GetPrivateProfileString("SPEED", "X ACCDEC", "Default", MData, 20, csFileName);
	SpeedAcc.lX1 = atol(MData) ;

	GetPrivateProfileString("SPEED", "X HOME", "Default", MData, 20, csFileName);
	SpeedHome.lX1 = atol(MData) ;

	GetPrivateProfileString("SPEED", "X JOG", "Default", MData, 20, csFileName);
	SpeedJog.lX1 = atol(MData) ;

	GetPrivateProfileString("SPEED", "Y MOVE", "Default", MData, 20, csFileName);
	SpeedFH.lY1 = atol(MData) ;

	GetPrivateProfileString("SPEED", "Y ACCDEC", "Default", MData, 20, csFileName);
	SpeedAcc.lY1 = atol(MData) ;

	GetPrivateProfileString("SPEED", "Y HOME", "Default", MData, 20, csFileName);
	SpeedHome.lY1 = atol(MData) ;

	GetPrivateProfileString("SPEED", "Y JOG", "Default", MData, 20, csFileName);
	SpeedJog.lY1 = atol(MData) ;

	GetPrivateProfileString("SPEED", "X MOVE2", "Default", MData, 20, csFileName);
	SpeedFH.lX2 = atol(MData) ;

	GetPrivateProfileString("SPEED", "X ACCDEC2", "Default", MData, 20, csFileName);
	SpeedAcc.lX2 = atol(MData) ;

	GetPrivateProfileString("SPEED", "Y MOVE2", "Default", MData, 20, csFileName);
	SpeedFH.lY2 = atol(MData) ;

	GetPrivateProfileString("SPEED", "Y ACCDEC2", "Default", MData, 20, csFileName);
	SpeedAcc.lY2 = atol(MData) ;

	GetPrivateProfileString("SPEED", "Z MOVE", "Default", MData, 20, csFileName);
	SpeedFH.lZ1 = atol(MData) ;

	GetPrivateProfileString("SPEED", "Z ACC", "Default", MData, 20, csFileName);
	SpeedAcc.lZ1 = atol(MData) ;

	GetPrivateProfileString("SPEED", "Z HOME", "Default", MData, 20, csFileName);
	SpeedHome.lZ1 = atol(MData) ;

	GetPrivateProfileString("SPEED", "Z JOG", "Default", MData, 20, csFileName);
	SpeedJog.lZ1 = atol(MData) ;

	GetPrivateProfileString("TEACH", "UP POS Z", "Default", MData, 20, csFileName);
	gTeach.lUpPos = atol(MData) ;

	GetPrivateProfileString("TEACH", "UP POS Z2", "Default", MData, 20, csFileName);
	gTeach.lUpPos2 = atol(MData) ;

	GetPrivateProfileString("TEACH", "UP POS Z3", "Default", MData, 20, csFileName);
	gTeach.lUpPos3 = atol(MData) ;

	GetPrivateProfileString("TEACH", "UP POS Z4", "Default", MData, 20, csFileName);
	gTeach.lUpPos4 = atol(MData) ;

	GetPrivateProfileString("TEACH", "DOWN POS Z", "Default", MData, 20, csFileName);
	gTeach.lDownPos = atol(MData) ;

	GetPrivateProfileString("TEACH", "POS X1", "Default", MData, 20, csFileName);
	gTeach.lX1 = atol(MData) ;

	GetPrivateProfileString("TEACH", "POS X2", "Default", MData, 20, csFileName);
	gTeach.lX2 = atol(MData) ;

	GetPrivateProfileString("TEACH", "POS X3", "Default", MData, 20, csFileName);
	gTeach.lX3 = atol(MData) ;

	GetPrivateProfileString("TEACH", "POS X4", "Default", MData, 20, csFileName);
	gTeach.lX4 = atol(MData) ;
	GetPrivateProfileString("TEACH", "POS Y1", "Default", MData, 20, csFileName);
	gTeach.lY1 = atol(MData) ;

	GetPrivateProfileString("TEACH", "POS Y2", "Default", MData, 20, csFileName);
	gTeach.lY2 = atol(MData) ;

	GetPrivateProfileString("TEACH", "POS Y3", "Default", MData, 20, csFileName);
	gTeach.lY3 = atol(MData) ;

	GetPrivateProfileString("TEACH", "POS Y4", "Default", MData, 20, csFileName);
	gTeach.lY4 = atol(MData) ;
	
	GetPrivateProfileString("TEACH", "INTERLOCK Z", "Default", MData, 20, csFileName);
	gTeach.lInterZ = atol(MData) ;

	for(int nY = 0; nY < 10; nY++)
	{
		for(int nX = 0; nX < 10; nX++)
		{
			csData.Format("X%d Y%d", nX, nY);
			GetPrivateProfileString("SKIP", csData, "Default", MData, 20, csFileName);
			gnSkip[nX][nY] = atol(MData) ;

			GetPrivateProfileString("SKIP2", csData, "Default", MData, 20, csFileName);
			gnSkip2[nX][nY] = atol(MData) ;

			GetPrivateProfileString("SKIP3", csData, "Default", MData, 20, csFileName);
			gnSkip3[nX][nY] = atol(MData) ;
		}
	}
}

void FileDelete1(CString csEQNum, CString csFileName)
{	
	
}

void FileCopy1(CString csFileName, CString csEQTray)
{
	
}

void ERLog(CString csMessage)
{
	FILE* pFile;
	CString csDate;
	CString csPath;
	CString csLog;
	CString csYear, csMonth, csDay;

	////////////////이벤트 발생시간////////////////////
	CTime CurTime;
	CString csEventTime, csCreateName;
	CString csH,csM,csS;
	int nH,nM,nS;

	CString csFileName;
	
	CString csData;

	GetCurDay(&csYear, &csMonth, &csDay);
	csFileName = GetRunDirectory();

	csCreateName = csFileName + "\\ERData\\";

	CurTime = CTime::GetCurrentTime();
	nH = CurTime.GetHour();
	nM = CurTime.GetMinute();
	nS = CurTime.GetSecond();
	csH.Format("%02d시",nH);
	csM.Format("%02d분",nM);
	csS.Format("%02d초",nS);
	csEventTime = csH + csM + csS;
	/////////////////////////////////////////////////////
	
	csCreateName = csCreateName + csYear + "\\";
	DirectoryCreate(csCreateName);

	csCreateName = csCreateName + csMonth + "\\";
	DirectoryCreate(csCreateName);

	csCreateName = csCreateName + csDay + "\\";
	DirectoryCreate(csCreateName);
	csPath = csCreateName ;
	csPath = csPath + "AlarmLog.txt";
	pFile = _fsopen(csPath, "a+", _SH_DENYNO);
	if(pFile != NULL)
	{
		csLog.Format("%s,%s\n",csEventTime, gNOS.csErrorCode);
		fprintf(pFile, csLog);
	}
	fclose(pFile);
}
CString GetTime()
{
	////////////////이벤트 발생시간////////////////////
	CTime CurTime;
	CString csEventTime;
	CString csH,csM,csS;
	int nH,nM,nS;

	CurTime = CTime::GetCurrentTime();
	nH = CurTime.GetHour();
	nM = CurTime.GetMinute();
	nS = CurTime.GetSecond();
	csH.Format("%02d시",nH);
	csM.Format("%02d분",nM);
	csS.Format("%02d초",nS);
	csEventTime = csH + csM + csS;
	/////////////////////////////////////////////////////

	return csEventTime;
}

void PWLoad()
{
	CString csFileName;	
	csFileName = GetRunDirectory();
	csFileName = csFileName + "\\Setting\\";
	csFileName = csFileName + "PW.dat";
	char MData[20];//불러올변수저장공간및 확보

	GetPrivateProfileString("PW", "DATA", "Default", MData, 20, csFileName);
	gcsNewPW = MData;
	if(gcsNewPW == "Default")
	{
		gcsNewPW = "0000";
	}
}

void ArrayPosCalc()
{
	/*
	int nI = 0;
	//좌측 대각선 내분점 구하기
	for(nI = 0; nI < gnYCnt; nI ++)
	{
		glPosArray[nI].lX1 = ((nI * gTeach.lX_110) + ((gnYCnt - 1 - nI) * gTeach.lX_11)) / (gnYCnt - 1);
		glPosArray[nI].lY1 = ((nI * gTeach.lY_110) + ((gnYCnt - 1 - nI) * gTeach.lY_11)) / (gnYCnt - 1);
	}

	//우측 대각선 내분점 구하기
	
	for(nI = 0; nI < gnYCnt; nI ++)
	{
		glPosArray[nI].lX2 = ((nI * gTeach.lX_1010) + ((gnYCnt - 1 - nI) * gTeach.lX_101)) / (gnYCnt - 1);
		glPosArray[nI].lY2 = ((nI * gTeach.lY_1010) + ((gnYCnt - 1 - nI) * gTeach.lY_101)) / (gnYCnt - 1);
	}

	//좌우 좌표 를 시작과 끝으로 하고 중간좌표를 구한다. 
	for(int nY = 0; nY < gnYCnt; nY++)
	{
		for(int nX = 0; nX < gnXCnt; nX++)
		{
			glLensPos[nX][nY].lX = ((nX * glPosArray[nY].lX2) + (((gnXCnt) - 1 - nX) * glPosArray[nY].lX1)) / ((gnXCnt) - 1);
			glLensPos[nX][nY].lY = ((nX * glPosArray[nY].lY2) + (((gnXCnt) - 1 - nX) * glPosArray[nY].lY1)) / ((gnXCnt) - 1);
		}
	}
	*/
}

void CountSave()
{
/*
	CString csFileName;
	CString csRet;
	CString csData;
	
	csFileName = GetRunDirectory();
	csFileName = csFileName + "\\Setting\\MotionData.txt" ;
	
	csRet.Format("%d", gnRecOKCnt); 
	WritePrivateProfileString("COUNT", "OK", csRet, csFileName);

	csRet.Format("%d", gnRecNGCnt); 
	WritePrivateProfileString("COUNT", "NG", csRet, csFileName);
	*/
}

void CountLoad()
{
/*
	CString csFileName;
	CString csRet;
	CString csData;
	char MData[20];//불러올변수저장공간및 확보
		
	csFileName = GetRunDirectory();
	csFileName = csFileName + "\\Setting\\MotionData.txt" ;

	GetPrivateProfileString("COUNT", "OK", "Default", MData, 20, csFileName);
	gnRecOKCnt = atol(MData) ;
	GetPrivateProfileString("COUNT", "NG", "Default", MData, 20, csFileName);
	gnRecNGCnt = atol(MData) ;
	*/
}
