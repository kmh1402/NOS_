#include "Define.h"
///////////////////////////////////VISION 관련/////////////////////////////////////
extern long ImageWidth;              // Overlay image size x
extern long ImageHeight;             // Overlay image size y
extern BOOL OverlayIsEnable[3];       // Overlay show state
extern BOOL fOverlayIsInitialized[3]; // Overlay initialization state
extern bool gbOnLive;
extern double gdAngle;
extern char m_szCamName[2][100];          // 모델 이름
extern char m_szSerialNum[2][100];        // Serial Number
extern char m_szInterface[2][100];        // Inter face 방식
extern int  m_iCamNumber;                       // 연결된 카메라 수
extern int  m_iCamPosition[2];            // 연결된 카메라 순서
extern int  m_iCameraIndex;                     // 프로그램에서 사용할 카메라 인덱스 넘버 
extern int  m_error;
extern unsigned char **pImageresizeOrgBuffer[2];                   // Mono resize 이미지 버퍼     	
extern unsigned char **pImageColorDestBuffer[2];                   // Color resize 이미지 버퍼

extern bool   bStopThread[2];               // LiveThread flag
extern bool   bLiveFlag[2];

extern int gnCirSel1;
extern int gnCirSel2;
extern int gnCirSel3;
extern int gnCirSize1;
extern int gnCirSize2;
extern int gnCirSize3;
extern int gdScore;
extern double gdCenterX;
extern double gdCenterY;
extern int gnRad;
extern double gdCal_X;
extern double gdCal_Y;

///////////////////////////////////MOTION 관련/////////////////////////////////////

struct    MotorBaseData {
		  long lX1;
		  long lY1;
		  long lZ1;
		  long lX2;
		  long lY2;
} ;
extern	MotorBaseData   SpeedFH ;	// 각 모터마다 High Speed일때 FH값 
extern	MotorBaseData   SpeedAcc ;  //각모터마다 High Speed일때 Acc값
extern	MotorBaseData   SpeedDec ;  //각모터마다 High Speed일때 Dec값
extern	MotorBaseData   SpeedHome ;  //각모터마다 High Speed일때 Dec값
extern	MotorBaseData   SpeedJog ;  //각모터마다 High Speed일때 Dec값

extern bool gbOriginStart;

struct POSITIONDATA	{
		long lRdy_X;
		long lRdy_Y;
		long lRdy_Z;
		long lRdy_T1;
		long lInter_Z;
};
extern POSITIONDATA	gTeach;

struct RUNFLAG	{
		bool bStart;
		bool bStop;
		bool bError;
		bool bStopToStart;
		CString csErrorCode;
};
extern RUNFLAG	gNOS;
extern bool gbThreadEnd;
extern bool gbOrgEnd;
extern bool gbInitDlgFirst;
extern bool gbOnLive;
extern int gnJogSpeed;	
extern bool gbSameProjectStart;
extern long glJogSpeed;
extern CString	gcsNewPW;
extern bool gbPWFail; 
extern long glJogPos;

//////////////////////////////////////기타설정///////////////////////////////
extern int gnXCnt;
extern int gnYCnt;
extern long glMotDelay;
extern long glCycleTime1;
extern double gdRatioT1;
extern long glTactTime1;
extern int gnLightPort;
extern int gnLightValue;
extern bool gbManualCheck;


