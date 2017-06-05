/*
*	���������������� ����� ������ ��� ������
*	������� � ����������� ���������
*
*	����� ������������ ���������� ������������
*/

// MyUIThread.cpp : implementation file
#include "stdafx.h"
#include "MFCProgressApplication.h"
#include "MyUIThread.h"

#include "MainFrm.h"

// CMyUIThread
IMPLEMENT_DYNCREATE(CMyUIThread, CWinThread)

CMyUIThread::CMyUIThread() : 
	m_bKill(FALSE),
	m_bRunning(FALSE)
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
	//m_ProgressDlg.setCurrentThread(this);

	m_ProgressDlg.ShowWindow(SW_SHOW);
	m_ProgressDlg.CenterWindow(m_pParentWnd);
	m_pParentWnd->EnableWindow(FALSE);

	m_bKill = FALSE;
	m_bRunning = TRUE;
	
	CWnd* pMainWnd = m_pParentWnd;
	// ������ ����������
	::PostMessage(pMainWnd->GetSafeHwnd(),
		CM_START_LOCAL_CALCULATION,
		static_cast<WPARAM>(0),
		static_cast<LPARAM>(0));

	//m_ProgressDlg.DoModal();
			
	//if (CWinThread::Run())
	//{
	//	TRACE("RUN !!!");
	//};
		
	//m_bKill = TRUE;
	//m_bRunning = FALSE;

	return CWinThread::Run();
}

void CMyUIThread::Kill()
{
	if (!m_bKill) return;
	m_ProgressDlg.PostMessageW(CLOSE_PROGRESS_BAR, (WPARAM)0, (LPARAM)0);
}

void CMyUIThread::myKill()
{
	m_ProgressDlg.PostMessageW(CLOSE_PROGRESS_BAR, (WPARAM)0, (LPARAM)0);
}

void CMyUIThread::SetPosProgress(int iPosition)
{
	if (IsRunning())
	{
		m_ProgressDlg.setMainProgressPosition(iPosition);
	}
}

void CMyUIThread::SetParent(CWnd * pParent)
{
	m_pParentWnd = pParent;
}
// CMyUIThread message handlers