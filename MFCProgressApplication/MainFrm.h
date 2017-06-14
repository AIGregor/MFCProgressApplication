
// MainFrm.h : ��������� ������ CMainFrame
//

#pragma once
#include "FileView.h"
#include "ClassView.h"
#include "OutputWnd.h"
#include "PropertiesWnd.h"

#include "MyUIThread.h"
#include "MyWnd.h"

class CProgresDialog;

#define STOP_CALCULATION (WM_USER + 12)

// ��������� ���������� �������� ������
#define CM_START_LOCAL_CALCULATION (WM_USER + 13)

#define CM_START_INNER1_LOCAL_CALCULATION (WM_USER + 14)
#define CM_START_INNER2_LOCAL_CALCULATION (WM_USER + 15)

DWORD WINAPI CalculationRoutine(__in LPVOID lpParameter);

class CMainFrame : public CMDIFrameWndEx
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// ��������
public:

// ��������
public:

// ���������������
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// ����������
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	void CalculationProc();
	void InitProgressBarDlg();
	void DoEvents();

protected:  // ���������� ����� ������ ��������� ����������
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;
	CFileView         m_wndFileView;
	CClassView        m_wndClassView;
	COutputWnd        m_wndOutput;
	CPropertiesWnd    m_wndProperties;

	bool			  m_bStopCalculation;

	CProgresDialog*	  pProgressBarDlg;
	HANDLE m_ThreadID;

	CMyUIThread*	  m_pMyUIThread;
// ��������� ������� ����� ���������
protected:

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnWindowManager();
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);

	afx_msg LRESULT OnStopCalc(WPARAM wp, LPARAM lp);

	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	DECLARE_MESSAGE_MAP()

	BOOL CreateDockingWindows();
	void SetDockingWindowIcons(BOOL bHiColorIcons);

public:
	afx_msg void OnStartCalc();
	afx_msg void OnStartLocalCalc();

protected:
	afx_msg LRESULT OnCmStartlocalcalc(WPARAM wParam, LPARAM lParam);

public:
	afx_msg void OnStartUithread();
	afx_msg void OnInner1Calculation();
	afx_msg void OnInner2Calculation();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


