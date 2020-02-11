// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "NOS.h"
#include "MainFrm.h"
#include "MenuHead.h"
#include "VarEx.h"
#include "Dlg_Skip.h"
#include "Dlg_Skip2.h"
#include "Dlg_Skip3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_MENU_MAIN, &CMainFrame::OnMenuMain)
	ON_UPDATE_COMMAND_UI(ID_MENU_MAIN, &CMainFrame::OnUpdateMenuMain)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("���� ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	// TODO: ���� ������ ��ŷ�� �� ���� �Ϸ��� �� �� ���� �����Ͻʽÿ�.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	SetMenu(NULL);
	return 0;
}

void CMainFrame::OnVisionSkip()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CDlg_Skip		*dlg = new CDlg_Skip;//�������� �������ش�
	dlg -> Create(IDD_DLG_SKIP,NULL);//��޸����� �ݵ�� Create�� ������Ѵ�. 
	dlg ->ShowWindow(SW_SHOW);

}
void CMainFrame::OnVisionSkip2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CDlg_Skip		*dlg = new CDlg_Skip;//�������� �������ش�
	dlg -> Create(IDD_DLG_SKIP2,NULL);//��޸����� �ݵ�� Create�� ������Ѵ�. 
	dlg ->ShowWindow(SW_SHOW);

}

void CMainFrame::OnVisionSkip3()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CDlg_Skip		*dlg = new CDlg_Skip;//�������� �������ش�
	dlg -> Create(IDD_DLG_SKIP3,NULL);//��޸����� �ݵ�� Create�� ������Ѵ�. 
	dlg ->ShowWindow(SW_SHOW);

}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.
	int  chk=GetSystemMetrics(SM_CXFULLSCREEN) ;
	switch(chk) 
	{
		// 1280*1024 Mode
		case 1280:
			cs.x=0 ;    cs.y=0 ;   cs.cx=1280;  cs.cy=1024;
   		    break;
		// 640*480 Mode
     	case 640:
	       	cs.x=0 ;    cs.y=0 ;   cs.cx=640;  cs.cy=480;
   		    break;
        // 1024*768 Mode
		case 1024:       
			cs.x=0 ;   cs.y=0 ;    cs.cx=1024;  cs.cy=768;
   		    break;
		// 800*600 Mode
		case 800:
			cs.x=0 ;    cs.y=0 ;   cs.cx=800;  cs.cy=600;
   		    break;
		default:
			//cs.x=0 ;    cs.y=0 ;   cs.cx=1024;  cs.cy=768;
			cs.x=0 ;    cs.y=0 ;   cs.cx=1280;  cs.cy=1024;
   		    break;
    }
	
	//cs.style &= ~WS_THICKFRAME & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX & WS_BORDER;
	cs.style &= ~FWS_ADDTOTITLE;
	return TRUE;
}


// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame �޽��� ó����

void CMainFrame::SwitchToForm(int nForm)
{
	if (nForm == 0)
	{
		nForm = IDW_FRM_MAIN;
	}
	CView* pOldActiveView = GetActiveView() ;
	CView* pNewActiveView = (CView*)GetDlgItem(nForm) ;

	if(pNewActiveView==NULL)  
	{
		switch(nForm)
		{			
			case IDW_FRM_MAIN : pNewActiveView = (CView*)new CFrm_Main;	break;
			//case IDW_FRM_MOTION : pNewActiveView = (CView*)new CFrm_Motion;	break;
			//case IDW_FRM_IO : pNewActiveView = (CView*)new CFrm_IO;	break;	
			//case IDW_FRM_ALIGN : pNewActiveView = (CView*)new CFrm_Align;	break;	
			//case IDW_FRM_GATE : pNewActiveView = (CView*)new CFrm_Gate;	break;
			//case IDW_FRM_BOND : pNewActiveView = (CView*)new CFrm_Bond;	break;
				
		}
		CCreateContext context;
		context.m_pCurrentDoc=pOldActiveView->GetDocument() ;
        pNewActiveView->Create(NULL,NULL,0L,CFrameWnd::rectDefault,this,nForm,&context) ; 
        pNewActiveView->OnInitialUpdate();
	}

	pOldActiveView->ShowWindow(SW_HIDE);
	SetActiveView(pNewActiveView);
	pNewActiveView->ShowWindow(SW_SHOW);

	if(pOldActiveView->GetRuntimeClass()==RUNTIME_CLASS(CFrm_Main))	pOldActiveView->SetDlgCtrlID(IDW_FRM_MAIN);
	//else if(pOldActiveView->GetRuntimeClass()==RUNTIME_CLASS(CFrm_Motion))	pOldActiveView->SetDlgCtrlID(IDW_FRM_MOTION) ;
	//else if(pOldActiveView->GetRuntimeClass()==RUNTIME_CLASS(CFrm_IO))	pOldActiveView->SetDlgCtrlID(IDW_FRM_IO) ;
	//else if(pOldActiveView->GetRuntimeClass()==RUNTIME_CLASS(CFrm_Align))	pOldActiveView->SetDlgCtrlID(IDW_FRM_ALIGN) ;
	//else if(pOldActiveView->GetRuntimeClass()==RUNTIME_CLASS(CFrm_Gate))	pOldActiveView->SetDlgCtrlID(IDW_FRM_GATE) ;
	//else if(pOldActiveView->GetRuntimeClass()==RUNTIME_CLASS(CFrm_Bond))	pOldActiveView->SetDlgCtrlID(IDW_FRM_BOND) ;
	
	
	pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	pOldActiveView->DestroyWindow();
	RecalcLayout() ;
	MenuNum = nForm ;
}


void CMainFrame::OnMenuMain()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	if(GetActiveView()->IsKindOf(RUNTIME_CLASS(CFrm_Main)))   return ;
	SwitchToForm(IDW_FRM_MAIN);
}

void CMainFrame::OnUpdateMenuMain(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(MenuNum == IDW_FRM_MAIN?FALSE:TRUE);
}
