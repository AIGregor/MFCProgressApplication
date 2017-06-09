/*
*	ѕользовательский класс потока дл€ вывода 
*	диалога с индикатором програсса
*/
#if !defined(MYUITHREAD_H_0F9E6709_B977_4F20_8469_AAF0FE6E3790_INCLUDED)
#define MYUITHREAD_H_0F9E6709_B977_4F20_8469_AAF0FE6E3790_INCLUDED

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProgresDialog.h"

// CMyUIThread
class CMyUIThread : public CWinThread
{
	DECLARE_DYNCREATE(CMyUIThread)

protected:
	//CMyUIThread();           // protected constructor used by dynamic creation
	//virtual ~CMyUIThread();

// Overrides
public:
	CMyUIThread();
	virtual ~CMyUIThread();

	virtual BOOL InitInstance() override;
	virtual int ExitInstance() override;

	int Run() override; 
	void Kill();
	BOOL IsRunning() const { return m_bRunning; };
	BOOL IsStopCommand() const { return m_StopCalculation ? true : false; };
	void SetPosTotalProgress(int iPosition);
	void SetPosStepProgress(int iPosition);
	void SetCurrentOperationText(CString sCurrentOperationName);
	void SetParent(CWnd* pParent);

	HWND getProgressDlgHandle() const { return m_ProgressDlg.GetSafeHwnd(); }

private:
	CWnd*	m_pParentWnd; // –одительское окно, к которому прив€зываемс€ 
	BOOL	m_bRunning; // ‘лаг - поток запущен
	CProgresDialog m_ProgressDlg; // ƒиалог с прогрессом
	BOOL	m_StopCalculation;
	
protected:
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(MYUITHREAD_H_0F9E6709_B977_4F20_8469_AAF0FE6E3790_INCLUDED)

