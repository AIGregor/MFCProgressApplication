#pragma once

// CProgresDialog dialog
#define UPDATE_PROGRESS_BAR (WM_USER + 10)
#define CLOSE_PROGRESS_BAR (WM_USER + 11)

class CProgresDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CProgresDialog)

public:
	CProgresDialog(CWnd* pParent = NULL);   // standard constructor
	//virtual ~CProgresDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRESDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

public:

	CStatic m_Progress;
	CStatic m_TotalProgressTime;
	unsigned int ComputerTime;
	DWORD m_nTimer;

	CProgressCtrl m_ProgressBar;

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg LRESULT OnUpdateProgressBar(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnCloseProgressBar(WPARAM, LPARAM);
	afx_msg void PostNcDestroy();

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedProgress();
};
