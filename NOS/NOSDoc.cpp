// NOSDoc.cpp : CNOSDoc 클래스의 구현
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


// CNOSDoc 생성/소멸

CNOSDoc::CNOSDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CNOSDoc::~CNOSDoc()
{
}

BOOL CNOSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CNOSDoc serialization

void CNOSDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CNOSDoc 진단

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


// CNOSDoc 명령
