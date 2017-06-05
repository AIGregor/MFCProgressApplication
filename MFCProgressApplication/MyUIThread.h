/*
*	���������������� ����� ������ ��� ������ 
*	������� � ����������� ���������
*/
#if !defined(MYUITHREAD_H_0F9E6709_B977_4F20_8469_AAF0FE6E3790_INCLUDED)
#define MYUITHREAD_H_0F9E6709_B977_4F20_8469_AAF0FE6E3790_INCLUDED

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProgresDialog.h"

// CMyUIThread

#define WM_INFORM_CLOSE		WM_USER + 100

class CMyUIThread : public CWinThread
{
	DECLARE_DYNCREATE(CMyUIThread)

protected:
	//CMyUIThread();           // protected constructor used by dynamic creation
	//virtual ~CMyUIThread();

// Overrides
public:
	virtual BOOL InitInstance() override;
	virtual int ExitInstance() override;

	CMyUIThread();
	virtual ~CMyUIThread();

	int Run() override; 
	void Kill();
	void myKill();
	BOOL IsRunning() const { return m_bRunning; };
	void SetPosProgress(int iPosition);
	void SetParent(CWnd* pParent);

private:
	CWnd*	m_pParentWnd; // ������������ ����, � �������� ������������� 
	BOOL	m_bKill; // ���� ��� �������� ������
	BOOL	m_bRunning; // ���� - ����� �������
	CProgresDialog m_ProgressDlg; // ������ � ����������

protected:
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(MYUITHREAD_H_0F9E6709_B977_4F20_8469_AAF0FE6E3790_INCLUDED)

