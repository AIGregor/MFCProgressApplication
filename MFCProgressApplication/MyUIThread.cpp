/*
*	Пользовательский класс потока для вывода
*	диалога с индикатором програсса
*
*	Поток графического интерфейса пользователя
*/

// MyUIThread.cpp : implementation file
#include "stdafx.h"
#include "MFCProgressApplication.h"
#include "MyUIThread.h"

#include "MainFrm.h"

// CMyUIThread
IMPLEMENT_DYNCREATE(CMyUIThread, CWinThread)

CMyUIThread::CMyUIThread() : 
	m_StopCalculation(FALSE)
{	
}

CMyUIThread::~CMyUIThread()
{
}

BOOL CMyUIThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CMyUIThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyUIThread, CWinThread)
END_MESSAGE_MAP()

//-------------------------------------------
int CMyUIThread::Run()
{
	BOOL ret = m_ProgressDlg.Create(IDD_PROGRESDIALOG);
	if (!ret)
	{
		AfxMessageBox(_T("Error creating Dialog"));
		delete m_ProgressDlg;
	}
	m_ProgressDlg.setMainWnd(m_pParentWnd);

	m_ProgressDlg.ShowWindow(SW_SHOW);
	m_ProgressDlg.CenterWindow(m_pParentWnd);
	m_pParentWnd->EnableWindow(FALSE);

	CWnd* pMainWnd = m_pParentWnd;
	// Запуск вычислений
	::PostMessage(pMainWnd->GetSafeHwnd(),
		CM_START_LOCAL_CALCULATION,
		static_cast<WPARAM>(0),
		static_cast<LPARAM>(0));

	return CWinThread::Run();
}

void CMyUIThread::Kill()
{
	m_ProgressDlg.PostMessageW(CLOSE_PROGRESS_BAR, (WPARAM)0, (LPARAM)0);
}

void CMyUIThread::SetPosTotalProgress(int iPosition)
{
	m_ProgressDlg.setTotalProgressPosition(iPosition);
	m_ProgressDlg.resetStepTimer();
	m_StopCalculation = m_ProgressDlg.getStopCalculation();
}

void CMyUIThread::SetPosStepProgress(int iPosition)
{
	m_ProgressDlg.setStepProgressPosition(iPosition);
	m_StopCalculation = m_ProgressDlg.getStopCalculation();
}

void CMyUIThread::SetCurrentOperationText(CString sCurrentOperationName)
{
	m_ProgressDlg.setCurrentOperationText(sCurrentOperationName);
}

void CMyUIThread::SetParent(CWnd * pParent)
{
	m_pParentWnd = pParent;
}
// CMyUIThread message handlers