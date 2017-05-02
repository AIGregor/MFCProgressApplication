
// MFCProgressApplicationView.cpp : ���������� ������ CMFCProgressApplicationView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "MFCProgressApplication.h"
#endif

#include "MFCProgressApplicationDoc.h"
#include "MFCProgressApplicationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCProgressApplicationView

IMPLEMENT_DYNCREATE(CMFCProgressApplicationView, CView)

BEGIN_MESSAGE_MAP(CMFCProgressApplicationView, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCProgressApplicationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ��������/����������� CMFCProgressApplicationView

CMFCProgressApplicationView::CMFCProgressApplicationView()
{
	// TODO: �������� ��� ��������

}

CMFCProgressApplicationView::~CMFCProgressApplicationView()
{
}

BOOL CMFCProgressApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CMFCProgressApplicationView

void CMFCProgressApplicationView::OnDraw(CDC* /*pDC*/)
{
	CMFCProgressApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}


// ������ CMFCProgressApplicationView


void CMFCProgressApplicationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCProgressApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CMFCProgressApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CMFCProgressApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}

void CMFCProgressApplicationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCProgressApplicationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� CMFCProgressApplicationView

#ifdef _DEBUG
void CMFCProgressApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCProgressApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCProgressApplicationDoc* CMFCProgressApplicationView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCProgressApplicationDoc)));
	return (CMFCProgressApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CMFCProgressApplicationView
