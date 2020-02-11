// MainFrm.cpp : CMainFrame 클래스의 구현
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
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
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
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	SetMenu(NULL);
	return 0;
}

void CMainFrame::OnVisionSkip()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CDlg_Skip		*dlg = new CDlg_Skip;//동적으로 생성해준다
	dlg -> Create(IDD_DLG_SKIP,NULL);//모달리스는 반드시 Create로 띄워야한다. 
	dlg ->ShowWindow(SW_SHOW);

}
void CMainFrame::OnVisionSkip2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CDlg_Skip		*dlg = new CDlg_Skip;//동적으로 생성해준다
	dlg -> Create(IDD_DLG_SKIP2,NULL);//모달리스는 반드시 Create로 띄워야한다. 
	dlg ->ShowWindow(SW_SHOW);

}

void CMainFrame::OnVisionSkip3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CDlg_Skip		*dlg = new CDlg_Skip;//동적으로 생성해준다
	dlg -> Create(IDD_DLG_SKIP3,NULL);//모달리스는 반드시 Create로 띄워야한다. 
	dlg ->ShowWindow(SW_SHOW);

}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.
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


// CMainFrame 진단

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


// CMainFrame 메시지 처리기

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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if(GetActiveView()->IsKindOf(RUNTIME_CLASS(CFrm_Main)))   return ;
	SwitchToForm(IDW_FRM_MAIN);
}

void CMainFrame::OnUpdateMenuMain(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(MenuNum == IDW_FRM_MAIN?FALSE:TRUE);
}
