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
	unsigned int	ComputerTime; // времы с момента запуска системы - изменить

	CProgressCtrl	m_ProgressBarTotal; // Общий прогресс	
	CProgressCtrl	m_ProgressBarStep; // Прогресс обработки одного листа
	CStatic			m_stTotalProgressTime; // общее время выполнения операции
	CStatic			m_stProgressTimeStep; // время выполнения время выполнеиня одного листа
	CStatic			m_stCurrentStepName; // Название текущей операции

	DWORD			dwTotalTimerID;
	DWORD			dwStepTimerID;
	const UINT_PTR	uiptrTotalTimerIDEvent = 111;
	const UINT_PTR	uiptrStepTimerIDEvent = 999;

	BOOL			bResetStepTimer;

public:	
	void setMainWnd(CWnd* pParent); // изменить указатель на главное окно
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
