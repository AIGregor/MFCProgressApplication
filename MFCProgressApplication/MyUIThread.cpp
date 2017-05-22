/*
*	Пользовательский класс потока для вывода
*	диалога с индикатором програсса
*/

// MyUIThread.cpp : implementation file
//

#include "stdafx.h"
#include "MFCProgressApplication.h"
#include "MyUIThread.h"

#include "MainFrm.h"

// CMyUIThread

IMPLEMENT_DYNCREATE(CMyUIThread, CWinThread)

CMyUIThread::CMyUIThread() : 
	m_bKill(FALSE),
	m_bRunning(FALSE),
	m_iCurrentProgressPos(0)
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

	/*
	BOOL ret = m_ProgressDlg.Create(IDD_PROGRESDIALOG);
	if (!ret)
	{
		AfxMessageBox(_T("Error creating Dialog"));
		delete m_ProgressDlg;
	}
	*/
	//::PostMessage(m_pParentWnd->GetSafeHwnd(), CM_START_LOCAL_CALCULATION, 0, 0);
	//m_ProgressDlg.DoModal();
	
	BOOL ret = m_ProgressDlg.Create(IDD_PROGRESDIALOG);
	if (!ret)
	{
		AfxMessageBox(_T("Error creating Dialog"));
		delete m_ProgressDlg;
	}
	m_ProgressDlg.ShowWindow(SW_SHOW);
	m_ProgressDlg.CenterWindow(m_pParentWnd);

	::PostMessage(m_pParentWnd->GetSafeHwnd(), CM_START_LOCAL_CALCULATION, (WPARAM)0, (LPARAM)0);

	m_bKill = FALSE;
	m_bRunning = TRUE;

	//m_bKill = TRUE;
	//m_bRunning = FALSE;

	return 0;
}

void CMyUIThread::Kill()
{
	if (!m_bKill) return;
	m_ProgressDlg.PostMessageW(CLOSE_PROGRESS_BAR, (WPARAM)0, (LPARAM)0);
}

void CMyUIThread::SetPosProgress(int iPosition)
{
	if (IsRunning())
	{
		//m_iCurrentProgressPos = iPosition;
		//::PostMessage(m_ProgressDlg.GetSafeHwnd(), UPDATE_PROGRESS_BAR, (WPARAM)static_cast<int>(iPosition), (LPARAM)0);
		m_ProgressDlg.m_ProgressBar.SetPos(iPosition);
		//m_ProgressDlg.UpdateData(FALSE);
	}
}

void CMyUIThread::SetParent(CWnd * pParent)
{
	m_pParentWnd = pParent;
}




// CMyUIThread message handlers
