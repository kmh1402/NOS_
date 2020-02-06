///////////////////////////////////VISION 관련/////////////////////////////////////
long ImageWidth;              // Overlay image size x
long ImageHeight;             // Overlay image size y
BOOL OverlayIsEnable[3];       // Overlay show state
BOOL fOverlayIsInitialized[3]; // Overlay initialization state
bool gbOnLive;
double gdAngle;
char m_szCamName[2][100];          // 모델 이름
char m_szSerialNum[2][100];        // Serial Number
char m_szInterface[2][100];        // Inter face 방식
int  m_iCamNumber;                       // 연결된 카메라 수
int  m_iCamPosition[2];            // 연결된 카메라 순서
int  m_iCameraIndex;                     // 프로그램에서 사용할 카메라 인덱스 넘버 
int  m_error;
unsigned char **pImageresizeOrgBuffer[2];                   // Mono resize 이미지 버퍼     	
unsigned char **pImageColorDestBuffer[2];                   // Color resize 이미지 버퍼

bool   bStopThread[2];               // LiveThread flag
bool   bLiveFlag[2];

int gnCirSel1;
int gnCirSel2;
int gnCirSel3;
int gnCirSize1;
int gnCirSize2;
int gnCirSize3;
bool gbInitDlgFirst;

int gdScore;
double gdCenterX;
double gdCenterY;
int gnRad;
double gdCal_X;
double gdCal_Y;

/////////////////////////////////Motion 관련 ////////////////////////////////////
MotorBaseData   SpeedFH ;	// 각 모터마다 High Speed일때 FH값 
MotorBaseData   SpeedAcc ;  //각모터마다 High Speed일때 Acc값
MotorBaseData   SpeedDec ;  //각모터마다 High Speed일때 Dec값
MotorBaseData   SpeedHome ;  //각모터마다 High Speed일때 Dec값
MotorBaseData   SpeedJog ;  //각모터마다 High Speed일때 Dec값

bool gbOriginStart; 

POSITIONDATA	gTeach;
RUNFLAG	gNOS;

bool gbThreadEnd;
bool gbOrgEnd;

int gnJogSpeed;
bool gbSameProjectStart;
int gnXCnt;
int gnYCnt;
long glJogSpeed;
CString	gcsNewPW;
bool gbPWFail;
long glMotDelay;
long glJogPos;
long glCycleTime1;
double gdRatioT1;
long glTactTime1;
int gnLightPort;
int gnLightValue;
bool gbManualCheck;

