#pragma once

// CProgresDialog dialog
#define CLOSE_PROGRESS_BAR (WM_USER + 11)

class CProgresDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CProgresDialog)

public:
	explicit CProgresDialog(CWnd* pParent = nullptr);   // standard constructor
	BOOL OnInitDialog() override;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRESDIALOG };
#endif
	
protected:
	void DoDataExchange(CDataExchange* pDX) override;    // DDX/DDV support	

protected:
	CWnd*			m_MainFrame;	
	unsigned int	ComputerTime; // ����� � ������� ������� ������� - ��������

	CProgressCtrl	m_ProgressBarTotal; // ����� ��������	
	CProgressCtrl	m_ProgressBarStep; // �������� ��������� ������ �����
	CStatic			m_stTotalProgressTime; // ����� ����� ���������� ��������
	CStatic			m_stProgressTimeStep; // ����� ���������� ����� ���������� ������ �����
	CStatic			m_stCurrentStepName; // �������� ������� ��������

	DWORD			dwTotalTimerID;
	DWORD			dwStepTimerID;
	const UINT_PTR	uiptrTotalTimerIDEvent = 111;
	const UINT_PTR	uiptrStepTimerIDEvent = 999;

	BOOL			bResetStepTimer;

public:	
	void setMainWnd(CWnd* pParent); // �������� ��������� �� ������� ����
	void setTotalProgressPosition(int iPosition);
	void setStepProgressPosition(int iPosition);
	void setCurrentOperationText(CString sCurrentOpretion);

	//void setCurrentThread(CMyUIThread* mCurrentThread);

	DECLARE_MESSAGE_MAP()	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void PostNcDestroy() override;
	afx_msg LRESULT OnCloseProgressBar(WPARAM, LPARAM);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnStopCalculation();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnBnClickedBtDialogCalc();
};
