// ProgresDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFCProgressApplication.h"
#include "ProgresDialog.h"
#include "afxdialogex.h"
#include "MainFrm.h"

// CProgresDialog dialog

IMPLEMENT_DYNAMIC(CProgresDialog, CDialogEx)

CProgresDialog::CProgresDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROGRESDIALOG, pParent)
{

}

void CProgresDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_PROGRESS_CONTROL, m_ProgressBar);
	DDX_Control(pDX, IDC_TOTALTIME, m_TotalProgressTime);
}


BEGIN_MESSAGE_MAP(CProgresDialog, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_MESSAGE(UPDATE_PROGRESS_BAR, OnUpdateProgressBar)
	ON_MESSAGE(CLOSE_PROGRESS_BAR, OnCloseProgressBar)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDCANCEL_PROGRESS, &CProgresDialog::OnBnClickedProgress)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BT_DIALOG_CALC, &CProgresDialog::OnBnClickedBtDialogCalc)
END_MESSAGE_MAP()


// CProgresDialog message handlers


BOOL CProgresDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	TRACE("OnInitDialog - Start\n");

	// TODO:  Add extra initialization here
	ComputerTime = GetTickCount();

	m_ProgressBar.SetRange(0, 100);
	m_ProgressBar.SetPos(0);
	m_nTimer = SetTimer(1234, 1000, NULL);
	
	return TRUE;  
}

void CProgresDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

LRESULT CProgresDialog::OnUpdateProgressBar(WPARAM wparam, LPARAM lparam)
{
	m_ProgressBar.SetPos(wparam);
	return 0;
}

LRESULT CProgresDialog::OnCloseProgressBar(WPARAM, LPARAM)
{
	//if (this)
	//	this->DestroyWindow(); 
	//KillTimer(1234);

	return 0;
}

void CProgresDialog::PostNcDestroy()
{
	delete this;
}


void CProgresDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	unsigned long CurTickValue = GetTickCount();
	unsigned int Difference = CurTickValue - ComputerTime;

	unsigned int ComputerHours, ComputerMinutes, ComputerSeconds;
	unsigned int ApplicationHours, ApplicationMinutes, ApplicationSeconds;

	ComputerHours = (CurTickValue / (3600 * 999)) % 24;
	ComputerMinutes = (CurTickValue / (60 * 999)) % 60;
	ComputerSeconds = (CurTickValue / 999) % 60;
	ApplicationHours = (Difference / (3600 * 999)) % 24;
	ApplicationMinutes = (Difference / (60 * 999)) % 60;
	ApplicationSeconds = (Difference / 999) % 60;
	CString val2;
	val2.Format(_T("%d:%d:%d"),
		ApplicationHours, ApplicationMinutes, ApplicationSeconds);
	m_TotalProgressTime.SetWindowTextW(val2);
	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}


void CProgresDialog::OnBnClickedProgress()
{
	// TODO: Add your control notification handler code here
	//CFrameWnd* pMainWnd = GetParentFrame();
	//::PostMessage(pMainWnd->GetSafeHwnd(), STOP_CALCULATION, (WPARAM)0, (LPARAM)0);
	::PostMessage(m_pParentWnd->GetSafeHwnd(), CM_START_LOCAL_CALCULATION, (WPARAM)0, (LPARAM)0);
	//OnCloseProgressBar((WPARAM)0, (LPARAM)0);
}


void CProgresDialog::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	TRACE("OnShowWindow - Finish\n");
	//::PostMessage(m_pParentWnd->GetSafeHwnd(), CM_START_LOCAL_CALCULATION, (WPARAM)0, (LPARAM)0);
	// TODO: Add your message handler code here
}


void CProgresDialog::OnBnClickedBtDialogCalc()
{
	// TODO: Add your control notification handler code here
	TRACE("Вычисления в Диалоге - Start\n");
	int i = 0;
	while (i < 100)
	{
		++i;
		m_ProgressBar.SetPos(i);

		//m_pMyUIThread->SetPosProgress(i);

		//::PostMessage(pProgressBarDlg->GetSafeHwnd(), UPDATE_PROGRESS_BAR, (WPARAM)static_cast<int>(i), (LPARAM)0);
		Sleep(100);

		if (i == 30)
			::SendMessage(::GetParent(this->GetSafeHwnd()), WM_COMMAND, CM_START_INNER1_LOCAL_CALCULATION, 0);
		if (i == 60)
			::SendMessage(::GetParent(this->GetSafeHwnd()),WM_COMMAND, CM_START_INNER2_LOCAL_CALCULATION, 0);
	}
	TRACE("Вычисления в Диалоге - Finish\n");
}
