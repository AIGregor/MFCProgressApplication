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
END_MESSAGE_MAP()


// CProgresDialog message handlers


BOOL CProgresDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	if (this)
		this->DestroyWindow(); 

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
	CFrameWnd* pMainWnd = GetParentFrame();
	::PostMessage(pMainWnd->GetSafeHwnd(), STOP_CALCULATION, (WPARAM)0, (LPARAM)0);
}
