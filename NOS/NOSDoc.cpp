// NOSDoc.cpp : CNOSDoc Ŭ������ ����
//

#include "stdafx.h"
#include "NOS.h"

#include "NOSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNOSDoc

IMPLEMENT_DYNCREATE(CNOSDoc, CDocument)

BEGIN_MESSAGE_MAP(CNOSDoc, CDocument)
END_MESSAGE_MAP()


// CNOSDoc ����/�Ҹ�

CNOSDoc::CNOSDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CNOSDoc::~CNOSDoc()
{
}

BOOL CNOSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CNOSDoc serialization

void CNOSDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CNOSDoc ����

#ifdef _DEBUG
void CNOSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNOSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CNOSDoc ���
