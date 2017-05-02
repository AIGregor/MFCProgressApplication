
// MFCProgressApplicationView.h : интерфейс класса CMFCProgressApplicationView
//

#pragma once


class CMFCProgressApplicationView : public CView
{
protected: // создать только из сериализации
	CMFCProgressApplicationView();
	DECLARE_DYNCREATE(CMFCProgressApplicationView)

// Атрибуты
public:
	CMFCProgressApplicationDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMFCProgressApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в MFCProgressApplicationView.cpp
inline CMFCProgressApplicationDoc* CMFCProgressApplicationView::GetDocument() const
   { return reinterpret_cast<CMFCProgressApplicationDoc*>(m_pDocument); }
#endif

