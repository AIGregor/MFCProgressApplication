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
	: CDialogEx(IDD_PROGRESDIALOG, pParent), 
		m_MainFrame(nullptr), 
		ComputerTime(0), 
		dwTotalTimerID(0)
{
}

void CProgresDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_PROGRESS_CONTROL, m_ProgressBarTotal);
	DDX_Control(pDX, IDC_PROGRESS_STEP, m_ProgressBarStep);
	DDX_Control(pDX, IDC_TOTALTIME, m_stTotalProgressTime);
	DDX_Control(pDX, IDC_STATIC_TIME_STEP, m_stProgressTimeStep);
	DDX_Control(pDX, IDC_STATIC_NAME_STEP, m_stCurrentStepName);
}

BEGIN_MESSAGE_MAP(CProgresDialog, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_TIMER()
	ON_WM_CLOSE()	
	ON_WM_SHOWWINDOW()	
	ON_WM_TIMER()
	ON_MESSAGE(CLOSE_PROGRESS_BAR, OnCloseProgressBar)
	ON_BN_CLICKED(IDCANCEL_PROGRESS, OnBnStopCalculation)
	ON_BN_CLICKED(IDC_BT_DIALOG_CALC, &CProgresDialog::OnBnClickedBtDialogCalc)
END_MESSAGE_MAP()


// CProgresDialog message handlers
BOOL CProgresDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	TRACE("OnInitDialog - Start\n");
	// Инициализация прогресса
	m_ProgressBarTotal.SetRange(0, 3);
	m_ProgressBarTotal.SetPos(0);

	m_ProgressBarStep.SetRange(0, 100);
	m_ProgressBarStep.SetPos(0);

	// Инициализация таймера
	ComputerTime = GetTickCount();
	dwTotalTimerID = SetTimer(uiptrTotalTimerIDEvent, 1000, NULL);
	dwStepTimerID = SetTimer(uiptrStepTimerIDEvent, 1000, NULL);
	// Очистка текста
	m_stTotalProgressTime.SetWindowTextW(L"");
	m_stProgressTimeStep.SetWindowTextW(L"");
	return TRUE;  
}

void CProgresDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}
// Закрытие окна диалога
LRESULT CProgresDialog::OnCloseProgressBar(WPARAM, LPARAM)
{
	KillTimer(dwTotalTimerID);
	KillTimer(dwStepTimerID);

	if (this)
		this->DestroyWindow();
	return 0;
}

void CProgresDialog::PostNcDestroy()
{
	//delete this;
}

void CProgresDialog::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == uiptrTotalTimerIDEvent) 
	{
		// TODO: Add your message handler code here and/or call default
		unsigned long CurTickValue = GetTickCount();
		unsigned int Difference = CurTickValue - ComputerTime;

		unsigned int ApplicationHours, ApplicationMinutes, ApplicationSeconds;
		ApplicationHours = (Difference / (3600 * 999)) % 24;
		ApplicationMinutes = (Difference / (60 * 999)) % 60;
		ApplicationSeconds = (Difference / 999) % 60;
		CString val2;
		val2.Format(_T("%d:%d:%d"),
			ApplicationHours, ApplicationMinutes, ApplicationSeconds);
		m_stTotalProgressTime.SetWindowTextW(val2);
	} 
	else if (nIDEvent == uiptrStepTimerIDEvent)
	{

	}
		
	UpdateData(FALSE);
	CDialogEx::OnTimer(nIDEvent);
}

// Обработчик остановка выполнения операции
void CProgresDialog::OnBnStopCalculation()
{
	::PostMessage(m_MainFrame->GetSafeHwnd(), STOP_CALCULATION, (WPARAM)0, (LPARAM)0);
}

void CProgresDialog::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);
	TRACE("OnShowWindow - Finish\n");
}

// Выполнение вычислений в классе диалога
void CProgresDialog::OnBnClickedBtDialogCalc()
{
	// TODO: Add your control notification handler code here
	TRACE("Вычисления в Диалоге - Start\n");
	int i = 0;
	while (i < 100)
	{
		++i;
		m_ProgressBarTotal.SetPos(i);

		Sleep(100);

		if (i == 30)
			::PostMessage(::GetParent(this->GetSafeHwnd()), WM_COMMAND, CM_START_INNER1_LOCAL_CALCULATION, 0);
		if (i == 60)
			::PostMessage(::GetParent(this->GetSafeHwnd()),WM_COMMAND, CM_START_INNER2_LOCAL_CALCULATION, 0);
	}
	TRACE("Вычисления в Диалоге - Finish\n");
}

void CProgresDialog::setMainWnd(CWnd * pParent)
{
	m_MainFrame = pParent;
}

void CProgresDialog::setTotalProgressPosition(int iPosition)
{
	if (m_ProgressBarTotal)
		m_ProgressBarTotal.SetPos(iPosition);
}

void CProgresDialog::setStepProgressPosition(int iPosition)
{
	if (m_ProgressBarStep)
		m_ProgressBarStep.SetPos(iPosition);
}



void CProgresDialog::setCurrentOperationText(CString sCurrentOpretion)
{
	if (m_stCurrentStepName)
		m_stCurrentStepName.SetWindowTextW(sCurrentOpretion);
}
