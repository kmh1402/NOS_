// NOSView.cpp : CNOSView Ŭ������ ����
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CNOSView ����/�Ҹ�

CNOSView::CNOSView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CNOSView::~CNOSView()
{
}

BOOL CNOSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CNOSView �׸���

void CNOSView::OnDraw(CDC* /*pDC*/)
{
	CNOSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CNOSView �μ�

BOOL CNOSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CNOSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CNOSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CNOSView ����

#ifdef _DEBUG
void CNOSView::AssertValid() const
{
	CView::AssertValid();
}

void CNOSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNOSDoc* CNOSView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNOSDoc)));
	return (CNOSDoc*)m_pDocument;
}
#endif //_DEBUG


// CNOSView �޽��� ó����
