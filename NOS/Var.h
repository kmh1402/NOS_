///////////////////////////////////VISION ����/////////////////////////////////////
long ImageWidth;              // Overlay image size x
long ImageHeight;             // Overlay image size y
BOOL OverlayIsEnable[3];       // Overlay show state
BOOL fOverlayIsInitialized[3]; // Overlay initialization state
bool gbOnLive;
double gdAngle;
char m_szCamName[2][100];          // �� �̸�
char m_szSerialNum[2][100];        // Serial Number
char m_szInterface[2][100];        // Inter face ���
int  m_iCamNumber;                       // ����� ī�޶� ��
int  m_iCamPosition[2];            // ����� ī�޶� ����
int  m_iCameraIndex;                     // ���α׷����� ����� ī�޶� �ε��� �ѹ� 
int  m_error;
unsigned char **pImageresizeOrgBuffer[2];                   // Mono resize �̹��� ����     	
unsigned char **pImageColorDestBuffer[2];                   // Color resize �̹��� ����

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

/////////////////////////////////Motion ���� ////////////////////////////////////
MotorBaseData   SpeedFH ;	// �� ���͸��� High Speed�϶� FH�� 
MotorBaseData   SpeedAcc ;  //�����͸��� High Speed�϶� Acc��
MotorBaseData   SpeedDec ;  //�����͸��� High Speed�϶� Dec��
MotorBaseData   SpeedHome ;  //�����͸��� High Speed�϶� Dec��
MotorBaseData   SpeedJog ;  //�����͸��� High Speed�϶� Dec��

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

