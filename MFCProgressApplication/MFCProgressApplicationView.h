
// MFCProgressApplicationView.h : ��������� ������ CMFCProgressApplicationView
//

#pragma once


class CMFCProgressApplicationView : public CView
{
protected: // ������� ������ �� ������������
	CMFCProgressApplicationView();
	DECLARE_DYNCREATE(CMFCProgressApplicationView)

// ��������
public:
	CMFCProgressApplicationDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CMFCProgressApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � MFCProgressApplicationView.cpp
inline CMFCProgressApplicationDoc* CMFCProgressApplicationView::GetDocument() const
   { return reinterpret_cast<CMFCProgressApplicationDoc*>(m_pDocument); }
#endif

