// NOSDoc.h : CNOSDoc Ŭ������ �������̽�
//


#pragma once


class CNOSDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CNOSDoc();
	DECLARE_DYNCREATE(CNOSDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CNOSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


