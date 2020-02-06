/******************************************************************************
*
*	File Version: 3,0,1,0
*
*	Copyright(c) 2012 Alpha Motion Co,. Ltd. All Rights Reserved.
*
*	This file is strictly confidential and do not distribute it outside.
*
*	MODULE NAME :
*		pmiMApi.h
*
*	AUTHOR :
*		K.C. Lee
*
*	DESCRIPTION :
*		the header file for RC files of project.
*
*
* - Phone: +82-31-303-5050
* - Fax  : +82-31-303-5051
* - URL  : http://www.alphamotion.co.kr,
*
*
/****************************************************************************/

#ifndef PMI_MAPI_H
#define PMI_MAPI_H


//***********************************************************************************************
//				STRUCTURE for User												*
//***********************************************************************************************
// Informations of a motion device //
typedef struct
{
	//===========================================
	HANDLE	   hDevice;
	int        uiDeviceId;
	int        uiDeviceNo;
	int	       uiSlotNo;
	int	       uiFwVer;
	int	       uiHwVer;
	int	       uiApiVer;
	int        uiAxesNum;
	int        uiInitAxis;
	int        uiDiNumNo;
	int        uiDiInitCh;
	int        uiDoNumNo;
	int        uiDoInitCh;
	int        uiDeviceSpec;

} TMotMapInfo;

// Informations of motion devices defined by user 
typedef struct{
	//===========================================
	int       uiNumDevs;  // Number of user motion devices
	//===========================================
	int       uiNumAllAxis;
	int       uiNumAllDiCh;
	int       uiNumAllDoCh;
	
	TMotMapInfo taMapInfo[16];
	
}TMotDevMap;

// Informations of a motion-net slave device //
typedef struct
{
	//===========================================
	int        uiDeviceId;
	int        uiConnect;
	int        uiStationNo;
	int        uiDiInitCh;
	int        uiDoInitCh;
	int        uiDiNumNo;
	int        uiDoNumNo;
	int        uiDioSel;

} TMotMNetDevMap;

#ifdef __cplusplus
extern "C" {
#endif



#ifndef PMI_DLL_EXP
	#define PMI_DLL_EXP      _declspec(dllexport)
#endif



//====================== System Management Function ====================================================//
//bManual = TRUE, Con Number is set to dip switch(Default)
//npNumCons In a computer-set number of board
PMI_DLL_EXP int WINAPI pmiSysLoad					(/*[in]*/int bManual,/*[out]*/int *npNumCons );

PMI_DLL_EXP int WINAPI pmiSysUnload					(/*[none]*/ void);
//H/W, S/W리셋 
PMI_DLL_EXP int WINAPI pmiConInit					(/*[in]*/ int nCon);

//====================== Motion Parameter Management Function ====================================================//
//파라미터 파일 읽어오기(.PRM)
PMI_DLL_EXP int WINAPI pmiConParamLoad				(/*[in]*/ const char* szFilename);

//파라미터 파일 저장하기(.PRM)
PMI_DLL_EXP int WINAPI pmiConParamSave				(/*[in]*/ const char* szFilename);


//======================  Motion interface I/O Configure and Control Function ==============================================//
//nState=0, emSERVO_OFF.
//nState=1, emSERVO_ON.
PMI_DLL_EXP int WINAPI pmiAxSetServoOn				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nState );
PMI_DLL_EXP int WINAPI pmiAxGetServoOn				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npState );

//logic=0, active LOW.(Default)
//logic=1, active HIfGH.
//TMC-BAxxP is not Supported a Function.
//TMC-BBxxP is not Supported a Function.
//Preserved for later
PMI_DLL_EXP int WINAPI pmiAxSetServoOnLevel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nLevel );
PMI_DLL_EXP int WINAPI pmiAxGetServoOnLevel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *nLevel );

//nState=0, reset.
//nState=1, set.
PMI_DLL_EXP int WINAPI pmiAxSetServoReset			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nState );
PMI_DLL_EXP int WINAPI pmiAxGetServoReset			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npState );

//inp_logic=0, active LOW.(Default)
//inp_logic=1, active HIGH.
PMI_DLL_EXP int WINAPI pmiAxSetServoInpLevel		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nLevel);
PMI_DLL_EXP int WINAPI pmiAxGetServoInpLevel		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npLevel);

//inp_enable=0, Disabled (Default)
//inp_enable=1, Enabled
PMI_DLL_EXP int WINAPI pmiAxSetServoInpEnable       (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nEnable);
PMI_DLL_EXP int WINAPI pmiAxGetServoInpEnable       (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npEnable);

PMI_DLL_EXP int WINAPI pmiAxGetServoInp		        (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *nInp);

//alm_logic=0, active LOW. (Default)
//alm_logic=1, active HIGH.
PMI_DLL_EXP int WINAPI pmiAxSetServoAlarmLevel		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nLevel);
PMI_DLL_EXP int WINAPI pmiAxGetServoAlarmLevel		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npLevel);

//alm_mode=0, motor immediately stops(Default)
//alm_mode=1, motor decelerates then stops
PMI_DLL_EXP int WINAPI pmiAxSetServoAlarmAction     (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nAction);
PMI_DLL_EXP int WINAPI pmiAxGetServoAlarmAction     (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npAction);

//el_logic=0, active LOW.(Default)
//el_logic=1, active HIGH.
PMI_DLL_EXP int WINAPI pmiAxSetLimitLevel		    (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nLevel);
PMI_DLL_EXP int WINAPI pmiAxGetLimitLevel		    (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npLevel);

//el_act=0, motor immediately stops.(Default)
//el_act=1, motor decelerates then stops.
PMI_DLL_EXP int WINAPI pmiAxSetLimitAction          (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nAction);
PMI_DLL_EXP int WINAPI pmiAxGetLimitAction          (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npAction);

//org_logic=0, active LOW.(Default)
//org_logic=1, active HIGH.
PMI_DLL_EXP int WINAPI pmiAxSetOrgLevel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nLevel);
PMI_DLL_EXP int WINAPI pmiAxGetOrgLevel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npLevel);

//CPhase_logic=0, active LOW.(Default)
//CPhase_logic=1, active HIGH.
PMI_DLL_EXP int WINAPI pmiAxSetEzLevel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nLevel);
PMI_DLL_EXP int WINAPI pmiAxGetEzLevel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npLevel);


//soft limit of positive direction -134,217,728 <= P <= 134,217,727
//soft limit of negative direction -134,217,728 <= N <= 134,217,727
PMI_DLL_EXP int WINAPI pmiAxSetSoftLimitPos			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  double  dLimitP,/*[in]*/  double  dLimitN );
PMI_DLL_EXP int WINAPI pmiAxGetSoftLimitPos			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpLimitP,/*[out]*/ double *dpLimitN );

//Action: The reacting method of soft limit
//Action =0, INT
//Action =1, Immediately stop
//Action =2, slow down then stop
//Action =3, Change Velocity
PMI_DLL_EXP int WINAPI pmiAxSetSoftLimitAction		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nAction );
PMI_DLL_EXP int WINAPI pmiAxGetSoftLimitAction		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npAction );

//0 softlimit disale (default)
//1 softlimit enable
PMI_DLL_EXP int WINAPI pmiAxSetSoftLimitEnable		(/*[in]*/ int nCon,/*[in]*/ int nAxis, /*[in]*/int nEnable );
PMI_DLL_EXP int WINAPI pmiAxGetSoftLimitEnable		(/*[in]*/ int nCon,/*[in]*/ int nAxis, /*[in]*/int *npEnable );

//limit pos ( 0 <= ResetPos <= 134217727)
PMI_DLL_EXP int WINAPI pmiAxSetRCountResetPos		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  double  dPos );
PMI_DLL_EXP int WINAPI pmiAxGetRCountResetPos		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpPos );

//0 ring counter(Position RollOver) disale (default)
//1 ring counter(Position RollOver) enable
PMI_DLL_EXP int WINAPI pmiAxSetRCountEnable			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nEnable );
PMI_DLL_EXP int WINAPI pmiAxGetRCountEnable			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/  int *npEnable );

//erc_logic=0, active LOW.(Default)
//erc_logic=1, active HIGH
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetServoCrcLevel		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nLevel );
PMI_DLL_EXP int WINAPI pmiAxGetServoCrcLevel		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npLevel );

//crc_on_time=0 12us
//crc_on_time=1 102us
//crc_on_time=2 409us
//crc_on_time=3 1.6ms
//crc_on_time=4 13ms
//crc_on_time=5 52ms
//crc_on_time=6 104ms (Default)
//crc_on_time=7 erc level out
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetServoCrcTime			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nOnTime );
PMI_DLL_EXP int WINAPI pmiAxGetServoCrcTime			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npOnTime );

//Automatically outputs an CRC signal when the axis is stopped immediately by a +EL,-EL, ALM, or #CEMG input signal. However, the CRC signal is not output when a
//deceleration stop occurs on the axis. 
//Even if the EL signal is specified for a normal stop, by setting MOD = "010X000" (feed to the EL position) in the RMD register, 
//the CRC signal is output if an immediate stop occurs
//crc_enable=0
//crc_enable=1
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetServoCrcEnable       (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nEnable);
PMI_DLL_EXP int WINAPI pmiAxGetServoCrcEnable       (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npEnable);

//crc signal active command 
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetServoCrcOn	        (/*[in]*/ int nCon,/*[in]*/ int nAxis);

//crc signal deactive command 
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetServoCrcReset        (/*[in]*/ int nCon,/*[in]*/ int nAxis);

//Reset COUNTER when the CLR input turns OFF->ON
//Action = 0, Falling edge clear
//Action = 1, Rising edge clear
//Action = 2, Low Level clear
//Action = 3, Hi Level clear
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetCountAction			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nAction );
PMI_DLL_EXP int WINAPI pmiAxGetCountAction			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npAction );

//Reset COUNTER when the CLR input turns OFF->ON
//Connected to GPIO DI[2]
//enable=0, Disabled (Default)
//enable=1, Enabled
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetCountReset			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nEnable );
PMI_DLL_EXP int WINAPI pmiAxGetCountReset			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npEnable );

//sd_logic=0, active LOW.(Default)
//sd_logic=1, active HIGH.
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetSdLevel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nLevel );
PMI_DLL_EXP int WINAPI pmiAxGetSdLevel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npLevel );

//sd_mode=0, slow down only(Default)
//sd_mode=1, slow down then stop
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetSdAction				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nStop );
PMI_DLL_EXP int WINAPI pmiAxGetSdAction				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npStop );

// SDLT Specify the latch function of the SD input. (0: OFF. 1: ON.)
//sd_latch=0, do not latch.(Default)
//sd_latch=1, latch.
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetSdLatch				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nLatch );
PMI_DLL_EXP int WINAPI pmiAxGetSdLatch				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npLatch );
//Decelerates (deceleration stop) by turning ON the input
////Connected to GPIO DI[0]
//enable=0, Disabled (Default)
//enable=1, Enabled
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetSdEnable				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nEnable );
PMI_DLL_EXP int WINAPI pmiAxGetSdEnable				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npEnable );

//pcs_logic=0, active LOW.(Default)
//pcs_logic=1, active HIGH.
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetPcsLevel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nLevel );
PMI_DLL_EXP int WINAPI pmiAxGetPcsLevel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npLevel );

//While in automatic operation, control the number of pulses after the PCS input is turned ON. (Override 2 for the target position.)
//Connected to GPIO DI[1]
//enable=0, Disabled (Default)
//enable=1, Enabled
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetPcsEnable			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nEnable );
PMI_DLL_EXP int WINAPI pmiAxGetPcsEnable			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npEnable );

//Simultaneously Start Signals STA 
//sta_action=1, active Low Level. (Default)
//sta_action=0, active Falling Edge. 
PMI_DLL_EXP int WINAPI pmiAxSetStaAction			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nAction );
PMI_DLL_EXP int WINAPI pmiAxGetStaAction			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npAction );

//sta_enable=0, Disable a start from the #CSTA input
//sta_enable=1, Enable a start from the #CSTA input
PMI_DLL_EXP int WINAPI pmiAxSetStaEnable			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nEnable );
PMI_DLL_EXP int WINAPI pmiAxGetStaEnable			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npEnable );

//동시 시작 S/W command
PMI_DLL_EXP int WINAPI pmiAxStaBeginCmd	 			( /*[in]*/ int nCon,/*[in]*/ int nAxis );

//0. Immediate stop when the #CSTP signal is turned ON.
//1. Deceleration stop when the #CSTP signal is turned ON.
PMI_DLL_EXP int WINAPI pmiAxSetStpAction			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nAction );
PMI_DLL_EXP int WINAPI pmiAxGetStpAction			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npAction );

//stp_enable=0, Disable a Stop from the #CSTP input
//stp_enable=1, Enable a stop from the #CSTP input
PMI_DLL_EXP int WINAPI pmiAxSetStpEnable			(/*[in]*/int nCon,/*[in]*/int nAxis,/*[in]*/ int  nEnable );
PMI_DLL_EXP int WINAPI pmiAxGetStpEnable			(/*[in]*/int nCon,/*[in]*/int nAxis,/*[out]*/int* npEnable );

//동시 정지 S/W command
PMI_DLL_EXP int WINAPI pmiAxStpBeginCmd	 		( /*[in]*/ int nCon,/*[in]*/ int nAxis );

//target=0, PA/PB.
//target=1, EA/EB/EZ.
//enable=0.
//enable=1.
PMI_DLL_EXP int WINAPI pmiAxSetFilterABEnable		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nTarget,/*[in]*/  int  nEnable );
PMI_DLL_EXP int WINAPI pmiAxGetFilterABEnable		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nTarget,/*[out]*/ int *npEnable );

//target=0, PA/PB.
//target=1, EA/EB/EZ.
//0000 : 40[ns]    0001 : 60[ns]    0010 : 80[ns]    0010 : 100[ns]
//0011 : 120[ns]   0100 : 140[ns]   0101 : 160[ns]   0110 : 180[ns]
//0111 : 200[ns]   1000 : 220[ns]   1001 : 240[ns]   1010 : 260[ns]
//1100 : 280[ns]   1101 : 300[ns]   1110 : 320[ns]   1111 : 340[ns]
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetFilterABTime			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nTarget,/*[in]*/ int  nTime);
PMI_DLL_EXP int WINAPI pmiAxGetFilterABTime			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nTarget,/*[out]*/ int *nTime);

//0 Command pulse(Default)
//1 External Feedback
PMI_DLL_EXP int WINAPI pmiCtrSetCount		         (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nCount );
PMI_DLL_EXP int WINAPI pmiCtrGetCount	             (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npCount );

//Command pulse signal output mode
//0 OUT/DIR OUT Falling edge, DIR+ is high level
//1 OUT/DIR OUT Rising edge,  DIR+ is high level
//2 OUT/DIR OUT Falling edge, DIR+ is low level
//3 OUT/DIR OUT Rising edge,  DIR+ is low level
//4 CW/CCW Falling edge(Default)
//5 CW/CCW Rising edge
//6 CW/CCW Falling edge Inverse
//7 CW/CCW Rising  edge Inverse
//8 Two Phase Mode Pulse Phase lead than Dir
//9 Two Phase Mode Dir   Phase lead than Pulse
PMI_DLL_EXP int WINAPI pmiAxSetPulseType			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nType );
PMI_DLL_EXP int WINAPI pmiAxGetPulseType			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npType );

//Encoder pulse input signal mode
//0x00 1X A/B
//0x01 2X A/B
//0x02 4X A/B(Default)
//0x03 CW/CCW
PMI_DLL_EXP int WINAPI pmiAxSetEncType				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nType );
PMI_DLL_EXP int WINAPI pmiAxGetEncType				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npType );

//Feedback counter UP / DOWN direction is opposite
//0 normal counting(Default)
//1 reverse counting
PMI_DLL_EXP int WINAPI pmiAxSetEncDir				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nDir  );
PMI_DLL_EXP int WINAPI pmiAxGetEncDir				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npDir  );

//0 Command pulse(Default) 
//1 External Feedback     
PMI_DLL_EXP int WINAPI pmiAxSetEncCount				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nCount );
PMI_DLL_EXP int WINAPI pmiAxGetEncCount				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npCount );


//Motion setting the Velocity limit
//0 < dVel <= 6553500 ) [pps]
PMI_DLL_EXP int WINAPI pmiAxSetMaxVel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  double  dVel );
PMI_DLL_EXP int WINAPI pmiAxGetMaxVel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/  double *dpVel );

//Set the jOG start velocity
//0 <= dVel <= 6553500 ) [pps]
PMI_DLL_EXP int WINAPI pmiAxSetInitJogVel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  double  dVel );  
PMI_DLL_EXP int WINAPI pmiAxGetInitJogVel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/  double *dpVel );

//Set the POS start velocity
//0 <= dVel <= 6553500 ) [pps]
PMI_DLL_EXP int WINAPI pmiAxSetInitVel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  double  dVel );
PMI_DLL_EXP int WINAPI pmiAxGetInitVel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/  double *dpVel );

//Jog Motion transfer Velocity setting standards
//nType = 0 Constant
//nType = 1 T-Curve
//nType = 2 S-Curve
//0 <= dVel <= 6553500 [pps]
//0 <= Tacc < 60000  [ms]
PMI_DLL_EXP int WINAPI pmiAxSetJogVelProf			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nProfileType, /*[in]*/  double  dVel,/*[in]*/  double  dTacc );
PMI_DLL_EXP int WINAPI pmiAxGetJogVelProf			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *nProfileType,/*[out]*/ double *dpVel,/*[out]*/ double *dpTacc );

//Motion transfer Velocity setting standards
//nType = 0 Constant
//nType = 1 T-Curve
//nType = 2 S-Curve
//0 <= dVel <= 6553500 [pps]
//0 <= Tacc < 60000  [ms]
//0 <= Tdec < 60000  [ms]
PMI_DLL_EXP int WINAPI pmiAxSetVelProf				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nProfileType, /*[in]*/  double  dVel,/*[in]*/  double  dTacc,/*[in]*/  double  dTdec );
PMI_DLL_EXP int WINAPI pmiAxGetVelProf				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *nProfileType,/*[out]*/ double *dpVel,/*[out]*/ double *dpTacc,/*[out]*/ double *dpTdec );

//Set the deceleration start point detection method
//nType = 0 AutoDetect
//nType = 1 ManulDetect
PMI_DLL_EXP int WINAPI pmiAxSetDecelType			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/   int  nType );
PMI_DLL_EXP int WINAPI pmiAxGetDecelType			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/  int *npType );

//Set the deceleration start point detection method
//nDecel = 0 AutoDetect
//nDecel = 1 ManulDetect
PMI_DLL_EXP int WINAPI pmiAxSetRStopDecel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/   int  nDecel );
PMI_DLL_EXP int WINAPI pmiAxGetRStopDecel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/  int *npDecel );

//The ramping down point is the position where deceleration starts. 
//The data is stored as pulse count, and it cause the axis start to decelerate when remaining pulse count reach the data.
//-8388608 <= dPul <= 8388607
PMI_DLL_EXP int WINAPI pmiAxSetRemainPul			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/   double  dPulse );
PMI_DLL_EXP int WINAPI pmiAxGetRemainPul			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/  double *dpPulse );

//nType= 0 AutoDetect.
//nType= 1 ManulDetect
PMI_DLL_EXP int WINAPI pmiAxSetCorrVelType			(/*[in]*/int nCon,/*[in]*/int nAxisNo,/*[in]*/int nType);
PMI_DLL_EXP int WINAPI pmiAxGetCorrVelType			(/*[in]*/int nCon,/*[in]*/int nAxisNo,/*[out]*/int* npType);

//nType= 1 ManulDetect  설정시 사용
// 1 <= nRatio <= 100
// nRatio = 78 (Default)
PMI_DLL_EXP int WINAPI pmiAxSetCorrVelRatio			(/*[in]*/int nCon,/*[in]*/int nAxisNo,/*[in]*/int nRatio);
PMI_DLL_EXP int WINAPI pmiAxGetCorrVelRatio			(/*[in]*/int nCon,/*[in]*/int nAxisNo,/*[out]*/int* nRatio);

//TMC-BAxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxSetFilterEnable			(/*[in]*/int nCon,/*[in]*/int nAxisNo,/*[in]*/int nEnable);
PMI_DLL_EXP int WINAPI pmiAxGetFilterEnable			(/*[in]*/int nCon,/*[in]*/int nAxisNo,/*[out]*/int* nEnable );
//====================== HOME-RETURN FUNCTIONS ================================================//

PMI_DLL_EXP int WINAPI pmiAxHomeSetResetPos			(/*[in]*/int nCon,/*[in]*/int nAxis,/*[in]*/int nResetPos );
PMI_DLL_EXP int WINAPI pmiAxHomeGetResetPos			(/*[in]*/int nCon,/*[in]*/int nAxis,/*[out]*/int* npResetPos );

//Automatically outputs an CRC signal when the axis is stopped immediately by a ORG input signal. However, the CRC signal is not output when a
//deceleration stop occurs on the axis. 
//Even if the EL signal is specified for a normal stop, by setting MOD = "010X000" (feed to the EL position) in the RMD register, 
//the CRC signal is output if an immediate stop occurs
//crc_enable=0
//crc_enable=1
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiAxHomeSetCrcEnable( /*[in]*/int nCon,/*[in]*/int nAxisNo,/*[in]*/int nEnable );
PMI_DLL_EXP int WINAPI pmiAxHomeGetCrcEnable( /*[in]*/int nCon,/*[in]*/int nAxisNo,/*[out]*/int* nEnable );

//Home search mode setting one axis
//TYPE=0 ORG ON -> Slow down -> Stop 
//TYPE=1 ORG ON -> Stop -> Go back(Rev Spd) -> ORG OFF -> Go forward(Rev Spd) -> ORG ON -> Stop(Default)
//TYPE=2 ORG ON -> Slow down(Low Spd) -> Stop on EZ signal
//TYPE=3 ORG ON -> EZ signal -> Slow down -> Stop
//TYPE=4 ORG ON -> Stop -> Go back(Rev Spd) -> ORG OFF -> Stop on EZ signal
//TYPE=5 ORG ON -> Stop -> Go back(High Spd) -> ORG OFF -> EZ signal -> Slow down -> Stop
//TYPE=6 EL ON -> Stop -> Go back(Rev Spd) -> EL OFF -> Stop
//TYPE=7 EL ON -> Stop -> Go back(Rev Spd) -> EL OFF -> Stop on EZ signal
//TYPE=8 EL ON -> Stop -> Go back(High Spd) -> EL OFF -> Stop on EZ signal
//TYPE=9 ORG ON -> Slow down -> Stop -> Go back -> Stop at beginning edge of ORG
//TYPE=10 ORG ON -> EZ signal -> Slow down -> Stop -> Go back -> Stop at beginning edge of EZ;
//TYPE=11 ORG ON -> Slow down -> Stop -> Go back (High Spd) -> ORG OFF -> EZ signal -> Slow down -> Stop -> Go forward(High Spd) -> Stop at beginning edge of EZ
//TYPE=12 EL ON -> Stop -> Go back (High Spd) -> EL OFF -> EZ signal -> Slow down -> Stop -> Go forward(High Spd) -> Stop at beginning edge of EZ
//TYPE=13 On EZ signal -> Slow down -> Stop
PMI_DLL_EXP int WINAPI pmiAxHomeSetType				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nType );
PMI_DLL_EXP int WINAPI pmiAxHomeGetType				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npType );

//Home search direction of one axis
//#define emDIR_P                      0  //Positive Direction
//#define emDIR_N                      1  //Negative Direction  (Default)
PMI_DLL_EXP int WINAPI pmiAxHomeSetDir				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nDir  );
PMI_DLL_EXP int WINAPI pmiAxHomeGetDir				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npDir  );

//The origin of the origin of the behavior to escape from the distance sensor
//pps ( -134217728 ~ 134217727 )
PMI_DLL_EXP int WINAPI pmiAxHomeSetEscapePul		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  double  dEscape );
PMI_DLL_EXP int WINAPI pmiAxHomeGetEscapePul		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpEscape );

//EZ Count
//nEzCount(1 ~ 16)
PMI_DLL_EXP int WINAPI pmiAxHomeSetEzCount			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nEzCnt );
PMI_DLL_EXP int WINAPI pmiAxHomeGetEzCount			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npEzCnt );

//Driving home from the relative position of one axis to complete the search
//pps ( -134217728 ~ 134217727 )
PMI_DLL_EXP int WINAPI pmiAxHomeSetShiftDist		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  double  dShift );
PMI_DLL_EXP int WINAPI pmiAxHomeGetShiftDist		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpShift );

//pps ( 0 ~ 6553500 )
PMI_DLL_EXP int WINAPI pmiAxHomeSetInitVel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ double  dVel );
PMI_DLL_EXP int WINAPI pmiAxHomeGetInitVel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpVel );


//Home search drive Vel setting one axis
//nType=0 Constant
//nType=1 T-Curve (Default)
//nType=2 S-Curve
//dVel    pps ( 0 ~ 6553500 )
//dRevVel pps ( 0 ~ 6553500 )
//0 <= Tacc < 60000  [ms]
PMI_DLL_EXP int WINAPI pmiAxHomeSetVelProf		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nProfileType,/*[in]*/ double  dVel, /*[in]*/  double dRevVel,  /*[in]*/  double  dTacc);
PMI_DLL_EXP int WINAPI pmiAxHomeGetVelProf		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *nProfileType,/*[out]*/ double *dpVel, /*[out]*/ double *dpRevVel, /*[out]*/ double *dpTacc);

//One axis driving home search
PMI_DLL_EXP int WINAPI pmiAxHomeMove				(/*[in]*/ int nCon,/*[in]*/ int nAxis );

//Multi axis driving home search
PMI_DLL_EXP int WINAPI pmiMxHomeMove				(/*[in]*/ int nCon,/*[in]*/ int nNAxis,/*[in]*/ int naAxis[] );

//Home search check one axis driving
//0 stop
//1 Home search driving
PMI_DLL_EXP int WINAPI pmiAxHomeCheckDone			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *nDone );

PMI_DLL_EXP int WINAPI pmiAxHomeWaitDone			(/*[in]*/ int nCon,/*[in]*/ int nAxisNo );
//Home search has been completed successfully one axis
//0 Home search incomplete one axis
//1 Home search completed one axis
PMI_DLL_EXP int WINAPI pmiAxHomeSetStatus			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nStatus );
PMI_DLL_EXP int WINAPI pmiAxHomeGetStatus			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *nStatus );

//======================  Velocity mode And Single Axis Position Motion Configure  ==============================================//

//Driving one axis continuous operation
//#define PMI_DIR_P                      0  //Positive Direction
//#define PMI_DIR_N                      1  //Negative Direction
PMI_DLL_EXP int WINAPI pmiAxJogMove					(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int  nDir );

//One axis transported to a specified location
//nAbsMode = 0 Driving the relative coordinates
//nAbsMode = 1 Driving the absolute coordinate
//-134217728 <= pos <= 134217727
PMI_DLL_EXP int WINAPI pmiAxPosMove				   (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int  nAbsMode,/*[in]*/  double dPos );

//nDone = 0 stop
//nDone = 1 driving
PMI_DLL_EXP int WINAPI pmiAxCheckDone				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npDone );

PMI_DLL_EXP int WINAPI pmiAxWaitDone				(/*[in]*/ int nCon,/*[in]*/ int nAxis );

//One axis deceleration stop
PMI_DLL_EXP int WINAPI pmiAxStop					(/*[in]*/ int nCon,/*[in]*/ int nAxis );

//One axis emergency stop
PMI_DLL_EXP int WINAPI pmiAxEStop					(/*[in]*/ int nCon,/*[in]*/ int nAxis );

//다른 축 동기 구동 설정 
//sync_mode=0, 내부 동기 사용 안함(즉시 시작) 
//sync_mode=1, 내부 동기 시작 신호에의해 시작 
//sync_mode=2, 지정축의 정지에 의해 시작
PMI_DLL_EXP int WINAPI pmiAxSetSyncType				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int  nType );
PMI_DLL_EXP int WINAPI pmiAxGetSyncType				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npType );

//다른 축 동기 구동 동기 신호
//sync_condition=0 내부 동기 신호 출력 OFF
//sync_condition=1 가속 개시 때 이송 
//sync_condition=2 가속 종료 때 이송
//sync_condition=3 감속 개시 때 이송
//sync_condition=4 감속 종료 때 이송
//sync_condition=5 -SL 신호가 검출 되었을 때 이송 시작
//sync_condition=6 +SL 신호가 검출 되었을 때 이송 시작
//sync_condition=7 범용 비교기기에 설정된 조건이 만족하면 이송 
//sync_condition=8 TRG-CMP 조건이 만족되었을 때 이송을 시작합니다. 
PMI_DLL_EXP int WINAPI pmiAxSetSyncAction			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/int nMaskAxes,/*[in]*/ int  nContion );
PMI_DLL_EXP int WINAPI pmiAxGetSyncAction			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/int nMaskAxes,/*[out]*/ int *npContion );

//======================  Velocity mode And Multi Axis Point to Point Motion Configure  ==============================================//
//Driving multi axis continuous operation
//#define PMI_DIR_P                      0  //Positive Direction
//#define PMI_DIR_N                      1  //Negative Direction
PMI_DLL_EXP int WINAPI pmiMxJogMove					(/*[in]*/ int nCon,/*[in]*/ int nNAxis,/*[in]*/ int naAxis[],/*[in]*/ int naDir[]);

//Multi axis transported to a specified location
//0 Driving the relative coordinates
//1 Driving the absolute coordinate
//-134217728 <= pos <= 134217727
PMI_DLL_EXP int WINAPI pmiMxPosMove				(/*[in]*/ int nCon,/*[in]*/ int nNAxis,/*[in]*/ int nAbsMode, /*[in]*/ int naAxis[],/*[in]*/ double faDist[]);

//motion check multi axis driving
//0 stop
//1 driving
PMI_DLL_EXP int WINAPI pmiMxCheckDone				(/*[in]*/ int nCon,/*[in]*/ int nNAxis,/*[in]*/ int naAxis[],/*[out]*/ int *npDone);

//Multi axis deceleration stop
PMI_DLL_EXP int WINAPI pmiMxStop					(/*[in]*/ int nCon,/*[in]*/ int nNAxis,/*[in]*/ int naAxis[]);

//Multi axis emergency stop
PMI_DLL_EXP int WINAPI pmiMxEStop					(/*[in]*/ int nCon,/*[in]*/ int nNAxis,/*[in]*/ int naAxis[]);

//====================== Motion I/O Monitoring FUNCTIONS =========================================//
//BIT0 EMG pin input
//BIT1 ALM Alarm Signal
//BIT2 +EL Positive Limit Switch
//BIT3 -EL Negative Limit Switch
//BIT4 ORG Origin Switch
//BIT5 DIR DIR output( 0 : +방향 , 1 : -방향)
//BIT6 Home Success
//BIT7 PCS PCS signal input
//BIT8 CRC CRC pin output
//BIT9 EZ Index signal
//BIT10 CLR 입력 신호 상태
//BIT11 Latch Latch signal input
//BIT12 SD Slow Down signal input
//BIT13 INP In-Position signal input
//BIT14 SVON Servo-ON output status
//BIT15 ServoAlarmReset output status
//BIT16 STA signal input
//BIT17 STP signal input
//BIT18 SYNC Pos Error signal input
//BIT19 GANT Pos Erorr signal input
//BIT20 DRV	 구동중
//BIT21 CMP  CMP 동작중
//BIT22 SYNC  SYNC 동작중
//BIT23 GANT  GANT 동작중

PMI_DLL_EXP int WINAPI pmiAxGetMechanical			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ unsigned int *npMechanical );

//BIT0 DRV_STOP:   1;	모션 구동 중
//BIT1 WAIT_DR:    1;	DR 입력 신호 기다림
//BIT2 WAIT_STA:   1;	STA 입력 신호 기다림
//BIT3 WAIT_INSYNC:1;	내부 동기 신호 기다림
//BIT4 WAIT_OTHER: 1;	타축 정지 신호 기다림
//BIT5 WAIT_:   1;	ERC 출력 완료 기다림
//BIT6 WAIT_DIR:   1;	방향 변화를 기다림
//BIT7 BACKLASH:   1;	BACKLASH 상태
//BIT8 WAIT_PE:    1;	PE 입력 신호 기다림
//BIT9 IN_FA:      1;	FA 정속 동작 중 ( 홈 스페셜 속도 )
//BIT10 IN_FL:     1;	FL 정속 동작 중
//BIT11 IN_FUR:    1;	가속 중
//BIT12 IN_FH:     1;	FH 정속 동작 중 
//BIT13 IN_FDR:    1;	감속 중 
//BIT14 WAIT_INP:  1;	INP 입력 신호 기다림
//BIT15 IN_CMP:    1;	CMP 동작중
//BIT16 WAIT_SYNC:  1;	SYNC 동작중
//BIT17 WAIT_GANT: 1;	GANT 동작중
PMI_DLL_EXP int WINAPI pmiAxGetMotion				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ unsigned int *npMotion );

//BIT0 EMG Error
//BIT1 ALM Alarm Signal Error
//BIT2 +EL Positive Limit Switch Error
//BIT3 -EL Negative Limit Switch Error
PMI_DLL_EXP int WINAPI pmiAxGetErrStatus			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ unsigned int *npErrStatus );

//current Vel in pps
PMI_DLL_EXP int WINAPI pmiAxGetCmdVel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpVel );

//feedback current Vel in pps
PMI_DLL_EXP int WINAPI pmiAxGetActVel				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpVel );

//Command position counter value
//-134,217,728 <= <= 143,217,727
PMI_DLL_EXP int WINAPI pmiAxSetCmdPos			    (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  double  dPos );
PMI_DLL_EXP int WINAPI pmiAxGetCmdPos			    (/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpPos );

//Feedback position counter value
//-134,217,728 <= <= 143,217,727
PMI_DLL_EXP int WINAPI pmiAxSetActPos				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  double  dPos );
PMI_DLL_EXP int WINAPI pmiAxGetActPos				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpPos );

//Position error counter value
PMI_DLL_EXP int WINAPI pmiAxSetPosError				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  double  dErrPos );
PMI_DLL_EXP int WINAPI pmiAxGetPosError				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpErrPos );

//Method =0, 조건 성립 하지 않음
//Method =1, Counter 방향과 무관
//Method =2, Counter Up 중
//Method =3, Counter Down 중
//Action =0, 사용하지 않음
//Action =1, Immediately stop
//Action =2, slow down then stop
//Action =3, 속도 변경
PMI_DLL_EXP int WINAPI pmiAxSetPosErrAction		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nMethod, /*[in]*/ int nAction, /*[in]*/ double dPos  );
PMI_DLL_EXP int WINAPI pmiAxGetPosErrAction		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npMethod, /*[out]*/ int *npAction, /*[out]*/ double *dpPos );

//0x0 Command pulse(Default) 
//0x1 External Feedback  
//0x2 PA/PB 
PMI_DLL_EXP int WINAPI pmiAxSetGenCount				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nCount );
PMI_DLL_EXP int WINAPI pmiAxGetGenCount				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npCount );

//This function is used to enable the step losing checking facility. 
//By giving an tolerance value
PMI_DLL_EXP int WINAPI pmiAxSetGenSource		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nSource);
PMI_DLL_EXP int WINAPI pmiAxGetGenSource		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npSource);

//Method =0, 조건 성립 하지 않음
//Method =1, Counter 방향과 무관
//Method =2, Counter Up 중
//Method =3, Counter Down 중

//Action =0, 사용하지 않음
//Action =1, Immediately stop
//Action =2, slow down then stop
//Action =3, 속도 변경
// -134217728 < dPos < 134217727 [pps]
PMI_DLL_EXP int WINAPI pmiAxSetGenAction		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nMethod,/*[in]*/ int nAction, /*[in]*/ double dPos );
PMI_DLL_EXP int WINAPI pmiAxGetGenAction		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npMethod,/*[out]*/ int *npAction, /*[out]*/ double *dpPos );

PMI_DLL_EXP int WINAPI pmiAxSetGenPos			(/*[in]*/ int nCon,/*[in]*/ int nAxisNo,/*[in]*/ double dPos );
PMI_DLL_EXP int WINAPI pmiAxGetGenPos			(/*[in]*/ int nCon,/*[in]*/ int nAxisNo,/*[out]*/ double* dPos );

//This function is select a auto speed change method to use when the comparator conditions are satisfied. 
//By giving an tolerance value

PMI_DLL_EXP int WINAPI pmiAxSetCmpModifySource		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nSource);
PMI_DLL_EXP int WINAPI pmiAxGetCmpModifySource		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npSource);

//Method =0, 조건 성립 하지 않음
//Method =1, Counter 방향과 무관
//Method =2, Counter Up 중
//Method =3, Counter Down 중

//Action =0, 사용하지 않음
//Action =1, Immediately stop
//Action =2, slow down then stop
//Action =3, 속도 변경
// -134217728 < dPos < 134217727 [pps]
PMI_DLL_EXP int WINAPI pmiAxSetCmpModifyAction	(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nMethod,/*[in]*/ int nAction, /*[in]*/ double dPos );
PMI_DLL_EXP int WINAPI pmiAxGetCmpModifyAction	(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npMethod,/*[out]*/ int *npAction, /*[out]*/ double *dpPos );

PMI_DLL_EXP int WINAPI pmiAxSetCmpModifyVel	(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ double dVel );
PMI_DLL_EXP int WINAPI pmiAxGetCmpModifyVel	(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpVel );

//====================== Overriding FUNCTIONS =================================================//
//new target position -134,217,728 <= new pos <= 134,217,727
PMI_DLL_EXP int WINAPI pmiAxModifyPos			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ double dPos ); 
PMI_DLL_EXP int WINAPI pmiMxModifyPos           (/*[in]*/int nCon,/*[in]*/int nNAxis,/*[in]*/int naAxes[], /*[in]*/double daPos[] ); 

//new Vel in pps 1 ~ 6553500
PMI_DLL_EXP int WINAPI pmiAxModifyVel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ double dOvr );
PMI_DLL_EXP int WINAPI pmiMxModifyVel           (/*[in]*/int nCon,/*[in]*/int nNAxis,/*[in]*/int naAxes[],/*[in]*/double daOvr[] );

//new Vel in pps 1 ~ 6553500
//0 <= Tacc < 60000  [ms]
//0 <= Tdec < 60000  [ms]
PMI_DLL_EXP int WINAPI pmiAxModifyVelProf			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ double dVel,/*[in]*/ double dTacc,/*[in]*/ double dTdec);
//====================== Coordinat Motion Control =========================================//
//nCS = 0,1,2,3
PMI_DLL_EXP int WINAPI pmiCsSetAxis					(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[in]*/ int nNAxis,/*[in]*/ int naAxis[] );

PMI_DLL_EXP int WINAPI pmiCsSetInitVel				(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[in]*/ double dVel );
PMI_DLL_EXP int WINAPI pmiCsGetInitVel				(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[out]*/ double *dpVel );

//Op_type = 0 vector vel, 
//Op_type = 1 long axis vel, 
//nType=0 Constant
//nType=1 T-Curve (Default)
//nType=2 S-Curve
PMI_DLL_EXP int WINAPI pmiCsSetVelProf			(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[in]*/  int  nOpType, /*[in]*/ int nProfileType,/*[in]*/  double  dVel,/*[in]*/  double  dTacc,/*[in]*/  double  dTdec );
PMI_DLL_EXP int WINAPI pmiCsGetVelProf			(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[in]*/  int  nOpType, /*[out]*/ int *nProfileType,/*[out]*/ double *dpVel,/*[out]*/ double *dTacc,/*[out]*/ double *dTdec );

//Line Coordinate Motion 
PMI_DLL_EXP int WINAPI pmiCsLinMove				(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[in]*/ int nAbsMode,/*[in]*/ double daPos[] );
PMI_DLL_EXP int WINAPI pmiCsLinMoveEx			(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[in]*/ int nNAxis,/*[in]*/ int naAxis[],/*[in]*/ int nAbsMode,/*[in]*/ double daPos[] );

//End Point Circular Coordinate Motion 
//0 : CW
//1 : CCW 
PMI_DLL_EXP int WINAPI pmiCsArcPMove			(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[in]*/ int nAbsMode,/*[in]*/ double daCen[],/*[in]*/ double daPos[],/*[in]*/ int nDir );
PMI_DLL_EXP int WINAPI pmiCsArcPMoveEx		 	(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[in]*/ int nNAxis,/*[in]*/ int naAxis[],/*[in]*/ int nAbsMode,/*[in]*/ double daCen[],/*[in]*/ double daPos[],/*[in]*/ int nDir );

//Angle Circular Coordinate Motion 
PMI_DLL_EXP int WINAPI pmiCsArcAMove			(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[in]*/ int nAbsMode,/*[in]*/ double daCen[],/*[in]*/ double dAngle );
PMI_DLL_EXP int WINAPI pmiCsArcAMoveEx			(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[in]*/ int nNAxis,/*[in]*/ int naAxis[], /*[in]*/ int nAbsMode,/*[in]*/ double daCen[],/*[in]*/ double dAngle );

//-- Helical Motion -------------------
PMI_DLL_EXP int WINAPI pmiCsHelSetInitVel		(/*[in]*/ int nCon,/*[in]*/ int nHelId,/*[in]*/ double dVel );
PMI_DLL_EXP int WINAPI pmiCsHelGetInitVel		(/*[in]*/ int nCon,/*[in]*/ int nHelId,/*[out]*/ double *dpVel );

PMI_DLL_EXP int WINAPI pmiCsHelSetVelProf		(/*[in]*/ int nCon,/*[in]*/ int nHelId,/*[in]*/ int nProfileType,/*[in]*/  double  dVel,/*[in]*/  double  dTacc,/*[in]*/  double  dTdec );
PMI_DLL_EXP int WINAPI pmiCsHelGetVelProf		(/*[in]*/ int nCon,/*[in]*/ int nHelId,/*[out]*/ int *nProfileType,/*[out]*/ double *dpVel,/*[out]*/ double *dTacc,/*[out]*/ double *dTdec );

PMI_DLL_EXP int WINAPI pmiCsHelMove				(/*[in]*/ int nCon,/*[in]*/ int nHelId, /*[in]*/ double dCenX,/*[in]*/ double dCenY,/*[in]*/ double dPosX,/*[in]*/ double dPosY,/*[in]*/ double dPosZ,/*[in]*/ int nDir );
PMI_DLL_EXP int WINAPI pmiCsHelMoveEx			(/*[in]*/ int nCon,/*[in]*/ int nHelId, /*[in]*/ int nNAxis,/*[in]*/ int naAxis[], /*[in]*/ double dCenX,/*[in]*/ double dCenY,/*[in]*/ double dPosX,/*[in]*/ double dPosY,/*[in]*/ double dPosZ,/*[in]*/ int nDir );

//motion check Coordinate axis driving
//0 stop
//1 driving
PMI_DLL_EXP int WINAPI pmiCsCheckDone				(/*[in]*/ int nCon,/*[in]*/ int nCs,/*[out]*/ int *npDone);

PMI_DLL_EXP int WINAPI pmiCsWaitDone				(/*[in]*/ int nCon,/*[in]*/ int nCs);

PMI_DLL_EXP int WINAPI pmiCsStop					(/*[in]*/ int nCon,/*[in]*/ int nCs);

PMI_DLL_EXP int WINAPI pmiCsEStop				    (/*[in]*/ int nCon,/*[in]*/ int nCs);

//====================== Continuous Motion ========================================================//
//연속 보간 구동을 위해 저장된 내부 Queue를 모두 삭제하는 함수이다.
PMI_DLL_EXP int WINAPI pmiCsContClearQueue		    (/*[in]*/ int nCon);
//지정된 좌표계에 연속보간에서 수행할 작업들의 등록을 시작한다
PMI_DLL_EXP int WINAPI pmiCsContBeginQueue			(/*[in]*/ int nCon);
//지정된 좌표계에서 연속보간을 수행할 작업들의 등록을 종료한다
PMI_DLL_EXP int WINAPI pmiCsContEndQueue			(/*[in]*/ int nCon);
//저장된 내부 연속 보간 Queue의 구동을 시작하는 함수이다
PMI_DLL_EXP int WINAPI pmiCsContMove				(/*[in]*/ int nCon);
//저장된 내부 연속 보간 Queue의 구동을 정지하는 함수이다
PMI_DLL_EXP int WINAPI pmiCsContStop				(/*[in]*/ int nCon);
//연속 보간 구동 중 현재 구동중인 연속 보간 인덱스 번호를 확인하는 함수이다
PMI_DLL_EXP int WINAPI pmiCsContGetCurIndex			(/*[in]*/ int nCon,/*[in]*/ int nLsi, /*[out]*/ int *nIndex);

//====================== Position Compare FUNCTIONS ===========================================//
//cmp_logic=0, active LOW.
//cmp_logic=1, active HIGH.
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiCmpSetLevel			(/*[in]*/ int nCon,/*[in]*/ int nCmp, /*[in]*/ int nLevel );
PMI_DLL_EXP int WINAPI pmiCmpGetLevel			(/*[in]*/ int nCon,/*[in]*/ int nCmp,/*[out]*/ int *npLevel );

//cmp =0, Compare[0]
//cmp =1, Compare[1]
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiCmpSetAxis				(/*[in]*/ int nCon,/*[in]*/ int nCmp, /*[in]*/ int nAxis );
PMI_DLL_EXP int WINAPI pmiCmpGetAxis				(/*[in]*/ int nCon,/*[in]*/ int nCmp, /*[out]*/ int *npAxis );

//position 0 <= pule <= 134,217,727
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiCmpSetHoldTime			(/*[in]*/ int nCon,/*[in]*/ int nCmp, /*[in]*/ int  nPulse );
PMI_DLL_EXP int WINAPI pmiCmpGetHoldTime			(/*[in]*/ int nCon,/*[in]*/ int nCmp, /*[out]*/ int *nPulse );

//cmp_method =0, CmpValue=Counter (+Dir)
//cmp_method =1, CmpValue=Counter (-Dir)
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiCmpSetSinglePos			(/*[in]*/ int nCon,/*[in]*/ int nCmp,/*[in]*/ int nMethod,/*[in]*/ double dPos );

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiCmpSetRangePos			(/*[in]*/ int nCon,/*[in]*/ int nCmp,/*[in]*/ int nMethod,/*[in]*/ double dNPos, /*[in]*/ double dPPos  );

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiCmpSetMultPos				(/*[in]*/ int nCon,/*[in]*/ int nCmp,/*[in]*/ int nMethod,/*[in]*/ int nNum,/*[in]*/ double dSPos,/*[in]*/ double dDist);

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiCmpSetPosTable			(/*[in]*/ int nCon,/*[in]*/ int nCmp,/*[in]*/ int nMethod,/*[in]*/ int nNum,/*[in]*/ double daPos[] );

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiCmpBegin					(/*[in]*/ int nCon,/*[in]*/ int nCmp );
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiCmpEnd					(/*[in]*/ int nCon,/*[in]*/ int nCmp );

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiCmpGetPos					(/*[in]*/ int nCon,/*[in]*/ int nCmp, /*[out]*/ int *npNum,/*[out]*/ double *dpPos );
//====================== Master/Slave Motion Control =========================================//
//nMAxis = Master Axis
//0000 : Axis0 Counter
//0001 : Axis1 Counter
//…
//0111 : Axis7 Counter
//1000 : MPG Counter
//1001 : 보드간 counter
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiSyncSetMaster				(/*[in]*/ int nCon,/*[in]*/ int nMAxis);
PMI_DLL_EXP int WINAPI pmiSyncGetMaster				(/*[in]*/ int nCon,/*[out]*/ int *nMAxis);

//nSAxis = Slave Axis
//mode=0, motor not stops(Default)
//mode=1, motor immediately stops
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiSyncSetAction				(/*[in]*/ int nCon,/*[in]*/ int nSAxis,/*[in]*/  int  nAction);
PMI_DLL_EXP int WINAPI pmiSyncGetAction			    (/*[in]*/ int nCon,/*[in]*/ int nSAxis,/*[out]*/ int *npAction);

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiSyncSetPosErrorLimit		(/*[in]*/ int nCon,/*[in]*/ int nSAxis,/*[in]*/ double dLimit);
PMI_DLL_EXP int WINAPI pmiSyncGetPosErrorLimit		(/*[in]*/ int nCon,/*[in]*/ int nSAxis,/*[out]*/ double *dpLimit);

//Master axis position deviation between the Slave axis
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiSyncGetPosError			(/*[in]*/ int nCon,/*[in]*/ int nSAxis,/*[out]*/ double *dpError,/*[out]*/ double *dpMaxError);

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiSyncBegin					(/*[in]*/ int nCon,/*[in]*/ int nSAxis);
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiSyncEnd					(/*[in]*/ int nCon,/*[in]*/ int nSAxis);

//====================== Gantry Motion Control =========================================//
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiGantSetMaster				(/*[in]*/ int nCon,/*[in]*/ int nId,/*[in]*/ int nMAxis);
PMI_DLL_EXP int WINAPI pmiGantGetMaster				(/*[in]*/ int nCon,/*[in]*/ int nId,/*[out]*/ int *nMAxis);

//mode=0, motor not stops(Default)
//mode=1, motor immediately stops
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiGantSetAction				(/*[in]*/ int nCon,/*[in]*/ int nId,/*[in]*/ int nSAxis,/*[in]*/  int  nAction);
PMI_DLL_EXP int WINAPI pmiGantGetAction			    (/*[in]*/ int nCon,/*[in]*/ int nId,/*[in]*/ int nSAxis,/*[out]*/ int *npAction);

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiGantSetPosErrorLimit		(/*[in]*/ int nCon,/*[in]*/ int nId,/*[in]*/ int nSAxis,/*[in]*/ double dLimit);
PMI_DLL_EXP int WINAPI pmiGantGetPosErrorLimit		(/*[in]*/ int nCon,/*[in]*/ int nId,/*[in]*/ int nSAxis,/*[out]*/ double *dpLimit);

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiGantGetPosError			(/*[in]*/ int nCon,/*[in]*/ int nId,/*[in]*/ int nSAxis,/*[out]*/ double *dpError,/*[out]*/ double *dpMaxError);

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiGantBegin				    (/*[in]*/ int nCon,/*[in]*/ int nId,/*[in]*/ int nSAxis);
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiGantEnd					(/*[in]*/ int nCon,/*[in]*/ int nId,/*[in]*/ int nSAxis);

//====================== Manual Pulsar FUNCTIONS ==============================================//
//PA/PB(MPG) input signal mode
//0x00 1X A/B
//0x01 2X A/B
//0x02 4X A/B
//0x03 CW/CCW(Default)
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiMpgSetInType					(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nType );
PMI_DLL_EXP int WINAPI pmiMpgGetInType					(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npType );
//Reverse the moving direction from pulse direction
//Inverse =0, no inverse
//Inverse =1, Reverse moving direction
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiMpgSetDir						(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nDir );
PMI_DLL_EXP int WINAPI pmiMpgGetDir						(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npDir );

//Set manual pulser ratio for actual output pulse rate. The formula for
//pulser output rate is Output Pulse Speed=(PA_PB Velocity) * 4 * (PMG+1)*PDV/2048
//The PMG=1~32 Multi Factor
//The PDV=1~2048 Divide Factor
//The Output Pulse Velocity=(PA_PB Velocity) * 4 * (PMG+1)*PDV/2048
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiMpgSetGain				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nMultiFactor,/*[in]*/  int  nDivFactor );
PMI_DLL_EXP int WINAPI pmiMpgGetGain				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npMultiFactor,/*[out]*/ int *npDivFactor );

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiMpgBegin					(/*[in]*/ int nCon,/*[in]*/ int nAxis );
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiMpgEnd					(/*[in]*/ int nCon,/*[in]*/ int nAxis );


//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiMpgSetEnable					(/*[in]*/ int nCon,/*[in]*/ int nAxis, /*[in]*/  int  nEnable);
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiMpgGetEnable					(/*[in]*/ int nCon,/*[in]*/ int nAxis, /*[out]*/ int *nEnable);

//====================== Position LATCH FUNCTIONS =======================================================//
//Position Latch
//Latch = external trigger to latch input
//ltc_logic=0, Falling.
//ltc_logic=1, Rising.
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiLtcSetLevel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  int  nLevel);
PMI_DLL_EXP int WINAPI pmiLtcGetLevel			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npLevel);

//Counter = 0 , Command counter
//Counter = 1 , Feedback counter
//Counter = 2 , Error Counter 
//Counter = 3 , General Counter
//Counter = 4 , Command Velocity
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiLtcGetPos					(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/int nCount,/*[out]*/ double *dpPos );

////Connected to DI[3]
//enable=0, Disabled (Default)
//enable=1, Enabled
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiLtcSetEnable				(/*[in]*/ int nCon,/*[in]*/ int nAxisNo,/*[in]*/  int  nEnable);
PMI_DLL_EXP int WINAPI pmiLtcGetEnable				(/*[in]*/ int nCon,/*[in]*/ int nAxisNo,/*[out]*/ int *nEnable);

//====================== interrupt FUNCTIONS ==================================================//
PMI_DLL_EXP int WINAPI pmiIntSetHandler			    (/*[in]*/ int nCon,/*[in]*/ int nType,/*[in]*/ HANDLE hWnd,/*[in]*/ void* hHandler,/*[in]*/ unsigned int nMsg);

PMI_DLL_EXP int WINAPI pmiIntSetHandlerEnable		(/*[in]*/ int nCon,/*[in]*/ int nEnable);

//-------- Axis--------------------------------------------------------------------------------------
//BIT0	; 자동 정지때
//BIT1	; 다음 동작 계속 START 때
//BIT2	; 동작용 2nd pre register 기입 가능 때
//BIT3	; Comparator 5용 2nd pre register 기입 가능 때
//BIT4	; 가속 개시 때
//BIT5	; 가속 종료 때
//BIT6	; 감속 개시 때
//BIT7	; 감속 종료 때
//BIT8	; Compatator1 조건 성립 때
//BIT9	; Compatator2 조건 성립 때
//BIT10	; Compatator3 조건 성립 때
//BIT11	; Compatator4 조건 성립 때
//BIT12	; Compatator6 조건 성립 때
//BIT13	; CLR 신호 입력에 의해 COUNTER 값 RESET 때
//BIT14	; LTC 신호 입력에 의해 COUNTER 값 LATCH 때
//BIT15	; ORG 신호 입력에 의해 COUNTER 값 LATCH 때
//BIT16	; SD 입력 ON 때
//BIT17	; /STA 입력 ON 때

PMI_DLL_EXP int WINAPI pmiIntSetAxisEnable			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/  unsigned int  nMask );

PMI_DLL_EXP int WINAPI pmiIntGetAxisEnable			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ unsigned int *nMask );

//BIT0	; 자동 정지때
//BIT1	; 다음 동작 계속 START 때
//BIT2	; 동작용 2nd pre register 기입 가능 때
//BIT3	; Comparator 5용 2nd pre register 기입 가능 때
//BIT4	; 가속 개시 때
//BIT5	; 가속 종료 때
//BIT6	; 감속 개시 때
//BIT7	; 감속 종료 때
//BIT8	; Compatator1 조건 성립 때
//BIT9	; Compatator2 조건 성립 때
//BIT10	; Compatator3 조건 성립 때
//BIT11	; Compatator4 조건 성립 때
//BIT12	; Compatator6 조건 성립 때
//BIT13	; CLR 신호 입력에 의해 COUNTER 값 RESET 때
//BIT14	; LTC 신호 입력에 의해 COUNTER 값 LATCH 때
//BIT15	; ORG 신호 입력에 의해 COUNTER 값 LATCH 때(사용안함)
//BIT16	; SD 입력 ON 때
//BIT19	; /STA 입력 ON 때

PMI_DLL_EXP int WINAPI pmiIntGetAxisStatus			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ unsigned int *npStatus );

//BIT0 STOP_BY_SLP:   1;	양의 소프트 리미트에 의해 정지
//BIT1 STOP_BY_SLN:   1;	음의 소프트 리미트에 의해 정지
//BIT2 STOP_BY_CMP3:  1;	비교기3에 의해 정지
//BIT3 STOP_BY_CMP4:  1;	비교기4에 의해 정지
//BIT4 STOP_BY_CMP5:  1;	비교기5에 의해 정지
//BIT5 STOP_BY_ELP:   1;	+EL 에 의해 정지
//BIT6 STOP_BY_ELN:   1;	-EL 에 의해 정지
//BIT7 STOP_BY_ALM:   1;	알람에 의해 정지
//BIT8 STOP_BY_STP:   1;	CSTP에 의해 정지
//BIT9 STOP_BY_EMG:   1;	EMG에 의해 정지
//BIT10 STOP_BY_SD:   1;	SD 입력에 의해 정지
//BIT11 STOP_BY_DT:   1;	보간 동작 DATA 이상에 의해 정지
//BIT12 STOP_BY_IP:   1;	보간 동작 중에 타 축의 이상 정지에 의해 동시 정지
//BIT13 STOP_BY_PO:   1;	PA/PB 입력용 buffer counter dml overflow 에 의해 정지
//BIT14 STOP_BY_AO:   1;	보간 동작 때의 위치 범위를 벗어나서 정지
//BIT15	STOP_BY_EE:   1;	EA/EB 입력 에러 발생 (정지 하지 않음)
//BIT16	STOP_BY_PE:   1;	PA/PB 입력 에러 발생 (정지 하지 않음)

PMI_DLL_EXP int WINAPI pmiIntGetAxisErrStatus  		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ unsigned int *npStatus );

//-------- DI----------------------------------------------------------------------------------------
//0 nId => 0  ~ 31
//1 nId => 32 ~ 63
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiIntSetDiEnable			(/*[in]*/ int nCon,/*[in]*/ int nId,/*[in]*/  unsigned int  nMask );
//0 nId => 0  ~ 31
//1 nId => 32 ~ 63
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiIntGetDiStatus			(/*[in]*/ int nCon,/*[in]*/ int nId,/*[out]*/ unsigned int *npStatus );

//====================== Digital In/Out FUNCTIONS =============================================//
//0 nId => 0  ~ 31
//1 nId => 32 ~ 63
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiDiGetData					(/*[in]*/int nCon,/*[in]*/ int nId,/*[out]*/ unsigned int *npData);

//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiDiGetBit					(/*[in]*/int nCon,/*[in]*/ int nBit,/*[out]*/ unsigned int *npData);

//0 nId => 0  ~ 31
//1 nId => 32 ~ 63
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiDoSetData					(/*[in]*/int nCon,/*[in]*/ int nId,/*[in]*/ unsigned int  nData);
PMI_DLL_EXP int WINAPI pmiDoGetData					(/*[in]*/int nCon,/*[in]*/ int nId,/*[out]*/ unsigned int *npData);
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiDoSetBit					(/*[in]*/int nCon,/*[in]*/ int nBit,/*[in]*/ unsigned int  nData);
PMI_DLL_EXP int WINAPI pmiDoGetBit					(/*[in]*/int nCon,/*[in]*/ int nBit,/*[out]*/ unsigned int *npData);

//0 nId => 0  ~ 15
//1 nId => 16 ~ 31
//2 nId => 32 ~ 47
//3 nId => 48 ~ 63
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiDiSetFilterEnable			(/*[in]*/ int nCon,/*[in]*/ int nId, /*[in]*/ int  nEnable);
PMI_DLL_EXP int WINAPI pmiDiGetFilterEnable			(/*[in]*/ int nCon,/*[in]*/ int nId, /*[out]*/ int *npEnable);

//0 nId => 0  ~ 15
//1 nId => 16 ~ 31
//2 nId => 32 ~ 47
//3 nId => 48 ~ 63
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiDiSetFilterTime			(/*[in]*/ int nCon,/*[in]*/ int nId,/*[in]*/ int  nTime);
PMI_DLL_EXP int WINAPI pmiDiGetFilterTime			(/*[in]*/ int nCon,/*[in]*/ int nId,/*[out]*/ int *npTime);

//======================  Motion Correction Control  ==============================================//
//백래시/SLIP 보정
//-134217728 <= pos <= 134217727
//Specified number of corrective pulses
//Mode0 : disable (default)
//Mode1 : Backlash 
//Mode2 : Slip
//pulse ( 0 <= backlash_pulse <= 4095)
//Velocity ( 0 <= backlash_Velocity <= 6553500)
//Bit0 : command counter
//Bit1 : feedback counter
//Bit2 : deviation counter
//Bit3 : general counter
PMI_DLL_EXP int WINAPI pmiAxSetBacklashComps		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nCorrMode,/*[in]*/  double  dCorrPos,/*[in]*/  double  dCorrVel, /*[in]*/  int  nCtrMask );
PMI_DLL_EXP int WINAPI pmiAxGetBacklashComps		(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npCorrMode,/*[out]*/ double *dpCorrPos,/*[out]*/ double *dporrVel, /*[out]*/  int*  npCtrMask );

//진동제어 기능 
//T1: Specified Reverse Time ( 0 <= RT <= 65535)
//T2: Specified Forward Time ( 0 <= RT <= 65535)
PMI_DLL_EXP int WINAPI pmiAxSetSuppressVibration	(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ double  dRevTime,/*[in]*/  double dForTime );
PMI_DLL_EXP int WINAPI pmiAxGetSuppressVibration	(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ double *dpRevTime,/*[out]*/double *dpForTime );

//====================== DEBUG-LOGGING FUNCTIONS ==============================================//
PMI_DLL_EXP int WINAPI pmiDLogSetFile				(/*[in]*/ const char *szFilename );
PMI_DLL_EXP int WINAPI pmiDLogGetFile				(/*[out]*/ char *szFilename );

PMI_DLL_EXP int WINAPI pmiDLogSetLevel				(/*[in]*/ int nLevel);
PMI_DLL_EXP int WINAPI pmiDLogGetLevel				(/*[out]*/ int *nLevel);

PMI_DLL_EXP int WINAPI pmiDLogSetEnable				(/*[in]*/ int nEnable);
PMI_DLL_EXP int WINAPI pmiDLogGetEnable  			(/*[out]*/ int *nEnable);
//====================== ERROR HANDLING FUNCTIONS =============================================//
PMI_DLL_EXP int WINAPI pmiErrGetCode	             (/*[in]*/ int nCon, /*[out]*/ int *nCode );

PMI_DLL_EXP int WINAPI pmiErrGetString		         (/*[in]*/ int nCon, /*[in]*/ int nCode,/*[out]*/ char* szStr );

PMI_DLL_EXP int WINAPI pmiErrAxGetCode    		     (/*[in]*/ int nCon, /*[in]*/ int nAxis,/*[out]*/ int *pCode );

//====================== GENERAL FUNCTIONS ==============================================//
//Setting the simulation mode
//0 Do not use the simulation mode(Default)
//1 Using the simulation mode
PMI_DLL_EXP int WINAPI pmiAxSetSimulEnable			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int  nEnable);
PMI_DLL_EXP int WINAPI pmiAxGetSimulEnable			(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[out]*/ int *npEnable);

PMI_DLL_EXP int WINAPI pmiAxSetVelRatio				(/*[in]*/int nCon,/*[in]*/int nAxisNo, /*[in]*/double dVel,/*[in]*/double dTacc,/*[in]*/double dTdec );
PMI_DLL_EXP int WINAPI pmiAxGetVelRatio				(/*[in]*/int nCon,/*[in]*/int nAxisNo,/*[out]*/double* dVel,/*[out]*/double* dTacc,/*[out]*/double* dTdec );

//+el.-el.sd.org. alm.inp
//+el.-el.sd.org. alm.inp
//0 <= nTime <= 15
/*설정 입력 신호의 레벨	신호 지연 시간
	CLK=16MHz時）	설정 입력 신호의 레벨	신호 지연 시간（CLK=16MHz時）
	PALF3	PALF2	PALF1	PALF0				PALF3	PALF2	PALF1	PALF0	
	Low		Low		Low		Low		1 μsec	    Hi		Low		Low		Low		0.256 msec
	Low		Low		Low		Hi		2 μsec	    Hi		Low		Low		Hi		0.512 msec
	Low		Low		Hi		Low		4 μsec		Hi		Low		Hi		Low		1.02 msec(default)
	Low		Low		Hi		Hi		8 μsec		Hi		Low		Hi		Hi		2.05 msec
	Low		Hi		Low		Low		16 μsec	Hi		Hi		Low		Low		4.10 msec
	Low		Hi		Low		Hi		32 μsec	Hi		Hi		Low		Hi		8.19 msec
	Low		Hi		Hi		Low		64 μsec	Hi		Hi		Hi		Low		16.4 msec
	Low		Hi		Hi		Hi		128 μsec	Hi		Hi		Hi		Hi		32.8 msec
*/
//TMC-BBxxP is not Supported a Function.
PMI_DLL_EXP int WINAPI pmiGnSetFilterTime			(/*[in]*/ int nCon,/*[in]*/ int  nTime);
PMI_DLL_EXP int WINAPI pmiGnGetFilterTime			(/*[in]*/ int nCon,/*[out]*/ int *nTime);

//긴급 정지 신호 레벨 
PMI_DLL_EXP int WINAPI pmiGnSetEmgLevel				(/*[in]*/ int nCon, /*[in]*/  int  nLevel );
PMI_DLL_EXP int WINAPI pmiGnGetEmgLevel				(/*[in]*/ int nCon, /*[out]*/ int *npLevel );

//해당 보드에 모션을 긴급 정지 명령어
PMI_DLL_EXP int WINAPI pmiGnSetEStop				(/*[in]*/ int nCon );

//모션 보드에 설치된 축 개수 
PMI_DLL_EXP int WINAPI pmiGnGetAxesNum				(/*[in]*/ int nCon,/*[out]*/ int* nNAxesNum);

//모션 보드에 설치된 디지털 범용 I/O 개수
PMI_DLL_EXP int WINAPI pmiGnGetDioNum				(/*[in]*/ int nCon,/*[out]*/ int* nNDiChNum, /*[out]*/ int* nNDoChNum);

//실제 모터 속도 사용 여부
PMI_DLL_EXP int WINAPI pmiGnSetCheckActVel			(/*[in]*/  int nEnable,/*[in]*/ int nInterval);
PMI_DLL_EXP int WINAPI pmiGnGetCheckActVel			(/*[out]*/ int* nEnable,/*[out]*/ int* npInterval);

//모델명 읽어오기
PMI_DLL_EXP int WINAPI pmiConGetModel				(/*[in]*/ int nCon,/*[out]*/ int *npModel );

//특주 모델명 읽어오기
PMI_DLL_EXP int WINAPI pmiConGetModelEx				(/*[in]*/ int nCon,/*[out]*/ int *npModel );

//F/W 버전 읽어오기
PMI_DLL_EXP int WINAPI pmiConGetFwVersion			(/*[in]*/ int nCon,/*[out]*/ int *npVer );

//H/W 버전 읽어오기
PMI_DLL_EXP int WINAPI pmiConGetHwVersion			(/*[in]*/ int nCon,/*[out]*/ int *npVer );

//DLL 버전 읽어오기
PMI_DLL_EXP int WINAPI pmiConGetMApiVersion			(/*[in]*/ int nCon,/*[out]*/ int *npVer );

//보드 LED ON/OFF
PMI_DLL_EXP int WINAPI pmiConSetCheckOn				(/*[in]*/ int nCon,/*[in]*/ int nOn );
PMI_DLL_EXP int WINAPI pmiConGetCheckOn				(/*[in]*/ int nCon,/*[out]*/ int *nOn );

PMI_DLL_EXP int WINAPI pmiGnSetRegister				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nRNo,/*[in]*/  int  nValue);
PMI_DLL_EXP int WINAPI pmiGnGetRegister				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nRNo,/*[out]*/ int *npValue);

PMI_DLL_EXP int WINAPI pmiGnGetString				(/*[in]*/ int nCon,/*[in]*/ int nAxis,/*[in]*/ int nStrID,/*[out]*/ char* szBuffer );

//동시 시작 H/W 
PMI_DLL_EXP int WINAPI pmiGnSetStaSignal			(/*[in]*/ int nCon, /*[in]*/ int nEnable);
PMI_DLL_EXP int WINAPI pmiGnGetStaSignal			(/*[in]*/ int nCon, /*[in]*/ int *nEnable);

//동시 정지 H/W 
PMI_DLL_EXP int WINAPI pmiGnSetStpSignal			(/*[in]*/ int nCon, /*[in]*/ int nEnable);
PMI_DLL_EXP int WINAPI pmiGnGetStpSignal			(/*[in]*/ int nCon, /*[in]*/ int *nEnable);

PMI_DLL_EXP int WINAPI pmiSyncGetAxes				(/*[in]*/ int nCon,/*[out]*/ int *nMAxisNo, /*[out]*/ int *nSAxis );
PMI_DLL_EXP int WINAPI pmiGantGetAxes				(/*[in]*/ int nCon,/*[in]*/ int nId,/*[out]*/ int *nMAxisNo,/*[out]*/ int *nSAxisNo );

PMI_DLL_EXP int WINAPI pmiGnGetMotDevMap            (/*[out]*/TMotDevMap *TMotDevBuf);


#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of PMI_MAPI_H definition

//===========================================================================
// End of file.
//===========================================================================
