#pragma once

// CProgresDialog dialog
#define CLOSE_PROGRESS_BAR (WM_USER + 11)
#define UM_SETPOS_STEPPROGRESS (WM_USER + 12)

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
	CString getTimeString(unsigned int uiTime);

protected:
	CWnd*			m_MainFrame;
	unsigned int	m_uiStartTotalTime; // ����� � ������� ������� �������
	unsigned int	m_uiStartStepTime; // ����� � ������� ������� ����

	CProgressCtrl	m_ProgressBarTotal; // ����� ��������	
	CProgressCtrl	m_ProgressBarStep; // �������� ��������� ������ �����
	CStatic			m_stTotalProgressTime; // ����� ����� ���������� ��������
	CStatic			m_stProgressTimeStep; // ����� ���������� ����� ���������� ������ �����
	CStatic			m_stCurrentStepName; // �������� ������� ��������

	DWORD			dwTotalTimerID;
	DWORD			dwStepTimerID;
	const UINT_PTR	uiptrTotalTimerIDEvent = 111;
	const UINT_PTR	uiptrStepTimerIDEvent = 999;

	BOOL			bResetStepTimer; // ����� ������� �������� ����
	BOOL			m_bStopCalculation;

public:	
	void setMainWnd(CWnd* pParent); // �������� ��������� �� ������� ����
	void setTotalProgressPosition(int iPosition);
	void setStepProgressPosition(int iPosition);
	void setCurrentOperationText(CString sCurrentOpretion);
	void resetStepTimer();
	BOOL getStopCalculation() const;
	
	DECLARE_MESSAGE_MAP()	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void PostNcDestroy() override;

	afx_msg LRESULT OnCloseProgressBar(WPARAM, LPARAM);
	afx_msg LRESULT OnSetPosStepProgress(WPARAM wParam, LPARAM lParam);

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnStopCalculation();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnBnClickedBtDialogCalc();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
};
