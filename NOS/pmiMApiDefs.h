/******************************************************************************
*
*	File Version: 1,0,0,0
*
*	Copyright(c) 2012 Alpha Motion Co,. Ltd. All Rights Reserved.
*
*	This file is strictly confidential and do not distribute it outside.
*
*	MODULE NAME :
*		pmiMApiDefs.h
*
*	AUTHOR :
*		K.C. Lee
*
*	DESCRIPTION :
*		the header file for RC files of pfroject.
*
*
* - Phone: +82-31-303-5050
* - Fax  : +82-31-303-5051
* - URL  : http://www.alphamotion.co.kr,
*
*
/****************************************************************************/
#ifndef TMC_MAPI_DEFS_H
#define TMC_MAPI_DEFS_H
	

#ifdef __cplusplus
extern "C" {
#endif



// VALUE�� MIN�� MAX ������ ���ΰ� ?
#ifndef InBound
#define InBound(MIN, MAX, VALUE)		((MIN) <= (VALUE) && (VALUE) <= (MAX) ? TRUE : FALSE)
#endif	// InBound

// VALUE�� MIN���� ���� ���̸� MIN, MAX���� ū ���̸� MAX, MIN�� MAX������ ���̸� VALUE�� ����
#ifndef Bound
#define Bound(MIN, MAX, VALUE)			((MIN) > (VALUE) ? (MIN) : ((MAX) < (VALUE) ? (MAX) : (VALUE)))
#endif

// �ݿø�
#ifndef round
#define round(x)						(x >= 0)?(INT32)(x + 0.5):(INT32)(x -0.5)
#endif	// round


// Device ID definition //
#define   TMC_BA800P					0xB8     
#define   TMC_BA600P					0xB6
#define   TMC_BA400P					0xB4
#define   TMC_BA200P					0xB2

#define   TMC_BB160P					0xCF
#define   TMC_BB120P					0xCC


#define   TMC_BB8MNP					0xD8
#define   TMC_BB4MNP					0xD4
#define   TMC_BB0MNP					0xD0
#define   TMC_BB800P					0xC8
#define   TMC_BB400P					0xC4


// Definition of maximum number of things //

//Device Max
#define  TMC_MAX_MOT_DEV                 16  // Maximum number of Motion Devices in one PC
#define  TMC_MAX_MOT_AXES                16  // Maximum number of motion axes

#define  TMC_MAX_DI						 48 // Maximum number of D/I channels
#define  TMC_MAX_DO						 48 // Maximum number of D/O channels


//String
#define TMC_MAX_STR  	                  256 //Maximum String Length

// Slave Max
#define  TMC_MAX_SLAVE_DEC				 64 // Maximum number of Slave Device in one Motion-Net



//����� �̺�Ʈ �޽���
#define TMC_WM_INTERRUPT	 (WM_USER + 2000)




// Motion Chip Registers //
enum {	
	  MSTS  =  0, RMV,   PRMV,  RFL,   PRFL,  RFH,   PRFH,  RUR,   PRUR,  RDR,   PRDR,  RMG,   PRMG,  RDP,   PRDP, 
	  RMD   = 15, PRMD,  RIP,   PRIP,  RUS,   PRUS,  RDS,   PRDS,  RFA,   RENV1, RENV2, RENV3, RENV4, RENV5, RENV6, RENV7, 
      RCUN1 = 31, RCUN2, RCUN3, RCUN4, RCMP1, RCMP2, RCMP3, RCMP4, RCMP5, PRCP5, RIRQ,  RLTC1, RLTC2, RLTC3, RLTC4, 
	  RSTS  = 46, REST,  RIST,  RPLS,  RSPD,  RPSDC, RCI,  RIPS,  RCIC,
	  RFCUN = 55, RFSER, RFSMR, RFGER0, RFGMR0, RFGER1, RFGMR1, RFGER2, RFGMR2, RFGER3, RFGMR3
};


//***********************************************************************************************
//				CONSTATNS for User												*
//***********************************************************************************************

// Axis index definition //
#define emAX0						0
#define emAX1						1
#define emAX2						2
#define emAX3						3
#define emAX4						4
#define emAX5						5
#define emAX6						6
#define emAX7						7
#define emAX8						8
#define emAX9						9
#define emAXA						10
#define emAXB						11
#define emAXC						12
#define emAXD						13
#define emAXE						14
#define emAXF						15


// Definition for axes mask  //
#define emAX0_MASK 					0x00000001
#define emAX1_MASK 					0x00000002
#define emAX2_MASK 					0x00000004
#define emAX3_MASK 					0x00000008
#define emAX4_MASK 					0x00000010
#define emAX5_MASK 					0x00000020
#define emAX6_MASK 					0x00000040
#define emAX7_MASK 					0x00000080
#define emAX8_MASK 					0x00000100
#define emAX9_MASK 					0x00000200
#define emAXA_MASK 					0x00000400
#define emAXB_MASK 					0x00000800
#define emAXC_MASK 					0x00001000
#define emAXD_MASK 					0x00002000
#define emAXE_MASK 					0x00004000
#define emAXF_MASK 					0x00008000


// Definition for axes mask  //
#define emGAX0_BIT 					0x00000000
#define emGAX1_BIT 					0x00000001
#define emGAX2_BIT 					0x00000002
#define emGAX3_BIT 					0x00000003
#define emGAX4_BIT 					0x00000004
#define emGAX5_BIT 					0x00000005
#define emGAX6_BIT 					0x00000006
#define emGAX7_BIT 					0x00000007
#define emGMPG_BIT 					0x00000008
#define emGPAB_BIT 					0x00000009


/////////////////////////////////////////////////////////////////
#define emBIT_OFF					0
#define emBIT_ON					1

#define	 emOFF			 			0
#define  emON			    		1

// Boolean type definition //
#define emFALSE 					0
#define emTRUE 						1

// Used type definition //
#define emNUSED 					0
#define emUSED		 				1

#define emDISABLED 					0
#define emENABLED	 				1


// Used type definition //
#define emLOW						0 
#define emHIGH						1

// Used type definition //
#define emLOGIC_A					0 
#define emLOGIC_B					1


// motion type definition 	
#define	 emSTAND                0 /*steady*/
#define  emRUNNING              1 /*running*/

// stop type definition //
#define emESTOP 						0
#define emSSTOP 						1 
#define emSTOP  						1 

//Operation direction 
#define  emDIR_P                0 /*(+)Dir*/
#define  emDIR_N                1/*(-)Dir*/

// speed profile type definition //
#define emPROF_C				 0   //Constant Speed Profile
#define emPROF_T                 1  //Trapezoidal Speed Profile
#define emPROF_S                 2  //S-Curve Speed Profile
#define emPROF_N                 3  //Curve Speed Profile


// speed profile type definition 
#define	emCONST                 0
#define emTCURVE                1 
#define emSCURVE                2
#define emNCURVE                3


#define emINC                   0	/*Relative*/ 
#define emABS                   1	/*Absolute*/

// Arc operation direction //
#define emCW                    0  //Clockwise Direction         ( Angle Decreases  < 0)
#define emCCW                   1  //Counter Clockwise Direction ( Angle Increases  > 0)

#define emOPEN_LOOP					0   //OPEN CLOSE LOOP
#define emSEMI_LOOP					1   //SEMI CLOSE LOOP
#define emFULL_LOOP					2   //FULL CLOSE LOOP(���� ����)

// Bit order of pmiAxGetMechanical() return value  //
#define emMEC_S_EMG 					0x000000001 // EMG �Է� ��ȣ ����
#define emMEC_S_ALM 					0x000000002 // �˶� �Է� ��ȣ ����
#define emMEC_S_ELP  					0x000000004 // POSITIVE ����Ʈ ����ġ �Է� ��ȣ ����
#define emMEC_S_ELN  					0x000000008 // NEGATIVE ����Ʈ ����ġ �Է� ��ȣ ����
#define emMEC_S_ORG  					0x000000010 // ORIGIN ����ġ �Է� ��ȣ ����
#define emMEC_S_DIR 					0x000000020 // ���� ���� ���� ( 0 : +���� , 1 : -����) 
#define emMEC_S_OK	 					0x000000040 // HOME_OK �Է� ��ȣ ����
#define emMEC_S_PCS 					0x000000080 // PCS �Է� ��ȣ ����
#define emMEC_S_CRC  					0x000000100 // CRC ��� ��ȣ ����
#define emMEC_S_EZ 						0x000000200 // EZ �Է� ��ȣ ����
#define emMEC_S_CLR  					0x000000400 // CLR �Է� ��ȣ ����
#define emMEC_S_LTC  					0x000000800 // LATCH �Է� ��ȣ ����
#define emMEC_S_SD   					0x000001000 // SLOW DOWN �Է� ��ȣ ����
#define emMEC_S_INP 					0x000002000 // IN-POSITION �Է� ��ȣ ����
#define emMEC_S_SVON				    0x000004000 //SVON ��ȣ ����
#define emMEC_S_ARST				    0x000008000 //SERVO ALARM RESET ��ȣ ����
#define emMEC_S_STA  					0x000010000 // STA �Է� ��ȣ ����
#define emMEC_S_STP  					0x000020000 // STP �Է� ��ȣ ����
#define emMEC_S_ESYNC  					0x000040000 // SYNC ���� �Է� ��ȣ ����
#define emMEC_S_EGANT  					0x000080000 // GANTRY ���� ���� �Է� ��ȣ ����
#define emMEC_S_DRV  					0x000100000 // ������
#define emMEC_S_CMP  					0x000200000 // ��ġ�� �����
#define emMEC_S_SYNC  					0x000400000 // SYNC �����
#define emMEC_S_GANT  					0x000800000 // GANTRY �����


#define  emDRV_STOP 					0x00000001 // ��� ���� ��
#define  emWAIT_DR 						0x00000002 // DR �Է� ��ȣ ��ٸ�
#define  emWAIT_STA 					0x00000004 // STA �Է� ��ȣ ��ٸ�
#define  emWAIT_INSYNC 					0x00000008 // ���� ���� ��ȣ ��ٸ�
#define  emWAIT_OTHER 					0x00000010 // Ÿ�� ���� ��ȣ ��ٸ�
#define  emWAIT_CRC 					0x00000020 // CRC ��� �Ϸ� ��ٸ�
#define  emWAIT_DIR 					0x00000040 // ���� ��ȭ�� ��ٸ�
#define  emBACKLASH 					0x00000080 // BACKLASH ����
#define  emWAIT_MPG 					0x00000100 // PA/PB �Է� ��ȣ ��ٸ�
#define  emIN_FA 						0x00000200 // FA ���� ���� �� ( Ȩ ����� �ӵ� )
#define  emIN_FL 						0x00000400 // FL ���� ���� ��
#define  emIN_FUR 						0x00000800 // ���� ��
#define  emIN_FH 						0x00001000 // FH ���� ���� �� 
#define  emIN_FDR 						0x00002000 // ���� �� 
#define  emWAIT_INP 					0x00004000 // INP �Է� ��ȣ ��ٸ�

// LEVEL type definition //
#define emLEVEL_LOW 					0 
#define emLEVEL_HIGH 					1 

// stp stop type definition //
#define emSTP_NSTOP 					0 
#define emSTP_ESTOP 					1 
#define emSTP_SSTOP 					2 

//soft limit action
#define emSOFT_NONE 					0 
#define emSOFT_ESTOP 					1 
#define emSOFT_SSTOP 					2 
#define emSOFT_CHVEL 					3 

// remain pulse stop type definition //
#define emAUTO 				     	0
#define emMANUAL 					1

#define emSD_INIT 					0 
#define emSD_STOP 					1
#define emSD_LATCH 					0 	
// 
#define emERR_NONE 		   			    0 /*������� ����*/ 
#define emERR_ESTOP 					1 /*��   ����*/
#define emERR_STOP 					2 /*���� ����*/
#define emERR_CHGVEL					3 /*�ӵ� ����*/

// Encoder input mode definition //
#define emEAB1X 					0x00
#define emEAB2X 					0x01 
#define emEAB4X 					0x02 
#define emCWCCW 					0x03 

//  PA/PB input mode definition //
#define emPAB1X 					0x00
#define emPAB2X 					0x01
#define emPAB4X 					0x02
#define emPCWCCW 					0x03

// Command output mode definition //
#define emONE_LOW_HIGH_LOW 			0x00
#define emONE_HIGH_HIGH_LOW 		0x01
#define emONE_LOW_LOW_HIGH 			0x02
#define emONE_HIGH_LOW_HIGH 		0x03
#define emTWO_CW_CCW_LOW 			0x04
#define emTWO_CW_CCW_HIGH 			0x05
#define emTWO_CCW_CW_LOW 			0x06
#define emTWO_CCW_CW_HIGH 			0x07
#define emTWO_PHASE 				0x08
#define emTWO_PHASE_RESERVE         0x09 

#define emCOMM                  0/*Command*/
#define emFEED                  1/*Feedback*/
#define emPAPB					2/*PA/B*/
#define emDEV                   2/*Deviation*/ 
#define emGEN                   3/*General*/
#define emCURVEL                4/*����ӵ�*/

#define emEQ_PDIR               0   //CmpData = CmpSrc_Value ( while counting up )
#define emEQ_NDIR               1  // CmpData = CmpSrc_Value ( while counting down )


// sta method definition //	
#define emSTA_SOFTWARE			  0 /*Software */
#define emSTA_HARDWARE			  1 /* Hardware*/

// sta action definition //	
#define emACT_LEVEL					0  /* Level Trigger */
#define emACT_FALL					1  /* Edge Trigger*/

// Compare Type //
#define emCMP_IDX0					0  /*compare[0]*/
#define emCMP_IDX1					1  /*compare[1]*/
#define emCMP_IDX2					2  /*compare[2]*/
#define emCMP_IDX3					3  /*compare[3]*/

// Gantry Type //
#define emGANT_IDX0					0  /*Gantry[0]*/
#define emGANT_IDX1					1  /*Gantry[1]*/
#define emGANT_IDX2					2  /*Gantry[2]*/
#define emGANT_IDX3					3  /*Gantry[3]*/

// motion type definition //	
#define emFORWARD					0/*forward*/
#define emRESERVE 					1 /*reserved*/

// Action when general comparator met the condition //
#define emEVT_ONLY					0  // ���ͷ�Ʈ�� �߻�
#define emEVT_ESTOP					1  // ���ͷ�Ʈ �� �� ����
#define emEVT_STOP					2  // ���ͷ�Ʈ �� ������ ����
#define emEVT_SPDCHG				        3  // ���ͷ�Ʈ �� �ӵ�����

// Backlash/Slip correction mode //
#define  emCORR_DIS					0 // Disable correction 
#define  emCORR_BACK				1 // Backlash correction mode 
#define  emCORR_SLIP				2 // Slip correction mode

//position trigger output level
#define  emRISING					    0
#define  emFALLING						1

// Interrupt Handler Type //
#define  emIHT_MESSAGE					0
#define  emIHT_CALLBACK					1
#define  emIHT_EVENT 		        	2

// SetFilterAB�� ��� //
#define  emPULSAR_AB			        0
#define  emENC_AB				      	1

#define  emHOME_POS_RST0		        0 	// ORG(/EL/EZ) ��ȣ�� �߻��� �� COMMAND & FEEDBACK ��ġ�� 0���� Ŭ�����Ѵ�.
#define  emHOME_POS_RST1				1	// �������͸� ��� �Ϸ��ϰ� ���� COMMAND & FEEDBACK ��ġ�� ��� 0���� Ŭ�����Ѵ�.
#define  emHOME_POS_RST2				2	// �������͸� ��� �Ϸ��ϰ� ���� FEEDBACK ��ġ�� �״�� �ΰ� COMMAND ��ġ�� FEEDBACK ��ġ�� ��ġ��Ų��.

#define emHOME_NG                       0  	// �������͸� ���������� �Ϸ����� ����
#define emHOME_OK                       1	// �������͸� ���������� �Ϸ���.

// Sync mode //
#define  emSYNC_DISABLE					0
#define  emSYNC_INT_SYNC				1
#define  emSYNC_OTHER_STOP				2

// Internal sync. conditions //
#define  emISYNC_ACC_STA				1	// 1: at start of acceleration
#define  emISYNC_ACC_END				2	// 2: at end of acceleration
#define  emISYNC_DEC_STA				3	// 3: at start of deceleration
#define  emISYNC_DEC_END				4	// 4: at end of deceleration
#define  emISYNC_SLN					5	// 5: when (-)software limit met
#define  emISYNC_SLP					6	// 6: when (+)software limit met
#define  emISYNC_GCMP					7	// 7: when General Comparator condition is satisfied
#define  emISYNC_TCMP					8	// 8: when Trigger Comparator condition is satisfied


//Coordinate Systems
#define emMAX_CS                     4 //Maximum Number of Coordinate Systems

//Coordinate System No.
#define emCS0                        0
#define emCS1                        1
#define emCS2                        2
#define emCS3                        3

//Coordinate System No.
#define emHEL0                        0
#define emHEL1                        1
#define emHEL2                        2
#define emHEL3                        3

//Coordinate System Mask
#define emCS0_MASK                   0x00000001
#define emCS1_MASK                   0x00000002
#define emCS2_MASK                   0x00000004
#define emCS3_MASK                   0x00000008
#define emCS4_MASK                   0x00000010
#define emCS5_MASK                   0x00000020
#define emCS6_MASK                   0x00000040
#define emCS7_MASK                   0x00000080
#define emCS8_MASK                   0x00000100
#define emCS9_MASK                   0x00000200
#define emCSA_MASK                   0x00000400
#define emCSB_MASK                   0x00000800
#define emCSC_MASK                   0x00001000
#define emCSD_MASK                   0x00002000
#define emCSE_MASK                   0x00004000
#define emCSF_MASK                   0x00008000


// Internal sync. conditions //
#define  emCNS_VECTOR                0   //0:Vector Vel
#define  emCNS_MASTER	             1   //1:Long Axis Vel

// Function Log Level //
#define  emDLOG_NONE			 0   //LOG ��� ���� ����
#define  emDLOG_ERROR_ONLY	     1   //������ �߻��� ��� 
#define  emDLOG_MOT_SET		     2   //��� ���� �Լ� + ���� �Լ�(SET)  
#define  emDLOG_DO_SET		     3   //LEVEL 2 + ��ȯ �Լ�(SET) + ������ ��� �Լ�(DO)
#define  emDLOG_DI_SET		     4   //LEVEL 3 + ������ �Է� �Լ�(DI) 
#define  emDLOG_ALL	    	     5   //����

// Motion net
#define  emCOMM_SPEED2_5	     0  // 2.5Mbps ��� �ӵ�  
#define  emCOMM_SPEED5		     1  // 5Mbps   ��� �ӵ�   
#define  emCOMM_SPEED10		     2  // 10Mbps  ��� �ӵ�  
#define  emCOMM_SPEED20		     3  // 25Mbps  ��� �ӵ�

//�����̺� �߿��� SB-MN16GPIO-M ��ǰ 
#define  emNONE_DIO               0   //  ��� ����
#define  emONLY_DI                1   //  �Է� ���� 
#define  emONLY_DO                2   //  ��� ����



// =======================================
// == IO Bit
// =======================================
#define TMC_BIT_OFF					0
#define TMC_BIT_ON					1

// Boolean type definition //
#define TMC_FALSE 					0
#define TMC_TRUE 					1

// Used type definition //
#define TMC_NOTUSED 				0
#define TMC_USED		 			1

// Used type definition //
#define TMC_LOW                     0 
#define TMC_HIGH                    1

// Axis index definition //
#define TMC_AX0 					0
#define TMC_AX1 					1
#define TMC_AX2 					2
#define TMC_AX3 					3
#define TMC_AX4 					4
#define TMC_AX5 					5
#define TMC_AX6 					6
#define TMC_AX7 					7
#define TMC_AX8 					8
#define TMC_AX9 					9
#define TMC_AXA 					10
#define TMC_AXB 					11
#define TMC_AXC 					12
#define TMC_AXD 					13
#define TMC_AXE 					14
#define TMC_AXF 					15


// Definition for axes mask  //
#define TMC_AX0_MASK 					0x00000001
#define TMC_AX1_MASK 					0x00000002
#define TMC_AX2_MASK 					0x00000004
#define TMC_AX3_MASK 					0x00000008
#define TMC_AX4_MASK 					0x00000010
#define TMC_AX5_MASK 					0x00000020
#define TMC_AX6_MASK 					0x00000040
#define TMC_AX7_MASK 					0x00000080
#define TMC_AX8_MASK 					0x00000100
#define TMC_AX9_MASK 					0x00000200
#define TMC_AXA_MASK 					0x00000400
#define TMC_AXB_MASK 					0x00000800
#define TMC_AXC_MASK 					0x00001000
#define TMC_AXD_MASK 					0x00002000
#define TMC_AXE_MASK 					0x00004000
#define TMC_AXF_MASK 					0x00008000



#define TMC_OPEN_LOOP					0   //OPEN CLOSE LOOP
#define TMC_SEMI_LOOP					1   //SEMI CLOSE LOOP
#define TMC_FULL_LOOP					2   //FULL CLOSE LOOP(���� ����)

// Bit order of pmiAxGetMechanical() return value  //
#define TMC_MEC_S_EMG 					0x000000001 // EMG �Է� ��ȣ ����
#define TMC_MEC_S_ALM 					0x000000002 // �˶� �Է� ��ȣ ����
#define TMC_MEC_S_ELP  					0x000000004 // POSITIVE ����Ʈ ����ġ �Է� ��ȣ ����
#define TMC_MEC_S_ELN  					0x000000008 // NEGATIVE ����Ʈ ����ġ �Է� ��ȣ ����
#define TMC_MEC_S_ORG  					0x000000010 // ORIGIN ����ġ �Է� ��ȣ ����
#define TMC_MEC_S_DIR 					0x000000020 // ���� ���� ���� ( 0 : +���� , 1 : -����) 
#define TMC_MEC_S_OK	 				0x000000040 // HOME_OK �Է� ��ȣ ����
#define TMC_MEC_S_PCS 					0x000000080 // PCS �Է� ��ȣ ����
#define TMC_MEC_S_CRC  					0x000000100 // CRC ��� ��ȣ ����
#define TMC_MEC_S_EZ 					0x000000200 // EZ �Է� ��ȣ ����
#define TMC_MEC_S_CLR  					0x000000400 // CLR �Է� ��ȣ ����
#define TMC_MEC_S_LTC  					0x000000800 // LATCH �Է� ��ȣ ����
#define TMC_MEC_S_SD   					0x000001000 // SLOW DOWN �Է� ��ȣ ����
#define TMC_MEC_S_INP 					0x000002000 // IN-POSITION �Է� ��ȣ ����
#define TMC_MEC_S_SVON                  0x000004000 //SVON ��ȣ ����
#define TMC_MEC_S_ARST                  0x000008000 //SERVO ALARM RESET ��ȣ ����
#define TMC_MEC_S_STA  					0x000010000 // STA �Է� ��ȣ ����
#define TMC_MEC_S_STP  					0x000020000 // STP �Է� ��ȣ ����
#define TMC_MEC_S_SYNC  				0x000040000 // SYNC ���� �Է� ��ȣ ����
#define TMC_MEC_S_GANT  				0x000080000 // GANTRY ���� ���� �Է� ��ȣ ����

#define  TMC_DRV_STOP 					0x00000001 // ��� ���� ��
#define  TMC_WAIT_DR 					0x00000002 // DR �Է� ��ȣ ��ٸ�
#define  TMC_WAIT_STA 					0x00000004 // STA �Է� ��ȣ ��ٸ�
#define  TMC_WAIT_INSYNC 				0x00000008 // ���� ���� ��ȣ ��ٸ�
#define  TMC_WAIT_OTHER 				0x00000010 // Ÿ�� ���� ��ȣ ��ٸ�
#define  TMC_WAIT_CRC 					0x00000020 // CRC ��� �Ϸ� ��ٸ�
#define  TMC_WAIT_DIR 					0x00000040 // ���� ��ȭ�� ��ٸ�
#define  TMC_BACKLASH 					0x00000080 // BACKLASH ����
#define  TMC_WAIT_PE 					0x00000100 // PA/PB �Է� ��ȣ ��ٸ�
#define  TMC_IN_FA 						0x00000200 // FA ���� ���� �� ( Ȩ ����� �ӵ� )
#define  TMC_IN_FL 						0x00000400 // FL ���� ���� ��
#define  TMC_IN_FUR 					0x00000800 // ���� ��
#define  TMC_IN_FH 						0x00001000 // FH ���� ���� �� 
#define  TMC_IN_FDR 					0x00002000 // ���� �� 
#define  TMC_WAIT_INP 					0x00004000 // INP �Է� ��ȣ ��ٸ�
#define  TMC_IN_CMP 					0x00008000 // CMP ������
#define  TMC_WAIT_SYNC 					0x00010000 // SYNC �Է� ��ȣ ��ٸ�
#define  TMC_WAIT_GANT 					0x00020000 // GANT �Է� ��ȣ ��ٸ�



// LEVEL type definition //
#define TMC_LOGIC_A 					0 
#define TMC_LOGIC_B 					1 

#define TMC_LEVEL_LOW 					0 
#define TMC_LEVEL_HIGH 					1 

// stp stop type definition //
#define TMC_STP_NSTOP 					0 
#define TMC_STP_ESTOP 					1 
#define TMC_STP_STOP 					2 

// stop type definition //
#define TMC_ESTOP 						0
#define TMC_STOP 						1 

//soft limit action
#define TMC_SOFT_NONE 					0 
#define TMC_SOFT_ESTOP 					1 
#define TMC_SOFT_STOP 					2 
#define TMC_SOFT_CHVEL 					3 

// remain pulse stop type definition //
#define TMC_AUTO 					0
#define TMC_MANUAL 					1

#define TMC_SD_SLOW 					0 
#define TMC_SD_STOP 					1	


#define TMC_ERR_NONE 					0 /*������� ����*/ 
#define TMC_ERR_ESTOP 					1 /*��   ����*/
#define TMC_ERR_STOP 					2 /*���� ����*/
#define TMC_ERR_CHGVEL					3 /*�ӵ� ����*/

// Encoder input mode definition //
#define TMC_EAB1X 					0x00
#define TMC_EAB2X 					0x01 
#define TMC_EAB4X 					0x02 
#define TMC_CWCCW 					0x03 

//  PA/PB input mode definition //
#define TMC_PAB1X 					0x00
#define TMC_PAB2X 					0x01
#define TMC_PAB4X 					0x02
#define TMC_PCWCCW 					0x03

// Command output mode definition //
#define TMC_ONE_LOW_HIGH_LOW 			0x00
#define TMC_ONE_HIGH_HIGH_LOW 			0x01
#define TMC_ONE_LOW_LOW_HIGH 			0x02
#define TMC_ONE_HIGH_LOW_HIGH 			0x03
#define TMC_TWO_CW_CCW_LOW 				0x04
#define TMC_TWO_CW_CCW_HIGH 			0x05
#define TMC_TWO_CCW_CW_LOW 				0x06
#define TMC_TWO_CCW_CW_HIGH 			0x07
#define TMC_TWO_PHASE 					0x08
#define TMC_TWO_PHASE_RESERVE           0x09 

// motion type definition //	
#define TMC_STAND 						0x00 /*steady*/
#define TMC_RUNNING 					0x01 /*running*/

// motion type definition //	
#define TMC_FORWARD						0/*forward*/
#define TMC_RESERVE 					1 /*reserved*/

#define TMC_DIR_P                     	0  //Positive Direction
#define TMC_DIR_N                       1  //Negative Direction

// Position Move type definition //
#define TMC_INC                        0  //Incremental Position 
#define TMC_ABS                        1  //Absolute Position

// Arc operation direction //
#define TMC_CW						   0  //Clockwise Direction         ( Angle Decreases  < 0)
#define TMC_CCW						   1  //Counter Clockwise Direction ( Angle Increases  > 0)

// Counter name //
#define TMC_COMM					0 /*Command*/
#define TMC_ACT						1 /*Feedback*/
#define TMC_DEV						2 /*Deviation*/ 
#define TMC_GEN						3 /*General*/
#define TMC_CURVEL					4 /*����ӵ�*/

// speed profile type definition //
#define TMC_PROF_C					   0   //Constant Speed Profile
#define TMC_PROF_T                    1  //Trapezoidal Speed Profile
#define TMC_PROF_S                    2  //S-Curve Speed Profile

// sta method definition //	
#define TMC_STA_SOFTWARE					    0 /*Software */
#define TMC_STA_HARDWARE					1 /* Hardware*/

// sta action definition //	
#define TMC_ACT_LEVEL					0  /* Level Trigger */
#define TMC_ACT_FALL					1  /* Edge Trigger*/

// Compare Method //
#define TMC_EQ_PDIR						0  // CmpData = CmpSrc_Value ( while counting up )
#define TMC_EQ_NDIR						1  // CmpData = CmpSrc_Value ( while counting down )

// Compare Type //
#define TMC_CMP_IDX0					0  /*compare[0]*/
#define TMC_CMP_IDX1					1  /*compare[1]*/
#define TMC_CMP_IDX2					2  /*compare[2]*/
#define TMC_CMP_IDX3					3  /*compare[3]*/

// Gantry Type //
#define TMC_GANT_IDX0					0  /*Gantry[0]*/
#define TMC_GANT_IDX1					1  /*Gantry[1]*/
#define TMC_GANT_IDX2					2  /*Gantry[2]*/
#define TMC_GANT_IDX3					3  /*Gantry[3]*/

// Method when general comparator met the condition //
#define TMC_MTH_NONE					0  // ���� ���� ���� ����
#define TMC_MTH_EQ_DIR				    1  // Counter ����� ����
#define TMC_MTH_EQ_PDIR				    2  // Counter Up ��
#define TMC_MTH_EQ_NDIR				    3  // Counter Down ��

// Action when general comparator met the condition //
#define TMC_EVT_ONLY					0  // ó������ ���� (���ͷ�Ʈ�� �߻�)
#define TMC_EVT_ESTOP					1  // ����
#define TMC_EVT_STOP					2  // ������ ����
#define TMC_EVT_SPDCHG				    3  // �ӵ�����


// Backlash/Slip correction mode //
#define  TMC_CORR_DIS					0 // Disable correction 
#define  TMC_CORR_BACK				    1 // Backlash correction mode 
#define  TMC_CORR_SLIP				    2 // Slip correction mode

//position trigger output level
#define  TMC_RISING					    0
#define  TMC_FALLING					1


// Interrupt Handler Type //
#define  TMC_IHT_MESSAGE				0
#define  TMC_IHT_CALLBACK				1
#define  TMC_IHT_EVENT 			        2

// SetFilterAB�� ��� //
#define  TMC_ENC_AB				      	0
#define  TMC_PULSAR_AB			        1

#define  TMC_HOME_POS_RST0		        0 	// ORG(/EL/EZ) ��ȣ�� �߻��� �� COMMAND & FEEDBACK ��ġ�� 0���� Ŭ�����Ѵ�.
#define  TMC_HOME_POS_RST1			1	// �������͸� ��� �Ϸ��ϰ� ���� COMMAND & FEEDBACK ��ġ�� ��� 0���� Ŭ�����Ѵ�.
#define  TMC_HOME_POS_RST2			2	// �������͸� ��� �Ϸ��ϰ� ���� FEEDBACK ��ġ�� �״�� �ΰ� COMMAND ��ġ�� FEEDBACK ��ġ�� ��ġ��Ų��.

// Sync mode //
#define  TMC_SYNC_DISABLE             0
#define  TMC_SYNC_INT_SYNC            1
#define  TMC_SYNC_OTHER_STOP          2

// Internal sync. conditions //
#define  TMC_ISYNC_ACC_STA			0	// 0: at start of acceleration
#define  TMC_ISYNC_ACC_END			1	// 1: at end of acceleration
#define  TMC_ISYNC_DEC_STA			2	// 2: at start of deceleration
#define  TMC_ISYNC_DEC_END			3	// 3: at end of deceleration
#define  TMC_ISYNC_SLN				4	// 4: when (-)software limit met
#define  TMC_ISYNC_SLP				5	// 5: when (+)software limit met
#define  TMC_ISYNC_GCMP				6	// 6: when General Comparator condition is satisfied
#define  TMC_ISYNC_TCMP				7	// 7: when Trigger Comparator condition is satisfied


//Coordinate Systems
#define TMC_MAX_CS                     4 //Maximum Number of Coordinate Systems

//Coordinate System No.
#define TMC_CS0                        0
#define TMC_CS1                        1
#define TMC_CS2                        2
#define TMC_CS3                        3

#define TMC_HEL0                        0
#define TMC_HEL1                        1
#define TMC_HEL2                        2
#define TMC_HEL3                        3


//Coordinate System Mask
#define TMC_CS0_MASK                   0x00000001
#define TMC_CS1_MASK                   0x00000002
#define TMC_CS2_MASK                   0x00000004
#define TMC_CS3_MASK                   0x00000008
#define TMC_CS4_MASK                   0x00000010
#define TMC_CS5_MASK                   0x00000020
#define TMC_CS6_MASK                   0x00000040
#define TMC_CS7_MASK                   0x00000080
#define TMC_CS8_MASK                   0x00000100
#define TMC_CS9_MASK                   0x00000200
#define TMC_CSA_MASK                   0x00000400
#define TMC_CSB_MASK                   0x00000800
#define TMC_CSC_MASK                   0x00001000
#define TMC_CSD_MASK                   0x00002000
#define TMC_CSE_MASK                   0x00004000
#define TMC_CSF_MASK                   0x00008000


// Internal sync. conditions //
#define  TMC_CNS_VECTOR              0   //0:Vector Vel
#define  TMC_CNS_MASTER	             1   //1:Long Axis Vel

// Function Log Level //
#define  TMC_DLOG_LEVEL0			 0   //LOG ��� ���� ����
#define  TMC_DLOG_LEVEL1		     1   //������ �߻��� ��� 
#define  TMC_DLOG_LEVEL2		     2   //��� ���� �Լ� + ���� �Լ�(SET)  
#define  TMC_DLOG_LEVEL3		     3   //LEVEL 2 + ��ȯ �Լ�(SET) + ������ ��� �Լ�(DO)
#define  TMC_DLOG_LEVEL4		     4   //LEVEL 3 + ������ �Է� �Լ�(DI) 
#define  TMC_DLOG_LEVEL5		     5   //����

#define  TMC_COMM_SPEED2_5		     0  // 2.5Mbps ��� �ӵ�  
#define  TMC_COMM_SPEED5		     1  // 5Mbps   ��� �ӵ�   
#define  TMC_COMM_SPEED10		     2  // 10Mbps  ��� �ӵ�  
#define  TMC_COMM_SPEED20		     3  // 25Mbps  ��� �ӵ�

//�����̺� �߿��� SB-MN16GPIO-M ��ǰ 
#define  TMC_NONE_DIO               0   //  ��� ����
#define  TMC_ONLY_DI                1   //  �Է� ���� 
#define  TMC_ONLY_DO                2   //  ��� ����


/* Return code () */ 
/////////////////////////////////////////////////////////////////

#define TMC_RV_OK		      1   //����


/////////////////////////////////////////////////////////////////
#define TMC_RV_MOT_INIT_ERR			  -100   //���̺귯�� �ʱ�ȭ ����
#define TMC_RV_MOT_FILE_SAVE_ERR      -101   //��� �������� �����ϴ� ���� ���忡 ������
#define TMC_RV_MOT_FILE_LOAD_ERR      -102   //��� �������� ����� ������ �ε尡 �ȵ�

/////////////////////////////////////////////////////////////////
#define TMC_RV_STOP_P_S_END_ERR        -200  //(+) ���� ����Ʈ���� ����Ʈ�� ���� ����
#define TMC_RV_STOP_N_S_END_ERR        -201  //(-) ���� ����Ʈ���� ����Ʈ�� ���� ����
#define TMC_RV_STOP_CMP3_ERR	       -202  //CMP3 �� ���� ����
#define TMC_RV_STOP_CMP4_ERR	       -203  //CMP4 �� ���� ����
#define TMC_RV_STOP_CMP5_ERR	       -204  //CMP5 �� ���� ����
#define TMC_RV_STOP_P_H_END_ERR        -205  //(+) ���� �ϵ���� ����Ʈ�� ���� ����
#define TMC_RV_STOP_N_H_END_ERR        -206  //(-) ���� �ϵ���� ����Ʈ�� ���� ���� 
#define TMC_RV_STOP_ALM_ERR            -207  //���� �˶��� ���� ����
#define TMC_RV_STOP_CSTP_ERR           -208  //CSTP ��ȣ�� ���� ����
#define TMC_RV_STOP_EMG_ERR            -209  //��� ���� ��ȣ�� ���� ����
#define TMC_RV_STOP_ESSD_ERR	       -210  //SD �Է� ON �� ���� ����
#define TMC_RV_STOP_ESDT_ERR           -211  //���� ���� DATA �̻� ���� ����
#define TMC_RV_STOP_ESIP_ERR           -212  //���� ���� �߿� Ÿ���� �̻� ���� ����
#define TMC_RV_STOP_ESPO_ERR           -213  //PA/PB �Է¿� ���� �� �����÷ο� �߻��� ���� ����
#define TMC_RV_STOP_ESAO_ERR           -214  //���� ���� �� ��ġ������ ī������ ī���� ���� OVER �߻��� ���� ����
#define TMC_RV_STOP_ESEE_ERR           -215  //EA/EB �Է� ERROR �߻� ��(���� ���� ����)
#define TMC_RV_STOP_ESPE_ERR           -216  //PA/PB �Է� ERROR �߻� ��(���� ���� ����)
#define TMC_RV_STOP_SYNC_ERR           -217  //SYNC ���� �߿� ������ ��� ���� �� ���� ����
#define TMC_RV_STOP_GANT_ERR           -218  //GANT ���� �߿� ������ ��� ���� �� ���� ����

/////////////////////////////////////////////////////////////////
#define TMC_RV_DRV_VER_ERR             -1000
#define TMC_RV_LOC_MEM_ERR             -1001    //�޸� ���� ���� ����
#define TMC_RV_GLB_MEM_ERR             -1002    //���� �޸� ���� ���� ����
#define TMC_RV_HANDLE_ERR              -1003    //����̽� �ڵ鰪�� ����
#define TMC_RV_CREATE_KERNEL_ERR       -1004    // Ŀ�� ����̺� ���� ����
#define TMC_RV_CREATE_THREAD_ERR       -1005    //������ ���� ����
#define TMC_RV_CREATE_EVENT_ERR        -1006    //�̺�Ʈ ���� ����
#define TMC_RV_CREATE_FILE_ERR	       -1007    //���� ���� ����

/////////////////////////////////////////////////////////////////
#define TMC_RV_CON_NOT_FOUND_ERR	 -1030  //CONTROLLER NOT FOUND ����
#define TMC_RV_CON_NOT_LOAD_ERR		 -1031  //CONTROLLER LOAD ����
#define TMC_RV_CON_DIP_SW_ERR		 -1032  //���� ID ���� ����
#define TMC_RV_CON_MAX_ERR		     -1033  // CONTROLLER �ִ� ���� ����
#define TMC_RV_PCI_BUS_LINE_ERR		 -1034   //PCI ���� ����Ÿ�� �̻��մϴ�.
#define TMC_RV_MOD_POS_ERR		     -1035   //��� ������ �߸��Ǿ����ϴ�.
#define TMC_RV_SUPPORT_PROCESS_ERR   -1036   // �������� ���� ���μ���
#define TMC_RV_SUPPORT_FUCTION_ERR   -1037   // �������� ���� �Լ�
#define TMC_RV_CON_OPEN_MODE_ERR     -1038   // ����/�ڵ� ��尡 Ʋ��
#define TMC_RV_CON_MODEL_TYPE_ERR    -1039   // ����� �𵨸��� Ʋ��
#define TMC_RV_SUPPORT_HARDWARE_ERR  -1040   // �������� ���� �ϵ����
/////////////////////////////////////////////////////////////////
#define TMC_RV_PRM_LOAD_ERR             -1050  //�Ķ���� �ε� ����
#define TMC_RV_PRM_VAL_ERR              -1051  //�Ķ���� �� ����
#define TMC_RV_PRM_FILENAME_ERR         -1052  //�Ķ���� ������ �������� ����
#define TMC_RV_PRM_FILENAME_DIFF_ERR    -1053  //�̹� ���µ� �Ķ���� ���ϰ� �������� ���� 
#define TMC_RV_PRM_OPEN_FILENAME_ERR    -1054  //�̹� ���µ� �Ķ���� ������ ����
/////////////////////////////////////////////////////////////////
#define TMC_RV_NOT_SPT_ERR            -1100 // �𵨿��� �������� �ʴ� ���
#define TMC_RV_DIV_BY_ZERO_ERR        -1101 // DIVIDE BY ZERO ����
#define TMC_RV_TIME_OUT_ERR           -1102 // TIME OUT ����
#define TMC_RV_WM_QUIT_ERR            -1103 // WM_QUIT �߻� ����
#define TMC_RV_CON_NO_ERR             -1120 // �ش� ī���ȣ�� �������� ����
#define TMC_RV_AXIS_NO_ERR            -1121 // �� ��ȣ ����
#define TMC_RV_MASTER_AXIS_NO_ERR     -1122 // �������� ��ȣ ���� 
#define TMC_RV_SLAVE_AXIS_NO_ERR      -1123 // �����̺��� ��ȣ ����
#define TMC_RV_COORD_NO_ERR           -1124 // COORDINATE ��ȣ ����
#define TMC_RV_ARG_RNG_ERR            -1125 // �Լ� ���� ���� ����
#define TMC_RV_CS_AXIS_ERR            -1126 // COORDINATE AXIS ����
#define TMC_RV_INT_CFG_ERR            -1127 // ���ͷ�Ʈ ���� ����
#define TMC_RV_COORD_AXES_ERR         -1128 // COORDINATE AXIS ���� ����
#define TMC_RV_CONT_AXES_ERR          -1129 // ���� ���  AXIS ���� ����
#define TMC_RV_HEL_COORD_NO_ERR       -1110 // HEL COORDINATE ��ȣ ����


/////////////////////////////////////////////////////////////////
#define TMC_RV_GROUP_RNG_ERR          -1130 // Group ���� ����
#define TMC_RV_AXES_MIN_ERR           -1131 // AXIS �ּ� ���� ����
#define TMC_RV_AXES_MAX_ERR           -1132 // AXIS �ִ� ����  ����

/////////////////////////////////////////////////////////////////

#define TMC_RV_MTN_IN_STOP_ERR        -1140  // ��� �������̾�� �Ǵµ� ��� �������� �ƴ� �� ����
#define TMC_RV_MTN_DRV_ERR            -1141  // ��� �������̾�� �Ǵµ� ��� ������ �� �� ����
#define TMC_RV_HOME_BUSY_ERR          -1142  // ORG SEARCH ���� ����
#define TMC_RV_DRV_STEADY_ERR         -1143  // ���� ����
#define TMC_RV_DRV_PAB_ERR			  -1144  // �����޽� �������϶� ��� ��� ���� �� ����
#define TMC_RV_DRV_MODIFY_POS_ERR	  -1145  // ��� ������ �߻� �Ǵ� �̹� �̼��� �Ϸ�Ǿ� ��ġ �������̵尡 ������� ����
#define TMC_RV_PRE_POS_ERR       	  -1146  // �������� ����Ÿ ����
#define TMC_RV_PRE_FULL_ERR       	  -1147  // �������� ����Ÿ Ǯ ���� ����
/////////////////////////////////////////////////////////////////
#define TMC_RV_MIN_VEL_ERR		      -1150   //  MIN VEL VALUE IS UNDER VALID 
#define TMC_RV_MAX_VEL_ERR			  -1151   //  MAX VEL VALUE IS OVER VALID 
#define TMC_RV_MIN_STARTV_ERR         -1152   //  START VEL VALUE IS UNDER VALID SV
#define TMC_RV_MAX_STARTV_ERR         -1153   //  START VEL VALUE IS OVER VALID SV
#define TMC_RV_MIN_WORKV_ERR          -1154   //  WORK  VEL VALUE IS UNDER VALID WV
#define TMC_RV_MAX_WORKV_ERR          -1155   //  WORK  VEL IS OVER VALID WV
#define TMC_RV_MIN_ACC_ERR            -1156   //  ACC TIME IS UNDER VALID AC
#define TMC_RV_MAX_ACC_ERR            -1157   //  ACC TIME IS OVER VALID AC
#define TMC_RV_MIN_DEC_ERR            -1158   //  DEC TIME IS UNDER VALID AC
#define TMC_RV_MAX_DEC_ERR            -1159   //  DEC TIME IS OVER VALID AC

/////////////////////////////////////////////////////////////////
#define TMC_RV_MIN_DISTANCE_ERR        -1160   //  �̵� �Ÿ��� �ּҰ� �̻�
#define TMC_RV_MAX_DISTANCE_ERR        -1161   //  �̵� �Ÿ��� �ִ밪 �̻�

/////////////////////////////////////////////////////////////////
#define TMC_RV_DLOG_ERR               -1180   // FUNCTION �α� ����
#define TMC_RV_DLOG_LEVEL_ERR         -1181   // FUNCTION �α� ���� ����
#define TMC_RV_DLOG_FILENAME_ERR      -1182   // FUNCTION �α� ���� ����
/////////////////////////////////////////////////////////////////
#define TMC_RV_CMP_CONNECT_ERR        -1200   //CMP ���� ���� ����

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
#define TMC_RV_UNKNOWN_ERR            -9999  // �˼� ���� ����




#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of TMC_MAPI_DEFS_H definition

//===========================================================================
// End of file.
//===========================================================================

