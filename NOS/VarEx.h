#include "Define.h"
///////////////////////////////////VISION ����/////////////////////////////////////
extern long ImageWidth;              // Overlay image size x
extern long ImageHeight;             // Overlay image size y
extern BOOL OverlayIsEnable[3];       // Overlay show state
extern BOOL fOverlayIsInitialized[3]; // Overlay initialization state
extern bool gbOnLive;
extern double gdAngle;
extern char m_szCamName[2][100];          // �� �̸�
extern char m_szSerialNum[2][100];        // Serial Number
extern char m_szInterface[2][100];        // Inter face ���
extern int  m_iCamNumber;                       // ����� ī�޶� ��
extern int  m_iCamPosition[2];            // ����� ī�޶� ����
extern int  m_iCameraIndex;                     // ���α׷����� ����� ī�޶� �ε��� �ѹ� 
extern int  m_error;
extern unsigned char **pImageresizeOrgBuffer[2];                   // Mono resize �̹��� ����     	
extern unsigned char **pImageColorDestBuffer[2];                   // Color resize �̹��� ����

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

///////////////////////////////////MOTION ����/////////////////////////////////////

struct    MotorBaseData {
		  long lX1;
		  long lY1;
		  long lZ1;
		  long lX2;
		  long lY2;
} ;
extern	MotorBaseData   SpeedFH ;	// �� ���͸��� High Speed�϶� FH�� 
extern	MotorBaseData   SpeedAcc ;  //�����͸��� High Speed�϶� Acc��
extern	MotorBaseData   SpeedDec ;  //�����͸��� High Speed�϶� Dec��
extern	MotorBaseData   SpeedHome ;  //�����͸��� High Speed�϶� Dec��
extern	MotorBaseData   SpeedJog ;  //�����͸��� High Speed�϶� Dec��

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

//////////////////////////////////////��Ÿ����///////////////////////////////
extern int gnXCnt;
extern int gnYCnt;
extern long glMotDelay;
extern long glCycleTime1;
extern double gdRatioT1;
extern long glTactTime1;
extern int gnLightPort;
extern int gnLightValue;
extern bool gbManualCheck;


