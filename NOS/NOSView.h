// NOSView.h : CNOSView Ŭ������ �������̽�
//


#pragma once


class CNOSView : public CView
{
protected: // serialization������ ��������ϴ�.
	CNOSView();
	DECLARE_DYNCREATE(CNOSView)

// Ư���Դϴ�.
public:
	CNOSDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CNOSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // NOSView.cpp�� ����� ����
inline CNOSDoc* CNOSView::GetDocument() const
   { return reinterpret_cast<CNOSDoc*>(m_pDocument); }
#endif

