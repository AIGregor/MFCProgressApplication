#pragma once

// CProgresDialog dialog
#define UPDATE_PROGRESS_BAR (WM_USER + 10)
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
	DWORD			m_nTimer; // идентификатор нового таймера

	CProgressCtrl	m_ProgressBar; // Общий прогресс	
	CStatic			m_TotalProgressTime; // общее время выполнения операции

	//CMyUIThread*	m_pMyUIThread;
public:	
	void setMainWnd(CWnd* pParent); // изменить указатель на главное окно
	void setMainProgressPosition(int iPosition);
	//void setCurrentThread(CMyUIThread* mCurrentThread);

	DECLARE_MESSAGE_MAP()	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg LRESULT OnUpdateProgressBar(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnCloseProgressBar(WPARAM, LPARAM);
	afx_msg void PostNcDestroy() override;

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnStopCalculation();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnBnClickedBtDialogCalc();
};
