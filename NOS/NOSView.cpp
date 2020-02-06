// NOSView.cpp : CNOSView 클래스의 구현
//

#include "stdafx.h"
#include "NOS.h"

#include "NOSDoc.h"
#include "NOSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNOSView

IMPLEMENT_DYNCREATE(CNOSView, CView)

BEGIN_MESSAGE_MAP(CNOSView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CNOSView 생성/소멸

CNOSView::CNOSView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CNOSView::~CNOSView()
{
}

BOOL CNOSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CNOSView 그리기

void CNOSView::OnDraw(CDC* /*pDC*/)
{
	CNOSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CNOSView 인쇄

BOOL CNOSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CNOSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CNOSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CNOSView 진단

#ifdef _DEBUG
void CNOSView::AssertValid() const
{
	CView::AssertValid();
}

void CNOSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNOSDoc* CNOSView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNOSDoc)));
	return (CNOSDoc*)m_pDocument;
}
#endif //_DEBUG


// CNOSView 메시지 처리기
